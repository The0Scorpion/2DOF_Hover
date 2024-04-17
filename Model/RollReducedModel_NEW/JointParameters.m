%upper joint parameters
mass_u = 2.024; %kg
g = 9.81; %m/s^2
J_u = 0.049103; %kg.m^2
L_u = 0.227293; %m
L_cg_u = 0.066301; %m
B_u = 0.5;  

%lower joint parameters
mass_l = 2.495; %kg
J_l = 0.071440709; %kg.m^2
L_l = 0.223793; %m
L_cg_l = 0.102366; %m
B_l = 0.5;

RollYStartThrust = 40; %starting thrust in percent power
RollYMotorSaturation = 30; %saturation limits for motor

PitchXStartThrust = 50; %starting thrust in percent power
PitchXMotorSaturation = 50; %saturation limits for motor


PositionLoopSat = 1; %saturation limits for Position PID

%joint limits
RollLowerLimit = -0.33;
RollUpperLimit = 0.4;
PitchLowerLimit = -0.37;
PitchUpperLimit = 0.27;

EncoderDelay = 0.020;
ActuatorDelay = 0.005;
%motor + propeller setting
k = 0.13;
b = 0.1;

%% PID Parameters
ixposkp = 12 ;       %12
ixposki = 1;         %1
ixposkd = 0;         %0
ixvelkp = 30;        %30
ixvelki = 5;         %5
ixvelkd = 0;         %0
iyposkp = 10;        %10
iyposki = 1;         %1
iyposkd = 0;         %0
iyvelkp = 20;        %20
iyvelki = 5;         %5
iyvelkd = 0;         %0