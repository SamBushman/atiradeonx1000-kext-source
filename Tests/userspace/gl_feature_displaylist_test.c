/* gl_feature_displaylist_test.c - issue #128: GL 1.5 feature-completeness check for display lists (glNewList/glEndList/
 * glCallList, sec 5.4), against the exact spec guarantee: executing a list must produce the SAME result as issuing the
 * same commands in immediate mode. Checked two ways: (1) a simple list reproduces an immediate-mode reference image
 * exactly: (2) GL_COMPILE_AND_EXECUTE actually executes immediately AND stores the list (checked by rendering once via
 * compile-and-execute with nothing else drawn, then calling the list again and checking the result is unchanged, i.e.
 * idempotent replay - not just that no GL error occurred). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

static void draw_scene(void) {
    glColor3f(1, 0.5f, 0.25f);
    glBegin(GL_TRIANGLES);
    glVertex2f(5, 5); glVertex2f(55, 10); glVertex2f(20, 55);
    glEnd();
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
    glDisable(GL_DEPTH_TEST);

    static GLubyte ref[W * H * 4], listbuf[W * H * 4], execbuf[W * H * 4];
    int bad = 0;

    /* reference: immediate mode */
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    draw_scene();
    glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, ref);

    /* GL_COMPILE: build the list with no immediate drawing, then call it and compare to the reference */
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    draw_scene();
    glEndList();
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glCallList(list);
    glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, listbuf);
    int diff1 = memcmp(ref, listbuf, sizeof ref);
    printf("GL_COMPILE + glCallList matches immediate mode: %s\n", diff1 == 0 ? "OK" : "MISMATCH");
    if (diff1) bad++;

    /* GL_COMPILE_AND_EXECUTE: building the list must ALSO draw immediately */
    GLuint list2 = glGenLists(1);
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glNewList(list2, GL_COMPILE_AND_EXECUTE);
    draw_scene();
    glEndList();
    glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, execbuf);
    int diff2 = memcmp(ref, execbuf, sizeof ref);
    printf("GL_COMPILE_AND_EXECUTE draws immediately:    %s\n", diff2 == 0 ? "OK" : "MISMATCH");
    if (diff2) bad++;

    /* calling the same list a second time (idempotent replay) must give the same result again */
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glCallList(list2);
    glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, execbuf);
    int diff3 = memcmp(ref, execbuf, sizeof ref);
    printf("replaying the stored list again matches:     %s\n", diff3 == 0 ? "OK" : "MISMATCH");
    if (diff3) bad++;

    printf("RESULT: %s (%d mismatches of 3 checks)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
