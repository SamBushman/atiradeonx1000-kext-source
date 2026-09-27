/* unload_test.c - issue #69 criterion 3: what happens to the image's atexit registrations when it is dlclose()d and the process then exits.
 *   unload_test IMAGE [nolock]
 * The stock's crt shim registers each static destructor with __cxa_atexit(fn, 0, &__dso_handle), so dlclose runs them; the rebuilt image maps the shim to libSystem's atexit(fn),
 * which registers them for the whole process. Prints whether dlclose returned, and exits normally; the exit status / signal shows a handler run after the image was unmapped. */
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <mach-o/dyld.h>
/* run with DYLD_FORCE_FLAT_NAMESPACE=1 to count the image's registrations: this definition then wins over libSystem's */
extern int __cxa_atexit(void (*)(void *), void *, void *);
static int registered, phase; static void *first_fn;
static void tramp(void *f) { printf("handler %p called %s\n", (void *)0, phase == 1 ? "during dlclose" : phase == 2 ? "at exit" : "early"); fflush(stdout); ((void (*)(void))f)(); }
int atexit(void (*f)(void)) { if (!registered++) first_fn = (void *)f; return __cxa_atexit(tramp, (void *)f, 0); }
static void my_handler(void) { printf("registered handler ran %s\n", phase == 1 ? "during dlclose" : phase == 2 ? "at exit" : "early"); fflush(stdout); }
static void cxa_handler(void *p) { printf("__cxa_atexit(fn, 0, dso) handler ran %s\n", phase == 1 ? "during dlclose" : phase == 2 ? "at exit" : "early"); fflush(stdout); }
int main(int argc, char **argv) {
    void *L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL); if (!L) { printf("dlopen failed: %s\n", dlerror()); return 2; }
    printf("atexit registrations during dlopen: %d\n", registered);
    if (registered) printf("first registered function mapped before dlclose: %s\n", msync((void *)((unsigned long)first_fn & ~4095UL), 4096, 1) == 0 ? "yes" : "no");
    if (argc > 3 && !strcmp(argv[3], "dso")) {   /* unload_test IMAGE ANCHOR dso HEADER_DELTA: register through __cxa_atexit with the image's Mach-O header as the dso handle */
        char *hdr = (char *)dlsym(L, argv[2]) - strtol(argv[4], 0, 0); printf("header magic %08x\n", *(unsigned *)hdr); __cxa_atexit(cxa_handler, 0, hdr); }
    else if (argc > 3) {   /* unload_test IMAGE ANCHOR OFFSET: call the stock's atexit shim (FUN_00002748) at ANCHOR+OFFSET with my_handler; for the rebuilt image the shim IS libSystem's atexit */
        char *b = dlsym(L, argv[2]); int (*shim)(void (*)(void)) = (int (*)(void (*)(void)))(argc > 4 ? (void *)atexit : (void *)(b + strtol(argv[3], 0, 0))); printf("shim returned %d\n", shim(my_handler)); }
    printf("images before dlclose: %u\n", _dyld_image_count()); fflush(stdout);
    phase = 1; int r = dlclose(L); phase = 2;
    if (registered) printf("first registered function mapped after dlclose: %s\n", msync((void *)((unsigned long)first_fn & ~4095UL), 4096, 1) == 0 ? "yes" : "no");
    printf("dlclose -> %d, images after: %u\n", r, _dyld_image_count()); fflush(stdout);
    printf("exiting\n"); fflush(stdout);
    return 0;
}
