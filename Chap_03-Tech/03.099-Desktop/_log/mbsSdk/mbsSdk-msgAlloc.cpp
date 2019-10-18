/SwingDoorPlatform/mbsSdk/components/common/messaging/src/mbsMessagingMessage.c
    MbsMsg * mbsMsgAlloc( uint32_t size )

/SwingDoorPlatform/mbsSdk/components/common/buffer/src/mbsBuffer.c
    void * mbsBufferAlloc( uint32_t size )
    ----mbsBufferDynamicAlloc( size );

/SwingDoorPlatform/mbsSdk/components/common/buffer/src/mbsBufferDynamic.c
    xPortGetFreeHeapSize();

/SwingDoorPlatform/mbsSdk/components/common/rtos/freeRTOS/Source/portable/MemMang/heap_4.c
    size_t xPortGetFreeHeapSize( void )
    {
        return xFreeBytesRemaining;
    }