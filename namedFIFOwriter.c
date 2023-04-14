#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fp;
    if (access("fifoThing.txt", F_OK)) {
        mkfifo("fifoThing.txt", S_IRWXU);
    }
    fp = open("fifoThing.txt", O_RDWR);

    write(fp, "hello worl", 10);
    write(fp, "hello word", 10);
    close(fp);
}