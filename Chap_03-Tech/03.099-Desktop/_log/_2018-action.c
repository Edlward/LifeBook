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
03. ���£�����嵥�����������˵�֧�֣� 
	��Ӧ�������ˣ�Jeppa remove enum ADC_TO_VOLT, Ҫ���ϸ񣬸ɾ���
04. ���е��ԣ���е���ˣ�CCL����������ߣ���SPM����������ߣ���
			���ܿ���λ�ζ���
			
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
Fixed�� in new commit as it may. 
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

G:\R&D\2017\Janny Zhang\��׼\USA

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
	
	1100-quasar and quasarMotor target doesn��t compile
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
10. ���������ӣ��������
	�״��ϵ��Ŷ������ֶ������Ŵ򿪣�����λ������ֹ������������
	ͨ�Ŷ������ӣ�

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
14. vs2005��C# code:  ('pc sw')

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
14. vs2005��C# code:  ('pc sw')

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
14. vs2005��C# code:  ('pc sw')

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
14. vs2005��C# code:  ('pc sw')

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
14. vs2005��C# code:  ('pc sw')

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

	My groceries cost about $400 each month. 			�ҵ��ӻ�����ÿ��Լ400 ��Ԫ��
	My train pass is $50 a month. 						�ҵĻ�ͨƱ��ÿ��50��Ԫ��
	My utility bill is usually around 200 per month. 	�ҵ�ˮ����˵�ͨ����Լÿ��200��
	My monthly mortgage payment is $2,500. 				��ÿ�°��Ҹ���Ϊ2��500��Ԫ��
	I pay about 7,000 in property tax every year. 		��ÿ�긶��Լ7��000����˰��
  	  	 
	����һЩ��һ��ʱ���ڷ�����ֹһ�εķ��ã������ʹ����twice��three times�����ĵ��ʡ�
  	  	 
	I pay my car insurance twice a year. 				��ÿ�긶�����������ա�
	I buy a subway ticket three times a week. 			��һ�������ε���Ʊ��
	
	
	�о�ѡ��
	����һ������ķ������г����ѡ�Ȼ��ѡ����õ�һ���� ע�������м������ʵ���˼��option��ͬ��
	One option is to lay off workers with low seniority. 	  	һ��ѡ���ǽ�͹���̵Ĺ��ˡ�
	We have to make some hard choices. 	  	���ǲ��ò���һЩ���ѵ�ѡ��
	One alternative is to use attrition. We just don't replace workers who leave. 	  	һ��ѡ����ʹ����ġ�Ա���뿪�����ǲ����������ְλ��
	Another possibility is to offer older workers a large retirement bonus. 	  	��һ���������Ǹ���Ա��һ�ʴ������ݽ���
	We may have to consider more drastic options. 	  	���ǿ��ܲ��ò����Ǹ����˵�ѡ��
	
	
	 My salary is $60,000, but my total compensation adds up to about $80,000 per year.
	  	�ҵĹ�����60��000��Ԫ�������ҵ�����н�������ÿ���Լ80��000��Ԫ��
	I'm really happy with the compensation package at my company. 	  	�Ҷ����ǹ�˾��н��������⡣
	
	 	
My benefits include generous medical and retirement plans, and three weeks of vacation each year.
	  	�ҵĸ�������������ҽ�ƺ����ݷ�������ÿ���������ڵ��ݼ١�
	My company contributes $500 every month to my retirement plan. 	  	�ҵĹ�˾ÿ��֧��500��Ԫ���ҵ����ݷ����С�
	There is a 400-a-month deduction for the medical plan. 	  	ÿ�¿۳�400��ҽ�Ƽƻ�Ǯ��
	Our medical plan includes dental work and any counseling we need. 	  	���ǵ�ҽ�Ʒ����������ƺ�������Ҫ���κ���ѯ���á�

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
01. vs2005��C# code: 
02. FOC, doctor paper.
03. freeRTOS.
04. pc-lint.
05. email.

