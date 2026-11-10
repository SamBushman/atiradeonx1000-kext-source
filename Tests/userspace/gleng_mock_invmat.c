/* gleng_mock_invmat.c - Phase 3 mock test of GLEngine _gleInvertMatrix_AltiVec (stock 0x335c0, the hand-transcribed C of Userspace/GLEngine/ppc/hand) on a valid context block.
 *   gleng_mock_invmat STOCK REBUILT ANCHOR STOCK_ANCHOR_ADDR REBUILT_ANCHOR_ADDR STOCK_FN REBUILT_FN [N]   (hex addresses; N random matrices per alignment/index, default 2000)
 * The function takes (ctx, idx) and inverts the 4x4 float matrix at ctx + idx*64 + 0x1bc0 into ctx + idx*64 + 0x21c0 (unaligned loads and stores). A 0x2400-byte block with the matrix
 * at 16 start alignments (0..15), idx 0..4, and matrices: identity, diagonal, singular rows, +-0 / Inf / NaN / denormal entries, ranges 1e-30..1e30, plus N random bit patterns each, is
 * run through both images; the WHOLE block (so any byte written outside the 64 output bytes shows) must be identical afterwards. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef void (*fn_t)(unsigned char *, unsigned int);
#define BLK 0x2400
static unsigned long long rs = 0x9e3779b97f4a7c15ULL;
static unsigned int rnd(void) { rs ^= rs << 13; rs ^= rs >> 7; rs ^= rs << 17; return (unsigned int)(rs >> 16); }
static float rf(float lo, float hi) { return lo + (hi - lo) * (rnd() & 0xffffff) / 16777215.0f; }
static unsigned int special(void) { static const unsigned int s[] = { 0, 0x80000000, 0x3f800000, 0xbf800000, 0x7f800000, 0xff800000, 0x7fc00000, 0x00000001, 0x80000001, 0x007fffff, 0x7f7fffff, 0x00800000, 0x40000000, 0x3f000000 }; return s[rnd() % (sizeof s / sizeof *s)]; }
static void fill(unsigned int *m, int kind) {
    int i;
    switch (kind) {
    case 0: for (i = 0; i < 16; i++) m[i] = (i % 5 == 0) ? 0x3f800000u : 0; break;
    case 1: for (i = 0; i < 16; i++) { float f = (i % 5 == 0) ? rf(0.25f, 8.0f) : 0.0f; memcpy(m + i, &f, 4); } break;
    case 2: for (i = 0; i < 16; i++) { float f = rf(-4, 4); memcpy(m + i, &f, 4); } break;
    case 3: for (i = 0; i < 16; i++) { float f = rf(-4, 4); memcpy(m + i, &f, 4); } for (i = 0; i < 4; i++) m[4 + i] = m[i]; break;     /* singular: row1 == row0 */
    case 4: for (i = 0; i < 16; i++) m[i] = special(); break;
    case 5: for (i = 0; i < 16; i++) { float f = rf(-1, 1) * (float)(1 << (rnd() % 60)) * 1e-9f; memcpy(m + i, &f, 4); } break;
    case 6: for (i = 0; i < 16; i++) { float f = rf(-1, 1) * 1e30f; if (rnd() & 1) f = rf(-1, 1) * 1e-30f; memcpy(m + i, &f, 4); } break;
    case 7: for (i = 0; i < 16; i++) { float f = (float)((int)(rnd() % 9) - 4); memcpy(m + i, &f, 4); } break;
    default: for (i = 0; i < 16; i++) m[i] = rnd(); break;
    }
}
int main(int argc, char **argv) {
    if (argc < 8) return 2;
    void *L[2] = { dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), dlopen(argv[2], RTLD_NOW | RTLD_LOCAL) };
    const char *an = argv[3][0] == '_' ? argv[3] + 1 : argv[3];
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    unsigned sa = strtoul(argv[4], 0, 16), ra = strtoul(argv[5], 0, 16), sf = strtoul(argv[6], 0, 16), rfn = strtoul(argv[7], 0, 16);
    int N = argc > 8 ? atoi(argv[8]) : 2000;
    if (!ap[0] || !ap[1]) { printf("anchor not found\n"); return 2; }
    fn_t f[2] = { (fn_t)(ap[0] + (sf - sa)), (fn_t)(ap[1] + (rfn - ra)) };
    int ntests = 0, bad = 0, a, idx, k, n;
    for (a = 0; a < 16; a++) for (idx = 0; idx < 5; idx++) {
        int nb = 0;
        for (k = 0; k < 9; k++) for (n = 0; n < (k < 8 ? (k == 0 || k == 3 ? 1 : 40) : N); n++) {
            unsigned char *raw[2], *c[2], *base[2]; unsigned int m[16]; int s;
            fill(m, k);
            for (s = 0; s < 2; s++) {
                void *pp = malloc(BLK + 96); raw[s] = (unsigned char *)(((unsigned long)pp + 15) & ~15UL); base[s] = pp; memset(raw[s], 0xA5, BLK + 64); c[s] = raw[s] + a;
                memcpy(c[s] + 0x1bc0 + idx * 64, m, 64);
                f[s](c[s], idx);
            }
            ntests++;
            if (memcmp(raw[0], raw[1], BLK + 64) != 0) {
                bad++; nb++;
                if (nb <= 3) { int i; for (i = 0; i < BLK + 64; i++) if (raw[0][i] != raw[1][i]) break; printf("DIFF align %d idx %d kind %d n %d: first differing byte at +0x%x (stock %02x rebuilt %02x); out at +0x%x\n", a, idx, k, n, i, raw[0][i], raw[1][i], a + 0x21c0 + idx * 64); }
            }
            free(base[0]); free(base[1]);
        }
    }
    printf("tests %d; bad %d\nRESULT: %s\n", ntests, bad, bad ? "FAIL" : "PASS");
    return bad != 0;
}
