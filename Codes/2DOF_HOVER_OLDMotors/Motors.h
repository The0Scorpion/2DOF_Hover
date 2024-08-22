/*
   Submodule That contains all the brushless motor functions
   Credit:Scorpion
   Created: 14/11/2023
*/

#pragma once
#include <ESP32Servo.h>

//#define DebugMotor
Servo Fmotor,Rmotor,Bmotor,Lmotor;
//initialize ESCs and set running flag
void initESCs() {
  Fmotor.attach(FrontMotorPIN);
  Rmotor.attach(RightMotorPIN);
  Bmotor.attach(BackMotorPIN);
  Lmotor.attach(LeftMotorPIN);
  Fmotor.write(0);
  Rmotor.write(0);
  Bmotor.write(0);
  Lmotor.write(0);
  delay(1000);
  //start up motors

  for (unsigned int i = 1000; i < 1100; i += 5) {
    Fmotor.writeMicroseconds(i);
    Rmotor.writeMicroseconds(i);
    Bmotor.writeMicroseconds(i);
    Lmotor.writeMicroseconds(i);
    delay(1);
  }
  delay(200);
  ESC_Running = 1;
}
void DisableMotors() {
  Fmotor.attach(FrontMotorPIN);
  Rmotor.attach(RightMotorPIN);
  Bmotor.attach(BackMotorPIN);
  Lmotor.attach(LeftMotorPIN);
  Fmotor.write(0);
  Rmotor.write(0);
  Bmotor.write(0);
  Lmotor.write(0);
  Fmotor.detach();
  Rmotor.detach();
  Bmotor.detach();
  Lmotor.detach();
}
//Write Speed to ESCs if running flag is set, takes 4 values as micros (1000us=0% power,2000us=100%)
void writeSpeed(uint32_t Fmicros, uint32_t Rmicros, uint32_t Bmicros, uint32_t Lmicros) {
  if (ESC_Running == 1) {
    Fmotor.writeMicroseconds(Fmicros);
    Rmotor.writeMicroseconds(Rmicros);
    Bmotor.writeMicroseconds(Bmicros);
    Lmotor.writeMicroseconds(Lmicros);
  } else {
    DisableMotors();
  }
}

//Write Xact as a delta between Right motor speed and left, yAct as delta between front and back (unit is us)
void writeControlAction(int xAct, int yAct) { //delta micros
  //Calculates each motor duty cycle as a distance from the operating point
  uint32_t FM = min(max(yOpratingpoint + yAct, yminMicros), ymaxMicros);
  uint32_t RM = min(max(xOpratingpoint + xAct, xminMicros), xmaxMicros);
  uint32_t BM = min(max(yOpratingpoint - yAct, yminMicros), ymaxMicros);
  uint32_t LM = min(max(xOpratingpoint - xAct, xminMicros), xmaxMicros);

#ifdef DebugMotor
  Serial.println((String)"POWERS: " + FM + ", " + RM + ", " + BM + ", " + LM);
#endif

  writeSpeed(FM, RM, BM, LM);
}
float readCurrent(int analogPin) {
    const int NUM_SAMPLES = 100; // Number of samples to average
    long sum = 0;

    for (int i = 0; i < NUM_SAMPLES; i++) {
        sum += analogRead(analogPin);
    }

    float average = sum / NUM_SAMPLES;

    // Convert the analog reading to voltage
    float voltage = (average * 3.3) / 4096.0;

    // Calculate the current
    float current = (voltage - ZERO_CURRENT_VOLTAGE) / (ACS712_SENSITIVITY / 1000.0);

    return current;
}
