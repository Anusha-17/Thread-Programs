#include<stdio.h>

#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define SIZE 26

char ch='A'; // Shared Variable

pthread_mutex_t mutex;
 
void *capital_Alp()
{
	int i;
	pthread_mutex_lock(&mutex);
	printf("Capital Alphabet:\n");
	for(i=0;i<SIZE;i++)
	{
		//pthread_mutex_lock(&mutex);
		sleep(1);
		printf("%c\n",ch);
		ch++;
		//pthread_mutex_unlock(&mutex);
	}
	printf("Capital Alphabet Thread Handling Function ID : %ld\n",pthread_self());
	printf("Capital Alphabet Thread Handling Function Executed Successfully\n");
	pthread_mutex_unlock(&mutex);
}

void *small_Alp()
{
	int i;
	pthread_mutex_lock(&mutex);
	printf("Small Alphabets: \n");
	for(i=0;i<SIZE;i++)
	{
		//pthread_mutex_lock(&mutex);
		sleep(1);
		printf("%c\n",ch+6);
		ch++;
		//pthread_mutex_unlock(&mutex);
	}
	printf("Capital Alphabet Thread Handling Function ID : %ld\n",pthread_self());
        printf("Capital Alphabet Thread Handling Function Executed Successfully\n");
	pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t newthread[2];
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&newthread[0],NULL,&capital_Alp,NULL);
	pthread_create(&newthread[1],NULL,&small_Alp,NULL);
	pthread_join(newthread[0],NULL);
	pthread_join(newthread[1],NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
