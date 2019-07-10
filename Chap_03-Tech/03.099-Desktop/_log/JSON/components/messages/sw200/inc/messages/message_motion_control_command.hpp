/**
  \file message_motion_control_command.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message MOTION_CONTROL_COMMAND
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_MOTION_CONTROL_COMMAND_INCLUDE_GUARD
#define MESSAGE_MOTION_CONTROL_COMMAND_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageMotionControlCommand: public messagesInternal::Message
    {
        private:
            MessageMotionControlCommand() = delete;
            MessageMotionControlCommand(const MessageMotionControlCommand& source) = delete;
            MessageMotionControlCommand& operator=(const MessageMotionControlCommand& source) = delete;

        public:
            explicit MessageMotionControlCommand(messages::MessageRouter& messageRouter);
            virtual ~MessageMotionControlCommand();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetCommand(const uint8_t ui8Command);
            uint8_t ui8GetCommand() const;

        private:
            uint8_t m_ui8Command;
    };

}
#endif // MESSAGE_MOTION_CONTROL_COMMAND_INCLUDE_GUARD
