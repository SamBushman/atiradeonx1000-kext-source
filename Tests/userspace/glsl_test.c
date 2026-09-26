/* glsl_test.c - differential test of the GLSL front end / code generator of the rebuilt libGLProgrammability against the stock one.
 *
 *   glsl_test STOCK.dylib REBUILT.dylib SHADER_DIR OUT_DIR [name-substring]
 *   glsl_test --one LIB.dylib SHADER_FILE          (one image, in this process, output on stdout: for gdb)
 *
 * For every SHADER_DIR/NAME.vert|frag, each image is run in its own forked child (a crash or hang in one image cannot hide the other's result):
 *   variant A  ShCompile(handle, src, 1, 0, 0)  parse + type check only          -> return code, info log
 *   variant B  ShCompile(handle, src, 1, 1, 1)  + intermediate tree dump + code gen -> return code, info log (contains the tree)
 *   variant C  ShCompile(handle, src, 1, 1, 0)  code gen only                    -> return code, info log, generated ARB program text
 * and writes OUT_DIR/<stock|rebuilt>_NAME.txt. The parent then compares the two files for every shader and prints DIFF / CRASH lines.
 * The EShLanguage argument is 0 for .vert, 1 for .frag. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef int (*init_t)(void);
typedef void *(*mk_t)(int, int);
typedef int (*compile_t)(void *, const char *const *, int, int, unsigned);
typedef const char *(*log_t)(void *);
typedef void (*destroy_t)(void *);
typedef void *(*getpp_t)(void *);

static char *slurp(const char *path, long *len) {
    FILE *f = fopen(path, "rb"); if (!f) return NULL;
    fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
    char *b = malloc(n + 1); if (fread(b, 1, n, f) != (size_t)n) { fclose(f); return NULL; } b[n] = 0; fclose(f); if (len) *len = n; return b;
}

static void run_child(const char *lib, const char *shader, int lang, const char *outpath) {
    if (strcmp(outpath, "/dev/stdout")) alarm(60);   /* not in --one (gdb) mode */
    FILE *out = fopen(outpath, "w"); if (!out) _exit(2);
    setvbuf(out, NULL, _IOFBF, 1 << 16);
    void *L = dlopen(lib, RTLD_NOW | RTLD_LOCAL);
    if (!L) { fprintf(out, "DLOPEN FAILED %s\n", dlerror()); fclose(out); _exit(3); }
    init_t init = dlsym(L, "ShInitialize"); mk_t mk = dlsym(L, "ShConstructCompiler"); compile_t comp = dlsym(L, "ShCompile");
    log_t lg = dlsym(L, "ShGetInfoLog"); destroy_t des = dlsym(L, "ShDestruct"); getpp_t getpp = dlsym(L, "ShGetCompilerShaderToProgramString");
    mk_t mkl = dlsym(L, "ShConstructLinker"); int (*link)(void *, void **, int, int, int) = dlsym(L, "ShLink");
    const char *(*getlp)(void *) = dlsym(L, "ShGetLinkerShaderToProgramString"), *(*getlb)(void *) = dlsym(L, "ShGetLinkerBindingTable");
    const char *(*getls)(void *) = dlsym(L, "ShGetLinkerStats"), *(*getlpp)(void *) = dlsym(L, "ShGetLinkerPPStream");
    fprintf(out, "init=%d\n", init());
    static const struct { int mode; unsigned dbg; const char *name; } var[4] = { { 0, 0, "A parse" }, { 1, 1, "B tree+codegen" }, { 1, 0, "C codegen" }, { 1, 0, "D codegen+link" } };
    const char *only = getenv("GT_VARIANTS");   /* debugging: e.g. GT_VARIANTS=AC runs just those variants, in that order */
    for (int vi = 0; vi < (only ? (int)strlen(only) : 4); vi++) {
        int v = only ? only[vi] - 'A' : vi;
        void *h = mk(lang, 0);
        const char *s[1] = { shader };
        int rc = comp(h, s, 1, var[v].mode, var[v].dbg);
        const char *l = lg(h);
        fprintf(out, "== variant %s: rc=%d\n--- log (%d bytes)\n%s\n", var[v].name, rc, l ? (int)strlen(l) : -1, l ? l : "(null)");
        void *pp = getpp(h);   /* the generated ARB program text (or "No Shader Program generated.") */
        fprintf(out, "--- program (%s)\n%s\n", pp ? "string" : "none", pp ? (const char *)pp : "(null)");
        if (v == 3 && rc) {   /* what the GL driver does next: link the compiled shader; the linker owns the final program text, binding table and statistics */
            void *lk = mkl(lang, 0);
            void *hs[1] = { h };
            int lrc = link(lk, hs, 1, 0, 0);
            const char *ll = lg(lk);
            fprintf(out, "== link: rc=%d\n--- log (%d bytes)\n%s\n", lrc, ll ? (int)strlen(ll) : -1, ll ? ll : "(null)");
            const char *(*fn[4])(void *) = { getlp, getlb, getls, getlpp };
            static const char *fname[4] = { "program", "binding table", "stats", "pp stream" };
            for (int q = 0; q < 4; q++) { const char *t = fn[q] ? fn[q](lk) : NULL; fprintf(out, "--- linker %s (%s)\n%s\n", fname[q], t ? "string" : "none", t ? t : "(null)"); }
            des(lk);
        }
        des(h);
        fflush(out);
    }
    fprintf(out, "END\n"); fclose(out); _exit(0);
}

