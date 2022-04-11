#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *thread_handler1(void *ptr)
{
		for(int i=1;i<=5;i++)
		{
				sleep(1);
				printf("Thread1 is running\n");
		}
}

void *thread_handler2(void *ptr)
{
		for(int i=1;i<=5;i++)
		{
				sleep(1);
				printf("Thread2 is running\n");
		}
}

int main()
{
		pthread_t thread[2];
		char *msg1 = "anusha";
		char *msg2 = "aadhya";
		pthread_create(&thread[0], NULL, &thread_handler1, (void *)msg1);
		pthread_create(&thread[1], NULL, &thread_handler2, (void *)msg2);
		pthread_join(thread[0],NULL);
		pthread_join(thread[1],NULL);
		return 0;
}
