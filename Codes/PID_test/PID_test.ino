#include "Parameters.h"
#include "PID.h"

#define Kp 50
#define Ki 35
#define Kd 22
#define SP 5
#define MinSat -9999
#define MaxSat 9999

float PID_out;
PIDController TestPID;
float Output = 0;

void setup() {

  Serial.begin(250000);
  /*xTaskCreatePinnedToCore(
      PID_TestTask,   // Functionto implement the task
      "PID_Test", // Name of the task
      5000,      // Stack size in words
      NULL,       // Task input parameter
      5,          // Priority of the task
      NULL,       // Task handle.
      1);  // Core where the task should run*/

}

void loop() {
  uint64_t LastTime = micros();
  initializePID(&TestPID, Kp, Ki, Kd, SP, MinSat, MaxSat);
  resetPID(&TestPID); //Moved the reset PID from the loop, to be executed once.
  
  while (1)
  {
    Output = Output + 0.01;
    LastTime = micros();

    //Serial.print("PID_CurrentState = ");
    PID_out = calculatePID(&TestPID, Output);
    //    Serial.print(Output);
    //    Serial.print(",");
    Serial.println(PID_out);
    //    Serial.print(",");
    //    Serial.println(micros() / 1000);

    while (micros() - LastTime < Sampling_time) {
      delayMicroseconds(1);
    }
    if (micros() > 5000000)
    {
      while (1);
    }
  }
}
