//***************************************************/
//�ļ�����SVPWM.c
//���ܣ�����28335�ڲ�PWMģ������SVPWM��������ļ�
//˵����������Ϣ���ýṹ�壬ʹ��ʱ�ı�ṹ��ָ�뼴�ɸı������źš�
//     InitSvpwm���������ṩPWMģ���ʼ���Լ���ӦPIE�жϵ����á�
//     ͨ��park��任�õ���ֹƽ������ϵ�µĵ�ѹ�źš�
//     ��PWM��ʱ�������ж��и��±Ƚ�����ֵ����ÿ��PWM���ڸ���һ��
//****************************************************/

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "math.h"
#include "float.h"

extern Uint16 RamfuncsRunStart;
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;

//=========================================================
#define DBG_DATA_ENABLE		1 // 0

#if DBG_DATA_ENABLE
	#define DBG_DATA_BUFF_SIZE	500
	int16 DebugDataM[DBG_DATA_BUFF_SIZE] = {0};
	int16 DebugDataN[DBG_DATA_BUFF_SIZE] = {0};
	int16 DebugDataP[DBG_DATA_BUFF_SIZE] = {0};
	int16 DebugDataQ[DBG_DATA_BUFF_SIZE] = {0};
#endif
	
typedef struct
{
   float ds;              // ��ֹƽ������ϵ�µ�ѹ�ź�
   float qs;
   float ang;             // �����Ƕ� �����Ƕ�=��е�Ƕ�*������
   float de;              // ��ת����ϵ�µ�ѹ�ź�
   float qe;
}IPARK;
  IPARK ipark1={0,0,0,0.3,0.4};
//  IPARK *v=&ipark1;       //�ı�˴��ṹ��ָ��ı�����

void InitSvpwm(void);
void InitEPwm1(void);
void InitEPwm2(void);
void InitEPwm3(void);
interrupt void epwm1_isr(void);
void ipark(IPARK *v);
void svgen(IPARK *v);

#define PRD  7500                // PWM���ڼĴ���
#define PI 3.1415926
float tmr1,tmr2,tmr3;

void main(void)
{
	float test1 = 0.1;
	float test2 = 1.2;
	float test3 = 6.6;


#if DBG_DATA_ENABLE
	int16 indexd = 0;
	for (indexd=0; indexd<DBG_DATA_BUFF_SIZE; indexd++)
	{
		DebugDataM[indexd] = 0;
		DebugDataN[indexd] = 0;
		DebugDataP[indexd] = 0;
		DebugDataQ[indexd] = 0;
	}
#endif

	test3 = 3.15 * test1;
	test3 = test1 * test2;

	InitSysCtrl();

	DINT;
	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;

	InitPieVectTable();

	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);			//Flash operation<F28335.cmd>

	InitFlash();	

	InitSvpwm();

	for(;;)
	{
	   asm("          NOP");
	}

}

void InitSvpwm(void)
{  
   InitEPwm1Gpio();
   InitEPwm2Gpio();
   InitEPwm3Gpio();

   EALLOW; 
   PieVectTable.EPWM1_INT = &epwm1_isr;
  
   EDIS; 

   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;
   EDIS;

   InitEPwm1();
   InitEPwm2();
   InitEPwm3();

   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
   EDIS;

   IER |= M_INT3;

// ʹ���ж� EPWM INT1 λ��PIE�жϷ���3.1
   PieCtrlRegs.PIEIER3.bit.INTx1 = 1;

   EINT; 
   ERTM;
}

interrupt void epwm1_isr(void)
{
	// ���� CMPA �� CMPB �Ĵ���ֵ
	svgen(&ipark1);
	EPwm1Regs.CMPA.half.CMPA=tmr1;
	EPwm2Regs.CMPA.half.CMPA=tmr2;
	EPwm3Regs.CMPA.half.CMPA=tmr3;
	EPwm1Regs.CMPB=tmr1;
	EPwm2Regs.CMPB=tmr2;
	EPwm3Regs.CMPB=tmr3;

	// ����жϱ�־
	EPwm1Regs.ETCLR.bit.INT = 1;

	// ����ж���Ӧ
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}


void ipark(IPARK *v)
{ 
	float  ang;
	ang=(v->ang/360)*2*PI;                    //�Ƕ�ת��Ϊ����
	v->ds=v->de*cos(ang)-v->qe*sin(ang);      //�õ���ֹƽ������ϵ��d���ѹ
	v->qs=v->qe*cos(ang)+v->de*sin(ang);      //�õ���ֹƽ������ϵ��q���ѹ
}

