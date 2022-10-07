#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

void *threadRoutine(void *arg);
int main(){
	int arg[2]={5,6};
	// thread creation
	pthread_t n_thread;
	pthread_create(&n_thread,NULL,threadRoutine,(void *)arg);
	void *retVal;
	pthread_join(n_thread,&retVal);
	printf("Thread return vallue %ld\n",((intptr_t)retVal));
return 0;
}

void *threadRoutine(void *arg){
	printf("Inside thread...\n");
	int *arr=(int *)arg;
	int sum=(arr[0]+arr[1]);
	//printf("%d-%p\n",sum,&sum);
	pthread_exit((void *)(intptr_t)sum);
}
