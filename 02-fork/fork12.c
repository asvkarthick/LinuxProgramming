#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    char buf[100];
    pid_t pid;
    int status;
    printf("%% "); /* print prompt (printf requires %% to print %) */
    while (fgets(buf, 100, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */
        if ((pid = fork()) < 0) {
            printf("fork error\n");
        } else if (pid == 0) {
            /* child */
            execlp(buf, buf, (char *)0);
            printf("couldn’t execute: %s\n", buf);
            exit(127);
        }
        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
            printf("waitpid error\n");
        printf("%% ");
    }
    exit(0);
}
