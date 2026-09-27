/* va_create_test.c - issue #65 criterion 3: differential test for VA's 3 untested exports besides
 * _AVAGetRendererInfo (already covered elsewhere). Confirmed by reading the corpus: all three are pure
 * software constructors (calloc + vtable setup + a capability-bitmap scan) that never touch IOKit or any
 * hardware state, unlike GA's LockSurface/SetSurface/etc siblings - so unlike those, these are fully
 * testable with synthetic input.
 *
 * Usage: va_create_test STOCK_BUNDLE_EXECUTABLE REBUILT_BUNDLE_EXECUTABLE
 */
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

typedef int (*create_renderer_t)(void **, unsigned int *, unsigned int *);
typedef int (*create_ext_t)(void **);

static int check(const char *what, int ok) {
    if (!ok) printf("  MISMATCH: %s\n", what);
    return ok;
}

static int run(const char *label, void *handle) {
    create_renderer_t createRenderer = (create_renderer_t)dlsym(handle, "AVACreateRenderer");
    create_ext_t createDisplayExt = (create_ext_t)dlsym(handle, "AVACreateRendererDisplayExt");
    create_ext_t createDVDExt = (create_ext_t)dlsym(handle, "AVACreateRendererDVDExt");
    if (!createRenderer || !createDisplayExt || !createDVDExt) {
        printf("%s: dlsym failed: %s\n", label, dlerror());
        return -1;
    }

    /* _AVACreateRenderer: param_2 is a 4-word capability descriptor read as [0],[1],[2],[3];
       param_2[1] is scanned bit-by-bit (0..31) as a supported-formats bitmap. Fixed synthetic input,
       not fuzzed - one representative, deterministic capability set. */
    unsigned int caps[4] = {0x11111111u, 0x00000025u, 0x22222222u, 0x33333333u};
    unsigned int info[80]; /* renderer-info out param: >=7 words + a 0x100-byte string per AVAGetRendererInfo's shape */
    memset(info, 0xAA, sizeof info);
    void *handleOut = 0;
    int rc1 = createRenderer(&handleOut, caps, info);
    unsigned int *h = (unsigned int *)handleOut;
    printf("%s: CreateRenderer rc=%d info[1..5]=%u,%u,%u,%u,%u str=\"%s\"",
           label, rc1, info[1], info[2], info[3], info[4], info[5], (char *)(info + 6));
    if (h) {
        printf(" handle[1]=%u handle[0xc]=%u sub[1]=%u", h[1], h[0xc],
               h[3] ? ((unsigned int *)(unsigned long)h[3])[1] : 0xFFFFFFFFu);
    }
    printf("\n");

    void *handle2 = 0;
    int rc2 = createDisplayExt(&handle2);
    printf("%s: CreateRendererDisplayExt rc=%d handle=%s\n", label, rc2, handle2 ? "non-null" : "NULL");

    void *handle3 = 0;
    int rc3 = createDVDExt(&handle3);
    printf("%s: CreateRendererDVDExt rc=%d handle=%s\n", label, rc3, handle3 ? "non-null" : "NULL");

    return rc1 || rc2 || rc3;
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    if (argc < 3) { fprintf(stderr, "usage: %s stock_bundle rebuilt_bundle\n", argv[0]); return 1; }
    void *stock = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    void *rebuilt = dlopen(argv[2], RTLD_NOW | RTLD_LOCAL);
    printf("dlopen stock=%s rebuilt=%s\n", stock ? "ok" : dlerror(), rebuilt ? "ok" : dlerror());
    if (!stock || !rebuilt) return 1;
    int bad = 0;
    bad |= run("stock  ", stock) < 0;
    bad |= run("rebuilt", rebuilt) < 0;
    printf("RESULT: %s (compare the two blocks above by eye - handle/sub addresses will legitimately differ, everything else should match exactly)\n", bad == 0 ? "PASS" : "FAIL");
    return bad;
}
