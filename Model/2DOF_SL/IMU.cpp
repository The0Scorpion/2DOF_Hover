//#include "F:\College\Semester_10\GP2\2DOF\2DOF_Hover\Model\2DOF_SL\IMU.h"
#include <arduino.h>
#include <Wire.h>
#include "IMU.h"
#include "IMU_Michael.h"



void setupFunctionIMU(){
    initIMU();
}

// IMU_X double [1,1]
// IMU_Y double [1,1]


void stepFunctionIMU(double * IMU_X,int size_vector_1,double * IMU_Y,int size_vector_2){
  updateIMU();
  *IMU_X = GetxPosIMU();
  *IMU_Y = GetyPosIMU();

}