//Cascaded PID Control
#include "PID.h"
#include "Parameters.h"
#include "EEPROM.h"
#include "RVG0.h"
#include "encoder.h"

double initController(double *param=nullptr){
      // Reset and Create 4 PID objects with specified parameters
      xPOSPID.reset();
      xPOSPID.init(xposkp, xposki, xposkd, xposSet, -PositionLoopSat, PositionLoopSat); // to be rechecked the limits

      xVELPID.reset();
      xVELPID.init(xvelkp, xvelki, xvelkd, xvelSet, -xmaxDeltaMicros / 10, xmaxDeltaMicros / 10);

      yPOSPID.reset();
      yPOSPID.init(yposkp, yposki, yposkd, yposSet, -PositionLoopSat, PositionLoopSat); // to be rechecked the limits

      yVELPID.reset();
      yVELPID.init(yvelkp, yvelki, yvelkd, yvelSet, -ymaxDeltaMicros / 10, ymaxDeltaMicros / 10);

      XRVG0_U.Y1target = xposSet;
      YRVG0_U.Y1target = yposSet;

#ifdef DebugCF
      Serial.println("init PID Loops Success");
#endif
}
void stepController(){
        // calcualte RVG
        RVG0_step();
        xPOSPID.setpoint = XRVG0_Y.Y1ref;
        yPOSPID.setpoint = XRVG0_Y.Y1ref;

        // Calculate velocity SP from positionPID output
        xVELPID.setpoint = (float)xPOSPID.calculate(CountsToAngle(xEncoderCount)) + XRVG0_Y.Y2ref;
        yVELPID.setpoint = (float)yPOSPID.calculate(CountsToAngle(yEncoderCount)) + YRVG0_Y.Y2ref;

        // Calculate action for motors from velocity PID output
        xAction = (float)xVELPID.calculate(xSpeed) * 10; // convert from Percent to micros (Pulse width)
        yAction = (float)yVELPID.calculate(ySpeed) * 10; // convert from Percent to micros (Pulse width)

}