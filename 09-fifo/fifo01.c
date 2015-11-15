#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FIFO_NAME "fifo_node"

int main(void)
{
    char s[300];
    int n, fd;

    mknod(FIFO_NAME, S_IFIFO | 0666, 0);

    printf("Waiting for readers ...\n");
    fd = open(FIFO_NAME, O_WRONLY);
    printf("got a reader--type something\n");

    while(gets(s), !feof(stdin))
    {
        n = write(fd, s, strlen(s));
        printf("%d bytes written\n", n);
    }
    return 0;
}
