/**
  \file message_motion_control_status.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message MOTION_CONTROL_STATUS
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_MOTION_CONTROL_STATUS_INCLUDE_GUARD
#define MESSAGE_MOTION_CONTROL_STATUS_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageMotionControlStatus: public messagesInternal::Message
    {
        private:
            MessageMotionControlStatus() = delete;
            MessageMotionControlStatus(const MessageMotionControlStatus& source) = delete;
            MessageMotionControlStatus& operator=(const MessageMotionControlStatus& source) = delete;

        public:
            explicit MessageMotionControlStatus(messages::MessageRouter& messageRouter);
            virtual ~MessageMotionControlStatus();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetStatus(const uint8_t ui8Status);
            uint8_t ui8GetStatus() const;

        private:
            uint8_t m_ui8Status;
    };

}
#endif // MESSAGE_MOTION_CONTROL_STATUS_INCLUDE_GUARD
