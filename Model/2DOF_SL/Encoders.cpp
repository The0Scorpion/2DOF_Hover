//#include "F:\College\Semester_10\GP2\2DOF\2DOF_Hover\Model\2DOF_SL\Encoders.h"
#include "Arduino.h"
#include "Encoders.h"



// EncXA uint8 [1,1] Non tunable
// EncXB int8 [1,1] Non tunable
// EncYA int8 [1,1] Non tunable
// EncYB int8 [1,1] Non tunable

#define X_ENCODER_PIN_A 32
#define X_ENCODER_PIN_B 33
#define Y_ENCODER_PIN_A 34
#define Y_ENCODER_PIN_B 35

#define PPR 8000 //Counts per rev for encoders (PPR*4)
#define pre 20 //Prescaler for hardware timers
#define NoP  8 //Number of counts for rolling average for encoder velocity calculation
volatile long xEncoderCount = 0, yEncoderCount = 0;
unsigned long xLastSpeedTime, yLastSpeedTime;
uint64_t SpeedUpdateTime = 20000;
hw_timer_t *SpeedUpdateTimer = NULL, *IntTimer = NULL;
volatile int64_t xNext = 0, yNext = 0;
volatile double xDelta[NoP], yDelta[NoP]; //[0,130,150,110]
bool enabled;



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
    yDelta[(yNext) % NoP] = (double) 1000000.0 / lastT;
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
  yNext++;
  if (yNext == NoP)yNext = 0;
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
  yNext++;
  if (yNext == NoP)yNext = 0;
}




void setupFunctionEncoders(){
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

}

// X double [1,1]
// Xdot double [1,1]
// Y double [1,1]
// Ydot double [1,1]
// IMU_X double [1,1]
// IMU_Y double [1,1]

void stepFunctionEncoders(double * X,int size_vector_1,double * Xdot,int size_vector_2,double * Y,int size_vector_3,double * Ydot,int size_vector_4,double IMU_X,int size_vector_a,double IMU_Y,int size_vector_b){
  if(enabled)
  {
      *X = CountsToAngle(xEncoderCount);
      *Xdot = CountsToAngle(getxSpeed());
      *Y = CountsToAngle(yEncoderCount);
      *Ydot = CountsToAngle(getySpeed());
  }
  else
  {
      xEncoderCount  = IMU_X;
      yEncoderCount  = IMU_Y;

      //Attach the ISR functions for encoder pusles
      attachInterrupt(digitalPinToInterrupt(X_ENCODER_PIN_A), x_cha_isr, CHANGE);
      attachInterrupt(digitalPinToInterrupt(X_ENCODER_PIN_B), x_chb_isr, CHANGE);
      attachInterrupt(digitalPinToInterrupt(Y_ENCODER_PIN_A), y_cha_isr, CHANGE);
      attachInterrupt(digitalPinToInterrupt(Y_ENCODER_PIN_B), y_chb_isr, CHANGE);
      //Set The Start time for Speed Calculation
      xLastSpeedTime = timerRead(SpeedUpdateTimer);
      yLastSpeedTime = timerRead(SpeedUpdateTimer);

      enabled = 1;
  }

}