#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <sys/dir.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void *thread_function(void *ptr);

main(){
	pthread_t thread1;
	int iret1;
  	struct sockaddr_in addr;
   	int addrlen, sock, status;
   	struct ip_mreq mreq;
   	int ids;
   	char line[1024];

    sock = socket(AF_INET, SOCK_DGRAM, 0);
   	if (sock < 0) {
    	 perror("socket");
     	exit(1);
   	}
	
	ids = sock;
	iret1 = pthread_create(&thread1,NULL,thread_function,&ids);
  	//pthread_join(thread1,NULL);

	bzero((char *)&addr, sizeof(addr));
   	addr.sin_family = AF_INET;
   	/*addr.sin_addr.s_addr = htonl(INADDR_ANY);*/
	   addr.sin_port = htons(4447);
   	addrlen = sizeof(addr);
   	addr.sin_addr.s_addr = inet_addr("230.0.0.1");

   	while (1) {
     	if(!fgets(line,1024,stdin)){
     		perror("stdin");
     	}
     	status = sendto(sock, line, sizeof(line), 0,
		 	(struct sockaddr *) &addr, addrlen);
     	if (status < 0) {
	 	    perror("sendto");
	    	exit(1);
     	}
   	}

}
void *thread_function(void * ptr){
	struct sockaddr_in addr;
   	int addrlen, status;
   	struct ip_mreq mreq;
   	char buf[50];
   	static int so_reuseaddr = 1;
	int sock = *(int *)ptr;

	bzero((char *)&addr, sizeof(addr));
   	addr.sin_family = AF_INET;
   	addr.sin_addr.s_addr = htonl(INADDR_ANY);
   	addr.sin_port = htons(4447);
   	addrlen = sizeof(addr);

   	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,
    	&so_reuseaddr, sizeof(so_reuseaddr)) < 0) {
     	perror("setsockopt reuse addr");
     	exit(1);
   	}

   	if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {        
    	perror("bind");
    	exit(1);
   	} 

   	mreq.imr_multiaddr.s_addr = inet_addr("230.0.0.1");         
  	mreq.imr_interface.s_addr = htonl(INADDR_ANY);

  	if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
    	 perror("setsockopt mreq");
   		 exit(1);
   	}

   while (1) {
     	status = recvfrom(sock, buf, sizeof(buf), 0,(struct sockaddr *) &addr, &addrlen);
     	if (status < 0) {
     	  perror("recvfrom");
     	  exit(1);
     	} 
     	printf("%s: message = %s", inet_ntoa(addr.sin_addr), buf);
    }

}