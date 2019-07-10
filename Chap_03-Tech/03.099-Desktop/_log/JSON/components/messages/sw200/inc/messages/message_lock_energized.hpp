/**
  \file message_lock_energized.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message LOCK_ENERGIZED
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_LOCK_ENERGIZED_INCLUDE_GUARD
#define MESSAGE_LOCK_ENERGIZED_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageLockEnergized: public messagesInternal::Message
    {
        private:
            MessageLockEnergized() = delete;
            MessageLockEnergized(const MessageLockEnergized& source) = delete;
            MessageLockEnergized& operator=(const MessageLockEnergized& source) = delete;

        public:
            explicit MessageLockEnergized(messages::MessageRouter& messageRouter);
            virtual ~MessageLockEnergized();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetRequest(const bool bRequest);
            bool bGetRequest() const;

        private:
            bool m_bRequest;
    };

}
#endif // MESSAGE_LOCK_ENERGIZED_INCLUDE_GUARD
