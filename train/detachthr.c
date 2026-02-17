#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define THREAD_NUM 2

void *routine()
{
    sleep(1);
    printf("finished execute\n");
    return NULL;
}

int main()
{
    pthread_t th[THREAD_NUM];
    pthread_attr_t detachthr;
    pthread_attr_init(&detachthr);
    pthread_attr_setdetachstate(&detachthr, PTHREAD_CREATE_DETACHED);
    int i = 0;
    while (i < THREAD_NUM)
    {
        if (pthread_create(&th[i], &detachthr, &routine, NULL) != 0)
            perror("failed to create thread");
        i++;
    }
    i = 0;
    // while (i < THREAD_NUM)
    // {
    //     if (pthread_join(th[i], NULL) != 0)
    //         perror("failed to join thread");
    //     i++;
    // }
    pthread_attr_destroy(&detachthr);
    pthread_exit(0);
}