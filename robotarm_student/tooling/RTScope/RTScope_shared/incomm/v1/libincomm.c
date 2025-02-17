
// shared library for network communication
// Rene' van de Molengraft, June, 21th, 2005

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BACKLOG		10
#define MY_PORT		2039
#define DEST_PORT	2039

static int sockfd1, sockfd2, new_fd;



int read_open(void)
{
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    int sin_size;
    int len;

//  get socket file descriptor
    if ( (sockfd1=socket(AF_INET, SOCK_STREAM, 0)) ==-1 ) {
	perror("read_open: call to socket failed");
	return -1;
    }

//  bind
    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(MY_PORT);
//  my_addr.sin_addr.s_addr=INADDR_ANY;
//  inet_aton("127.0.0.1", &(my_addr.sin_addr));
    my_addr.sin_addr.s_addr=INADDR_ANY;
    memset(&(my_addr.sin_zero),'\0',8);
    
    if (bind(sockfd1, (struct sockaddr*) &my_addr, sizeof(struct sockaddr))==-1 ) {
	perror("read_open: call to bind failed");
	return -1;
    }
    
//  listen
    if (listen(sockfd1,BACKLOG)==-1) {
	perror("read_open: call to listen failed");
	return -1;
    }

//  accept
    sin_size=sizeof(struct sockaddr_in);
    if ( (new_fd=accept(sockfd1, (struct sockaddr*) &their_addr, &sin_size)) == -1 ) {
	perror("read_open: call to socket failed");
    	return -1;
    }

    return 0;
}





int read_data(void* pdata, int len_in_bytes)
{
    int len,totlen,ipass;
    
    totlen=0;
    ipass=0;
    
    while (totlen<len_in_bytes) {    
    	if ( (len=recv(new_fd,pdata+totlen,len_in_bytes,0)) == -1 ) {
		perror("read_data: call to recv failed");
		return -1;
    	}
	if (len==0) {
		printf("read_data: client disconnected.\n");
	}	
    	totlen=totlen+len;
	ipass++;
    }

    printf("read_data: data read in %d passes.\n",ipass);

    printf("read_data: waiting for client to disconnect...\n");

    if ( (len=recv(new_fd,pdata+totlen,len_in_bytes,0)) == -1 ) {
	perror("read_data: call to recv failed");
	return -1;
    }
    
    printf("read_data: client disconnected.\n");

    return 0;
}





int read_close(void)
{
    close(new_fd);
    close(sockfd1);

    return 0;
}





int write_open(void)
{
    struct sockaddr_in dest_addr;
    struct sockaddr_in their_addr;
    int sin_size;
    int len;

//  get socket file descriptor
    if ( (sockfd2=socket(AF_INET, SOCK_STREAM, 0)) ==-1 ) {
	perror("write_open: call to socket failed");
	return -1;
    }

//  bind
    dest_addr.sin_family=AF_INET;
    dest_addr.sin_port=htons(DEST_PORT);
//    inet_aton("127.0.0.1", &(dest_addr.sin_addr));
    dest_addr.sin_addr.s_addr=INADDR_ANY;
    memset(&(dest_addr.sin_zero),'\0',8);
    
    if ( connect(sockfd2, (struct sockaddr*) &dest_addr, sizeof(struct sockaddr)) == -1 ) {
	perror("write_open: call to connect fails");
	return -1;
    }

    return 0;
}




int write_data(void* pdata, int len_in_bytes)
{    
    if ( send(sockfd2,pdata,len_in_bytes,0)==-1 ) {
    	perror("write_data: call to send fails");
	return -1;
    }

    return 0;
}




int write_close(void)
{
    close(sockfd2);
    
    return 0;
}

