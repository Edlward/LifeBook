#include "aaesCommon.hpp"
#include "messageRouter.hpp"
#include "messageRouterBackend.hpp"

#include "message.hpp"

messagesInternal::Message::Message(messages::MessageRouter& messageRouter, const uint8_t ui8MessageId)
    : m_messageRouter(messageRouter.backend())
    , m_messageId(ui8MessageId)
{

}

messagesInternal::Message::~Message()
{

}

uint8_t messagesInternal::Message::ui8GetMessageId() const
{
    return m_messageId;
}

bool messagesInternal::Message::bReceive()
{
    return (ui8GetMessageId() == m_messageRouter.ui8GetMessageId());
}//lint !e1961 // No it cannot be made const. It literally sets internal variables in its overrides.

messagesInternal::MessageRouterBackend& messagesInternal::Message::getRouter()
{
    return m_messageRouter; //lint !e1536 // The point is to expose internal protected member.
}
