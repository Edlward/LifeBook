
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
03. ���£�����嵥�����������˵�֧�֣�
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

G:\R&D\2017\Janny Zhang\��׼\USA

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

