
function qadscope(is_simulink, ip)

% QADScope
% measuring instrument for the TUeDACS/1 QAD/AQI real-time data-acquisition interface
% (c) Rene' van de Molengraft, 2001-2004
% last update: October, 28th, 2002
%              June, 30th, 2003 : fixed range-dependent trigger level
%              July, 8th, 2003  : all globals in one structure
%              November, 24th, 2003: MAXFREQ (ql_defines) can be easily redefined (see also tdext!)
%              February, 6th, 2004: MAXFREQ (ql_globals) is now inherited from tdext (see tdext.h!)
%              March, 5th, 2004: added lowpass trigger functionlc
%              March, 10th, 2004: save/load command repaired
%				                  save-last-frame implemented
%              March, 16th, 2004: added busy indicators
%                                 implemented scope hold and freeze functions
%	           July, 28th, 2004: separated qadscope gui from tdext via use of shared memory ipc
%	           October, 24th, 2004: create frequency range from user argument
%              November, 15th, 2004: added cumulative autopowerspectrum
%              December, 5th, 2004: added hoh selection in generator
%	           January, 31th, 2005: added energy spectral density, power spectrum, fixed scope memory,
%			        fixed timing inaccuracy (use nominal clock instead of real clock)
%	           March, 11th, 2005: added openloop (rtscope only)
%	           May, 25th, 2005: startqs deamon, obsolete
%	           October, 12th, 2004: added support for 4 TUeDACS/1 devices

% clear memory
%clear all;

% clear previously used mex-files
clear mex;

% globals
global g g2 data xgui;

% get structure with defined macros
def=qs_defines;

[g, g2, data]=qs_globals;
xgui=guistate;

% wait some time to let the shm task in the engine start up...
%pause(3);

% this version is exclusively for use with Simulink
is_simulink=1; % 2 virtual qad's
for i=1:2,
    g.QS_AQI(i)=0;
end
g.QS_IS_SIMULINK=1;
g.QS_IP=ip;
g.QS_NDEVS=2;

% current scope
g.QS_SCOPE_ID=1;

% initialize frf-signal selection
g.QS_IN=1;
g.QS_OUT=2;

% two scopes available in this version
g.QS_SCOPES=[1 2];
g.QS_MAXSCOPE=max(size(g.QS_SCOPES));

% no exit yet, not running yet
g.QS_EXIT=0;
g.QS_RUNNING=0;
% no gui yet
g.QS_GUI_OPEN=0;
% no file being loaded...
g.QS_LOADING=0;

% get max dimensions
[g.QS_MAXCHAN g.QS_MAXFRAME]=tde_gate_m(def.CALL_TDE_GET_INFO, g.QS_IP);

% initialize scope data
g.QS_SCOPE_CHAN=zeros(g.QS_MAXSCOPE,2*g.QS_MAXCHAN);
g.QS_SCOPE_HDL=zeros(g.QS_MAXSCOPE);
g.QS_SCOPE_TYPE=ones(g.QS_MAXSCOPE,1);
g.QS_SCOPE_SCALE=ones(g.QS_MAXSCOPE,1);
g.QS_SCOPE_DOFRF=zeros(g.QS_MAXSCOPE,1);
g.QS_SCOPE_MEM=zeros(g.QS_MAXSCOPE,1);
g.QS_SCOPE_MEM_XDAT=zeros(g.QS_MAXSCOPE,g.QS_MAXFRAME+1);
g.QS_SCOPE_MEM_LDAT=zeros(g.QS_MAXSCOPE,1);
g.QS_SCOPE_MEM_YDAT=zeros(g.QS_MAXSCOPE*g.QS_MAXCHAN*2,g.QS_MAXFRAME+1);
g.QS_SCOPE_MEM_IDAT=zeros(g.QS_MAXSCOPE*g.QS_MAXCHAN*2,1);
g.QS_SCOPE_FREEZE=zeros(g.QS_MAXSCOPE,1);
g.QS_SCOPE_XBAK=zeros(g.QS_MAXSCOPE,2);

g.QS_COLOR=[def.LCLR_BLACK; def.LCLR_BLUE; def.LCLR_GREEN; def.LCLR_RED; def.LCLR_GREY; def.LCLR_CYAN; def.LCLR_PURPLE; def.LCLR_BROWN];
g.QS_COLOR=[g.QS_COLOR; 0.5*g.QS_COLOR];

% default trigger settings
g.QS_TRIG_SIGNAL=0;
g.QS_TRIG_TYPE=0;
g.QS_TRIG_PREROLL=1;
g.QS_TRIG_RELFREQ=2;

% possible trigger levels (percentage of +-2.5 V)
% [100%, 50%, 25%, 10%, 5%, 1%, 0.1%, 0%, -0.1%, -1%, -5%, 10%, 25%, 50%, 100%];
g.QS_TLEVEL=[2.5, 1.25, 0.625, 0.25, 0.125, 0.025, 0.0025, 0, -0.0025, -0.025, -0.125, -0.25, -0.625, -1.25, -2.5];
g.QS_TRIG_LEVEL=(max(size(g.QS_TLEVEL))-1)/2+1;
g.QS_TSCALE=[4.0, 2.0, 0.8, 0.4, 0.2, 0.08, 0.04, 1.0];

% possible preroll values (percentage of frame length)
% [0%, 5%, 10%, 20%, 30%, 40%, 50%];
g.QS_TPREROLL=[0, 0.05, 0.1, 0.2, 0.3, 0.4, 0.5];

% possible trigger relfreq values (percentage of sampling rate)
g.QS_TRELFREQ=[0.5, 0.4, 0.3, 0.2, 0.1, 0.05, 0.01, 0.005, 0.001];

% autocreate frequency range

% get maxfreq
g.QS_MAXFREQ=tde_gate_m(def.CALL_TDE_GET_MAXFREQ, g.QS_IP);

% maximum sampling rate
fs_max=g.QS_MAXFREQ;

% number of rates
maxrates=30;

% initialize frequency array
fs=[];

