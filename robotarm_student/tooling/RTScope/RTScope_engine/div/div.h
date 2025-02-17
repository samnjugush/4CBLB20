#ifndef DIV
#define DIV

/* prototypes */

double** create_double_matrix(int, int);
void destroy_double_matrix(double **, int, int);
void print_double_matrix(double **, int, int);
int mat_invert(double **, double **, int);
int mat_mult(double **, double **, int, int, double **, int);
int mat_transp(double **, double **, int, int);
int polyfit(double **, double **, double **, int, int);
int polyfit0(double **, double **, double **, int, int);
void polyget(double **, double, double **, int);
int minfun(double *, int, double (*)(double []));

#endif
