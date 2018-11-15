/*
 * clarke.c
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */
#include "DSP2833x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include <math.h>
#include "clarke.h"

//======== Definations for functions ===========================
//**********************************
/*
  @ Description:
  @ Param
  @ Return
*/
//**********************************
void clarke_calc(CLARKE *p)
{
   p->Alpha = 1.2247448714*p->As;

   p->Beta = (p->As + 2*p->Bs)*0.7071067812;
}


