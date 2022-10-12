#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<stdio.h>

#define MEM_SIZE 2048

int main(){
	key_t key=9099;
	int shmid=shmget(key,MEM_SIZE,00600);
	void *shm_addr=shmat(shmid,NULL,00600);
	
	printf("Message recieved from sender: %s\n",(char *)shm_addr);
	return 0;
}
