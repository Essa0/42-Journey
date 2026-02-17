#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t sema;

void *routine(void *arg)
{
	sem_wait(&sema);
	sleep(1);
	printf("hello from thread %d\n", *(int *)arg);
	sem_post(&sema);
	free(arg);
	return NULL;
}

int main()
{
	pthread_t th[THREAD_NUM];
	sem_init(&sema, 0, 3);
	int i = 0;
	while (i < THREAD_NUM)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("failed to create thread\n");
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("failed to join thread\n");
		i++;
	}
	sem_destroy(&sema);
	return 0;
}