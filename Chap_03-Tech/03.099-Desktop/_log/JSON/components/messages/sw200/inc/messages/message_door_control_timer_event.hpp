/**
  \file message_door_control_timer_event.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message DOOR_CONTROL_TIMER_EVENT
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_DOOR_CONTROL_TIMER_EVENT_INCLUDE_GUARD
#define MESSAGE_DOOR_CONTROL_TIMER_EVENT_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageDoorControlTimerEvent: public messagesInternal::Message
    {
        private:
            MessageDoorControlTimerEvent() = delete;
            MessageDoorControlTimerEvent(const MessageDoorControlTimerEvent& source) = delete;
            MessageDoorControlTimerEvent& operator=(const MessageDoorControlTimerEvent& source) = delete;

        public:
            explicit MessageDoorControlTimerEvent(messages::MessageRouter& messageRouter);
            virtual ~MessageDoorControlTimerEvent();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetEvent(const uint8_t ui8Event);
            uint8_t ui8GetEvent() const;

        private:
            uint8_t m_ui8Event;
    };

}
#endif // MESSAGE_DOOR_CONTROL_TIMER_EVENT_INCLUDE_GUARD
