/**
  \file input.cpp

  \par Copyright &copy; 2017 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \addtogroup Input
  \{
 */
extern "C" {
    #include <FreeRTOS.h>
    #include <task.h>
    #include <mbsLog.h>
    #include <systemControlRegistration.h>
}
#include "mbsCfgTask.h"
#include "input.hpp"
#include "inputBackEnd.hpp"
#include "digitalInputImp.hpp"
#include "adcInputImp.hpp"
#include "encoderImp.hpp"
#include "eventTimerImp.hpp"
#include "messageRouterImp.hpp"
#include "systemConfiguration.hpp"

#include "messageIds.h"
#include "message_system_monitor_status.hpp"
#include "layerUds.hpp"
#include "diagnostics.hpp"
#include "diagUnitSpecific.h"

#include "unused.h"

#include "taskHandler.hpp"

using namespace messages;

namespace inputInternal
{
    const int16_t si16AdcMaxValue = static_cast<int16_t>(4095);                 // 12bits max value
    const int16_t si16AdcRefVolt = static_cast<int16_t>(3300);                  // milliVolt 3300mV used as referernce from Hw team

    // Following two defines are taken from STM32F103 data sheet.
//  const int16_t si16TempSensor25dgVolt = static_cast<int16_t>(1430);          // Measured voltage @ 25 degC according to data sheet: 1430mV
//  const int16_t si16TemSensorSlope  = static_cast<int16_t>(43);               // Average slope according to data sheet: 4.3mV/degC => 43mv/centidegC

    const int16_t si16CurrentSens = static_cast<int16_t>(90);                   // 90mV/A
    const int16_t si16ZeroAmpVolt = static_cast<int16_t>(1710);                 // 1710mV

//  const int16_t chipTempAdcScaleFactor = (static_cast<int16_t>(-3300));
//  const int16_t chipTempAdcScaleDenominator = (static_cast<int16_t>( (si16AdcMaxValue / 10) * si16TemSensorSlope));
//  const int32_t chipTempAdcOffset = (static_cast<int32_t>(((-25-si16TempSensor25dgVolt) / si16TemSensorSlope) * 10));

//  const int16_t refVoltAdcScaleFactor = static_cast<int16_t>(si16AdcRefVolt);
//  const int16_t refVoltAdcScaleDenominator = si16AdcMaxValue;
//  const int32_t refVoltAdcOffset = 0;

    // The main 24V is scaled from 0 to 3300*(130 + 8.2)/8.2 mv over the dynamic range of the ADC (12 bits)
    // The product 4095*8.2 = 33579 is rounded up to 33580 to provide a better GCD.
    // The scaleFactor and denominator are divided by their greatest common denominator, which is 20.
    // 22803/1678.95 = 13.5817  22803/1679 = 13.5813 -> 0.003 % error, which should be negligible
    const int16_t mainVoltAdcScaleFactor = static_cast<int16_t>( 22803 );    // 3300*(130 + 8.2) / 20 = 22803
    const int16_t mainVoltAdcScaleDenominator = static_cast<int16_t>( 1679 );// 4095*8.2 / 20 = 1678.95
    const int32_t mainVoltAdcOffset = 0;

    const int16_t ref2V5VoltAdcScaleFactor = static_cast<int16_t>(si16AdcRefVolt);
    const int16_t ref2V5VoltAdcScaleDenominator = si16AdcMaxValue;
    const int32_t ref2V5VoltAdcOffset = 0;

    const int16_t ref5V0VoltAdcScaleFactor = static_cast<int16_t>(si16AdcRefVolt * 2); // 2 means 200kohm/10kohm/10 = 20/10;
    const int16_t ref5V0VoltAdcScaleDenominator = si16AdcMaxValue;
    const int32_t ref5V0VoltAdcOffset = 0;

    const int16_t hwVersion1ScaleFactor = static_cast<int16_t>(si16AdcRefVolt);
    const int16_t hwVersion1ScaleDenominator = si16AdcMaxValue;
    const int32_t hwVersion1Offset = 0;

    const int16_t hwVersion2ScaleFactor = static_cast<int16_t>(si16AdcRefVolt);
    const int16_t hwVersion2ScaleDenominator = si16AdcMaxValue;
    const int32_t hwVersion2Offset = 0;

    const int16_t encoderVoltAdcScaleFactor = static_cast<int16_t>(si16AdcRefVolt * 2); // 2 means 20kohm/10kohm
    const int16_t encoderVoltAdcScaleDenominator = si16AdcMaxValue;
    const int32_t encoderVoltAdcOffset = 0;

    // The brakeChopVoltage has the same hw measurement setup as main 24V.
    // It is scaled from 0 to 3300*(130 + 8.2)/8.2 mv over the dynamic range of the ADC (12 bits)
    const int16_t brakeChopVoltAdcScaleFactor = mainVoltAdcScaleFactor;
    const int16_t brakeChopVoltAdcScaleDenominator = mainVoltAdcScaleDenominator;
    const int32_t brakeChopVoltAdcOffset = 0;

