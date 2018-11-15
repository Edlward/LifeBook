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

//=======�궨��=================================================
#define  T   0.0002   // PWM�������ڣ�Ҳ����ɢ��ʱ�Ĳ������ڣ���λ s
#define  PI   3.141592654
#define  PI2  6.283185307

//****����ͬ���������****
#define  MaxRPM  2000  //�ת�٣���λ r/min
#define  p   4       //���������
#define  Rs  0.78    //���ӵ��裬��λ ŷķ
#define  Ld  0.0085  //ֱ���У���λ ��
#define  Lq  0.0085  //�����У���λ ��
#define  KeSha 0.303  //���ת�Ӵ�������λ Τ��
#define  PWMS_FRC_DISABLE  0x0000  //�궨�壬��ֹePWMģ��ǿ�ƹ���
#define  PWMS_ALBL   0x0005    //�궨�壬ǿ��ePWMģ����ePWMAΪ�͵�ƽ��ePWMBΪ�͵�ƽ
#define  PWMS_AHBH   0x000A   //�궨�壬ǿ��ePWMģ����ePWMAΪ�ߵ�ƽ��ePWMBΪ�ߵ�ƽ
#define  PWMS_AHBL   0x0006   //�궨�壬ǿ��ePWMģ����ePWMAΪ�ߵ�ƽ��ePWMBΪ�͵�ƽ
#define  PWMS_ALBH   0x0009   //�궨�壬ǿ��ePWMģ����ePWMAΪ�͵�ƽ��ePWMBΪ�ߵ�ƽ
#define  SPEED_STEP  0.0005 //�ٶȲ�������ôֵ�������ٶȸ�������

//======== ȫ�ֱ��� ====================================================
volatile Uint16 Enable_flag = 0;    //ȫ��ʹ��λ
volatile Uint16 LockRotor_flag = 1; //ת�Ӷ�λʹ��λ
volatile Uint16 LiCi_OK_flag = 1;  //����ͬ������ų��������彨��
volatile Uint16 LockRotor_OK_flag = 0;  //ת�Ӷ�λ������־λ����λǰΪ0����λ��Ϊ1
volatile Uint32 Time_speed_cnt = 0; //ÿ���жϼ�1�����ﵽ�ٶȵ�������ʱ�������ٶ�PI����

//����PI�������Ĳ���������޷�ֵ
volatile float Isdref=0, IsdKp=2, IsdKi=15, IsdLimit = 50;  //isd PI������
volatile float Isqref=1, IsqKp=2, IsqKi=15, IsqLimit = 50;  //isqPI������
volatile float Speedref=0.025, SpeedKp=0.02, SpeedKi=0.1, SpeedLimit=2.0; //�ٶ�PI������
volatile float Speedgive_pu=0.05;  //�����������洢�ٶ�б�º�����Ŀ��ֵ�������ٶȸ����Ա��ۻ���ʽ��ʾ
volatile float Mech_speed_w=0;   //��������е���ٶ�
volatile float Elec_speed_w=0;    //����������ٶ�

//���½ṹ������Ķ������û�����Ӧͷ�ļ���Ķ����йأ�Ϊ������⣬���߿ɷ��ı���ǰ����ܵ�����ļ�
ADC_VOLT_CURRENT_GET  Volt_current = ADC_VOLT_CURRENT_GET_DEFAULTS;  //AD����ģ���Ӧ�Ľṹ�����
EQEP_POS_SPEED_GET  Pos_speed = EQEP_POS_SPEED_GET_DEFAULTS;  //�Ƕ����ٶȲ���ģ���Ӧ�Ľṹ�����
EPWMS  Epwm_modules = EPWMS_DEFAULTS; //ePWMģ���Ӧ�Ľṹ�����

//����任
CLARKE  Iabc_to_Ialphabeta = CLARKE_DEFAULTS; //Clarke�任������ia ib ic��i�� i�±任��Ӧ�Ľṹ�����
PARK  Ialphabeta_to_Idq = PARK_DEFAULTS;   //Park�任������i�� i����id iq�任��Ӧ�Ľṹ�����
PARK  Ualphabeta_to_Udq = PARK_DEFAULTS;  //Park�任����ѹu�� u����ud uq�任��Ӧ�Ľṹ�����
IPARK  Udq_to_Ualphabeta = IPARK_DEFAULTS; //��Park�任����ѹud uq��u�� u�±任��Ӧ�Ľṹ�����

//PI��������Ӧ�Ľṹ�����
PIFUNC ASR = PIFUNC_DEFAULTS;     //�ٶ�PI������ASR
PIFUNC A_Isd_R = PIFUNC_DEFAULTS;  //d�����PI������A_Isd_R
PIFUNC A_Isq_R = PIFUNC_DEFAULTS;  //q�����PI������A_Isq_R

