
// function generator

// Ren� van de Molengraft, November, 2001
// Revision history: January, 15th, 2003: added FIR-filtered band-limited noise signal
//										  (IIR elliptic was removed)
//					 December, 1st, 2003: generator got its own clock
//					 February, 6th, 2004: clock replaced by delta t increments
//										  for the purpose of exact simulation
//					 March, 14th, 2004: added link to measurement
//					 June, 30th, 2004: linux-port
//					 September, 3rd, 2004: changed tde_link_is_active into fg_notify to resolve linkage order
//								problem
//					 February, 9th, 2005: added chirp signal
// Michael Ronde, August, 2011
//					 August, 25th, 2011: Added header files for correct compilation (time.h and timer.h)
//                   August, 28th, 2011: Removed unused variables            

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#if 0
#ifdef USB
#include <td_usb.h>
#else
#include <td.h>
#endif
#endif

#include "fungen.h"
#include "../remez/remez.h"
#include "../fir/fir.h"
#include "../engine.h"
//#include "../../../Libs/Timer_posix_AK/timer.h"

// void _init()
// {
// //	initialize variables
// 	fg_onoff=0;
// 	fp=NULL;
// //	clock variables
// 	fgc_t0=0.0;
// 	fgc_freq=0.0;
// 
// 	fg_arg=-1.0;
// 	fg_ilinked=0;
// 	fg_t0=0.0;
// }





// void _fini()
// {
// }





static int nearest(double x)
{
    if (x>=0.0) {
	return (int) ((double) x+0.49999999999);
    } else {
	return (int) ((double) x-0.49999999999);
    }
}





double** create_double_matrix(int nrows, int ncols)
{
	int irow;
	double** a;
	
//	declare matrix dynamically

	a=(double**) calloc(nrows,sizeof(double*));

	for (irow=0;irow<nrows;irow++) {
		a[irow]=(double*) calloc(ncols,sizeof(double));
	}

	return a;
}





/*
#ifdef USB
static struct timeval tv0,tva;

int fgc_reset_time(void)
{
  gettimeofday(&tv0,NULL);
  
  return 0;
}

double fgc_get_time(void)
{
  double t,wrk;
  
  gettimeofday(&tva,NULL);
  
  t=(double) (tva.tv_sec-tv0.tv_sec)+((double) (tva.tv_usec-tv0.tv_usec))/1000000.0;
  
  return t;
}
#else
*/





int fgc_reset_time(pfungen_data pfgd)
{
    gettimeofday(&pfgd->tv0, NULL);

    return 0;
}





double fgc_get_time(pfungen_data pfgd)
{
  double t;

  gettimeofday(&pfgd->tva, NULL);

  t=(double) (pfgd->tva.tv_sec-pfgd->tv0.tv_sec)+((double) (pfgd->tva.tv_usec-pfgd->tv0.tv_usec))/1000000.0;

  return t;
}
/*#endif*/





double sqval(double x)
{
	if (x>=0) {
		return 1;
	} else {
		return -1;
	}
}





