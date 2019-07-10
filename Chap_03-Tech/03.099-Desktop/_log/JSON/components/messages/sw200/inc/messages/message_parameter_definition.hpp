/**
  \file message_parameter_definition.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message PARAMETER_DEFINITION
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_PARAMETER_DEFINITION_INCLUDE_GUARD
#define MESSAGE_PARAMETER_DEFINITION_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageParameterDefinition: public messagesInternal::Message
    {
        private:
            MessageParameterDefinition() = delete;
            MessageParameterDefinition(const MessageParameterDefinition& source) = delete;
            MessageParameterDefinition& operator=(const MessageParameterDefinition& source) = delete;

        public:
            explicit MessageParameterDefinition(messages::MessageRouter& messageRouter);
            virtual ~MessageParameterDefinition();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetMin(const int32_t si32Min);
            int32_t si32GetMin() const;

            void vSetMax(const int32_t si32Max);
            int32_t si32GetMax() const;

            void vSetDefaultValue(const int32_t si32DefaultValue);
            int32_t si32GetDefaultValue() const;

            void vSetWriteLevel(const int32_t si32WriteLevel);
            int32_t si32GetWriteLevel() const;

            void vSetReadLevel(const int32_t si32ReadLevel);
            int32_t si32GetReadLevel() const;

            void vSetId(const int32_t si32Id);
            int32_t si32GetId() const;

            void vSetType(const uint8_t ui8Type);
            uint8_t ui8GetType() const;

            void vSetFreezeFlags(const int32_t si32FreezeFlags);
            int32_t si32GetFreezeFlags() const;

        private:
            int32_t m_si32Min;
            int32_t m_si32Max;
            int32_t m_si32DefaultValue;
            int32_t m_si32WriteLevel;
            int32_t m_si32ReadLevel;
            int32_t m_si32Id;
            uint8_t m_ui8Type;
            int32_t m_si32FreezeFlags;
    };

}
#endif // MESSAGE_PARAMETER_DEFINITION_INCLUDE_GUARD
