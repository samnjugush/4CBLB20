function [freq,xf]=rm_fft2(t,xt,iwindow)

% sampling frequency (assumes equidistantly spaced data)
ts=mean(diff(t));
fs=1/ts;

% number of data points;
nfft=max(size(t));

% observation interval
T=t(end)+ts;

% frequency resolution
df=1/T;

% minimum frequency
fmin=-nfft/2*df;

% maximum frequency
fmax=(nfft/2-1)*df;

% frequency axis
freq=fmin:df:fmax;

if iwindow==1
% apply windowing
    w=sqrt(8/3)*vonhann(nfft);
    w=w';
    xt=w.*xt;
end

% fourier transform
xf=(fftshift(fft(xt)))*ts;
