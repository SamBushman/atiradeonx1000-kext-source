#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
static volatile int got = 0;
static int wfd;
static void h(int s) { char c = 'A' + (s & 15); (void)!write(wfd, &c, 1); _exit(2); }
int main(void) {
    int which[3] = { ITIMER_REAL, ITIMER_VIRTUAL, ITIMER_PROF };
    for (int w = 0; w < 3; w++) {
        int p[2]; pipe(p); pid_t pid = fork();
        if (pid == 0) {
            wfd = p[1]; signal(SIGALRM, h); signal(SIGVTALRM, h); signal(SIGPROF, h);
            struct itimerval it; memset(&it, 0, sizeof it); it.it_value.tv_usec = 3000;
            setitimer(which[w], &it, NULL); for (;;) ;
        }
        close(p[1]);
        fd_set rs; FD_ZERO(&rs); FD_SET(p[0], &rs); struct timeval tv = { 2, 0 }; struct timeval t0, t1; gettimeofday(&t0, NULL);
        int r = select(p[0] + 1, &rs, NULL, NULL, &tv); gettimeofday(&t1, NULL);
        char c = 0; if (r > 0) (void)!read(p[0], &c, 1); else kill(pid, SIGKILL);
        int st; waitpid(pid, &st, 0);
        printf("timer %d: %s (signal char %c) after %ld us\n", which[w], r > 0 ? "fired" : "NEVER FIRED within 2 s", c ? c : '-', (t1.tv_sec - t0.tv_sec) * 1000000L + (t1.tv_usec - t0.tv_usec));
    }
    return 0;
}
