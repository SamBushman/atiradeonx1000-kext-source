/* gl_feature_abgr_bgra_test.c - EXT_abgr/EXT_bgra: upload with alternate component orderings and confirm
 * the components land in the right place after sampling (vs. the standard GL_RGBA order). Never checked. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_ABGR_EXT
#define GL_ABGR_EXT 0x8000
#endif
#ifndef GL_BGRA
#define GL_BGRA 0x80E1
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static void sample(GLuint tex, GLubyte *out) {
    glBindTexture(GL_TEXTURE_2D, tex);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(-1,-1); glTexCoord2f(1,0); glVertex2f(1,-1);
    glTexCoord2f(1,1); glVertex2f(1,1); glTexCoord2f(0,1); glVertex2f(-1,1);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    out[0]=p[0]; out[1]=p[1]; out[2]=p[2]; out[3]=p[3];
}

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
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor3f(1,1,1);

    int bad = 0;

    /* ABGR byte order: A,B,G,R in memory. Want final sampled RGBA = (10,20,30,40), so memory bytes = (40,30,20,10) */
    GLubyte abgr_mem[4] = {40,30,20,10};
    GLuint t1; glGenTextures(1,&t1); glBindTexture(GL_TEXTURE_2D,t1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_ABGR_EXT,GL_UNSIGNED_BYTE,abgr_mem);
    GLubyte c1[4]; sample(t1, c1);
    int ok1 = (c1[0]==10 && c1[1]==20 && c1[2]==30 && c1[3]==40);
    printf("ABGR upload (mem A,B,G,R=40,30,20,10): sampled RGBA=%d,%d,%d,%d want 10,20,30,40 %s\n", c1[0],c1[1],c1[2],c1[3], ok1?"OK":"MISMATCH");
    if (!ok1) bad++;

    /* BGRA byte order: B,G,R,A in memory. Want RGBA=(10,20,30,40) -> memory = (30,20,10,40) */
    GLubyte bgra_mem[4] = {30,20,10,40};
    GLuint t2; glGenTextures(1,&t2); glBindTexture(GL_TEXTURE_2D,t2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_BGRA,GL_UNSIGNED_BYTE,bgra_mem);
    GLubyte c2[4]; sample(t2, c2);
    int ok2 = (c2[0]==10 && c2[1]==20 && c2[2]==30 && c2[3]==40);
    printf("BGRA upload (mem B,G,R,A=30,20,10,40): sampled RGBA=%d,%d,%d,%d want 10,20,30,40 %s\n", c2[0],c2[1],c2[2],c2[3], ok2?"OK":"MISMATCH");
    if (!ok2) bad++;

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
