/*
 * Submodule that Handles Imu functions
 * Credit:Michael 
 * Created:
 * Updated By Scorpion 
 * Last update: 4/3/2024
*/
#include <Wire.h>

//IMU Parameters and Variables
#define PI 3.14
#define IMU_XACC_Error  -0.02
#define IMU_YACC_Error   0.00
#define IMU_ZACC_Error  -0.03
#define IMU_XDOT_Error  1.14 * PI / 180
#define IMU_YDOT_Error  -1.87 * PI / 180
float xDotIMU, yDotIMU;
float AccX, AccY, AccZ;
float xPosIMU = 0;
float yPosIMU = 0;

void updateIMU(void);
void initIMU();
float GetxPosIMU(void);
float GetyPosIMU(void);