double fg_get_val(double time, int ichan, pfungen_data pfgd)
{
	int iframe,k1,k2,k,n,nlines;
	double t,x,u,a,b,freq,tim,f1,f2,sum;

	pfgd->fg_time=fgc_get_time(pfgd);//time;//fgc_get_time();

//	link has just been turned on
	if ( ( pfgd->fg_link_is_active==1 ) & ( pfgd->fg_ilinked==0 ) ) {
//		printf("link has just been turned on (t=%f s).\n",fg_time);
		pfgd->fg_ilinked=1;
		pfgd->fg_t0=pfgd->fg_time;
	}

//	link has just been turned off
	if ( ( pfgd->fg_link_is_active==0 ) & ( pfgd->fg_ilinked==1 ) ) {
//		printf("link has just been turned off (t=%f s).\n",fg_time);
		pfgd->fg_ilinked=0;
		pfgd->fg_t0=0.0;
	}

	t=pfgd->fg_time;

	if ( ( pfgd->fg_onoff==0 ) & ( pfgd->fg_link_is_active==0 ) ) {
		return 0.0;
	}

//	if (ichan==0) {printf("type=%d, power=%d\n",fg_type[ichan],fg_power[ichan]);}
	switch ( pfgd->fg_type[ichan] ) {
        case SINE:
            if ( pfgd->fg_power[ichan]==1 ) {
                return pfgd->fg_amp1[ichan]*sin(2*PI*pfgd->fg_freq1[ichan]*(t-pfgd->fg_t0))+pfgd->fg_offset[ichan];
//			    ttt=fg_amp1[ichan]*sin(2*PI*fg_freq1[ichan]*(t-fg_t0))+fg_offset[ichan];
//			    if (ttt>0.0) {printf("ttt = %f\n",ttt);}
//			    return ttt;
            } else {
                return 0.0;
            }
        case RAND:
            if ( pfgd->fg_power[ichan]==1 ) {
                u=pfgd->fg_amp1[ichan]*2.0*( ((double) rand())/((double) RAND_MAX)-0.5);
                x=fir_filter(u, ichan, &pfgd->fd)+pfgd->fg_offset[ichan];
                return x;
            } else {
                return 0.0;
            }
        case SQUARE:
            if ( pfgd->fg_power[ichan]==1 ) {
                return pfgd->fg_amp1[ichan]*sqval(sin(2*PI*pfgd->fg_freq1[ichan]*(t-pfgd->fg_t0)))+pfgd->fg_offset[ichan];
            } else {
                return 0.0;
            }
        case TWOTONE:
            if ( pfgd->fg_power[ichan]==1 ) {
                return pfgd->fg_amp1[ichan]*sin(2*PI*pfgd->fg_freq1[ichan]*(t-pfgd->fg_t0))+pfgd->fg_amp2[ichan]*sin(2*PI*pfgd->fg_freq2[ichan]*(t-pfgd->fg_t0))+pfgd->fg_offset[ichan];
            } else {
                return 0.0;
            }
        case CHIRP:
#define EPS 0.000001
            if ( pfgd->fg_power[ichan]==1 ) {
//		        actual time
                tim=t-pfgd->fg_t0;
    
//		        check frequency bounds
//		        lower frequency
                f1=pfgd->fg_freq1[ichan];
//	    	    upper frequency
                f2=0.5*(f1+pfgd->fg_freq2[ichan]);

                n=nearest(2.0*f2*pfgd->fg_obsiv);
	    	    if (n==0) {n=1;}
                f2=((double) n)/(2.0*pfgd->fg_obsiv);

//	   	        new bandwidth
                pfgd->fg_freq2[ichan]=2.0*(f2-0.5*f1);
//		        bandwidth should be non-negative
                if ( pfgd->fg_freq2[ichan]<0.0 ) { pfgd->fg_freq2[ichan]=0.0; }

//		        frame id
                iframe=((int) ((t-pfgd->fg_t0+EPS)/pfgd->fg_obsiv))+1;
//		        adjust time
                tim=tim-((double) (iframe-1))*pfgd->fg_obsiv;
//	    	    linearly increasing frequency
                f2=0.5*(pfgd->fg_freq1[ichan]+pfgd->fg_freq2[ichan]);
                a=(f2-pfgd->fg_freq1[ichan])/pfgd->fg_obsiv;
                b=pfgd->fg_freq1[ichan];
                freq=a*tim+b;
                return pfgd->fg_amp1[ichan]*sin(2*PI*freq*tim)+pfgd->fg_offset[ichan];
            } else {
                return 0.0;
            }
        case MULTISINE:
            if ( pfgd->fg_power[ichan]==1 ) {
//		        actual time
                tim=t-pfgd->fg_t0;

//		        check frequency bounds
                k1=nearest(pfgd->fg_freq1[ichan]*pfgd->fg_obsiv);
                if (k1==0) {k1=1;}
                pfgd->fg_freq1[ichan]=((double) k1)/pfgd->fg_obsiv;
                k2=nearest(pfgd->fg_freq2[ichan]*pfgd->fg_obsiv);
                if (k2==0) {k2=1;}
                pfgd->fg_freq2[ichan]=((double) k2)/pfgd->fg_obsiv;
//		        line bounds
                nlines=k2-k1+1;
                sum=0.0;
                for (k=k1;k<k1+nlines;k++) {
                    sum=sum+(pfgd->fg_amp1[ichan]/sqrt((double) nlines))*sin(2*PI*k*tim/pfgd->fg_obsiv+pfgd->fg_phase[ichan][k]);
                }
                return sum+pfgd->fg_offset[ichan];
            } else {
                return 0.0;
            }
        case WHISTLE:
//		    return 0.0;
            if ( pfgd->fg_power[ichan]==1 ) {
//		        actual time
                tim=t-pfgd->fg_t0;

//		        lowest spectral line
                k1=nearest(pfgd->fg_freq1[ichan]*pfgd->fg_obsiv);
                if (k1==0) {k1=1;}

//		        highest spectral line
                k2=nearest(pfgd->fg_freq2[ichan]*pfgd->fg_obsiv);
                if (k2==0) {k2=1;}
		    
//		        k2 should be greater or equal k1
                if (k1>k2) {k2=k1;};

//		        frame id
                iframe=((int) ((t-pfgd->fg_t0+EPS)/pfgd->fg_obsiv))+1;
//		        adjust time
                tim=tim-((double) (iframe-1))*pfgd->fg_obsiv;
                while (iframe>0) {
                    iframe=iframe-(k2-k1+1);
                }
                iframe=iframe+(k2-k1+1);
		    
//		        actual spectral line
                pfgd->fg_k[ichan]=k1+(iframe-1);

                return pfgd->fg_amp1[ichan]*sin(2*PI*pfgd->fg_k[ichan]*tim/pfgd->fg_obsiv)+pfgd->fg_offset[ichan];
            } else {
                return 0.0;
            }
        default:
            return 0.0;
	}
}





