#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
        int status = system("date");
        if (WIFEXITED(status))
                printf("Normális befejeződés, visszaadott érték: %d\n", WEXITSTATUS(status));
        else
                printf("Hamis\n");

        int status2 = system("nothing");
        if(WIFEXITED(status) == 0)
                printf("Normális befejeződés, visszaadott érték: %d\n", WEXITSTATUS(status));
        else
                printf("Hamis\n");


        return 0;
}
