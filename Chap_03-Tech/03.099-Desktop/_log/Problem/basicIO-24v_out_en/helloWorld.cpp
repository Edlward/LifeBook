/* Copyright 閿燂拷 2017 ASSA ABLOY ENTRANCE SYSTEM AB,
 * Lodjursgatan 10,
 * Landskrona, Sweden.
 * All rights reserved
 */
/**
 * \file        omsBasicMain.c
 *
 * \author      Roger Felix & Johan Nilsson
 *
 */
/* Include files ------------------------------------------------------------ */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "input.hpp"
#include "comm.hpp"
#include "messageRouter.hpp"
#include "messageRouterImp.hpp"

extern "C" {
    #include <FreeRTOS.h>

    #include <task.h>

    #include <halSerial.h>

    #include <mbsAssert.h>
    #include <mbsLog.h>
    #include <timerIfc.h>
    #include <systemControlRegistration.h>
    #include <mbsMessaging.h>
	#include <stm32f10x_gpio.h>
}

/* Module defines ----------------------------------------------------------- */
/* Module types and type definitions ---------------------------------------- */

/* Static constants and variables ------------------------------------------- */
/* Static function declarations --------------------------------------------- */
/* Static variables and constants ------------------------------------------- */
static int32_t testTimerInterval;//3000ms
/* Handles to clients and servers
 * */
static xTaskHandle quasarMainTaskHandle;
static MbsMsgHandle * inputServerHandle = NULL;
static MbsMsgAddress  inputServerAddress = MBS_MSG_ADDRESS_UNKNOWN;
static messages::MessageRouter* messageRouterInput = new messagesInternal::MessageRouterImp( messagesInternal::TRANSMITTING_ONLY,
                                                                                             MBS_MSG_ADDRESS_UNKNOWN );
static messagesInternal::MessageRouterImp* messageRouterMainImp;
static messages::MessageRouter*            messageRouterMain;


static void vParameterValueWrite(const uint8_t * pui8Payload)
{
	const uint8_t ui8ParameterId = pui8Payload[0];
	uint16_t ui16Temp = static_cast<uint32_t>(pui8Payload[1] <<8) + static_cast<uint32_t>(pui8Payload[2]);
	const int16_t si16ParameterValue = static_cast<int16_t>(ui16Temp);

	switch(ui8ParameterId)
	{
		case messages::PARAMETER_ID_HOLD_OPEN_TIME:
			mbsLogPrintf( "Hold Open time %d ms \n",si16ParameterValue);
			break;
		default:
			break;
	}
}

static void vCbFromInner ( bool bStatus )
{

}

static void vDispatchMainMessage ()
{
    switch ( messageRouterMain->ui8GetMessageId() )
    {
        case messages::HEART_BEAT:
            /* Do nothing, not implemented */
            break;
        case messages::INNER_IMPULSE:
            {
                if ( true == messageRouterMain->boGetBoolPayload() )
                {
                    mbsLogPrintf( "Inner pressed\n" );
                    input::innerImpulseDelay->vRequestTimeout(500U);
                }
                else
                {
                    mbsLogPrintf( "Inner released\n" );
                }
            }
            break;
        case messages::OUTER_IMPULSE:
        {
            if ( true == messageRouterMain->boGetBoolPayload() )
            {
                mbsLogPrintf( "Outer pressed\n" );
            }
            else
            {
                mbsLogPrintf( "Outer released\n" );
            }
        }
            break;
        case messages::KEY_IMPULSE:

            if ( true == messageRouterMain->boGetBoolPayload() )
			  {
				  mbsLogPrintf( "key impulse active\n" );
			  }
			  else
			  {
				  mbsLogPrintf( "key impulse inactive \n" );
			  }

            break;

        case messages::PARAMETER_VALUE_WRITE:
        	vParameterValueWrite(messageRouterMain->pGetMessagePayload());
            break;

        case messages::OPEN_CLOSE_IMPULSE:
            /* Do nothing, not implemented */
            break;
        case messages::LEARN_BUTTON:
            /* Do nothing, not implemented */
            break;
        case messages::MOTION_CONTROL_STATUS:
            /* Do nothing, not implemented */
            break;
        case messages::DOOR_CONTROL_TIMER_EVENT:
            mbsLogPrintf( "Delayed Inner Impulse" );
            break;
        case messages::NOT_USED:
        default:
            /* No other messages are routed to this module */
            break;
    }
}

static MbsStatus inputHandleRequest( MbsMsgHandle         * msgHandle,
                                     MbsMsgAddress          sender,
                                     MbsMsg               * request,
                                     MbsMsgResponseHandle * responseHandle )
{
    messageRouterMainImp->vReceive( request );

    vDispatchMainMessage();
    return MBS_STATUS_OK;
}


/**
 * This is the function run by the omsBasicMain task.
 */
