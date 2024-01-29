unsigned long PIDLastTime = 0;
PIDController *xPOSPID, *xVELPID, *yPOSPID, *yVELPID;
double xSpeed, ySpeed;
void PIDLoop() {
  /*
    Main Control Loop, Runs each sampling time
  */
  while (1) {
    resetPID(xPOSPID);
    initializePID(xPOSPID, ixposkp, ixposki, ixposkd, ixposSet, -maxDeltaMicros, maxDeltaMicros);
    resetPID(xVELPID);
    initializePID(xVELPID, ixvelkp, ixvelki, ixvelkd, ixvelSet, -maxDeltaMicros, maxDeltaMicros);
    resetPID(yPOSPID);
    initializePID(yPOSPID, iyposkp, iyposki, iyposkd, iyposSet, -maxDeltaMicros, maxDeltaMicros);
    resetPID(yVELPID);
    initializePID(yVELPID, iyvelkp, iyvelki, iyvelkd, iyvelSet, -maxDeltaMicros, maxDeltaMicros);

    PID_Running = 1;

    initESCs(FrontMotorPIN, RightMotorPIN, BackMotorPIN, LeftMotorPIN);

    while (PID_Running) {
      while (micros() - PIDLastTime < Sampling_time)delay(1);
      xSpeed = getxSpeed();
      ySpeed = getySpeed();
      updateIMU();
      xSpeed = (1 - IMU_FusionPrio) * xSpeed + IMU_FusionPrio * AngleToCounts(xDotIMU);
      ySpeed = (1 - IMU_FusionPrio) * ySpeed + IMU_FusionPrio * AngleToCounts(yDotIMU);
      xVELPID->setpoint = calculatePID(xPOSPID, CountsToAngle(xEncoderCount));
      xAction =  calculatePID(xVELPID, xSpeed);
      if (xAction > maxDeltaMicros)xAction = maxDeltaMicros;
      if (xAction < -maxDeltaMicros)xAction = -maxDeltaMicros;
      yVELPID->setpoint = calculatePID(yPOSPID, CountsToAngle(yEncoderCount));
      yAction =   calculatePID(yVELPID, ySpeed);
      if (yAction > maxDeltaMicros)yAction = maxDeltaMicros;
      if (yAction < -maxDeltaMicros)yAction = -maxDeltaMicros;
      writeControlAction(xAction, yAction); //to check
      PIDLastTime = micros();
    }
  }
}
