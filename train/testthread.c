#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mail = 0;
pthread_mutex_t mutex;

void *routine()
{
	int i = 0;
	while (i < 100000)
	{
		pthread_mutex_lock(&mutex);
		mail++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return NULL;
}

int main()
{
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 2;
	if (pthread_join(t1, NULL) != 0)
		return 3;
	printf("Number of mails: %d\n", mail);
	if (pthread_join(t2, NULL) != 0)
		return 4;
	printf("Number of mails: %d\n", mail);
	pthread_mutex_destroy(&mutex);	
	return 0;
}