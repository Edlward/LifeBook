
//-1.1-// enum
enum { MAX_LEARN_CYCLE_TIME = 120000 }; /* ms */

//-1.2-// help variables  //类似全局变量，不用函数传参，方便。
int32_t si32DoorAngle = 0;

class Xxx_UnitTest_ConfigClass
{	/* This class is used to create the unit-test parameters,
	and equips the methods to configurate the parameters. */
	public: //methods.
		void vSetMaxMinStartAndTargetLimit(	int32_t si32MaxStart,
											int32_t si32MinStart,
											int32_t si32MaxTarget,
											int32_t si32MinTarget );
		void vUpdateMaxMinStartAndTargetLimitByRampTimes( /*int32_t si32OldMaxStart,
                                                      int32_t si32OldMinStart,
                                                      int32_t si32OldMaxTarget,
                                                      int32_t si32OldMinTarget,  # already in class # */
                                                      int32_t si32NewMaxTarget,
                                                      int32_t si32NewMinTarget, 
                                                      uint16_t ui16RampTimes);
		int32_t siCalculatePowerTorqueLimit(int32_t si32SetVoltage);
		
	public: //configurations. //as public, easy to use for config.
		motionControl::TorqueLimiter::teTorqueModeType  eTorqueModeTest;
		bool boSetMockSpringExistStateTest;
		uint8_t ui8ExtendedClosingPercentTest;
		int32_t si32SetMotorPowerInMilliWatt;
		int32_t si32TargetMaxTorqueLimitInMilliNm;
		int32_t si32StartMaxTorqueLimitInMilliNm;
};
Xxx_UnitTest_ConfigClass                            torqueLimitTest;
Xxx_UnitTest_ConfigClass* const pTorqueLimitTest = &torqueLimitTest;


//-2.1-// FSM goto product function.  
motionControl::MotionCommand* pGotoSettleDoorStopPhase();

//-2.2-// Use configurations.
void vTestUseConfig_NormalLearnResults ( 0 /*pv1*/, 1 /*pv2*/, 2 /*pv3*/ );

//-2.3-// Function Test helper function.   (If not reused, can write code directly.)
void vTestReleaseTension(motionControl::MotionCommand* testLearnCommad);

//-2.4-// Function Expect helper product function. //"产品功能" (If not reused, can expect directly.)
void vExpectReleaseTension(motionControl::MotionCommand* testLearnCommad);

//-3.1-// "Repeat" expect helper function code.   //"函数代码"   //重复的代码，封装为函数；同类多数据，传入为参数。
void vSubExpectGetDoorAngle ( int32_t* psi32DoorAngle ); //subroutine

//-4-// TEST.
TEST( LearnCommand, RestartLearnCommand)
