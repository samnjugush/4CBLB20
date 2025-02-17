function [freq,xf]=rm_fft(t,xt)

% sampling frequency (assumes equidistantly spaced data)
ts=mean(diff(t));
fs=1/ts;

% number of data points
nfft=max(size(xt));
if is_even(nfft)
    nfft=nfft-1;
end
n=(nfft-1)/2;

% measuring time
T=t(nfft)-t(1);

% fourier transform
xf=(fftshift(fft(xt(1:nfft))))*ts;

% frequency axis
freq=zeros(nfft,1);
for i=1:nfft,
  freq(i)=(-n+i-1)/T;
end
