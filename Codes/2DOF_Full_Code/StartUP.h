/*
   Submodule for the non linear region
   Credit:Scorpion
   Created: 20/1/2024
   Not used for now
*/

void StartUP(double targetX, double targetY) {
  initIMU();
  updateIMU();
  updateIMU();
  delay(500);
  updateIMU();
  xEncoderCount = AngleToCounts(xPosIMU);
  yEncoderCount = AngleToCounts(yPosIMU);

  //Reset and Create 4 PID objects with StartUP parameters
  resetPID(&xPOSPID);
  initializePID(&xPOSPID, 1.5 * xposkp, 1.5 * xposki, 1.5 * xposkd, 0, -PositionLoopSat * 2, PositionLoopSat * 2); // to be rechecked the limits
  resetPID(&xVELPID);
  initializePID(&xVELPID, 1.5 * xvelkp, 1.5 * xvelki, 1.5 * xvelkd, 0, -xmaxDeltaMicrosStart / 10, xmaxDeltaMicrosStart / 10);
  resetPID(&yPOSPID);
  initializePID(&yPOSPID, 1.5 * yposkp, 1.5 * yposki, 1.5 * yposkd, 0, -PositionLoopSat * 2, PositionLoopSat * 2); // to be rechecked the limits
  resetPID(&yVELPID);
  initializePID(&yVELPID, 1.5 * yvelkp, 1.5 * yvelki, 1.5 * yvelkd, 0, -ymaxDeltaMicrosStart / 10, ymaxDeltaMicrosStart / 10);
  TickType_t PIDLastTime;
  const TickType_t xFrequency = 5 / portTICK_PERIOD_MS;

  // Initialise the xLastWakeTime variable with the current time.
  PIDLastTime = xTaskGetTickCount();
  while ((abs(targetX) < abs(CountsToAngle(xEncoderCount))) || (abs(targetY) < abs(CountsToAngle(yEncoderCount))) || (abs(xSpeed > targetX)) || (abs(ySpeed > targetY))) {
    xSpeed = getxSpeed();
    ySpeed = getySpeed();
    xVELPID.setpoint = (float)calculatePID(&xPOSPID, CountsToAngle(xEncoderCount)) ;//+ XRVG0_Y.Y2ref;
    yVELPID.setpoint = (float)calculatePID(&yPOSPID, CountsToAngle(yEncoderCount)) ;//+ YRVG0_Y.Y2ref;;

    //Calculate action for motors from velocityPID output
    xAction =  (int)(calculatePID(&xVELPID, xSpeed) * 10) ; //convert from Percnt to micros (Pulse width)
    yAction =  (int)(calculatePID(&yVELPID, ySpeed) * 10) ; //convert from Percnt to micros (Pulse width)

    uint32_t FM = min(max((int)(1300 + yAction), 1000), 2000);
    uint32_t RM = min(max((int)(1500 + xAction), 1000), 2000);
    uint32_t BM = min(max((int)(1300 - yAction), 1000), 2000);
    uint32_t LM = min(max((int)(1500 - xAction), 1000), 2000);

#ifdef DebugMotor
    Serial.println((String)"POWERS: " + FM + ", " + RM + ", " + BM + ", " + LM);
#endif

    writeSpeed(FM, RM, BM, LM);

    counta++;
    vTaskDelayUntil( &PIDLastTime, xFrequency );
  }
}
