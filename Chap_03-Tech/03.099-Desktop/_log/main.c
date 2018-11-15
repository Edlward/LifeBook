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

//=======ºê¶¨Òå=================================================
#define  T   0.0002   // PWMµ÷ÖÆÖÜÆÚ£¬Ò²ÊÇÀëÉ¢»¯Ê±µÄ²ÉÑùÖÜÆÚ£¬µ¥Î» s
#define  PI   3.141592654
#define  PI2  6.283185307

//****ÓÀ´ÅÍ¬²½µç»ú²ÎÊý****
#define  MaxRPM  2000  //¶î¶¨×ªËÙ£¬µ¥Î» r/min
#define  p   4       //µç»ú¼«¶ÔÊý
#define  Rs  0.78    //¶¨×Óµç×è£¬µ¥Î» Å·Ä·
#define  Ld  0.0085  //Ö±Öáµç¸Ð£¬µ¥Î» ºà
#define  Lq  0.0085  //½»Öáµç¸Ð£¬µ¥Î» ºà
#define  KeSha 0.303  //µç»ú×ª×Ó´ÅÁ´£¬µ¥Î» Î¤²®
#define  PWMS_FRC_DISABLE  0x0000  //ºê¶¨Òå£¬½ûÖ¹ePWMÄ£¿éÇ¿ÖÆ¹¦ÄÜ
#define  PWMS_ALBL   0x0005    //ºê¶¨Òå£¬Ç¿ÖÆePWMÄ£¿éÖÐePWMAÎªµÍµçÆ½¡¢ePWMBÎªµÍµçÆ½
#define  PWMS_AHBH   0x000A   //ºê¶¨Òå£¬Ç¿ÖÆePWMÄ£¿éÖÐePWMAÎª¸ßµçÆ½¡¢ePWMBÎª¸ßµçÆ½
#define  PWMS_AHBL   0x0006   //ºê¶¨Òå£¬Ç¿ÖÆePWMÄ£¿éÖÐePWMAÎª¸ßµçÆ½¡¢ePWMBÎªµÍµçÆ½
#define  PWMS_ALBH   0x0009   //ºê¶¨Òå£¬Ç¿ÖÆePWMÄ£¿éÖÐePWMAÎªµÍµçÆ½¡¢ePWMBÎª¸ßµçÆ½
#define  SPEED_STEP  0.0005 //ËÙ¶È²½³¤£¬±êÃ´Öµ£¬ÓÃÓÚËÙ¶È¸ø¶¨»·½Ú

//======== È«¾Ö±äÁ¿ ====================================================
volatile Uint16 Enable_flag = 0;    //È«¾ÖÊ¹ÄÜÎ»
volatile Uint16 LockRotor_flag = 1; //×ª×Ó¶¨Î»Ê¹ÄÜÎ»
volatile Uint16 LiCi_OK_flag = 1;  //ÓÀ´ÅÍ¬²½µç»ú´Å³¡ÓÉÓÀ´ÅÌå½¨Á¢
volatile Uint16 LockRotor_OK_flag = 0;  //×ª×Ó¶¨Î»½áÊø±êÖ¾Î»£¬¶¨Î»Ç°Îª0£¬¶¨Î»ºóÎª1
volatile Uint32 Time_speed_cnt = 0; //Ã¿´ÎÖÐ¶Ï¼Ó1£¬µ±´ïµ½ËÙ¶Èµ÷½ÚÖÜÆÚÊ±£¬½øÐÐËÙ¶ÈPIµ÷½Ú

//¶¨ÒåPIµ÷½ÚÆ÷µÄ²ÎÊý¼°Êä³öÏÞ·ùÖµ
volatile float Isdref=0, IsdKp=2, IsdKi=15, IsdLimit = 50;  //isd PIµ÷½ÚÆ÷
volatile float Isqref=1, IsqKp=2, IsqKi=15, IsqLimit = 50;  //isqPIµ÷½ÚÆ÷
volatile float Speedref=0.025, SpeedKp=0.02, SpeedKi=0.1, SpeedLimit=2.0; //ËÙ¶ÈPIµ÷½ÚÆ÷
volatile float Speedgive_pu=0.05;  //±äÁ¿£¬ÓÃÀ´´æ´¢ËÙ¶ÈÐ±ÆÂº¯ÊýµÄÄ¿±êÖµ£¬ÕâÀïËÙ¶È¸ø¶¨ÒÔ±êçÛ»¯ÐÎÊ½±íÊ¾
volatile float Mech_speed_w=0;   //±äÁ¿£¬»úÐµ½ÇËÙ¶È
volatile float Elec_speed_w=0;    //±äÁ¿£¬µç½ÇËÙ¶È

