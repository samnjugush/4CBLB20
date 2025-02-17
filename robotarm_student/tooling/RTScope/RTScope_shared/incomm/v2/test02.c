
#include "incomm.h"

#define LEN	100

int main(void)
{
    int buf[LEN],i,istart,j;
    
    for (i=0;i<LEN;i++) {
	buf[i]=i;
    }

    incomm_client_open(2039);
    
//    for (j=0;j<10;j++) {
    
	incomm_client_write((void*) buf, LEN*sizeof(int));

	incomm_client_read((void*) buf, LEN*sizeof(int));

	for (i=0;i<LEN;i++) {
	    printf("buf[%d] = %d\n",i,buf[i]);
	}
//    }
    
    incomm_client_close();
    
    return 0;
}
