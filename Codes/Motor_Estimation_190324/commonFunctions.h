int Value = 0;
uint16_t Iter = 0;
uint16_t StartPoints = 0;
enum TestMode {
  Step = 1,
  Ramp = 2
} ExpType;

enum Joint {
  xTest = 1,
  yTest = 2
} TestJoint;

#define RUN
#include <ArduinoJson.h>

void MotorEstimation(void * parameter) {
  initEncoder(0, 0);

#ifdef RUN
  //  EEPROM.begin(1);
  //  byte Work = EEPROM.read(0);
  //  EEPROM.write(0, !Work); //toggles running on resets
  //  EEPROM.commit();

  byte Work = 1;
  if (Work)
  {
    Fmotor.detach();
    Rmotor.detach();
    Bmotor.detach();
    Lmotor.detach();

    if (TestJoint == xTest)
      initESCs(0, RightMotorPIN, 0, LeftMotorPIN);
    else if (TestJoint == yTest)
      initESCs(FrontMotorPIN, 0, BackMotorPIN, 0);

    delay(2500);//wait for esc calib
  }
#endif

  Test_Running = 1;
  uint64_t lastSample = micros();
  unsigned long PktCounter = 0;
  unsigned int RampValue = 1000;
  xAction = 0;
  yAction = 0;
  for (int i = 0; i < StartPoints; i++) {
    writeControlAction(0, 0);
    Serial.print(PktCounter++);
    Serial.print(",");
    Serial.print(CountsToAngle(xEncoderCount));
    Serial.print(",");
    Serial.print(CountsToAngle(yEncoderCount));
    Serial.print(",");
    Serial.print(getxSpeed());
    Serial.print(",");
    Serial.println(getySpeed());
    while (micros() - lastSample < Sampling_time) {
      delayMicroseconds(10);
    }
    lastSample = micros();
  }
  while (Test_Running) {

    //Update feedback values using sensor fusion
    xSpeed = getxSpeed();
    ySpeed = getySpeed();
    //      updateIMU();
    //      xSpeed = (1 - IMU_FusionPrio) * xSpeed + IMU_FusionPrio * AngleToCounts(xDotIMU);
    //      ySpeed = (1 - IMU_FusionPrio) * ySpeed + IMU_FusionPrio * AngleToCounts(yDotIMU);

    if (ExpType == Step)
    {
      if (TestJoint == xTest)
        xAction =  Value * 5 ; //convert from Percent to micros (Pulse width)
      else if (TestJoint == yTest)
        yAction =  Value * 5 ; //convert from Percent to micros (Pulse width)
    }
    else if (ExpType == Ramp)
    {
      if (TestJoint == xTest)
      {
        if (RampValue <= Value * 5)
          xAction++; //RampValue reaches 500 after 5 seconds
      }
      else if (TestJoint == yTest)
      {
        if (RampValue <= Value * 5)
          yAction++;//RampValue reaches 500 after 5 seconds
      }
    }

    writeControlAction(xAction, yAction);
    Serial.print(PktCounter++);
    Serial.print(",");
    Serial.print(CountsToAngle(xEncoderCount));
    Serial.print(",");
    Serial.print(CountsToAngle(yEncoderCount));
    Serial.print(",");
    Serial.print(getxSpeed());
    Serial.print(",");
    Serial.println(getySpeed());

    //      writeSpeed(1400, 1000, 1000, 1000);

    if (PktCounter >= Iter + StartPoints)
    {
      Test_Running = 0;
      break;
    }

    while (micros() - lastSample < Sampling_time) {
      delayMicroseconds(10);
    }
    lastSample = micros();

  }

  writeSpeed(1000, 1000, 1000, 1000);
}
