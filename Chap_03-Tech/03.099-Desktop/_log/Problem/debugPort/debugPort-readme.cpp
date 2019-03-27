
# how to use debug port in platform?

*01. add code folder: *

    components/application/test/debugPort/inc/debugPort.hpp xxx.cpp in project.

*02. change makefile:  *

	//---------------------------------------------------------
    products/"quasarMotor"/abs-module.mk:  components/application/test/debugPort \
                                           components/application/test/gpioTestPins \
										   
	_DEBUG_PORT_ := 1

	ifdef  _DEBUG_PORT_

	ABS_COMPONENTS += \
		components/application/test/gpioTestPins \
		components/application/test/debugPort \

	endif #_DEBUG_PORT_
	

*03. define dbgPort in namespace: *

    such as in "modules/motionControl/motorBoard/mbs_st_m64_core_v10/init/src/motionControl.cpp"

#ifdef  _DEBUG_PORT_
    #include "debugPort.hpp"
    namespace motionControlInternal
    {
        testInternal::DebugPort dbgPort;
    }
#endif //  _DEBUG_PORT_	

*04. open and enable debug port: *

    In "modules/motionControl/motorBoard/mbs_st_m64_core_v10/init/src/motionControl.cpp"

    SYSTEM_CONTROL_REGISTER_SYNCED_INIT_FUNCTION( initMotionControl,        \
                                              INIT_MOTION_CONTROL_LEVEL, \
                                              INIT_MOTION_CONTROL_ORDER )
    {
	#ifdef  _DEBUG_PORT_
        motionControlInternal::dbgPort.vOpen();
	#endif //  _DEBUG_PORT_	
        //...
    }
	
*05. close mbsLogPrintf.
    Then close mbsLogPrintf(), and enable '_DEBUG_PORT_ENABLED_'
    /modules/drivers/serial/mbs_st_m64_core_v10/config/src/serialConfig.c
	
	#define _DEBUG_PORT_ENABLED_    2    //for check macro define valid.

#ifdef  _DEBUG_PORT_
#define _DEBUG_PORT_ENABLED_    1
#endif

#ifndef _DEBUG_PORT_ENABLED_
        .portName     = "console",
        .aliasName    = "log",
#else
        .portName     = "debug",
        .aliasName    = "dbg",
#endif


*06. add header include:  *  in associated project cpp file.

    such as in  components/application/swingDoorGeneric/motionCommand/src/openCommand.cpp

#ifdef  _DEBUG_PORT_
#include "debugPort.hpp"
	namespace motionControlInternal
    {
        extern testInternal::DebugPort dbgPort;
    }
#endif //  _DEBUG_PORT_	

	
*07. use dbgPort print: *  

    such as in "void OpenCommandImp::vUpdate( const int16_t si16ShaftSpeed )".

    dbgPort << "[O:Vset = " << trajectoryGenerator->si16GetSpeedSetValueInMilliRadPerSecond()   << "],"
            << "[O:Vsft = " << si16ShaftSpeed                                                   << "],"
            << "[O:Imtr = " << motor->si16GetMotorCurrent()                                     << "],"
            << "[O:Posi = " << encoder->si32GetMotorPosition()                                  << "]\n";

    dbgPort << "[C:Vset = " << trajectoryGenerator->si16GetSpeedSetValueInMilliRadPerSecond()   << "],"
            << "[C:Vsft = " << si16ShaftSpeed                                                   << "],"
            << "[C:Imtr = " << motor->si16GetMotorCurrent()                                     << "],"
            << "[C:Posi = " << encoder->si32GetMotorPosition()                                  << "]\n";

    dbgPort << si16ShaftSpeed << "\n"; //"==="
	
	//===//add error sign (such as "===") after dbgPort sentence, then to compile; if there is error, macro used.
	
	    int32_t siPos1 = encoder->si32GetShaftPosition();
        int32_t siPos2 = armSystem->si32GetDoorAngleInMicroRad();
        #ifdef  _DEBUG_PORT_
        dbgPort << siPos1 << "  "
                << siPos2 << "\n";
        #endif
		
			
			
			
		//==================================================================================	
		mbsLogPrintf("center shaft pos %d urad\r", static_cast<int>(si32CenterShaftPosition));
	
	
	
		//==================================================================================
	    static int32_t siDataBuf[100];
        static int16_t siIndex = 0;

        static int16_t siCounter = 0;
        if ( siCounter < 100)
        {
            siCounter++;
        }
        else
        {
            siCounter = 0;

            if ( siIndex < 100 )
            {
                siIndex++;
            }
            else
            {
                siIndex = 0;
            }
            siDataBuf[siIndex] = siPos1;
        }
		
		