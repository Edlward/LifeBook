
//================================
1000-plan list:
{
01. every day 	: Code.
				  project board; 
				  Git commit; 
                  smile to problem; 
                  email;
				  UnitTest.
02. every Monday: swing door platform meeting.
03. trainning.
04. Python.
05. doxgen example.


EF : course start on 2 July
姓名： Hua Jerry
邮箱： jerry.hua@assaabloy.com
电话： +86 051287181277
手机： 18248788319
公司： Assa Abloy
国家： China
您的测试结果
日期： 2018-07-04
推荐级别： 10级 － 中高级
级别描述：
此阶段结束的时候，您将能跟上一个熟悉的话题或就此发言，或者能跟上一个包含广泛话题的对话。
能浏览文章来获取相关信息，并能理解复杂详细的说明或建议。能在别人讲话时做笔记，
或能写以不标准语言描述要求的信件。
总分： 52%
语法： 42%
听力： 52%
阅读： 61%

advisors@ef.com
课程有效期至: 2018年12月30日

个人学习计划：
1）每月完成学习1个单元通用英语；
4）每月至少参加1节小班会话课。
3）每月至少参加1节单元最后的私人课堂；
2）每月至少参加2节40分钟私教课堂；

课程介绍：
普通英语共有16个级别，每级别有6个单元，每个单元包含四节自学课以及两种形式的口语课。
第一种形式是小班会话课，每天24小时的整点和大部分半点开课，每堂课45Min，没有参加次数限制，但是小班会话课是按照您是否在课堂待满30分钟以上及是否发言积极来评分的，所以不积极发言的分数可能不高。
第二种形式是每单元最后有一节对应的私人课堂（20分钟），主要是对这个单元的复习和回顾，所以需要您先把前面的四节自学课自行完成，完成后会自动解锁，由于这节课是一对一的，所以需要您提前24小时在网上预约或者取消。
第三种形式是40分钟的私教课，主要是根据您的个人喜好选定一个主题，老师会根据您选定的主题来展开上课的主要内容。由于这节课也是一对一的，所以需要您提前24小时在网上预约或者取消。

}
//1000.

//================================
1001-work list:
{

01. email; headset, docking;
02. eclipse, cpputest, git, Cygwin 64bit; PC-lint;
03. project code; sharing topic;
04. startteam, 
	MBS, 
	IAR; 
	sdk; st-link driver.
	Doxygen,
	Python,
	Eclipse 32bit,
	
05. win10-en, pinyin input.(alt + Ctrl + delete )
	controlpanel-region and language.
	
06. read 2 doc everyday.

}
//1001.

//================================
1002-link list:
{
01.	tool list.
02.	git.  0.GIT+0.MBS.
03.	mbsSdk.
04.	share.
05. \Weekly plans\
	\Item-breakdown\
		G:\R&D\Folder_Tree_Management\41_Active_Projects_Electronics
		\SwingDoorPlatform\time plan
		
06. \100_Special_Project\
	\\cnsuzsfp01\suzhou$\R&D\Folder_Tree_Management\100_Special_Project\Slider\Magnetic linear drive sliding door
	
07. G:\R&D\2018\Jeff Zhang\Weekly meeting\
08. G:\R&D\Folder_Tree_Management\95_Project_Review\
09. G:\R&D\Folder_Tree_Management\41_Active_Projects_Electronics\Technology sharing\

}
//1002.

//================================
1003-expand knowledge:
{
001. hardware.
{
    //===MOTOR BOARD===//		V3.
    pin26-PB0 , not used,     HW_VERSION.
    pin24-PC4 , not used,     HW_VERSION.

    pin16-PA2 , 'U_ENCODER_FB', not used in V3.
    pin20-PA4 , v3.3,         /I_ENCODER_FB.
    pin21-PA5 , "v2.5REF",      not used in V3.
    pin22-PA6 , not used,     /v2.5REF.
    pin44-PA11, not used,     /MOTOR_WATCHDOG. //"MOTOR_POWER" power, relay.

    pin39-PC8 , HOME1,     	  not used.
    pin40-PC9 , not used,     /MOTOR_ENABLE. //module/init/output.cpp
    //---//1-Right.
    pin33-PB12, not used,     SPI_MEMORY_SELECT.
    pin34-PB13, not used,     SPI_SCK.
    pin35-PB14, "MOTOR_ENABLE", SPI_MISO.
    pin36-PB15, "MOTOR_POWER",  SPI_MOSI.
    //...//2-Left.
    pin56-PB4,  JTRST,        not used.
    pin03-Pc14, DC-,          not used.

    //===MAIN BOARD===//
    pin14-PA00, BT_CTS,       	U_6V6_PB.
    pin15-PA01, BT_RTS,       	PSU_HW_VERSION.
    pin16-PA02, BLE_TX,       	U_LOCK_FB.
    pin17-PA03, BLE_RX,       	ALARM_LED.
    pin21-PA05, PSU_HW_VERSION, BLE_SPI_SCK.
    pin22-PA06, U_LOCK_FB,      BLE_SPI_MISO.
    pin23-PA07, AN_6V_CHECK,    BLE_SPI_MOSI.
    //---//
    pin24-PC04, BT_EN,    		HW_VERSION.
    pin25-PC05, not used,    	U_6V_FB.
    pin38-PC07, '24V_OUT_EN',    	BLE_READY.
    pin51-PC10, not used,    	BLE_BOOT.
    pin52-PC11, not used,    	/24V_OUT_EN.  //output/mainBoard/init/???
    pin53-PC12, not used,    	BLE_nRST.
    //...//2.
    pin60-BOOT0, BOOT0,  		GND.
    pin28-PB02 , BOOT1,  		STATUS_LED.
    }

002. mockup
{
    mock().actualCall( "pGetPayloadBuffer" )
    mock().expectOneCall( "pGetPayloadBuffer" )
}    
    
}
//1003.

