/****************************************************************************/
/*                                                                         	*/
/*     alg_cpid.c                                                     		*/
/*                                                                         	*/
/*     Processing in a main loop                                			*/
/*                                                                         	*/
/****************************************************************************/

/*------------ include files -----------------------------------------------*/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "calc_cpid.h" 

/*------------ MACRO define -----------------------------------------------*/
#define  CRSCL  	  	10	//current radio scale. 2^10=1024.

#define  KPC         	200 //220 //220 //240 // 400 // 350 // 512
#define  KIC         	550 //330 //330 //320 // 400 // 350 // 512

/*------------ value define -----------------------------------------------*/
struct T_CPID cpid;
int16 aRealCrrnt[1000] = {0};

/*------------ Functions define ---------------------------------------------*/
void  Alg_cPid(void); 
void  CrrntcPidInit(void); 
int16 AlgCrrntcPid(int16); 

/*
 * ============================================================================
 *
 * FUNCTION: xxx.
 *
 * PARAMETERS: xxx.
 *
 * RETURN VALUE: xxx.
 * ============================================================================
 */
void Alg_cPid(void)
{
	Uint16 cdelay=0;
	Uint16 ccount=0;

	CrrntcPidInit();

    //puts("Alg_pid started\n");
#if MCW_DEBUG_PRINTF
	printf("===cPID test begin \n");
#endif

	while (ccount < 500)
	{
		int16 crrnt = AlgCrrntcPid(550);
#if MCW_DEBUG_PRINTF
		printf("current=%d\n", crrnt);
#endif
		aRealCrrnt[ccount] = crrnt;
		ccount++;
	}

    while (cdelay < 10000)
    {
	    cdelay ++;

    } /*while*/

}


/*
 * ============================================================================
 *
 * FUNCTION: xxx.
 *
 * PARAMETERS: xxx.
 *
 * RETURN VALUE: xxx.
 * ============================================================================
 */
void CrrntcPidInit(void) 
{ 
#if MCW_DEBUG_PRINTF
	printf("======================\n");
	printf("c PID_init begin \n");
#endif

	cpid.iCrrtRef		= 0;
	cpid.iCrrtSmp		= 0;
	cpid.iCrrtLst		= 0;
	cpid.iCrrtErr		= 0;

	cpid.Kp_c			= KPC;
	cpid.Ki_c			= KIC;
	cpid.Kd_c			=  10;

	cpid.lCrrtUival		= 0;
	cpid.lCrrtUnout		= 0;

	cpid.lCrrtUimax		= 10000;
	cpid.lCrrtUimin		= -10000;
	cpid.lCrrtUnmax		= 10000;
	cpid.lCrrtUnmin		= -10000;

#if MCW_DEBUG_PRINTF
	printf("c PID_init end \n");
#endif
} 

/*
 * ============================================================================
 *
 * FUNCTION: xxx.
 *
 * PARAMETERS: xxx.
 *
 * RETURN VALUE: xxx.
 * ============================================================================
 */
int16 AlgCrrntcPid(int16 crrnt)
{
	//int  itmpCrrntSamp = 0;									// current sample.

	long itmpUpCrrnt = 0;									// Up component value.
	long ltmpUiCrrnt = 0;									// Ui component value.
	long ltmpUnCrrnt = 0;									// Un out to current ACR.

	cpid.iCrrtRef  = crrnt;
	cpid.iCrrtSmp  = cpid.lCrrtUnout;

	cpid.iCrrtErr = cpid.iCrrtRef - cpid.iCrrtSmp;			// 计算电流偏差1:100
	itmpUpCrrnt   = ((long)cpid.iCrrtErr * cpid.Kp_c)>>CRSCL;	// P分量
	ltmpUiCrrnt   = ((long)cpid.iCrrtErr * cpid.Ki_c)>>CRSCL;   // I分量
	ltmpUiCrrnt   += cpid.lCrrtUival;   					// ?// D积分计算
#if MCW_DEBUG_PRINTF
	printf("----------------------\n");
	printf("err=%d, Up=%ld, Ui=%ld\n", cpid.iCrrtErr, itmpUpCrrnt, ltmpUiCrrnt);
#endif

	if (ltmpUiCrrnt > cpid.lCrrtUimax)
	{
		ltmpUiCrrnt = cpid.lCrrtUimax;
	}
	else if (ltmpUiCrrnt < cpid.lCrrtUimin)
	{
		ltmpUiCrrnt = cpid.lCrrtUimin;
	}
	cpid.lCrrtUival = ltmpUiCrrnt;          				// 积分结果保存

	// control Un.
	if (cpid.iCrrtErr > cpid.lCrrtUimax/2)
	{
		ltmpUnCrrnt = itmpUpCrrnt + ltmpUiCrrnt>>1;    		// 计算PWM值 //PI结合
	}
	else if (cpid.iCrrtErr < cpid.lCrrtUimin/2)
	{
		ltmpUnCrrnt = itmpUpCrrnt + ltmpUiCrrnt>>1;    		// 计算PWM值 //PI结合
	}
	else
	{
		ltmpUnCrrnt = itmpUpCrrnt + ltmpUiCrrnt;    		// 计算PWM值 //PI结合
	}
	
	// limit out.
	if (ltmpUnCrrnt > cpid.lCrrtUnmax)
	{
		ltmpUnCrrnt = cpid.lCrrtUnmax;            			// PWM阈值限定
	}
	else if (ltmpUnCrrnt < cpid.lCrrtUnmin)
	{
		ltmpUnCrrnt = cpid.lCrrtUnmin;   
	}
#if MCW_DEBUG_PRINTF
	printf("Un=%ld, Unmax=%ld, Ummin=%ld\n", ltmpUnCrrnt, cpid.lCrrtUnmax, cpid.lCrrtUnmin);
#endif
	cpid.lCrrtUnout = ltmpUnCrrnt;
#if MCW_DEBUG_PRINTF
	printf("Uout=%ld\n", cpid.lCrrtUnout);
#endif
	return cpid.lCrrtUnout;
} 

 /* ===========================================================================
 		file end
 ============================================================================*/

