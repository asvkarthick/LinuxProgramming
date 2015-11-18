#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* doSomeThing1(void *arg)
{
    int j = 0;
    printf("%s entering...", __func__);
    fflush(stdout);
    while(j < 10)
    {
        pthread_mutex_lock(&lock);
        printf("%s done\n", __func__);

        unsigned long i = 0;
        counter += 1;
        printf("\n Job %d started, tid = %ld, i = %d\n", counter, pthread_self(), j);

        for(i=0; i<(0xFFFFFF);i++);

        printf("\n Job %d finished, tid = %ldm i = %d\n", counter, pthread_self(), j);

        pthread_mutex_unlock(&lock);
        ++j;
        sleep(1);
    }

    return NULL;
}

void* doSomeThing2(void *arg)
{
    int j = 0;
    printf("%s entering...", __func__);
    fflush(stdout);
    while(j < 10)
    {
        pthread_mutex_lock(&lock);
        printf("%s done\n", __func__);

        unsigned long i = 0;
        counter += 1;
        printf("\n Job %d started, tid = %ld, i = %d\n", counter, pthread_self(), j);

        for(i=0; i<(0xFFFFFF);i++);

        printf("\n Job %d finished, tid = %ld, i = %d\n", counter, pthread_self(), j);

        pthread_mutex_unlock(&lock);
        ++j;
        sleep(1);
    }

    return NULL;
}

int main(void)
{
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    pthread_create(&tid[0], NULL, doSomeThing1, NULL);
    pthread_create(&tid[1], NULL, doSomeThing2, NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}
