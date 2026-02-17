#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex;

void *routine(void *arg)
{
	(void)arg;
	pthread_mutex_lock(&mutex);
	printf("Got lock\n");
	sleep(1);
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main()
{
	pthread_t th[4];
	int i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			return 1;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(th[i], NULL) != 0)
			return 1;
		i++;
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}