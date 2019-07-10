/**
  \file message_parameter_get_data.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message PARAMETER_GET_DATA
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_PARAMETER_GET_DATA_INCLUDE_GUARD
#define MESSAGE_PARAMETER_GET_DATA_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageParameterGetData: public messagesInternal::Message
    {
        private:
            MessageParameterGetData() = delete;
            MessageParameterGetData(const MessageParameterGetData& source) = delete;
            MessageParameterGetData& operator=(const MessageParameterGetData& source) = delete;

        public:
            explicit MessageParameterGetData(messages::MessageRouter& messageRouter);
            virtual ~MessageParameterGetData();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetType(const uint8_t ui8Type);
            uint8_t ui8GetType() const;

            void vSetId(const int32_t si32Id);
            int32_t si32GetId() const;

        private:
            uint8_t m_ui8Type;
            int32_t m_si32Id;
    };

}
#endif // MESSAGE_PARAMETER_GET_DATA_INCLUDE_GUARD
