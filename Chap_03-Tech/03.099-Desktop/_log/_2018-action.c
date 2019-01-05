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
}

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

//================================
1003-entry list:
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
1006-project:
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
1007-code finshed:
{
01. digitalOutput component.
02. torqueLimiter.
03. freeSwingCommand.
04. slowOpenCommand. (debug and revise closeCommand.cpp without spring./*init open, close obstruct, if check 1 condition.*/)
05. doorControlApp.
}
//1007.

//================================
1015-sentence:
{
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

------
clean,
gcovr,
runWindows,
windows.

/SwingDoorPlatform/mbsSdk/components/system/tcpIp/ssl_tp/polarSSL/doxygen/polarssl.doxyfile

G:\R&D\2017\Janny Zhang\标准\USA

}
//1015.

//================================
1016-platform design:
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
}
//1016.


//=================================
4005-questions:
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
}
//4005.


//================================
4006-V3 prototype pins:
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
//4006.

//================================
4007-error
{
001. error: cannot convert 'motionControl::MotionCommand* const' to 'motionControlInternal::OpeningCommandBackEnd*' in initialization

    //! Sub-id of MOTION_CONTROL_STATUS
    enum
    {
        MOTION_CONTROL_STATUS_CLOSING = 0,//0
        MOTION_CONTROL_STATUS_MANUAL,     //1
        MOTION_CONTROL_STATUS_CLOSED,     //2
        MOTION_CONTROL_STATUS_OBSTRUCTED, //3
        MOTION_CONTROL_STATUS_OPENING,    //4
        MOTION_CONTROL_STATUS_OPEN,       //5
        MOTION_CONTROL_STATUS_STALLED,    //6
        MOTION_CONTROL_STATUS_DRIFT_COMP, //7
        MOTION_CONTROL_STATUS_STOPPED     //8
    };
    
}
//4007.
//################################
5000-log:
{
virtual int16_t si16GetMotorCrrtLimit() const volatile = 0; //xxvv,2502=2.502A, v0.2.
mbsLogPrintf("Software ID V00.03. \r");
	
	
G:\R&D\2018\Jerry Hua\002-ST-Link Utility Load Flash\	
	
	
C:\mbs\zs_plat
C:\mbs\SwingDoorPlatform

V3 board.








2740 uH








Error	1	Inconsistent accessibility: field type 'Kalman2005.KalmanFilter.kalmanType' 
is less accessible than field 'Kalman2005.KalmanFilter.kal'	
C:\Users\jerhua\_huamg_assa_\03-tech\03.061-Git\Kalman2005\DrawLine2005\Form1.Designer.cs	153	27	Kalman2005

Inconsistent accessibility: field type  is less accessible than field 

Error	1	'Kalman2005.kalmanType.X' is inaccessible due to its protection level	
C:\Users\jerhua\_huamg_assa_\03-tech\03.061-Git\Kalman2005\DrawLine2005\Form1.cs	174	17	Kalman2005













//================================
2018.12.26 Wednesday.
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

//================================
2018.12.24 Monda.
01. email!
02. platform: doorControlApp. //debugPort, //serialPort.//makefile.
03. pc-lint.
12. FOC, doctor paper.('MOTOR')
13. freeRTOS.         ('rtos')
14. vs2005，C# code:  ('pc sw')

21. /// STM32CubeMX.
22. //make.exe -> Cygwin Gcc. //LaTeX. //MakeDown. //MathJax. //Dot.
23. //gcc -> cmd.
24. //openocd.
25. c++ design.
26. python.

//================================
2018.12.13 Friday.
01. email!
02. platform: doorControlApp. //debugPort, //serialPort.//makefile.
03. pc-lint.
12. FOC, doctor paper.('MOTOR')
13. freeRTOS.         ('rtos')
14. vs2005，C# code:  ('pc sw')

21. /// STM32CubeMX.
22. //make.exe -> Cygwin Gcc. //LaTeX. //MakeDown. //MathJax. //Dot.
23. //gcc -> cmd.
24. //openocd.
25. c++ design.
26. python.

//================================
2018.12.12 Wednesday.
01. email !
02. platform: slowOpen.
03. pc-lint.
12. FOC, doctor paper.('MOTOR')
13. freeRTOS.         ('rtos')
14. vs2005，C# code:  ('pc sw')

21. /// STM32CubeMX.
22. //make.exe -> Cygwin Gcc.
23. //gcc -> cmd.
24. //openocd.
25. c++ design.
26. python.

//================================
2018.12.10 Monday.
01. email !
02. platform: slowOpen.
03. pc-lint.
12. FOC, doctor paper.('MOTOR')
13. freeRTOS.         ('rtos')
14. vs2005，C# code:  ('pc sw')

#125   00000 00:00:23.023    Info doorLogicApp set current -972 mA # 

## Assert failed at LR 0x801DD25, task CanSrvRx

===========================
MBS logging to UART started
#0     00000 00:00:00.000    Info SYS_CTRL last reset flag(s): Pin reset
#1     00000 00:00:00.000    Info SYS_CTRL last reset flag(s): Software reset
#2     00000 00:00:00.000    Info SYS_CTRL build-id Len:20 Data:0x35ef12d711efb56d22a4967d65e8dedae9c88614
#3     00000 00:00:00.000 Warning Error from previous run ## Assert failed at LR 0x801DD25, task CanSrvRx
#4     00000 00:00:00.003    Info initGlobals Globals initialized
#5     00000 00:00:00.005    Info initDoorLogicApp Using SERIAL driver = HAL-SERIAL_Stm32 v-1, config = mbs_st_m64_core_v10 v-1 
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#7     00000 00:00:00.006 Warning mbsBufferDynamic Heap low memory!
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#6     00000 00:00:00.006    Info inputApp input task started
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#8     00000 00:00:00.006    Info motionControlApp motionControl task started
#9     00000 00:00:00.007    Info doorLogicApp OMSBasicMain task started
#10    00000 00:00:00.007    Info doorLogicApp Motor Version =_= 0906. 
#11    00000 00:00:00.007    Info doorLogicApp motor speed 0 mrad/s # 
#12    00000 00:00:00.007    Info doorLogicApp motor pos 0 urad # 
#13    00000 00:00:00.007    Info doorLogicApp set current 0 mA # 
MBS Console online, type help for a list of available commands

> #14    00000 00:00:01.008    Info doorLogicApp Motor Version =_= 0906. 
#15    00000 00:00:01.008    Info doorLogicApp motor speed 0 mrad/s # 
#16    00000 00:00:01.008    Info doorLogicApp motor pos 0 urad # 



//================================
2018.12.08 Sat.

	My groceries cost about $400 each month. 			我的杂货费用每月约400 美元。
	My train pass is $50 a month. 						我的火车通票是每月50美元。
	My utility bill is usually around 200 per month. 	我的水电费账单通常大约每月200。
	My monthly mortgage payment is $2,500. 				我每月按揭付款为2，500美元。
	I pay about 7,000 in property tax every year. 		我每年付大约7，000房产税。
  	  	 
	对于一些在一段时间内发生不止一次的费用，你可以使用像twice或three times这样的单词。
  	  	 
	I pay my car insurance twice a year. 				我每年付两次汽车保险。
	I buy a subway ticket three times a week. 			我一周买三次地铁票。
	
	
	列举选项
	处理一个问题的方法是列出你的选项，然后选择最好的一个。 注意这里有几个单词的意思和option相同。
	One option is to lay off workers with low seniority. 	  	一个选择是解雇工龄短的工人。
	We have to make some hard choices. 	  	我们不得不做一些艰难的选择。
	One alternative is to use attrition. We just don't replace workers who leave. 	  	一个选择是使用损耗。员工离开后我们不会再招人填补职位。
	Another possibility is to offer older workers a large retirement bonus. 	  	另一个可能性是给老员工一笔大额的退休奖金。
	We may have to consider more drastic options. 	  	我们可能不得不考虑更极端的选择。
	
	
	 My salary is $60,000, but my total compensation adds up to about $80,000 per year.
	  	我的工资是60，000美元，但是我的总体薪酬加起来每年大约80，000美元。
	I'm really happy with the compensation package at my company. 	  	我对我们公司的薪酬包很满意。
	
	 	
My benefits include generous medical and retirement plans, and three weeks of vacation each year.
	  	我的福利包括慷慨的医疗和退休方案，和每年三个星期的休假。
	My company contributes $500 every month to my retirement plan. 	  	我的公司每月支付500美元到我的退休方案中。
	There is a 400-a-month deduction for the medical plan. 	  	每月扣除400的医疗计划钱。
	Our medical plan includes dental work and any counseling we need. 	  	我们的医疗方案包括牙科和我们需要的任何咨询费用。

My incomes expenses debts are about $ 3,000 a month, including rent and food.
Because of my student loan, I have about $ 5,000 in income debt savings .
My income debt saving from work is about $ 5,000 a month.
I have about $ 3,000 in expenses savings borrows in the bank.
My parents paid back borrowed loaned me $ 6,000 for school.
I pay back borrow owe the bank about $ 4,000 for my loan.

//================================
2018.11.28 Wednesday.
00. email.
00. platform: slowOpen.
01. vs2005，C# code: 
02. FOC, doctor paper.
03. freeRTOS.
04. pc-lint.
05. email.

mock, expect指向同一个地址。
    void vExpectGetDoorAngle( int32_t* psi32DoorAngle )
    {
        mock().expectOneCall( "si32GetDoorAngleInMicroRad" )
              .andReturnValue( static_cast<void*>( psi32DoorAngle ) );
    }

指针类型不能转换，直接源头定义为应用的类型。
SlowOpenCommandImp* slowOpenCmdImp = reinterpret_cast<SlowOpenCommandImp*>(slowOpenCommand);

//================================
2018.11.28 Wednesday.
00. email.
00. platform: slowOpen.
01. vs2005，C# code: 
02. FOC, doctor paper.
03. freeRTOS.
04. pc-lint.
05. email.

indentation.

//================================
2018.11.19 Monday.
/*
## Library/*
## !Library/*.asset
## 表示忽略Library文件夹但是不忽略Library文件夹下的.asset结尾的文件。
## 需要注意的是，忽略的文件夹一定要结尾 /* ，否则不忽略规则将无法生效。

## “#”表示注释
## “/”表示目录；
## “*”通配多个字符；
## “?”通配单个字符
## “[]”包含单个字符的匹配列表，参见正则表达式；
## “!”表示不忽略*匹配到的文件或目录；
*/

//================================
2018.11.16 Friday.
00. platform, freeWing.
01. vs2005，C# code: 
02. FOC, doctor paper.
03. freeRTOS.
04. pc-lint.

//================================
2018.11.14 Wednesday.
00. platform, freeWing.
01. vs2005，C# code: 
02. FOC, doctor paper.
03. freeRTOS.

//================================
2018.11.06 Tuesday.
01. code: 

C:\Users\jerhua\Downloads\Jenkins\
int32_t si32DeltaVoltage = pTorqueLimitTest->si32SetMotorVoltageInMilliVolt1 - pTorqueLimitTest->si32SetMotorVoltageInMilliVolt2;

//================================
2018.11.02 Wednesday.
01. code: 
void MotorImp::vTranslateSetCurrentToAdQuanta() const volatile
{
    int32_t si32AdSetValue = static_cast<int32_t>( CURRENT_OFFSET_IN_AD_QUANTA );
    si32AdSetValue += static_cast<int32_t>( ( static_cast<int32_t>( RAW_CURRENT_QUANTA )*si16SetCurrentInMilliA )/static_cast<int32_t>( CURRENT_SENSOR_RANGE_IN_MILLI_A ) );
    si16SetCurrentInAdQuanta = static_cast<int16_t>( si32AdSetValue );
}

//================================
2018.11.01 Thursday.
01. code: 

//================================
2018.10.29 Monday.
01. review: 
-DUSE_MBS_COMPILER_ATTRS=0

据吉尼斯世界纪录统计，阿加莎?克里斯蒂是人类史上最畅销的著书作家。
而将所有形式的著作算入，只有圣经与威廉?莎士比亚的著作的总销售量在她之上。
其著作曾翻译成超过103种语言，总销突破20亿本 

无人生还、东方快车谋杀案、尼罗河谋杀案、罗杰疑案 

//================================
2018.10.26 Friday.
01. review: 

//================================
2018.10.25 Thursday.
01. code,	//torque limiter. #### low energy, min>max, how to find the according test? set breakpoint in min>max place!
02. foc,
03. english.
04. email.
05. commu.

siCalculateMaxPowerAssistTorqueLimit()
siCalculatePowerAssistTorqueLimit()

C:\mbs\SwingDoorPlatform\unitTest\common\lib\cppUTest\CppUTest
C:\mbs\SwingDoorPlatform\unitTest\common\lib\cppUTest\Platforms\armcc
C:\mbs\SwingDoorPlatform\unitTest\common\inc\CppUTest

Can't find a source file at 
"/cygdrive/c/Users/sejgr/Downloads/cpputest-3.8/cpputest_build/../src/CppUTest/Utest.cpp" 

/*! When the motor object is instantiated, GPIO shall be enabled as output for driving the H-bridge,
 *  A timer shall be set up for PWM generation on the two channels, with a repetition frequency of 10 kHz.
 *  The timer shall provide a trigger for start of AD Conversion, and the end of AD Conversion
 *  interrupt shal be enabled. */
 /*! When the motor object is instantiated, and the first mcuGpioStm32f10xConfigure returns false, an mbsAssert shall
 * be thrown */
/*! When the motor object is instantiated, and the second mcuGpioStm32f10xConfigure returns false, an mbsAssert shall
 * be thrown */
/*! When the motor is enabled and the set current is changed to 4000 mA, the controller shall drive the
 * motor current to 4000 mA +- 5% within 1,5 ms. While doing so, the ADC conversion trigger shall be
 * correctly placed behind the first occurring edge that is followed by more than 25% of the total PWM
 * timer cycle time without additional switching. The AD conversion trigger shall occur ADC_SETTLE_DELAY
 * after the selected edge
 */
 /*! When the motor is enabled and the set current is changed to -4000 mA, the controller shall drive the
 * motor current to -4000 mA +- 5% within 1,5 ms. While doing so, the ADC conversion trigger shall be
 * correctly placed behind the first occurring edge that is followed by more than 25% of the total PWM
 * timer cycle time without additional switching. The AD conversion trigger shall occur ADC_SETTLE_DELAY
 * after the selected edge
 */
 /*! It shall be possible to drive the motor at 4000 mA as the counter EMF increases
 * When the gap between the first edge of the positive motor input and the negative motor input
 * gets larger than 50% of the total PWM period (i.e. 25 us or 1800 timer ticks) the AD triger interrupt
 * shall be scheduled to happen after the positive edge of the positive input.
 */
 /*! It shall be possible to drive the motor at -4000 mA when the counter EMF decreases
 * When the gap between the first edge of the negative motor input and the positive motor input
 * gets larger than 50% of the total PWM period (i.e. 25 us or 1800 timer ticks) the AD triger interrupt
 * shall be scheduled to happen after the positive edge of the negative input.
 */
/*! There shall be limited glitches in the output in time and magnitude when the link voltage drops rapidly
 *  and the motor is running with high positive current and EMF */
/*! There shall be limited glitches in the output in time and magnitude when the link voltage drops rapidly
 *  and the motor is running with high negative current and EMF */
 /*! When the motor object is disabled, by calling the vSetMotorEnable method with argument MOTOR_DIABLE
 *  50 % synchronous PWM shall be output on both the H-bridge PWM pins, and the AD-trigger PWM shall
 *  have its first rising edge AD_TRIGGER_DELAY after the first rising common edge of the two H-bridge pins.
 */
 /*! When the motor object is instantiated the Enable-Status shall be set to Disabled
 */
 /*! When the motor has been disabled for some time, so that the motor current has reached zero,
 *  the step response when enabled again shall be similar to when it was enabled immediately after
 *  initialization. I.e. all internal regulator states shall be reset when the motor is disabled.
 */
 /*! When the End Of Conversion interrupt is called, the vSampleAndFilter method of each adcBackEnd object
 *  that exist in the adcObject array shall be called
 */
/*! When the End Of Conversion interrupt is called, the vSampleAndFilter method of each adcBackEnd object
 *  that exist in the adcObject array shall be called even if MotorControl is Disabled
 */\
 /*! It shall be possible to set the output torque as an alternative to the output current.
 *  The resulting current shall correspond to the requested torque on the output shaft.
 */
 
    vUpdateMaxMinStartAndTargetLimit(   /* si32MaxStart  */   MAX_TORQUE_LIMIT,
                                        /* si32MinStart  */   MIN_TORQUE_LIMIT,
                                        /* si32MaxTarget */   siCalculatePowerTorqueLimit(pTorqueLimitTest->si32SetMotorVoltageInMilliVolt),
                                        /* si32MinTarget */   MAX_EXTENDED_CLOSE_TORQUE_LIMIT*pTorqueLimitTest->si8ExtendedClosingPercentTest/100,
                                        /* pTorqueLimitTest*/ pTorqueLimitTest );
										
    vUpdateMaxMinStartAndTargetLimit(   /* si32MaxStart  */   pTorqueLimitTest->si32TargetMaxTorqueLimitInMilliNm,
                                        /* si32MinStart  */   pTorqueLimitTest->si32TargetMinTorqueLimitInMilliNm,
                                        /* si32MaxTarget */   siCalculatePowerTorqueLimit(pTorqueLimitTest->si32SetMotorVoltageInMilliVolt),
                                        /* si32MinTarget */   si32MinHardwareTorqueLimitInMilliNm,
                                        /* pTorqueLimitTest*/ pTorqueLimitTest );
	
    vUpdateMaxMinStartAndTargetLimitByRampTimes(   /* si32OldMaxStart   */ pTorqueLimitTest->si32StartMaxTorqueLimitInMilliNm,
                                                   /* si32OldMinStart   */ pTorqueLimitTest->si32StartMinTorqueLimitInMilliNm,
                                                   /* si32OldMaxTarget  */ pTorqueLimitTest->si32TargetMaxTorqueLimitInMilliNm,
                                                   /* si32OldMinTarget  */ pTorqueLimitTest->si32TargetMinTorqueLimitInMilliNm,
                                                   /* si32NewMaxTarget  */ siCalculatePowerTorqueLimit(pTorqueLimitTest->si32SetMotorVoltageInMilliVolt),
                                                   /* si32NewMinTarget  */ MAX_EXTENDED_CLOSE_TORQUE_LIMIT*pTorqueLimitTest->si8ExtendedClosingPercentTest/100,
                                                   /* ui16RampTimes     */ ui16RampTimesTest,
                                                   /* pTorqueLimitTest  */ pTorqueLimitTest );	
	
            //maximum low energy torque limit
            si32MaxLowEnergyTorqueInMilliNm = si32SpringTorqueInMilliNm;
            si32MaxLowEnergyTorqueInMilliNm += si32LowEnergyTorqueInMilliNm;
            si32MaxLowEnergyTorqueInMilliNm += csi32UpperLowEnergyTorqueMarginInMilliNm;
            //minimum low energy torque limit
            si32MinLowEnergyTorqueInMilliNm = si32SpringTorqueInMilliNm;
            si32MinLowEnergyTorqueInMilliNm -= si32LowEnergyTorqueInMilliNm;
            si32MinLowEnergyTorqueInMilliNm -= csi32LowerLowEnergyTorqueMarginInMilliNm;
			
    //hardware limit
    const int32_t si32MaxHardwareTorqueLimitInMilliNm = motionControlInternal::MAX_HARDWARE_TORQUE;
    const int32_t si32MinHardwareTorqueLimitInMilliNm = - si32MaxHardwareTorqueLimitInMilliNm;		
  	///power limit: (90000/24)*(2555/256)=37426, 
    //max low energy limit:-45000+67000+1000=23000.
    si32TargetMaxTorqueLimitInMilliNm = siCalculateMaxLowEnergyTorqueLimit(si32SetSpringTorqueMilliNm);
	
	int32_t si32PowerAssistSettingTorque = pTorqueLimitTest->si8SetPowerAssistPercentTest*MAX_POWER_ASSIST_TORQUE_LIMIT/100-MAX_POWER_ASSIST_TORQUE_MARGIN;
	
	pTorqueLimitTest->si32SetSpringTorqueMilliNm + FREE_SWING_TORQUE_OFFSET_RANGE
	
	
    //extended set: -6000*(30/100)=-18000, 
	//min low energy limit:-45000-67000-1000=-103000.
	hardware limit: 4000*2555/256        = 39921,
	negative hardware limit:-4000*2555/256=-39921
    power limit  : (90000/24)*(2555/256) = 37426
	power limit  : (90000/26)*(2555/256) = 34547,
	
	max low energy limit:-45000+67000+1000=23000.
	min low energy limit:-45000-67000-1000=-103000.
	
 siCalculatePowerTorqueLimit(pTorqueLimitTest->si32SetMotorVoltageInMilliVolt); //(90000/24)*(2555/256)=37426
 siCalculateHardwareTorqueLimit(); //4000*2555/256=39921.
 - siCalculateHardwareTorqueLimit(); //-4000*2555/256=-39921.
 siCalculatePowerTorqueLimit(pTorqueLimitTest->si32SetMotorVoltageInMilliVolt); //(90000/-24)*(2555/256)=-37426
	
    ///Delta.
    siDeltaRampMinLimitTorqueInMilliNm = si32TargetMinTorqueLimitInMilliNm - MIN_TORQUE_LIMIT;
	siDeltaRampMaxLimitTorqueInMilliNm = si32TargetMaxTorqueLimitInMilliNm - MAX_TORQUE_LIMIT;
	
	///switch to auto mode
    eTorqueModeTest = motionControl::TorqueLimiter::TORQUE_MODE_AUTO;
	
    si32StartMaxTorqueLimitInMilliNm = MAX_TORQUE_LIMIT;
    si32StartMinTorqueLimitInMilliNm = MIN_TORQUE_LIMIT;
    si32TargetMaxTorqueLimitInMilliNm = siCalculatePowerTorqueLimit(si32SetMotorVoltageInMilliVolt); //(90000/24)*(2555/256)=37426
    si32TargetMinTorqueLimitInMilliNm = MAX_EXTENDED_CLOSE_TORQUE_LIMIT*si8ExtendedClosingPercentTest/100;	

	//the torque limit above back check angle.
    si32StartMinTorqueLimitInMilliNm = si32TargetMinTorqueLimitInMilliNm;
    si32StartMaxTorqueLimitInMilliNm = si32TargetMaxTorqueLimitInMilliNm;
    si32TargetMinTorqueLimitInMilliNm = MAX_EXTENDED_CLOSE_TORQUE_LIMIT*si8ExtendedClosingPercentTest/100;
    ///si32TargetMaxTorqueLimitInMilliNm, not changed.
	
	    void vRampTorqueLimitCheck (        motionControlInternal::TorqueLimiterImp* pTorqueLimiterImp,
                                        int32_t si32SetVoltage,
                                        int32_t si32TargetMaxSelectTorqueLimit,
                                        int32_t si32TargetMinSelectTorqueLimit,
                                        int32_t si32StartMaxSelectTorqueLimit,
                                        int32_t si32StartMinSelectTorqueLimit, /* max/min torque */
                                        motionControl::TorqueLimiterBackEnd::teLowEnergyModeType eLowEnergyMode,
                                        motionControl::TorqueLimiter::teTorqueModeType eTorqueMode,
                                        bool boExtendedClosingState,
                                        bool boSpringExistState,                /* mode */
                                        int32_t si32SetDoorAngle,
                                        uint16_t ui16RampTimes );

    vCommonTorqueLimitCheck (   torqueLimiterImp,
                                si32SetMotorVoltageInMilliVolt,
                                si32SetPowerInMilliWatt,
                                si32TargetMaxTorqueLimitInMilliNm,
                                si32TargetMinTorqueLimitInMilliNm,
                                si32StartMaxTorqueLimitInMilliNm,
                                si32StartMinTorqueLimitInMilliNm, /* max/min torque */
                                eLowEnergyModeTest,
                                eTorqueModeTest,
                                boSetExtendedClosingStateTest,
                                boSetMockSpringExistStateTest, /* mode */
                                si32SetDoorAngleInMicroRad,
                                si32SetSpringTorqueMilliNm,
                                si8ExtendedClosingPercentTest,
                                si8SetPowerAssistPercentTest );
								
	///===
	arguments:  -r1 -v
	
	cyggcc_s-1.dll
	cygwin1.dll
	cygstdc++-6.dll
	

//================================
2018.10.10 Wednesday.
01. code,	//torque limiter.
02. foc,
03. english.
04. email.
05. commu.

//================================
2018.10.09 Tuesday.
01. code,	//speed-control
02. foc,
03. english.
04. email.
05. commu.

//================================
2018.10.08 Monday.
01. code,	//position, pi-controller.
02. foc,
03. english.
04. email.
05. commu.

//================================
2018.10.06 sat.

https://yunpan.cn/crRgFzPfWniZi ???????? cae4

//================================
2018.09.25 Thursday.
01. Email.
02. code design.

//------unit test.
realease, 
//------
C:\Users\jerhua\Videos\Lync Recordings\Cui, Willis, Grosshog, Jeppa, Hua, Jerry - Tuesday, September 25, 2018 2.23.08 PM.mp4

_UNIT_TEST_COMMON_DIR_ = $(_PROJ_DIR_)unitTest/common/



10:36:52 **** Build of configuration Default for project SwingDoorPlatform ****
make -j program,unitTest/drivers,ARMCM3_GCC-debug-none-mbs_st_m64_core_v10 
$MBS_CC_TOOLCHAIN is [gcc-arm-none-eabi-4_9-2015q3]. To use another compiler, redefine MBS_CC_TOOLCHAIN
ABS - making product "products/unitTest/drivers", configuration:
- ABS_BUILD_ARCH: ARMCM3_GCC
- ABS_BUILD_VAR:  debug
- ABS_BUILD_CPU:  none
- ABS_BUILD_HW:   mbs_st_m64_core_v10
Reading makefiles...
*** using cached data from "_output/products-unitTest-drivers/ARMCM3_GCC-debug-none-mbs_st_m64_core_v10/products-unitTest-drivers.elf_cache"
$ABS_LINK_SCRIPT is [stm32f10x_hd_256k_48k_flash.ld]
### file "../src/system_stm32f10x.c" does not exist [mbsSdk/components/halMcu/init/stm32f10x/bareMetal/abs-component.mk]
*** [components: 17]

Programming...
BINARY = _output/products-unitTest-drivers/ARMCM3_GCC-debug-none-mbs_st_m64_core_v10/products-unitTest-drivers.elf

INFO: No tasks running with the specified criteria.
Open On-Chip Debugger 0.9.0 (2015-05-19-12:06)
Licensed under GNU GPL v2
For bug reports, read
	http://openocd.org/doc/doxygen/bugs.html
>>>> Trasport selected: hla_swd
Info : The selected transport took over low-level target control. The results might differ compared to plain JTAG/SWD
adapter speed: 1000 kHz
adapter_nsrst_delay: 100
none separate
none separate
Info : Unable to match requested speed 1000 kHz, using 950 kHz
Info : Unable to match requested speed 1000 kHz, using 950 kHz
Info : clock speed 950 kHz
Info : STLINK v2 JTAG v28 API v2 SWIM v7 VID 0x0483 PID 0x3748
Info : using stlink api v2
Info : Target voltage: 3.055409
Info : stm32f1x.cpu: hardware has 6 breakpoints, 4 watchpoints
    TargetName         Type       Endian TapName            State       
--  ------------------ ---------- ------ ------------------ ------------
 0* stm32f1x.cpu       hla_target little stm32f1x.cpu       running
target state: halted
target halted due to debug-request, current mode: Thread 
xPSR: 0x01000000 pc: 0x0804c920 msp: 0x2000add0
auto erase enabled
Info : device id = 0x10036414
Info : flash size = 512kbytes
target state: halted
target halted due to breakpoint, current mode: Thread 
xPSR: 0x61000000 pc: 0x2000003a msp: 0x2000add0
wrote 520192 bytes from file _output/products-unitTest-drivers/ARMCM3_GCC-debug-none-mbs_st_m64_core_v10/products-unitTest-drivers.elf in 22.748951s (22.331 KiB/s)
target state: halted
target halted due to breakpoint, current mode: Thread 
xPSR: 0x61000000 pc: 0x2000002e msp: 0x2000add0
target state: halted
target halted due to breakpoint, current mode: Thread 
xPSR: 0x61000000 pc: 0x2000002e msp: 0x2000add0
verified 518980 bytes in 7.454123s (67.991 KiB/s)
shutdown command invoked
ABS - "program,unitTest/drivers,ARMCM3_GCC-debug-none-mbs_st_m64_core_v10" done

10:37:29 Build Finished (took 37s.579ms)



//================================
2018.09.20 Thursday.
01. Email.
02. code design.

AUTO
MANUAL
POWER_ASSIST
MAX_POWER_ASSIST
FREE_SWING
//RAMP_TO_FREE_SWING
TORQUE_MODE_BRAKING

-> torque mode  
-> braking
-> freeSwing

One could elaborate some on the function. 

One idea is to set the 'torque mode' to FREE_SWING from start 
and use max-allowed-torque form the torqueLimiter during braking, 
and then 'ramp' the torque limit to max-limited-torque, perhaps in 
an intermediate internal state, (e.g. RAMP_TO_FREE_SWING). 

Another solution is to do the 'ramp' in the torqueLimiter, this 
might be a better solution? 
anyway, in that case stopCommand should 'start' with a new torque-mode, 
TORQUE_MODE_BRAKING. in that mode the torqueLimiter will put out 
limited-torque equal to max-allowed-torque. 
Then, when the torqueMode is switched to FREE_SWING, 
//the ramp is done in torqueLmiter instead.

Also, is it possible to implement something generic for the FREE_SWING 
part that may be reused in the freeSwing command?



For the freeSwing we have to remember that we may need to brake both-dir 
when approaching the frame and when approaching the doorStop. 
How will this be solved? Dual brake controllers, or a single controller 
that is limited in different directions depending on the direction of 
the door movement?


//================================
2018.09.19 Wednesday.
01. Email.
02. code design.

//================================
2018.09.18 Tuesday.
01. Email.
02. code design. //slowOpen unit test!
03. 双双聚餐。

//================================
2018.09.17 Monday.
01. Email.
02. TrueSTUDIO,  http://update.toem.de
	OS_USE_TRACE_SEMIHOSTING_DEBUG
	C++11 'constexpr' only available with -std=c++11 or -std=gnu++11
      for (i=9541; i>0; i--)
      {
    	  for (j=200; j>0; j--)
    	  {
    		  k++;
    	  }
      }

//================================
2018.09.10 Monday.
01. Email.
02. code design.
03. english learn.
04. communication, 
05. diease, residence.

//================================
2018.09.06 Thursday.
01. linear motor control.
02. slow open implementation set-up.
03. 

//================================ 20:00
2018.09.05 Wednesday.
01. chance, change,
02. perfect design, perfect code.
03. knowledge learn.

//================================ 18:00
2018.09.04 Tuesday.
01. kang1200.
02. jeppa brake speed control mock.
03. torquelimit design.

//================================ 20:00
2018.09.03 Monday.
01. jeppa email; 	//slow open design.
02. arm table; 		//arm, tractroty.
03. load program;
04. slow open imp-setup;

//================================ 
2018.08.27 Monday.
01. jeppa email; 	//slow open design.
02. arm code; 		//arm, tractroty.
03. english;
04. power assist program:   //system play; //free swing; //push & go test;
05. pull arm program: c300.
06. 高速停机不稳定；
07. 开关门时间可调；		//UL228;
08. 上位机工具；下周；

//================================ 
2018.08.27 Monday.
01. jeppa email;
02. arm code; 	//arm, tractroty.
03. debug; 		//开到位抖动(位置保持)，关不到位（电机问题）， 拉杆的门（pull）；
04. review learn code;


岗位职责：

职责：负责构建用户环境中，系统使用芯片的实际应用开发。负责芯片bringup以及板级BSP构建。

任职要求：
1、 电子工程，计算机相关专业本科及以上学历
2、 5年以上软件设计开发工作经验，精通C/C++
3、 熟悉Linux操作系统和Android架构，熟悉ARM或X86平台开发和编译环境
4、 掌握嵌入式Linux内核的裁剪、移植，设备驱动程序的开发、优化
5、 熟悉PCIe & AXI等协议，具有PCIe、DMA、I2C、UART、HDMI等模块的开发调试经验
6、 良好的中英文沟通能力
具有以下经验者优先：

1、 熟悉芯片研发流程，有芯片BSP或SDK开发经验
2、 熟悉OpenCV、OpenGL等视觉图像处理开源库
3、 深刻理解设计模式，对基于API的设计有丰富的开发经验
4、 有一定分布式计算框架的理解和经验

高级软件研发工程师

1.负责开发电机控制器固件和仪表固件功能开发，制定开发计划、撰写项目文档；	
2.负责将研发新品的软件设计需求转化为设计规范与测试规范；			
3.负责固件的测试、调试、验证工作等；			
4. 协助硬件、结构和测试工程师进行新品功能、性能、可靠性等方面的测试、验证及外部认证；		
5. 配合生产和技术服务部门，为产品的调试、测试和故障排查提供技术支持。		
任职要求：			
1. 可独立带领研发小组，完成相关项目研发工作；
2. 3年以上嵌入式产品研发经验，熟悉ARM 32位MCU者优先；			
3. 熟练掌握C语言，编码风格良好，调试技巧丰富，能独立解决问题；有基于C#的上位机软件开发经验者优先。			
4. 熟悉交流电机控制原理，有电机控制器固件和仪表固件开发经验者优先考虑；		
5. 良好的团队协作，能够承压、迎接挑战，能接受不定期的出差和客户端调试。		
6.必须有仪表或电驱动相关工作经验；	

//================================ 
2018.08.22 Wednesday.
01. project code.
02. 调试串口助手：数据接收显示；
03. 英语；
04. 直线电机控制：矢量算法；
05. 交流锻炼, Email, Skype。

//================================ 
2018.08.21 Tuesday.
01. project code.
02. 调试串口助手：数据接收显示；程序打包；
03. 英语；
04. 直线电机控制：矢量算法；
05. 交流锻炼, Email, Skype。

//================================ 
2018.08.20 Monday.
01. project code.
	文库账号；
02. 调试串口助手：数据接收显示；程序打包；
	//display not 0.
03. 英语；
04. 直线电机控制：矢量算法；
05. 交流锻炼, Email, Skype。

//================================ 
2018.08.17 Friday.
01. ECLPILSE graph tool: NOT FOUND.
	CDT, //-P "${project_loc}/${config_name:${project_name}/${project_name}.hex" -V -Rst
		 //C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\ST-LINK_CLI.exe
		 //-f "${project_loc}/../zs_tool/st_link/stlink-v2.cfg" 
		 //-f "${project_loc}/../zs_tool/st_link/stm32f1x_stlink.cfg"
	文库账号；
	
02. 调试串口助手：数据接收显示；程序打包；
	//display not 0.
03. 英语；
04. 直线电机控制：矢量算法；
	//MISRA,
05. 交流锻炼, Email, Skype。


//================================ 
2018.08.13 Monday.
01. ECLPILSE graph tool: NOT FOUND.
	//open cmd,
	//Git repo: 1for work, 2for ref.
	
torqueLimit-powerassist ?
	
02. 调试串口助手：数据接收显示；程序打包；
	//display not 0.
03. 英语；
04. 直线电机控制：矢量算法普及；
	//MISRA,
05. 交流锻炼, Email, Skype。


//================================ 
2018.08.10 Friday.
01. BLE 通讯调试；//
	//open cmd,
	//Git repo: 1for work, 2for ref.
	
02. 调试串口助手：数据接收显示；程序打包；
	//display not 0.
03. 英语；
04. 直线电机控制：矢量算法普及；
	//MISRA,
05. 交流锻炼, Email, Skype。

//================================ 
2018.08.09 Thursday.
01. BLE 通讯调试；//
	//open cmd,
	//Git repo: 1for work, 2for ref.
	
02. 调试串口助手：数据接收显示；程序打包；
	//display not 0.
03. 英语；
04. 直线电机控制：矢量算法普及；
	//MISRA,
05. 交流锻炼, Email, Skype。

//================================ 
2018.08.08 Wed.
01. BLE 通讯调试；//64:CF:D9:17:2B:D9
	FOC 熟练, 
	Git hub共用。
	winxp iso.	
02. 调试串口助手：数据接收显示；程序打包；
03. 英语；
04. 直线电机控制：矢量算法普及；
05. 交流锻炼, Email, Skype。

//================================ 
2018.08.07 Tuesday.
01. BLE 通讯调试；//64:CF:D9:17:2B:D9
	FOC 熟练, 
	Git hub共用。
	winxp iso.	
02. 调试串口助手：数据接收显示；程序打包；
03. 英语；
04. 直线电机控制：矢量算法普及；
05. 交流锻炼, Email, Skype。

//================================ 
2018.08.06 Monday.
01. BLE 通讯调试；//64:cf:d9:17:30:4e.
				  //64:cf:d9:17:35:b3.
				  //63:3F:DB:58:3B:C0
				  //64:CF:D9:17:2B:D9
	FOC 熟练, 
	Git hub共用。
	winxp iso.
	
	teClosingTorqueStateType	
	
	
02. 调试串口助手：数据接收显示；程序打包；
03. 英语；
04. 直线电机控制：矢量算法普及；
05. 交流锻炼, Email, Skype。


//================================ 
2018.08.03 Friday.
01. BLE,	
	FOC,
02. 调试串口助手：数据接收显示；程序打包；
03. 英语；
04. 直线电机控制：矢量算法普及；
05. 交流锻炼。

//================================ 
2018.08.02 Thursday.
01. //调试电机程序：速度曲线生成；
	0去掉EGR配置，测试电机是否抖动；
	0电机发热；
	0merge into ms1.
	
02. 调试串口助手：数据接收显示；程序打包；
03. 英语；
04. 直线电机控制：矢量算法普及；
05. 交流锻炼。	

//================================ 
2018.08.01 Wed.
01. //调试电机程序：速度曲线生成；
	0去掉EGR配置，测试电机是否抖动；
	0电机发热；
	0merge into ms1.
	
02. 调试串口助手：数据接收显示；程序打包；
03. 英语；
04. 直线电机控制：矢量算法普及；
05. 交流锻炼。	


//================================ 
2018.07.31 Tuesday.
01. 调试电机程序：速度曲线生成；
02. 调试串口助手：数据接收显示；程序打包；
03. 英语；
04. 直线电机控制：矢量算法普及；
05. 交流锻炼。
	
//================================ 
2018.07.30 Monday.
01. 调试电机程序：速度曲线生成；
02. 调试串口助手：数据接收显示；程序打包；
03. 英语；
04. 直线电机控制：矢量算法普及；
05. 交流锻炼。
	
//================================ 
2018.07.27 Friday.
//================================ 
2018.07.26 Thur.
01. 熟悉整体代码，把握程序结构；	
02. 熟悉Python代码，接收数据调试；
03. 调试电机程序；
04. 锻炼；坚强的毅力，坚韧的个性；
05. 技术交流；
06. 英语。
07. 直线电机。


*{background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0
rgba(214, 249, 255, 100), stop:1
rgba(158, 232, 250, 100) ); }
	
