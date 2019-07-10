/**
  \file message_program_override.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message PROGRAM_OVERRIDE
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_PROGRAM_OVERRIDE_INCLUDE_GUARD
#define MESSAGE_PROGRAM_OVERRIDE_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageProgramOverride: public messagesInternal::Message
    {
        private:
            MessageProgramOverride() = delete;
            MessageProgramOverride(const MessageProgramOverride& source) = delete;
            MessageProgramOverride& operator=(const MessageProgramOverride& source) = delete;

        public:
            explicit MessageProgramOverride(messages::MessageRouter& messageRouter);
            virtual ~MessageProgramOverride();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetProgram(const uint8_t ui8Program);
            uint8_t ui8GetProgram() const;

        private:
            uint8_t m_ui8Program;
    };

}
#endif // MESSAGE_PROGRAM_OVERRIDE_INCLUDE_GUARD
