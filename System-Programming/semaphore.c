// Process Synchronization to avoid race condition...
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>

void *fun1();
void *fun2();

sem_t sem;
int shared=100;

int main(){
	pthread_t th1,th2;
	sem_init(&sem,0,1);
	
	pthread_create(&th1,NULL,fun1,NULL);
	pthread_create(&th2,NULL,fun2,NULL);

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	
	printf("Final value of shared var: %d\n",shared);	
	return 0;
}

void *fun1(){
	printf("Inside thread 1\n");
	sem_wait(&sem); //wait
	int x=shared;
	printf("th1: Before updation shared variable: %d\n",x);
	x+=10;
	printf("th1: After updation local variable: %d\n",x);
	sleep(2);
	shared=x;
	printf("th1: After updation Final shared variable: %d\n",shared);
	sem_post(&sem); //signal
}
void *fun2(){
        printf("Inside thread 2\n");
        sem_wait(&sem); //wait
        int x=shared;
        printf("th2: Before updation shared variable: %d\n",x);
        x-=40;
        printf("th2: After updation local variable: %d\n",x);
        sleep(1);
        shared=x;
        printf("th2: After updation Final shared variable: %d\n",shared);
        sem_post(&sem); //signal
}

