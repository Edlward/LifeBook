/**
  \file motor.cpp

  \par Copyright &copy; 2018 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \addtogroup Motor
  \{
 */
extern "C"
{
    #include <mbsAssert.h>
}
#include "motorImp.hpp"
#include "outputConfig.hpp"
#include "unused.h"
#include "interruptTest.hpp"

// Defines necessary for the unit test.
#ifdef _UNIT_TEST_
  /* In a unit test the read function from the stm gpio library must be renamed. This file is used
   * in the Unit test on target, so if the function is redefined here there will be multiple definitions.
   */
    void mcuRegisterInterruptHandler_test( McuInterrupt irq,
                                           McuInterruptHandler irqHandler,
                                           void * param );
    #define mcuRegisterInterruptHandler mcuRegisterInterruptHandler_test
#endif /* #ifdef _UNIT_TEST_ */

namespace outputInternal
{
    volatile output::Motor::teMotorEnableType MotorImp::eMotorEnable              = output::Motor::MOTORDISABLE;
    volatile int16_t                          MotorImp::si16LastCurrentInAdQuanta = 4096; //! Value corresponding to 0 current
    volatile int16_t                          MotorImp::si16SetCurrentInAdQuanta  = 4096; //! Value corresponding to 0 current
    volatile int16_t                          MotorImp::si16PwmWidthInTimerTicks  = 0;    //! Value corresponding to idle output

    volatile int16_t                          MotorImp::si16Adc1ZeroDrift     = 0; //better to initialize to 0, avoid not calibration.
    volatile int16_t                          MotorImp::si16Adc1ZeroDriftAvg  = 0; //better to initialize to 0, avoid not calibration.
    volatile int16_t                          MotorImp::si16Adc1ZeroDriftMax  = 2048;
    volatile int16_t                          MotorImp::si16Adc1ZeroDriftMin  = 2048;
    volatile int16_t                          MotorImp::si16Adc2ZeroDrift     = 0; //better to initialize to 0, avoid not calibration.
    volatile int16_t                          MotorImp::si16Adc2ZeroDriftAvg  = 0; //better to initialize to 0, avoid not calibration.
    volatile int16_t                          MotorImp::si16Adc2ZeroDriftMax  = 2048;
    volatile int16_t                          MotorImp::si16Adc2ZeroDriftMin  = 2048;

    //lint -e{1938} The constructor is not used as a copy constructor, and only constant global values are accessed, without being modified.
    //              Therefore MISRA C++ rule 12-8-1 is not violated.
    MotorImp::MotorImp():
        si16SetCurrentInMilliA ( 0 ),
        si32SetTorqueInMilliNm ( 0 )
    {
        vSetUpHardWare();
        vReInitializeStaticMembers();
    }


    void MotorImp::vSetMotorEnable ( const teMotorEnableType eNewMotorEnable ) const volatile
    {
        eMotorEnable = eNewMotorEnable;
    }

    void MotorImp::vSetMotorCurrent (const int16_t si16MotorCurrentSetValue ) volatile
    {
        si16SetCurrentInMilliA = si16MotorCurrentSetValue;
        si32SetTorqueInMilliNm = ( static_cast<int32_t>( si16MotorCurrentSetValue )*csi16CurrentToTorqueFactor )/256;
        vTranslateSetCurrentToAdQuanta();
    }

    void MotorImp::vSetShaftTorque (const int32_t si32ShaftTorqueSet) volatile
    {
        si32SetTorqueInMilliNm = si32ShaftTorqueSet;
        si16SetCurrentInMilliA = static_cast<int16_t>( ( si32ShaftTorqueSet*csi16TorqueToCurrentFactor )/16384 );
        vTranslateSetCurrentToAdQuanta();
    }

    int32_t MotorImp::si32GetShaftTorque() const volatile
    {
        return si32SetTorqueInMilliNm;
    }

    int16_t MotorImp::si16GetMotorCurrent() const volatile
    {
        return si16SetCurrentInMilliA;
    }

    int16_t MotorImp::si16GetMotorPwmSign() const volatile
    {
        return si16PwmWidthInTimerTicks;
    }

