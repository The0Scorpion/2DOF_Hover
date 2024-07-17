/*
   Header file with the main loop and common functions
   Credit:Scorpion
   Created: 20/10/2023
*/
#pragma once
// #define DebugCF
#define DebugCF1

#include "Parameters.h"
#include "encoder.h"
#include <EEPROM.h>
#include "Motors.h"

#include "StartUP.h"

#include "CascadedPID.h"

void Control(void *parameter)
{

  /*
    Main Control Loop, Runs each sampling time
  */
  initEncoder(0, 0);

#ifdef OFFLINE
  Work = EEPROM.read(0) > 1 ? 0 : !EEPROM.read(0);
  EEPROM.write(0, Work); // toggles running on resets
  EEPROM.commit();
#endif

  while (1)
  {
    if (Work)
    {
      initESCs();
      delay(1000); // wait for esc calib

      // Startup
#ifdef DebugCF
      Serial.println("Start Up");
#endif
      StartUP(0.20, 0.20);
#ifdef DebugCF
      Serial.println("Started");
#endif
      initController();

      // LastStepTime = micros();
      TickType_t LastStepTime;
      const TickType_t xFrequency = 5 / portTICK_PERIOD_MS;

      // Initialise the xLastWakeTime variable with the current time.
      LastStepTime = xTaskGetTickCount();
#ifdef DebugCF // just for debugging
      Serial.println("PID Started");
#endif

      while (ControllerRunning && Work)
      {
        SendToMQTT = 1;
        // Update feedback values using sensor fusion
        xSpeed = getxSpeed();
        ySpeed = getySpeed();

        // updateIMU();
        // xSpeed = (1 - IMU_FusionPrio) * xSpeed + IMU_FusionPrio * AngleToCounts(xDotIMU);
        // ySpeed = (1 - IMU_FusionPrio) * ySpeed + IMU_FusionPrio * AngleToCounts(yDotIMU);

        
        stepController();

        writeControlAction((int)xAction, (int)yAction);

        counta++;
        if (counta > RunSamples)
        {
          counta = 0;
          Work = 0;
          ControllerRunning = 0;
          failed_Trials = 0;
          DisableMotors();
          break;
        }
        vTaskDelayUntil(&LastStepTime, xFrequency);

        if (abs(CountsToAngle(xEncoderCount)) > xposSetLimit || abs(CountsToAngle(yEncoderCount)) > yposSetLimit)
        {
          if (failcount == 0)
          {
            failcount = counta;
          }
          else
          {
            if (counta - failcount > failLimit)
            {
              ControllerRunning = 0;
              failed_Trials++;
              if (failed_Trials > fail_TrailLimit)
              {
                ControllerRunning = 0;
                Work = 0;
                failed_Trials = 0;
                break;
                // Startup
#ifdef DebugCF
                Serial.println("Start Up");
#endif
                StartUP(0.20, 0.20);
#ifdef DebugCF
                Serial.println("Started");
#endif
              }
            }
          }
        }
        else
        {
          failcount = 0;
        }
#ifdef debugTime
        Serial.print(micros() - LastStepTime);
#endif

#ifdef DebugCF1 // just for debugging
        Serial.print("Counter For PID: ");
        Serial.println(counta);
#endif
      }
    }

#ifdef DebugCF // just for debugging
    Serial.println("PID Stopped");
#endif
    // Work = 0;
    delay(20);
  }
}
