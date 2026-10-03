/* gl_feature_stencil_test.c - issue #128: a GL 1.5 feature-completeness check, not an opcode-coverage probe. Verifies the stencil
 * buffer's actual PIXEL-LEVEL result against the GL 1.5 spec's own semantics for glStencilFunc/glStencilOp - not just that some
 * PM4 opcode got emitted (that is #42's concern; this is "does the result match what the spec requires").
 *
 * Sequence (all against the real driver via CGL, same pattern as cgl_probe.c):
 *   1. Clear color=black, stencil=0.
 *   2. glStencilFunc(GL_ALWAYS, 1, 0xff); glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE) - draw a quad over the LEFT HALF only, colour red.
 *      Per spec: GL_ALWAYS means the stencil test always passes, GL_REPLACE on pass writes the ref value (1) into the stencil buffer
 *      wherever this quad covers. Left half's stencil is now 1; right half's stencil is still 0.
 *   3. glStencilFunc(GL_EQUAL, 1, 0xff); glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP) - draw a quad over the WHOLE screen, colour green.
 *      Per spec: the stencil test now only passes where stencil == 1, i.e. only the left half; the right half's fragments are
 *      discarded before ever reaching the color buffer.
 * Expected result: left half pixels are green (0,255,0), right half pixels are UNCHANGED from the black clear (0,0,0) - the green
 * quad's right-half fragments must never have been written. Sampled at several points per half, not just the centre, since a driver
 * bug could plausibly affect only part of a region (see the ati-x1900-driver-quirks skill's catalogue of narrowly-scoped bugs). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

static void quad(float x0, float y0, float x1, float y1) {
    glBegin(GL_QUADS);
    glVertex2f(x0, y0); glVertex2f(x1, y0); glVertex2f(x1, y1); glVertex2f(x0, y1);
    glEnd();
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = {
        kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery,
        kCGLPFAColorSize, 32, kCGLPFAStencilSize, 8,
        (CGLPixelFormatAttribute)0
    };
    CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
    if (err || npix == 0 || !pf) { die("ChoosePixelFormat", err); fprintf(stderr, "npix=%d\n", npix); return 1; }
    CGLContextObj ctx = NULL;
    err = CGLCreateContext(pf, NULL, &ctx);
    if (err) { die("CreateContext", err); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf = NULL;
    err = CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }

    GLint stencilBits = 0;
    glGetIntegerv(GL_STENCIL_BITS, &stencilBits);
    printf("GL_STENCIL_BITS=%d\n", stencilBits);
    if (stencilBits == 0) { fprintf(stderr, "FAIL: no stencil buffer allocated, cannot test\n"); return 1; }

    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();

    glClearColor(0, 0, 0, 1);
    glClearStencil(0);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_ALWAYS, 1, 0xff);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    glColor3f(1, 0, 0);
    quad(0, 0, W / 2, H);   /* left half: stencil -> 1 */

    glStencilFunc(GL_EQUAL, 1, 0xff);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    glColor3f(0, 1, 0);
    quad(0, 0, W, H);       /* whole screen: only passes where stencil == 1 */

    glFinish();
    static GLubyte buf[W * H * 4];
    glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);

    int bad = 0;
    int leftxs[] = {2, 10, 20, 31};
    int rightxs[] = {33, 44, 54, 61};
    int ys[] = {2, 16, 32, 48, 61};
    int i, j;
    for (j = 0; j < 5; j++) for (i = 0; i < 4; i++) {
        int x = leftxs[i], y = ys[j];
        GLubyte *p = buf + (y * W + x) * 4;
        int ok = (p[0] == 0 && p[1] == 255 && p[2] == 0);
        if (!ok) { bad++; printf("LEFT (%d,%d): got %d,%d,%d,%d want 0,255,0,* MISMATCH\n", x, y, p[0], p[1], p[2], p[3]); }
    }
    for (j = 0; j < 5; j++) for (i = 0; i < 4; i++) {
        int x = rightxs[i], y = ys[j];
        GLubyte *p = buf + (y * W + x) * 4;
        int ok = (p[0] == 0 && p[1] == 0 && p[2] == 0);
        if (!ok) { bad++; printf("RIGHT (%d,%d): got %d,%d,%d,%d want 0,0,0,* MISMATCH\n", x, y, p[0], p[1], p[2], p[3]); }
    }
    printf("RESULT: %s (%d mismatches of 40 sampled)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
