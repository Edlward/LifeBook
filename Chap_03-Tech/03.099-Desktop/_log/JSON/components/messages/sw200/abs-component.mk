$(eval $(abs-begin))

ABS_INTERFACE := \
    inc \
    inc/messages \
    ../../application/aaesGeneric/messageRouter/inc/ \

ABS_SOURCE_FILES := \
    src/messages.cpp \
    src/message_base.cpp \
    src/message.cpp \
    src/message_helper.cpp \

ABS_GEN_SOURCE_FILES :=

ABS_LIB_SOURCE_FILES :=

ABS_DEFINES := 

ABS_COMPILE_FLAGS := 

ABS_LINK_FLAGS :=

ABS_LINK_SCRIPT :=

ABS_LIBRARIES := supc++

ABS_SUPPRESS_WARNINGS :=

ABS_DOXYGEN_INPUT := inc

$(eval $(abs-end))
