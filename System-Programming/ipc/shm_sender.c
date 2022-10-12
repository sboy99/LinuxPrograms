#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h> 
#define MEM_SIZE 2048

int main(){
	char enterMsg[]="Enter your Message: ";
	key_t key=9099;
	int shmid=shmget(key,MEM_SIZE,IPC_CREAT|00600);
	void *shm_addr=shmat(shmid,NULL,00600);

	char buffer[256];
	write(1,enterMsg,strlen(enterMsg));
	read(0,buffer,256);

	strcpy((char *)shm_addr,buffer);
	return 0;
	
}
