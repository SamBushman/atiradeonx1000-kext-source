/* table_lookup_inrange_test.c - GLDriver table-lookup functions (FUN_00126708/126760/12678c/10406c/10e368/ec258/1896f8) stock vs rebuilt on IN-RANGE indices only.
 * fnfuzz feeds wild indices into these, so crash/value differences there are address-layout artifacts (each image reads a different neighbour of the table); this test removes that.
 * usage: cmpf STOCK REBUILT REB_gldGetString_off REB_126708 REB_126760 REB_12678c REB_10406c REB_10e368 REB_ec258 REB_1896f8   (hex nm offsets; LIM=n limits the 0x126xxx/10406c index range; the table has 71 entries) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef unsigned (*f2)(unsigned, unsigned);
int main(int argc, char **argv) {
    void *a = dlopen(argv[1], RTLD_NOW|RTLD_LOCAL), *b = dlopen(argv[2], RTLD_NOW|RTLD_LOCAL);
    char *ba = dlsym(a, "gldGetString"), *bb = dlsym(b, "gldGetString");
    unsigned as = 0x39250, ar = strtoul(argv[3], 0, 16);
    struct { const char *n; unsigned so, ro; int kind; } F[] = {
        {"126708", 0x126708, strtoul(argv[4],0,16), 0}, {"126734", 0x126734, 0, 0}, {"126760", 0x126760, strtoul(argv[5],0,16), 0}, {"12678c", 0x12678c, strtoul(argv[6],0,16), 0},
        {"10406c", 0x10406c, strtoul(argv[7],0,16), 0}, {"10e368", 0x10e368, strtoul(argv[8],0,16), 0}, {"ec258", 0xec258, strtoul(argv[9],0,16), 1}, {"1896f8", 0x1896f8, strtoul(argv[10],0,16), 2},
    };
    for (unsigned i = 0; i < sizeof F / sizeof *F; i++) {
        if (!F[i].ro) continue;
        f2 fs = (f2)(ba - as + F[i].so), fr = (f2)(bb - ar + F[i].ro); int n = 0, bad = 0;
        if (F[i].kind == 0) for (unsigned x = 0; x < (unsigned)atoi(getenv("LIM") ? getenv("LIM") : "512"); x++) { n++; if (fs(x, 0) != fr(x, 0)) { if (bad++ < 3) printf("  %s idx %u: stock %u rebuilt %u\n", F[i].n, x, fs(x,0), fr(x,0)); } }
        else if (F[i].kind == 1) for (unsigned x = 0; x < 64; x++) { n++; if (fs(0, x) != fr(0, x)) { if (bad++ < 3) printf("  %s idx %u: stock %08x rebuilt %08x\n", F[i].n, x, fs(0,x), fr(0,x)); } }
        else for (unsigned p = 0; p < 625; p++) { unsigned v = ((p/125)%5)<<24 | ((p/25)%5)<<16 | ((p/5)%5)<<8 | (p%5); n++; if (fs(v, 0) != fr(v, 0)) { if (bad++ < 3) printf("  %s arg %08x: stock %u rebuilt %u\n", F[i].n, v, fs(v,0), fr(v,0)); } }
        printf("FUN_%s: %d in-range inputs, %d differ\n", F[i].n, n, bad);
    }
    return 0;
}
