unsigned long PIDLastTime = 0;
PIDController *xPOSPID, *XVELPID, *yPOSPID, *yVELPID;

void PIDLoop(void * parameter) {
  /*
    Main Control Loop, Runs each sampling time
  */
  while (1) {
    resetPID(xPOSPID);
    initializePID(xPOSPID, ixposkp, ixposki, ixposkd, ixposSet, -maxDeltaMicros, maxDeltaMicros);
    resetPID(XVELPID);
    initializePID(XVELPID, ixvelkp, ixvelki, ixvelkd, ixvelSet, -maxDeltaMicros, maxDeltaMicros);
    resetPID(yPOSPID);
    initializePID(yPOSPID, iyposkp, iyposki, iyposkd, iyposSet, -maxDeltaMicros, maxDeltaMicros);
    resetPID(yVELPID);
    initializePID(yVELPID, iyvelkp, iyvelki, iyvelkd, iyvelSet, -maxDeltaMicros, maxDeltaMicros);

    PID_Running = 1;

    initESCs(FrontMotorPIN, RightMotorPIN, BackMotorPIN, LeftMotorPIN);
    ESC_Running = 1;

    while (PID_Running) {
      while (micros() - PIDLastTime < Sampling_time)continue;
      getxSpeed();
      getySpeed();
      updateIMU();
      xSpeed = (1 - IMU_FusionPrio) * xSpeed + IMU_FusionPrio * AngleToCounts(xDotIMU);
      ySpeed = (1 - IMU_FusionPrio) * ySpeed + IMU_FusionPrio * AngleToCounts(yDotIMU);
      xAction = calculatePID(xPOSPID, xEncoderCount) + calculatePID(XVELPID, xSpeed);
      if (xAction > maxDeltaMicros)xAction = maxDeltaMicros;
      if (xAction < -maxDeltaMicros)xAction = -maxDeltaMicros;
      xAction = calculatePID(yPOSPID, yEncoderCount) + calculatePID(yVELPID, ySpeed);
      if (yAction > maxDeltaMicros)yAction = maxDeltaMicros;
      if (yAction < -maxDeltaMicros)yAction = -maxDeltaMicros;
      writeControlAction(xAction, yAction); //to check
      PIDLastTime = micros();
    }
  }
}

void DataAQU() {
  /*Takes The xpos,ypos,xvel,yvel and displays them over Serial and ESPnow
    constructs an OutMessage Struct to be sent over ESPNOW*/
  //TO DO
}
