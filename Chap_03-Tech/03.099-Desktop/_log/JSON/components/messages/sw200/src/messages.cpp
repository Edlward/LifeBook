/**
  \file messages.cpp

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Implements message-related structures.
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#include <stdint.h>

#include "messageIds.h"
#include "array_index.h"
namespace messages
{
    const uint8_t arMessageSize[NUMBER_OF_MESSAGE_IDS] = {
        AI(NOT_USED, 0U),
        AI(DOOR_CONTROL_TIMER_EVENT, 1U),
        AI(LEARN_RESULTS, 7U),
        AI(THRESHOLD_TYPE_2, 6U),
        AI(ISO_TP_FRAME, 8U),
        AI(SAFETY_CAN_ERROR, 2U),
        AI(LEARN_BACK_CHECK_ANGLE, 2U),
        AI(HEART_BEAT, 2U),
        AI(PARAMETER_SET_DEFINITIONS, 0U),
        AI(LEARN_LATCH_CHECK_ANGLE, 2U),
        AI(PARAMETER_DEFINITION, 29U),
        AI(LEARN_BUTTON, 1U),
        AI(SAFETY_IMPULSE, 4U),
        AI(SYSTEM_MONITOR_ERROR, 1U),
        AI(STATUS, 2U),
        AI(PROGRAM_UPDATED, 1U),
        AI(BLE_STATUS_UPDATED, 1U),
        AI(SYSTEM_MONITOR_STATUS, 1U),
        AI(DOOR_ANGLE_REPETITION, 2U),
        AI(MOTION_CONTROL_EVENT_TIMEOUT, 1U),
        AI(PARAMETER_MAP, 7U),
        AI(MOTION_CONTROL_STATUS, 1U),
        AI(REQUEST_STATUS, 2U),
        AI(PROGRAM_OVERRIDE, 1U),
        AI(PARAMETER_UPDATED, 7U),
        AI(SOFTWARE_RESET, 1U),
        AI(THRESHOLD_TYPE_3, 6U),
        AI(ABORT_IMPULSES_TIMEOUT, 1U),
        AI(MOTION_CONTROL_COMMAND, 1U),
        AI(ENCODER_INFO, 6U),
        AI(PARAMETER_SET_VALUE, 8U),
        AI(CAN_BUS_ERROR, 1U),
        AI(SET_ERROR, 1U),
        AI(DOOR_CONTROL_RENEW_CLOSED_ANGLE, 1U),
        AI(LOCK_ENERGIZED, 1U),
        AI(PARAMETER_GET_DATA, 5U),
        AI(BASIC_IO_HW_ERROR, 1U),
        AI(IMPULSE, 2U),
        AI(LEARN_COMMAND_ERROR, 1U),
        AI(SYSTEM_MONITOR_EVENT_TIMEOUT, 1U),
        AI(SYS_MON_THRES, 6U),
        AI(CLEAR_ERROR, 1U),
        AI(THRESHOLD_TYPE_5, 6U),
        AI(THRESHOLD_TYPE_4, 6U),
    };

}
