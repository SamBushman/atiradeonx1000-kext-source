/* gl_feature_pointline_test.c - issue #128: GL 1.5 feature-completeness check for glPointSize/glLineWidth, against the
 * spec's basic guarantee (sec 3.3/3.4): with smoothing disabled, a point or line of width N is rasterized covering
 * (approximately) N pixels across its narrow dimension - not an exact-formula check like blend/logicop (the spec allows
 * implementation-defined rounding at fragment boundaries), but a real, falsifiable check that size actually SCALES: a
 * size-8 point/line must cover visibly and proportionately more pixels than a size-2 one, counted from a real readback,
 * not merely that glPointSize/glLineWidth returned GL_NO_ERROR. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

static int count_lit(GLubyte *buf) {
    int i, n = 0;
    for (i = 0; i < W * H; i++) if (buf[i * 4] > 10) n++;   /* red channel above background */
    return n;
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
    if (err || npix == 0 || !pf) { die("ChoosePixelFormat", err); return 1; }
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

    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST); glDisable(GL_POINT_SMOOTH); glDisable(GL_LINE_SMOOTH);
    glColor3f(1, 0, 0);

    static GLubyte buf[W * H * 4];
    int bad = 0;

    /* points: size 2 vs size 16 */
    float psizes[2] = {2.0f, 16.0f}; int pcounts[2];
    int i;
    for (i = 0; i < 2; i++) {
        glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(psizes[i]);
        glBegin(GL_POINTS); glVertex2f(W / 2, H / 2); glEnd();
        glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        pcounts[i] = count_lit(buf);
        printf("point size %.0f: %d pixels lit\n", psizes[i], pcounts[i]);
    }
    int point_ok = pcounts[0] >= 1 && pcounts[1] > pcounts[0] * 4;   /* size scales ~quadratically in area; demand at least a clear, large increase */
    printf("point size scaling: %s\n", point_ok ? "OK" : "MISMATCH");
    if (!point_ok) bad++;

    /* lines: width 1 vs width 10, horizontal segment, measure VERTICAL extent covered at one x column */
    float lwidths[2] = {1.0f, 10.0f}; int lcounts[2];
    for (i = 0; i < 2; i++) {
        glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
        glLineWidth(lwidths[i]);
        glBegin(GL_LINES); glVertex2f(5, H / 2); glVertex2f(W - 5, H / 2); glEnd();
        glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        lcounts[i] = count_lit(buf);
        printf("line width %.0f: %d pixels lit\n", lwidths[i], lcounts[i]);
    }
    int line_ok = lcounts[0] >= 1 && lcounts[1] > lcounts[0] * 4;
    printf("line width scaling: %s\n", line_ok ? "OK" : "MISMATCH");
    if (!line_ok) bad++;

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
