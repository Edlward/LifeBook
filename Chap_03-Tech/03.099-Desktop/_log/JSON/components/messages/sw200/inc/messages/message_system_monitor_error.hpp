/**
  \file message_system_monitor_error.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message SYSTEM_MONITOR_ERROR
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_SYSTEM_MONITOR_ERROR_INCLUDE_GUARD
#define MESSAGE_SYSTEM_MONITOR_ERROR_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageSystemMonitorError: public messagesInternal::Message
    {
        private:
            MessageSystemMonitorError() = delete;
            MessageSystemMonitorError(const MessageSystemMonitorError& source) = delete;
            MessageSystemMonitorError& operator=(const MessageSystemMonitorError& source) = delete;

        public:
            explicit MessageSystemMonitorError(messages::MessageRouter& messageRouter);
            virtual ~MessageSystemMonitorError();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetError(const uint8_t ui8Error);
            uint8_t ui8GetError() const;

        private:
            uint8_t m_ui8Error;
    };

}
#endif // MESSAGE_SYSTEM_MONITOR_ERROR_INCLUDE_GUARD
