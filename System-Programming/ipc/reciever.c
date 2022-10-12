#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
	char msgRecieved[]="Message Recieved!\nSender: ";
	char buffer[256];
	int fd=open("/tmp/fifoPipe",O_RDONLY);
	while(strcmp(buffer,"exit")){
	int bytesRead=read(fd,buffer,256);
	write(1,msgRecieved,strlen(msgRecieved));
	write(1,buffer,bytesRead);
	}
	return 0;
}