mock, expectָ��ͬһ����ַ��
    void vExpectGetDoorAngle( int32_t* psi32DoorAngle )
    {
        mock().expectOneCall( "si32GetDoorAngleInMicroRad" )
              .andReturnValue( static_cast<void*>( psi32DoorAngle ) );
    }

ָ�����Ͳ���ת����ֱ��Դͷ����ΪӦ�õ����͡�
SlowOpenCommandImp* slowOpenCmdImp = reinterpret_cast<SlowOpenCommandImp*>(slowOpenCommand);

//================================
2018.11.28 Wednesday.
00. email.
00. platform: slowOpen.
01. vs2005��C# code: 
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
## ��ʾ����Library�ļ��е��ǲ�����Library�ļ����µ�.asset��β���ļ���
## ��Ҫע����ǣ����Ե��ļ���һ��Ҫ��β /* �����򲻺��Թ����޷���Ч��

## ��#����ʾע��
## ��/����ʾĿ¼��
## ��*��ͨ�����ַ���
## ��?��ͨ�䵥���ַ�
## ��[]�����������ַ���ƥ���б��μ�������ʽ��
## ��!����ʾ������*ƥ�䵽���ļ���Ŀ¼��
*/

//================================
2018.11.16 Friday.
00. platform, freeWing.
01. vs2005��C# code: 
02. FOC, doctor paper.
03. freeRTOS.
04. pc-lint.

//================================
2018.11.14 Wednesday.
00. platform, freeWing.
01. vs2005��C# code: 
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

�ݼ���˹�����¼ͳ�ƣ�����ɯ?����˹��������ʷ��������������ҡ�
����������ʽ���������룬ֻ��ʥ��������?ɯʿ���ǵ�������������������֮�ϡ�
������������ɳ���103�����ԣ�����ͻ��20�ڱ� 

���������������쳵ıɱ�������޺�ıɱ�����޽��ɰ� 

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
03. ˫˫�۲͡�

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
06. ����ͣ�����ȶ���
07. ������ʱ��ɵ���		//UL228;
08. ��λ�����ߣ����ܣ�

//================================ 
2018.08.27 Monday.
01. jeppa email;
02. arm code; 	//arm, tractroty.
03. debug; 		//����λ����(λ�ñ���)���ز���λ��������⣩�� ���˵��ţ�pull����
04. review learn code;


��λְ��

ְ�𣺸��𹹽��û������У�ϵͳʹ��оƬ��ʵ��Ӧ�ÿ���������оƬbringup�Լ��弶BSP������

��ְҪ��
1�� ���ӹ��̣���������רҵ���Ƽ�����ѧ��
2�� 5�����������ƿ����������飬��ͨC/C++
3�� ��ϤLinux����ϵͳ��Android�ܹ�����ϤARM��X86ƽ̨�����ͱ��뻷��
4�� ����Ƕ��ʽLinux�ں˵Ĳü�����ֲ���豸��������Ŀ������Ż�
5�� ��ϤPCIe & AXI��Э�飬����PCIe��DMA��I2C��UART��HDMI��ģ��Ŀ������Ծ���
6�� ���õ���Ӣ�Ĺ�ͨ����
�������¾��������ȣ�

1�� ��ϤоƬ�з����̣���оƬBSP��SDK��������
2�� ��ϤOpenCV��OpenGL���Ӿ�ͼ����Դ��
3�� ���������ģʽ���Ի���API������зḻ�Ŀ�������
4�� ��һ���ֲ�ʽ�����ܵ����;���

�߼�����з�����ʦ

1.���𿪷�����������̼����Ǳ�̼����ܿ������ƶ������ƻ���׫д��Ŀ�ĵ���	
2.�����з���Ʒ������������ת��Ϊ��ƹ淶����Թ淶��			
3.����̼��Ĳ��ԡ����ԡ���֤�����ȣ�			
4. Э��Ӳ�����ṹ�Ͳ��Թ���ʦ������Ʒ���ܡ����ܡ��ɿ��Եȷ���Ĳ��ԡ���֤���ⲿ��֤��		
5. ��������ͼ��������ţ�Ϊ��Ʒ�ĵ��ԡ����Ժ͹����Ų��ṩ����֧�֡�		
��ְҪ��			
1. �ɶ��������з�С�飬��������Ŀ�з�������
2. 3������Ƕ��ʽ��Ʒ�з����飬��ϤARM 32λMCU�����ȣ�			
3. ��������C���ԣ����������ã����Լ��ɷḻ���ܶ���������⣻�л���C#����λ������������������ȡ�			
4. ��Ϥ�����������ԭ���е���������̼����Ǳ�̼��������������ȿ��ǣ�		
5. ���õ��Ŷ�Э�����ܹ���ѹ��ӭ����ս���ܽ��ܲ����ڵĳ���Ϳͻ��˵��ԡ�		
6.�������Ǳ���������ع������飻	

