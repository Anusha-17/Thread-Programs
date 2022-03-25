#include <stdio.h>
#include <unistd.h> //Header file for sleep().
#include <pthread.h>

int val=10;
pthread_t tid[2];

unsigned int data = 0;

void* even_num(void *ptr)
{
     while(data <= val)
     {
	     sleep(1);
         if((data % 2 == 0))
         {
             printf("Even : %d\n",data);
             data++;
         }
     }
}


void* odd_num(void* ptr1)
{
    while(data <= val)
    {
		sleep(1);
        if(data % 2 != 0)
        {
            printf("Odd : %d\n",data);
            data++;
        }
    }
}
      

void main(void)
{
    pthread_create(&tid[0],NULL,&even_num,NULL);
    pthread_create(&tid[1],NULL,&odd_num,NULL);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
}
