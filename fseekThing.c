#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    int pos;
    sscanf(argv[1], "%i", &pos);

    FILE* fd = fopen("file.txt", "r");
    fseek(fd, pos, SEEK_CUR);
    char c; // extra for \0

    fread(&c, 1, 1, fd);

    printf("got '%c'\n", c);
}