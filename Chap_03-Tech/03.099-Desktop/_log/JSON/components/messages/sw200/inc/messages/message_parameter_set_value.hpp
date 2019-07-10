/**
  \file message_parameter_set_value.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message PARAMETER_SET_VALUE
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_PARAMETER_SET_VALUE_INCLUDE_GUARD
#define MESSAGE_PARAMETER_SET_VALUE_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageParameterSetValue: public messagesInternal::Message
    {
        private:
            MessageParameterSetValue() = delete;
            MessageParameterSetValue(const MessageParameterSetValue& source) = delete;
            MessageParameterSetValue& operator=(const MessageParameterSetValue& source) = delete;

        public:
            explicit MessageParameterSetValue(messages::MessageRouter& messageRouter);
            virtual ~MessageParameterSetValue();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetId(const int32_t si32Id);
            int32_t si32GetId() const;

            void vSetValue(const int32_t si32Value);
            int32_t si32GetValue() const;

        private:
            int32_t m_si32Id;
            int32_t m_si32Value;
    };

}
#endif // MESSAGE_PARAMETER_SET_VALUE_INCLUDE_GUARD
