/**
  \file message.cpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Implementation of classes for messages.
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#include <cstring>
#include "messageIds.h"
#include "messageRouter.hpp"
#include "messageRouterBackend.hpp"
#include "message.hpp"
#include "message_helper.hpp"
#include "message_not_used.hpp"
#include "message_door_control_timer_event.hpp"
#include "message_learn_results.hpp"
#include "message_threshold_type_2.hpp"
#include "message_iso_tp_frame.hpp"
#include "message_safety_can_error.hpp"
#include "message_learn_back_check_angle.hpp"
#include "message_heart_beat.hpp"
#include "message_parameter_set_definitions.hpp"
#include "message_learn_latch_check_angle.hpp"
#include "message_parameter_definition.hpp"
#include "message_learn_button.hpp"
#include "message_safety_impulse.hpp"
#include "message_system_monitor_error.hpp"
#include "message_status.hpp"
#include "message_program_updated.hpp"
#include "message_ble_status_updated.hpp"
#include "message_system_monitor_status.hpp"
#include "message_door_angle_repetition.hpp"
#include "message_motion_control_event_timeout.hpp"
#include "message_parameter_map.hpp"
#include "message_motion_control_status.hpp"
#include "message_request_status.hpp"
#include "message_program_override.hpp"
#include "message_parameter_updated.hpp"
#include "message_software_reset.hpp"
#include "message_threshold_type_3.hpp"
#include "message_abort_impulses_timeout.hpp"
#include "message_motion_control_command.hpp"
#include "message_encoder_info.hpp"
#include "message_parameter_set_value.hpp"
#include "message_can_bus_error.hpp"
#include "message_set_error.hpp"
#include "message_door_control_renew_closed_angle.hpp"
#include "message_lock_energized.hpp"
#include "message_parameter_get_data.hpp"
#include "message_basic_io_hw_error.hpp"
#include "message_impulse.hpp"
#include "message_learn_command_error.hpp"
#include "message_system_monitor_event_timeout.hpp"
#include "message_sys_mon_thres.hpp"
#include "message_clear_error.hpp"
#include "message_threshold_type_5.hpp"
#include "message_threshold_type_4.hpp"

//lint -esym(438, offset) // We want to ignore dangling assignments of offset in auto-generated code

namespace messages {

MessageNotUsed::MessageNotUsed(MessageRouter& messageRouter)
    : Message(messageRouter, NOT_USED)
{
}

MessageNotUsed::~MessageNotUsed() { }

bool MessageNotUsed::bReceive()
{
    return Message::bReceive();
}

void MessageNotUsed::vSend()
{
    getRouter().vTransmit();
}

MessageDoorControlTimerEvent::MessageDoorControlTimerEvent(MessageRouter& messageRouter)
    : Message(messageRouter, DOOR_CONTROL_TIMER_EVENT)
    , m_ui8Event(0)
{
}

MessageDoorControlTimerEvent::~MessageDoorControlTimerEvent() { }

void MessageDoorControlTimerEvent::vSetEvent(const uint8_t ui8Event)
{
    m_ui8Event = ui8Event;
}

uint8_t MessageDoorControlTimerEvent::ui8GetEvent() const
{
    return m_ui8Event;
}

bool MessageDoorControlTimerEvent::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Event = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageDoorControlTimerEvent::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Event, si32Offset);
    getRouter().vTransmit();
}

MessageLearnResults::MessageLearnResults(MessageRouter& messageRouter)
    : Message(messageRouter, LEARN_RESULTS)
    , m_bSpringExists(false)
    , m_ui16DoorInertiaInDeciKgMeterSquared(0)
    , m_ui16DoorOpenAngleInDeciDegrees(0)
    , m_ui16SpringPreTensionInMillimeter(0)
{
}

MessageLearnResults::~MessageLearnResults() { }

void MessageLearnResults::vSetSpringExists(const bool bSpringExists)
{
    m_bSpringExists = bSpringExists;
}

bool MessageLearnResults::bGetSpringExists() const
{
    return m_bSpringExists;
}

void MessageLearnResults::vSetDoorInertiaInDeciKgMeterSquared(const uint16_t ui16DoorInertiaInDeciKgMeterSquared)
{
    m_ui16DoorInertiaInDeciKgMeterSquared = ui16DoorInertiaInDeciKgMeterSquared;
}

uint16_t MessageLearnResults::ui16GetDoorInertiaInDeciKgMeterSquared() const
{
    return m_ui16DoorInertiaInDeciKgMeterSquared;
}

void MessageLearnResults::vSetDoorOpenAngleInDeciDegrees(const uint16_t ui16DoorOpenAngleInDeciDegrees)
{
    m_ui16DoorOpenAngleInDeciDegrees = ui16DoorOpenAngleInDeciDegrees;
}

uint16_t MessageLearnResults::ui16GetDoorOpenAngleInDeciDegrees() const
{
    return m_ui16DoorOpenAngleInDeciDegrees;
}

void MessageLearnResults::vSetSpringPreTensionInMillimeter(const uint16_t ui16SpringPreTensionInMillimeter)
{
    m_ui16SpringPreTensionInMillimeter = ui16SpringPreTensionInMillimeter;
}

uint16_t MessageLearnResults::ui16GetSpringPreTensionInMillimeter() const
{
    return m_ui16SpringPreTensionInMillimeter;
}

bool MessageLearnResults::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bSpringExists = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
        m_ui16DoorInertiaInDeciKgMeterSquared = messagesInternal::MessageHelper::ui16GetValue(pMessageBuffer, si32Offset);
        m_ui16DoorOpenAngleInDeciDegrees = messagesInternal::MessageHelper::ui16GetValue(pMessageBuffer, si32Offset);
        m_ui16SpringPreTensionInMillimeter = messagesInternal::MessageHelper::ui16GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageLearnResults::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bSpringExists, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui16DoorInertiaInDeciKgMeterSquared, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui16DoorOpenAngleInDeciDegrees, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui16SpringPreTensionInMillimeter, si32Offset);
    getRouter().vTransmit();
}

MessageThresholdType2::MessageThresholdType2(MessageRouter& messageRouter)
    : Message(messageRouter, THRESHOLD_TYPE_2)
    , m_ui8Status(0)
    , m_ui8Id(0)
    , m_si32Level(0)
{
}

MessageThresholdType2::~MessageThresholdType2() { }

void MessageThresholdType2::vSetStatus(const uint8_t ui8Status)
{
    m_ui8Status = ui8Status;
}

uint8_t MessageThresholdType2::ui8GetStatus() const
{
    return m_ui8Status;
}

void MessageThresholdType2::vSetId(const uint8_t ui8Id)
{
    m_ui8Id = ui8Id;
}

uint8_t MessageThresholdType2::ui8GetId() const
{
    return m_ui8Id;
}

void MessageThresholdType2::vSetLevel(const int32_t si32Level)
{
    m_si32Level = si32Level;
}

int32_t MessageThresholdType2::si32GetLevel() const
{
    return m_si32Level;
}

bool MessageThresholdType2::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Status = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_ui8Id = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_si32Level = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageThresholdType2::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Status, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Id, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Level, si32Offset);
    getRouter().vTransmit();
}

MessageIsoTpFrame::MessageIsoTpFrame(MessageRouter& messageRouter)
    : Message(messageRouter, ISO_TP_FRAME)
    , m_aData()
{
}

MessageIsoTpFrame::~MessageIsoTpFrame() { }

void MessageIsoTpFrame::vSetData(const uint8_t aData[8])
{
    std::memcpy(m_aData, aData, 8);
}
const uint8_t* MessageIsoTpFrame::pGetData() const
{
    return m_aData;
}

bool MessageIsoTpFrame::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        for (int32_t i = 0; i < 8; i++)
        {
            m_aData[i] = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        }
    }
    return bSuccess;
}

void MessageIsoTpFrame::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_aData, sizeof(m_aData), si32Offset);
    getRouter().vTransmit();
}

MessageSafetyCanError::MessageSafetyCanError(MessageRouter& messageRouter)
    : Message(messageRouter, SAFETY_CAN_ERROR)
    , m_ui8ErrorMessageId(0)
    , m_ui8Error(0)
{
}

MessageSafetyCanError::~MessageSafetyCanError() { }

void MessageSafetyCanError::vSetErrorMessageId(const uint8_t ui8ErrorMessageId)
{
    m_ui8ErrorMessageId = ui8ErrorMessageId;
}

uint8_t MessageSafetyCanError::ui8GetErrorMessageId() const
{
    return m_ui8ErrorMessageId;
}

void MessageSafetyCanError::vSetError(const uint8_t ui8Error)
{
    m_ui8Error = ui8Error;
}

uint8_t MessageSafetyCanError::ui8GetError() const
{
    return m_ui8Error;
}

bool MessageSafetyCanError::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8ErrorMessageId = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_ui8Error = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageSafetyCanError::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8ErrorMessageId, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Error, si32Offset);
    getRouter().vTransmit();
}

MessageLearnBackCheckAngle::MessageLearnBackCheckAngle(MessageRouter& messageRouter)
    : Message(messageRouter, LEARN_BACK_CHECK_ANGLE)
    , m_ui16Angle(0)
{
}

MessageLearnBackCheckAngle::~MessageLearnBackCheckAngle() { }

void MessageLearnBackCheckAngle::vSetAngle(const uint16_t ui16Angle)
{
    m_ui16Angle = ui16Angle;
}

uint16_t MessageLearnBackCheckAngle::ui16GetAngle() const
{
    return m_ui16Angle;
}

bool MessageLearnBackCheckAngle::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui16Angle = messagesInternal::MessageHelper::ui16GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageLearnBackCheckAngle::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui16Angle, si32Offset);
    getRouter().vTransmit();
}

MessageHeartBeat::MessageHeartBeat(MessageRouter& messageRouter)
    : Message(messageRouter, HEART_BEAT)
    , m_ui8Crc8(0)
    , m_ui8SequenceNumber(0)
{
}

MessageHeartBeat::~MessageHeartBeat() { }

void MessageHeartBeat::vSetCrc8(const uint8_t ui8Crc8)
{
    m_ui8Crc8 = ui8Crc8;
}

uint8_t MessageHeartBeat::ui8GetCrc8() const
{
    return m_ui8Crc8;
}

void MessageHeartBeat::vSetSequenceNumber(const uint8_t ui8SequenceNumber)
{
    m_ui8SequenceNumber = ui8SequenceNumber;
}

uint8_t MessageHeartBeat::ui8GetSequenceNumber() const
{
    return m_ui8SequenceNumber;
}

bool MessageHeartBeat::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Crc8 = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_ui8SequenceNumber = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageHeartBeat::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Crc8, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8SequenceNumber, si32Offset);
    getRouter().vTransmit();
}

MessageParameterSetDefinitions::MessageParameterSetDefinitions(MessageRouter& messageRouter)
    : Message(messageRouter, PARAMETER_SET_DEFINITIONS)
{
}

MessageParameterSetDefinitions::~MessageParameterSetDefinitions() { }

bool MessageParameterSetDefinitions::bReceive()
{
    return Message::bReceive();
}

void MessageParameterSetDefinitions::vSend()
{
    getRouter().vTransmit();
}

MessageLearnLatchCheckAngle::MessageLearnLatchCheckAngle(MessageRouter& messageRouter)
    : Message(messageRouter, LEARN_LATCH_CHECK_ANGLE)
    , m_ui16Angle(0)
{
}

MessageLearnLatchCheckAngle::~MessageLearnLatchCheckAngle() { }

void MessageLearnLatchCheckAngle::vSetAngle(const uint16_t ui16Angle)
{
    m_ui16Angle = ui16Angle;
}

uint16_t MessageLearnLatchCheckAngle::ui16GetAngle() const
{
    return m_ui16Angle;
}

bool MessageLearnLatchCheckAngle::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui16Angle = messagesInternal::MessageHelper::ui16GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageLearnLatchCheckAngle::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui16Angle, si32Offset);
    getRouter().vTransmit();
}

MessageParameterDefinition::MessageParameterDefinition(MessageRouter& messageRouter)
    : Message(messageRouter, PARAMETER_DEFINITION)
    , m_si32Min(0)
    , m_si32Max(0)
    , m_si32DefaultValue(0)
    , m_si32WriteLevel(0)
    , m_si32ReadLevel(0)
    , m_si32Id(0)
    , m_ui8Type(0)
    , m_si32FreezeFlags(0)
{
}

MessageParameterDefinition::~MessageParameterDefinition() { }

void MessageParameterDefinition::vSetMin(const int32_t si32Min)
{
    m_si32Min = si32Min;
}

int32_t MessageParameterDefinition::si32GetMin() const
{
    return m_si32Min;
}

void MessageParameterDefinition::vSetMax(const int32_t si32Max)
{
    m_si32Max = si32Max;
}

int32_t MessageParameterDefinition::si32GetMax() const
{
    return m_si32Max;
}

void MessageParameterDefinition::vSetDefaultValue(const int32_t si32DefaultValue)
{
    m_si32DefaultValue = si32DefaultValue;
}

int32_t MessageParameterDefinition::si32GetDefaultValue() const
{
    return m_si32DefaultValue;
}

void MessageParameterDefinition::vSetWriteLevel(const int32_t si32WriteLevel)
{
    m_si32WriteLevel = si32WriteLevel;
}

int32_t MessageParameterDefinition::si32GetWriteLevel() const
{
    return m_si32WriteLevel;
}

void MessageParameterDefinition::vSetReadLevel(const int32_t si32ReadLevel)
{
    m_si32ReadLevel = si32ReadLevel;
}

int32_t MessageParameterDefinition::si32GetReadLevel() const
{
    return m_si32ReadLevel;
}

void MessageParameterDefinition::vSetId(const int32_t si32Id)
{
    m_si32Id = si32Id;
}

int32_t MessageParameterDefinition::si32GetId() const
{
    return m_si32Id;
}

void MessageParameterDefinition::vSetType(const uint8_t ui8Type)
{
    m_ui8Type = ui8Type;
}

uint8_t MessageParameterDefinition::ui8GetType() const
{
    return m_ui8Type;
}

void MessageParameterDefinition::vSetFreezeFlags(const int32_t si32FreezeFlags)
{
    m_si32FreezeFlags = si32FreezeFlags;
}

int32_t MessageParameterDefinition::si32GetFreezeFlags() const
{
    return m_si32FreezeFlags;
}

bool MessageParameterDefinition::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_si32Min = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
        m_si32Max = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
        m_si32DefaultValue = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
        m_si32WriteLevel = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
        m_si32ReadLevel = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
        m_si32Id = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
        m_ui8Type = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_si32FreezeFlags = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageParameterDefinition::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Min, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Max, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32DefaultValue, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32WriteLevel, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32ReadLevel, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Id, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Type, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32FreezeFlags, si32Offset);
    getRouter().vTransmit();
}

MessageLearnButton::MessageLearnButton(MessageRouter& messageRouter)
    : Message(messageRouter, LEARN_BUTTON)
    , m_bActive(false)
{
}

MessageLearnButton::~MessageLearnButton() { }

void MessageLearnButton::vSetActive(const bool bActive)
{
    m_bActive = bActive;
}

bool MessageLearnButton::bGetActive() const
{
    return m_bActive;
}

bool MessageLearnButton::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bActive = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageLearnButton::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bActive, si32Offset);
    getRouter().vTransmit();
}

MessageSafetyImpulse::MessageSafetyImpulse(MessageRouter& messageRouter)
    : Message(messageRouter, SAFETY_IMPULSE)
    , m_bActive(false)
    , m_ui8Crc8(0)
    , m_ui8Type(0)
    , m_ui8SequenceNumber(0)
{
}

MessageSafetyImpulse::~MessageSafetyImpulse() { }

void MessageSafetyImpulse::vSetActive(const bool bActive)
{
    m_bActive = bActive;
}

bool MessageSafetyImpulse::bGetActive() const
{
    return m_bActive;
}

void MessageSafetyImpulse::vSetCrc8(const uint8_t ui8Crc8)
{
    m_ui8Crc8 = ui8Crc8;
}

uint8_t MessageSafetyImpulse::ui8GetCrc8() const
{
    return m_ui8Crc8;
}

void MessageSafetyImpulse::vSetType(const uint8_t ui8Type)
{
    m_ui8Type = ui8Type;
}

uint8_t MessageSafetyImpulse::ui8GetType() const
{
    return m_ui8Type;
}

void MessageSafetyImpulse::vSetSequenceNumber(const uint8_t ui8SequenceNumber)
{
    m_ui8SequenceNumber = ui8SequenceNumber;
}

uint8_t MessageSafetyImpulse::ui8GetSequenceNumber() const
{
    return m_ui8SequenceNumber;
}

bool MessageSafetyImpulse::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bActive = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
        m_ui8Crc8 = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_ui8Type = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_ui8SequenceNumber = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageSafetyImpulse::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bActive, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Crc8, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Type, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8SequenceNumber, si32Offset);
    getRouter().vTransmit();
}

MessageSystemMonitorError::MessageSystemMonitorError(MessageRouter& messageRouter)
    : Message(messageRouter, SYSTEM_MONITOR_ERROR)
    , m_ui8Error(0)
{
}

MessageSystemMonitorError::~MessageSystemMonitorError() { }

void MessageSystemMonitorError::vSetError(const uint8_t ui8Error)
{
    m_ui8Error = ui8Error;
}

uint8_t MessageSystemMonitorError::ui8GetError() const
{
    return m_ui8Error;
}

bool MessageSystemMonitorError::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Error = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageSystemMonitorError::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Error, si32Offset);
    getRouter().vTransmit();
}

MessageStatus::MessageStatus(MessageRouter& messageRouter)
    : Message(messageRouter, STATUS)
    , m_ui8Key(0)
    , m_si8TaskId(0)
{
}

MessageStatus::~MessageStatus() { }

void MessageStatus::vSetKey(const uint8_t ui8Key)
{
    m_ui8Key = ui8Key;
}

uint8_t MessageStatus::ui8GetKey() const
{
    return m_ui8Key;
}

void MessageStatus::vSetTaskId(const int8_t si8TaskId)
{
    m_si8TaskId = si8TaskId;
}

int8_t MessageStatus::si8GetTaskId() const
{
    return m_si8TaskId;
}

bool MessageStatus::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Key = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_si8TaskId = messagesInternal::MessageHelper::si8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageStatus::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Key, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si8TaskId, si32Offset);
    getRouter().vTransmit();
}

MessageProgramUpdated::MessageProgramUpdated(MessageRouter& messageRouter)
    : Message(messageRouter, PROGRAM_UPDATED)
    , m_ui8NewProgram(0)
{
}

MessageProgramUpdated::~MessageProgramUpdated() { }

void MessageProgramUpdated::vSetNewProgram(const uint8_t ui8NewProgram)
{
    m_ui8NewProgram = ui8NewProgram;
}

uint8_t MessageProgramUpdated::ui8GetNewProgram() const
{
    return m_ui8NewProgram;
}

bool MessageProgramUpdated::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8NewProgram = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageProgramUpdated::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8NewProgram, si32Offset);
    getRouter().vTransmit();
}

MessageBleStatusUpdated::MessageBleStatusUpdated(MessageRouter& messageRouter)
    : Message(messageRouter, BLE_STATUS_UPDATED)
    , m_ui8Connection(0)
{
}

MessageBleStatusUpdated::~MessageBleStatusUpdated() { }

void MessageBleStatusUpdated::vSetConnection(const uint8_t ui8Connection)
{
    m_ui8Connection = ui8Connection;
}

uint8_t MessageBleStatusUpdated::ui8GetConnection() const
{
    return m_ui8Connection;
}

bool MessageBleStatusUpdated::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Connection = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageBleStatusUpdated::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Connection, si32Offset);
    getRouter().vTransmit();
}

MessageSystemMonitorStatus::MessageSystemMonitorStatus(MessageRouter& messageRouter)
    : Message(messageRouter, SYSTEM_MONITOR_STATUS)
    , m_ui8Status(0)
{
}

MessageSystemMonitorStatus::~MessageSystemMonitorStatus() { }

void MessageSystemMonitorStatus::vSetStatus(const uint8_t ui8Status)
{
    m_ui8Status = ui8Status;
}

uint8_t MessageSystemMonitorStatus::ui8GetStatus() const
{
    return m_ui8Status;
}

bool MessageSystemMonitorStatus::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Status = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageSystemMonitorStatus::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Status, si32Offset);
    getRouter().vTransmit();
}

MessageDoorAngleRepetition::MessageDoorAngleRepetition(MessageRouter& messageRouter)
    : Message(messageRouter, DOOR_ANGLE_REPETITION)
    , m_ui16Angle(0)
{
}

MessageDoorAngleRepetition::~MessageDoorAngleRepetition() { }

void MessageDoorAngleRepetition::vSetAngle(const uint16_t ui16Angle)
{
    m_ui16Angle = ui16Angle;
}

uint16_t MessageDoorAngleRepetition::ui16GetAngle() const
{
    return m_ui16Angle;
}

bool MessageDoorAngleRepetition::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui16Angle = messagesInternal::MessageHelper::ui16GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageDoorAngleRepetition::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui16Angle, si32Offset);
    getRouter().vTransmit();
}

MessageMotionControlEventTimeout::MessageMotionControlEventTimeout(MessageRouter& messageRouter)
    : Message(messageRouter, MOTION_CONTROL_EVENT_TIMEOUT)
    , m_ui8Event(0)
{
}

MessageMotionControlEventTimeout::~MessageMotionControlEventTimeout() { }

void MessageMotionControlEventTimeout::vSetEvent(const uint8_t ui8Event)
{
    m_ui8Event = ui8Event;
}

uint8_t MessageMotionControlEventTimeout::ui8GetEvent() const
{
    return m_ui8Event;
}

bool MessageMotionControlEventTimeout::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Event = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageMotionControlEventTimeout::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Event, si32Offset);
    getRouter().vTransmit();
}

MessageParameterMap::MessageParameterMap(MessageRouter& messageRouter)
    : Message(messageRouter, PARAMETER_MAP)
    , m_si32Count(0)
    , m_aMap()
{
}

MessageParameterMap::~MessageParameterMap() { }

void MessageParameterMap::vSetCount(const int32_t si32Count)
{
    m_si32Count = si32Count;
}

int32_t MessageParameterMap::si32GetCount() const
{
    return m_si32Count;
}

void MessageParameterMap::vSetMap(const uint8_t aMap[3])
{
    std::memcpy(m_aMap, aMap, 3);
}
const uint8_t* MessageParameterMap::pGetMap() const
{
    return m_aMap;
}

bool MessageParameterMap::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_si32Count = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
        for (int32_t i = 0; i < 3; i++)
        {
            m_aMap[i] = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        }
    }
    return bSuccess;
}

void MessageParameterMap::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Count, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_aMap, sizeof(m_aMap), si32Offset);
    getRouter().vTransmit();
}

MessageMotionControlStatus::MessageMotionControlStatus(MessageRouter& messageRouter)
    : Message(messageRouter, MOTION_CONTROL_STATUS)
    , m_ui8Status(0)
{
}

MessageMotionControlStatus::~MessageMotionControlStatus() { }

void MessageMotionControlStatus::vSetStatus(const uint8_t ui8Status)
{
    m_ui8Status = ui8Status;
}

uint8_t MessageMotionControlStatus::ui8GetStatus() const
{
    return m_ui8Status;
}

bool MessageMotionControlStatus::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Status = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageMotionControlStatus::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Status, si32Offset);
    getRouter().vTransmit();
}

MessageRequestStatus::MessageRequestStatus(MessageRouter& messageRouter)
    : Message(messageRouter, REQUEST_STATUS)
    , m_aKeys()
{
}

MessageRequestStatus::~MessageRequestStatus() { }

void MessageRequestStatus::vSetKeys(const uint8_t aKeys[2])
{
    std::memcpy(m_aKeys, aKeys, 2);
}
const uint8_t* MessageRequestStatus::pGetKeys() const
{
    return m_aKeys;
}

bool MessageRequestStatus::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        for (int32_t i = 0; i < 2; i++)
        {
            m_aKeys[i] = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        }
    }
    return bSuccess;
}

void MessageRequestStatus::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_aKeys, sizeof(m_aKeys), si32Offset);
    getRouter().vTransmit();
}

MessageProgramOverride::MessageProgramOverride(MessageRouter& messageRouter)
    : Message(messageRouter, PROGRAM_OVERRIDE)
    , m_ui8Program(0)
{
}

MessageProgramOverride::~MessageProgramOverride() { }

void MessageProgramOverride::vSetProgram(const uint8_t ui8Program)
{
    m_ui8Program = ui8Program;
}

uint8_t MessageProgramOverride::ui8GetProgram() const
{
    return m_ui8Program;
}

bool MessageProgramOverride::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Program = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageProgramOverride::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Program, si32Offset);
    getRouter().vTransmit();
}

MessageParameterUpdated::MessageParameterUpdated(MessageRouter& messageRouter)
    : Message(messageRouter, PARAMETER_UPDATED)
    , m_ui8ErrorCode(0)
    , m_si16Id(0)
    , m_si32Value(0)
{
}

MessageParameterUpdated::~MessageParameterUpdated() { }

void MessageParameterUpdated::vSetErrorCode(const uint8_t ui8ErrorCode)
{
    m_ui8ErrorCode = ui8ErrorCode;
}

uint8_t MessageParameterUpdated::ui8GetErrorCode() const
{
    return m_ui8ErrorCode;
}

void MessageParameterUpdated::vSetId(const int16_t si16Id)
{
    m_si16Id = si16Id;
}

int16_t MessageParameterUpdated::si16GetId() const
{
    return m_si16Id;
}

void MessageParameterUpdated::vSetValue(const int32_t si32Value)
{
    m_si32Value = si32Value;
}

int32_t MessageParameterUpdated::si32GetValue() const
{
    return m_si32Value;
}

bool MessageParameterUpdated::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8ErrorCode = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_si16Id = messagesInternal::MessageHelper::si16GetValue(pMessageBuffer, si32Offset);
        m_si32Value = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageParameterUpdated::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8ErrorCode, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si16Id, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Value, si32Offset);
    getRouter().vTransmit();
}

MessageSoftwareReset::MessageSoftwareReset(MessageRouter& messageRouter)
    : Message(messageRouter, SOFTWARE_RESET)
    , m_bStatus(false)
{
}

MessageSoftwareReset::~MessageSoftwareReset() { }

void MessageSoftwareReset::vSetStatus(const bool bStatus)
{
    m_bStatus = bStatus;
}

bool MessageSoftwareReset::bGetStatus() const
{
    return m_bStatus;
}

bool MessageSoftwareReset::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bStatus = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageSoftwareReset::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bStatus, si32Offset);
    getRouter().vTransmit();
}

MessageThresholdType3::MessageThresholdType3(MessageRouter& messageRouter)
    : Message(messageRouter, THRESHOLD_TYPE_3)
    , m_ui8Status(0)
    , m_ui8Id(0)
    , m_si32Level(0)
{
}

MessageThresholdType3::~MessageThresholdType3() { }

void MessageThresholdType3::vSetStatus(const uint8_t ui8Status)
{
    m_ui8Status = ui8Status;
}

uint8_t MessageThresholdType3::ui8GetStatus() const
{
    return m_ui8Status;
}

void MessageThresholdType3::vSetId(const uint8_t ui8Id)
{
    m_ui8Id = ui8Id;
}

uint8_t MessageThresholdType3::ui8GetId() const
{
    return m_ui8Id;
}

void MessageThresholdType3::vSetLevel(const int32_t si32Level)
{
    m_si32Level = si32Level;
}

int32_t MessageThresholdType3::si32GetLevel() const
{
    return m_si32Level;
}

bool MessageThresholdType3::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Status = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_ui8Id = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_si32Level = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageThresholdType3::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Status, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Id, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Level, si32Offset);
    getRouter().vTransmit();
}

MessageAbortImpulsesTimeout::MessageAbortImpulsesTimeout(MessageRouter& messageRouter)
    : Message(messageRouter, ABORT_IMPULSES_TIMEOUT)
    , m_bAbort(false)
{
}

MessageAbortImpulsesTimeout::~MessageAbortImpulsesTimeout() { }

void MessageAbortImpulsesTimeout::vSetAbort(const bool bAbort)
{
    m_bAbort = bAbort;
}

bool MessageAbortImpulsesTimeout::bGetAbort() const
{
    return m_bAbort;
}

bool MessageAbortImpulsesTimeout::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bAbort = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageAbortImpulsesTimeout::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bAbort, si32Offset);
    getRouter().vTransmit();
}

MessageMotionControlCommand::MessageMotionControlCommand(MessageRouter& messageRouter)
    : Message(messageRouter, MOTION_CONTROL_COMMAND)
    , m_ui8Command(0)
{
}

MessageMotionControlCommand::~MessageMotionControlCommand() { }

void MessageMotionControlCommand::vSetCommand(const uint8_t ui8Command)
{
    m_ui8Command = ui8Command;
}

uint8_t MessageMotionControlCommand::ui8GetCommand() const
{
    return m_ui8Command;
}

bool MessageMotionControlCommand::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Command = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageMotionControlCommand::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Command, si32Offset);
    getRouter().vTransmit();
}

MessageEncoderInfo::MessageEncoderInfo(MessageRouter& messageRouter)
    : Message(messageRouter, ENCODER_INFO)
    , m_si32Angle(0)
    , m_si16ShaftSpeed(0)
{
}

MessageEncoderInfo::~MessageEncoderInfo() { }

void MessageEncoderInfo::vSetAngle(const int32_t si32Angle)
{
    m_si32Angle = si32Angle;
}

int32_t MessageEncoderInfo::si32GetAngle() const
{
    return m_si32Angle;
}

void MessageEncoderInfo::vSetShaftSpeed(const int16_t si16ShaftSpeed)
{
    m_si16ShaftSpeed = si16ShaftSpeed;
}

int16_t MessageEncoderInfo::si16GetShaftSpeed() const
{
    return m_si16ShaftSpeed;
}

bool MessageEncoderInfo::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_si32Angle = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
        m_si16ShaftSpeed = messagesInternal::MessageHelper::si16GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageEncoderInfo::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Angle, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si16ShaftSpeed, si32Offset);
    getRouter().vTransmit();
}

MessageParameterSetValue::MessageParameterSetValue(MessageRouter& messageRouter)
    : Message(messageRouter, PARAMETER_SET_VALUE)
    , m_si32Id(0)
    , m_si32Value(0)
{
}

MessageParameterSetValue::~MessageParameterSetValue() { }

void MessageParameterSetValue::vSetId(const int32_t si32Id)
{
    m_si32Id = si32Id;
}

int32_t MessageParameterSetValue::si32GetId() const
{
    return m_si32Id;
}

void MessageParameterSetValue::vSetValue(const int32_t si32Value)
{
    m_si32Value = si32Value;
}

int32_t MessageParameterSetValue::si32GetValue() const
{
    return m_si32Value;
}

bool MessageParameterSetValue::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_si32Id = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
        m_si32Value = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageParameterSetValue::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Id, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Value, si32Offset);
    getRouter().vTransmit();
}

MessageCanBusError::MessageCanBusError(MessageRouter& messageRouter)
    : Message(messageRouter, CAN_BUS_ERROR)
    , m_bActive(false)
{
}

MessageCanBusError::~MessageCanBusError() { }

void MessageCanBusError::vSetActive(const bool bActive)
{
    m_bActive = bActive;
}

bool MessageCanBusError::bGetActive() const
{
    return m_bActive;
}

bool MessageCanBusError::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bActive = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageCanBusError::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bActive, si32Offset);
    getRouter().vTransmit();
}

MessageSetError::MessageSetError(MessageRouter& messageRouter)
    : Message(messageRouter, SET_ERROR)
    , m_ui8ErrorCode(0)
{
}

MessageSetError::~MessageSetError() { }

void MessageSetError::vSetErrorCode(const uint8_t ui8ErrorCode)
{
    m_ui8ErrorCode = ui8ErrorCode;
}

uint8_t MessageSetError::ui8GetErrorCode() const
{
    return m_ui8ErrorCode;
}

bool MessageSetError::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8ErrorCode = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageSetError::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8ErrorCode, si32Offset);
    getRouter().vTransmit();
}

MessageDoorControlRenewClosedAngle::MessageDoorControlRenewClosedAngle(MessageRouter& messageRouter)
    : Message(messageRouter, DOOR_CONTROL_RENEW_CLOSED_ANGLE)
    , m_bRenew(false)
{
}

MessageDoorControlRenewClosedAngle::~MessageDoorControlRenewClosedAngle() { }

void MessageDoorControlRenewClosedAngle::vSetRenew(const bool bRenew)
{
    m_bRenew = bRenew;
}

bool MessageDoorControlRenewClosedAngle::bGetRenew() const
{
    return m_bRenew;
}

bool MessageDoorControlRenewClosedAngle::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bRenew = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageDoorControlRenewClosedAngle::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bRenew, si32Offset);
    getRouter().vTransmit();
}

MessageLockEnergized::MessageLockEnergized(MessageRouter& messageRouter)
    : Message(messageRouter, LOCK_ENERGIZED)
    , m_bRequest(false)
{
}

MessageLockEnergized::~MessageLockEnergized() { }

void MessageLockEnergized::vSetRequest(const bool bRequest)
{
    m_bRequest = bRequest;
}

bool MessageLockEnergized::bGetRequest() const
{
    return m_bRequest;
}

bool MessageLockEnergized::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bRequest = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageLockEnergized::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bRequest, si32Offset);
    getRouter().vTransmit();
}

MessageParameterGetData::MessageParameterGetData(MessageRouter& messageRouter)
    : Message(messageRouter, PARAMETER_GET_DATA)
    , m_ui8Type(0)
    , m_si32Id(0)
{
}

MessageParameterGetData::~MessageParameterGetData() { }

void MessageParameterGetData::vSetType(const uint8_t ui8Type)
{
    m_ui8Type = ui8Type;
}

uint8_t MessageParameterGetData::ui8GetType() const
{
    return m_ui8Type;
}

void MessageParameterGetData::vSetId(const int32_t si32Id)
{
    m_si32Id = si32Id;
}

int32_t MessageParameterGetData::si32GetId() const
{
    return m_si32Id;
}

bool MessageParameterGetData::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Type = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_si32Id = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageParameterGetData::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Type, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Id, si32Offset);
    getRouter().vTransmit();
}

MessageBasicIoHwError::MessageBasicIoHwError(MessageRouter& messageRouter)
    : Message(messageRouter, BASIC_IO_HW_ERROR)
    , m_bError(false)
{
}

MessageBasicIoHwError::~MessageBasicIoHwError() { }

void MessageBasicIoHwError::vSetError(const bool bError)
{
    m_bError = bError;
}

bool MessageBasicIoHwError::bGetError() const
{
    return m_bError;
}

bool MessageBasicIoHwError::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bError = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageBasicIoHwError::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bError, si32Offset);
    getRouter().vTransmit();
}

MessageImpulse::MessageImpulse(MessageRouter& messageRouter)
    : Message(messageRouter, IMPULSE)
    , m_bActive(false)
    , m_ui8Type(0)
{
}

MessageImpulse::~MessageImpulse() { }

void MessageImpulse::vSetActive(const bool bActive)
{
    m_bActive = bActive;
}

bool MessageImpulse::bGetActive() const
{
    return m_bActive;
}

void MessageImpulse::vSetType(const uint8_t ui8Type)
{
    m_ui8Type = ui8Type;
}

uint8_t MessageImpulse::ui8GetType() const
{
    return m_ui8Type;
}

bool MessageImpulse::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bActive = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
        m_ui8Type = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageImpulse::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bActive, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Type, si32Offset);
    getRouter().vTransmit();
}

MessageLearnCommandError::MessageLearnCommandError(MessageRouter& messageRouter)
    : Message(messageRouter, LEARN_COMMAND_ERROR)
    , m_bActive(false)
{
}

MessageLearnCommandError::~MessageLearnCommandError() { }

void MessageLearnCommandError::vSetActive(const bool bActive)
{
    m_bActive = bActive;
}

bool MessageLearnCommandError::bGetActive() const
{
    return m_bActive;
}

bool MessageLearnCommandError::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_bActive = messagesInternal::MessageHelper::bGetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageLearnCommandError::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_bActive, si32Offset);
    getRouter().vTransmit();
}

MessageSystemMonitorEventTimeout::MessageSystemMonitorEventTimeout(MessageRouter& messageRouter)
    : Message(messageRouter, SYSTEM_MONITOR_EVENT_TIMEOUT)
    , m_ui8Event(0)
{
}

MessageSystemMonitorEventTimeout::~MessageSystemMonitorEventTimeout() { }

void MessageSystemMonitorEventTimeout::vSetEvent(const uint8_t ui8Event)
{
    m_ui8Event = ui8Event;
}

uint8_t MessageSystemMonitorEventTimeout::ui8GetEvent() const
{
    return m_ui8Event;
}

bool MessageSystemMonitorEventTimeout::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Event = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageSystemMonitorEventTimeout::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Event, si32Offset);
    getRouter().vTransmit();
}

MessageSysMonThres::MessageSysMonThres(MessageRouter& messageRouter)
    : Message(messageRouter, SYS_MON_THRES)
    , m_ui8Status(0)
    , m_ui8Id(0)
    , m_si32Level(0)
{
}

MessageSysMonThres::~MessageSysMonThres() { }

void MessageSysMonThres::vSetStatus(const uint8_t ui8Status)
{
    m_ui8Status = ui8Status;
}

uint8_t MessageSysMonThres::ui8GetStatus() const
{
    return m_ui8Status;
}

void MessageSysMonThres::vSetId(const uint8_t ui8Id)
{
    m_ui8Id = ui8Id;
}

uint8_t MessageSysMonThres::ui8GetId() const
{
    return m_ui8Id;
}

void MessageSysMonThres::vSetLevel(const int32_t si32Level)
{
    m_si32Level = si32Level;
}

int32_t MessageSysMonThres::si32GetLevel() const
{
    return m_si32Level;
}

bool MessageSysMonThres::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Status = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_ui8Id = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_si32Level = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageSysMonThres::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Status, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Id, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Level, si32Offset);
    getRouter().vTransmit();
}

MessageClearError::MessageClearError(MessageRouter& messageRouter)
    : Message(messageRouter, CLEAR_ERROR)
    , m_ui8ErrorCode(0)
{
}

MessageClearError::~MessageClearError() { }

void MessageClearError::vSetErrorCode(const uint8_t ui8ErrorCode)
{
    m_ui8ErrorCode = ui8ErrorCode;
}

uint8_t MessageClearError::ui8GetErrorCode() const
{
    return m_ui8ErrorCode;
}

bool MessageClearError::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8ErrorCode = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageClearError::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8ErrorCode, si32Offset);
    getRouter().vTransmit();
}

MessageThresholdType5::MessageThresholdType5(MessageRouter& messageRouter)
    : Message(messageRouter, THRESHOLD_TYPE_5)
    , m_ui8Status(0)
    , m_ui8Id(0)
    , m_si32Level(0)
{
}

MessageThresholdType5::~MessageThresholdType5() { }

void MessageThresholdType5::vSetStatus(const uint8_t ui8Status)
{
    m_ui8Status = ui8Status;
}

uint8_t MessageThresholdType5::ui8GetStatus() const
{
    return m_ui8Status;
}

void MessageThresholdType5::vSetId(const uint8_t ui8Id)
{
    m_ui8Id = ui8Id;
}

uint8_t MessageThresholdType5::ui8GetId() const
{
    return m_ui8Id;
}

void MessageThresholdType5::vSetLevel(const int32_t si32Level)
{
    m_si32Level = si32Level;
}

int32_t MessageThresholdType5::si32GetLevel() const
{
    return m_si32Level;
}

bool MessageThresholdType5::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Status = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_ui8Id = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_si32Level = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageThresholdType5::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Status, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Id, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Level, si32Offset);
    getRouter().vTransmit();
}

MessageThresholdType4::MessageThresholdType4(MessageRouter& messageRouter)
    : Message(messageRouter, THRESHOLD_TYPE_4)
    , m_ui8Status(0)
    , m_ui8Id(0)
    , m_si32Level(0)
{
}

MessageThresholdType4::~MessageThresholdType4() { }

void MessageThresholdType4::vSetStatus(const uint8_t ui8Status)
{
    m_ui8Status = ui8Status;
}

uint8_t MessageThresholdType4::ui8GetStatus() const
{
    return m_ui8Status;
}

void MessageThresholdType4::vSetId(const uint8_t ui8Id)
{
    m_ui8Id = ui8Id;
}

uint8_t MessageThresholdType4::ui8GetId() const
{
    return m_ui8Id;
}

void MessageThresholdType4::vSetLevel(const int32_t si32Level)
{
    m_si32Level = si32Level;
}

int32_t MessageThresholdType4::si32GetLevel() const
{
    return m_si32Level;
}

bool MessageThresholdType4::bReceive()
{
    int32_t si32Offset = 0;
    const bool bSuccess = Message::bReceive();
    if (bSuccess)
    {
        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();
        m_ui8Status = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_ui8Id = messagesInternal::MessageHelper::ui8GetValue(pMessageBuffer, si32Offset);
        m_si32Level = messagesInternal::MessageHelper::si32GetValue(pMessageBuffer, si32Offset);
    }
    return bSuccess;
}

void MessageThresholdType4::vSend()
{
    const uint8_t cui8MessageId = ui8GetMessageId();
    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Status, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_ui8Id, si32Offset);
    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, m_si32Level, si32Offset);
    getRouter().vTransmit();
}


}
