/* gleng_mock_color4f_comp.c - mock-context test of GLEngine _glColor4f_Comp (display-list compile of glColor4f), stock vs rebuilt.
 *   gleng_mock_color4f_comp STOCK REBUILT ANCHOR STOCK_ANCHOR REBUILT_ANCHOR FN_S FN_R HANDLER_S HANDLER_R
 * A valid ctx (list block, buffer, table as in gleng_mock_listitem.c) and a spread of float arguments, including doubles that are not floats (rounded by the
 * stores) and NaNs. _glColor4f_Comp ends in a tail call to FUN_00008b68 (stock 0x8b68 = the epilogue millicode that restores f28-f31). Compared: the list item's
 * handler word (relative to each image's _glColor4_ListExec) and the four stored float words. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef void (*fn_t)(void *, double, double, double, double);
static unsigned long long bits(double d) { unsigned long long u; memcpy(&u, &d, 8); return u; }
static double mkd(unsigned long long u) { double d; memcpy(&d, &u, 8); return d; }
int main(int argc, char **argv) {
    if (argc < 10) return 2;
    void *L[2] = { dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), dlopen(argv[2], RTLD_NOW | RTLD_LOCAL) };
    const char *an = argv[3][0] == '_' ? argv[3] + 1 : argv[3];
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    unsigned sa = strtoul(argv[4], 0, 16), ra = strtoul(argv[5], 0, 16);
    unsigned fa[2] = { strtoul(argv[6], 0, 16), strtoul(argv[7], 0, 16) }, ha[2] = { strtoul(argv[8], 0, 16), strtoul(argv[9], 0, 16) };
    unsigned base_a[2] = { sa, ra };
    fn_t f[2]; unsigned long hp[2];
    for (int k = 0; k < 2; k++) { f[k] = (fn_t)(ap[k] + (fa[k] - base_a[k])); hp[k] = ap[k] + (ha[k] - base_a[k]); }
    unsigned long long vals[] = { 0x3fe0000000000000ULL, 0x4025780000000000ULL, 0xbff4000000000000ULL, 0xc021b80000000000ULL, 0, 0x8000000000000000ULL,
        0x3ff0000000000000ULL, 0x3ff0000000000001ULL /* not a float */, 0x47efffffe0000000ULL /* FLT_MAX */, 0x47f0000000000000ULL /* overflows float */,
        0x3690000000000000ULL /* below float denormal range */, 0x380fffffe0000000ULL /* float denormal */, 0x7ff0000000000000ULL, 0x7ff8000000000000ULL, 0x7ff4000000000000ULL /* sNaN */,
        0x3fb999999999999aULL /* 0.1 */ };
    int nv = sizeof vals / sizeof vals[0], bad = 0, n = 0, nfl = 0, badfl = 0;
    for (int i = 0; i < nv; i++) for (int j = 0; j < nv; j += 3) {
        unsigned long long a[4] = { vals[i], vals[(i + j) % nv], vals[(i * 5 + j + 1) % nv], vals[(i + 7 * j) % nv] };
        unsigned w[2][5];
        for (int k = 0; k < 2; k++) {
            unsigned char *ctx = calloc(1, 0x8000), *H = calloc(1, 0x200); unsigned *T = calloc(8, 4);
            *(unsigned char **)(ctx + 0x53e8) = H; *(unsigned *)(ctx + 0x53fc) = 0x200; *(unsigned *)(ctx + 0x5400) = 0x1c;
            *(unsigned *)(H + 0x10) = 0; *(unsigned **)(H + 0x14) = T; *(unsigned *)(H + 0x18) = 8;
            f[k](ctx, mkd(a[0]), mkd(a[1]), mkd(a[2]), mkd(a[3]));
            unsigned char *item = H + 0x1c;
            w[k][0] = *(unsigned *)item == (unsigned)hp[k] ? 1 : 0;
            for (int q = 0; q < 4; q++) w[k][1 + q] = *(unsigned *)(item + 4 + q * 4);
        }
        int allfl = 1; for (int q = 0; q < 4; q++) { double d = mkd(a[q]); if (d != d || (double)(float)d != d) allfl = 0; }   /* every argument exactly a float (an ABI-valid float parameter) */
        n++; nfl += allfl;
        if (memcmp(w[0], w[1], sizeof w[0])) { bad++; badfl += allfl; if (bad <= 8) printf("DIFF args %016llx %016llx %016llx %016llx: stock h=%u %08x %08x %08x %08x | rebuilt h=%u %08x %08x %08x %08x\n", a[0], a[1], a[2], a[3], w[0][0], w[0][1], w[0][2], w[0][3], w[0][4], w[1][0], w[1][1], w[1][2], w[1][3], w[1][4]); }
    }
    printf("%d argument sets, %d differ; of the %d sets whose arguments are all exactly floats, %d differ\nRESULT: %s (float-valued arguments)\n", n, bad, nfl, badfl, badfl ? "FAIL" : "PASS");
    return badfl != 0;
}
