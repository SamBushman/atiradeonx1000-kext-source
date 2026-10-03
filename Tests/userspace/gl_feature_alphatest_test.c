/* gl_feature_alphatest_test.c - issue #128 gap list: glAlphaFunc/GL_ALPHA_TEST, never checked before. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static void readback(GLubyte *out) {
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

    int bad = 0;
    GLubyte c[4];

    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.5f);

    /* alpha 0.2 should FAIL the test -> background stays visible */
    glClearColor(0,0,1,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1,0,0,0.2f);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    readback(c);
    int ok1 = (c[0]==0 && c[1]==0 && c[2]==255);
    printf("ALPHA_TEST GREATER 0.5, frag alpha=0.2 (fails): got %d,%d,%d want 0,0,255 (background) %s\n", c[0],c[1],c[2], ok1?"OK":"MISMATCH");
    if (!ok1) bad++;

    /* alpha 0.8 should PASS -> red drawn */
    glClearColor(0,0,1,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1,0,0,0.8f);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    readback(c);
    int ok2 = (c[0]==255 && c[1]==0 && c[2]==0);
    printf("ALPHA_TEST GREATER 0.5, frag alpha=0.8 (passes): got %d,%d,%d want 255,0,0 %s\n", c[0],c[1],c[2], ok2?"OK":"MISMATCH");
    if (!ok2) bad++;

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
