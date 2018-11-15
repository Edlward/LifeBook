/*
 * zhs_eQEP_pos_speed_get.h
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */

#ifndef EQEP_POS_SPEED_GET_H_
#define EQEP_POS_SPEED_GET_H_
#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object
//-----------------------------------------------------------------------------

typedef struct {float ElecTheta;    //OutPut: Motor Electrical Angle
                float MechTheta;    //Output: Motor Mechanical Angle
                  int DirectionQep; //output: Motor rotation direction

                  int PolePairs;     //Parameter: 同步电机极对数
                  int LineEncoder;   //Parameter: 码盘一周脉冲数（增量式）
                  int Encoder_N;     //Parameter: 码盘一周脉冲数的4倍(根据倍频的倍数而定，这里用4倍频)
                  int CalibrateAngle;//Parameter:电机A相绕组和码盘Index信号之间的夹角，与安装精度有关
                float Mech_Scaler;   //Parameter:1/Encoder_N
                float RawTheta;      //Variable: 初始定位后，电机转子d轴和定子A相绕组之间所相差的码盘计数值
                  int Index_sync_flag;//Output: Index sync status

                float BaseRpm;        //Parameter:额定转速

                float Speed_Mr_Rpm_Scaler;//Parameter:60000/(Encoder_N * T)，其中T为M法测速时的时间间隔，单位ms
                float Speed_Mr_Rpm;   //Output: speed int r.p.m
                float Speed_Mr;       //Output: speed in per-uint
                float Position_k_1;   //Input: Current position
                float Position_k;     //Input: Last position

                float Speed_Tr_Rpm_Scaler;//Parameter: (UPPS * 150e6 * 60)/(Encoder_N * CCPS)
                float Speed_Tr_Rpm;   //Output: spedd int r.p.m
                float Speed_Tr;       //Output: speed int per-uint

                void (*init)();         // Pointer to the init funcion
                void (*calc)();
                } EQEP_POS_SPEED_GET;

//-----------------------------------------------------------------------------
// Define a POSSPEED_handle
//-----------------------------------------------------------------------------
typedef EQEP_POS_SPEED_GET  *EQEP_POS_SPEED_GET_handle;


//-----------------------------------------------------------------------------
// Default initializer for the POSSPEED Object.
//-----------------------------------------------------------------------------

#define EQEP_POS_SPEED_GET_DEFAULTS {0,0,0,\
                                     4,2500,10000,0,1.0/10000,0,0,\
                                     2000.0,\
                                     0.6,0,0,0,0,\
                                     225000,0,0,\
                                     (void (*)(long))eQEP_pos_speed_get_Init,\
                                     (void (*)(long))eQEP_pos_speed_get_Calc}
//-----------------------------------------------------------------------------
//  Prototypes for the functions in posspeed.c
//-----------------------------------------------------------------------------
void eQEP_pos_speed_get_Init(EQEP_POS_SPEED_GET_handle);
void eQEP_pos_speed_get_Calc(EQEP_POS_SPEED_GET_handle);

#endif /* ZHS_EQEP_POS_SPEED_GET_H_ */