% find series of integer rates
EPS=1e-12;
n=1;
nmax=10000;
for i=1:maxrates,
    while abs(fs_max/n-round(fs_max/n))>EPS & n<nmax
      n=n+1;
    end
    if ( (fs_max/n) >= 1 )
        fs=[fs fs_max/n];
        n=n+1;
    end
end
%fs
nrates=max(size(fs));
if nrates==0
%   integer rates could not be found...
    fs=fs_max;
    nrates=1;
end

% possible sampling rates
%g.QS_MSAMPRATE=[8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4];
g.QS_MSAMPRATE=fs;
g.QS_NRATES=nrates;

% default sampling rate selection (see g.QS_MSAMPRATE)
i=1;
while g.QS_MSAMPRATE(i)>g.QS_MAXFREQ,
    i=i+1;
end
g.QS_MEAS_RATE=i;

% downsampling factor
g.QS_NDOWN=max(round(g.QS_MAXFREQ/g.QS_MSAMPRATE(g.QS_MEAS_RATE))-1,0);
tde_gate_m(def.CALL_TDE_SET_NDOWN, g.QS_NDOWN, g.QS_IP);

% possible frame lengths
g.QS_MFRAMELEN=[64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384];
%list=[];
%for i=1:max(size(g.QS_MFRAMELEN))
%    if (g.QS_MFRAMELEN(i)/g.QS_MAXFREQ)>0.05 % Matlab cannot keep up if spectra need to be computed too fast
%        list=[list g.QS_MFRAMELEN(i)];
%    end
%end
%g.QS_MFRAMELEN=list;

% default frame length selection (see g.QS_MFRAMELEN)
%fix: g.QS_MEAS_LEN=3; %set this to 4096
g.QS_MEAS_LEN=1;

% number of samples in one frame
g.QS_NSAMP=min(g.QS_MFRAMELEN(g.QS_MEAS_LEN),g.QS_MAXFRAME);
tde_gate_m(def.CALL_TDE_SET_NSAMP, g.QS_NSAMP, g.QS_IP);

% reset engine trigger settings
g.QS_TRIGGER=1;
tde_gate_m(def.CALL_TDE_TRIGGER_ON,g.QS_TRIG_SIGNAL,g.QS_TRIG_TYPE,g.QS_TSCALE(8)*g.QS_TLEVEL(g.QS_TRIG_LEVEL),g.QS_TPREROLL(g.QS_TRIG_PREROLL),g.QS_TRELFREQ(g.QS_TRIG_RELFREQ),g.QS_NSAMP, g.QS_IP);

% switch off trigger
g.QS_TRIGGER=0;
tde_gate_m(def.CALL_TDE_TRIGGER_OFF, g.QS_IP);

% no window
g.QS_WINDOW=0;

% no aa-filter
g.QS_AACONFIG=0;

% possible numbers of frames
g.QS_MNUMFRAMES=[1000000000000 1000, 500, 400, 300, 200, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1];

% initialize adc ranges
g.QS_CHAN_SIGNAL=1;
% g.QS_CHAN_SIGNAL belongs to first device...
g.QS_CURRENT_DEVICE=1;
g.QS_MAXLEV=[10 5 2 1 0.5 0.2 0.1 2.5 1.0];

% adc and enc enable state (read from hardware!)
g.QS_CHAN_IN_STATE=zeros(2*g.QS_MAXCHAN,1);

% adc offset state
g.QS_CHAN_IN_OFFSET=zeros(2*g.QS_MAXCHAN,1);

% adc range state
g.QS_CHAN_IN_RANGE=8*ones(2*g.QS_MAXCHAN,1);
g.QS_CHAN_IN_RANGE(g.QS_MAXCHAN+1:2*g.QS_MAXCHAN,1)=9*ones(g.QS_MAXCHAN,1);

% dac channel state (read from hardware!)
g.QS_CHAN_OUT_STATE=zeros(g.QS_MAXCHAN,1);

% dac offset state
g.QS_CHAN_OUT_OFFSET=zeros(g.QS_MAXCHAN,1);

g.QS_MEAS_NUM=1;
g.QS_IFRAME=1;
g.QS_AVG_ON=0;
g.QS_FIRSTRUN=1;
g.QS_VALID=0;

g.QS_MEAS_TIME=num2str(g.QS_NSAMP/g.QS_MSAMPRATE(g.QS_MEAS_RATE));

% signal generator settings
g.QSG_GEN_SIGNAL=1;
g.QSG_GEN_OPEN=0;
% default hold order is zero
g.QSG_GEN_HOLD_ORDER=zeros(g.QS_MAXCHAN,1);

% default settings
tde_gate_m(def.CALL_FG_SET_DEFAULTS, g.QS_IP);

% all generator channels off
g.QSG_GEN_CHAN=zeros(g.QS_MAXCHAN,1);
for i=1:g.QS_MAXCHAN,
    g.QSG_GEN_CHAN(i)=0;
    tde_gate_m(def.CALL_FG_STOP, i-1, g.QS_IP);
    
    tde_gate_m(def.CALL_TDE_SET_DAC_STATE, 0, i-1, g.QS_IP);
end

% start clock
% tde_gate_m(def.CALL_TDE_START_ACQ, 1, 256, g.QS_IP);
% pause(1)(1);

g.QS_REDRAW=0;
% start gui
qlgui

% scopes
start_scope;
pause(1);

% frame indicator switch
frm_ind_init;

% measuring loop
while g.QS_EXIT==0

%   error checking
    ierr=tde_gate_m(def.CALL_TDE_CHECK_ERROR);
    if ierr==1
	g.QS_EXIT=1;
	break;
    end

    set(g2.QS_HANDLES.tag_meas_num_disp,'String',num2str(g.QS_IFRAME));

   PAUSELEN=0.2;
   while ~tde_gate_m(def.CALL_TDE_CHECK_ERROR) & g.QS_EXIT==0 & tde_gate_m(def.CALL_TDE_CHECK_DATA, g.QS_IP) & ~((g.QS_RUNNING==0)&(g.QS_REDRAW==1))
        check_clipping;
        pause(PAUSELEN);
        %c=clock;
        %msg=sprintf('Pause at %f', c(6));
        %disp(msg);
    end
    check_clipping;
    pause(PAUSELEN);

    if g.QS_RUNNING==1
        switch g.QS_AVG_ON
        case {0, 1}
            frm_ind_flash(g.QS_AVG_ON+1);
        otherwise,
        end
    end
    
