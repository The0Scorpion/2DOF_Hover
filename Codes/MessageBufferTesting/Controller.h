/*
   Header file with the main loop and common functions
   Credit:Scorpion
   Created: 20/10/2023
*/
#pragma once
// #define DebugCF
// #define DebugCF1

#include "Parameters.h"
#include "encoder.h"
#include <EEPROM.h>
#include "Motors.h"
#include "StartUP.h"
#include "AWS_IOT.h"



#ifdef CascadedPIDControl 
  #include "CascadedPID.h"
#elif defined(OnlineControl)
  #include "OnlineControl.h"
#endif

void Control(void *parameter)
{
  /*
    Main Control Loop, Runs the sensing and actuation
  */
  initEncoder(0, 0);

#ifdef OFFLINE
  Work = EEPROM.read(0) > 1 ? 0 : !EEPROM.read(0);
  EEPROM.write(0, Work);
  EEPROM.commit();
#endif
  while (1)
  {
    if (Work)
    {
      initESCs();
      delay(1000); // Wait for ESC calibration

#ifdef DebugCF
      Serial.println("Start Up");
#endif
      StartUP(0.20, 0.20); // Startup sequence
#ifdef DebugCF
      Serial.println("Started");
#endif
      initController(); // Initialize PID controllers //0x0ff000

      TickType_t LastStepTime;
      const TickType_t xFrequency = 5 / portTICK_PERIOD_MS;
      LastStepTime = xTaskGetTickCount();

#ifdef DebugCF // Debugging messages
      Serial.println("PID Started");
#endif

      while (ControllerRunning && Work)
      {
        
        xSpeed = getxSpeed();
        ySpeed = getySpeed();

        // updateIMU();
        // xSpeed = (1 - IMU_FusionPrio) * xSpeed + IMU_FusionPrio * AngleToCounts(xDotIMU);
        // ySpeed = (1 - IMU_FusionPrio) * ySpeed + IMU_FusionPrio * AngleToCounts(yDotIMU);

        stepController(); // Execute PID control

        writeControlAction((int)xAction, (int)yAction); // Send control signals to motors

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

        vTaskDelayUntil(&LastStepTime, xFrequency); // Maintain fixed control frequency

        // Check for position limits or failure conditions
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
              }
            }
          }
        }
        else
        {
          failcount = 0;
        }

#ifdef DebugCF1
        Serial.print("Counter For PID: ");
        Serial.println(counta);
#endif
      }
    }

#ifdef DebugCF
    Serial.println("PID Stopped");
#endif

    delay(20); // Allow some delay before restarting
  }
}
