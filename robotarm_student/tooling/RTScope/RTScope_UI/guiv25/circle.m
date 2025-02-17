function [re,im] = circle(cent_x,cent_y,radius,npoints)
% Replacement function for missing circle funtcion

if nargin == 0,
    cent_x	= 0;
    cent_y	= 0;
end;
if nargin <= 2,
    radius 	= 1;
end
if nargin <= 3,
    npoints = 200;
end


mag	= ones(npoints,1)*radius;
ph	= linspace(0,2*pi,npoints)';

radius=mag.*exp(ph.*(sqrt(-1)));
im=imag(radius) + cent_y;
re=real(radius) + cent_x;