    int16_t MotorImp::si16GetMotorAdcQuata() const volatile
    {
        return si16LastCurrentInAdQuanta;
    }

    int16_t MotorImp::si16GetMotorAdcDrift1() const volatile
    {
        return si16Adc1ZeroDrift;
    }

    int16_t MotorImp::si16GetMotorAdcDrift2() const volatile
    {
        return si16Adc2ZeroDrift;
    }

    int16_t MotorImp::si16GetMotorAdcDrift1Avg() const volatile
    {
        return si16Adc1ZeroDriftAvg;
    }

    int16_t MotorImp::si16GetMotorAdcDrift2Avg() const volatile
    {
        return si16Adc2ZeroDriftAvg;
    }

    void MotorImp::vTranslateSetCurrentToAdQuanta() const volatile
    {
        int32_t si32AdSetValue = static_cast<int32_t>( CURRENT_OFFSET_IN_AD_QUANTA );
        si32AdSetValue += static_cast<int32_t>( ( static_cast<int32_t>( RAW_CURRENT_QUANTA )*si16SetCurrentInMilliA )/static_cast<int32_t>( CURRENT_SENSOR_RANGE_IN_MILLI_A ) );
        si16SetCurrentInAdQuanta = static_cast<int16_t>( si32AdSetValue );
    }

    //lint -save -esym(715, param) -esym(818, param) -esym(952, param) param is not used but has to be included due to MBS calling convention
    void MotorImp::vAdcEndOfConversionInterruptHandler ( void* param )
    {
        UNUSED_PARAMETER(param);
        //lint -e(1960,9005,929) pAdc has a constant address to the register map of the used peripheral but is not declared const in the ST library
        //                       function ADC_ClearITPendingBit interface.
        ADC_ClearITPendingBit( const_cast<ADC_TypeDef*>( pAdc ), ADC_IT_EOC );

        if ( output::Motor::MOTORENABLE == eMotorEnable )
        {
            const int32_t csi32RequestedPwmWidthIncrement = si32UpdateIncrementalPiController();
            vIncrementAndLimitPwmWidth( csi32RequestedPwmWidthIncrement );
            vPlaceAdTriggerAndSetOutputRegistersWhenTheMotorIsEnabled();
        }
        else
        {
            vSetOutputRegistersAndControllerStatesWhenTheMotorIsDisabled();

            //drift average
            const int16_t csi16Adc1Sample = motorCurrent1Adc->ui16GetRawAdValue();
            const int16_t csi16Adc2Sample = motorCurrent2Adc->ui16GetRawAdValue();
            if ( si16Adc1ZeroDriftMax < csi16Adc1Sample )
            {
                si16Adc1ZeroDriftMax = csi16Adc1Sample;
            }
            if ( si16Adc1ZeroDriftMin > csi16Adc1Sample )
            {
                si16Adc1ZeroDriftMin = csi16Adc1Sample;
            }
            if ( si16Adc2ZeroDriftMax < csi16Adc2Sample )
            {
                si16Adc2ZeroDriftMax = csi16Adc2Sample;
            }
            if ( si16Adc2ZeroDriftMin > csi16Adc2Sample )
            {
                si16Adc2ZeroDriftMin = csi16Adc2Sample;
            }
            si16Adc1ZeroDriftAvg = si16Adc1ZeroDriftMax + si16Adc1ZeroDriftMin;
            si16Adc1ZeroDriftAvg /= 2;
            si16Adc1ZeroDriftAvg -= 2048;
            si16Adc2ZeroDriftAvg = si16Adc2ZeroDriftMax + si16Adc2ZeroDriftMin;
            si16Adc2ZeroDriftAvg /= 2;
            si16Adc2ZeroDriftAvg -= 2048;

            //last sample to adjust zero drift.
            si16Adc1ZeroDrift = motorCurrent1Adc->ui16GetRawAdValue() - 2048;
            si16Adc2ZeroDrift = motorCurrent2Adc->ui16GetRawAdValue() - 2048;
        }

        vSampleAndFilterAdObjects();
        systemMonitorInternal::InterruptTest::si32InterruptCounter++;
    }
    //lint -restore

