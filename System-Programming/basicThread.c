#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdio.h>

void *threadFunc(void *arg);

int main(){
	pthread_t a_thread; //thread variable
	pthread_create(&a_thread,NULL,threadFunc,NULL);//creating a thread;
	pthread_join(a_thread,NULL);
	printf("Inside main function \n");
	for(int i=0;i<=7;i++){
		printf("%d\n",i);
		sleep(1);
	}
	return 0;
}

void *threadFunc(void *arg){
	printf("Inside thread \n");
	for(int i=0;i<=5;i++){
		printf("%d\n",i);
		sleep(1);
	}
}
