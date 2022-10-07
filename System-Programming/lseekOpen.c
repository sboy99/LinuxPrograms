#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	char buffer[256];
	int fd=open("./shared/lseekBuffer",O_RDONLY);
	int bytesRead=read(fd,buffer,10);
	write(1,buffer,bytesRead);
	lseek(fd,10,SEEK_CUR);
	bytesRead=read(fd,buffer,10);
	write(1,buffer,bytesRead);
	return 0;
}

