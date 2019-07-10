/**
  \file messageIds.h

  \par Copyright &copy; 2019 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Defines the messages available in the product.
  \author Daniel Hellsson

  This file is generated from messages.json and should not be edited directly
**/

#ifndef MESSAGE_IDS_HEADER_INCLUDE_GUARD
#define MESSAGE_IDS_HEADER_INCLUDE_GUARD

#include <stdint.h>

//lint -e551 // Spurious error

namespace messages
{
    constexpr uint8_t NOT_USED = 0U;
    constexpr uint8_t DOOR_CONTROL_TIMER_EVENT = 1U;
    constexpr uint8_t LEARN_RESULTS = 2U;
    constexpr uint8_t THRESHOLD_TYPE_2 = 3U;
    constexpr uint8_t ISO_TP_FRAME = 4U;
    constexpr uint8_t SAFETY_CAN_ERROR = 5U;
    constexpr uint8_t LEARN_BACK_CHECK_ANGLE = 6U;
    constexpr uint8_t HEART_BEAT = 7U;
    constexpr uint8_t PARAMETER_SET_DEFINITIONS = 8U;
    constexpr uint8_t LEARN_LATCH_CHECK_ANGLE = 9U;
    constexpr uint8_t PARAMETER_DEFINITION = 10U;
    constexpr uint8_t LEARN_BUTTON = 11U;
    constexpr uint8_t SAFETY_IMPULSE = 12U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR = 13U;
    constexpr uint8_t STATUS = 14U;
    constexpr uint8_t PROGRAM_UPDATED = 15U;
    constexpr uint8_t BLE_STATUS_UPDATED = 16U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS = 17U;
    constexpr uint8_t DOOR_ANGLE_REPETITION = 18U;
    constexpr uint8_t MOTION_CONTROL_EVENT_TIMEOUT = 19U;
    constexpr uint8_t PARAMETER_MAP = 20U;
    constexpr uint8_t MOTION_CONTROL_STATUS = 21U;
    constexpr uint8_t REQUEST_STATUS = 22U;
    constexpr uint8_t PROGRAM_OVERRIDE = 23U;
    constexpr uint8_t PARAMETER_UPDATED = 24U;
    constexpr uint8_t SOFTWARE_RESET = 25U;
    constexpr uint8_t THRESHOLD_TYPE_3 = 26U;
    constexpr uint8_t ABORT_IMPULSES_TIMEOUT = 27U;
    constexpr uint8_t MOTION_CONTROL_COMMAND = 28U;
    constexpr uint8_t ENCODER_INFO = 29U;
    constexpr uint8_t PARAMETER_SET_VALUE = 30U;
    constexpr uint8_t CAN_BUS_ERROR = 31U;
    constexpr uint8_t SET_ERROR = 32U;
    constexpr uint8_t DOOR_CONTROL_RENEW_CLOSED_ANGLE = 33U;
    constexpr uint8_t LOCK_ENERGIZED = 34U;
    constexpr uint8_t PARAMETER_GET_DATA = 35U;
    constexpr uint8_t BASIC_IO_HW_ERROR = 36U;
    constexpr uint8_t IMPULSE = 37U;
    constexpr uint8_t LEARN_COMMAND_ERROR = 38U;
    constexpr uint8_t SYSTEM_MONITOR_EVENT_TIMEOUT = 39U;
    constexpr uint8_t SYS_MON_THRES = 40U;
    constexpr uint8_t CLEAR_ERROR = 41U;
    constexpr uint8_t THRESHOLD_TYPE_5 = 42U;
    constexpr uint8_t THRESHOLD_TYPE_4 = 43U;

    constexpr uint8_t NUMBER_OF_MESSAGE_IDS = 44U;

    // Parameters for THRESHOLD_TYPE_2
    constexpr uint8_t THRESHOLD_TYPE_2_STATUS_BELOW_THRESHOLD = 0U;
    constexpr uint8_t THRESHOLD_TYPE_2_STATUS_ABOVE_THRESHOLD = 1U;

    // Parameters for SAFETY_CAN_ERROR
    constexpr uint8_t SAFETY_CAN_ERROR_NONE = 0U;
    constexpr uint8_t SAFETY_CAN_ERROR_CRC = 1U;
    constexpr uint8_t SAFETY_CAN_ERROR_SEQ = 2U;
    constexpr uint8_t SAFETY_CAN_ERROR_TIMEOUT = 3U;

    // Parameters for PARAMETER_DEFINITION
    constexpr uint8_t PARAMETER_DEFINITION_TYPE_INT = 0U;
    constexpr uint8_t PARAMETER_DEFINITION_TYPE_ENUM = 1U;
    constexpr uint8_t PARAMETER_DEFINITION_TYPE_BITFIELD = 2U;
    constexpr uint8_t PARAMETER_DEFINITION_TYPE_BOOL = 3U;

    // Parameters for SAFETY_IMPULSE
    constexpr uint8_t SAFETY_IMPULSE_TYPE_PRESENCE = 0U;

