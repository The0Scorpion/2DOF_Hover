#include "F:\College\Semester_10\GP2\2DOF\2DOF_Hover\Model\2DOF_SL\Motors_Propellers.h"
#include "Arduino.h"
#include "ESP32Servo.h"
#include "Motors.h"

void setupFunctionMotors_Propellers(){
    initESCs(FrontMotorPIN , RightMotorPIN ,BackMotorPIN ,LeftMotorPIN);
}


// Xaction int32 [1,1]
// Yaction int32 [1,1]

void stepFunctionMotors_Propellers(int32_T Xaction,int size_vector_a,int32_T Yaction,int size_vector_b){
  writeControlAction(Xaction , Yaction);
}