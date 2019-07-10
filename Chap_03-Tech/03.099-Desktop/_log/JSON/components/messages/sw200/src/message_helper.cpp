extern "C" {
    #include <mbsAssert.h>
}
#include "message_helper.hpp"
#include <cstring>

namespace messagesInternal
{

    int8_t MessageHelper::si8GetValue(const uint8_t* const pBuffer, int32_t& io_offset)
    {
        const int32_t offset = io_offset++;
        return static_cast<int8_t>(pBuffer[offset]);//lint !e613 TODO CHECK.
    }

    int16_t MessageHelper::si16GetValue(const uint8_t* const pBuffer, int32_t& io_offset)
    {
        mbsAssert(pBuffer != nullptr);

        uint16_t value = (static_cast<uint16_t>(pBuffer[io_offset]) << 8);
        io_offset++;
        value |= pBuffer[io_offset];
        io_offset++;
        return static_cast<int16_t>(value);
    }

    int32_t MessageHelper::si32GetValue(const uint8_t* const pBuffer, int32_t& io_offset)
    {
        mbsAssert(pBuffer != nullptr);

        uint32_t value = (static_cast<uint32_t>(pBuffer[io_offset]) << 24);
        io_offset++;
        value |= (static_cast<uint32_t>(pBuffer[io_offset]) << 16);
        io_offset++;
        value |= (static_cast<uint32_t>(pBuffer[io_offset]) << 8);
        io_offset++;
        value |= static_cast<uint32_t>(pBuffer[io_offset]);
        io_offset++;
        return static_cast<int32_t>(value);
    }

    uint8_t MessageHelper::ui8GetValue(const uint8_t* const pBuffer, int32_t& io_offset)
    {
        mbsAssert(pBuffer != nullptr);

        const int32_t offset = io_offset;
        io_offset++;
        return pBuffer[offset];
    }

    uint16_t MessageHelper::ui16GetValue(const uint8_t* const pBuffer, int32_t& io_offset)
    {
        mbsAssert(pBuffer != nullptr);

        uint16_t value = (static_cast<uint16_t>(pBuffer[io_offset]) << 8);
        io_offset++;
        value |= static_cast<uint16_t>(pBuffer[io_offset]);
        io_offset++;
        return value;
    }

    uint32_t MessageHelper::ui32GetValue(const uint8_t* const pBuffer, int32_t& io_offset)
    {
        uint32_t value = (static_cast<uint32_t>(pBuffer[io_offset]) << 24);
        io_offset++;
        value |= (static_cast<uint32_t>(pBuffer[io_offset]) << 16);
        io_offset++;
        value |= (static_cast<uint32_t>(pBuffer[io_offset]) << 8);
        io_offset++;
        value |= static_cast<uint32_t>(pBuffer[io_offset]);
        io_offset++;
        return value;
    }

    bool MessageHelper::bGetValue(const uint8_t* const pBuffer, int32_t& io_offset)
    {
        mbsAssert(pBuffer != nullptr);

        const int32_t offset = io_offset;
        io_offset++;
        return (pBuffer[offset] != 0U);
    }

    void MessageHelper::vSetValue(uint8_t* const pBuffer, const int8_t si8Value, int32_t& io_offset)
    {
        pBuffer[io_offset] = static_cast<uint8_t>(si8Value);
        io_offset++;
    }

    void MessageHelper::vSetValue(uint8_t* const pBuffer, const int16_t si16Value, int32_t& io_offset)
    {
        const uint16_t ui16Value = static_cast<uint16_t>(si16Value);
        pBuffer[io_offset] = static_cast<uint8_t>(ui16Value >> 8);
        io_offset++;
        pBuffer[io_offset] = static_cast<uint8_t>(ui16Value & 0xffU);
        io_offset++;
    }

    void MessageHelper::vSetValue(uint8_t* const pBuffer, const int32_t si32Value, int32_t& io_offset)
    {
        const uint32_t ui32Value = static_cast<uint32_t>(si32Value);
        pBuffer[io_offset] = static_cast<uint8_t>(ui32Value >> 24);
        io_offset++;
        pBuffer[io_offset] = static_cast<uint8_t>((ui32Value >> 16) & 0xffU);
        io_offset++;
        pBuffer[io_offset] = static_cast<uint8_t>((ui32Value >> 8) & 0xffU);
        io_offset++;
        pBuffer[io_offset] = static_cast<uint8_t>(ui32Value & 0xffU);
        io_offset++;
    }

    void MessageHelper::vSetValue(uint8_t* const pBuffer, const uint8_t ui8Value, int32_t& io_offset)
    {
        pBuffer[io_offset] = ui8Value;
        io_offset++;
    }

    void MessageHelper::vSetValue(uint8_t* const pBuffer, const uint16_t ui16Value, int32_t& io_offset)
    {
        pBuffer[io_offset] = static_cast<uint8_t>(ui16Value >> 8);
        io_offset++;
        pBuffer[io_offset] = static_cast<uint8_t>(ui16Value & 0xffU);
        io_offset++;
    }

    void MessageHelper::vSetValue(uint8_t* const pBuffer, const uint32_t ui32Value, int32_t& io_offset)
    {
        pBuffer[io_offset] = static_cast<uint8_t>(ui32Value >> 24);
        io_offset++;
        pBuffer[io_offset] = static_cast<uint8_t>((ui32Value >> 16) & 0xffU);
        io_offset++;
        pBuffer[io_offset] = static_cast<uint8_t>((ui32Value >> 8) & 0xffU);
        io_offset++;
        pBuffer[io_offset] = static_cast<uint8_t>(ui32Value & 0xffU);
        io_offset++;
    }

    void MessageHelper::vSetValue(uint8_t* const pBuffer, const bool bValue, int32_t& io_offset)
    {
        pBuffer[io_offset] = bValue ? 1U : 0U;
        io_offset++;
    }

    void MessageHelper::vSetValue(uint8_t* const pBuffer, const uint8_t* const aData, const size_t dataSize, int32_t& io_offset)
    {
        std::memcpy(&pBuffer[io_offset], aData, dataSize);
        io_offset += static_cast<int32_t>(dataSize);
    }
}
