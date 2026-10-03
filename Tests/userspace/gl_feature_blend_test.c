/* gl_feature_blend_test.c - issue #128: GL 1.5 feature-completeness check for alpha blending (glBlendFunc), checked against the
 * exact spec formula, not just that a blend-related opcode fires.
 *
 * Spec (GL 1.5 sec 4.1.8): with glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA), the blended colour is
 *     C_result = C_src * A_src + C_dst * (1 - A_src)
 * Sequence: clear to a known opaque background colour, disable depth test, draw one quad per test case with a known
 * src colour/alpha, read back and compare against the formula computed in this program (not hand-derived constants),
 * with the small rounding tolerance real 8-bit framebuffers require. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

typedef struct { float sr, sg, sb, sa; } Case;

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
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    const float dr = 0.20f, dg = 0.40f, db = 0.80f;   /* background colour the quads blend onto */
    Case cases[] = {
        {1.0f, 0.0f, 0.0f, 1.0f},   /* opaque red: result should just be red */
        {1.0f, 0.0f, 0.0f, 0.0f},   /* fully transparent red: result should be unchanged background */
        {1.0f, 0.0f, 0.0f, 0.5f},   /* half-alpha red */
        {0.0f, 1.0f, 0.0f, 0.25f},  /* quarter-alpha green */
        {1.0f, 1.0f, 0.0f, 0.75f},  /* three-quarter-alpha yellow */
    };
    int n = sizeof cases / sizeof cases[0];
    static GLubyte buf[W * H * 4];
    int bad = 0;

    int i;
    for (i = 0; i < n; i++) {
        glClearColor(dr, dg, db, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor4f(cases[i].sr, cases[i].sg, cases[i].sb, cases[i].sa);
        glBegin(GL_QUADS);
        glVertex2f(0, 0); glVertex2f(W, 0); glVertex2f(W, H); glVertex2f(0, H);
        glEnd();
        glFinish();
        glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);

        float er = cases[i].sr * cases[i].sa + dr * (1 - cases[i].sa);
        float eg = cases[i].sg * cases[i].sa + dg * (1 - cases[i].sa);
        float eb = cases[i].sb * cases[i].sa + db * (1 - cases[i].sa);
        int wr = (int)(er * 255.0f + 0.5f), wg = (int)(eg * 255.0f + 0.5f), wb = (int)(eb * 255.0f + 0.5f);

        int x = W / 2, y = H / 2;
        GLubyte *p = buf + (y * W + x) * 4;
        int dr8 = abs((int)p[0] - wr), dg8 = abs((int)p[1] - wg), db8 = abs((int)p[2] - wb);
        int ok = dr8 <= 2 && dg8 <= 2 && db8 <= 2;   /* +-2/255 tolerance for 8-bit rounding */
        printf("case %d (src %.2f,%.2f,%.2f a=%.2f): got %d,%d,%d want %d,%d,%d %s\n",
               i, cases[i].sr, cases[i].sg, cases[i].sb, cases[i].sa, p[0], p[1], p[2], wr, wg, wb, ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
    }
    printf("RESULT: %s (%d mismatches of %d cases)\n", bad == 0 ? "PASS" : "FAIL", bad, n);
    return bad ? 1 : 0;
}
