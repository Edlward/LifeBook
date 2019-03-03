
/**
  \file debugPort.cpp

  \par Copyright &copy; 2018 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \addtogroup Test
  \{
 */

extern "C" {
//    #include <mbsAssert.h>
    #include <stdio.h>
    #include <string.h>     //lint !e829 Info 829: A +headerwarn option was previously issued for header 'string.h'
}
#include <cstddef>
#include "../inc/debugPort.hpp"

namespace testInternal
{
    const uint8_t         DebugPort::cui8ScratchPadSize = 20U;
    const HalSerialConfig DebugPort::serConf =
    {
        .baud = 115200,
        .useTxHwFlowControlUsingCts = false,
        .useRxHwFlowControlUsingRts = false,
        .txBufSize = 100,
        .rxBufSize = 20,
        .txDmaBufSize = 20,
        .evListener = NULL,
    };

    DebugPort::DebugPort():
        port( NULL )
	{
        strScratchPad = new char[cui8ScratchPadSize];
	}

    DebugPort::DebugPort ( const DebugPort &object ) :
            port         ( object.port ),
            strScratchPad( object.strScratchPad )
    {
    }

	DebugPort::~DebugPort()
	{
	    halSerialClose( port );
	    port = NULL;
	    delete[] strScratchPad;
	}

    void DebugPort::vOpen()
    {
        halSerialOpen( "debug", &serConf, &port );
    }

    DebugPort& DebugPort::operator = ( const DebugPort& object )
    {
        port = object.port;
        strScratchPad = object.strScratchPad;
        return *this;
    }

	DebugPort& DebugPort::operator << ( const char* str )
    {
        halSerialWriteBytes( port,
                             reinterpret_cast<const uint8_t*>( str ),
                             static_cast<uint32_t>( strlen( str ) ),
                             0,
                             10 );
        return *this;
    }

    DebugPort& DebugPort::operator << ( const uint16_t ui16Value )
    {
        sprintf( strScratchPad, "%u", ui16Value );
        halSerialWriteBytes( port,
                             reinterpret_cast<const uint8_t*>( strScratchPad ),
                             static_cast<uint32_t>( strlen( strScratchPad ) ),
                             0,
                             10 );
        return *this;
    }

    DebugPort& DebugPort::operator << ( const int16_t si16Value )
    {
        sprintf( strScratchPad, "%i", si16Value );
        halSerialWriteBytes( port,
                             reinterpret_cast<const uint8_t*>( strScratchPad ),
                             static_cast<uint32_t>( strlen( strScratchPad ) ),
                             0,
                             10 );
        return *this;
    }

    DebugPort& DebugPort::operator << ( const uint32_t ui32Value )
    {
        sprintf( strScratchPad, "%u", ui32Value );
        halSerialWriteBytes( port,
                             reinterpret_cast<const uint8_t*>( strScratchPad ),
                             static_cast<uint32_t>( strlen( strScratchPad ) ),
                             0,
                             10 );
        return *this;
    }

    DebugPort& DebugPort::operator << ( const int32_t si32Value )
    {
        sprintf( strScratchPad, "%i", si32Value );
        halSerialWriteBytes( port,
                             reinterpret_cast<const uint8_t*>( strScratchPad ),
                             static_cast<uint32_t>( strlen( strScratchPad ) ),
                             0,
                             10 );
        return *this;
    }

    DebugPort& DebugPort::operator << ( const unsigned int uiValue )
    {
        sprintf( strScratchPad, "%u", uiValue );
        halSerialWriteBytes( port,
                             reinterpret_cast<const uint8_t*>( strScratchPad ),
                             static_cast<uint32_t>( strlen( strScratchPad ) ),
                             0,
                             10 );
        return *this;
    }

    DebugPort& DebugPort::operator << ( const int siValue )
    {
        sprintf( strScratchPad, "%i", siValue );
        halSerialWriteBytes( port,
                             reinterpret_cast<const uint8_t*>( strScratchPad ),
                             static_cast<uint32_t>( strlen( strScratchPad ) ),
                             0,
                             10 );
        return *this;
    }

    DebugPort dbgPort;
}
/**
  \}
 */

//lint -e1960 "function without external side-effects" Functions write to register map
