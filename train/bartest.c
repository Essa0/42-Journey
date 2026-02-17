#define _XOPEN_SOURCE 600
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

pthread_barrier_t bar;


void *routine()
{
	printf("waiting at the barrier...\n");
	pthread_barrier_wait(&bar);
	printf("we passed the barrier.\n");
	return NULL;
}

int main()
{
	pthread_t th[12];
	pthread_barrier_init(&bar, NULL, 3);
	int i = 0;
	while (i < 12)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL))
			perror("failed to create thread\n");
		i++;
	}
	i = 0;
	while (i < 12)
	{
		if (pthread_join(th[i], NULL))
			perror("failed to join thread\n");
		i++;
	}
	pthread_barrier_destroy(&bar);
	return (0);
}