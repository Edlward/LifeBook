/*
 * zhs_eQEP_pos_speed_get.c
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include"DSP2833x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include <math.h>
#include "eQEP_pos_speed_get.h"

//======== Definations for functions ===========================
//**********************************
/*
  @ Description:
  @ Param
  @ Return
*/
//**********************************
void eQEP_pos_speed_get_Init(EQEP_POS_SPEED_GET *p)
{/*
   #if (CPU_FRQ_150MHZ)
      EQep1Regs.QUPRD=1500000;          // Unit Timer for 100Hz at 150 MHz SYSCLKOUT
   #endif
   #if (CPU_FRQ_100MHZ)
      EQep1Regs.QUPRD=1000000;          // Unit Timer for 100Hz at 100 MHz SYSCLKOUT
   #endif

    EQep1Regs.QDECCTL.bit.QSRC=00;      // QEP quadrature count mode

    EQep1Regs.QEPCTL.bit.FREE_SOFT=2;
    EQep1Regs.QEPCTL.bit.PCRM=00;       // PCRM=00 mode - QPOSCNT reset on index event
    EQep1Regs.QEPCTL.bit.UTE=1;         // Unit Timeout Enable
    EQep1Regs.QEPCTL.bit.QCLM=1;        // Latch on unit time out
    EQep1Regs.QEPCTL.bit.QPEN=1;        // QEP enable

    EQep1Regs.QCAPCTL.bit.UPPS=5;       // 1/32 for unit position
    EQep1Regs.QCAPCTL.bit.CCPS=7;       // 1/128 for CAP clock
    EQep1Regs.QCAPCTL.bit.CEN=1;        // QEP Capture Enable

    EQep1Regs.QPOSMAX=p->Encoder_N;     // Encoder_N

    EQep1Regs.QEPCTL.bit.SWI=1;// software generate index pulse
    InitEQep1Gpio();
*/

    #if (CPU_FRQ_150MHZ)
      EQep2Regs.QUPRD=1500000;          // Unit Timer for 100Hz at 150 MHz SYSCLKOUT
   #endif
   #if (CPU_FRQ_100MHZ)
      EQep2Regs.QUPRD=1000000;          // Unit Timer for 100Hz at 100 MHz SYSCLKOUT
   #endif

    EQep2Regs.QDECCTL.bit.QSRC=00;      // QEP quadrature count mode

    EQep2Regs.QEPCTL.bit.FREE_SOFT=2;
    EQep2Regs.QEPCTL.bit.PCRM=00;       // PCRM=00 mode - QPOSCNT reset on index event
    EQep2Regs.QEPCTL.bit.UTE=1;         // Unit Timeout Enable
    EQep2Regs.QEPCTL.bit.QCLM=1;        // Latch on unit time out
    EQep2Regs.QEPCTL.bit.QPEN=1;        // QEP enable

    EQep2Regs.QCAPCTL.bit.UPPS=5;       // 1/32 for unit position
    EQep2Regs.QCAPCTL.bit.CCPS=7;       // 1/128 for CAP clock
    EQep2Regs.QCAPCTL.bit.CEN=1;        // QEP Capture Enable

    EQep2Regs.QPOSMAX=p->Encoder_N;     // Encoder_N

    EQep2Regs.QPOSINIT=EQep2Regs.QPOSMAX - p->CalibrateAngle;

    EQep2Regs.QEPCTL.bit.SWI=1;// software generate index pulse
//  InitEQep2Gpio();
                                                                                                \
     EALLOW;                       /* Enable EALLOW*/                                           \
     GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 2;  /* GPIO20 is EQep2A */                               \
     GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 2;  /* GPIO21 is EQep2B */                               \
     GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 2;  /* GPIO23 is EQep2I  */                              \
     EDIS;

}


