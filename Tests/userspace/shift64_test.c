/* shift64_test.c - libGLProgrammability's libgcc 64-bit shift helpers ___lshrdi3 / ___ashldi3 (issue #228), stock vs rebuilt.
 *
 *   shift64_test IMAGE EXPORT OFF_EXPORT OFF_LSHR OFF_ASHL
 *
 * Both take a 64-bit value in r3:r4 (high word first) and a shift count in r5 and return the 64-bit result in r3:r4; they are called here as
 * `unsigned long long f(unsigned hi, unsigned lo, unsigned n)` over a grid of values and shift counts 0..40. The output (one line per case) must be identical
 * for the two images and equal to the C operators' results; a mismatch against the C operators is printed as WRONG. The functions are not exported: the address
 * is the nm offset rebased on dlsym(EXPORT). Build: gcc -arch ppc -o shift64_test shift64_test.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef unsigned long long (*sh_t)(unsigned, unsigned, unsigned);

int main(int argc, char **argv) {
    static const unsigned vals[] = { 0, 1, 0xf, 0x80000000u, 0xffffffffu, 0x12345678u, 0xdeadbeefu, 0x0000ffffu };
    unsigned i, j, n; int wrong = 0;
    sh_t f[2]; static const char *nm[2] = { "___lshrdi3", "___ashldi3" };
    if (argc < 6) { fprintf(stderr, "usage: shift64_test IMAGE EXPORT OFF_EXPORT OFF_LSHR OFF_ASHL\n"); return 2; }
    void *L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!L) { printf("dlopen failed: %s\n", dlerror()); return 2; }
    char *e = (char *)dlsym(L, argv[2]);
    if (!e) { printf("no %s\n", argv[2]); return 2; }
    f[0] = (sh_t)(e - strtoul(argv[3], 0, 16) + strtoul(argv[4], 0, 16));
    f[1] = (sh_t)(e - strtoul(argv[3], 0, 16) + strtoul(argv[5], 0, 16));
    setvbuf(stdout, NULL, _IONBF, 0);
    for (n = 0; n < 2; n++)
        for (i = 0; i < sizeof vals / sizeof vals[0]; i++)
            for (j = 0; j < sizeof vals / sizeof vals[0]; j++) {
                unsigned s;
                for (s = 0; s <= 40; s++) {
                    unsigned long long v = ((unsigned long long)vals[i] << 32) | vals[j], got, want;
                    if (s >= 32 && n == 0) { /* a shift of 32..63 is defined for both helpers; 40 is the largest tested */ }
                    got = f[n](vals[i], vals[j], s);
                    want = n == 0 ? (v >> s) : (v << s);
                    if (got != want) { wrong++; printf("%s(%08x:%08x, %2u) = %016llx WRONG (want %016llx)\n", nm[n], vals[i], vals[j], s, got, want); }
                    else if (s == 0 || s == 5 || s == 32 || s == 33) printf("%s(%08x:%08x, %2u) = %016llx\n", nm[n], vals[i], vals[j], s, got);
                }
            }
    printf("RESULT: %s (%d wrong)\n", wrong ? "FAIL" : "PASS", wrong);
    return wrong ? 1 : 0;
}
