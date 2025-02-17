
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

static int sockfd2;





#ifdef WINDOWS123
int inet_pton(int af, const char *src, void *dst)
{
  struct sockaddr_storage ss;
  int size = sizeof(ss);
  char src_copy[INET6_ADDRSTRLEN+1];

  ZeroMemory(&ss, sizeof(ss));
  /* stupid non-const API */
  strncpy (src_copy, src, INET6_ADDRSTRLEN+1);
  src_copy[INET6_ADDRSTRLEN] = 0;

  if (WSAStringToAddress(src_copy, af, NULL, (struct sockaddr *)&ss, &size) == 0) {
    switch(af) {
      case AF_INET:
    *(struct in_addr *)dst = ((struct sockaddr_in *)&ss)->sin_addr;
    return 1;
      case AF_INET6:
    *(struct in6_addr *)dst = ((struct sockaddr_in6 *)&ss)->sin6_addr;
    return 1;
    }
  }
  return 0;
}
#endif





int incomm_client_open(const char* ip, int port_id)
{
    struct sockaddr_in dest_addr;
    struct sockaddr_in their_addr;
    int sin_size;
    int len;

//  get socket file descriptor
    if ( (sockfd2=socket(AF_INET, SOCK_STREAM, 0)) ==-1 ) {
//	perror("incomm_client_open: call to socket failed");
//	mexPrintf("incomm_client_open: call to socket failed.\n");
        return INCOMM_ERR;
    }

//  bind
    dest_addr.sin_family=AF_INET;
    dest_addr.sin_port=htons(port_id);
    
    //dest_addr.sin_port=htons(0);
#ifdef WINDOWS
    inet_pton(AF_INET, ip, &(dest_addr.sin_addr));
    //InetPton(AF_INET, ip, &(dest_addr.sin_addr));
#else
    inet_aton(ip, &(dest_addr.sin_addr));
#endif

    //dest_addr.sin_addr.s_addr=INADDR_ANY;
    memset(&(dest_addr.sin_zero),'\0',8);
    
    if ( connect(sockfd2, (struct sockaddr*) &dest_addr, sizeof(struct sockaddr)) == -1 ) {
//	perror("incomm_client_open: call to connect fails");
//	mexPrintf("incomm_client_open: call to connect fails.\n");
#ifdef WINDOWS
    closesocket(sockfd2);
#else
	close(sockfd2);
#endif
	return INCOMM_ERR;
    }

//    mexPrintf("Client connection opened.\n");

    return INCOMM_SUCCESS;
}





int incomm_client_read(void* pdata, int len_in_bytes)
{
    int len,totlen,ipass;
    
    totlen=0;
    ipass=0;
    
    while (totlen<len_in_bytes) {    
    	if ( (len=recv(sockfd2,pdata+totlen,len_in_bytes,0)) == -1 ) {
//		perror("incomm_client_read: call to recv failed");
//		mexPrintf("incomm_client_read: call to recv failed.\n");
#ifdef WINDOWS
        closesocket(sockfd2);
#else
		close(sockfd2);
#endif
		return INCOMM_ERR;
    	}
	if (len==0) {
//		mexPrintf("incomm_client_read: server disconnected.\n");
#ifdef WINDOWS
        closesocket(sockfd2);
#else
		close(sockfd2);
#endif
		return INCOMM_ERR;
	}	
    	totlen=totlen+len;
	ipass++;
    }

//    mexPrintf("incomm_client_read: data read in %d passes.\n",ipass);

    return INCOMM_SUCCESS;
}





int incomm_client_write(void* pdata, int len_in_bytes)
{    
    if ( send(sockfd2,pdata,len_in_bytes,0)==-1 ) {
//    	perror("incomm_client_write: call to send fails");
//    	mexPrintf("incomm_client_write: call to send fails.\n");
#ifdef WINDOWS
        closesocket(sockfd2);
#else
        close(sockfd2);
#endif    
        return INCOMM_ERR;
    }

//    mexPrintf("Client write ready.\n");

    return INCOMM_SUCCESS;
}




int incomm_client_close(void)
{
#ifdef WINDOWS
    closesocket(sockfd2);
#else
    close(sockfd2);
#endif
    
//    mexPrintf("Client connection closed.\n");    
    
    return INCOMM_SUCCESS;
}