    // The motor voltages have the same hw measurement setup as main 24V.
    // They are scaled from 0 to 3300*(130 + 8.2)/8.2 mv over the dynamic range of the ADC (12 bits)
    const int16_t motorVolt1AdcScaleFactor = mainVoltAdcScaleFactor;
    const int16_t motorVolt1AdcScaleDenominator = mainVoltAdcScaleDenominator;
    const int32_t motorVolt1AdcOffset = 0;

    const int16_t motorVolt2AdcScaleFactor = mainVoltAdcScaleFactor;
    const int16_t motorVolt2AdcScaleDenominator = mainVoltAdcScaleDenominator;
    const int32_t motorVolt2AdcOffset = 0;

    const int16_t motorCurrent1AdcScaleFactor = static_cast<int16_t>(19000);                                    // 1710(mV)/90(mV/A)*1000 = 19000mA
    const int16_t motorCurrent1AdcScaleDenominator = static_cast<int16_t>(si16AdcMaxValue/2);
    const int32_t motorCurrent1AdcOffset = (si16ZeroAmpVolt/si16CurrentSens)*static_cast<int16_t>(1000);

    const int16_t motorCurrent2AdcScaleFactor = motorCurrent1AdcScaleFactor;
    const int16_t motorCurrent2AdcScaleDenominator = motorCurrent1AdcScaleDenominator;
    const int32_t motorCurrent2AdcOffset = motorCurrent1AdcOffset;


    //lint -e(9084) Result of the assignment operator is NOT used in larger expression
    static messages::MessageRouter* const pMessageRouter = new messagesInternal::MessageRouterImp(
            messagesInternal::cui8NumberOfReceivers, MBS_MSG_ADDRESS_UNKNOWN );

    /*
     * The DigitalInputImp constructor is called in the following way:
     * DigitalInputImp name( gpio            - GPIO group that the physical pin belongs to, gpioWrapper::GPIO_A - gpioWrapper::GPIO_F
     *                       mode            - Input mode of the pin , can be IN_FLOATING, IPU or IPD
     *                       pin             - the pin number within the group, 0 - 15
     *                       speed           - can be any of GPIO_Speed_2MHz, GPIO_Speed_10MHz or GPIO_Speed_50MHz
     *                       messageRouter   - a pointer to the input instantiation of the messageRouter
     *                       messageIdentity - The Message ID to be used when transmitting events from this pin.
     *                       polarity        - Either ACTIVE_HIGH or ACTIVE_LOW
     *                       filt_active     - filter length for going from state inactive to active. 0-255
     *                       filt_inactive   - filter length for going from state active to inactive. 0-255 )
     */
    //! The input Objects are singletons that are implemented as global objects. The initialization
    //! is handled in the constructor. this will ensure that they are initialized
    //! before they are used.
    static volatile DigitalInputImp learnImp( /* GPIO group */gpioWrapper::GPIO_D,
    /* mode */GPIO_Mode_IN_FLOATING,
    /* pin  */static_cast<uint16_t>( GPIO_Pin_2 ),
    /* speed */GPIO_Speed_2MHz,
    /* polarity */input::DigitalInput::ACTIVE_LOW,
    /* messageRouter* */pMessageRouter,
    /* inputMessageType */ input::DigitalInput::MESSAGE_TYPE_BUTTON,
    /* messageIdentity */messages::LEARN_BUTTON,
    /* filt_active */2U,
    /* filt_inactive */2U );
}

namespace input
{
    volatile DigitalInput* const learn = &inputInternal::learnImp;
}


/*
 * The ADCInputImp constructor is called in the following way:
 * ADCInputImp name    ( gpio          - GPIO group that the physical pin belongs to, gpioWrapper::GPIO_A - gpioWrapper::GPIO_F
 *                       pin           - the pin number within the group, 0 - 15
 *                       adc           - ADC group that the physical pin belongs to, gpioWrapper::ADC_1 - gpioWrapper::ADC_3
 *                       sample_time   - can be any of                              14MHZ       12MHZ(selected)
 *                                          ADC_SampleTime_1Cycles5                 1us         1.166
                                            ADC_SampleTime_7Cycles5                 1.428us     1.66
                                            ADC_SampleTime_13Cycles5                1.857us     2.16
                                            ADC_SampleTime_28Cycles5                2.928us     3.416
                                            ADC_SampleTime_41Cycles5                3.856us     4.5
                                            ADC_SampleTime_55Cycles5                4.856us     5.66
                                            ADC_SampleTime_71Cycles5                6us         7us
                                            ADC_SampleTime_239Cycles5               18us        21us
 *                       channel       - ADC channel, can be any of ADC_Channel_0~ADC_Channel_17
 *                       minValue      - minimum value
 *                       maxValue      - maximum value
 *                       index         - index in the dma reading buffer
 *                       factor        - scale factor
 *                       denominator   - scale denominator
 *                       offset        - offset value )
 */
//! The input Objects are singletons that are implemented as global objects. The initialization
//! is handled in the constructor. this will ensure that they are initialized
//! before they are used.

