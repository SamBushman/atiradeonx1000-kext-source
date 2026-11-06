/* gl_doom_replay_probe.c - #214: grow-a-repro-from-Doom-3 probe.  Replays the shape of the draw batch that wedges the CP when
 * dhewm3 runs with r_useVertexBuffers=1 on the stock X1900 driver: a batch of fixed-function depth-fill draws (RB_T_FillDepthBuffer:
 * glVertexPointer(3,FLOAT,60,vbo+0) + glTexCoordPointer(2,FLOAT,60,vbo+12), black glColor, bound white texture, client 32-bit
 * indices, one STATIC_DRAW vertex VBO per surface, ONE glFinish at the end of the batch).  Measured from a dhewm3 trace the batch that
 * wedges is draws 15248-15253 of demo1: (indexes:verts) = 21:11 66:30 15:7 2388:564 3672:740 456:175.
 *   usage: gl_doom_replay_probe [spec]   spec = comma list of indexes:verts[:vboId] (default the six above; draws with the same vboId share one VBO)
 *   env:   FRAMES=N   repeat the batch N times (VBOs persist, like dhewm3 across frames; default 50)
 *          FINISH_EVERY=N  glFinish after every Nth draw instead of once per batch (default 0 = once per batch)
 *          DEPTH=0  disable depth test (default on, pbuffer has a depth buffer)
 *          TEX=0    no texture (default: white 64x64 bound, GL_TEXTURE_2D enabled)
 *          (to push total resident vertex bytes past the ~4 MB pool: prepend big draws to the spec, e.g. 600:20000:9001,600:20000:9002,...)
 *          PERM=1   random index order (mesh-like reuse, default windowed locality)
 *   DUMPDIR=dir [DLO=n DHI=n]  real-data mode (see load_real): replay dhewm3's dumped draws exactly, with its own matrices.
 * Prints "frame F draw D" (unbuffered) before every draw so a wedge is attributable to its exact draw.  Each batch verifies a
 * readback. Growth steps are controlled by environment switches; see the #214 issue for the ladder of experiments. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <ApplicationServices/ApplicationServices.h>
#define GSD_ISEN(c) glIsEnabled(c)
#define GSD_GETI(p, a) glGetIntegerv(p, a)
#define GSD_GETF(p, a) glGetFloatv(p, a)
#define GSD_GETIV_ATTRIB(i, p, out) glGetVertexAttribivARB(i, p, out)
#define GSD_CLIENTACTIVE(u) glClientActiveTextureARB(GL_TEXTURE0_ARB + (u))
#define GSD_ACTIVETEX(u) glActiveTextureARB(GL_TEXTURE0_ARB + (u))
#define GSD_TEXLEVEL(t, l, p, o) glGetTexLevelParameteriv(t, l, p, o)
#define GSD_TEXPARAM(t, p, o) glGetTexParameteriv(t, p, o)
#define GSD_TEXENV(p, o) glGetTexEnviv(GL_TEXTURE_ENV, p, o)
#include "gl_state_dump.h"

static int W = 256, H = 256;
#define VSZ 60
#define MAXD 4096

static unsigned rng_state = 12345;
static unsigned rnd(void) { rng_state = rng_state * 1664525u + 1013904223u; return rng_state >> 8; }

/* Real-data mode: DUMPDIR=<dir> with dNNNNN.bin files written by the dhewm3 D3DUMP_* trace (see tr_render.cpp in the #214 trace patch):
 * int numIndexes, numVerts; float proj[16], modelview[16]; int viewport[4], depthTest, depthFunc; then numVerts*60 vertex bytes and
 * numIndexes*4 index bytes, all big-endian (PPC host order), exactly what dhewm3 handed to glDrawElements. */
struct RealDraw { int ni, nv; float proj[16], mv[16]; int vp[4], dt, df; unsigned char *verts; GLuint *idx; GLuint vbo; char name[64]; };
static int load_real(const char *dir, int lo, int hi, struct RealDraw *out) {
    int n = 0;
    for (int d = lo; d <= hi; d++) {
        char fn[512]; snprintf(fn, sizeof fn, "%s/d%05d.bin", dir, d);
        FILE *fp = fopen(fn, "rb"); if (!fp) continue;
        struct RealDraw *r = &out[n];
        int hdr[2]; if (fread(hdr, 4, 2, fp) != 2) { fclose(fp); continue; }
        r->ni = hdr[0]; r->nv = hdr[1];
        fread(r->proj, 4, 16, fp); fread(r->mv, 4, 16, fp); fread(r->vp, 4, 4, fp); fread(&r->dt, 4, 1, fp); fread(&r->df, 4, 1, fp);
        r->verts = malloc((size_t)r->nv * VSZ); r->idx = malloc((size_t)r->ni * 4);
        fread(r->verts, VSZ, r->nv, fp); fread(r->idx, 4, r->ni, fp); fclose(fp);
        snprintf(r->name, sizeof r->name, "d%05d", d); n++;
    }
    return n;
}


/* REPLAY=<gllog>: replay Doom 3's logged GL texture/buffer call history (dhewm3 gllog214.cpp, D3GLLOG=path) up to the first DRAWE, with zero-filled data.
   Object names are remapped (GENT/GENB results -> our own generated names). Reproduces the kernel new_texture/delete_texture/page_off history (#214). */
static GLuint *rp_tex = NULL, *rp_buf = NULL; static unsigned rp_ntex = 0, rp_nbuf = 0;
static unsigned long rp_startLine = 0;
static int rp_nr = 0; static unsigned long rp_rlo[64], rp_rhi[64];   /* REPLAY_LINES="a-b,c-d": replay only these log line ranges (must not contain DRAWE lines) */
static unsigned rp_curArr = 0; static long *rp_bsz = NULL; static unsigned rp_nbsz = 0;
static GLuint rp_map(GLuint **tab, unsigned *n, GLuint name, int isbuf) {
    if (name == 0) return 0;
    if (name >= *n) { unsigned nn = name + 4096; *tab = (GLuint *)realloc(*tab, nn * sizeof(GLuint)); memset(*tab + *n, 0, (nn - *n) * sizeof(GLuint)); *n = nn; }
    if (!(*tab)[name]) { GLuint g = 0; if (isbuf) glGenBuffersARB(1, &g); else glGenTextures(1, &g); (*tab)[name] = g; }
    return (*tab)[name];
}

/* REPLAY_REAL="1329,1382,1383" REPLAY_REALDIR=<dir with gllog.txt.state<N>.txt + .idx<N>.bin from dhewm3 D3GL_STATE_AT>: at those glDrawElements indices (1-based over the
   log's DRAWE lines) issue the REAL draw (state, matrices, scissor, index array from the dumps; stencil-shadow draws use Doom's shadow.vp), every other DRAWE is skipped.
   dhewm3 wedges with exactly the draws {1329,1382,1383} issued (everything else dropped): 1329/1383 = stencil shadow volumes (vec4 stride-16 VBO 1022, 2502 idx,
   depth-pass DECR_WRAP, colour/depth writes off, scissor, ARB vertex program), 1382 = fixed-function depth fill (VBO 795 stride 60, 2388 idx, tex 2 DXT1). */
static unsigned rp_drawN = 0; static int rp_realN = 0, rp_realList[64]; static const char *rp_realDir = NULL;
static GLuint rp_shadowVP = 0;
static const char rp_shadowVPsrc[] =
 "!!ARBvp1.0\nTEMP R0;\nSUB R0, vertex.position, program.env[4];\nMAD R0, R0.wwww, program.env[4], R0;\n"
 "DP4 result.position.x, R0, state.matrix.mvp.row[0];\nDP4 result.position.y, R0, state.matrix.mvp.row[1];\n"
 "DP4 result.position.z, R0, state.matrix.mvp.row[2];\nDP4 result.position.w, R0, state.matrix.mvp.row[3];\nEND\n";
