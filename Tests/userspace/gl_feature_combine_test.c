/* gl_feature_combine_test.c - issue #128: GL 1.5 feature-completeness check for GL_ARB_texture_env_combine /
 * GL_TEXTURE_ENV_MODE=GL_COMBINE modes, against the exact per-mode spec formula. GL 1.5 core requires GL_COMBINE,
 * GL_ADD, GL_SUBTRACT as texture env modes (sec 3.8.16) in addition to the long-standing GL_MODULATE/GL_DECAL/etc.
 * Single texture unit, constant per-texel colour, GL_PREVIOUS = GL_CONSTANT fragment colour, so the expected result
 * is a plain per-channel formula with no interpolation/sampling ambiguity. */
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
    glDisable(GL_DEPTH_TEST); glDisable(GL_LIGHTING);

    GLuint tex; glGenTextures(1, &tex); glBindTexture(GL_TEXTURE_2D, tex);
    float tr = 0.6f, tg = 0.3f, tb = 0.9f;
    GLubyte texel[3] = { (GLubyte)(tr * 255), (GLubyte)(tg * 255), (GLubyte)(tb * 255) };
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, texel);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_TEXTURE_2D);

    float fr = 0.4f, fg = 0.8f, fb = 0.2f;   /* the fragment (vertex) colour, i.e. GL_PREVIOUS going into this single-unit combine */

    static GLubyte buf[W * H * 4];
    int bad = 0;

    /* case 1: GL_ADD env mode (GL 1.5 core, not GL_COMBINE) - result = clamp(fragment + texture) */
    {
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);
        glColor3f(fr, fg, fb);
        glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS); glVertex2f(0, 0); glVertex2f(W, 0); glVertex2f(W, H); glVertex2f(0, H); glEnd();
        glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        GLubyte *p = buf + (H / 2 * W + W / 2) * 4;
        int wr = clampb(fr + tr), wg = clampb(fg + tg), wb = clampb(fb + tb);
        int ok = abs(p[0] - wr) <= 1 && abs(p[1] - wg) <= 1 && abs(p[2] - wb) <= 1;
        printf("GL_ADD           got %d,%d,%d want %d,%d,%d %s\n", p[0], p[1], p[2], wr, wg, wb, ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
    }
    /* case 2: GL_COMBINE / GL_SUBTRACT (GL_PREVIOUS - GL_TEXTURE) */
    {
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
        glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_SUBTRACT);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_PREVIOUS); glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE); glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_SRC_COLOR);
        glColor3f(fr, fg, fb);
        glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS); glVertex2f(0, 0); glVertex2f(W, 0); glVertex2f(W, H); glVertex2f(0, H); glEnd();
        glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        GLubyte *p = buf + (H / 2 * W + W / 2) * 4;
        int wr = clampb(fr - tr), wg = clampb(fg - tg), wb = clampb(fb - tb);
        int ok = abs(p[0] - wr) <= 1 && abs(p[1] - wg) <= 1 && abs(p[2] - wb) <= 1;
        printf("COMBINE/SUBTRACT got %d,%d,%d want %d,%d,%d %s\n", p[0], p[1], p[2], wr, wg, wb, ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
    }
    /* case 3: GL_COMBINE / GL_INTERPOLATE, GL_PREVIOUS and GL_TEXTURE blended by a constant alpha */
    {
        float constcol[4] = {0, 0, 0, 0.3f};   /* alpha used as the interpolation factor */
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
        glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_INTERPOLATE);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_PREVIOUS); glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE); glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_CONSTANT); glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND2_RGB, GL_SRC_ALPHA);
        glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, constcol);
        glColor3f(fr, fg, fb);
        glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS); glVertex2f(0, 0); glVertex2f(W, 0); glVertex2f(W, H); glVertex2f(0, H); glEnd();
        glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        GLubyte *p = buf + (H / 2 * W + W / 2) * 4;
        float a = 0.3f;
        int wr = clampb(fr * a + tr * (1 - a)), wg = clampb(fg * a + tg * (1 - a)), wb = clampb(fb * a + tb * (1 - a));
        int ok = abs(p[0] - wr) <= 2 && abs(p[1] - wg) <= 2 && abs(p[2] - wb) <= 2;
        printf("COMBINE/INTERP   got %d,%d,%d want %d,%d,%d %s\n", p[0], p[1], p[2], wr, wg, wb, ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
    }
    printf("RESULT: %s (%d mismatches of 3 cases)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
