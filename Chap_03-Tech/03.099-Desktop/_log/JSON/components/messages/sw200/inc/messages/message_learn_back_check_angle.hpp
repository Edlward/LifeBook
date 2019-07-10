/**
  \file message_learn_back_check_angle.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message LEARN_BACK_CHECK_ANGLE
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_LEARN_BACK_CHECK_ANGLE_INCLUDE_GUARD
#define MESSAGE_LEARN_BACK_CHECK_ANGLE_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageLearnBackCheckAngle: public messagesInternal::Message
    {
        private:
            MessageLearnBackCheckAngle() = delete;
            MessageLearnBackCheckAngle(const MessageLearnBackCheckAngle& source) = delete;
            MessageLearnBackCheckAngle& operator=(const MessageLearnBackCheckAngle& source) = delete;

        public:
            explicit MessageLearnBackCheckAngle(messages::MessageRouter& messageRouter);
            virtual ~MessageLearnBackCheckAngle();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetAngle(const uint16_t ui16Angle);
            uint16_t ui16GetAngle() const;

        private:
            uint16_t m_ui16Angle;
    };

}
#endif // MESSAGE_LEARN_BACK_CHECK_ANGLE_INCLUDE_GUARD
