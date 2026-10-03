/* gl_feature_stencil_wrap_test.c - issue #128 gap list: stencil wrap modes (GL_INCR_WRAP/GL_DECR_WRAP, core GL1.4+)
 * and two-sided stencil (checked for availability, not assumed present). */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

static void readback(GLubyte *out) {
    glFinish();
    static GLubyte buf[32*32*4];
    glReadPixels(0,0,32,32,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    memcpy(out, buf + (16*32+16)*4, 4);
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, kCGLPFAStencilSize,8, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs,&pf,&npix);
    if (err||npix==0||!pf) { die("ChoosePixelFormat",err); return 1; }
    CGLContextObj ctx=NULL; err=CGLCreateContext(pf,NULL,&ctx);
    if (err) { die("CreateContext",err); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf=NULL; err=CGLCreatePBuffer(32,32,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pbuf);
    if (err) { die("CreatePBuffer",err); return 1; }
    err=CGLSetCurrentContext(ctx); if (err) { die("SetCurrentContext",err); return 1; }
    err=CGLSetPBuffer(ctx,pbuf,0,0,0); if (err) { die("SetPBuffer",err); return 1; }
    glViewport(0,0,32,32);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    int bad = 0;
    GLubyte c[4];

    /* GL_INCR_WRAP: start stencil at 255, draw with stencil always-pass + INCR_WRAP -> should wrap to 0 */
    glClearStencil(255); glClear(GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_ALWAYS, 0, 0xff);
    glStencilOp(GL_KEEP, GL_KEEP, GL_INCR_WRAP);
    glColor3f(1,1,1);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    /* now read back the stencil value via a second pass that only draws if stencil == 0 */
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glStencilFunc(GL_EQUAL, 0, 0xff);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    glColor3f(0,1,0);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    readback(c);
    int ok1 = (c[0]==0 && c[1]==255 && c[2]==0);
    printf("INCR_WRAP 255->0: got %d,%d,%d want 0,255,0 %s\n", c[0],c[1],c[2], ok1?"OK":"MISMATCH");
    if (!ok1) bad++;

    /* GL_DECR_WRAP: start stencil at 0, draw with DECR_WRAP -> should wrap to 255 */
    glClearStencil(0); glClear(GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glStencilFunc(GL_ALWAYS, 0, 0xff);
    glStencilOp(GL_KEEP, GL_KEEP, GL_DECR_WRAP);
    glColor3f(1,1,1);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glStencilFunc(GL_EQUAL, 255, 0xff);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    glColor3f(0,1,0);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    readback(c);
    int ok2 = (c[0]==0 && c[1]==255 && c[2]==0);
    printf("DECR_WRAP 0->255: got %d,%d,%d want 0,255,0 %s\n", c[0],c[1],c[2], ok2?"OK":"MISMATCH");
    if (!ok2) bad++;

    /* two-sided stencil: just check extension availability, don't assume present */
    const char *ext = (const char*)glGetString(GL_EXTENSIONS);
    int has_two_side = ext && strstr(ext, "GL_EXT_stencil_two_side") != NULL;
    printf("GL_EXT_stencil_two_side: %s\n", has_two_side ? "AVAILABLE (not tested further here)" : "NOT AVAILABLE on this driver - two-sided stencil cannot be checked");

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