//================================ 
2018.08.22 Wednesday.
01. project code.
02. ���Դ������֣����ݽ�����ʾ��
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨��
05. ��������, Email, Skype��

//================================ 
2018.08.21 Tuesday.
01. project code.
02. ���Դ������֣����ݽ�����ʾ����������
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨��
05. ��������, Email, Skype��

//================================ 
2018.08.20 Monday.
01. project code.
	�Ŀ��˺ţ�
02. ���Դ������֣����ݽ�����ʾ����������
	//display not 0.
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨��
05. ��������, Email, Skype��

//================================ 
2018.08.17 Friday.
01. ECLPILSE graph tool: NOT FOUND.
	CDT, //-P "${project_loc}/${config_name:${project_name}/${project_name}.hex" -V -Rst
		 //C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\ST-LINK_CLI.exe
		 //-f "${project_loc}/../zs_tool/st_link/stlink-v2.cfg" 
		 //-f "${project_loc}/../zs_tool/st_link/stm32f1x_stlink.cfg"
	�Ŀ��˺ţ�
	
02. ���Դ������֣����ݽ�����ʾ����������
	//display not 0.
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨��
	//MISRA,
05. ��������, Email, Skype��


//================================ 
2018.08.13 Monday.
01. ECLPILSE graph tool: NOT FOUND.
	//open cmd,
	//Git repo: 1for work, 2for ref.
	
torqueLimit-powerassist ?
	
02. ���Դ������֣����ݽ�����ʾ����������
	//display not 0.
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
	//MISRA,
05. ��������, Email, Skype��


//================================ 
2018.08.10 Friday.
01. BLE ͨѶ���ԣ�//
	//open cmd,
	//Git repo: 1for work, 2for ref.
	
02. ���Դ������֣����ݽ�����ʾ����������
	//display not 0.
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
	//MISRA,
05. ��������, Email, Skype��

//================================ 
2018.08.09 Thursday.
01. BLE ͨѶ���ԣ�//
	//open cmd,
	//Git repo: 1for work, 2for ref.
	
02. ���Դ������֣����ݽ�����ʾ����������
	//display not 0.
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
	//MISRA,
05. ��������, Email, Skype��

//================================ 
2018.08.08 Wed.
01. BLE ͨѶ���ԣ�//64:CF:D9:17:2B:D9
	FOC ����, 
	Git hub���á�
	winxp iso.	
02. ���Դ������֣����ݽ�����ʾ����������
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
05. ��������, Email, Skype��

//================================ 
2018.08.07 Tuesday.
01. BLE ͨѶ���ԣ�//64:CF:D9:17:2B:D9
	FOC ����, 
	Git hub���á�
	winxp iso.	
02. ���Դ������֣����ݽ�����ʾ����������
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
05. ��������, Email, Skype��

//================================ 
2018.08.06 Monday.
01. BLE ͨѶ���ԣ�//64:cf:d9:17:30:4e.
				  //64:cf:d9:17:35:b3.
				  //63:3F:DB:58:3B:C0
				  //64:CF:D9:17:2B:D9
	FOC ����, 
	Git hub���á�
	winxp iso.
	
	teClosingTorqueStateType	
	
	
02. ���Դ������֣����ݽ�����ʾ����������
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
05. ��������, Email, Skype��


//================================ 
2018.08.03 Friday.
01. BLE,	
	FOC,
02. ���Դ������֣����ݽ�����ʾ����������
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
05. ����������

