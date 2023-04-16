#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        for (int i = 0; argv[i]; i++) {
            printf("%s = \"%s\"\n", argv[i], getenv(argv[i]));
        }
    }
}