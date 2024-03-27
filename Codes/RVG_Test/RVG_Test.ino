#include "RVG0.h"

void setup() {
  XRVG0_U.Y1target = 0.4;
  Serial.begin(115200);
}

void loop() {

  while (1)
  {
    RVG0_step();
    Serial.print(XRVG0_Y.Y1ref);
    Serial.print(", ");
    Serial.print(XRVG0_Y.Y2ref);
    Serial.println();
  }
}
