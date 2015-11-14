#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint(int signo)
{
    printf("Interrupt\n");
}

int main(void)
{
    signal(SIGINT, sigint);
    while(1);
    return 0;
}