int fg_start(int ichan, pfungen_data pfgd)
{
	if ( pfgd->fg_type[ichan]==RAND ) {
		srand((unsigned) time(NULL));
	}
	
	pfgd->fg_power[ichan]=1;
 
    pfgd->fg_onoff = 0;
    pfgd->fg_ilinked = 0;
    pfgd->fg_t0 = 0.0;

	return 0;
}





int fg_stop(int ichan, pfungen_data pfgd)
{
	pfgd->fg_power[ichan]=0;

	return 0;
}





int fg_status(int ichan, pfungen_data pfgd)
{
	return pfgd->fg_power[ichan];
}





int fg_set_defaults(pfungen_data pfgd)
{
	int i,j;

	pfgd->fg_onoff=0;
	
	for (i=0;i<MAXCHAN;i++) {
		pfgd->fg_power[i]=0;
		pfgd->fg_type[i]=SINE;
		pfgd->fg_amp1[i]=1.0;
		pfgd->fg_amp2[i]=1.0;
		pfgd->fg_freq1[i]=1.0;
		pfgd->fg_freq2[i]=1.0;
		pfgd->fg_offset[i]=0.0;
		pfgd->fg_std[i]=1.0;
		fir_init(i, &pfgd->fd);
		pfgd->fg_k[i]=1;
		for (j=0;j<MAXFRAME;j++) {
//			random phase between +-PI
			pfgd->fg_phase[i][j]=PI*2.0*( ((double) rand())/((double) RAND_MAX)-0.5);
		}
	}
	
//	initialize clock
	fgc_reset_time(pfgd);
	
	return 0;
}





int fg_set_amp1(double amp, int ichan, pfungen_data pfgd)
{
	pfgd->fg_amp1[ichan]=amp;

	return 0;
}





int fg_get_amp1(double* amp, int ichan, pfungen_data pfgd)
{
	amp[0]=pfgd->fg_amp1[ichan];

	return 0;
}





int fg_set_amp2(double amp, int ichan, pfungen_data pfgd)
{
	pfgd->fg_amp2[ichan]=amp;

	return 0;
}





