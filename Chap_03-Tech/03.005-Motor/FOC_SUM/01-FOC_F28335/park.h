/*
 * Park.h
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */

#ifndef PARK_H_
#define PARK_H_
#include "C28x_FPU_FastRTS.h"
typedef struct{
	float32 Alpha;
	float32 Beta;
	float32 Cos;
	float32 Sin;
	float32 Ds;
	float32 Qs;
	void (*calc)();
 } PARK;
typedef PARK *PARK_handle;

#define PARK_DEFAULTS {0,0,\
	                  0,0,\
	                  0,0,\
	                  (void(*)(Uint32))park_calc}
void park_calc(PARK_handle);

#endif /* PARK_H_ */
