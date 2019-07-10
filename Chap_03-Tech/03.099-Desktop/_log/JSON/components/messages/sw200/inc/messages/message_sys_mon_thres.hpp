/**
  \file message_sys_mon_thres.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message SYS_MON_THRES
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_SYS_MON_THRES_INCLUDE_GUARD
#define MESSAGE_SYS_MON_THRES_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageSysMonThres: public messagesInternal::Message
    {
        private:
            MessageSysMonThres() = delete;
            MessageSysMonThres(const MessageSysMonThres& source) = delete;
            MessageSysMonThres& operator=(const MessageSysMonThres& source) = delete;

        public:
            explicit MessageSysMonThres(messages::MessageRouter& messageRouter);
            virtual ~MessageSysMonThres();

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
#endif // MESSAGE_SYS_MON_THRES_INCLUDE_GUARD
