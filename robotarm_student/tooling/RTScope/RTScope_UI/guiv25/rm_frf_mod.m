function [freq,frf_mod]=rm_frf_mod(t,ut,yt)

[freq,Huy,Suy,Cuy]=rm_frf_all(t,ut,yt);
frf_mod=abs(Huy);
