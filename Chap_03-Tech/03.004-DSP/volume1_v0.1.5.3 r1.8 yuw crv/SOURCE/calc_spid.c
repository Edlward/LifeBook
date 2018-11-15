/****************************************************************************/
/*                                                                         	*/
/*     alg_pid.c                                                     		*/
/*                                                                         	*/
/*     Processing in a main loop                                			*/
/*                                                                         	*/
/****************************************************************************/

/*------------ include files -----------------------------------------------*/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "calc_spid.h" 

/*------------ MACRO define -----------------------------------------------*/
/*------------ value define -----------------------------------------------*/
struct T_SPEED_PID pid;

float aRealSpeed[1000] = {0};

/*------------ Functions define -------------------------------------------*/
void  Alg_Pid(void); 

void  SpeedPidInit(void); 
float AlgSpeedPid(float); 

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
void Alg_Pid(void)
{
	unsigned int delay=0;
	int count=0;

	SpeedPidInit();

    //puts("Alg_pid started\n");
	printf("PID test begin \n");

	while (count<500)
	{
		float speed = AlgSpeedPid(-600.0);
		printf("%f\n",speed);
		aRealSpeed[count] = speed;
		count++;
	}

    while (delay < 10000)
    {
	    delay ++;

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
void SpeedPidInit(void) 
{ 
	printf("===============\n");
	printf("PID_init begin \n");
	pid.SetSpeed		= 0.0;
	pid.ActualSpeed		= 0.0;
	pid.err				= 0.0;
	pid.err_last		= 0.0;
	pid.voltage			= 0.0;
	pid.integral		= 0.0;
	pid.Kp				= 0.45;
	pid.Ki				= 0.45;
	pid.Kd				= 0.01;
	pid.umax			= 1000;
	pid.umin			= -1000;
	printf("PID_init end \n");
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
float AlgSpeedPid(float speed)
{
	float tmpUp_s 		= 0.0;						/* ASR calculation of p.*/
	float tmpUi_s 		= 0.0;						/* ASR calculation of i.*/
	float tmpUd_s 		= 0.0;						/* ASR calculation of d.*/

	unsigned int tmpIntgSep	= 0;					/* intergatiion separation saturation.*/

	pid.SetSpeed		= speed;
	pid.err				= pid.SetSpeed-pid.ActualSpeed;
	
	if (pid.err > pid.umax/2)
	{
		tmpIntgSep 		= 0.2;
	}
	else if (pid.err < pid.umin/2)
	{
		tmpIntgSep 		= 0.2;
	}
	else
	{
		tmpIntgSep 		= 1;
		pid.integral	+= pid.err;
	}

	tmpUp_s				= (pid.Kp) * (pid.err);
	tmpUi_s				= (pid.Ki) * (pid.integral) * (tmpIntgSep);
	tmpUd_s				= (pid.Kd) * (pid.err - pid.err_last);
	pid.voltage			= tmpUp_s  + tmpUi_s  + tmpUd_s;

	if (pid.voltage > pid.umax) 							// ¿¹»ý·Ö±¥ºÍ
    {
		pid.voltage = pid.umax;
    }
    else if (pid.voltage < pid.umin)
    {
		pid.voltage = pid.umin;
    }
	
	pid.err_last		= pid.err;
	pid.ActualSpeed		= pid.voltage * 1.0;

	return pid.ActualSpeed;
} 

 /* ===========================================================================
 		file end
 ============================================================================*/

