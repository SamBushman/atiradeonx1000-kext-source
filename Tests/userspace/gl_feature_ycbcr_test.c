/* gl_feature_ycbcr_test.c - APPLE_ycbcr_422: a packed YCbCr 4:2:2 texture format should decode to the
 * correct RGB via the standard YCbCr->RGB conversion when sampled. Never checked before. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_YCBCR_422_APPLE
#define GL_YCBCR_422_APPLE 0x85B9
#endif
#ifndef GL_UNSIGNED_SHORT_8_8_APPLE
#define GL_UNSIGNED_SHORT_8_8_APPLE 0x85BA
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs,&pf,&npix);
    if (err||npix==0||!pf) { die("ChoosePixelFormat",err); return 1; }
    CGLContextObj ctx=NULL; err=CGLCreateContext(pf,NULL,&ctx);
    if (err) { die("CreateContext",err); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf=NULL; err=CGLCreatePBuffer(W,H,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pbuf);
    if (err) { die("CreatePBuffer",err); return 1; }
    err=CGLSetCurrentContext(ctx); if (err) { die("SetCurrentContext",err); return 1; }
    err=CGLSetPBuffer(ctx,pbuf,0,0,0); if (err) { die("SetPBuffer",err); return 1; }
    glViewport(0,0,W,H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    /* a 2x1 YCbCr 4:2:2 block: each GL_UNSIGNED_SHORT_8_8_APPLE texel packs (Y, Cb) or (Y, Cr) depending on
     * byte order convention - use the well-known "white" case: Y=235 (full white luma, per video-range
     * convention), Cb=Cr=128 (neutral chroma) should decode to a near-white/gray RGB regardless of exact
     * channel order, an unambiguous sanity check that doesn't depend on getting the YCbCr matrix exactly right */
    GLubyte block[4] = {235,128, 235,128};   /* 2 texels, each (Y=235, Cb_or_Cr=128) */
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    while (glGetError() != GL_NO_ERROR) {}
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,2,1,0,GL_YCBCR_422_APPLE,GL_UNSIGNED_SHORT_8_8_APPLE,block);
    GLenum e = glGetError();
    printf("YCbCr 4:2:2 upload (Y=235, chroma=128, neutral): glGetError=0x%04x\n", (unsigned)e);
    if (e != GL_NO_ERROR) { printf("RESULT: FAIL (upload errored)\n"); return 1; }

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor3f(1,1,1);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(-1,-1); glTexCoord2f(1,0); glVertex2f(1,-1);
    glTexCoord2f(1,1); glVertex2f(1,1); glTexCoord2f(0,1); glVertex2f(-1,1);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    printf("sampled YCbCr texel: got %d,%d,%d\n", p[0],p[1],p[2]);
    /* neutral chroma + near-max luma should decode to a near-white/light-gray RGB, roughly equal channels,
     * not something wildly colored (which would indicate the chroma/luma channels got swapped or misread) */
    int balanced = (abs((int)p[0]-(int)p[1]) < 40) && (abs((int)p[1]-(int)p[2]) < 40);
    int bright = (p[0] > 180 && p[1] > 180 && p[2] > 180);
    int ok = balanced && bright;
    printf("  balanced+bright (neutral chroma, high luma decoded sanely) = %s\n", ok?"YES":"NO");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
