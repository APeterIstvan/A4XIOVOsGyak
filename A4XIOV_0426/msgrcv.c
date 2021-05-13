#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSGKEY 654321L

struct msgbuf1 {
        long mtype;
        char mtext[512];
} rcvbuf, *msgp;

struct msqid_ds ds, *buf;

int main()
{
        int msgid;
        key_t key;
        int mtype, msgflg;
        int rtn, msgsz;

        key = MSGKEY;
        msgflg = 00666 | IPC_CREAT | MSG_NOERROR;

        msgid = msgget( key, msgflg);
        if ( msgid == -1) {
                perror("Msgget error!");
                exit(-1);
        }
        printf("\nMsgid: %d",msgid);

        msgp = &rcvbuf;
        buf = &ds;
        msgsz = 20;
        mtype = 0;
        rtn = msgctl(msgid,IPC_STAT,buf);
        printf("\nNumber of messages: %d",buf->msg_qnum);

        while (buf->msg_qnum) {

                rtn = msgrcv(msgid,(struct msgbuf *)msgp, msgsz, mtype, msgflg);
                printf("\nRtn: %d, Got message: %s\n",rtn, msgp->mtext);
                rtn = msgctl(msgid,IPC_STAT,buf);
        }

        exit (0);
}
