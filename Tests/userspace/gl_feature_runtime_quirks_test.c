/* gl_feature_runtime_quirks_test.c - issue #128/#193: checks for two already-documented runtime driver quirks (ati-x1900-driver-quirks skill, quirks 1 and 2) in a CGL PBUFFER context.
 *   quirk 1: writing a DISABLED generic vertex attribute (constant-broadcast via glVertexAttrib4f, never enabled via glEnableVertexAttribArray) into a varying corrupts the draw's output;
 *            control: the same attribute properly ENABLED with a real per-vertex array must render correctly.
 *   quirk 2: a texture2D() call inside a runtime if/else branch voids the fragment's output even when the branch is never taken; control: the same shader without texture2D() must render correctly.
 * #193: both quirks were first observed in a WINDOWED NSOpenGLContext and do NOT reproduce in this pbuffer; the test used to assert "still bugged" and so failed on the unmodified stock driver.
 * It now treats the controls as the pass/fail part (a control that mis-renders is a real failure) and REPORTS whether each defect reproduces in a pbuffer, without failing on either answer.
 * The window-backed version of the same checks is gl_quirks_window_probe.m (needs an Aqua session: run it through its .command launcher, see the header of that file). */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include "runtime_quirks_checks.h"

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
    err = CGLCreatePBuffer(32, 32, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }

    glViewport(0, 0, 32, 32);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    int bad = rq_run("pbuffer");

    printf("RESULT: %s (%d control mismatches; defect reproduction is informational, context = pbuffer)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
