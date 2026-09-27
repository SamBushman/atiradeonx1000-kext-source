/* cgl_probe.c - issue #64: a minimal, headless (offscreen pbuffer) real OpenGL sequence - context create,
 * a couple of state changes, one draw call, a readback, destroy - driven entirely through the public CGL
 * API. Real CGL resolves and calls into whichever ATIRadeonX1000GLDriver.bundle is installed at
 * /System/Library/Extensions/ATIRadeonX1000GLDriver.bundle, so every gldXxx entry point this exercises is
 * called with genuine, correctly-typed arguments - nothing here guesses a GLD SPI prototype.
 *
 * Run under IOKIT_RECORD_LOG=... DYLD_INSERT_LIBRARIES=.../iokit_record.dylib to capture the resulting
 * IOKit traffic. No window, no user interaction - safe to launch over SSH (see tiger-ssh skill).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static void die(const char *what, CGLError e) {
    fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e));
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf;
    GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = {
        kCGLPFAPBuffer,
        kCGLPFAAccelerated,
        kCGLPFANoRecovery,
        kCGLPFAColorSize, 32,
        (CGLPixelFormatAttribute)0
    };
    CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
    if (err) { die("ChoosePixelFormat", err); return 1; }
    printf("pixel formats matched: %d\n", (int)npix);
    if (npix == 0 || !pf) { fprintf(stderr, "FAIL: no pixel format\n"); return 1; }

    CGLContextObj ctx = NULL;
    err = CGLCreateContext(pf, NULL, &ctx);
    if (err) { die("CreateContext", err); return 1; }
    printf("context created: %p\n", (void *)ctx);
    CGLDestroyPixelFormat(pf);

    CGLPBufferObj pbuf = NULL;
    err = CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }

    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }

    if (getenv("CGL_PROBE_PAUSE")) {
        fprintf(stderr, "PAUSED pid=%d, sleeping %s sec for external inspection\n", (int)getpid(), getenv("CGL_PROBE_PAUSE"));
        sleep(atoi(getenv("CGL_PROBE_PAUSE")));
    }

    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }
    printf("pbuffer bound: %dx%d\n", W, H);
    static GLubyte buf[W * H * 4];

    const GLubyte *vendor = glGetString(GL_VENDOR);
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *version = glGetString(GL_VERSION);
    printf("GL_VENDOR=%s\n", vendor ? (const char *)vendor : "(null)");
    printf("GL_RENDERER=%s\n", renderer ? (const char *)renderer : "(null)");
    printf("GL_VERSION=%s\n", version ? (const char *)version : "(null)");

    glViewport(0, 0, W, H);
    glClearColor(0.25f, 0.5f, 0.75f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.8f, -0.8f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.8f, -0.8f);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.0f, 0.8f);
    glEnd();

    glFlush();
    GLenum e1 = glGetError();
    printf("glGetError after draw: 0x%x\n", (unsigned)e1);

    memset(buf, 0xAA, sizeof buf);
    glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    GLenum e2 = glGetError();
    printf("glGetError after readback: 0x%x\n", (unsigned)e2);

    /* checksum + a few sample pixels so two runs can be diffed without shipping the whole buffer */
    unsigned long sum = 0;
    int i;
    for (i = 0; i < W * H * 4; i++) sum += buf[i];
    printf("pixel checksum: %lu\n", sum);
    printf("center pixel (should be background or triangle color): %u %u %u %u\n",
           buf[((H / 2) * W + W / 2) * 4 + 0], buf[((H / 2) * W + W / 2) * 4 + 1],
           buf[((H / 2) * W + W / 2) * 4 + 2], buf[((H / 2) * W + W / 2) * 4 + 3]);
    printf("corner pixel (0,0) (background): %u %u %u %u\n", buf[0], buf[1], buf[2], buf[3]);

    CGLSetCurrentContext(NULL);
    CGLDestroyContext(ctx);
    CGLDestroyPBuffer(pbuf);
    printf("RESULT: PASS\n");
    return 0;
}
