#include <stdio.h>
#include <pthread.h>

int gvar = 20;

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
    printf("thread: %d\n", *(int*)arg);
    printids("new thread");
    ++gvar;
    *(int*)arg = 100;
    return NULL;
}

int main(void)
{
    pthread_t ntid;
    int lvar = 50;

    pthread_create(&ntid, NULL, thr_fn, &lvar);

    printids("main thread");
    usleep(1000000);
    printf("gvar = %d, lvar = %d\n", gvar, lvar);
    return 0;
}
