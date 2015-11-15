#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_NAME "fifo_node"

int main(void)
{
    int num, fd;
    char s[300];

    mknod(FIFO_NAME, S_IFIFO | 0666, 0);

    printf("Waiting for writers...\n");
    fd = open(FIFO_NAME, O_RDONLY);
    printf("got a writer\n");

    do
    {
        num = read(fd, s, 300);
        s[num] = '\0';
        printf("Read %d bytes: %s\n", num, s);
    } while(num > 0);

    return 0;
}
