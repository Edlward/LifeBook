/**
  \file message_request_status.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message REQUEST_STATUS
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_REQUEST_STATUS_INCLUDE_GUARD
#define MESSAGE_REQUEST_STATUS_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageRequestStatus: public messagesInternal::Message
    {
        private:
            MessageRequestStatus() = delete;
            MessageRequestStatus(const MessageRequestStatus& source) = delete;
            MessageRequestStatus& operator=(const MessageRequestStatus& source) = delete;

        public:
            explicit MessageRequestStatus(messages::MessageRouter& messageRouter);
            virtual ~MessageRequestStatus();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetKeys(const uint8_t aKeys[2]);
            const uint8_t* pGetKeys() const;

        private:
            uint8_t m_aKeys[2];
    };

}
#endif // MESSAGE_REQUEST_STATUS_INCLUDE_GUARD
