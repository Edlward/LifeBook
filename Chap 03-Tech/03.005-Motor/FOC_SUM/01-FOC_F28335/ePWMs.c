/*
 * zhs_ePWMs.c
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */
#include "DSP2833x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include <math.h>
#include "ePWMs.h"
#define PWM1_INT_ENABLE  1
#define PWM2_INT_ENABLE  1
#define PWM3_INT_ENABLE  1
#define PWM4_INT_ENABLE  1
#define PWM5_INT_ENABLE  1
#define PWM6_INT_ENABLE  1
#define DBTIME_FED  300 //3us when TBCLK=SYSCLKOUT
#define DBTIME_RED  300
void ePWMs_Init(EPWMS *p)
{
  InitEPwm1Gpio();
 EPwm1Regs.TBPRD=p->PeriodMax; //(the period is PeriodMax * 2 * TBCLK)
 EPwm1Regs.TBPHS.half.TBPHS=0x0000;//phase is 0
 EPwm1Regs.TBCTR=0x0000; // clear the counter

//set the compare value
 EPwm1Regs.CMPA.half.CMPA=p->PeriodMax;//set compare A
 EPwm1Regs.CMPB=0;// set compare B

// set counter mode
 EPwm1Regs.TBCTL.bit.CTRMODE=TB_COUNT_UPDOWN;// up and down counter
 EPwm1Regs.TBCTL.bit.PHSEN=TB_DISABLE;// enable phase*******************************************************?
 EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;//在CTR=0时，产生同步信号
 EPwm1Regs.TBCTL.bit.HSPCLKDIV=0;//1/clock ratio to SYSCLKOUT
 EPwm1Regs.TBCTL.bit.CLKDIV=0;// TBCLK = SYSCLKOUT/(CLKDIV*HSPCLKDIV)

//setup shadowing
 EPwm1Regs.CMPCTL.bit.SHDWAMODE=CC_SHADOW;//enable shadow CMPA
 EPwm1Regs.CMPCTL.bit.SHDWBMODE=CC_SHADOW;//enable shadow CMPB
 EPwm1Regs.CMPCTL.bit.LOADAMODE=CC_CTR_ZERO;//load on zero
 EPwm1Regs.CMPCTL.bit.LOADBMODE=CC_CTR_ZERO;

//set actions
 EPwm1Regs.AQCTLA.bit.CAU=AQ_SET;//set PWM1A on event A, up count
 EPwm1Regs.AQCTLA.bit.CAD=AQ_CLEAR;//clear PWM1A on event A, down count

 EPwm1Regs.AQCTLB.bit.CBU=AQ_CLEAR;// clear PWM1B on event B, up count
 EPwm1Regs.AQCTLB.bit.CBD=AQ_SET;// set PWM1B on event B, down count

  // Setup Deadband
 EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;//both epwmA and epwmB are enbale
 EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;// A is A and B is inversed.
 EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;// ePWMA is the source for both falling and rising delay
 EPwm1Regs.DBRED = DBTIME_FED;// Rising edge delay time
 EPwm1Regs.DBFED = DBTIME_FED;// Falling edge delay time

InitEPwm2Gpio();
 //set TBCLK
 EPwm2Regs.TBPRD=p->PeriodMax; //(the period is PeriodMax * 2 * TBCLK)
 EPwm2Regs.TBPHS.half.TBPHS=0x0000;//phase is 0
 EPwm2Regs.TBCTR=0x0000;// clear the counter

//set the compare value
 EPwm2Regs.CMPA.half.CMPA=p->PeriodMax;//set compare A
 EPwm2Regs.CMPB=0;// set compare B

// set counter mode
 EPwm2Regs.TBCTL.bit.CTRMODE=TB_COUNT_UPDOWN;// up and down counter
 EPwm2Regs.TBCTL.bit.PHSEN=TB_ENABLE;// enable phase
 EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;//接收上个模块产生的同步信号
 EPwm2Regs.TBCTL.bit.HSPCLKDIV=0;//1/clock ratio to SYSCLKOUT
 EPwm2Regs.TBCTL.bit.CLKDIV=0;//

//setup shadowing
 EPwm2Regs.CMPCTL.bit.SHDWAMODE=CC_SHADOW;//enable shadow CMPA
 EPwm2Regs.CMPCTL.bit.SHDWBMODE=CC_SHADOW;//enable shadow CMPB
 EPwm2Regs.CMPCTL.bit.LOADAMODE=CC_CTR_ZERO;//load on zero
 EPwm2Regs.CMPCTL.bit.LOADBMODE=CC_CTR_ZERO;

//set actions
 EPwm2Regs.AQCTLA.bit.CAU=AQ_SET;//set PWM1A on event A, up count
 EPwm2Regs.AQCTLA.bit.CAD=AQ_CLEAR;//clear PWM1A on event B, down count

 EPwm2Regs.AQCTLB.bit.CBU=AQ_CLEAR;// clear PWM1B on event B, up count
 EPwm2Regs.AQCTLB.bit.CBD=AQ_SET;// set PWM1B on event B, down count

  // Setup Deadband
 EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
 EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
 EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
 EPwm2Regs.DBRED = DBTIME_RED;
 EPwm2Regs.DBFED = DBTIME_FED;


 //setup Interrupt
  // EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
  // EPwm2Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
  // EPwm2Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event

InitEPwm3Gpio();
 //set TBCLK
 EPwm3Regs.TBPRD=p->PeriodMax;
 EPwm3Regs.TBPHS.half.TBPHS=0x0000;//phase is 0
 EPwm3Regs.TBCTR=0x0000;// clear the counter

//set the compare value
 EPwm3Regs.CMPA.half.CMPA=p->PeriodMax;//set compare A
 EPwm3Regs.CMPB=0;// set compare B

// set counter mode
 EPwm3Regs.TBCTL.bit.CTRMODE=TB_COUNT_UPDOWN;// up and down counter
 EPwm3Regs.TBCTL.bit.PHSEN=TB_ENABLE;// disable phase
 EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;//接收上个模块产生的同步信号
 EPwm3Regs.TBCTL.bit.HSPCLKDIV=0;//1/clock ratio to SYSCLKOUT
 EPwm3Regs.TBCTL.bit.CLKDIV=0;// TBCLK = SYSCLKOUT/128  0.853us

//setup shadowing
 EPwm3Regs.CMPCTL.bit.SHDWAMODE=CC_SHADOW;//enable shadow CMPA
 EPwm3Regs.CMPCTL.bit.SHDWBMODE=CC_SHADOW;//enable shadow CMPB
 EPwm3Regs.CMPCTL.bit.LOADAMODE=CC_CTR_ZERO;//load on zero
 EPwm3Regs.CMPCTL.bit.LOADBMODE=CC_CTR_ZERO;

//set actions
 EPwm3Regs.AQCTLA.bit.CAU=AQ_SET;//set PWM1A on event A, up count
 EPwm3Regs.AQCTLA.bit.CAD=AQ_CLEAR;//clear PWM1A on event B, down count

 EPwm3Regs.AQCTLB.bit.CBU=AQ_CLEAR;// clear PWM1B on event B, up count
 EPwm3Regs.AQCTLB.bit.CBD=AQ_SET;// set PWM1B on event B, down count

  // Setup Deadband
 EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
 EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
 EPwm3Regs.DBCTL.bit.IN_MODE = DBA_ALL;
 EPwm3Regs.DBRED = DBTIME_RED;
 EPwm3Regs.DBFED = DBTIME_FED;


 //setup Interrupt
  // EPwm3Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
  // EPwm3Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
  // EPwm3Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event
}

void ePWMs_Update(EPWMS *p)
{
 EPwm1Regs.CMPA.half.CMPA = (int)(2.0 * p->PeriodMax * p->Duty1A);
 EPwm2Regs.CMPA.half.CMPA = (int)(2.0 * p->PeriodMax * p->Duty2A);
 EPwm3Regs.CMPA.half.CMPA = (int)(2.0 * p->PeriodMax * p->Duty3A);

/*
 EPwm1Regs.CMPA.half.CMPA = 5000;
 EPwm2Regs.CMPA.half.CMPA = 5000;
 EPwm3Regs.CMPA.half.CMPA = 5000;
*/

}


