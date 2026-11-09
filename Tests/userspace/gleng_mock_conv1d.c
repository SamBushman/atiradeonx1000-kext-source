/* gleng_mock_conv1d.c - Phase 3 mock-environment test of GLEngine _gleConvolutionFilter1D / _gleImagingUnpackData / _gleImagingPackData (stock vs rebuilt) on a VALID context block.
 *   gleng_mock_conv1d STOCK REBUILT ANCHOR STOCK_ANCHOR_ADDR REBUILT_ANCHOR_OFF STOCK_CONV_ADDR REBUILT_CONV_OFF
 * _gleConvolutionFilter1D(ctx, target, components, width, format, type, data) frees ctx+0x32cc, mallocs width*pixelBytes(components, GL_FLOAT), unpacks `data` into it with
 * _gleImagingUnpackData (9 arguments: the buffer is the ninth, a caller-stack word) and finishes with _gleImagingScaleAndBias(ctx, ctx+0x32a8 = the scale/bias block, ...).
 * The fuzzers reach it only through random context values (free(garbage) / malloc(random) make the stock and the rebuilt image diverge on heap state alone), so here the context holds
 * what the function reads: the pixel-unpack settings at ctx+0x31cc (row length, skips, alignment 4), the scale/bias block at ctx+0x32a8 (distinct floats, so a wrong scale or bias shows), and no previous buffer.
 * Both images run the same cases; the buffer contents the function produced (width*components floats), the context words it wrote (+0x32c8..+0x32d8 minus the heap pointer) and the GL error are compared. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef void (*fn_t)(void *, unsigned, unsigned, unsigned, unsigned, unsigned, void *);
static int ncomp(unsigned f) { switch (f) { case 0x1906: case 0x1909: case 0x1903: return 1; case 0x190a: return 2; case 0x1907: return 3; case 0x1908: return 4; } return 4; }
int main(int argc, char **argv) {
    if (argc < 8) return 2;
    void *L[2] = { dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), dlopen(argv[2], RTLD_NOW | RTLD_LOCAL) };
    const char *an = argv[3][0] == '_' ? argv[3] + 1 : argv[3];
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    unsigned sa = strtoul(argv[4], 0, 16), ra = strtoul(argv[5], 0, 16), sf = strtoul(argv[6], 0, 16), rf = strtoul(argv[7], 0, 16);
    fn_t f[2] = { (fn_t)(ap[0] + (sf - sa)), (fn_t)(ap[1] + (rf - ra)) };
    struct { unsigned comp, width, fmt, type; } cases[] = {
        { 0x1907, 4, 0x1908, 0x1401 }, { 0x1908, 8, 0x1908, 0x1406 }, { 0x1906, 3, 0x1909, 0x1401 }, { 0x1907, 5, 0x1907, 0x1406 },
        { 0x1908, 1, 0x1908, 0x1401 }, { 0x190a, 6, 0x190a, 0x1401 }, { 0x1907, 7, 0x1908, 0x1403 }, { 0x1908, 2, 0x1908, 0x1405 }, { 0x1907, 0, 0x1908, 0x1401 },
    };
    int bad = 0;
    for (unsigned ci = 0; ci < sizeof cases / sizeof cases[0]; ci++) {
        unsigned char *ctx[2]; unsigned char *data = malloc(4096); for (int i = 0; i < 4096; i++) data[i] = (unsigned char)(i * 37 + ci * 11 + 3);
        if (cases[ci].type == 0x1406) { float *fp = (float *)data; for (int i = 0; i < 1000; i++) fp[i] = (float)((i * 7 + ci) % 23) / 11.0f; }
        for (int k = 0; k < 2; k++) {
            ctx[k] = calloc(1, 0x8000);
            unsigned *u = (unsigned *)(ctx[k] + 0x31cc); u[3] = 4;                                     /* unpack alignment */
            float *sb = (float *)(ctx[k] + 0x32a8); for (int i = 0; i < 8; i++) sb[i] = 0.5f + 0.25f * i;  /* scale/bias block */
            f[k](ctx[k], 0x8031, cases[ci].comp, cases[ci].width, cases[ci].fmt, cases[ci].type, data);
        }
        unsigned w = cases[ci].width; unsigned n = w * ncomp(cases[ci].comp);   /* the buffer is width * pixelBytes(components, GL_FLOAT) = n floats; bytes past it are uninitialised malloc memory */
        unsigned char *b0 = *(unsigned char **)(ctx[0] + 0x32cc), *b1 = *(unsigned char **)(ctx[1] + 0x32cc);
        int dctx = memcmp(ctx[0] + 0x32a0, ctx[1] + 0x32a0, 0x2c) != 0;   /* includes the heap pointer at +0x2c: compare outside it below */
        { unsigned char t0[0x40], t1[0x40]; memcpy(t0, ctx[0] + 0x32a0, 0x40); memcpy(t1, ctx[1] + 0x32a0, 0x40); *(unsigned *)(t0 + 0x2c) = 0; *(unsigned *)(t1 + 0x2c) = 0; dctx = memcmp(t0, t1, 0x40) != 0; }
        int dbuf = (b0 == 0) != (b1 == 0) || (b0 && memcmp(b0, b1, n * 4) != 0);
        int dall = memcmp(ctx[0] + 0x3000, ctx[1] + 0x3000, 0x2c) != 0 || memcmp(ctx[0] + 0x3300, ctx[1] + 0x3300, 0x4000) != 0;
        unsigned fl = 0; if (b0) for (unsigned i = 0; i < n * 4; i++) fl |= b0[i];
        printf("case %u (comp %x width %u fmt %x type %x): ctx %s, buffer %s%s%s (buffer %s, nonzero %s)\n", ci, cases[ci].comp, w, cases[ci].fmt, cases[ci].type, dctx ? "DIFFER" : "SAME", dbuf ? "DIFFER" : "SAME", dall ? ", rest-of-ctx DIFFER" : "", "", b0 ? "alloc" : "null", fl ? "yes" : "no");
        if (dctx || dbuf || dall) bad++;
    }
    printf("RESULT: %s\n", bad ? "FAIL" : "PASS");
    return bad;
}
