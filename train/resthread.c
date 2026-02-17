#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


// void *roll_dice()
// {
// 	int value = (rand() % 6) + 1;
// 	int *res = malloc(sizeof(int));
// 	*res = value;
// 	// printf("%d", value);
// 	printf("%p\n", res);
// 	return (void *)res;
// }

pthread_mutex_t mutex;

void *roll_dices()
{
	int *res = malloc(sizeof(int)*8);
	int i = 0;
	while (i < 8)
	{
		pthread_mutex_lock(&mutex);
		res[i] = (rand() % 6) + 1;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	pthread_exit((void *) res);
}

int main()
{
	pthread_t t1;
	int *res;
	srand(time(NULL));
	if (pthread_create(&t1, NULL, &roll_dices, NULL) != 0)
		return 1;
	if (pthread_join(t1, (void **)&res) != 0)
		return 2;
	int i = 0;
	while (i < 8)
	{
		printf("%d\n", res[i]);
		i++;
	}
	free(res);
	pthread_mutex_destroy(&mutex);
	return 0;
}