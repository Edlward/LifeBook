/**
  \file message_learn_command_error.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message LEARN_COMMAND_ERROR
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_LEARN_COMMAND_ERROR_INCLUDE_GUARD
#define MESSAGE_LEARN_COMMAND_ERROR_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageLearnCommandError: public messagesInternal::Message
    {
        private:
            MessageLearnCommandError() = delete;
            MessageLearnCommandError(const MessageLearnCommandError& source) = delete;
            MessageLearnCommandError& operator=(const MessageLearnCommandError& source) = delete;

        public:
            explicit MessageLearnCommandError(messages::MessageRouter& messageRouter);
            virtual ~MessageLearnCommandError();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetActive(const bool bActive);
            bool bGetActive() const;

        private:
            bool m_bActive;
    };

}
#endif // MESSAGE_LEARN_COMMAND_ERROR_INCLUDE_GUARD
