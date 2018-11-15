//================================
1005-template:
{


}
//1005.

//================================
1008-questions:
{
0001-undefine stLibMock.cpp function.
	change unitTest/makefile.
	
	ABS_INTERFACE:
	C:\mbs\SwingDoorPlatform\components\application\aaesGeneric\adcInput\unitTest\abs-component.mk
	
0002. can not change private var in public. //boActive in GetStatus. should by vUpdate to call vWritePhysicalPinStatus.
0003. CDigitalOutputImp* pObject = ( new CDigitalOutputImp ...) //new， can: delete pObject;
}

----------------------------------------------	
project debug used file.
{

C:\mbs\SwingDoorPlatform\mbsSdk\components\halMcu\init\stm32f10x\src\start_ARMCM3.s
	SystemInit,
	//component.
	components/application/aaesGeneric/motor/src/motor.cpp			'cKP'
	components/application/helloWorld/motorboard/src/helloWorld.cpp		'hold-time, quasarMotor'
	//module.
	modules/input/motorBoard/mbs_st_m64_core_v10/init/src/input.cpp		'encoder-CW'
	modules/motionControl/motorBoard/mbs_st_m64_core_v10/init/src/motionControl.cpp	'OPN-88.5, Speed-loop'
	modules/motionControl/motorBoard/mbs_st_m64_core_v10/init/src/motionControl.cpp  'speedController = new motionControlInternal::SpeedControllerImp =20000'
	modules/input/motorBoard/mbs_st_m64_core_v10/init/src/input.cpp		"time"
	modules/output/motorBoard/mbs_st_m64_core_v10/init/src/output.cpp	"motor model."
	//product.
	products/quasarMotor/conf/mbsCfgTask.h					'cfg quasar.'
	products/quasarMotor/conf/mbsCfgTask.h
	//unit-test.
	/SwingDoorPlatform/mbsSdk/components/halMcu/gpio/stm32f10x/inc/mcuGpioStm32f10x.h
	/SwingDoorPlatform/unitTest/common/inc/CppUTest/TestHarness_c.h
}
	
	
//==========================
motor.cpp	
{	
C:\mbs\SwingDoorPlatform\modules\motionControl\motorBoard\mbs_st_m64_core_v10\init\src\
motionControl.cpp

	//Quasar
//	static  MotorImp myMotorImp(
//	/*motor direction*/			motorWrapper::CCW,
//	/*motor inductance*/		2300,		//2300uH
//	/*motor resistance*/		2600,		//2600mOhm
//	/*torque/current constant*/	46U,		//46milliNm/A
//	/*gear ration*/				245U
//	);
    //Quasar
    static  MotorImp myMotorImp(
         /*motor direction*/         motorWrapper::CCW,
         /*motor inductance*/        3200,       //2300uH
         /*motor resistance*/        4400,       //2600mOhm
         /*torque/current constant*/ 42U,        //46milliNm/A
         /*gear ration*/             245U
         );

	//SW300
/*	static  MotorImp myMotorImp(
	motor direction			motorWrapper::CCW,
	motor inductance		960,		//960uH
	motor resistance		430,		//430mOhm
	torque/current constant	58U,		//58milliNm/A
	gear ration				172U
	);*/
}
	
//==========example============
{
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

TEST_GROUP(MockDocumentation)
{
    void teardown()
    {
        mock().clear();
    }
};

void productionCode()
{
    mock().actualCall("productionCode");
}

TEST(MockDocumentation, SimpleScenario)
{
    mock().expectOneCall("productionCode");
    //productionCode();
    productionCode();
    mock().checkExpectations();
}

//
//TEST_GROUP (FirstTestGroup)
//{
//    //what should put in here?
//};
//
//TEST (FirstTestGroup, FirstTest)
//{
//    FAIL ("Fail me!");
//}

//TEST (FirstTestGroup, SecondTest)
//{
//    STRCMP_EQUAL ("aaa", "aaa");
//}

//-----------------------------------
//TEST_GROUP (MockManual)
//{
//    void setup ()
//    {
//
//    }
//    void teardown ()
//    {
//        mock().clear();
//    }
//};
//
//void productCode ()
//{
//    mock().actualCall("productCode");
//}
//
//TEST (MockManual, Called)
//{
//   mock().expectOneCall("productCode");
//   productCode();
//   mock().checkExpectations();
//}
	
}


//================================
1009-cppUTest:
{
	//usually.
    TEST(group, name) 			- define a test
    IGNORE_TEST(group, name) 	- turn off the execution of a test
    TEST_GROUP(group) 			- Declare a test group to which certain tests belong. This will also create the link needed from another library.
    TEST_GROUP_BASE(group, base) - Same as TEST_GROUP, just use a different base class than Utest
    IMPORT_TEST_GROUP(group) 	- Export the name of a test group so it can be linked in from a library (also see Advanced Stuff)
	
	//exit:
    CHECK(boolean condition) 	- checks any boolean result.
    CHECK_TEXT(boolean condition, text) - checks any boolean result and prints text on failure.
    CHECK_FALSE(condition) 		- checks any boolean result
    CHECK_EQUAL(expected, actual) - checks for equality between entities using ==. So if you have a class that supports operator==() you can use this macro to compare two instances. You will also need to add a StringFrom() function like those found in SimpleString. This is for printing the objects when the check failed.
    CHECK_COMPARE(first, relop, second) - checks thats a relational operator holds between two entities. On failure, prints what both operands evaluate to.
    CHECK_THROWS(expected_exception, expression) - checks if expression throws expected_exception (e.g. std::exception). CHECK_THROWS is only available if CppUTest is built with the Standard C++ Library (default).
    STRCMP_EQUAL(expected, actual) - checks const char* strings for equality using strcmp().
    STRNCMP_EQUAL(expected, actual, length) - checks const char* strings for equality using strncmp().
    STRCMP_NOCASE_EQUAL(expected, actual) 	- checks const char* strings for equality, not considering case.
    STRCMP_CONTAINS(expected, actual) 		- checks whether const char* actual contains const char* expected.
    LONGS_EQUAL(expected, actual) 			- compares two numbers.
    UNSIGNED_LONGS_EQUAL(expected, actual) 	- compares two positive numbers.
    BYTES_EQUAL(expected, actual) 			- compares two numbers, eight bits wide.
    POINTERS_EQUAL(expected, actual) 		- compares two pointers.
    DOUBLES_EQUAL(expected, actual, tolerance) - compares two floating point numbers within some tolerance
    FUNCTIONPOINTERS_EQUAL(expected, actual) - compares two void (*)() function pointers
    MEMCMP_EQUAL(expected, actual, size) 	- compares two areas of memory
    BITS_EQUAL(expected, actual, mask) 		- compares expected to actual bit by bit, applying mask
    FAIL(text) - always fails	
}