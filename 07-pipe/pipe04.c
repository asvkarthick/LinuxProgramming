#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fds[2];

    pipe(fds);

    if(fork() == 0)
    {
        close(1);
        dup(fds[1]);
        close(fds[0]);
        execlp("ls", "ls", NULL);
    }
    else
    {
        close(0);
        dup(fds[0]);
        close(fds[1]);
        execlp("wc", "wc", "-l", NULL);
    }
    return 0;
}
