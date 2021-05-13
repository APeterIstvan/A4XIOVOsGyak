#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12

int semid, semnum, nsems, r, semflag, cmd;

union semun arg;
union semun {
        int val;
        struct semid_ds *buf;
        unsigned short int *array;
};

int main(){

        nsems = 1;
        semflag = 00666 | IPC_CREAT;
        semid = semget (SEMKEY, nsems, semflag);
        if (semid < 0 ) {
                perror("Semget error!\n");
                return 0;
        }else
                printf("Semid: %d\n", semid);

        cmd = GETVAL;
        r = semctl(semid, 0, cmd, NULL);
        printf("Value: %d\n", r);

    return 0;

}
