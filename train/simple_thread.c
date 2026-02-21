#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *my_turn()
{
	int i = 0;
	int *iptr = (int *)malloc(sizeof(int));
	*iptr = 5;
	while (i < 10)
	{
		sleep(1);
		printf("my turn! %d, %d\n", i, *iptr);
		(*iptr)++;
		i++;
	}
	return iptr;
}

void your_turn()
{
	int i = 0;
	while (i < 5)
	{
		sleep(1);
		printf("your turn!\n");
		i++;
	}
}
int main()
{
	pthread_t th;
	int *v;
	pthread_create(&th, NULL, &my_turn, NULL);
	your_turn();
	pthread_join(th, (void **)&v);
	printf("thread done: v = %d\n", *v);
	free(v);
	return 0;
}