    // Parameters for SYSTEM_MONITOR_ERROR
    constexpr uint8_t SYSTEM_MONITOR_ERROR_RELAY_ERROR = 0U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_UDC_OVER_VOLTAGE_ERROR = 1U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_UDC_UNDER_VOLTAGE_ERROR = 2U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_UCTRLDC_OVER_VOLTAGE_ERROR = 3U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_MAIN_VOLTAGE_DIFF_ERROR = 4U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_ENCODER_CONNECT_ERROR = 5U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_ENCODER_MANUAL_ERROR = 6U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_ENCODER_OVER_VOLTAGE_ERROR = 7U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_ENCODER_FICTIVE_RESISTANCE_ERROR = 8U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_CLEAR_ENCODER_CONNECT_ERROR = 9U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_CLEAR_OTHER_ENCODER_ERRORS = 10U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_EXT_SHORT_CIRCUIT = 11U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_EXT_OVER_VOLTAGE = 12U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_CLEAR_EXT_SHORT_CIRCUIT = 13U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_LOCK_VOLTAGE_ERROR = 14U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_LOCK_BACKUP_ERROR = 15U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_TEMINAL_5V4_ERROR = 16U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_LED_6V_ERROR = 17U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_REF_2V5_ERROR = 18U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_24V_OVER_VOLTAGE_ERROR = 19U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_24V_UNDER_VOLTAGE_ERROR = 20U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_MOTOR_VOLTAGE_ERROR = 21U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_MOTOR_CURRENT_ERROR = 22U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_MOTOR_DRIVER_ERROR = 23U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_MOTOR_OVERHEAT_ERROR = 24U;
    constexpr uint8_t SYSTEM_MONITOR_ERROR_CLEAR_MOTOR_OVERHEAT_ERROR = 25U;

    // Parameters for PROGRAM_UPDATED
    constexpr uint8_t PROGRAM_UPDATED_NEW_PROGRAM_OFF = 0U;
    constexpr uint8_t PROGRAM_UPDATED_NEW_PROGRAM_EXIT = 1U;
    constexpr uint8_t PROGRAM_UPDATED_NEW_PROGRAM_AUTO = 2U;
    constexpr uint8_t PROGRAM_UPDATED_NEW_PROGRAM_OPEN = 3U;

    // Parameters for BLE_STATUS_UPDATED
    constexpr uint8_t BLE_STATUS_UPDATED_CONNECTION_CONNECTED = 0U;
    constexpr uint8_t BLE_STATUS_UPDATED_CONNECTION_DISCONNECTED = 1U;

    // Parameters for SYSTEM_MONITOR_STATUS
    constexpr uint8_t SYSTEM_MONITOR_STATUS_RELAY_TEST_DONE = 0U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_RELAY_ENERGIZED = 1U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_RELAY_DE_ENERGIZED = 2U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_MAIN_VOLTAGE_DROP = 3U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_EXT_ENABLED = 4U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_EXT_DISABLED = 5U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_LOCK_ENERGIZED = 6U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_LOCK_DE_ENERGIZED = 7U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_MOTOR_75_PERCENT_OVERHEAT = 8U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_MOTOR_80_PERCENT_OVERHEAT = 9U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_MOTOR_85_PERCENT_OVERHEAT = 10U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_MOTOR_90_PERCENT_OVERHEAT = 11U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_MOTOR_95_PERCENT_OVERHEAT = 12U;
    constexpr uint8_t SYSTEM_MONITOR_STATUS_CLEAR_MOTOR_75_PERCENT_OVERHEAT = 13U;

    // Parameters for MOTION_CONTROL_STATUS
    constexpr uint8_t MOTION_CONTROL_STATUS_CLOSING = 0U;
    constexpr uint8_t MOTION_CONTROL_STATUS_MANUAL = 1U;
    constexpr uint8_t MOTION_CONTROL_STATUS_CLOSED = 2U;
    constexpr uint8_t MOTION_CONTROL_STATUS_OBSTRUCTED = 3U;
    constexpr uint8_t MOTION_CONTROL_STATUS_OPENING = 4U;
    constexpr uint8_t MOTION_CONTROL_STATUS_OPEN = 5U;
    constexpr uint8_t MOTION_CONTROL_STATUS_STALLED = 6U;
    constexpr uint8_t MOTION_CONTROL_STATUS_DRIFT_COMP = 7U;
    constexpr uint8_t MOTION_CONTROL_STATUS_STOPPED = 8U;
    constexpr uint8_t MOTION_CONTROL_STATUS_LEARN = 9U;

    // Parameters for PROGRAM_OVERRIDE
    constexpr uint8_t PROGRAM_OVERRIDE_PROGRAM_OFF = 0U;
    constexpr uint8_t PROGRAM_OVERRIDE_PROGRAM_EXIT = 1U;
    constexpr uint8_t PROGRAM_OVERRIDE_PROGRAM_AUTO = 2U;
    constexpr uint8_t PROGRAM_OVERRIDE_PROGRAM_OPEN = 3U;
    constexpr uint8_t PROGRAM_OVERRIDE_PROGRAM_LOCAL = 4U;

