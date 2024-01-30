//#define DebugCF
#define RUN
unsigned long PIDLastTime = 0;
PIDController xPOSPID, xVELPID, yPOSPID, yVELPID;
double xSpeed, ySpeed;
void PIDLoop(void * parameter) {
  /*
    Main Control Loop, Runs each sampling time
  */
  while (1) {
#ifdef DebugCF
    Serial.println("init PID Loops");
#endif
    resetPID(&xPOSPID);
    initializePID(&xPOSPID, ixposkp, ixposki, ixposkd, ixposSet, -maxDeltaMicros, maxDeltaMicros);
    resetPID(&xVELPID);
    initializePID(&xVELPID, ixvelkp, ixvelki, ixvelkd, ixvelSet, -maxDeltaMicros, maxDeltaMicros);
    resetPID(&yPOSPID);
    initializePID(&yPOSPID, iyposkp, iyposki, iyposkd, iyposSet, -maxDeltaMicros, maxDeltaMicros);
    resetPID(&yVELPID);
    initializePID(&yVELPID, iyvelkp, iyvelki, iyvelkd, iyvelSet, -maxDeltaMicros, maxDeltaMicros);
#ifdef DebugCF
    Serial.println("init PID Loops Success");
    int counta = 0;
#endif
    PID_Running = 1;
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
    PIDLastTime = micros();

    while (PID_Running) {

      xSpeed = getxSpeed();
      ySpeed = getySpeed();
      updateIMU();
      xSpeed = (1 - IMU_FusionPrio) * xSpeed + IMU_FusionPrio * AngleToCounts(xDotIMU);
      ySpeed = (1 - IMU_FusionPrio) * ySpeed + IMU_FusionPrio * AngleToCounts(yDotIMU);
      xVELPID.setpoint = calculatePID(&xPOSPID, CountsToAngle(xEncoderCount));
      xAction =  (double)calculatePID(&xVELPID, xSpeed) * 10 ; //convert from Percnt to micros (Pulse width)
      if (xAction > maxDeltaMicros)xAction = maxDeltaMicros;
      if (xAction < -maxDeltaMicros)xAction = -maxDeltaMicros;
      yVELPID.setpoint = calculatePID(&yPOSPID, CountsToAngle(yEncoderCount));
      yAction =  (double)calculatePID(&yVELPID, ySpeed) * 10 ; //convert from Percnt to micros (Pulse width)
      if (yAction > maxDeltaMicros)yAction = maxDeltaMicros;
      if (yAction < -maxDeltaMicros)yAction = -maxDeltaMicros;
      writeControlAction(xAction, yAction); //to check
      PIDLastTime = micros();
      delayMicroseconds(Sampling_time);
#ifdef DebugCF //just for debugging 
      Serial.print("Counter For PID: ");
      Serial.println(counta);
      counta++;
#endif
    }
  }
}