//================================ 
2018.08.02 Thursday.
01. //���Ե�������ٶ��������ɣ�
	0ȥ��EGR���ã����Ե���Ƿ񶶶���
	0������ȣ�
	0merge into ms1.
	
02. ���Դ������֣����ݽ�����ʾ����������
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
05. ����������	

//================================ 
2018.08.01 Wed.
01. //���Ե�������ٶ��������ɣ�
	0ȥ��EGR���ã����Ե���Ƿ񶶶���
	0������ȣ�
	0merge into ms1.
	
02. ���Դ������֣����ݽ�����ʾ����������
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
05. ����������	


//================================ 
2018.07.31 Tuesday.
01. ���Ե�������ٶ��������ɣ�
02. ���Դ������֣����ݽ�����ʾ����������
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
05. ����������
	
//================================ 
2018.07.30 Monday.
01. ���Ե�������ٶ��������ɣ�
02. ���Դ������֣����ݽ�����ʾ����������
03. Ӣ�
04. ֱ�ߵ�����ƣ�ʸ���㷨�ռ���
05. ����������
	
//================================ 
2018.07.27 Friday.
//================================ 
2018.07.26 Thur.
01. ��Ϥ������룬���ճ���ṹ��	
02. ��ϤPython���룬�������ݵ��ԣ�
03. ���Ե������
04. ��������ǿ�����������͵ĸ��ԣ�
05. ����������
06. Ӣ�
07. ֱ�ߵ����


*{background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0
rgba(214, 249, 255, 100), stop:1
rgba(158, 232, 250, 100) ); }
	
//================================ 
2018.07.25 Wed.
01. ��Ϥ������룬���ճ���ṹ��	///SwingDoorPlatform/mbsSdk/tools/ABS/abs.mk  //ABS_BUILD_HW   := $(call abs-get-word,4)
02. ��ϤPython���룬�������ݵ��ԣ�
03. ���Ե������
04. ��������ǿ�����������͵ĸ��ԣ�
05. ����������
06. Ӣ�
07. ֱ�ߵ����

/SwingDoorPlatform/components/application/swingDoorGeneric/speedController/src/normalSpeedController.cpp
NormalSpeedControllerImp::vUpdate

	
//================================ 
2018.07.24 Tuesday.
01. //��Ϥ������룬���ճ���ṹ��	///SwingDoorPlatform/mbsSdk/tools/ABS/abs.mk  //ABS_BUILD_HW   := $(call abs-get-word,4)
02. ��ϤPython���룬�������ݵ��ԣ�
03. //���Ե������
04. //��ѵ��
05. //����������
06. Ӣ�
07. ֱ�ߵ����
	
//================================ 
2018.07.23 Monday.	
01. ��ѵʱ��ԤԼ��
02. ��������ʱ�䣻	
	
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
02. EMC experiment, ��ҵ·99�š�

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
01. //const���α��� //const���κ������� //const���������-����ָ��
	//const�������ݳ�Ա //const���γ�Ա���� //���γ�Ա�����ķ���ֵ
const ��������������������κ����Ĳ���������ֵ�����������Ķ����塣
const ��constant ����д�����㶨���䡱����˼����const ���εĶ������ܵ�ǿ�Ʊ���������Ԥ������ı䶯������߳���Ľ�׳�ԡ����Ժܶ�C++��������鼮���飺��Use const whenever you need����
---
�κβ����޸����ݳ�Ա(�������еı���) �ĺ�����Ӧ������Ϊconst ���͡� 0�Ƚ������ı��Ա���ݡ�
//�����ı����ĳ�Ա����. Ҳ���ܵ��������κη�const��Ա������
int GetCount(void) const; // const ��Ա����
����ڱ�дconst ��Ա����ʱ�������޸������ݳ�Ա�����ߵ�����������const ��Ա��������������ָ�����������ɻ���߳���Ľ�׳�ԡ�
---