namespace inputInternal
{
    static volatile ADCInputImp mainVoltAdcImp (/* GPIO group */        gpioWrapper::GPIO_A,
                                                /* pin  */              static_cast<uint16_t>( GPIO_Pin_3 ),
                                                /* ADC group */         adcWrapper::ADC_1,
                                                /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                /* ADC channel */       ADC_Channel_3,
                                                /* index*/              static_cast<uint8_t>( 0 ),
                                                /* ScaleFactor*/        mainVoltAdcScaleFactor,
                                                /* ScaleDenominator*/   mainVoltAdcScaleDenominator,
                                                /* offset*/             mainVoltAdcOffset,
                                                /* filter shift*/       2U,
                                                /* messageRouter*/      pMessageRouter);


    static volatile ADCInputImp motorAmp1AdcImp   ( /* GPIO group */        gpioWrapper::GPIO_C,
                                                    /* pin  */              static_cast<uint16_t>( GPIO_Pin_0 ),
                                                    /* ADC group */         adcWrapper::ADC_1,
                                                    /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                    /* ADC channel */       ADC_Channel_10,
                                                    /* index*/              static_cast<uint8_t>( 1 ),
                                                    /* ScaleFactor*/        motorCurrent1AdcScaleFactor,
                                                    /* ScaleDenominator*/   motorCurrent1AdcScaleDenominator,
                                                    /* offset*/             motorCurrent1AdcOffset,
                                                    /* filter shift*/       2U,
                                                    /* messageRouter*/      pMessageRouter);

    static volatile ADCInputImp motorAmp2AdcImp (   /* GPIO group */        gpioWrapper::GPIO_C,
                                                    /* pin  */              static_cast<uint16_t>( GPIO_Pin_2 ),
                                                    /* ADC group */         adcWrapper::ADC_1,
                                                    /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                    /* ADC channel */       ADC_Channel_12,
                                                    /* index*/              static_cast<uint8_t>( 2 ),
                                                    /* ScaleFactor*/        motorCurrent2AdcScaleFactor,
                                                    /* ScaleDenominator*/   motorCurrent2AdcScaleDenominator,
                                                    /* offset*/             motorCurrent2AdcOffset,
                                                    /* filter shift*/       2U,
                                                    /* messageRouter*/      pMessageRouter);

    static volatile ADCInputImp ref2V5VoltAdcImp   (/* GPIO group */        gpioWrapper::GPIO_A,
                                                    /* pin  */              static_cast<uint16_t>( GPIO_Pin_6 ),
                                                    /* ADC group */         adcWrapper::ADC_1,
                                                    /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                    /* ADC channel */       ADC_Channel_6,
                                                    /* index*/              static_cast<uint8_t>( 3 ),
                                                    /* ScaleFactor*/        ref2V5VoltAdcScaleFactor,
                                                    /* ScaleDenominator*/   ref2V5VoltAdcScaleDenominator,
                                                    /* offset*/             ref2V5VoltAdcOffset,
                                                    /* filter shift*/       2U,
                                                    /* messageRouter*/      pMessageRouter);

    static volatile ADCInputImp ref5V0VoltAdcImp   (/* GPIO group */        gpioWrapper::GPIO_A,
                                                    /* pin  */              static_cast<uint16_t>( GPIO_Pin_1 ),
                                                    /* ADC group */         adcWrapper::ADC_1,
                                                    /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                    /* ADC channel */       ADC_Channel_1,
                                                    /* index*/              static_cast<uint8_t>( 4 ),
                                                    /* ScaleFactor*/        ref5V0VoltAdcScaleFactor,
                                                    /* ScaleDenominator*/   ref5V0VoltAdcScaleDenominator,
                                                    /* offset*/             ref5V0VoltAdcOffset,
                                                    /* filter shift*/       2U,
                                                    /* messageRouter*/      pMessageRouter);

    static volatile ADCInputImp hwVersion1AdcImp   (/* GPIO group */        gpioWrapper::GPIO_B,
                                                    /* pin  */              static_cast<uint16_t>( GPIO_Pin_0 ),
                                                    /* ADC group */         adcWrapper::ADC_1,
                                                    /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                    /* ADC channel */       ADC_Channel_8,
                                                    /* index*/              static_cast<uint8_t>( 5 ),
                                                    /* ScaleFactor*/        hwVersion1ScaleFactor,
                                                    /* ScaleDenominator*/   hwVersion1ScaleDenominator,
                                                    /* offset*/             hwVersion1Offset,
                                                    /* filter shift*/       2U,
                                                    /* messageRouter*/      pMessageRouter);


    static volatile ADCInputImp encoderVoltAdcImp  (/* GPIO group */        gpioWrapper::GPIO_A,
                                                    /* pin  */              static_cast<uint16_t>( GPIO_Pin_4 ),
                                                    /* ADC group */         adcWrapper::ADC_1,
                                                    /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                    /* ADC channel */       ADC_Channel_4,
                                                    /* index*/              static_cast<uint8_t>( 6 ),
                                                    /* ScaleFactor*/        encoderVoltAdcScaleFactor,
                                                    /* ScaleDenominator*/   encoderVoltAdcScaleDenominator,
                                                    /* offset*/             encoderVoltAdcOffset,
                                                    /* filter shift*/       2U,
                                                    /* messageRouter*/      pMessageRouter);


