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
int failcount = 0, failLimit = 600, failed_Trials = 0, fail_TrailLimit = 2;

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





//Main loop Parameters
double xSpeed, ySpeed; //Feedback speeds for control (after Fusion)
//unsigned long PIDLastTime = 0;
unsigned int Sampling_time = 5000;
double IMU_FusionPrio = 0.02;
byte PID_Running = 1, ESC_Running = 1;
float xAction, yAction;
byte Work = 1;

//PID Parameters
/*
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
*/

//PID Parameters

//Parameters for ESCs and motors
#define xmaxMicros 1700
#define xminMicros 1100
#define xmaxDeltaMicros 300
#define xmaxDeltaMicrosStart 300
int xOpratingpoint = 1400;

#define ymaxMicros 1700
#define yminMicros 1100
#define ymaxDeltaMicros 300
#define ymaxDeltaMicrosStart 350
int yOpratingpoint = 1400;
/*
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
*/

//Normal Mode
byte load = 0; //if set then the parameters are loaded from EEPROM on first run
byte save = 0; //if set then the parameters are saved to EEPROM on the first run
float xposkp = 8 ; //12
float xposki = 0.5;  //1
float xposkd = 0;
float xvelkp = 15; //30
float xvelki = 1;  //5
float xvelkd = 0;
float yposkp = 10; //10
float yposki = 0.5; //1
float yposkd = 0;
float yvelkp = 13; //20
float yvelki = 1; //5
float yvelkd = 0;

float xposSet = 0;
float yposSet = 0;
float xvelSet = 0;
float yvelSet = 0;
float PositionLoopSat = 2;

//Limits
float xposkpLimit = 12 ; //12
float xposkiLimit = 5; //1
float xposkdLimit = 5;
float xvelkpLimit = 30; //30
float xvelkiLimit = 5; //5
float xvelkdLimit = 5;
float yposkpLimit = 10; //10
float yposkiLimit = 5; //1
float yposkdLimit = 5;
float yvelkpLimit = 20; //20
float yvelkiLimit = 5; //5
float yvelkdLimit = 5;
float xposSetLimit = 0.3;
float yposSetLimit = 0.3;

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
Servo Fmotor, Rmotor, Bmotor, Lmotor;
