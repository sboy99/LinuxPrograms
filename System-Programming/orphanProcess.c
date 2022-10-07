#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main(int argc,char **argv){
	pid_t p1,processId=getpid();
	p1=fork();
	if(p1<0){
	//error in creating child process
	}
	else if(p1==0){
	//child process
	printf("I'm a child process & my id: %u\n",getpid());
	sleep(2);
	}
	else{
	// parent process
	printf("I'm parent process & my id: %u\n",getpid());
	return 0;
	}
	printf("%u is my Id and my parent id: %u\n",getpid(),getppid());
	if(processId!=getppid()){
	printf("I'm a orphan process\n");
	}
	return 0;
}
