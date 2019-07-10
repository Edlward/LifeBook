/**
  \file message_abort_impulses_timeout.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message ABORT_IMPULSES_TIMEOUT
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_ABORT_IMPULSES_TIMEOUT_INCLUDE_GUARD
#define MESSAGE_ABORT_IMPULSES_TIMEOUT_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageAbortImpulsesTimeout: public messagesInternal::Message
    {
        private:
            MessageAbortImpulsesTimeout() = delete;
            MessageAbortImpulsesTimeout(const MessageAbortImpulsesTimeout& source) = delete;
            MessageAbortImpulsesTimeout& operator=(const MessageAbortImpulsesTimeout& source) = delete;

        public:
            explicit MessageAbortImpulsesTimeout(messages::MessageRouter& messageRouter);
            virtual ~MessageAbortImpulsesTimeout();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetAbort(const bool bAbort);
            bool bGetAbort() const;

        private:
            bool m_bAbort;
    };

}
#endif // MESSAGE_ABORT_IMPULSES_TIMEOUT_INCLUDE_GUARD
