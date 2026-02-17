#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
void *routine(void *arg)
{
	int index = *(int *)arg;
	int sum = 0;
	int i = 0;
	while (i < 5)
	{
		sum += arr[index + i];
		i++;
	}
	printf("local sum: %d\n", sum);
	*(int *)arg = sum;
	return (arg);
}
int main()
{
	pthread_t t[2];
	int i = 0;
	while (i < 2)
	{
		int *a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&t[i], NULL, &routine, a) != 0)
		{
			perror("failed to create thread\n");
			return 1;
		}
		i++;
	}
	
	i = 0;
	int globalsum = 0;
	while (i < 2)
	{
		int *r;
		if (pthread_join(t[i], (void **)&r) != 0)
		{
			perror("failed to join thread\n");
			return 1;
		}
		globalsum += *r;
		free(r);
		i++;
	}
	printf("sum= %d\n", globalsum);
	return 0;
}