static int rp_parseMat(const char *line, const char *key, float *m) {
    size_t kl = strlen(key); if (strncmp(line, key, kl)) return 0; const char *q = line + kl; char *e;
    for (int k = 0; k < 16; k++) { m[k] = (float)strtod(q, &e); q = e; } return 1;
}
static const char *rp_skip = NULL;
#define SK(x) (rp_skip && strstr(rp_skip, x))
static unsigned rp_rnd = 777;
static float rp_frand(void) { rp_rnd = rp_rnd * 1664525u + 1013904223u; return (float)((rp_rnd >> 8) & 0xffff) / 65536.f; }
static void rp_real_draw(int n) {
    char fn[1024]; float mv[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, pr[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}; int sc[4] = { 0, 0, 1024, 768 };
    snprintf(fn, sizeof fn, "%s/gllog.txt.state%d.txt", rp_realDir, n);
    FILE *f = fopen(fn, "r"); if (!f) { fprintf(stderr, "FAIL open %s\n", fn); exit(1); }
    char l[2048]; while (fgets(l, sizeof l, f)) { rp_parseMat(l, "MODELVIEW", mv); rp_parseMat(l, "PROJECTION", pr); if (!strncmp(l, "GL_SCISSOR_BOX", 14)) sscanf(l + 14, "%d %d %d %d", sc, sc + 1, sc + 2, sc + 3); }
    fclose(f);
    snprintf(fn, sizeof fn, "%s/gllog.txt.idx%d.bin", rp_realDir, n);
    f = fopen(fn, "rb"); if (!f) { fprintf(stderr, "FAIL open %s\n", fn); exit(1); }
    fseek(f, 0, SEEK_END); long isz = ftell(f); fseek(f, 0, SEEK_SET); unsigned *idx = (unsigned *)malloc(isz); if (fread(idx, 1, isz, f) != (size_t)isz) { fprintf(stderr, "short idx\n"); exit(1); } fclose(f);
    int cnt = (int)(isz / 4); unsigned mx = 0; for (int k = 0; k < cnt; k++) if (idx[k] > mx) mx = idx[k];
    int shadow = (n != 1382);
    GLuint vbo = rp_map(&rp_buf, &rp_nbuf, shadow ? 1022 : 795, 1);
    if (rp_nr && getenv("REPLAY_INIT")) {   /* ranged replay: make sure the objects the real draws use have storage even if their defining log lines are outside the ranges */
        unsigned nm = shadow ? 1022 : 795; long need = shadow ? 41600 : 33840;
        if (nm >= rp_nbsz || rp_bsz[nm] < need) { glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo); glBufferDataARB(GL_ARRAY_BUFFER_ARB, need, NULL, GL_STATIC_DRAW_ARB);
            if (nm >= rp_nbsz) { unsigned nn = nm + 4096; rp_bsz = (long *)realloc(rp_bsz, nn * sizeof(long)); memset(rp_bsz + rp_nbsz, 0, (nn - rp_nbsz) * sizeof(long)); rp_nbsz = nn; } rp_bsz[nm] = need; }
        static int t2done = 0; if (!shadow && !t2done) { t2done = 1; static unsigned char junk[256]; GLuint t2 = rp_map(&rp_tex, &rp_ntex, 2, 0); glActiveTextureARB(GL_TEXTURE0_ARB); glBindTexture(GL_TEXTURE_2D, t2);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            for (int lvl = 0, w = 16; w >= 1; lvl++, w /= 2) glCompressedTexImage2DARB(GL_TEXTURE_2D, lvl, 0x83f0, w, w, 0, ((w + 3) / 4) * ((w + 3) / 4) * 8, junk); }
    }
    glMatrixMode(GL_PROJECTION); glLoadMatrixf(pr); glMatrixMode(GL_MODELVIEW); glLoadMatrixf(mv);
    glViewport(0, 0, 1024, 768); if (SK("noscissor")) glDisable(GL_SCISSOR_TEST); else { glEnable(GL_SCISSOR_TEST); glScissor(sc[0], sc[1], sc[2], sc[3]); }
    glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LEQUAL); glEnable(GL_BLEND); glBlendFunc(GL_ONE, GL_ZERO); glDisable(GL_ALPHA_TEST);
    if (SK("nostencil")) glDisable(GL_STENCIL_TEST); else glEnable(GL_STENCIL_TEST); glStencilFunc(GL_ALWAYS, 1, 255); glStencilMask(255); glColor4f(0.f, 0.f, 0.f, 1.f);
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
    if (shadow) {   /* vec4 stride 16: near/far pair per vertex (w=1 / w=0) */
        float *v = (float *)malloc((mx + 1) * 16); for (unsigned k = 0; k <= mx; k++) { unsigned b = k & ~1u; srand(b); v[k*4+0] = 889.f + 300.f * (((b*2654435761u)>>8 & 0xffff)/65536.f - .5f); v[k*4+1] = 208.f + 300.f * (((b*40503u+7)*2654435761u>>8 & 0xffff)/65536.f - .5f); v[k*4+2] = -656.f + 300.f * (((b*9973u+3)*2654435761u>>8 & 0xffff)/65536.f - .5f); v[k*4+3] = (k & 1) ? 0.f : 1.f; }
        glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, (mx + 1) * 16, v); free(v);
        if (!rp_shadowVP) { glGenProgramsARB(1, &rp_shadowVP); glBindProgramARB(GL_VERTEX_PROGRAM_ARB, rp_shadowVP);
            glProgramStringARB(GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)strlen(rp_shadowVPsrc), rp_shadowVPsrc);
            GLint ep = -1; glGetIntegerv(GL_PROGRAM_ERROR_POSITION_ARB, &ep); if (ep != -1) { fprintf(stderr, "FAIL shadow.vp error pos %d: %s\n", ep, (const char *)glGetString(GL_PROGRAM_ERROR_STRING_ARB)); exit(1); } }
        if (SK("novp")) glDisable(GL_VERTEX_PROGRAM_ARB); else { glBindProgramARB(GL_VERTEX_PROGRAM_ARB, rp_shadowVP); glEnable(GL_VERTEX_PROGRAM_ARB);
        glProgramEnvParameter4fARB(GL_VERTEX_PROGRAM_ARB, 4, 880.f, 200.f, -600.f, 0.f); }
        glDepthMask(GL_FALSE); glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); glDisable(GL_CULL_FACE);
        if (SK("nooffset")) glDisable(GL_POLYGON_OFFSET_FILL); else { glEnable(GL_POLYGON_OFFSET_FILL); glPolygonOffset(0.f, 1.f); }
        glStencilOp(GL_KEEP, GL_KEEP, SK("keepop") ? GL_KEEP : 0x8508 /* DECR_WRAP */);
        glActiveTextureARB(GL_TEXTURE0); glDisable(GL_TEXTURE_2D); glClientActiveTextureARB(GL_TEXTURE0);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY); glDisableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY); glVertexPointer(4, GL_FLOAT, 16, (const void *)0);
    } else {
        float *v = (float *)malloc((mx + 1) * 60); for (unsigned k = 0; k <= mx; k++) { float *d = v + k * 15; for (int j = 0; j < 15; j++) d[j] = 0.f;
            d[0] = 889.f + 150.f * (rp_frand() - .5f); d[1] = 208.f + 150.f * (rp_frand() - .5f); d[2] = -656.f + 150.f * (rp_frand() - .5f); d[3] = rp_frand(); d[4] = rp_frand(); }
        glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, (mx + 1) * 60, v); free(v);
        glDisable(GL_VERTEX_PROGRAM_ARB);
        glDepthMask(GL_TRUE); glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); glEnable(GL_CULL_FACE); glCullFace(GL_FRONT); glDisable(GL_POLYGON_OFFSET_FILL);
        glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
        glActiveTextureARB(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D, rp_map(&rp_tex, &rp_ntex, 2, 0)); glEnable(GL_TEXTURE_2D); glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glClientActiveTextureARB(GL_TEXTURE0); glEnableClientState(GL_TEXTURE_COORD_ARRAY); glTexCoordPointer(2, GL_FLOAT, 60, (const void *)12); glDisableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY); glVertexPointer(3, GL_FLOAT, 60, (const void *)0);
    }
    printf("REAL draw #%d: %s count=%d maxidx=%u scissor=%d,%d,%d,%d\n", n, shadow ? "shadow" : "depthfill", cnt, mx, sc[0], sc[1], sc[2], sc[3]);
    glDrawElements(GL_TRIANGLES, cnt, GL_UNSIGNED_INT, idx);
    free(idx);
}
static void replay_gllog(const char *path) {
    FILE *f = fopen(path, "r"); if (!f) { fprintf(stderr, "FAIL open %s\n", path); exit(1); }
    if (getenv("REPLAY_LINES")) { const char *e = getenv("REPLAY_LINES"); while (*e && rp_nr < 64) { char *q; rp_rlo[rp_nr] = strtoul(e, &q, 10); e = q; if (*e == '-') { e++; rp_rhi[rp_nr] = strtoul(e, &q, 10); e = q; } else rp_rhi[rp_nr] = rp_rlo[rp_nr]; rp_nr++; if (*e == ',') e++; } }
    if (getenv("REPLAY_REAL") && getenv("REPLAY_REALDIR")) { rp_realDir = getenv("REPLAY_REALDIR"); const char *e = getenv("REPLAY_REAL"); while (*e && rp_realN < 64) { rp_realList[rp_realN++] = atoi(e); while (*e && *e != ',') e++; if (*e == ',') e++; } }
    size_t zsz = 64u << 20; unsigned char *zero = (unsigned char *)calloc(zsz, 1);
    if (getenv("REPLAY_FILL")) { const char *m = getenv("REPLAY_FILL"); unsigned r = 12345; for (size_t k = 0; k < zsz; k++) { r = r * 1664525u + 1013904223u; zero[k] = !strcmp(m, "ff") ? 0xff : (unsigned char)(r >> 16); } }
    char line[4096]; unsigned long ln = 0, ntexi = 0, nbd = 0, ndummy = 0;
    unsigned long stopLine = getenv("REPLAY_STOP") ? strtoul(getenv("REPLAY_STOP"), NULL, 0) : 0; int dummyDraws = getenv("REPLAY_DRAWS") != NULL;
    while (fgets(line, sizeof line, f)) {
        ln++;
        if (ln < rp_startLine) continue;
        if (rp_realN && !strncmp(line, "DRAWE ", 6)) {   /* count every logged draw (range or not); issue the REAL ones, skip the rest */
            rp_drawN++;
            for (int k = 0; k < rp_realN; k++) if ((int)rp_drawN == rp_realList[k]) { rp_real_draw((int)rp_drawN); if (getenv("REPLAY_FINISH_AFTER") && (int)rp_drawN == atoi(getenv("REPLAY_FINISH_AFTER"))) glFinish(); if (getenv("REPLAY_FLUSH_AFTER") && (int)rp_drawN == atoi(getenv("REPLAY_FLUSH_AFTER"))) glFlush(); if (k == rp_realN - 1) { printf("replay: last REAL draw done at log line %lu\n", ln); goto replay_done; } }
            continue;
        }
        if (rp_nr) { int in = 0; for (int k = 0; k < rp_nr; k++) if (ln >= rp_rlo[k] && ln <= rp_rhi[k]) in = 1; if (!in) { if (ln > rp_rhi[rp_nr - 1] && ln > rp_rlo[rp_nr - 1]) { int mx = 0; for (int k = 0; k < rp_nr; k++) if (rp_rhi[k] > (unsigned long)mx) mx = (int)rp_rhi[k]; if (ln > (unsigned long)mx) break; } continue; } }
        char op[32]; unsigned a, b, c, d, e, g, h, i2; int x, y, w, hh, bd, pn; long l1, l2; double fv;
        if (sscanf(line, "%31s", op) != 1 || op[0] == '#') continue;
        if (rp_nr && !strcmp(op, "DRAWE")) continue;   /* ranged replay: draws are skipped (MIN_REAL issues its own) */
        if (!strcmp(op, "DRAWE") && rp_startLine) { printf("replay tail: stop at DRAWE line %lu\n", ln); break; }
        if (!strcmp(op, "DRAWE")) {
            if (stopLine && ln >= stopLine) { printf("replay: stop at DRAWE line %lu: %lu TexImage-class calls, %lu BufferData calls, %lu dummy draws\n", ln, ntexi, nbd, ndummy); break; }
            if (!stopLine) { printf("replay: stop at first DRAWE (line %lu): %lu TexImage-class calls, %lu BufferData calls\n", ln, ntexi, nbd); break; }
            if (dummyDraws) {   /* REPLAY_DRAWS=1: tiny draw from the currently bound VBO (if any) with unit0 2D texturing, so VBOs/textures become resident like the real draws made them */
                static float tri[] = { 0.f,0.f,0.f, 0.1f,0.f,0.f, 0.f,0.1f,0.f };
                glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);
                glEnableClientState(GL_VERTEX_ARRAY);
                if (rp_curArr && rp_curArr < rp_nbsz && rp_bsz[rp_curArr] >= 48) { glBindBufferARB(GL_ARRAY_BUFFER_ARB, rp_map(&rp_buf, &rp_nbuf, rp_curArr, 1)); glVertexPointer(3, GL_FLOAT, 0, (const void *)0); }
                else { glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0); glVertexPointer(3, GL_FLOAT, 0, tri); }
                glActiveTextureARB(GL_TEXTURE0); glEnable(GL_TEXTURE_2D);
                glDrawArrays(GL_TRIANGLES, 0, 3); ndummy++;
                glBindBufferARB(GL_ARRAY_BUFFER_ARB, rp_curArr ? rp_map(&rp_buf, &rp_nbuf, rp_curArr, 1) : 0);
            }
            continue;
        }
        else if (!strcmp(op, "TI2D")) { int lvl, ifmt, p; unsigned t, fm, ty; if (sscanf(line, "%*s %u %d %d %d %d %d %u %u %d", &t, &lvl, &ifmt, &w, &hh, &bd, &fm, &ty, &p) == 9) { glTexImage2D(t, lvl, ifmt, w, hh, bd, fm, ty, p ? zero : NULL); ntexi++; } }
        else if (!strcmp(op, "TSI2D")) { int lvl; unsigned t, fm, ty; int xo, yo; if (sscanf(line, "%*s %u %d %d %d %d %d %u %u", &t, &lvl, &xo, &yo, &w, &hh, &fm, &ty) == 8) glTexSubImage2D(t, lvl, xo, yo, w, hh, fm, ty, zero); }
        else if (!strcmp(op, "CTI2D")) { int lvl; unsigned t, ifm; int cx, cy; if (sscanf(line, "%*s %u %d %u %d %d %d %d %d", &t, &lvl, &ifm, &cx, &cy, &w, &hh, &bd) == 8) { glCopyTexImage2D(t, lvl, ifm, cx, cy, w, hh, bd); ntexi++; } }
        else if (!strcmp(op, "CTSI2D")) { int lvl, xo, yo, cx, cy; unsigned t; if (sscanf(line, "%*s %u %d %d %d %d %d %d %d", &t, &lvl, &xo, &yo, &cx, &cy, &w, &hh) == 8) glCopyTexSubImage2D(t, lvl, xo, yo, cx, cy, w, hh); }
        else if (!strcmp(op, "CTEX2D")) { int lvl, sz, p; unsigned t, ifm; if (sscanf(line, "%*s %u %d %u %d %d %d %d %d", &t, &lvl, &ifm, &w, &hh, &bd, &sz, &p) == 8) { glCompressedTexImage2DARB(t, lvl, ifm, w, hh, bd, sz, p ? zero : NULL); ntexi++; } }
        else if (!strcmp(op, "BT")) { if (sscanf(line, "%*s %u %u", &a, &b) == 2) glBindTexture(a, rp_map(&rp_tex, &rp_ntex, b, 0)); }
        else if (!strcmp(op, "GENT") || !strcmp(op, "GENB")) {
            int isb = op[3] == 'B'; char *q = line + 4; int n = (int)strtol(q, &q, 10);
            for (int k = 0; k < n; k++) { unsigned nm = (unsigned)strtoul(q, &q, 10); (void)rp_map(isb ? &rp_buf : &rp_tex, isb ? &rp_nbuf : &rp_ntex, nm, isb); }
        }
        else if (!strcmp(op, "DELT") || !strcmp(op, "DELB")) {
            int isb = op[3] == 'B'; char *q = line + 4; int n = (int)strtol(q, &q, 10);
            for (int k = 0; k < n; k++) { unsigned nm = (unsigned)strtoul(q, &q, 10); GLuint **tab = isb ? &rp_buf : &rp_tex; unsigned *tn = isb ? &rp_nbuf : &rp_ntex;
                if (nm && nm < *tn && (*tab)[nm]) { GLuint g = (*tab)[nm]; if (isb) glDeleteBuffersARB(1, &g); else glDeleteTextures(1, &g); (*tab)[nm] = 0; } }
        }
        else if (!strcmp(op, "TPI")) { if (sscanf(line, "%*s %u %u %d", &a, &b, &pn) == 3) glTexParameteri(a, b, pn); }
        else if (!strcmp(op, "TPF")) { if (sscanf(line, "%*s %u %u %lf", &a, &b, &fv) == 3) glTexParameterf(a, b, (float)fv); }
        else if (!strcmp(op, "BB")) { if (sscanf(line, "%*s %u %u", &a, &b) == 2) { glBindBufferARB(a, rp_map(&rp_buf, &rp_nbuf, b, 1)); if (a == 34962) rp_curArr = b; } }
        else if (!strcmp(op, "BD")) { int p; unsigned t, u; if (sscanf(line, "%*s %u %ld %u %d", &t, &l1, &u, &p) == 4) {
            unsigned char *src = zero; if ((size_t)l1 > zsz) src = (unsigned char *)calloc((size_t)l1, 1);
            glBufferDataARB(t, l1, p ? src : NULL, u); if (src != zero) free(src); nbd++;
            if (t == 34962 && rp_curArr) { if (rp_curArr >= rp_nbsz) { unsigned nn = rp_curArr + 4096; rp_bsz = (long *)realloc(rp_bsz, nn * sizeof(long)); memset(rp_bsz + rp_nbsz, 0, (nn - rp_nbsz) * sizeof(long)); rp_nbsz = nn; } rp_bsz[rp_curArr] = l1; } } }
        else if (!strcmp(op, "BSD")) { unsigned t; if (sscanf(line, "%*s %u %ld %ld", &t, &l1, &l2) == 3 && (size_t)l2 <= zsz) glBufferSubDataARB(t, l1, l2, zero); }
        else if (!strcmp(op, "AT")) { if (sscanf(line, "%*s %u", &a) == 1) glActiveTextureARB(a); }
        else if (!strcmp(op, "CAT")) { if (sscanf(line, "%*s %u", &a) == 1) glClientActiveTextureARB(a); }
        else if (!strcmp(op, "CLEAR")) { if (sscanf(line, "%*s %u", &a) == 1) glClear(a); }
        else if (!strcmp(op, "FINISH")) { glFinish(); }
        else if (!strcmp(op, "SWAP")) { /* no swap in pbuffer; fullscreen path flips below if needed */ if (getenv("REPLAY_SWAP")) { if (getenv("WINDOWED")) { gl_window_flush(); gl_window_pump(); } else CGLFlushDrawable(CGLGetCurrentContext()); } }
        (void)b; (void)c; (void)d; (void)e; (void)g; (void)h; (void)i2; (void)x; (void)y;
    }
