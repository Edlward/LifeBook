/*
 * zhs_ADC_volt_current_get.h
 *
 *  Created on: 2016-3-25
 *      Author: Administrator
 */

#ifndef ZHS_ADC_VOLT_CURRENT_GET_H_
#define ZHS_ADC_VOLT_CURRENT_GET_H_
#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object
//-----------------------------------------------------------------------------
typedef struct {float Vdc;  //Output: DC bus voltage of VSC
                float Ia;   //Output: VSC output line current Ia
                float Ib;   //Output:
                float Ic;   //Output:
                float Volt_channelA0;//Output:DSP A通道8个管脚上的电压值
                float Volt_channelA1;
                float Volt_channelA2;
                float Volt_channelA3;
                float Volt_channelA4;
                float Volt_channelA5;
                float Volt_channelA6;
                float Volt_channelA7;
                float Volt_channelB0;
                float Volt_channelB1;
                float Volt_channelB2;
                float Volt_channelB3;
                float Volt_channelB4;
                float Volt_channelB5;
                float Volt_channelB6;
                float Volt_channelB7;

                void (*init)();       // Pointer to the init function
                void (*read)();       // Pointer to the read function
               }ADC_VOLT_CURRENT_GET;


//-----------------------------------------------------------------------------
// Define a POSSPEED_handle
//-----------------------------------------------------------------------------
typedef ADC_VOLT_CURRENT_GET  *ADC_VOLT_CURRENT_GET_handle;


//-----------------------------------------------------------------------------
// Default initializer for the POSSPEED Object.
//-----------------------------------------------------------------------------
#define ADC_VOLT_CURRENT_GET_DEFAULTS {0,0,0,0,\
                                       0,0,0,0,0,0,0,0,\
                                       0,0,0,0,0,0,0,0,\
                                     (void (*)(long))ADC_volt_current_get_Init,\
                                     (void (*)(long))ADC_volt_current_get_Calc}
//-----------------------------------------------------------------------------
//  Prototypes for the functions in posspeed.c
//-----------------------------------------------------------------------------
void ADC_volt_current_get_Init();
void ADC_volt_current_get_Calc(ADC_VOLT_CURRENT_GET_handle);

#endif /* ZHS_ADC_VOLT_CURRENT_GET_H_ */
