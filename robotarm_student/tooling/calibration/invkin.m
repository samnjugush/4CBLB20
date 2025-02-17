function [Psi, Phi, Theta] = invkin(x, y, z)
%% function to determine the angle of the motors for the right x,y,z position
%% Psi is angle R motor in rad
%% Phi is angle X motor in rad
%% Theta is angle Z motor in rad
%% x [mm] is perpendicular to the conveyer
%% y [mm] is in the direction of the conveyer
%% Z [mm]is the height from the conveyer

% These offsets are for the homing position (160, 0, 99) w.r.t. the middle
% of the robotarm on the table
r_offset = 0;
x_offset = -0.2551;
z_offset = -0.6150;

mm  = 10^(-3);
L1  = 130*mm;
L2a = 120*mm;
L2b = 65*mm;
L2  = L2a+L2b;
L3  = 80*mm;
L4  = 130*mm;
ED  = 165*mm;
OE  = 81*mm;

%% measurements
length_head = 45*mm;              % length of the vacuum head
height_conveyer = 0*mm;           % height of the conveyer
X0 = 0*mm;                        % distance center robot to conveyer
Y0      =   0;                    % distance center plate to grid

%% Determine the x, y and z coordinates of the grid in [m]
Y = Y0+y*mm;
X = X0+x*mm;
Z = length_head+height_conveyer+z*mm;

%% Psi - motor R
R   =   sqrt(X^2+Y^2);
Psi =   atan2(Y,X);

%% Theta - motor Z
L_DB    = sqrt(R^2+(OE+ED-Z)^2);
H_GDB   = asin(R/L_DB);
H_CDB   = acos((L1^2+L_DB^2-L2^2)/(2*L1*L_DB));
Theta   = H_CDB+H_GDB-.5*pi;

%% PHI - motor X
H_DBC   = acos((L2^2+L_DB^2-L1^2)/(2*L2*L_DB));
H_DCB   = pi-H_CDB-H_DBC;
L_DF    = sqrt(L1^2+L2a^2-2*L1*L2a*cos(H_DCB));
H_CDF   = acos((L1^2+L_DF^2-L2a^2)/(2*L1*L_DF));
H_EDF   = H_CDB+H_GDB-H_CDF;
L_EF    = sqrt(L_DF^2+ED^2-2*L_DF*ED*cos(H_EDF));
H_DEF   = acos((L_EF^2+ED^2-L_DF^2)/(2*L_EF*ED));
Phi_2   = acos((L3^2+L_EF^2-L4^2)/(2*L3*L_EF));
Phi_1   = 0.5*pi-H_DEF;
Phi     = Phi_1+Phi_2;

%% Final results of the angles
Psi     = Psi+r_offset;  % offset R robot 1
Phi     = pi/2-Phi+x_offset; % offset X robot 1
Theta   = Theta+z_offset; % offset Z robot 1
end
