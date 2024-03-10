/*
   header file with all the control paramters for the system
   Credit: Scorpion
   Created: 12/10/2023
   Last update:5/3/2024
*/

//Defines Test cases
//#define X_test 1
#define Y_test 1

/*
 * if Test_Mode = 1 ==> Ramp
 *    Test_Mode = 2 ==> Step
 */
#define Ramp 1
#define Step 2 
byte Test_Mode = Ramp;
unsigned char StepPercent = 20;
unsigned int RampValue = 0;

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
#define Send_Period 50 //unit is ms
unsigned long lastsent = 0;
//Rest in Secrets.h

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
#define maxMicros 2000
#define minMicros 1000
#define maxDeltaMicros 500
#define StartPower 1500
int Opratingpoint = 1500;


//Main loop Parameters
double xSpeed, ySpeed; //Feedback speeds for control (after Fusion)
unsigned long PIDLastTime = 0;
unsigned int Sampling_time = 50000;
double IMU_FusionPrio = 0;
byte Test_Running = 1, ESC_Running = 1;
float xAction, yAction;

//PID Parameters
float ixposkp = 22;
float ixposki = 0.1;
float ixposkd = 0.1;
float ixvelkp = 7;
float ixvelki = 0.0001;
float ixvelkd = 0.4;
float iyposkp = 20;
float iyposki = 0.1;
float iyposkd = 1.1;
float iyvelkp = 5;
float iyvelki = 0.001;
float iyvelkd = 1.4;
int ixposSet = 0;
int iyposSet = 0;
int ixvelSet = 0;
int iyvelSet = 0;


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
