/*
 * Copyright 2012 ASSA ABLOY AB,
 * Klarabergsviadukten 90,
 * Stockholm, Sweden.
 * All rights reserved
 */
/**
 * \file serialConfig.c
 *
 * \brief This file defines the logical serial ports available on this board
 * and what hardware they are assigned to.
 *
 */
/* $Revision: $
 * $Date: $
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

#include "halSerial.h"
#include "halSerialStm32Common.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "mcuGpioStm32f10x.h"

#include "mbsArraySize.h"

#define _DEBUG_PORT_ENABLED_    2    //for check macro define valid.

#ifdef  _DEBUG_PORT_
#define _DEBUG_PORT_ENABLED_    1
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Interface variables and constants -----------------------------------------*/

/**
 * This array defines what logical serial ports are connected to what physical
 * GPIO-pins.
 */
const Stm32f10xPhysPortPinConf serialGpioPinConf[] =
{
    //DEFINE_GPIO_MODE( GPIO_Mode_IPD, B, 50, GPIO_Pin_11 )
	DEFINE_GPIO_MODE( GPIO_Mode_IPD, A, 50, GPIO_Pin_3 )
	//DEFINE_GPIO_MODE( GPIO_Mode_Out_OD, C, 50, GPIO_Pin_4 )
};

const uint8_t serialGpioPinConfsize = sizeof(serialGpioPinConf)/sizeof(serialGpioPinConf[0]);

/**
 * This array defines what logical serial ports are connected to what physical
 * USART and GPIO-pins.
 */
HalSerialStm32Config const mbsStM64CoreV10HalSerialPorts[] =
{
    {
#ifndef _DEBUG_PORT_ENABLED_
        .portName     = "console",
        .aliasName    = "log",
#else
        .portName     = "debug",
        .aliasName    = "dbg",
#endif
        .usart        = USART3,
        .rxPort       = GPIOB,
        .rxPin        = GPIO_PinSource11,
        .txPort       = GPIOB,
        .txPin        = GPIO_PinSource10,
    },
    {
        .portName     = "serialport2",
        .aliasName    = "BLE",
        .usart        = USART2,
        .rxPort       = GPIOA,
        .rxPin        = GPIO_PinSource3,
        .txPort       = GPIOA,
        .txPin        = GPIO_PinSource2,
    },
    {
#ifdef _DEBUG_PORT_ENABLED_
        .portName     = "console",
        .aliasName    = "log",
#else
        .portName     = "debug",
        .aliasName    = "dbg",
#endif
        .usart        = USART1,
        .rxPort       = GPIOA,
        .rxPin        = GPIO_PinSource10,
        .txPort       = GPIOA,
        .txPin        = GPIO_PinSource9,
    },
};

uint8_t const      mbsStM64CoreV10HalSerialPortCount     = ARRAY_SIZE( mbsStM64CoreV10HalSerialPorts );
char const * const mbsStM64CoreV10HalSerialConfigName    = "mbs_st_m64_core_v10";
uint32_t const     mbsStM64CoreV10HalSerialConfigVersion = 1;

/* Interface functions -------------------------------------------------------*/


