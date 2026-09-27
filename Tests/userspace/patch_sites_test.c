/* patch_sites_test.c - drives the call sites fixed by hand patches (Tools/userspace/patches.py, issue #71) in ONE image and prints what came back; run it on the stock
 * and on the rebuilt image and diff the two outputs (patch_sites.sh does both).
 *
 *   patch_sites_test IMAGE ANCHOR key=OFFSET ...
 *
 * The patched functions are not exported: OFFSET is (address of the function - address of the exported symbol ANCHOR) in the image under test, from `nm`.
 * keys: yfa yfr yff (glprog yy_flex_alloc / realloc / free), ung (_str_ungetch + FUN_97b88a90), unl (_unlinkScope + FUN_97b89f04), cppv (data _cpp), scopev (data _ScopeList),
 *       dcba dcbr dcbf (_glpDCBAlloc / Realloc / Free), trav (TIntermSymbol::traverse), cal (GLDriver FUN_000a6f70), cos / sin (FUN_001d05b0 / FUN_001d0794), rsq (FUN_001d06ec). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <math.h>
#include <unistd.h>

static void *fn[32]; static const char *names[32]; static int nfn;
static void *F(const char *k) { for (int i = 0; i < nfn; i++) if (!strcmp(names[i], k)) return fn[i]; return NULL; }

static void *last_this, *last_trav; static int ncalls;
static int cb(void *self, void *t) { last_this = self; last_trav = t; ncalls++; return 1; }
static double angle_conv(void *self, double x) { return x * 2.0; }   /* the GLDriver's virtual "angle conversion" slot at vtable + 0xe0 */

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    void *L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL); if (!L) { printf("DLOPEN FAILED\n"); return 2; }
    char *base = dlsym(L, argv[2]); if (!base) { printf("NO ANCHOR\n"); return 2; }
    for (int i = 3; i < argc; i++) { char *eq = strchr(argv[i], '='); *eq = 0; names[nfn] = argv[i]; fn[nfn++] = base + strtol(eq + 1, NULL, 0); }
    void *(*fa)(unsigned) = F("yfa"), *(*fr)(void *, unsigned) = F("yfr"); void (*ff)(void *) = F("yff");
    if (fa && fr && ff) {
        unsigned char *p = fa(64); for (int i = 0; i < 64; i++) p[i] = i * 3; unsigned char *q = fr(p, 4096);
        int ok = 1; for (int i = 0; i < 64; i++) if (q[i] != (unsigned char)(i * 3)) ok = 0;
        printf("yy_flex_alloc/realloc: alloc %s, contents kept through realloc %d\n", p ? "ok" : "NULL", ok); ff(q); printf("yy_flex_free returned\n");
    }
    void (*ung)(char *, int) = F("ung"); void **cppv = F("cppv");
    if (ung && cppv) {
        /* struct { ..., +0x14 line, +0x18 cursor }; cpp -> record whose +0x144 counter is decremented when the character does not match */
        char buf[8] = "abcdef"; static char cppr[0x200]; void *savecpp = *cppv; *cppv = cppr; *(int *)(cppr + 0x144) = 10;
        for (int t = 0; t < 3; t++) {
            unsigned char s[0x30]; memset(s, 0, sizeof s); memset(buf, 'a', 6); buf[6] = 0; buf[2] = 'X';
            *(char **)(s + 0x18) = buf + 3; *(int *)(s + 0x14) = 5;
            ((void (*)(void *, int))ung)(s, t == 0 ? 'X' : t == 1 ? 'q' : 'a');
            printf("_str_ungetch case %d: cursor moved %ld, buf[3]=%d, cpp counter %d\n", t, (long)(*(char **)(s + 0x18) - (buf + 3)), buf[3], *(int *)(cppr + 0x144));
        }
        *cppv = savecpp;
    }
    void (*unl)(void *) = F("unl"); void **scopev = F("scopev");
    if (unl && scopev) {
        void *n[4][2]; void *save = *scopev;
#define IDX(p) ((p) == NULL ? -1 : (int)(((void **)(p) - &n[0][0]) / 2))
        for (int t = 0; t < 3; t++) {   /* a doubly linked list n0 <-> n1 <-> n2 (next at +0, prev at +4); unlink the middle / the head / the tail node */
            memset(n, 0, sizeof n); n[0][0] = &n[1][0]; n[1][0] = &n[2][0]; n[1][1] = &n[0][0]; n[2][1] = &n[1][0];
            *scopev = &n[t == 1 ? 0 : 1][0]; unl(&n[t][0]);
            printf("_unlinkScope node %d: n0=(%d,%d) n1=(%d,%d) n2=(%d,%d) head=%d\n", t, IDX(n[0][0]), IDX(n[0][1]), IDX(n[1][0]), IDX(n[1][1]), IDX(n[2][0]), IDX(n[2][1]), IDX(*scopev));
        }
        *scopev = save;
    }
    void *(*da)(int) = F("dcba"), *(*dr)(void *, int) = F("dcbr"); void (*df)(void *) = F("dcbf");
    if (da && dr && df) {
        unsigned char *p = da(40); for (int i = 0; i < 40; i++) p[i] = 200 - i;
        unsigned char *q = dr(p, 100); int ok = 1; for (int i = 0; i < 40; i++) if (q[i] != (unsigned char)(200 - i)) ok = 0;
        printf("_glpDCBRealloc grow: 32-aligned %d, contents %d\n", ((unsigned long)q & 31) == 0, ok);
        unsigned char *r = dr(q, 12); ok = 1; for (int i = 0; i < 12; i++) if (r[i] != (unsigned char)(200 - i)) ok = 0;
        printf("_glpDCBRealloc shrink: 32-aligned %d, contents %d\n", ((unsigned long)r & 31) == 0, ok);
        void *z = dr(r, 0); printf("_glpDCBRealloc to 0 -> %s\n", z ? "non-NULL" : "NULL"); void *n2 = dr(NULL, 24); printf("_glpDCBRealloc(NULL,24) -> %s\n", n2 ? "block" : "NULL"); df(n2);
    }
    int (*tr)(void *, void *) = F("trav");
    if (tr) {
        void *trv[4] = { (void *)cb, 0, 0, 0 }; int dummy; ncalls = 0; tr(&dummy, trv);
        printf("TIntermSymbol::traverse: callback called %d time(s), this ok %d, traverser ok %d\n", ncalls, last_this == &dummy, last_trav == trv);
        void *trv0[4] = { 0, 0, 0, 0 }; ncalls = 0; tr(&dummy, trv0); printf("with a NULL callback: %d call(s)\n", ncalls);
    }
    void *(*cal)(unsigned) = F("cal");
    if (cal) { unsigned char *p = cal(37); int z = 1; for (int i = 0; i < 37; i++) if (p[i]) z = 0; printf("FUN_000a6f70: block %s, zeroed %d\n", p ? "ok" : "NULL", z); }
    static const float xs[] = { 0.0f, 1.0f, 0.5f, 2.0f, -1.0f, 3.14159f, 100.0f, 1e-3f, 1e10f, -0.0f };
    const char *tn[3] = { "cos", "sin", "rsq" };
    for (int k = 0; k < 3; k++) {
        int (*g)(void *, float *, void *, void *) = F(tn[k]); if (!g) continue;
        void *vt[0x40]; memset(vt, 0, sizeof vt); vt[0xe0 / 4] = (void *)angle_conv; void *o2[1] = { vt }; unsigned char o4[0x320]; memset(o4, 0, sizeof o4); *(void **)(o4 + 0x30c) = o2;
        for (unsigned i = 0; i < sizeof xs / sizeof *xs; i++) {
            unsigned char in[8]; float out = 12345.0f; memset(in, 0, 8); *(float *)(in + 4) = xs[i];
            int r = g(NULL, &out, in, o4); printf("%s(%g): r=%d out=%08x\n", tn[k], xs[i], r, *(unsigned *)&out);
        }
        unsigned char in[8] = { 0 }; float out = 7.0f; g(NULL, &out, in, o4); printf("%s(bits 0): out=%08x\n", tn[k], *(unsigned *)&out);
    }
    return 0;
}
