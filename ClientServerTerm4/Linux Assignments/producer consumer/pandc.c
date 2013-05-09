#include <semaphore.h>
#include <unistd.h>
#include <sys/dir.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

void* producer(void *ptr);
void* consumer(void* ptr);

static char buffer[1024];
pthread_mutex_t mutexA  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexB  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexC  = PTHREAD_MUTEX_INITIALIZER;


int main(){

	pthread_t proThread, conThread;
	pthread_create(&proThread,NULL,producer,NULL);
	pthread_create(&conThread,NULL,consumer,NULL);
	pthread_join(proThread,NULL);
	pthread_join(conThread,NULL);
	

	return 0;
}

void* producer(void *ptr){
	while(1){
		pthread_mutex_lock(&mutexC);
		pthread_mutex_lock(&mutexA);
		produce();
		pthread_mutex_unlock(&mutexA);
		pthread_mutex_unlock(&mutexB);
	}

}

void* consumer(void* ptr){
	while(1){
	pthread_mutex_lock(&mutexB);
	pthread_mutex_lock(&mutexA);
	take();
	pthread_mutex_unlock(&mutexA);
	pthread_mutex_unlock(&mutexC);
	}
}

int produce(){
	char line[1024];
    if(!fgets(line,1024,stdin)){
     	perror("stdin");
    }
    sscanf(line,"%s", buffer);
    return 0;	 
}

int take(){
	printf("%s\n", buffer);
	return 0;
}