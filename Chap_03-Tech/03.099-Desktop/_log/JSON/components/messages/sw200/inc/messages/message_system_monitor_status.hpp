/**
  \file message_system_monitor_status.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message SYSTEM_MONITOR_STATUS
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_SYSTEM_MONITOR_STATUS_INCLUDE_GUARD
#define MESSAGE_SYSTEM_MONITOR_STATUS_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageSystemMonitorStatus: public messagesInternal::Message
    {
        private:
            MessageSystemMonitorStatus() = delete;
            MessageSystemMonitorStatus(const MessageSystemMonitorStatus& source) = delete;
            MessageSystemMonitorStatus& operator=(const MessageSystemMonitorStatus& source) = delete;

        public:
            explicit MessageSystemMonitorStatus(messages::MessageRouter& messageRouter);
            virtual ~MessageSystemMonitorStatus();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetStatus(const uint8_t ui8Status);
            uint8_t ui8GetStatus() const;

        private:
            uint8_t m_ui8Status;
    };

}
#endif // MESSAGE_SYSTEM_MONITOR_STATUS_INCLUDE_GUARD
