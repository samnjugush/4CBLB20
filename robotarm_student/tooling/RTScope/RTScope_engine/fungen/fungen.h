
#ifndef FUNGEN_H
#define FUNGEN_H

#include "../constants.h"
#include "../fir/fir.h"
#include <sys/time.h>

/* macros */
#define SINE		1
#define RAND		2
#define SQUARE		3
#define TWOTONE		4
#define CHIRP		5
#define MULTISINE	6
#define WHISTLE		7
#define PI		3.14159265358979





typedef struct tag_fungen_t {
    int fg_type[MAXCHAN];
    int fg_power[MAXCHAN];
    int fg_onoff;
    double fg_amp1[MAXCHAN];
    double fg_amp2[MAXCHAN];
    double fg_freq1[MAXCHAN];
    double fg_freq2[MAXCHAN];
    double fg_std[MAXCHAN];
    double fg_offset[MAXCHAN];
    double fg_maxfreq;
    double fg_obsiv;
    double fg_phase[MAXCHAN][MAXFRAME];
    int fg_k[MAXCHAN];
    int fg_is_simulink;
    double fg_time;
    int fg_ilinked;
    double fg_t0;
    int fg_link_is_active;
    struct timeval tv0, tva;
    fir_data fd;
} fungen_data, *pfungen_data;





/* prototypes */
double fg_get_val(double, int, pfungen_data pfgd);
int fg_start(int, pfungen_data pfgd);
int fg_stop(int, pfungen_data pfgd);
int fg_status(int, pfungen_data pfgd);
int fg_set_defaults(pfungen_data pfgd);
int fg_set_amp1(double, int, pfungen_data pfgd);
int fg_get_amp1(double*, int, pfungen_data pfgd);
int fg_set_amp2(double, int, pfungen_data pfgd);
int fg_get_amp2(double*, int, pfungen_data pfgd);
int fg_set_freq1(double, int, pfungen_data pfgd);
int fg_get_freq1(double*, int, pfungen_data pfgd);
int fg_set_freq2(double, int, pfungen_data pfgd);
int fg_get_freq2(double*, int, pfungen_data pfgd);
int fg_set_offset(double, int, pfungen_data pfgd);
int fg_get_offset(double*, int, pfungen_data pfgd);
int fg_set_type(int, int, pfungen_data pfgd);
int fg_get_type(double*, int, pfungen_data pfgd);
int fg_set_onoff(int, pfungen_data pfgd);
int fg_get_onoff(double*, pfungen_data pfgd);
int fg_notify(int, pfungen_data pfgd);
int fg_set_hold_order(int, int);
int fg_get_hold_order(double*, int);
int fg_put_maxfreq(double, pfungen_data pfgd);
int fg_put_obsiv(double, pfungen_data pfgd);
int fg_put_issim(int, pfungen_data pfgd);

#endif