02. volatile�ı����ǡ��ױ�ġ�,										1�ױ䣬С��ʹ�á�
volatile�ؼ�����һ���������η����������������ͱ�����ʾ���Ա�ĳЩ������δ֪�����ظ��ģ�
�������ϵͳ��Ӳ�����������̵߳ȡ���������ؼ��������ı������������Է��ʸñ����Ĵ���
�Ͳ��ٽ����Ż����Ӷ������ṩ�������ַ���ȶ����ʡ�
1). һ�������ȿ�����const��������volatile�� 
�ǵġ�ֻ����״̬�Ĵ���������volatile��Ϊ�����ܱ����벻���ظı䡣����const��Ϊ����Ӧ����ͼȥ�޸�����

���׶ຣ����������(����ʯ·����) 
?	��ַ�� �����·219��ʯ·���5¥NO.520���� �������2����5�ſڲ���350m��



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
��л����������ͨ�����ҷǳ����˵ػ�ӭ������EF���߿γ̡�������������������������߿γ̲���������²����Դﵽ���ĸ���ѧϰĿ��͹�˾KPIҪ��

���߿γ���ַ��https://corporate.ef.com.cn

KPI�������빫˾���²���ʵ��

ͬʱ�������˾��С��Ự�κ�˽�̿��п���Ҫ��Ļ�����������ǰ��ɣ���Ϊ��ҪԤ��48Сʱ����ʦ����ʱ�䣬�γ��ڵ�С��Ự�����ڿγ̶��Ľ�ֹ��ǰ1~2��رգ�˽�˿�������ǰ2~3��ر�Ԥ��ϵͳ������֪����

�γ���Ч����: 2018��12��30��

�����������²��迪ʼѧϰ:
����ѧϰ�ƻ���
1��ÿ�����ѧϰ1����Ԫͨ��Ӣ�
2��ÿ�����ٲμ�2��40����˽�̿��ã�
3��ÿ�����ٲμ�1�ڵ�Ԫ����˽�˿��ã�
4��ÿ�����ٲμ�1��С��Ự�Ρ�

ͨ�����Զ�ѧϰ����ʹ�����°�Ĺȸ���������߻���������
Chrome: http://www.google.cn/intl/zh-CN/chrome/browser/ 
Firefox: http://www.firefox.com.cn/ 

��Ҳ����ͨ���ֻ�����ѧϰ��
��ע�⣺ 
1.��һ��˽�˿γ̵�ԤԼ����ͨ�������������ɣ������ú���ȷʱ���������ſ���ʹ���ֻ���������ԤԼ��
2.Ŀǰ�ֻ����Ѿ�����С��Ự���Ͽι��ܡ�
3. ������ʱ���ڵ��Զ˺��ֻ����л���½�γ̣�������ע�⣺����Ҫ����Ԫ�ڵ�һ������ѧ�Σ�ÿ����Ԫ��4����ѧ�Σ���ͬһ�豸����ɣ�ѧϰ���ȵ����ݲ��ܱ�ͬ����

��ϵ���ǣ��������ѧϰ�������κ����⣬��ӭ����¼�γ�ҳ��ӵ���������Ҫ�������еġ����߿ͷ����͡�email us����ϵ���ǣ���Ҳ����ֱ�Ӵ�������������γ�ע�������ַ�ύ���⣺
http://corporate.englishtown.cn/CustomerService/contactus/contactus.aspx?bhcp=1
����ѧУʹ�ÿ���ָ����Ƶ�����ѧУ��¼ҳ�����·��� ѧУ��ʾ ���ɻ����Ƶ�������������ֱ�ӵ�������ӣ� http://corporate.ef.com.cn/Juno/16/78/23/v/167823/B2B_How_to_SC_v4.mp4

