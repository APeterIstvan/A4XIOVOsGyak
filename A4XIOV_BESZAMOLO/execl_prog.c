#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

        printf("Engem a gyermek processz futtatott.\nPID-em: %d\nSzülőm PID-je: %d\n", getpid(), getppid());

        return 0;
}
