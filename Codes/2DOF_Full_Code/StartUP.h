/*
   Submodule for the non linear region
   Credit:Scorpion
   Created: 20/1/2024
   Not used for now
*/

void StartUP(double targetX, double targetY) {
  resetPID(&xPOSPID);
  initializePID(&xPOSPID, ixposkp, ixposki, ixposkd, ixposSet, -PositionLoopSat, PositionLoopSat);    // to be rechecked the limits
  resetPID(&xVELPID);
  initializePID(&xVELPID, ixvelkp, ixvelki, ixvelkd, ixvelSet, -xmaxDeltaMicrosStart / 10, xmaxDeltaMicrosStart / 10);
  resetPID(&yPOSPID);
  initializePID(&yPOSPID, iyposkp, iyposki, iyposkd, iyposSet, -PositionLoopSat, PositionLoopSat);    // to be rechecked the limits
  resetPID(&yVELPID);
  initializePID(&yVELPID, iyvelkp, iyvelki, iyvelkd, iyvelSet, -ymaxDeltaMicrosStart / 10, ymaxDeltaMicrosStart / 10);
  TickType_t PIDLastTime;
  const TickType_t xFrequency = 5 / portTICK_PERIOD_MS;

  // Initialise the xLastWakeTime variable with the current time.
  PIDLastTime = xTaskGetTickCount();
  while (abs(targetX) < abs(CountsToAngle(xEncoderCount)) || abs(targetY) < abs(CountsToAngle(yEncoderCount))) {
    xSpeed = getxSpeed();
    ySpeed = getySpeed();
    xVELPID.setpoint = (float)calculatePID(&xPOSPID, CountsToAngle(xEncoderCount)) ;//+ XRVG0_Y.Y2ref;
    yVELPID.setpoint = (float)calculatePID(&yPOSPID, CountsToAngle(yEncoderCount)) ;//+ YRVG0_Y.Y2ref;;

    //Calculate action for motors from velocityPID output
    xAction =  (int)(calculatePID(&xVELPID, xSpeed) * 10) ; //convert from Percnt to micros (Pulse width)
    yAction =  (int)(calculatePID(&yVELPID, ySpeed) * 10) ; //convert from Percnt to micros (Pulse width)
    
    uint32_t FM = min(max((int)(1500 + yAction), 1000), 2000);
    uint32_t RM = min(max((int)(1500 + xAction), 1000), 2000);
    uint32_t BM = min(max((int)(1500 - yAction), 1000), 2000);
    uint32_t LM = min(max((int)(1500 - xAction), 1000), 2000);

#ifdef DebugMotor
    Serial.println((String)"POWERS: " + FM + ", " + RM + ", " + BM + ", " + LM);
#endif

    writeSpeed(FM, RM, BM, LM);

    counta++;
    vTaskDelayUntil( &PIDLastTime, xFrequency );
  }
}
