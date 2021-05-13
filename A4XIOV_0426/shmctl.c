#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 123456L

int main()
{
        int shmid;
        key_t key;
        int size=512;
        int shmflg;
        int rtn;
        int cmd;
        struct shmid_ds shmid_ds, *buf;

        buf = &shmid_ds;

        key = SHMKEY;
        shmflg = 0;

        if ((shmid=shmget( key, size, shmflg)) < 0) {
            perror("\nShmget error!");
            exit(-1);
        }


        do {
                printf("\nGive the number of the command ");
                printf("\n0 IPC_STAT (status)");
                printf("\n1 IPC_RMID (torles)");
                printf("\nEnter the number: ");
                scanf("%d",&cmd);
        } while (cmd < 0 && cmd > 1);

        switch (cmd){
                case 0: rtn = shmctl(shmid, IPC_STAT, buf);
                        printf("\nSegment size: %d",buf->shm_segsz);
                        printf("\nLast shmop process pid: %d\n ",buf->shm_lpid);
                        break;
                case 1: rtn = shmctl(shmid, IPC_RMID, NULL);
                        printf("\nSegment deleted.\n");
        }

        exit(0);

}
