/* forkstress.c - isolate which ingredient of the fnfuzz fork harness takes the G5's Tiger kernel down (Nov 12).
 *
 *   forkstress NAME FLAGS SECONDS RATE LOGFILE
 *
 * Every iteration looks like fnfuzz's run_one(): pipe(), fork(), the child does some work and reports one byte through the
 * pipe, the parent reads it and waitpid()s. FLAGS (sum):
 *    1  child arms ualarm(300000) (the harness does, for its SIGALRM hang detector)
 *    2  child mmap()s a 128 KB fixed arena at 0x50000000, fills it (touches 32 pages), installs SIGSEGV/SIGALRM handlers
 *       and in 3 of 4 iterations dies by dereferencing a bad pointer (handler -> write(pipe) -> _exit), like the fuzz trials
 *    4  the PARENT dlopen()s the stock GLDriver (RTLD_NOW|RTLD_LOCAL) before the loop: CoreFoundation, IOKit, libGLImage,
 *       libstdc++, libGLProgrammability get mapped into the forking process
 *    8  every 10th child blocks SIGALRM and spins; the parent's select() times out after 30 ms and SIGKILLs it (the
 *       harness' watchdog path)
 *   16  (Nov 13, #273 repro) the child spins until ITS OWN timer fires and exits from the signal handler: the timer is ualarm()
 *       (ITIMER_REAL, a kernel thread_call callout) unless flag 32; the exit therefore happens microseconds after the callout ran.
 *   32  with 16: the timer is setitimer(ITIMER_PROF) + SIGPROF (never fires in a forked child on Tiger: ITIMER_VIRTUAL/PROF do not work there, vt_fork.c).
 *   64  with 16: control - the child sets NO timer and spins; the parent select()s FS_ALARM_US and SIGKILLs it (no itimer callout involved).
 * env FS_ALARM_US = timer length in microseconds (default 300000), FS_PAR = children forked per round before waiting (default 1).
 * RATE = forks per second cap (0 = unlimited).
 * Telemetry: one line per second (iterations, achieved rate, status histogram), written + F_FULLFSYNC'd to LOGFILE BEFORE the
 * next second starts, plus one UDP datagram to the dev host, so a panic leaves the last second's state on disk and on the
 * wire. The per-iteration counter is also written every 256 iterations. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static int lfd = -1, usock = -1; static struct sockaddr_in dst;
static void say(const char *fmt, ...) {
    char b[400]; va_list ap; va_start(ap, fmt); int n = vsnprintf(b, sizeof b, fmt, ap); va_end(ap);
    if (n > (int)sizeof b - 1) n = sizeof b - 1;
    if (lfd >= 0) { (void)!write(lfd, b, n);
#ifdef F_FULLFSYNC
        fcntl(lfd, F_FULLFSYNC, 0);
#endif
        fsync(lfd); }
    if (usock >= 0) sendto(usock, b, n, 0, (struct sockaddr *)&dst, sizeof dst);
}

static int wfd_g;
static void on_sig(int s) { char c = 'A' + (s & 15); (void)!write(wfd_g, &c, 1); _exit(2); }

static void child(int flags, unsigned long i, int wfd) {
    wfd_g = wfd;
    if (flags & 16) {
        const char *e = getenv("FS_ALARM_US"); unsigned us = e ? (unsigned)atoi(e) : 300000;
        signal(SIGALRM, on_sig); signal(SIGVTALRM, on_sig); signal(SIGPROF, on_sig);
        if (flags & 32) { struct itimerval it; memset(&it, 0, sizeof it); it.it_value.tv_sec = us / 1000000; it.it_value.tv_usec = us % 1000000; setitimer(ITIMER_PROF, &it, NULL); }
        else if (!(flags & 64)) ualarm(us, 0);
        for (;;) ;
    }
    if (flags & 2) { signal(SIGSEGV, on_sig); signal(SIGBUS, on_sig); signal(SIGALRM, on_sig); signal(SIGILL, on_sig); }
    if (flags & 1) ualarm(300000, 0);
    if ((flags & 8) && i % 10 == 0) { sigset_t m; sigemptyset(&m); sigaddset(&m, SIGALRM); sigprocmask(SIG_BLOCK, &m, NULL); for (;;) ; }
    if (flags & 2) {
        unsigned *w = mmap((void *)0x50000000, 0x20000, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANON | MAP_PRIVATE, -1, 0);
        if (w != (unsigned *)0x50000000) _exit(9);
        unsigned x = (unsigned)i * 2654435761u + 12345;
        for (int k = 0; k < 0x20000 / 4; k++) { x = x * 1664525u + 1013904223u; w[k] = x; }
        if ((i & 3) != 3) { volatile unsigned *bad = (unsigned *)(x | 0x00010000u); if ((unsigned)bad >= 0x50000000u && (unsigned)bad < 0x50020000u) bad += 0x1000000; *bad = 1; }
    }
    char c = 'R'; (void)!write(wfd, &c, 1); _exit(0);
}

int main(int argc, char **argv) {
    if (argc < 6) { fprintf(stderr, "usage: forkstress NAME FLAGS SECONDS RATE LOGFILE\n"); return 2; }
    const char *name = argv[1]; int flags = atoi(argv[2]), secs = atoi(argv[3]), rate = atoi(argv[4]);
    lfd = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0644);
    usock = socket(AF_INET, SOCK_DGRAM, 0); memset(&dst, 0, sizeof dst); dst.sin_family = AF_INET; dst.sin_port = htons(9999); dst.sin_addr.s_addr = inet_addr("192.168.5.213");
    say("FS %s begin flags %d secs %d rate %d pid %d\n", name, flags, secs, rate, (int)getpid());
    if (flags & 4) {
        void *h = dlopen("/Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver", RTLD_NOW | RTLD_LOCAL);
        say("FS %s dlopen %s\n", name, h ? "ok" : dlerror());
    }
    unsigned long it = 0, hist[16]; memset(hist, 0, sizeof hist); unsigned long kills = 0, last_it = 0;
    struct timeval t0, now; gettimeofday(&t0, NULL); long sec_done = 0;
    for (;;) {
        gettimeofday(&now, NULL);
        long el = (now.tv_sec - t0.tv_sec) * 1000000L + (now.tv_usec - t0.tv_usec);
        if (el / 1000000L > sec_done) {
            sec_done = el / 1000000L;
            say("FS %s t=%lds it=%lu rate=%lu/s kills=%lu hist R=%lu SEGV=%lu ALRM=%lu other=%lu\n", name, sec_done, it, it - last_it, kills, hist['R' & 15], hist['A' + 11 & 15] + hist['A' + 10 & 15], hist['A' + 14 & 15], hist[0]);
            last_it = it;
            if (sec_done >= secs) break;
        }
        if (rate > 0 && (unsigned long)(el / 1000000.0 * rate) < it) { usleep(1000); continue; }
        if ((it & 255) == 255) say("FS %s it=%lu\n", name, it);
        { const char *pe = getenv("FS_PAR"); int par = pe ? atoi(pe) : 1; if (par < 1) par = 1; if (par > 16) par = 16;
        int pp[16][2]; pid_t pids[16]; int started = 0;
        for (int k = 0; k < par; k++) {
            if (pipe(pp[k])) { say("FS %s pipe failed %d\n", name, errno); break; }
            pid_t pid = fork();
            if (pid < 0) { say("FS %s fork failed %d\n", name, errno); close(pp[k][0]); close(pp[k][1]); usleep(10000); break; }
            if (pid == 0) { for (int j = 0; j < k; j++) { close(pp[j][0]); } close(pp[k][0]); child(flags, it + k, pp[k][1]); _exit(7); }
            close(pp[k][1]); pids[k] = pid; started++;
        }
        for (int k = 0; k < started; k++) {
            if (flags & (8 | 64)) {
                fd_set rs; FD_ZERO(&rs); FD_SET(pp[k][0], &rs); struct timeval tv = { 0, 30000 };
                if (flags & 64) { const char *e = getenv("FS_ALARM_US"); unsigned us = e ? (unsigned)atoi(e) : 300000; tv.tv_sec = us / 1000000; tv.tv_usec = us % 1000000; }
                if (select(pp[k][0] + 1, &rs, NULL, NULL, &tv) <= 0) { kill(pids[k], SIGKILL); kills++; }
            }
            char c = 0; ssize_t n = read(pp[k][0], &c, 1); int st; waitpid(pids[k], &st, 0); close(pp[k][0]);
            if (n == 1) hist[c & 15]++; else hist[0]++;
            it++;
        } }
    }
    say("FS %s end it=%lu kills=%lu\n", name, it, kills);
    return 0;
}
