#include <stdio.h>
#include <pthread.h>

void *thr_fn(void *arg)
{
    int count = 999999;
    while(count--) printf("RK: %d\n", count);
}

int main(void)
{
    pthread_t thrid;

    pthread_create(&thrid, NULL, thr_fn, NULL);
    printf("%s\n", __func__);
    sleep(1);
    return 0;
}
