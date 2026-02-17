#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void *routine()
{
	return NULL;
}

int main()
{
	pthread_t th[2];
	pthread_mutex_init(&mutex, NULL);
	int i = 0;
	while (i < 2)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("failed to create thread\n");
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("failed to join thread\n");
		i++;
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}