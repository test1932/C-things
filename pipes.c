#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pip[2];
    pipe(pip);
    int pid = fork();
    if (pid < 0) {
        printf("error\n");
        exit(1);
    } 
    if (pid == 0) {
        close(pip[1]);//close write
        int val, i;
        read(pip[0], &val, 4);
        printf("I am a child, mummy calls me %i\n", val);
    }
    else {
        close(pip[0]);//close read
        printf("I am a mother, my child is %i\n", pid);
        write(pip[1], &pid, 4);
    }
    return 0;
}