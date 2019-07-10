/**
  \file message_status.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message STATUS
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_STATUS_INCLUDE_GUARD
#define MESSAGE_STATUS_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageStatus: public messagesInternal::Message
    {
        private:
            MessageStatus() = delete;
            MessageStatus(const MessageStatus& source) = delete;
            MessageStatus& operator=(const MessageStatus& source) = delete;

        public:
            explicit MessageStatus(messages::MessageRouter& messageRouter);
            virtual ~MessageStatus();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetKey(const uint8_t ui8Key);
            uint8_t ui8GetKey() const;

            void vSetTaskId(const int8_t si8TaskId);
            int8_t si8GetTaskId() const;

        private:
            uint8_t m_ui8Key;
            int8_t m_si8TaskId;
    };

}
#endif // MESSAGE_STATUS_INCLUDE_GUARD
