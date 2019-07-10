/**
  \file message_basic_io_hw_error.hpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Header file for the message BASIC_IO_HW_ERROR
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_BASIC_IO_HW_ERROR_INCLUDE_GUARD
#define MESSAGE_BASIC_IO_HW_ERROR_INCLUDE_GUARD

#include "message.hpp"

namespace messages {

    class MessageBasicIoHwError: public messagesInternal::Message
    {
        private:
            MessageBasicIoHwError() = delete;
            MessageBasicIoHwError(const MessageBasicIoHwError& source) = delete;
            MessageBasicIoHwError& operator=(const MessageBasicIoHwError& source) = delete;

        public:
            explicit MessageBasicIoHwError(messages::MessageRouter& messageRouter);
            virtual ~MessageBasicIoHwError();

            virtual bool bReceive() final;
            virtual void vSend() final;
            void vSetError(const bool bError);
            bool bGetError() const;

        private:
            bool m_bError;
    };

}
#endif // MESSAGE_BASIC_IO_HW_ERROR_INCLUDE_GUARD
