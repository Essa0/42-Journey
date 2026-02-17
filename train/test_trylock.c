#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex[4];
int stoveFuel[4] = {100, 100, 100, 100};

void *routine()
{
	int i = 0;
	while (i < 4)
	{
		if (pthread_mutex_trylock(&mutex[i]) == 0)
		{	
			int fuelNeeded = (rand() % 30);
			if (stoveFuel[i] - fuelNeeded < 0)
				printf("no more fuel.... go home\n");
			else
			{
				stoveFuel[i] -= fuelNeeded;
				usleep(500000);
				printf("fuel left %d\n", stoveFuel[i]);
			}
			pthread_mutex_unlock(&mutex[i]);
			break;
		}
		else
		{
			if (i == 3)
			{
				printf("no stove available yet, waiting,,,,\n");
				usleep(300000);
				i = 0;
			}
			
		}
		i++;
	}
	
	
	return NULL;
}

int main()
{
	pthread_t th[10];
	int i = 0;
	while (i < 4)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	
	srand(time(NULL));
	i = 0;
	while (i < 10)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("failed to create thread\n");
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("failed to create thread\n");
		i++;
	}
	while (i < 4)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
	return 0;
}