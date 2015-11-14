#include <stdio.h>

int main(void)
{
    fork();
    fork();
    fork();
    fork();
    printf("Hello Rashila Karthick, pid = %d\n", getpid());
    while(1);
    return 0;
}