replay_done:
    fclose(f); free(zero);
    if (rp_nr) { glFinish(); return; }
    if (rp_startLine) return;   /* tail replay: leave state as Doom left it, no finish */
    glBindTexture(GL_TEXTURE_2D, 0); glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0); glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0); glActiveTextureARB(GL_TEXTURE0); glClientActiveTextureARB(GL_TEXTURE0);
    glFinish();
}


/* MIN_REAL=1 (+REPLAY_REALDIR, optional MIN_SKIP=comma flags): no log replay -- create just the objects the 3 wedge draws touch and issue them in Doom's order:
   shadow #1329, depth-fill #1382, glCopyTexSubImage2D(depth tex 23, 1024x768) + glClear(STENCIL), shadow #1383, glFinish.  MIN_SKIP flags (each removes one ingredient):
   no1329 no1382 nocopy noclear notex23 novp noscissor nooffset keepop nostencil nodepthtex(tex23 left RGBA 16x16) */
static void min_repro(void) {
    rp_realDir = getenv("REPLAY_REALDIR"); rp_skip = getenv("MIN_SKIP");
    GLuint b = rp_map(&rp_buf, &rp_nbuf, 1022, 1); glBindBufferARB(GL_ARRAY_BUFFER_ARB, b); glBufferDataARB(GL_ARRAY_BUFFER_ARB, 41600, NULL, GL_STATIC_DRAW_ARB);
    b = rp_map(&rp_buf, &rp_nbuf, 795, 1); glBindBufferARB(GL_ARRAY_BUFFER_ARB, b); glBufferDataARB(GL_ARRAY_BUFFER_ARB, 33840, NULL, GL_STATIC_DRAW_ARB);
    static unsigned char junk[4096]; for (unsigned k = 0; k < sizeof junk; k++) junk[k] = (unsigned char)(k * 7);
    glActiveTextureARB(GL_TEXTURE0_ARB);
    GLuint t2 = rp_map(&rp_tex, &rp_ntex, 2, 0); glBindTexture(GL_TEXTURE_2D, t2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    for (int lvl = 0, w = 16; w >= 1; lvl++, w /= 2) glCompressedTexImage2DARB(GL_TEXTURE_2D, lvl, 0x83f0, w, w, 0, ((w + 3) / 4) * ((w + 3) / 4) * 8, junk);
    GLuint t23 = rp_map(&rp_tex, &rp_ntex, 23, 0); glBindTexture(GL_TEXTURE_2D, t23);
    if (SK("nodepthtex")) glTexImage2D(GL_TEXTURE_2D, 0, 0x8058, 1024, 1024, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    else glTexImage2D(GL_TEXTURE_2D, 0, 0x81a6, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812f); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812f);
    glClearColor(0, 0, 0, 1); glClearStencil(0); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    if (!SK("no1329")) rp_real_draw(1329);
    if (!SK("no1382")) rp_real_draw(1382);
    glActiveTextureARB(GL_TEXTURE0_ARB); if (!SK("notex23")) glBindTexture(GL_TEXTURE_2D, t23);
    if (!SK("nocopy")) glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, 1024, 768);
    if (!SK("noclear")) { glDisable(GL_SCISSOR_TEST); glDepthMask(GL_TRUE); glColorMask(1, 1, 1, 1); glClear(GL_STENCIL_BUFFER_BIT); }
    rp_real_draw(1383);
    glFinish();
}

