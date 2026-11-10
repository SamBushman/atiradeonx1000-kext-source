/* gleng_mock_getparam.c - Phase 3 mock test of GLEngine _glGet{Histogram,Minmax}Parameter{iv,fv}_Exec (stock vs rebuilt) on a VALID context block.
 *   gleng_mock_getparam STOCK REBUILT ANCHOR STOCK_ANCHOR_ADDR REBUILT_ANCHOR_OFF  S_HIST_IV R_HIST_IV S_MM_IV R_MM_IV S_HIST_FV R_HIST_FV S_MM_FV R_MM_FV   (hex)
 * The fuzzers call the fv functions with a random ctx; on the paths where the iv callee returns without writing (GL error) the fv function converts a never-written stack word
 * (stock 0x48(r1) of its frame, rebuilt local) and stores it, so the stored float is stack residue in BOTH images. Here the context is valid (ctx+0x4a10 < 0: the non-error state, a value >= 0 takes the GL_INVALID_OPERATION path) and the
 * output word is pre-filled with a sentinel; a case counts as "callee wrote" when the stock iv function changed the sentinel. For those cases the iv and fv results, the output word and
 * the context error word (+0x7574) must be identical in both images; the other (error) cases are compared on the error word only, the output float there being residue. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef void (*fn_t)(void *, unsigned, unsigned, void *);
#define CTXSZ 0x8000
static void mkctx(unsigned char *c, unsigned err, int pat) {
    for (int i = 0; i < CTXSZ; i++) c[i] = (unsigned char)(i * 131 + pat * 17 + 5);
    *(short *)(c + 0x4a10) = -1; *(unsigned *)(c + 0x7574) = err;
}
int main(int argc, char **argv) {
    if (argc < 14) return 2;
    void *L[2] = { dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), dlopen(argv[2], RTLD_NOW | RTLD_LOCAL) };
    const char *an = argv[3][0] == '_' ? argv[3] + 1 : argv[3];
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    unsigned sa = strtoul(argv[4], 0, 16), ra = strtoul(argv[5], 0, 16);
    const char *nm[4][2] = { { "Histogram iv", "" }, { "Minmax iv", "" }, { "Histogram fv", "" }, { "Minmax fv", "" } };
    fn_t f[4][2];
    for (int k = 0; k < 4; k++) { f[k][0] = (fn_t)(ap[0] + (strtoul(argv[6 + 2 * k], 0, 16) - sa)); f[k][1] = (fn_t)(ap[1] + (strtoul(argv[7 + 2 * k], 0, 16) - ra)); }
    unsigned targets[] = { 0x8024, 0x8025, 0x802e, 0x802f, 0x8000, 0, 0x1234 };
    unsigned pnames[] = { 0x8020, 0x8021, 0x8022, 0x8023, 0x8024, 0x8025, 0x8026, 0x8027, 0x8028, 0x8029, 0x802a, 0x802b, 0x802c, 0x802d, 0x802e, 0x802f, 0x8030, 0x1, 0 };
    if (getenv("MOCK_VERBOSE")) { for (int k = 0; k < 4; k++) printf("fn %d: stock %p rebuilt %p\n", k, (void *)f[k][0], (void *)f[k][1]); }
    int ntests = 0, nwrote = 0, bad = 0, nerr = 0, errbad = 0;
    for (int k = 0; k < 4; k++) {
        int kw = 0, kb = 0;
        for (unsigned ti = 0; ti < sizeof targets / sizeof targets[0]; ti++)
            for (unsigned pi = 0; pi < sizeof pnames / sizeof pnames[0]; pi++)
                for (int pre = 0; pre < 2; pre++) for (int pat = 0; pat < 2; pat++) {
                    unsigned char *c[2]; unsigned out[2][4]; unsigned wrote;
                    for (int s = 0; s < 2; s++) {
                        c[s] = malloc(CTXSZ); mkctx(c[s], pre ? 0x502 : 0, pat);
                        for (int i = 0; i < 4; i++) out[s][i] = 0xA5A5A5A5;
                        f[k][s](c[s], targets[ti], pnames[pi], out[s]);
                    }
                    wrote = out[0][0] != 0xA5A5A5A5 || k >= 2;   /* fv always stores a float; for iv the sentinel shows whether it wrote */
                    int errdiff = *(unsigned *)(c[0] + 0x7574) != *(unsigned *)(c[1] + 0x7574);
                    int ctxdiff = memcmp(c[0], c[1], CTXSZ) != 0;
                    /* is the output word defined? iv: sentinel changed. fv: the matching iv (k-2) wrote it in stock */
                    int defined;
                    if (k < 2) defined = out[0][0] != 0xA5A5A5A5;
                    else { unsigned o[4] = { 0xA5A5A5A5 }; unsigned char *cc = malloc(CTXSZ); mkctx(cc, pre ? 0x502 : 0, pat); f[k - 2][0](cc, targets[ti], pnames[pi], o); defined = o[0] != 0xA5A5A5A5; free(cc); }
                    int outdiff = out[0][0] != out[1][0];
                    if (getenv("MOCK_VERBOSE") && k == 0 && ti < 2 && pi < 9 && !pre && !pat) printf("  Histogram iv target %x pname %x: lha4a10 %d out %08x/%08x err %x/%x\n", targets[ti], pnames[pi], *(short *)(c[0] + 0x4a10), out[0][0], out[1][0], *(unsigned *)(c[0] + 0x7574), *(unsigned *)(c[1] + 0x7574));
                    ntests++;
                    if (defined) { nwrote++; kw++; if (outdiff || ctxdiff) { kb++; bad++; printf("DIFF %s target %x pname %x pre %d pat %d: out stock %08x rebuilt %08x, ctx %s\n", k == 0 ? "Histogram iv" : k == 1 ? "Minmax iv" : k == 2 ? "Histogram fv" : "Minmax fv", targets[ti], pnames[pi], pre, pat, out[0][0], out[1][0], ctxdiff ? "DIFFER" : "same"); } }
                    else { nerr++; if (ctxdiff) { errbad++; kb++; printf("ERRDIFF %s target %x pname %x pre %d pat %d: ctx differs\n", k == 0 ? "Histogram iv" : k == 1 ? "Minmax iv" : k == 2 ? "Histogram fv" : "Minmax fv", targets[ti], pnames[pi], pre, pat); } }
                    free(c[0]); free(c[1]); (void)wrote; (void)errdiff;
                }
        printf("%s: %d defined-output cases, %d differ\n", k == 0 ? "Histogram iv" : k == 1 ? "Minmax iv" : k == 2 ? "Histogram fv" : "Minmax fv", kw, kb);
    }
    printf("tests %d, defined-output %d, error-path (output not compared, ctx compared) %d; bad %d errbad %d\nRESULT: %s\n", ntests, nwrote, nerr, bad, errbad, (bad || errbad) ? "FAIL" : "PASS");
    return bad || errbad;
}
