
#include <math.h>
#include <mex.h>
#include "../shmtool_fusion/shm.h"
#include "../incomm/incomm.h"
#include <matrix.h>

void mexFunction(int nlhs, mxArray *plhs[], 
		 int nrhs, const mxArray *prhs[])
{ 
	mexPrintf("Hier!!!\n");

	if (nrhs==0) {
		mexErrMsgTxt("At least one input argument required.\n");
	}


	return;
}