    //lint -e{1960,9005,929} pPwmTimer and pAdc has a constant address to the register map of the used peripherals. rPwmTimerBaseConfiguration,
    //                       rOutputCompareConfigurationPwmChannels, rOutputCompareConfigurationAdcTriggerChannel and rEndOfAdcIrqConfiguration
    //                       are all structs of constant setup-data that will not be altered by the ST library functions they are passed to,
    //                       but none of these are declared const int the ST library function interfaces.
    void MotorImp::vSetUpHardWare() const
    {
        mbsAssert ( mcuGpioStm32f10xConfigure( &rPwm1GpioConfiguration, 1U ) );
        mbsAssert ( mcuGpioStm32f10xConfigure( &rPwm2GpioConfiguration, 1U ) );
        RCC_APB2PeriphClockCmd( cui32PwmTimerClock, ENABLE);
        TIM_TimeBaseInit( const_cast<TIM_TypeDef*>( pPwmTimer ), const_cast<TIM_TimeBaseInitTypeDef*>( &rPwmTimerBaseConfiguration ) );
        TIM_OC1Init( const_cast<TIM_TypeDef*>( pPwmTimer ), const_cast<TIM_OCInitTypeDef*>( &rOutputCompareConfigurationPwmChannels ) );
        TIM_OC1PreloadConfig( const_cast<TIM_TypeDef*>( pPwmTimer ), TIM_OCPreload_Enable );
        TIM_OC2Init( const_cast<TIM_TypeDef*>( pPwmTimer ), const_cast<TIM_OCInitTypeDef*>( &rOutputCompareConfigurationPwmChannels ) );
        TIM_OC2PreloadConfig( const_cast<TIM_TypeDef*>( pPwmTimer ), TIM_OCPreload_Enable );
        TIM_OC3Init( const_cast<TIM_TypeDef*>( pPwmTimer ), const_cast<TIM_OCInitTypeDef*>( &rOutputCompareConfigurationAdcTriggerChannel ) );
        TIM_OC3PreloadConfig( const_cast<TIM_TypeDef*>( pPwmTimer ), TIM_OCPreload_Enable );
        TIM_CtrlPWMOutputs( const_cast<TIM_TypeDef*>( pPwmTimer ), ENABLE );

        TIM_ARRPreloadConfig( const_cast<TIM_TypeDef*>( pPwmTimer ), ENABLE );
        TIM_SelectOutputTrigger( const_cast<TIM_TypeDef*>( pPwmTimer ), TIM_TRGOSource_OC3Ref );

        NVIC_Init( const_cast<NVIC_InitTypeDef*>( &rEndOfAdcIrqConfiguration ) );
        ADC_ClearITPendingBit( const_cast<ADC_TypeDef*>( pAdc ), ADC_IT_EOC );
        ADC_ITConfig( const_cast<ADC_TypeDef*>( pAdc ), ADC_IT_EOC, ENABLE);
        mcuRegisterInterruptHandler ( eAdcInterrupt, vAdcEndOfConversionInterruptHandler, nullptr );

        TIM_Cmd( const_cast<TIM_TypeDef*>( pPwmTimer ), ENABLE );                                                         //lint !e934 !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining TIM2

#ifdef _MOTOR_TEST_
        vEnableMotorTestPinsAndInterrupts ();
#endif
    }

    void MotorImp::vReInitializeStaticMembers() const
    {
        si16LastCurrentInAdQuanta = 4096;
        si16SetCurrentInAdQuanta = 4096;
        si16PwmWidthInTimerTicks = 0;
        eMotorEnable = output::Motor::MOTORDISABLE;
    }

