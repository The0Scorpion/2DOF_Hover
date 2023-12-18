#define pre 2
int n = 8;
volatile long xEncoderCount = 0, yEncoderCount = 0, xSpeedCount = 0, ySpeedCount = 0;
volatile long xLastCount = 0, xCurrentP = 0;
unsigned long xLastSpeedTime, yLastSpeedTime;
volatile int xDir = 0;
uint32_t Tmin = 15000, SpeedUpdateTime = 20000;
volatile double xSpeed = 0, ySpeed = 0; //counts per second
hw_timer_t *SpeedUpdateTimer = NULL, *IntTimer = NULL;
volatile int xNext = 0, yNext = 0;
volatile long xDelta, yDelta; //[0,130,150,110]
void IRAM_ATTR  UpdateSpeedISR() {
  uint32_t temp = timerRead(SpeedUpdateTimer) ;
  if (temp - xLastSpeedTime > SpeedUpdateTime) {
    xDelta = temp - xLastSpeedTime;
  }

}
long AngleToCounts(double angle) {
  return angle * PPR / 360;
}
double getxSpeed() {

  if (xDelta == 0) {
    return 0;
  }
  else {
    return (double)xCurrentP * 1000000 / pre * 80 / xDelta / 4;
  }
}
double getySpeed() {
  if (yDelta == 0) {
    return 0;
  }
  else {
    return (double)n * 1000000 / pre * 80 / yDelta;
  }
}
void IRAM_ATTR  x_cha_isr() {
  uint32_t temp = timerRead(SpeedUpdateTimer);
  if (digitalRead(X_ENCODER_PIN_A) == digitalRead(X_ENCODER_PIN_B)) {
    xEncoderCount++;
    xDir = 1;
    if (temp - xLastSpeedTime > Tmin  && !(abs(xEncoderCount - xLastCount) % 4) && ((xEncoderCount - xLastCount) > 0)) {
      xCurrentP = xEncoderCount - xLastCount;
      xDelta = temp - xLastSpeedTime;
      xLastSpeedTime = temp;
      xLastCount = xEncoderCount;
    }
  } else {
    xEncoderCount--;
    xDir = -1;
    if (temp - xLastSpeedTime > Tmin  && !(abs(xEncoderCount - xLastCount) % 4)  && ((xEncoderCount - xLastCount) < 0)) {
      xCurrentP = xEncoderCount - xLastCount;
      uint32_t temp = timerRead(SpeedUpdateTimer);
      xDelta = temp - xLastSpeedTime;
      xLastSpeedTime = temp;
      xLastCount = xEncoderCount;
    }
  }
}
void IRAM_ATTR  x_chb_isr() {
  uint32_t temp = timerRead(SpeedUpdateTimer);
  if (digitalRead(X_ENCODER_PIN_A) == digitalRead(X_ENCODER_PIN_B)) {
    xEncoderCount--;
    xDir = -1;
    if (temp - xLastSpeedTime > Tmin && !(abs(xEncoderCount - xLastCount) % 4) && ((xEncoderCount - xLastCount) < 0) ) {
      xCurrentP = xEncoderCount - xLastCount;
      xDelta = temp - xLastSpeedTime;
      xLastSpeedTime = temp;
      xLastCount = xEncoderCount;
    }
  } else {
    xEncoderCount++;
    xDir = 1;
    if (temp - xLastSpeedTime > Tmin  && !(abs(xEncoderCount - xLastCount) % 4) && ((xEncoderCount - xLastCount) > 0) ) {
      xCurrentP = xEncoderCount - xLastCount;
      uint32_t temp = timerRead(SpeedUpdateTimer);
      xDelta = temp - xLastSpeedTime;
      xLastSpeedTime = temp;
      xLastCount = xEncoderCount;
    }
  }
}
void IRAM_ATTR  y_cha_isr() {
  if (digitalRead(Y_ENCODER_PIN_A) == digitalRead(Y_ENCODER_PIN_B)) {
    yEncoderCount++;
  } else {
    yEncoderCount--;
  }
}
void IRAM_ATTR  y_chb_isr() {
  if (digitalRead(Y_ENCODER_PIN_A) == digitalRead(Y_ENCODER_PIN_B)) {
    yEncoderCount--;
  } else {
    yEncoderCount++;
  }
}
void initEncoder(double xStartAngle, double yStartAngle) {
  pinMode(X_ENCODER_PIN_A, INPUT);
  pinMode(X_ENCODER_PIN_B, INPUT);
  pinMode(Y_ENCODER_PIN_A, INPUT);
  pinMode(Y_ENCODER_PIN_B, INPUT);
  IntTimer = timerBegin(0, pre, true); //1mhz
  timerAttachInterrupt(IntTimer, &UpdateSpeedISR, true);
  timerAlarmWrite(IntTimer, SpeedUpdateTime, true);
  timerAlarmEnable(IntTimer); //Just Enable
  SpeedUpdateTimer = timerBegin(1, pre, true); //1mhz
  timerStart(SpeedUpdateTimer);
  xEncoderCount = AngleToCounts(xStartAngle);
  yEncoderCount = AngleToCounts(yStartAngle);
  attachInterrupt(digitalPinToInterrupt(X_ENCODER_PIN_A), x_cha_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(X_ENCODER_PIN_B), x_chb_isr, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(Y_ENCODER_PIN_A), y_cha_isr, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(Y_ENCODER_PIN_B), y_chb_isr, CHANGE);
  xLastSpeedTime = timerRead(SpeedUpdateTimer);
  yLastSpeedTime = timerRead(SpeedUpdateTimer);
}