    static volatile ADCInputImp brakeChopVoltAdcImp(/* GPIO group */        gpioWrapper::GPIO_A,
                                                    /* pin  */              static_cast<uint16_t>( GPIO_Pin_0 ),
                                                    /* ADC group */         adcWrapper::ADC_1,
                                                    /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                    /* ADC channel */       ADC_Channel_0,
                                                    /* index*/              static_cast<uint8_t>( 7 ),
                                                    /* ScaleFactor*/        brakeChopVoltAdcScaleFactor,
                                                    /* ScaleDenominator*/   brakeChopVoltAdcScaleDenominator,
                                                    /* offset*/             brakeChopVoltAdcOffset,
                                                    /* filter shift*/       2U,
                                                    /* messageRouter*/      pMessageRouter);


    static volatile ADCInputImp motorVolt1AdcImp   (/* GPIO group */        gpioWrapper::GPIO_C,
                                                    /* pin  */              static_cast<uint16_t>( GPIO_Pin_1 ),
                                                    /* ADC group */         adcWrapper::ADC_1,
                                                    /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                    /* ADC channel */       ADC_Channel_11,
                                                    /* index*/              static_cast<uint8_t>( 8 ),
                                                    /* ScaleFactor*/        motorVolt1AdcScaleFactor,
                                                    /* ScaleDenominator*/   motorVolt1AdcScaleDenominator,
                                                    /* offset*/             motorVolt1AdcOffset,
                                                    /* filter shift*/       2U,
                                                    /* messageRouter*/      pMessageRouter);

    static volatile ADCInputImp motorVolt2AdcImp   (/* GPIO group */        gpioWrapper::GPIO_C,
                                                    /* pin  */              static_cast<uint16_t>( GPIO_Pin_3 ),
                                                    /* ADC group */         adcWrapper::ADC_1,
                                                    /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                    /* ADC channel */       ADC_Channel_13,
                                                    /* index*/              static_cast<uint8_t>( 9 ),
                                                    /* ScaleFactor*/        motorVolt2AdcScaleFactor,
                                                    /* ScaleDenominator*/   motorVolt2AdcScaleDenominator,
                                                    /* offset*/             motorVolt2AdcOffset,
                                                    /* filter shift*/       2U,
                                                    /* messageRouter*/      pMessageRouter);

    static volatile ADCInputImp hwVersion2AdcImp   (/* GPIO group */        gpioWrapper::GPIO_C,
                                                    /* pin  */              static_cast<uint16_t>( GPIO_Pin_4 ),
                                                    /* ADC group */         adcWrapper::ADC_1,
                                                    /* ADC sample time*/    ADC_SampleTime_1Cycles5,
                                                    /* ADC channel */       ADC_Channel_14,
                                                    /* index*/              static_cast<uint8_t>( 10 ),
                                                    /* ScaleFactor*/        hwVersion2ScaleFactor,
                                                    /* ScaleDenominator*/   hwVersion2ScaleDenominator,
                                                    /* offset*/             hwVersion2Offset,
                                                    /* filter shift*/       2U,
                                                    /* messageRouter*/      pMessageRouter);

    static volatile ADCInputAbsDiffImp mainVoltageDiffImp(
                                                    /*mainVoltage*/         input::mainVoltAdc,
                                                    /*brakeChopVoltage*/    input::brakeChopVoltAdc,
                                                    /*messageRouter*/       pMessageRouter);

    static volatile ADCInputProductImp motorVoltXAmpImp(
                                                    /**/                            input::motorVolt1Adc,
                                                    /*scale factor for volt*/       1000,               //TODO factors
                                                    /**/                            input::motorAmp1Adc,
                                                    /*scale factor for current*/    1000,               //TODO factors
                                                    /*scale factor for prod*/       1,                   //TODO factors
                                                    /*messageRouter*/               pMessageRouter);

    static volatile ADCInputProductImp motorAmpSquareImp(
                                                    /**/                            input::motorAmp1Adc,
                                                    /*scale factor for volt*/       1,
                                                    /**/                            input::motorAmp1Adc,
                                                    /*scale factor for current*/    1,
                                                    /*scale factor for prod*/       1,
                                                    /*messageRouter*/               pMessageRouter);
}

namespace inputBackEnd
{
    volatile inputInternal::AdcInputBackEnd* const mainVoltAdc = &inputInternal::mainVoltAdcImp;
    volatile inputInternal::AdcInputBackEnd* const motorCurrent1Adc = &inputInternal::motorAmp1AdcImp;
    volatile inputInternal::AdcInputBackEnd* const motorCurrent2Adc = &inputInternal::motorAmp2AdcImp;
    volatile inputInternal::AdcInputBackEnd* const motorVolt1AdcBackEnd = &inputInternal::motorVolt1AdcImp;
    volatile inputInternal::AdcInputBackEnd* const motorVolt2AdcBackEnd = &inputInternal::motorVolt2AdcImp;
    volatile inputInternal::AdcInputBackEnd* const encoderVoltAdcBackEnd = &inputInternal::encoderVoltAdcImp;
    volatile inputInternal::AdcInputBackEnd* const brakeChopVoltAdcBackEnd = &inputInternal::brakeChopVoltAdcImp;
    volatile inputInternal::AdcInputBackEnd* const ref2V5VoltAdcBackEnd = &inputInternal::ref2V5VoltAdcImp;
    volatile inputInternal::AdcInputBackEnd* const ref5V0VoltAdcBackEnd = &inputInternal::ref5V0VoltAdcImp;
    volatile inputInternal::AdcInputBackEnd* const hwVersion1AdcBackEnd = &inputInternal::hwVersion1AdcImp;
    volatile inputInternal::AdcInputBackEnd* const hwVersion2AdcBackEnd = &inputInternal::hwVersion2AdcImp;
}

