/**
  \file message_ble_status_updated.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message BLE_STATUS_UPDATED
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_BLE_STATUS_UPDATED_INCLUDE_GUARD
#define MESSAGE_BLE_STATUS_UPDATED_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageBleStatusUpdated: public messagesInternal::Message
    {
        private:
            MessageBleStatusUpdated() = delete;
            MessageBleStatusUpdated(const MessageBleStatusUpdated& source) = delete;
            MessageBleStatusUpdated& operator=(const MessageBleStatusUpdated& source) = delete;

        public:
            explicit MessageBleStatusUpdated(messages::MessageRouter& messageRouter);
            virtual ~MessageBleStatusUpdated();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetConnection(const uint8_t ui8Connection);
            uint8_t ui8GetConnection() const;

        private:
            uint8_t m_ui8Connection;
    };

}
#endif // MESSAGE_BLE_STATUS_UPDATED_INCLUDE_GUARD
