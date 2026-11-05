/* gl_feature_vertexblend_test.c - ARB_vertex_blend: multi-matrix vertex blending (skinning).
 *
 * #138 CORRECTION: the earlier version of this test (and diag_vbaddr.c) concluded the extension was "advertised but
 * non-functional" because dlsym("glActiveMatrixARB") and dlsym("glWeightfARB") returned NULL. Neither function is part of
 * GL_ARB_vertex_blend: the extension defines only
 *     glWeight{b,s,i,f,d,ub,us,ui}vARB(size, weights)  (vector forms only), glWeightPointerARB, glVertexBlendARB,
 * and the per-unit matrices are selected with glMatrixMode(GL_MODELVIEW0_ARB .. GL_MODELVIEW31_ARB). The OpenGL
 * framework exports exactly that set (Tiger libGL: 10 symbols, all present). The old test also queried the wrong
 * enum for GL_MAX_VERTEX_UNITS_ARB (0x86A8 is GL_CURRENT_WEIGHT_ARB; the real value is 0x86A4).
 *
 * This version actually exercises the extension: MODELVIEW0 = translate(-0.5,0,0), MODELVIEW1 = translate(+0.5,0,0),
 * two units, weights {0.25, 0.75}, so a quad centred on the origin must land at x = 0.25*(-0.5) + 0.75*(0.5) = +0.25
 * (NDC) = pixel column 20 of a 32-wide target, instead of column 8 (MODELVIEW0 only). Result lines:
 *     PASS     - blended quad is at column 20 and columns 8 and 28 are empty
 *     FAIL     - the entry points exist but the blend is not applied (read the printed pixels)
 *     SKIPPED  - extension not advertised / entry points missing
 */
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_VERTEX_BLEND_ARB
#define GL_VERTEX_BLEND_ARB 0x86A7
#endif
#ifndef GL_MAX_VERTEX_UNITS_ARB
#define GL_MAX_VERTEX_UNITS_ARB 0x86A4
#endif
#ifndef GL_MODELVIEW0_ARB
#define GL_MODELVIEW0_ARB 0x1700
#endif
#ifndef GL_MODELVIEW1_ARB
#define GL_MODELVIEW1_ARB 0x850A
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

typedef void (*WeightfvFn)(GLint, const GLfloat *);
typedef void (*VertexBlendFn)(GLint);
static WeightfvFn pWeightfv;

static GLubyte px[W * H * 4];

static void drawQuad(int blend) {
    static const GLfloat w[2] = { 0.25f, 0.75f };
    static const GLfloat v[4][2] = { {-0.2f,-0.2f}, {0.2f,-0.2f}, {0.2f,0.2f}, {-0.2f,0.2f} };
    int i;
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    for (i = 0; i < 4; i++) {
        if (blend) pWeightfv(2, w);      /* the weight is a per-vertex attribute: set it before each glVertex */
        glVertex3f(v[i][0], v[i][1], 0.0f);
    }
    glEnd();
    glFinish();
    glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, px);
}

static int lit(int x) { GLubyte *p = px + (H / 2 * W + x) * 4; return p[0] > 128 && p[1] > 128 && p[2] > 128; }

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
    if (err || npix == 0 || !pf) { die("ChoosePixelFormat", err); return 1; }
    CGLContextObj ctx = NULL; err = CGLCreateContext(pf, NULL, &ctx);
    if (err) { die("CreateContext", err); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf = NULL; err = CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx); if (err) { die("SetCurrentContext", err); return 1; }
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, 0); if (err) { die("SetPBuffer", err); return 1; }
    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glDisable(GL_DEPTH_TEST); glDisable(GL_LIGHTING); glDisable(GL_CULL_FACE);

    const char *ext = (const char *)glGetString(GL_EXTENSIONS);
    if (!(ext && strstr(ext, "GL_ARB_vertex_blend"))) {
        printf("RESULT: SKIPPED - GL_ARB_vertex_blend not available\n");
        return 0;
    }

    GLint maxUnits = -1;
    glGetIntegerv(GL_MAX_VERTEX_UNITS_ARB, &maxUnits);
    printf("MAX_VERTEX_UNITS_ARB = %d (glGetError 0x%04x)\n", (int)maxUnits, (unsigned)glGetError());

    void *h = dlopen("/System/Library/Frameworks/OpenGL.framework/OpenGL", RTLD_LAZY);
    VertexBlendFn pVertexBlend = (VertexBlendFn)dlsym(h, "glVertexBlendARB");
    pWeightfv = (WeightfvFn)dlsym(h, "glWeightfvARB");
    printf("dlsym glVertexBlendARB=%p glWeightfvARB=%p\n", (void *)pVertexBlend, (void *)pWeightfv);
    if (!pVertexBlend || !pWeightfv) {
        printf("RESULT: SKIPPED - a required ARB_vertex_blend entry point is missing\n");
        return 0;
    }
    if (maxUnits < 2) {
        printf("RESULT: SKIPPED - fewer than 2 vertex units\n");
        return 0;
    }

    /* per-unit matrices: GL_MODELVIEW0_ARB is the ordinary modelview */
    glMatrixMode(GL_MODELVIEW0_ARB); glLoadIdentity(); glTranslatef(-0.5f, 0.0f, 0.0f);
    printf("glMatrixMode(MODELVIEW0) glGetError 0x%04x\n", (unsigned)glGetError());
    glMatrixMode(GL_MODELVIEW1_ARB); glLoadIdentity(); glTranslatef(0.5f, 0.0f, 0.0f);
    {
        GLenum e = glGetError();
        printf("glMatrixMode(MODELVIEW1) glGetError 0x%04x\n", (unsigned)e);
        if (e != 0) { printf("RESULT: FAIL - GL_MODELVIEW1_ARB matrix mode rejected\n"); return 1; }
    }
    glMatrixMode(GL_MODELVIEW0_ARB);

    /* reference: blending off, quad drawn through MODELVIEW0 only -> centred on column 8 */
    glDisable(GL_VERTEX_BLEND_ARB);
    drawQuad(0);
    printf("reference (no blend): column 8 lit=%d column 20 lit=%d (want 1, 0)\n", lit(8), lit(20));

    glEnable(GL_VERTEX_BLEND_ARB);
    pVertexBlend(2);
    printf("blend enable/count glGetError 0x%04x\n", (unsigned)glGetError());
    drawQuad(1);
    printf("blended: column 8 lit=%d column 20 lit=%d column 28 lit=%d (want 0, 1, 0) glGetError 0x%04x\n",
           lit(8), lit(20), lit(28), (unsigned)glGetError());
    if (lit(20) && !lit(8) && !lit(28)) { printf("RESULT: PASS\n"); return 0; }
    printf("RESULT: FAIL - the quad was not moved to the blended position\n");
    return 1;
}
