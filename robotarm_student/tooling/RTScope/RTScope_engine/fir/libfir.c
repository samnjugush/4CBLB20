
// fir filter library

// Ren� van de Molengraft, March, 2004
// Revision history: March, 5th, 2004: start
//		     June, 30th, 2004: linux port

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "fir.h"
#include "../remez/remez.h"

//FILE *fp={NULL};

// void _init()
// {
// }





// void _fini()
// {
// }





double getmax(double x, double y)
{
	if (x>=y) {
		return x;
	} else {
		return y;
	}
}





double getmin(double x, double y)
{
	if (x<=y) {
		return x;
	} else {
		return y;
	}
}





int fir_init(int ichan, pfir_data pfd)
{
	int j;
	
	pfd->fir_idx_x[ichan]=0;

	for (j=0;j<FIRNTAPS;j++) {
		pfd->fir_h[j][ichan]=0;
		pfd->fir_x[j][ichan]=0;
	}

	fir_design(1.0, ichan, pfd);

	return FIRNTAPS;
}





int fir_design(double rel_stop_freq, int ichan, pfir_data pfd) {

	double *h,*weights,*desired,*bands;
	int i;

	if (ichan>=MAXFIR) {
		printf("fir_design: only %d channels\n",MAXFIR);
		return 1;
	}

	bands=(double*) malloc(2*FIRNBANDS*sizeof(double));
	weights=(double*) malloc(FIRNBANDS*sizeof(double));
	desired=(double*) malloc(FIRNBANDS*sizeof(double));
	h=(double*) malloc(FIRNTAPS*sizeof(double));

	desired[0]=1.0;
	desired[1]=0.0001; 

	weights[0]=1.0;
	weights[1]=1.0;

//	bound rel_freq to prevent numerical problems with remez...
	rel_stop_freq=getmax(rel_stop_freq, 0.025);
	rel_stop_freq=getmin(rel_stop_freq, 0.450);

	bands[0]=0.0;
	bands[1]=rel_stop_freq;
	bands[2]=rel_stop_freq+0.025;
	bands[3]=0.5;

//	fp=fopen("fg.log","w");
//	fprintf(fp,"bands[0]=%f\n",bands[0]);
//	fprintf(fp,"bands[1]=%f\n",bands[1]);
//	fprintf(fp,"bands[2]=%f\n",bands[2]);
//	fprintf(fp,"bands[3]=%f\n",bands[3]);
//	fprintf(fp,"desired[0]=%f\n",desired[0]);
//	fprintf(fp,"desired[1]=%f\n",desired[1]);
//	fprintf(fp,"weights[0]=%f\n",weights[0]);
//	fprintf(fp,"weights[1]=%f\n",weights[1]);
//	fclose(fp);
	
	remez(h,FIRNTAPS,FIRNBANDS,bands,desired,weights,BANDPASS);

	for (i=1;i<FIRNTAPS;i++) {
		pfd->fir_h[i][ichan]=h[i];
	}

	free(bands);
	free(weights);
	free(desired);
	free(h);

	return 0;
}





double fir_filter(double xn, int ichan, pfir_data pfd)
{
	int i,j;
	double yn;

	if (ichan>=MAXFIR) {
		printf("fir_filter: only %d channels\n",MAXFIR);
		return 0.0;
	}
	
	yn=0;
	
//	store xn
	if ( pfd->fir_idx_x[ichan]==FIRNTAPS ) {
		pfd->fir_idx_x[ichan]=0;
	}
	pfd->fir_x[pfd->fir_idx_x[ichan]][ichan]=xn;
	pfd->fir_idx_x[ichan]++;

//	compute filtered output yn
	j=pfd->fir_idx_x[ichan]-1;
	for ( i=0; i<FIRNTAPS; i++ ) {
		yn=yn+pfd->fir_h[i][ichan]*pfd->fir_x[j][ichan];
		j--;
		if ( j<0 ) { j=FIRNTAPS-1; }
	}

	return yn;
}
