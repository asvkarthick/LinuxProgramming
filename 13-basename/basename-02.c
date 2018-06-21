#include <stdio.h>
#include <string.h>

char* basename(char* str)
{
    int len = strlen(str);
    char *strend = str;
    if(len > 0) {
        strend = str + len - 1;
        while(*strend != '/' && strend != str) strend--;
        strend++;
    }
    return strend;
}

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
