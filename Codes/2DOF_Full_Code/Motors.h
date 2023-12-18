#include <ESP32Servo.h>
Servo Fmotor, Rmotor, Bmotor, Lmotor;

void initESCs(byte FPin, byte RPin, byte BPin, byte LPin) {
  Fmotor.attach(FPin);
  Rmotor.attach(RPin);
  Bmotor.attach(BPin);
  Lmotor.attach(LPin);
}
void writeSpeed(int Fmicros, int Rmicros, int Bmicros, int Lmicros) {
  if (ESC_Running) {
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
  int FM = min(max(Opratingpoint + xAct, minMicros), maxMicros);
  int RM = min(max(Opratingpoint + yAct, minMicros), maxMicros);
  int BM = min(max(Opratingpoint - xAct, minMicros), maxMicros);
  int LM = min(max(Opratingpoint - yAct, minMicros), maxMicros);
  writeSpeed(FM, RM, BM, LM);
}
