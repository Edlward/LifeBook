
# how to use debug port in platform?

*01. add code folder: *

    components/application/test/debugPort/inc/debugPort.hpp xxx.cpp in project.

*02. change makefile:  *

    products/"quasarMotor"/abs-module.mk:  components/application/test/debugPort \
                                           components/application/test/gpioTestPins \

*03. add header include:  *

    components/application/swingDoorGeneric/motionCommand/src/openCommand.cpp

    #include "debugPort.hpp"
    extern testInternal::DebugPort dbgPort; //if defined in other file, extern in test-file(openCommand.cpp) namespace.

*04. define dbgPort in namespace: *

    such as in "modules/motionControl/motorBoard/mbs_st_m64_core_v10/init/src/motionControl.cpp"

    #include "debugPort.hpp"

    namespace motionControlInternal
    {
        testInternal::DebugPort dbgPort;
        //...
    }

*05. open and enable debug port: *

    In "modules/motionControl/motorBoard/mbs_st_m64_core_v10/init/src/motionControl.cpp"

    SYSTEM_CONTROL_REGISTER_SYNCED_INIT_FUNCTION( initMotionControl,        \
                                              INIT_MOTION_CONTROL_LEVEL, \
                                              INIT_MOTION_CONTROL_ORDER )
    {
        motionControlInternal::dbgPort.vOpen();
        //...
    }
    then close mbsLogPrintf(), and enable '_DEBUG_PORT_ENABLED_'
    /modules/drivers/serial/mbs_st_m64_core_v10/config/src/serialConfig.c
    #define _DEBUG_PORT_ENABLED_

*06. use dbgPort print: *

    such as in "void OpenCommandImp::vUpdate( const int16_t si16ShaftSpeed )".

    dbgPort << "[O:Vset = " << trajectoryGenerator->si16GetSpeedSetValueInMilliRadPerSecond()   << "],"
            << "[O:Vsft = " << si16ShaftSpeed                                                   << "],"
            << "[O:Imtr = " << motor->si16GetMotorCurrent()                                     << "],"
            << "[O:Posi = " << encoder->si32GetMotorPosition()                                  << "]\n";

    dbgPort << "[C:Vset = " << trajectoryGenerator->si16GetSpeedSetValueInMilliRadPerSecond()   << "],"
            << "[C:Vsft = " << si16ShaftSpeed                                                   << "],"
            << "[C:Imtr = " << motor->si16GetMotorCurrent()                                     << "],"
            << "[C:Posi = " << encoder->si32GetMotorPosition()                                  << "]\n";

    dbgPort << si16ShaftSpeed << "\n";