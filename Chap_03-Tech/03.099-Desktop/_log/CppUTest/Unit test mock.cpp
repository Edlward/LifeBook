

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


