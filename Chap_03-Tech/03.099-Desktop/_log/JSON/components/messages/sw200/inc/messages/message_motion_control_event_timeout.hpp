/**
  \file message_motion_control_event_timeout.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message MOTION_CONTROL_EVENT_TIMEOUT
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_MOTION_CONTROL_EVENT_TIMEOUT_INCLUDE_GUARD
#define MESSAGE_MOTION_CONTROL_EVENT_TIMEOUT_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageMotionControlEventTimeout: public messagesInternal::Message
    {
        private:
            MessageMotionControlEventTimeout() = delete;
            MessageMotionControlEventTimeout(const MessageMotionControlEventTimeout& source) = delete;
            MessageMotionControlEventTimeout& operator=(const MessageMotionControlEventTimeout& source) = delete;

        public:
            explicit MessageMotionControlEventTimeout(messages::MessageRouter& messageRouter);
            virtual ~MessageMotionControlEventTimeout();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetEvent(const uint8_t ui8Event);
            uint8_t ui8GetEvent() const;

        private:
            uint8_t m_ui8Event;
    };

}
#endif // MESSAGE_MOTION_CONTROL_EVENT_TIMEOUT_INCLUDE_GUARD
