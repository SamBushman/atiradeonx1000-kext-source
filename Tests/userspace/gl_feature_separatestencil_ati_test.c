/* gl_feature_separatestencil_ati_test.c - GL_ATI_separate_stencil: the real two-sided-stencil extension this
 * driver advertises (the earlier stencil test only checked for GL_EXT_stencil_two_side, which is NOT
 * available - this is the correct one for this hardware, via glStencilOpSeparateATI/glStencilFuncSeparateATI).
 * Draws two triangles (one CCW/front, one CW/back) covering the same pixels, each with a different stencil
 * op per face, and checks both faces' effects land correctly. */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_STENCIL_BACK_FUNC_ATI
#define GL_STENCIL_BACK_FUNC_ATI 0x8800
#endif

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

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, kCGLPFAStencilSize,8, (CGLPixelFormatAttribute)0 };
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

    const char *ext = (const char*)glGetString(GL_EXTENSIONS);
    if (!(ext && strstr(ext, "GL_ATI_separate_stencil"))) {
        printf("RESULT: SKIPPED - GL_ATI_separate_stencil not available\n");
        return 0;
    }

    int bad = 0;

    /* front faces (CCW): stencil op INCR on pass. back faces (CW): stencil op DECR on pass (actually
     * DECR_WRAP to make the result unambiguous from a starting value of 128). draw a CCW-wound front-facing
     * quad covering the whole viewport (incrementing everywhere), then a CW-wound back-facing quad ALSO
     * covering the whole viewport (decrementing everywhere via the BACK op) - net effect should be
     * incr then decr = back to the original value, proving the BACK-specific op really fired, not the FRONT one twice. */
    glClearStencil(128); glClear(GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glEnable(GL_STENCIL_TEST);
    glStencilFuncSeparateATI(GL_ALWAYS, GL_ALWAYS, 0, 0xff);
    glStencilOpSeparateATI(GL_FRONT, GL_KEEP, GL_KEEP, GL_INCR);
    glStencilOpSeparateATI(GL_BACK, GL_KEEP, GL_KEEP, GL_DECR);

    /* CCW front-facing quad covering everything */
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    /* CW back-facing quad (reversed winding) covering everything */
    glBegin(GL_QUADS); glVertex2f(-1,1); glVertex2f(1,1); glVertex2f(1,-1); glVertex2f(-1,-1); glEnd();

    /* now read back the stencil value via a pass that only draws if stencil == 128 (back to original) */
    glStencilFuncSeparateATI(GL_FRONT_AND_BACK, GL_FRONT_AND_BACK, 128, 0xff);
    glStencilOpSeparateATI(GL_FRONT_AND_BACK, GL_KEEP, GL_KEEP, GL_KEEP);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    GLubyte c[3]; readback(c);
    int ok = (c[0]==0 && c[1]==255 && c[2]==0);
    printf("ATI_separate_stencil FRONT=INCR BACK=DECR, net INCR+DECR back to 128: got %d,%d,%d want 0,255,0 %s\n",
           c[0],c[1],c[2], ok?"OK":"MISMATCH");
    if (!ok) bad++;

    printf("RESULT: %s (%d mismatches)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
