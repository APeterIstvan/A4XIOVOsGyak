#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

       int child;

        mkfifo("A4XIOV", S_IRUSR|S_IWUSR);

        child = fork();

        if(child>0){
                char buffer[1024];
                int fd;

                fd = open("A4XIOV", O_RDONLY);
                read(fd, buffer, sizeof(buffer));
                printf("%s", buffer);

                close(fd);
                unlink("A4XIOV");
        }

        else if(child == 0){
                int fd;

                fd = open("A4XIOV", O_WRONLY);

                write(fd, "Ábrahám Péter István\n", 30);

                close(fd);
        }

        return 0;
}
