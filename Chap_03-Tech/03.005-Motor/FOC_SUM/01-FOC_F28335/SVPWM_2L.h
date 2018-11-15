/*
 * zhs_SVPWM_2L.h
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */

#ifndef SVPWM_2L_H_
#define SVPWM_2L_H_
#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object
//-----------------------------------------------------------------------------
typedef struct  { float  Ualpha;  // Input: reference alpha-axis phase voltage
                  float  Ubeta;   // Input: reference beta-axis phase voltage
                  float  Vdc;     // Input: DC voltage
                  float  T;       // Input: PWM Modulation Period
                  float  Tcmpa; // Output: reference phase-a switching function
                  float  Tcmpb; // Output: reference phase-b switching function
                  float  Tcmpc; // Output: reference phase-c switching function
                  void (*calc)();       // Pointer to calculation function
                } SVPWM_2L;


//-----------------------------------------------------------------------------
// Define a POSSPEED_handle
//-----------------------------------------------------------------------------
typedef SVPWM_2L *SVPWM_2L_handle;


//-----------------------------------------------------------------------------
// Default initializer for the POSSPEED Object.
//-----------------------------------------------------------------------------
#define SVPWM_2L_DEFAULTS {0,0,0,1.0,\
                           0.5,0.5,0.5,\
                           (void (*)(Uint32))svpwm_2l_calc}

//-----------------------------------------------------------------------------
//  Prototypes for the functions in posspeed.c
//-----------------------------------------------------------------------------
void svpwm_2l_calc(SVPWM_2L_handle);

#endif /* ZHS_SVPWM_2L_H_ */