int fg_get_amp2(double* amp, int ichan, pfungen_data pfgd)
{
	amp[0]=pfgd->fg_amp2[ichan];

	return 0;
}





int fg_set_freq1(double freq, int ichan, pfungen_data pfgd)
{
	int ittt,n;

//	temporary power off
	ittt=pfgd->fg_power[ichan];
	pfgd->fg_power[ichan]=0;

	if ((pfgd->fg_type[ichan]==MULTISINE) | (pfgd->fg_type[ichan]==WHISTLE)) {
//	    adjust multisine frequency bound
	    n=nearest(freq*pfgd->fg_obsiv);
	    if (n==0) {n=1;}
	    freq=((double) n)/pfgd->fg_obsiv;

	    if ( pfgd->fg_type[ichan]==MULTISINE ) {
//	        maximum bandwidth is 256 spectral lines due to cpu effort
	        if ( (pfgd->fg_freq2[ichan]-freq)>(255.0/pfgd->fg_obsiv) ) {
		    freq=pfgd->fg_freq2[ichan]-(255.0/pfgd->fg_obsiv);
		    if (freq<=0.0) {freq=1.0/pfgd->fg_obsiv;}
		}
	    }
	}

	pfgd->fg_freq1[ichan]=freq;

	if ( pfgd->fg_type[ichan]==RAND ) {
//		design new fir filter
		fir_design(freq/pfgd->fg_maxfreq, ichan, &pfgd->fd);
	}

//	restore power setting
	pfgd->fg_power[ichan]=ittt;
	
	return 0;
}





int fg_get_freq1(double* freq, int ichan, pfungen_data pfgd)
{
	freq[0]=pfgd->fg_freq1[ichan];

	return 0;
}





int fg_set_freq2(double freq, int ichan, pfungen_data pfgd)
{
	int ittt,n;
	double f1,f2;

//	temporary power off
	ittt=pfgd->fg_power[ichan];
	pfgd->fg_power[ichan]=0;
	
	if ( pfgd->fg_type[ichan]==CHIRP ) {
//	    adjust chirp bandwidth
//	    lower frequency
	    f1=pfgd->fg_freq1[ichan];
//	    upper frequency
	    f2=0.5*(f1+freq);

	    n=nearest(2.0*f2*pfgd->fg_obsiv);
	    if (n==0) {n=1;}
	    f2=((double) n)/(2.0*pfgd->fg_obsiv);

//	    new bandwidth
	    freq=2.0*(f2-0.5*f1);
//	    bandwidth should be non-negative	    
	    if (freq<0.0) {freq=0.0;}
	}

	if ((pfgd->fg_type[ichan]==MULTISINE) | (pfgd->fg_type[ichan]==WHISTLE)) {
//          adjust multisine frequency bound
	    n=nearest(freq*pfgd->fg_obsiv);
	    if (n==0) {n=1;}
	    freq=((double) n)/pfgd->fg_obsiv;

	    if ( pfgd->fg_type[ichan]==MULTISINE ) {
//	        maximum bandwidth is 256 spectral lines due to cpu effort
            if ( (freq-pfgd->fg_freq1[ichan])>(255.0/pfgd->fg_obsiv) ) {
                freq=pfgd->fg_freq1[ichan]+(255.0/pfgd->fg_obsiv);
            }
	    }
	    
	    if ( pfgd->fg_type[ichan]==WHISTLE ) {
//		    freq2 should be greater or equal freq1
            if (freq<pfgd->fg_freq1[ichan]) {
                freq=pfgd->fg_freq1[ichan];
            }
	    }
	    
	}

	pfgd->fg_freq2[ichan]=freq;

//	restore power setting
	pfgd->fg_power[ichan]=ittt;

	return 0;
}





int fg_get_freq2(double* freq, int ichan, pfungen_data pfgd)
{
	freq[0]=pfgd->fg_freq2[ichan];

	return 0;
}





int fg_set_offset(double offset, int ichan, pfungen_data pfgd)
{
	pfgd->fg_offset[ichan]=offset;

	return 0;
}





int fg_get_offset(double* offset, int ichan, pfungen_data pfgd)
{
	offset[0]=pfgd->fg_offset[ichan];

	return 0;
}




