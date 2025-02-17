function [w]=vonhann(N)

idx=(0:1:N-1)';
w=0.5-0.5*cos(2*pi*idx/N);

