//#define DebugCF

#define RUN
#include <ArduinoJson.h>

void MotorEstimation(void * parameter) {
  initEncoder(0, 0);

#ifdef DebugCF
    Serial.println("init Estimation Loops");
#endif

#ifdef RUN
    EEPROM.begin(1);
    byte Work = EEPROM.read(0);
    EEPROM.write(0, !Work); //toggles running on resets
    EEPROM.commit();
    if (Work)
    {
      initESCs(FrontMotorPIN, RightMotorPIN, BackMotorPIN, LeftMotorPIN);
      delay(2500);//wait for esc calib
    }
#endif

#ifdef DebugCF
    Serial.println("init Escs Success");
#endif


    Test_Running = 1;
    uint64_t lastSample = micros();
    unsigned long PktCounter = 0;
    unsigned int RampValue = 1000;
    unsigned char StepPercent = 20;

    while (Test_Running) {

      //Update feedback values using sensor fusion
      xSpeed = getxSpeed();
      ySpeed = getySpeed();
      //      updateIMU();
      //      xSpeed = (1 - IMU_FusionPrio) * xSpeed + IMU_FusionPrio * AngleToCounts(xDotIMU);
      //      ySpeed = (1 - IMU_FusionPrio) * ySpeed + IMU_FusionPrio * AngleToCounts(yDotIMU);


      if (Test_Mode == Step)
      {
#ifdef X_test
        xAction =  StepPercent * 5 ; //convert from Percent to micros (Pulse width)
#endif

#ifdef Y_test
        yAction =  StepPercent * 5 ; //convert from Percent to micros (Pulse width)
#endif

#ifdef DebugCF
        Serial.println(StepPercent);
#endif
      }
      else if (Test_Mode == Ramp)
      {
#ifdef X_test
        xAction =  (float)RampValue; //RampValue reaches 500 after 5 seconds
#endif

#ifdef Y_test
        yAction =  (float)RampValue; //RampValue reaches 500 after 5 seconds
#endif

#ifdef DebugCF
        Serial.println(RampValue);
#endif
      }

//      writeControlAction(xAction, yAction);
      RampValue+=2;
      Serial.print(PktCounter++);
      Serial.print(",");
      Serial.print(CountsToAngle(xEncoderCount));
      Serial.print(",");
      Serial.print(CountsToAngle(yEncoderCount));
      Serial.print(",");
      Serial.print(getxSpeed());
      Serial.print(",");
      Serial.println(getySpeed());

      writeSpeed(1400, 1000, 1000, 1000);

      if (PktCounter >= 500)
      {
        Test_Running=0;
        break;
      }
      while (micros() - lastSample < Sampling_time) {
        delayMicroseconds(10);
      }
      lastSample = micros();
      //      Serial.print(",");
      //      Serial.println(micros());


      // Populate the JSON document with values directly
      //UpdateTimeStamp();

    }
    
      writeSpeed(1000, 1000, 1000, 1000);
  }