�γ̽��ܣ�
��ͨӢ�ﹲ��16������ÿ������6����Ԫ��ÿ����Ԫ�����Ľ���ѧ���Լ�������ʽ�Ŀ���Ρ�
��һ����ʽ��С��Ự�Σ�ÿ��24Сʱ������ʹ󲿷ְ�㿪�Σ�ÿ�ÿ�45Min��û�вμӴ������ƣ�����С��Ự���ǰ������Ƿ��ڿ��ô���30�������ϼ��Ƿ��Ի��������ֵģ����Բ��������Եķ������ܲ��ߡ�
�ڶ�����ʽ��ÿ��Ԫ�����һ�ڶ�Ӧ��˽�˿��ã���Ҫ�Ƕ������Ԫ�ĸ�ϰ�ͻعˣ�������Ҫ���Ȱ�ǰ����Ľ���ѧ��������ɣ���ɺ���Զ�������������ڿ���һ��һ�ģ�������Ҫ����ǰ24Сʱ������ԤԼ����ȡ����
��������ʽ��40���ӵ�˽�̿Σ���Ҫ�Ǹ������ĸ���ϲ��ѡ��һ�����⣬��ʦ�������ѡ����������չ���Ͽε���Ҫ���ݡ�������ڿ�Ҳ��һ��һ�ģ�������Ҫ����ǰ24Сʱ������ԤԼ����ȡ����

---��ÿ�켸���ӵ�����ѧϰ��Ϊ��չ��������������޿��ܡ���ף���ɹ���

���Ĳ��Խ��
���ڣ� 2018-07-04
�Ƽ����� 10�� �� �и߼�
����������
�˽׶ν�����ʱ�������ܸ���һ����Ϥ�Ļ����ʹ˷��ԣ������ܸ���һ�������㷺����ĶԻ����������������ȡ�����Ϣ��������⸴����ϸ��˵�����顣���ڱ��˽���ʱ���ʼǣ�����д�Բ���׼��������Ҫ����ż���
�ܷ֣� 52%
�﷨�� 42%
������ 52%
�Ķ��� 61%


Best regards,
Cylin Hong 
Student Advisor 


���׶ຣ����������(����ʯ·����) 
�����·219��ʯ·���5¥NO.520����,11:00-13:45

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

//================================ ��ٻؼҡ�
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
01. can test. //normal 3.3V�� push button, get data low.
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
��ͨ����·������
01. merge request.
02. can code,
03. open command.


//================================
2018.06.19 Tue.
��ͨ����·������
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
�������
Ȼ��ɾ��
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
   ���¹�ֱͨԤ����ģ����Բ��Σ�
 
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
 @����?���ϴ���һ�� wls_dev_v2_prototype �İ汾 ����Ҫ��æȷ��Ӳ���Ĺ��� 
 _1.������������оƬ��debug����һ�� �����������ǲ��Ǻ�֮ǰһ��115200
 _2�ǵĻ� ���Խӵ��תת�� ������ǵĻ� ��˵
 
 #define HSE_VALUE    ((uint32_t)16000000)
 
 /SwingDoorPlatform/modules/bsp/mbs_st_m64_core_v10/config/abs-component.mk
 
 115200
 230400
 
03. 

//================================
2018.06.07 Wed.
01. Git,
02. ת�Ƶĵ���֯��ϵ�� 

//================================
2018.06.05 Tue.
01. ��٣�
02. �������ƣ����Ӳ��ԣ�
03. �ĵ���Ӣ�ĵ�ѧϰ��
04. ���ռƻ����ٽ�����
05. Git branch master-devlop-feature-release-hotfix.
	clone mbssdk, eclipse simu sz0512, html hug, 
	

�������ߣ�
1.	���η��ã�ϸ�ڲμ������ʼ���������767Ԫ/�ˣ���ͯ217Ԫ/�ˣ�
2.	6��8��ȥ�̣���7��20�ֻ����29�Ź�˾���ſ�----7��30�����Ͻֵ���վ3�ſ�-----7��40�ֹ��ʲ������Ĺ�����վ------8��00�ָ��ٹ�·�������200�״�------׼ʱ������
3.	6��9�ջس̣���ȥ���෴��
4.	���������²������ú�һ����������������
5.	��������֤��ͬʱ����ϸ�Ķ�Ī��ɽ����ע���������������


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
��clone���֮��Git ���Զ�Ϊ�㽫��Զ�ֿ̲�����Ϊorigin��originֻ�൱��һ��������
����git remote �Cv���߲鿴.git/config���Կ���origin�ĺ��壩

