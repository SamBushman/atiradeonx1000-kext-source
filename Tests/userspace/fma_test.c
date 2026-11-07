/* fma_test.c - issue #229: the stock libGLProgrammability computes a*b+c with ONE rounding (fmadds); the -O0 rebuilt image used fmuls+fadds (two roundings, last-bit
 * differences). _InterpreterNoiseGeneratorInterpolate (result[i] = w[i]*(b[i]-a[i]) + a[i], four floats) is called on random floats and compared with the single-rounding
 * reference (the product of two floats is exact in a double, so (float)((double)w*(double)d + (double)a) with d = b-a rounded to float is the fused result up to a
 * double-rounding case of probability 2^-29 per value).
 *
 *   fma_test IMAGE EXPORT OFF_EXPORT OFF_FUNC [cases]
 *
 * Run on the stock image (must print 0 WRONG: validates the reference) and on the rebuilt one. The function is not exported: the address is the nm offset rebased on
 * dlsym(EXPORT). Build: gcc -arch ppc -o fma_test fma_test.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef void (*interp_t)(int noise, float *a, float *b, float *w, float *r);

static float rnd(unsigned *s) {
    float v; unsigned x;
    *s = *s * 1103515245u + 12345u; x = *s;
    switch ((x >> 28) & 3) {
    case 0: v = (float)((int)(x & 0xffff) - 0x8000) / 256.0f; break;
    case 1: v = (float)(x >> 8) / 16777216.0f; break;
    case 2: v = (float)((int)(x >> 4) - 0x8000000) / 65536.0f; break;
    default: v = (float)(x & 0xfffff) / 1048576.0f; break;
    }
    return v;
}

int main(int argc, char **argv) {
    int cases = argc > 5 ? atoi(argv[5]) : 200000, c, k, wrong = 0;
    unsigned seed = 229;
    if (argc < 5) { fprintf(stderr, "usage: fma_test IMAGE EXPORT OFF_EXPORT OFF_FUNC [cases]\n"); return 2; }
    void *L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!L) { printf("dlopen failed: %s\n", dlerror()); return 2; }
    char *e = (char *)dlsym(L, argv[2]);
    if (!e) { printf("no %s\n", argv[2]); return 2; }
    interp_t f = (interp_t)(e - strtoul(argv[3], 0, 16) + strtoul(argv[4], 0, 16));
    setvbuf(stdout, NULL, _IONBF, 0);
    for (c = 0; c < cases; c++) {
        float a[4], b[4], w[4], r[4];
        for (k = 0; k < 4; k++) { a[k] = rnd(&seed); b[k] = rnd(&seed); w[k] = rnd(&seed); r[k] = 0; }
        f(0, a, b, w, r);
        for (k = 0; k < 4; k++) {
            float d = b[k] - a[k], want = (float)((double)w[k] * (double)d + (double)a[k]);
            if (memcmp(&want, &r[k], 4)) { if (++wrong <= 10) printf("case %d lane %d: a=%a b=%a w=%a got %a want %a WRONG\n", c, k, a[k], b[k], w[k], r[k], want); }
        }
    }
    printf("RESULT: %s (%d wrong of %d values)\n", wrong ? "FAIL" : "PASS", wrong, cases * 4);
    return wrong ? 1 : 0;
}
