/*
 * zhs_SVPWM_2L.c
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */
#include "DSP2833x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include <math.h>
#include "SVPWM_2L.h"

//======== Definations for functions ===========================
//**********************************
/*
  @ Description:
  @ Param
  @ Return
*/
//**********************************
void svpwm_2l_calc(SVPWM_2L *p)
{
 float temp;
 float X,Y,Z, t1,t2;
 Uint16 A,B,C,N,Sector;
 float Ta, Tb, Tc;
 float K=1.73205081;//sqrt(3)/2

 p->T=1.0;//将整个调制周期归一化处理

 X= K*p->Ubeta/p->Vdc*p->T;
 Y=(K*p->Ubeta+3*p->Ualpha)/(2*p->Vdc)*p->T;
 Z=(K*p->Ubeta-3*p->Ualpha)/(2*p->Vdc)*p->T;
//
 if(p->Ubeta>0)
   {A=1;}
 else
   {A=0;}

 if( (K*p->Ualpha - p->Ubeta)>0 )
   {B=1;}
 else
   {B=0;}

 if((-K*p->Ualpha - p->Ubeta)>0)
   {C=1;}
 else
   {C=0;}

 N=A+2*B+4*C;
//
 switch(N)
 {
case 1:{Sector=2;break;}
case 2:{Sector=6;break;}
case 3:{Sector=1;break;}
case 4:{Sector=4;break;}
case 5:{Sector=3;break;}
case 6:{Sector=5;break;}
 default:{;}
 }
 //
switch(Sector)
{
case 1: {t1=-Z; t2= X;break;}
case 2: {t1= Z; t2= Y;break;}
case 3: {t1= X; t2=-Y;break;}
case 4: {t1=-X; t2= Z;break;}
case 5: {t1=-Y; t2=-Z;break;}
case 6: {t1= Y; t2=-X;break;}
  default:{;}
}

if((t1+t2)>p->T)//对过调制情况进行调整
 {
  temp=t1+t2;
  t1=t1*p->T/temp;
  t2=t2*p->T/temp;
 }

//
 Ta=(p->T-t1-t2)/4;//作用时间分配
 Tb=Ta+t1/2;
 Tc=Tb+t2/2;

 switch(Sector)
  {
    case 1: {p->Tcmpa=Ta; p->Tcmpb=Tb; p->Tcmpc=Tc; break;}
    case 2: {p->Tcmpa=Tb; p->Tcmpb=Ta; p->Tcmpc=Tc; break;}
    case 3: {p->Tcmpa=Tc; p->Tcmpb=Ta; p->Tcmpc=Tb; break;}
    case 4: {p->Tcmpa=Tc; p->Tcmpb=Tb; p->Tcmpc=Ta; break;}
    case 5: {p->Tcmpa=Tb; p->Tcmpb=Tc; p->Tcmpc=Ta; break;}
    case 6: {p->Tcmpa=Ta; p->Tcmpb=Tc; p->Tcmpc=Tb; break;}
      default:{;}

  }
}


