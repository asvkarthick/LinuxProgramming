#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */

#define MAX 5

/* global vars */
/* semaphores are declared global so they can be accessed 
   in main() and in thread routine,
   here, the semaphore is used as a mutex */
sem_t empty;
sem_t full;
int buffer[MAX];
int fill = 0;
int use = 0;

void put(int value)
{
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
}

int get()
{
    int tmp = buffer[use];
    use = (use + 1) % MAX;
    return tmp;
}

void *producer(void *arg)
{
    int i;
    int loopcnt = *(int*)arg;

    for(i = 0; i < loopcnt; i++)
    {
        sem_wait(&empty);
        put(i);
        sem_post(&full);
    }
    sem_wait(&empty);
    put(-1);
    sem_post(&full);
}

void *consumer(void *arg)
{
    int i, tmp = 0;
    while(tmp != -1)
    {
        sem_wait(&full);
        tmp = get();
        sem_post(&empty);
        printf("%d\n", tmp);
    }
}

int main()
{
    int i[2];
    pthread_t thread_a;
    pthread_t thread_b;
    
    i[0] = MAX; /* argument to threads */
    i[1] = 0;
    
    sem_init(&empty, 0, MAX);
    sem_init(&full,  0, 0);
                                 
    /* Note: you can check if thread has been successfully created by checking return value of
       pthread_create */                                 
    pthread_create (&thread_a, NULL, (void *) &producer, (void *) &i[0]);
    pthread_create (&thread_b, NULL, (void *) &consumer, (void *) &i[1]);
    
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
                  
    /* exit */  
    exit(0);
} /* main() */
