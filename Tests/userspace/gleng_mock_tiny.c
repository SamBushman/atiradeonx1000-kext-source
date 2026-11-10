/* gleng_mock_tiny.c - Phase 3 mock test of the GLEngine functions of <16 bytes that the fuzzers skip and whose rebuilt instructions differ from the stock's (stock vs rebuilt, same process).
 *   gleng_mock_tiny STOCK REBUILT ANCHOR STOCK_ANCHOR_ADDR REBUILT_ANCHOR_ADDR [N] < spec     (hex addresses; spec lines: `kind name stock_addr rebuilt_addr off`)
 * kinds: ext  = f(block, src): *(float *)(block + off) = *(float *)src            (_gleExtractPixel_*_Float, _glFogCoordfv_Exec: stock lfs/stfs, rebuilt lwz/stw)
 *        ins  = f(block, dst): *(float *)dst = *(float *)(block + off)            (_gleInsertPixel_*_Float: same pair)
 *        rtc  = int f(int word, int count): (word & ~0xfffc) | ((count << 2) & 0xfffc)   (_gleRTCBuildABranch_*: stock rlwinm + rlwimi, rebuilt one rlwimi; the stock leaves r4 = (count << 2) & 0xfffc,
 *               dead in every stock caller, see EVIDENCE section 15)
 * lfs/stfs convert a single through a double and back; the claim is that this is a bit-exact copy for EVERY 32-bit pattern (SNaN, QNaN payloads, +-Inf, denormals, -0). Run: all 65536 patterns of the top
 * halfword x 8 low halfwords, then N random 32-bit patterns; the whole block / destination and the return value must be identical. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef unsigned (*fn_t)(void *, void *);
static unsigned long long rs = 0x9e3779b97f4a7c15ULL;
static unsigned rnd(void) { rs ^= rs << 13; rs ^= rs >> 7; rs ^= rs << 17; return (unsigned)(rs >> 16); }
#define BLK 0x400
int main(int argc, char **argv) {
    if (argc < 6) return 2;
    void *L[2] = { dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), dlopen(argv[2], RTLD_NOW | RTLD_LOCAL) };
    const char *an = argv[3][0] == '_' ? argv[3] + 1 : argv[3];
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    unsigned sa = strtoul(argv[4], 0, 16), ra = strtoul(argv[5], 0, 16);
    int N = argc > 6 ? atoi(argv[6]) : 5000000;
    if (!ap[0] || !ap[1]) { printf("anchor not found\n"); return 2; }
    char kind[16], name[96]; unsigned s, r, off; int total = 0, totbad = 0;
    while (scanf("%15s %95s %x %x %x", kind, name, &s, &r, &off) == 5) {
        fn_t f[2] = { (fn_t)(ap[0] + (s - sa)), (fn_t)(ap[1] + (r - ra)) };
        unsigned long long n = 0, bad = 0; unsigned pat_lo[8] = { 0, 1, 0x7fff, 0x8000, 0x4000, 0xffff, 0x2aaa, 0x5555 };
        unsigned long long iters = strcmp(kind, "rtc") ? 65536ULL * 8 + (unsigned)N : 1000000ULL + (unsigned)N;
        for (unsigned long long it = 0; it < iters; it++) {
            unsigned v;
            if (strcmp(kind, "rtc")) v = it < 65536ULL * 8 ? ((unsigned)(it >> 3) << 16) | pat_lo[it & 7] : rnd() ^ (rnd() << 16);
            else v = rnd() ^ (rnd() << 16);
            unsigned w = rnd() ^ (rnd() << 16);
            unsigned res[2];
            unsigned char blk[2][BLK], io[2][16];
            for (int k = 0; k < 2; k++) {
                memset(blk[k], 0xA5, BLK); memset(io[k], 0x5A, 16);
                if (!strcmp(kind, "ext")) { memcpy(io[k], &v, 4); res[k] = f[k](blk[k], io[k]); }
                else if (!strcmp(kind, "ins")) { memcpy(blk[k] + off, &v, 4); res[k] = f[k](blk[k], io[k]); }
                else { res[k] = ((unsigned (*)(unsigned, unsigned))f[k])(v, w); }
            }
            if (strcmp(kind, "rtc")) for (int k = 0; k < 2; k++) res[k] -= (unsigned)(unsigned long)blk[k];   /* r3 is left holding the block pointer (arrays differ per image: compare relative to it) */
            n++;
            if (res[0] != res[1] || memcmp(blk[0], blk[1], BLK) || memcmp(io[0], io[1], 16)) { if (bad++ < 3) printf("DIFF %s v %08x w %08x: ret %08x/%08x\n", name, v, w, res[0], res[1]); }
        }
        printf("%-4s %-36s %llu cases, %llu differ\n", kind, name, n, bad);
        total += n > 0; totbad += bad != 0;
    }
    printf("functions %d; bad %d\nRESULT: %s\n", total, totbad, totbad ? "FAIL" : "PASS");
    return totbad != 0;
}
