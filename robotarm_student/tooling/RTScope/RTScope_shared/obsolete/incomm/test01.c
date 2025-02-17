#include <stdio.h>
#include "incomm.h"
/*#include "../tde_gate/shm.h"*/
#include "../RTScope_engine/engine.h"
/*#include "../shmtool_fusion/shm.h"*/

tde_shm the_shm;

int main(void)
{
    int i,istart,j;
    
    incomm_server_open(2039);
    
    for (j=0;j<10;j++) {
        
        printf("waiting for command j = %d...\n",j);
        
        // read from test02
        incomm_server_read((void*) &the_shm, sizeof(tde_shm));
        
        printf("cmd_id = %d\n",the_shm.cmd_id);
        sleep(1);
        
        // write to test02
        incomm_server_write((void*) &the_shm, sizeof(tde_shm));
    }
    
    printf("Einde j = %d\n",j);
    
    sleep(1);
    
    incomm_server_close();
    
    return 0;
}
