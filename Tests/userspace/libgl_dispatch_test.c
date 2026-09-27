/* libgl_dispatch_test.c - every exported gl* entry point of libGL, stock vs rebuilt, through a FAKE context whose dispatch table records the calls (issue #65 criterion 2).
 *
 *   libgl_dispatch_test IMAGE UNUSED [SEED] > out.txt      (libgl_dispatch.py runs SEED 0 and 1 on both images and compares only the live positions)
 *
 * libGL's entry points are stubs: fetch the current context (`*_gll_cc`), check the thread tag at ctx+0xab0 against the stack, load a function pointer from the context and tail-call it
 * with the caller's argument registers. Here `_gll_cc` points at a buffer whose every word is the address of a recording thunk (libgl_dispatch_gen.py: thunk i = `li r12,i; b record`), so
 * the call lands in the recorder, which stores r3..r10, f1..f13 and 24 stack words of the dispatch frame (from r1+0x38: the first stack-passed argument). Each function is called with sentinel arguments of every register class
 * (8 integers, 13 doubles, 8 stack integers); the output lists, per function, the dispatch slot that was called and every recorded argument. A stub that drops or reorders a
 * float / stack argument (the FPR-forwarding case) differs. Build: python3 libgl_dispatch_gen.py 4096 > /tmp/thunks.s; python3 libgl_dispatch_gen_calls.py gl.h glext.h > /tmp/dsp_calls.c; gcc -arch ppc -w -std=gnu99 -o libgl_dispatch_test libgl_dispatch_test.c /tmp/dsp_calls.c /tmp/thunks.s */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <alloca.h>
#include <signal.h>
#include <setjmp.h>

extern char dsp_thunks[];
unsigned char *dsp_pos;
static unsigned char recbuf[240 * 64];
static unsigned ctx[0x4000 / 4] __attribute__((aligned(64)));
typedef struct { const char *name; void (*call)(void *, const int *, const double *); } dsp_entry;
extern dsp_entry dsp_table[];
static jmp_buf jb;
static void onsig(int s) { longjmp(jb, s); }
static int SEED; static int IARR[128]; static double DARR[64];
extern void dsp_clear(void);
static void call_deep(dsp_entry *e, void *f, void **cc) {
    volatile char *pad = alloca(64);
    unsigned sp = (unsigned)&pad;
    if ((sp & 0xfff) < 0xa00) { call_deep(e, f, cc); return; }              /* keep the stub's frame in the same 4K page as the tag we store */
    ctx[0xab0 / 4] = sp - 0x100; *cc = ctx;
    dsp_clear();
    e->call(f, IARR, DARR);
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IOLBF, 0);
    void *L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL); if (!L) { printf("DLOPEN FAILED %s\n", dlerror()); return 2; }
    SEED = argc > 3 ? atoi(argv[3]) : 0;
    for (int k = 0; k < 32; k++) { IARR[k] = 0x5a000000 + SEED * 0x10000 + k * 0x101; IARR[32 + k] = 0x5b000000 + SEED * 0x10000 + k * 0x101; IARR[64 + k] = 0x20 + k * 4 + SEED; IARR[96 + k] = 0x2000 + k * 16 + SEED;
                                 DARR[k] = 100.0 + SEED * 1000.0 + k * 10.0; DARR[32 + k] = 2000.5 + SEED * 1000.0 + k * 10.0; }
    void **cc = dlsym(L, "gll_cc"); if (!cc) { printf("NO gll_cc\n"); return 2; }
    for (int i = 0; i < 0x4000 / 4; i++) ctx[i] = (unsigned)(dsp_thunks + 8 * i);
    signal(SIGSEGV, onsig); signal(SIGBUS, onsig); signal(SIGILL, onsig);
    int nok = 0, nrec = 0;
    for (dsp_entry *e = dsp_table; e->name; e++) {
        const char *sym = e->name;
        void *f = dlsym(L, sym); if (!f) continue;
        dsp_pos = recbuf; memset(recbuf, 0, sizeof recbuf);
        int s = setjmp(jb);
        if (s) { printf("%s: SIGNAL %d after %ld records\n", sym, s, (long)(dsp_pos - recbuf) / 240); continue; }
        call_deep(e, f, cc);
        long n = (dsp_pos - recbuf) / 240; nok++; nrec += n;
        printf("%s: %ld record(s)\n", sym, n);
        for (long r = 0; r < n; r++) {
            unsigned *w = (unsigned *)(recbuf + 240 * r);
            printf("  slot %u gpr %x %x %x %x %x %x %x %x fpr", w[0] * 4, w[1], w[2], w[3], w[4], w[5], w[6], w[7], w[8]);
            for (int k = 0; k < 13; k++) { double d; memcpy(&d, w + 10 + 2 * k, 8); printf(" %g", d); }
            printf(" stack"); for (int k = 0; k < 24; k++) printf(" %x", w[36 + k]); printf("\n");
        }
    }
    printf("TOTAL %d functions, %d records\n", nok, nrec);
    return 0;
}
