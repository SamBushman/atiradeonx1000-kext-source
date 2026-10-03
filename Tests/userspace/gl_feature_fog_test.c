/* gl_feature_fog_test.c - issue #128: GL 1.5 feature-completeness check for linear fog (GL_FOG), against the exact spec formula.
 *
 * Spec (GL 1.5 sec 3.10): for GL_LINEAR fog, f = (end - z) / (end - start) clamped to [0,1] where z is the fragment's eye-space
 * depth magnitude; C_result = f * C_src + (1 - f) * C_fog. Eye-space z is just the vertex's Z after the modelview transform - it
 * does not depend on the projection, so a plain glOrtho projection is fine here; only glTranslatef along Z varies the fog distance.
 * Two cases, each its own draw/clear/readback: a quad at eye-space z=-5 and one at z=-15, fog start=0 end=20 colour=white, source
 * colour pure red - checked against the formula computed in this program, not a hand-derived constant. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

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
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-10, 10, -10, 10, 0.1, 100);
    glDisable(GL_DEPTH_TEST);

    float fogcolor[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogf(GL_FOG_START, 0.0f);
    glFogf(GL_FOG_END, 20.0f);
    glFogfv(GL_FOG_COLOR, fogcolor);

    float zs[] = {-5.0f, -15.0f};
    int n = 2, i;
    static GLubyte buf[W * H * 4];
    int bad = 0;

    for (i = 0; i < n; i++) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(0, 0, zs[i]);
        glColor3f(1, 0, 0);
        glBegin(GL_QUADS);
        glVertex3f(-5, -5, 0); glVertex3f(5, -5, 0); glVertex3f(5, 5, 0); glVertex3f(-5, 5, 0);
        glEnd();
        glFinish();
        glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);

        float z = fabsf(zs[i]);
        float f = (20.0f - z) / (20.0f - 0.0f);
        if (f < 0) f = 0; if (f > 1) f = 1;
        float er = f * 1.0f + (1 - f) * 1.0f;   /* src red=1, fog red=1 -> channel unaffected */
        float eg = f * 0.0f + (1 - f) * 1.0f;
        float eb = f * 0.0f + (1 - f) * 1.0f;
        int wr = (int)(er * 255.0f + 0.5f), wg = (int)(eg * 255.0f + 0.5f), wb = (int)(eb * 255.0f + 0.5f);

        int x = W / 2, y = H / 2;
        GLubyte *p = buf + (y * W + x) * 4;
        int dr = abs((int)p[0] - wr), dg = abs((int)p[1] - wg), db = abs((int)p[2] - wb);
        int ok = dr <= 2 && dg <= 2 && db <= 2;
        printf("case %d (z=%.1f, f=%.3f): got %d,%d,%d want %d,%d,%d %s\n", i, zs[i], f, p[0], p[1], p[2], wr, wg, wb, ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
    }
    printf("RESULT: %s (%d mismatches of %d cases)\n", bad == 0 ? "PASS" : "FAIL", bad, n);
    return bad ? 1 : 0;
}
