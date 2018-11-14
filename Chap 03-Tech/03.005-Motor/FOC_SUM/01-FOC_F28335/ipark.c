/*
 * ipark.c
 *
 *  Created on: 2016-3-26
 *      Author: Administrator
 */
#include "DSP2833x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include <math.h>
#include "ipark.h"

//======== Definations for functions ===========================
//**********************************
/*
  @ Description:
  @ Param
  @ Return
*/
//**********************************
void ipark_calc(IPARK *p)
{

   p->Alpha = p->Ds * p->Cos - p->Qs * p->Sin;
   p->Beta  = p->Qs * p->Cos + p->Ds * p->Sin;

}









