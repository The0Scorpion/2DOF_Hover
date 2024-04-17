/*
   header file with all the control paramters for the system
   Credit: Scorpion
   Created: 12/10/2023
   Last update:5/3/2024
*/

//Defines the wiring for each major comp
#define X_ENCODER_PIN_A 32
#define X_ENCODER_PIN_B 33
#define Y_ENCODER_PIN_A 34
#define Y_ENCODER_PIN_B 35
#define FrontMotorPIN 17
#define RightMotorPIN 16
#define BackMotorPIN 27
#define LeftMotorPIN 26

//IOT Parameters
#define Send_Period 60000 //unit is ms
unsigned long lastsent = 0;
//Rest in Secrets.h
int counta = 0;

//IMU Parameters and Variables
#define IMU_XACC_Error  -0.02
#define IMU_YACC_Error   0.00
#define IMU_ZACC_Error  -0.03
#define IMU_XDOT_Error  1.14 * PI / 180
#define IMU_YDOT_Error  -1.87 * PI / 180
float xDotIMU, yDotIMU;
float AccX, AccY, AccZ;
float xPosIMU = 0;
float yPosIMU = 0;

//Parameters for ESCs and motors
#define xmaxMicros 1700
#define xminMicros 1100
#define xmaxDeltaMicros 300
#define xmaxDeltaMicrosStart 550
int xOpratingpoint = 1400;

#define ymaxMicros 1700
#define yminMicros 1100
#define ymaxDeltaMicros 300
#define ymaxDeltaMicrosStart 500
int yOpratingpoint = 1400;

#define StartPower 1600




//Main loop Parameters
double xSpeed, ySpeed; //Feedback speeds for control (after Fusion)
//unsigned long PIDLastTime = 0;
unsigned int Sampling_time = 5000;
double IMU_FusionPrio = 0.2;
byte PID_Running = 1, ESC_Running = 1;
float xAction, yAction;

//PID Parameters
float ixposkp = 20 ; //12
float ixposki = 1;  //1
float ixposkd = 0;
float ixvelkp = 35; //30
float ixvelki = 5;  //5
float ixvelkd = 0;
float iyposkp = 10; //10
float iyposki = 1; //1
float iyposkd = 0;
float iyvelkp = 20; //20
float iyvelki = 5; //5
float iyvelkd = 0;

//Normal Mode
float xposkp = 10 ; //12
float xposki = 1;  //1
float xposkd = 0;
float xvelkp = 20; //30
float xvelki = 5;  //5
float xvelkd = 0;
float yposkp = 10; //10
float yposki = 1; //1
float yposkd = 0;
float yvelkp = 20; //20
float yvelki = 5; //5
float yvelkd = 0;

float ixposSet = 0;
float iyposSet = 0;
float ixvelSet = 0;
float iyvelSet = 0;
float PositionLoopSat=4;


//Encoder Parameters
#define PPR 8000 //Counts per rev for encoders (PPR*4)
#define pre 20 //Prescaler for hardware timers
#define NoP  8 //Number of counts for rolling average for encoder velocity calculation
volatile long xEncoderCount = 0, yEncoderCount = 0;
unsigned long xLastSpeedTime, yLastSpeedTime;
uint64_t SpeedUpdateTime = 20000;
hw_timer_t *SpeedUpdateTimer = NULL, *IntTimer = NULL;
volatile int64_t xNext = 0, yNext = 0;
volatile double xDelta[NoP], yDelta[NoP]; //[0,130,150,110]
