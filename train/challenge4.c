#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define THREAD_NUM 10

typedef struct s_actions
{
	int				balance;
	int 			transaction;
	pthread_mutex_t *mutex;
}		t_actions;


void *routine(void *ag)
{
	t_actions *actions = (t_actions *)ag;
	pthread_mutex_lock(actions->mutex);
	actions->balance -= 10;
	actions->transaction += 1;
	printf("withdraw 10. new balance: %d, total transaction: %d\n", actions->balance, actions->transaction);
	pthread_mutex_unlock(actions->mutex);
	return NULL;
}

int main()
{
	pthread_t th[THREAD_NUM];
	t_actions action;
	pthread_mutex_t shared_mutex;
	action.balance = 1000;
	action.transaction = 0;
	action.mutex = &shared_mutex;
	pthread_mutex_init(&shared_mutex, NULL);
	int i = 0;
	while (i < THREAD_NUM)
	{
		if (pthread_create(&th[i], NULL, &routine, &action))
			perror("failed to create thread");
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
	{
		if (pthread_join(th[i], NULL))
			perror("failed to join thread");
		i++;
	}
	pthread_mutex_destroy(&shared_mutex);
	return (0);
}