//ÒÔÏÂ½á¹¹Ìå±äÁ¿µÄ¶¨ÒåÓëÓÃ»§ÔÚÏàÓ¦Í·ÎÄ¼þÀïµÄ¶¨ÒåÓÐ¹Ø£¬Îª±ãÓÚÀí½â£¬¶ÁÕß¿É·­ÔÄ±¾ÊéÇ°Ãæ½éÉÜµÄÏà¹ØÎÄ¼þ
ADC_VOLT_CURRENT_GET  Volt_current = ADC_VOLT_CURRENT_GET_DEFAULTS;  //AD²ÉÑùÄ£¿é¶ÔÓ¦µÄ½á¹¹Ìå±äÁ¿
EQEP_POS_SPEED_GET  Pos_speed = EQEP_POS_SPEED_GET_DEFAULTS;  //½Ç¶ÈÓëËÙ¶È²âÁ¿Ä£¿é¶ÔÓ¦µÄ½á¹¹Ìå±äÁ¿
EPWMS  Epwm_modules = EPWMS_DEFAULTS; //ePWMÄ£¿é¶ÔÓ¦µÄ½á¹¹Ìå±äÁ¿

//×ø±ê±ä»»
CLARKE  Iabc_to_Ialphabeta = CLARKE_DEFAULTS; //Clarke±ä»»£ºµçÁ÷ia ib icÏòi¦Á i¦Â±ä»»¶ÔÓ¦µÄ½á¹¹Ìå±äÁ¿
PARK  Ialphabeta_to_Idq = PARK_DEFAULTS;   //Park±ä»»£ºµçÁ÷i¦Á i¦ÂÏòid iq±ä»»¶ÔÓ¦µÄ½á¹¹Ìå±äÁ¿
PARK  Ualphabeta_to_Udq = PARK_DEFAULTS;  //Park±ä»»£ºµçÑ¹u¦Á u¦ÂÏòud uq±ä»»¶ÔÓ¦µÄ½á¹¹Ìå±äÁ¿
IPARK  Udq_to_Ualphabeta = IPARK_DEFAULTS; //·´Park±ä»»£ºµçÑ¹ud uqÏòu¦Á u¦Â±ä»»¶ÔÓ¦µÄ½á¹¹Ìå±äÁ¿

//PIµ÷½ÚÆ÷¶ÔÓ¦µÄ½á¹¹Ìå±äÁ¿
PIFUNC ASR = PIFUNC_DEFAULTS;     //ËÙ¶ÈPIµ÷½ÚÆ÷ASR
PIFUNC A_Isd_R = PIFUNC_DEFAULTS;  //dÖáµçÁ÷PIµ÷½ÚÆ÷A_Isd_R
PIFUNC A_Isq_R = PIFUNC_DEFAULTS;  //qÖáµçÁ÷PIµ÷½ÚÆ÷A_Isq_R

//Á½µçÆ½Ê¸Á¿PWMËã·¨¶ÔÓ¦µÄ½á¹¹Ìå±äÁ¿
SVPWM_2L Svpwm = SVPWM_2L_DEFAULTS;
/*
//DlogÄ£¿é¶ÔÓ¦µÄ±äÁ¿
int16 DlogCh1 = 0;
int16 DlogCh2 = 0;
int16 DlogCh3 = 0;
int16 DlogCh4 = 0;
DLOG_4CH dlog = DLOG_4CH_DEFAULTS;
int16 Dlog_cnt=-256;
*/

//========º¯ÊýÉùÃ÷ ==============================================
//void Dlog_init(void);  //Dlog³õÊ¼»¯º¯Êý
interrupt void epwm1_timer_isr(void); //ePWM1ÖÜÆÚÖÐ¶Ï·þÎñº¯Êý
void clear_states(void); //×´Ì¬Çå³ýº¯Êý