//================================ 
2018.07.25 Wed.
01. 熟悉整体代码，把握程序结构；	///SwingDoorPlatform/mbsSdk/tools/ABS/abs.mk  //ABS_BUILD_HW   := $(call abs-get-word,4)
02. 熟悉Python代码，接收数据调试；
03. 调试电机程序；
04. 锻炼；坚强的毅力，坚韧的个性；
05. 技术交流；
06. 英语。
07. 直线电机。

/SwingDoorPlatform/components/application/swingDoorGeneric/speedController/src/normalSpeedController.cpp
NormalSpeedControllerImp::vUpdate

	
//================================ 
2018.07.24 Tuesday.
01. //熟悉整体代码，把握程序结构；	///SwingDoorPlatform/mbsSdk/tools/ABS/abs.mk  //ABS_BUILD_HW   := $(call abs-get-word,4)
02. 熟悉Python代码，接收数据调试；
03. //调试电机程序；
04. //培训；
05. //技术交流；
06. 英语。
07. 直线电机。
	
//================================ 
2018.07.23 Monday.	
01. 培训时间预约；
02. 程序代码调时间；	
	
//================================ 
2018.07.20 Friday.	
01. tar = 'tar -cvzf %s %s -X /home/swaroop/excludes.txt' % (target, ' '.join(srcdir))	
02. SYSTEM_CONTROL_REGISTER_SYNCED_INIT_FUNCTION( initOutput,
03. case messages::ENCODER_INFO: vSetMotorEnable(),
04. motor print.
05. pMotorPowerPin->vSetPinHigh(); //output namespace.
	motorPowerPin.vSetPinHigh();   //outputInternal namespace.
06. fix PWM value.

//================================ 
2018.07.19 Thur.
/SwingDoorPlatform/mbsSdk/components/common/log/src/mbsLogTempStore.c //memset

//================================ 
2018.07.18 Wed.
01. trainning: Jemaes-production, experiment.
02. EMC experiment, 宏业路99号。

//================================ 
2018.07.17 Tuesday.
//ms1_test:
| Total                                                                                    | 101660  | 32735 |
| Unused memory                                                                            | 160484  | 15905 |

//================================ 
2018.07.17 Tuesday.
//---positionController:
/SwingDoorPlatform/modules/motionControl/motorBoard/mbs_st_m64_core_v10/abs-module.mk
//---macro enum define:
/SwingDoorPlatform/modules/motionControl/motorBoard/mbs_st_m64_core_v10/config/inc/motionControlConfig.hpp
//jerry_dev_v2_prototype.
| Total                                                                                    | 115662  | 33687 |
| Unused memory                                                                            | 146482  | 14953 |

//================================ 20:00
2018.07.16 Thur.
01. eventTimer->vRequestTimeout( cui8StatusTransitionDelayId, cui16StalledDelay )
recipe commences before first target.  Stop.

//================================ 18:00
2018.07.12 Thur.
01. //const修饰变量 //const修饰函数参数 //const修饰类对象-对象指针
	//const修饰数据成员 //const修饰成员函数 //修饰成员函数的返回值
const 更大的魅力是它可以修饰函数的参数、返回值，甚至函数的定义体。
const 是constant 的缩写，“恒定不变”的意思。被const 修饰的东西都受到强制保护，可以预防意外的变动，能提高程序的健壮性。所以很多C++程序设计书籍建议：“Use const whenever you need”。
---
任何不会修改数据成员(即函数中的变量) 的函数都应该声明为const 类型。 0稳健，不改变成员数据。
//它不改变对象的成员变量. 也不能调用类中任何非const成员函数。
int GetCount(void) const; // const 成员函数
如果在编写const 成员函数时，不慎修改了数据成员，或者调用了其它非const 成员函数，编译器将指出错误，这无疑会提高程序的健壮性。
---

02. volatile的本意是“易变的”,										1易变，小心使用。
volatile关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素更改，
比如操作系统、硬件或者其它线程等。遇到这个关键字声明的变量，编译器对访问该变量的代码
就不再进行优化，从而可以提供对特殊地址的稳定访问。
1). 一个参数既可以是const还可以是volatile吗？ 
是的。只读的状态寄存器，它是volatile因为它可能被意想不到地改变。它是const因为程序不应该试图去修改它。