%   if necessary restore QADScope View
    if ~strcmp(get(gcf,'Name'),'RTScope View')
        start_scope;
        g.QS_REDRAW=1;
    end
    
    if g.QS_IFRAME==1
%       set scales and labels for first frame
        g.QS_REDRAW=1;
    end

    deltat=1/g.QS_MSAMPRATE(g.QS_MEAS_RATE);
    tim=0:deltat:(g.QS_NSAMP-1)*deltat;
    A=tde_gate_m(def.CALL_TDE_GET_DATA, g.QS_NSAMP*g.QS_MAXCHAN*2, g.QS_IP);
    
%   check which channels are active and which are not
%   stat=zeros(2*g.QS_MAXCHAN,1);
%   stat=tde_gate_m(def.CALL_TDE_GET_ADC_ENC_STATE, g.QS_IP);

%   first get dimensions (still to be made faster!)
%   A(1,:) is taken as sample time series here
    lent=max(size(tim));

    [f1,ttt1,ttt2]=rm_fft_all(tim,A(1,:),0);
    lenf1=max(size(f1));

    [f2,ttt1]=rm_psd_auto(tim,A(1,:),1,0,0,0);
    lenf2=max(size(f2));
    
    [f3,ttt1,ttt2,ttt3,ttt4]=rm_frf_all(tim,A(1,:),A(1,:),0,0);
    lenf3=max(size(f3));
    
    first_frame=(g.QS_IFRAME==1) & (g.QS_RUNNING==1);
    
%   initialize storage space
    if first_frame | (g.QS_FIRSTRUN==1)
        data.XT=zeros(g.QS_MAXCHAN*2,lent);
        data.XF_MOD=zeros(g.QS_MAXCHAN*2,lenf1);
        data.XF_PHS=zeros(g.QS_MAXCHAN*2,lenf1);
        data.PSD_AUTO=zeros(g.QS_MAXCHAN*2,lenf2);
        if g.QS_AVG_ON==1
%           initialize or clear avaraged quantities
            MEAN_XT=data.XT;
            MEAN_XF_MOD=data.XF_MOD;
            MEAN_XF_PHS=data.XF_PHS;
        end
        data.FRF_MOD=zeros(lenf3,1);
        data.FRF_PHS=data.FRF_MOD;
        data.PSD_CROSS=data.FRF_MOD;
        data.COH=data.FRF_MOD;
	if g.QS_IS_SIMULINK
	    data.FRF_OL_MOD=data.FRF_MOD;
	    data.FRF_OL_PHS=data.FRF_MOD;
	    data.FRF_OL=data.FRF_MOD;
        end
	g.QS_FIRSTRUN=0;
    end

%   compute relevant quantities for active channels
    if g.QS_RUNNING==1
        for i=1:g.QS_MAXCHAN*2,
            if g.QS_CHAN_IN_STATE(i)==1
                data.TIM_XT=tim;
                data.XT(i,:)=A(i,:);
                [f1,xf_mod,xf_phs]=rm_fft_all(tim,A(i,:),g.QS_WINDOW);
                data.FREQ_XF=f1;
                data.XF_MOD(i,:)=xf_mod;
                data.XF_PHS(i,:)=xf_phs;
                [f2,psd_auto]=rm_psd_auto(tim,A(i,:),i,g.QS_AVG_ON,g.QS_IFRAME,g.QS_WINDOW);
                data.FREQ_PSD_AUTO=f2;
                data.PSD_AUTO(i,:)=psd_auto/g.QS_MSAMPRATE(g.QS_MEAS_RATE);

                if g.QS_AVG_ON==1
                    MEAN_XT(i,:)=(g.QS_IFRAME-1)/g.QS_IFRAME*MEAN_XT(i,:)+A(i,:)/g.QS_IFRAME;
                    data.XT(i,:)=MEAN_XT(i,:);
                    MEAN_XF_MOD(i,:)=(g.QS_IFRAME-1)/g.QS_IFRAME*MEAN_XF_MOD(i,:)+data.XF_MOD(i,:)/g.QS_IFRAME;
                    data.XF_MOD(i,:)=MEAN_XF_MOD(i,:);
                    MEAN_XF_PHS(i,:)=(g.QS_IFRAME-1)/g.QS_IFRAME*MEAN_XF_PHS(i,:)+data.XF_PHS(i,:)/g.QS_IFRAME;
                    data.XF_PHS(i,:)=MEAN_XF_PHS(i,:);
                end            
           
                if (g.QS_IN==i) & ((g.QS_SCOPE_DOFRF(1)==1 | g.QS_SCOPE_DOFRF(2)==1));
%                   compute frf quantities
                    [f3,data.FRF_MOD,data.FRF_PHS,data.PSD_CROSS,data.COH]=rm_frf_all(tim,A(g.QS_IN,:),A(g.QS_OUT,:),g.QS_AVG_ON,g.QS_IFRAME);
                    data.FREQ_FRF=f3;
		    if g.QS_IS_SIMULINK
%			sensitivity to openloop
                	sens=data.FRF_MOD.*exp(sqrt(-1)*data.FRF_PHS);
			data.FRF_OL=1./sens-1;
			data.FRF_OL_MOD=abs(data.FRF_OL);
			data.FRF_OL_PHS=angle(data.FRF_OL);
		    end
                end
            end
        end
        g.QS_VALID=1;
    end

    for j=1:g.QS_MAXSCOPE,
        thelegend=[];
        hlegend=[];
        subplot(g.QS_MAXSCOPE,1,j);
        cla;       
	    if sum(g.QS_SCOPE_CHAN(j,:))>0
           for i=1:g.QS_MAXCHAN*2,
                if g.QS_SCOPE_CHAN(j,i)==1
                    if g.QS_SCOPE_MEM(j)==1
