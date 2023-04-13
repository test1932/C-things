#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
    int fd = open("file2.txt", O_RDWR|O_CREAT, S_IRWXU);
    write(fd, "hello terrible world", 15);
    int *ptr = mmap ( NULL, 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );
    if (ptr == MAP_FAILED) {
        printf("failed\n");
        close(fd);
    }
    else {
        printf("mmapped, code is %i\n", *ptr);
        // write(1,ptr,10);
    }

    int pid = fork();

    if (pid < 0) return 1;

    //child
    if (pid == 0) {
        ptr[0] = 'F';
    }
    //parent
    else {
        waitpid(pid, NULL, 0);
        printf("char is %c\n", ptr[0]);
    }

    int err;
    if ((err = munmap(ptr, 10))) {
        printf("failed munmap %i\n", err);
    }
    return 0;
}