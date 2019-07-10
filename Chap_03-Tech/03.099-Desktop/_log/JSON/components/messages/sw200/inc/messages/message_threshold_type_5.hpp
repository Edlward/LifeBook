/**
  \file message_threshold_type_5.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message THRESHOLD_TYPE_5
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_THRESHOLD_TYPE_5_INCLUDE_GUARD
#define MESSAGE_THRESHOLD_TYPE_5_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageThresholdType5: public messagesInternal::Message
    {
        private:
            MessageThresholdType5() = delete;
            MessageThresholdType5(const MessageThresholdType5& source) = delete;
            MessageThresholdType5& operator=(const MessageThresholdType5& source) = delete;

        public:
            explicit MessageThresholdType5(messages::MessageRouter& messageRouter);
            virtual ~MessageThresholdType5();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetStatus(const uint8_t ui8Status);
            uint8_t ui8GetStatus() const;

            void vSetId(const uint8_t ui8Id);
            uint8_t ui8GetId() const;

            void vSetLevel(const int32_t si32Level);
            int32_t si32GetLevel() const;

        private:
            uint8_t m_ui8Status;
            uint8_t m_ui8Id;
            int32_t m_si32Level;
    };

}
#endif // MESSAGE_THRESHOLD_TYPE_5_INCLUDE_GUARD