//**********************************
/*
  @ Description:
  @ Param
  @ Return
*/
//**********************************
/*
void eQEP_pos_speed_get_Calc(EQEP_POS_SPEED_GET *p)
{
 float tmp1;
 unsigned long t2_t1;

 //Check the rotational direction
  p->DirectionQep = EQep1Regs.QEPSTS.bit.QDF;

 //Check the position counter for EQep1
  p->RawTheta = EQep1Regs.QPOSCNT + p->CalibrateAngle;
  if(p->RawTheta < 0)
    {
     p->RawTheta = p->RawTheta + EQep1Regs.QPOSMAX;
    }
  else if(p->RawTheta > EQep1Regs.QPOSMAX)
    {
     p->RawTheta = p->RawTheta - EQep1Regs.QPOSMAX;
    }

  //Compute the mechanical angle
    p->MechTheta = p->Mech_Scaler * p->RawTheta;

  //Compute the electrical angle
    p->ElecTheta = (p->PolePairs * p->MechTheta)-floor(p->PolePairs * p->MechTheta);

  // Check an index occurrence
     if (EQep1Regs.QFLG.bit.IEL == 1)
     {
        p->Index_sync_flag = 0x00F0;
        EQep1Regs.QCLR.bit.IEL=1;                   // Clear interrupt flag
     }

  // High Speed Calcultation using QEP Position counter //M法
  // Check unit Time out-event for speed calculation:
  // Unit Timer is configured for 100Hz in INIT function
  if(EQep1Regs.QFLG.bit.UTO==1)// If unit timeout (one 100Hz period)
    {
     p->Position_k =1.0 * EQep1Regs.QPOSLAT;
     if(p->DirectionQep==0) // POSCNT is counting down
       {
        if(p->Position_k > p->Position_k_1)
          { tmp1 = -(p->Encoder_N - (p->Position_k - p->Position_k_1)); }
        else
          { tmp1 = p->Position_k - p->Position_k_1;}// x2-x1 should be negative
       }
     else if(p->DirectionQep==1)    // POSCNT is counting up
       {
        if(p->Position_k < p->Position_k_1)
          { tmp1 = p->Encoder_N - (p->Position_k_1 - p->Position_k); }
        else
          { tmp1 = p->Position_k - p->Position_k_1;}// x2-x1 should be positive
       }

     if(tmp1 > p->Encoder_N)
       { p->Speed_Mr_Rpm = p->BaseRpm;  }
     else if(tmp1 < -p->Encoder_N)
       { p->Speed_Mr_Rpm = -p->BaseRpm; }
     else
       { p->Speed_Mr_Rpm = tmp1 * p->Speed_Mr_Rpm_Scaler; }

      p->Speed_Mr = p->Speed_Mr_Rpm / p->BaseRpm;

      p->Position_k_1 = p->Position_k;

      EQep1Regs.QCLR.bit.UTO=1; // Clear interrupt flag
    }


  // Low-speed computation using QEP capture counter // T法
  if(EQep1Regs.QEPSTS.bit.UPEVNT==1)
    {
     if(EQep1Regs.QEPSTS.bit.COEF==0)
       t2_t1 =  EQep1Regs.QCPRDLAT;
     else
       t2_t1 = 0xFFFF;

     if(p->DirectionQep==0)
       p->Speed_Tr_Rpm = -p->Speed_Tr_Rpm_Scaler / t2_t1;
     else
       p->Speed_Tr_Rpm =  p->Speed_Tr_Rpm_Scaler / t2_t1;

     if(p->Speed_Tr_Rpm > p->BaseRpm)
       p->Speed_Tr_Rpm = p->BaseRpm;
     else if(p->Speed_Tr_Rpm < -p->BaseRpm)
       p->Speed_Tr_Rpm = -p->BaseRpm;

     EQep1Regs.QEPSTS.all=0x88;
    }
}
*/

void eQEP_pos_speed_get_Calc(EQEP_POS_SPEED_GET *p)
{
 float tmp1;
 unsigned long t2_t1;

 //Check the rotational direction
  p->DirectionQep = EQep2Regs.QEPSTS.bit.QDF;

 //Check the position counter for EQep2
  p->RawTheta = EQep2Regs.QPOSCNT + p->CalibrateAngle;
  if(p->RawTheta < 0)
    {
     p->RawTheta = p->RawTheta + EQep2Regs.QPOSMAX;
    }
  else if(p->RawTheta > EQep2Regs.QPOSMAX)
    {
     p->RawTheta = p->RawTheta - EQep2Regs.QPOSMAX;
    }

  //Compute the mechanical angle
    p->MechTheta = p->Mech_Scaler * p->RawTheta;

  //Compute the electrical angle
    p->ElecTheta = (p->PolePairs * p->MechTheta)-floor(p->PolePairs * p->MechTheta);

  // Check an index occurrence
     if (EQep2Regs.QFLG.bit.IEL == 1)
     {
        p->Index_sync_flag = 0x00F0;
        EQep2Regs.QCLR.bit.IEL=1;                   // Clear interrupt flag
     }

  // High Speed Calcultation using QEP Position counter //M法
  // Check unit Time out-event for speed calculation:
  // Unit Timer is configured for 100Hz in INIT function
  if(EQep2Regs.QFLG.bit.UTO==1)// If unit timeout (one 100Hz period)
    {
     p->Position_k =1.0 * EQep2Regs.QPOSLAT;
     if(p->DirectionQep==0) // POSCNT is counting down
       {
        if(p->Position_k > p->Position_k_1)
          { tmp1 = -(p->Encoder_N - (p->Position_k - p->Position_k_1)); }
        else
          { tmp1 = p->Position_k - p->Position_k_1;}// x2-x1 should be negative
       }
     else if(p->DirectionQep==1)    // POSCNT is counting up
       {
        if(p->Position_k < p->Position_k_1)
          { tmp1 = p->Encoder_N - (p->Position_k_1 - p->Position_k); }
        else
          { tmp1 = p->Position_k - p->Position_k_1;}// x2-x1 should be positive
       }

     if(tmp1 > p->Encoder_N)
       { p->Speed_Mr_Rpm = p->BaseRpm;  }
     else if(tmp1 < -p->Encoder_N)
       { p->Speed_Mr_Rpm = -p->BaseRpm; }
     else
       { p->Speed_Mr_Rpm = tmp1 * p->Speed_Mr_Rpm_Scaler; }

      p->Speed_Mr = p->Speed_Mr_Rpm / p->BaseRpm;

      p->Position_k_1 = p->Position_k;

      EQep2Regs.QCLR.bit.UTO=1; // Clear interrupt flag
    }


  // Low-speed computation using QEP capture counter // T法
  if(EQep2Regs.QEPSTS.bit.UPEVNT==1)
    {
     if(EQep2Regs.QEPSTS.bit.COEF==0)
       t2_t1 =  EQep2Regs.QCPRDLAT;
     else
       t2_t1 = 0xFFFF;

     if(p->DirectionQep==0)
       p->Speed_Tr_Rpm = -p->Speed_Tr_Rpm_Scaler / t2_t1;
     else
       p->Speed_Tr_Rpm =  p->Speed_Tr_Rpm_Scaler / t2_t1;

     if(p->Speed_Tr_Rpm > p->BaseRpm)
       p->Speed_Tr_Rpm = p->BaseRpm;
     else if(p->Speed_Tr_Rpm < -p->BaseRpm)
       p->Speed_Tr_Rpm = -p->BaseRpm;

     EQep2Regs.QEPSTS.all=0x88;
    }
}


