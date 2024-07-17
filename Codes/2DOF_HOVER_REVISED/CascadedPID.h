// Cascaded PID Control
#include "PID.h"
#include "Parameters.h"
#include "EEPROM.h"
#include "RVG0.h"
#include "encoder.h"

// Initialize PID controllers and related variables
void initController() {
    // Reset and initialize 4 PID objects with specified parameters

    // X Position PID
    xPOSPID.reset();
    xPOSPID.init(xposkp, xposki, xposkd, xposSet, -PositionLoopSat, PositionLoopSat);

    // X Velocity PID
    xVELPID.reset();
    xVELPID.init(xvelkp, xvelki, xvelkd, xvelSet, -xmaxDeltaMicros / 10, xmaxDeltaMicros / 10);

    // Y Position PID
    yPOSPID.reset();
    yPOSPID.init(yposkp, yposki, yposkd, yposSet, -PositionLoopSat, PositionLoopSat);

    // Y Velocity PID
    yVELPID.reset();
    yVELPID.init(yvelkp, yvelki, yvelkd, yvelSet, -ymaxDeltaMicros / 10, ymaxDeltaMicros / 10);

    // Set initial targets for RVG0 module
    XRVG0_U.Y1target = xposSet;
    YRVG0_U.Y1target = yposSet;

#ifdef DebugCF
    Serial.println("Initialized PID Loops Successfully");
#endif
}

// Perform one step of the controller loop
void stepController() {
    // Calculate RVG0 outputs
    RVG0_step();

    // Set position setpoints from RVG0 module
    xPOSPID.setpoint = XRVG0_Y.Y1ref;
    yPOSPID.setpoint = YRVG0_Y.Y1ref;

    // Calculate velocity setpoints from position PID outputs and RVG0 references
    xVELPID.setpoint = (float)xPOSPID.calculate(CountsToAngle(xEncoderCount)) + XRVG0_Y.Y2ref;
    yVELPID.setpoint = (float)yPOSPID.calculate(CountsToAngle(yEncoderCount)) + YRVG0_Y.Y2ref;

    // Calculate motor actions from velocity PID outputs, converting from percent to microseconds (pulse width)
    xAction = (float)xVELPID.calculate(xSpeed) * 10;
    yAction = (float)yVELPID.calculate(ySpeed) * 10;
}