namespace input
{
    volatile ADCInput* const mainVoltAdc= &inputInternal::mainVoltAdcImp;
    volatile ADCInput* const ref2V5VoltAdc= &inputInternal::ref2V5VoltAdcImp;
    volatile ADCInput* const ref5V0VoltAdc= &inputInternal::ref5V0VoltAdcImp;
    volatile ADCInput* const encoderVoltAdc= &inputInternal::encoderVoltAdcImp;
    volatile ADCInput* const brakeChopVoltAdc= &inputInternal::brakeChopVoltAdcImp;
    volatile ADCInput* const motorVolt1Adc= &inputInternal::motorVolt1AdcImp;
    volatile ADCInput* const motorVolt2Adc= &inputInternal::motorVolt2AdcImp;
    volatile ADCInput* const motorAmp1Adc= &inputInternal::motorAmp1AdcImp;
    volatile ADCInput* const motorAmp2Adc= &inputInternal::motorAmp2AdcImp;
    volatile ADCInput* const mainVoltageDiff = &inputInternal::mainVoltageDiffImp;
    volatile ADCInput* const motorVoltXAmp   = &inputInternal::motorVoltXAmpImp;
    volatile ADCInput* const motorAmpSquare   = &inputInternal::motorAmpSquareImp;
}

namespace inputInternal
{
    static volatile ADCInputAbsDiffImp motorAmpDiffAdcImp(input::motorAmp1Adc, input::motorAmp2Adc, pMessageRouter);
    static volatile ADCInputRelDiffImp encoderVoltageTo5V0DiffImp(input::ref5V0VoltAdc, input::encoderVoltAdc, pMessageRouter);
    static volatile ADCInputRelDiffImp motorVoltAdcImp(input::motorVolt1Adc, input::motorVolt2Adc, pMessageRouter);
    static volatile ADCInputRelDiffImp voltBetweenUdcAndMotor1Imp(input::motorVolt1Adc,input::mainVoltAdc,  pMessageRouter);
}

namespace input
{
    volatile ADCInput* const motorAmpDiffAdc= &inputInternal::motorAmpDiffAdcImp;
    volatile ADCInput* const encoderTo5v0AdcDiff = &inputInternal::encoderVoltageTo5V0DiffImp;
    volatile ADCInput* const motorVoltAdc = &inputInternal::motorVoltAdcImp;
    volatile ADCInput* const voltBetweenUdcAndMotor1 = &inputInternal::voltBetweenUdcAndMotor1Imp;
}

namespace inputInternal
{
    static volatile ADCInputAbsDiffImp motorVoltDiffAdcImp(input::voltBetweenUdcAndMotor1, input::motorVolt2Adc, pMessageRouter);
}

namespace input
{
    volatile ADCInput* const motorVoltDiffAdc= &inputInternal::motorVoltDiffAdcImp;
}

namespace inputInternal
{

    static volatile EncoderImp motorEncoderImp( /* resolution*/          100U,
                                                /* motor direction*/     motorWrapper::CCW,
                                                /* message router*/      pMessageRouter);
}

namespace input
{
    volatile Encoder * const motorEncoder = &inputInternal::motorEncoderImp;
}

