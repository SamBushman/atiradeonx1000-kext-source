/* gleng_mock_map2load.c - Phase 3 mock test of the 13 GLEngine _gleMap2*dLoad functions (stock vs rebuilt, same process) with STRUCTURED arguments.
 *   gleng_mock_map2load STOCK REBUILT ANCHOR STOCK_ANCHOR_ADDR REBUILT_ANCHOR_ADDR [N] < spec     (hex addresses; spec lines: `name stock_addr rebuilt_addr`)
 * Why: the fuzzers call them with random arguments, so almost every call dies at once on the NULL / wild output pointer (stack word 15) and the loops over the control points are never reached
 * (a control that paired _gleMap2Vertex3dLoad with _gleMap2Texture1dLoad as the "rebuilt" function showed 0 differences). Signature (Ghidra, flat): 15 integer words then f1..f13:
 *   word 6 = u stride (doubles), word 7 = u order, word 12 = v stride, word 13 = v order, word 14 = double *points, word 15 = int *out; f1..f4 = u1, u2, v1, v2.
 * The function writes u order, v order, the four range limits and two reciprocals (as floats) at out[0..7], then 1..4 floats per control point. Every trial gives both images an identical points array
 * (random doubles with +-0, +-Inf, NaN, denormal, >FLT_MAX, exact floats), identical strides (1..40) / orders (0..9) and ranges (normal, equal, reversed, NaN, Inf, huge), and a 4096-word out block pre-filled
 * with a sentinel: the WHOLE block and the points array must be identical afterwards (a store outside the expected words shows). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dlfcn.h>
typedef void (*fn_t)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned,
                     double, double, double, double, double, double, double, double, double, double, double, double, double);
static unsigned long long rs = 0x9e3779b97f4a7c15ULL;
static unsigned rnd(void) { rs ^= rs << 13; rs ^= rs >> 7; rs ^= rs << 17; return (unsigned)(rs >> 16); }
static double dval(void) {
    switch (rnd() % 14) {
    case 0: return 0.0; case 1: return -0.0; case 2: return 1.0; case 3: return -1.0;
    case 4: { unsigned long long b = 0x7ff0000000000000ULL; double d; memcpy(&d, &b, 8); return d; }
    case 5: { unsigned long long b = 0xfff0000000000000ULL; double d; memcpy(&d, &b, 8); return d; }
    case 6: { unsigned long long b = 0x7ff8000000000001ULL; double d; memcpy(&d, &b, 8); return d; }
    case 7: return 4.9e-324 * (1 + rnd() % 1000);                 /* double denormal */
    case 8: return 1e300 * (rnd() % 2 ? 1 : -1);                   /* > FLT_MAX */
    case 9: return (double)(float)((int)(rnd() % 20001) - 10000) / 64.0;   /* exact float */
    case 10: return 1e-40 * (1 + rnd() % 100);                     /* float denormal range */
    default: return ((int)(rnd() % 2000001) - 1000000) / 1000.0;
    }
}
static void range(double *a, double *b) {
    switch (rnd() % 8) {
    case 0: *a = 0; *b = 1; break; case 1: *a = 1; *b = 0; break; case 2: *a = *b = dval(); break;
    case 3: *a = dval(); *b = dval(); break; default: *a = (int)(rnd() % 200) - 100; *b = *a + 1 + rnd() % 50; break;
    }
}
#define OUTW 4096
#define NPTS 4096
int main(int argc, char **argv) {
    if (argc < 6) return 2;
    void *L[2] = { dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), dlopen(argv[2], RTLD_NOW | RTLD_LOCAL) };
    const char *an = argv[3][0] == '_' ? argv[3] + 1 : argv[3];
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    unsigned sa = strtoul(argv[4], 0, 16), ra = strtoul(argv[5], 0, 16);
    int N = argc > 6 ? atoi(argv[6]) : 20000;
    if (!ap[0] || !ap[1]) { printf("anchor not found\n"); return 2; }
    char name[96]; unsigned s, r; int nf = 0, nbad = 0;
    while (scanf("%95s %x %x", name, &s, &r) == 3) {
        fn_t f[2] = { (fn_t)(ap[0] + (s - sa)), (fn_t)(ap[1] + (r - ra)) };
        int bad = 0, written = 0;
        for (int t = 0; t < N; t++) {
            static double pts[2][NPTS]; static unsigned out[2][OUTW];
            unsigned us = 1 + rnd() % 40, vs = 1 + rnd() % 40, uo = rnd() % 10, vo = rnd() % 10; double u1, u2, v1, v2;
            if (t % 50 == 0) { uo = 1 + rnd() % 3; vo = 1 + rnd() % 3; }
            range(&u1, &u2); range(&v1, &v2);
            for (int i = 0; i < NPTS; i++) pts[0][i] = pts[1][i] = dval();
            unsigned fill = rnd();
            for (int k = 0; k < 2; k++) { for (int i = 0; i < OUTW; i++) out[k][i] = fill ^ (unsigned)i * 2654435761u; }
            for (int k = 0; k < 2; k++)
                f[k](rnd() & 0, 0x11111111, 0x22222222, 0x33333333, 0x44444444, us, uo, 0x55555555, 0x66666666, 0x77777777, 0x88888888, vs, vo, (unsigned)(unsigned long)pts[k], (unsigned)(unsigned long)out[k],
                     u1, u2, v1, v2, 0.5, 0.25, 0.125, 0.0625, 3.0, 5.0, 7.0, 9.0, 11.0);
            if (memcmp(out[0], out[1], sizeof out[0]) || memcmp(pts[0], pts[1], sizeof pts[0])) { if (bad++ < 3) { int i; for (i = 0; i < OUTW; i++) if (out[0][i] != out[1][i]) break; printf("DIFF %s trial %d us %u uo %u vs %u vo %u: first differing out word %d (stock %08x rebuilt %08x)\n", name, t, us, uo, vs, vo, i, out[0][i % OUTW], out[1][i % OUTW]); } }
            for (int i = 0; i < OUTW; i++) if (out[0][i] != (fill ^ (unsigned)i * 2654435761u)) { written++; break; }
        }
        printf("%-30s %d trials, %d differ; %d trials wrote the out block\n", name, N, bad, written);
        nf++; nbad += bad != 0;
    }
    printf("functions %d; bad %d\nRESULT: %s\n", nf, nbad, nbad ? "FAIL" : "PASS");
    return nbad != 0;
}
