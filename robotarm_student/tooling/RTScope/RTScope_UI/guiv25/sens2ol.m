function [frf_ol, freq] = sens2ol(qadscope_data_file)

%
% usage: [frf_ol, freq] = sens2ol(qadscope_data_file)
%
% sens2ol assumes that the data file contains a sensitivity frf measurement
% from ch0 (input) to ch1 (output). The sensitivity is transformed into the
% open loop frf as frf_ol at frequencies freq in Hz.
%
% see also: diet_ol
%

global frf_ol freq;

cmd=sprintf('load %s',qadscope_data_file);
eval(cmd);

if ~exist('adc_ch0_adc_ch1_frf_mod')
    error('sens2ol reports: no frf data!!!')
end

freq=freq_frf;

sens=adc_ch0_adc_ch1_frf_mod.*exp(j*adc_ch0_adc_ch1_frf_phs);
frf_ol=1./sens-1;

subplot(2,1,1);
semilogx(freq,20*log10(abs(frf_ol)));
grid;
subplot(2,1,2)
semilogx(freq,angle(frf_ol)/pi*180);
grid
shg;

