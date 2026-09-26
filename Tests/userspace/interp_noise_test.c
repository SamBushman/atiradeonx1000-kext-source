/* interp_noise_test.c - differential test of the interpreter's Perlin-noise generator (libGLProgrammability), stock vs rebuilt.
 *
 *   interp_noise_test STOCK.dylib REBUILT.dylib
 *
 * Each image runs in its own forked child with the libc PRNG seeded identically (the generator's tables come from random()): it creates the generator,
 * dumps its 0xa20-byte state, then evaluates Calculate1D..4D, InterpolatedNoise1D..3D, SmoothHermiteCurve and Interpolate on the same 300 input vectors
 * and writes every result as raw bits. The parent compares the two dumps word for word. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <math.h>

typedef void *(*create_t)(void);
typedef void (*calc_t)(void *, float *, float *);
typedef double (*inoise_t)(void *, float *);
typedef void (*interp_t)(void *, float *, float *, float *, float *);

static unsigned lcg_state;
static float rnd(float lo, float hi) { lcg_state = lcg_state * 1664525u + 1013904223u; return lo + (hi - lo) * ((lcg_state >> 8) / 16777216.0f); }

static void run(const char *lib, const char *out) {
    alarm(120);
    FILE *f = fopen(out, "w"); if (!f) _exit(2);
    void *L = dlopen(lib, RTLD_NOW | RTLD_LOCAL); if (!L) { fprintf(f, "DLOPEN FAILED\n"); _exit(3); }
    create_t create = dlsym(L, "InterpreterNoiseGeneratorCreate");
    calc_t calc[4] = { dlsym(L, "InterpreterNoiseGeneratorCalculate1D"), dlsym(L, "InterpreterNoiseGeneratorCalculate2D"), dlsym(L, "InterpreterNoiseGeneratorCalculate3D"), dlsym(L, "InterpreterNoiseGeneratorCalculate4D") };
    inoise_t in_[3] = { dlsym(L, "InterpreterNoiseGeneratorInterpolatedNoise1D"), dlsym(L, "InterpreterNoiseGeneratorInterpolatedNoise2D"), dlsym(L, "InterpreterNoiseGeneratorInterpolatedNoise3D") };
    calc_t hermite = dlsym(L, "InterpreterNoiseGeneratorSmoothHermiteCurve");
    interp_t interp = dlsym(L, "InterpreterNoiseGeneratorInterpolate");
    if (!create || !calc[0] || !calc[3] || !in_[2] || !hermite || !interp) { fprintf(f, "MISSING SYMBOL\n"); _exit(4); }
    srandom(20260926);
    void *g = create();
    unsigned char *st = g; for (int i = 0; i < 0xa20; i += 4) fprintf(f, "S%03x %02x%02x%02x%02x\n", i, st[i], st[i+1], st[i+2], st[i+3]);
    lcg_state = 12345;
    for (int n = 0; n < 300; n++) {
        float v[4], w[4], o[4]; float lo = n < 100 ? -4 : n < 200 ? -100 : -1e4f, hi = -lo;
        for (int i = 0; i < 4; i++) { v[i] = rnd(lo, hi); w[i] = rnd(lo, hi); }
        if (n % 50 == 0) { v[0] = 0; v[1] = 1; v[2] = -1; v[3] = 0.5f; }
        for (int k = 0; k < 4; k++) { memset(o, 0, sizeof o); calc[k](g, v, o); fprintf(f, "C%d %d %08x %08x %08x %08x\n", k + 1, n, *(unsigned *)&o[0], *(unsigned *)&o[1], *(unsigned *)&o[2], *(unsigned *)&o[3]); }
        for (int k = 0; k < 3; k++) { double r = in_[k](g, v); float rf = (float)r; fprintf(f, "I%d %d %016llx\n", k + 1, n, *(unsigned long long *)&r); (void)rf; }
        memset(o, 0, sizeof o); hermite(g, v, o); fprintf(f, "H %d %08x %08x %08x %08x\n", n, *(unsigned *)&o[0], *(unsigned *)&o[1], *(unsigned *)&o[2], *(unsigned *)&o[3]);
        float t[4] = { rnd(0, 1), rnd(0, 1), rnd(0, 1), rnd(0, 1) };
        memset(o, 0, sizeof o); interp(g, v, w, t, o); fprintf(f, "L %d %08x %08x %08x %08x\n", n, *(unsigned *)&o[0], *(unsigned *)&o[1], *(unsigned *)&o[2], *(unsigned *)&o[3]);
    }
    fprintf(f, "END\n"); fclose(f); _exit(0);
}

int main(int argc, char **argv) {
    if (argc < 3) { fprintf(stderr, "usage: interp_noise_test STOCK REBUILT\n"); return 2; }
    const char *tag[2] = { "/tmp/noise_stock.txt", "/tmp/noise_rebuilt.txt" }; int st[2];
    for (int k = 0; k < 2; k++) { pid_t p = fork(); if (p == 0) run(argv[1 + k], tag[k]); waitpid(p, &st[k], 0); }
    for (int k = 0; k < 2; k++) if (!WIFEXITED(st[k]) || WEXITSTATUS(st[k])) printf("%s: %s %d\n", k ? "rebuilt" : "stock", WIFSIGNALED(st[k]) ? "signal" : "exit", WIFSIGNALED(st[k]) ? WTERMSIG(st[k]) : WEXITSTATUS(st[k]));
    /* the generator's tables must match exactly; the arithmetic may differ in the last bits: the stock (gcc 3.3 -O2) fuses `a*b+c` into fmadds (one rounding), the
       recompile at -O0 rounds twice. Results are compared with a relative tolerance of 1e-4 and the exact-match / ulp statistics are reported. */
    FILE *a = fopen(tag[0], "r"), *b = fopen(tag[1], "r"); char la[256], lb[256]; int lines = 0, state_diff = 0, exact = 0, tol = 0, bad = 0, nfl = 0; long maxulp = 0; double maxrel = 0;
    while (a && b && fgets(la, sizeof la, a) && fgets(lb, sizeof lb, b)) {
        lines++;
        if (!strcmp(la, lb)) { exact++; continue; }
        if (la[0] == 'S' || la[0] == 'D' || la[0] == 'M') { state_diff++; if (state_diff < 5) printf("STATE DIFF: %s vs %s", la, lb); continue; }
        char ka[8], kb[8]; int na, nb; unsigned fa[4], fb[4]; unsigned long long da, db; int okrow = 1;
        if (la[0] == 'I') {
            if (sscanf(la, "%7s %d %llx", ka, &na, &da) != 3 || sscanf(lb, "%7s %d %llx", kb, &nb, &db) != 3) { bad++; continue; }
            double x, y; memcpy(&x, &da, 8); memcpy(&y, &db, 8); double d = fabs(x - y), m = fmax(1.0, fmax(fabs(x), fabs(y))); if (d / m > maxrel) maxrel = d / m; if (d / m > 1e-4) okrow = 0; nfl++;
        } else {
            if (sscanf(la, "%7s %d %x %x %x %x", ka, &na, &fa[0], &fa[1], &fa[2], &fa[3]) != 6 || sscanf(lb, "%7s %d %x %x %x %x", kb, &nb, &fb[0], &fb[1], &fb[2], &fb[3]) != 6) { bad++; continue; }
            for (int i = 0; i < 4; i++) {
                float x, y; memcpy(&x, &fa[i], 4); memcpy(&y, &fb[i], 4); nfl++;
                if (fa[i] == fb[i]) continue;
                long ia = (int)fa[i], ib = (int)fb[i]; if (ia < 0) ia = 0x80000000L - ia; if (ib < 0) ib = 0x80000000L - ib; long u = labs(ia - ib); if (u > maxulp) maxulp = u;
                double d = fabs((double)x - y), m = fmax(1.0, fmax(fabs((double)x), fabs((double)y))); if (d / m > maxrel) maxrel = d / m; if (d / m > 1e-4) okrow = 0;
            }
        }
        if (okrow) tol++; else { bad++; if (bad < 6) printf("OUT OF TOLERANCE line %d:\n  stock   %s  rebuilt %s", lines, la, lb); }
    }
    printf("noise generator: %d result lines: %d identical, %d within 1e-4 (fused multiply-add rounding: max %ld ulp, max relative %.3g), %d out of tolerance, %d state/table differences\nRESULT: %s\n",
           lines, exact, tol, maxulp, maxrel, bad, state_diff, (bad == 0 && state_diff == 0 && lines > 1000) ? "PASS" : "FAIL");
    return 0;
}
