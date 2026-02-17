#define _XOPEN_SOURCE 600
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define THREAD_NUM 8

int diceValues[8];
int status[8] = {0};

pthread_barrier_t barRolledDice;
pthread_barrier_t barCal;

void *rollDice(void *args)
{
	int idx = *(int *)args;
	diceValues[idx] = rand() % 6 + 1;
	pthread_barrier_wait(&barRolledDice);
	pthread_barrier_wait(&barCal);
	if (status[idx] == 1)
		printf("(%d rolled %d) I won\n", idx, diceValues[idx]);
	else
		printf("(%d rolled %d) I lost\n", idx, diceValues[idx]);
	free(args);
	return NULL;
}
int main()
{
	srand(time(NULL));
	pthread_t th[THREAD_NUM];
	pthread_barrier_init(&barRolledDice, NULL, THREAD_NUM + 1);
	pthread_barrier_init(&barCal, NULL, THREAD_NUM + 1);
	int i = 0;
	while (i < THREAD_NUM)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &rollDice, a) != 0)
			perror("failed to create thread\n");
		i++;
	}
	pthread_barrier_wait(&barRolledDice);
	int max = 0;
	i = 0;
	while (i < THREAD_NUM)
	{
		if (diceValues[i] > max)
			max = diceValues[i];
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
	{
		if (diceValues[i] == max)
			status[i] = 1;
		else 
			status[i] = 0;
		i++;
	}
	sleep(1);
	pthread_barrier_wait(&barCal);
	
	i = 0;
	while (i < THREAD_NUM)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("failed to create thread\n");
		i++;
	}
	pthread_barrier_destroy(&barRolledDice);
	pthread_barrier_destroy(&barCal);
	return 0;
}