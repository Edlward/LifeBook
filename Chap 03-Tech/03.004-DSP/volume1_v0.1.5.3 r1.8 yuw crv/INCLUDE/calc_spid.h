/*
 *  ======== alg_pid.H ========
 *
 */

#ifndef _ALG_PID_H
#define _ALG_PID_H


#define DEFAULT_SPEED_KP 	10 

struct T_SPEED_PID{
	float SetSpeed;						//�����趨ֵ
	float ActualSpeed;					//����ʵ��ֵ
	float err;							//����ƫ��ֵ
	float err_last;						//������һ��ƫ��ֵ
	float Kp;							//�������ϵ��
	float Ki;							//�������ϵ��
	float Kd;							//����΢��ϵ��
	float voltage;						//�����ѹֵ������ִ�����ı�����
	float integral;						//�������ֵ
	float umax;
	float umin;
};

#endif /* _ALG_PID_H */

