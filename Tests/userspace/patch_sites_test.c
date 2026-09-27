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
    /* GLDriver FUN_0002cd50 (a command-stream emitter: an atomic reference-count add of 0x10000 on the object's holder, `lwarx/stwcx.` rewritten as a CAS loop) and
       FUN_0000b620 (a `dcbst` loop + `dcbf` over a range, line size from *(param_1 + 8)); the cache-line alignment of the stream is fixed so the outputs are comparable */
    int *(*em)(void *, void *, int, int *) = F("cmdemit");
    if (em) {
        static int cmd[64] __attribute__((aligned(64))); static unsigned char ctx[0x300]; static unsigned char obj[0x100]; static int holder[8];
        for (int v = 0; v < 4; v++) {
            memset(cmd, 0, sizeof cmd); memset(ctx, 0, sizeof ctx); memset(obj, 0, sizeof obj); memset(holder, 0, sizeof holder);
            *(int **)(ctx + 0x1d8) = cmd; holder[0] = 0x1234; holder[4] = 0x50000; *(int **)(obj + 0x34) = holder; *(int *)(obj + 0x40) = 0x77;
            *(unsigned *)(obj + 0xc8) = (v & 1) ? 0xc00000 : 0; *(unsigned *)(obj + 0xcc) = 0x8000; obj[0x38] = 0x5a;
            int *r = em(ctx, (v & 2) ? NULL : obj, 3, cmd + 4);
            printf("cmdemit v=%d: returned +%ld words, ctx->last=+%ld words, holder refcount %x, words:", v, (long)(r - cmd), (long)(*(int **)(ctx + 0x1d8) - cmd), holder[4]);
            for (int i = 0; i < 16; i++) printf(" %x", cmd[i]); printf("\n");
        }
    }
    for (int q = 0; q < 2; q++) {
        void (*cf)(void *, unsigned, int, int, int, int, int, int) = F(q ? "cflush2" : "cflush");
        if (!cf) continue;
        static unsigned char st[16]; static char mem[1024] __attribute__((aligned(128)));
        for (int ls = 32; ls <= 128; ls *= 4) { memset(st, 0, 16); st[8] = ls; for (int i = 0; i < 1024; i++) mem[i] = i; cf(st, (unsigned)mem + 3, 500, 0, 0, 0, 0, 0); }
        printf("%s: ran with line sizes 32 and 128, memory intact %d\n", q ? "FUN_0000b670 (dcbf loop + sync; isync)" : "FUN_0000b620 (dcbst loop + dcbf)", mem[1000] == (char)1000);
    }
    /* GLDriver FUN_0001e8a0 (AltiVec halfword-swapping copy: vperm, dcbt, dcbz-style allocate) and FUN_0001eaf0 (AltiVec copy with dcbz clear-to-zero of the destination lines and a
       vsel edge merge): destination / source at assorted alignments and lengths, guard bytes around the destination; the result is a checksum of the whole destination buffer */
    static unsigned char permtab[0x400] __attribute__((aligned(16)));
    { int **slot = F("permslot"); if (slot) { for (int i = 0; i < 0x400; i++) permtab[i] = (i * 5 + (i >> 4)) & 0x1f;    /* the data word the stock's initialisation fills: a pointer to the vperm / vsel constants */
        **(int **)slot = (int)permtab; } }
    void (*sw)(void *, void *, unsigned) = F("avswap"), (*cp)(unsigned, unsigned, unsigned) = F("avcopy");
    for (int k = 0; k < 2; k++) {
        if (!(k ? (void *)cp : (void *)sw)) continue;
        static unsigned char src[8192] __attribute__((aligned(128))), dst[8192] __attribute__((aligned(128)));
        for (int i = 0; i < 8192; i++) src[i] = (unsigned char)(i * 7 + (i >> 8));
        static const int doff[] = { 0, 4, 16, 32, 36, 60, 128 }, soff[] = { 0, 4, 8, 12, 20, 48 }, cnt[] = { 2, 16, 34, 64, 130, 256, 500, 1000, 1500 };
        unsigned long long h = 1469598103934665603ULL; int n = 0;
        for (unsigned a = 0; a < sizeof doff / sizeof *doff; a++) for (unsigned b = 0; b < sizeof soff / sizeof *soff; b++) for (unsigned c = 0; c < sizeof cnt / sizeof *cnt; c++) {
            memset(dst, 0xaa, sizeof dst); if (getenv("PS_TRACE")) fprintf(stderr, "k=%d d=%d s=%d c=%d\n", k, doff[a], soff[b], cnt[c]);
            if (k) cp((unsigned)dst + 256 + doff[a], (unsigned)src + 256 + soff[b], cnt[c]); else sw(dst + 256 + doff[a], src + 256 + soff[b], cnt[c]);
            for (int i = 0; i < 8192; i++) { h ^= dst[i]; h *= 1099511628211ULL; } n++;
        }
        printf("%s: %d combinations, checksum %08x%08x\n", k ? "FUN_0001eaf0" : "FUN_0001e8a0", n, (unsigned)(h >> 32), (unsigned)h);
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
