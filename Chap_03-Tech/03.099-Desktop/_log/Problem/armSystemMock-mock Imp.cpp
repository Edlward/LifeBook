/**
  \file armSystemMock.cpp

  \par Copyright &copy; 2018 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \addtogroup TestCommon
  \{
 */

#include "armSystemMock.hpp"
#include "armTables.hpp"
#include "armSystem.hpp"
#include "armSystemImp.hpp"
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

//motionControlInternal::ArmSystemImp::ArmSystemImp( ) :
//pcrArmTable                            ( NULL ),
//si32CurrentDoorAngleInMicroRad         ( 0 ),
//si16CurrentDoorSpeedInMilliRadPerSecond( 0 ),
//si16CurrentGearRatioTimes1024          ( 1024 )
//{
////    pcrArmTable = NULL;
////    si32CurrentDoorAngleInMicroRad = 0;
////    si16CurrentDoorSpeedInMilliRadPerSecond = 0;
////    si16CurrentGearRatioTimes1024 = 1024;
//}

ArmSystemMock::ArmSystemMock():
    motionControlInternal::ArmSystemImp()
{
    si32DefaultDoorAngle = 0;
    si16DefaultDoorSpeed = 0;
    si16DefaultGearRatio = 1000;
}

ArmSystemMock::~ArmSystemMock()
{
}
int32_t ArmSystemMock::si32GetDoorAngleInMicroRad () const volatile
{
    return *static_cast<int32_t*>( mock().actualCall( "si32GetDoorAngleInMicroRad" )
                                        .returnPointerValueOrDefault( (void*)( &si32DefaultDoorAngle ) ) );
}

int16_t ArmSystemMock::si16GetDoorSpeedInMilliRadPerSecond () const volatile
{
    return *static_cast<int16_t*>( mock().actualCall( "si16GetDoorSpeedInMilliRadPerSecond" )
                                        .returnPointerValueOrDefault( (void*)( &si16DefaultDoorSpeed ) ) );
}

int16_t ArmSystemMock::si16GetGearRatioTimes1024 () const volatile
{
    return *static_cast<int16_t*>( mock().actualCall( "si16GetGearRatioTimes1024" )
                                        .returnPointerValueOrDefault( (void*)( &si16DefaultGearRatio ) ) );
}

int32_t ArmSystemMock::si32DoorToShaftAngleInMicroRad ( const int32_t si32DoorAngle ) const volatile
{
    return *static_cast<int32_t*>( mock().actualCall( "si32DoorToShaftAngleInMicroRad" )
                                         .withParameterOfType( "int32_t", "si32DoorAngle", static_cast<const void*>( &si32DoorAngle ) )
                                         .returnPointerValueOrDefault( (void*)( &si32DoorAngle ) ) );
}

void ArmSystemMock::vSelectArmTable ( const teArmTableType eArmTable ) volatile
{
    //! do nothing
}

void ArmSystemMock::vUpdate (int32_t si32ShaftAngle, int16_t si16ShaftSpeed)  volatile
{
    mock().actualCall( "vUpdateArmSystem" )
          .withParameterOfType( "int32_t", "si32ShaftAngle", static_cast<void*>( &si32ShaftAngle ) )
          .withParameterOfType( "int16_t", "si16ShaftSpeed", static_cast<void*>( &si16ShaftSpeed ) );
}

void ArmSystemMock::vSetDefaultDoorAngle( int32_t si32DoorAngle )
{
    si32DefaultDoorAngle = si32DoorAngle;
}

void ArmSystemMock::vSetDefaultDoorSpeed( int16_t si16DoorSpeed )
{
    si16DefaultDoorSpeed = si16DoorSpeed;
}

void ArmSystemMock::vSetDefaultGearRatio( int16_t si16GearRatio )
{
    si16DefaultGearRatio = si16GearRatio;
}

#ifndef _ARM_SYSTEM_IS_INCLUDED_IN_DUT_

//#include "armSystem.cpp"
//#include "armTables.cpp"

motionControl::ArmSystem::~ArmSystem()
{
    // C++ demands that even a pure virtual destructor has an implementation.
}

motionControlInternal::ArmSystemBackEnd::~ArmSystemBackEnd()
{
}

//
//motionControlInternal::ArmSystemImp::~ArmSystemImp()
//{
//}

