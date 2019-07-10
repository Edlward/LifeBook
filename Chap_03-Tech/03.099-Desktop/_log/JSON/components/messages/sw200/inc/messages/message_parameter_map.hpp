/**
  \file message_parameter_map.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message PARAMETER_MAP
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_PARAMETER_MAP_INCLUDE_GUARD
#define MESSAGE_PARAMETER_MAP_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageParameterMap: public messagesInternal::Message
    {
        private:
            MessageParameterMap() = delete;
            MessageParameterMap(const MessageParameterMap& source) = delete;
            MessageParameterMap& operator=(const MessageParameterMap& source) = delete;

        public:
            explicit MessageParameterMap(messages::MessageRouter& messageRouter);
            virtual ~MessageParameterMap();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetCount(const int32_t si32Count);
            int32_t si32GetCount() const;

            void vSetMap(const uint8_t aMap[3]);
            const uint8_t* pGetMap() const;

        private:
            int32_t m_si32Count;
            uint8_t m_aMap[3];
    };

}
#endif // MESSAGE_PARAMETER_MAP_INCLUDE_GUARD
