/*
 * zhs_clarke.h
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */

#ifndef CLARKE_H_
#define CLARKE_H_
#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object
//-----------------------------------------------------------------------------

typedef struct {  float32  As;      // Input: phase-a stator variable
                  float32  Bs;      // Input: phase-b stator variable
                  float32  Cs;      // Input: phase-b stator variable
                  float32  Alpha;   // Output: stationary d-axis stator variable
                  float32  Beta;    // Output: stationary q-axis stator variable
                  void  (*calc)();  // Pointer to calculation function
                 } CLARKE;

//-----------------------------------------------------------------------------
// Define a _handle
//-----------------------------------------------------------------------------
typedef CLARKE *CLARKE_handle;


//-----------------------------------------------------------------------------
// Default initializer for the  Object.
//-----------------------------------------------------------------------------

#define CLARKE_DEFAULTS { 0, \
                          0, \
                          0, \
                          0, \
                          0, \
                          (void (*)(Uint32))clarke_calc }

//-----------------------------------------------------------------------------
//  Prototypes for the functions in .c
//-----------------------------------------------------------------------------
void clarke_calc(CLARKE_handle);

#endif /* CLARKE_H_ */
