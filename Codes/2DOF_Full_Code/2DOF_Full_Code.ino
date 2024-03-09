#include <WiFi.h>
#include <EEPROM.h>
#include "Secrets.h"
#include "Parameters.h"
#include "IMU.h"
#include "encoder.h"
#include "PID.h"
#include "motors.h"
#include "commonFunctions.h"
#include "WindUp.h"
#include "OTA.h"
#include "AWS_IOT.h"
TaskHandle_t TaskHandle_1;

void setup() {
  Serial.begin(115200);//init Serial For debugging
  initEncoder(0, 0);
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
     5000,      // Stack size in words
     NULL,       // Task input parameter
     0,          // Priority of the task
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
  Serial.print(xEncoderCount);
  Serial.print(", ");
  Serial.print(yEncoderCount);
  Serial.print(", ");
  Serial.print(AngleToCounts(xPosIMU));
  Serial.print(", ");
  Serial.println(AngleToCounts(yPosIMU));
  delay(1000);
#endif
}
