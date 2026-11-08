/* gld_ctxlist_test.c - issue #235: the GLDriver's list of live contexts must be maintained correctly when contexts are destroyed.
 *
 * The driver keeps every context on a singly linked list whose nodes are embedded in the context block (ctx+0x2b90 self, +0x2b94 next; _gldCreateContext inserts at the head,
 * _gldDestroyContext unlinks). The rebuilt corpus declared the head pointer as `unsigned char *`, so the "is the context I am destroying the head?" test compared a pointer with ONE BYTE
 * and the head context was never unlinked: after destroying the most recently created context the list head pointed into freed memory (stock compares words and unlinks it).
 *
 * Sequence (public CGL API only, headless pbuffer pixel format, like cgl_probe.c):
 *   repeat ROUNDS times:  create A, create B (B becomes the list head), destroy B, then malloc-and-fill FILLERS blocks of the context size (0x2b98) with 0xA1 so the freed block of B is
 *   recycled and its embedded "next" word becomes 0xA1A1A1A1, then destroy A.
 * Correct driver: B is unlinked when destroyed, destroying A finds A at the head, nothing touches B's old block -> every round passes.
 * Defective driver: B stays the head, destroying A starts at B's recycled block, follows 0xA1A1A1A1 and faults (EXC_BAD_ACCESS, the Halo crash in gldDestroyContext+112).
 * A fault is caught by a SIGSEGV/SIGBUS handler and reported as RESULT FAIL so the failure is a normal test result (exit 1).
 * The test cannot prove the list is correct when nothing is recycled; it fails reliably on the defective image because same-size blocks are recycled first-fit, and the number of rounds
 * that survived is printed so a "pass" can be compared with a "fail" run.
 * Run (headless, safe over ssh):  ./gld_ctxlist_test   -> prints `RESULT PASS` / `RESULT FAIL ...`; exit 0 / 1. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define ROUNDS 20
#define FILLERS 64
#define CTXSZ 0x2b98

static volatile int g_round = -1;
static void on_fault(int sig) {
    char m[96];
    int n = snprintf(m, sizeof m, "RESULT FAIL: signal %d in round %d (fault while destroying the earlier context)\n", sig, (int)g_round);
    write(1, m, (size_t)n);
    _exit(1);
}

static CGLContextObj make(CGLPixelFormatObj pf, const char *what) {
    CGLContextObj c = NULL; CGLError e = CGLCreateContext(pf, NULL, &c);
    if (e || !c) { printf("RESULT FAIL: CGLCreateContext(%s): %s\n", what, CGLErrorString(e)); exit(1); }
    return c;
}

int main(void) {
    CGLPixelFormatObj pf; GLint npix = 0; int r, j; void *junk[FILLERS];
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    setvbuf(stdout, NULL, _IONBF, 0);
    signal(SIGSEGV, on_fault); signal(SIGBUS, on_fault);
    if (CGLChoosePixelFormat(attrs, &pf, &npix) || npix == 0 || !pf) { printf("RESULT FAIL: no accelerated pixel format\n"); return 1; }
    for (r = 0; r < ROUNDS; r++) {
        CGLContextObj a, b; g_round = r;
        a = make(pf, "A"); b = make(pf, "B");
        CGLDestroyContext(b);
        for (j = 0; j < FILLERS; j++) { junk[j] = malloc(CTXSZ); if (junk[j]) memset(junk[j], 0xA1, CTXSZ); }
        CGLDestroyContext(a);
        for (j = 0; j < FILLERS; j++) free(junk[j]);
    }
    CGLDestroyPixelFormat(pf);
    printf("NOTE rounds survived: %d\nRESULT PASS\n", ROUNDS);
    return 0;
}
