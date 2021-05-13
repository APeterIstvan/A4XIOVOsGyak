#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
        int pid;
        int status;

        if((pid = fork())<0)
                perror("fork error");
        else if(pid == 0)
                if(execl("./child.out", "child", (char*) NULL) < 0)
                        perror("execl error");
        if(wait(&status) != pid)
                perror("wait hiba");

        return 0;
}
