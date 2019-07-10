/**
  \file message_door_angle_repetition.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message DOOR_ANGLE_REPETITION
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_DOOR_ANGLE_REPETITION_INCLUDE_GUARD
#define MESSAGE_DOOR_ANGLE_REPETITION_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageDoorAngleRepetition: public messagesInternal::Message
    {
        private:
            MessageDoorAngleRepetition() = delete;
            MessageDoorAngleRepetition(const MessageDoorAngleRepetition& source) = delete;
            MessageDoorAngleRepetition& operator=(const MessageDoorAngleRepetition& source) = delete;

        public:
            explicit MessageDoorAngleRepetition(messages::MessageRouter& messageRouter);
            virtual ~MessageDoorAngleRepetition();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetAngle(const uint16_t ui16Angle);
            uint16_t ui16GetAngle() const;

        private:
            uint16_t m_ui16Angle;
    };

}
#endif // MESSAGE_DOOR_ANGLE_REPETITION_INCLUDE_GUARD