static void quasarMain( void *pvParameters )
{
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 1; 	//1s tick
    MbsStatus result;

    systemControlInitDone( pvParameters );
    mbsLogPrintf("OMSBasicMain task started\r\n");

    // Initialize the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount ();


    //*******************************************/
    // Call init functions.

    //*******************************************/
    input::innerImpulse->vAddCallback( vCbFromInner );

	GPIO_InitTypeDef rGpioInit;
	// STATUS_LED pin.
	rGpioInit.GPIO_Pin = GPIO_Pin_2;   // PB2
	rGpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
	rGpioInit.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &rGpioInit);      //lint !e934 !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining GPIOB
	GPIO_ResetBits(GPIOB, GPIO_Pin_2); //lint !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining GPIOB
	// BT_EN pin.
	rGpioInit.GPIO_Pin = GPIO_Pin_4;   // PC4
	rGpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
	rGpioInit.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &rGpioInit);      //lint !e934 !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining GPIOB
	GPIO_ResetBits(GPIOC, GPIO_Pin_4); //lint !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining GPIOB
	// OK_LED pin.
	rGpioInit.GPIO_Pin = GPIO_Pin_6;   // PC6
	rGpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
	rGpioInit.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &rGpioInit);      //lint !e934 !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining GPIOB
	GPIO_ResetBits(GPIOC, GPIO_Pin_6); //lint !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining GPIOB
	// 24V_OUT_EN pin.
	rGpioInit.GPIO_Pin = GPIO_Pin_11;   // PC11
	rGpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
	rGpioInit.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &rGpioInit);      //lint !e934 !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining GPIOB
	GPIO_SetBits(GPIOC, GPIO_Pin_11); //lint !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining GPIOB
	// BT_RTS
	rGpioInit.GPIO_Pin = GPIO_Pin_1;   //lint !e9048 unsigned integer literal without a 'U' suffix
	GPIO_Init(GPIOA, &rGpioInit);      //lint !e934 !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining GPIOB
	GPIO_ResetBits(GPIOA, GPIO_Pin_1); //lint !e9048 !e9029 !e835 !e9078 !e923 !e511 Error in the ST Library defining GPIOB

    testTimerInterval = si32TimerNew(3000);
    do
    {
    	if(boTimerElapsed(testTimerInterval)==true)
    	{
        	if ( true == input::learn->boGetStatus() )
        	{
        	    mbsLogPrintf ( "hello world! Learn is active. \n");
        	}
        	else
        	{
                mbsLogPrintf ( "hello world! Learn is released. \n");
        	}

    		mbsLogPrintf("Main Version === 0910\r");
    		mbsLogPrintf("Main Voltage %d mV\r",static_cast<int>(input::mainVoltAdc->si32GetRealValue()));
    		mbsLogPrintf("ChipTemp %d c degree\r",static_cast<int>(input::chipTempAdc->si32GetRealValue()));
    		mbsLogPrintf("RefVoltage %d mV\r",static_cast<int>(input::refVoltAdc->si32GetRealValue()));

        	testTimerInterval = si32TimerNew(3000);
    	}

       if( MBS_STATUS_OK != ( result = mbsMsgPollInbox( inputServerHandle, 0 ) ) )
        {
    	   	// Receive failed
            // mbsLogPrintf("mbsMsgPollInbox failed res code = %d \r\n", result );
        }

        // System tick 1ms.
        vTaskDelayUntil( &xLastWakeTime, xFrequency );
        //*******************************************/

    }while( true );
}


SYSTEM_CONTROL_REGISTER_SYNCED_INIT_FUNCTION( initQuasarBasicMain,     \
                                              INIT_QUASAR_BASIC_LEVEL, \
                                              INIT_QUASAR_BASIC_ORDER )
{
    HalSpecificInfo serInfo;

    /* Get SERIAL driver information */
    if ( HAL_RES_OK == halSerialGetInfo( &serInfo ) )
    {
        mbsLogPrintf("Using SERIAL driver = %s v-%d, config = %s v-%d \r\n", serInfo.driverName,
                     (int)serInfo.driverVersion,
                     serInfo.configName,
                     (int)serInfo.configVersion );
    }

    /* Register inputServer service */
    if( MBS_STATUS_OK != mbsMsgRegister( &inputServerHandle, "inputSrv", 20 ) )
    {
        mbsLogPrintf("mbsMsgRegister server failed");
    }

    if( MBS_MSG_ADDRESS_UNKNOWN == (inputServerAddress = mbsMsgFindService( "inputSrv" ) ) )
    {
        mbsLogPrintf("mbsMsgFindService inputSrv failed");
    }

    messageRouterMainImp = new messagesInternal::MessageRouterImp ( messagesInternal::MAIN, inputServerAddress );
    messageRouterMain = messageRouterMainImp;
    mbsMsgOnRequestCallbackSet( inputServerHandle, inputHandleRequest );

    /*
     * Create the omsBasicMain task
     *
     * Responsible for lighting the LED's according to the pattern as
     * received by the controller task.
     */
    if( pdPASS != xTaskCreate( quasarMain,
                               (const char * const)MBS_CFG_TASK_NAME_APPLICATION_QUASAR_MAIN,
                               MBS_CFG_TASK_STACK_APPLICATION_QUASAR_MAIN,
                               context,
                               MBS_CFG_TASK_PRIO_APPLICATION_QUASAR_MAIN,
                               &quasarMainTaskHandle ) )
    {
        mbsLogPrintf("xTaskCreate failed");
    }
}

SYSTEM_CONTROL_REGISTER_SYNCED_INIT_FUNCTION( initGlobals,       \
                                              INIT_GLOBALS_LEVEL,\
                                              INIT_GLOBALS_ORDER )
{
    // Start and end points of the constructor list,
    // defined by the linker script.
    extern void ( *__init_array_start )();
    extern void ( *__init_array_end )();

    // Call each function in the list.
    // We have to take the address of the symbols, as __init_array_start* i
    // the first function pointer, not the address of it
    void ( **p ) () = &__init_array_start;
    for (; p < &__init_array_end; ++p )
    {
        ( *p )();
    }
    mbsLogPrintf("Globals initialized");
    systemControlInitDone( context );

}
