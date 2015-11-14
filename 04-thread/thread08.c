#include <stdio.h>
#include <pthread.h>

void *thr_fn(void *arg)
{
    int count = 99999;
    while(count--) printf("RK: %d\n", count);
    return((void*)0);
}

int main(void)
{
    pthread_t thrid;
    void *rval;

    pthread_create(&thrid, NULL, thr_fn, NULL);
    printf("%s\n", __func__);
    pthread_join(thrid, &rval);
    printf("rval = %d\n", (int)rval);
    return 0;
}
