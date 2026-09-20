/* va_test.c - load the stock VA driver bundle and the rebuilt one side by side: exports resolve, and _AVAGetRendererInfo (fills a caller buffer, no hardware access)
 * returns the same status and writes the same bytes. */
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
typedef int (*f_t)(void *);
int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    void *a = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), *b = dlopen(argv[2], RTLD_NOW | RTLD_LOCAL);
    printf("stock dlopen %s, rebuilt dlopen %s\n", a ? "ok" : dlerror(), b ? "ok" : dlerror());
    if (!a || !b) return 1;
    const char *names[] = {"AVACreateRenderer", "AVACreateRendererDisplayExt", "AVACreateRendererDVDExt", "AVAGetRendererInfo", 0};
    int ok = 1;
    for (int i = 0; names[i]; i++) {
        void *pa = dlsym(a, names[i]), *pb = dlsym(b, names[i]);
        printf("  %-30s stock=%s rebuilt=%s\n", names[i], pa ? "yes" : "no", pb ? "yes" : "no");
        if (!pa || !pb) ok = 0;
    }
    f_t fa = (f_t)dlsym(a, "AVAGetRendererInfo"), fb = (f_t)dlsym(b, "AVAGetRendererInfo");
    unsigned char ba[512], bb[512];
    memset(ba, 0xAA, sizeof ba); memset(bb, 0xAA, sizeof bb);
    int ra = fa(ba), rb = fb(bb);
    int same = memcmp(ba, bb, sizeof ba) == 0;
    printf("AVAGetRendererInfo: stock -> %d, rebuilt -> %d, buffers %s\n", ra, rb, same ? "identical" : "DIFFERENT");
    if (!same) for (int i = 0; i < 512; i++) if (ba[i] != bb[i]) { printf("  first diff at %d: %02x vs %02x\n", i, ba[i], bb[i]); break; }
    printf("stock buffer head:"); for (int i = 0; i < 48; i++) printf(" %02x", ba[i]); printf("\n");
    printf("RESULT: %s\n", (ok && ra == rb && same) ? "PASS" : "FAIL");
    return 0;
}
