#include <Arduino.h>
#line 1 "C:\\Programs\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
#include <WiFi.h>
#include <EEPROM.h>
#include <ESP32Servo.h>
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
//#define OFFLINE
TaskHandle_t TaskHandle_1;

#line 18 "C:\\Programs\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
void setup();
#line 58 "C:\\Programs\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
void loop();
#line 18 "C:\\Programs\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
void setup() {
  Serial.begin(115200);//init Serial For debugging
  //initEncoder(0, 0);
  //Over the air task to allow wireless flash runs on core 1
    EEPROM.begin(300);
#ifndef OFFLINE
  initWIFI();// Blocking Stop for offline

  xTaskCreatePinnedToCore(
    OTATASK,
    "OTA Routine",
    5000,
    NULL,
    0,
    NULL,
    1);

  //Data Acquisition  Task Run on core 0 for now
  xTaskCreatePinnedToCore(
    DataAQU,   // Function to implement the task
    "Data AQU Loop", // Name of the task
    5000,      // Stack size in words
    NULL,       // Task input parameter
    0,          // Priority of the task
    NULL,       // Task handle.
    0);  // Core where the task should run
#endif
  //Main Loop task runs on core 0
  xTaskCreatePinnedToCore(
    PIDLoop,   //Function to implement the task
    "Main Loop", // Name of the task
    10000,      // Stack size in words
    NULL,       // Task input parameter
    9,          // Priority of the task
    &TaskHandle_1,       // Task handle.
    0);  // Core where the task should run


}
//#define DebugCFMain
void loop() {

  //if debug then print the values between IMU and Encoder
#ifdef DebugCFMain
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
  Serial.print(CountsToAngle(xEncoderCount));
  Serial.print(", ");
  Serial.print(CountsToAngle(yEncoderCount));
  Serial.print(", ");
  Serial.print(xPosIMU);
  Serial.print(", ");
  Serial.println(yPosIMU);

  //  Serial.print(xPOSPID.integral);
  //  Serial.print(", ");
  //  Serial.println(xPOSPID.output);
  vTaskDelay(50 / portTICK_PERIOD_MS);
#endif
}

