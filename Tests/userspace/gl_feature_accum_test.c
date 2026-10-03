/* gl_feature_accum_test.c - issue #128: GL 1.5 feature-completeness check for the accumulation buffer (glAccum,
 * sec 4.2.3), against the exact spec formulas:
 *   GL_ACCUM:  acc += value * color
 *   GL_LOAD:   acc = value * color
 *   GL_RETURN: color = acc * value
 *   GL_MULT:   acc *= value
 *   GL_ADD:    acc += value (a constant, not the colour buffer)
 */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
static int clampb(float x) { if (x < 0) x = 0; if (x > 1) x = 1; return (int)(x * 255.0f + 0.5f); }

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = {
        kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, kCGLPFAAccumSize, 32,
        (CGLPixelFormatAttribute)0
    };
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

    GLint accumBits = 0; glGetIntegerv(GL_ACCUM_RED_BITS, &accumBits);
    printf("GL_ACCUM_RED_BITS=%d\n", accumBits);
    if (accumBits == 0) { fprintf(stderr, "FAIL: no accumulation buffer allocated, cannot test\n"); return 1; }

    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    static GLubyte buf[W * H * 4];
    int bad = 0;

    /* GL_LOAD then GL_ACCUM then GL_RETURN: acc = 0.5*red, acc += 0.5*red again -> acc = red (1,0,0); return *1.0 -> red */
    glClearColor(1, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glAccum(GL_LOAD, 0.5f);
    glAccum(GL_ACCUM, 0.5f);
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);   /* prove RETURN really writes the colour buffer, not a no-op */
    glAccum(GL_RETURN, 1.0f);
    glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    {
        GLubyte *p = buf + (H / 2 * W + W / 2) * 4;
        int wr = clampb(1.0f), wg = 0, wb = 0;
        int ok = abs(p[0] - wr) <= 2 && abs(p[1] - wg) <= 2 && abs(p[2] - wb) <= 2;
        printf("LOAD+ACCUM+RETURN  got %d,%d,%d want %d,%d,%d %s\n", p[0], p[1], p[2], wr, wg, wb, ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
    }

    /* GL_MULT: load green at value 1.0 (acc=1,0,1,0... wait green only: acc=(0,1,0)), mult by 0.5 -> acc=(0,0.5,0), return *1 */
    glClearColor(0, 1, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glAccum(GL_LOAD, 1.0f);
    glAccum(GL_MULT, 0.5f);
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glAccum(GL_RETURN, 1.0f);
    glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    {
        GLubyte *p = buf + (H / 2 * W + W / 2) * 4;
        int wr = 0, wg = clampb(0.5f), wb = 0;
        int ok = abs(p[0] - wr) <= 2 && abs(p[1] - wg) <= 2 && abs(p[2] - wb) <= 2;
        printf("LOAD+MULT+RETURN   got %d,%d,%d want %d,%d,%d %s\n", p[0], p[1], p[2], wr, wg, wb, ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
    }

    /* GL_ADD: load blue (acc=0,0,1), add a constant 0.25 to every channel, return *1 -> (0.25, 0.25, 1.0) clamped */
    glClearColor(0, 0, 1, 1); glClear(GL_COLOR_BUFFER_BIT);
    glAccum(GL_LOAD, 1.0f);
    glAccum(GL_ADD, 0.25f);
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glAccum(GL_RETURN, 1.0f);
    glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    {
        GLubyte *p = buf + (H / 2 * W + W / 2) * 4;
        int wr = clampb(0.25f), wg = clampb(0.25f), wb = clampb(1.0f);
        int ok = abs(p[0] - wr) <= 2 && abs(p[1] - wg) <= 2 && abs(p[2] - wb) <= 2;
        printf("LOAD+ADD+RETURN    got %d,%d,%d want %d,%d,%d %s\n", p[0], p[1], p[2], wr, wg, wb, ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
    }

    printf("RESULT: %s (%d mismatches of 3 cases)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
