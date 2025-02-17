function [freq,Pxy,Txy,Cxy]=crosspowerspectrum(x,y,fs,imode,iframe)

global gcPxx gcPyy gcPxy;

INSTANTANEOUS=0;
AVERAGING=1;

nfft=length(x);

if iframe>0
    % make sure x and y are a column vectors
    x=x(:);
    y=y(:);

    % hanning window
    window=vonhann(nfft);

    index=1:nfft;

    % scaling factor
    if imode==INSTANTANEOUS
    	KMU=norm(window)^2;
    else
    	KMU=iframe*norm(window)^2;
    end

    % initialization
    if iframe==1 | imode==INSTANTANEOUS
    	gcPxx=zeros(nfft,1);
    	gcPyy=zeros(nfft,1);
    	gcPxy=zeros(nfft,1);
    end

    % apply window
%    xw=window.*(detrend(x(index)));
%    yw=window.*(detrend(y(index)));

    xw=window.*(x(index));
    yw=window.*(y(index));

    xf=fft(xw,nfft);
    yf=fft(yw,nfft);

    Xx=abs(xf).^2;
    Yy=abs(yf).^2;
    Xy=yf.*conj(xf);

    gcPxx=gcPxx+Xx;
    gcPyy=gcPyy+Yy;
    gcPxy=gcPxy+Xy;
end

% select first half
if ~any(any(imag(x)~=0))
	if rem(nfft,2)
		select=[1:(nfft+1)/2];
	else
		select=[1:nfft/2+1];
	end
else
	select=1:nfft;
end

if iframe>0
    Pxx=gcPxx(select);
    Pyy=gcPyy(select);
    Pxy=gcPxy(select);

    Txy=Pxy./Pxx;
    Cxy=(abs(Pxy).^2)./(Pxx.*Pyy);

    Pxy=Pxy/KMU;
else
    Txy=[];
    Cxy=[];
    Pxy=[];
end

freq=(select-1)'*fs/nfft;
