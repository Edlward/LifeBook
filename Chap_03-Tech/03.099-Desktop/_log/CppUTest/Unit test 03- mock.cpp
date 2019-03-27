

010. onObject.
	
mock().expectOneCall( "vUpdateSpeedController" )
	  .onObject( &normalSpeedController )
	  .withParameterOfType( "int16_t", "si16SetSpeed", static_cast<const void*>( &si16FeedBackShaftSpeed ) )
	  .withParameterOfType( "int16_t", "si16FeedBackSpeed", static_cast<void*>( &si16FeedBackShaftSpeed ) );
	
void SpeedControllerMock::vUpdate ( int16_t si16SetSpeed, int16_t si16FeedbackSpeed ) volatile
{
    mock().actualCall( "vUpdateSpeedController" )
          .onObject(const_cast<SpeedControllerMock*>( this ) )
          .withParameterOfType( "int16_t", "si16SetSpeed", static_cast<void*>( &si16SetSpeed ) )
          .withParameterOfType( "int16_t",  "si16FeedBackSpeed", static_cast<void*>( &si16FeedbackSpeed ) );
}


011. 结构体指针的模拟仿制（模拟考试）imitate to replace.
//! Mock function for the mcuGpioStm32f10xConfigure function that is used to configure GPIO ports
bool mcuGpioStm32f10xConfigure( Stm32f10xPhysPortPinConf const * config,
                                uint16_t                         configSize )
{
    mock().actualCall ( "mcuGpioStm32f10xConfigure" )
          .withParameterOfType ( "GPIOMode_TypeDef",  "gpioMode",  static_cast<const void*>( &config->mode ) )
          .withParameterOfType ( "GPIO_TypeDef*",     "gpioPort",  static_cast<const void*>( &config->physicalPort ) )
          .withParameterOfType ( "uint16_t",          "gpioPin",   static_cast<const void*>( &config->physicalPins ) )
          .withParameterOfType ( "uint32_t",          "gpioClock", static_cast<const void*>( &config->clock ) )
          .withParameterOfType ( "GPIOSpeed_TypeDef", "gpioSpeed", static_cast<const void*>( &config->speedMhz ) )
          .withParameterOfType ( "uint16_t",          "gpioSize",  static_cast<      void*>( &configSize ) );

    return mock().returnBoolValueOrDefault( true );
}

typedef struct
{
    GPIOMode_TypeDef  mode;
    GPIO_TypeDef *    physicalPort;
    uint16_t          physicalPins;
    uint32_t          clock;
    GPIOSpeed_TypeDef speedMhz;
} Stm32f10xPhysPortPinConf;


    mock().expectOneCall( "mbsMsgRequestCallbackSet" )
          .withPointerParameter( "handle", static_cast<void*>( handle ) )
          .andReturnValue( static_cast<void*>( requestHandler ) );
	  
	
//pointer.
void DoorCommandPriorityListMock::vSetActiveCommandAtDefinedPriority(doorControl::DoorCommandBackEnd* const pDoorCommand ) volatile
{
    mock().actualCall("vSetActiveCommandAtDefinedPriority")
          .withParameterOfType( "DoorCommandBackEnd", "pDoorCommand", static_cast<const void*>( pDoorCommand ) );
}

//interal private 
