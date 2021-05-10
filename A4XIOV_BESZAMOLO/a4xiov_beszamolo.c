#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
        int child;
        child = fork();

        char *path = "execl_prog";
        setenv("PATH", path, 1);

        if(child < 0)
                perror("fork error");
        if(child == 0){
                if(execl("./execl_prog.out", getenv("PATH"), (char*) NULL)<0)
                                perror("execl error");
        }

        if(waitpid(child, NULL, 0)<0)
                perror("wait error");

        printf("Szülő vagyok.\nPID-em: %d\nGyermekem PID-je: %d\n", getpid(), child);


        return 0;
}