多伦多海鲜自助餐厅(苏州石路天虹店) 
?	地址： 广济南路219号石路天虹5楼NO.520店铺 （距地铁2号线5号口步行350m）



//================================ 20:00
2018.07.11 Wed.
01. -i"../modules/motionControl/motorBoard/mbs_st_m64_core_v10/config/inc"
-i"../components/application/aaesGeneric/torqueLimiter/inc"

messageRouter useage:
//hpp doc,
//messageID, range (0-255 type .cpp uint8.)
//messageTable, subscriber, copy(), mbsMsgSend.
//Transmit: uint8, bool, buffer. 
//Receive: mbsMsgPollInBox(),  callback function.


//lint -e{930},

This is a summary for the meeting this morning.
We need more information to make decision for merger.
It's too early to make a decision.
We should move quickly to get a replacement for CFO.
At last, she also suggest to take a team building for the summer.
Thank you.

//================================
2018.07.10 Tue.
01. ble module(SmartRF), 
02. gcovr guide, 
03. torqueLimit unit test,
	//3.1-hardware: 4000*2555				=10220000
	
	//3.2-power90w: 24v: 1000*90*2555/24	= 9581250
	//3.2-power90w: 24v: 1000*90*2555/12	=19162500
	
	//3.3-force133: <1570: 1000*133*1000/10	=13300000
	//3.3-force133: >1570: 1000*133*1000/15	= 8866666
