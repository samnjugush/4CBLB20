
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





int incomm_server_open(int port_id)
{
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    int sin_size;
    int len;

//  get socket file descriptor
    if ( (sockfd1=socket(AF_INET, SOCK_STREAM, 0)) ==-1 ) {
	perror("incomm_server_open: call to socket failed");
	return -1;
    }

//  bind
    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(port_id);
//    my_addr.sin_port=htons(0);
//  my_addr.sin_addr.s_addr=INADDR_ANY;
//  inet_aton("127.0.0.1", &(my_addr.sin_addr));
    my_addr.sin_addr.s_addr=INADDR_ANY;
    memset(&(my_addr.sin_zero),'\0',8);
    
    if (bind(sockfd1, (struct sockaddr*) &my_addr, sizeof(struct sockaddr))==-1 ) {
	perror("incomm_server_open: call to bind failed");
	return -1;
    }
    
//  listen
    if (listen(sockfd1,BACKLOG)==-1) {
	perror("incomm_server_open: call to listen failed");
	return -1;
    }

//  accept
//    sin_size=sizeof(struct sockaddr_in);
//    if ( (new_fd=accept(sockfd1, (struct sockaddr*) &their_addr, &sin_size)) == -1 ) {
//	perror("incomm_server_open: call to socket failed");
//    	return -1;
//    }

    return 0;
}





int incomm_server_read(void* pdata, int len_in_bytes)
{
    int len,totlen,ipass;
    struct sockaddr_in their_addr;
    int sin_size;

    totlen=0;
    ipass=0;

//  accept
    sin_size=sizeof(struct sockaddr_in);
    if ( (new_fd=accept(sockfd1, (struct sockaddr*) &their_addr, &sin_size)) == -1 ) {
	perror("incomm_server_open: call to socket failed");
    	return -1;
    }
    
    while (totlen<len_in_bytes) {    
    	if ( (len=recv(new_fd,pdata+totlen,len_in_bytes,0)) == -1 ) {
		perror("incomm_server_read: call to recv failed");
		return -1;
    	}
	if (len==0) {
		printf("incomm_server_read: client disconnected.\n");
		return -1;
	}	
    	totlen=totlen+len;
	ipass++;
    }

    printf("incomm_server_read: data read in %d passes.\n",ipass);

    return 0;
}





int incomm_server_write(void* pdata, int len_in_bytes)
{    
    if ( send(new_fd,pdata,len_in_bytes,0)==-1 ) {
    	perror("incomm_server_write: call to send fails");
	return -1;
    }

    return 0;
}





int incomm_server_close(void)
{
    close(new_fd);
    close(sockfd1);

    return 0;
}





int incomm_client_open(int port_id)
{
    struct sockaddr_in dest_addr;
    struct sockaddr_in their_addr;
    int sin_size;
    int len;

//  get socket file descriptor
    if ( (sockfd2=socket(AF_INET, SOCK_STREAM, 0)) ==-1 ) {
	perror("incomm_client_open: call to socket failed");
	return -1;
    }

//  bind
    dest_addr.sin_family=AF_INET;
    dest_addr.sin_port=htons(port_id);
//    dest_addr.sin_port=htons(0);
//    inet_aton("127.0.0.1", &(dest_addr.sin_addr));
    dest_addr.sin_addr.s_addr=INADDR_ANY;
    memset(&(dest_addr.sin_zero),'\0',8);
    
    if ( connect(sockfd2, (struct sockaddr*) &dest_addr, sizeof(struct sockaddr)) == -1 ) {
	perror("incomm_client_open: call to connect fails");
	return -1;
    }

    return 0;
}





int incomm_client_read(void* pdata, int len_in_bytes)
{
    int len,totlen,ipass;
    
    totlen=0;
    ipass=0;
    
    while (totlen<len_in_bytes) {    
    	if ( (len=recv(sockfd2,pdata+totlen,len_in_bytes,0)) == -1 ) {
		perror("incomm_client_read: call to recv failed");
		return -1;
    	}
	if (len==0) {
		printf("incomm_client_read: server disconnected.\n");
	}	
    	totlen=totlen+len;
	ipass++;
    }

    printf("incomm_client_read: data read in %d passes.\n",ipass);

    return 0;
}





int incomm_client_write(void* pdata, int len_in_bytes)
{    
    if ( send(sockfd2,pdata,len_in_bytes,0)==-1 ) {
    	perror("incomm_client_write: call to send fails");
	return -1;
    }

    return 0;
}




int incomm_client_close(void)
{
    close(sockfd2);
    
    return 0;
}
