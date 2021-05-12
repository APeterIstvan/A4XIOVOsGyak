#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void do_nothing();

int main(){
        signal(SIGALRM, do_nothing);
        printf(" %d Waiting\n");
        pause();
        printf("Alarm\n");
}

void do_nothing(){;}
