#include <WiFi.h>
#include <EEPROM.h>
#include "Parameters.h"
#include "AWS_IOT.h"
#include "Controller.h"



#define DebugAngles
// #define OFFLINE

#ifndef OFFLINE
#include "OTA.h"

#endif
// #define DebugCFMain
TaskHandle_t TaskHandle_1;

void setup() {
 calibESCs();
#ifdef EnableDebug
  Serial.begin(115200);  // init Serial For debugging
#endif
  // initEncoder(0, 0);
  // Over the air task to allow wireless flash runs on core 1
  EEPROM.begin(300);
#ifndef OFFLINE
  initWiFi();  // Blocking Stop for offline

  xTaskCreatePinnedToCore(
    OTATask,
    "OTA Routine",
    3000,
    NULL,
    0,
    NULL,
    0);

  // Data Acquisition  Task Run on core 0 for now
  xTaskCreatePinnedToCore(
    DataAQU,          // Function to implement the task
    "Data AQU Loop",  // Name of the task
    6000,             // Stack size in words
    NULL,             // Task input parameter
    0,                // Priority of the task
    NULL,             // Task handle.
    0);               // Core where the task should run
#endif
  // Main Loop task runs on core 0
  xTaskCreatePinnedToCore(
    Control,        // Function to implement the task
    "Main Loop",    // Name of the task
    5120,           // Stack size in words
    NULL,           // Task input parameter
    9,              // Priority of the task
    &TaskHandle_1,  // Task handle.
    0);             // Core where the task should run

#ifdef DebugCFMain
  initEncoder(0, 0);
#endif
  // Initialize the watchdog timer

  esp_task_wdt_init(ResetTime, true);  // Time in seconds
  esp_task_wdt_add(NULL);              // Add the main task to the watchdog
  lastMqttMessageTime = millis();
}
// #define DebugCFMain
uint64_t lastHighCurrent;
void loop() {
  // Check if the watchdog timer should be reset
  if (millis() - lastMqttMessageTime < ResetTime * 1000) {
    // Feed the watchdog
    esp_task_wdt_reset();
  }
  float PitchCurrent = abs(readCurrent(PitchCurrentSense));
  float RollCurrent = abs(readCurrent(RollCurrentSense));
#ifdef DebugCurrent
  Serial.printf("Currents: %f, %f \r\n", PitchCurrent, RollCurrent);
#endif
#ifdef DebugAngles
  Serial.println((String)"Angles: " + CountsToAngle(xEncoderCount) + ", " + CountsToAngle(yEncoderCount) );
#endif
  if (PitchCurrent > CutoffCurrent || RollCurrent > CutoffCurrent) {
    if (lastHighCurrent > 0) {
      if (millis() - lastHighCurrent > CutoffCurrentTime) {
        //Send IOT Warn And stop operation
        publishWarning("High Current Detected");
      }
    } else {
      publishWarning("High Current Spike Detected");
      lastHighCurrent = millis();
    }
  } else {
    lastHighCurrent = 0;
  }
  vTaskDelay(100);
/*  // make sure motors are disabled if not intended to run
  if (!Work || failed_Trials > fail_TrailLimit) {
    DisableMotors();
  }*/
}
