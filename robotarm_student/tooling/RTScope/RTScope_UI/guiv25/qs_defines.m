
% contains MAXDEVS definition!!! see also file tdext.h

function gl=qs_defines()

% static defines

gl=struct(  'CALL_TDE_START_ACQ',1,...
            'CALL_TDE_STOP_ACQ',2,...
            'CALL_TDE_CHECK_DATA',3,...
            'CALL_TDE_SAY_READY',4,...
            'CALL_TDE_GET_DATA',5,...
            'CALL_TDE_GET_INFO',6,...
            'CALL_TDE_TRIGGER_ON',7,...
            'CALL_TDE_TRIGGER_OFF',8,...
            'CALL_TDE_CHECK_CLIPPING',9,...
            'CALL_TDE_SET_ADC_STATE',10,...
            'CALL_TDE_GET_ADC_STATE',11,...
            'CALL_TDE_SET_ENC_STATE',12,...
            'CALL_TDE_GET_ENC_STATE',13,...
            'CALL_TDE_SET_DAC_STATE',14,...
            'CALL_TDE_GET_DAC_STATE',15,...
            'CALL_TDE_SET_ADC_OFFSET',16,...
            'CALL_TDE_GET_ADC_OFFSET',17,...
            'CALL_TDE_PAUSE',18,...
            'CALL_TDE_SET_NSAMP',19,...
            'CALL_TDE_SET_NDOWN',20,...
            'CALL_TDE_INIT_ENC',21,...
            'CALL_TD_GET_DEVICE_TYPE',22,...
            'CALL_TD_AAFILTER_ON',23,...
            'CALL_TD_AAFILTER_OFF',24,...
            'CALL_TD_SET_RANGE',25,...
            'CALL_TD_GET_RANGE',26,...
            'CALL_TD_GET_FILTER_ENABLE',27,...
            'CALL_TDE_GET_MAXFREQ',28,...
            'CALL_TDE_LINK2MEAS',29,...
            'CALL_TDE_LINK_IS_ACTIVE',30,...
            'CALL_FG_GET_VAL',31,...
            'CALL_FG_START',32,...
            'CALL_FG_STOP',33,...
            'CALL_FG_SET_DEFAULTS',34,...
            'CALL_FG_SET_AMP1',35,...
            'CALL_FG_GET_AMP1',36,...
            'CALL_FG_SET_FREQ1',37,...
            'CALL_FG_GET_FREQ1',38,...
            'CALL_FG_SET_OFFSET',39,...
            'CALL_FG_GET_OFFSET',40,...
            'CALL_FG_STATUS',41,...
            'CALL_FG_SET_TYPE',42,...
            'CALL_FG_GET_TYPE',43,...
            'CALL_FG_SET_ONOFF',44,...
            'CALL_FG_GET_ONOFF',45,...
            'CALL_FG_SET_FREQ2',46,...
            'CALL_FG_GET_FREQ2',47,...
            'CALL_FG_SET_AMP2',48,...
            'CALL_FG_GET_AMP2',49,...
            'CALL_FG_SET_HOLD_ORDER',50,...
            'CALL_FG_GET_HOLD_ORDER',51,...
	    'CALL_TDE_GET_ADC_ENC_STATE',52,...
	    'CALL_TDE_CHECK_ERROR',53,...
            'SINE',1,...
            'RAND',2,...
            'SQUARE',3,...
            'TWOTONE',4,...
	    'CHIRP',5,...
	    'MULTISINE',6,...
	    'WHISTLE',7,...
	    'MAXHOLDORDER',3,...
            'QSST_TIME',1,...
            'QSST_FFT_MOD',2,...
            'QSST_FFT_PHS',3,...
	    'QSST_ESD_AUTO',4,...
            'QSST_PSD_AUTO',5,...
            'QSST_PSD_AUTO_CUM',6,...
	    'QSST_POW_AUTO',7,...
            'QSST_PSD_CROSS',8,...
            'QSST_FRF_MOD',9,...
            'QSST_FRF_PHS',10,...
            'QSST_COHERENCE',11,...
	    'QSST_FRF_OL_MOD',12,...
	    'QSST_FRF_OL_PHS',13,...
	    'QSST_FRF_OL_NYQ',14,...
            'QSSS_LIN',1,...
            'QSSS_LOG',2,...
            'MENUBAR_HEIGHT',51,...
            'FMIN',0,...
            'COLOR_YELLOW',[1 1 0],...
            'COLOR_GREY',[0.9 0.9 0.9],...
            'COLOR_GREEN',[0 1 0],...
            'COLOR_RED',[1 0 0],...
            'LCLR_BLACK',[0.0 0.0 0.0],...
            'LCLR_BLUE',[0.0 0.0 0.8],...
            'LCLR_GREEN',[0.0 0.8 0.0],...
            'LCLR_RED',[0.8 0.0 0.0],...
            'LCLR_GREY',[0.4 0.4 0.4],...
            'LCLR_CYAN',[0 0.4 0.4],...
            'LCLR_PURPLE',[0.4 0 0.4],...
            'LCLR_BROWN',[0.4 0.4 0],...
	    'DEVICE_NOT_READY',-1,...
	    'MAXDEVS',4);
%            'COLOR_GREY',[0.83 0.82 0.78],...
