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
    printf("%s\n", (char*)arg);
    printids((char*)arg);
    return NULL;
}

int main(void)
{
    pthread_t ntid1, ntid2;
    void *rval;
    char *msg1 = "Thread-1";
    char *msg2 = "Thread-2";

    pthread_create(&ntid1, NULL, thr_fn, msg1);
    pthread_create(&ntid2, NULL, thr_fn, msg2);

    printids("main thread");
    pthread_join(ntid1, &rval);
    pthread_join(ntid2, &rval);
    return 0;
}
