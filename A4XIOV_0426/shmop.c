#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        struct vmi {
                int  hossz;
                char szoveg[512-sizeof(int)];
        } *segm;

        key = SHMKEY;
        shmflg = 0;

        if ((shmid=shmget( key, size, shmflg)) < 0) {
            perror("\nShmget error!");
            exit(-1);
        }

        shmflg = 00666 | SHM_RND;
        segm = (struct vmi *)shmat(shmid, NULL, shmflg);

        if (segm == (void *)-1) {
                perror("Unsuccessful attach.");
                exit (-1);
        }

        if (strlen(segm->szoveg) > 0)
                printf("\nOld text: %s (with %d length)",segm->szoveg,segm->hossz);

        printf("\nEnter new text: ");
        scanf("%s", segm->szoveg);
        printf("\nNew text: %s\n",segm->szoveg);
        segm->hossz=strlen(segm->szoveg);
        shmdt(segm);

        exit(0);

}
