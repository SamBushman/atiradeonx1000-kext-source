/* gld_test.c - load the stock GL driver bundle and the rebuilt one side by side (constructors/initialisers run at dlopen) and check that every stock export resolves. */
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    void *a = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), *b = dlopen(argv[2], RTLD_NOW | RTLD_LOCAL);
    printf("stock dlopen %s, rebuilt dlopen %s\n", a ? "ok" : dlerror(), b ? "ok" : dlerror());
    if (!a || !b) return 1;
    FILE *f = fopen(argv[3], "r"); char line[256]; int n = 0, bad = 0, both = 0;
    while (f && fgets(line, sizeof line, f)) {
        line[strcspn(line, "\r\n")] = 0; if (!line[0]) continue;
        n++; void *pa = dlsym(a, line + 1), *pb = dlsym(b, line + 1);
        if (pa && pb) both++; else { bad++; if (bad < 10) printf("  %s: stock=%p rebuilt=%p\n", line, pa, pb); }
    }
    printf("exports: %d listed, %d resolve in both, %d not\n", n, both, bad);
    printf("RESULT: %s\n", bad == 0 ? "PASS" : "FAIL");
    return 0;
}
