#include <WiFi.h>
#include <EEPROM.h>
#include "Controller.h"

#include "Parameters.h"

#define EnableDebug
// #define OFFLINE

#ifndef OFFLINE
#include "OTA.h"
#include "AWS_IOT.h"
#endif
// #define DebugCFMain
TaskHandle_t TaskHandle_1;

void setup()
{
// calibESCs();
#ifdef EnableDebug
  Serial.begin(115200); // init Serial For debugging
#endif
  // initEncoder(0, 0);
  // Over the air task to allow wireless flash runs on core 1
  EEPROM.begin(300);
#ifndef OFFLINE
  initWIFI(); // Blocking Stop for offline

  xTaskCreatePinnedToCore(
      OTATASK,
      "OTA Routine",
      3000,
      NULL,
      0,
      NULL,
      1);

  // Data Acquisition  Task Run on core 0 for now
  xTaskCreatePinnedToCore(
      DataAQU,         // Function to implement the task
      "Data AQU Loop", // Name of the task
      6000,            // Stack size in words
      NULL,            // Task input parameter
      0,               // Priority of the task
      NULL,            // Task handle.
      0);              // Core where the task should run
#endif
  // Main Loop task runs on core 0
  xTaskCreatePinnedToCore(
      Control,       // Function to implement the task
      "Main Loop",   // Name of the task
      5120,          // Stack size in words
      NULL,          // Task input parameter
      9,             // Priority of the task
      &TaskHandle_1, // Task handle.
      0);            // Core where the task should run

#ifdef DebugCFMain
  initEncoder(0, 0);
#endif
}
// #define DebugCFMain
void loop()
{

  // if debug then print the values between IMU and Encoder
#ifdef DebugCFMain
  // Used in other instances for Testing and debugging
  Serial.printf("Encoders: %d, %d\n", xEncoderCount, yEncoderCount);
  delay(100);
#endif
  // make sure motors are disabled if not intended to run
  if(!Work || failed_Trials>fail_TrailLimit){
    DisableMotors();
  }
}
