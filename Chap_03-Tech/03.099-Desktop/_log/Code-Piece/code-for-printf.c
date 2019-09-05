


extern "C" {
    #include <mbsLog.h>
    #include <mbsAssert.h>
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

            TickType_t xTickTimeCounter = 0;

            xTickTimeCounter++;
            if ( xTickTimeCounter >= 1000 )
            {
                xTickTimeCounter = 0;

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
            
            
