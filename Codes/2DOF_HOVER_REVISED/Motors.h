/*
   Submodule That contains all the brushless motor functions
   Credit:Scorpion
   Created: 14/11/2023
*/
#include <ESP32Servo.h>
#include "Parameters.h"
#pragma once
class ESP32ESC
{
private:
  // < Local attributes >
  // Hardware
  byte oPin; // ESC output Pin

  // Calibration
  int oMin = 1000;
  int oMax = 2000;
  int oESC = 1000;
  int oArm = 500;
  uint32_t calibrationDelay = 5000; // Calibration delay (milisecond)
  uint32_t stopPulse = 1000;         // Stop pulse (microseconds)
  Servo myESC;                      // create servo object to control an ESC
public:
  ESP32ESC(byte ESC_pin, int outputMin=1000, int outputMax=2000, int armVal=1000)
  {
    oPin = ESC_pin;
    oMin = outputMin;
    oMax = outputMax;
    oArm = armVal;
  }
  ~ESP32ESC()
  {
    // Nothing to destruct
  }
  void calib(void)
  {
    myESC.attach(oPin); // attaches the ESC on pin oPin to the ESC object
    myESC.writeMicroseconds(oMax);
    delay(calibrationDelay);
    myESC.writeMicroseconds(oMin);
    delay(calibrationDelay);
    arm();
  }

  /*
   * Sent a signal to Arm the ESC
   * depends on the Arming value from the constructor
   */
  void arm(void)
  {
    myESC.attach(oPin); // attaches the ESC on pin oPin to the ESC object
    myESC.writeMicroseconds(oArm);
  }

  void detach(void)
  {
    myESC.writeMicroseconds(stopPulse);
    myESC.detach(); // attaches the ESC on pin oPin to the ESC object
    
  }
  /*
   * Sent a signal to stop the ESC
   * depends on the ESC stop pulse value
   */
  void stop(void)
  {
    myESC.writeMicroseconds(stopPulse);
  }

  /*
   * Sent a signal to set the ESC speed
   * depends on the calibration minimum and maximum values
   */
  void speed(int outputESC)
  {
    oESC = constrain(outputESC, oMin, oMax);
    myESC.writeMicroseconds(oESC);
  }

  /*
   * Set the current calibration delay in miliseconds
   *
   */
  void setCalibrationDelay(uint32_t calibration_delay)
  {
    calibrationDelay = calibration_delay;
  }
  void setStopPulse(uint32_t stop_pulse)
  {
    stopPulse = stop_pulse;
  }


};

ESP32ESC Fmotor(FrontMotorPIN),Rmotor(RightMotorPIN),Bmotor(BackMotorPIN),Lmotor(LeftMotorPIN);

void calibESCs(){
  Fmotor.calib();
  Rmotor.calib();
  Bmotor.calib();
  Lmotor.calib();
}

// initialize ESCs and set running flag
void initESCs()
{
  Fmotor.arm();
  Rmotor.arm();
  Bmotor.arm();
  Lmotor.arm();
  // start up motors

  for (unsigned int i = 1000; i < 1100; i += 5)
  {
    Fmotor.speed(i);
    Rmotor.speed(i);
    Bmotor.speed(i);
    Lmotor.speed(i);
    delay(10);
  }
  delay(200);
  ESC_Running = 1;
}
void DisableMotors()
{
  Fmotor.stop();
  Rmotor.stop();
  Bmotor.stop();
  Lmotor.stop();
  Fmotor.detach();
  Rmotor.detach();
  Bmotor.detach();
  Lmotor.detach();
}
// Write Speed to ESCs if running flag is set, takes 4 values as micros (1000us=0% power,2000us=100%)
void writeSpeed(uint32_t Fmicros, uint32_t Rmicros, uint32_t Bmicros, uint32_t Lmicros)
{
  if (ESC_Running == 1)
  {
    Fmotor.speed(Fmicros);
    Rmotor.speed(Rmicros);
    Bmotor.speed(Bmicros);
    Lmotor.speed(Lmicros);
  }
  else
  {
    DisableMotors();
  }
}

// Write Xact as a delta between Right motor speed and left, yAct as delta between front and back (unit is us)
void writeControlAction(int xAct, int yAct)
{ // delta micros
  // Calculates each motor duty cycle as a distance from the operating point
  uint32_t FM = min(max(yOpratingpoint + yAct, yminMicros), ymaxMicros);
  uint32_t RM = min(max(xOpratingpoint + xAct, xminMicros), xmaxMicros);
  uint32_t BM = min(max(yOpratingpoint - yAct, yminMicros), ymaxMicros);
  uint32_t LM = min(max(xOpratingpoint - xAct, xminMicros), xmaxMicros);

#ifdef DebugMotor
  Serial.println((String) "POWERS: " + FM + ", " + RM + ", " + BM + ", " + LM);
#endif

  writeSpeed(FM, RM, BM, LM);
}