%                       plot scope memory
                        idx=(j-1)*g.QS_MAXCHAN*2+i;
                        len=g.QS_SCOPE_MEM_LDAT(j,1);
                        if g.QS_SCOPE_MEM_IDAT(idx,1)==1
			    linst=0;
                            switch g.QS_SCOPE_TYPE(j)
                            case {def.QSST_FRF_MOD, def.QSST_FRF_OL_MOD}
                                if g.QS_IN==i 
				    h=line(g.QS_SCOPE_MEM_XDAT(j,1:len),20*log10(g.QS_SCOPE_MEM_YDAT(idx,1:len)));
				    linst=1;
				end
                            case {def.QSST_FRF_PHS, def.QSST_FRF_OL_PHS}
                                if g.QS_IN==i
				    h=line(g.QS_SCOPE_MEM_XDAT(j,1:len),g.QS_SCOPE_MEM_YDAT(idx,1:len)/pi*180);
				    linst=1;
				end
                            case {def.QSST_COHERENCE}
                                if g.QS_IN==i
				    h=line(g.QS_SCOPE_MEM_XDAT(j,1:len),g.QS_SCOPE_MEM_YDAT(idx,1:len));
				    linst=1;
				end
                            case {def.QSST_FRF_OL_NYQ}
                                if g.QS_IN==i
				    h=line(g.QS_SCOPE_MEM_XDAT(j,1:len),g.QS_SCOPE_MEM_YDAT(idx,1:len));
				    linst=1;
				end
                            case {def.QSST_PSD_AUTO,def.QSST_PSD_CROSS}
%				from double-sided to one-sided spectrum...
				ttt=g.QS_SCOPE_MEM_YDAT(idx,1:len);
				ttt(2:len)=2*g.QS_SCOPE_MEM_YDAT(idx,2:len);			    
                                h=line(g.QS_SCOPE_MEM_XDAT(j,1:len),20*log10(ttt));
				linst=1;
			    case {def.QSST_ESD_AUTO}
%				from double-sided to one-sided spectrum...
				ttt=g.QS_SCOPE_MEM_YDAT(idx,1:len);
				ttt(2:len)=2*g.QS_SCOPE_MEM_YDAT(idx,2:len);			    
                                h=line(g.QS_SCOPE_MEM_XDAT(j,1:len),20*log10(ttt*tim(end)));
				linst=1;
			    case {def.QSST_PSD_AUTO_CUM}
%			    	from double-sided to one-sided spectrum...
				ttt=g.QS_SCOPE_MEM_YDAT(idx,1:len);
				ttt(2:len)=2*g.QS_SCOPE_MEM_YDAT(idx,2:len);
				h=line(g.QS_SCOPE_MEM_XDAT(j,1:len),20*log10(cumsum(ttt)*g.QS_MSAMPRATE(g.QS_MEAS_RATE)/g.QS_NSAMP));
				linst=1;
			    case {def.QSST_POW_AUTO}		    
%				from double-sided to one-sided spectrum...
				ttt=g.QS_SCOPE_MEM_YDAT(idx,1:len);
				ttt(2:len)=2*g.QS_SCOPE_MEM_YDAT(idx,2:len);			    
                                h=line(g.QS_SCOPE_MEM_XDAT(j,1:len),20*log10(ttt*g.QS_MSAMPRATE(g.QS_MEAS_RATE)/g.QS_NSAMP));
				linst=1;
			    otherwise,
                                h=line(g.QS_SCOPE_MEM_XDAT(j,1:len),g.QS_SCOPE_MEM_YDAT(idx,1:len));
				linst=1;
                            end
			    if linst==1
				set(h,'LineWidth',2.0);
                        	set(h,'Color',g.QS_COLOR(i,:)+0.5*(ones(1,3)-g.QS_COLOR(i,:)));
                        	set(h,'LineStyle','--');
			    end
                        end
                    end
               
                    switch g.QS_SCOPE_TYPE(j)
                    case def.QSST_TIME,

                        if g.QS_REDRAW==1
                            set(gca,'XScale','linear');
                            set(gca,'XLim',[0 max(tim)]);
                            xlabel('time [s]');
                            if i<=g.QS_MAXCHAN
                                color_gray=[0.4 0.4 0.4];
                                % fix: added title
                                title(sprintf('SCOPE %d',j),'Color',color_gray,'FontSize', 16)
                                % fix index: ylabel(sprintf('scope %d: [V]',j));
                                ylabel(sprintf('voltage [V]'));
                                % fix index: legstr=sprintf('a ch%d',i-1);
                                legstr=sprintf('a ch%d',i);
                            else
                                ylabel(sprintf('scope %d: [counts]',j));
                                %fix index: legstr=sprintf('e ch%d',i-1-g.QS_MAXCHAN);
                                legstr=sprintf('e ch%d',i-g.QS_MAXCHAN);
                            end
                            thelegend=[thelegend; legstr];
                        end

                        if g.QS_VALID==1
                            h=line(tim,data.XT(i,:));
                            set(h,'Color',g.QS_COLOR(i,:));
                            hlegend=[hlegend; h];
                        end
                    case def.QSST_FFT_MOD,
                 
                        if g.QS_REDRAW==1
                            set(gca,'XScale','linear');
                            set(gca,'XLim',[f1(1) f1(end)]);
                            xlabel('freq [Hz]');
                            if i<=g.QS_MAXCHAN
                                %fix: ylabel(sprintf('scope %d: [V/Hz]',j));
                                ylabel(sprintf('modulus [V/Hz]',j));
                                %fix index: legstr=sprintf('a ch%d',i-1);
                                legstr=sprintf('a ch%d',i);
                            else
                                %fix: ylabel(sprintf('scope %d: [counts/Hz]',j));
                                ylabel(sprintf('modulus [counts/Hz]',j));
                                %fix index: legstr=sprintf('e ch%d',i-1-g.QS_MAXCHAN);
                                legstr=sprintf('e ch%d',i-g.QS_MAXCHAN);
                            end
                            thelegend=[thelegend; legstr];                       
                        end
                    
                        if g.QS_VALID==1
                            h=line(f1,data.XF_MOD(i,:));
                            set(h,'Color',g.QS_COLOR(i,:));
                            hlegend=[hlegend; h];
                        end
                    case def.QSST_FFT_PHS,

                        if g.QS_REDRAW==1
                            set(gca,'XScale','linear');
                            set(gca,'XLim',[f1(1) f1(end)]);
                            xlabel('freq [Hz]');
                            %fix: ylabel(sprintf('scope %d: [rad]',j));
                            ylabel(sprintf('phase [rad]',j));
                            if i<=g.QS_MAXCHAN
                                %fix index: legstr=sprintf('a ch%d',i-1);                            
                                legstr=sprintf('a ch%d',i);                            
                            else
                                %fix index: legstr=sprintf('e ch%d',i-1-g.QS_MAXCHAN);
                                legstr=sprintf('e ch%d',i-g.QS_MAXCHAN);
                           end
                            thelegend=[thelegend; legstr];                        
                        end
                        
                        if g.QS_VALID==1
                            h=line(f1,data.XF_PHS(i,:));
                            set(h,'Color',g.QS_COLOR(i,:));
                            hlegend=[hlegend; h];
                        end
                    case def.QSST_ESD_AUTO,

                        if g.QS_REDRAW==1
                            switch g.QS_SCOPE_SCALE(j)
                            case def.QSSS_LIN,
                                set(gca,'XScale','linear');
                            case def.QSSS_LOG,
                                set(gca,'XScale','log');
                            otherwise,
                            end                      
                            set(gca,'XLim',[f2(1) f2(end)]);
                            if i<=g.QS_MAXCHAN
                                %fix: ylabel(sprintf('scope %d: [V^2s/Hz in dB]',j));
                                ylabel(sprintf('energy spectral density [V^2s/Hz in dB]',j));
                                %fix index: legstr=sprintf('a ch%d',i-1); 
                                legstr=sprintf('a ch%d',i); 
                            else
                                %fix: ylabel(sprintf('scope %d: [counts^2s/Hz in dB]',j));
                                ylabel(sprintf('energy spectral density [counts^2s/Hz in dB]',j));
                                %fix index: legstr=sprintf('e ch%d',i-1-g.QS_MAXCHAN); 
                                legstr=sprintf('e ch%d',i-g.QS_MAXCHAN); 
                            end
                            thelegend=[thelegend; legstr];
                        end

                        if g.QS_VALID==1
