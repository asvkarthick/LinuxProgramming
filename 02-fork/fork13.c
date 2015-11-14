#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
    {
        while(1) printf("Child process...\n");
    }
    else
    {
        int i;
        for(i = 0; i < 999999; i++)
            printf("Parent process\n");
    }
    return 0;
}
