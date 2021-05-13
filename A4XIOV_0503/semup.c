#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12

int semid, nsems, r, semflag;

struct sembuf sembuf, *sop;

unsigned nsops;

int main(){

        nsems = 1;
        semflag = 00666 | IPC_CREAT;
        semid = semget (SEMKEY, nsems, semflag);
        if (semid < 0 ) {
                perror("Semget error!\n");
                return 0;
        }else
                printf("Semid: %d\n", semid);

        nsops = 1;
        sembuf.sem_flg = 0066;
        sembuf.sem_op = 1;
        sembuf.sem_num = 0;
        sop = &sembuf;
        r = semop(semid, sop, nsops);
        printf("Return value: %d\n", r);

    return 0;

}
