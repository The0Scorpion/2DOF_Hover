int Value = 0;
int startValue = 0;
uint16_t Iter = 0;
uint16_t StartPoints = 0;
enum TestMode {
  Step = 1,
  Ramp = 2
} ExpType;

enum Joint {
  FMOTOR = 1,
  RMOTOR = 2,
  BMOTOR = 3,
  LMOTOR = 4
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

    if (TestJoint == FMOTOR)
      initESCs(FrontMotorPIN, 0, 0, 0);
    else if (TestJoint == RMOTOR)
      initESCs(0, RightMotorPIN, 0, 0);
    else if (TestJoint == BMOTOR)
      initESCs(0, 0, BackMotorPIN, 0);
    else if (TestJoint == LMOTOR)
      initESCs(0, 0, 0, LeftMotorPIN);
    writeSpeed(1000, 1000, 1000, 1000);
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
    if (TestJoint == RMOTOR || TestJoint == LMOTOR) {
      xAction =  startValue * 10 ; //convert from Percent to micros (Pulse width)
      writeSpeed(1000 + xAction + yAction, 1000 + xAction + yAction, 1000 + xAction + yAction, 1000 + xAction + xAction);
      xSpeed = getxSpeed();
      ySpeed = getySpeed();
      Serial.print(PktCounter++);
      Serial.print(",");
      Serial.print(startValue);
      Serial.print(",");
      Serial.print(CountsToAngle(xEncoderCount));
      Serial.print(",");
      Serial.println(getxSpeed());
    }
    else if (TestJoint == FMOTOR || TestJoint == BMOTOR) {
      yAction =  startValue * 10 ; //convert from Percent to micros (Pulse width)
      writeSpeed(1000 + xAction + yAction, 1000 + xAction + yAction, 1000 + xAction + yAction, 1000 + xAction + xAction);
      xSpeed = getxSpeed();
      ySpeed = getySpeed();
      Serial.print(PktCounter++);
      Serial.print(",");
      Serial.print(startValue);
      Serial.print(",");
      Serial.print(CountsToAngle(yEncoderCount));
      Serial.print(",");
      Serial.println(getySpeed());
    }
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
      if (TestJoint == RMOTOR || TestJoint == LMOTOR) {
        xAction =  Value * 10 ; //convert from Percent to micros (Pulse width)
        writeSpeed(1000 + xAction + yAction, 1000 + xAction + yAction, 1000 + xAction + yAction, 1000 + xAction + xAction);
        Serial.print(PktCounter++);
        Serial.print(",");
        Serial.print(Value);
        Serial.print(",");
        Serial.print(CountsToAngle(xEncoderCount));
        Serial.print(",");
        Serial.println(getxSpeed());
      }
      else if (TestJoint == FMOTOR || TestJoint == BMOTOR) {
        yAction =  Value * 10 ; //convert from Percent to micros (Pulse width)
        writeSpeed(1000 + xAction + yAction, 1000 + xAction + yAction, 1000 + xAction + yAction, 1000 + xAction + xAction);
        Serial.print(PktCounter++);
        Serial.print(",");
        Serial.print(Value);
        Serial.print(",");
        Serial.print(CountsToAngle(yEncoderCount));
        Serial.print(",");
        Serial.println(getySpeed());
      }
    }
    else if (ExpType == Ramp)
    {
      if (TestJoint == RMOTOR || TestJoint == LMOTOR)
      {
        if (RampValue <= Value * 10)
          xAction++; //RampValue reaches 500 after 5 seconds
        Serial.print(PktCounter++);
        Serial.print(",");
        Serial.print(Value);
        Serial.print(",");
        Serial.print(CountsToAngle(xEncoderCount));
        Serial.print(",");
        Serial.println(getxSpeed());
      }
      else if (TestJoint == FMOTOR || TestJoint == BMOTOR)
      {
        if (RampValue <= Value * 10)
          yAction++;//RampValue reaches 500 after 5 seconds
        Serial.print(PktCounter++);
        Serial.print(",");
        Serial.print(Value);
        Serial.print(",");
        Serial.print(CountsToAngle(yEncoderCount));
        Serial.print(",");
        Serial.println(getySpeed());
      }
    }



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