//========Ö÷³ÌÐò==================================================
void main()
{
    InitSysCtrl(); //ÏµÍ³³õÊ¼»¯
    DINT;//¹Ø±ÕÈ«¾ÖÖÐ¶Ï
    InitPieCtrl();//³õÊ¼»¯ÖÐ¶Ï¿ØÖÆ¼Ä´æÆ÷
    IER = 0x0000;//¹Ø±ÕCPUÖÐ¶Ï
    IFR = 0x0000;//Çå³ýCPUÖÐ¶ÏÐÅºÅ
    InitPieVectTable();//³õÊ¼»¯ÖÐ¶ÏÏòÁ¿±í

    //ÑÓÊ±50ms£¬µÈ´ý¿ØÖÆ°åÉÏÆäËûÄ£¿éÍê³É³õÊ¼»¯
    DELAY_US(50000L);

    //****³õÊ¼»¯Dlog****
    //Dlog_init();

    //****ePWMÄ£¿é³õÊ¼»¯²¿·Ö****
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;  //ÔÚÅäÖÃePWMÄ£¿éÇ°ÏÈ½ûÖ¹TBCLKÊ±ÖÓ
    EDIS;

    //ÅäÖÃ ePWM1Ä£¿éµÄÖÜÆÚÖÐ¶Ï¹¦ÄÜ
    EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Ñ¡Ôñ¼ÆÊýÆ÷Öµ=0ÎªÖÐ¶ÏÊÂ¼þ
    EPwm1Regs.ETSEL.bit.INTEN = 1; //Ê¹ÄÜÏàÓ¦µÄÖÐ¶Ï
    EPwm1Regs.ETPS.bit.INTPRD = ET_1ST; //Ã¿´ÎÖÐ¶ÏÊÂ¼þ·¢ÉúÊ±¶¼²úÉúÒ»´ÎÖÐ¶ÏÇëÇó
    EPwm1Regs.ETCLR.bit.INT = 1; //ÇåÖÐ¶Ï±êÖ¾Î»
    EALLOW;
    PieVectTable.EPWM1_INT = &epwm1_timer_isr;  //ÅäÖÃÖÐ¶ÏÏòÁ¿µØÖ·
    EDIS;
    IER |= M_INT3;// Ê¹ÄÜCPU INT3Ä£¿éµÄÖÐ¶Ï¹¦ÄÜ
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1; //Ê¹ÄÜPIEÄ£¿éÖÐEPWM INTn

    //ÓÉÓÚÔÚePWM.cÎÄ¼þÖÐÉè¶¨TBCLK = SYSCLKOUT£¬ÇÒÎªÔö¼õ¼ÆÊýÄ£Ê½£¬¹ÊÈý½Ç²¨ÖÜÆÚ=2*15000*6.67ns=200us
    Epwm_modules.PeriodMax = 15000;  //Éè¶¨¼ÆÊýÆ÷µÄ×î´ó¼ÆÊýÖµ
    Epwm_modules.init(&Epwm_modules); //µ÷ÓÃePWMÄ£¿éµÄ³õÊ¼»¯º¯Êý£¬¿ªÊ¼³õÊ¼»¯

    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1; //ÅäÖÃÍê³Éºó£¬ÖØÐÂÊ¹ÄÜTBCLKÊ±ÖÓÐÅºÅ
    EDIS;

    //ÔÚÊ¸Á¿ÏµÍ³¿ªÊ¼¹¤×÷Ç°£¬Ç¿ÖÆePWM1~ePWM3Ä£¿éÊä³öÂö³åÎªµÍµçÆ½£¬±ÜÃâ¿ª¹Ø¹ÜÎó¿ªÍ¨
    EPwm1Regs.AQCSFRC.all = PWMS_ALBL;
    EPwm2Regs.AQCSFRC.all = PWMS_ALBL;
    EPwm3Regs.AQCSFRC.all = PWMS_ALBL;

    //****ADCÄ£¿é³õÊ¼»¯****
    Volt_current.init(&Volt_current); //µ÷ÓÃADCÄ£¿é³õÊ¼»¯º¯Êý

    //****eQEPÄ£¿é³õÊ¼»¯****
    Pos_speed.init(&Pos_speed); //µ÷ÓÃeQEPÄ£¿é³õÊ¼»¯º¯Êý

    //****³õÊ¼»¯µ÷½ÚÆ÷****
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

    //****¿ªÊ¼¹¤×÷****
    while(Enable_flag==0); //µÈ´ý£¬Ö±µ½Enable_flag=1Ê±¿ªÊ¼ÏòÏÂÖ´ÐÐ£¬µ÷ÊÔÊ±¿ÉÖ±½ÓÍ¨¹ýCCSÉè¶¨Enable_flagµÄÖµ

    EINT; //¿ªCPUÖÐ¶Ï
    ERTM;

    //ËÀÑ­»·
    while(1)
    {
        if(Enable_flag==0) //Èç¹ûÔÚÔËÐÐ¹ý³ÌÖÐ£¬Enable_flag±»ÇåÁã£¬ÄÇÃ´Ç¿ÖÆ¸÷¸öePWMÄ£¿éÊä³öÎªµÍµçÆ½
        {
            EPwm1Regs.AQCSFRC.all = PWMS_ALBL;
            EPwm2Regs.AQCSFRC.all = PWMS_ALBL;
            EPwm3Regs.AQCSFRC.all = PWMS_ALBL;
            clear_states();
        }
        else //Õý³£ÔËÐÐÊ±£¬½ûÖ¹ePWMÄ£¿éµÄÇ¿ÖÆ¹¦ÄÜ
        {
            EPwm1Regs.AQCSFRC.all = PWMS_FRC_DISABLE;
            EPwm2Regs.AQCSFRC.all = PWMS_FRC_DISABLE;
            EPwm3Regs.AQCSFRC.all = PWMS_FRC_DISABLE;
        }
    }
}

