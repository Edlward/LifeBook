

extern "C" {
    #include <mbsAssert.h>
    #include <mbsLog.h>
    
    #include "output.hpp"
    
}

extern "C" {
    #include <mbsAssert.h>
    #include <mbsLog.h>
    static int16_t si16TimeCounter = 0; //out of while.
}
#define PRINT_IMPULSE                   1
#define PRINT_MAIN_VOLTAGE              1
#define PRINT_ERROR_HANDLER             1

#if PRINT_IMPULSE
#if PRINT_MAIN_VOLTAGE
#if PRINT_ERROR_HANDLER
        mbsLogInfo(":Impulse %d enable\r", static_cast<int>( cui8ErrorCode ));
#endif

#if PRINT_MAIN_VOLTAGE
        mbsLogInfo(":diffV=%d.\r", static_cast<int>( diffVoltageStatus ) );
#endif

            si16TimeCounter++;
            if ( si16TimeCounter >= 200 )
            {
                si16TimeCounter = 0;
                int32_t brakeChopVolt = input::brakeChopVoltAdc->si32GetRealValue();
                int32_t mainVolt = input::mainVoltAdc->si32GetRealValue();
                if ( ((mainVolt - brakeChopVolt) > 2000)
                 ||  ((mainVolt - brakeChopVolt) < -2000))
                {
                    mbsLogInfo(":ChopV=%d.\r", static_cast<int>( brakeChopVolt ) );
                    mbsLogInfo(":MainV=%d.\r", static_cast<int>( mainVolt ) );
                }
            }

/SwingDoorPlatform/modules/input/motorBoard/mbs_st_m64_core_v10/init/src/input.cpp
/SwingDoorPlatform/components/application/swingDoorGeneric/controller/src/controller.cpp
/SwingDoorPlatform/components/application/swingDoorGeneric/motionCommand/src/closeCommand.cpp

/SwingDoorPlatform/components/application/swingDoorGeneric/errorHandler/motorBoard/src/errorHandler.cpp
on jer-error-print.


        if ( ePreState != eState)
        {
            ePreState = eState;

            mbsLogInfo("closeState=%d\r", static_cast<int>( eState ));
        }

            int16_t si16TimeCounter = 0; //out of while.

            si16TimeCounter++;
            if ( si16TimeCounter >= 1000 )
            {
                si16TimeCounter = 0;

                mbsLogInfo("ADC1=%d\r", static_cast<int>( motorVolt1AdcImp.si32GetRealValue() ));
                mbsLogInfo("ADC2=%d\r", static_cast<int>( motorVolt2AdcImp.si32GetRealValue() ));

                mbsLogInfo("Amp1=%d\r", static_cast<int>( motorAmp1AdcImp.si32GetRealValue() ));
                mbsLogInfo("Amp2=%d\r", static_cast<int>( motorAmp1AdcImp.si32GetRealValue() ));

                mbsLogInfo("Raw1=%d\r", static_cast<int>( motorAmp1AdcImp.ui16GetRawAdValue() ));
                mbsLogInfo("Raw2=%d\r", static_cast<int>( motorAmp1AdcImp.ui16GetRawAdValue() ));

                mbsLogInfo("2.5Volt=%d\r", static_cast<int>( ref2V5VoltAdcImp.si32GetRealValue() ));
                mbsLogInfo("2.5-Raw=%d\r", static_cast<int>( ref2V5VoltAdcImp.ui16GetRawAdValue() ));

                mbsLogInfo("Set-mA=%d\r", static_cast<int>( output::motor->si16GetMotorCurrent() ));
                mbsLogInfo("MtrPWM=%d\n\r", static_cast<int>( output::motor->si16GetMotorPwmSign() ));
            }
            
            

        si16TimeCounter++;
        if ( si16TimeCounter >= 100 )
        {
            si16TimeCounter = 0;
            mbsLogInfo("si16OpnBrakeSpeed=%d\r", static_cast<int>( csi16OpeningBrakeSetSpeed ));
            mbsLogInfo("si16SetSpeed=%d\r", static_cast<int>( si16RequestedSpeed ));
            mbsLogInfo("si16SmpSpeed=%d\n\r", static_cast<int>( csi16ShaftSpeedInMilliRadPerSecond ));
        }
        
        //print generator power
        uint16_t si16TimeCounter = 0; //out of while.
        
        si16TimeCounter++;
        if ( si16TimeCounter >= 200 )
        {
            si16TimeCounter = 0;

            int32_t  mainVoltage = mainVoltAdcImp.si32GetRealValue();
            if ( mainVoltage > 30000) //30v
            {
                mbsLogInfo("MainV=%d\r", static_cast<int>( mainVoltAdcImp.si32GetRealValue() ));
                mbsLogInfo("Volt1=%d\r", static_cast<int>( motorVolt1AdcImp.si32GetRealValue() ));
                mbsLogInfo("Volt2=%d\r", static_cast<int>( motorVolt2AdcImp.si32GetRealValue() ));
                mbsLogInfo("Amp-1=%d\r", static_cast<int>( motorAmp1AdcImp.si32GetRealValue() ));
                mbsLogInfo("Amp-2=%d\r", static_cast<int>( motorAmp2AdcImp.si32GetRealValue() ));
                mbsLogInfo("Power=%d\n\r", static_cast<int>( motorPowerImp.si32GetRealValue() ));
                
                mbsLogInfo("MainV=%d\r", static_cast<int>( input::mainVoltAdc->si32GetRealValue() ));
                mbsLogInfo("Volt1=%d\r", static_cast<int>( input::motorVolt1Adc->si32GetRealValue() ));
                mbsLogInfo("Volt2=%d\r", static_cast<int>( input::motorVolt2Adc->si32GetRealValue() ));
                mbsLogInfo("Amp-1=%d\r", static_cast<int>( input::motorAmp1Adc->si32GetRealValue() ));
            }
        }

case SYS_MON_THRES_ID_MAIN_VOL_DIFF_THRESHOLD_ID:
    mbsLogInfo("Diff thre=%d, Monitor=%d\r", static_cast<int>( thresholdStatus ), static_cast<int>( eMonitorState ));
    
    mbsLogInfo("Generator thre=%d\r", static_cast<int>( thresholdStatus ));
        
        
        
            switch (eTorqueMode)
           {
            case TORQUE_MODE_AUTO:
                si32MaxSelectedTorqueInMilliNm = si32MaxAllowedTorqueInMilliNm;
                si32DoorAngleInMicroRad = armSystem->si32GetDoorAngleInMicroRad();
                if ( si32DoorAngleInMicroRad >= csi32BackCheckAngleInMicroRadian )
                {
                    si32MinSelectedTorqueInMilliNm = csi32MaxExtendedClosingTorquelimitInMilliNm;
                }
                else
                {
                    si32MinSelectedTorqueInMilliNm = si32ExtendedClosingTorqueLimitUpdate();
                }
                break;
                
                default:
                    // We should never end up here.
                break;
            }