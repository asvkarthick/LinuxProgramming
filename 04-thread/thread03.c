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
    printf("%s\n", (char*)arg);
    printids("new thread");
    ++gvar;
    return NULL;
}

int main(void)
{
    pthread_t ntid;
    char *msg = "Rashila Karthick";

    pthread_create(&ntid, NULL, thr_fn, msg);

    printids("main thread");
    usleep(1000000);
    printf("gvar = %d\n", gvar);
    return 0;
}
