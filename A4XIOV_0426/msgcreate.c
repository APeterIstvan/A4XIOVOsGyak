#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define MSGKEY 654321L

struct msgbuf1 {
        long mtype;
        char mtext[512];
} sndbuf, *msgp;



int main()
{
        int msgid;
        key_t key;
        int msgflg;
        int rtn, msgsz;

        key = MSGKEY;
        msgflg = 00666 | IPC_CREAT;
        msgid = msgget( key, msgflg);
        if ( msgid == -1) {
                perror("\nMsgget error!");
                exit(-1);
        }
        printf("Msgid %d, %x : ", msgid,msgid);

        msgp        = &sndbuf;
        msgp->mtype = 1;
        strcpy(msgp->mtext,"Message 1");
        msgsz       = strlen(msgp->mtext) + 1;

        rtn = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);
        printf("\nFirst msgsnd return: %d", rtn);
        printf("\nSent message: %s", msgp->mtext);

        strcpy(msgp->mtext,"Message 2");
        msgsz       = strlen(msgp->mtext) + 1;
        rtn = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);
        printf("\nSecond msgsnd return: %d", rtn);
        printf("\nSent message: %s\n", msgp->mtext);

        exit (0);
}

