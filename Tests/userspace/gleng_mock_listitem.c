/* gleng_mock_listitem.c - Phase 3 mock-environment test of GLEngine _gleAddListItem (stock vs rebuilt) on a VALID context block.
 *   gleng_mock_listitem STOCK REBUILT ANCHOR STOCK_ANCHOR_ADDR REBUILT_ANCHOR_OFF STOCK_FN_ADDR REBUILT_FN_OFF
 * The plain / ctx fuzzers reach this function (it calls realloc) only through garbage context data. Here the context has the fields the function uses:
 *   ctx+0x53e8 -> list block H (data buffer, realloc'd): +0x10 item count, +0x14 table of item sizes (realloc'd), +0x18 table capacity
 *   ctx+0x53fc buffer capacity, ctx+0x5400 bytes used, ctx+0x7574 GL error.
 * Both images run the same call sequence (varied item sizes so the data buffer and the table both grow); the buffer contents (without the realloc'd pointers),
 * the returned offsets, the counters and the error word are compared after every call. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef int (*fn_t)(void *, unsigned, int);
static unsigned char *mk(fn_t f, int variant, unsigned long *log, int *nlog, unsigned *errout, unsigned *cntout) {
    unsigned char *ctx = calloc(1, 0x8000);
    unsigned cap = variant ? 0x40 : 0x100;
    unsigned char *H = calloc(1, cap); unsigned *T = calloc(2, 4);
    *(unsigned **)(ctx + 0x53e8) = (unsigned *)H; *(unsigned *)(ctx + 0x53fc) = cap; *(unsigned *)(ctx + 0x5400) = 0x1c;
    *(unsigned *)(H + 0x10) = 0; *(unsigned **)(H + 0x14) = T; *(unsigned *)(H + 0x18) = 2;
    unsigned sizes[] = { 0x10, 0x4, 0x20, 0x10, 0x10, 0x34, 0x8, 0x10, 0x10, 0x100, 0x10, 0x10, 0x10, 0x4, 0x10 };
    int n = 0;
    for (int i = 0; i < 15; i++) {
        unsigned char *r = (unsigned char *)(unsigned long)f(ctx, 0xC0DE0000u + i, sizes[i] - 4);
        unsigned char *base = *(unsigned char **)(ctx + 0x53e8);
        log[n++] = r ? (unsigned long)(r - base) : 0xffffffffu;
        log[n++] = *(unsigned *)(ctx + 0x5400); log[n++] = *(unsigned *)(ctx + 0x53fc);
        log[n++] = *(unsigned *)(*(unsigned char **)(ctx + 0x53e8) + 0x10); log[n++] = *(unsigned *)(*(unsigned char **)(ctx + 0x53e8) + 0x18);
        if (r) memset(r, 0xA5, sizes[i] - 4);
    }
    *nlog = n; *errout = *(unsigned *)(ctx + 0x7574);
    return ctx;
}
int main(int argc, char **argv) {
    if (argc < 8) return 2;
    void *L[2] = { dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), dlopen(argv[2], RTLD_NOW | RTLD_LOCAL) };
    const char *an = argv[3][0] == '_' ? argv[3] + 1 : argv[3];
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    unsigned sa = strtoul(argv[4], 0, 16), ra = strtoul(argv[5], 0, 16), sf = strtoul(argv[6], 0, 16), rf = strtoul(argv[7], 0, 16);
    fn_t f[2] = { (fn_t)(ap[0] + (sf - sa)), (fn_t)(ap[1] + (rf - ra)) };
    int bad = 0;
    for (int v = 0; v < 2; v++) {
        unsigned long lg[2][200]; int nl[2]; unsigned er[2], cn[2]; unsigned char *c[2];
        for (int k = 0; k < 2; k++) c[k] = mk(f[k], v, lg[k], &nl[k], &er[k], &cn[k]);
        int same = nl[0] == nl[1] && !memcmp(lg[0], lg[1], nl[0] * sizeof lg[0][0]) && er[0] == er[1];
        unsigned char *h0 = *(unsigned char **)(c[0] + 0x53e8), *h1 = *(unsigned char **)(c[1] + 0x53e8);
        unsigned cap = *(unsigned *)(c[0] + 0x53fc);
        if (cap == *(unsigned *)(c[1] + 0x53fc) && memcmp(h0 + 0x10, h1 + 0x10, 8) == 0) { /* skip the pointer word at +0x14 */ }
        int dd = memcmp(h0, h1, 0x10) != 0 || memcmp(h0 + 0x18, h1 + 0x18, cap > 0x18 ? cap - 0x18 : 0) != 0;
        printf("variant %d: calls/log %s, buffer %s (cap %x, error %x/%x)\n", v, same ? "SAME" : "DIFFER", dd ? "DIFFER" : "SAME", cap, er[0], er[1]);
        if (!same || dd) { bad++; for (int i = 0; i < nl[0] && i < nl[1]; i++) if (lg[0][i] != lg[1][i]) { printf("  log[%d]: stock %lx rebuilt %lx\n", i, lg[0][i], lg[1][i]); break; } }
    }
    printf("RESULT: %s\n", bad ? "FAIL" : "PASS");
    return bad;
}
