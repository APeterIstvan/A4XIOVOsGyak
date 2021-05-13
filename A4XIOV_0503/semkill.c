#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x10

int semid, semnum, nsems, r, semflag, cmd;

struct sembuf sembuf, *sop;

union semun {
        int val;
        struct semid_ds *buf;
        unsigned short int *array;
};

int main(){

        int arg;
        nsems = 1;
        semflag = 00666 | IPC_CREAT;
        semid = semget (SEMKEY, nsems, semflag);
        if (semid < 0 ) {
                perror("Semget error!\n");
                return 0;
        }else
                printf("Semid: %d\n", semid);

        cmd = IPC_RMID;
        r = semctl(semid, 0, cmd, arg);
        printf("Kill return value: %d\n", r);

    return 0;

}
