#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef int (*init_t)(void);
typedef void *(*mk_t)(int, int);
typedef int (*compile_t)(void *, const char *const *, int, int, unsigned);
typedef const char *(*log_t)(void *);
typedef void (*destroy_t)(void *);
typedef void *(*getpp_t)(void *);
typedef int (*gs_t)(void *, void *, unsigned *);
int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    void *L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    init_t init = dlsym(L, "ShInitialize"); mk_t mk = dlsym(L, "ShConstructCompiler");
    compile_t comp = dlsym(L, "ShCompile"); log_t lg = dlsym(L, "ShGetInfoLog"); destroy_t des = dlsym(L, "ShDestruct");
    getpp_t getpp = dlsym(L, "ShGetCompilerShaderToProgramString"); gs_t gs = dlsym(L, "PPStreamGetStream");
    init();
    int mode = atoi(argv[2]); unsigned dbg = atoi(argv[3]); int stage = atoi(argv[4]);
    const char *src = "void main() { gl_Position = ftransform(); }\n";
    static char buf[65536];
    if (argc > 5) {   /* optional shader source file (e.g. constant math the front end folds with libm) */
        FILE *fp = fopen(argv[5], "r"); size_t n = fp ? fread(buf, 1, sizeof buf - 1, fp) : 0;
        if (fp) fclose(fp);
        buf[n] = 0; src = buf;
    }
    void *h = mk(0, 0); printf("mk=%p\n", h);
    const char *s[1] = { src };
    int rc = comp(h, s, 1, mode, dbg); printf("compile rc=%d\n", rc);
    if (stage >= 1) { const char *l = lg(h); printf("log=%d bytes\n%s\n", l ? (int)strlen(l) : -1, l ? l : ""); }
    void *pp = 0;
    if (stage >= 2) { pp = getpp(h); printf("pp=%p\n", pp); }
    if (stage >= 3 && pp) { printf("program string:\n%s\n", (char*)pp); }
    if (stage >= 4) { des(h); printf("destroyed\n"); }
    return 0;
}
