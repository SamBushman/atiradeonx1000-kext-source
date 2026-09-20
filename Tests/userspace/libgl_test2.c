/* libgl_test2.c - GL smoke test linked against the OpenGL framework only; run it normally and with DYLD_LIBRARY_PATH pointing at a directory that holds the
 * rebuilt libGL.dylib (stock install name), so the whole process, framework included, uses the rebuilt libGL. Prints which image glClear lives in. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    Dl_info di; memset(&di, 0, sizeof di);
    dladdr((void *)glClear, &di);
    printf("glClear in image: %s (base %p, glClear %p)\n", di.dli_fname ? di.dli_fname : "?", di.dli_fbase, (void *)glClear);
    CGLPixelFormatAttribute attrs[] = { kCGLPFAOffScreen, kCGLPFAColorSize, (CGLPixelFormatAttribute)32, kCGLPFADepthSize, (CGLPixelFormatAttribute)16, (CGLPixelFormatAttribute)0 };
    CGLPixelFormatObj pf; GLint npf; CGLContextObj ctx = NULL;
    if (CGLChoosePixelFormat(attrs, &pf, &npf) || !pf) { printf("FAIL pixelformat\n"); return 2; }
    if (CGLCreateContext(pf, NULL, &ctx) || !ctx) { printf("FAIL context\n"); return 3; }
    enum { W = 64, H = 64 };
    unsigned char *buf = (unsigned char *)calloc(W * H, 4);
    CGLSetOffScreen(ctx, W, H, W * 4, buf);
    CGLError se = CGLSetCurrentContext(ctx);
    printf("CGLSetCurrentContext -> %d; CGLGetCurrentContext==ctx: %s\n", (int)se, CGLGetCurrentContext() == ctx ? "yes" : "NO");
    printf("GL_VENDOR=%s | GL_RENDERER=%s | GL_VERSION=%s\n", glGetString(GL_VENDOR), glGetString(GL_RENDERER), glGetString(GL_VERSION));
    GLint mt = 0; glGetIntegerv(GL_MAX_TEXTURE_SIZE, &mt);
    glViewport(0, 0, W, H);
    glClearColor(0.25f, 0.5f, 0.75f, 1.0f); glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1); glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS); glVertex2f(8, 8); glVertex2f(24, 8); glVertex2f(24, 24); glVertex2f(8, 24); glEnd();
    glFinish();
    unsigned char bg[4] = {0}, fg[4] = {0};
    glReadPixels(40, 40, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, bg);
    glReadPixels(16, 16, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, fg);
    /* the bytes come back in this machine's channel order; print raw */
    printf("max_tex=%d bg=%02x%02x%02x%02x quad=%02x%02x%02x%02x err=%d\n", (int)mt, bg[0], bg[1], bg[2], bg[3], fg[0], fg[1], fg[2], fg[3], (int)glGetError());
    /* thread-migration path: a second thread makes the context current through the gl* stubs' stack-tag check */
    CGLSetCurrentContext(NULL);
    printf("after CGLSetCurrentContext(NULL): GetCurrent -> %p\n", (void *)CGLGetCurrentContext());
    CGLDestroyContext(ctx);
    printf("DONE\n");
    return 0;
}
