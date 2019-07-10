/**
  \file message_parameter_updated.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message PARAMETER_UPDATED
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_PARAMETER_UPDATED_INCLUDE_GUARD
#define MESSAGE_PARAMETER_UPDATED_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageParameterUpdated: public messagesInternal::Message
    {
        private:
            MessageParameterUpdated() = delete;
            MessageParameterUpdated(const MessageParameterUpdated& source) = delete;
            MessageParameterUpdated& operator=(const MessageParameterUpdated& source) = delete;

        public:
            explicit MessageParameterUpdated(messages::MessageRouter& messageRouter);
            virtual ~MessageParameterUpdated();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetErrorCode(const uint8_t ui8ErrorCode);
            uint8_t ui8GetErrorCode() const;

            void vSetId(const int16_t si16Id);
            int16_t si16GetId() const;

            void vSetValue(const int32_t si32Value);
            int32_t si32GetValue() const;

        private:
            uint8_t m_ui8ErrorCode;
            int16_t m_si16Id;
            int32_t m_si32Value;
    };

}
#endif // MESSAGE_PARAMETER_UPDATED_INCLUDE_GUARD
