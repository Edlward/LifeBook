/**
  \file message_not_used.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message NOT_USED
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_NOT_USED_INCLUDE_GUARD
#define MESSAGE_NOT_USED_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageNotUsed: public messagesInternal::Message
    {
        private:
            MessageNotUsed() = delete;
            MessageNotUsed(const MessageNotUsed& source) = delete;
            MessageNotUsed& operator=(const MessageNotUsed& source) = delete;

        public:
            explicit MessageNotUsed(messages::MessageRouter& messageRouter);
            virtual ~MessageNotUsed();

            virtual bool bReceive() final;
            virtual void vSend() final;
    };

}
#endif // MESSAGE_NOT_USED_INCLUDE_GUARD
