#include "Parameters.h"
#include <EEPROM.h>
#include "IMU.h"
#include "encoder.h"
#include "PID.h"
#include "motors.h"
#include "commonFunctions.h"
TaskHandle_t TaskHandle_1;

void setup() {
  /*
   * give different signals to motors --> step, Ramp
   * Read Position and velocity each 5ms
   */
   
  Serial.begin(250000);


  xTaskCreatePinnedToCore(
     MotorEstimation,   //Function to implement the task
     "Main Loop", // Name of the task
     5000,      // Stack size in words
     NULL,       // Task input parameter
     0,          // Priority of the task
     &TaskHandle_1,       // Task handle.
     0);  // Core where the task should run
  

}

void loop() {

}
