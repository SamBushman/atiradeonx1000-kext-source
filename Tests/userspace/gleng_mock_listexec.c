/* gleng_mock_listexec.c - Phase 3 mock test of GLEngine _glMap1VertexAttrib{1,2,3,4}ARB_ListExec (stock vs rebuilt) on a VALID context block.
 *   gleng_mock_listexec STOCK REBUILT ANCHOR STOCK_ANCHOR_ADDR REBUILT_ANCHOR_ADDR S1 R1 S2 R2 S3 R3 S4 R4   (hex addresses)
 * Defect class #16: the stock stores a flag BYTE at MapData + idx + 0x9da8 (`addis r9,r9,1; stb r0,-0x6258(r9)`); 0x9da8 is also the address of
 * _gleSelectVertexAddMaterialFunc, so Ghidra printed the function's name and the rebuilt code stored a WORD through the name's (rebuilt) address
 * (fnfuzz: stock returns, rebuilt SIGBUS). Here ctx+0x7450 (the MapData pointer _gleGetMapData returns when it is non-NULL) points at a sentinel-filled block, and
 * idx 0..15 x count 0..6 x two parameter fills are run through both images: the return value and the whole MapData block must be identical. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef int (*fn_t)(void *, int *);
#define CTXSZ 0x8000
#define MAPSZ 0xA000
static void mkctx(unsigned char *c, unsigned char *map, int pat) {
    for (int i = 0; i < CTXSZ; i++) c[i] = (unsigned char)(i * 131 + pat * 17 + 5);
    *(unsigned char **)(c + 0x7450) = map;
}
int main(int argc, char **argv) {
    if (argc < 14) return 2;
    void *L[2] = { dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), dlopen(argv[2], RTLD_NOW | RTLD_LOCAL) };
    const char *an = argv[3][0] == '_' ? argv[3] + 1 : argv[3];
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    unsigned sa = strtoul(argv[4], 0, 16), ra = strtoul(argv[5], 0, 16);
    fn_t f[4][2];
    for (int k = 0; k < 4; k++) { f[k][0] = (fn_t)(ap[0] + (strtoul(argv[6 + 2 * k], 0, 16) - sa)); f[k][1] = (fn_t)(ap[1] + (strtoul(argv[7 + 2 * k], 0, 16) - ra)); }
    int ntests = 0, bad = 0;
    for (int k = 0; k < 4; k++) {
        int kb = 0, kt = 0;
        for (int idx = 0; idx < 16; idx++) for (int cnt = 0; cnt <= 6; cnt++) for (int pat = 0; pat < 2; pat++) {
            int p[2][80]; unsigned char *m[2], *c[2]; int r[2];
            for (int s = 0; s < 2; s++) {
                for (int i = 0; i < 80; i++) p[s][i] = (int)(0x3f000000u + (unsigned)(i * 0x10101 + pat * 0x777 + idx));
                p[s][0] = idx; p[s][1] = cnt;
                m[s] = malloc(MAPSZ); memset(m[s], 0xA5 ^ pat, MAPSZ);
                c[s] = malloc(CTXSZ); mkctx(c[s], m[s], pat);
                r[s] = f[k][s](c[s], p[s]);
            }
            ntests++; kt++;
            int mapdiff = memcmp(m[0], m[1], MAPSZ) != 0;
            *(unsigned *)(c[0] + 0x7450) = 0; *(unsigned *)(c[1] + 0x7450) = 0;   /* the two MapData pointers differ by construction */
            int ctxdiff = memcmp(c[0], c[1], CTXSZ) != 0;
            int flag0 = m[0][0x9da8 + idx], flag1 = m[1][0x9da8 + idx];
            if (r[0] != r[1] || mapdiff || ctxdiff) {
                bad++; kb++;
                printf("DIFF Map1VertexAttrib%dARB_ListExec idx %d cnt %d pat %d: ret %d/%d map %s ctx %s flag %d/%d\n", k + 1, idx, cnt, pat, r[0], r[1], mapdiff ? "DIFFER" : "same", ctxdiff ? "DIFFER" : "same", flag0, flag1);
            } else if (getenv("MOCK_VERBOSE") && idx < 2 && cnt == 2 && !pat) printf("  attrib%d idx %d cnt %d: ret %d flag byte %d (both)\n", k + 1, idx, cnt, r[0], flag0);
            for (int s = 0; s < 2; s++) { free(m[s]); free(c[s]); }
        }
        printf("Map1VertexAttrib%dARB_ListExec: %d cases, %d differ\n", k + 1, kt, kb);
    }
    printf("tests %d; bad %d\nRESULT: %s\n", ntests, bad, bad ? "FAIL" : "PASS");
    return bad != 0;
}
