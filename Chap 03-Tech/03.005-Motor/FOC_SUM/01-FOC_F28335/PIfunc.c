/*
 * PIfunc.c
 *
 *  Created on: 2016-3-28
 *      Author: Administrator
 */
#include "DSP2833x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include <math.h>
#include"PIfunc.h"
void PIFUNC_calc(PIFUNC *p)
{
	p->PresentE = p->Give - p->Feedback;
	p->Output = p->LastOutput + p->Kp*(p->PresentE - p->LastE) + p->Ki*0.0002*p->PresentE;
	//输出限幅
	if(p->Output > p->OutMax) p->Output = p->OutMax;
	if(p->Output < p->OutMin) p->Output = p->OutMin;

	//保存上一周期的值
	p->LastOutput = p->Output;
	p->LastE=p->PresentE;

}

