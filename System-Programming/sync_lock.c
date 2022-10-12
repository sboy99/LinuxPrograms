#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
void *fun1();
void *fun2();
int shared=100;
pthread_mutex_t l;
int main(){
	pthread_t th1,th2;
	pthread_mutex_init(&l,NULL);
	pthread_create(&th1,NULL,fun1,NULL);
	pthread_create(&th2,NULL,fun2,NULL);

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	
	printf("Final variable after updation: %d\n",shared);
	return 0;
}

void *fun1(){
	int x;
	printf("Thread 1 is trying to accuire lock\n");
	pthread_mutex_lock(&l);
	printf("Thread 1 successfully accuired lock\n");
	x=shared;
	printf("Before updation shared variable value is %d\n",x);
	x+=25;
	sleep(3);
	shared=x;
	printf("After updation shared variable value is %d\n",shared);
	pthread_mutex_unlock(&l);
	printf("Thread 1 releases lock\n");
} 
void *fun2(){
        int x;
        printf("Thread 2 is trying to accuire lock\n");
        pthread_mutex_lock(&l);
        printf("Thread 2 successfully accuired lock\n");
        x=shared;
        printf("Before updation shared variable value is %d\n",x);
        x-=50;
        sleep(1);
        shared=x;
        printf("After updation shared variable value is %d\n",shared);
        pthread_mutex_unlock(&l);
        printf("Thread 2 releases lock\n");
}

