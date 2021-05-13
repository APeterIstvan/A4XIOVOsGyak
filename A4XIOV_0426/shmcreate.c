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

        key = SHMKEY;

        shmflg = 0;
        if ((shmid=shmget( key, size, shmflg)) < 0) {
           printf("\nSegment creation.");
           shmflg = 00666 | IPC_CREAT;
           if ((shmid=shmget( key, size, shmflg)) < 0) {
              perror("\nShmget error!");
              exit(-1);
           }
        } else printf("\nThere is already a segment.");

        printf("\nShmid ID: %d \n", shmid);

        exit (0);
}
