//This File has all the contol paramters for the system
//Most of these are to be changed

#define PPR 8000
#define pre 20
#define NoP  8

#define maxMicros 2000
#define minMicros 1000
#define maxDeltaMicros 200
int Opratingpoint= 1400;
#define StartPower 1600
unsigned int Sampling_time = 5000;
int gl_windup_limit = 300;
double IMU_FusionPrio = 0.1;

float ixposkp = 0.1;
float ixposki = 0.001;
float ixposkd = 0.001;
float ixvelkp = 0.1;
float ixvelki = 0.001;
float ixvelkd = 0.001;
float iyposkp = 0.1;
float iyposki = 0.001;
float iyposkd = 0.001;
float iyvelkp = 0.1;
float iyvelki = 0.001;
float iyvelkd = 0.001;
int ixposSet = 0;
int iyposSet = 0;
int ixvelSet = 0;
int iyvelSet = 0;
byte PID_Running = 1, ESC_Running = 1;
float xAction, yAction;
