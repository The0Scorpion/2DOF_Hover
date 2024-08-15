#include <WiFi.h>
#include <EEPROM.h>
#include "Parameters.h"
#include "AWS_IOT.h"
#include "Controller.h"

#define EnableDebug
// #define OFFLINE

#ifndef OFFLINE
#include "OTA.h"

#endif
// #define DebugCFMain
TaskHandle_t ControlTaskHandle, OTATaskHandle, IOTTaskHandle;

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
  initWiFi(); // Blocking Stop for offline

  xTaskCreatePinnedToCore(
      OTATask,
      "OTA Routine",
      10000,
      NULL,
      0,
      &OTATaskHandle,
      0);

  // Data Acquisition  Task Run on core 0 for now
  xTaskCreatePinnedToCore(
      DataAQU,         // Function to implement the task
      "Data AQU Loop", // Name of the task
      40000,           // Stack size in words
      NULL,            // Task input parameter
      7,               // Priority of the task
      &IOTTaskHandle,            // Task handle.
      0);              // Core where the task should run
#endif
  // Main Loop task runs on core 0
  /* xTaskCreatePinnedToCore(
       Control,       // Function to implement the task
       "Main Loop",   // Name of the task
       5120,          // Stack size in words
       NULL,          // Task input parameter
       9,             // Priority of the task
       &ControlTaskHandle, // Task handle.
       0);            // Core where the task should run*/

#ifdef DebugCFMain
  initEncoder(0, 0);
#endif
  // Initialize the watchdog timer

  esp_task_wdt_init(ResetTime, true); // Time in seconds
  esp_task_wdt_add(NULL);             // Add the main task to the watchdog
  lastMqttMessageTime = millis();
}

void loop()
{
  
  // Check if the watchdog timer should be reset
  if (millis() - lastMqttMessageTime < ResetTime * 1000)
  {
    // Feed the watchdog
    esp_task_wdt_reset();
  }
  /*else
  {
    Serial.println("Watchdog timeout! No MQTT message received.");
    // Take any necessary action, e.g., reset the ESP32
    esp_restart();
  }*/ 
  /*mqttClient.unsubscribe(SubAWSTopic);
  delay(2000);
  uint16_t packetIdSub0 = mqttClient.subscribe(SubAWSTopic, ReceiveQoS);
  Serial.print("Subscribing at QoS 0, packetId: ");
  Serial.println(packetIdSub0);
  delay(20000);*/
  // if debug then print the values between IMU and Encoder
#ifdef DebugCFMain
  // Used in other instances for Testing and debugging
  Serial.printf("Encoders: %d, %d\n", xEncoderCount, yEncoderCount);
  delay(100);
#endif
  // make sure motors are disabled if not intended to run
  if (!Work || failed_Trials > fail_TrailLimit)
  {
    DisableMotors();
  }
}
