
/**
  \file gpioTestPins.cpp

  \par Copyright &copy; 2018 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \addtogroup Test
  \{
 */

extern "C" {
    #include <mcuGpioStm32f10x.h>
    #include <stm32f10x_rcc.h>
}
#include <cstddef>
#include "gpioTestPins.hpp"

namespace testInternal
{
	GpioTestPin::GpioTestPin( teTestPinType eTestPin )
	{
        const Stm32f10xPhysPortPinConf* pPinConfiguration;

        RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, ENABLE );
        GPIO_PinRemapConfig( GPIO_Remap_SWJ_JTAGDisable, ENABLE );

	    switch ( eTestPin )
	    {
	        case JTDI :
	            pPinConfiguration = &rJtdiGpioConfiguration;
	            break;
	        case JTDO :
	            pPinConfiguration = &rJtdoGpioConfiguration;
	            break;
	        case NJTRST :
	            pPinConfiguration = &rNjtrstGpioConfiguration;
	            break;
	        default:
	            break;
	    }
        mcuGpioStm32f10xConfigure( pPinConfiguration, 1U);
        gpioPort = pPinConfiguration->physicalPort;
        gpioPin = pPinConfiguration->physicalPins;
	}

    GpioTestPin::~GpioTestPin()
    {
    }

    void GpioTestPin::vSetPin ()
    {
        GPIO_SetBits( gpioPort, gpioPin );
    }

    void GpioTestPin::vClearPin ()
    {
        GPIO_ResetBits( gpioPort, gpioPin );
    }

    void GpioTestPin::vTogglePin ()
    {
        if ( GPIO_ReadOutputDataBit( gpioPort, gpioPin) )
        {
            GPIO_ResetBits( gpioPort, gpioPin );
        }
        else
        {
            GPIO_SetBits( gpioPort, gpioPin );
        }
    }

	const Stm32f10xPhysPortPinConf GpioTestPin::rJtdiGpioConfiguration = { /* mode          */ GPIO_Mode_Out_PP,
                                                                           /* physical port */ GPIOA,
                                                                           /* physical pin  */ GPIO_Pin_15,
                                                                           /* clock         */ RCC_APB2Periph_GPIOA,
                                                                           /* speedMhz      */ GPIO_Speed_2MHz };

    const Stm32f10xPhysPortPinConf GpioTestPin::rJtdoGpioConfiguration = { /* mode          */ GPIO_Mode_Out_PP,
                                                                           /* physical port */ GPIOB,
                                                                           /* physical pin  */ GPIO_Pin_3,
                                                                           /* clock         */ RCC_APB2Periph_GPIOB,
                                                                           /* speedMhz      */ GPIO_Speed_2MHz };

    const Stm32f10xPhysPortPinConf GpioTestPin::rNjtrstGpioConfiguration = { /* mode          */ GPIO_Mode_Out_PP,
                                                                             /* physical port */ GPIOB,
                                                                             /* physical pin  */ GPIO_Pin_4,
                                                                             /* clock         */ RCC_APB2Periph_GPIOB,
                                                                             /* speedMhz      */ GPIO_Speed_2MHz };
}
/**
  \}
 */

//lint -e1960 "function without external side-effects" Functions write to register map
