/*NAME: HARMAN SINGH
ROLL NO. : 2019042*/

#include <pthread.h>

#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <string.h>
#include <unistd.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 



struct my_semaphore{    //The counting semaphore structure
	int count;    //to maintain the count of threads
	pthread_mutex_t mut;


};




int k;			//no. of philosophers
struct my_semaphore sema;   //my_semaphore as counting semaphore
pthread_mutex_t forks[10000000];  //forks represented by mutexes
pthread_t ptid[10000000];  //philosophers as threads
pthread_mutex_t sauceBowls;    //both sauce bowls represented ad mutex

void wait(struct my_semaphore *m){   //wait structure to block the incoming thread
	
	if(m->count==k-1)			
	return;
	m->count++;
	if(m->count==k-1) //blocking the philosopher from entering the room in case there are alreasy k-1 philosophers in the room
	pthread_mutex_trylock(&m->mut); //using pthread_mutex_trylock, non blocking variant of block
	
	
}
void signal(struct my_semaphore *m){   //signal structure to release the thread
	m->count--;
	if(m->count==k-2)
	pthread_mutex_unlock(&m->mut);
	
}
void signalprintValue(struct my_semaphore *m){
	printf("Count variable is %d\n",m->count);
}




void* func(void * arg){

	

	int pno=*(int *)arg;



		
		
		wait(&sema);   //not allowing more than k-1 philosophers inside the room using my_semaphore
		
		
		pthread_mutex_lock(&forks[pno]);    //locking 1st fork
	
		pthread_mutex_lock(&forks[(pno+1)%k]);  //locking 2nd fork
	
		pthread_mutex_lock(&sauceBowls); //locking saucebowls
		printf("P%d receives the 2 sauce bowls.\n",pno);

		printf("Philosopher %d eats using forks %d and %d\n",pno,pno,(pno+1)%k);
		
	

	printf("P%d is eating...\n",pno);
	sleep(1.5); //eating
	printf("P%d has finished eating.\n",pno);


	pthread_mutex_unlock(&forks[pno]);  //releasing 1st fork
	pthread_mutex_unlock(&forks[(pno+1)%k]);  //releasing 2nd fork
	pthread_mutex_unlock(&sauceBowls); //releasing saucebowls
	
	signal(&sema); //signalling to reduce the count of philosophers by 1
}
	

//count -- se pehle 4 tha to unlock





int main(){

	printf("Enter k (no. of philosophers): ");
	scanf("%d",&k);


	while(1){

		//initialising mutexes &  my_semaphore 
		pthread_mutex_init(&sema.mut,NULL);
		pthread_mutex_init(&sauceBowls,NULL);

		

		int pass[k];
		for(int i=0;i<k;i++){
			pass[i]=i;
		}
		//initialising forks
		for(int i=0;i<k;i++){
			pthread_mutex_init(&forks[i],NULL);
		}
		//creating philosophers as threads
		for(int i=0;i<k;i++){
			pthread_create(&ptid[i],NULL,func,(void *)&pass[i]);
		}
		
		//waiting for threads to complete execution
		for(int i=0;i<k;i++){
			pthread_join(ptid[i],NULL);
		}

		sema.count=0;
		pthread_mutex_destroy(&sema.mut);
		pthread_mutex_destroy(&sauceBowls);
		for(int i=0;i<k;i++){
			pthread_mutex_destroy(&forks[i]);
		}
	}

	return 0;

}