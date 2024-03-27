/*
 * Submodule for the non linear region
 * Credit:Scorpion 
 * Created: 20/1/2024
 * Not used for now
*/

void StartUP(double targetX, double targetY) {

  while (targetX < CountsToAngle(xEncoderCount) || targetY < CountsToAngle(yEncoderCount)) {
    Serial.println(CountsToAngle(xEncoderCount));
    Serial.println(CountsToAngle(yEncoderCount));
    int FPower = StartPower;
    int BPower = StartPower;
    int RPower = StartPower;
    int LPower = StartPower;
    if (targetX < abs(CountsToAngle(yEncoderCount))) {
      if (xEncoderCount > 0) {
        FPower -= ymaxDeltaMicros;
        BPower += ymaxDeltaMicros;
      } else {
        FPower += ymaxDeltaMicros;
        BPower -= ymaxDeltaMicros;
      }
    }
    if (targetY < abs(CountsToAngle(xEncoderCount))) {
      if (yEncoderCount > 0) {
        RPower -= xmaxDeltaMicros;
        LPower += xmaxDeltaMicros;
      } else {
        RPower += xmaxDeltaMicros;
        LPower -= xmaxDeltaMicros;
      }
    }
    writeSpeed(FPower, RPower, BPower, LPower);
  }
}
