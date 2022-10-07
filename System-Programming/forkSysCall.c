#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<wait.h>

int main(){
	pid_t p1;
	p1=fork();
	if(p1==-1){
	printf("Can't create a child process");
	}
	else if(p1==0){
	// child process
	printf("Child Process id:%u\n",getpid());
	printf("Parent Process id:%u\n",getppid());
	}
	else{
	// parent process
	wait(NULL);
	printf("Process id:%u\n",getpid());
	}
	printf("%u is executing this\n",getpid());
}
