function [freq,psd_cross]=rm_psd_cross(t,ut,yt)

[freq,Huy,Suy,Cuy]=rm_frf_all(t,ut,yt);
psd_cross=abs(Suy);
