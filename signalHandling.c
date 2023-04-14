#include <stdio.h>
#include <signal.h>

struct sigaction sigaction1, sigaction2;

void signalHandler(int signum, siginfo_t *info, void *v) {
    printf("signal %i occurred with code %i. fpdiv is %i\n", signum, info->si_code, FPE_INTDIV);
    fflush(stdout);
}

void segvHandler(int signum, siginfo_t *info, void *v) {
    printf("segfault occurred at %i\n", info -> si_addr);
    fflush(stdout);
}

int main() {
    sigaction1.sa_sigaction = signalHandler;
    sigaction1.sa_flags = SA_SIGINFO;
    sigemptyset(&sigaction1.sa_mask);
    sigaction(SIGFPE, &sigaction1, NULL);

    sigaction2.sa_sigaction = segvHandler;
    sigaction2.sa_flags = SA_SIGINFO;
    sigemptyset(&sigaction2.sa_mask);
    sigaction(SIGSEGV, &sigaction2, NULL);

    int* i = 5;
    printf("%i", (int)*i);
}