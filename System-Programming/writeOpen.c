#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	int fd=open("./shared/buffer",O_CREAT|O_APPEND|O_WRONLY);
	char* buffer=(char*)malloc(256*sizeof(char));
	int bytesRead=read(0,buffer,256);
	write(fd,buffer,bytesRead);
	free(buffer);
return 0;
}
