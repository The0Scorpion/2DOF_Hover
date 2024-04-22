/*
   Header file with the main loop and common functions
   Credit:Scorpion
   Created: 20/10/2024
*/

#define DebugCF
#define RUN


void PIDLoop(void * parameter) {

  /*
    Main Control Loop, Runs each sampling time
  */
  initEncoder(0, 0);
#ifdef RUN
  EEPROM.begin(1);
  Work = !EEPROM.read(0);
  EEPROM.write(0, Work); //toggles running on resets
  EEPROM.commit();

#endif

  while (1) {
#ifdef DebugCF
    Serial.println("init PID Loops");
#endif
    if (Work) {
      initESCs(FrontMotorPIN, RightMotorPIN, BackMotorPIN, LeftMotorPIN);
      delay(2500);//wait for esc calib
    }
    //Startup
#ifdef DebugCF
    Serial.println("StaRTUp");
#endif
    initIMU();
    updateIMU();
    updateIMU();
    delay(500);
    updateIMU();
    xEncoderCount = AngleToCounts(xPosIMU);
    yEncoderCount = AngleToCounts(yPosIMU);


    StartUP(0.20, 0.20);

    //Reset and Create 4 PID objects with StarUp parameters


    //Reset and Create 4 PID objects with specified parameters
    resetPID(&xPOSPID);
    initializePID(&xPOSPID, xposkp, xposki, xposkd, xposSet, -PositionLoopSat, PositionLoopSat);   // to be rechecked the limits
    resetPID(&xVELPID);
    initializePID(&xVELPID,  xvelkp, xvelki, xvelkd, xvelSet, -xmaxDeltaMicros / 10, xmaxDeltaMicros / 10);
    resetPID(&yPOSPID);
    initializePID(&yPOSPID, yposkp, yposki, yposkd, yposSet, -PositionLoopSat, PositionLoopSat);   // to be rechecked the limits
    resetPID(&yVELPID);
    initializePID(&yVELPID, yvelkp, yvelki, yvelkd, yvelSet, -ymaxDeltaMicros / 10, ymaxDeltaMicros / 10);

    XRVG0_U.Y1target = xposSet;
    YRVG0_U.Y1target = yposSet;

#ifdef DebugCF
    Serial.println("init PID Loops Success");
#endif



    //PIDLastTime1 = micros();
    TickType_t PIDLastTime1;
    const TickType_t xFrequency = 5 / portTICK_PERIOD_MS;

    // Initialise the xLastWakeTime variable with the current time.
    PIDLastTime1 = xTaskGetTickCount();
    PID_Running = 1;
    while (PID_Running) {

      //Update feedback values using sensor fusion
      xSpeed = getxSpeed();
      ySpeed = getySpeed();

      //updateIMU();
      //xSpeed = (1 - IMU_FusionPrio) * xSpeed + IMU_FusionPrio * AngleToCounts(xDotIMU);
      //ySpeed = (1 - IMU_FusionPrio) * ySpeed + IMU_FusionPrio * AngleToCounts(yDotIMU);

      //calcualte RVG
      RVG0_step();
      xPOSPID.setpoint = XRVG0_Y.Y1ref;
      yPOSPID.setpoint = XRVG0_Y.Y1ref;

      //Calculate velocity SP from positionPID output
      xVELPID.setpoint = (float)calculatePID(&xPOSPID, CountsToAngle(xEncoderCount)) + XRVG0_Y.Y2ref;
      yVELPID.setpoint = (float)calculatePID(&yPOSPID, CountsToAngle(yEncoderCount)) + YRVG0_Y.Y2ref;

      //Calculate action for motors from velocityPID output
      xAction =  (float)calculatePID(&xVELPID, xSpeed) * 10 ; //convert from Percnt to micros (Pulse width)
      yAction =  (float)calculatePID(&yVELPID, ySpeed) * 10 ; //convert from Percnt to micros (Pulse width)
      writeControlAction((int)xAction, (int)yAction);

      counta++;
      vTaskDelayUntil( &PIDLastTime1, xFrequency );

      if (abs(CountsToAngle(xEncoderCount)) > xposSetLimit || abs(CountsToAngle(yEncoderCount)) > yposSetLimit) {
        if (failcount == 0) {
          failcount = counta;
        } else {
          if (counta - failcount > failLimit) {
            PID_Running = 0;
          }
        }
      } else {
        failcount = 0;
      }
#ifdef debugTime
      Serial.print(micros() - PIDLastTime1);
#endif

#ifdef DebugCF1 //just for debugging 
      Serial.print("Counter For PID: ");
      Serial.println(counta);
#endif
    }
  }
}
