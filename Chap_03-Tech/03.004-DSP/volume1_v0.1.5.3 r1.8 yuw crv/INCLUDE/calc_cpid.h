/*
 *  ======== alg_pid.H ========
 *
 */

#ifndef _ALG_CPID_H
#define _ALG_CPID_H
//==========================================
#define  MCW_DEBUG_PRINTF   0 //1

//==========================================
typedef int                 int16;
typedef long                int32;
typedef long long           int64;   
typedef unsigned int        Uint16;
typedef unsigned long       Uint32;
typedef unsigned long long  Uint64;
typedef float               float32;
typedef long double         float64;

//==========================================
struct T_CPID{
	int16 iCrrtRef;
	int16 iCrrtSmp;
	int16 iCrrtLst;
	int16 iCrrtErr;

	Uint16 Kp_c;
	Uint16 Ki_c;
	Uint16 Kd_c;

	int32 lCrrtUival;
	int32 lCrrtUnout;

	int32 lCrrtUimax;
	int32 lCrrtUimin;
	int32 lCrrtUnmax;
	int32 lCrrtUnmin;
};

extern struct T_CPID  cpid;

//==========================================
void  CrrntcPidInit(void);
int16 AlgCrrntcPid(int16);
void SimuCurvePid(void);

#endif /* _ALG_CPID_H */

