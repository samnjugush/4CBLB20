%
% usage: diet_ol
%
% diet_ol prepares the open loop frf from sens2ol for import in diet
% and starts diet. Choose '7/Frequency Response Function (FRF)' and 
% press OK. This is especially useful if the open loop frf was measured
% with a fixed gain controller. Use only after sens2ol.
% 

global frf hz
frf=frf_ol;
hz=freq;
diet