namespace inputInternal
{
    static volatile EventTimerImp motionControlAppSendDoorAngleTimerImp( /* pMessageRouter */          pMessageRouter,
                                                                        /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::MOTION_CONTROL_EVENT_TIMEOUT ), /* todo */
                                                                        /* cui8TimerEventId */        static_cast<uint8_t>( input::SEND_DOOR_ANGLE_REPETITION_TIMER_ID ) );

    static volatile EventTimerImp motionControlTransitionDelayTimerImp( /* pMessageRouter */          pMessageRouter,
                                                                        /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::MOTION_CONTROL_EVENT_TIMEOUT ),
                                                                        /* cui8TimerEventId */        static_cast<uint8_t>( input::MOTION_CONTROL_TRANSITION_DELAY_TIMER_ID ) );

    static volatile EventTimerImp closedPositionControlReleaseTensionDelayTimerImp( /* pMessageRouter */          pMessageRouter,
                                                                                    /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::MOTION_CONTROL_EVENT_TIMEOUT ),
                                                                                    /* cui8TimerEventId */        static_cast<uint8_t>( input::CLOSED_POSITION_CONTROL_RELEASE_TENSION_DELAY_TIMER_ID ) );

    static volatile EventTimerImp closedPositionControlClosingSpeedDelayTimerImp( /* pMessageRouter */          pMessageRouter,
                                                                                  /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::MOTION_CONTROL_EVENT_TIMEOUT ),
                                                                                  /* cui8TimerEventId */        static_cast<uint8_t>( input::CLOSED_POSITION_CONTROL_CLOSING_SPEED_DELAY_TIMER_ID ) );

    static volatile EventTimerImp closedPositionControlExcessiveClosingSpeedDelayTimerImp( /* pMessageRouter */          pMessageRouter,
                                                                                           /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::MOTION_CONTROL_EVENT_TIMEOUT ),
                                                                                           /* cui8TimerEventId */        static_cast<uint8_t>( input::CLOSED_POSITION_CONTROL_EXCESSIVE_CLOSING_SPEED_DELAY_TIMER_ID ) );

    static volatile EventTimerImp openCommandDriftCompensationIntervalTimerImp( /* pMessageRouter */          pMessageRouter,
                                                                                /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::MOTION_CONTROL_EVENT_TIMEOUT ),
                                                                                /* cui8TimerEventId */        static_cast<uint8_t>( input::OPEN_COMMAND_DRIFT_COMPENSATION_TIMER_DELAY_ID ) );

    static volatile EventTimerImp learnCommandErrorTimeoutTimerImp( /* pMessageRouter */          pMessageRouter,
                                                                    /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::MOTION_CONTROL_EVENT_TIMEOUT ),
                                                                    /* cui8TimerEventId */        static_cast<uint8_t>( input::LEARN_COMMAND_ERROR_TIMEOUT_TIMER_ID ) );

    static volatile EventTimerImp encoderConnectTimerImp( /* pMessageRouter */          pMessageRouter,
                                                          /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::SYSTEM_MONITOR_EVENT_TIMEOUT ),
                                                          /* cui8TimerEventId */        static_cast<uint8_t>( input::ENCODER_CONNECT_TIMER_ID ) );

    static volatile EventTimerImp encoderMonitorIntervalTimerImp( /* pMessageRouter */          pMessageRouter,
                                                                  /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::SYSTEM_MONITOR_EVENT_TIMEOUT ),
                                                                  /* cui8TimerEventId */        static_cast<uint8_t>( input::ENCODER_MONITOR_TIMER_ID ) );

    static volatile EventTimerImp mainVoltMonitorIntervalTimerImp( /* pMessageRouter */          pMessageRouter,
                                                                   /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::SYSTEM_MONITOR_EVENT_TIMEOUT ),
                                                                   /* cui8TimerEventId */        static_cast<uint8_t>( input::MAINVOLT_MONITOR_TIMER_ID ) );

    static volatile EventTimerImp motorMonitorTimerImp( /* pMessageRouter */          pMessageRouter,
                                                        /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::SYSTEM_MONITOR_EVENT_TIMEOUT ),
                                                        /* cui8TimerEventId */        static_cast<uint8_t>( input::MOTOR_MONITOR_TIMER_ID ) );


    static volatile EventTimerImp motorBoardRedLedTimerImp( /* pMessageRouter */      pMessageRouter,
                                                        /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::SYSTEM_MONITOR_EVENT_TIMEOUT ),
                                                        /* cui8TimerEventId */        static_cast<uint8_t>( input::MOTOR_BOARD_RED_LED_TIMER_ID ) );

    static volatile EventTimerImp statisticsManagerTimerImp( /* pMessageRouter */          pMessageRouter,
                                                             /* cui8EventTimerMessageId */ static_cast<uint8_t>( messages::STATISTICS_AND_LOG_EVENT_TIMEOUT ),
                                                             /* cui8TimerEventId */        static_cast<uint8_t>( input::STATISTICS_MANAGER_TIMER_ID ) );
}

namespace input
{
    volatile EventTimer* const motionControlAppSendDoorAngleTimer                   = &inputInternal::motionControlAppSendDoorAngleTimerImp;
    volatile EventTimer* const motionControlTransitionDelayTimer                    = &inputInternal::motionControlTransitionDelayTimerImp;
    volatile EventTimer* const closedPositionControlReleaseTensionDelayTimer        = &inputInternal::closedPositionControlReleaseTensionDelayTimerImp;
    volatile EventTimer* const closedPositionControlClosingSpeedDelayTimer          = &inputInternal::closedPositionControlClosingSpeedDelayTimerImp;
    volatile EventTimer* const closedPositionControlExcessiveClosingSpeedDelayTimer = &inputInternal::closedPositionControlExcessiveClosingSpeedDelayTimerImp;
    volatile EventTimer* const OpenCommandDriftCompensationIntervalTimer            = &inputInternal::openCommandDriftCompensationIntervalTimerImp;
    volatile EventTimer* const learnCommandErrorTimeoutTimer                        = &inputInternal::learnCommandErrorTimeoutTimerImp;
    volatile EventTimer* const encoderConnectTimer                                  = &inputInternal::encoderConnectTimerImp;
    volatile EventTimer* const encoderMonitorIntervalTimer                          = &inputInternal::encoderMonitorIntervalTimerImp;
    volatile EventTimer* const mainVoltMonitorIntervalTimer                         = &inputInternal::mainVoltMonitorIntervalTimerImp;
    volatile EventTimer* const motorMonitorTimer                                    = &inputInternal::motorMonitorTimerImp;
    volatile EventTimer* const pMotorBoardRedLedTimer                               = &inputInternal::motorBoardRedLedTimerImp;
    volatile EventTimer* const statisticsManagerTimer                               = &inputInternal::statisticsManagerTimerImp;
}

