/**
  \file message_learn_results.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message LEARN_RESULTS
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_LEARN_RESULTS_INCLUDE_GUARD
#define MESSAGE_LEARN_RESULTS_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageLearnResults: public messagesInternal::Message
    {
        private:
            MessageLearnResults() = delete;
            MessageLearnResults(const MessageLearnResults& source) = delete;
            MessageLearnResults& operator=(const MessageLearnResults& source) = delete;

        public:
            explicit MessageLearnResults(messages::MessageRouter& messageRouter);
            virtual ~MessageLearnResults();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetSpringExists(const bool bSpringExists);
            bool bGetSpringExists() const;

            void vSetDoorInertiaInDeciKgMeterSquared(const uint16_t ui16DoorInertiaInDeciKgMeterSquared);
            uint16_t ui16GetDoorInertiaInDeciKgMeterSquared() const;

            void vSetDoorOpenAngleInDeciDegrees(const uint16_t ui16DoorOpenAngleInDeciDegrees);
            uint16_t ui16GetDoorOpenAngleInDeciDegrees() const;

            void vSetSpringPreTensionInMillimeter(const uint16_t ui16SpringPreTensionInMillimeter);
            uint16_t ui16GetSpringPreTensionInMillimeter() const;

        private:
            bool m_bSpringExists;
            uint16_t m_ui16DoorInertiaInDeciKgMeterSquared;
            uint16_t m_ui16DoorOpenAngleInDeciDegrees;
            uint16_t m_ui16SpringPreTensionInMillimeter;
    };

}
#endif // MESSAGE_LEARN_RESULTS_INCLUDE_GUARD
