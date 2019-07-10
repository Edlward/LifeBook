/**
  \file message_program_updated.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message PROGRAM_UPDATED
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_PROGRAM_UPDATED_INCLUDE_GUARD
#define MESSAGE_PROGRAM_UPDATED_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageProgramUpdated: public messagesInternal::Message
    {
        private:
            MessageProgramUpdated() = delete;
            MessageProgramUpdated(const MessageProgramUpdated& source) = delete;
            MessageProgramUpdated& operator=(const MessageProgramUpdated& source) = delete;

        public:
            explicit MessageProgramUpdated(messages::MessageRouter& messageRouter);
            virtual ~MessageProgramUpdated();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetNewProgram(const uint8_t ui8NewProgram);
            uint8_t ui8GetNewProgram() const;

        private:
            uint8_t m_ui8NewProgram;
    };

}
#endif // MESSAGE_PROGRAM_UPDATED_INCLUDE_GUARD
