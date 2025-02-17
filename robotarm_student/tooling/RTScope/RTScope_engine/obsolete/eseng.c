/* 
 * Filename: eseng 
 * 
 * Abstract: Start application for E-scope engine 
 * 
 * Usage: sudo ./eseng fs nsamp dac_ndown netif
 *
 * Example: sudo ./eseng 4096 1024 1 eth0
 * 
 * Inputs: 
 *  fs           -   Sample frequency (Hz)
 *  nsamp        -   Number of samples
 *  dac_ndown    -   Downsampling factor for DAC
 *                   0 - No downsampling
 *                   1 - 1 sample  ignored, i.e. downsampling factor 2
 *                   3 - 3 samples ignored, i.e. downsampling factor 4
 *  netif        -   Name of network interface  
 * 
 * Outputs: 
 * 
 * References: 
 * 
 * Michael Ronde: 
 * (2011-08-31) 

 * Changes: 
 * 2011-05-11 Initial version 
 * 2011-05-29 Added commandline parameters 
 * 2011-08-31 Changed default DAC downsampling and corrected comments
 * 
 * ________________________________
 * Eindhoven University of Technology
 * Dept. of Mechanical Engineering
 * Control Systems Technology group
 * PO Box 513, WH -1.127
 * 5600 MB Eindhoven, NL
 * T +31 (0)40 247 2798
 * F +31 (0)40 246 1418
 * E m.j.c.ronde@tue.nl
 */ 

#define DEBUG 
 
#include <stdio.h> 
#include <stdlib.h> 
#include "engine.h" 
 
int main(int argc, char *argv[]) 
{    
    int i; 
    double fs,nsamp,dac_ndown; 
    char* netif; 
     
 
#ifdef DEBUG     
    for(i=0; i < argc; i++){ 
        printf("%s\n",argv[i]); 
    } 
#endif 
     
    if(argc >= 5){ 
        fs          =   atof(argv[1]); 
        nsamp       =   atof(argv[2]); 
        dac_ndown   =   atof(argv[3]); 
        netif       =   argv[4]; 
#ifdef DEBUG         
        printf("Starting parameters %f %f %f %s\n",fs,nsamp,dac_ndown,netif); 
#endif         
        printf("Starting acquisition \n"); 
        tde_start_acq(fs, nsamp, dac_ndown, netif); 
        printf("Endof starting acquisition \n");         
    } else { 
        printf("Usage: ./eseng 4096 4096 0 eth0\n"); 
        printf("Using standard values \n");
        tde_start_acq(4096.0 , 4096.0, 0,"eth0");
    } 
     
 
    return 0; 
} 
 
