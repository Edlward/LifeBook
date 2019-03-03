$(eval $(abs-begin))

ABS_LOCAL_COMPONENTS := \
    conf \


ABS_COMPONENTS := \
    components/application/mbsConsole \
    components/application/mbsConsole/serial \
    components/application/aaesGeneric/systemTimer \
    components/application/test/helloMotor \
    components/common/log/consoleCmds \
    components/common/error/consoleCmds \
    components/common/stdlib/consoleCmds \
    components/common/fwHeader \
    components/halFunc/timestamp/generic \
    components/halFunc/timestamp/specific/stm32f10x \
    components/application/aaesGeneric/aaesCommon \
    components/system/can \



_DEBUG_PORT_ := 1

ifdef  _DEBUG_PORT_

ABS_COMPONENTS += \
    components/application/test/gpioTestPins \
    components/application/test/debugPort \

endif #_DEBUG_PORT_


$(eval $(abs-end))
