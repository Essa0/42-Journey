#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BIG 1000000000L
int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *counter_to_big()
{
	int i = 0;
	while (i < BIG)
	{
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
		i++;
	}
	return NULL;
}

int main()
{
	counter_to_big();
	counter_to_big();
	printf("Done. Counter = %u\n", counter);
	return 0;
}