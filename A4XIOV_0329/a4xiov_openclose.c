#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
        int opener;
        char  *arr[100];
        int reader;

        if((opener = open("a4xiov.txt", O_RDWR)) < 0){
                perror("Open error.");
                return -1;
        }

        if((reader = read(opener, arr, sizeof(arr))) != 0){
                if(reader == -1){
                        perror("Read error.");
                        return -1;
                }
                int i;
                for(i=0; i<sizeof(arr) && arr[i] != NULL; i++);
                arr[i] = '\0'; // Lezárjuk a sort;
                printf("Number of bytes: %d, \nThe file itself contains: %s\n", reader, arr);
        }

        if(lseek(opener, 0, SEEK_SET) < 0){
                perror("Lseek error");
                return -1;
        }

        if((reader = write(opener, "Hello there\n", 11)) != 11){
                perror("Write error");
                return -1;
        }

        close(opener);
        return 0;
}
