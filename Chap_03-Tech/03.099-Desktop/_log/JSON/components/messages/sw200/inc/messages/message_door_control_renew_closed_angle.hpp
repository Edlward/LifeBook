/**
  \file message_door_control_renew_closed_angle.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message DOOR_CONTROL_RENEW_CLOSED_ANGLE
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_DOOR_CONTROL_RENEW_CLOSED_ANGLE_INCLUDE_GUARD
#define MESSAGE_DOOR_CONTROL_RENEW_CLOSED_ANGLE_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageDoorControlRenewClosedAngle: public messagesInternal::Message
    {
        private:
            MessageDoorControlRenewClosedAngle() = delete;
            MessageDoorControlRenewClosedAngle(const MessageDoorControlRenewClosedAngle& source) = delete;
            MessageDoorControlRenewClosedAngle& operator=(const MessageDoorControlRenewClosedAngle& source) = delete;

        public:
            explicit MessageDoorControlRenewClosedAngle(messages::MessageRouter& messageRouter);
            virtual ~MessageDoorControlRenewClosedAngle();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetRenew(const bool bRenew);
            bool bGetRenew() const;

        private:
            bool m_bRenew;
    };

}
#endif // MESSAGE_DOOR_CONTROL_RENEW_CLOSED_ANGLE_INCLUDE_GUARD
