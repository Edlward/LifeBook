/**
  \file message_helper.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Helper class for converting to and from data types in messages.
  \author Daniel Hellsson

**/

//lint -e1960 // Spurious error message
#ifndef _MESSAGE_HELPER_HEADER_FILE_INCLUDE_GUARD_
#define _MESSAGE_HELPER_HEADER_FILE_INCLUDE_GUARD_

#include <stdint.h>

namespace messagesInternal
{
    class MessageHelper
    {
    public:
        MessageHelper() = delete;
        MessageHelper(const MessageHelper& source) = delete;

        static int8_t si8GetValue(const uint8_t* const pBuffer, int32_t& io_offset);
        static int16_t si16GetValue(const uint8_t* const pBuffer, int32_t& io_offset);
        static int32_t si32GetValue(const uint8_t* const pBuffer, int32_t& io_offset);
        static uint8_t ui8GetValue(const uint8_t* const pBuffer, int32_t& io_offset);
        static uint16_t ui16GetValue(const uint8_t* const pBuffer, int32_t& io_offset);
        static uint32_t ui32GetValue(const uint8_t* const pBuffer, int32_t& io_offset);
        static bool bGetValue(const uint8_t* const pBuffer, int32_t& io_offset);

        static void vSetValue(uint8_t* const pBuffer, const int8_t si8Value, int32_t& io_offset);
        static void vSetValue(uint8_t* const pBuffer, const int16_t si16Value, int32_t& io_offset);
        static void vSetValue(uint8_t* const pBuffer, const int32_t si32Value, int32_t& io_offset);
        static void vSetValue(uint8_t* const pBuffer, const uint8_t ui8Value, int32_t& io_offset);
        static void vSetValue(uint8_t* const pBuffer, const uint16_t ui16Value, int32_t& io_offset);
        static void vSetValue(uint8_t* const pBuffer, const uint32_t ui32Value, int32_t& io_offset);
        static void vSetValue(uint8_t* const pBuffer, const bool bValue, int32_t& io_offset);

        static void vSetValue(uint8_t* const pBuffer, const uint8_t aData[], const size_t dataSize, int32_t& io_offset);
    };
}

#endif // _MESSAGE_HELPER_HEADER_FILE_INCLUDE_GUARD_