//����ƽʸ��PWM�㷨��Ӧ�Ľṹ�����
SVPWM_2L Svpwm = SVPWM_2L_DEFAULTS;
/*
//Dlogģ���Ӧ�ı���
int16 DlogCh1 = 0;
int16 DlogCh2 = 0;
int16 DlogCh3 = 0;
int16 DlogCh4 = 0;
DLOG_4CH dlog = DLOG_4CH_DEFAULTS;
int16 Dlog_cnt=-256;
*/

//========�������� ==============================================
//void Dlog_init(void);  //Dlog��ʼ������
interrupt void epwm1_timer_isr(void); //ePWM1�����жϷ�����
void clear_states(void); //״̬�������

//========������==================================================
void main()
{
    InitSysCtrl(); //ϵͳ��ʼ��
    DINT;//�ر�ȫ���ж�
    InitPieCtrl();//��ʼ���жϿ��ƼĴ���
    IER = 0x0000;//�ر�CPU�ж�
    IFR = 0x0000;//���CPU�ж��ź�
    InitPieVectTable();//��ʼ���ж�������

    //��ʱ50ms���ȴ����ư�������ģ����ɳ�ʼ��
    DELAY_US(50000L);

    //****��ʼ��Dlog****
    //Dlog_init();

    //****ePWMģ���ʼ������****
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;  //������ePWMģ��ǰ�Ƚ�ֹTBCLKʱ��
    EDIS;

    //���� ePWM1ģ��������жϹ���
    EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // ѡ�������ֵ=0Ϊ�ж��¼�
    EPwm1Regs.ETSEL.bit.INTEN = 1; //ʹ����Ӧ���ж�
    EPwm1Regs.ETPS.bit.INTPRD = ET_1ST; //ÿ���ж��¼�����ʱ������һ���ж�����
    EPwm1Regs.ETCLR.bit.INT = 1; //���жϱ�־λ
    EALLOW;
    PieVectTable.EPWM1_INT = &epwm1_timer_isr;  //�����ж�������ַ
    EDIS;
    IER |= M_INT3;// ʹ��CPU INT3ģ����жϹ���
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1; //ʹ��PIEģ����EPWM INTn

    //������ePWM.c�ļ����趨TBCLK = SYSCLKOUT����Ϊ��������ģʽ�������ǲ�����=2*15000*6.67ns=200us
    Epwm_modules.PeriodMax = 15000;  //�趨��������������ֵ
    Epwm_modules.init(&Epwm_modules); //����ePWMģ��ĳ�ʼ����������ʼ��ʼ��

    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1; //������ɺ�����ʹ��TBCLKʱ���ź�
    EDIS;

    //��ʸ��ϵͳ��ʼ����ǰ��ǿ��ePWM1~ePWM3ģ���������Ϊ�͵�ƽ�����⿪�ع���ͨ
    EPwm1Regs.AQCSFRC.all = PWMS_ALBL;
    EPwm2Regs.AQCSFRC.all = PWMS_ALBL;
    EPwm3Regs.AQCSFRC.all = PWMS_ALBL;

    //****ADCģ���ʼ��****
    Volt_current.init(&Volt_current); //����ADCģ���ʼ������

    //****eQEPģ���ʼ��****
    Pos_speed.init(&Pos_speed); //����eQEPģ���ʼ������

    //****��ʼ��������****
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

    //****��ʼ����****
    while(Enable_flag==0); //�ȴ���ֱ��Enable_flag=1ʱ��ʼ����ִ�У�����ʱ��ֱ��ͨ��CCS�趨Enable_flag��ֵ

    EINT; //��CPU�ж�
    ERTM;

    //��ѭ��
    while(1)
    {
        if(Enable_flag==0) //��������й����У�Enable_flag�����㣬��ôǿ�Ƹ���ePWMģ�����Ϊ�͵�ƽ
        {
            EPwm1Regs.AQCSFRC.all = PWMS_ALBL;
            EPwm2Regs.AQCSFRC.all = PWMS_ALBL;
            EPwm3Regs.AQCSFRC.all = PWMS_ALBL;
            clear_states();
        }
        else //��������ʱ����ֹePWMģ���ǿ�ƹ���
        {
            EPwm1Regs.AQCSFRC.all = PWMS_FRC_DISABLE;
            EPwm2Regs.AQCSFRC.all = PWMS_FRC_DISABLE;
            EPwm3Regs.AQCSFRC.all = PWMS_FRC_DISABLE;
        }
    }
}

