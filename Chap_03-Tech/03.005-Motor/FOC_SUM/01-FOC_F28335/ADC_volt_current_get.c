/*
 * zhs_ADC_volt_current_get.c
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */
#include "DSP2833x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include <math.h>
#include "ADC_volt_current_get.h"
#define ADC_CHANNELS 16
void ADC_volt_current_get_Init()
{

    EALLOW;
   #if (CPU_FRQ_150MHZ)     // Default - 150 MHz SYSCLKOUT
     #define ADC_MODCLK 0x3 // HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 150/(2*3)   = 25.0 MHz
   #endif
   #if (CPU_FRQ_100MHZ)
     #define ADC_MODCLK 0x2 // HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 100/(2*2)   = 25.0 MHz
   #endif
   EDIS;

  InitAdc();//this function can be found in DSP2833x_Adc.c

 //configure ADC
   EALLOW;
   SysCtrlRegs.HISPCP.all = ADC_MODCLK; // HSPCLK = SYSCLKOUT/ADC_MODCLK
   EDIS;

   AdcRegs.ADCTRL1.bit.ACQ_PS =0xf;//设置启动脉冲的宽度
   AdcRegs.ADCTRL3.bit.ADCCLKPS = 0x1;//设置采用2分频

   AdcRegs.ADCMAXCONV.bit.MAX_CONV1= ADC_CHANNELS-1;       // Setup n+1 conv's on SEQ1
   AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;          // 1 ： Cascaded mode; 0: depart mode

  AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;// enable ePWMx_SOCA tigger signal

   AdcRegs.ADCCHSELSEQ1.bit.CONV00=0x0;//ADCINA0
   AdcRegs.ADCCHSELSEQ1.bit.CONV01=0x1;//ADCINA1
   AdcRegs.ADCCHSELSEQ1.bit.CONV02=0x2;//ADCINA2
   AdcRegs.ADCCHSELSEQ1.bit.CONV03=0x3;//ADCINA3
   AdcRegs.ADCCHSELSEQ2.bit.CONV04=0x4;//ADCINA4
   AdcRegs.ADCCHSELSEQ2.bit.CONV05=0x5;//ADCINA5
   AdcRegs.ADCCHSELSEQ2.bit.CONV06=0x6;//ADCINA6
   AdcRegs.ADCCHSELSEQ2.bit.CONV07=0x7;//ADCINA7
   AdcRegs.ADCCHSELSEQ3.bit.CONV08=0x8;//ADCINB0
   AdcRegs.ADCCHSELSEQ3.bit.CONV09=0x9;//ADCINB1
   AdcRegs.ADCCHSELSEQ3.bit.CONV10=0xa;//ADCINB2
   AdcRegs.ADCCHSELSEQ3.bit.CONV11=0xb;//ADCINB3
   AdcRegs.ADCCHSELSEQ4.bit.CONV12=0xc;//ADCINB4
   AdcRegs.ADCCHSELSEQ4.bit.CONV13=0xd;//ADCINB5
   AdcRegs.ADCCHSELSEQ4.bit.CONV14=0xe;//ADCINB6
   AdcRegs.ADCCHSELSEQ4.bit.CONV15=0xf;//ADCINB7

 //AdcRegs.ADCTRL1.bit.CONT_RUN = 1;   // Setup continuous run

  // Setup ePWM1_SOCA ADC trigger signal
 EPwm1Regs.ETSEL.bit.SOCAEN = 1; // Enable SOC on A group
 EPwm1Regs.ETSEL.bit.SOCASEL = ET_CTR_ZERO;// Select SOC from CTR=ZERO
 EPwm1Regs.ETPS.bit.SOCAPRD = ET_1ST;  // Generate pulse on 1st event
 EPwm1Regs.ETCLR.bit.SOCA = 1;// Clear SOCA flag
}

void ADC_volt_current_get_Calc(ADC_VOLT_CURRENT_GET *p)
{

  //AdcRegs.ADCTRL2.bit.SOC_SEQ1=1;//if it is not continuous run , this is neccesory
  //while (AdcRegs.ADCST.bit.INT_SEQ1== 0); // Wait for the process is over
 while (AdcRegs.ADCST.bit.SEQ1_BSY == 1);

 p->Volt_channelA0= 3.0 * (AdcRegs.ADCRESULT0>>4)/4095.0;
 p->Volt_channelA1= 3.0 * (AdcRegs.ADCRESULT1>>4)/4095.0;
 p->Volt_channelA2= 3.0 * (AdcRegs.ADCRESULT2>>4)/4095.0;
 p->Volt_channelA3= 3.0 * (AdcRegs.ADCRESULT3>>4)/4095.0;
 p->Volt_channelA4= 3.0 * (AdcRegs.ADCRESULT4>>4)/4095.0;
 p->Volt_channelA5= 3.0 * (AdcRegs.ADCRESULT5>>4)/4095.0;
 p->Volt_channelA6= 3.0 * (AdcRegs.ADCRESULT6>>4)/4095.0;
 p->Volt_channelA7= 3.0 * (AdcRegs.ADCRESULT7>>4)/4095.0;

 p->Volt_channelB0= 3.0 * (AdcRegs.ADCRESULT8 >>4)/4095.0;
 p->Volt_channelB1= 3.0 * (AdcRegs.ADCRESULT9 >>4)/4095.0;
 p->Volt_channelB2= 3.0 * (AdcRegs.ADCRESULT10>>4)/4095.0;
 p->Volt_channelB3= 3.0 * (AdcRegs.ADCRESULT11>>4)/4095.0;
 p->Volt_channelB4= 3.0 * (AdcRegs.ADCRESULT12>>4)/4095.0;
 p->Volt_channelB5= 3.0 * (AdcRegs.ADCRESULT13>>4)/4095.0;
 p->Volt_channelB6= 3.0 * (AdcRegs.ADCRESULT14>>4)/4095.0;
 p->Volt_channelB7= 3.0 * (AdcRegs.ADCRESULT15>>4)/4095.0;
 p->Ia = 3.333*(p->Volt_channelA3 - 1.5);
 p->Ib = 3.333*(p->Volt_channelA4 - 1.5);
 p->Ic = -(p->Ia + p->Ib);
 p->Vdc = 133.333*p->Volt_channelA2;
 AdcRegs.ADCTRL2.bit.RST_SEQ1=1;
 AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;// clear the mark of IN_SEQ1
}



