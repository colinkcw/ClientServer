#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <sys/dir.h>
#include <string.h>

void *thread_function(void *ptr);

main(){
	int sock;
	int msgsock;
	struct sockaddr_in server;
	pthread_t thread1;
	int iret1;
	int ids;

	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0 ){
		perror("openiing stream socket");
	}	
	server.sin_family = AF_INET;
  	server.sin_addr.s_addr = INADDR_ANY;
  	server.sin_port = 8888;
  	if (bind (sock, (struct sockaddr *)&server, sizeof server) < 0) {
    	perror ("binding stream socket");
  	}
  	listen(sock,5);
  	while(1){
  		msgsock = accept(sock, (struct sockaddr *)0, (socklen_t *)0);
  		if (msgsock == -1) {
    		perror("accept");
  		}
  		ids = msgsock;
  		iret1 = pthread_create(&thread1,NULL,thread_function,&ids);
  		pthread_join(thread1,NULL);
  	}
}

void *thread_function(void * ptr){
	int rval;
	char buf[1024];
	int msock = *(int *)ptr;
	DIR * dirp;
	struct direct *d;
	char foo[1024];
	

  	if ((rval = read(msock, buf, 1024)) < 0){
	    perror("reading socket");
  	}else  {
	    strcpy(foo,buf);
  	}


  	dirp = opendir(foo);
  	if (dirp == NULL) {
	    perror("openning dir");
  	}
  	while (d = readdir(dirp)) {
	    printf("%s\n",d->d_name);
	    strcpy(buf,d->d_name);
	    rval = write(msock, buf, 1024);
	  }
  	closedir (dirp);
	  //strcpy(buf,"hello");
	 // rval = write((int)&msock,buf, 1024);

}