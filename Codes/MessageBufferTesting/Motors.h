/*
   Submodule that contains all the brushless motor functions
   Credit: Scorpion
   Created: 14/11/2023
*/
#include <ESP32Servo.h>
#include "Parameters.h"

#pragma once

class ESP32ESC
{
private:
  // Hardware attributes
  byte oPin; // ESC output Pin

  // Calibration values
  int oMin = 1000;                  // Minimum pulse width for ESC
  int oMax = 2000;                  // Maximum pulse width for ESC
  int oESC = 1000;                  // Current ESC pulse width
  int oArm = 500;                   // Arm pulse width
  uint32_t calibrationDelay = 5000; // Calibration delay in milliseconds
  uint32_t stopPulse = 1000;        // Stop pulse duration in microseconds
  Servo myESC;                      // Servo object to control an ESC

public:
  // Constructor to initialize ESC pin and optional calibration parameters
  ESP32ESC(byte ESC_pin, int outputMin = 1000, int outputMax = 2000, int armVal = 1000)
  {
    oPin = ESC_pin;
    oMin = outputMin;
    oMax = outputMax;
    oArm = armVal;
  }

  // Destructor (empty as there's no dynamic memory allocation)
  ~ESP32ESC()
  {
    // Nothing to destruct
  }

  // Attach ESC to pin for operation
  void attach()
  {
    myESC.attach(oPin);
  }

  // Perform ESC calibration
  void calib()
  {
    myESC.attach(oPin);            // Attach ESC to the specified pin
    myESC.writeMicroseconds(oMax); // Send maximum signal to calibrate high
    delay(calibrationDelay);       // Wait for calibration
    myESC.writeMicroseconds(oMin); // Send minimum signal to calibrate low
    delay(calibrationDelay);       // Wait for calibration
    arm();                         // Arm the ESC after calibration
  }

  // Arm the ESC with pre-defined arm value
  void arm()
  {
    myESC.attach(oPin);            // Attach ESC to the specified pin
    myESC.writeMicroseconds(oArm); // Send arming signal
  }

  // Detach the ESC to stop signal transmission
  void detach()
  {
    myESC.writeMicroseconds(stopPulse); // Send stop pulse
    myESC.detach();                     // Detach ESC
  }

  // Stop the ESC by sending stop pulse
  void stop()
  {
    myESC.writeMicroseconds(stopPulse); // Send stop pulse
  }

  // Set ESC speed within calibrated range
  void speed(int outputESC)
  {
    oESC = constrain(outputESC, oMin, oMax); // Constrain speed within calibrated limits
    myESC.writeMicroseconds(oESC);           // Set ESC speed
  }

  // Set the calibration delay
  void setCalibrationDelay(uint32_t calibration_delay)
  {
    calibrationDelay = calibration_delay; // Set calibration delay
  }

  // Set the stop pulse duration
  void setStopPulse(uint32_t stop_pulse)
  {
    stopPulse = stop_pulse; // Set stop pulse duration
  }
};

// Instantiate four motors using ESP32ESC class with defined pins
ESP32ESC Fmotor(FrontMotorPIN), Rmotor(RightMotorPIN), Bmotor(BackMotorPIN), Lmotor(LeftMotorPIN);

// Calibrate all ESCs at startup
void calibESCs()
{
  // Attach all motors and set maximum signal for calibration
  Fmotor.attach(); Rmotor.attach(); Bmotor.attach(); Lmotor.attach();
  Fmotor.speed(2000); Rmotor.speed(2000); Bmotor.speed(2000); Lmotor.speed(2000);
  
  // Wait for calibration (first delay)
  delay(6000);

  // Set minimum signal for calibration
  Fmotor.speed(1000); Rmotor.speed(1000); Bmotor.speed(1000); Lmotor.speed(1000);

  // Wait for calibration (second delay)
  delay(6000);

  // Arm all ESCs after calibration
  Fmotor.arm(); Rmotor.arm(); Bmotor.arm(); Lmotor.arm();
}


// Initialize ESCs, arm them, and gradually start up
void initESCs()
{
  Fmotor.arm(); // Arm Front motor
  Rmotor.arm(); // Arm Right motor
  Bmotor.arm(); // Arm Back motor
  Lmotor.arm(); // Arm Left motor

  // Gradually increase speed to start motors smoothly
  for (unsigned int i = 1000; i < 1100; i += 5)
  {
    Fmotor.speed(i); // Set Front motor speed
    Rmotor.speed(i); // Set Right motor speed
    Bmotor.speed(i); // Set Back motor speed
    Lmotor.speed(i); // Set Left motor speed
    delay(10);       // Small delay between speed increments
  }
  delay(200);      // Additional delay after startup
  ESC_Running = 1; // Set ESC running flag
}

// Disable all motors by stopping and detaching them
void DisableMotors()
{
  Fmotor.stop();   // Stop Front motor
  Rmotor.stop();   // Stop Right motor
  Bmotor.stop();   // Stop Back motor
  Lmotor.stop();   // Stop Left motor
  Fmotor.detach(); // Detach Front motor
  Rmotor.detach(); // Detach Right motor
  Bmotor.detach(); // Detach Back motor
  Lmotor.detach(); // Detach Left motor
}

// Write speed values to all ESCs if running flag is set
void writeSpeed(uint32_t Fmicros, uint32_t Rmicros, uint32_t Bmicros, uint32_t Lmicros)
{
  if (ESC_Running == 1)
  {
    Fmotor.speed(Fmicros); // Set Front motor speed
    Rmotor.speed(Rmicros); // Set Right motor speed
    Bmotor.speed(Bmicros); // Set Back motor speed
    Lmotor.speed(Lmicros); // Set Left motor speed
  }
  else
  {
    DisableMotors(); // Disable motors if running flag is not set
  }
}

// Write control actions (delta values) to adjust motor speeds
void writeControlAction(int xAct, int yAct)
{
  // Calculate adjusted motor speeds based on control actions and operating points
  uint32_t FM = min(max(yOpratingpoint + yAct, yminMicros), ymaxMicros); // Front motor speed
  uint32_t RM = min(max(xOpratingpoint + xAct, xminMicros), xmaxMicros); // Right motor speed
  uint32_t BM = min(max(yOpratingpoint - yAct, yminMicros), ymaxMicros); // Back motor speed
  uint32_t LM = min(max(xOpratingpoint - xAct, xminMicros), xmaxMicros); // Left motor speed

  // Write adjusted speeds to motors
  writeSpeed(FM, RM, BM, LM);

#ifdef DebugMotor
  // Debugging: Print motor power levels
  Serial.println((String) "POWERS: " + FM + ", " + RM + ", " + BM + ", " + LM);
#endif
}
