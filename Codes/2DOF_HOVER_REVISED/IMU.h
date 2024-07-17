/*
 * Submodule that Handles IMU functions
 * Credit: Michael
 * Created:
 * Updated By: Scorpion
 * Last update: 4/3/2024
*/
#pragma once
#include <Wire.h>
#include "Parameters.h"

// Function to update IMU readings
void updateIMU(void) {
  // Request Acceleration data
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

  // Request Gyro data
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);
  Wire.write(0x08);
  Wire.endTransmission();
  
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  
  Wire.requestFrom(0x68, 6);
  int16_t GyroX = Wire.read() << 8 | Wire.read();
  int16_t GyroY = Wire.read() << 8 | Wire.read();
  int16_t GyroZ = Wire.read() << 8 | Wire.read();

  // Convert raw data into SI units

  // Angle Rates
  yDotIMU = (float)GyroX / 65.5 + IMU_XDOT_Error; // rad/s
  xDotIMU = (float)GyroY / 65.5 + IMU_YDOT_Error;

  // Acceleration
  AccX = (float)AccXLSB / 4096 + IMU_XACC_Error; // m/s^2 (subtracting calibration values)
  AccY = (float)AccYLSB / 4096 + IMU_YACC_Error;
  AccZ = (float)AccZLSB / 4096 + IMU_ZACC_Error;

  // Calculate the position from trigonometry and current acceleration
  xPosIMU = atan(AccY / sqrt(AccX * AccX + AccZ * AccZ));
  yPosIMU = -atan(AccX / sqrt(AccY * AccY + AccZ * AccZ));
}

// Function to initialize IMU
void initIMU() {
  // Set the clock and begin the wire interface (clock values are from datasheet)
  Wire.setClock(400000);
  Wire.begin();
  delay(250); // Wait for initialization
  
  Wire.beginTransmission(0x68); // Begin communication with MPU6050 address
  Wire.write(0x6B); // Initialize command
  Wire.write(0x00);
  Wire.endTransmission(); // Send packet
}
