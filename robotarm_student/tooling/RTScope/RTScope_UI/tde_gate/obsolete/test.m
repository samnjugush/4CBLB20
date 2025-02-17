clear mex;

CALL_TDE_START_ACQ=1;
CALL_TDE_STOP_ACQ=2;
CALL_TDE_CHECK_DATA=3;
CALL_TDE_SAY_READY=4;
CALL_TDE_GET_DATA=5;
CALL_TDE_GET_INFO=6;
CALL_TDE_TRIGGER_ON=7;
CALL_TDE_TRIGGER_OFF=8;
CALL_TDE_CHECK_CLIPPING=9;
CALL_TDE_SET_ADC_STATE=10;
CALL_TDE_GET_ADC_STATE=11;
CALL_TDE_SET_ENC_STATE=12;
CALL_TDE_GET_ENC_STATE=13;
CALL_TDE_SET_DAC_STATE=14;
CALL_TDE_GET_DAC_STATE=15;

CALL_EE_GET_NADC    =   101;
CALL_EE_GET_NDAC    =   102;
CALL_EE_GET_NENC    =   103;
CALL_EE_GET_NPWM    =   104;
CALL_EE_GET_NDIN    =   105;
CALL_EE_GET_NDOUT   =   106;

nadc = tde_gate(CALL_EE_GET_NADC)
ndac = tde_gate(CALL_EE_GET_NDAC)
nenc = tde_gate(CALL_EE_GET_NENC)
npwm = tde_gate(CALL_EE_GET_NPWM)
ndin = tde_gate(CALL_EE_GET_NDIN)
ndout = tde_gate(CALL_EE_GET_NDOUT)


[maxchan maxframe]=tde_gate(CALL_TDE_GET_INFO);

maxframe

nsamp=min(1024,maxframe);

msstep=1;
%tde_gate(CALL_TDE_START_ACQ,msstep,nsamp);

% isignal=0;
% itype=1;
% ilevel=-0.5;
% preroll=0;
% tde_gate(CALL_TDE_TRIGGER_ON,isignal,itype,ilevel,preroll,nsamp);

tde_gate(CALL_TDE_GET_ADC_STATE,0)
tde_gate(CALL_TDE_GET_DAC_STATE,0)
tde_gate(CALL_TDE_SET_ADC_STATE,0,0)
tde_gate(CALL_TDE_GET_ADC_STATE,0)

for i=1:20,
    
    while tde_gate(CALL_TDE_CHECK_DATA)
        pause(0.1);
    end
    
    disp('Clipping')
    tde_gate(CALL_TDE_CHECK_CLIPPING)

    disp(i);
    A=tde_gate(CALL_TDE_GET_DATA,nsamp*maxchan*2);
    plot(A');
    title(['framenumber=',num2str(i)])
    shg;
    
    tde_gate(CALL_TDE_SAY_READY);

    if i==5
	disp('Now???');
	tde_gate(CALL_TDE_TRIGGER_OFF);
    end
end

tde_gate(CALL_TDE_STOP_ACQ);

    
    

    
    
    