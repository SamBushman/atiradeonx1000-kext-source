/* gl_feature_selection_test.c - issue #128: GL 1.5 feature-completeness check for GL_SELECT render mode (glRenderMode,
 * glLoadName/glPushName, sec 5.3), against the exact spec behaviour: only primitives whose geometry survives clipping
 * against the current viewing volume generate a hit record, and each hit record carries the name stack's contents.
 * Three points at different object-space Y, a restricted projection volume that only the middle one falls inside: only
 * ONE hit record should be produced, carrying name 2 (not 1 or 3). */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

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
    err = CGLCreatePBuffer(64, 64, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }

    glViewport(0, 0, 64, 64);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glOrtho(-1, 1, 8, 12, -1, 1);   /* only y in [8,12] is visible: point at y=10 is in, y=0 and y=20 are clipped out */
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();

    static GLuint selbuf[64];
    glSelectBuffer(64, selbuf);
    glRenderMode(GL_SELECT);
    glInitNames();
    glPushName(0);

    glLoadName(1); glBegin(GL_POINTS); glVertex2f(0, 0); glEnd();
    glLoadName(2); glBegin(GL_POINTS); glVertex2f(0, 10); glEnd();
    glLoadName(3); glBegin(GL_POINTS); glVertex2f(0, 20); glEnd();

    GLint hits = glRenderMode(GL_RENDER);
    printf("hits=%d\n", hits);
    int bad = 0;
    if (hits != 1) { printf("FAIL: expected exactly 1 hit, got %d\n", hits); bad++; }
    else {
        GLuint numNames = selbuf[0];
        GLuint name = selbuf[3 + numNames - 1];   /* record layout: numNames, zmin, zmax, names[numNames] */
        printf("hit record: numNames=%u name=%u (want 2)\n", numNames, name);
        if (name != 2) bad++;
    }
    printf("RESULT: %s (%d mismatches)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