04. english.
05. print.

Hello Hua Jerry, 
感谢您今天与我通话，我非常高兴地欢迎您加入EF在线课程。我想鼓励您继续访问您的在线课程并且完成以下步骤以达到您的个人学习目标和公司KPI要求。

在线课程网址：https://corporate.ef.com.cn

KPI：建议与公司人事部核实。

同时，如果贵公司对小班会话课和私教课有考核要求的话，建议您提前完成，因为需要预留48小时给教师反馈时间，课程内的小班会话课是在课程订阅截止期前1~2天关闭，私人课堂是提前2~3天关闭预订系统，望您知晓。

课程有效期至: 2018年12月30日

请您按照以下步骤开始学习:
个人学习计划：
1）每月完成学习1个单元通用英语；
2）每月至少参加2节40分钟私教课堂；
3）每月至少参加1节单元最后的私人课堂；
4）每月至少参加1节小班会话课。

通过电脑端学习，请使用最新版的谷歌浏览器或者火狐浏览器：
Chrome: http://www.google.cn/intl/zh-CN/chrome/browser/ 
Firefox: http://www.firefox.com.cn/ 

您也可以通过手机进行学习：
请注意： 
1.第一次私人课程的预约必须通过电脑浏览器完成（请设置好正确时区），今后才可以使用手机进行正常预约。
2.目前手机端已经开放小班会话课上课功能。
3. 如您有时会在电脑端和手机端切换登陆课程，烦请您注意：您需要将单元内的一整节自学课（每个单元有4节自学课）在同一设备端完成，学习进度的数据才能被同步。

