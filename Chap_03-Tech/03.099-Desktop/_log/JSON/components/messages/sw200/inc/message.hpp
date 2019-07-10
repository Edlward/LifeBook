#ifndef MESSAGE_HEADER_INCLUDE_GUARD
#define MESSAGE_HEADER_INCLUDE_GUARD

#include <stdint.h>

namespace messagesInternal
{
    class MessageRouterBackend; //lint !e1960 !e763

    class Message
    { //lint !e1960
    public:

        Message(messages::MessageRouter& messageRouter, const uint8_t ui8MessageId);
        virtual ~Message();

        uint8_t ui8GetMessageId() const;

        virtual bool bReceive();

        virtual void vSend() = 0;

    private:
        MessageRouterBackend& m_messageRouter; //lint !e1725 // Yes, the member is a reference. That's cool, we know what we're doing.
        const uint8_t m_messageId;


        Message() = delete;
        Message(const Message& source) = delete;
        Message& operator=(const Message& source) = delete;

    protected:
        messagesInternal::MessageRouterBackend& getRouter();

    };
}

#endif // MESSAGE_HEADER_INCLUDE_GUARD
