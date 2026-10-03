/* gl_feature_feedback_test.c - issue #128: GL 1.5 feature-completeness check for GL_FEEDBACK render mode
 * (glFeedbackBuffer/glRenderMode, sec 6.1.3), against the exact spec-defined token stream: GL_2D feedback type for a
 * GL_POINTS primitive writes GL_POINT_TOKEN followed by the point's window-space (x,y), which this test computes
 * independently from the same ortho/viewport setup and compares exactly (window coordinates are an exact affine
 * transform of the object coordinates here, no rounding ambiguity beyond float precision). */
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
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();

    static GLfloat fb[256];
    glFeedbackBuffer(256, GL_2D, fb);
    glRenderMode(GL_FEEDBACK);

    float ox = 20.0f, oy = 40.0f;   /* object-space point; with this ortho+viewport, window coords are exactly (ox, oy) */
    glBegin(GL_POINTS);
    glVertex2f(ox, oy);
    glEnd();

    GLint used = glRenderMode(GL_RENDER);
    printf("feedback entries used: %d\n", used);

    int bad = 0;
    if (used < 3) { printf("FAIL: expected at least a token + 2 coords, got %d values\n", used); bad++; }
    else {
        int tok = (int)fb[0];
        float wx = fb[1], wy = fb[2];
        printf("token=%d (want GL_POINT_TOKEN=%d) window=(%.3f,%.3f) want (%.3f,%.3f)\n", tok, GL_POINT_TOKEN, wx, wy, ox, oy);
        if (tok != GL_POINT_TOKEN) bad++;
        if (fabsf(wx - ox) > 0.01f || fabsf(wy - oy) > 0.01f) bad++;
    }
    printf("RESULT: %s (%d mismatches)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
