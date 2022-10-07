#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc,char **argv){
	pid_t p=fork();
	if(p<0){
		printf("Error while creating a child process");
		return 1;
	}
	else if(p==0){
		// child process
		printf("I'm a child process my id:%u and my parent process id:%u \n",getpid(),getppid());
	}
	else{
		// parent process
		wait(NULL);
		sleep(3);
		printf("I'm a parent process my id:%u and my child id:%u",getpid(),p);	
	}
return 0;
}
