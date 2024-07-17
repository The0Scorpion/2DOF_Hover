/*
 * PID Controller Class for ESP32
 * Created: 14/11/2023
 * Updated by Scorpion
 * Last update 20/12/2023
*/
#pragma once
class PIDController {
public:
    float setpoint;
    PIDController() {}

    void init(float kp, float ki, float kd, float setpoint, float minoutput, float maxoutput) {
        this->kp = kp;
        this->ki = ki;
        this->kd = kd;
        this->setpoint = setpoint;
        this->minoutput = minoutput;
        this->maxoutput = maxoutput;
        reset();
    }

    void reset() {
        prev_error = 0.0;
        integral = 0.0;
        prev_filter_out = 0.0;
        prevdrev = 0.0;
        lastTime = micros();
        output = 0.0;
    }

    double calculate(float current_state) {
        uint64_t currentTime = micros();
        double dt = (double)(currentTime - lastTime) / 1000000.0; // calculate dt
        double error = setpoint - current_state; //calculate error

        // proportional action
        float proportional = kp * error;

        // integral action clamping method
        if (!((output == maxoutput && error > 0) || (output == minoutput && error < 0))) {
            integral += ki * error * dt;
        }

        // derivative action
        float derivative = kd * (error - prev_error) / dt;
        float filter_der = (1 / (2 * RC + dt)) * (dt * derivative + dt * prevdrev - (dt - 2 * RC) * prev_filter_out);

        prev_filter_out = filter_der;
        prevdrev = derivative;
        lastTime = currentTime;
        prev_error = error;
        output = proportional + integral + filter_der;

        // clamp output to min and max
        if (output > maxoutput) output = maxoutput;
        if (output < minoutput) output = minoutput;

        return output;
    }

private:
    float kp;
    float ki;
    float kd;
    
    uint64_t lastTime;
    float prev_error;
    float integral;
    float prev_filter_out;
    float RC = 0.1;
    float prevdrev;
    float output;
    float minoutput;
    float maxoutput;
};

// Usage example
PIDController xPOSPID;
PIDController xVELPID;
PIDController yPOSPID;
PIDController yVELPID;
