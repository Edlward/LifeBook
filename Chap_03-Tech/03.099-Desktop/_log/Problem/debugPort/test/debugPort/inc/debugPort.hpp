/**
  \file debugPort.hpp

  \par Copyright &copy; 2018 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Implementation of a debugPort for streaming of debug data using an UART port.

  \author Jeppa Grossh&ouml;g <!-- Grossh�g -->

  \addtogroup Test
  \{


*/
#ifndef _DEBUG_PORT_HPP_
#define _DEBUG_PORT_HPP_ //lint !e1960 MISRA C++, 17-0-2. Re-use is done to form a standard header guard in this case

extern "C" {
    #include <halSerial.h>
}
#include "aaesCommon.hpp"

/*! Implementation of debug data streaming.
 *  The debugPort component may be used for streaming of higher-speed data, that requires higher speed than what is possible with the MBS-log
 *  The debugPort has very little formatting, and provides a simple stream of characters on a port without any overhead.
 *
 *  To use the component, the debug USART must be freed. To this end, in file modules/drivers/serial/mbs_st_m64_core_v10/config/src/serialConfig.c
 *  - Change the .portname of the USART belonging to "console" to "debug"
 *  - Create an aternative USART for the console. for the motorboard, the following settings will do:
 *      .portName     = "console",
 *      .aliasName    = "log",
 *      .usart        = USART1,
 *      .rxPort       = GPIOA,
 *      .rxPin        = GPIO_PinSource10,
 *      .txPort       = GPIOA,
 *      .txPin        = GPIO_PinSource9,
 *
 *  - The debugPort is instatntiated in the debugPort.cpp file. with the name testInternal::dbgPort
 *    To use it in your code, include this file and open the port in a piece of code that is running once at start-up, e.g. a constructor, using the command:
 *
 *    dbgPort.vOpen();
 *
 *    It can then be written to using C++ stream operators, e.g
 *
 *    dbgPort << "a = " << ui32Value << "\n";
 *
 */

namespace testInternal
{
	class  DebugPort
	{
		public:
            DebugPort();

            DebugPort ( const DebugPort& object );

            //! The destructor will only be used in the UnitTest environment.
            virtual ~DebugPort();

            void vOpen();

            DebugPort& operator = ( const DebugPort& object);

            DebugPort& operator << ( const char* str );

            DebugPort& operator << ( const uint16_t ui16Value );

            DebugPort& operator << ( const int16_t si16Value );

            DebugPort& operator << ( const uint32_t ui32Value );

            DebugPort& operator << ( const int32_t si32Value );

            DebugPort& operator << ( const unsigned int uiValue );

            DebugPort& operator << ( const int siValue );

		private:
            static const uint8_t         cui8ScratchPadSize;
            static const HalSerialConfig serConf;
            HalSerialPortHandle          port;
            char*                        strScratchPad;

	};

	extern DebugPort dbgPort;
} /* End of namespace testInternal */
#endif /* _DEBUG_PORT_HPP_ */

/**
  \}
*/
