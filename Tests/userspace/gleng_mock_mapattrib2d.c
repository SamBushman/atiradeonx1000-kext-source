/* gleng_mock_mapattrib2d.c - Phase 3 mock test of GLEngine _glMapVertexAttrib2dARB_Exec and _glMapVertexAttrib2dARB_Comp (stock vs rebuilt, same process) on valid context blocks.
 *   gleng_mock_mapattrib2d STOCK REBUILT ANCHOR SA RA EXEC_S EXEC_R COMP_S COMP_R [N]   (hex addresses)
 * Exec: ctx + 0x4a10 (short, < 0 = not inside glBegin), ctx + 0x7450 -> MapData block (the pointer _gleGetMapData returns when non-NULL), ctx + 0x7574 = pending GL error. For index < 16, ranges u1 != u2 and v1 != v2,
 *   1..10 orders and size 1..4 with strides >= size it forwards to _gleMap2VertexAttrib{1,2,3,4}dLoad into MapData + index*0x660 + 0x37a8 and stores the size at MapData + index + 0x9db8; otherwise it sets GL error 0x501
 *   (0x502 inside a Begin) unless one is pending. Comp: _gleAddListItem on a valid list context (ctx + 0x53e8 -> list block H: +0x10 item count, +0x14 table, +0x18 capacity; ctx + 0x5400 bytes used, ctx + 0x53fc capacity)
 *   then the same Load into the item; size outside 1..4 sets 0x501. Words 1..16: ctx, index/op, size, 4 unused, ustride, uorder, 4 unused, vstride, vorder, points; f1..f4 = u1, u2, v1, v2.
 * Per trial both images get identical arguments / points / blocks; the WHOLE ctx (pointer words zeroed), MapData block, list block H and item-size table must be identical afterwards. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef void (*fn_t)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned,
                     double, double, double, double, double, double, double, double, double, double, double, double, double);
static unsigned long long rs = 0x9e3779b97f4a7c15ULL;
static unsigned rnd(void) { rs ^= rs << 13; rs ^= rs >> 7; rs ^= rs << 17; return (unsigned)(rs >> 16); }
static double dval(void) {
    switch (rnd() % 12) {
    case 0: return 0.0; case 1: return -0.0; case 2: return 1.0; case 3: return -1.0;
    case 4: { unsigned long long b = 0x7ff0000000000000ULL; double d; memcpy(&d, &b, 8); return d; }
    case 5: { unsigned long long b = 0x7ff8000000000001ULL; double d; memcpy(&d, &b, 8); return d; }
    case 6: return 4.9e-324 * (1 + rnd() % 1000); case 7: return 1e300 * (rnd() % 2 ? 1 : -1);
    case 8: return (double)(float)((int)(rnd() % 20001) - 10000) / 64.0; case 9: return 1e-40 * (1 + rnd() % 100);
    default: return ((int)(rnd() % 2000001) - 1000000) / 1000.0;
    }
}
static void range(double *a, double *b) {
    switch (rnd() % 8) { case 0: *a = 0; *b = 1; break; case 1: *a = 1; *b = 0; break; case 2: *a = *b = dval(); break; case 3: *a = dval(); *b = dval(); break;
    default: *a = (int)(rnd() % 200) - 100; *b = *a + 1 + rnd() % 50; break; }
}
#define CTXSZ 0x8000
#define MAPSZ 0xA000
#define HSZ 0x8000
#define TSZ 0x1000
#define NPTS 4096
static void mk(unsigned char *c, unsigned char *map, unsigned char *H, unsigned *T, int pat, int negbegin, unsigned err) {
    for (int i = 0; i < CTXSZ; i++) c[i] = (unsigned char)(i * 131 + pat * 17 + 5);
    memset(H, 0, HSZ); memset(T, 0, TSZ); memset(map, 0xA5 ^ pat, MAPSZ);
    *(unsigned char **)(c + 0x7450) = map; *(short *)(c + 0x4a10) = negbegin ? -1 : 0x10; *(unsigned *)(c + 0x7574) = err;
    *(unsigned char **)(c + 0x53e8) = H; *(unsigned *)(c + 0x53fc) = HSZ; *(unsigned *)(c + 0x5400) = 0x1c; *(unsigned *)(H + 0x10) = 0; *(unsigned **)(H + 0x14) = T; *(unsigned *)(H + 0x18) = 0x400;
}
static void ptrs(unsigned char *c, unsigned char *H) { *(unsigned *)(c + 0x7450) = 0; *(unsigned *)(c + 0x53e8) = 0; *(unsigned *)(H + 0x14) = 0; *(unsigned *)(H + 0x1c) = 0; }   /* + the code pointer _gleAddListItem stores as the item's first word (a different address in each image) */   /* allocation addresses differ between the two sides */
int main(int argc, char **argv) {
    if (argc < 10) return 2;
    void *L[2] = { dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), dlopen(argv[2], RTLD_NOW | RTLD_LOCAL) };
    const char *an = argv[3][0] == '_' ? argv[3] + 1 : argv[3];
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    unsigned sa = strtoul(argv[4], 0, 16), ra = strtoul(argv[5], 0, 16);
    unsigned fs[2] = { strtoul(argv[6], 0, 16), strtoul(argv[8], 0, 16) }, fr[2] = { strtoul(argv[7], 0, 16), strtoul(argv[9], 0, 16) };
    int N = argc > 10 ? atoi(argv[10]) : 100000;
    if (!ap[0] || !ap[1]) { printf("anchor not found\n"); return 2; }
    const char *nm[2] = { "_glMapVertexAttrib2dARB_Exec", "_glMapVertexAttrib2dARB_Comp" };
    int total = 0, totbad = 0;
    for (int w = 0; w < 2; w++) {
        fn_t f[2] = { (fn_t)(ap[0] + (fs[w] - sa)), (fn_t)(ap[1] + (fr[w] - ra)) };
        int bad = 0, fwd = 0, err = 0;
        for (int t = 0; t < N; t++) {
            static double pts[2][NPTS];
            unsigned idx = rnd() % 4 == 0 ? rnd() % 40 : rnd() % 16, size = rnd() % 8 == 0 ? rnd() % 8 : 1 + rnd() % 4;
            unsigned us = rnd() % 4 == 0 ? rnd() % 6 : 1 + rnd() % 12, vs = rnd() % 4 == 0 ? rnd() % 6 : 1 + rnd() % 12, uo = rnd() % 8 == 0 ? rnd() % 14 : 1 + rnd() % 10, vo = rnd() % 8 == 0 ? rnd() % 14 : 1 + rnd() % 10;
            if (w == 1) { /* the item size 100 - uo*vo must stay >= 0: a bigger map overruns the item in the stock too */ if (uo * vo > 100) { uo = 1 + rnd() % 10; vo = 1 + rnd() % 10; } }
            double u1, u2, v1, v2; range(&u1, &u2); range(&v1, &v2);
            int pat = rnd() % 2, negb = rnd() % 8 != 0; unsigned e = rnd() % 4 == 0 ? 0x1234 : 0;
            for (int i = 0; i < NPTS; i++) pts[0][i] = pts[1][i] = dval();
            unsigned char *c[2], *map[2], *H[2]; unsigned *T[2];
            for (int k = 0; k < 2; k++) {
                c[k] = malloc(CTXSZ); map[k] = malloc(MAPSZ); H[k] = malloc(HSZ); T[k] = malloc(TSZ);
                mk(c[k], map[k], H[k], T[k], pat, negb, e);
                f[k]((unsigned)(unsigned long)c[k], idx, size, 0x11111111, 0x22222222, 0x33333333, 0x44444444, us, uo, 0x55555555, 0x66666666, 0x77777777, 0x88888888, vs, vo, (unsigned)(unsigned long)pts[k],
                     u1, u2, v1, v2, 0.5, 0.25, 0.125, 0.0625, 3.0, 5.0, 7.0, 9.0, 11.0);
            }
            unsigned e0 = *(unsigned *)(c[0] + 0x7574); int hcount = *(unsigned *)(H[0] + 0x10), hptr = (*(unsigned *)(H[0] + 0x1c) != 0) == (*(unsigned *)(H[1] + 0x1c) != 0), flag = idx < 16 ? map[0][idx + 0x9db8] : 0; ptrs(c[0], H[0]); ptrs(c[1], H[1]);
            int mapdiff = memcmp(map[0], map[1], MAPSZ) != 0, hdiff = !hptr || memcmp(H[0], H[1], HSZ) != 0 || memcmp(T[0], T[1], TSZ) != 0;
            if (e0 != e) err++; if (w == 0 ? (idx < 16 && flag == (int)size && e0 == e) : hcount == 1) fwd++;
            int cdiff = memcmp(c[0], c[1], CTXSZ) != 0;
            if (mapdiff || hdiff || cdiff) { if (bad++ < 3) printf("DIFF %s trial %d idx %u size %u us %u uo %u vs %u vo %u neg %d: map %s list %s ctx %s\n", nm[w], t, idx, size, us, uo, vs, vo, negb, mapdiff ? "DIFFER" : "same", hdiff ? "DIFFER" : "same", cdiff ? "DIFFER" : "same"); }
            for (int k = 0; k < 2; k++) { free(c[k]); free(map[k]); free(H[k]); free(T[k]); }
        }
        printf("%-30s %d trials, %d differ; %d reached the Load, %d changed the error word\n", nm[w], N, bad, fwd, err);
        total++; totbad += bad != 0;
    }
    printf("functions %d; bad %d\nRESULT: %s\n", total, totbad, totbad ? "FAIL" : "PASS");
    return totbad != 0;
}
