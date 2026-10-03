/* gl_feature_cullface_test.c - issue #128 gap list: glCullFace/glFrontFace correctness, never checked before. */
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
    out[0]=p[0]; out[1]=p[1]; out[2]=p[2];
}

/* a CCW-wound (in standard GL screen orientation) triangle covering the center */
static void draw_ccw_tri(void) {
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f,-0.8f); glVertex2f(0.8f,-0.8f); glVertex2f(0.0f,0.8f);
    glEnd();
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
    GLubyte c[3];

    /* default: GL_FRONT_FACE=GL_CCW, GL_CULL_FACE disabled -> triangle (wound CCW) renders regardless */
    glDisable(GL_CULL_FACE);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1); draw_ccw_tri();
    readback(c);
    int ok1 = (c[0]==255);
    printf("CULL_FACE disabled: got %d,%d,%d want 255,255,255 %s\n", c[0],c[1],c[2], ok1?"OK":"MISMATCH");
    if (!ok1) bad++;

    /* FrontFace=CCW (default), CullFace=BACK: our CCW triangle IS front-facing -> should still render */
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1); draw_ccw_tri();
    readback(c);
    int ok2 = (c[0]==255);
    printf("CULL_FACE=BACK, FrontFace=CCW, CCW tri (front-facing): got %d,%d,%d want 255,255,255 %s\n", c[0],c[1],c[2], ok2?"OK":"MISMATCH");
    if (!ok2) bad++;

    /* FrontFace=CW, CullFace=BACK: our CCW triangle is now back-facing -> should be culled (background shows) */
    glFrontFace(GL_CW);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1); draw_ccw_tri();
    readback(c);
    int ok3 = (c[0]==0);
    printf("CULL_FACE=BACK, FrontFace=CW, CCW tri (now back-facing): got %d,%d,%d want 0,0,0 %s\n", c[0],c[1],c[2], ok3?"OK":"MISMATCH");
    if (!ok3) bad++;

    /* FrontFace=CW, CullFace=FRONT: now the "front" (per CW convention) is culled, but our triangle is
     * back-facing per that convention, so it should render */
    glCullFace(GL_FRONT);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1); draw_ccw_tri();
    readback(c);
    int ok4 = (c[0]==255);
    printf("CULL_FACE=FRONT, FrontFace=CW, CCW tri (back per CW, not culled): got %d,%d,%d want 255,255,255 %s\n", c[0],c[1],c[2], ok4?"OK":"MISMATCH");
    if (!ok4) bad++;

    printf("RESULT: %s (%d mismatches of 4 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
