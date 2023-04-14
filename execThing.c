#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid < 0) return 1;

    // child
    if (pid == 0) {
        char* argv[] = {NULL};
        execv("mem", argv);
    }
    //parent
    else {
        printf("I am a mother\n");
        waitpid(pid, NULL, 0);
    }

    return 0;
}