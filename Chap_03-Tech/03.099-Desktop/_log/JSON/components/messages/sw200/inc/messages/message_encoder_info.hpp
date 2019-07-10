/**
  \file message_encoder_info.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message ENCODER_INFO
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_ENCODER_INFO_INCLUDE_GUARD
#define MESSAGE_ENCODER_INFO_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageEncoderInfo: public messagesInternal::Message
    {
        private:
            MessageEncoderInfo() = delete;
            MessageEncoderInfo(const MessageEncoderInfo& source) = delete;
            MessageEncoderInfo& operator=(const MessageEncoderInfo& source) = delete;

        public:
            explicit MessageEncoderInfo(messages::MessageRouter& messageRouter);
            virtual ~MessageEncoderInfo();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetAngle(const int32_t si32Angle);
            int32_t si32GetAngle() const;

            void vSetShaftSpeed(const int16_t si16ShaftSpeed);
            int16_t si16GetShaftSpeed() const;

        private:
            int32_t m_si32Angle;
            int16_t m_si16ShaftSpeed;
    };

}
#endif // MESSAGE_ENCODER_INFO_INCLUDE_GUARD
