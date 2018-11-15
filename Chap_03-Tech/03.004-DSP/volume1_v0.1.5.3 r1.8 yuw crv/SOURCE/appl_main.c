/***************************************************************************/
/*                                                                         */
/*     main.c		                                                       */
/*                                                                         */
/*     Audio gain processing in a main loop                                */
/*                                                                         */
/***************************************************************************/

/*------------ include files -----------------------------------------------*/
#include <stdio.h>

#include "appl_volume.h"
#include "calc_bisearch.h"
#include "calc_cpid.h"

/*------------ MACRO define -----------------------------------------------*/
/*------------ value define -----------------------------------------------*/
/*------------ Functions define ---------------------------------------------*/

/*
 * ============================================================================
 * 		 main 
 * ============================================================================
 */
void main()
{
	//unsigned int time_tick = 1;                      	/* time tick */

    /* loop forever */
    while(TRUE)
    {
		
		static	int len = 0;
		//printf("init len 	= %d.\n", len);
		
		if (0 == len)
		{
			len = sizeof(char);
			printf("sizeof(char) 	= %d.\n", len);
			
			len = sizeof(short);
			printf("sizeof(short) 	= %d.\n", len);
			
			len = sizeof(int);
			printf("sizeof(int) 	= %d.\n", len);
			
			len = sizeof(long);
			printf("sizeof(long) 	= %d.\n", len);
			
			len = sizeof(float);
			printf("sizeof(float) 	= %d.\n", len);
			
			len = sizeof(double);
			printf("sizeof(double) 	= %d.\n", len);
		}

		//TestSytax();
		//Appl_Volume();
		//Alg_Bisearch(); 
		//Alg_Pid(); 
		//Alg_cPid();
		SimuCurvePid();
    }     
}

 /* ===========================================================================
 		file end
 ============================================================================*/

