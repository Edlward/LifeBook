如果是“纯虚函数”，即 virtual int run() = 0;编译时会报" because the following virtual functions are pure within 'Test' "

     如果在基类中实现了虚函数，或者在子类中实现纯虚函数或虚函数，就不会报错。

     包含有虚函数的类，是不能创建对象的。
	 
	 In file included from src/closeCommandTest.cpp:18:0:
inc/motionCommandTestCommon.hpp:61:40: error: cannot declare variable 'motionCommandTestHelpers::torqueLimiter' to be of abstract type 'TorqueLimiterMock'
     extern TorqueLimiterMock           torqueLimiter;
                                        ^
In file included from inc/motionCommandTestCommon.hpp:26:0,
                 from src/closeCommandTest.cpp:18:
../../../../../unitTest/common/inc/torqueLimiterMock.hpp:21:7: note:   because the following virtual functions are pure within 'TorqueLimiterMock':
 class TorqueLimiterMock : public motionControl::TorqueLimiter
       ^
In file included from src/../../inc/closeCommandImp.hpp:26:0,
                 from src/closeCommandTest.cpp:16:
../../../../../components/application/swingDoorGeneric/torqueLimiter/inc/torqueLimiter.hpp:52:22: note: 	virtual void motionControl::TorqueLimiter::vUpdate(int32_t, int32_t, uint8_t) volatile
         virtual void vUpdate ( const int32_t si32Position, const int32_t si32Voltage, const uint8_t ui8MotionControlStatus) volatile = 0;
                      ^