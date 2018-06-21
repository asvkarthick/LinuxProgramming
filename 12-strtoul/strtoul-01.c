#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *ptr;
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return -1;
    }

    printf("%u\n", strtoul(argv[1], &ptr, 0));
    return 0;
}
