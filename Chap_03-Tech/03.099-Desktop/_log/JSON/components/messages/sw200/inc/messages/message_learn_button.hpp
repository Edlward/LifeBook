/**
  \file message_learn_button.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message LEARN_BUTTON
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_LEARN_BUTTON_INCLUDE_GUARD
#define MESSAGE_LEARN_BUTTON_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageLearnButton: public messagesInternal::Message
    {
        private:
            MessageLearnButton() = delete;
            MessageLearnButton(const MessageLearnButton& source) = delete;
            MessageLearnButton& operator=(const MessageLearnButton& source) = delete;

        public:
            explicit MessageLearnButton(messages::MessageRouter& messageRouter);
            virtual ~MessageLearnButton();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetActive(const bool bActive);
            bool bGetActive() const;

        private:
            bool m_bActive;
    };

}
#endif // MESSAGE_LEARN_BUTTON_INCLUDE_GUARD