int fg_set_type(int itype, int ichan, pfungen_data pfgd)
{
	int ittt;
	
//	temporary power off
	ittt=pfgd->fg_power[ichan];
	pfgd->fg_power[ichan]=0;

	pfgd->fg_type[ichan]=itype;

	if ( pfgd->fg_type[ichan]==RAND ) {
//		design new fir filter
		fir_design(pfgd->fg_freq1[ichan], ichan, &pfgd->fd);
	}

//	restore power setting
	pfgd->fg_power[ichan]=ittt;

	return 0;
}




int fg_get_type(double* type, int ichan, pfungen_data pfgd)
{
	type[0]=(double) pfgd->fg_type[ichan];

	return 0;
}





int fg_set_onoff(int ipower, pfungen_data pfgd)
{
	if ( ipower==1 ) {
//		time line restarts at zero
		fgc_reset_time(pfgd);
		pfgd->fg_time=0.0;
	}

	pfgd->fg_onoff=ipower;
		
	return 0;
}




int fg_get_onoff(double* power, pfungen_data pfgd)
{
	power[0]=(double) pfgd->fg_onoff;

	return 0;
}





int fg_notify(int link_is_active, pfungen_data pfgd)
{
	if (link_is_active==1) {
		pfgd->fg_link_is_active=1;
	} else {
        pfgd->fg_link_is_active=0;
	}
	
	return 0;
}





#if 0
#define MAXHOLDORDER	3

int fg_set_hold_order(int holdorder, int ichan)
{
	int ilink;

	if (fg_is_simulink) {
	    return 0;
	}

//	find link id (assumes ilink 0 or 1)
	if (ichan<2) {
	    ilink=0;
	} else {
	    ichan=ichan-2;
	    ilink=1;
	}
	
	if (holdorder>MAXHOLDORDER) {
//	    hardware hoh
	    holdorder=holdorder-MAXHOLDORDER;
//	    set hoh order
	    td_dac_set_filter_order_chan(holdorder,ichan,ilink,TD_CACHED);
//	    switch on hardware hoh
	    td_dac_set_filter_enable_chan(1,ichan,ilink,TD_CACHED);
	} else {
//	    switch off hardware hoh
	    td_dac_set_filter_enable_chan(0,ichan,ilink,TD_CACHED);
//	    set hold order
	    td_dac_set_filter_order_chan(holdorder,ichan,ilink,TD_CACHED);
	}
	
	return 0;
}





int fg_get_hold_order(double* pholdorder, int ichan)
{
	int ienable;
	int iorder;
	int ilink;
    
	if (fg_is_simulink) {
	    pholdorder[0]=0.0;
	    return 0;
	}

//	find link id (assumes ilink 0 or 1)
	if (ichan<2) {
	    ilink=0;
	} else {
	    ichan=ichan-2;
	    ilink=1;
	}

//	get hold order
        td_dac_get_filter_order_chan(&iorder,ichan,ilink);
//	check for hardware hoh
	td_dac_get_filter_enable_chan(&ienable,ichan,ilink);
	
	if (ienable==1) {
//		hardware hoh
	 	pholdorder[0]=(double) (iorder+MAXHOLDORDER);
	} else {
//		software hoh
	 	pholdorder[0]=(double) iorder;	
	}
	
	return 0;
}
#endif

/* MRonde (20110503) Empty functions to enable compiling */
int fg_set_hold_order(int holdorder, int ichan)
{
    return 0;
}

int fg_get_hold_order(double* pholdorder, int ichan)
{
    return 0;
}



int fg_put_maxfreq(double maxfreq, pfungen_data pfgd)
{
    pfgd->fg_maxfreq=maxfreq;

    return 0;
}





int fg_put_obsiv(double obsiv, pfungen_data pfgd)
{
    pfgd->fg_obsiv=obsiv;
    
    return 0;
}





int fg_put_issim(int is_simulink, pfungen_data pfgd)
{
    pfgd->fg_is_simulink=is_simulink;

    return 0;
}
