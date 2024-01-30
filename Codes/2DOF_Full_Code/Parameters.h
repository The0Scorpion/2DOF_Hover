//This File has all the contol paramters for the system
//Most of these are to be changed

#define PPR 8000
#define pre 20
#define NoP  8

#define maxMicros 2000
#define minMicros 1000
#define maxDeltaMicros 500
int Opratingpoint= 1500;
#define StartPower 1600
unsigned int Sampling_time = 5000;
int gl_windup_limit = 300;
double IMU_FusionPrio = 0;

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
byte PID_Running = 1, ESC_Running = 1;
float xAction, yAction;