namespace inputInternal {

    class InputDiagnosticsHandler : public DiagnosticsHandler
    {
    public:
        InputDiagnosticsHandler()
        {

        }

        virtual ~InputDiagnosticsHandler()
        {

        }

        virtual UdsResponseCode readDid(const UdsDataIdentifiers dataId,
                                        DiagDataParsed& o_data,
                                        uint8_t& o_length) const
        {
            UdsResponseCode result = UDS_RSP_SNS;
            uint16_t ui16GetRawValue = 0;
            switch(dataId)
            {
                case UDS_DID_LEARN_BUTTON:
                    o_length = 1;
                    o_data[0] = learnImp.boIsPinHigh() ? 1 : 0; //lint !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_MAIN_VOLTAGE:
                    ui16GetRawValue = mainVoltAdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;    //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_MOTOR_CURRENT_1:
                    ui16GetRawValue = motorAmp1AdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;   //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_MOTOR_CURRENT_2:
                    ui16GetRawValue = motorAmp2AdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;   //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_REF_2V5_VOLTAGE:
                    ui16GetRawValue = ref2V5VoltAdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;   //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_REF_5V0_VOLTAGE:
                    ui16GetRawValue = ref5V0VoltAdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;   //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_HW_VERSION_1:
                    ui16GetRawValue = hwVersion1AdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;   //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_ENCODER_VOLTAGE:
                    ui16GetRawValue = encoderVoltAdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;   //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_BREAK_CHOP_VOLTAGE:
                    ui16GetRawValue = brakeChopVoltAdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;   //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_MOTOR_VOLTAGE_1:
                    ui16GetRawValue = motorVolt1AdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;   //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_MOTOR_VOLTAGE_2:
                    ui16GetRawValue = motorVolt2AdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;   //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;
                case UDS_DID_HW_VERSION_2:
                    ui16GetRawValue = hwVersion2AdcImp.ui16GetRawAdValue();
                    o_length = 2;
                    o_data[0] = ui16GetRawValue >> 8;   //lint !e9034 Guaranteed to fit.
                    o_data[1] = ui16GetRawValue & 0x0FF;   //lint !e9027 !e9029 !e9130 !e9034 Guaranteed to fit.
                    result = UDS_RSP_OK;
                    break;

                default:
                    // Do nothing.
                    break; //lint !e9085 // Comment is on row above. Fancy that.
            }
            return result;
        }

        virtual UdsResponseCode writeDid(const UdsDataIdentifiers dataId,
                                         const DiagDataParsed& data,
                                         const uint8_t length) const
        {
            UdsResponseCode result = UDS_RSP_SNS;

            UNUSED_PARAMETER(length);

            switch(dataId)
            {
                case UDS_DID_LEARN_BUTTON:
                    {
                        const bool boPinHigh = (data[0] != static_cast<uint8_t>(0));
                        learnImp.vOverride(boPinHigh);
                        result = UDS_RSP_OK;
                    }
                    break;
                default:
                    // Do nothing.
                    break; //lint !e9085 // Comment is on row above. Fancy that.
            }
            return result;
        }

        virtual bool handlesDid(const uint16_t dataId) const
        {
            return ((dataId > UDS_DID_SESSION) && (dataId <= UDS_DID_HW_VERSION_2));
        }

        virtual bool handlesRoutinCtrlId(const UdsRoutineCtlIdentifiers id) const
        {
            UNUSED_PARAMETER(id);

            return false;
        }

        virtual UdsResponseCode routineCtrl(const UdsRoutineCtlType SubFn,
                                            const uint8_t* const optionRecord,
                                            const uint8_t lengthOptionRecord,
                                            uint8_t* const ppOutRoutineStatusRec,
                                            uint8_t* const pOutLengthStatusRec) const
        {
            UNUSED_PARAMETER(SubFn);
            UNUSED_PARAMETER(optionRecord);
            UNUSED_PARAMETER(lengthOptionRecord);
            UNUSED_PARAMETER(ppOutRoutineStatusRec);
            UNUSED_PARAMETER(pOutLengthStatusRec);

            return UDS_RSP_SNS;
        }

    };
}


namespace input
{
    xTaskHandle inputAppHandler;
}