%			    from double-sided to one-sided spectrum...
			    ttt=data.PSD_AUTO(i,1:end);
			    ttt(2:end)=2*data.PSD_AUTO(i,2:end);
                            h=line(f2,20*log10(ttt*tim(end)));
                            set(h,'Color',g.QS_COLOR(i,:));
                            hlegend=[hlegend; h];
                        end
                    case def.QSST_PSD_AUTO,

                        if g.QS_REDRAW==1
                            switch g.QS_SCOPE_SCALE(j)
                            case def.QSSS_LIN,
                                set(gca,'XScale','linear');
                            case def.QSSS_LOG,
                                set(gca,'XScale','log');
                            otherwise,
                            end                      
                            set(gca,'XLim',[f2(1) f2(end)]);
                            if i<=g.QS_MAXCHAN
                                %fix: ylabel(sprintf('scope %d: [V^2/Hz in dB]',j));
                                ylabel(sprintf('power spectral density [V^2/Hz in dB]',j));
                                %fix index: legstr=sprintf('a ch%d',i-1); 
                                legstr=sprintf('a ch%d',i); 
                            else
                                %fix: ylabel(sprintf('scope %d: [counts^2/Hz in dB]',j));
                                ylabel(sprintf('power spectral density [counts^2/Hz in dB]',j));
                                %fix index: legstr=sprintf('e ch%d',i-1-g.QS_MAXCHAN); 
                                legstr=sprintf('e ch%d',i-g.QS_MAXCHAN); 
                            end
                            thelegend=[thelegend; legstr];
                        end

                        rms=sqrt((2*sum(data.PSD_AUTO(i,2:end))+data.PSD_AUTO(i,1))*g.QS_MSAMPRATE(g.QS_MEAS_RATE)/g.QS_NSAMP);
                        if i<=g.QS_MAXCHAN
                            xlabel(['freq [Hz]   (rms a ch' num2str(i-1) ': ' num2str(rms) ' V)']);
                        else
                            xlabel(['freq [Hz]   (rms e ch' num2str(i-1-g.QS_MAXCHAN) ': ' num2str(rms) ' counts)']);
                        end
                    
                        if g.QS_VALID==1
%			    from double-sided to one-sided spectrum...
			    ttt=data.PSD_AUTO(i,1:end);
			    ttt(2:end)=2*data.PSD_AUTO(i,2:end);
                            h=line(f2,20*log10(ttt));
                            set(h,'Color',g.QS_COLOR(i,:));
                            hlegend=[hlegend; h];
                        end
                    case def.QSST_PSD_AUTO_CUM,

                        if g.QS_REDRAW==1
                            switch g.QS_SCOPE_SCALE(j)
                            case def.QSSS_LIN,
                                set(gca,'XScale','linear');
                            case def.QSSS_LOG,
                                set(gca,'XScale','log');
                            otherwise,
                            end                      
                            set(gca,'XLim',[f2(1) f2(end)]);
                            if i<=g.QS_MAXCHAN
                                %fix: ylabel(sprintf('scope %d: [V^2 in dB]',j));
                                ylabel(sprintf('cumulative psd [V^2 in dB]',j));
                                %fix index: legstr=sprintf('a ch%d',i-1); 
                                legstr=sprintf('a ch%d',i); 
                            else
                                %fix: ylabel(sprintf('scope %d: [counts^2 in dB]',j));
                                ylabel(sprintf('cumulative psd [counts^2 in dB]',j));
                                %fix index: legstr=sprintf('e ch%d',i-1-g.QS_MAXCHAN); 
                                legstr=sprintf('e ch%d',i-g.QS_MAXCHAN); 
                            end
                            thelegend=[thelegend; legstr];
                        end

                        rms=sqrt((2*sum(data.PSD_AUTO(i,2:end))+data.PSD_AUTO(i,1))*g.QS_MSAMPRATE(g.QS_MEAS_RATE)/g.QS_NSAMP);
                        if i<=g.QS_MAXCHAN
                            xlabel(['freq [Hz]   (rms a ch' num2str(i-1) ': ' num2str(rms) ' V)']);
                        else
                            xlabel(['freq [Hz]   (rms e ch' num2str(i-1-g.QS_MAXCHAN) ': ' num2str(rms) ' counts)']);
                        end
                    
                        if g.QS_VALID==1