���ڹ�����֧����һ��˽�з�֧��
���������˽�з�֧commit���롣
һ����Ĵ��������ˣ����������˽�з�֧����ʷ��
���ɾ���˽�з�֧merge��������֧�С�

01����Я����Ч�������֤
	

//================================
2018.06.01 Fri.
01. R&D meeting.
02. python.
03. review Adc component.
04. Doxgen!
05. BLE: 
	6 �豸status�� standby, advertiser, scanner, initiator, master, slave.
	5 ����status�� standby, advertising, scanning, initialiating, connected.
	4 DEV type: central����, periphal�ӻ�, observer�۲���, broadcast�㲥��.
	
	MAC central can store 6 mac.

//================================
2018.05.31 Thur.
01. quasar project board.
02. Gcovr 100%.

//================================
2018.05.30 Wed.
01. digitaloutput unit test code. backup.
02. bool �洢��С��
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
	

���ڽ������Σ������¼��㹲��
1.	���ߣ�Ī��ɽ����Ŀ���Ǻ����Σ��Ժ�ס�ã���׼1500������Ĳ��ֹ�˾�����ҷ�����ʳ��
2.	���ߣ��żҽ磩Ŀǰ�ƻ�ȥ�ɻض�������˫������Ҫ���������Ƿ��ܰ��ŵ�Ʊ���۸��Լ3000���ҡ�
Ϊ���������������и����׼ȷ����������Ҫ��Ұ�æ��ȷ��һ����������
����������ε�ͬ�£��ڽ�������16��00ǰ��ñ��G:\R&D\2018\2018��������������.xlsx
������κ����⣬��ӭ�������
���⣺����ԭ��: ����δ��3���Ա��,��˾����1500Ԫ/��,����3���ڼ�2016�긣ί���Ա����1800Ԫ/��,
��5���ڼ�����Ա������2100Ԫ/��,��7���ڵĲ���2400Ԫ/��,10���ڵĲ���2700Ԫ/�ˣ������μ���֧��ȫ�����η��ã������������ۼӣ�

����2��1������ʱ��δ����Ԥ��6/8�ߣ�����5��4��6��7����������ϳ�����


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
02. ����������
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
	
	˫���ţ�" "������˫�����У�����$, '', `��\�������е��ַ������ͳ��ַ�����
	�����ţ�' '�����ڵ����������е��ַ����������ַ���$,'',`��\���������ͳ��ַ��������Ϊ��ͨ�ַ���
	�����ţ�` `�����ڷ������е��ַ��������ͳ�shell������ִ�С�
	
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
01. ��֪���˿���׬���ࣻ�������ˣ� ������״�������Լ���

//================================
2018.05.17 Thur.
01. ��װ�����
02. ���ģ�齨����
03. ���Գ���
04. ˼��Ϊ�˴�����help��action��

//================================ 17:00-18:30
2018.05.16 Wed.		
	�绰���飬���ܴ����

//================================
2018.05.15 Tue.
01. ����֯��ϵ�����ţ�
02. �����Ч�Ķ������սṹ��
03. Ӣ�����Լ����뷨��
04. �¼���ѧϰPLC����ṹ��PC-lint���ƹ��ߣ�
05. cygwin->Unix����(cygwin1.dll֧�ֿ�)��MinGW32->GNU���ߣ�
	(Minimalist GNU for Windows)
	GNU (a recursive acronym meaning "GNU's not Unix") ��ū���ɣ���д-����-������

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
Select ��C/C++ -> Debug -> Source Lookup Path�� then ��Add -> Path mapping��
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

������죻
excel��񹤾�ʹ�ã�
Git���߲���ʹ�ã�
�������ظ���ʹ�ã�

��D1��Ԫ�����룺=OFFSET(A$1,INT((ROW()-1)/4),MOD(ROW()-1,4))
��D1��Ԫ�����룺=OFFSET(A$1,INT((ROW(A1)-1)/4),MOD(ROW(A1)-1,4))
��D1��Ԫ�����룺=OFFSET(A$1,TRUNC((ROW()-1)/4),MOD(ROW()-1,4))

ANSI,
unicode��

ST-LINK V2 ʹ���ֲ�V1.1

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

