/*
 * Main code to calculate the delay of the mqtt client package
 * Credit: Scorpion
 * Created: 4/3/2024
*/
#include <WiFi.h>
#include <EEPROM.h>
#include "Secrets.h"
#include "Parameters.h"
#include "OTA.h"
#include "cNTP.h"
#include "AWS_IOT.h"


void setup() {
  Serial.begin(115200);//init Serial For debugging

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
  initMQTT();

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
void loop() {

}