void svgen(IPARK *v)
{
#if DBG_DATA_ENABLE
	static int16 indexsg = 0;
#endif

   float Va,Vb,Vc,t1,t2,Ta,Tb,Tc;
   Uint32 sector=0;                                               // sector=a+2b+4c ����״̬��ʾ ע�⣺setor��ֵ1~6����������˳���Ӧ
   ipark(v);
   Va=v->qs;                                                      // Va = Uq
   Vb=(-0.5) * v->qs + (0.8660254) * v->ds;                       // Vb = 1/2*(sqrt(3)*Ud - Uq)         sqrt(3)/2=0.866
   Vc=(-0.5) * v->qs - (0.8660254) * v->ds;                       // Vc = -1/2*(sqrt(3)Ud + Uq)
   if(Va>0.0000001)                                               // �ж������ĸ�����        
   sector=1;                                                      // Va>0 �� a=1������a=0
   if(Vb>0.0000001)                                               // 
   sector=sector+2;                                               // Vb>0 �� b=1������b=0
   if(Vc>0.0000001)                                               //
   sector=sector+4;                                               // Vc>0 �� c=1; ����c=0
   Va=v->qs;                                                     
   Vb=(-0.5) * v->qs + (0.8660254) * v->ds;                      
   Vc=(-0.5) * v->qs - (0.8660254) * v->ds;  

   switch(sector){
     case 1:                               //sector==1 ��Ӧ����II
       t1=Vc;
       t2=Vb;
       Tb=(0.25)*(1-t1-t2);
       Ta=Tb+(0.5)*t1;
       Tc=Ta+(0.5)*t2;
	   break;
     case 2:                               //sector==2 ��Ӧ����VI
       t1=Vb;
       t2=-Va;
       Ta=(0.25)*(1-t1-t2);
       Tc=Ta+(0.5)*t1;
       Tb=Tc+(0.5)*t2;
       break;
     case 3:                               //sector==3 ��Ӧ����I
       t1=-Vc;
       t2=Va;
       Ta=(0.25)*(1-t1-t2);
       Tb=Ta+(0.5)*t1;
       Tc=Tb+(0.5)*t2;
       break;
     case 4:                               //sector==4 ��Ӧ����IV
       t1=-Va;
       t2=Vc;
       Tc=(0.25)*(1-t1-t2);
       Tb=Tc+(0.5)*t1;
       Ta=Tb+(0.5)*t2;
       break;
     case 5:                               //sector==5 ��Ӧ����III
       t1=Va;
       t2=-Vb;
       Tb=(0.25)*(1-t1-t2);
       Tc=Tb+(0.5)*t1;
       Ta=Tc+(0.5)*t2;
       break;
     case 6:                              //sector==6 ��Ӧ����V   
       t1=-Vb;
       t2=-Vc;
       Tc=(0.25)*(1-t1-t2);
       Ta=Tc+(0.5)*t1;
       Tb=Ta+(0.5)*t2;
       break;
     default:                             //sector=0��sector=7ʱ���� 
       Ta=0.5;
       Tb=0.5;
       Tc=0.5;
   }
   tmr1=Ta*PRD;
   tmr2=Tb*PRD;
   tmr3=Tc*PRD;

#if DBG_DATA_ENABLE
	if (indexsg < DBG_DATA_BUFF_SIZE)
	{
		DebugDataM[indexsg] = tmr1;
		DebugDataN[indexsg] = tmr2;
		DebugDataP[indexsg] = tmr3;
		indexsg++;
	}
	else
	{
		indexsg = 0;
	}
#endif

}
void InitEPwm1()
{ 
   // ����ʱ��
   EPwm1Regs.TBCTL.bit.CTRMODE = 0x2;             // ��������ģʽ
   EPwm1Regs.TBPRD = PRD;                         // ��������
   EPwm1Regs.TBCTL.bit.PHSEN = 0x0;               // ������λ����ͬ��
   EPwm1Regs.TBPHS.half.TBPHS = 0x0000;           // ��λ��ֵ
   EPwm1Regs.TBCTR = 0x0000;                      // ������ֵ
   EPwm1Regs.TBCTL.bit.HSPCLKDIV = 0x1;           // TBCLK = SYSCLKOUT / (HSPCLKDIV �� CLKDIV)
   EPwm1Regs.TBCTL.bit.CLKDIV = 0x1;

   // ���ñȽϼĴ���
   EPwm1Regs.CMPCTL.bit.SHDWAMODE = 0x0;          //ʹ����Ӱ�Ĵ���       
   EPwm1Regs.CMPCTL.bit.SHDWBMODE = 0x0;
   EPwm1Regs.CMPCTL.bit.LOADAMODE = 0x0;          //������ֵΪ0ʱ���±Ƚ���ֵ
   EPwm1Regs.CMPCTL.bit.LOADBMODE = 0x0;

   // ���ñȽ�����ֵ
   EPwm1Regs.CMPA.half.CMPA = 1875;               
   EPwm1Regs.CMPB = 1875;                         

   // ģʽ�趨
   EPwm1Regs.AQCTLA.bit.ZRO = 0x1;               // ����0ʱ�����
   EPwm1Regs.AQCTLA.bit.CAU = 0x3;               // ����ֵ=�Ƚ�ֵʱ���ȡ��
   EPwm1Regs.AQCTLB.bit.ZRO = 0x2;               // ����0ʱ�����
   EPwm1Regs.AQCTLB.bit.CBU = 0x3;               // ����ֵ=�Ƚ�ֵʱ���ȡ��

   // �����ж�
   EPwm1Regs.ETSEL.bit.INTSEL = 0x1;             // ����ֵ��0�����¼�
   EPwm1Regs.ETSEL.bit.INTEN = 1;                // ʹ���ж�
   EPwm1Regs.ETPS.bit.INTPRD = 0x1;              // ÿ���¼������������ж�
}


