#line 1 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\StartUP.h"
/*
   Submodule for the non-linear region
   Credit: Scorpion
   Created: 20/1/2024
   Not used for now
*/
#pragma once

#include "Parameters.h"
#include "PID.h"
#include "encoder.h"
#include "Motors.h"

void StartUP(double targetX, double targetY) {

  if (Work) {
    // Reset and create 4 PID objects with StartUP parameters
    xPOSPID.reset();
    xPOSPID.init(8, 1, 0, 0, -PositionLoopSat * 2, PositionLoopSat * 2); 
    xVELPID.reset();
    xVELPID.init(15, 1, 0, 0, -xmaxDeltaMicrosStart / 10, xmaxDeltaMicrosStart / 10);
    yPOSPID.reset();
    yPOSPID.init(8, 1, 0, 0, -PositionLoopSat * 2, PositionLoopSat * 2); 
    yVELPID.reset();
    yVELPID.init(13, 1, 0, 0, -ymaxDeltaMicrosStart / 10, ymaxDeltaMicrosStart / 10);

    TickType_t PIDLastTime;
    const TickType_t xFrequency = 5 / portTICK_PERIOD_MS;

    // Initialize the xLastWakeTime variable with the current time.
    PIDLastTime = xTaskGetTickCount();

    while ((abs(targetX) < abs(CountsToAngle(xEncoderCount))) || (abs(targetY) < abs(CountsToAngle(yEncoderCount))) || (abs(xSpeed > targetX)) || (abs(ySpeed > targetY))) {
      xSpeed = getxSpeed();
      ySpeed = getySpeed();

      xVELPID.setpoint = (float)xPOSPID.calculate(CountsToAngle(xEncoderCount));
      yVELPID.setpoint = (float)yPOSPID.calculate(CountsToAngle(yEncoderCount));

      // Calculate action for motors from velocity PID output
      xAction = (int)(xVELPID.calculate(xSpeed) * 10); // convert from Percent to micros (Pulse width)
      yAction = (int)(yVELPID.calculate(ySpeed) * 10); // convert from Percent to micros (Pulse width)

      uint32_t FM = min(max((int)(1300 + yAction), 1000), 2000);
      uint32_t RM = min(max((int)(1500 + xAction), 1000), 2000);
      uint32_t BM = min(max((int)(1300 - yAction), 1000), 2000);
      uint32_t LM = min(max((int)(1500 - xAction), 1000), 2000);

#ifdef DebugMotor
      Serial.println((String)"POWERS: " + FM + ", " + RM + ", " + BM + ", " + LM);
#endif

      writeSpeed(FM, RM, BM, LM);

      counta++;
      vTaskDelayUntil(&PIDLastTime, xFrequency);

      if (counta > maxStartupSamples) {
        Work = 0;
        Serial.println("Failed To startUp");
        DisableMotors();
        break;
      }
    }
  }
  counta = 0;
}