extern void *gl_window_make_ctx(int w, int h);
extern void gl_window_pump(void);
extern void gl_window_flush(void);
int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    if (getenv("REPLAY_REAL") || getenv("MIN_REAL")) { W = 1024; H = 768; }
    const char *spec = argc > 1 ? argv[1] : "21:11,66:30,15:7,2388:564,3672:740,456:175";
    int nidx[MAXD], nvert[MAXD], nkey[MAXD], nd = 0;
    { char *s = strdup(spec), *tok = strtok(s, ",");
      while (tok && nd < MAXD) { nidx[nd] = atoi(tok); char *c = strchr(tok, ':'); nvert[nd] = c ? atoi(c + 1) : nidx[nd] / 2;
        char *c2 = c ? strchr(c + 1, ':') : NULL; nkey[nd] = c2 ? atoi(c2 + 1) : nd; nd++; tok = strtok(NULL, ","); } }
    int frames = getenv("FRAMES") ? atoi(getenv("FRAMES")) : 50;
    int finishEvery = getenv("FINISH_EVERY") ? atoi(getenv("FINISH_EVERY")) : 0;
    int depth = getenv("DEPTH") ? atoi(getenv("DEPTH")) : 1;
    int tex = getenv("TEX") ? atoi(getenv("TEX")) : 1;
    int perm = getenv("PERM") != NULL;
    /* CLIP=S: Doom-like perspective camera (glFrustum near 4 far 8000) and vertex positions spread over +-S world units around/behind
       the eye, so many triangles straddle the near plane / frustum and need CLIPPING (dhewm3 draws world-space geometry through the
       view projection; the earlier rungs used identity matrices with every vertex inside the view volume). */
    float clipS = getenv("CLIP") ? (float)atof(getenv("CLIP")) : 0.f;
    int respec = getenv("RESPEC") ? atoi(getenv("RESPEC")) : 0;   /* RESPEC=P: each frame, P% of draws re-specify their VBO name with new glBufferData (dhewm3 reuses freed vertex-cache VBO names) */
    int respecSize = getenv("RESPEC_SIZE") != NULL;
    /* CHURN=P: P% of draws behave like dhewm3 dynamic/re-created surfaces: every frame they take a VBO NAME from a LIFO free list
       (names previously used by OTHER surfaces, freed at end of frame), glBufferData(STATIC_DRAW) their data into it, draw, and free it
       at end of frame without a glFinish (idVertexCache::Alloc / ActuallyFree behaviour; the trace shows the same surface drawn with a
       different vbo id each frame).  CHURN_POOL=N extra pre-created names (default 64). */
    int churn = getenv("CHURN") ? atoi(getenv("CHURN")) : 0;
    int poolN = getenv("CHURN_POOL") ? atoi(getenv("CHURN_POOL")) : 64;
    GLuint freeList[MAXD * 2]; int nfree = 0;

    const char *dumpdir = getenv("DUMPDIR");
    static struct RealDraw real[MAXD]; int nreal = 0;
    if (dumpdir) {
        nreal = load_real(dumpdir, getenv("DLO") ? atoi(getenv("DLO")) : 0, getenv("DHI") ? atoi(getenv("DHI")) : 99999, real);
        if (!nreal) { fprintf(stderr, "no dump files in %s\n", dumpdir); return 1; }
        W = real[0].vp[2]; H = real[0].vp[3]; if (W < 16 || H < 16 || W > 2048 || H > 2048) { W = 1024; H = 768; }
        printf("loaded %d real draws from %s, viewport %dx%d\n", nreal, dumpdir, W, H);
    }
    int fullscreen = getenv("FULLSCREEN") != NULL;   /* FULLSCREEN=1: capture the main display, fullscreen double-buffered CGL context, CGLFlushDrawable each frame
                                                         (dhewm3 r_fullscreen 1 + swapInterval 0; must be launched from the Aqua session, e.g. Terminal .command) */
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLContextObj ctx = NULL; CGLPBufferObj pbuf = NULL;
    int windowed = getenv("WINDOWED") != NULL;   /* WINDOWED=1: on-screen NSWindow+NSOpenGLContext (like SDL r_fullscreen 0), composited by WindowServer; needs the Aqua session */
    if (windowed) {
        ctx = (CGLContextObj)gl_window_make_ctx(W, H);
        if (!ctx) { fprintf(stderr, "FAIL window ctx\n"); return 1; }
        CGLSetCurrentContext(ctx);
        printf("windowed %dx%d\n", W, H);
    } else
    if (fullscreen) {
        CGDirectDisplayID dsp = CGMainDisplayID();
        CGDisplayCapture(dsp);
        if (getenv("MODE")) {   /* MODE=WxH: switch the captured display to that mode like Doom (SDL, r_mode -1 1024x768) does on the 4K desktop */
            int mw = 1024, mh = 768; sscanf(getenv("MODE"), "%dx%d", &mw, &mh);
            boolean_t exact = 0; CFDictionaryRef md = CGDisplayBestModeForParameters(dsp, 32, mw, mh, &exact);
            if (!md || !exact) { fprintf(stderr, "FAIL no exact %dx%d mode\n", mw, mh); return 1; }
            if (CGDisplaySwitchToMode(dsp, md) != kCGErrorSuccess) { fprintf(stderr, "FAIL SwitchToMode\n"); return 1; }
        }
        W = (int)CGDisplayPixelsWide(dsp); H = (int)CGDisplayPixelsHigh(dsp);
        CGLPixelFormatAttribute fa[] = { kCGLPFAFullScreen, kCGLPFADoubleBuffer, kCGLPFAAccelerated, kCGLPFAColorSize, (CGLPixelFormatAttribute)32,
                                         kCGLPFADepthSize, (CGLPixelFormatAttribute)24, kCGLPFAStencilSize, (CGLPixelFormatAttribute)8,
                                         kCGLPFADisplayMask, (CGLPixelFormatAttribute)CGDisplayIDToOpenGLDisplayMask(dsp), (CGLPixelFormatAttribute)0 };
        if (CGLChoosePixelFormat(fa, &pf, &npix) || !npix || !pf) { fprintf(stderr, "FAIL fullscreen ChoosePixelFormat\n"); return 1; }
        if (CGLCreateContext(pf, NULL, &ctx)) { fprintf(stderr, "FAIL CreateContext\n"); return 1; }
        CGLDestroyPixelFormat(pf);
        CGLSetCurrentContext(ctx);
        if (CGLSetFullScreen(ctx)) { fprintf(stderr, "FAIL SetFullScreen\n"); return 1; }
        GLint zero = 0; CGLSetParameter(ctx, kCGLCPSwapInterval, &zero);
        printf("fullscreen %dx%d\n", W, H);
    } else {
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, (CGLPixelFormatAttribute)32,
                                        kCGLPFADepthSize, (CGLPixelFormatAttribute)24, kCGLPFAStencilSize, (CGLPixelFormatAttribute)8, (CGLPixelFormatAttribute)0 };
    if (CGLChoosePixelFormat(attrs, &pf, &npix) || !npix || !pf) { fprintf(stderr, "FAIL ChoosePixelFormat\n"); return 1; }
    if (CGLCreateContext(pf, NULL, &ctx)) { fprintf(stderr, "FAIL CreateContext\n"); return 1; }
    CGLDestroyPixelFormat(pf);
    if (CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf)) { fprintf(stderr, "FAIL CreatePBuffer\n"); return 1; }
    CGLSetCurrentContext(ctx); CGLSetPBuffer(ctx, pbuf, 0, 0, 0);
    }
    if (getenv("MIN_REAL")) { if (getenv("REPLAY") && getenv("REPLAY_LINES")) replay_gllog(getenv("REPLAY")); min_repro(); printf("min repro complete: glFinish returned (GL error 0x%x)\n", glGetError()); return 0; }
    if (getenv("REPLAY")) replay_gllog(getenv("REPLAY"));
    if (getenv("REPLAY") && getenv("REPLAY_REAL")) { printf("real replay complete: glFinish returned (GL error 0x%x)\n", glGetError()); if (windowed) gl_window_flush(); return 0; }
    if (getenv("IDLE_SECS")) { int n = atoi(getenv("IDLE_SECS")); printf("idling %d s (kernel GART collector / command-buffer reclaim)\n", n); fflush(stdout); for (int i = 0; i < n; i++) { sleep(1); if (windowed) gl_window_pump(); } }
    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    if (clipS > 0.f) glFrustum(-4.0, 4.0, -4.0, 4.0, 4.0, 8000.0);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    if (depth) { glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LESS); } else glDisable(GL_DEPTH_TEST);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glColor4f(0.f, 0.f, 0.f, 1.f);
    if (tex) {
        static unsigned char texels[64 * 64 * 4]; memset(texels, 255, sizeof texels);
        GLuint t; glGenTextures(1, &t); glBindTexture(GL_TEXTURE_2D, t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, texels);
        glEnable(GL_TEXTURE_2D);
    }

    /* TEXSTATE=1: replicate the texture objects Doom has bound at the wedge draw (state_15251 of the single-draw run): unit0 2D 16x16 DXT1 (enabled) +
       CUBE 64x64 DXT1, unit1 2D 64x64 DXT5, unit2 64x64 DXT1, unit3 128x128 DXT1 clamp, unit4 128x128 DXT1, unit5 64x64 DXT1, unit6 2D 256x1 INTENSITY8;
       all LINEAR_MIPMAP_LINEAR/LINEAR (unit6 LINEAR/LINEAR), texenv MODULATE, only unit0 GL_TEXTURE_2D enabled. */
    GLuint ts_id[16]; int ts_unit[16], ts_cube[16], nts = 0;
    if (getenv("TEXSTATE")) {
        struct { int unit, cube, w, h, ifmt, wrap, nomip; } T[] = {
            { 0, 0, 16, 16, 0x83f0, GL_REPEAT, 0 }, { 0, 1, 64, 64, 0x83f0, 0x812f, 0 }, { 1, 0, 64, 64, 0x83f3, GL_REPEAT, 0 },
            { 2, 0, 64, 64, 0x83f1, GL_REPEAT, 0 }, { 3, 0, 128, 128, 0x83f1, 0x812f, 0 }, { 4, 0, 128, 128, 0x83f1, GL_REPEAT, 0 },
            { 5, 0, 64, 64, 0x83f1, GL_REPEAT, 0 }, { 6, 0, 256, 1, 0x804b, 0x812f, 1 } };
        static unsigned char junk[512 * 1024]; for (unsigned k = 0; k < sizeof junk; k++) junk[k] = (unsigned char)rnd();
        for (unsigned ti = 0; ti < sizeof T / sizeof T[0]; ti++) {
            glActiveTextureARB(GL_TEXTURE0_ARB + T[ti].unit);
            GLuint id; glGenTextures(1, &id); ts_id[ti] = id; ts_unit[ti] = T[ti].unit; ts_cube[ti] = T[ti].cube; nts = ti + 1;
            GLenum tgt = T[ti].cube ? GL_TEXTURE_CUBE_MAP_ARB : GL_TEXTURE_2D;
            glBindTexture(tgt, id);
            glTexParameteri(tgt, GL_TEXTURE_MIN_FILTER, T[ti].nomip ? GL_LINEAR : GL_LINEAR_MIPMAP_LINEAR); glTexParameteri(tgt, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(tgt, GL_TEXTURE_WRAP_S, T[ti].wrap); glTexParameteri(tgt, GL_TEXTURE_WRAP_T, T[ti].wrap);
            int faces = T[ti].cube ? 6 : 1;
            for (int fc = 0; fc < faces; fc++) {
                GLenum ft = T[ti].cube ? (GLenum)(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB + fc) : GL_TEXTURE_2D;
                int w = T[ti].w, h = T[ti].h;
                for (int lvl = 0; ; lvl++) {
                    if (T[ti].ifmt == 0x804b) glTexImage2D(ft, lvl, 0x804b, w, h, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, junk);
                    else { int bs = (T[ti].ifmt == 0x83f0 || T[ti].ifmt == 0x83f1) ? 8 : 16; int sz = ((w + 3) / 4) * ((h + 3) / 4) * bs;
                           glCompressedTexImage2DARB(ft, lvl, T[ti].ifmt, w, h, 0, sz, junk); }
                    if (T[ti].nomip || (w == 1 && h == 1)) break;
                    w = w > 1 ? w / 2 : 1; h = h > 1 ? h / 2 : 1;
                }
            }
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        }
        glActiveTextureARB(GL_TEXTURE0_ARB); glEnable(GL_TEXTURE_2D);
        printf("TEXSTATE: bound Doom's 8 textures\n");
    }
    /* DS=bitmask of Doom render state (from the gl_state_dump diff at the wedge draw): 1 GL_BLEND, 2 GL_CULL_FACE front, 4 SCISSOR (viewport box),
       8 STENCIL_TEST ref 1 mask 255, 16 polygon offset units -600 (enabled), 32 stale disabled colour/normal pointers still bound to another VBO,
       64 alpha func LESS ref 0.5 (test off).  DS=127 = all. */
    int ds = getenv("DS") ? (int)strtol(getenv("DS"), NULL, 0) : 0;
    if (ds & 1) { glEnable(GL_BLEND); glBlendFunc(GL_ONE, GL_ZERO); glBlendEquation(GL_FUNC_ADD); }
    /* BLENDFN=stale: reproduce Doom's hardware BLENDCNTL 0x2726000e (SRC_ALPHA,ONE_MINUS_SRC_ALPHA, read-enable) while the GL state says ONE,ZERO + GL_BLEND enabled:
       draw something with alpha blending first, then switch to ONE,ZERO without disabling blend.  BLENDFN=alpha: leave alpha blending on for the real draw. */
    if (getenv("BLENDFN") && !strcmp(getenv("BLENDFN"), "alpha")) { glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); }   /* Doom: explicit ONE,ZERO + FUNC_ADD */
    if (ds & 2) { glEnable(GL_CULL_FACE); glCullFace(GL_FRONT); }
    if (ds & 4) { glEnable(GL_SCISSOR_TEST); glScissor(0, 0, W, H); }
    if (ds & 8) { glEnable(GL_STENCIL_TEST); glStencilFunc(GL_ALWAYS, 1, 255); glStencilMask(255); }
    if (ds & 16) { glPolygonOffset(0.f, -600.f); }   /* state_15251: offset units -600 stored but GL_POLYGON_OFFSET_FILL is DISABLED */
    if (ds & 256) glEnable(GL_POLYGON_OFFSET_FILL);
    if (ds & 64) glAlphaFunc(GL_GREATER, 0.5f);   /* state_15251: ALPHA_TEST_FUNC 516 = GREATER ref 0.5 (test disabled) */
    if (dumpdir) {   /* ---- real-data replay: exact vertices/indices/matrices as dhewm3 issued them ---- */
        glDepthFunc(real[0].df ? real[0].df : GL_LESS);
        for (int d = 0; d < nreal; d++) {
            glGenBuffersARB(1, &real[d].vbo); glBindBufferARB(GL_ARRAY_BUFFER_ARB, real[d].vbo);
            glBufferDataARB(GL_ARRAY_BUFFER_ARB, (GLsizeiptrARB)((size_t)real[d].nv * VSZ), real[d].verts, GL_STATIC_DRAW_ARB);
        }
        int rbad = 0;
        /* REUPLOAD=N: draws with >= N vertices are dhewm3 DYNAMIC surfaces (the trace shows the 740-vertex model gets a new recycled vbo id every
           frame): each frame take a VBO name from a LIFO free list, glBufferData(STATIC_DRAW) the real vertices into it, draw it, free it at end
           of frame without a glFinish (idVertexCache::Alloc / ActuallyFree).  REUPLOAD_POOL=M names pre-created with other-sized data. */
        int reup = getenv("REUPLOAD") ? atoi(getenv("REUPLOAD")) : 0, rpool = getenv("REUPLOAD_POOL") ? atoi(getenv("REUPLOAD_POOL")) : 16;
        GLuint rfree[256]; int nrfree = 0; GLuint rused[MAXD]; memset(rused, 0, sizeof rused);
        if (reup) for (int i = 0; i < rpool && i < 250; i++) { GLuint n; glGenBuffersARB(1, &n); glBindBufferARB(GL_ARRAY_BUFFER_ARB, n);
            glBufferDataARB(GL_ARRAY_BUFFER_ARB, 1000 + (rnd() % 60000), NULL, GL_STATIC_DRAW_ARB); rfree[nrfree++] = n; }
        /* INTSTATE=1: after each frame's real depth-fill draws, apply the state Doom has at the NEXT draw (state_15254: interaction pass setup) WITHOUT drawing:
           ARB vertex+fragment programs (real interaction.vfp) enabled, units 1-6 2D + unit0 CUBE enabled with Doom's bound textures, attribs 8-11 + colour array,
           depth EQUAL/mask 0, blend dst ONE, stencil GEQUAL/128, scissor box; then glFinish (the wedge in d3t13/14/16 happens with exactly this state pending). */
        int intstate = getenv("INTSTATE") != NULL; GLuint vpId = 0, fpId = 0; GLuint itex[8]; memset(itex, 0, sizeof itex); GLuint icube = 0;
        if (intstate) {
            const char *pf = getenv("INTPROG") ? getenv("INTPROG") : "/Users/bushmas/rung3/interaction.vfp";
            FILE *pfh = fopen(pf, "rb"); if (!pfh) { fprintf(stderr, "no %s\n", pf); return 1; }
            static char ptxt[16384]; size_t pn = fread(ptxt, 1, sizeof ptxt - 1, pfh); ptxt[pn] = 0; fclose(pfh);
            char *fpp = strstr(ptxt, "!!ARBfp1.0"); if (!fpp) { fprintf(stderr, "bad program file\n"); return 1; }
            glGenProgramsARB(1, &vpId); glBindProgramARB(GL_VERTEX_PROGRAM_ARB, vpId);
            glProgramStringARB(GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)(fpp - ptxt), ptxt);
            if (glGetError()) fprintf(stderr, "vp load error\n");
            glGenProgramsARB(1, &fpId); glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, fpId);
            glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)strlen(fpp), fpp);
            if (glGetError()) fprintf(stderr, "fp load error\n");
            /* textures per unit, same as state_15254 */
            struct { int unit, w, h, ifmt, wrap, minf, magf; } IT[] = {
                { 0, 1024, 1024, 0x81a6, 0x812f, GL_NEAREST, GL_NEAREST }, { 1, 128, 128, 0x83f3, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR },
                { 2, 64, 8, 0x83f2, 0x812f, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR }, { 3, 128, 128, 0x83f1, 0x812f, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR },
                { 4, 128, 128, 0x83f1, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR }, { 5, 64, 64, 0x83f1, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR },
                { 6, 256, 1, 0x804b, 0x812f, GL_LINEAR, GL_LINEAR } };
            static unsigned char junk2[4 * 1024 * 1024]; for (unsigned k = 0; k < sizeof junk2; k++) junk2[k] = (unsigned char)rnd();
            for (unsigned ti = 0; ti < sizeof IT / sizeof IT[0]; ti++) {
                glActiveTextureARB(GL_TEXTURE0_ARB + IT[ti].unit); glGenTextures(1, &itex[ti]); glBindTexture(GL_TEXTURE_2D, itex[ti]);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, IT[ti].minf); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, IT[ti].magf);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, IT[ti].wrap); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, IT[ti].wrap);
                int w = IT[ti].w, h = IT[ti].h, f = IT[ti].ifmt;
                for (int lvl = 0; ; lvl++) {
                    if (f == 0x81a6) { glTexImage2D(GL_TEXTURE_2D, lvl, f, w, h, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, junk2); break; }
                    if (f == 0x804b) { glTexImage2D(GL_TEXTURE_2D, lvl, f, w, h, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, junk2); break; }
                    int bs = (f == 0x83f0 || f == 0x83f1) ? 8 : 16; int sz = ((w + 3) / 4) * ((h + 3) / 4) * bs;
                    glCompressedTexImage2DARB(GL_TEXTURE_2D, lvl, f, w, h, 0, sz, junk2);
                    if (w == 1 && h == 1) break; w = w > 1 ? w / 2 : 1; h = h > 1 ? h / 2 : 1;
                }
                glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            }
            glActiveTextureARB(GL_TEXTURE0_ARB); glGenTextures(1, &icube); glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, icube);   /* unit0 cube 32x32 RGB8 linear clamp */
            glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MIN_FILTER, GL_LINEAR); glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S, 0x812f); glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T, 0x812f);
            for (int fc = 0; fc < 6; fc++) glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB + fc, 0, 0x8051, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, junk2);
            for (int ti = 0; ti < nts; ti++) { glActiveTextureARB(GL_TEXTURE0_ARB + ts_unit[ti]); glBindTexture(ts_cube[ti] ? GL_TEXTURE_CUBE_MAP_ARB : GL_TEXTURE_2D, ts_id[ti]); }
            glActiveTextureARB(GL_TEXTURE0_ARB);
            printf("INTSTATE: programs + 8 interaction textures ready\n");
        }
        /* VRAM PRESSURE (Doom has hundreds of MB of textures + static VBOs resident): TEXMB=N textures of 1MB (512x512 RGBA) and STATICMB=M static
           VBOs of 256KB; PDRAWS=K small textured draws per frame (rotating window over both pools) before the real batch, PDRAWS_AFTER=1 puts them after. */
        int texmb = getenv("TEXMB") ? atoi(getenv("TEXMB")) : 0, statmb = getenv("STATICMB") ? atoi(getenv("STATICMB")) : 0;
        int pdraws = getenv("PDRAWS") ? atoi(getenv("PDRAWS")) : 0, pafter = getenv("PDRAWS_AFTER") != NULL;
        GLuint *ptex = NULL, *pvbo = NULL; int nptex = texmb, npvbo = statmb * 4, pcur = 0;
        if (nptex) { ptex = malloc(nptex * sizeof(GLuint)); unsigned char *tx = malloc(512 * 512 * 4);
            for (int i = 0; i < nptex; i++) { for (int k = 0; k < 512 * 512 * 4; k++) tx[k] = (unsigned char)rnd();
                glGenTextures(1, &ptex[i]); glBindTexture(GL_TEXTURE_2D, ptex[i]);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 512, 512, 0, GL_RGBA, GL_UNSIGNED_BYTE, tx); }
            free(tx); printf("created %d pressure textures\n", nptex); }
        if (npvbo) { pvbo = malloc(npvbo * sizeof(GLuint)); unsigned char *vd = malloc(256 * 1024);
            for (int i = 0; i < npvbo; i++) { for (int k = 0; k < 256 * 1024 / 4; k++) ((float *)vd)[k] = -0.9f + 1.8f * ((float)(rnd() % 1000) / 1000.f);
                glGenBuffersARB(1, &pvbo[i]); glBindBufferARB(GL_ARRAY_BUFFER_ARB, pvbo[i]); glBufferDataARB(GL_ARRAY_BUFFER_ARB, 256 * 1024, vd, GL_STATIC_DRAW_ARB); }
            free(vd); printf("created %d pressure static vbos\n", npvbo); }
        static const GLuint pidx[6] = { 0, 1, 2, 2, 1, 3 };
        for (int f = 0; f < frames; f++) {
            glClearColor(0.f, 0.f, 0.f, 1.f); glClearDepth(1.0);   /* Doom clears to black */
            if (getenv("CLEARST")) { glClearStencil(128); glStencilMask(255); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); }   /* CLEARST=1: Doom clears depth+stencil (stencil 128) -> driver fast-clear / Hi-Z (ZB_BW_CNTL 0xc081d, ZB_DEPTHCLEARVALUE 0xffffff80) */
            else glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            if (ds & 128) glDepthRange(0.0, 0.5);   /* DS bit 128: Doom depth-fill draws use depth range 0..0.5 */
            #define PRESSURE_PASS() do { if (pdraws && (nptex || npvbo)) { \
                glMatrixMode(GL_PROJECTION); glLoadIdentity(); glMatrixMode(GL_MODELVIEW); glLoadIdentity(); \
                for (int k = 0; k < pdraws; k++, pcur++) { \
                    if (nptex) glBindTexture(GL_TEXTURE_2D, ptex[pcur % nptex]); \
                    glBindBufferARB(GL_ARRAY_BUFFER_ARB, npvbo ? pvbo[pcur % npvbo] : 0); \
                    glVertexPointer(3, GL_FLOAT, VSZ, (void *)0); glTexCoordPointer(2, GL_FLOAT, VSZ, (void *)12); \
                    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, pidx); } \
                glBindTexture(GL_TEXTURE_2D, 0); } } while (0)
            if (getenv("FILLER")) {   /* FILLER=1: a different-sized resident filler VBO each frame (drawn once so it gets VRAM) before the real batch, freed at end of frame: shifts the VRAM address the model VBO lands at */
                static GLuint fillers[4]; static int nf = 0; static unsigned char *fbuf = NULL; if (!fbuf) { fbuf = calloc(1, 1100 * 1024); for (int k = 0; k < 1100 * 1024 / 4; k++) ((float *)fbuf)[k] = 0.1f * (k % 7); }
                size_t fsz = (size_t)(((f * 37 + 11) % 256) + 1) * 4096 + (f % 3) * 1024;
                GLuint fb; glGenBuffersARB(1, &fb); glBindBufferARB(GL_ARRAY_BUFFER_ARB, fb); glBufferDataARB(GL_ARRAY_BUFFER_ARB, (GLsizeiptrARB)fsz, fbuf, GL_STATIC_DRAW_ARB);
                glMatrixMode(GL_PROJECTION); glLoadIdentity(); glMatrixMode(GL_MODELVIEW); glLoadIdentity();
                glVertexPointer(3, GL_FLOAT, VSZ, (void *)0); glTexCoordPointer(2, GL_FLOAT, VSZ, (void *)12);
                static const GLuint fidx[3] = { 0, 1, 2 }; glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, fidx);
                if (nf < 4) fillers[nf++] = fb; else { glDeleteBuffersARB(1, &fillers[f % 4]); fillers[f % 4] = fb; }
            }
            if (!pafter) PRESSURE_PASS();
            if (reup && getenv("UPFRONT")) {   /* UPFRONT=1: all dynamic-surface uploads happen before any draw of the frame (dhewm3 frontend creates the ambient caches first) */
                for (int d = 0; d < nreal; d++) if (real[d].nv >= reup && nrfree > 0) {
                    GLuint n = rfree[--nrfree]; rused[d] = n; glBindBufferARB(GL_ARRAY_BUFFER_ARB, n);
                    glBufferDataARB(GL_ARRAY_BUFFER_ARB, (GLsizeiptrARB)((size_t)real[d].nv * VSZ), real[d].verts, GL_STATIC_DRAW_ARB); }
            }
            int repeat = getenv("REPEAT") ? atoi(getenv("REPEAT")) : 1;   /* REPEAT=N: issue the whole real batch N times per frame (grows the command buffer: Doom's wedge is the first batch needing the 0x80000 cb) */
            for (int dd = 0; dd < nreal * repeat; dd++) {
                int d = dd % nreal;
                struct RealDraw *r = &real[d];
                printf("frame %d draw %d %s (%d idx, %d verts)...", f, d, r->name, r->ni, r->nv);
                glMatrixMode(GL_PROJECTION); glLoadMatrixf(r->proj); glMatrixMode(GL_MODELVIEW); glLoadMatrixf(r->mv);
                GLuint curv = r->vbo;
                if (rused[d]) curv = rused[d];
                else if (reup && r->nv >= reup && nrfree > 0) {
                    curv = rfree[--nrfree]; rused[d] = curv;
                    glBindBufferARB(GL_ARRAY_BUFFER_ARB, curv);
                    glBufferDataARB(GL_ARRAY_BUFFER_ARB, (GLsizeiptrARB)((size_t)r->nv * VSZ), r->verts, GL_STATIC_DRAW_ARB);
                }
                glBindBufferARB(GL_ARRAY_BUFFER_ARB, curv);
                glVertexPointer(3, GL_FLOAT, VSZ, (void *)0); glTexCoordPointer(2, GL_FLOAT, VSZ, (void *)12);
                if (ds & 32) { glBindBufferARB(GL_ARRAY_BUFFER_ARB, real[(d + 7) % nreal].vbo); glColorPointer(4, GL_UNSIGNED_BYTE, VSZ, (void *)56); glNormalPointer(GL_FLOAT, VSZ, (void *)20); glBindBufferARB(GL_ARRAY_BUFFER_ARB, r->vbo); }
                if (f == 0 && getenv("STATE_OUT") && d == nreal - 1) { FILE *sf = fopen(getenv("STATE_OUT"), "w"); if (sf) { gsd_dump(sf); fclose(sf); } }
                glDrawElements(GL_TRIANGLES, r->ni, GL_UNSIGNED_INT, r->idx);
                if (finishEvery > 0 && (d % finishEvery) == finishEvery - 1) { glFinish(); printf(" finished"); }
                printf("\n");
            }
            if (getenv("REPLAY_TAIL") && getenv("REPLAY")) {   /* REPLAY_TAIL=1: after the wedge draw replay Doom's following GL calls (BindBuffer/BindTexture/glCopyTexSubImage2D 1024x768 of the framebuffer/clear) up to the next draw */
                rp_startLine = strtoul(getenv("REPLAY_STOP"), NULL, 0) + 1; printf("replaying tail from line %lu\n", rp_startLine); fflush(stdout);
                replay_gllog(getenv("REPLAY")); printf("tail done\n"); fflush(stdout);
            }
            if (intstate) {
                glEnable(GL_VERTEX_PROGRAM_ARB); glEnable(GL_FRAGMENT_PROGRAM_ARB);
                glBindProgramARB(GL_VERTEX_PROGRAM_ARB, vpId); glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, fpId);
                glBindBufferARB(GL_ARRAY_BUFFER_ARB, real[nreal - 1].vbo);
                glEnableClientState(GL_COLOR_ARRAY); glColorPointer(4, GL_UNSIGNED_BYTE, VSZ, (void *)56);
                glEnableVertexAttribArrayARB(8);  glVertexAttribPointerARB(8, 2, GL_FLOAT, 0, VSZ, (void *)12);
                glEnableVertexAttribArrayARB(9);  glVertexAttribPointerARB(9, 3, GL_FLOAT, 0, VSZ, (void *)32);
                glEnableVertexAttribArrayARB(10); glVertexAttribPointerARB(10, 3, GL_FLOAT, 0, VSZ, (void *)44);
                glEnableVertexAttribArrayARB(11); glVertexAttribPointerARB(11, 3, GL_FLOAT, 0, VSZ, (void *)20);
                glDepthFunc(GL_EQUAL); glDepthMask(GL_FALSE); glBlendFunc(GL_ONE, GL_ONE); glStencilFunc(GL_GEQUAL, 128, 255); glDepthRange(0.0, 1.0);
                for (int u = 0; u < 7; u++) { glActiveTextureARB(GL_TEXTURE0_ARB + u); glBindTexture(GL_TEXTURE_2D, itex[u]);
                    if (u == 0) { glDisable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, icube); glEnable(GL_TEXTURE_CUBE_MAP_ARB); } else glEnable(GL_TEXTURE_2D); }
                glActiveTextureARB(GL_TEXTURE0_ARB + 5);
                printf("frame %d interaction state applied, finishing...", f); glFinish(); printf(" done\n");
                /* back to the depth-fill state */
                for (int u = 0; u < 7; u++) { glActiveTextureARB(GL_TEXTURE0_ARB + u); if (u == 0) { glDisable(GL_TEXTURE_CUBE_MAP_ARB); glEnable(GL_TEXTURE_2D); } else glDisable(GL_TEXTURE_2D); }
                for (int ti = 0; ti < nts; ti++) { glActiveTextureARB(GL_TEXTURE0_ARB + ts_unit[ti]); glBindTexture(ts_cube[ti] ? GL_TEXTURE_CUBE_MAP_ARB : GL_TEXTURE_2D, ts_id[ti]); }   /* Doom's depth-fill bindings (state_15251) */
                glActiveTextureARB(GL_TEXTURE0_ARB);
                glDisableVertexAttribArrayARB(8); glDisableVertexAttribArrayARB(9); glDisableVertexAttribArrayARB(10); glDisableVertexAttribArrayARB(11);
                glDisableClientState(GL_COLOR_ARRAY); glDisable(GL_VERTEX_PROGRAM_ARB); glDisable(GL_FRAGMENT_PROGRAM_ARB);
                glDepthFunc(real[0].df ? real[0].df : GL_LESS); glDepthMask(GL_TRUE); glBlendFunc(GL_ONE, GL_ZERO); glStencilFunc(GL_ALWAYS, 1, 255);
            }
            if (pafter) PRESSURE_PASS();
            if (windowed) { gl_window_flush(); gl_window_pump(); } else if (fullscreen) CGLFlushDrawable(ctx);
            for (int d = 0; d < nreal; d++) if (rused[d]) { rfree[nrfree++] = rused[d]; rused[d] = 0; }   /* end-of-frame free, no finish */
            printf("frame %d finish...", f);
            if (getenv("NOFRAMEFINISH")) { glFlush(); printf(" (no finish)\n"); continue; }   /* NOFRAMEFINISH=1: like dhewm3 SwapBuffers, the frame's last IBs stay in flight */
            glFinish();
            GLubyte px[4]; glReadPixels(W / 2, H / 2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px); GLenum e = glGetError();
            printf(" px=%d,%d,%d,%d err=0x%x\n", px[0], px[1], px[2], px[3], (unsigned)e); if (e) rbad++;
        }
        if (fullscreen) { CGLSetCurrentContext(NULL); CGDisplayRelease(CGMainDisplayID()); }
        printf("RESULT: %s (%d of %d frames reported a GL error)\n", rbad ? "FAIL" : "PASS", rbad, frames);
        return rbad ? 1 : 0;
    }

    /* one static VBO + one client index array per draw, built once (like dhewm3's static vertex cache + srfTriangles indexes) */
    GLuint vbo[MAXD]; GLuint *idx[MAXD];
    for (int d = 0; d < nd; d++) {
        int shared = -1;
        for (int e = 0; e < d; e++) if (nkey[e] == nkey[d] && nvert[e] == nvert[d]) { shared = e; break; }
        if (shared >= 0) { vbo[d] = vbo[shared]; idx[d] = idx[shared]; nidx[d] = nidx[shared]; continue; }   /* same dhewm3 vbo id: same geometry drawn again */
        int nv = nvert[d], ni = nidx[d];
        unsigned char *vd = malloc((size_t)nv * VSZ);
        for (int i = 0; i < nv; i++) {
            float *f = (float *)(vd + (size_t)i * VSZ);
            float a = (float)i / (float)(nv > 1 ? nv - 1 : 1);
            if (clipS > 0.f) { f[0] = clipS * (-1.f + 2.f * ((float)(rnd() % 1000) / 1000.f)); f[1] = clipS * (-1.f + 2.f * ((float)(rnd() % 1000) / 1000.f)); f[2] = -clipS * ((float)(rnd() % 1000) / 1000.f); }
            else { f[0] = -0.9f + 1.8f * ((float)(rnd() % 1000) / 1000.f); f[1] = -0.9f + 1.8f * ((float)(rnd() % 1000) / 1000.f);
            f[2] = 0.1f + 0.8f * a; }
            f[3] = a; f[4] = (i & 1) ? 1.f : 0.f;
            f[5] = 0; f[6] = 0; f[7] = 1; f[8] = 1; f[9] = 0; f[10] = 0; f[11] = 0; f[12] = 1; f[13] = 0;
            vd[(size_t)i * VSZ + 56] = 0; vd[(size_t)i * VSZ + 57] = 0; vd[(size_t)i * VSZ + 58] = 0; vd[(size_t)i * VSZ + 59] = 255;
        }
        glGenBuffersARB(1, &vbo[d]); glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo[d]);
        glBufferDataARB(GL_ARRAY_BUFFER_ARB, (GLsizeiptrARB)((size_t)nv * VSZ), vd, GL_STATIC_DRAW_ARB);
        free(vd);
        idx[d] = malloc((size_t)ni * sizeof(GLuint));
        for (int k = 0; k < ni; k++) {
            int tri = k / 3, c = k % 3;
            int base = (int)(((long)tri * (nv - 3)) / (ni / 3 > 0 ? ni / 3 : 1));
            idx[d][k] = perm ? (rnd() % nv) : (unsigned)(base + c + (rnd() % 3 == 0 ? (rnd() % 3) : 0)) % nv;
        }
    }
    int isChurn[MAXD]; for (int d = 0; d < nd; d++) isChurn[d] = churn && (int)(rnd() % 100) < churn;
    if (churn) { for (int i = 0; i < poolN; i++) { GLuint n; glGenBuffersARB(1, &n); glBindBufferARB(GL_ARRAY_BUFFER_ARB, n);
                 glBufferDataARB(GL_ARRAY_BUFFER_ARB, 4096, NULL, GL_STATIC_DRAW_ARB); freeList[nfree++] = n; } }
    printf("%d draws, %d frames, vbo err=0x%x\n", nd, frames, (unsigned)glGetError());

    int bad = 0; GLuint usedName[MAXD]; memset(usedName, 0, sizeof usedName);
    for (int f = 0; f < frames; f++) {
        glClearColor(1.f, 1.f, 1.f, 1.f); glClearDepth(1.0); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for (int d = 0; d < nd; d++) {
            printf("frame %d draw %d (%d idx, %d verts)...", f, d, nidx[d], nvert[d]);
            GLuint cur = vbo[d];
            if (isChurn[d] && nfree > 0) {
                cur = freeList[--nfree];                      /* LIFO: most recently freed name first */
                int nv = nvert[d]; unsigned char *vd = malloc((size_t)nv * VSZ);
                for (int i = 0; i < nv; i++) { float *ff = (float *)(vd + (size_t)i * VSZ); memset(ff, 0, VSZ);
                    ff[0] = -0.9f + 1.8f * ((float)(rnd() % 1000) / 1000.f); ff[1] = -0.9f + 1.8f * ((float)(rnd() % 1000) / 1000.f); ff[2] = 0.5f; vd[(size_t)i*VSZ+59] = 255; }
                glBindBufferARB(GL_ARRAY_BUFFER_ARB, cur);
                glBufferDataARB(GL_ARRAY_BUFFER_ARB, (GLsizeiptrARB)((size_t)nv * VSZ), vd, GL_STATIC_DRAW_ARB);
                free(vd); usedName[d] = cur;
            }
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, cur);
            if (respec && (int)(rnd() % 100) < respec) {
                int nv = nvert[d]; unsigned char *vd = malloc((size_t)nv * VSZ);
                for (int i = 0; i < nv; i++) { float *ff = (float *)(vd + (size_t)i * VSZ); memset(ff, 0, VSZ);
                    ff[0] = -0.9f + 1.8f * ((float)(rnd() % 1000) / 1000.f); ff[1] = -0.9f + 1.8f * ((float)(rnd() % 1000) / 1000.f); ff[2] = 0.5f; vd[(size_t)i*VSZ+59] = 255; }
                glBufferDataARB(GL_ARRAY_BUFFER_ARB, (GLsizeiptrARB)((size_t)nv * VSZ), vd, GL_STATIC_DRAW_ARB);
                free(vd);
            }
            glVertexPointer(3, GL_FLOAT, VSZ, (void *)0);
            glTexCoordPointer(2, GL_FLOAT, VSZ, (void *)12);
            glDrawElements(GL_TRIANGLES, nidx[d], GL_UNSIGNED_INT, idx[d]);
            if (finishEvery > 0 && (d % finishEvery) == finishEvery - 1) { glFinish(); printf(" finished"); }
            printf("\n");
        }
        for (int d = 0; d < nd; d++) if (isChurn[d] && usedName[d]) { freeList[nfree++] = usedName[d]; usedName[d] = 0; }   /* end-of-frame free, no finish */
        if (windowed) { gl_window_flush(); gl_window_pump(); } else if (fullscreen) CGLFlushDrawable(ctx);
        printf("frame %d finish...", f);
        glFinish();
        GLubyte px[4]; glReadPixels(W / 2, H / 2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px);
        GLenum e = glGetError();
        printf(" px=%d,%d,%d,%d err=0x%x\n", px[0], px[1], px[2], px[3], (unsigned)e);
        if (e) bad++;
    }
    if (fullscreen) { CGLSetCurrentContext(NULL); CGDisplayRelease(CGMainDisplayID()); }
    printf("RESULT: %s (%d of %d frames reported a GL error)\n", bad ? "FAIL" : "PASS", bad, frames);
    return bad ? 1 : 0;
}