联系我们：如果您在学习中遇到任何问题，欢迎您登录课程页面从导航栏“需要帮助”中的“在线客服”和“email us”联系我们，您也可以直接从以下链接输入课程注册邮箱地址提交问题：
http://corporate.englishtown.cn/CustomerService/contactus/contactus.aspx?bhcp=1
在线学校使用快速指导视频：点击学校登录页面正下方的 学校演示 即可获得视频讲解帮助。或者直接点击该链接： http://corporate.ef.com.cn/Juno/16/78/23/v/167823/B2B_How_to_SC_v4.mp4

课程介绍：
普通英语共有16个级别，每级别有6个单元，每个单元包含四节自学课以及两种形式的口语课。
第一种形式是小班会话课，每天24小时的整点和大部分半点开课，每堂课45Min，没有参加次数限制，但是小班会话课是按照您是否在课堂待满30分钟以上及是否发言积极来评分的，所以不积极发言的分数可能不高。
第二种形式是每单元最后有一节对应的私人课堂，主要是对这个单元的复习和回顾，所以需要您先把前面的四节自学课自行完成，完成后会自动解锁，由于这节课是一对一的，所以需要您提前24小时在网上预约或者取消。
第三种形式是40分钟的私教课，主要是根据您的个人喜好选定一个主题，老师会根据您选定的主题来展开上课的主要内容。由于这节课也是一对一的，所以需要您提前24小时在网上预约或者取消。

