/**
  \file message_iso_tp_frame.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message ISO_TP_FRAME
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_ISO_TP_FRAME_INCLUDE_GUARD
#define MESSAGE_ISO_TP_FRAME_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageIsoTpFrame: public messagesInternal::Message
    {
        private:
            MessageIsoTpFrame() = delete;
            MessageIsoTpFrame(const MessageIsoTpFrame& source) = delete;
            MessageIsoTpFrame& operator=(const MessageIsoTpFrame& source) = delete;

        public:
            explicit MessageIsoTpFrame(messages::MessageRouter& messageRouter);
            virtual ~MessageIsoTpFrame();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetData(const uint8_t aData[8]);
            const uint8_t* pGetData() const;

        private:
            uint8_t m_aData[8];
    };

}
#endif // MESSAGE_ISO_TP_FRAME_INCLUDE_GUARD