//=================================
1004-problems:
{
//questions:
-----------------------------------
STM32F103-RET6-GQ21U
01. "HSE_VALUE" redefined
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
02. ADC sample: //component/motor.cpp.
	uint16_t ui16ThisI0 = static_cast<uint16_t>(inputInternal::ADCInputImp::aui16ReceivedBuffer[1U]);
	ui16ThisI0 += static_cast<uint16_t>(inputInternal::ADCInputImp::aui16ReceivedBuffer[2U]);

-----------------------------------
03. reset.
addr2line -e <elf-file-name>.elf 0x8038F53 
#8  00000 00:00:00.007    Info quasarMain OMSBasicMain task started
MBS Console online, type help for a list of available commands
> 
## Assert failed at LR 0x801D03F, task commApp
## Assert failed at LR 0x8014BBF, task outputApp
	//message: vTaskDelayUntil( &xLastWakeTime, 100 ); in static void commApp( void* pvParameters ).
	//\modules\messageRouter\motorBoard\mbs_st_m64_core_v10\config\src\messageRoutingTable.cpp

-----------------------------------	
04. can comm. //jump. //open-signal.
	extern  CanComm* const can1; 
	C:\mbs\SwingDoorPlatform\modules\comm\mainBoard\mbs_st_m64_core_v10\init\inc\comm.hpp

-----------------------------------	
05. ADC_ResetCalibration(ADC1);

-----------------------------------	
06. initial speed -40; //
const int16_t CloseCommandImp::csi16SetSpeedAtClosed    = -40; /* -0.040 rad/s shaft speed */
/SwingDoorPlatform/modules/motionControl/motorBoard/mbs_st_m64_core_v10/config/src/motionControlConfig.cpp==

-----------------------------------	
07. Kp, Ki, Kc.
enum { PUSH_SPEED_P = 400 }; 				 //400Nms/radian on output shaft
enum { MAX_ALLOW_CURRENT = 4000 };
/SwingDoorPlatform/modules/motionControl/motorBoard/mbs_st_m64_core_v10/config/inc/motionControlConfig.hpp==

ui32DoorInertiaSeenFromShaft		(30000U),//30kgm2
/SwingDoorPlatform/components/application/swingDoorGeneric/speedController/src/normalSpeedController.cpp

-----------------------------------
08. _FIX_PWM_ //PI debug.
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

-----------------------------------	
09. serial dbg_port
C:\mbs\zs_plat\modules\drivers\serial\mbs_st_m64_core_v10\config\src\serialConfig.c
#define _DEBUG_PORT_ENABLED_	
	
	static_cast<uint32_t>( MAX_ALLOW_VOLTAGE )
-----------------------------------	
10. 编码器连接，红灯亮；
	首次上电门抖动，手动推门门打开，开到位抖动不止，编码器反向；
	通信端子连接；

-----------------------------------	
11. 
UnitTest/makefile 
products/unitTest/motionControl/abs-binary.mk  

lint/conf/project.lnt	

-----------------------------------	
12. TorqueLimiterImp* torqueLimiter = pTorqueLimiterConstruction();
    TorqueLimiter* torqueLimiter = pTorqueLimiterConstruction();
    TorqueLimiterBackEnd* torqueLimiterBackEnd = torqueLimiter;
    
13. message, timer
    ////message SEND & RECEIVE:              //who send msg? motionControl send every set Time. //CAN_BUS recv.
    pui8EncoderInfo = messageRouter->pGetPayloadBuffer(static_cast<uint8_t>(messages::SEND_DOOR_ANGLE_REPETITION));
    ////event Timer:
    eventTimer->vRequestTimeout( ui32MotionSendDoorAngleRepetitionTime );
}
//1004.

//================================
1005-template:
{

dekai-suzhou.
qtk12345678


#export PATH=$PATH:/C/mbs/programs/bin/
#export PATH=$PATH:/C/mbs/programs/bin/

}
//1005.

