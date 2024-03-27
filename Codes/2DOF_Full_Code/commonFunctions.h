/*
   Header file with the main loop and common functions
   Credit:Scorpion
   Created: 20/10/2024
*/

#define DebugCF
#define RUN

PIDController xPOSPID, xVELPID, yPOSPID, yVELPID;

void PIDLoop(void * parameter) {
  initEncoder(0, 0);
  /*
    Main Control Loop, Runs each sampling time
  */
  while (1) {
#ifdef DebugCF
    Serial.println("init PID Loops");
#endif

#ifdef RUN
    EEPROM.begin(1);
    byte Work = EEPROM.read(0);
    EEPROM.write(0, !Work); //toggles running on resets
    EEPROM.commit();
    if (Work) {
      initESCs(FrontMotorPIN, RightMotorPIN, BackMotorPIN, LeftMotorPIN);
      delay(2500);//wait for esc calib
    }
#endif
    //Reset and Create 4 PID objects with specified parameters
    resetPID(&xPOSPID);
    initializePID(&xPOSPID, ixposkp, ixposki, ixposkd, ixposSet, -PositionLoopSat, PositionLoopSat);    // to be rechecked the limits
    resetPID(&xVELPID);
    initializePID(&xVELPID, ixvelkp, ixvelki, ixvelkd, ixvelSet, -xmaxDeltaMicros / 10, xmaxDeltaMicros / 10);
    resetPID(&yPOSPID);
    initializePID(&yPOSPID, iyposkp, iyposki, iyposkd, iyposSet, -PositionLoopSat, PositionLoopSat);    // to be rechecked the limits
    resetPID(&yVELPID);
    initializePID(&yVELPID, iyvelkp, iyvelki, iyvelkd, iyvelSet, -ymaxDeltaMicros / 10, ymaxDeltaMicros / 10);

#ifdef DebugCF
    Serial.println("init PID Loops Success");

#endif
    PID_Running = 1;


    PIDLastTime = micros();

    while (PID_Running) {

      //Update feedback values using sensor fusion
      xSpeed = getxSpeed();
      ySpeed = getySpeed();
      updateIMU();
      xSpeed = (1 - IMU_FusionPrio) * xSpeed + IMU_FusionPrio * AngleToCounts(xDotIMU);
      ySpeed = (1 - IMU_FusionPrio) * ySpeed + IMU_FusionPrio * AngleToCounts(yDotIMU);

      //Calculate velocity SP from positionPID output
      xVELPID.setpoint = (double)calculatePID(&xPOSPID, CountsToAngle(xEncoderCount));
      yVELPID.setpoint = (double)calculatePID(&yPOSPID, CountsToAngle(yEncoderCount));

      //Calculate action for motors from velocityPID output
      xAction =  (double)calculatePID(&xVELPID, xSpeed) * 10 ; //convert from Percnt to micros (Pulse width)
      yAction =  (double)calculatePID(&yVELPID, ySpeed) * 10 ; //convert from Percnt to micros (Pulse width)
      writeControlAction(xAction, yAction); //to check
      /*if (xAction > maxDeltaMicros)xAction = maxDeltaMicros;
        if (xAction < -maxDeltaMicros)xAction = -maxDeltaMicros;
        if (yAction > maxDeltaMicros)yAction = maxDeltaMicros;
        if (yAction < -maxDeltaMicros)yAction = -maxDeltaMicros;*/



      counta++;
      while (micros() - PIDLastTime < Sampling_time) {
        delayMicroseconds(1);

      }
#ifdef debugTime
      Serial.print(micros() - PIDLastTime);
#endif
      PIDLastTime = micros();

#ifdef DebugCF1 //just for debugging 
      Serial.print("Counter For PID: ");
      Serial.println(counta);
      counta++;
#endif
    }
  }
}
