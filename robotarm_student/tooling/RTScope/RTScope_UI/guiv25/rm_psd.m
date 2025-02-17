function [freq,psd]=rm_psd(t,ut,yt)

% transform input arguments into vectors
if size(t,2)>size(t,1)
    t=t';
end

if size(ut,2)>size(ut,1)
    ut=ut';
end

if size(yt,2)>size(yt,1)
    yt=yt';
end

% sampling interval (assumes equidistantly spaced data)
%ts=t(2)-t(1);
ts=mean(diff(t);

% autocorrelation ut
tcorr=-max(t):ts:max(t);
tcorr=tcorr';

Ruy=xcorr(ut,yt,'unbiased');
nRuy=max(size(Ruy));
nstart=(nRuy-1)/2+1;

% autopowerspectrum ut
wRuy=rm_hann(tcorr(nstart:end),Ruy(nstart:end));
[freq,Suy]=rm_fft(tcorr(nstart:end),wRuy);

nfft=max(size(freq));
n=(nfft-1)/2;

% one-sided power spectral density
freq=freq(n+1:end);
psd=Suy(n+1:end);
