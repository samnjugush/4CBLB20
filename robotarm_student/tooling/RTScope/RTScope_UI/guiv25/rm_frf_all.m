function [freq,frf_mod,frf_phs,psd_cross,coh]=rm_frf_all(t,ut,yt,imode,iframe)

fs=1/mean(diff(t));

[freq,Pxy,Txy,Cxy]=crosspowerspectrum(ut,yt,fs,imode,iframe);

frf_mod=abs(Txy);
frf_phs=angle(Txy);
psd_cross=abs(Pxy);
coh=abs(Cxy);