    // Parameters for THRESHOLD_TYPE_3
    constexpr uint8_t THRESHOLD_TYPE_3_STATUS_BELOW_THRESHOLD = 0U;
    constexpr uint8_t THRESHOLD_TYPE_3_STATUS_ABOVE_THRESHOLD = 1U;

    // Parameters for MOTION_CONTROL_COMMAND
    constexpr uint8_t MOTION_CONTROL_COMMAND_CLOSE = 0U;
    constexpr uint8_t MOTION_CONTROL_COMMAND_OPEN = 1U;
    constexpr uint8_t MOTION_CONTROL_COMMAND_STOP = 2U;
    constexpr uint8_t MOTION_CONTROL_COMMAND_FREE_SWING = 3U;
    constexpr uint8_t MOTION_CONTROL_COMMAND_LOCK_RETRY_OPEN = 4U;
    constexpr uint8_t MOTION_CONTROL_COMMAND_SLOW_OPEN = 5U;
    constexpr uint8_t MOTION_CONTROL_COMMAND_LOCK_RELEASE = 6U;
    constexpr uint8_t MOTION_CONTROL_COMMAND_LEARN = 7U;

    // Parameters for PARAMETER_GET_DATA
    constexpr uint8_t PARAMETER_GET_DATA_TYPE_VALUE = 0U;
    constexpr uint8_t PARAMETER_GET_DATA_TYPE_DEFINITION = 1U;
    constexpr uint8_t PARAMETER_GET_DATA_TYPE_MAP = 2U;

    // Parameters for IMPULSE
    constexpr uint8_t IMPULSE_TYPE_INNER = 0U;
    constexpr uint8_t IMPULSE_TYPE_OUTER = 1U;
    constexpr uint8_t IMPULSE_TYPE_KEY = 2U;
    constexpr uint8_t IMPULSE_TYPE_OPEN_CLOSE = 3U;
    constexpr uint8_t IMPULSE_TYPE_PRESENCE_DETECT = 4U;
    constexpr uint8_t IMPULSE_TYPE_RUO = 5U;
    constexpr uint8_t IMPULSE_TYPE_PAG = 6U;
    constexpr uint8_t IMPULSE_TYPE_PROGRAM_OFF = 7U;
    constexpr uint8_t IMPULSE_TYPE_PROGRAM_OPEN = 8U;

    // Parameters for SYS_MON_THRES
    constexpr uint8_t SYS_MON_THRES_STATUS_BELOW_THRESHOLD = 0U;
    constexpr uint8_t SYS_MON_THRES_STATUS_ABOVE_THRESHOLD = 1U;

    // Parameters for SYS_MON_THRES
    constexpr uint8_t SYS_MON_THRES_ID_OVERV_ENCODER = 0U;
    constexpr uint8_t SYS_MON_THRES_ID_UNDERV_ENCODER = 1U;
    constexpr uint8_t SYS_MON_THRES_ID_MAIN_VOL_THRESHOLD_ID = 2U;
    constexpr uint8_t SYS_MON_THRES_ID_MAIN_VOL_OVERVOL_THRESHOLD_ID = 3U;
    constexpr uint8_t SYS_MON_THRES_ID_MAIN_VOL_UNDERVOL_THRESHOLD_ID = 4U;
    constexpr uint8_t SYS_MON_THRES_ID_BR_CHOP_THRESHOLD_ID = 5U;
    constexpr uint8_t SYS_MON_THRES_ID_BR_CHOP_OVERVOL_THRESHOLD_ID = 6U;
    constexpr uint8_t SYS_MON_THRES_ID_MAIN_VOL_DIFF_THRESHOLD_ID = 7U;
    constexpr uint8_t SYS_MON_THRES_ID_GENERATOR_MODE_THRESHOLD_ID = 8U;
    constexpr uint8_t SYS_MON_THRES_ID_SHORTCIRCUIT_EXTVOLT = 9U;
    constexpr uint8_t SYS_MON_THRES_ID_OVERVOLT_EXTVOLT = 10U;
    constexpr uint8_t SYS_MON_THRES_ID_VOLT_DIFF_MOTOR = 11U;
    constexpr uint8_t SYS_MON_THRES_ID_AMP_DIFF_MOTOR = 12U;

    // Parameters for THRESHOLD_TYPE_5
    constexpr uint8_t THRESHOLD_TYPE_5_STATUS_BELOW_THRESHOLD = 0U;
    constexpr uint8_t THRESHOLD_TYPE_5_STATUS_ABOVE_THRESHOLD = 1U;

    // Parameters for THRESHOLD_TYPE_4
    constexpr uint8_t THRESHOLD_TYPE_4_STATUS_BELOW_THRESHOLD = 0U;
    constexpr uint8_t THRESHOLD_TYPE_4_STATUS_ABOVE_THRESHOLD = 1U;

    extern const uint8_t arMessageSize[NUMBER_OF_MESSAGE_IDS];
}

#endif // MESSAGE_IDS_HEADER_INCLUDE_GUARD