%			    from double-sided to one-sided spectrum...
			    ttt=data.PSD_AUTO(i,1:end);
			    ttt(2:end)=2*data.PSD_AUTO(i,2:end);
                            h=line(f2,20*log10(cumsum(ttt)*g.QS_MSAMPRATE(g.QS_MEAS_RATE)/g.QS_NSAMP));
                            set(h,'Color',g.QS_COLOR(i,:));
                            hlegend=[hlegend; h];
                        end                        
                    case def.QSST_POW_AUTO,

                        if g.QS_REDRAW==1
                            switch g.QS_SCOPE_SCALE(j)
                            case def.QSSS_LIN,
                                set(gca,'XScale','linear');
                            case def.QSSS_LOG,
                                set(gca,'XScale','log');
                            otherwise,
                            end                      
                            set(gca,'XLim',[f2(1) f2(end)]);
                            if i<=g.QS_MAXCHAN
                                %fix: ylabel(sprintf('scope %d: [V^2 in dB]',j));
                                ylabel(sprintf('ps [V^2 in dB]',j));
                                %fix index: legstr=sprintf('a ch%d',i-1); 
                                legstr=sprintf('a ch%d',i); 
                            else
                                %fix: ylabel(sprintf('scope %d: [counts^2 in dB]',j));
                                ylabel(sprintf('ps [counts^2 in dB]',j));
                                %fix index: legstr=sprintf('e ch%d',i-1-g.QS_MAXCHAN); 
                                legstr=sprintf('e ch%d',i-g.QS_MAXCHAN); 
                            end
                            thelegend=[thelegend; legstr];
                        end

                        rms=sqrt((2*sum(data.PSD_AUTO(i,2:end))+data.PSD_AUTO(i,1))*g.QS_MSAMPRATE(g.QS_MEAS_RATE)/g.QS_NSAMP);
                        if i<=g.QS_MAXCHAN
                            xlabel(['freq [Hz]   (rms a ch' num2str(i-1) ': ' num2str(rms) ' V)']);
                        else
                            xlabel(['freq [Hz]   (rms e ch' num2str(i-1-g.QS_MAXCHAN) ': ' num2str(rms) ' counts)']);
                        end
                    
                        if g.QS_VALID==1
%			    from double-sided to one-sided spectrum...
			    ttt=data.PSD_AUTO(i,1:end);
			    ttt(2:end)=2*data.PSD_AUTO(i,2:end);
                            h=line(f2,20*log10(ttt*g.QS_MSAMPRATE(g.QS_MEAS_RATE)/g.QS_NSAMP));
                            set(h,'Color',g.QS_COLOR(i,:));
                            hlegend=[hlegend; h];
                        end                        
                    case def.QSST_PSD_CROSS,
                        if i==g.QS_IN                          
                            if g.QS_REDRAW==1
                                switch g.QS_SCOPE_SCALE(j)
                                case def.QSSS_LIN,
                                    set(gca,'XScale','linear');
                                case def.QSSS_LOG,
                                    set(gca,'XScale','log');
                                otherwise,
                                end                           
                                set(gca,'XLim',[f3(1) f3(end)]);
                                xlabel('freq [Hz]');
                                if g.QS_IN<=g.QS_MAXCHAN
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        %fix: ylabel(sprintf('scope %d: [V^2/Hz in dB]',j));
                                        ylabel(sprintf('cross psd [V^2/Hz in dB]',j));
                                        %fix index: legstr=sprintf('a ch%d/a ch %d',g.QS_OUT-1,g.QS_IN-1);
                                        legstr=sprintf('a ch%d/a ch %d',g.QS_OUT,g.QS_IN);
                                    else
                                        %fix: ylabel(sprintf('scope %d: [V*counts/Hz in dB]',j));                                    
                                        ylabel(sprintf('cross psd [V*counts/Hz in dB]',j));                                    
                                        %fix index: legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1);
                                        legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN);
                                    end
                                else
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        %fix: ylabel(sprintf('scope %d: [counts*V/Hz in dB]',j));
                                        ylabel(sprintf('cross psd [counts*V/Hz in dB]',j));
                                        %fix index: legstr=sprintf('a ch%d/e ch %d',g.QS_OUT-1,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('a ch%d/e ch %d',g.QS_OUT,g.QS_IN-g.QS_MAXCHAN);
                                    else
                                        %fix: ylabel(sprintf('scope %d: [counts^2/Hz in dB]',j));                                    
                                        ylabel(sprintf('cross psd [counts^2/Hz in dB]',j));                                    
                                        %fix index: legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN-g.QS_MAXCHAN);
                                    end
                                end
                                thelegend=[thelegend; legstr];                    
                            end

                            if g.QS_VALID==1
