
//timer Routine to update speed, runs on a timer with <SpeedUpdateTimer> Period
void IRAM_ATTR  UpdateSpeedISR() {
  uint64_t temp = timerRead(SpeedUpdateTimer);

  //if no X Pulse was detected after Period Update speed
  if ((temp - xLastSpeedTime) > (SpeedUpdateTime * 80 / pre)) {
    double lastT = (double)1000000.0 / xDelta[(xNext) % NoP];
    if (lastT > 0) {
      lastT += NoP * temp;
    } else {
      lastT -= NoP * temp;
    }
    xDelta[(xNext) % NoP] = (double) 1000000.0 / lastT;
  }

  //if no X Pulse was detected after Period Update speed
  if ((temp - yLastSpeedTime) > (SpeedUpdateTime * 80 / pre)) {
    double lastT = (double)1000000.0 / yDelta[(yNext) % NoP];
    if (lastT > 0) {
      lastT += NoP * (temp - yLastSpeedTime);
    } else {
      lastT -= NoP * (temp - yLastSpeedTime);
    }
    xDelta[(xNext) % NoP] = (double) 1000000.0 / lastT;
  }
  return ;
}

//Convert angle units
long AngleToCounts(double angle) {
  return (double)angle * PPR / 2 / PI;
}
double CountsToAngle(long count) {
  return (double)count * 2 * PI / PPR;
}

//Calculate the rolling average speed based on the last <NoP> Measurements
double getxSpeed() {
  double dtX = 0;
  byte dir = xDelta[(xNext) % NoP] > 0;
  for (byte c = 0; c < NoP; c++) {
    dtX  += (xDelta[c]);
    if ((xDelta[c] > 0) != dir) {
      dtX  += (xDelta[c]);
    }
  }
  return (double)(80 / pre * (double)dtX / PPR * (2 * PI) ) / NoP;
}
double getySpeed() {
  double dtY = 0;
  byte dir = yDelta[(yNext) % NoP] > 0;
  for (byte c = 0; c < NoP; c++) {
    dtY  += (yDelta[c]);
    if ((yDelta[c] > 0) != dir) {
      dtY  += (yDelta[c]);
    }
  }
  return (double)(80 / pre * (double)dtY / PPR * (2 * PI) ) / NoP;
}

//ISR to handle Each encoder channel pulses and record the deltatime in between(Pushes the Earliest value out of the FIFO stack)
void IRAM_ATTR  x_cha_isr() {
  int64_t temp = timerRead(SpeedUpdateTimer) - xLastSpeedTime;
  xLastSpeedTime = timerRead(SpeedUpdateTimer);
  if (digitalRead(X_ENCODER_PIN_A) == digitalRead(X_ENCODER_PIN_B)) {
    xEncoderCount++;
    xDelta[xNext % NoP] = (double)1000000.0 / temp;
  } else {
    xEncoderCount--;
    xDelta[xNext % NoP] = (double) - 1000000.0 / temp;
  }
  xNext++;
  if (xNext == NoP)xNext = 0;
}
void IRAM_ATTR  x_chb_isr() {
  int64_t temp = timerRead(SpeedUpdateTimer) - xLastSpeedTime;
  xLastSpeedTime = timerRead(SpeedUpdateTimer);
  if (digitalRead(X_ENCODER_PIN_A) == digitalRead(X_ENCODER_PIN_B)) {
    xEncoderCount--;
    xDelta[xNext % NoP] = (double) - 1000000.0 / temp;
  } else {
    xEncoderCount++;
    xDelta[xNext % NoP] = (double)1000000.0 / temp;
  }
  xNext++;
  if (xNext == NoP)xNext = 0;
}
void IRAM_ATTR  y_cha_isr() {
  int64_t temp = timerRead(SpeedUpdateTimer) - yLastSpeedTime;
  yLastSpeedTime = timerRead(SpeedUpdateTimer);
  if (digitalRead(Y_ENCODER_PIN_A) == digitalRead(Y_ENCODER_PIN_B)) {
    yEncoderCount++;
    yDelta[yNext % NoP] = (double)  1000000.0 / temp;
  } else {
    yEncoderCount--;
    yDelta[yNext % NoP] = (double) - 1000000.0 / temp;
  }
}
void IRAM_ATTR  y_chb_isr() {
  int64_t temp = timerRead(SpeedUpdateTimer) - yLastSpeedTime;
  yLastSpeedTime = timerRead(SpeedUpdateTimer);
  if (digitalRead(Y_ENCODER_PIN_A) == digitalRead(Y_ENCODER_PIN_B)) {
    yEncoderCount--;
    yDelta[yNext % NoP] = (double) - 1000000.0 / temp;
  } else {
    yEncoderCount++;
    yDelta[yNext % NoP] = (double)  1000000.0 / temp;
  }
}

//init the encoders
void initEncoder(double xStartAngle, double yStartAngle) {
  pinMode(X_ENCODER_PIN_A, INPUT);
  pinMode(X_ENCODER_PIN_B, INPUT);
  pinMode(Y_ENCODER_PIN_A, INPUT);
  pinMode(Y_ENCODER_PIN_B, INPUT);

  IntTimer = timerBegin(0, pre, true); //Start the timer at 80/<pre> mhz
  timerAttachInterrupt(IntTimer, &UpdateSpeedISR, true) ; //set the Timer ISR
  timerAlarmWrite(IntTimer, SpeedUpdateTime * 80 / pre, true); //Set the period
  timerAlarmEnable(IntTimer); //Just Enable
  SpeedUpdateTimer = timerBegin(1, pre, true); //Start the timer at 80/<pre> mhz
  timerStart(SpeedUpdateTimer); //Timer for getting the elapsed micros for speed calculation

  //Set the inital angles to Values from IMU
  initIMU();
  delay(500);
  updateIMU();
  xEncoderCount = AngleToCounts(xPosIMU);
  yEncoderCount = AngleToCounts(yPosIMU);

  //Attach the ISR functions for encoder pusles
  attachInterrupt(digitalPinToInterrupt(X_ENCODER_PIN_A), x_cha_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(X_ENCODER_PIN_B), x_chb_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Y_ENCODER_PIN_A), y_cha_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Y_ENCODER_PIN_B), y_chb_isr, CHANGE);

  //Set The Start time for Speed Calculation
  xLastSpeedTime = timerRead(SpeedUpdateTimer);
  yLastSpeedTime = timerRead(SpeedUpdateTimer);
}
