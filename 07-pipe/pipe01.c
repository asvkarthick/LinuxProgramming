#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fds[2];
    char buf[80];

    pipe(fds);

    printf("Writing to file descriptor %d\n", fds[1]);
    write(fds[1], "Pipe Example", strlen("Pipe Example") + 1);

    printf("Reading from file descriptor %d\n", fds[0]);
    read(fds[0], buf, 13);

    printf("String read = %s\n", buf);
    return 0;
}
