/*
 * main.c
 */
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"
#include "DSP2833x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include <math.h>
//#include "dlog4ch.h"
#include "ADC_volt_current_get.h"
#include "ePWMs.h"
#include "eQEP_pos_speed_get.h"
#include "clarke.h"
#include "park.h"
#include "ipark.h"
#include "PIfunc.h"
#include "SVPWM_2L.h"

//=======宏定义=================================================
#define  T   0.0002   // PWM调制周期，也是离散化时的采样周期，单位 s
#define  PI   3.141592654
#define  PI2  6.283185307

//****永磁同步电机参数****
#define  MaxRPM  2000  //额定转速，单位 r/min
#define  p   4       //电机极对数
#define  Rs  0.78    //定子电阻，单位 欧姆
#define  Ld  0.0085  //直轴电感，单位 亨
#define  Lq  0.0085  //交轴电感，单位 亨
#define  KeSha 0.303  //电机转子磁链，单位 韦伯
#define  PWMS_FRC_DISABLE  0x0000  //宏定义，禁止ePWM模块强制功能
#define  PWMS_ALBL   0x0005    //宏定义，强制ePWM模块中ePWMA为低电平、ePWMB为低电平
#define  PWMS_AHBH   0x000A   //宏定义，强制ePWM模块中ePWMA为高电平、ePWMB为高电平
#define  PWMS_AHBL   0x0006   //宏定义，强制ePWM模块中ePWMA为高电平、ePWMB为低电平
#define  PWMS_ALBH   0x0009   //宏定义，强制ePWM模块中ePWMA为低电平、ePWMB为高电平
#define  SPEED_STEP  0.0005 //速度步长，标么值，用于速度给定环节

//======== 全局变量 ====================================================
volatile Uint16 Enable_flag = 0;    //全局使能位
volatile Uint16 LockRotor_flag = 1; //转子定位使能位
volatile Uint16 LiCi_OK_flag = 1;  //永磁同步电机磁场由永磁体建立
volatile Uint16 LockRotor_OK_flag = 0;  //转子定位结束标志位，定位前为0，定位后为1
volatile Uint32 Time_speed_cnt = 0; //每次中断加1，当达到速度调节周期时，进行速度PI调节

//定义PI调节器的参数及输出限幅值
volatile float Isdref=0, IsdKp=2, IsdKi=15, IsdLimit = 50;  //isd PI调节器
volatile float Isqref=1, IsqKp=2, IsqKi=15, IsqLimit = 50;  //isqPI调节器
volatile float Speedref=0.025, SpeedKp=0.02, SpeedKi=0.1, SpeedLimit=2.0; //速度PI调节器
volatile float Speedgive_pu=0.05;  //变量，用来存储速度斜坡函数的目标值，这里速度给定以标幺化形式表示
volatile float Mech_speed_w=0;   //变量，机械角速度
volatile float Elec_speed_w=0;    //变量，电角速度

//以下结构体变量的定义与用户在相应头文件里的定义有关，为便于理解，读者可翻阅本书前面介绍的相关文件
ADC_VOLT_CURRENT_GET  Volt_current = ADC_VOLT_CURRENT_GET_DEFAULTS;  //AD采样模块对应的结构体变量
EQEP_POS_SPEED_GET  Pos_speed = EQEP_POS_SPEED_GET_DEFAULTS;  //角度与速度测量模块对应的结构体变量
EPWMS  Epwm_modules = EPWMS_DEFAULTS; //ePWM模块对应的结构体变量

//坐标变换
CLARKE  Iabc_to_Ialphabeta = CLARKE_DEFAULTS; //Clarke变换：电流ia ib ic向iα iβ变换对应的结构体变量
PARK  Ialphabeta_to_Idq = PARK_DEFAULTS;   //Park变换：电流iα iβ向id iq变换对应的结构体变量
PARK  Ualphabeta_to_Udq = PARK_DEFAULTS;  //Park变换：电压uα uβ向ud uq变换对应的结构体变量
IPARK  Udq_to_Ualphabeta = IPARK_DEFAULTS; //反Park变换：电压ud uq向uα uβ变换对应的结构体变量

