/**
  \file message_software_reset.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message SOFTWARE_RESET
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_SOFTWARE_RESET_INCLUDE_GUARD
#define MESSAGE_SOFTWARE_RESET_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageSoftwareReset: public messagesInternal::Message
    {
        private:
            MessageSoftwareReset() = delete;
            MessageSoftwareReset(const MessageSoftwareReset& source) = delete;
            MessageSoftwareReset& operator=(const MessageSoftwareReset& source) = delete;

        public:
            explicit MessageSoftwareReset(messages::MessageRouter& messageRouter);
            virtual ~MessageSoftwareReset();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetStatus(const bool bStatus);
            bool bGetStatus() const;

        private:
            bool m_bStatus;
    };

}
#endif // MESSAGE_SOFTWARE_RESET_INCLUDE_GUARD
