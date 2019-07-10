/**
  \file message_clear_error.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message CLEAR_ERROR
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_CLEAR_ERROR_INCLUDE_GUARD
#define MESSAGE_CLEAR_ERROR_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageClearError: public messagesInternal::Message
    {
        private:
            MessageClearError() = delete;
            MessageClearError(const MessageClearError& source) = delete;
            MessageClearError& operator=(const MessageClearError& source) = delete;

        public:
            explicit MessageClearError(messages::MessageRouter& messageRouter);
            virtual ~MessageClearError();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetErrorCode(const uint8_t ui8ErrorCode);
            uint8_t ui8GetErrorCode() const;

        private:
            uint8_t m_ui8ErrorCode;
    };

}
#endif // MESSAGE_CLEAR_ERROR_INCLUDE_GUARD
