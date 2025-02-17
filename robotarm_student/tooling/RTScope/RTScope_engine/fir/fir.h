
#ifndef FIR_H
#define FIR_H

// macros
#define FIRNTAPS	101
#define FIRNBANDS	2
#define BANDPASS	1
#define MAXFIR		10





typedef struct tag_fir_t {
//  input buffer index
    int fir_idx_x[MAXFIR];
//  input buffer
    double fir_x[FIRNTAPS][MAXFIR];
//  fir
    double fir_h[FIRNTAPS][MAXFIR];
} fir_data, *pfir_data;





/* prototypes */
int fir_init(int, pfir_data);
int fir_design(double, int, pfir_data);
double fir_filter(double, int, pfir_data);

#endif
