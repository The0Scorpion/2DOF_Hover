#include <Wire.h>
float xDotIMU, yDotIMU;
float AccX, AccY, AccZ;
float xPosIMU = 0; // put initial angles of our drone
float yPosIMU = 0; // put initial angles of our drone



void updateIMU(void) {
  //too recheck
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
  xDotIMU = (float)GyroX / 65.5;
  yDotIMU = (float)GyroY / 65.5;
  AccX = (float)AccXLSB / 4096 - 0.02;
  AccY = (float)AccYLSB / 4096;
  AccZ = (float)AccZLSB / 4096 - 0.03;
  xPosIMU = atan(AccY / sqrt(AccX * AccX + AccZ * AccZ));
  yPosIMU = -atan(AccX / sqrt(AccY * AccY + AccZ * AccZ));
  xDotIMU += 1.14 * PI / 180;
  yDotIMU -= 1.87 * PI / 180;
}

void initIMU() {
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
}
