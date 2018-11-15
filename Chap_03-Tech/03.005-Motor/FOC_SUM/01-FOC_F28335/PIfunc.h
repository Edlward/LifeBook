/*
 DESCRIPTION:



 TEST RESULT: Passed the test;

 DESIGNED TIME: 2011-08-21

 DESIGNER: ZhuHongshun

*/



#ifndef PIFUNC_H
#define PIFUNC_H

#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object 
//-----------------------------------------------------------------------------
typedef struct { 
	    		 float Give;
				 float Kp;
		 		 float Ki;
	    		 float LastE;
	    		 float PresentE;
	    		 float OutMax;
	    		 float OutMin;
        		 float Output;
        		 float Feedback;
				 float LastOutput;
				 void  (*calc)();	  	// Pointer to calculation function
			   } PIFUNC;

//-----------------------------------------------------------------------------
// Define a POSSPEED_handle
//-----------------------------------------------------------------------------
typedef PIFUNC *PIFUNC_handle;


//-----------------------------------------------------------------------------
// Default initializer for the POSSPEED Object.
//-----------------------------------------------------------------------------
#define PIFUNC_DEFAULTS { 0, \
                           0, \
                           0, \
                           0, \
                           0, \
                           0, \
                           0, \
                           0, \
                           0, \
						   0, \
                          (void (*)(Uint32))PIFUNC_calc }
//-----------------------------------------------------------------------------
//  Prototypes for the functions in posspeed.c                                 
//-----------------------------------------------------------------------------
void PIFUNC_calc(PIFUNC_handle);




#endif

//==============================================================
//End of file.
//==============================================================