    uint16_t MotorImp::ui16GetCalibrationSampleValue( const uint16_t ui16SampleValue )
    {
        int32_t si32AdSampleValue = static_cast<int32_t>( ui16SampleValue );
        const int32_t csi32Ref2v5RawValue = static_cast<int32_t>( ref2V5VoltAdc->ui16GetRawAdValue() );
        if ( 0 != csi32Ref2v5RawValue )
        {
            if (( csi32Ref2v5RawValue > static_cast<int32_t>( ADC_QUANTA_OF_2V5_WITHIN_3V3 + 20 ))
             || ( csi32Ref2v5RawValue < static_cast<int32_t>( ADC_QUANTA_OF_2V5_WITHIN_3V3 - 20 ))) //out of range to adjust.
            {
                si32AdSampleValue *= static_cast<int32_t>( ADC_QUANTA_OF_2V5_WITHIN_3V3 );
                si32AdSampleValue /= csi32Ref2v5RawValue;
            }

        }
        return static_cast<uint16_t>( si32AdSampleValue );
    }

    int32_t MotorImp::si32UpdateIncrementalPiController()
    {
        const uint8_t  cui8GainTableIndex = static_cast<uint8_t>( mainVoltageAdc->ui16GetRawAdValue()/static_cast<uint8_t>( RAW_UDC_DENOMINATOR ) );
        const uint16_t cui16RawMotorCurrentInAdQuanta1 = ui16GetCalibrationSampleValue( motorCurrent1Adc->ui16GetRawAdValue() - si16Adc1ZeroDrift );
        const uint16_t cui16RawMotorCurrentInAdQuanta2 = ui16GetCalibrationSampleValue( motorCurrent2Adc->ui16GetRawAdValue() - si16Adc2ZeroDrift );

        const uint8_t cui8ProportionalGain = caui8ProportionalGain[cui8GainTableIndex];
        const uint8_t cui8IntegrationFactor = caui8IntegrationFactor[cui8GainTableIndex];

        const int16_t csi16ThisCurrentInAdQuanta = static_cast<int16_t>( cui16RawMotorCurrentInAdQuanta1 )
                                                 + static_cast<int16_t>( cui16RawMotorCurrentInAdQuanta2 );

        // Proportional part of the PI Controller
        int32_t si32PwmWidth = static_cast<int32_t>( static_cast<int32_t>( cui8ProportionalGain ) *
                                                    ( static_cast<int32_t>( si16LastCurrentInAdQuanta ) - csi16ThisCurrentInAdQuanta ) );
        // Intergration part of the PI Controller
        si32PwmWidth += static_cast<int32_t>( static_cast<int32_t>( cui8IntegrationFactor ) *
                                             ( static_cast<int32_t>( si16SetCurrentInAdQuanta ) - csi16ThisCurrentInAdQuanta ) );
        si32PwmWidth += outputInternal::SCALE_FACTOR/2; // Add one half to round up in next division
        si32PwmWidth /= outputInternal::SCALE_FACTOR;   // Divide by scale-factor
        si16LastCurrentInAdQuanta = csi16ThisCurrentInAdQuanta;
        return si32PwmWidth;
    }

    void MotorImp::vIncrementAndLimitPwmWidth( const int32_t csi32RequestedPwmWidthIncrement )
    {
        if ( csi16MinPwmWidth > ( csi32RequestedPwmWidthIncrement + si16PwmWidthInTimerTicks ) )
        {
            si16PwmWidthInTimerTicks = csi16MinPwmWidth;
        }
        else if ( csi16MaxPwmWidth < ( csi32RequestedPwmWidthIncrement + si16PwmWidthInTimerTicks ) )
        {
            si16PwmWidthInTimerTicks = csi16MaxPwmWidth;
        }
        else
        {
            si16PwmWidthInTimerTicks += static_cast<int16_t>( csi32RequestedPwmWidthIncrement );
        }
    }

