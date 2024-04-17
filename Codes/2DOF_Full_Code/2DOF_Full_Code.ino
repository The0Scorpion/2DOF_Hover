#include <WiFi.h>
#include <EEPROM.h>

#include "Secrets.h"
#include "Parameters.h"
#include "RVG0.h"
#include "IMU.h"
#include "encoder.h"
#include "PID.h"
#include "motors.h"
#include "StartUP.h"
#include "commonFunctions.h"
#include "OTA.h"
#include "AWS_IOT.h"
TaskHandle_t TaskHandle_1;

void setup() {
  Serial.begin(115200);//init Serial For debugging
  //initEncoder(0, 0);
  //Over the air task to allow wireless flash runs on core 1
    xTaskCreatePinnedToCore(
      OTATASK,
      "OTA Routine",
      5000,
      NULL,
      0,
      NULL,
      1);
  
  //init MQTT client


  //Main Loop task runs on core 0

  xTaskCreatePinnedToCore(
    PIDLoop,   //Function to implement the task
    "Main Loop", // Name of the task
    10000,      // Stack size in words
    NULL,       // Task input parameter
    9,          // Priority of the task
    &TaskHandle_1,       // Task handle.
    0);  // Core where the task should run

  //StartUP(0,0); //Not used

  //Data Acquisition  Task Run on core 0 for now
    xTaskCreatePinnedToCore(
      DataAQU,   // Function to implement the task
      "Data AQU Loop", // Name of the task
      5000,      // Stack size in words
      NULL,       // Task input parameter
      0,          // Priority of the task
      NULL,       // Task handle.
      0);  // Core where the task should run
}
#define DebugCF
void loop() {

  //if debug then print the values between IMU and Encoder
#ifdef DebugCF
  updateIMU();
//  Serial.print(xVELPID.setpoint);
//  Serial.print(", ");
//  Serial.print(xSpeed);
//  Serial.print(", ");
//  Serial.print(xVELPID.integral);
//  Serial.print(", ");
//  Serial.println(xVELPID.output - xVELPID.integral);
//  Serial.print("XPOS:");
//  Serial.print(xPOSPID.setpoint);
//  Serial.print(", ");
 // Serial.print(CountsToAngle(xEncoderCount));
 // Serial.print(", ");
 // Serial.println(CountsToAngle(yEncoderCount));

//  Serial.print(xPOSPID.integral);
//  Serial.print(", ");
//  Serial.println(xPOSPID.output);
  counta = 0;
  vTaskDelay(50/portTICK_PERIOD_MS);
#endif
}
