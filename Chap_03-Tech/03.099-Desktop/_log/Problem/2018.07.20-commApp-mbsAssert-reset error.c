//example.
01. /c/mbs/programs/bin/addr2line.exe -e products-quasarMotor.elf 0x803103f
$ /c/mbs/programs/bin/addr2line -e products-quasarMotor.elf 0x801d03f
C:\mbs\SwingDoorPlatform/components/application/aaesGeneric/messageRouter/src/messageRouter.cpp:236

void MessageRouterImp::vTransmitToOneNode ( MbsMsg* const pMessageCopy, const uint8_t ui8RxIndex )
mbsAssert( MBS_STATUS_OK == mbsMsgSend( NULL, address, pMessageCopy, MBS_MSG_TIMEOUT_NOW ) );


02. ## Assert failed at LR 0x801D03F, task commApp
 CAN send message to MIAN, MAIN need to register message, but NOT.
 
03. vTaskDelayUntil( &xLastWakeTime, 100 );
	static void commApp( void* pvParameters )
	
04. messageRoutingTable.cpp ///* ui8Subscribers     */ { static_cast<uint8_t>( MAIN ), 255U }  
						      /* ui8Subscribers     */ {255U, 255U }
C:\mbs\SwingDoorPlatform\modules\messageRouter\motorBoard\mbs_st_m64_core_v10\config\src\messageRoutingTable.cpp
