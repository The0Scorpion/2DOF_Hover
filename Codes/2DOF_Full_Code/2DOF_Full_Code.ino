#include <WiFi.h>
#include <EEPROM.h>
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

  xTaskCreatePinnedToCore(
    OTATASK,
    "OTA Routine",
    5000,
    NULL,
    0,
    NULL,
    1);

  Serial.begin(115200);
  //initESCs(FrontMotorPIN, RightMotorPIN, BackMotorPIN, LeftMotorPIN);
  initIMU();
  delay(500);
  updateIMU();
  
  initEncoder(xPosIMU, yPosIMU);
  //initEncoder(0, 0);
  initMQTT();

  ESC_Running = 1;
  xTaskCreatePinnedToCore(
    PIDLoop,   //Function to implement the task
    "Main Loop", // Name of the task
    5000,      // Stack size in words
    NULL,       // Task input parameter
    0,          // Priority of the task
    &TaskHandle_1,       // Task handle.
    0);  // Core where the task should run
  //StartUP(0,0);
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
  //TO DO: IMPLEMENT Switching between windup and Normal Control
  #ifdef DebugCF
  updateIMU();
    Serial.print(xEncoderCount);
    Serial.print(", ");
    Serial.print(yEncoderCount);
    Serial.print(", ");
    Serial.print(xPosIMU);
    Serial.print(", ");
    Serial.println(AngleToCounts(xPosIMU));
    delay(1000);
    #endif
}
