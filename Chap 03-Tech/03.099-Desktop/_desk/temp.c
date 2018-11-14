    
	hardware limit: 4000*2555/256        = 39921,
	negative hardware limit:-4000*2555/256=-39921
    power limit  : (90000/24)*(2555/256) = 37426
	power limit  : (90000/26)*(2555/256) = 34547,
	
	max low energy limit:-45000+67000+1000=23000.
	min low energy limit:-45000-67000-1000=-103000.
	
	si32TargetMaxTorqueLimitInMilliNm = siCalculatePowerTorqueLimit(si32SetMotorVoltage); //(90000/24)*(2555/256)=37426
	si32TargetMaxTorqueLimitInMilliNm = siCalculateHardwareTorqueLimit(); //4000*2555/256=39921.
	si32TargetMinTorqueLimitInMilliNm = - siCalculateHardwareTorqueLimit(); //-4000*2555/256=-39921.
	si32TargetMinTorqueLimitInMilliNm = siCalculatePowerTorqueLimit(si32SetMotorVoltage); //(90000/-24)*(2555/256)=-37426
	
	
	//power limit: (90000/24)*(2555/256)=37426, 
    //max low energy limit:-45000+67000+1000=23000.
    si32TargetMaxTorqueLimitInMilliNm = siCalculateMaxLowEnergyTorqueLimit(si32SetSpringTorqueMilliNm);
    //extended set: -6000*(30/100)=-18000, 
	//min low energy limit:-45000-67000-1000=-103000.
	
	//switch to auto mode
    eTorqueModeTest = motionControl::TorqueLimiter::TORQUE_MODE_AUTO;
	
    int32_t siLastTargetMinLimitTorque = si32TargetMinTorqueLimitInMilliNm;
    //extended closing setting:-60000.
    //negative hardware limit:-4000*2555/256=-39921
    si32TargetMinTorqueLimitInMilliNm = - siCalculateHardwareTorqueLimit(); //-4000*2555/256=-39921.
    if (si32TargetMinTorqueLimitInMilliNm > si32TargetMaxTorqueLimitInMilliNm)
    {
        si32TargetMinTorqueLimitInMilliNm = si32TargetMaxTorqueLimitInMilliNm;
    }
    siDeltaRampMinLimitTorqueInMilliNm = si32TargetMinTorqueLimitInMilliNm - siLastTargetMinLimitTorque;
	
	
	arguments:  -r1 -v
	
	cyggcc_s-1.dll
	cygwin1.dll
	cygstdc++-6.dll
	
	
	
	
	
	
	
	
	
	