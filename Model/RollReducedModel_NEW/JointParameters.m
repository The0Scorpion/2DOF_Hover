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

CurrThrust = 60; %starting thrust in percent power
MotorSaturation = 25; %saturation limits for motor

PositionLoopSat = 1; %saturation limits for Position PID

EncoderDelay = 0.020;
ActuatorDelay = 0.005;
%motor + propeller setting
k = 0.13;
b = 0.1;