/*
 * Header file with all the control parameters for the system
 * Credit: Scorpion
 * Created: 12/10/2023
 * Last update: 5/3/2024
 */
#pragma once

//#define OnlineControl
#define CascadedPIDControl
#include <ArduinoJson.h>
// Defines the wiring for each major component
#define X_ENCODER_PIN_A 32
#define X_ENCODER_PIN_B 33
#define Y_ENCODER_PIN_A 34
#define Y_ENCODER_PIN_B 35
#define FrontMotorPIN 17
#define RightMotorPIN 16
#define BackMotorPIN 27
#define LeftMotorPIN 26

// IoT Parameters
#define ResetTime 60 //seconds without iot activity to reset after
#define Send_Period 300 // Unit is ms
unsigned long lastsent = 0,lastAquired;
#define SendingQoS 0
#define ReceiveQoS 0
#define SendingBufferSize 4096 // Adjust the size according to your needs
StaticJsonDocument<SendingBufferSize> SendingDoc; 
StaticJsonDocument<256> DataPacket;
StaticJsonDocument<512> ParamterObject;
char SendingString[SendingBufferSize];  // Adjust the size according to your needs
bool Readytosend = false;  // Send flag, set this to true when ready to send the buffer
// Rest in Secrets.h

int counta = 0;
int failcount = 0, failLimit = 200;
int failed_Trials = 0, fail_TrailLimit = 4;
int maxStartupSamples = 1000, RunSamples = 2000;


// Error corrections for IMU
#define IMU_XACC_Error  -0.02
#define IMU_YACC_Error   0.00
#define IMU_ZACC_Error  -0.03
#define IMU_XDOT_Error  1.14 * PI / 180
#define IMU_YDOT_Error  -1.87 * PI / 180
float xDotIMU, yDotIMU;
float AccX, AccY, AccZ;
float xPosIMU = 0;
float yPosIMU = 0;

// Main loop parameters
double xSpeed, ySpeed; // Feedback speeds for control (after Fusion)
unsigned int Sampling_time = 5000;
double IMU_FusionPrio = 0.02;
byte ControllerRunning = 1, ESC_Running = 1;
float xAction, yAction;
byte Work = 0;

// Parameters for PID control
float xposkp = 8;   // Proportional gain for X position
float xposki = 0.5; // Integral gain for X position
float xposkd = 0;   // Derivative gain for X position
float xvelkp = 15;  // Proportional gain for X velocity
float xvelki = 1;   // Integral gain for X velocity
float xvelkd = 0;   // Derivative gain for X velocity

float yposkp = 10;  // Proportional gain for Y position
float yposki = 0.5; // Integral gain for Y position
float yposkd = 0;   // Derivative gain for Y position
float yvelkp = 13;  // Proportional gain for Y velocity
float yvelki = 1;   // Integral gain for Y velocity
float yvelkd = 0;   // Derivative gain for Y velocity

float xposSet = 0;  // Setpoint for X position
float yposSet = 0;  // Setpoint for Y position
float xvelSet = 0;  // Setpoint for X velocity
float yvelSet = 0;  // Setpoint for Y velocity
float PositionLoopSat = 2; // Saturation limit for position loop

// Limits for PID parameters and setpoints
float xposkpLimit = 12;  // Limit for X position proportional gain
float xposkiLimit = 5;   // Limit for X position integral gain
float xposkdLimit = 5;   // Limit for X position derivative gain
float xvelkpLimit = 30;  // Limit for X velocity proportional gain
float xvelkiLimit = 5;   // Limit for X velocity integral gain
float xvelkdLimit = 5;   // Limit for X velocity derivative gain

float yposkpLimit = 10;  // Limit for Y position proportional gain
float yposkiLimit = 5;   // Limit for Y position integral gain
float yposkdLimit = 5;   // Limit for Y position derivative gain
float yvelkpLimit = 20;  // Limit for Y velocity proportional gain
float yvelkiLimit = 5;   // Limit for Y velocity integral gain
float yvelkdLimit = 5;   // Limit for Y velocity derivative gain

float xposSetLimit = 0.3; // Limit for X position setpoint
float yposSetLimit = 0.3; // Limit for Y position setpoint

// Parameters for ESCs and motors
#define xmaxMicros 1700
#define xminMicros 1100
#define xmaxDeltaMicros 300
#define xmaxDeltaMicrosStart 400
int xOpratingpoint = 1400;

#define ymaxMicros 1700
#define yminMicros 1100
#define ymaxDeltaMicros 300
#define ymaxDeltaMicrosStart 350
int yOpratingpoint = 1400;

// Encoder Parameters
#define PPR 8000   // Counts per revolution for encoders (PPR*4)
#define pre 20     // Prescaler for hardware timers
#define NoP  8     // Number of counts for rolling average for encoder velocity calculation
unsigned long lastMqttMessageTime;
volatile long xEncoderCount = 0, yEncoderCount = 0;
unsigned long xLastSpeedTime, yLastSpeedTime;
uint64_t SpeedUpdateTime = 20000;
hw_timer_t *SpeedUpdateTimer = NULL, *IntTimer = NULL;
volatile int64_t xNext = 0, yNext = 0;
volatile double xDelta[NoP], yDelta[NoP];