//==============================================================
//�жϷ�����
//==============================================================
//**********************************
/*
  @ Description: ePWM1�����жϷ�����
  @ Param
  @ Return
*/
//**********************************
void epwm1_timer_isr()
{
    //������ѹ����
    Volt_current.read(&Volt_current);

    //��ABC����ϵ�ĵ����任��Alpha Beta ����ϵ��Clarke�任
    Iabc_to_Ialphabeta.As = Volt_current.Ia;
    Iabc_to_Ialphabeta.Bs = Volt_current.Ib;
    Iabc_to_Ialphabeta.calc(&Iabc_to_Ialphabeta);

    //----��ʼ��ת�ӽ��г�ʼ��λ-----------------------------------------------------
    /*���ת�Ӵų�������ɣ���ʼת�Ӷ�λ����������ͬ�����ת�Ӵų��������彨����LiCi_OK_flagʼ��Ϊ1���ڵ�����ͬ��������ٹ����У���ͨ����λ�ж�ת�Ӵų��Ƿ�����ɡ�*/
    if(LiCi_OK_flag==1)
    {
        if( LockRotor_flag ==1 ) //ת�Ӷ�λ����
        {
             //����Park�任
            Ialphabeta_to_Idq.Alpha=Iabc_to_Ialphabeta.Alpha;
            Ialphabeta_to_Idq.Beta =Iabc_to_Ialphabeta.Beta;
            Ialphabeta_to_Idq.Cos=1;
            Ialphabeta_to_Idq.Sin=0;
            Ialphabeta_to_Idq.calc(&Ialphabeta_to_Idq);

            //ת�Ӷ�λ��Ҫ������ ������������ｫ��ת�任���趨Ϊ0������ֱ�Ӹ���d q�����
            //����d������������е���
            A_Isd_R.Give = 1.0; //��λA
            A_Isd_R.Feedback=Ialphabeta_to_Idq.Ds;
            A_Isd_R.Kp=IsdKp;
            A_Isd_R.Ki=IsdKi;
            A_Isd_R.OutMax = IsdLimit;
            A_Isd_R.OutMin =-IsdLimit;
            A_Isd_R.calc(&A_Isd_R);

            IsqKp=IsdKp;
            IsqKi=IsdKi;

               //����q������������е���
             A_Isq_R.Give = 0;
             A_Isq_R.Feedback=Ialphabeta_to_Idq.Qs;
             A_Isq_R.Kp=IsqKp;
             A_Isq_R.Ki=IsqKi;
             A_Isq_R.OutMax = IsqLimit;
             A_Isq_R.OutMin =-IsqLimit;
             A_Isq_R.calc(&A_Isq_R);

               //��ѹǰ��
             Udq_to_Ualphabeta.Ds=A_Isd_R.Output;
             Udq_to_Ualphabeta.Qs=A_Isq_R.Output;
             Udq_to_Ualphabeta.Cos=1;
             Udq_to_Ualphabeta.Sin=0;
             Udq_to_Ualphabeta.calc(&Udq_to_Ualphabeta);

            //       Time_LockRotor++;//************************************************************************************???
             LockRotor_OK_flag=0;
        }
        else if(LockRotor_OK_flag==0)  //ת�ӳ�ʼ��λ���̽���
        {
            LockRotor_OK_flag=1;  //ת�Ӷ�λ�����󣬽���λ��1
            EQep2Regs.QEPCTL.bit.SWI=1; //ת�Ӷ�λ���̱�������ת���������ڶ�λ�������eQEPģ�����³�ʼ��
        }
    }
    //----ת�Ӷ�λ����--------------------------------------------------------

    //----���������������ʸ���ջ������㷨��ʵ��-----------------------------------
    if(LockRotor_OK_flag==1)  //��֤��ת�Ӷ�λ�����󣬲Ž���ʸ���ջ������㷨
    {
        //�ٶȸ�����б�º���
        if(Time_speed_cnt==100) //100*200us=20000us=20ms
        {
         //���ٶȸ����޶��ڶת���ڣ�֧������ת
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

        Pos_speed.calc(&Pos_speed); //��ȡ��ǰת��

        //ת�ٵ���PI
        ASR.Give = Speedref * MaxRPM;  //�ٶȸ���******************************************************************************�����ٶ�
        ASR.Feedback = Pos_speed.Speed_Mr_Rpm; //�ٶȷ���
        ASR.Kp = SpeedKp;
        ASR.Ki = SpeedKi;
        ASR.OutMax = SpeedLimit;
        ASR.OutMin =-SpeedLimit;
        ASR.calc(&ASR);

        Time_speed_cnt = 0; //�Լ��������㣬��������һ����������
        }
        else
        { Time_speed_cnt++; }

        //��ȡd����� ��֮��ļн�
        Pos_speed.calc(&Pos_speed);
        Pos_speed.ElecTheta = Pos_speed.ElecTheta * PI2; //��eQEP�ǶȲ��������һ�ܽǶȷ�Χ��Ӧ0~1�����ｫ�仯Ϊ0~2pi
        if(Pos_speed.ElecTheta>PI)
        { Pos_speed.ElecTheta-=PI2; }

        //���� ������ϵ�µ��ӵ���ת���� d q����ϵ��Park�任
        Ialphabeta_to_Idq.Alpha = Iabc_to_Ialphabeta.Alpha;
        Ialphabeta_to_Idq.Beta =Iabc_to_Ialphabeta.Beta;
        Ialphabeta_to_Idq.Cos = cos(Pos_speed.ElecTheta);
        Ialphabeta_to_Idq.Sin = sin(Pos_speed.ElecTheta);
        Ialphabeta_to_Idq.calc(&Ialphabeta_to_Idq);

        //Isd����PI
        A_Isd_R.Give = 0; //����isd=0���Ʋ���
        A_Isd_R.Feedback =Ialphabeta_to_Idq.Ds;
        A_Isd_R.Kp =IsdKp;
        A_Isd_R.Ki =IsdKi;
        A_Isd_R.OutMax = IsdLimit;
        A_Isd_R.OutMin =-IsdLimit;
        A_Isd_R.calc(&A_Isd_R);

        IsqKp=IsdKp;
        IsqKi=IsdKi;

        //Isq����PI
        A_Isq_R.Give = ASR.Output; //ת�ص����ĸ���ֵ = ת��PI�����������
        A_Isq_R.Feedback =Ialphabeta_to_Idq.Qs;
        A_Isq_R.Kp =IsqKp;
        A_Isq_R.Ki =IsqKi;
        A_Isq_R.OutMax = IsqLimit;
        A_Isq_R.OutMin =-IsqLimit;
        A_Isq_R.calc(&A_Isq_R);

        //��ѹǰ����Ԫ������d q����ϵ�µĵ�ѹ����ת������ ������ϵ
        Mech_speed_w = Pos_speed.Speed_Mr_Rpm * PI2 / 60; //��е���ٶ�
        Elec_speed_w = Mech_speed_w * Pos_speed.PolePairs; //����ٶ�
        Udq_to_Ualphabeta.Ds =A_Isd_R.Output- Ialphabeta_to_Idq.Qs*Elec_speed_w*Ld;
        Udq_to_Ualphabeta.Qs =A_Isq_R.Output+ Ialphabeta_to_Idq.Qs*Rs+KeSha*Elec_speed_w;
        Udq_to_Ualphabeta.Cos = cos(Pos_speed.ElecTheta);
        Udq_to_Ualphabeta.Sin = sin(Pos_speed.ElecTheta);
        Udq_to_Ualphabeta.calc(&Udq_to_Ualphabeta);
}

    //----����ƽ������Ŀ���-----------------------------------------------------------
    //����ƽSVPWM�㷨
     Svpwm.Ualpha = Udq_to_Ualphabeta.Alpha; //��ѹǰ����Ԫ�����u��
     Svpwm.Ubeta  = Udq_to_Ualphabeta.Beta;  //��ѹǰ����Ԫ�����u ��
     Svpwm.Vdc = Volt_current.Vdc;  //ͨ��ADģ�������ֱ��ĸ�ߵ�ѹ
     Svpwm.calc(&Svpwm);

    //ʹ��ePWMģ�������Ӧ��PWM����
     Epwm_modules.Duty1A = Svpwm.Tcmpa;
     Epwm_modules.Duty2A = Svpwm.Tcmpb;
     Epwm_modules.Duty3A = Svpwm.Tcmpc;
     Epwm_modules.update(&Epwm_modules);
    //----����������㷨���-----------------------------------------------------------

    //----���������ν������������CCS��Graph���ܽ�����ʾ-----------------------------------------
    //  Dlog_cnt+=1;
    //  if(Dlog_cnt==257){Dlog_cnt=-256;}
    //  DlogCh1 = (int16) (Dlog_cnt);
    //  DlogCh2 = (int16) (Dlog_cnt);
    //  DlogCh3 = (int16) ( ASR.Give / MaxRPM*512 );
    //  DlogCh4 = (int16) ( ASR.Feedback / MaxRPM*512 );
    // dlog.update(&dlog);

    EPwm1Regs.ETCLR.bit.INT = 1; //����жϱ�־λ
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

//======== ��������===========================
//**********************************
/*
  @ Description: ״̬��λ�Ӻ���
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
  @ Description: Dlog��ʼ���Ӻ���
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
