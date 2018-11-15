/*
 *  ======== alg_pid.H ========
 *
 */

#ifndef _ALG_PID_H
#define _ALG_PID_H


#define DEFAULT_SPEED_KP 	10 

struct T_SPEED_PID{
	float SetSpeed;						//定义设定值
	float ActualSpeed;					//定义实际值
	float err;							//定义偏差值
	float err_last;						//定义上一个偏差值
	float Kp;							//定义比例系数
	float Ki;							//定义积分系数
	float Kd;							//定义微分系数
	float voltage;						//定义电压值（控制执行器的变量）
	float integral;						//定义积分值
	float umax;
	float umin;
};

#endif /* _ALG_PID_H */