//================================
1006-project design:
{
01. backup .setting.
02. send email for one question.
03. 做事，完成清单；帮助，别人的支持； 
	适应环境与人，Jeppa remove enum ADC_TO_VOLT, 要求严格，干净。
04. 运行调试：机械连杆，CCL电机（编码线），SPM电机（驱动线），
			功能开到位晃动，
			
05. State Machine. How many states? What States?
	//! object   ------->states. //isoSgl ->0, 1.------>state machine       ------------>condition table.
		//!      ------->signals                 ------>events              ------------>messages.
	//! signals -> events. signalsArray[SGINAL_IDx], eventsArray[EVENT_ID]. SetEvent(event, EVENT_ID, MESSAGE_ID). 
		//! input signals  ->events.  
		//! fault signals  ->events.
		//! process signals->events.
		//! state signals  ->events.
	//! events -> messages:    messageArray[MESSAGE_ID].   between modules, independence.
		//! CMD.
		/// enum {MSG_ISO_SET = 0, ..., MSG_LENGTH}
	
	//event, jump edge once, send to other module. //reset iso event, to interior light, to open cmd.
	if (signal)
	{
		isoSetMsgToIntLight = signal;
		isoSetMsgToOpnCmd   = signal;
	}
	else //can recover event.
	{
		isoResetMsgToIntLight = signal;
	}

	SetEvent(signal, SGINAL_IDx, EVENT_IDx)
	{
		if (signalsArray[SGINAL_IDx] != signal)
		{
			if (signal)
			{
				eventsArray[EVENT_IDx] = signal;
			}
			signalsArray[SGINAL_IDx] = signal;
		}
	}
	SetEvent((!isoSgl), SGINAL_IDx, EVENT_ISO_RESET_IDx);
	
	
	//! conditions: truth table.
	//! priority: priority table.
	switch, state no more 5. 
	
    if, else if  only use 1 condition. many conditons, use truth table.
	
	SetLightOnTruthTable    = (A && B && C && D);
	SetLightFlashTruthTable = (E && F && G && D);
	if (SetLightOnTruthTable)
	{	LightValue = ON;
	}
	else if (SetLightFlashTruthTable)
	{	LightValue = FLASH;
	}
	else
	{	LightValue = OF;
	}
	
	PriorityTable = (!A && !B && !C && D);
    
06. instruction mode / order logic design:
    fireMode > learnMode > manualMode > safetyMode > activeMode
    
07. c struct instead of c++ class.
    1-function pointer, (fun *)(parameters,..)
    2-this pointer.
    3-_VAL_ARGUS
    4-Structor function.
    5-inherit, //use no-named struct.
    6-
}
//1006.

//================================
1007-job finshed:
{
01. digitalOutput component.
02. torqueLimiter.
03. freeSwingCommand.
04. slowOpenCommand. (debug and revise closeCommand.cpp without spring./*init open, close obstruct, if check 1 condition.*/)
05. doorControlApp.
}
//1007.

//================================
1008-platform design:
{
01. 0907-It would be good to have a small test-plan for the comming work. 
		 It could be just comments indicating what tests will need to be developped.
	0908-the documentation in PiController.hpp that the "incremental" form of a PI controller is used.
	0905-there was a general update of the code to comply with our PC-lint
	0903-length.
MOTION_COMMAND_TRANSITION_DELAY_TIMER_ID(41-length)
MOTION_CONTROL_TRANSITION_DELAY_TIMER_ID(41-length)	

	0910-the filter function should be made as simple as possible, since it will execute in the ISR context of the motor controller. 
	check what PC-Lint says
	0910-The unit test should run on target as well. //eventTimer/unitTest && $(MAKE) runWindows
	0910-variableWithUnit.
	1030-Could the code be shared instead of copied? //not repeated code.
	1030-calculate less.
	1030-common helper function.
	
	1100-quasar and quasarMotor target doesn’t compile
	1101-check the door opens and closes.
	1102-Check if the onObject() function.
	1103-indentation bloopers.
	1104-git pull before continuing.
	1105-NOT use tab, use 4 spaces.
    

------
clean,
gcovr,
runWindows,
windows.

/SwingDoorPlatform/mbsSdk/components/system/tcpIp/ssl_tp/polarSSL/doxygen/polarssl.doxyfile

G:\R&D\2017\Janny Zhang\标准\USA

------
Corrected in new commit.
Removed in new commit.
It has been corrected.
Removed the 'open' state.
Fixed？ in new commit as it may. 
As far as my concerned it's use full to distinguish class and object with C(class).
Changed to xxx in new commit.
Removed the outputConfig.hpp file in new commit.
//csi16StalledSpeedDifferenceLimit is not used as a speed difference, but rather as an absolute limit
I think that the introduced statuses SLOW_OPENING ad SLOW_STALLED are unnecessary. 
Use the normal once OPENING and STALLED.

a more descriptive name.

pop up an issue
comment,
description,
documentation,



}
//1008.

//################################
1009-log:
{
//================================
2019.01.04 Friday.
01. KPI.
G:\R&D\Folder_Tree_Management\95_Project_Review\KPI\2018\

//================================
2019.01.02 Wednesday.
01. email!
02. platform: sendDoorAngle.//doorControlApp. //debugPort, //serialPort.//makefile.
03. pc-lint.
12. FOC, doctor paper.('MOTOR')
13. freeRTOS.         ('rtos')
14. vs2005，C# code:  ('pc sw')

21. c struct make c++ class.
22. inline func.
23. C macro # STR, ## CONS.
24. //openocd.
25. c++ design.
26. python.

}
//1009.
