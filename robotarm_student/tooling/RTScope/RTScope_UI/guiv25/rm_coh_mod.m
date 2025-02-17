function [freq,coh_mod]=rm_coh_mod(t,ut,yt)

[freq,Huy,Suy,Cuy]=rm_frf_all(t,ut,yt);
coh_mod=abs(Cuy);
