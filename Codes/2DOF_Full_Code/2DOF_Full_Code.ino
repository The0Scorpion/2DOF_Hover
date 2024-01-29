#include <WiFi.h>
#include "Parameters.h"
#include "wiring.h"
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
  Serial.begin(115200);
  
  initIMU();
  updateIMU();

  initEncoder(AngleToCounts(xPosIMU), AngleToCounts(yPosIMU));
  initMQTT();
  initESCs(FrontMotorPIN,RightMotorPIN,BackMotorPIN,LeftMotorPIN);

  xTaskCreatePinnedToCore(
    PIDLoop,   //Function to implement the task
    "Main Loop", // Name of the task
    1000,      // Stack size in words
    NULL,       // Task input parameter
    0,          // Priority of the task
    &TaskHandle_1,       // Task handle.
    0);  // Core where the task should run

  xTaskCreatePinnedToCore(
    DataAQU,   // Function to implement the task
    "Data AQU Loop", // Name of the task
    10000,      // Stack size in words
    NULL,       // Task input parameter
    0,          // Priority of the task
    NULL,       // Task handle.
    0);  // Core where the task should run


  xTaskCreatePinnedToCore(
    OTATASK,   /* Function to implement the task */
    "OTA Routine", /* Name of the task */
    5000,      /* Stack size in words */
    NULL,       /* Task input parameter */
    0,          /* Priority of the task */
    NULL,       /* Task handle. */
    1);  /* Core where the task should run */
}
void loop() {
//TO DO: IMPLEMENT Switching between windup and Normal Control
}
