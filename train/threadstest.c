#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int x = 0;
void *routine()
{
	int i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		x+=1;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return NULL;
}

int main()
{
	pthread_t ths[4];
	int i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(ths + i, NULL, &routine, NULL) != 0)
		{
			perror("failed to create thread\n");
			return 1;
		}
		i++;
		printf("thread %d has started\n", i);
	}
	i=0;
	while (i < 4)
	{
		if (pthread_join(ths[i], NULL) != 0)
			return 2;
		i++;
		printf("thread %d has finish execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("%d\n", x);
	return(0);
}
