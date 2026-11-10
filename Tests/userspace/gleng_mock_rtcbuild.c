/* gleng_mock_rtcbuild.c - Phase 3 structured mock of the GLEngine RTC (run-time-compiled) function builders, stock vs rebuilt.
 *   gleng_mock_rtcbuild STOCK REBUILT ANCHOR SA RA CELLS ALLOCVA_S ALLOCVA_R ALLOCFN_S ALLOCFN_R [NTRIALS] [CTL] < spec
 *   CELLS = PROC_S,PROC_R,PUSH_S,PUSH_R  (hex image addresses of the two pointer cells: the stock cells 0x11204c / 0x112054 and the rebuilt
 *           PTR__gle_processor_0011204c / PTR__glePushInstructions_00112054; each holds the address of the global it names)
 *   spec lines: name stock_addr reb_off      (reb_off is the rebuilt FILE address; fn = anchor + (addr - anchor_addr), like fnfuzz ledgers)
 * Why a mock: fnfuzz hands the builders a garbage context; each builder starts with _gleCreateFuncCacheElem(*(ctx+0x49b8) ...) and ends with an
 * indirect call through _glePushInstructions, so on a garbage context both images fault at once and a mismatch control is NOT detected (11 of 18 blind).
 * Here every case builds its own valid context in a forked child (so the heap layout is identical in the stock and rebuilt child):
 *   ctx = zeroed block, ctx+0x468c -> a block with the +0x94 mode word, then BOTH images' own _gleAllocVertexArrays and _gleAllocFunctions create the
 *   function-cache lists (ctx+0x49b4/+0x49b8, +0x5088.., ...), then the flag fields the builders read (+0x498c, +0x4990, +0x49c0/+0x49c2, +0x4661, +0x4fe8,
 *   +0x280d, +0x50b4, blk+0x94) and the global _gle_processor are set from a per-trial PRNG, and the builder runs with (ctx, key).
 *   The hook stored in the _glePushInstructions variable records (nwords, code); what is compared is: the return value, the recorded nwords + every generated
 *   code word, and every byte of the context and the +0x468c block afterwards (heap pointers agree because both children allocate identically).
 * Liveness: the report says how many trials produced code (the builder returned a code pointer) and how many DISTINCT generated blocks there were. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <sys/mman.h>
#define CTXSZ 0x8000
#define MAXW 0x200
#define MAXLOG 64
typedef unsigned (*bfn_t)(unsigned char *, unsigned);
typedef void (*afn_t)(unsigned char *);
typedef struct { int status; unsigned ret, nw, hooked_n, hooked_p; unsigned code[MAXW]; unsigned long long dctx, dblk; unsigned nlog, log[MAXLOG]; } res_t;
static unsigned chunklog[MAXLOG], nlog;     /* source address of every _gleRTCAddAChunk_* call made by the builder (the clones are patched to jump here) */
static unsigned chunk_hook(unsigned *src, unsigned *dst) {
    if (nlog < MAXLOG) chunklog[nlog] = (unsigned)(unsigned long)src; nlog++;
    unsigned n = 0, v; while ((v = src[n]) != 0) { dst[n] = v; n++; }
    return n;
}
static void patch_entry(unsigned long fn, void *to) {   /* lis r12,hi ; ori r12,r12,lo ; mtctr r12 ; bctr */
    unsigned t = (unsigned)(unsigned long)to; unsigned *p = (unsigned *)fn;
    unsigned long pg = fn & ~0xfffUL;
    if (mprotect((void *)pg, 0x2000, PROT_READ | PROT_WRITE | PROT_EXEC)) perror("mprotect");
    p[0] = 0x3d800000u | (t >> 16); p[1] = 0x618c0000u | (t & 0xffff); p[2] = 0x7d8903a6u; p[3] = 0x4e800420u;
    for (int i = 0; i < 4; i++) __asm__ volatile("dcbst 0,%0 ; sync ; icbi 0,%0 ; sync ; isync" : : "r"(p + i) : "memory");
}
static res_t *shm_res;   /* filled by the hook inside the child */
static void hook(int n, unsigned *code) {
    shm_res->hooked_n = (unsigned)n; shm_res->hooked_p = (unsigned)(unsigned long)code;
    int k = n < MAXW ? n : MAXW; shm_res->nw = (unsigned)k;
    for (int i = 0; i < k; i++) shm_res->code[i] = code[i];
}
static unsigned long long fnv(const unsigned char *p, size_t n) { unsigned long long h = 1469598103934665603ULL; while (n--) { h ^= *p++; h *= 1099511628211ULL; } return h; }
static unsigned rs;
static unsigned rnd(void) { rs = rs * 1664525u + 1013904223u; return rs >> 8 | rs << 24; }
typedef struct { bfn_t b; afn_t av, af; unsigned *proc; unsigned *push; } img_t;
static void child_run(int wfd, img_t *I, unsigned key, unsigned seed) {
    static res_t R; shm_res = &R; memset(&R, 0, sizeof R);
    rs = seed * 2654435761u + 12345; for (int i = 0; i < 4; i++) rnd();
    unsigned char *ctx = calloc(1, CTXSZ), *blk = calloc(1, 0x400);
    *(unsigned char **)(ctx + 0x468c) = blk;
    I->av(ctx); I->af(ctx);
    unsigned r = rnd();
    *(unsigned *)(ctx + 0x498c) = (rnd() & 0xffff0000u) | (r & 0xffff);
    *(unsigned short *)(ctx + 0x4990) = (unsigned short[]){ 0x10, 0x20, 0x21, 0x30, 0x40 }[rnd() % 5];
    *(unsigned *)(blk + 0x94) = rnd() & 0xff;
    *(unsigned *)I->proc = (rnd() & 1) ? 0x10 : 0;
    ctx[0x4661] = rnd() & 1; ctx[0x280d] = rnd() & 1; ctx[0x50b4] = rnd() & 1;
    *(unsigned short *)(ctx + 0x4fe8) = rnd() % 0x40;
    if (rnd() & 1) { unsigned short v = rnd() % 8; *(unsigned short *)(ctx + 0x49c0) = v; *(unsigned short *)(ctx + 0x49c2) = v; }
    if (rnd() & 1) { unsigned short v = rnd() % 8; *(unsigned short *)(ctx + 0x49bc) = v; *(unsigned short *)(ctx + 0x49be) = v; }
    *(unsigned *)I->push = (unsigned)(unsigned long)hook;
    nlog = 0; R.ret = I->b(ctx, key); R.nlog = nlog < MAXLOG ? nlog : MAXLOG; memcpy(R.log, chunklog, sizeof R.log);
    R.dctx = fnv(ctx, CTXSZ); R.dblk = fnv(blk, 0x400);
    write(wfd, &R, sizeof R);
    _exit(0);
}
static int run_one(img_t *I, unsigned key, unsigned seed, res_t *out) {
    int fd[2]; pipe(fd); fflush(stdout);
    pid_t p = fork();
    if (p == 0) { close(fd[0]); alarm(5); child_run(fd[1], I, key, seed); _exit(9); }
    close(fd[1]);
    size_t got = 0; ssize_t k; char *dst = (char *)out; int st = 0;
    while (got < sizeof *out && (k = read(fd[0], dst + got, sizeof *out - got)) > 0) got += k;
    close(fd[0]); waitpid(p, &st, 0);
    if (got != sizeof *out) { memset(out, 0, sizeof *out); out->status = WIFSIGNALED(st) ? WTERMSIG(st) : 99; }
    return 0;
}
int main(int argc, char **argv) {
    if (argc < 11) { fprintf(stderr, "usage\n"); return 2; }
    void *L[2] = { dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), dlopen(argv[2], RTLD_NOW | RTLD_LOCAL) };
    if (!L[0] || !L[1]) { fprintf(stderr, "dlopen: %s\n", dlerror()); return 2; }
    const char *an = argv[3][0] == '_' ? argv[3] + 1 : argv[3];
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    unsigned sa = strtoul(argv[4], 0, 16), ra = strtoul(argv[5], 0, 16);
    unsigned long slide[2] = { ap[0] - sa, ap[1] - ra };
    unsigned cell[4]; sscanf(argv[6], "%x,%x,%x,%x", &cell[0], &cell[1], &cell[2], &cell[3]);
    img_t I[2];
    I[0].proc = *(unsigned **)(slide[0] + cell[0]); I[1].proc = *(unsigned **)(slide[1] + cell[1]);
    I[0].push = *(unsigned **)(slide[0] + cell[2]); I[1].push = *(unsigned **)(slide[1] + cell[3]);
    I[0].av = (afn_t)(ap[0] + strtoul(argv[7], 0, 16) - sa); I[1].av = (afn_t)(ap[1] + strtoul(argv[8], 0, 16) - ra);
    I[0].af = (afn_t)(ap[0] + strtoul(argv[9], 0, 16) - sa); I[1].af = (afn_t)(ap[1] + strtoul(argv[10], 0, 16) - ra);
    unsigned noop[2] = { *(unsigned *)(slide[0] + 0x112058), *(unsigned *)(slide[1] + 0x143328) };   /* PTR__gleRTCNoop cells: hold the (rebased) address of _gleRTCNoop */
    int ntr = argc > 11 ? atoi(argv[11]) : 400; int ctl = argc > 12 ? atoi(argv[12]) : 0;
    fprintf(stderr, "cells: stock proc %p push %p ; rebuilt proc %p push %p\n", (void *)I[0].proc, (void *)I[0].push, (void *)I[1].proc, (void *)I[1].push);
    char nm[128]; unsigned sadr[64], radr[64]; char names[64][128]; int nf = 0;
    while (nf < 64 && scanf("%127s %x %x", nm, &sadr[nf], &radr[nf]) == 3) {
        if (nm[0] == '@') { patch_entry(ap[0] + sadr[nf] - sa, (void *)chunk_hook); patch_entry(ap[1] + radr[nf] - ra, (void *)chunk_hook); continue; }   /* "@chunk stock reb": patch both images' _gleRTCAddAChunk clone */
        strcpy(names[nf], nm); nf++; }
    int total_bad = 0, total = 0;
    for (int f = 0; f < nf; f++) {
        int g = ctl ? (f + 1) % nf : f;      /* control: run the stock function against a different rebuilt function */
        I[0].b = (bfn_t)(ap[0] + sadr[f] - sa); I[1].b = (bfn_t)(ap[1] + radr[g] - ra);
        int bad = 0, produced = 0, died0 = 0, died1 = 0, distinct = 0; unsigned long long seen[512]; int ns = 0;
        for (int t = 0; t < ntr; t++) {
            unsigned key = t < 256 ? (unsigned)t : (unsigned)(t * 2654435761u);
            res_t a, b; run_one(&I[0], key, t, &a); run_one(&I[1], key, t, &b);
            total++;
            if (a.status) died0++; if (b.status) died1++;
            int same = a.status == b.status;
            if (!a.status) { if (a.ret == noop[0]) a.ret = 0xdeadbeef; if (b.ret == noop[1]) b.ret = 0xdeadbeef; }   /* each image returns ITS OWN _gleRTCNoop */
            if (same && !a.status) same = a.ret == b.ret && a.hooked_n == b.hooked_n && a.nw == b.nw && !memcmp(a.code, b.code, a.nw * 4) && a.dctx == b.dctx && a.dblk == b.dblk && a.hooked_p == b.hooked_p;
            if (!a.status && a.nw) { produced++; unsigned long long h = fnv((unsigned char *)a.code, a.nw * 4) ^ a.nw; int i; for (i = 0; i < ns; i++) if (seen[i] == h) break; if (i == ns && ns < 512) { seen[ns++] = h; distinct++; } }
            if (!same && getenv("RTC_DUMP") && !a.status && !b.status && bad < 2) {
                unsigned m = a.nw < b.nw ? a.nw : b.nw, i = 0; while (i < m && a.code[i] == b.code[i]) i++;
                { unsigned k = 0; while (k < a.nlog && k < b.nlog && a.log[k] - (unsigned)slide[0] == (unsigned)0 + 0 * 1 + 0 && 0) k++; }
                printf("  chunk calls %u/%u:", a.nlog, b.nlog); for (unsigned k = 0; k < a.nlog && k < b.nlog && k < 40; k++) printf(" [%x|%x]", a.log[k] - (unsigned)slide[0], b.log[k] - (unsigned)slide[1]); printf("\n");
                printf("  first differing word %u of %u/%u; stock:", i, a.nw, b.nw); for (unsigned j = i > 2 ? i - 2 : 0; j < i + 10 && j < a.nw; j++) printf(" %08x", a.code[j]);
                printf("\n                       rebuilt:"); for (unsigned j = i > 2 ? i - 2 : 0; j < i + 10 && j < b.nw; j++) printf(" %08x", b.code[j]); printf("\n");
            }
            if (!same) { bad++; total_bad++; if (bad <= 3) printf("DIFF %s trial %d key %#x: status %d/%d ret %#x/%#x nw %u/%u code %s ctx %s blk %s\n", names[f], t, key, a.status, b.status, a.ret, b.ret, a.nw, b.nw, (a.nw == b.nw && !memcmp(a.code, b.code, a.nw * 4)) ? "same" : "DIFFER", a.dctx == b.dctx ? "same" : "DIFFER", a.dblk == b.dblk ? "same" : "DIFFER"); }
        }
        printf("%-34s %4d trials, %4d differ; stock died %d rebuilt died %d; generated code in %d trials, %d distinct blocks\n", names[f], ntr, bad, died0, died1, produced, distinct);
    }
    printf("trials %d; bad %d\nRESULT: %s\n", total, total_bad, total_bad ? "FAIL" : "PASS");
    return total_bad != 0;
}
