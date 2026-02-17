#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define THREAD_NUM 5

void *routine(void *args)
{
    int i = *(int *)args;
    printf("i am thread number %d\n", i);
    free(args);
    return (NULL);
}

int main()
{
    pthread_t th[THREAD_NUM];
    int i = 0;
    while (i < THREAD_NUM)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0)
            perror("failed to create thread\n");
        i++;
    }
    i = 0;
    while (i < THREAD_NUM)
    {
        if (pthread_join(th[i], NULL) != 0)
            perror("failed to join thread\n");
        i++;
    }

    return (0);
}