function [freq,Pxx]=autopowerspectrum(x,fs,idx,imode,iframe,iwindow)

global gPxx;

% transform x to single column format
[nr,nc]=size(x);
if nc>nr
    x=x';
end

% number of data points
nfft=max(size(x));

% observation interval
T=nfft*(1/fs);

% spectral resolution
df=1/T;

% frequency grid
select=1:nfft/2+1;
freq=(select-1)*df;

if iframe<=0
%   return empty matrix
    Pxx=[];
    return;
end
    
% apply windowing
w=ones(nfft,1);
if iwindow==1
    w=sqrt(8/3)*vonhann(nfft);
end
xw=w.*x;

% fourier transform
xf=fft(xw);

% power spectral density
psd=(abs(xf).^2)/nfft;

% not ok: what if several channels are computed... earlier results are lost
if iframe==1
%   initialize global memory (maximum 16 channels!)
    gPxx=zeros(nfft,16);
end

if imode==0
%   instantaneous mode
    gPxx(:,idx)=psd;
else
%   averaging mode
    gPxx(:,idx)=(iframe-1)/iframe*gPxx(:,idx)+psd/iframe;
end
Pxx=gPxx(select,idx);
