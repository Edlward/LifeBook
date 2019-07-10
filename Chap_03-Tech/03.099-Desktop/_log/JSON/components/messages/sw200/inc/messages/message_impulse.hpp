/**
  \file message_impulse.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message IMPULSE
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_IMPULSE_INCLUDE_GUARD
#define MESSAGE_IMPULSE_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageImpulse: public messagesInternal::Message
    {
        private:
            MessageImpulse() = delete;
            MessageImpulse(const MessageImpulse& source) = delete;
            MessageImpulse& operator=(const MessageImpulse& source) = delete;

        public:
            explicit MessageImpulse(messages::MessageRouter& messageRouter);
            virtual ~MessageImpulse();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetActive(const bool bActive);
            bool bGetActive() const;

            void vSetType(const uint8_t ui8Type);
            uint8_t ui8GetType() const;

        private:
            bool m_bActive;
            uint8_t m_ui8Type;
    };

}
#endif // MESSAGE_IMPULSE_INCLUDE_GUARD
