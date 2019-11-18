
//================================
1000-plan list:
{
00. 2019-plan: 	English,   			Speechcraft,
                Janpanse,           Words,
				Heart HuSea ocean,  Heart-Mouth-Step-One.
				FOC board, 			TaoBao CodeStore, 
				Work commu skill,	Taekwondo,			Chinese Go Chess 'Do',
				Honeymoon, 			WeddingPhotos,		Wedding feast,
				
01. every day : 01.00-(Notes)Note, is just note. 	//note.
				01.01-(Commu)Email,					//commu-understand-english.
				01.02-(Rview)GitLab web, git shell fetch.	//check state.
				01.03-(Assgn)Jira,		//assign.
				01.04-(Tools)Eclipse,  	//NotePad, Q-Dir, FireFox, Email.
				01.05-(Speak)English,  	//speadk.
				
				  Code.
				  project board; 
				  Git commit; 
                  smile to problem; 
                  email;
				  UnitTest.

    01. project doc, UL.
    02. project code, led twinkle, //led indicator, sequencer comments.
    03. project test, (mode change from open to auto, door pause short time.)
                      (closed, current not same.)
                      (reveal same, update sw changed arm table, door open angle change only 0.2 degree.)
    04. project hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
    08. meeting, daily update, test sharing.
    09. behave, slow speak fast thinking, fast action.
    10. other, reimburement, stock, weiChat, lunch.
					  
		
					  
02. every Monday: swing door platform meeting.
03. trainning.
04. Python.
05. Key Words:

	NCV, ATS;// WORK.
	EGM, DLU;//(eclipse)
	BFC, CMP.//(git)
	CPI, OVS.// name.



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

07. jenkins run CNOffice test, can message door open and close.

08. jira develop stage drag and assign.

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
    /work_tasks_xlsx.
    G:\R&D\Folder_Tree_Management\95_Project_Review\
    
		
06. \100_Special_Project\
	\\cnsuzsfp01\suzhou$\R&D\Folder_Tree_Management\100_Special_Project\Slider\Magnetic linear drive sliding door
	
07. G:\R&D\2018\Jeff Zhang\Weekly meeting\
08. G:\R&D\Folder_Tree_Management\95_Project_Review\
09. G:\R&D\Folder_Tree_Management\41_Active_Projects_Electronics\Technology sharing\
10. G:\R&D\Folder_Tree_Management\95_Project_Review\KPI\2018\
     //idcproxy， chinaproxy
11. G:\R&D\2018\Jeff Zhang\2018 KPI\Review result
	\\cnsuzsfp01\suzhou$\R&D\2019\Jeff Zhang\Vacation list
	G:\R&D\Folder_Tree_Management\41_Active_Projects_Electronics\SwingDoorPlatform\
	
12. http://demeesis0038.ad.global:8080/job/SwingDoors/job/jer_dev_learnCmd/15/consoleFull


	
	
}
//1002.

//================================
1003-expand knowledge:
{
001. hardware.
{
    //===MOTOR BOARD===//		V3. jerry_dev_v3_prototype.  helloWorld.cpp:202:       GPIO_SetBits(GPIOC, GPIO_Pin_11);
    pin26-PB0 , not used,     HW_VERSION.
    pin24-PC4 , not used,     HW_VERSION.

    pin16-PA2 , 'U_ENCODER_FB', not used in V3.
    pin20-PA4 , v3.3,         /I_ENCODER_FB.
    pin21-PA5 , "v2.5REF",      not used in V3.
    pin22-PA6 , not used,     /v2.5REF.
    pin44-PA11, not used,     /MOTOR_WATCHDOG. //"MOTOR_POWER" power, relay.

    pin39-PC8 , HOME1,     	  not used.
    pin40-PC9 , not used,     /MOTOR_ENABLE.   //module/init/output.cpp
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
	
	There should be some test-case testing that the trajectoryGenerator->vResetSpeed function is called. A good aproach is to write the testcase first to see that it fails and then update the code to make it pass. That way one knows that the test is relevant.
	.
	Corrected in new commit. In my understanding now, the method should be used to learn spring exist state, so it should not assume spring exist state.
}    
  
003. git cmd
{
    //config
    git config --global alias.st status
    git config --global alias.log10  "log -10 --graph --oneline"
        
    git whatchanged --since='2 weeks ago'
        
	git for-each-ref --sort=-committerdate refs/heads/
		
    //branch, repository
    git log10       /* branch tree. */
    git branch -vv  /* upstream     */
    git status      /* local status.*/
    
	git branch -r --contains CommitID
    git checkout --orphan  NEW_BRANCH_NAME_HERE
    
    git fetch -p                /*获取和清除旧数据，非常好用。*/
	
    //rebase
    git rebase --continue       /*衍合，衍变融合； 他人有不一样的更改，需要解决冲突。*/
	git reset --hard HEAD~1 则删除了commit3，如果发现删除错误了，需要恢复commit3，这个时候就要使用git reflog
    
    git bundle create <file> <branch-name>
    
    //log
    git log Branch1 ^Branch2
    
    git for-each-ref --sort=-committerdate --format='%(refname:short)' refs/heads/
    
    //grep
    git grep --break --heading --line-number
    git grep 'variableName' -- '*.java'
    git archive -o ../updated.zip HEAD $(git diff --name-only HEAD^)
    
    //git stash
    git stash list
    git stash show
    git stash drop
    
    git stash push  
    git stash pop  
    git stash apply  
    
    git stash clear 
    
    //remote, origin
     
}

004. eclipse cmd
{
	----------------------
	uml_mdt - file:/C:/Users/jerhua/Downloads/mdt-uml2-Update-5.5.0/
	
	http://plantuml.com/eclipse
	http://hallvard.github.io/plantuml/
	http://files.idi.ntnu.no/publish/plantuml/repository/
	
	----------------------
	window -> preference -> C/C++ -> codeStyle -> formatter.
	MingoBSD_Wrap_Func03
	file   -> export -> general -> preference.
	
	----------------------
}

005. concept
{
	前端就是作为用户（使用系统的人）来说可以"看得到"的交互部分， 后端则是持久化数据或者将持久化数据读取出来的"不可见"部分。
    BackEnd: 对组件对配置，例如setRetryAttempts().
}

  
}
//1003.

