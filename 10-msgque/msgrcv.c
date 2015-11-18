#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf
{
    long mtype;
    char mtext[200];
};

int main(void)
{
    struct my_msgbuf buf;
    int msgid;
    key_t key;

    key = ftok("msgsnd.c", 'B');
    msgid = msgget(key, 0644);

    printf("Ready to receive messages:\n");

    for(;;)
    {
        if(msgrcv(msgid, &buf, sizeof(buf.mtext), 0, 0) == -1)
        {
            perror("msgrcv");
            exit(1);
        }
        printf("Text: %s\n", buf.mtext);
    }
    return 0;
}