    void MotorImp::vPlaceAdTriggerAndSetOutputRegistersWhenTheMotorIsEnabled()
    {
        //when closing, drive out1~>out2; need cc1 < cc2; define tick negative, so to add+tick.
        const int16_t csi16CC1RegisterSetting = csi16ZeroOutputPwmTick + si16PwmWidthInTimerTicks;
        const int16_t csi16CC2RegisterSetting = csi16ZeroOutputPwmTick - si16PwmWidthInTimerTicks;
        int16_t       si16CC3RegisterSetting;

        if ( csi16HalfOutputPwmTick < si16PwmWidthInTimerTicks )
        {
            si16CC3RegisterSetting = csi16CC2RegisterSetting + static_cast<int16_t>( cui16AdTriggerDelay );
        }
        else if ( 0 < si16PwmWidthInTimerTicks )
        {
            si16CC3RegisterSetting = csi16CC1RegisterSetting + static_cast<int16_t>( cui16AdTriggerDelay );
        }
        else if ( -csi16HalfOutputPwmTick < si16PwmWidthInTimerTicks )
        {
            si16CC3RegisterSetting = csi16CC2RegisterSetting + static_cast<int16_t>( cui16AdTriggerDelay );
        }
        else
        {
            si16CC3RegisterSetting = csi16CC1RegisterSetting + static_cast<int16_t>( cui16AdTriggerDelay );
        }

        //lint -e(1960,9005,929) pPwmTimer has a constant address to the register map of the used peripheral, and will not be altered in the TIM_SetCompare1 function
        TIM_SetCompare1( const_cast<TIM_TypeDef*>( pPwmTimer ), static_cast<uint16_t>( csi16CC1RegisterSetting ) );
        //lint -e(1960,9005,929) pPwmTimer has a constant address to the register map of the used peripheral, and will not be altered in the TIM_SetCompare2 function
        TIM_SetCompare2( const_cast<TIM_TypeDef*>( pPwmTimer ), static_cast<uint16_t>( csi16CC2RegisterSetting ) );
        //lint -e(1960,9005,929) pPwmTimer has a constant address to the register map of the used peripheral, and will not be altered in the TIM_SetCompare3 function
        TIM_SetCompare3( const_cast<TIM_TypeDef*>( pPwmTimer ), static_cast<uint16_t>( si16CC3RegisterSetting ) );

    }

    void MotorImp::vSetOutputRegistersAndControllerStatesWhenTheMotorIsDisabled()
    {
//        TIM_GenerateEvent(const_cast<TIM_TypeDef*>( pPwmTimer),1U);
        //lint -e(1960,9005,929) pPwmTimer has a constant address to the register map of the used peripheral, and will not be altered in the TIM_SetCompare1 function
        TIM_SetCompare1( const_cast<TIM_TypeDef*>( pPwmTimer ), static_cast<uint16_t>( csi16ZeroOutputPwmTick ) );
        //lint -e(1960,9005,929) pPwmTimer has a constant address to the register map of the used peripheral, and will not be altered in the TIM_SetCompare2 function
        TIM_SetCompare2( const_cast<TIM_TypeDef*>( pPwmTimer ), static_cast<uint16_t>( csi16ZeroOutputPwmTick ) );
        //lint -e(1960,9005,929) pPwmTimer has a constant address to the register map of the used peripheral, and will not be altered in the TIM_SetCompare3 function
        TIM_SetCompare3( const_cast<TIM_TypeDef*>( pPwmTimer ), ( static_cast<uint16_t>( csi16ZeroOutputPwmTick ) + cui16AdTriggerDelay ) );

        si16LastCurrentInAdQuanta = 4096;
        si16SetCurrentInAdQuanta = 4096;
        si16PwmWidthInTimerTicks = 0;

    }

    void MotorImp::vSampleAndFilterAdObjects()
    {
        for ( uint8_t ui8Index = 0U; ui8Index < static_cast<uint8_t>( NUMBER_OF_ADC_OBJECTS ); ui8Index++ )
        {
            adcObject[ui8Index]->vSampleAndFilter();
        }
    }

    MotorImp::~MotorImp()
    {

    }
}

namespace output
{
    output::Motor::~Motor()
    {
        // C++ demands that a pure virtual destructor has an implementation
    }
}


#ifdef _MOTOR_TEST_
namespace outputInternal
{
    void MotorImp::vPwmTimerUpdateInterruptHandler ( void* param )
    {

        TIM_ClearITPendingBit( const_cast<TIM_TypeDef*>( pPwmTimer ), ui16PwmTimerUpdateInterruptSource );
        pwmTimerUpdatePin->vTogglePin();
    }

