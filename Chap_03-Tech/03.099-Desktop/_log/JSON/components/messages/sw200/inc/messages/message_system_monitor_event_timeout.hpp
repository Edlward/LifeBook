/**
  \file message_system_monitor_event_timeout.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message SYSTEM_MONITOR_EVENT_TIMEOUT
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_SYSTEM_MONITOR_EVENT_TIMEOUT_INCLUDE_GUARD
#define MESSAGE_SYSTEM_MONITOR_EVENT_TIMEOUT_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageSystemMonitorEventTimeout: public messagesInternal::Message
    {
        private:
            MessageSystemMonitorEventTimeout() = delete;
            MessageSystemMonitorEventTimeout(const MessageSystemMonitorEventTimeout& source) = delete;
            MessageSystemMonitorEventTimeout& operator=(const MessageSystemMonitorEventTimeout& source) = delete;

        public:
            explicit MessageSystemMonitorEventTimeout(messages::MessageRouter& messageRouter);
            virtual ~MessageSystemMonitorEventTimeout();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetEvent(const uint8_t ui8Event);
            uint8_t ui8GetEvent() const;

        private:
            uint8_t m_ui8Event;
    };

}
#endif // MESSAGE_SYSTEM_MONITOR_EVENT_TIMEOUT_INCLUDE_GUARD
