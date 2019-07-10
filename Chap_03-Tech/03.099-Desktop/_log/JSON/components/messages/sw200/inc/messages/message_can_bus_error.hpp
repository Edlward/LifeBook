/**
  \file message_can_bus_error.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message CAN_BUS_ERROR
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_CAN_BUS_ERROR_INCLUDE_GUARD
#define MESSAGE_CAN_BUS_ERROR_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageCanBusError: public messagesInternal::Message
    {
        private:
            MessageCanBusError() = delete;
            MessageCanBusError(const MessageCanBusError& source) = delete;
            MessageCanBusError& operator=(const MessageCanBusError& source) = delete;

        public:
            explicit MessageCanBusError(messages::MessageRouter& messageRouter);
            virtual ~MessageCanBusError();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetActive(const bool bActive);
            bool bGetActive() const;

        private:
            bool m_bActive;
    };

}
#endif // MESSAGE_CAN_BUS_ERROR_INCLUDE_GUARD
