#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    if (access("fifoThing.txt", F_OK)) return 1;
    FILE* fp = fopen("fifoThing.txt", "r");
    if (!fp) return 1;

    char str[10];
    while (fgets(str, 10, fp) != NULL) {
        printf("got %s\n", str);fflush(stdout);
    }

    return 0;
}