function freqb = bound_freq(freq)

global g;

freqb=max(freq,0.025*g.QS_MAXFREQ);
freqb=min(freqb,0.450*g.QS_MAXFREQ);