//PI调节器对应的结构体变量
PIFUNC ASR = PIFUNC_DEFAULTS;     //速度PI调节器ASR
PIFUNC A_Isd_R = PIFUNC_DEFAULTS;  //d轴电流PI调节器A_Isd_R
PIFUNC A_Isq_R = PIFUNC_DEFAULTS;  //q轴电流PI调节器A_Isq_R

//两电平矢量PWM算法对应的结构体变量
SVPWM_2L Svpwm = SVPWM_2L_DEFAULTS;
/*
//Dlog模块对应的变量
int16 DlogCh1 = 0;
int16 DlogCh2 = 0;
int16 DlogCh3 = 0;
int16 DlogCh4 = 0;
DLOG_4CH dlog = DLOG_4CH_DEFAULTS;
int16 Dlog_cnt=-256;
*/

//========函数声明 ==============================================
//void Dlog_init(void);  //Dlog初始化函数
interrupt void epwm1_timer_isr(void); //ePWM1周期中断服务函数
void clear_states(void); //状态清除函数

//========主程序==================================================
void main()
{
    InitSysCtrl(); //系统初始化
    DINT;//关闭全局中断
    InitPieCtrl();//初始化中断控制寄存器
    IER = 0x0000;//关闭CPU中断
    IFR = 0x0000;//清除CPU中断信号
    InitPieVectTable();//初始化中断向量表

    //延时50ms，等待控制板上其他模块完成初始化
    DELAY_US(50000L);

    //****初始化Dlog****
    //Dlog_init();

    //****ePWM模块初始化部分****
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;  //在配置ePWM模块前先禁止TBCLK时钟
    EDIS;

    //配置 ePWM1模块的周期中断功能
    EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // 选择计数器值=0为中断事件
    EPwm1Regs.ETSEL.bit.INTEN = 1; //使能相应的中断
    EPwm1Regs.ETPS.bit.INTPRD = ET_1ST; //每次中断事件发生时都产生一次中断请求
    EPwm1Regs.ETCLR.bit.INT = 1; //清中断标志位
    EALLOW;
    PieVectTable.EPWM1_INT = &epwm1_timer_isr;  //配置中断向量地址
    EDIS;
    IER |= M_INT3;// 使能CPU INT3模块的中断功能
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1; //使能PIE模块中EPWM INTn

    //由于在ePWM.c文件中设定TBCLK = SYSCLKOUT，且为增减计数模式，故三角波周期=2*15000*6.67ns=200us
    Epwm_modules.PeriodMax = 15000;  //设定计数器的最大计数值
    Epwm_modules.init(&Epwm_modules); //调用ePWM模块的初始化函数，开始初始化

    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1; //配置完成后，重新使能TBCLK时钟信号
    EDIS;

    //在矢量系统开始工作前，强制ePWM1~ePWM3模块输出脉冲为低电平，避免开关管误开通
    EPwm1Regs.AQCSFRC.all = PWMS_ALBL;
    EPwm2Regs.AQCSFRC.all = PWMS_ALBL;
    EPwm3Regs.AQCSFRC.all = PWMS_ALBL;

    //****ADC模块初始化****
    Volt_current.init(&Volt_current); //调用ADC模块初始化函数

    //****eQEP模块初始化****
    Pos_speed.init(&Pos_speed); //调用eQEP模块初始化函数

    //****初始化调节器****
    ASR.Kp = SpeedKp;
    ASR.Ki = SpeedKi;
    ASR.OutMax = SpeedLimit;
    ASR.OutMin =-SpeedLimit;

    A_Isd_R.Kp = IsdKp;
    A_Isd_R.Ki = IsdKi;
    A_Isd_R.OutMax = IsdLimit;
    A_Isd_R.OutMin =-IsdLimit;

    A_Isq_R.Kp = IsqKp;
    A_Isq_R.Ki = IsqKi;
    A_Isq_R.OutMax = IsqLimit;
    A_Isq_R.OutMin =-IsqLimit;

    //****开始工作****
    while(Enable_flag==0); //等待，直到Enable_flag=1时开始向下执行，调试时可直接通过CCS设定Enable_flag的值

    EINT; //开CPU中断
    ERTM;

    //死循环
    while(1)
    {
        if(Enable_flag==0) //如果在运行过程中，Enable_flag被清零，那么强制各个ePWM模块输出为低电平
        {
            EPwm1Regs.AQCSFRC.all = PWMS_ALBL;
            EPwm2Regs.AQCSFRC.all = PWMS_ALBL;
            EPwm3Regs.AQCSFRC.all = PWMS_ALBL;
            clear_states();
        }
        else //正常运行时，禁止ePWM模块的强制功能
        {
            EPwm1Regs.AQCSFRC.all = PWMS_FRC_DISABLE;
            EPwm2Regs.AQCSFRC.all = PWMS_FRC_DISABLE;
            EPwm3Regs.AQCSFRC.all = PWMS_FRC_DISABLE;
        }
    }
}

