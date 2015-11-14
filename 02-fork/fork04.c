#include <stdio.h>

int main(void)
{
    int pid;
    pid = fork();
    printf("Hello Rashila Karthick %d\n", pid);
    return 0;
}
