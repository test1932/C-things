#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    int pos;
    sscanf(argv[1], "%i", &pos);
    int fd = open("file.txt", O_RDONLY);
    lseek(fd, pos, SEEK_CUR);
    char str[2];
    read(fd, str, 1);
    printf("%c\n", str[0]);
}