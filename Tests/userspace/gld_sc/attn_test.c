/* attn_test.c - #273 confirmation (Nov 13): does executing a data word that decodes as the PPC970 `attn` instruction (primary opcode 0, XO 256: 0x00000200, e.g. the pointer 0x01710a00 trial 7 of
 * Program__emitMovFromFieldA4 branches to) take the G5 down?  Each step runs in a forked child with SIGILL/SIGSEGV/SIGBUS handlers; the parent mirrors a line to UDP 192.168.5.213:9999 and fsyncs the log
 * BEFORE the child runs, so a hang leaves "ABOUT TO EXEC" as the last line.
 *   attn_test LOGFILE
 * steps: 1 word 0x00000000 (illegal instruction: expected SIGILL), 2 word 0x4e800020 (blr: harmless), 3 word 0x01710a00 (the real word), 4 word 0x00000200 (plain attn). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
static int lfd = -1, us = -1; static struct sockaddr_in dst;
static void say(const char *fmt, ...) {
    char b[300]; va_list ap; va_start(ap, fmt); int n = vsnprintf(b, sizeof b, fmt, ap); va_end(ap); if (n > (int)sizeof b - 1) n = sizeof b - 1;
    if (lfd >= 0) { (void)!write(lfd, b, n); fcntl(lfd, F_FULLFSYNC, 0); fsync(lfd); }
    if (us >= 0) sendto(us, b, n, 0, (struct sockaddr *)&dst, sizeof dst);
}
static int wfd;
static void h(int s) { char c = 'A' + s; (void)!write(wfd, &c, 1); _exit(2); }
static void run_step(int step, unsigned word) {
    int p[2]; if (pipe(p)) return; pid_t pid = fork();
    if (pid == 0) {
        close(p[0]); wfd = p[1]; signal(SIGILL, h); signal(SIGSEGV, h); signal(SIGBUS, h); signal(SIGTRAP, h);
        unsigned *pg = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
        pg[0] = word; pg[1] = 0x4e800020u;   /* the word, then a blr in case it falls through */
        __asm__ volatile("dcbst 0,%0\n\tsync\n\ticbi 0,%0\n\tsync\n\ticbi 0,%1\n\tsync\n\tisync" : : "r"(pg), "r"(pg + 1) : "memory");
        ((void (*)(void))pg)();
        char c = 'S'; (void)!write(wfd, &c, 1); _exit(0);   /* survived: executed the word and returned */
    }
    close(p[1]); char c = '?'; ssize_t n = read(p[0], &c, 1); int st = 0; waitpid(pid, &st, 0); close(p[0]);
    say("ATTN step %d word %08x -> child %s (byte %c, status %d sig %d)\n", step, word, n == 1 && c == 'S' ? "RETURNED" : n == 1 ? "SIGNAL-HANDLED" : "NO RESULT", n == 1 ? c : '-', WIFEXITED(st) ? WEXITSTATUS(st) : -1, WIFSIGNALED(st) ? WTERMSIG(st) : 0);
}
int main(int argc, char **argv) {
    lfd = open(argc > 1 ? argv[1] : "attn_test.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
    us = socket(AF_INET, SOCK_DGRAM, 0); memset(&dst, 0, sizeof dst); dst.sin_family = AF_INET; dst.sin_port = htons(9999); dst.sin_addr.s_addr = inet_addr("192.168.5.213");
    static const unsigned words[4] = { 0x00000000u, 0x4e800020u, 0x01710a00u, 0x00000200u };
    say("ATTN begin pid %d\n", (int)getpid());
    for (int i = 0; i < 4; i++) { say("ATTN step %d ABOUT TO EXEC %08x\n", i + 1, words[i]); run_step(i + 1, words[i]); }
    say("ATTN end: all steps survived\n");
    return 0;
}
