/* ga_probe_test.c - issue #65 criterion 3: differential test for ATIRadeonX1000GA's `_Probe` (the
 * IOCFPlugInInterface Probe method - standard signature (self, propertyTable, service, order_out)).
 * Confirmed by reading the corpus: this specific function touches none of its incoming pointers -
 * `*param_4 = 2000; return 0;` - so it is genuinely callable without hardware, unlike its 5 siblings
 * (_SetDestination/_LockSurface/_SetSurface/_SwapSurface/_UnlockSurface), which all dereference a
 * real IOKit connection a real CFPlugIn Start() call would have opened and so are recorded as
 * hardware-dependent instead of exercised here.
 *
 * Usage: ga_probe_test STOCK_BUNDLE_EXECUTABLE REBUILT_BUNDLE_EXECUTABLE
 */
#include <stdio.h>
#include <dlfcn.h>

typedef int (*probe_t)(void *, void *, void *, int *);

static int run(const char *label, void *handle) {
    probe_t fn = (probe_t)dlsym(handle, "_Probe");
    if (!fn) { printf("%s: dlsym _Probe failed: %s\n", label, dlerror()); return 1; }
    int order = -1;
    int rc = fn(0, 0, 0, &order);
    printf("%s: _Probe(0,0,0,&order) = %d, order = %d\n", label, rc, order);
    return 0;
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    if (argc < 3) { fprintf(stderr, "usage: %s stock_bundle rebuilt_bundle\n", argv[0]); return 1; }
    void *stock = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    void *rebuilt = dlopen(argv[2], RTLD_NOW | RTLD_LOCAL);
    printf("dlopen stock=%s rebuilt=%s\n", stock ? "ok" : dlerror(), rebuilt ? "ok" : dlerror());
    if (!stock || !rebuilt) return 1;
    int bad = 0;
    bad |= run("stock  ", stock);
    bad |= run("rebuilt", rebuilt);
    printf("RESULT: %s\n", bad == 0 ? "PASS" : "FAIL");
    return bad;
}
