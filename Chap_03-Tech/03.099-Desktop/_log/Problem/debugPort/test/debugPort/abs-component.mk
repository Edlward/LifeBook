$(eval $(abs-begin))

ABS_INTERFACE := \
	inc \


ABS_SOURCE_FILES := \
    src/debugPort.cpp

ABS_GEN_SOURCE_FILES :=

ABS_LIB_SOURCE_FILES :=

ABS_DEFINES :=

ABS_COMPILE_FLAGS := \
    -fno-use-cxa-atexit \

ABS_LINK_FLAGS :=

ABS_LINK_SCRIPT :=

ABS_LIBRARIES := supc++

ABS_SUPPRESS_WARNINGS :=

ABS_DOXYGEN_INPUT := inc

$(eval $(abs-end))
