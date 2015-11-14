#include <stdio.h>
#include <pthread.h>

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf("%s pid = %d, tid = %d\n", s, pid, tid);
}

void* thr_fn(void *arg)
{
    printids("new thread");
    return NULL;
}

int main(void)
{
    pthread_t ntid;

    pthread_create(&ntid, NULL, thr_fn, NULL);

    printids("main thread");
    sleep(1);
    return 0;
}
