function [freq,xf_mod,xf_phs]=rm_fft_all(t,xt,iwindow)

[freq,xf]=rm_fft2(t,xt,iwindow);

xf_mod=abs(xf);
xf_phs=angle(xf);