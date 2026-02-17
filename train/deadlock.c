#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 8

pthread_mutex_t mutex;

int fuel = 50;

void *routine()
{
	pthread_mutex_lock(&mutex);
	pthread_mutex_lock(&mutex);
	fuel += 50;
	printf("increment fuel to: %d\n", fuel);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main()
{
	pthread_t th[THREAD_NUM];
	pthread_mutexattr_t recMutex;
	pthread_mutexattr_init(&recMutex);
	pthread_mutexattr_settype(&recMutex, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mutex, &recMutex);
	
	int i = 0;
	while (i < THREAD_NUM)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("failed create thread\n");
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("failed join thread\n");
		i++;
	}
	printf("fuel: %d\n", fuel);
	pthread_mutexattr_destroy(&recMutex);
	pthread_mutex_destroy(&mutex);
	return (0);
}