void InitEPwm2()
{
   EPwm2Regs.TBCTL.bit.CTRMODE = 0x2;        
   EPwm2Regs.TBPRD = PRD;                  
   EPwm2Regs.TBCTL.bit.PHSEN = 0x0;          
   EPwm2Regs.TBPHS.half.TBPHS = 0x0000;        
   EPwm2Regs.TBCTR = 0x0000;                  
   EPwm2Regs.TBCTL.bit.HSPCLKDIV = 0x1;     
   EPwm2Regs.TBCTL.bit.CLKDIV = 0x1;
   EPwm2Regs.CMPCTL.bit.SHDWAMODE = 0x0;          
   EPwm2Regs.CMPCTL.bit.SHDWBMODE = 0x0;
   EPwm2Regs.CMPCTL.bit.LOADAMODE = 0x0;    
   EPwm2Regs.CMPCTL.bit.LOADBMODE = 0x0;
   EPwm2Regs.CMPA.half.CMPA = 1875;               
   EPwm2Regs.CMPB = 1875;                         
   EPwm2Regs.AQCTLA.bit.ZRO = 0x1;                        
   EPwm2Regs.AQCTLA.bit.CAU = 0x3;                
   EPwm2Regs.AQCTLB.bit.ZRO = 0x2;             
   EPwm2Regs.AQCTLB.bit.CBU = 0x3;                     
   EPwm2Regs.ETSEL.bit.INTEN = 0;                 //�����ж�             
            
}

void InitEPwm3(void)
{
   EPwm3Regs.TBCTL.bit.CTRMODE = 0x2;          
   EPwm3Regs.TBPRD = PRD;                      
   EPwm3Regs.TBCTL.bit.PHSEN = 0x0;             
   EPwm3Regs.TBPHS.half.TBPHS = 0x0000;        
   EPwm3Regs.TBCTR = 0x0000;                    
   EPwm3Regs.TBCTL.bit.HSPCLKDIV = 0x1;           
   EPwm3Regs.TBCTL.bit.CLKDIV = 0x1;
   EPwm3Regs.CMPCTL.bit.SHDWAMODE = 0x0;                
   EPwm3Regs.CMPCTL.bit.SHDWBMODE = 0x0;
   EPwm3Regs.CMPCTL.bit.LOADAMODE = 0x0;          
   EPwm3Regs.CMPCTL.bit.LOADBMODE = 0x0;
   EPwm3Regs.CMPA.half.CMPA = 1875;               
   EPwm3Regs.CMPB = 1875;                         
   EPwm3Regs.AQCTLA.bit.ZRO = 0x1;                
   EPwm3Regs.AQCTLA.bit.CAU = 0x3;                 
   EPwm3Regs.AQCTLB.bit.ZRO = 0x2;                 
   EPwm3Regs.AQCTLB.bit.CBU = 0x3;                     
   EPwm3Regs.ETSEL.bit.INTEN = 0;                           
}

void MemCopy(unsigned int* uPSourceAddr, unsigned int* uPSourceEndAddr, unsigned int* uPDestAddr)
{
    while(uPSourceAddr < uPSourceEndAddr)
    { 
        *uPDestAddr++ = *uPSourceAddr++;
    }
    return;    
}


