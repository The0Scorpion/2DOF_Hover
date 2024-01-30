#include <ESP32Servo.h>
Servo Fmotor, Rmotor, Bmotor, Lmotor;
//#define DebugMotor
void initESCs(byte FPin, byte RPin, byte BPin, byte LPin) {
  Fmotor.attach(FPin, 1000, 2000);
  Rmotor.attach(RPin, 1000, 2000);
  Bmotor.attach(BPin, 1000, 2000);
  Lmotor.attach(LPin, 1000, 2000);
  Fmotor.write(0);
  Rmotor.write(0);
  Bmotor.write(0);
  Lmotor.write(0);
  ESC_Running = 1;
}
void writeSpeed(int Fmicros, int Rmicros, int Bmicros, int Lmicros) {
  if (ESC_Running == 1) {
    Fmotor.writeMicroseconds(Fmicros);
    Rmotor.writeMicroseconds(Rmicros);
    Bmotor.writeMicroseconds(Bmicros);
    Lmotor.writeMicroseconds(Lmicros);
  } else {
    Fmotor.detach();
    Rmotor.detach();
    Bmotor.detach();
    Lmotor.detach();
  }
}
void writeControlAction(int xAct, int yAct) { //delta micros
  int FM = min(max(Opratingpoint + yAct, minMicros), maxMicros);
  int RM = min(max(Opratingpoint + xAct, minMicros), maxMicros);
  int BM = min(max(Opratingpoint - yAct, minMicros), maxMicros);
  int LM = min(max(Opratingpoint - xAct, minMicros), maxMicros);
#ifdef DebugMotor
  Serial.println((String)"POWERS: " + FM + ", " + RM + ", " + BM + ", " + LM);
#endif
  writeSpeed(FM, RM, BM, LM);
}
