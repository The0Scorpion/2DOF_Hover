#include "Parameters.h"
#include "PID.h"

#define Kp 10
#define Ki 1
#define Kd 30
#define SP 5
#define MinSat -9999
#define MaxSat 9999

float PID_out;
float randNumber1 , randNumber2;
PIDController TestPID;


void setup() {

  Serial.begin(250000);

  /*xTaskCreatePinnedToCore(
      PID_TestTask,   // Function to implement the task
      "PID_Test", // Name of the task
      5000,      // Stack size in words
      NULL,       // Task input parameter
      5,          // Priority of the task
      NULL,       // Task handle.
      1);  // Core where the task should run*/

}
void loop() {
  uint64_t LastTime = micros();
  while (1)
  {
    LastTime = micros();
    randNumber2 = (float)random(-1000 , 1001) / 100 ;
    //Serial.print("PID_CurrentState = ");
    Serial.print(randNumber2);

    resetPID(&TestPID);
    initializePID(&TestPID, Kp, Ki, Kd, SP, MinSat, MaxSat);
    PID_out = calculatePID(&TestPID, randNumber2);

    Serial.print(",");
    Serial.print(PID_out);
    Serial.print(",");
    Serial.println(micros() / 1000);
    while (micros() - LastTime < Sampling_time) {
      delayMicroseconds(1);
    }

  }
}
