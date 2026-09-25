/* ftoa_test.c - differential test of GLDriver FUN_000cdc3c (value -> decimal string via ecvt; used by the driver's state dump), stock vs rebuilt.
 *
 *   ftoa_test IMAGE EXPORT OFF_EXPORT OFF_FUNC
 *
 * Signature from the machine code: (r3 unused, int ndigit in r4, char *buf in r5, double value in f1) -> buf. The function is not exported:
 * its address is the nm offset rebased with dlsym(EXPORT). Before the Stage B3 fixes the rebuilt copy called ecvt with its arguments in the
 * wrong registers (SysV vs Darwin storage) and never received the value (undeclared f1). Build: gcc -arch ppc -o ftoa_test ftoa_test.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef char *(*ftoa_t)(int, int, char *, double);

int main(int argc, char **argv) {
    static const double v[] = { 0.0, 1.0, -1.0, 0.5, -0.5, 3.14159265358979, -2.718281828, 0.001234, -0.000001234, 123456.789, -98765.4321,
                                1e-10, -1e-10, 2.5e20, -2.5e20, 1e100, 100.0, 0.1, 42.0, -0.0 };
    if (argc < 5) { fprintf(stderr, "usage: ftoa_test IMAGE EXPORT OFF_EXPORT OFF_FUNC\n"); return 2; }
    void *L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!L) { printf("dlopen failed: %s\n", dlerror()); return 2; }
    char *e = (char *)dlsym(L, argv[2]);
    if (!e) { printf("no %s\n", argv[2]); return 2; }
    ftoa_t f = (ftoa_t)(e - strtoul(argv[3], 0, 16) + strtoul(argv[4], 0, 16));
    unsigned i;
    for (i = 0; i < sizeof v / sizeof v[0]; i++) {
        char buf[128]; memset(buf, 0x55, sizeof buf); buf[127] = 0;
        f(0, 10, buf, v[i]);
        printf("%-22.10g -> \"%s\"\n", v[i], buf);
    }
    return 0;
}