namespace motionControlInternal
{
    const uint16_t ArmSystemImp::cui16LastTableIndex = static_cast<const uint16_t>( ARM_TABLE_SIZE ) - 1U;

    ArmSystemImp::ArmSystemImp( ) :
        pcrArmTable                            ( NULL ),
        si32CurrentDoorAngleInMicroRad         ( 0 ),
        si16CurrentDoorSpeedInMilliRadPerSecond( 0 ),
        si16CurrentGearRatioTimes1024          ( 1024 )
    {

    }

    int32_t ArmSystemImp::si32GetDoorAngleInMicroRad () const volatile
    {
        return si32CurrentDoorAngleInMicroRad;
    }

    int16_t ArmSystemImp::si16GetDoorSpeedInMilliRadPerSecond () const volatile
    {
        return si16CurrentDoorSpeedInMilliRadPerSecond;
    }

    int16_t ArmSystemImp::si16GetGearRatioTimes1024 () const volatile
    {
        return si16CurrentGearRatioTimes1024;
    }

    int32_t ArmSystemImp::si32DoorToShaftAngleInMicroRad ( const int32_t csi32DoorAngle ) const volatile
    {
        const int32_t csi32MaxDoorAngleInMicroRad = static_cast<const int32_t>( cui16LastTableIndex )*10000; //lint !e648 ToDo Remove when PC-Lint interpretation of int32_t has been fixed
        int32_t si32ShaftAngleInMicroRad = 0;

        return si32ShaftAngleInMicroRad;
    }

    void ArmSystemImp::vSelectArmTable ( const ArmSystemBackEnd::teArmTableType ceArmTable ) volatile
    {

    }

    void ArmSystemImp::vUpdate( const int32_t csi32ShaftAngle, const int16_t csi16ShaftSpeed ) volatile
    {

    }

//    //lint -esym(613, motionControlInternal::ArmSystemImp::pcrArmTable)
//    // This function is a helper function that will only be called from the si32DoorToShaftAngleInMicroRad function, which includes a check that pcrArmTable != NULL
//    int32_t ArmSystemImp::si32InterpolateToFindShaftAngleInMicroRad ( const int32_t csi32DoorAngleInMicroRad ) const volatile
//    {
//        int32_t si32ShaftAngleInMicroRad = csi32DoorAngleInMicroRad;
//
//        return si32ShaftAngleInMicroRad;
//    } //lint +esym(613, motionControlInternal::ArmSystemImp::pcrArmTable)
//
//    //lint -esym(613, motionControlInternal::ArmSystemImp::pcrArmTable)
//    // This function is a helper function that will only be called from the vUpdate function, which includes a check that pcrArmTable != NULL
//    void ArmSystemImp::vDoBinarySearchAndInterpolationInTables( const int32_t csi32ShaftAngle ) volatile
//    {
//    } //lint +esym(613, motionControlInternal::ArmSystemImp::pcrArmTable)
//
//    void ArmSystemImp::vCalculateDoorSpeed ( const int16_t csi16ShaftSpeed ) volatile
//    {
//        int32_t si32CurrentDoorSpeedInMilliRadPerSecond = csi16ShaftSpeed;
//    }

    ArmSystemImp::~ArmSystemImp()
    {
        pcrArmTable = NULL;
    }
} /* Namespace motionControlInternal */

namespace motionControlInternal {
/* Pull conversion tables created with:
  A:0.0 B:240.0 O:28.5 F:15.0 C:17.5 K:0.0 L:370.0 */
    const trArmTablesType ArmSystemImp::crArmTablePull =
    {
        //lint -e{9034} -e{712} -e{569} -e{1960} ToDo fix definition of int32_t in lint
        /* .csi32ShaftAngleInMicroRad = */
        {
                     2826727,
        },
        /* .csi16GearRatioTimes1024 = */
        {
                  1689,
        }
    };
/* Push conversion tables created with:
  A:0.0 B:240.0 O:28.5 F:65.0 C:15.47 K:280.0 L:284.1 */
    const trArmTablesType ArmSystemImp::crArmTablePush =
    {
        //lint -e{9034} -e{712} -e{569} -e{1960} ToDo fix definition of int32_t in lint
        /* .csi32ShaftAngleInMicroRad = */
        {
                     3139011,
        },
        /* .csi16GearRatioTimes1024 = */
        {
                  1166,
        }
    };
} /* end of namespace motionControlInternal */

#endif
/**
  \}
 */

