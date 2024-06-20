/*
 * Submodule that Handles Imu functions
 * Credit:Michael 
 * Created:
 * Updated By Scorpion 
 * Last update: 4/3/2024
*/

#include "IMU_Michael.h"

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


void updateIMU(void) {
  //to recheck
  //request Acceleration
  Wire.beginTransmission(0x68); 
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x1C);
  Wire.write(0x10);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 6);
  int16_t AccXLSB = Wire.read() << 8 | Wire.read();
  int16_t AccYLSB = Wire.read() << 8 | Wire.read();
  int16_t AccZLSB = Wire.read() << 8 | Wire.read();

  //request Angle rates
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);
  Wire.write(0x8);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 6);
  int16_t GyroX = Wire.read() << 8 | Wire.read();
  int16_t GyroY = Wire.read() << 8 | Wire.read();
  int16_t GyroZ = Wire.read() << 8 | Wire.read();

  //convert raw data into SI units
  //Angle Rates
  yDotIMU = (float)GyroX / 65.5 + IMU_XDOT_Error; //rad/s
  xDotIMU = (float)GyroY / 65.5 + IMU_YDOT_Error;

  //Acceleration
  AccX = (float)AccXLSB / 4096 + IMU_XACC_Error; // m/s^2  //minus the calibration values
  AccY = (float)AccYLSB / 4096 + IMU_YACC_Error;
  AccZ = (float)AccZLSB / 4096 + IMU_ZACC_Error;

  //Calculate The Position from trigonometry and current ACC
  xPosIMU = atan(AccY / sqrt(AccX * AccX + AccZ * AccZ));
  yPosIMU = -atan(AccX / sqrt(AccY * AccY + AccZ * AccZ));
  

}

float GetxPosIMU(void)
{
  return xPosIMU;
}
float GetyPosIMU(void)
{
  return yPosIMU;
}


void initIMU() {
  //Sets the clock and begins the wire interface (clock Values are from datasheet)
  Wire.setClock(400000);
  Wire.begin();
  delay(250); //waits for init
  
  Wire.beginTransmission(0x68); //begin talking to mpu6050 address
  Wire.write(0x6B);  //init command
  Wire.write(0x00);
  Wire.endTransmission(); //send packet
}