    void MotorImp::vAdConversionTriggerInterruptHandler ( void* param )
    {
        TIM_ClearITPendingBit( const_cast<TIM_TypeDef*>( pPwmTimer ), ui16AdTriggerInterruptSource );
        adConversionActivePin->vSetPin();
    }

    void MotorImp::vEnableMotorTestPinsAndInterrupts ()
    {
        /* Enable timer update output pin and interrupt */
        if ( pwmTimerUpdatePin == nullptr )
        {
            pwmTimerUpdatePin = new testInternal::GpioTestPin( ePwmTimerUpdatePin );
        }
        mcuRegisterInterruptHandler( ePwmTimerUpdateInterrupt, vPwmTimerUpdateInterruptHandler, nullptr );
        NVIC_Init( const_cast<NVIC_InitTypeDef*>( &rPwmTimerUpdateInterruptConfiguration ) );
        TIM_ClearITPendingBit( const_cast<TIM_TypeDef*>( pPwmTimer ), ui16PwmTimerUpdateInterruptSource );
        TIM_ITConfig( const_cast<TIM_TypeDef*>( pPwmTimer ), ui16PwmTimerUpdateInterruptSource, ENABLE );

        /* Enable adc trigger output pin and interrupt */
        if ( adConversionActivePin == nullptr )
        {
            adConversionActivePin = new testInternal::GpioTestPin( eAdConversionActivePin );
        }
        mcuRegisterInterruptHandler( eAdcStartTriggerInterrupt, vAdConversionTriggerInterruptHandler, nullptr );
        NVIC_Init( const_cast<NVIC_InitTypeDef*>( &rAdTriggerInterruptConfiguration ) );
        TIM_ClearITPendingBit( const_cast<TIM_TypeDef*>( pPwmTimer ), ui16AdTriggerInterruptSource );
        TIM_ITConfig( const_cast<TIM_TypeDef*>( pPwmTimer ), ui16AdTriggerInterruptSource, ENABLE );
    }

    const McuInterrupt     MotorImp::ePwmTimerUpdateInterrupt = IRQ_TIM8_UP_IRQHandler;
    const NVIC_InitTypeDef MotorImp::rPwmTimerUpdateInterruptConfiguration = { /* NVIC_IRQChannel                   */ static_cast<uint8_t>( TIM8_UP_IRQn ),
                                                                               /* NVIC_IRQChannelPreemptionPriority */ 1U,
                                                                               /* NVIC_IRQChannelSubPriority        */ 0U,
                                                                               /* NVIC_IRQChannelCmd                */ ENABLE };
    const uint16_t         MotorImp::ui16PwmTimerUpdateInterruptSource = TIM_IT_Update;
    testInternal::GpioTestPin* MotorImp::pwmTimerUpdatePin = nullptr;
    const testInternal::GpioTestPin::teTestPinType MotorImp::ePwmTimerUpdatePin = testInternal::GpioTestPin::JTDO;

    const McuInterrupt     MotorImp::eAdcStartTriggerInterrupt = IRQ_TIM8_CC_IRQHandler;
    const NVIC_InitTypeDef MotorImp::rAdTriggerInterruptConfiguration = { /* NVIC_IRQChannel                   */ static_cast<uint8_t>( TIM8_CC_IRQn ),
                                                                          /* NVIC_IRQChannelPreemptionPriority */ 1U,
                                                                          /* NVIC_IRQChannelSubPriority        */ 0U,
                                                                          /* NVIC_IRQChannelCmd                */ ENABLE };
    const uint16_t         MotorImp::ui16AdTriggerInterruptSource = TIM_IT_CC3;
    testInternal::GpioTestPin* MotorImp::adConversionActivePin = nullptr;
    const testInternal::GpioTestPin::teTestPinType MotorImp::eAdConversionActivePin = testInternal::GpioTestPin::JTDI;

}
#endif
/**
  \}
 */

//lint -e1960 "function without external side-effects" Functions write to register map
