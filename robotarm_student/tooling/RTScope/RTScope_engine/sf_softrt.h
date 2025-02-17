
#define S_FUNCTION_NAME  sf_softrt
#define S_FUNCTION_LEVEL 2

/* header files */
#include "simstruc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sched.h>
#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <errno.h>
#include <unistd.h>
//#include <pthread.h>
//#include <signal.h>
//#include <semaphore.h>

/* macro definitions */
#define NINPORTS	0
#define NOUTPORTS	1
#define NOUTPUTS        1
#define NPARAMS         1

#define SFPAR_PRIORITY(S)	ssGetSFcnParam(S,0)

#define PRIO_NORMAL     1
#define PRIO_REALTIME   2

#ifdef MATLAB_MEX_FILE
#define print	mexPrintf
#else
#define print	printf
#endif

typedef struct tag_sfun_global_data {
    real_T t0;
    struct timeval tv0, tva;
    int_T first_time;
    int_T priority;
    //sched_data sd;
} sfun_global_data, *psfun_global_data;
