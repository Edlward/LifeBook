
##########################
/SwingDoorPlatform/mbsSdk/components/halMcu/init/stm32f10x/src/start_ARMCM3.s
    .word  _sidata //start init data 汇编，符号：划分区域
    .word  _edata  //end data
  
    //====== reset handler
    .section  .text.Reset_Handler
    .weak  Reset_Handler //weak alias
    .type  Reset_Handler, %function
Reset_Handler:
    bl  SetupCSys  //$$$$// --> Default_SetupCSys:
    bl  SystemInit          --> Default_SystemInit:
    bl  main                --> Default_main:

    //====== data init.
    .section  .text.Default_SetupCSys,"ax",%progbits
    .type Default_SetupCSys, %function
Default_SetupCSys:
CopyDataInit:
LoopCopyDataInit:
FillZerobss:    /* Zero fill the bss segment. */
LoopFillZerobss:

    //====== system init. 
    .section  .text.Default_SystemInit,"ax",%progbits
    .type Default_SystemInit, %function
Default_SystemInit:

    //====== main entry.
    .section  .text.Default_main,"ax",%progbits
    .type Default_main %function
Default_main: //jump to mbsMain.
    bl mbsMain
    
    //====== RTOS init.
    /SwingDoorPlatform/mbsSdk/components/common/systemControl/src/systemControl.c
    systemControlStart();
    {
        sysCtlResourceInit()
        {
            sysCtlLevelOrder();
            sysCtlFindMaxSynced();                                          // record->syncedInitFunction
            void *pvPortMalloc( size_t xWantedSize );                       // heap_4.c  堆栈大小，区块划分，管理
                        //vTaskSuspendAll();  prvHeapInit(); xFreeBytesRemaining, // task.c    暂停机制，什么情况需要暂停？
            resource->evGroupsPtr[ i ].eventGroup = xEventGroupCreate();    // 事件组，evGroup.
                        //pvPortMalloc( sizeof( EventGroup_t ); vListInitialise( &( pxEventBits->xTasksWaitingForBits ) );
            xEventGroupClearBits( resource->evGroupsPtr[ i ].eventGroup,
                        //taskENTER_CRITICAL();
            resource->parallelContextPtr = parallelCtxDataPtr;              // 上下文，
        }
        
        systemControlConfigure( SystemControlStartLists * startLists )
        sysCtlInitialize( SysCtlResources * resource
                        //dispatchEvent( initType, (SystemControlLevels)
                        //sysCtlExcluded( resource, record->name )
                        //sysCtlStartSynced( resource, record, order )
                        //sysCtlAwaitSynced( resource, false );
                        //sysCtlEvGrpClearAll( resource );
        
        if ( pdPASS == xTaskCreate( sysCtlTask, (const char * const )"systemControl", MBS_CFG_TASK_STACK_SYSTEM_CONTROL, (void * )thisResourcePtr, MBS_CFG_TASK_PRIO_SYSTEM_CONTROL, NULL ) )       //堆栈方向，分配； 任务控制块TCB，就绪链表；
                                                                            //状态链表StateListItem， 事件链表EventListItem
        {
            /* Start the FreeRTOS */
            vTaskStartScheduler();           //启动调度，创建空闲任务。之前有“启动任务startTask”，其先于空闲任务。
                        //xTaskCreateStatic(	prvIdleTask,
                        //xTimerCreateTimerTask();
                        //portDISABLE_INTERRUPTS();
                        //xSchedulerRunning = pdTRUE;
        /SwingDoorPlatform/mbsSdk/components/common/rtos/freeRTOS/Source/portable/GCC/ARM_CM3/port.c
                        //xPortStartScheduler( void ) //ucMaxPriorityValue & portTOP_BIT_OF_BYTE //vPortSetupTimerInterrupt();
                        //prvPortStartFirstTask();    //" svc 0					\n"
        }
        
        sysCtlTask( void * pvParameters )
            //sysCtlInitialize( SysCtlResources * resource ####
        sysCtlFreeResources();
        vTaskDelete();
    }    
   
    vTaskSuspendAll();      
    ( void ) xTaskResumeAll();
    ( void ) uxListRemove( &( pxTCB->xEventListItem ) );

    
    //======
    SYSTEM_CONTROL_REGISTER_SYNCED_INIT_FUNCTION( initSystemMonitor,   \
    
    #define SYSTEM_CONTROL_REGISTER_SYNCED_INIT_FUNCTION( _initFunctionName,                                                \
                                                      _initLevel,                                                       \
                                                      _initOrder )                                                      \
                                                                                                                        \
    void _initFunctionName( void * context );                                                                           \
                                                                                                                        \
    SystemControlInitListRecord const systemControlInitRecord_ ## _initLevel ## _initOrder ## _ ## _initFunctionName    \
                    __attribute__ ((section (".systemControlInitList")))                                                \
                    = {                                                                                                 \
                        .name                   = #_initFunctionName,                                                   \
                        .syncedInitFunction     = _initFunctionName,                                                    \
                        .unsyncedInitFunction   = NULL,                                                                 \
                        .level                  = _initLevel,                                                           \
                        .order                  = _initOrder,                                                           \
                        .initType               = SYSTEM_CONTROL_RTOS_RUNNING                                           \
                      };                                                                                                \
                                                                                                                        \
    void _initFunctionName( void * context )
    
    syncedInitFunction
    
    __attribute 语法的来源

GNU C 的一大特色就是__attribute__ 机制。attribute 可以设置函数属性（Function Attribute）、变量属性（Variable Attribute）和类型属性（Type Attribute）。

其位置约束为： 放于声明的尾部“;” 之前

attribute 书写特征为: attribute 前后都有两个下划线，并切后面会紧跟一对原括弧，括弧里面是相应的__attribute__ 参数。

attribute 语法格式为: attribute ((attribute-list))

当__attribute__ 用于修饰对象时，它就如同C 语言语法体系结构的类型限定符，跟const , volatile , restrict 等属一类。
当__attribute__ 用于修饰函数时，它就相当于一个函数说明符，跟inline，Noreturn 属同一类。
当__attribute_ 用于修饰一个结构体，联合体或者枚举类型，该限定符只能放在类型标识符之前。

    
    
    //======
    canSrvInitExt
    
    txDataPtr->queueHandle = xQueueCreate( CAN_SRV_TX_BUFFER_SIZE, sizeof( CanMessage ) );
    
    txDataPtr->txMutexHandle = xSemaphoreCreateMutex();
    
    rc = xTaskCreate( canSrvTxTask,


##########################
/SwingDoorPlatform/mbsSdk/components/common/systemControl/src/systemControl.c
    int mbsMain( void )
    void systemControlStart( void )
    xTaskCreate( sysCtlTask
    vTaskStartScheduler();
    
    
    
##########################    
/SwingDoorPlatform/modules/drivers/can/mbs_st_m64_core_v10/config/src/canDriverConfig.c
    static "Stm32f10xPeripheralConfig" const stm32f10xPeripheralConfig1
    /* 125kB/s = 8us/bit, 32Mhz clock -> prescale by 18 */
    
    memcpy( &CAN_InitStructure,
        &( peripheralPtr->canSettings ),
        sizeof( CAN_InitTypeDef ) );
            
   CAN_Init( peripheralPtr->CANx, &CAN_InitStructure) );



