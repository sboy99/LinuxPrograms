#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
	int fd=open("/tmp/fifoPipe",O_WRONLY);
	char buffer[256];
	char msg[]="Enter message: \n";
	char msgSent[]="Message has been delivered successfully\n";
	while(strcmp(buffer,"exit")){
	write(1,msg,strlen(msg));
	int bytesRead=read(0,buffer,256);
	write(fd,buffer,bytesRead);
	write(1,msgSent,strlen(msgSent));
	}
	return 0;
}