//==============================================================
//中断服务函数
//==============================================================
//**********************************
/*
  @ Description: ePWM1周期中断服务函数
  @ Param
  @ Return
*/
//**********************************
void epwm1_timer_isr()
{
    //采样电压电流
    Volt_current.read(&Volt_current);

    //将ABC坐标系的电流变换到Alpha Beta 坐标系，Clarke变换
    Iabc_to_Ialphabeta.As = Volt_current.Ia;
    Iabc_to_Ialphabeta.Bs = Volt_current.Ib;
    Iabc_to_Ialphabeta.calc(&Iabc_to_Ialphabeta);

    //----开始对转子进行初始定位-----------------------------------------------------
    /*如果转子磁场建立完成，开始转子定位，由于永磁同步电机转子磁场由永磁体建立，LiCi_OK_flag始终为1。在电励磁同步电机调速过程中，可通过此位判断转子磁场是否建立完成。*/
    if(LiCi_OK_flag==1)
    {
        if( LockRotor_flag ==1 ) //转子定位过程
        {
             //电流Park变换
            Ialphabeta_to_Idq.Alpha=Iabc_to_Ialphabeta.Alpha;
            Ialphabeta_to_Idq.Beta =Iabc_to_Ialphabeta.Beta;
            Ialphabeta_to_Idq.Cos=1;
            Ialphabeta_to_Idq.Sin=0;
            Ialphabeta_to_Idq.calc(&Ialphabeta_to_Idq);

            //转子定位需要给定α β轴电流，这里将旋转变换角设定为0，即可直接给定d q轴电流
            //给定d轴电流，并进行调节
            A_Isd_R.Give = 1.0; //单位A
            A_Isd_R.Feedback=Ialphabeta_to_Idq.Ds;
            A_Isd_R.Kp=IsdKp;
            A_Isd_R.Ki=IsdKi;
            A_Isd_R.OutMax = IsdLimit;
            A_Isd_R.OutMin =-IsdLimit;
            A_Isd_R.calc(&A_Isd_R);

            IsqKp=IsdKp;
            IsqKi=IsdKi;

               //给定q轴电流，并进行调节
             A_Isq_R.Give = 0;
             A_Isq_R.Feedback=Ialphabeta_to_Idq.Qs;
             A_Isq_R.Kp=IsqKp;
             A_Isq_R.Ki=IsqKi;
             A_Isq_R.OutMax = IsqLimit;
             A_Isq_R.OutMin =-IsqLimit;
             A_Isq_R.calc(&A_Isq_R);

               //电压前馈
             Udq_to_Ualphabeta.Ds=A_Isd_R.Output;
             Udq_to_Ualphabeta.Qs=A_Isq_R.Output;
             Udq_to_Ualphabeta.Cos=1;
             Udq_to_Ualphabeta.Sin=0;
             Udq_to_Ualphabeta.calc(&Udq_to_Ualphabeta);

            //       Time_LockRotor++;//************************************************************************************???
             LockRotor_OK_flag=0;
        }
        else if(LockRotor_OK_flag==0)  //转子初始定位过程结束
        {
            LockRotor_OK_flag=1;  //转子定位结束后，将此位置1
            EQep2Regs.QEPCTL.bit.SWI=1; //转子定位过程编码器将转动，这里在定位结束后对eQEP模块重新初始化
        }
    }
    //----转子定位结束--------------------------------------------------------

    //----启动电机，并进行矢量闭环控制算法的实现-----------------------------------
    if(LockRotor_OK_flag==1)  //保证在转子定位结束后，才进行矢量闭环控制算法
    {
        //速度给定，斜坡函数
        if(Time_speed_cnt==100) //100*200us=20000us=20ms
        {
         //把速度给定限定在额定转速内，支持正反转
         if( Speedgive_pu > 1)
           { Speedgive_pu = 1;}
         else if( Speedgive_pu < -1)
           { Speedgive_pu = -1;}

         if( Speedref > Speedgive_pu )
           {
             Speedref -= SPEED_STEP;
             if( Speedref < Speedgive_pu)
               { Speedref = Speedgive_pu;}
           }
         else if( Speedref < Speedgive_pu)
           {
             Speedref += SPEED_STEP;
             if( Speedref > Speedgive_pu)
               {Speedref = Speedgive_pu;}
           }

        Pos_speed.calc(&Pos_speed); //读取当前转速

        //转速调节PI
        ASR.Give = Speedref * MaxRPM;  //速度给定******************************************************************************给定速度
        ASR.Feedback = Pos_speed.Speed_Mr_Rpm; //速度反馈
        ASR.Kp = SpeedKp;
        ASR.Ki = SpeedKi;
        ASR.OutMax = SpeedLimit;
        ASR.OutMin =-SpeedLimit;
        ASR.calc(&ASR);

        Time_speed_cnt = 0; //对计数器清零，随后进入下一个计数周期
        }
        else
        { Time_speed_cnt++; }

        //读取d轴与α 轴之间的夹角
        Pos_speed.calc(&Pos_speed);
        Pos_speed.ElecTheta = Pos_speed.ElecTheta * PI2; //在eQEP角度测量函数里，一周角度范围对应0~1，这里将其化为0~2pi
        if(Pos_speed.ElecTheta>PI)
        { Pos_speed.ElecTheta-=PI2; }

        //将α β坐标系下的子电流转换到 d q坐标系，Park变换
        Ialphabeta_to_Idq.Alpha = Iabc_to_Ialphabeta.Alpha;
        Ialphabeta_to_Idq.Beta =Iabc_to_Ialphabeta.Beta;
        Ialphabeta_to_Idq.Cos = cos(Pos_speed.ElecTheta);
        Ialphabeta_to_Idq.Sin = sin(Pos_speed.ElecTheta);
        Ialphabeta_to_Idq.calc(&Ialphabeta_to_Idq);

        //Isd调节PI
        A_Isd_R.Give = 0; //采用isd=0控制策略
        A_Isd_R.Feedback =Ialphabeta_to_Idq.Ds;
        A_Isd_R.Kp =IsdKp;
        A_Isd_R.Ki =IsdKi;
        A_Isd_R.OutMax = IsdLimit;
        A_Isd_R.OutMin =-IsdLimit;
        A_Isd_R.calc(&A_Isd_R);

        IsqKp=IsdKp;
        IsqKi=IsdKi;

        //Isq调节PI
        A_Isq_R.Give = ASR.Output; //转矩电流的给定值 = 转速PI调节器的输出
        A_Isq_R.Feedback =Ialphabeta_to_Idq.Qs;
        A_Isq_R.Kp =IsqKp;
        A_Isq_R.Ki =IsqKi;
        A_Isq_R.OutMax = IsqLimit;
        A_Isq_R.OutMin =-IsqLimit;
        A_Isq_R.calc(&A_Isq_R);

        //电压前馈单元，并将d q坐标系下的电压给定转换到α β坐标系
        Mech_speed_w = Pos_speed.Speed_Mr_Rpm * PI2 / 60; //机械角速度
        Elec_speed_w = Mech_speed_w * Pos_speed.PolePairs; //电角速度
        Udq_to_Ualphabeta.Ds =A_Isd_R.Output- Ialphabeta_to_Idq.Qs*Elec_speed_w*Ld;
        Udq_to_Ualphabeta.Qs =A_Isq_R.Output+ Ialphabeta_to_Idq.Qs*Rs+KeSha*Elec_speed_w;
        Udq_to_Ualphabeta.Cos = cos(Pos_speed.ElecTheta);
        Udq_to_Ualphabeta.Sin = sin(Pos_speed.ElecTheta);
        Udq_to_Ualphabeta.calc(&Udq_to_Ualphabeta);
}

    //----两电平逆变器的控制-----------------------------------------------------------
    //两电平SVPWM算法
     Svpwm.Ualpha = Udq_to_Ualphabeta.Alpha; //电压前馈单元的输出uα
     Svpwm.Ubeta  = Udq_to_Ualphabeta.Beta;  //电压前馈单元的输出u β
     Svpwm.Vdc = Volt_current.Vdc;  //通过AD模块测量的直流母线电压
     Svpwm.calc(&Svpwm);

    //使用ePWM模块输出相应的PWM脉冲
     Epwm_modules.Duty1A = Svpwm.Tcmpa;
     Epwm_modules.Duty2A = Svpwm.Tcmpb;
     Epwm_modules.Duty3A = Svpwm.Tcmpc;
     Epwm_modules.update(&Epwm_modules);
    //----逆变器控制算法完成-----------------------------------------------------------

    //----将变量波形进行量化，配合CCS的Graph功能进行显示-----------------------------------------
    //  Dlog_cnt+=1;
    //  if(Dlog_cnt==257){Dlog_cnt=-256;}
    //  DlogCh1 = (int16) (Dlog_cnt);
    //  DlogCh2 = (int16) (Dlog_cnt);
    //  DlogCh3 = (int16) ( ASR.Give / MaxRPM*512 );
    //  DlogCh4 = (int16) ( ASR.Feedback / MaxRPM*512 );
    // dlog.update(&dlog);

    EPwm1Regs.ETCLR.bit.INT = 1; //清除中断标志位
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

//======== 函数定义===========================
//**********************************
/*
  @ Description: 状态复位子函数
  @ Param
  @ Return
*/
//**********************************
void clear_states()
{
   Speedgive_pu=0;

   ADC_VOLT_CURRENT_GET Volt_current = ADC_VOLT_CURRENT_GET_DEFAULTS;
   EQEP_POS_SPEED_GET Pos_speed = EQEP_POS_SPEED_GET_DEFAULTS;
   EPWMS Epwm_modules = EPWMS_DEFAULTS;

   CLARKE Iabc_to_Ialphabeta = CLARKE_DEFAULTS;
   PARK Ialphabeta_to_Idq = PARK_DEFAULTS;
   PARK Ualphabeta_to_Udq = PARK_DEFAULTS;
   IPARK Udq_to_Ualphabeta = IPARK_DEFAULTS;

   PIFUNC ASR = PIFUNC_DEFAULTS;
   PIFUNC A_Isd_R = PIFUNC_DEFAULTS;
   PIFUNC A_Isq_R = PIFUNC_DEFAULTS;

   SVPWM_2L Svpwm = SVPWM_2L_DEFAULTS;
}

//**********************************
/*
  @ Description: Dlog初始化子函数
  @ Param
  @ Return
*/
//**********************************
/*
void Dlog_init(void)
{
    dlog.iptr1 = &DlogCh1;
    dlog.iptr2 = &DlogCh2;
    dlog.iptr3 = &DlogCh3;
    dlog.iptr4 = &DlogCh4;
    dlog.trig_value = 0x0;
    dlog.size = 0x400;
    dlog.prescalar = 1;
    dlog.init(&dlog);
}
*/
