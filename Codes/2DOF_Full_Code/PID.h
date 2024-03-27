/*
 * Submodule That contains All the PID bare bones stuff
 * Credit: Veronia 
 * Created: 14/11/2023
 * Updated by Scorpion
 * Last update 20/12/2023
*/

//All the PID bare bones stuff

//PID struct
typedef struct {
  float kp;
  float ki;
  float kd;
  float setpoint;
  float lastTime;
  float prev_error;
  float integral;
  float prev_filter_out;
  float RC = 0.1;
  float prevdrev;
  float output;
  int minoutput;
  int maxoutput;
} PIDController;

//initialize the PID struct (constructor like)
void initializePID(PIDController *pid, float kp, float ki, float kd, float setpoint, int minoutput, int maxoutput) {
  pid->kp = kp;
  pid->ki = ki;
  pid->kd = kd;
  pid->setpoint = setpoint;
  pid->lastTime = 0.0;
  pid->prev_error = 0.0;
  pid->integral = 0.0;
  pid->minoutput = minoutput;
  pid->maxoutput = maxoutput;
}

double calculatePID(PIDController *pid, float current_state) {
  //to Check
  int currentTime = micros();
  float dt = (currentTime - pid->lastTime) / 1000000.0; // calculate dt
  float error = pid->setpoint - current_state; //calculate error

  //proportional action
  float proportional = pid->kp * error;

  //integral action clamping method
  if (!((pid->output >= pid->maxoutput && error > 0) || (pid->output <= pid->minoutput && error < 0))) {
    pid->integral += pid->ki * error * dt ;//I*Ts
  }
  
  //derivative action
  float derivative = pid->kd * (error - pid->prev_error) / dt ;
  float filter_der = (1 / (2 * pid->RC + dt)) * (dt * derivative + dt * pid->prevdrev - (dt - 2 * pid->RC) * pid->prev_filter_out);
  
  pid->prev_filter_out = filter_der;
  pid->prevdrev = derivative;
  pid->lastTime = currentTime;
  pid->prev_error = error;
  //pid->output = proportional + pid->integral + filter_der;
  pid->output = proportional + pid->integral;
  pid->output = fmax(fmin(pid->output, pid->maxoutput), pid->minoutput);
  return pid->output;
}

void resetPID(PIDController *pid) {
  pid->prev_error = 0.0;
  pid->lastTime = 0.0;
  pid->integral = 0.0;
  pid->prev_filter_out = 0;
  pid->prevdrev = 0;
  pid->lastTime = 0;
  pid->prev_error = 0;
}
