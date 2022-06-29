#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define SIZE 50

int arr[SIZE]; // Global Shared Buffer

sem_t mutex;

/*................Even Thread Handling Function..............*/
void *Even()
{
	int i;
	sem_wait(&mutex); // Entry Section
	/*..........Critical Section...........*/
	for(i=0;i<=SIZE;i++)
	{
		if(i%2==0)
		{
			sleep(1);
			arr[i]=i;
			printf("%d\n",arr[i]);
		}
	}
	printf("Even_Thread_Function ID: %ld\n",pthread_self());
	printf("Even_Thread_Function Executed Successfully\n");
	sem_post(&mutex); // Exit Section
}

/*...............Odd Thread Handling Function................*/
void *Odd()
{
	int i;
	sem_wait(&mutex); // Entry Section
	/*.............Critical Section..............*/
	for(i=0;i<=SIZE;i++)
	{
		if(i%2==1)
		{
			sleep(1);
			arr[i]=i;
			printf("%d\n",arr[i]);
		}	
	}
	printf("Odd_Thread_Function ID: %ld\n",pthread_self());
	printf("Odd_Thread_Function Executed Successfully\n");
	sem_post(&mutex); // Exit Section
}


int main()
{
	sem_init(&mutex,0,1);
	pthread_t newthread[2];
	pthread_create(&newthread[0],NULL,&Even,NULL);
	pthread_create(&newthread[1],NULL,&Odd,NULL);
	pthread_join(newthread[0],NULL);
	pthread_join(newthread[1],NULL);
	sem_destroy(&mutex);
	return 0;
}