//=================================
1004-problems:
{
issue:
	motor enable;
	basic io 24v_out_en;
	


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
03. 做事，完成清单；帮助，别人的支持； //做事，提出风险，请示领导通过。
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
//################################
1009-log:
{
周一，10：00 - 11:00+
周二，09：00 - 10:30
周三，09：00 - 10:50, 14:00-14:20


/**
Android,
PLC,
FreeRTOS,

Octave, 

7.1-7.21 Sweden crash holiday, merge request?

**/


桌面； bash,  eclipse; 
       email, web;
       notePad, pctool;
       dir,     everything.

------------------------------------
------------------------------------
Q List:
01. Learn    : After learned, recycle door, burn motor board relay;
02. Parameter: push and go not disabled; not 4 degree， maybe 30 degree.
    Just can change block 0.
    hold open time, short.
03. Torque   :  //Open stalled, adapter reset; torqueLimiter hardware limit work;
                //Spring retension, FreeSwing negative spring torque.
04. BLE      : ble conneted status;
05. safeRTOS : version, MPU;
06. Power assist:  0%-100% //(mode enter？torque mode keep?)
07. Foce     : <133; now 150-170;
08. Open angle: longtime open angle changed from 90 to 110.
08. New sw rd:
09. document : learn command ? learn calculator?
10. Difference: Adc plus5, old one.

------------------------------------ 
9.5-Deniel Hellsson wife birthday,

------------------------------------ 

/What happens:

When performing a Learn on a door that opens more than 90 degrees the Learn functionality appears to crash and closes the door slowly until the last bit where it slams shut.
When door is blocked to a position less than 90 degrees the Learn finishes ok.
This problem has been verified with Michael

/Expectation:
When Learn has opened the door fully it shall follow a specific close sequence where it closes the door quickly a bit before closing the door in a controlled way.
On the weight door in the SE Test lab (EN 4) the door only opens to 90 degrees and there we do not see this problem. 

/Step by step:

    Door flashed (using the Gitlab pipeline)
    Press the Learn button
    Press open door button

/Tested on:
Two office table tops (CI and HIL) with larger than 90 degrees opening (estimate it to 110 degrees) and very little weight. Both fails in different ways
Test lab door in Landskrona: EN4, open only 90 degrees. Works ok.

/Build:
develop_free: Pipeline #7962 (Fix submodule version to the correct one). The hex-files are attached.

 

/Affects:

This problem affects the development of automatic tests because all the test doors are larger than 90 degrees.
    

Available commands:
    help - list all commands / help on specific command
    exit - exit current mode
    sysCtrlGetBuildId - print the hash number that is unique for this build
    reboot - Reboot MCU
    listParams - Print a list of all available parameters and their current value
    eraseParams - Erase all the parameters in storage
    setParamValue - Set a parameter's value
    halMemEraseAll - Erase the whole partition
    listStasts - Print a list of all available statistics and their current value
    eraseStasts - Erase all the statistics in storage
    clearStast - Clear a statistics's value



#ifeq (yes,$(USE_MBS_CONSOLE))

MBS_CONSOLE_REGISTER_CMD();
    
class FreeRTOSTime : public Time //package.

unit test script









settle 判定， 最終決定\安排好。


平等，即是不卑不亢。

保持原有设计的基础上，调整相关参数，例子low energy force, 弹簧弹性系数更改；加大margin;
最主要的还是需求，更改了门宽从1000->762mm

参数更改，相关的都要更改，避免遗漏，全面检查。

Boss Headache. CDC400.

=================== 文件 =================
C:\mbs\SwingDoorPlatform\mbsSdk\components\common\rtos\freeRTOS\Source\tasks.c
C:\mbs\SwingDoorPlatform\mbsSdk\components\common\rtos\freeRTOS\Source\queue.c

C:\mbs\SwingDoorPlatform\mbsSdk\components\halMcu\stdPeriphLib_tp\stm32f10x\Libraries\STM32F10x_StdPeriph_Driver\src\stm32f10x_tim.c
C:\mbs\SwingDoorPlatform\mbsSdk\components\halMcu\init\stm32f10x\src\start_ARMCM3.s
C:\mbs\SwingDoorPlatform\components\halMcu\interrupt\stm32f10x\src\mcuInterrupts.c

C:\mbs\SwingDoorPlatform\modules\output\motorBoard\mbs_st_m64_core_v10\config\inc\outputConfig.hpp  //PROPORIONAL_GAIN， CURRENT_TO_TORQUE_FACTOR

merge access,
advantum access,

=================== 实验 =================
01. Updating CRC32 signature at [0x08046b40]
    Checksum: 0xd9775671

02. Switch_off relay:
    Sw 009, 011, 016, 019, 020, 022.
    Sw 009, 019 更新打印程序。
    
03. Motor current sensor, test by Bob. //////


    
=================== 问题 =================
new version:
    01, reset, not continue cycle test=print reset. Still reset 2days running.
        /switch off relay not energized again after reset.
        console reset sw, to check relay enable status.
    02, /low energy not work on force limit, 
        close force67N.
    03, /ADC drift.
        zero sample,
        change dir check keep current.
        datasheet, sensitity offset, 3.3v >> offset,
        english,
    04, learn open position, no margin.
    05, flash test fail, change motor board. //crc32.
    06. hardware version.
    07. /no spring current 3.9A. 
    08. sprints not fufill.
    09. /Test Share.
            v8_5 全部测试否,(Free Swing, Partial open, Push and Close, )
            v8_5 Summary,
            SPS Matin kan,
Bob: SwingPlatform
    Spring not learned,
    No spring open current,
    Learn open hit door,
    RUO \ SOS not stable,
Wang: UL quasar,
    Close curve halt 200ms, (How, Let me how)
    No spring size2, close force 0, manual open 10 degree. (ADC)
    
    
    /Hardware version,
    
    /basicIO led,
   
    v0,7 power board support.
    //New power board, with current sensor, 
    //Remove zero drift code unit tests.
    
    //Advises_for_code.
    https://projectweb.assaabloyentrance.net/sites/ProductDevelopment/SW-Program/Shared%20Documents/Forms/AllItems.aspx?RootFolder=%2Fsites%2FProductDevelopment%2FSW%2DProgram%2FShared%20Documents%2FSwinger%20platform%2FSW%20Work%20Files&FolderCTID=0x01200076570E726491884CA37B6E6300BD79B3&View=%7BC86F47E9%2D5C2F%2D4633%2D868F%2D32C4346BEC38%7D
     
   PID,
   UL CDF,
   
   MATH,
   
    // BLE app: (softhouse)
    //door-name?
    //active errors?
    
    sha256.h
    bleGateKeeper.c //ble protocol,
    CRC,

    
    
    
    
    //==================================
    2019.10.16 Wednesday
    01. basicIO-LED, 
    02. knowledge-RTOS.
    03. knowledge-manage.
    04. knowledge-english.
    05. project code, doc, 
    06. work report.
    07. cube
    08. mbsSdk/component...
    
    //==================================
    2019.10.11 Friday
    01. team meeting, FCT, 
    02. Factory reset parameter.
    03. 
   
   //==================================
    2019.10.08 Tuesday
    01. code updated,
    02. email check,
    03. plan knowledge, 
    
    power assist limit 50-75-100,
    
    
	
    
    
   //==================================

   //! y(n+1) = y(n)*a + x(n+1)*(1-a)               where, 0 < a < 1
   //! y(n+1) = y(n)/k + x(n+1)*(1-1/k)             where, k = 1/a
   //! y(n+1) = [y(n)-x(n+1)]/k + x(n+1)
   //! y'(n+1) = y(n)-x(n+1) + x'(n+1)              where, y' = y * k
   
   //! y(n+1) = y(n)*[ 1-1/(2^i) ] + x(n+1)*[1/(2^i)]
   //! y'(n+1) = y'(n) – y'(n)/(2^i) + x(n+1)       where, y' = y * (2^i)
   //! y'(n+1) = y'(n) – y'(n)>> i + x(n+1)

   
    //! y(n+1) = y(n)*a + x(n+1)*(1-a), where 0 < a < 1
    //! y(n+1) = y(n)*[ 1-1/(2^i) ] + x(n+1)*[1/(2^i)]
    //! y'(n+1) = y'(n) - y'(n)/(2^i) + x(n+1), where y' = y * (2^i)
    //! y'(n+1) = y'(n) - y'(n)>> i + x(n+1)
   
   
    static uint16_t ui16GetZeroSampleFilterValue( const uint16_t ui16RawValue, volatile uint32_t &ui32ShiftedValue );
   
    static const uint8_t cui8FilterFactor;
    static volatile uint32_t ui32Adc1ZeroDriftFilter;
    static volatile int16_t si16Adc1ZeroDriftAvg;
    static volatile uint32_t ui32Adc2ZeroDriftFilter;
    static volatile int16_t si16Adc2ZeroDriftAvg;


    const uint8_t                             MotorImp::cui8FilterFactor     = 2;
    volatile uint32_t                         MotorImp::ui32Adc1ZeroDriftFilter = 0;
    volatile int16_t                          MotorImp::si16Adc1ZeroDriftAvg  = 0;
    volatile uint32_t                         MotorImp::ui32Adc2ZeroDriftFilter = 0;
    volatile int16_t                          MotorImp::si16Adc2ZeroDriftAvg  = 0;

    //last sample to adjust zero drift.
    const uint16_t cui16Adc1ZeroSample = motorCurrent1Adc->ui16GetRawAdValue();
    const uint16_t cui16Adc2ZeroSample = motorCurrent2Adc->ui16GetRawAdValue();

    si16Adc1ZeroDriftAvg = static_cast<int16_t>( ui16GetZeroSampleFilterValue(cui16Adc1ZeroSample, ui32Adc1ZeroDriftFilter) ) - 2048;
    si16Adc2ZeroDriftAvg = static_cast<int16_t>( ui16GetZeroSampleFilterValue(cui16Adc2ZeroSample, ui32Adc2ZeroDriftFilter) ) - 2048;
   
    uint16_t MotorImp::si16GetZeroDriftFilterValue( const int16_t si16DriftValue, volatile int16_t &si16FilterValue )
    {
        int32_t si32RawValueFilteredShifted  = si16FilterValue;
        si32RawValueFilteredShifted = (si32RawValueFilteredShifted >> cui8FilterShift);
        si16FilterValue -= si32RawValueFilteredShifted;
        si16FilterValue += si16DriftValue;
        return (si16FilterValue>>cui8FilterShift);
    }
   
    
    [?10/?11/?2019 3:57 PM] Hua, Jerry: 
Hello, Michael, I think it's better for me to update the merge request sps-278, according to your comments and my understanding.  After that, we can discuss the left unsolved Discussion. It will be less problem to discuss. Is that a good idea?
[?10/?11/?2019 3:58 PM] Shmulevich, Michael: 
Hi Jerry. Absolutely. 
If you agree with my proposal to "clean up" the interface, there are very few comments that should be discussed afterwards.
[?10/?11/?2019 4:00 PM] Hua, Jerry: 
Which interface? 
LedIndicator[?10/?11/?2019 4:05 PM] Shmulevich, Michael: 
I suggest that we remove all the mesage handling from it, and expose only simpler functions, like 
vSlowFlash() vFastFlash()  vCustomFlash(OnTime, OffTime, numPulses, delayTimeBetweenCycles) 
[?10/?11/?2019 4:13 PM] Hua, Jerry: 
I am not totally agree that suggestion.  As we designed before, the LedIndicator works like an APP, it determines the LED how to flash, not only just SlowFlash FastFlash. It also determines the priority of LED state request, for example, the learn cycle and ERROR exits at the same time, the LED should just response to ERROR state request.
[?10/?11/?2019 4:14 PM] Hua, Jerry: 
Also, the OFF, ON status have been done by OutputSequencer mode.
[?10/?11/?2019 4:15 PM] Shmulevich, Michael: 
I don't follow. Why is the LedIndicator allowed to make such decisions? 
Which App is running it?
Led does not have a separate task, as far as I can tell
[?10/?11/?2019 4:17 PM] Hua, Jerry: 
The systemMonitorApp run the LedIndicator
[?10/?11/?2019 4:17 PM] Shmulevich, Michael: 
Then let the System monitor decide upon that. 
SystemMonitorApp
We are putting bits of logic everywhere, and it gets really hard to get it right
[?10/?11/?2019 4:18 PM] Hua, Jerry: 
Oh, what about add another APP for LED?
[?10/?11/?2019 4:18 PM] Shmulevich, Michael: 
please, no
Then you'd have to add messages for led commands
[?10/?11/?2019 4:20 PM] Shmulevich, Michael: 
system monitor app already has the information about the errors, so it's better that it tells the led indicator what to do, instead of letting the led decide upon its own
[?10/?11/?2019 4:32 PM] Hua, Jerry: 
Yes, I understand your consideration now. And one question is about the flashing priority, for example, some error happens and then run learn cycle, the LED vFlashSlow() by errors then vFlashFast() by learn cycle. After the learn cycle, how the LED to indicate the Error status again without error message? 
[?10/?11/?2019 4:34 PM] Shmulevich, Michael: 
In fact, there is no learn possible when an error happens, I think. But more to the point, the App can keep this information and decide if the new program shoudl be sent or not. It's not that "Slow" shoudl never be aborted by "Fast", but instead what they mean is important.
[?10/?11/?2019 4:35 PM] Shmulevich, Michael: 
And this is why I proposed to remove this logic from ledInidicator. it is not clear why it shoudl be able to decide about it.
[?10/?11/?2019 4:42 PM] Hua, Jerry: 
OK, it's just an example. You know, I just want to know how to dispose the LED status.  So far as my unstanding, the systemMonitorApp has more work to do... Thanks

------

[?10/?15/?2019 2:40 PM] Hua, Jerry: 
Hello, Michael,  I have updated sps-278, please take a look when you have time.
We saved this conversation. You'll see it soon in the Conversations tab in Skype for Business and in the Conversation History folder in Outlook.
[?10/?15/?2019 3:04 PM] Hua, Jerry: 
One more thing is about sps-314 basicIO LED. When I do the setup for sps-314 now, it is same as motorBorad LED. Maybe we can use same ledIndicator class for both boards?
[?10/?15/?2019 3:04 PM] Shmulevich, Michael: 
I think so, if the interface is generic enough.This wasthe whole point.
[?10/?15/?2019 3:06 PM] Shmulevich, Michael: 
I am not sure if you saw it, but i had a talk with Daniel regarding this situation with message sending to itself. And he said this is according to the current design principles. So I removed my objection.
[?10/?15/?2019 3:08 PM] Hua, Jerry: 
Got it. And please give your advices and suggestions, We have better interfaces now.
[?10/?15/?2019 3:08 PM] Shmulevich, Michael: 
Thank you for listening to my advices
[?10/?15/?2019 3:09 PM] Hua, Jerry: 
(y)(y)

    
   
   //==================================
2019.09.27 Friday
    01. simulator can not conneted
    02. low pass filter code check-review,
    03. disk managerment
    
  //==================================
2019.09.23 Monday
    01. PDM training,
        Draft, Pre-Arroved, Approved, Cancelled,
        Documentation > Production, sub-production,
        Change, 
    02. New power board, with current sensor, 
    03. Remove zero drift code unit tests.
 
enum { CURRENT_SENSOR_RANGE_IN_MILLI_A = 25000 };
    /SwingDoorPlatform/modules/output/motorBoard/mbs_st_m64_core_v10/config/inc/outputConfig.hpp

const int16_t si16CurrentSens = static_cast<int16_t>(90); // 90mV/A
const int16_t motorCurrent1AdcScaleFactor = static_cast<int16_t>(12500); // 1650(mV)/32(mV/A)*1000 = 12500mA
    /SwingDoorPlatform/modules/input/motorBoard/mbs_st_m64_core_v10/init/src/input.cpp
    
  //==================================
2019.09.19 Thursday
    01. Test ADC sample in zero voltage GND,
    02. MBS assert,
    03. SOS, 
    
    
    
 //==================================
2019.09.18 Wednesday
    01. project doc, UL.  
    02. PI, 
        LOW SPEED, 
        BACK-CHECK ANGLE, 
        INERTIA, 
        SAMPLE-TIME, 
    
 //==================================
2019.09.12 Thursday
    01. project doc, UL.
    02. project code, !!!
    . For Quasar cT=0,044, rG=245 -> 10,78
    
 //==================================
2019.09.10 Tuesday
    01. project doc, UL.
    02. project code, !!!
        *.c, *.cpp, *.h, *.hpp, *.jenkins, *.jenkinsfile, *.json, *.markdown, *.md, *.mk
        
    03. project test, (relay off, ADC drift).
        relay off 
    04. project stm32, hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
        /topic ppt, 
    08. meeting, daily update, test sharing.
        /sw team meeting.      
    

Teacher: Karen/England


Vocabulary

planning

preparation

reserve hotel

itinerary


Pronunciation

Italy

Greece

Singapore

Malaysia

Kuala Lumpur

interests

interested = in+ter+est+ed

preferences



PAGE: 20 / 23 STEP: 8 / 8



So, what is it assault. 


Self-Defense - a person protects himself/herself from being injured by causing harm to the other person.  


Assault - when a person injuries another person.  


Claimed Innocence - the accused (Josh) is starting that he/she is innocent.  In other words, he/she did not commit the crime that he/she is being accused of. 


Accused will either state that they are guilty or innocent.  

______________________________

He was conviction yesterday and was sentenced …3 years in prison.  


He was convicted yesterday and was sentenced to 3 years in prison.  


Yes, the man hurted right away with blood. 

Yes, the man was badly hurt.  

OR

Yes, the man bleed on his shirt. 

________________________________


Technology


a calculated risk

risk averse - wanting to avoid risk

stability


Do you think that sometimes we must take risks to continue to be stable?


pragmatism - an attitude of acting based on practical evidence and rational thinking


CORRECTIONS

they have a similar knowledge about it...

they have knowledge about...

they are familiar with...



My trip is better in my opinion. We don't have so long holidays.


I don't have as many destinations. My destinations are not too far from each other. So we can have cheaper flights.


Role Play

It's a good idea but do you have a detailed plan? So many flights. According to your plan, I don't think you have enough time to enjoy your trip.

I recommend you to visit 2 or 3 countries in 2 weeks and in one country you can visit one or two beautiful city. It will not be so tired and you can taste some delicious food in Thailand or Malaysia.


Correction: I recommend you visit 2 or 3 countries in 2 weeks and in one country you can visit one or two beautiful cities.


It will not be so tiring...


Revision

modal verbs

eg would - for suggestion

should - for obligation - to say you must


Topic 2

Vocabulary

economy

layover/stop over

direct flight

frequent flyer - membership for people who fly a lot



Questions

Name

Passport

Destination

Departure date

Frequent flyer membership number

Length of trip

How would you like to fly? eg economy or first class

Direct flight

Is it one way or return?


Role Play

Hello, I want to book a ticket to London. I plan a month from today.

I'd like a direct flight.

I prefer economy.

I'm membership of your company. I have frequent flyer miles.


Correction: I am a member of your company's frequent flyer club.

===
        
Communications link media screen includes TV, newspapers and the web.

The great thing about digital media is you can get everything of on off demand.

Click on the link, and you'll see a pop-up window medium font .

It's so cool! You just need to swipe screen blink your eye to turn the page.

The screen font demand media is too small. I can't read the words.

You don't need to type. Just font blink swipe your finger across the screen.

当你将事情与过去对比时，使用下列类似表达强调现在。
	These days, there's just so much information everywhere. 	如今，到处都充斥着大量的信息。
	Nowadays, you can get any information on demand. 	如今，你能够获得任何要求的信息。
	Recently, they've invented technology where you can turn the page by just blinking. 	最近，他们发明了只用眨眼就能翻页的技术。
	Lately, I've been using my e-reader more than paper books. 	最近，相比纸质书，我更多地使用电子阅读器。

使用 in the + 十年代指代过去。如需指明具体是年代的哪个时期，你可以使用 early、late 和 mid-。
	In the '90s, no one was talking about e-books. 	90 年代，根本没人谈论电子书。
	In the early 1930s, families read together by the fire. 	20 世纪 30 年代初，一家人围坐火炉读书。
	In the late '70s, I watched a lot of TV instead of reading. 	70 年代末，我经常看电视，很少看书。
	In the mid-'80s, I had this huge cellphone. It was so heavy! 	80 年代中期，我有一部巨大的手机，非常笨重！
    
    Somewhere along the way, Jules started reading on her smartphone. 	从某个时候开始，Jules 就用智能手机阅读了。
	I recall the pride I felt at having on my shelves all the books I'd read. 	我书架上的书我全都看过了，我现在还记得当时心里的那份骄傲。
	In the past, you couldn't change the font or the brightness of the screen. 	在过去，你不能改变屏幕的字体或亮度。
	When I was growing up, I read constantly. 	在我长大的时候，我经常阅读。

 

        本次活动首先讨论了当前苏州在扫黑除恶活动中所达成的效果，在居民生活娱乐中起到了良好的引导左右，特别提到了小区棋牌室打麻将等民众生活娱乐的改善，做到娱乐身心，而拒绝赌博影响生活。
        接着讨论了当前热门的话题，房价对民众生活的影响。讨论了房子在生活中的重要性，分析了房价对当前民众生活和精神建设的影响。并由此引出当前猪肉价格飞涨的话题，以及对生活的影响。由于猪瘟蔓延，导致猪肉减产，价格飞涨。国家和政府采取了一系列措施，包括生猪养殖和环保政策，以及猪肉供给临时对策。政策起到了一定的作用。
        最后又讨论了苏州建立自贸区的作用及影响，分析了建立自贸区对公司发展的良好作用。

   逗号、冒号和分号
 
在下一活动中，你将看到作者是如何使用逗号、冒号和分号传达重要信息的。
 
逗号 ( , ) 用于 and、but、or 或 so 等连词之前，连接两个主句。
 
The links are part of the electronic text, and I tap on them to go to a networking site. 	这些链接存在于电子文本中，我点击链接，转到一个网站。
I have a tablet, so I swipe the screen to turn pages. 	我有一台平板电脑，因此我刷动屏幕翻页。

你也可以在引导性单词、短语或从句之后使用逗号。
 
Ideally, new technology should make reading even more relaxing. 	理想状况下，新技术应该让阅读更加轻松。
In the late '90s, I read my first electronic book. 	90 年代末，我阅读了我的第一本电子书。
When I was growing up, I read two newspapers a day. 	在我长大的时候，我每天看两份报纸。

使用逗号分隔三个或三个以上连续出现的项目，and 前面不用逗号。
 
I read on my phone, my tablet, my notebook and my desktop computer. 	我在我的手机、平板电脑、笔记本电脑和台式电脑上阅读。
You swipe the screen, tap the word and follow the link. 	你刷动屏幕，点击单词，然后追踪链接。

在主句后面使用冒号 ( : )，引出密切相关的信息，比如一种解释或清单内的物品。
 
An e-reader is important to me for one reason: I can carry lots of books on one small device. 	电子阅读器对我来说重要的原因在于：我能够在一部小小的设备上装许许多多的书。
  	 
Right now, I've got four things to read on my tablet: a crime novel, a graphic novel about monsters, a newspaper and a magazine with healthy recipes. 	目前，我的平板电脑有四种读物：一部犯罪小说、一本描写怪兽的图画小说、一份报纸和一本介绍健康食谱的杂志。

你可以在两个独立的句子之间，或者一个完整句和一个从句之间使用分号 ( ; )，连接两个密切相关的看法。分号可以替代诸如 but 和 and 等连词。有时，使用分号比两个独立的句子更为有效。
 
With paper media, I use my fingers to turn a page; with electronic media, I use my fingers for swiping. 	用纸质媒体阅读时，我用手指翻页；用电子媒体阅读时，我用手指刷动屏幕。
  	 
Paper books are too heavy; e-readers, too light. 	纸质书太重，电子阅读器太轻。

When I was younger, I read books printed on paper. I had read Forth Great Works of classic fiction, and some science fictions. My favorite is science fiction. Somewhere along the way, I've transitioned from paper to electronic media. In the middle of 2010s, I bought a smart phone and start to read e-books on it. Now, I read news on my smart phone. I also do search for new knowledge, new technology, and Japanese anime. It's a huge difference in learning for me. 
I would use my fingers to turn a page. I tap or swipe my screen to go to next page. But I still have not been tried eye blink to turn pages yet. Someday I like to try this method. Sometimes news articles are absorbing, but the content of it is not so useful. We need to filter so many redundant information. In all, however, I like it.


    

 //==================================
2019.09.03 Tuesday
    01. project doc, UL.
    02. project code, !!!
        *.c, *.cpp, *.h, *.hpp, *.jenkins, *.jenkinsfile, *.json, *.markdown, *.md, *.mk
        
    03. project test, (relay off, ADC drift).
        relay off 增加描述， 因为mainVoltage message not received， 电机运动时，导致ADC检测出错，没有发出消息；
        增加延时之后，测试，复位之后继电器使能。指出复位问题是messageRouter.cpp 182 引起的，建立新的sps.
        建立新的SPS，提供监控数据；
    04. project stm32, hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
        /topic ppt, 
    08. meeting, daily update, test sharing.
        /sw team meeting.   
    
//==================================
2019.09.02 Monday
    01. project doc, UL.
    02. project code, !!!
        *.c, *.cpp, *.h, *.hpp, *.jenkins, *.jenkinsfile, *.json, *.markdown, *.md, *.mk
        
    03. project test, (relay off, ADC drift).
    04. project stm32, hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
        /topic ppt, 
    08. meeting, daily update, test sharing.
        /sw team meeting.
    

//==================================
2019.08.29 Thursday
    01. project doc, UL.
    02. project code, 
    03. project test, (mode current).
    04. project hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
        /topic ppt, 
    08. meeting, daily update, test sharing.
        /sw team meeting.
        机械原理， 清华大学；

//==================================
2019.08.27 Tuesday
    01. project doc, UL.
    02. project code, led twinkle, //led indicator, sequencer comments.
            error flashing code,
            SPS-253 Documentation,
            
            lint sps-247 product test,
            adc sample zero drift, measure range scale.
            
    03. project test, (mode current).
    04. project hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
        standard-UL325, UL10C, A156.19, FCC Part 15.
        BHMA, builders harware manufacture association
        ANSI, American national staandards institute.
        
        A156.19-2007
        UL325, electriacal safety,(UL60730)
        UL10C, fire door assembles.
        
A156.19-2007: swinger.
        1-Swinger, A156.10 cover Slider. A156.38-low energy,
        2-Definition - power assist, 
                     - low energy, 
                     - Activation,
                     - Time dealy, auto hold open 5s, push and go 3s. ???
                     - Closing,
                     - Force, kinetic, 手动推开门133N, 最小67N，
         3-cycle tests
         4-low energy power operated doors
         5-cycle tests
        
        
        
        
        
    08. meeting, daily update, test sharing.
    
//==================================
2019.08.26 Monday
    01. project doc, UL.
    02. project code, led twinkle, //led indicator, sequencer comments.
            error flashing code,
            SPS-253 Documentation,
            
            switch_off relay SPS, reset messageRouter.cpp
            lint sps-247 product test,
            adc sample zero drift, measure range scale.
            
            
    03. project test, (mode current).
    04. project hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
    08. meeting, daily update, test sharing.
        Drawing review, 
        work tasks,
        test order,
        NMI, Production test, doc, arch,
        CDC4, 
        OMS-operation mode selection.
        escape route, sign, 24v 2s open 80%. 
            electrical faults not resist normal open.
            two motor, backup h24 open once. 
            off->auto, backup battery+motor, open once.    
    
    
//==================================
2019.08.23 Frid
    01. project doc, UL.
    02. project code, led twinkle, //led indicator, sequencer comments.
            error flashing code,
            SPS-253 Documentation,
            switch_off relay SPS,
            
            Sw 009, 011, 016, 019, 020, 022.
            Sw 009, 019 更新打印程序。
            
    03. project test, (mode current).
    04. project hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
    08. meeting, daily update, test sharing.
        Drawing review, 
        work tasks,
        test order,
        NMI, Production test, doc, arch,
        CDC4, 
        OMS-operation mode selection.
        escape route, sign, 24v 2s open 80%. 
            electrical faults not resist normal open.
            two motor, backup h24 open once. 
            off->auto, backup battery+motor, open once.
            
15:55 sw019 power on.
        
        
    09. behave, slow speak fast thinking, fast action.
    10. other, reimburement, stock, weiChat, lunch.
    

//==================================
2019.08.22 Thursday
    01. project doc, UL.
    02. project code, led twinkle, //led indicator, sequencer comments.
            error flashing code,
            SPS-253 Documentation,
    03. project test, (mode current.
    04. project hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
    08. meeting, daily update, test sharing.
    09. behave, slow speak fast thinking, fast action.
    10. other, reimburement, stock, weiChat, lunch.


//==================================
2019.08.16 Friday
    01. project doc, UL.
    02. project code, led twinkle, //led indicator, sequencer comments.
            SPS-224 Lean hold open time too longer,
            SPS-253 Documentation,
    03. project test, (mode current.
    04. project hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
    08. meeting, daily update, test sharing.
    09. behave, slow speak fast thinking, fast action.
    10. other, reimburement, stock, weiChat, lunch.
    

    
//==================================
2019.08.14 Wednesday
    01. project doc, UL.
    02. project code, led twinkle, //led indicator, sequencer comments.
    03. project test, (mode change from open to auto, door pause short time.)
                      (closed, current not same.)
                      (reveal same, update sw changed arm table, door open angle change only 0.2 degree.)
                      (latch check close time not > 1.5s.)  给客户可选项，设定-结果公差；
                      (start force overrange, ) UL325<133N (LOW ENERGY), UL156.19 <67N.
    04. project hw, SCH.
    05. project charge, code read.
    06. learning, English, Janpanse.
    07. learning, training, managerment development.
    08. meeting, daily update, test sharing.
    09. behave, slow speak fast thinking, fast action.
    10. other, reimburement, stock, weiChat, lunch.

//==================================
2019.08.14 Wednesday
    01. //UL doc,
    02. //led indicator, sequencer comments,
    03. Code-LearnMode.cpp,
    04. Hardware sch,
    05. //Disk clean,
    06. English,
    07. Excecise, health, human, 
    08. Slow.
    09. Test team commu-bug list.
    10. review 130mm， arm table.
    11. ---meeting with Sweden, after holiday.
    
    building information modeling (BIM) 

//==================================
2019.08.13 Tuesday
    01. UL doc,
    02. led indicator, sequencer comments,
    03. Code-LearnMode.cpp,
    04. Hardware sch,
    05. //Disk clean,
    06. English,
    07. Excecise, health, human, 
    08. Slow.
    09. Test team commu-bug list.
    10. review 130mm， arm table.
    11. ---meeting with Sweden, after holiday.
    
    building information modeling (BIM) 
    
    
{ Hellsson, Daniel <Daniel.Hellsson@assaabloy.com>
    I’m not sure how used all of you are to reporting time in JIRA. If you are, then skip to the end. If not, then I’ll tell you.

For each JIRA issue you have been working on:
1.	Open it up in JIRA
2.	Click “More->Log work”
3.	Write in “time spent” (make sure to enter days, not hours: “1d”)
4.	Make sure “Date Started” points to the day when you did the work (if you report in the mornings, this will usually be yesterday).
5.	Make sure that “Remaining Estimate” is adjusted accordingly. If you made progress, allow it to adjust automatically, if you feel that you now have a different opinion on how long it will take, choose “set to” or “reduce by”
6.	Add a short description of what you did. You don’t have to, but I encourage you to, since this will make up a sort of “developer diary” that you (and others) can look back on to see how development progressed.

It is important that you ask yourself if the estimate is good, each time you update it. If you keep saying “one more day” then you’re failing in the estimation. If you estimate 1 more day of development, ask yourself: “Will I really be done today? Is that realistic?” If not, then add another day, or two, if that feels more realistic.

If you work half days, add “0.5d”, but please do not register 1 hour or 2 hours. That is way to detailed and will not help us in the end. Half-day is the smallest unit of measure you can put into an issue and 1 day is the shortest time anything can be delivered to the system, so never estimate a task to take less than 1 day.

}
    
//==================================
2019.08.12 Monday
    01. UL doc,
    02. led indicator, sequencer comments,
    03. Code-LearnMode.cpp,
    04. Hardware sch,
    05. //Disk clean,
    06. English,
    07. Excecise, health, human, 
    08. Slow.
    09. Test team commu-bug list.
    10. review 130mm， arm table.
    11. ---meeting with Sweden, after holiday.
    
//==================================
2019.08.09 Friday
    01. UL doc,
    02. led indicator, sequencer comments,
    03. Code-LearnMode.cpp,
    04. Hardware sch,
    05. //Disk clean,
    06. English,
    07. Excecise, health, human, 
    08. Slow.
    09. Test team commu-bug list.
    10. review 130mm， arm table.
    11. ---meeting with Sweden, after holiday.
    
    training： 晶振，模数，高频，敷地；
    射频电源，星形拓扑；



//==================================
2019.08.07 Wednesday
    01. UL doc,
    02. led indicator, sequencer comments,
    03. Code-LearnMode.cpp,
    04. Hardware sch,
    05. //Disk clean,
    06. English,
    07. Excecise, health, human, 
    08. Slow.
    09. Test team commu-bug list.
    10. review 130mm， arm table.
    11. ---meeting with Sweden, after holiday.
    

//==================================
2019.08.06 Tuesday
    01. UL doc,
    02. led indicator,
    03. Code-structure, interface-backend, namespace,
    04. Hardware sch,
    05. //Disk clean,
    06. English,
    07. Excecise, health, human, 
    08. Slow.
    09. Test team commu-bug list.
    10. review 130mm， arm table.
    11. ---meeting with Sweden, after holiday.
    
    statistics, CM,
    logs, revolver solution,
    

//==================================
2019.08.05 Monday
    01. UL doc,
    02. Sequencer,
    03. Code-structure, interface-backend, namespace,
    04. Hardware sch,
    05. //Disk clean,
    06. English,
    07. Excecise, health, human, 
    08. Slow.
    09. Test team commu-bug list.
    10. review 130mm， arm table.
    11. ---meeting with Sweden, after holiday.
    
        const enum //cycle counter-section
		{
        	ALWAYS_FLSHING = -1,
        	STOP_FLASHING = 0
		};

//==================================
2019.08.02 Friday
    01. UL doc,
    02. Sequencer,
    03. Code-structure, interface-backend, namespace,
    04. Hardware sch,
    05. //Disk clean,
    06. English,
    07. Excecise, health, human, 
    08. Slow.
    09. Test team commu-bug list.
    10. review 130mm， arm table.
    
    UL5085-1, transform,
    thickness,
    
    
    three-phase,
    
    
        si16FlashingPulseTimes      ( 1 ),
        si16FlashingCycleTimes      ( 1 )


//==================================
2019.08.01 Thursday
    01. UL doc,
    02. Sequencer,
    03. Code-structure, interface-backend, namespace,
    04. Hardware sch,
    05. //Disk clean,
    06. English,
    07. Excecise, health, human, 
    08. Slow.
    09. Test team commu-bug list.
    
    147

//==================================
2019.07.30 Tuesday
    00. lock kick, merge request,
    01. led indicator
    02. UL doc,
    03. english,
    04. doctor search.
    
    C:/mbs/SwingDoorPlatform/html/hhc.exe
    

//==================================
2019.07.29 Monday
    01. led indicator
    02. UL doc,
    03. english,
    04. 
  
    
        [SENQUENCER_TIMEOUT] =
        {
            /* ui8NrOfSubscribers */ 1U,
            /* ui8Subscribers     */ { static_cast<uint8_t>( SYSTEM_MONITOR ), 255U, 255U }
        },

        [LED_INDICATOR_MODE] =
        {
            /* ui8NrOfSubscribers */ 1U,
            /* ui8Subscribers     */ { static_cast<uint8_t>( OUTPUT_SEQUENCER ), 255U, 255U }
        }
  
        
        //! Implementation of the corresponding interface function
        void vUpdate() volatile; //Give a update interface, can be updated in other module, not output module self.

        void LedIndicatorImp::vDispatch( const uint8_t ui8MessageId ) volatile
        {
            switch ( ui8MessageId )
            {
                case messages::SENQUENCER_TIMEOUT:
                    outputSequencerBackend->vTimeoutEvent( input::OUTPUT_SEQUENCER_TIMEOUT_TIMER_ID );
                    break;

                case messages::LED_INDICATOR_MODE:
                    DispatchLedIndicatorMode();
                    break;

                default:
                    //! Do nothing
                    break;
            }
        }    

//==================================
2019.07.25 Thursday
    01. led,
    02. UL 60730,
    03. Searching.
    04. English.
    
    	"MOTION_CONTROL_EVENT_TIMEOUT": {
		"event": {
			"type": "uint8_t",
			"description": "The event that timed out."
		}
	},


//==================================
2019.07.23 Tuesday
    01. Automatic electrical controls for household
    //02. makefile gcc,
    03. 程序，outputSequencer 应用层： LED class, recv cmd, ctrl output;
    04. 快速阅读UL文件；

//==================================
2019.07.23 Tuesday
    01. //USB-HUB 采购；
    02. //流量卡对比；
    03. makefile gcc使用；
    04. 程序；
    05. //辛福培训时间安排；
    06. outputSequencer 应用层： LED class, recv cmd, ctrl output;
    07. english: single,


//==================================
2019.07.22 Monday
    01. LED flash, //C:\mbs\SwingDoorPlatform\mbsSdk\components\system\sequencer\inc\outputSequencer.h
    02. makefile function,
    03. english,
    //04. merge request,
    
    
//==================================
2019.07.19 Friday
    01. Team meeting.
    02. discuss 电流环输入和反馈的比较，同样速度环输入和反馈对比；
        fictive resistance 电机运行了，但是没有检测到运行；
    03. link script,
    04. gcc manual,
    05. build.mk, abs.mk.

//==================================
2019.07.17
    01. //develop branch run again,   //access priority.
    02. reimbursement,
    03. EF,                         
    04. //UL doc,
    05. PCB simu PLC,
    06. //jer_dev_arch  new merge request to develop_free.

//==================================
2019.07.16 Tuesday


05. English:
You are applying for a position as a manager at a major company. 
Imagine you have extensive business qualifications and experience, 
and write your cover letter.

Read the example cover letter. Type in the input box. Write 45-65 words. 
Use your own words where possible.

Dear Ms. Rivers:

I am writing to apply for the manager position at IBX. I believe my extensive experience and solid education make me a strong candidate.

I graduated in electrical automation from Jangsu University with a master degree at 2011 year. Subsequently, I received a job in Nanjing. I worked in Nanjing about 4 years. Subsequently, I was invited to Changzhou by older class mate in Jangsu University. One years later, I was promoted to software director. I have extensive experience in software development. I am working at ASSA as an software engineer.

Details about my education and experience are in the attached resume. Thank you for considering my application. I hope to hear from you soon.

Sincerely,

//==================================
2019.07.15 Monday
01. Code, 
02. UL doc,
03. English,
04. gitlab runner,


//==================================
2019.07.12 Friday
01. team buildig discuss;
02. flowChart
03. /SwingDoorPlatform/components/common/selfTest/STM3210C_EVAL/EWARM/stm32f10x_STLcpurunIARv5.s
    /components/application/swingDoorGeneric/systemMonitorApp/motorBoard/inc/runtimeTestList.hpp
    /: RuntimeTest("ProgramFlowReceive", PROGRAM_FLOW_RECEIVE_TEST)
    
//==================================
2019.07.11 Thursday
00. i2tMonitor:().
01. encoderMonitor:().
02. System test:().
03. Runtime test:().


//==================================
2019.07.10-Wednesday.
01. ProgramSelector: (io param intf(impules),to private object(maybe not defined), &message, mode).
02. DoorControlApp: (#define INT16_MAX (__INT16_MAX__) stdint.h, 
    dispatch:   motion_control_status, timer_enent, impulse timeout,
                door_angle_repetion, impulse, learn button, 
                learn_error, ble_status_updated. ).
03. ActiveImpulse: (message=>door_command, 使信号活化。).
04. priorityList: (in doorCommand.hpp, DoorCommandPriorityListImp=>static apDoorCommandList[], constructor).
       
//==================================
2019.07.05-Friday.
01. 小组会议， 活动主题欢迎Cason.
02. Denbin实习结束，软件招聘实习生；
03. linux介绍：是什么，历史，对比window，能做什么，命令，编程...
       
//==================================
2019.07.04-Thursday.
01. read files: yml, jenkins, gitlab error,.
02. lockMonitor.
03. ul doc.
04. email, calendar.
       
//==================================
2019.07.01-code.
    01. path
    strIniFileFullName = Application.StartupPath + "BleList.ini"; // "\\BleList.ini"; //delimmer.
    strStartupPath = "C:\\Users\\jerhua\\_huamg_assa_\\02-proj\\02.003-wks\\__CODE_REPO__\\PTU\\SendAndReceive\\SendAndReceive\\bin\\Debug"
    strUserDataPath = "C:\\Users\\jerhua\\AppData\\Roaming\\BLE_PC_APP\\BLE_PC_APP\\1.0.0.0"   
    strCommAppDataPath = "C:\\ProgramData\\BLE_PC_APP\\BLE_PC_APP\\1.0.0.0"
    strIniFileFullName = "C:\\Users\\jerhua\\_huamg_assa_\\02-proj\\02.003-wks\\__CODE_REPO__\\PTU\\SendAndReceive\\SendAndReceive\\bin\\DebugBleList.ini"
    strIniFileHeadName = "DebugBleList"
    
//==================================	
2019.06.26 Wednesday
    01. architecture,
    02. lockVoltageMonitor,
    03. 报销；
    04. pipe_suzhou: 
        ==在linux安装git, gitlab-runner; （Debian: su, apt-get update, upgrade, install git.）(arch li: pacman -S git.)
        ==build? 在linux里build， 完成之后，怎么==load？
        ==st-link驱动，需要在linux里安装吗？
 
//==================================	
2019.06.19 Wednesday
    01. issue,    
We need to check how the expected behavior should be during learn. What kind of stop are we expecting? 
Willies to double check with team in China: https://aaes-jira.assaabloy.net/browse/SPS-174
Fix min 1,5s opening time: https://aaes-jira.assaabloy.net/browse/SPS-175
Implement limitation on opening time depending on size: https://aaes-jira.assaabloy.net/browse/SPS-176
Tuning needed for power assist! https://aaes-jira.assaabloy.net/browse/SPS-177
Stop on stall doesn't work: https://aaes-jira.assaabloy.net/browse/SPS-178
Lock voltage setting doesn't work: https://aaes-jira.assaabloy.net/browse/SPS-179
2 degree mechanical flex causes issues for software determining positions: https://aaes-jira.assaabloy.net/browse/SPS-180
    
    02. code bug, read, ble console, lint file, make,
    03. mbs, baremental,
    04. BLE PC TOOL,
   

    
//==================================	
2019.06.18 Tuesday
    01. Show power assist function to Jeppa, tuning.
    02. Fast push, brake at stopper not well,
    03. Door interia, unit he
    04. New issue,
    
    csi32DeltaShaftAngle 2523083,
    si32BrakeSpeedInMilliRadPerSecond 11377,
    
    
//==================================	
2019.06.17 Monday
    01. Talking in english about weekend,
    02. Gitlab thing; new version test;
    03. Code issue ongoning;
    04. Disk clean, virtual box;

//==================================	
2019.06.14 Friday
    01. 瑞典问候，有道翻译；耳机连接；
    02. git difftool config; (difftool messages)
    03. issues; 不急，处理，回前，处理下个；
    04. branch scope, one branch for one issues; each other br;
    05. UL, safeRTOS order(docu, code), system test, time schedule;
    06. SafeRTOS issue commu; price;

//==================================	
2019.06.13
    01. TickType_t: typedef uint32_t TickType_t;
    /SwingDoorPlatform/mbsSdk/components/common/rtos/freeRTOS/Source/portable/GCC/ARM_CM3/portmacro.h
        typedef __uint32_t uint32_t ;
        typedef __UINT32_TYPE__ __uint32_t;
        #define __UINT32_TYPE__ unsigned int
    c:/mbs/programs/cygwin/usr/include/sys/_stdint.h
        
    02. typedef portTickType TickType;
    /SwingDoorPlatform/mbsSdk/components/common/rtos/safeRTOS/taskControl/inc/taskControl.h
        typedef unsigned long			portTickType;
    /SwingDoorPlatform/mbsSdk/components/common/rtos/safeRTOS/Source/portable/003_GCC/033_ARM_CM4/portmacro.h

        
The powerAssist function is not entirely correct. It should work so that, in principle, 
when power assist is 100% all spring torque should be cancelled, maybe with //addition 
of some Nm to counter mechanical resistance in the gearbox. When power assist is 0% no 
helping torque should be added, and in between the value should be calculated as the 
given percentage of power assist.

//Then when there is spring:
So if we find that a constant offset is needed, then max power assist is Ts + Tc, with 
/*Ts*/ being the spring torque and /*Tc*/ is the constant offset, and normal power assist is (Ts+Tc)*p/100
with p being the wanted percentage of power assist.
/*
    power assist is Tp = (Ts + Tc)* p%;
    torque limit equals to Tp;
*/

Then when there is no spring, the motor needs to apply torque in the closing direction 
to keep the door closed. This torque is Tclose. If then an offset is needed as described 
above, to counter mechanical resistance in the motor, Tc, then max power assist is Tc, 
Tc zero power assist is Tclose and power assist in between is Tclose + (Tc-TClose)*p/100
/*
    power assist is Tp = Tc * p%;
    torque limit is (Tclose + Tp);
*/        
    
//==================================	
2019.06.12
    01. reset: 
$ ./export-gcc-cmd-motor.sh 0x801FF31
C:\mbs\SwingDoorPlatform/components/application/aaesGeneric/canComm/src/canComm.cpp:255
    
//==================================	
2019.06.11
    01. crash
    02. safeRTOS 2 branches,
    03. sps-158,
    04. pipeline,
    05. unit tests,
    06. learn command doc
    
//==================================	
2019.06.10
    01. crash
    02. safeRTOS 2 branches,
    03. sps-158, 
    
//==================================	
2019.06.3  
    01. action-plan,
    02. code change,
        products/quasar/conf/FreeRTOSConfig.h
        products/quasarMotor/conf/FreeRTOSConfig.h
    04. arch diagram.
    05. UL standard.

//==================================	
2019.05.31
    01. 四连杆，向量法；角度之间的关系；
    02. 求导微分，角速度，加速度；
    03. PUSH, 导轨机构门上， 滑块机构门上；
    04. 运动学分析，受力分析；static  analysis
    05. 惯性力P = -ma; M = - J * a; 转动点，质心； 矩阵法；
    EN1154;
    K S B C A O F .  
    K, S rise, shaft angle fall;
    B fall, angle fall;
    SolidWorks; 四连杆实际测试；
        
    06. 公式应用，认证，   机械，软件；
    
//==================================	
2019.05.30
    01. However, when you erase all parameters, you have to restart the system for the new value to take effect
        PRAMETER_UPDATED-messages completely filling the ISOTP-queue 
    02. components/application/swingDoorGeneric/errorHandler/motorBoard/inc/profiler.hpp
    05. not tested setting parameters or erasing them via the BLE-interface
    06. branch called “dh_dev_profiling” , error-handler ticks

//==================================	
2019.05.29 Wednesday.
    01. Android, do do do.
    02. PLC,
    03. platform code, new added, rtos, mbs, debug reset,
    04. diagram designer,
    05. change gitlat server.

//==================================	
2019.03.22 Friday.
01. topic: IHS-Infomation handling system. info-scheme-decesion.
	BOM-Bill of Material, 
	EMS-Environmental Management System. IMI. 
	PDS, ProDirectSoccer代购中文站点
	PCN-Process Change Notice,.

//==================================	
2019.03.19 Tuesday.
01. static 
02. meeting points: 
	1-back-check-angle, 2-ble, 3-American, 4-UL docum(how much), 5-safeRTOS, 
	6-jira-SPS126, SPS127, SPS128, 7-merge param branch, 8-everyone has work.
	who: jeppa, dh, matin.

	
//==================================	
2019.03.08 Friday.
01. 制版，重复多次 有意见，问题请示；
02. 贴标，注意形象；
03. 电池，携带美国；
04. DSS200 发布release，不等测试完成； CP, CM,
05. 电池测试，前后端原理，接口，优缺点；


宁德时代
比亚迪，补贴退坡，
亿纬锂能

它是由BJT（双极型三极管）和MOS（绝缘栅型场效应管）组成的复合全控型电压驱动式功率半导体器件，它拥有的特性是：高输入阻抗，可采用通用低成本的驱动线路；高速开关特性；导通状态低损耗。IGBT兼有MOSFET的高输入阻抗和GTR的低导通压降两方面的优点。GTR饱和压降低，载流密度大，但驱动电流较大；MOSFET驱动功率很小，开关速度快，但导通压降大，载流密度小。IGBT综合了以上两种器件的优点：驱动功率小而饱和压降低，是一种适合于中、大功率应用的电力电子器件。IGBT在综合性能方面占有明显优势，非常适合应用于直流电压为600V及以上的变流系统如交流电机、变频器、开关电源、照明电路、牵引传动等领域。
	
==================================	
2019.03.04 - 09 WK10.
01. topic,
02. name list,
03. code,
04. 

        int32_t siPos1 = encoder->si32GetShaftPosition();
        int32_t siPos2 = armSystem->si32GetDoorAngleInMicroRad();
        #ifdef  _DEBUG_PORT_
        dbgPort << siPos1 << "  "
                << siPos2 << "\n";
        #endif
			

//==================================	
2019.03.08 Friday.
01. 制版，重复多次 有意见，问题请示；
02. 贴标，注意形象；
03. 电池，携带美国；
04. DSS200 发布release，不等测试完成； CP, CM,
05. 电池测试，前后端原理，接口，优缺点；

//==================================	
2019.03.06 Wednesday.
	
encoder: const uint32_t ui16Temp = static_cast<uint16_t>(si16ShaftSpeed);


    ////////////////////////////////////////////////////////////////////////////////////////////
    // Enums and defines needed by the lockDriver
    ////////////////////////////////////////////////////////////////////////////////////////////
    //! Lock driver enable unlock deci-door angle range
    enum { LOCK_DRIVER_UNLOCK_DECI_DOOR_ANGLE = 8730};

	
==================================	
2019.02.11 - 16 WK07.
01. Platform code, issuse fix, transform to sdk4.4.0, springImp.
02. sw300 code,
03. foc control.
04. english.
05. chess.	

备注：	
北线：	
A.公司大门口	
B.锦丰广场	
C.东环大润发（南门口）	
D.杨枝塘城区高速入口	
	
南线：	
E.公司大门口	
F.钟南街地铁站3号出入口	
G.湖东邻里中心公交车站	
H.杨枝塘城区高速入口	
	



//==================================	
2019.03.04 Monday.
01. UNIT-TEST

//==================================	
2019.03.01 Friday.
01. UNIT-TEST

//-01-// enum
enum { MAX_LEARN_CYCLE_TIME = 120000 }; /* ms */

//-02-// help variables  //类似全局变量，不用函数传参，方便。
int32_t si32DoorAngle = 0;

//-03-// FSM goto function.
motionControl::MotionCommand* pGotoSettleDoorStopPhase();

//-04-// Config Test helper function.
void vConfigNormalLearnResults ( 0 /*pv1*/, 1 /*pv2*/, 2 /*pv3*/ );

//-05-// Function Test helper function.
void vTestReleaseTension(motionControl::MotionCommand* testLearnCommad);

//-06-// Function Expect helper function.
void vExpectReleaseTension(motionControl::MotionCommand* testLearnCommad);

//-07-// "Repeat" expect helper function. //重复的代码，封装为函数；同类多数据，传入为参数。
void vSubExpectGetDoorAngle ( int32_t* psi32DoorAngle ); //subroutine

//-08-// TEST.
TEST( LearnCommand, RestartLearnCommand)

	pui8EncoderInfo[0U]		= static_cast<uint8_t>(ui32Temp /16777216U);		// right shift 24 bits
	pui8EncoderInfo[1U] 	= static_cast<uint8_t>(ui32Temp /65536U);			// right shift 16 bits
	pui8EncoderInfo[2U] 	= static_cast<uint8_t>(ui32Temp /256U);				// right shift 8  bits
	pui8EncoderInfo[3U] 	= static_cast<uint8_t>(ui32Temp);					// right shift 0  bits
	

//==================================	
2019.02.28 Thursday.
01. Learn command,
02. 1009203-slider.


I have reviewed the code, and had some “comments”. 

I really like the “vUpdate” function, since it is easy to follow. 
The “vTimeOutEvent” function could be refactored in a similar fasion. 
Other than that I had some suggestions on simplifications in the “FSM”. 

The “unit-tests” are also very well designed, with helper functions that drives the FSM to each state that you need to test. 
This should make them easy to update and maintain. Well done!

    int32_t si32DoorAngle = 0;
    int16_t si16SampleSpeed = 0;
    int16_t si16DeltaSpeed = 0;
    int16_t si16ExpectedSpeed = 0;
    uint32_t ui32TimeInterval = 0;
	
	// vl=60mrad/s, vh=600mrad/s, ar=300mrad/ss, ad=-300mrad/ss.
    // tr=(600-60)/300=1.8s, Pr=(600-60)*1.8/2=486mrad=(486/3141.6)*180=55.7degree.

	

//==================================	
2019.02.22 Friday.
01. Learn command,
02. 1009203-slider.



配置下Java环境

1. //vim .bash_profile 
	添加：  
2.  //export JAVA_HOME="/Library/Internet Plug-Ins/JavaAppletPlugin.plugin/Contents/Home"
	//export PATH=${JAVA_HOME}/bin:$PATH
	通过:wq，保存并关闭vim
3.  source .bash_profile

C:\Users\jerhua\.bash_profile

GCC_PATH=/C/mbs/mbsToolchains/gcc-arm-none-eabi-4_9-2015q3/bin
MBS_BIN=/C/mbs/programs/bin
MAKE_PATH=/C/mbs/programs/cygwin/bin
export PATH=$PATH:$GCC_PATH:$MBS_BIN:$MAKE_PATH

勒克斯lux，法定符号lx)是照度(Illuminance)的单位。被光均匀照射的物体，在1平方米面积上所得的光通量是1流明时，它的照度是1勒克斯。适宜于阅读和缝纫等的照度约为500勒克斯。

流明，光通量的单位。

发光强度为1坎德拉(cd)的点光源，在单位立体角（1球面度）内发出的光通量为“1流明”，英文缩写(lm)。

勒克斯是引出单位，由流明(lm)引出。流明则由标准单位坎德拉(cd)引出

坎德拉，曾一度称为新烛光
发光强度简称光强，国际单位是（坎德拉）简写cd.

光通量（luminous flux）指人眼所能感觉到的辐射功率，它等于单位时间内某一波段的辐射能量和该波段的相对视见率的乘积。

Segmentation fault 这个提示还是比较常见的，这个提示就是段错误，这是翻译还是十分恰当的。

Core Dump 有的时候给我们呈现的翻译很有趣是”吐核“，但是实际上比较贴切的翻译是核心转储（是操作系统在进程收到某些信号而终止运行时，将此时进程地址空间的内容以及有关进程状态的其他信息写出的一个磁盘文件。这种信息往往用于调试），这个“吐核”的产生和王安博士有着一些关联，其实“吐核”这个词形容的很恰当，就是核心内存吐出来。

出现这种错误可能的原因（其实就是访问了内存中不应该访问的东西）：

　　1，内存访问越界：

　　　　（1） 数组访问越界，因为下标出超出了范围。

  　　　  （2） 搜索字符串的时候，通过字符串的结尾符号来判断结束，但是实际上没有这个结束符。

                （3）使用strcpy, strcat, sprintf, strcmp,strcasecmp等字符串操作函数，超出了字符中定义的可以存储的最大范围。使用strncpy, strlcpy, strncat, strlcat, snprintf, strncmp, strncasecmp等函数防止读写越界。

　　2，多线程程序使用了线程不安全的函数。

　　3，多线程读写的数据未加锁保护。

　　　　对于会被多个线程同时访问的全局数据，应该注意加锁保护，否则很容易造成核心转储

　　4，非法指针

  　　　　（1）使用NULL指针

 　　　　 （2）随意使用指针类型强制转换，因为在这种强制转换其实是很不安全的，因为在你不确认这个类型就应该是你转化的类型的时候，这样很容易出错，因为就会按照你强制转换的类型进行访问，这样就有可能访问到不应该访问的内存。

 　　5，堆栈溢出

　　　　不要使用大的局部变量（因为局部变量都分配在栈上），这样容易造成堆栈溢出，破坏系统的栈和堆结构，导致出现莫名其妙的错误。  
		
		
		
		
		
长线游：
1.长滩5晚6日游
时间：3月14日～3月19日(3月13日晚上19：30左右从公司出发)
价格：鉴于酒店房间数量有限，按最终出游人数确定入住酒店：
4180元/人（住FAIRWAYS或同级）或3980元/人（住SAVOY或同级）

短线游：
三清山婺源三日游
时间：3月15日～3月17日
价格：1492元

 
菲律宾团队旅游签证所需材料： 
1. 护照原件（有效期从回国之日算至少六个月以上）；
2. 签证申请表2份，并附上二张2寸白底彩色近6个月免冠证件照
3. 身份证正反面复印件
4. 十八周岁以下儿童需提供 出身证明复印件，并必须与父母其中一方出行，否则无法办理



//==================================	
2019.02.21 Thursday.
01. Learn command,
02. cell   -> format,  protect -> hide
	review -> protect,

//==================================	
2019.02.19 Tuesday.
01. Learn command,
02. English,
03. Birthday.

    uint32_t ui32AccelerateTimes = (motionControlInternal::LEARN_MAX_SPEED - motionControlInternal::LEARN_LOW_SPEED);
    ui32AccelerateTimes *= 1000;
    ui32AccelerateTimes /= motionControlInternal::LEARN_OPEN_ACC_INTERVAL;
   for (uint16_t i=0; i<ui32AccelerateTimes; i++)
   {
       int32_t si32CalculatedSpeed = (motionControlInternal::LEARN_OPEN_ACC_INTERVAL)*(motionControlInternal::LEARN_OPEN_ACCELERATION);
       si32CalculatedSpeed *= i;
       si32CalculatedSpeed /= 1000;
       si32CalculatedSpeed += motionControlInternal::LEARN_LOW_SPEED;
       int16_t si16ExpectedSpeed = static_cast<int16_t>( si32CalculatedSpeed );
       vExpectOpenPhaseOneBeforeBP4 ( &si32DoorAngle, &si16ExpectedSpeed );
       learnCommand->vUpdate(si16SampleSpeed);
   }

//==================================	
2019.02.18 Monday
01. Learn command,
02. English, meeting,
03. Matrix,

git remote show origin
git remote prune origin
git fetch -p


//==================================	
2019.02.14 Thursday
01. 真实说话，学会表达，对猪闭嘴；
02. 掌握财务，争取优秀，心中有湖。
03. 转换系统，工作投入。。。

@rem The arguments for this batch file: 
@rem %1: The path to the project folder
@rem %2: The path to the CodeWarrior installation folder

@rem ------------------------------------------------------
@rem Path to my project folder
SET PROJ_PATH=%1
@rem Path to CodeWarrior installation folder (which is e.g. "C:\Freescale\CW MCU v10.2\eclipse\..\MCU")
SET CW_PATH=%2

@rem Path to lint-nt.exe
SET LINT_EXE=C:\lint\lint-nt.exe

@rem Path to my lint configuration files
SET LOCAL_LNT_FILES=C:\Freescale\PC-lint\fsl_lnt

@rem Path to my local lint folder inside the project
SET PROJ_LINT_PATH=%PROJ_PATH%\lint

@rem Lint configuration files and includes
SET LNT_INCLUDES=-i"%LOCAL_LNT_FILES%" "%LOCAL_LNT_FILES%\co-mwhc08.lnt" -i%LOCAL_LNT_FILES%

@rem --------------- Run PC-lint ---------------------------
%LINT_EXE% %LNT_INCLUDES% %PROJ_LINT_PATH%\proj_options.lnt %PROJ_LINT_PATH%\proj_files.lnt -vf


//==================================	
2019.02.13 Wednesday
01. 请假2小时，感冒咳嗽睡。
02. lint compile.

make -f co-gcc.mak GCC_BIN='name of the gcc binary' GXX_BIN='name of the g++ binary' \
 CFLAGS='[usual C compile switches here]' \
 CXXFLAGS='[usual C++ compile switches here]' \
 CPPFLAGS='[usual common preprocessor switches here]' \
 COMMON_FLAGS='[usual C & C++ compile switches here]'
	
//==================================	
2019.02.12 Tuesday
请假，老妈生日。
	
//==================================	
2019.02.11 Monday
01. Backup branches.
02. Calander.
03. Eclipse.
04. Stock.

  EMC_test_v3_2A         6ff77b9b [origin/EMC_test_v3: ahead 3] emc test 4A.
  EMC_test_v3_2ms        32e321e0 [origin/EMC_test_v3] change sample time to 2ms.
  SPS_103                055ab6f3 [origin/SPS_103] updated by review discuss.
  SPS_48                 180788e9 [origin/wls_dev_doorCtl: behind 8] Updated some documentation and misspellings
  debugPort_cherry_pick  cc45af36 Lint debug port for "cherry-pick".
  develop                12c3b401 [origin/develop: behind 23] Merge branch 'jgr_sdk4.4.0' into 'develop'
  jer_dev_dbgPort        bd250336 change some comments.
  jer_dev_doorAngle      bd250336 [origin/jer_dev_doorAngle] change some comments.
  jer_dev_doorCtlApp     5e66d144 [origin/jer_dev_doorCtlApp] partly finish door control app unit test.
  jer_dev_freeSwCmd      5d3c9ae9 [origin/jer_dev_freeSwCmd: behind 2] Revert the time delay to 200, rename two test cases
  jer_dev_slowOpnCmd     24393893 [origin/jer_dev_slowOpnCmd: behind 5] Merge branch 'jer_dev_slowOpnCmd' of aaes.githost.io:AAESSwingDoor/SwingDoorPlatform into jer_dev_slowOpnCmd
  jer_dev_spring         d950e391 [origin/jer_dev_spring] Merge branch 'jer_dev_spring' of aaes.githost.io:AAESSwingDoor/SwingDoorPlatform into jer_dev_spring
  jer_dev_swgSdk4.4.0    984470a0 [origin/jer_dev_swgSdk4.4.0: behind 5] Merge remote-tracking branch 'origin/develop' into jer_dev_swgSdk4.4.0
  jerry_dev_doorLogic    13fb4d4a [origin/jerry_dev_doorLogic: ahead 1] revise.
  jerry_dev_doorLogicApp 2133a04f doorLogicApp disign.
  jerry_dev_torqueLimit  d6f20307 [origin/jerry_dev_torqueLimit] Merge branch 'origin/develop' into jerry_dev_torqueLimit
  jerry_ms1_110          79c249f7 [origin/jerry_ms1_CCL: gone] open to 110 degree.
  jerry_ms1_CCL+SPM      29e6512a [origin/jerry_ms1_CCL: gone] CCL encoder reverse.
  jerry_ms1_print        06a58adc [origin/develop_ms1_demo: ahead 14] debug port commit for cherry-pick.
  jerry_v1_prototype     5b86a6f7 [origin/jerry_dev_v1_prototype: gone] add up door open angle.
  jerry_v2_prototype     dbfc2a3c [origin/jerry_dev_v2_prototype: gone] motor current limit to 2500mA, add version id.
  jerry_v3_prototype     0f335eb3 [origin/jerry_ms1_CCL: gone] print moter sample current, not set current.
  jgr_sdk4.4.0           d242463f [origin/jgr_sdk4.4.0] change decription in readme.md
  mg_noise_v3_5s         20ca7604 [origin/develop: ahead 2, behind 38] debug port for cherry-pick
  mg_revPush_v03_agl     90792b08 [origin/develop: ahead 1, behind 84] new revese push mechanic system, enlarge door angle.
  mg_rtos_v01_read       29e6512a CCL encoder reverse.
* mg_sdk4_powerAssist    2599c338 try to add power assist openning assist force.
  mg_sdk4_test9          ec938de6 [origin/develop: ahead 16, behind 23] Merge branch 'develop' of aaes.githost.io:AAESSwingDoor/SwingDoorPlatform into mg_sdk4_test9
  ms2_noSpring           71fde08e add motor pwm test, close trajactory may wrong.
  ms2_test               8a8a3648 [origin/ms2_test: ahead 7] format closecommand.cpp
  ms3_wls_pushAndGo      939f20a6 [origin/wls_dev_doorCtl: ahead 1, behind 9] push & go, test not full opened

	
//mbsSdk4.4.0
	
//2015q3.
make -j build,quasarMotor,ARMCM3_GCC-release-none-mbs_st_m64_core_v10 
/cygdrive/c/mbs/SwingDoorPlatform/mbsSdk/tools/ABS/build.mk:17: *** Toolchain "gcc-arm-none-eabi-6-2017-q2" is not supported, choose one of the following: { gcc-arm-none-eabi-4_9-2015q3 }. If you have defined a custom MBS_CC_TOOLCHAIN_PATH, make sure to end it with a slash.  Stop.

//can crc8.h
components/application/aaesGeneric/canComm/src/canComm.cpp:13:19: fatal error: crc8.h: No such file or directory
  #include <crc8.h>

	C:\mbs\SwingDoorPlatform\mbsSdk\components\common\utilities\inc


modules/comm/motorBoard/mbs_st_m64_core_v10/init/src/comm.cpp:91:81: error: invalid conversion from 'const char*' to 'MbsMsgMailboxIdentifier {aka char*}' [-fpermissive]
      if( MBS_STATUS_OK != mbsMsgRegister( &canCommServerHandle, canSrvName, 20U ) )

C:\mbs\SwingDoorPlatform/components/application/aaesGeneric/canComm/src/canComm.cpp:202: undefined reference to `crc8calc'

	  /*
	  char* const canSrvName = commInternal::can1Imp.pGetCanServiceName();
		components/application/aaesGeneric/canComm/src/canComm.cpp
	  */
	
==================================	
2019.01.21 - 25 WK04.
01. Platform code, issuse fix, transform to sdk4.4.0, springImp.
02. sw300 code,
03. foc control.
04. english.
05. chess.

	
//================================
2019.01.25 Friday
01. meeting: SL500 trainning 通用部分, Slider train scope爆炸图, Julie电机控制。
02. plan-2019: KPI mark, welcome new.

//================================
2019.01.24 Thursday.
01. summary note.
02. better work.
	
//================================
2019.01.23 Wednesday.
_SPRING_SYSTEM_IS_INCLUDED_IN_DUT_ \

    components/application/swingDoorGeneric/springSystem/unitTest \


==================================	
2019.01.14 - 18 WK03.
01. Platform code, issuse fix.
02. sw300 code,
03. foc code.
04. protocol. //kan kai. cheng zhang you suohuo.
05. english.
06. chess.



//================================
2019.01.16 Wednesday.
01. sw300 code,
02. plat form code.
03. foc code.

//================================
2019.01.14 Monday.
01. sw300 code,
02. plat form code.
03. maxima.

//================================
2019.01.11 Friday.
01. meeting.
02. Maxma use, 
03. UML use, 
04. safety in motor board, no-freeRTOS, OPD ?


//================================
2019.01.10 Thursday.
01. SPS_50, SPS_51.
02. eclipse shortcut, bookmark: Alt+Shift+B。  //Ctrl+Shift+G
03. compare meld right key not necessary.
04. effective learn, code, tool find and use. //serial tool. QT is too large 2.8G for windows
	test in vitrual box.					  //better to use c#.
05. professional knowledge!!!

//================================
2019.01.09 Wednesday.
01. KPI.
02. trajactory breakpoints reset.
03. ABS_INTERFACE.

//================================
2019.01.08 Tuesday.
01. KPI.
02. put plantuml.jar in doxgen graphic/bin/.

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
