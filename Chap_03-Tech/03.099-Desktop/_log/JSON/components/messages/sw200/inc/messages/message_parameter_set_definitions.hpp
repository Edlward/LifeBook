/**
  \file message_parameter_set_definitions.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message PARAMETER_SET_DEFINITIONS
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_PARAMETER_SET_DEFINITIONS_INCLUDE_GUARD
#define MESSAGE_PARAMETER_SET_DEFINITIONS_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageParameterSetDefinitions: public messagesInternal::Message
    {
        private:
            MessageParameterSetDefinitions() = delete;
            MessageParameterSetDefinitions(const MessageParameterSetDefinitions& source) = delete;
            MessageParameterSetDefinitions& operator=(const MessageParameterSetDefinitions& source) = delete;

        public:
            explicit MessageParameterSetDefinitions(messages::MessageRouter& messageRouter);
            virtual ~MessageParameterSetDefinitions();

            virtual bool bReceive() final;
            virtual void vSend() final;
    };

}
#endif // MESSAGE_PARAMETER_SET_DEFINITIONS_INCLUDE_GUARD