---“每天几分钟的在线学习，为您展开精彩世界的无限可能。”祝您成功！

您的测试结果
日期： 2018-07-04
推荐级别： 10级 － 中高级
级别描述：
此阶段结束的时候，您将能跟上一个熟悉的话题或就此发言，或者能跟上一个包含广泛话题的对话。能浏览文章来获取相关信息，并能理解复杂详细的说明或建议。能在别人讲话时做笔记，或能写以不标准语言描述要求的信件。
总分： 52%
语法： 42%
听力： 52%
阅读： 61%


Best regards,
Cylin Hong 
Student Advisor 


多伦多海鲜自助餐厅(苏州石路天虹店) 
广济南路219号石路天虹5楼NO.520店铺,11:00-13:45

//================================
2018.07.09 Monday.
01. adc sample *2 used for pi calculate. 
	//2*dIs + 4096. (+/1)
	//2*Is.
			uint16_t ui16Crrt1 = static_cast<uint16_t>(inputInternal::ADCInputImp::aui16ReceivedBuffer[1U]);
			uint16_t ui16Crrt2 = static_cast<uint16_t>(inputInternal::ADCInputImp::aui16ReceivedBuffer[2U]);
			if ( ( 100U < ui16Crrt1 ) || ( 100U < ui16Crrt2 ) )
			{
//			    if ( 2048U < ui16Crrt1 )
//			    { //opening.
//                    ui16ThisI0 =  ( ui16Crrt1 - 2048U );
//                    ui16ThisI0 += ( ui16Crrt2 - 2048U );
//			    }
//			    else // ADC < 2048.
//			    { // closing
//                    ui16ThisI0 =  ( 2048U - ui16Crrt1 );
//                    ui16ThisI0 += ( 2048U - ui16Crrt2 );
//			    }
			    if ( ( 2048U < ui16Crrt1 ) && (2048U < ui16Crrt2) )
                { //opening.
                    ui16ThisI0 =  ( ui16Crrt1 - 2048U );
                    ui16ThisI0 += ( ui16Crrt2 - 2048U );
                }
			    if ( ( 2048U > ui16Crrt1 ) && (2048U > ui16Crrt2) )
                { //closing.
                    ui16ThisI0 =  ( 2048U - ui16Crrt1 );
                    ui16ThisI0 += ( 2048U - ui16Crrt2 );
                }
			}
			else
			{
			    //power on moment.
			}



    command = closeCommand;
    command->vRestart(); //object can restart.
	-> CloseCommandImp
	-> const int16_t si16PWM1 = static_cast<int16_t>(450) - (si16PWMWidth/static_cast<int16_t>(2));
	
/SwingDoorPlatform/components/application/swingDoorGeneric/motionCommand/src/openCommand.cpp
	//vSetLimitedTorqueFromSpeedController

/SwingDoorPlatform/components/application/swingDoorGeneric/speedController/src/speedController.cpp
	//si16Ek = si16SetSpeed - si16FeedbackSpeed; 
	//SpeedControllerImp::vUpdate Ctrl+Alt+H call hierarchy.
	//CloseCommandImp::vSetLimitedTorqueFromSpeedController.
	//CloseCommandImp::vUpdate( const int16_t si16ShaftSpeed )
	//enum { OBSTRUCTED_SPEED_LIMIT          = -24  }; //unit:mRad/s /* -0.024 rad/s shaft speed */
	//90dec.  //1000*PI/2= 1570-1571. //r=1, s=2PI.
	//enum { OPEN_ANGLE                      = static_cast<int>( 90.0*PI*1000000/180 ) }; //uRadians.

//================================
2018.07.05 Thur.
    command = closeCommand;
    command->vRestart(); //object can restart.
	-> CloseCommandImp
	-> const int16_t si16PWM1 = static_cast<int16_t>(450) - (si16PWMWidth/static_cast<int16_t>(2));


eclox - file:/C:/Users/jerhua/_huamg_assa_/03.033-swpk/Doxygen/packages/anb0s-eclox-a7d7762/


${CYGWIN_HOME}\bin;C:/Program Files (x86)/Java/jre1.8.0_161/bin/client;C:/Program Files (x86)/Java/jre1.8.0_161/bin;C:/Program Files (x86)/Java/jre1.8.0_161/lib/i386;C:\ProgramData\Oracle\Java\javapath;C:\Python27\Lib\site-packages\PyQt4;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Python27;C:\Python27\DLLs;C:\Python27\Scripts;C:\Python27\gnuplot\binary;C:\Program Files (x86)\pythonxy\SciTE-3.5.1-4;C:\Program Files (x86)\pythonxy\console;C:\Program Files (x86)\Borland\StarTeam SDK 10.4\Lib;C:\Program Files (x86)\Borland\StarTeam SDK 10.4\Bin;C:\Program Files\Git\cmd;C:\Users\jerhua\AppData\Local\Microsoft\WindowsApps;;C:\mbs\programs\eclipse


//================================
2018.07.04 Wed.

outputConfig.hpp: 
/SwingDoorPlatform/components/application/aaesGeneric/motor/unitTest/inc/outputConfig.hpp
/SwingDoorPlatform/modules/output/motorBoard/mbs_st_m64_core_v10/config/inc/outputConfig.hpp
/SwingDoorPlatform/modules/output/motorBoard/mbs_st_m64_core_v10/config/inc/outputConfig.hpp

mbsLogPrintf("motor pwm %d DEC \r",static_cast<int>(output::motor->si16GetMotorPwm()));

mbsLogPrintf("encoder V  == %d v\r",static_cast<int>(input::encoderVoltAdc->si32GetRealValue()));
mbsLogPrintf("motorVolt1 ==  %d v\r",static_cast<int>(input::motorVolt1Adc->si32GetRealValue()));
mbsLogPrintf("motorVolt2 ==  %d v\r",static_cast<int>(input::motorVolt2Adc->si32GetRealValue()));


//================================
2018.07.02 Monday.
01. torque limiter.
02. v2 board. //current sample should add, not sub.
	//L6205PD. Group AB, Bridge 12.
03. python.
04. project.
05. git //http://www.ossxp.com/doc/gotgit

//================================ 请假回家。
2018.06.29 Fri.
//================================
2018.06.28 Thur.
01. motor test. //limit.
02. torque limiter.

modules/input/motorBoard/mbs_st_m64_core_v10/init/src/input.cpp   //encoder.
modules/output/motorBoard/mbs_st_m64_core_v10/init/src/output.cpp //motor model.

//================================ 20:00
2018.06.27 Wed.
01. develop branch update mbsSdk; //submodule updagte fail. mbsSdkSwing is BRANCH.
02. jenkins driver sleep 90s.
03. digitalOutput polarity.

//================================ 20:30
2018.06.26 Tue.
01. digitalOutput polarity.

//================================ 20:00
2018.06.25 Monday.
01. can test. //normal 3.3V， push button, get data low.
	//motor 42X40, encoder ccw to cw.
	//modules/output/motorBoard/m64/init/src/output.cpp
