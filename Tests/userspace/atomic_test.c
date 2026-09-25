/* atomic_test.c - two-thread stress test of the lwarx/stwcx. paths of libGLProgrammability's own copy-on-write std::string (issue #69 criterion 1).
 *
 *   atomic_test IMAGE OFF_ShInitialize OFF_ctor_pchar OFF_copy_ctor OFF_dtor [ITERATIONS]
 *
 * The string functions are not exported: their addresses come from `nm` (the OFF_ arguments are the nm values of _ShInitialize, __ZNSsC1EPKcRKSaIcE,
 * __ZNSsC1ERKSs, __ZNSsD1Ev) and the image's load address from dlsym("ShInitialize"). Two threads each copy and destroy a shared string ITERATIONS times:
 * every copy is an atomic increment of the shared rep's refcount (rep = data - 12, refcount at data - 4), every destroy an atomic decrement. Without lost
 * updates the refcount ends where it started and the string is intact. Run for a normal string and for the empty string (whose shared empty rep is the
 * `DAT_x = storeWordConditionalIndexed(DAT_x + 1, ...)` form the CAS rewrite once turned into an endless loop). Prints PASS/FAIL per case. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <pthread.h>

typedef void (*ctor_t)(char **, const char *, void *);
typedef void (*copy_t)(char **, char **);
typedef void (*dtor_t)(char **);
static copy_t copy_fn;
static dtor_t dtor_fn;
static char *shared_s;
static long iters = 1000000;

static void *worker(void *arg) {
    long i;
    for (i = 0; i < iters; i++) {
        char *t;
        copy_fn(&t, &shared_s);
        if (t != shared_s) { fprintf(stderr, "copy did not share the rep\n"); exit(3); }
        dtor_fn(&t);
    }
    return arg;
}

static int run_case(ctor_t ctor, const char *text) {
    char alloc[8];
    int before, after, ok;
    pthread_t a, b;
    ctor(&shared_s, text, alloc);
    before = *(int *)(shared_s - 4);
    pthread_create(&a, 0, worker, 0);
    pthread_create(&b, 0, worker, 0);
    pthread_join(a, 0);
    pthread_join(b, 0);
    after = *(int *)(shared_s - 4);
    ok = before == after && strcmp(shared_s, text) == 0;
    printf("  \"%s\": refcount before %d, after %d (2 x %ld copy+destroy), text %s -> %s\n", text, before, after, iters,
           strcmp(shared_s, text) == 0 ? "intact" : "CHANGED", ok ? "PASS" : "FAIL");
    return ok;
}

int main(int argc, char **argv) {
    void *L;
    char *base;
    ctor_t ctor;
    int ok;
    if (argc < 6) { fprintf(stderr, "usage: atomic_test IMAGE OFF_ShInitialize OFF_ctor_pchar OFF_copy OFF_dtor [ITERATIONS]\n"); return 2; }
    setvbuf(stdout, NULL, _IONBF, 0);
    if (argc > 6) iters = atol(argv[6]);
    L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!L) { printf("dlopen failed: %s\n", dlerror()); return 2; }
    base = (char *)dlsym(L, "ShInitialize") - strtoul(argv[2], 0, 16);
    ctor = (ctor_t)(base + strtoul(argv[3], 0, 16));
    copy_fn = (copy_t)(base + strtoul(argv[4], 0, 16));
    dtor_fn = (dtor_t)(base + strtoul(argv[5], 0, 16));
    printf("%s\n", argv[1]);
    ok = run_case(ctor, "a string shared by two threads");
    ok &= run_case(ctor, "");
    printf("RESULT: %s\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
