/**
  \file message_safety_impulse.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message SAFETY_IMPULSE
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_SAFETY_IMPULSE_INCLUDE_GUARD
#define MESSAGE_SAFETY_IMPULSE_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageSafetyImpulse: public messagesInternal::Message
    {
        private:
            MessageSafetyImpulse() = delete;
            MessageSafetyImpulse(const MessageSafetyImpulse& source) = delete;
            MessageSafetyImpulse& operator=(const MessageSafetyImpulse& source) = delete;

        public:
            explicit MessageSafetyImpulse(messages::MessageRouter& messageRouter);
            virtual ~MessageSafetyImpulse();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetActive(const bool bActive);
            bool bGetActive() const;

            void vSetCrc8(const uint8_t ui8Crc8);
            uint8_t ui8GetCrc8() const;

            void vSetType(const uint8_t ui8Type);
            uint8_t ui8GetType() const;

            void vSetSequenceNumber(const uint8_t ui8SequenceNumber);
            uint8_t ui8GetSequenceNumber() const;

        private:
            bool m_bActive;
            uint8_t m_ui8Crc8;
            uint8_t m_ui8Type;
            uint8_t m_ui8SequenceNumber;
    };

}
#endif // MESSAGE_SAFETY_IMPULSE_INCLUDE_GUARD
