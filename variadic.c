#include <stdio.h>
#include <stdarg.h>

void func (const char* str, ...) {
    va_list args;
    va_start(args, str);
    int i = va_arg(args, int);
    va_end(args);
    printf("other arg was %i\n", i);
}

int main(int argc, char* argv[]){
    int i;
    sscanf(argv[1], "%i", &i);
    func("hello", i);
}