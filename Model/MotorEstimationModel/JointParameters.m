Current_Thrust = 50;
Input_Power = 1;
%upper joint parameters
mass_u = 1.821; %kg
g = 9.81; %m/s^2
J_u = 0.045179; %kg.m^2
L_u = 0.227293; %m
L_cg_u = 0.066582; %m

%lower joint parameters
mass_l = 2.292; %kg
J_l = 0.065561919; %kg.m^2
L_l = 0.2225794; %m
L_cg_l = 0.101389; %m

% to be determined
a = 0;  
b = 1;
c = 1;
k = 1;
B_u = 0;
B_l = 0.05;
