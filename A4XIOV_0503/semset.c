#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12

int semid, semnum, nsems, r, semflag, cmd;

union semun;

struct sembuf sembuf, *sop;

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

        printf ("Semval value: ");

        semnum = 0;
        cmd = SETVAL;
        scanf("%d", &arg);
        r = semctl(semid, semnum, cmd, arg);
        printf("\nReturn value: %d\nSemval value: %d\n", r, arg);

    return 0;

}