static int cmp_names(const void *a, const void *b) { return strcmp(*(char **)a, *(char **)b); }

int main(int argc, char **argv) {
    if (argc == 4 && !strcmp(argv[1], "--one")) {   /* debugging (gdb): glsl_test --one LIB SHADER_FILE  - compile in this process, output to stdout */
        char *src = slurp(argv[3], NULL); if (!src) return 2;
        run_child(argv[2], src, strstr(argv[3], ".frag") ? 1 : 0, "/dev/stdout");
    }
    if (argc < 5) { fprintf(stderr, "usage: glsl_test STOCK REBUILT SHADER_DIR OUT_DIR [filter]\n"); return 2; }
    const char *libs[2] = { argv[1], argv[2] }, *tag[2] = { "stock", "rebuilt" };
    const char *dir = argv[3], *outdir = argv[4], *filter = argc > 5 ? argv[5] : NULL;
    mkdir(outdir, 0755);
    DIR *d = opendir(dir); struct dirent *e; char *names[4096]; int nn = 0;
    while ((e = readdir(d)) && nn < 4096) { size_t l = strlen(e->d_name); if (l > 5 && (!strcmp(e->d_name + l - 5, ".vert") || !strcmp(e->d_name + l - 5, ".frag")) && (!filter || strstr(e->d_name, filter))) names[nn++] = strdup(e->d_name); }
    closedir(d); qsort(names, nn, sizeof *names, cmp_names);
    int ndiff = 0, ncrash = 0, nsame = 0;
    for (int i = 0; i < nn; i++) {
        char path[1024]; snprintf(path, sizeof path, "%s/%s", dir, names[i]);
        char *src = slurp(path, NULL); if (!src) continue;
        int lang = strstr(names[i], ".frag") ? 1 : 0;
        int status[2] = { 0, 0 };
        for (int k = 0; k < 2; k++) {
            char op[1100]; snprintf(op, sizeof op, "%s/%s_%s.txt", outdir, tag[k], names[i]);
            pid_t p = fork();
            if (p == 0) run_child(libs[k], src, lang, op);
            int st = 0; waitpid(p, &st, 0); status[k] = st;
            if (WIFSIGNALED(st)) { FILE *f = fopen(op, "a"); if (f) { fprintf(f, "CRASHED signal %d\n", WTERMSIG(st)); fclose(f); } }
        }
        char a[1100], b[1100]; snprintf(a, sizeof a, "%s/stock_%s.txt", outdir, names[i]); snprintf(b, sizeof b, "%s/rebuilt_%s.txt", outdir, names[i]);
        char *ta = slurp(a, NULL), *tb = slurp(b, NULL);
        int same = ta && tb && !strcmp(ta, tb) && status[0] == status[1];
        if (same && WIFSIGNALED(status[0]) && WIFSIGNALED(status[1]) && WTERMSIG(status[0]) == WTERMSIG(status[1])) { nsame++; printf("SAME-CRASH %s: both images die with signal %d after identical output (the stock's own bug, reproduced)\n", names[i], WTERMSIG(status[0])); }
        else if (WIFSIGNALED(status[0]) || WIFSIGNALED(status[1])) { ncrash++; printf("CRASH %s: stock %s%d, rebuilt %s%d\n", names[i], WIFSIGNALED(status[0]) ? "signal " : "exit ", WIFSIGNALED(status[0]) ? WTERMSIG(status[0]) : WEXITSTATUS(status[0]), WIFSIGNALED(status[1]) ? "signal " : "exit ", WIFSIGNALED(status[1]) ? WTERMSIG(status[1]) : WEXITSTATUS(status[1])); }
        else if (!same) { ndiff++; printf("DIFF %s\n", names[i]); }
        else nsame++;
        free(ta); free(tb); free(src);
    }
    printf("GLSL: %d shaders, %d identical, %d different, %d crashed\nRESULT: %s\n", nn, nsame, ndiff, ncrash, (ndiff == 0 && ncrash == 0) ? "PASS" : "FAIL");
    return 0;
}
