/*
 * Park.c
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */
#include "DSP2833x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include <math.h>
#include "park.h"
void park_calc(PARK*p)
{
	p->Ds=p->Alpha*p->Cos+p->Beta*p->Sin;
	p->Qs=p->Beta*p->Cos-p->Alpha*p->Sin;
}
