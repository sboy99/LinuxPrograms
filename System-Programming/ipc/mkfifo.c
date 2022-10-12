#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	if(!mkfifo("/tmp/fifoPipe",00764)){
	printf("Pipe has been created successfully\n");
	return 0;
	}
	printf("Pipe has not created! \n");
}
