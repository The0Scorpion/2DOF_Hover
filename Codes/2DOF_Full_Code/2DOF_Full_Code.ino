#include <WiFi.h>
#include "Parameters.h"
#include "wiring.h"
#include "IMU.h"
#include "encoder.h"
#include "PID.h"
#include "motors.h"
#include "commonFunctions.h"
#include "ESP4NOW.h"
#include "OTA.h"

TaskHandle_t TaskHandle_1;

void setup() {
  Serial.begin(115200);
  initIMU();
  updateIMU();

  initEncoder(AngleToCounts(xPosIMU), AngleToCounts(yPosIMU));
  //ESPNowInit();

  /*xTaskCreatePinnedToCore(
    PIDLoop,   //Function to implement the task
    "Main Loop", // Name of the task
    10000,      // Stack size in words
    NULL,       // Task input parameter
    0,          // Priority of the task
    &TaskHandle_1,       // Task handle.
    0);  // Core where the task should run
  */
  /*
    xTaskCreatePinnedToCore(
                    DataAQU,   // Function to implement the task
                    "Data AQU Loop", // Name of the task
                    10000,      // Stack size in words
                    NULL,       // Task input parameter
                    0,          // Priority of the task
                    NULL,       // Task handle.
                    0);  // Core where the task should run
  */

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
  uint32_t tt = micros();
  updateIMU();
  Serial.print(micros() - tt);
  Serial.print(": ");
  Serial.print(AngleRoll);
  Serial.print(", ");
  Serial.print(AnglePitch);
  Serial.print(", ");
  Serial.print(xDotIMU);
  Serial.print(", ");
  Serial.println(yDotIMU);
  delayMicroseconds(10000);
}
