#include <stdio.h>
#include <dlfcn.h>
typedef double (*f_t)(const char *, char **);
int main(int argc, char **argv) {
    void *h[2] = { dlopen(argv[1], RTLD_NOW), dlopen(argv[2], RTLD_NOW) };
    const char *t[] = { "1", "2.5", "-3", "1e3", "0.125", "123456.789", "4", "1.5e-2", ".5", "0x10", "abc", 0 };
    for (int i = 0; t[i]; i++) {
        double d[2]; long e[2];
        for (int k = 0; k < 2; k++) { char *end = (char *)-1; d[k] = ((f_t)dlsym(h[k], "glp_strtod"))(t[i], &end); e[k] = end == (char *)-1 ? -99 : (long)(end - t[i]); }
        printf("%-12s stock %g end=%ld  rebuilt %g end=%ld %s\n", t[i], d[0], e[0], d[1], e[1], (d[0] == d[1] && e[0] == e[1]) ? "" : "DIFF");
    }
    return 0;
}
