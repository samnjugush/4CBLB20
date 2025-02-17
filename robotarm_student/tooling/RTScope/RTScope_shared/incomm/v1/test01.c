
#include "incomm.h"

#define LEN	10

int main(void)
{
    int buf[LEN],i;
    
    read_open();
    
    read_data((void*) buf, LEN*sizeof(int));

    read_close();
    
    for (i=0;i<LEN;i++) {
	printf("buf[%d] = %d\n",i,buf[i]);
    }

    sleep(1);
    
    write_open();
    
    write_data((void*) buf, LEN*sizeof(int));
    
    write_close();
    
    return 0;
}
