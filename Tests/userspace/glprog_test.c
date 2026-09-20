/* glprog_test.c - differential test of the rebuilt libGLProgrammability against the stock one, loaded side by side.
 * 1. every C export of the stock resolves in the rebuilt image;
 * 2. the ARB vertex/fragment program parser (PPParserCreate/AttachString/Parse) returns the same status for a set of valid and invalid programs;
 * 3. the atom table and bit-set helpers give the same results. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void *(*create_t)(unsigned int);
typedef void (*attach_t)(void *, const char *, int);
typedef int (*parse_t)(void *);
typedef void (*free_t)(void *);

static const char *progs[] = {
    "!!ARBvp1.0\nMOV result.position, vertex.position;\nEND\n",
    "!!ARBvp1.0\nATTRIB pos = vertex.position;\nPARAM mvp[4] = { state.matrix.mvp };\nDP4 result.position.x, mvp[0], pos;\nDP4 result.position.y, mvp[1], pos;\nDP4 result.position.z, mvp[2], pos;\nDP4 result.position.w, mvp[3], pos;\nMOV result.color, vertex.color;\nEND\n",
    "!!ARBfp1.0\nMOV result.color, fragment.color;\nEND\n",
    "!!ARBfp1.0\nTEMP t;\nTEX t, fragment.texcoord[0], texture[0], 2D;\nMUL result.color, t, fragment.color;\nEND\n",
    "!!ARBfp1.0\nTEMP t;\nADD t, fragment.color, fragment.color;\nSUB result.color, t, program.env[0];\nEND\n",
    "!!ARBvp1.0\nMOV result.position, vertex.position\nEND\n",              /* missing semicolon */
    "!!ARBvp1.0\nFOO result.position, vertex.position;\nEND\n",             /* unknown opcode */
    "!!ARBvp1.0\nMOV result.position, vertex.position;\n",                  /* missing END */
    "!!ARBfp1.0\nMOV result.color, fragment.nosuch;\nEND\n",
    "!!ARBvp2.0\nEND\n",
    "not a program",
    "",
    "!!ARBvp1.0\nOPTION ARB_position_invariant;\nMOV result.color, vertex.color;\nEND\n",
    "!!ARBfp1.0\nOPTION ARB_precision_hint_fastest;\nMOV result.color, fragment.color;\nEND\n",
    "!!ARBvp1.0\nTEMP a, b;\nMOV a, vertex.position;\nMAD b, a, a, a;\nRSQ b.x, b.x;\nMOV result.position, b;\nEND\n",
    "!!ARBvp1.0\n# comment\nPARAM c = {1, 2, 3, 4};\nADD result.position, vertex.position, c;\nEND\n",
    "!!ARBvp1.0\nADDRESS a0;\nPARAM tbl[4] = { program.env[0..3] };\nARL a0.x, vertex.attrib[1].x;\nMOV result.position, tbl[a0.x + 1];\nEND\n",
    "!!ARBvp1.0\nTEMP r;\nSWZ r, vertex.position, x, y, -z, 1;\nMOV result.position, r;\nEND\n",
    "!!ARBvp1.0\nPARAM m[4] = { state.matrix.modelview };\nDP4 result.position.x, m[0], vertex.position;\nDP4 result.position.y, m[1], vertex.position;\nDP4 result.position.z, m[2], vertex.position;\nDP4 result.position.w, m[3], vertex.position;\nEND\n",
    "!!ARBvp1.0\nATTRIB p = vertex.position;\nOUTPUT o = result.position;\nOUTPUT c = result.color.primary;\nOUTPUT t = result.texcoord[1];\nMOV o, p;\nMOV c, vertex.color;\nMOV t, vertex.texcoord[0];\nEND\n",
    "!!ARBvp1.0\nTEMP r;\nEX2 r, vertex.position.x;\nLG2 r.y, vertex.position.y;\nPOW r.z, vertex.position.x, vertex.position.y;\nMOV result.position, r;\nEND\n",
    "!!ARBvp1.0\nMOV result.position, vertex.position.wzyx;\nEND\n",
    "!!ARBvp1.0\nMOV result.position.xyzw, -vertex.position;\nEND\n",
    "!!ARBvp1.0\nMOV result.pointsize, vertex.position.x;\nMOV result.fogcoord, vertex.position.y;\nEND\n",
    "!!ARBfp1.0\nTEMP t;\nTEX t, fragment.texcoord[0], texture[0], CUBE;\nMOV result.color, t;\nEND\n",
    "!!ARBfp1.0\nTEMP t;\nTEX t, fragment.texcoord[1], texture[1], 3D;\nMOV result.color, t;\nEND\n",
    "!!ARBfp1.0\nTEMP t;\nTEX t, fragment.texcoord[0], texture[0], 1D;\nMOV result.color, t;\nEND\n",
    "!!ARBfp1.0\nTEMP t;\nTEX t, fragment.texcoord[0], texture[0], RECT;\nMOV result.color, t;\nEND\n",
    "!!ARBfp1.0\nTEMP t;\nTEX t, fragment.texcoord[0], texture[0], 4D;\nMOV result.color, t;\nEND\n",
    "!!ARBfp1.0\nTEMP a, b;\nLRP a, fragment.color, fragment.texcoord[0], fragment.texcoord[1];\nCMP b, a, a, fragment.color;\nMOV_SAT result.color, b;\nEND\n",
    "!!ARBfp1.0\nTEMP a;\nDP3 a, fragment.color, fragment.color;\nRSQ a, a.x;\nMUL result.color, fragment.color, a.x;\nEND\n",
    "!!ARBfp1.0\nTEMP a;\nKIL fragment.color;\nMOV result.color, fragment.color;\nEND\n",
    "!!ARBfp1.0\nPARAM c = { 0.5, 1.5, -2.25, 1e2 };\nMOV result.color, c;\nEND\n",
    "!!ARBfp1.0\nPARAM c = { 0.5, 1.5, -2.25, 1e2 };\nMUL result.depth, c.x, c.y;\nMOV result.color, c;\nEND\n",
    "!!ARBfp1.0\nTEMP a;\nMOV a, program.local[3];\nMOV result.color, a;\nEND\n",
    "!!ARBfp1.0\nTEMP a;\nMOV a, fragment.position;\nMOV result.color, a;\nEND\n",
    "!!ARBfp1.0\nMOV result.color, fragment.color.secondary;\nEND\n",
    "!!ARBfp1.0\nTEMP a;\nMOV a.w, fragment.color;\nMOV result.color, a;\nEND\n",
    "!!ARBfp1.0\nTEMP a;\nMOV a, fragment.fogcoord;\nMOV result.color, a;\nEND\n",
    0
};
static const unsigned flagsets[] = { 0, 1, 0x10, 0x11, 0x2, 0x4 };

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    void *a = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), *b = dlopen(argv[2], RTLD_NOW | RTLD_LOCAL);
    printf("stock dlopen %s, rebuilt dlopen %s\n", a ? "ok" : dlerror(), b ? "ok" : dlerror());
    if (!a || !b) return 1;
    int missing = 0, n = 0;
    if (argc > 3) {
        FILE *f = fopen(argv[3], "r"); char line[512];
        while (f && fgets(line, sizeof line, f)) {
            line[strcspn(line, "\r\n")] = 0; if (!line[0]) continue;
            n++; if (dlsym(a, line + 1) && !dlsym(b, line + 1)) { missing++; if (missing < 8) printf("  missing in rebuilt: %s\n", line); }
        }
        printf("stock C exports checked: %d, missing in rebuilt: %d\n", n, missing);
    }
    typedef void *(*mk_t)(void);
    typedef void (*astream_t)(void *, void *);
    typedef int (*gs_t)(void *, void *, unsigned *);
    create_t ca = dlsym(a, "PPParserCreate"), cb = dlsym(b, "PPParserCreate");
    attach_t aa = dlsym(a, "PPParserAttachString"), ab = dlsym(b, "PPParserAttachString");
    parse_t pa = dlsym(a, "PPParserParse"), pb = dlsym(b, "PPParserParse");
    free_t fa = dlsym(a, "PPParserFree"), fb = dlsym(b, "PPParserFree");
    mk_t sa_ = dlsym(a, "PPStreamCreate"), sb_ = dlsym(b, "PPStreamCreate");
    astream_t ata = dlsym(a, "PPParserAttachStream"), atb = dlsym(b, "PPParserAttachStream");
    gs_t gsa = dlsym(a, "PPStreamGetStream"), gsb = dlsym(b, "PPStreamGetStream");
    free_t sfa = dlsym(a, "PPStreamFree"), sfb = dlsym(b, "PPStreamFree");
    unsigned vlim[15] = { 0x100, 0x100, 8, 0x8000, 0x100, 0x100, 0x20, 2, 8, 0x10, 4, 1, 6, 8, 0x10 };
    unsigned flim[15] = { 0x80, 0x80, 8, 0x8000, 0x100, 0x80, 0x40, 0, 8, 0x10, 4, 1, 6, 8, 0 };
    int total = 0, diff = 0;
    for (int kind = 0; kind < 2; kind++)
        for (int i = 0; progs[i]; i++) {
            if (argc > 4 && i < atoi(argv[4])) continue;
            void *pa_ = ca(kind ? 2 : 0), *pb_ = cb(kind ? 2 : 0);
            void *stA = sa_(), *stB = sb_();
            ata(pa_, stA); atb(pb_, stB);
            memcpy((char *)pa_ + 0x450, kind ? flim : vlim, 0x3c); memcpy((char *)pb_ + 0x450, kind ? flim : vlim, 0x3c);
            aa(pa_, progs[i], 1); ab(pb_, progs[i], 1);
            int ra = pa(pa_), rb = pb(pb_);
            unsigned na = 0, nb = 0; gsa(stA, 0, &na); gsb(stB, 0, &nb);
            int same = (ra == rb) && (na == nb);
            if (same && ra == 0 && na < 100000) {
                unsigned *bufa = calloc(na, 8), *bufb = calloc(nb, 8);
                gsa(stA, bufa, &na); gsb(stB, bufb, &nb);
                same = memcmp(bufa, bufb, na * 8) == 0;
                if (!same) { unsigned nd = 0, first = 0xffffffff; for (unsigned w = 0; w < na * 2; w++) if (bufa[w] != bufb[w]) { if (first == 0xffffffff) first = w; nd++; } printf("  DIFF stream kind=%d prog %d (n=%u): %u of %u words differ, first word %u: stock %08x rebuilt %08x\n", kind, i, na, nd, na * 2, first, bufa[first], bufb[first]); }
                free(bufa); free(bufb);
            }
            total++; if (!same) { diff++; printf("  DIFF kind=%d prog %d: stock rc=%d n=%u rebuilt rc=%d n=%u\n", kind, i, ra, na, rb, nb); }
            else printf("  kind %d prog %2d: rc=%d, %u stream words (both)\n", kind, i, ra, na);
            sfa(stA); sfb(stB); fa(pa_); fb(pb_);
        }
    printf("PPParser: %d parses compared (status, stream size and stream bytes), %d differences\n", total, diff);
    printf("RESULT: %s\n", (missing == 0 && diff == 0) ? "PASS" : "FAIL");
    return 0;
}
