/* diag_accum.c - isolating the GL_ADD accumulation-buffer anomaly from gl_feature_accum_test.c (issue #128): is LOAD+RETURN
 * alone correct (sanity baseline), and exactly what does ADD do to a known-nonzero acc state? Each stage printed separately. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 64
#define H 64

static void readback(const char *label) {
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    printf("%-28s centre = %d,%d,%d,%d\n", label, p[0], p[1], p[2], p[3]);
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, kCGLPFAAccumSize, 32, (CGLPixelFormatAttribute)0 };
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

    printf("--- stage 1: LOAD(1.0) then RETURN(1.0) alone, no ADD ---\n");
    glClearColor(0, 0, 1, 1); glClear(GL_COLOR_BUFFER_BIT);
    readback("after clear to blue");
    glAccum(GL_LOAD, 1.0f);
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    readback("after clear to black (pre-RETURN)");
    glAccum(GL_RETURN, 1.0f);
    readback("after RETURN(1.0) - want blue back");

    printf("--- stage 2: same, but now ADD(0.25) before RETURN ---\n");
    glClearColor(0, 0, 1, 1); glClear(GL_COLOR_BUFFER_BIT);
    glAccum(GL_LOAD, 1.0f);
    glAccum(GL_ADD, 0.25f);

    printf("--- stage 2b: same as stage 2, but with glFinish() between LOAD and ADD ---\n");
    glClearColor(0, 0, 1, 1); glClear(GL_COLOR_BUFFER_BIT);
    glAccum(GL_LOAD, 1.0f);
    glFinish();
    glAccum(GL_ADD, 0.25f);
    glFinish();
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    readback("after clear to black (pre-RETURN), stage 2b");
    glAccum(GL_RETURN, 1.0f);
    readback("stage 2b RETURN - want (0.25,0.25,1.0)=64,64,255");
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    readback("after clear to black (pre-RETURN)");
    glAccum(GL_RETURN, 1.0f);
    readback("after ADD(0.25)+RETURN - want (0.25,0.25,1.0)=64,64,255");

    printf("--- stage 3: ADD(0.25) on an all-zero acc (LOAD from black) ---\n");
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glAccum(GL_LOAD, 1.0f);
    glAccum(GL_ADD, 0.25f);
    glAccum(GL_RETURN, 1.0f);
    readback("LOAD(black)+ADD(0.25)+RETURN - want (0.25,0.25,0.25)=64,64,64");

    printf("--- stage 4: ADD(0.25) applied TWICE on an all-zero acc ---\n");
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glAccum(GL_LOAD, 1.0f);
    glAccum(GL_ADD, 0.25f);
    glAccum(GL_ADD, 0.25f);
    glAccum(GL_RETURN, 1.0f);
    readback("LOAD(black)+ADD(0.25)x2+RETURN - want (0.5,0.5,0.5)=128,128,128 if ADD is cumulative");

    return 0;
}
