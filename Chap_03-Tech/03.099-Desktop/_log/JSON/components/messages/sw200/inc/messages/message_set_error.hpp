/**
  \file message_set_error.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message SET_ERROR
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_SET_ERROR_INCLUDE_GUARD
#define MESSAGE_SET_ERROR_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageSetError: public messagesInternal::Message
    {
        private:
            MessageSetError() = delete;
            MessageSetError(const MessageSetError& source) = delete;
            MessageSetError& operator=(const MessageSetError& source) = delete;

        public:
            explicit MessageSetError(messages::MessageRouter& messageRouter);
            virtual ~MessageSetError();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetErrorCode(const uint8_t ui8ErrorCode);
            uint8_t ui8GetErrorCode() const;

        private:
            uint8_t m_ui8ErrorCode;
    };

}
#endif // MESSAGE_SET_ERROR_INCLUDE_GUARD
