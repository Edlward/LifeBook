/**
  \file message_heart_beat.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message HEART_BEAT
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_HEART_BEAT_INCLUDE_GUARD
#define MESSAGE_HEART_BEAT_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageHeartBeat: public messagesInternal::Message
    {
        private:
            MessageHeartBeat() = delete;
            MessageHeartBeat(const MessageHeartBeat& source) = delete;
            MessageHeartBeat& operator=(const MessageHeartBeat& source) = delete;

        public:
            explicit MessageHeartBeat(messages::MessageRouter& messageRouter);
            virtual ~MessageHeartBeat();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetCrc8(const uint8_t ui8Crc8);
            uint8_t ui8GetCrc8() const;

            void vSetSequenceNumber(const uint8_t ui8SequenceNumber);
            uint8_t ui8GetSequenceNumber() const;

        private:
            uint8_t m_ui8Crc8;
            uint8_t m_ui8SequenceNumber;
    };

}
#endif // MESSAGE_HEART_BEAT_INCLUDE_GUARD