static  MotorImp myMotorImp(
						/*motor direction*/			motorWrapper::CCW,
						/*motor inductance*/		2300,		//2300uH
						/*motor resistance*/		2600,		//2600mOhm
						/*torque/current constant*/	46U,		//46milliNm/A
						/*gear ration*/				245U
						);			
02. board, slope.

//================================ 20:00
2018.06.22 Fri.
01. digital output merge request unit test.
02. can test.

dir /b /a-d /on >list.txt
del *.d /f /s /q /a  >del_d.txt

//================================
2018.06.21 Thur.
01. digital output merge request revise.
02. git.


//================================
2018.06.20 Wed.
走通这条路！！！
01. merge request.
02. can code,
03. open command.


//================================
2018.06.19 Tue.
走通这条路！！！
01. jenkins, can, openCommand, //ouputConfig.hpp keep same.
02. python, Git,
03. english.

on target test: //outputConfig.hpp.
C/C++ Build:
${workspace_loc:/SwingDoorPlatform/components/application/aaesGeneric/digitalInput/unitTest}
${workspace_loc:/SwingDoorPlatform/components/application/aaesGeneric/digitalOutput/unitTest}
Apply.

error: reference to 'ADC_SETTLE_DELAY' is ambiguous

//================================
2018.06.15 Fri.

$ git cc -b org_dev origin/develop
warning: unable to rmdir 'mbsToolchains': Directory not empty
Switched to a new branch 'org_dev'
M       mbsSdk
Branch 'org_dev' set up to track remote branch 'develop' from 'origin'.

---
-I$(PATH_PROJ)		 /components/halMcu/interrupt/stm32f10x/inc/ \ 
加入这个
然后删掉
-I$(PATH_PROJ)/mbssdk/components/halMcu/interrupt/stm32f10x/inc/ \
---


//================================
2018.06.14 Thur.
01. PC-lint,
/*
MISRA: 0-1-5, 0-1-3,
*/

Variable references empty selection: ${project_loc}
C:\mbs\SwingDoorPlatform

