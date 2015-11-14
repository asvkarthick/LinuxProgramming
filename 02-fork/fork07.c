#include <stdio.h>

int main(void)
{
    int pid;
    pid = fork();
    printf("Hello Rashila Karthick %d, %d, %d\n", getppid(), getpid(), pid);
    return 0;
}