%			    	from double-sided to one-sided spectrum...
                                ttt=data.PSD_CROSS;
				ttt(2:end)=2*data.PSD_CROSS(2:end);
				h=line(f3,20*log10(ttt));
                                set(h,'Color',g.QS_COLOR(i,:));
                                hlegend=[hlegend; h];
                            end
			end
                    case def.QSST_FRF_MOD,
                        if i==g.QS_IN                     
                            if g.QS_REDRAW==1
                                switch g.QS_SCOPE_SCALE(j)
                                case def.QSSS_LIN,
                                    set(gca,'XScale','linear');
                                case def.QSSS_LOG,
                                    set(gca,'XScale','log');
                                otherwise,
                                end
                                set(gca,'XLim',[f3(1) f3(end)]);
                                xlabel('freq [Hz]');
                                if g.QS_IN<=g.QS_MAXCHAN
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        %fix: ylabel(sprintf('scope %d: [- in dB]',j));
                                        ylabel(sprintf('modulus [- in dB]',j));
                                        %fix index: legstr=sprintf('a ch%d/a ch %d',g.QS_OUT-1,g.QS_IN-1);
                                        legstr=sprintf('a ch%d/a ch %d',g.QS_OUT,g.QS_IN);
                                    else
                                        %fix: ylabel(sprintf('scope %d: [counts/V in dB]',j));                                    
                                        ylabel(sprintf('modulus [counts/V in dB]',j));                                    
                                        %fix index: legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1);
                                        legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN);
                                    end
                                else
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        %fix: ylabel(sprintf('scope %d: [V/counts in dB]',j));
                                        ylabel(sprintf('modulus [V/counts in dB]',j));
                                        %fix index: legstr=sprintf('a ch%d/e ch %d',g.QS_OUT-1,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('a ch%d/e ch %d',g.QS_OUT,g.QS_IN-g.QS_MAXCHAN);
                                    else
                                        %fix: ylabel(sprintf('scope %d: [- in dB]',j));                                    
                                        ylabel(sprintf('modulus [- in dB]',j));                                    
                                        %fix index: legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN-g.QS_MAXCHAN);
                                    end
                                end
                                thelegend=[thelegend; legstr]; 
                            end
                        
                            if g.QS_VALID==1
                                h=line(f3,20*log10(data.FRF_MOD));
                                set(h,'Color',g.QS_COLOR(i,:));
                                hlegend=[hlegend; h];
                            end
                        end
                    case def.QSST_FRF_PHS,
                        if i==g.QS_IN
                            if g.QS_REDRAW==1
                                switch g.QS_SCOPE_SCALE(j)
                                case def.QSSS_LIN,
                                    set(gca,'XScale','linear');
                                case def.QSSS_LOG,
                                    set(gca,'XScale','log');
                                otherwise,
                                end
                                set(gca,'XLim',[f3(1) f3(end)]);
                                xlabel('freq [Hz]');
                                %fix: ylabel(sprintf('scope %d: [deg]',j));
                                ylabel(sprintf('phase [deg]',j));
                                if g.QS_IN<=g.QS_MAXCHAN
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        %fix index: legstr=sprintf('a ch%d/a ch %d',g.QS_OUT-1,g.QS_IN-1);
                                        legstr=sprintf('a ch%d/a ch %d',g.QS_OUT,g.QS_IN);
                                    else
                                        %fix index: legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1);
                                        legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN);
                                    end
                                 else
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        %fix index: legstr=sprintf('a ch%d/e ch %d',g.QS_OUT-1,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('a ch%d/e ch %d',g.QS_OUT,g.QS_IN-g.QS_MAXCHAN);
                                    else
                                        %fix index: legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN-g.QS_MAXCHAN);
                                    end
                                 end
                                 thelegend=[thelegend; legstr];                             
                            end
                        
                            if g.QS_VALID==1
                                h=line(f3,data.FRF_PHS/pi*180);
                                set(h,'Color',g.QS_COLOR(i,:));
                                hlegend=[hlegend; h];
                            end
                        end
                    case def.QSST_COHERENCE,
                        if i==g.QS_IN
                            if g.QS_REDRAW==1
                                switch g.QS_SCOPE_SCALE(j)
                                case def.QSSS_LIN,
                                    set(gca,'XScale','linear');
                                case def.QSSS_LOG,
                                    set(gca,'XScale','log');
                                otherwise,
                                end                           
                                set(gca,'XLim',[f3(1) f3(end)]);
                                xlabel('freq [Hz]');
                                %fix: ylabel(sprintf('scope %d: [-]',j));
                                ylabel(sprintf('coherence [-]',j));
                                if g.QS_IN<=g.QS_MAXCHAN
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        %fix index: legstr=sprintf('a ch%d/a ch %d',g.QS_OUT-1,g.QS_IN-1);
                                        legstr=sprintf('a ch%d/a ch %d',g.QS_OUT,g.QS_IN);
                                    else
                                        %fix index: legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1);
                                        legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN);
                                    end
                                 else
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        %fix index: legstr=sprintf('a ch%d/e ch %d',g.QS_OUT-1,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('a ch%d/e ch %d',g.QS_OUT,g.QS_IN-g.QS_MAXCHAN);
                                    else
                                        %fix index: legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN-g.QS_MAXCHAN);
                                    end
                                 end
                                 thelegend=[thelegend; legstr];                            
                            end
                            
                            if g.QS_VALID==1
                                h=line(f3,data.COH);
                                set(h,'Color',g.QS_COLOR(i,:));
                                hlegend=[hlegend; h];
                            end
                        end                    
                    case def.QSST_FRF_OL_MOD,
                        if i==g.QS_IN
                            if g.QS_REDRAW==1
                                switch g.QS_SCOPE_SCALE(j)
                                case def.QSSS_LIN,
                                    set(gca,'XScale','linear');
                                case def.QSSS_LOG,
                                    set(gca,'XScale','log');
                                otherwise,
                                end
                                set(gca,'XLim',[f3(1) f3(end)]);
                                xlabel('freq [Hz]');
                                if g.QS_IN<=g.QS_MAXCHAN
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        ylabel(sprintf('scope %d: openloop [- in dB]',j));
                                        %fix index: legstr=sprintf('a ch%d/a ch %d',g.QS_OUT-1,g.QS_IN-1);
                                        legstr=sprintf('a ch%d/a ch %d',g.QS_OUT,g.QS_IN);
                                    else
                                        ylabel(sprintf('scope %d: openloop [counts/V in dB]',j));                                    
                                        %fix index: legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1);
                                        legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN);
                                    end
                                else
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        ylabel(sprintf('scope %d: openloop [V/counts in dB]',j));
                                        %fix index: legstr=sprintf('a ch%d/e ch %d',g.QS_OUT-1,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('a ch%d/e ch %d',g.QS_OUT,g.QS_IN-g.QS_MAXCHAN);
                                    else
                                        ylabel(sprintf('scope %d: openloop [- in dB]',j));                                    
                                        %fix index: legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN-g.QS_MAXCHAN);
                                    end
                                end
                                thelegend=[thelegend; legstr]; 
                            end
                        
                            if g.QS_VALID==1
				h=line(f3,20*log10(data.FRF_OL_MOD));
                                set(h,'Color',g.QS_COLOR(i,:));
                                hlegend=[hlegend; h];
                            end
                        end
                    case def.QSST_FRF_OL_PHS,
                        if i==g.QS_IN
                            if g.QS_REDRAW==1
                                switch g.QS_SCOPE_SCALE(j)
                                case def.QSSS_LIN,
                                    set(gca,'XScale','linear');
                                case def.QSSS_LOG,
                                    set(gca,'XScale','log');
                                otherwise,
                                end
                                set(gca,'XLim',[f3(1) f3(end)]);
                                xlabel('freq [Hz]');
                                ylabel(sprintf('scope %d: openloop [deg]',j));
                                if g.QS_IN<=g.QS_MAXCHAN
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        %fix index: legstr=sprintf('a ch%d/a ch %d',g.QS_OUT-1,g.QS_IN-1);
                                        legstr=sprintf('a ch%d/a ch %d',g.QS_OUT,g.QS_IN);
                                    else
                                        %fix index: legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1);
                                        legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN);
                                    end
                                 else
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        %fix index: legstr=sprintf('a ch%d/e ch %d',g.QS_OUT-1,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('a ch%d/e ch %d',g.QS_OUT,g.QS_IN-g.QS_MAXCHAN);
                                    else
                                        %fix index: legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN-g.QS_MAXCHAN);
                                    end
                                 end
                                 thelegend=[thelegend; legstr];                             
                            end

                            if g.QS_VALID==1
                                h=line(f3,data.FRF_OL_PHS/pi*180);
                                set(h,'Color',g.QS_COLOR(i,:));
                                hlegend=[hlegend; h];
                            end
                        end
                    case def.QSST_FRF_OL_NYQ,
                        if i==g.QS_IN
                            if g.QS_REDRAW==1
                                set(gca,'XScale','linear');
