#define DebugCF

#define RUN

void MotorEstimation(void * parameter) {
  //initEncoder(0, 0);
  while (1)
  {
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
      //initESCs(FrontMotorPIN, RightMotorPIN, BackMotorPIN, LeftMotorPIN);
      delay(2500);//wait for esc calib
    }
#endif

#ifdef DebugCF
    Serial.println("init Escs Success");
#endif


    Test_Running = 1;

    while (Test_Running) {

      //Update feedback values using sensor fusion
//      xSpeed = getxSpeed();
//      ySpeed = getySpeed();
//      updateIMU();
//      xSpeed = (1 - IMU_FusionPrio) * xSpeed + IMU_FusionPrio * AngleToCounts(xDotIMU);
//      ySpeed = (1 - IMU_FusionPrio) * ySpeed + IMU_FusionPrio * AngleToCounts(yDotIMU);


      if(Test_Mode == Step)
      {
        #ifdef X_test
              xAction =  StepPercent * 10 ; //convert from Percent to micros (Pulse width)
        #endif
 
        #ifdef Y_test
              yAction =  StepPercent * 10 ; //convert from Percent to micros (Pulse width)
        #endif

        #ifdef DebugCF
              Serial.println(StepPercent);
        #endif
      }
      else if(Test_Mode == Ramp)
      {
        #ifdef X_test
              xAction =  (float)RampValue / 2 ; //RampValue reaches 500 after 5 seconds
        #endif
 
        #ifdef Y_test
              yAction =  (float)RampValue / 2 ; //RampValue reaches 500 after 5 seconds
        #endif

        #ifdef DebugCF
              Serial.println(RampValue);
        #endif
      }

      writeControlAction(xAction, yAction);
      RampValue++;
//      Serial.print(",");
//      Serial.println(micros());

      delayMicroseconds(Sampling_time);
    }
  }
}
