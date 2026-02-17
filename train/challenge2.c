#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// #define THREAD_NUM 5

pthread_mutex_t mutex;
int mails = 0;

void *mailcounter(void *args)
{
	int i = *(int *)args;
	int counter = 0;
	while (counter < 10000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		counter++;
		pthread_mutex_unlock(&mutex);
	}
	printf("i am thread number %d and i finish %d\n", i, mails);
	free(args);
	return (NULL);
}

int main()
{
	pthread_t th[2];
	pthread_attr_t detach;
	pthread_mutex_init(&mutex, NULL);
	pthread_attr_init(&detach);
	pthread_attr_setdetachstate(&detach, PTHREAD_CREATE_DETACHED);
	int i = 0;
	while (i < 2)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], &detach, &mailcounter, a) != 0)
			perror("failed to create thread");
		i++;
	}
	// i = 0;
	// while (i < THREAD_NUM)
	// {
	//     if (pthread_join(th[i], NULL) != 0)
	//         perror("failed to join thread\n");
	//     i++;
	// }
	pthread_attr_destroy(&detach);
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);
}