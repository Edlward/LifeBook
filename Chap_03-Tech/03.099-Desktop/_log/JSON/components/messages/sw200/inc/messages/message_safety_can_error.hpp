/**
  \file message_safety_can_error.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message SAFETY_CAN_ERROR
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_SAFETY_CAN_ERROR_INCLUDE_GUARD
#define MESSAGE_SAFETY_CAN_ERROR_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageSafetyCanError: public messagesInternal::Message
    {
        private:
            MessageSafetyCanError() = delete;
            MessageSafetyCanError(const MessageSafetyCanError& source) = delete;
            MessageSafetyCanError& operator=(const MessageSafetyCanError& source) = delete;

        public:
            explicit MessageSafetyCanError(messages::MessageRouter& messageRouter);
            virtual ~MessageSafetyCanError();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetErrorMessageId(const uint8_t ui8ErrorMessageId);
            uint8_t ui8GetErrorMessageId() const;

            void vSetError(const uint8_t ui8Error);
            uint8_t ui8GetError() const;

        private:
            uint8_t m_ui8ErrorMessageId;
            uint8_t m_ui8Error;
    };

}
#endif // MESSAGE_SAFETY_CAN_ERROR_INCLUDE_GUARD
