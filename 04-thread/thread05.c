#include <stdio.h>
#include <pthread.h>

void *thr_fn(void *arg)
{
    while(1) printf("RK\n");
}

int main(void)
{
    pthread_t thrid;

    pthread_create(&thrid, NULL, thr_fn, NULL);
    printf("%s\n", __func__);
    return 0;
}
