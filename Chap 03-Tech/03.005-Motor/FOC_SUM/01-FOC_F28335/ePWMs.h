/*
 * zhs_ePWMs.h
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */

#ifndef ZHS_EPWMS_H_
#define ZHS_EPWMS_H_

#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object
//-----------------------------------------------------------------------------
typedef struct {float PeriodMax;// Parameter: PWM Half-Period in CPU clock cycles
                float Duty1A;
                float Duty1B;
                float Duty2A;
                float Duty2B;
                float Duty3A;
                float Duty3B;
                float Duty4A;
                float Duty4B;
                float Duty5A;
                float Duty5B;
                float Duty6A;
                float Duty6B;
                void (*init)();
                void (*update)();
                } EPWMS;

//-----------------------------------------------------------------------------
// Define a POSSPEED_handle
//-----------------------------------------------------------------------------
typedef EPWMS  *EPWMS_handle;


//-----------------------------------------------------------------------------
// Default initializer for the POSSPEED Object.
//-----------------------------------------------------------------------------
#define EPWMS_DEFAULTS {15000.0,\
                        0,0,0,0,0,0,\
                        0,0,0,0,0,0,\
                        (void (*)(long))ePWMs_Init,\
                        (void (*)(long))ePWMs_Update}

//-----------------------------------------------------------------------------
//  Prototypes for the functions in posspeed.c
//-----------------------------------------------------------------------------
void ePWMs_Init(EPWMS_handle);
void ePWMs_Update(EPWMS_handle);
#endif /* ZHS_EPWMS_H_ */
