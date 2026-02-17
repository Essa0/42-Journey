#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int fuel_amount = 0;
pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
void *fuel_filling()
{
	int i = 0;
	while (i < 5)
	{
		pthread_mutex_lock(&mutexFuel);
		fuel_amount += 60;
		printf("filled fuel... %d\n", fuel_amount);
		pthread_mutex_unlock(&mutexFuel);
		pthread_cond_broadcast(&condFuel);
		sleep(1);
		i++;
	}
	return NULL;
}

void *car()
{
	pthread_mutex_lock(&mutexFuel);
	while (fuel_amount < 40)
	{
		printf("got fuel. now left: %d\n", fuel_amount);
		pthread_cond_wait(&condFuel, &mutexFuel);
	}
	fuel_amount -= 40;
	printf("no fuel left\n");
	pthread_mutex_unlock(&mutexFuel);
	return NULL;
}

int main()
{
	pthread_t th[5];
	pthread_mutex_init(&mutexFuel, NULL);
	pthread_cond_init(&condFuel, NULL);
	int i = 0;
	while (i < 5)
	{
		if (i == 4)
		{
			if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
				perror("failed to create filling fuel thread\n");
		}
		else
		{
			if (pthread_create(&th[i], NULL, &car, NULL) != 0)
				perror("failed to create car thread\n");
		}
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("failed to join thread\n");
		i++;
	}
	pthread_mutex_destroy(&mutexFuel);
	pthread_cond_destroy(&condFuel);
	return 0;
}