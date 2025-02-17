function [freq,frf_phs]=rm_frf_phs(t,xt,yt)

[freq,Huy,Suy,Cuy]=rm_frf_all(t,xt,yt);
frf_phs=angle(Huy);
