/* gl_vbo_tempbuf_probe.c - minimal repro of the #214 Doom 3 VBO wedge: a large (default 4 MiB) GL_STREAM_DRAW array buffer used
 * the way dhewm3's vertex cache uses its per-frame temp buffer (glBufferData(NULL) once, then glBufferSubData of interleaved
 * 60-byte idDrawVert-style vertices at page-aligned offsets that walk DOWN the buffer, one glDrawElements per upload with 32-bit
 * client indices).  Each draw is verified by reading back a pixel.  Prints "draw N off=..." (unbuffered) BEFORE every draw so a
 * GPU wedge is attributable to the exact draw/offset that never completes.
 *   usage: gl_vbo_tempbuf_probe [bufBytes] [startOff] [stepBytes] [ndraws] [vertsPerDraw]
 *   CLIENT=1 in the environment draws the same vertices from client arrays (control).
 *   defaults: 0x400000 0x39c000 0x1000 14 12   (stepBytes is subtracted: offsets descend; use a negative via 'u' prefix to ascend, e.g. u0x1000)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

#define W 64
#define H 64
#define VSZ 60

static void setattr(const void *base) {   /* dhewm3 ARB2 layout */
    const unsigned char *b = (const unsigned char *)base;
    glVertexAttribPointerARB(0, 3, GL_FLOAT, GL_FALSE, VSZ, b + 0);
    glVertexAttribPointerARB(8, 2, GL_FLOAT, GL_FALSE, VSZ, b + 12);
    glVertexAttribPointerARB(2, 3, GL_FLOAT, GL_FALSE, VSZ, b + 20);
    glVertexAttribPointerARB(9, 3, GL_FLOAT, GL_FALSE, VSZ, b + 32);
    glVertexAttribPointerARB(10, 3, GL_FLOAT, GL_FALSE, VSZ, b + 44);
    glVertexAttribPointerARB(3, 4, GL_UNSIGNED_BYTE, GL_TRUE, VSZ, b + 56);
}
static unsigned long num(const char *s) { return strtoul(s, NULL, 0); }

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    unsigned long bufBytes = argc > 1 ? num(argv[1]) : 0x400000;
    unsigned long startOff = argc > 2 ? num(argv[2]) : 0x39c000;
    int ascend = 0; const char *st = argc > 3 ? argv[3] : "0x1000";
    if (st[0] == 'u') { ascend = 1; st++; }
    unsigned long step = num(st);
    int ndraws = argc > 4 ? (int)num(argv[4]) : 14;
    int nv = argc > 5 ? (int)num(argv[5]) : 12;
    int nofinish = getenv("NOFINISH") ? atoi(getenv("NOFINISH")) : 0;
    int staticblk = getenv("STATICBLK") != NULL;
    int client = getenv("CLIENT") != NULL;   /* CLIENT=1: same data from client memory, no VBO draw (control) */

    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
    if (err || !npix || !pf) { fprintf(stderr, "FAIL ChoosePixelFormat\n"); return 1; }
    CGLContextObj ctx = NULL; if (CGLCreateContext(pf, NULL, &ctx)) { fprintf(stderr, "FAIL CreateContext\n"); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf = NULL; if (CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf)) { fprintf(stderr, "FAIL CreatePBuffer\n"); return 1; }
    CGLSetCurrentContext(ctx); CGLSetPBuffer(ctx, pbuf, 0, 0, 0);
    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    GLuint vb; glGenBuffersARB(1, &vb); glBindBufferARB(GL_ARRAY_BUFFER_ARB, vb);
    { const char *u = getenv("USAGE"); GLenum usage = GL_STREAM_DRAW_ARB;   /* USAGE=static|dynamic|stream (default stream) */
      if (u && u[0] == 's' && u[1] == 't' && u[2] == 'a') usage = GL_STATIC_DRAW_ARB; else if (u && u[0] == 'd') usage = GL_DYNAMIC_DRAW_ARB;
      void *init = getenv("INITDATA") ? calloc(1, bufBytes) : NULL;   /* INITDATA=1: pass real initial data like dhewm3's static vertex cache */
      glBufferDataARB(GL_ARRAY_BUFFER_ARB, bufBytes, init, usage); }
    printf("buffer %lu bytes created, glGetError=0x%x\n", bufBytes, (unsigned)glGetError());

    int arb = getenv("ARB") != NULL;   /* ARB=1: dhewm3-style draw: ARB vertex+fragment program, 6 generic attribute arrays (pos@0 st@12 normal@20 tan0@32 tan1@44 color@56, stride 60) */
    if (arb) {
        static const char *vp = "!!ARBvp1.0\nMOV result.position, vertex.attrib[0];\nMOV result.texcoord[0], vertex.attrib[8];\nMOV result.texcoord[1], vertex.attrib[9];\nMOV result.texcoord[2], vertex.attrib[10];\nMOV result.texcoord[3], vertex.attrib[2];\nMOV result.color, vertex.attrib[3];\nEND\n";
        int tex = getenv("TEX") != NULL;   /* TEX=1: 3 textured units sampled in the fragment program like a dhewm3 GUI/interaction draw */
        static const char *fp0 = "!!ARBfp1.0\nMOV result.color, fragment.color;\nEND\n";
        static const char *fp1 = "!!ARBfp1.0\nTEMP a, b, c;\nTEX a, fragment.texcoord[0], texture[0], 2D;\nTEX b, fragment.texcoord[1], texture[1], 2D;\nTEX c, fragment.texcoord[2], texture[2], 2D;\nMUL a, a, b;\nMUL a, a, c;\nMUL result.color, a, fragment.color;\nEND\n";
        const char *fp = tex ? fp1 : fp0;
        if (tex) {
            static unsigned char texels[64 * 64 * 4]; for (int i = 0; i < 64 * 64; i++) { texels[i*4] = 255; texels[i*4+1] = 255; texels[i*4+2] = 255; texels[i*4+3] = 255; }
            for (int u = 0; u < 3; u++) {
                GLuint t; glGenTextures(1, &t); glActiveTexture(GL_TEXTURE0 + u); glBindTexture(GL_TEXTURE_2D, t);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, texels);
                glEnable(GL_TEXTURE_2D);
            }
            printf("textures err=0x%x\n", (unsigned)glGetError());
        }
        GLuint prog[2]; glGenProgramsARB(2, prog);
        glBindProgramARB(GL_VERTEX_PROGRAM_ARB, prog[0]); glProgramStringARB(GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)strlen(vp), vp);
        printf("vp err=0x%x\n", (unsigned)glGetError());
        glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, prog[1]); glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)strlen(fp), fp);
        printf("fp err=0x%x\n", (unsigned)glGetError());
        glEnable(GL_VERTEX_PROGRAM_ARB); glEnable(GL_FRAGMENT_PROGRAM_ARB);
        static const int attrs[6] = {0, 8, 2, 9, 10, 3};
        for (int i = 0; i < 6; i++) glEnableVertexAttribArrayARB(attrs[i]);
    } else {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    }

    unsigned char *vd = malloc((size_t)nv * VSZ);
    GLuint *idx = malloc((size_t)nv * sizeof(GLuint) * 3);
    int ni = 0;
    for (int i = 0; i + 2 < nv; i++) { idx[ni++] = i; idx[ni++] = i + 1; idx[ni++] = i + 2; }   /* tri strip as list: covers the quad area repeatedly */
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    int bad = 0;
    for (int d = 0; d < ndraws; d++) {
        unsigned long off = ascend ? startOff + (unsigned long)d * step : startOff - (unsigned long)d * step;
        if (off + (unsigned long)nv * VSZ > bufBytes) { printf("skip draw %d: off=0x%lx beyond buffer\n", d, off); continue; }
        for (int i = 0; i < nv; i++) {
            float *f = (float *)(vd + (size_t)i * VSZ);
            float a = (float)i / (float)(nv - 1);
            f[0] = -1.f + 2.f * a; f[1] = (i & 1) ? 1.f : -1.f; f[2] = 0.f;      /* position   +0  */
            f[3] = a; f[4] = (i & 1) ? 1.f : 0.f;                               /* texcoord   +12 */
            f[5] = 0; f[6] = 0; f[7] = 1;                                       /* normal     +20 */
            f[8] = 1; f[9] = 0; f[10] = 0; f[11] = 0; f[12] = 1; f[13] = 0;     /* tangents   +32,+44 */
            vd[(size_t)i * VSZ + 56] = 255; vd[(size_t)i * VSZ + 57] = 0; vd[(size_t)i * VSZ + 58] = 0; vd[(size_t)i * VSZ + 59] = 255; /* color +56 */
        }
        printf("draw %d off=0x%lx %s...", d, off, client ? "client" : "upload");
        if (client) {
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
            if (arb) setattr(vd);
            else {
            glVertexPointer(3, GL_FLOAT, VSZ, vd);
            glTexCoordPointer(2, GL_FLOAT, VSZ, vd + 12);
            glNormalPointer(GL_FLOAT, VSZ, vd + 20);
            glColorPointer(4, GL_UNSIGNED_BYTE, VSZ, vd + 56); }
        } else {
            if (staticblk) {   /* STATICBLK=1: dhewm3 static vertex-cache style: a NEW small STATIC_DRAW buffer per draw, filled by glBufferData(data), drawn from offset 0 */
                GLuint sb; glGenBuffersARB(1, &sb); glBindBufferARB(GL_ARRAY_BUFFER_ARB, sb);
                glBufferDataARB(GL_ARRAY_BUFFER_ARB, (GLsizeiptrARB)((size_t)nv * VSZ), vd, GL_STATIC_DRAW_ARB);
                off = 0;
            } else {
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, vb);
            glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, (GLintptrARB)off, (GLsizeiptrARB)((size_t)nv * VSZ), vd); }
            if (arb) setattr((void *)off);
            else {
            glVertexPointer(3, GL_FLOAT, VSZ, (void *)off);
            glTexCoordPointer(2, GL_FLOAT, VSZ, (void *)(off + 12));
            glNormalPointer(GL_FLOAT, VSZ, (void *)(off + 20));
            glColorPointer(4, GL_UNSIGNED_BYTE, VSZ, (void *)(off + 56)); }
        }
        printf(" draw...");
        glDrawElements(GL_TRIANGLES, ni, GL_UNSIGNED_INT, idx);
        if (nofinish && (d % nofinish) != nofinish - 1) { printf(" (no finish)\n"); continue; }   /* NOFINISH=N: only glFinish+verify every Nth draw, keeping the buffer busy like a real frame */
        printf(" finish...");
        glFinish();
        GLubyte px[4]; glReadPixels(W / 2, H / 2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px);
        GLenum e = glGetError();
        printf(" px=%d,%d,%d,%d err=0x%x\n", px[0], px[1], px[2], px[3], (unsigned)e);
        if (px[0] != 255 || e) bad++;
        glClear(GL_COLOR_BUFFER_BIT);
    }
    printf("RESULT: %s (%d of %d draws bad)\n", bad ? "FAIL" : "PASS", bad, ndraws);
    return bad ? 1 : 0;
}
