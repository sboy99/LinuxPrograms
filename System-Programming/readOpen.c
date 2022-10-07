#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
	int fd=open("./shared/buffer",O_RDONLY);
	char* buffer=(char*)malloc(256*sizeof(char));
	int bytesRead=read(fd,buffer,256);
	write(1,buffer,bytesRead);
	free(buffer); 
return 0;
}
