
volatile long xEncoderCount = 0, yEncoderCount = 0;
unsigned long xLastSpeedTime, yLastSpeedTime;
uint64_t SpeedUpdateTime = 20000;
hw_timer_t *SpeedUpdateTimer = NULL, *IntTimer = NULL;
volatile int64_t xNext = 0, yNext = 0;
volatile double xDelta[NoP], yDelta[NoP]; //[0,130,150,110]
void IRAM_ATTR  UpdateSpeedISR() {
  uint64_t temp = timerRead(SpeedUpdateTimer);
  if ((temp - xLastSpeedTime) > (SpeedUpdateTime * 80 / pre)) {
    double lastT = (double)1000000.0 / xDelta[(xNext) % NoP];
    if (lastT > 0) {
      lastT += NoP * temp;
    } else {
      lastT -= NoP * temp;
    }
    xDelta[(xNext) % NoP] = (double) 1000000.0 / lastT;
  }
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
long AngleToCounts(double angle) {
  return (double)angle * PPR / 2 / PI;
}
double CountsToAngle(long count) {
  return (double)count * 2 * PI / PPR;
}
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
void initEncoder(double xStartAngle, double yStartAngle) {
  pinMode(X_ENCODER_PIN_A, INPUT);
  pinMode(X_ENCODER_PIN_B, INPUT);
  pinMode(Y_ENCODER_PIN_A, INPUT);
  pinMode(Y_ENCODER_PIN_B, INPUT);
  IntTimer = timerBegin(0, pre, true); //1mhz
  timerAttachInterrupt(IntTimer, &UpdateSpeedISR, true) ;
  timerAlarmWrite(IntTimer, SpeedUpdateTime * 80 / pre, true);
  timerAlarmEnable(IntTimer); //Just Enable
  SpeedUpdateTimer = timerBegin(1, pre, true); //1mhz
  timerStart(SpeedUpdateTimer);
  xEncoderCount = AngleToCounts(xStartAngle);
  yEncoderCount = AngleToCounts(yStartAngle);
  attachInterrupt(digitalPinToInterrupt(X_ENCODER_PIN_A), x_cha_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(X_ENCODER_PIN_B), x_chb_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Y_ENCODER_PIN_A), y_cha_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Y_ENCODER_PIN_B), y_chb_isr, CHANGE);
  xLastSpeedTime = timerRead(SpeedUpdateTimer);
  yLastSpeedTime = timerRead(SpeedUpdateTimer);
}
