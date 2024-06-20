// #include "F:\College\Semester_10\GP2\2DOF\2DOF_Hover\Model\2DOF_SL\Motors_and_Propellers.h"
#include "arduino.h"
#include "Motors_and_Propellers.h"
#include "ESP32Servo.h"
#include "Motors.h"

void setupFunctionMotors_and_Propellers(){
    initESCs(FrontMotorPIN ,RightMotorPIN ,BackMotorPIN ,LeftMotorPIN );
}


// Xaction double [1,1]
// Yaction int8 [1,1]

void stepFunctionMotors_and_Propellers(double Xaction,int size_vector_a,int8_T Yaction,int size_vector_b){
  writeControlAction(Xaction,Yaction);
}