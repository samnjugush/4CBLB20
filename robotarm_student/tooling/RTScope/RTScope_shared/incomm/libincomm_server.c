
// shared library for network communication
// Rene' van de Molengraft, June, 21th, 2005

#include <sys/types.h>
#ifdef WINDOWS
#include <winsock2.h>
#include <ws2tcpip.h>
#include <wininet.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "incomm.h"

#define BACKLOG		10
#define MY_PORT		2039
#define DEST_PORT	2039

static int sockfd1, new_fd;





int incomm_server_open(int port_id)
{
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    int sin_size;
    int len, yes=1;

//  get socket file descriptor
    if ( (sockfd1=socket(AF_INET, SOCK_STREAM, 0)) ==-1 ) {
        perror("incomm_server_open: call to socket failed");
        return INCOMM_ERR;
    }

//  bind
    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(port_id);
//    my_addr.sin_port=htons(0);
//  my_addr.sin_addr.s_addr=INADDR_ANY;
//  inet_aton("127.0.0.1", &(my_addr.sin_addr));
    my_addr.sin_addr.s_addr=INADDR_ANY;
    memset(&(my_addr.sin_zero),'\0',8);

    if ( setsockopt(sockfd1,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))==-1 ) {
        perror("incomm_server_open: call to setsockopt failed");
        return INCOMM_ERR;
    }

    if (bind(sockfd1, (struct sockaddr*) &my_addr, sizeof(struct sockaddr))==-1 ) {
        perror("incomm_server_open: call to bind failed");
        return INCOMM_ERR;
    }
    
//  listen
    if (listen(sockfd1,BACKLOG)==-1) {
	perror("incomm_server_open: call to listen failed");
	return INCOMM_ERR;
    }

//  accept
//    sin_size=sizeof(struct sockaddr_in);
//    if ( (new_fd=accept(sockfd1, (struct sockaddr*) &their_addr, &sin_size)) == -1 ) {
//	perror("incomm_server_open: call to socket failed");
//    	return -1;
//    }

    return INCOMM_SUCCESS;
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
    	return INCOMM_ERR;
    }
    
    while (totlen<len_in_bytes) {    
    	if ( (len=recv(new_fd,pdata+totlen,len_in_bytes,0)) == -1 ) {
		perror("incomm_server_read: call to recv failed");
		return INCOMM_ERR;
    	}
	if (len==0) {
		printf("incomm_server_read: client disconnected.\n");
		return INCOMM_ERR;
	}	
    	totlen=totlen+len;
	ipass++;
    }

//    printf("incomm_server_read: data read in %d passes.\n",ipass);

    return INCOMM_SUCCESS;
}





int incomm_server_write(void* pdata, int len_in_bytes)
{    
    if ( send(new_fd,pdata,len_in_bytes,0)==-1 ) {
    	perror("incomm_server_write: call to send fails");
        return INCOMM_ERR;
    }

    return INCOMM_SUCCESS;
}





int incomm_server_close2(void)
{
#ifdef WINDOWS
    closesocket(new_fd);
#else
    close(new_fd);
#endif
    
    return INCOMM_SUCCESS;
}





int incomm_server_close(void)
{
#ifdef WINDOWS
    closesocket(new_fd);
    closesocket(sockfd1);
#else
    close(new_fd);
    close(sockfd1);
#endif
    
    return INCOMM_SUCCESS;
}
