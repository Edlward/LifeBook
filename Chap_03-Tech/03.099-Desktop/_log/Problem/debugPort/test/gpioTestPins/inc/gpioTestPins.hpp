/**
  \file motorImp.hpp

  \par Copyright &copy; 2018 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Implementation of test-pins to be used for evaluation of functions by e.g watching oscilloscope
          pictures of signals routed to the GPIO test pins.
  \author Jeppa Grossh&ouml;g <!-- Grosshög -->

  \addtogroup Test
  \{


*/
#ifndef _GPIO_TEST_PINS_HPP_
#define _GPIO_TEST_PINS_HPP_ //lint !e1960 MISRA C++, 17-0-2. Re-use is done to form a standard header guard in this case

extern "C" {
    #include <mcuGpioStm32f10x.h>
}
#include "aaesCommon.hpp"

//! Implementation of the test pin class class in the application code
namespace testInternal
{
	class  GpioTestPin
	{
		public:
            typedef enum
            {
                JTDI,
                JTDO,
                NJTRST
            } teTestPinType;

            GpioTestPin( teTestPinType eTestPin );

            //! The destructor will only be used in the UnitTest environment.
            virtual ~GpioTestPin();

            void vSetPin ();

            void vClearPin ();

            void vTogglePin ();

		private:

			static const Stm32f10xPhysPortPinConf rJtdiGpioConfiguration;
			static const Stm32f10xPhysPortPinConf rJtdoGpioConfiguration;
            static const Stm32f10xPhysPortPinConf rNjtrstGpioConfiguration;

            GPIO_TypeDef* gpioPort;
            uint16_t      gpioPin;
	};
} /* End of namespace outputInternal */
#endif /* _GPIO_TEST_PINS_HPP_ */

/**
  \}
*/
