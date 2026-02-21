#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define	THREAD_NUM 50

typedef struct s_parking
{
	int				occupied_count;
	int				slots[10];
	pthread_mutex_t locks[10];
	pthread_mutex_t	count_lock;
}			t_parking;

typedef struct s_car{
	int 		id;
	t_parking	*parking;
}			t_car;

void *park_car(void *arg)
{

}
int main()
{
	pthread_t th[50];
	t_parking park_info;
	int i = 0;
	while (i < 10)
	{
		pthread_mutex_init(&park_info.slots[i], NULL);
		i++;
	}
	
	i = 0;
	while (i < THREAD_NUM)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &park_car, a) != 0)
			perror("failed to create thread");
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("failed to join thread");
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_mutex_destroy(&park_info.slots[i]);
		i++;
	}
	return (0);
}