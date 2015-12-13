#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

extern volatile int x;

extern pthread_mutex_t lock;
extern sem_t mutex;

void *func(void *);
