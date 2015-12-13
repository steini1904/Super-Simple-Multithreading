#include "concurrent.h"


volatile int x=0;

sem_t mutex;

void *func(void *args)
{
	int *y = (int *) args;
	
	sem_wait(&mutex);
	
	for(int i=0; i < 100000000; i++)
	{
		x++;
		y[0]++;
	}
	
	sem_post(&mutex);
	
	return NULL;
}

int main (void)
{
	
	pthread_t thread1, thread2;
	int th_1, th_2;
	int a = 0;
	int b = 0;
	int err = 0;
	
	sem_init(&mutex, 0, 1);
	
	th_1 = pthread_create(&thread1, NULL, func, (void *) &a);
	th_2 = pthread_create(&thread2, NULL, func, (void *) &b);
	
	if(th_1 == 0)
	{
		pthread_join(thread1, NULL);
	}
	else
	{
		err = 1;
	}
	if(th_2 == 0)
	{
		pthread_join(thread2, NULL);
	}
	else
	{
		err = 1;
	}
	
	sem_destroy(&mutex);
	
	if(err == 1)
	{
		printf("Bad stuff happened\n");
		return 1;
	}
	
	printf("%i, %i, %i\n", x, a, b);
	
	return 0;
}
