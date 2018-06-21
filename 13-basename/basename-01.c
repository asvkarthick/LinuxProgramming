#include <stdio.h>

#define _GNU_SOURCE

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s <path/filename>\n", argv[0]);
        return -1;
    }

    printf("%s\n", basename(argv[1]));

    return 0;
}