%                                set(gca,'XLim',[ min([-1 min(real(data.FRF_OL))]) max([1 max(real(data.FRF_OL))]) ]);
				set(gca,'XLim',[-3 1]);
				set(gca,'YLim',[-2 2]);
                                xlabel('real');
                                if g.QS_IN<=g.QS_MAXCHAN
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        ylabel(sprintf('scope %d: openloop imag',j));
                                        %fix index: legstr=sprintf('a ch%d/a ch %d',g.QS_OUT-1,g.QS_IN-1);
                                        legstr=sprintf('a ch%d/a ch %d',g.QS_OUT,g.QS_IN);
                                    else
                                        ylabel(sprintf('scope %d: openloop imag',j));                                    
                                        %fix index: legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1);
                                        legstr=sprintf('e ch%d/a ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN);
                                    end
                                else
                                    if g.QS_OUT<=g.QS_MAXCHAN
                                        ylabel(sprintf('scope %d: openloop imag',j));
                                        %fix index: legstr=sprintf('a ch%d/e ch %d',g.QS_OUT-1,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('a ch%d/e ch %d',g.QS_OUT,g.QS_IN-g.QS_MAXCHAN);
                                    else
                                        ylabel(sprintf('scope %d: openloop imag',j));                                    
                                        %fix index: legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-1-g.QS_MAXCHAN,g.QS_IN-1-g.QS_MAXCHAN);
                                        legstr=sprintf('e ch%d/e ch %d',g.QS_OUT-g.QS_MAXCHAN,g.QS_IN-g.QS_MAXCHAN);
                                    end
                                end
                                thelegend=[thelegend; legstr]; 
                            end

                            if g.QS_VALID==1
%				circle around point -1 with radius 0.5
				[xc,yc]=circle(-1,0,0.5);
				h=line(xc,yc);
				set(h,'LineWidth',1);
                                set(h,'Color',def.LCLR_BLACK);				
                        	set(h,'LineStyle','--');
				

%				circle around origin with radius 1
				[xc,yc]=circle(0,0,1.0);
				h=line(xc,yc);
				set(h,'LineWidth',1);
                                set(h,'Color',def.LCLR_BLACK);				
                        	set(h,'LineStyle','--');
				

%				find cross point openloop with radius 1
				diff_ol=data.FRF_OL_MOD-1;
				n=max(size(data.FRF_OL_MOD))-1;
				s=sign(diff_ol(1));
				idx=2;
				while (sign(diff_ol(idx))==s) & (idx<n)
				    idx=idx+1;
				end
				x=real(data.FRF_OL(idx));
				y=imag(data.FRF_OL(idx))-0.3;
				fbw=f3(idx);
				text(x,y,[num2str(fbw) ' Hz']);
								
				h=line(real(data.FRF_OL),imag(data.FRF_OL));
                                set(h,'Color',g.QS_COLOR(i,:));
                                hlegend=[hlegend; h];
                            end
                        end
                    otherwise,
                    end
                end
            end
            if g.QS_REDRAW
                if ~isempty(thelegend) & ~isempty(hlegend)
                    legend(hlegend,thelegend);
                else
                    legend off;
                end
            end
        end
    end

    tde_gate_m(def.CALL_TDE_SAY_READY, g.QS_IP);

    g.QS_REDRAW=0;
                
    if g.QS_RUNNING==1
%       check frame number
        g.QS_IFRAME=g.QS_IFRAME+1;
        if g.QS_IFRAME>g.QS_MNUMFRAMES(g.QS_MEAS_NUM)
            if g.QS_EXIT==0
                turnoff;
                g.QS_IFRAME=1;
		gupdate;
            end
        end
    end

%    pause(0.05);

end


qsexit;

% clear variables
%clear g
%clear data
%clear xgui

% end of program





function check_clipping()

global g g2;

def=qs_defines;

[g.QS_CLIPPED, retval]=tde_gate_m(def.CALL_TDE_CHECK_CLIPPING, g.QS_IP);

for i=1:g.QS_MAXCHAN,
    if g.QS_CLIPPED(i)==1
	    set(eval(sprintf('g2.QS_HANDLES.tag_ch%d',i-1)),'BackgroundColor',def.COLOR_RED);
    else
	    set(eval(sprintf('g2.QS_HANDLES.tag_ch%d',i-1)),'BackgroundColor',def.COLOR_RED+0.75*(ones(1,3)-def.COLOR_RED));
    end
end
