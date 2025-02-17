function wt=rm_hann(t,xt)

% transform input arguments into vectors
if size(t,2)>size(t,1)
    t=t';
end

if size(xt,2)>size(xt,1)
    xt=xt';
end

n=max(size(t));

T=t(n)-t(1);

wt=zeros(n,1);
for i=1:n,
    wt(i)=1.633*(0.5+0.5*cos(2*pi*t(i)/T+pi))*xt(i);
end