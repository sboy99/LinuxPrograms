#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
void *aThreadFunc(void *arg);
void *bThreadFunc(void *arg);

int main(){
	int arg[]={100};
	pthread_t a_thread,b_thread;

	pthread_create(&a_thread,NULL,aThreadFunc,(void *)arg);	
	pthread_create(&b_thread,NULL,bThreadFunc,(void *)arg);

	void *aThreadRetVal,*bThreadRetVal;
	pthread_join(a_thread,&aThreadRetVal);
	printf("%s\n",(char*)aThreadRetVal);
	pthread_join(b_thread,&bThreadRetVal);
	printf("%s\n",(char*)bThreadRetVal);

	printf("Final Value of data elem: %d\n",arg[0]);
	return 0;
}

void *aThreadFunc(void *arg){
	int *vals=arg;
	int val=vals[0];
	printf("a: Value of data elem before updation : %d\n",val);
	val+=50;
	printf("a: Value of data elem after updation : %d\n",val);
	sleep(2);
	vals[0]=val;
	printf("a: Final value updated\n");
	pthread_exit((void *)"Task a is done");
}

void *bThreadFunc(void *arg){
	int *vals=arg;
        int val=vals[0];
        printf("b: Value of data elem before updation : %d\n",val);
        val=50;
        printf("b: Value of data elem after updation : %d\n",val);
        sleep(1);
	vals[0]=val;
	printf("b: Final value updated\n");
	pthread_exit((void *)"Task b is done");
}

