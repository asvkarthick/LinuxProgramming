#include <stdio.h>

int gvar = 25;

int main(void)
{
    int lvar = 12;
    int pid;

    pid = fork();
    if(pid == 0)
    {
        gvar++;
        ++lvar;
    }
    else
    {
        --gvar;
        --lvar;
    }
    printf("PID = %d, gvar = %d, lvar = %d\n", pid, gvar, lvar);
    return 0;
}
