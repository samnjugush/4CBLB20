
#include "incomm.h"

#define LEN	100

int main(void)
{
    int buf[LEN],i,istart,j;
    
    incomm_server_open(2039);

    for (j=0;j<100;j++) {

	printf("j = %d\n",j);

//  	read from test02
	incomm_server_read((void*) buf, LEN*sizeof(int));

	for (i=0;i<LEN;i++) {
	    printf("buf[%d] = %d\n",i,buf[i]);
	}
    
//  	write to test02
	incomm_server_write((void*) buf, LEN*sizeof(int));
    }
    
    printf("Einde j = %d\n",j);

    sleep(1);
    
    incomm_server_close();
    
    return 0;
}
