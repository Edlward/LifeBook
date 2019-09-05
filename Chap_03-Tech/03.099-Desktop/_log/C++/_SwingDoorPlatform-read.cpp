01. ProgramSelector: (io param intf(impules),to private object(maybe not defined), &message, mode).
    remote BLE mode > local mode(timer filter 500ms);
    mode >> inner, outer, key, PAG, RUO, hold open Impulses...
    
02. DoorControlApp: (#define INT16_MAX (__INT16_MAX__) stdint.h, 
    dispatch:   motion_control_status, timer_enent, impulse timeout,
                door_angle_repetion, impulse, learn button, 
                learn_error, ble_status_updated, programOveride! ).
                
03. ActiveImpulse: (message=>door_command, ʹЅڅۮۯc).
    
04. priorityList: (in doorCommand.hpp, DoorCommandPriorityListImp=>static apDoorCommandList[], constructor).
    activeDoorCommandBackEnd  ->vUpdateWithProgramSelectedAsLock
        -CommandCloseSingleImp::vUpdateWithProgramSelectedAsLock
    
05. SelfTest:
    -SystemMonitorAPP:
        -runtime test,
            -ProgramFlowSendTest,
            -ProgramFlowReceiveTest,
            -RamTest,
            -
    -SystemMonitorAppBackEnd( vDispatch(messages) ),
        -SystemMonitorAppBasicIoImp,
        -SystemMonitorApp'Motor'Imp //tRuntimeTestList[NUMBER_OF_RUNTIME_TESTS]


    /SwingDoorPlatform/components/common/selfTest/STM3210C_EVAL/EWARM/stm32f10x_STLcpurunIARv5.s
    /components/application/swingDoorGeneric/systemMonitorApp/motorBoard/inc/runtimeTestList.hpp
    /: RuntimeTest("ProgramFlowReceive", PROGRAM_FLOW_RECEIVE_TEST)
    
    
    
06. doorCommand:
    -cmdHpp:   vSetNumberOfLockRetryAttempts
        -backend: restart, timeoutEvent, updatMotionControlStatus, updateLocalDoorAngle, updateProgramSelectedAsLock.
        -priority: setActiveCommandAtDefPriority.
        -closeSingleBackend: setNumberOfLockRetry.
    -cmd'TO'CloseSingle:
        -from(cmd, cmdBackend, clsSignleBackend, CommonCmd), IO(lockDriver, timer), method(update status, up angle, up program, up retry).
        -state: CLOSING, OPEN, CHECK_LOCK, UNLOCK.
    -cmd'TO'FreeSwingSingle
    -cmd'TO'LearnSingle
    -cmdOpenSignle
    -cmdCommonImp: SetLockReleaseEnabled, SetLockReleaseTimeout.
        protected: SendMotionControlCommand(),
    -cndPriority:
        -inhert from cmdHpp priority.
        -static: vUpdateActiveCommandWithProgramSelectedAsLock().
        -private: apDoorCommandList[].

        //static variable door lock retry detect angle in deci-degree
        static const int16_t csi16LockRetryDetectAngleInDeciDegrees;    
    
//questions:
-----------------------------------
STM32F103-RET6-GQ21U
11. "HSE_VALUE" redefined
	/SwingDoorPlatform/modules/bsp/mbs_st_m64_core_v10/config/abs-component.mk //Here.
	//HSE_VALUE=16000000 
	/SwingDoorPlatform/modules/bsp/mbs_st_m64_core_v10/init/src/system_stm32f10x.c 
    /* PCLK1 = HCLK/2 = 36MHz */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;

    /* ADC = PCLK2/6 = 12MHZ */
    RCC->CFGR |= (uint32_t)RCC_CFGR_ADCPRE_DIV6;
	
    /*  PLL configuration: PLLCLK = HSE / 2 * 9 = 72 MHz   HSE = 16MHZ */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE |
                                        RCC_CFGR_PLLMULL));
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9 |RCC_CFGR_PLLXTPRE_HSE_Div2);

-----------------------------------
12. ADC sample: //component/motor.cpp.
	uint16_t ui16ThisI0 = static_cast<uint16_t>(inputInternal::ADCInputImp::aui16ReceivedBuffer[1U]);
	ui16ThisI0 += static_cast<uint16_t>(inputInternal::ADCInputImp::aui16ReceivedBuffer[2U]);

-----------------------------------
13. reset.
addr2line -e <elf-file-name>.elf 0x8038F53 
#8  00000 00:00:00.007    Info quasarMain OMSBasicMain task started
MBS Console online, type help for a list of available commands
> 
## Assert failed at LR 0x801D03F, task commApp
## Assert failed at LR 0x8014BBF, task outputApp
	//message: vTaskDelayUntil( &xLastWakeTime, 100 ); in static void commApp( void* pvParameters ).
	//\modules\messageRouter\motorBoard\mbs_st_m64_core_v10\config\src\messageRoutingTable.cpp

-----------------------------------	
14. can comm. //jump. //open-signal.
	extern  CanComm* const can1; 
	C:\mbs\SwingDoorPlatform\modules\comm\mainBoard\mbs_st_m64_core_v10\init\inc\comm.hpp

-----------------------------------	
15. ADC_ResetCalibration(ADC1);

-----------------------------------	
16. initial speed -40; //
const int16_t CloseCommandImp::csi16SetSpeedAtClosed    = -40; /* -0.040 rad/s shaft speed */
/SwingDoorPlatform/modules/motionControl/motorBoard/mbs_st_m64_core_v10/config/src/motionControlConfig.cpp==

-----------------------------------	
17. Kp, Ki, Kc.
enum { PUSH_SPEED_P = 400 }; 				 //400Nms/radian on output shaft
enum { MAX_ALLOW_CURRENT = 4000 };
/SwingDoorPlatform/modules/motionControl/motorBoard/mbs_st_m64_core_v10/config/inc/motionControlConfig.hpp==

ui32DoorInertiaSeenFromShaft		(30000U),//30kgm2
/SwingDoorPlatform/components/application/swingDoorGeneric/speedController/src/normalSpeedController.cpp

-----------------------------------
18. _FIX_PWM_ //PI debug.
/components/application/aaesGeneric/motor/src/motor.cpp

_FIX_CURRENT_
void MotorImp::vSetShaftTorque (const int32_t si32ShaftTorqueSet)

_FIX_SPEED_
/modules/motionControl/motorBoard/mbs_st_m64_core_v10/init/src/motionControl.cpp
si16ShaftSpeed |= pui8MessagePayload[5]; //sample speed.
#ifdef _FIX_SPEED_
    si16ShaftSpeed = SPEED_VALUE_MRAD;
#endif //_FIX_SPEED_
armSystem->vUpdate(si32ShaftAngle,si16ShaftSpeed);

------
case CLOSING:
    vSetLimitedTorqueFromSpeedController( -100, si16ShaftSpeed ); //CloseCommandImp::vUpdate()==
------
si32ShaftTorqueMax				(static_cast<int32_t>(25000)
outputConfig.hpp			enum { PROPORIONAL_GAIN = 2000 };	1500. //SPM.
							enum { INTEGRATION_FACTOR = 160 };	150.
motionControlConfig.hpp		enum { PUSH_SPEED_P 	= 30 };

    const int32_t csi32MotorResistanceInMilliOhm    = 430;
    const int32_t csi32MotorInductanceInMicroH      = 960;
    const int32_t csi32TorqueConstantInMilliNmOverA = 9980; // For SW300
        
        