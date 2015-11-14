#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint(int signo)
{
    printf("Interrupt\n");
}

void sigint2(int signo)
{
    printf("Interrupt KILL\n");
    exit(0);
}

int main(void)
{
    signal(SIGINT, sigint);
    signal(SIGKILL, sigint2);
    while(1);
    return 0;
}
