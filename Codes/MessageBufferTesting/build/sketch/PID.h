#line 1 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\PID.h"
/*
 * PID Controller Class for ESP32
 * Created: 14/11/2023
 * Updated by Scorpion
 * Last update: 20/12/2023
 */
#pragma once

class PIDController {
public:
    float setpoint;

    PIDController() {}

    // Initialize PID controller with parameters
    void init(float kp, float ki, float kd, float setpoint, float minoutput, float maxoutput) {
        this->kp = kp;
        this->ki = ki;
        this->kd = kd;
        this->setpoint = setpoint;
        this->minoutput = minoutput;
        this->maxoutput = maxoutput;
        reset();
    }

    // Reset PID controller
    void reset() {
        prev_error = 0.0;
        integral = 0.0;
        prev_filter_out = 0.0;
        prevdrev = 0.0;
        lastTime = micros();
        output = 0.0;
    }

    // Calculate PID output based on current state
    double calculate(float current_state) {
        uint64_t currentTime = micros();
        double dt = (double)(currentTime - lastTime) / 1000000.0; // Calculate dt
        double error = setpoint - current_state; // Calculate error

        // Proportional action
        float proportional = kp * error;

        // Integral action with clamping method
        if (!((output == maxoutput && error > 0) || (output == minoutput && error < 0))) {
            integral += ki * error * dt;
        }

        // Derivative action
        float derivative = kd * (error - prev_error) / dt;
        float filter_der = (1 / (2 * RC + dt)) * (dt * derivative + dt * prevdrev - (dt - 2 * RC) * prev_filter_out);

        prev_filter_out = filter_der;
        prevdrev = derivative;
        lastTime = currentTime;
        prev_error = error;
        output = proportional + integral + filter_der;

        // Clamp output to min and max
        if (output > maxoutput) output = maxoutput;
        if (output < minoutput) output = minoutput;

        return output;
    }

private:
    float kp; // Proportional gain
    float ki; // Integral gain
    float kd; // Derivative gain
    float minoutput; // Minimum output limit
    float maxoutput; // Maximum output limit

    uint64_t lastTime; // Last time for calculating dt
    float prev_error; // Previous error
    float integral; // Integral term
    float prev_filter_out; // Previous filtered derivative output
    float prevdrev; // Previous derivative
    float output; // PID output
    float RC = 0.1; // Filter parameter
};

// Usage example
PIDController xPOSPID;
PIDController xVELPID;
PIDController yPOSPID;
PIDController yVELPID;
