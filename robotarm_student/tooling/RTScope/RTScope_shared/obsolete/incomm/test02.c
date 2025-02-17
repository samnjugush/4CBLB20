#include <stdio.h>
#include "incomm.h"
/*#include "../tde_gate/shm.h"*/
#include "../engine/engine.h"
/*#include "../shmtool_fusion/shm.h"*/

#define LEN	100

int main(void)
{
    int buf[LEN],i,istart,j;
    
    for (i=0;i<LEN;i++) {
        buf[i]=i;
    }
    
    incomm_client_open("192.168.1.111", 2039);
    
    for (j=0;j<10;j++) {
        
        incomm_client_write((void*) buf, LEN*sizeof(int));
        
        incomm_client_read((void*) buf, LEN*sizeof(int));
        
        for (i=0;i<LEN;i++) {
            printf("buf[%d] = %d\n",i,buf[i]);
        }
    }
    
    incomm_client_close();
    
    return 0;
}