C:\mbs\SwingDoorPlatform/unitTest/common/mbsComp/../../../mbsSdk/components/halMcu/stdPeriphLib_tp/stm32f10x/Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c:375: multiple definition of `GPIO_ResetBits'
_output/products-unitTest-drivers/ARMCM3_GCC-debug-none-mbs_st_m64_core_v10/obj/unitTest-common/src-stLibMock.cpp.o:C:\mbs\SwingDoorPlatform/unitTest/common/src/stLibMock.cpp:58: first defined here
collect2.exe: error: ld returned 1 exit status
make: *** [/cygdrive/c/mbs/SwingDoorPlatform/products/unitTest/drivers/abs-binary.mk:33: _output/products-unitTest-drivers/ARMCM3_GCC-debug-none-mbs_st_m64_core_v10/products-unitTest-drivers.elf] Error 1

///products-unitTest-drivers/ARMCM3_GCC-debug-none-mbs_st_m64_core_v10/obj/unitTest-common/src-stLibMock.cpp

//================================
2018.06.13 Wed.
01. Git,
$ git remote add depot /C/Users/jerhua/_huamg_assa_/02.003-wks/Git_depot

//================================
2018.06.12 Tue.
01. Git,
02. meeting.
03. openCommand.
04. debug.
   上下管直通预防，模拟测试波形；
 
/SwingDoorPlatform/		  modules/bsp/mbs_st_m64_core_v10/init/src/system_stm32f10x.c //system_16MHz.
/SwingDoorPlatform/		  modules/bsp/mbs_st_m64_core_v10/config/abs-component.mk	  //8Mhz.
/SwingDoorPlatform/mbsSdk/modules/bsp/mbs_st_m64_core_v10/config/abs-component.mk	  //8Mhz.
 
Function "Reset_Handler" not defined in 
"C:\\mbs\\SwingDoorPlatform\\mbsSdk\\components\\halMcu\\init\\stm32f10x\\src\\start_ARMCM3.s".

05. merge.
I did quite  lot, including unit tests for these components. 
It is saved in branch willis_dev_new_prototype, 
and implemented in folder components/application/swingDoorGeneric/motionCommand/

//------//
C:\Program Files (x86)\PC-lint 9.0


//================================
2018.06.11 Monday.
01. Git,
02. test new board.
 @明公?我上传了一个 wls_dev_v2_prototype 的版本 这周要帮忙确认硬件的功能 
 _1.下载下来烧入芯片用debug口连一下 看看波特率是不是和之前一样115200
 _2是的话 可以接电机转转看 如果不是的话 再说
 
 #define HSE_VALUE    ((uint32_t)16000000)
 
 /SwingDoorPlatform/modules/bsp/mbs_st_m64_core_v10/config/abs-component.mk
 
 115200
 230400
 
03. 

//================================
2018.06.07 Wed.
01. Git,
02. 转移的党组织关系； 

//================================
2018.06.05 Tue.
01. 请假；
02. 程序完善，板子测试；
03. 文档，英文等学习。
04. 按照计划督促进步。
05. Git branch master-devlop-feature-release-hotfix.
	clone mbssdk, eclipse simu sz0512, html hug, 
	

二、短线：
1.	旅游费用（细节参见上轮邮件）：成人767元/人，孩童217元/人；
2.	6月8日去程：早7：20分华虹街29号公司大门口----7：30分钟南街地铁站3号口-----7：40分国际博览中心公交车站------8：00分高速公路城区入口200米处------准时出发；
3.	6月9日回程：与去程相反；
4.	景区早晚温差大，请带好厚一点的衣物，以免受凉；
5.	请带上身份证的同时，仔细阅读莫干山出游注意事项（附件三）；


//================================
2018.06.04 Mon.


01. git :  develop: merge wls_dev_encoder into develop, update .gitingore file.

----------------------------------
$ git bb -vv
check upstream.
	
----------------------------------jerry_dev_dOutput	
jerhua@CNSUZL0009 MINGW64 /c/mbs/SwingDoorPlatform (jerry_dev_dOutput)
$ git fetch
remote: Counting objects: 381, done.
remote: Compressing objects: 100% (282/282), done.
remote: Total 381 (delta 150), reused 146 (delta 47)
Receiving objects: 100% (381/381), 122.16 KiB | 128.00 KiB/s, done.
Resolving deltas: 100% (150/150), done.
From aaes.githost.io:AAESSwingDoor/SwingDoorPlatform
   ab354d67..60e55a5f  jgr_dev_motor        -> origin/jgr_dev_motor
   4b38b50f..bb61a8d6  master               -> origin/master
 * [new branch]        wls_dev_can          -> origin/wls_dev_can
 * [new branch]        wls_dev_v2_prototype -> origin/wls_dev_v2_prototype

----------------------------------master
jerhua@CNSUZL0009 MINGW64 /c/mbs/SwingDoorPlatform (master)
$ git fetch
From aaes.githost.io:AAESSwingDoor/SwingDoorPlatform
 * [new branch]        jgr_dev_trajectories -> origin/jgr_dev_trajectories

----------------------------------merge.
在clone完成之后，Git 会自动为你将此远程仓库命名为origin（origin只相当于一个别名，
运行git remote –v或者查看.git/config可以看到origin的含义）

基于公共分支创建一个私有分支。
经常向这个私有分支commit代码。
一旦你的代码完善了，就清理掉下私有分支的历史。
将干净的私有分支merge到公共分支中。

01、请携带有效居民身份证
	

//================================
2018.06.01 Fri.
01. R&D meeting.
02. python.
03. review Adc component.
04. Doxgen!
05. BLE: 
	6 设备status： standby, advertiser, scanner, initiator, master, slave.
	5 工作status： standby, advertising, scanning, initialiating, connected.
	4 DEV type: central主机, periphal从机, observer观察者, broadcast广播者.
	
	MAC central can store 6 mac.

//================================
2018.05.31 Thur.
01. quasar project board.
02. Gcovr 100%.

//================================
2018.05.30 Wed.
01. digitaloutput unit test code. backup.
02. bool 存储大小。
03. cpputest manual agagin, detail.


//================================
2018.05.29 Tue.
01. test code. //digital output unit test->makfile->stLibMock.cpp
02. training.
03. english.
04. shenglin leaving email.

//================================
2018.05.28 Mon.
01. code,
02. trainning,
03. english.
04. swingdoorp meeting:
	time left, 
	millk help doc,
	motor supplier.
	

关于今年旅游，有以下几点共享：
1.	短线（莫干山）的目标是豪华游，吃好住好，标准1500，不足的部分公司会给大家发放零食。
2.	长线（张家界）目前计划去飞回动或来回双动，主要看旅行社是否能安排到票，价格大约3000左右。
为了能让旅行社能有个大概准确的数量，需要大家帮忙先确定一下旅游意向。
请有意向出游的同事，在今天下午16：00前填好表格：G:\R&D\2018\2018年旅游意向征集.xlsx
如果有任何问题，欢迎提出来。
另外：补贴原则: 工作未满3年的员工,公司补贴1500元/人,年满3年期及2016年福委会成员补贴1800元/人,
满5年期及优秀员工补贴2100元/人,满7年期的补贴2400元/人,10年期的补贴2700元/人，家属参加需支付全额旅游费用；（补贴不能累加）

短线2天1晚，出发时间未定，预计6/8走；长线5天4晚，6月7号下午或晚上出发。


//================================
2018.05.25 Fri.
01. python,
02. encoder test case, output test case,
03. team meeting,
04. PVB project visualize Board,
05. comment code. ===milestone.

//================================
2018.05.24 Thur.
01. pi-lint email check ALL.
02. 旅游征集；
03. digitalOutput module config.

//================================
2018.05.23 Wed.
01. UDS, ISO TP.
02. discuss Bluetooth.


//================================ 20:00
2018.05.22 Tue.
01. meld git.
02. jeppa meeting.
03. code.
04. shell.
	
	双引号（" "）：在双引号中，除了$, '', `和\以外所有的字符都解释成字符本身。
	单引号（' '）：在单引号中所有的字符包括特殊字符（$,'',`和\）都将解释成字符本身而成为普通字符。
	反引号（` `）：在反引号中的字符串将解释成shell命令来执行。
	
	${var}
	$(cmd)

06. glade UI desigener. VisualProgrammingTool
10. virtual, volatile = 0. 
	://init list, 
	:://range.
	

//================================
2018.05.21 Mon.
01. code.code.code.
	Data Protection Compliance Training - Level 1 //
	Gcovr path. add to PATH, find and add.
	//===
	git branch -a
	git fetch -a
	git status
	git stashgit
	git stash list
	
	git checkout -b deveop  origin/develop
	git branch -a (-r)
	git status
	git checkout jerry_test //change to branch jerry_test 
	git merge develop	
	git status //check merge result.
	
	

//================================
2018.05.18 Fri.
01. 告知别人可以赚更多；激励别人； 认清现状，提升自己。

//================================
2018.05.17 Thur.
01. 安装软件；
02. 输出模块建立；
03. 调试程序；
04. 思考为人处世，help，action。

//================================ 17:00-18:30
2018.05.16 Wed.		
	电话会议，备受打击。

//================================
2018.05.15 Tue.
01. 党组织关系介绍信；
02. 代码高效阅读，掌握结构；
03. 英语表达自己的想法；
04. 新技术学习PLC编码结构，PC-lint类似工具；
05. cygwin->Unix环境(cygwin1.dll支持库)，MinGW32->GNU工具；
	(Minimalist GNU for Windows)
	GNU (a recursive acronym meaning "GNU's not Unix") 革奴自由，改写-复制-发布。

//================================
2018.05.14 Mon.
01. build quasar main. 
	products/../mbsCfgTask.h.
	component/../helloWorld.c quasarMain();
	
02. discuss:
	


//================================
2018.05.11 Fri.
01. code remendy.
02. english.
03. Friday meeting.
04. Jeppa SW discuss.
05. INIT_GLOBALS_LEVEL error.


//================================
2018.05.10 Thur.
01. documents;
02. program download;
03. build, 
--- mbsSdk/components/application/mbsConsole - src/mbsConsoleCommandList.c
--- mbsSdk/components/halFunc/timestamp/generic - src/halTimestamp.c
--- components/application/aaesGeneric/monitoredImpulse - src/monitoredImpulse.cpp
--- mbsSdk/components/common/rtos/freeRTOS/mbsComp - ../Source/tasks.c
--- mbsSdk/components/common/stdlib - src/bspStdIo.c
--- mbsSdk/components/halFunc/serial/generic - src/halSerial.c

--- modules/input/mainboard/mbs_st_m64_core_v10/init - src/input.cpp
--- components/application/aaesGeneric/digitalInput - src/digitalInput.cpp
--- components/application/aaesGeneric/adcInput - src/adcInput.cpp
--- components/application/aaesGeneric/encoder - src/encoder.cpp

Creating launch file: SwingDoorPlatform,products-quasarMain,mbs_st_m64_core_v10,stlink-v2,debug.launch
Creating launch file: SwingDoorPlatform,products-quasarMain,mbs_st_m64_core_v10,stlink-v2,program-and-debug.launch
Creating launch file: SwingDoorPlatform,products-quasarMain-for-bootloader,mbs_st_m64_core_v10,stlink-v2,debug.launch
Creating launch file: SwingDoorPlatform,products-quasarMain-for-bootloader,mbs_st_m64_core_v10,stlink-v2,program-and-debug.launch
ABS - "build,quasarMain,ARMCM3_GCC-release-none-mbs_st_m64_core_v10" done


//================================
2018.05.09. Wed
01. read pdf.
02. running code.
03. english speaking.
04. trainning-data.!!!

$ git pull
Updating fa5bc54..be2cdb2
Fast-forward
 .../helloWorld/motorboard/src/helloWorld.cpp       |  2 +-
 .../mbs_st_m64_core_v10/init/src/input.cpp         |  6 ++---
 .../mbs_st_m64_core_v10/init/src/motionControl.cpp |  2 +-
 .../mbs_st_m64_core_v10/init/src/output.cpp        | 28 +++++++++++-----------
 4 files changed, 19 insertions(+), 19 deletions(-)


//================================
2018.05.08. Tue.
01. comm with jappa. softeare architecture!!
02. recv MISRA standard doc.
03. jenkins account by jappa.
04. st-link cable 4 wires.
05. english.

//================================
2018.05.07. Mon.
English.
email, screen, coffe, 
01. install software.
02. Git usage.
03. wellcome jappa.
 

//================================
2018.05.04 Fri. 
01. topic. meeting.
02. -software.
03. -helth check review.

LibUSB, ST-Link V2,
WinUSB,
Cygwin for 64-bit, (setup-x86.exe )

http://pydev.org/updates
http://www.highintegritysystems.com/StateViewer/
http://embsysregview.sourceforge.net/update

OpenOCD
RIDE,

CYGWIN:
Window->Preferences and add an path mapping as shown below:
Select “C/C++ -> Debug -> Source Lookup Path” then “Add -> Path mapping”
and add text Name: cygdrive, Compilation path: \cygdrive\c, Local file system
path: c:\

General->Editors->Text Editors

//system.
CWD 	C:\mbs\SwingDoorPlatform\
LANG	C.ISO-8859-1
PATH	${CYGWIN_HOME}\bin;C:/Program Files (x86)/Java/jre1.8.0_161/bin/client;C:/Program Files (x86)/Java/jre1.8.0_161/bin;C:/Program Files (x86)/Java/jre1.8.0_161/lib/i386;C:\ProgramData\Oracle\Java\javapath;C:\Python27\Lib\site-packages\PyQt4;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Python27;C:\Python27\DLLs;C:\Python27\Scripts;C:\Python27\gnuplot\binary;C:\Program Files (x86)\pythonxy\SciTE-3.5.1-4;C:\Program Files (x86)\pythonxy\console;C:\Program Files (x86)\Borland\StarTeam SDK 10.4\Lib;C:\Program Files (x86)\Borland\StarTeam SDK 10.4\Bin;C:\Program Files\Git\cmd;C:\Users\jerhua\AppData\Local\Microsoft\WindowsApps;;C:\mbs\programs\eclipse
PWD	C:\mbs\SwingDoorPlatform\
//usrs.
CYGWIN_HOME		C:\mbs\programs\cygwin
MBS_CC_TOOLCHAIN_PATH	../mbsToolchains/
MBS_OPENOCD_INTERFACE	stlink-v2
ECLIPSEPROJECT 		${ProjName}


GDB CDT:
Eclipse Software installation site by clicking on 
Help->Install New Software. Install from http://download.eclipse.org/tools/cdt/releases/kepler


//================================
2018.05.03

上午体检；
excel表格工具使用；
Git工具操作使用；
板子下载更新使用；

在D1单元格输入：=OFFSET(A$1,INT((ROW()-1)/4),MOD(ROW()-1,4))
在D1单元格输入：=OFFSET(A$1,INT((ROW(A1)-1)/4),MOD(ROW(A1)-1,4))
在D1单元格输入：=OFFSET(A$1,TRUNC((ROW()-1)/4),MOD(ROW()-1,4))

ANSI,
unicode。

ST-LINK V2 使用手册V1.1

//================================
2018.05.02

..................................
Stm32f10xPhysPortPinConf config; //define.
project compiler, board load.


..................................


01. -email; headset, docking;
02. eclipse, cpputest, git, Cygwin; PC-lint;
03. project code; sharing topic;
04. startteam, MBS, IAR; sdk;
05. win10-en, pinyin input.

prj: input, output, Jenkins, rtos, mk, sh.
top: excel crv.
stm: datasheet.
stm: lib. /main();

== tomorrow helth check.

//================================
2018.04.28

01. -email; -headset, -docking;
02. -eclipse, cpputest, git, -Cygwin; PC-lint;
03. -project code;
04. startteam, -MBS, IAR;
05. -win10-en. pinyin input. =Q-dir.

C:\mbs\programs\cygwin\bin\doxgen.exe

//================================
2018.04.27

Jerry.Hua@assaabloy.com

C:\mbs\work\documentation

//================================
2018.04.26

G:\R&D\2018\Jeff Zhang\Share\PD organization.

G:\R&D\Folder_Tree_Management\80_Tools\10_Design_Tools

https://aaes.githost.io/help/ssh/README#generating-a-new-ssh-key-pair

(/c/Users/jerhua/.ssh/id_rsa)

}
//5000-log.