//==============================================================
//ÖÐ¶Ï·þÎñº¯Êý
//==============================================================
//**********************************
/*
  @ Description: ePWM1ÖÜÆÚÖÐ¶Ï·þÎñº¯Êý
  @ Param
  @ Return
*/
//**********************************
void epwm1_timer_isr()
{
    //²ÉÑùµçÑ¹µçÁ÷
    Volt_current.read(&Volt_current);

    //½«ABC×ø±êÏµµÄµçÁ÷±ä»»µ½Alpha Beta ×ø±êÏµ£¬Clarke±ä»»
    Iabc_to_Ialphabeta.As = Volt_current.Ia;
    Iabc_to_Ialphabeta.Bs = Volt_current.Ib;
    Iabc_to_Ialphabeta.calc(&Iabc_to_Ialphabeta);

    //----¿ªÊ¼¶Ô×ª×Ó½øÐÐ³õÊ¼¶¨Î»-----------------------------------------------------
    /*Èç¹û×ª×Ó´Å³¡½¨Á¢Íê³É£¬¿ªÊ¼×ª×Ó¶¨Î»£¬ÓÉÓÚÓÀ´ÅÍ¬²½µç»ú×ª×Ó´Å³¡ÓÉÓÀ´ÅÌå½¨Á¢£¬LiCi_OK_flagÊ¼ÖÕÎª1¡£ÔÚµçÀø´ÅÍ¬²½µç»úµ÷ËÙ¹ý³ÌÖÐ£¬¿ÉÍ¨¹ý´ËÎ»ÅÐ¶Ï×ª×Ó´Å³¡ÊÇ·ñ½¨Á¢Íê³É¡£*/
    if(LiCi_OK_flag==1)
    {
        if( LockRotor_flag ==1 ) //×ª×Ó¶¨Î»¹ý³Ì
        {
             //µçÁ÷Park±ä»»
            Ialphabeta_to_Idq.Alpha=Iabc_to_Ialphabeta.Alpha;
            Ialphabeta_to_Idq.Beta =Iabc_to_Ialphabeta.Beta;
            Ialphabeta_to_Idq.Cos=1;
            Ialphabeta_to_Idq.Sin=0;
            Ialphabeta_to_Idq.calc(&Ialphabeta_to_Idq);

            //×ª×Ó¶¨Î»ÐèÒª¸ø¶¨¦Á ¦ÂÖáµçÁ÷£¬ÕâÀï½«Ðý×ª±ä»»½ÇÉè¶¨Îª0£¬¼´¿ÉÖ±½Ó¸ø¶¨d qÖáµçÁ÷
            //¸ø¶¨dÖáµçÁ÷£¬²¢½øÐÐµ÷½Ú
            A_Isd_R.Give = 1.0; //µ¥Î»A
            A_Isd_R.Feedback=Ialphabeta_to_Idq.Ds;
            A_Isd_R.Kp=IsdKp;
            A_Isd_R.Ki=IsdKi;
            A_Isd_R.OutMax = IsdLimit;
            A_Isd_R.OutMin =-IsdLimit;
            A_Isd_R.calc(&A_Isd_R);

            IsqKp=IsdKp;
            IsqKi=IsdKi;

               //¸ø¶¨qÖáµçÁ÷£¬²¢½øÐÐµ÷½Ú
             A_Isq_R.Give = 0;
             A_Isq_R.Feedback=Ialphabeta_to_Idq.Qs;
             A_Isq_R.Kp=IsqKp;
             A_Isq_R.Ki=IsqKi;
             A_Isq_R.OutMax = IsqLimit;
             A_Isq_R.OutMin =-IsqLimit;
             A_Isq_R.calc(&A_Isq_R);

               //µçÑ¹Ç°À¡
             Udq_to_Ualphabeta.Ds=A_Isd_R.Output;
             Udq_to_Ualphabeta.Qs=A_Isq_R.Output;
             Udq_to_Ualphabeta.Cos=1;
             Udq_to_Ualphabeta.Sin=0;
             Udq_to_Ualphabeta.calc(&Udq_to_Ualphabeta);

            //       Time_LockRotor++;//************************************************************************************???
             LockRotor_OK_flag=0;
        }
        else if(LockRotor_OK_flag==0)  //×ª×Ó³õÊ¼¶¨Î»¹ý³Ì½áÊø
        {
            LockRotor_OK_flag=1;  //×ª×Ó¶¨Î»½áÊøºó£¬½«´ËÎ»ÖÃ1
            EQep2Regs.QEPCTL.bit.SWI=1; //×ª×Ó¶¨Î»¹ý³Ì±àÂëÆ÷½«×ª¶¯£¬ÕâÀïÔÚ¶¨Î»½áÊøºó¶ÔeQEPÄ£¿éÖØÐÂ³õÊ¼»¯
        }
    }
    //----×ª×Ó¶¨Î»½áÊø--------------------------------------------------------

    //----Æô¶¯µç»ú£¬²¢½øÐÐÊ¸Á¿±Õ»·¿ØÖÆËã·¨µÄÊµÏÖ-----------------------------------
    if(LockRotor_OK_flag==1)  //±£Ö¤ÔÚ×ª×Ó¶¨Î»½áÊøºó£¬²Å½øÐÐÊ¸Á¿±Õ»·¿ØÖÆËã·¨
    {
        //ËÙ¶È¸ø¶¨£¬Ð±ÆÂº¯Êý
        if(Time_speed_cnt==100) //100*200us=20000us=20ms
        {
         //°ÑËÙ¶È¸ø¶¨ÏÞ¶¨ÔÚ¶î¶¨×ªËÙÄÚ£¬Ö§³ÖÕý·´×ª
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

        Pos_speed.calc(&Pos_speed); //¶ÁÈ¡µ±Ç°×ªËÙ

        //×ªËÙµ÷½ÚPI
        ASR.Give = Speedref * MaxRPM;  //ËÙ¶È¸ø¶¨******************************************************************************¸ø¶¨ËÙ¶È
        ASR.Feedback = Pos_speed.Speed_Mr_Rpm; //ËÙ¶È·´À¡
        ASR.Kp = SpeedKp;
        ASR.Ki = SpeedKi;
        ASR.OutMax = SpeedLimit;
        ASR.OutMin =-SpeedLimit;
        ASR.calc(&ASR);

        Time_speed_cnt = 0; //¶Ô¼ÆÊýÆ÷ÇåÁã£¬Ëæºó½øÈëÏÂÒ»¸ö¼ÆÊýÖÜÆÚ
        }
        else
        { Time_speed_cnt++; }

        //¶ÁÈ¡dÖáÓë¦Á ÖáÖ®¼äµÄ¼Ð½Ç
        Pos_speed.calc(&Pos_speed);
        Pos_speed.ElecTheta = Pos_speed.ElecTheta * PI2; //ÔÚeQEP½Ç¶È²âÁ¿º¯ÊýÀï£¬Ò»ÖÜ½Ç¶È·¶Î§¶ÔÓ¦0~1£¬ÕâÀï½«Æä»¯Îª0~2pi
        if(Pos_speed.ElecTheta>PI)
        { Pos_speed.ElecTheta-=PI2; }

        //½«¦Á ¦Â×ø±êÏµÏÂµÄ×ÓµçÁ÷×ª»»µ½ d q×ø±êÏµ£¬Park±ä»»
        Ialphabeta_to_Idq.Alpha = Iabc_to_Ialphabeta.Alpha;
        Ialphabeta_to_Idq.Beta =Iabc_to_Ialphabeta.Beta;
        Ialphabeta_to_Idq.Cos = cos(Pos_speed.ElecTheta);
        Ialphabeta_to_Idq.Sin = sin(Pos_speed.ElecTheta);
        Ialphabeta_to_Idq.calc(&Ialphabeta_to_Idq);

        //Isdµ÷½ÚPI
        A_Isd_R.Give = 0; //²ÉÓÃisd=0¿ØÖÆ²ßÂÔ
        A_Isd_R.Feedback =Ialphabeta_to_Idq.Ds;
        A_Isd_R.Kp =IsdKp;
        A_Isd_R.Ki =IsdKi;
        A_Isd_R.OutMax = IsdLimit;
        A_Isd_R.OutMin =-IsdLimit;
        A_Isd_R.calc(&A_Isd_R);

        IsqKp=IsdKp;
        IsqKi=IsdKi;

        //Isqµ÷½ÚPI
        A_Isq_R.Give = ASR.Output; //×ª¾ØµçÁ÷µÄ¸ø¶¨Öµ = ×ªËÙPIµ÷½ÚÆ÷µÄÊä³ö
        A_Isq_R.Feedback =Ialphabeta_to_Idq.Qs;
        A_Isq_R.Kp =IsqKp;
        A_Isq_R.Ki =IsqKi;
        A_Isq_R.OutMax = IsqLimit;
        A_Isq_R.OutMin =-IsqLimit;
        A_Isq_R.calc(&A_Isq_R);

        //µçÑ¹Ç°À¡µ¥Ôª£¬²¢½«d q×ø±êÏµÏÂµÄµçÑ¹¸ø¶¨×ª»»µ½¦Á ¦Â×ø±êÏµ
        Mech_speed_w = Pos_speed.Speed_Mr_Rpm * PI2 / 60; //»úÐµ½ÇËÙ¶È
        Elec_speed_w = Mech_speed_w * Pos_speed.PolePairs; //µç½ÇËÙ¶È
        Udq_to_Ualphabeta.Ds =A_Isd_R.Output- Ialphabeta_to_Idq.Qs*Elec_speed_w*Ld;
        Udq_to_Ualphabeta.Qs =A_Isq_R.Output+ Ialphabeta_to_Idq.Qs*Rs+KeSha*Elec_speed_w;
        Udq_to_Ualphabeta.Cos = cos(Pos_speed.ElecTheta);
        Udq_to_Ualphabeta.Sin = sin(Pos_speed.ElecTheta);
        Udq_to_Ualphabeta.calc(&Udq_to_Ualphabeta);
}

    //----Á½µçÆ½Äæ±äÆ÷µÄ¿ØÖÆ-----------------------------------------------------------
    //Á½µçÆ½SVPWMËã·¨
     Svpwm.Ualpha = Udq_to_Ualphabeta.Alpha; //µçÑ¹Ç°À¡µ¥ÔªµÄÊä³öu¦Á
     Svpwm.Ubeta  = Udq_to_Ualphabeta.Beta;  //µçÑ¹Ç°À¡µ¥ÔªµÄÊä³öu ¦Â
     Svpwm.Vdc = Volt_current.Vdc;  //Í¨¹ýADÄ£¿é²âÁ¿µÄÖ±Á÷Ä¸ÏßµçÑ¹
     Svpwm.calc(&Svpwm);

    //Ê¹ÓÃePWMÄ£¿éÊä³öÏàÓ¦µÄPWMÂö³å
     Epwm_modules.Duty1A = Svpwm.Tcmpa;
     Epwm_modules.Duty2A = Svpwm.Tcmpb;
     Epwm_modules.Duty3A = Svpwm.Tcmpc;
     Epwm_modules.update(&Epwm_modules);
    //----Äæ±äÆ÷¿ØÖÆËã·¨Íê³É-----------------------------------------------------------

    //----½«±äÁ¿²¨ÐÎ½øÐÐÁ¿»¯£¬ÅäºÏCCSµÄGraph¹¦ÄÜ½øÐÐÏÔÊ¾-----------------------------------------
    //  Dlog_cnt+=1;
    //  if(Dlog_cnt==257){Dlog_cnt=-256;}
    //  DlogCh1 = (int16) (Dlog_cnt);
    //  DlogCh2 = (int16) (Dlog_cnt);
    //  DlogCh3 = (int16) ( ASR.Give / MaxRPM*512 );
    //  DlogCh4 = (int16) ( ASR.Feedback / MaxRPM*512 );
    // dlog.update(&dlog);

    EPwm1Regs.ETCLR.bit.INT = 1; //Çå³ýÖÐ¶Ï±êÖ¾Î»
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

//======== º¯Êý¶¨Òå===========================
//**********************************
/*
  @ Description: ×´Ì¬¸´Î»×Óº¯Êý
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
  @ Description: Dlog³õÊ¼»¯×Óº¯Êý
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
