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
     give different signals to motors --> step, Ramp
     Read Position and velocity each 5ms
  */
  Serial.begin(115200);
  Serial.println("Select Joint to test: \n1 for Front\n2 for Right\n3 for Back\n4 for Left\n");
  while (!Serial.available())delay(100);
  Joint myjoint = (Joint)Serial.parseInt();
  TestJoint = myjoint;

  Serial.println("Select Mode to test: \n1 for Step\n2 for Ramp\n");
  while (!Serial.available())delay(100);
  TestMode mymode = (TestMode)Serial.parseInt();
  ExpType = mymode;



  Serial.println("Select Number Of start % \n");
  while (!Serial.available())delay(100);
  startValue = Serial.parseInt();

  Serial.println("Select Number Of start points \n");
  while (!Serial.available())delay(100);
  StartPoints = Serial.parseInt();
  
  Serial.println("Select Test percentage \n");
  while (!Serial.available())delay(100);
  Value = Serial.parseInt();

  Serial.println("Select Number Of Data points \n");
  while (!Serial.available())delay(100);
  Iter = Serial.parseInt();


  /*xTaskCreatePinnedToCore(
     MotorEstimation,   //Function to implement the task
     "Main Loop", // Name of the task
     5000,      // Stack size in words
     NULL,       // Task input parameter
     0,          // Priority of the task
     &TaskHandle_1,       // Task handle.
     0);  // Core where the task should run*/
  MotorEstimation(NULL);
}

void loop() {

}
