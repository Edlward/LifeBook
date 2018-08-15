
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
01.	mbsSdk.
04.	share.
}

//================================
1005-template:
{


}
//1005.

//================================
1006-project:
{
01. backup .setting.
02. send email for one question.
03. 做事，完成清单；帮助，别人的支持；
}
//1006.


//================================
1015-sentence:
{
Fixed in new commit.
Fixed in new commit as it may. 
As far as my concerned it's use full to distinguish class and object with C(class).
Changed to xxx in new commit.
Removed the outputConfig.hpp file in new commit.

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
#8     00000 00:00:00.007    Info quasarMain OMSBasicMain task started
MBS Console online, type help for a list of available commands
> 
## Assert failed at LR 0x801D03F, task commApp
## Assert failed at LR 0x8014BBF, task outputApp
	//message: vTaskDelayUntil( &xLastWakeTime, 100 ); in static void commApp( void* pvParameters ).
	//\modules\messageRouter\motorBoard\mbs_st_m64_core_v10\config\src\messageRoutingTable.cpp

-----------------------------------	
04. can comm. //jump. //open-signal.

-----------------------------------	
05. ADC_ResetCalibration(ADC1);

-----------------------------------	
06. initial speed -40; //
const int16_t CloseCommandImp::csi16SetSpeedAtClosed           = -40; /* -0.040 rad/s shaft speed */
/SwingDoorPlatform/modules/motionControl/motorBoard/mbs_st_m64_core_v10/config/src/motionControlConfig.cpp==

-----------------------------------	
07. Kp, Ki, Kc.
enum { PUSH_SPEED_P = 400 }; 				//400Nms/radian on output shaft
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
	
}
//4005.



//################################
5000-log:
{
virtual int16_t si16GetMotorCrrtLimit() const volatile = 0; //xxvv,2502=2.502A, v0.2.
mbsLogPrintf("Software ID V00.03. \r");


	





	
	
G:\R&D\2018\Jerry Hua\002-ST-Link Utility Load Flash\	
	
	
C:\mbs\zs_plat
C:\mbs\SwingDoorPlatform














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

