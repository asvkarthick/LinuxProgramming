#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char line[80];
    FILE *fp;

    if(argc < 2)
    {
        fprintf(stderr, "%s filename\n", argv[0]);
        return 0;
    }

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[1]);
        return -1;
    }

    if(pipe(fd) < 0)
        printf("pipe error\n");

    pid = fork();

    if(pid > 0)
    {
        close(fd[0]); // close read end
        while(fgets(line, 80, fp) != NULL)
        {
            n = strlen(line);
            write(fd[1], line, n);
        }
        close(fd[1]);
        waitpid(pid, NULL, 0);
        exit(0);
    }
    else if(pid == 0)
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("sort", "sort", NULL);
    }
}
