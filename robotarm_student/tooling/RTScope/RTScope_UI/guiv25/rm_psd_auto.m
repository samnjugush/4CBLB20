function [freq,psd_auto]=rm_psd_auto(t,ut,idx,imode,iframe,iwindow)

fs=1/mean(diff(t));

[freq,Pxx]=autopowerspectrum(ut,fs,idx,imode,iframe,iwindow);
psd_auto=abs(Pxx)';