namespace inputInternal {
    /* Handles to clients and servers
     * */
    static void inputApp( void* const pvParameters )
    {
        TickType_t xLastWakeTime;
        TickType_t xTickTimeCounter = 0;
        const TickType_t xFrequency = static_cast<TickType_t>( systemConfiguration::SAMPLE_TIME_MOTOR_BOARD );

        InputDiagnosticsHandler handler; //lint !e1502 // No non-static data members, but needed for callbacks
        diagRegisterDidCB(&handler);

        systemControlInitDone( pvParameters );
        mbsLogPrintf("input task started\r\n");
        // Initialize the xLastWakeTime variable with the current time.
        xLastWakeTime = xTaskGetTickCount ();

        // Initialize ADC and DMA module
        ADCInputImp::vInitADC();

        vTaskDelayUntil( &xLastWakeTime, 2000U ); //lint !e934 not a DLL library function

        do
        {
/*            chipTempAdcImp.vUpdate();
            refVoltAdcImp.vUpdate();*/
            learnImp.vUpdate(systemConfiguration::SAMPLE_TIME_MOTOR_BOARD);

            ref2V5VoltAdcImp.vUpdate();
            ref5V0VoltAdcImp.vUpdate();
            hwVersion1AdcImp.vUpdate();
            hwVersion2AdcImp.vUpdate();
            brakeChopVoltAdcImp.vUpdate();

            encoderVoltAdcImp.vUpdate();
            encoderVoltageTo5V0DiffImp.vUpdate();

            motorVolt1AdcImp.vUpdate();
            motorVolt2AdcImp.vUpdate();
            mainVoltAdcImp.vUpdate();
            voltBetweenUdcAndMotor1Imp.vUpdate();
            motorVoltAdcImp.vUpdate();
            motorVoltDiffAdcImp.vUpdate();

            motorAmp1AdcImp.vUpdate();
            motorAmp2AdcImp.vUpdate();
            motorAmpDiffAdcImp.vUpdate();
            motorAmpSquareImp.vUpdate();

            mainVoltageDiffImp.vUpdate();
            motorVoltXAmpImp.vUpdate();

            motorEncoderImp.vUpdate();

            motionControlAppSendDoorAngleTimerImp.vUpdate();
            motionControlTransitionDelayTimerImp.vUpdate();
            closedPositionControlReleaseTensionDelayTimerImp.vUpdate();
            closedPositionControlClosingSpeedDelayTimerImp.vUpdate();
            closedPositionControlExcessiveClosingSpeedDelayTimerImp.vUpdate();
            openCommandDriftCompensationIntervalTimerImp.vUpdate();
            learnCommandErrorTimeoutTimerImp.vUpdate();
            encoderMonitorIntervalTimerImp.vUpdate();
            encoderConnectTimerImp.vUpdate();
            mainVoltMonitorIntervalTimerImp.vUpdate();
            motorMonitorTimerImp.vUpdate();
            motorBoardRedLedTimerImp.vUpdate();
            statisticsManagerTimerImp.vUpdate();

            xTickTimeCounter++;
            if ( xTickTimeCounter >= 1000 )
            {
                xTickTimeCounter = 0;
                uint16_t u16StackLeft = uxTaskGetStackHighWaterMark( input::inputAppHandler );
                mbsLogInfo("inputApp task stack left =%d\r", static_cast<int>( u16StackLeft ));

                u16StackLeft = uxTaskGetStackHighWaterMark( comm::commAppTaskHandleTop );
                mbsLogInfo("commApp task stack left =%d\r", static_cast<int>( u16StackLeft ));

                u16StackLeft = uxTaskGetStackHighWaterMark( configurationManager::cManagerAppTaskHandleTop );
                mbsLogInfo("CM-app task stack left =%d\r", static_cast<int>( u16StackLeft ));

                u16StackLeft = uxTaskGetStackHighWaterMark( motionControl::motionControlAppTaskHandleTop );
                mbsLogInfo("motionCtrl task stack left =%d\r", static_cast<int>( u16StackLeft ));

                u16StackLeft = uxTaskGetStackHighWaterMark( statisticsAndLog::statisticsAndLogAppTaskHandleTop );
                mbsLogInfo("statistics task stack left =%d\r", static_cast<int>( u16StackLeft ));

                u16StackLeft = uxTaskGetStackHighWaterMark( systemMonitor::systemMonitorAppTaskHandleTop );
                mbsLogInfo("systemMonitor task stack left =%d\n\r", static_cast<int>( u16StackLeft ));
            }

            vTaskDelayUntil( &xLastWakeTime, xFrequency ); //lint !e934 not a DLL library function

            //*******************************************/

        }while( true ); //lint !e506 The while expression is deliberately constant to form a never ending loop
    } // lint !e952 pvParameters must be declared non const to fit into mbs
} /* Namespace inputInternal */

//lint -e(9015) This should be suppressed at for the library macro below, but apparently
//              it must be done explicitly again: # and ## is used inside this library macro wich we are not implementing
//lint -save -esym(765,initInput) The MBS macro is not creating a static function, even if it perhaps might be static.
SYSTEM_CONTROL_REGISTER_SYNCED_INIT_FUNCTION( initInput,        \
                                              INIT_INPUT_LEVEL, \
                                              INIT_INPUT_ORDER )
{
    /*
     * Create the inputApp task
     *
     * Responsible for sampling analog and digital inputs and pass them to the application
     */

    //lint  -e(956)
    // The taskHandle is currently not used for anything. If it should be needed in the future it must
    // be declared outside the initfunction.
    static xTaskHandle inputAppTaskHandle;

    if( pdPASS != xTaskCreate( &inputInternal::inputApp,
                               MBS_CFG_TASK_NAME_INPUT_APP,
                               MBS_CFG_TASK_STACK_INPUT_APP,
                               context,
                               MBS_CFG_TASK_PRIO_INPUT_APP,
                               &input::inputAppHandler ) )
    {
        mbsAssertFailWithMsg("xTaskCreate input app failed");
    }
} //lint !e952 parameter context needs to be non const to fit into mbs
//lint -restore

/**
  \}
 */

//lint -e1960 "function without external side-effects" = Functions in the ST Library that write to register map
