#include <stdio.h>

int main(void)
{
    printf("User ID = %d, Group ID = %d\n", getuid(), getgid());
    return 0;
}
