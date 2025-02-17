
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */

#include <time.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */

/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void getSystemClockTimeval_Outputs_wrapper(real_T *y2)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */

/* The POSIX command gettimeofday() populates a timeval struct defined as:
 *
 *      struct timeval {
 *          time_t      tv_sec;     // seconds
 *          suseconds_t tv_usec;    // microseconds
 *      };
 *
 * gettimeofday() requires #include <sys/time.h>
 *
 * Marc Compere, comperem@gmail.com
 * 15 Dec 2015
 */

struct timeval tv; // declare a timeval struct

gettimeofday(&tv, (struct timezone *) 0); /* populate timeval struct */

y2[0] = (double) tv.tv_sec+(tv.tv_usec/1.0e6); /* output combined seconds since Jan 01, 1970 */
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


