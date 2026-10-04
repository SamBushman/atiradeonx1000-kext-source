/* gl_feature_rescalenormal_test.c - GL_EXT_rescale_normal / GL_RESCALE_NORMAL: a cheaper alternative to
 * GL_NORMALIZE that only corrects for a UNIFORM modelview scale (not a true per-normal renormalize). Tested
 * by scaling the modelview uniformly and checking lighting intensity stays correct with RESCALE_NORMAL
 * enabled, vs visibly wrong with both normalization options off. Never checked before. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_RESCALE_NORMAL
#define GL_RESCALE_NORMAL 0x803A
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
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    GLfloat black[4]={0,0,0,1}, white_mat[4]={1,1,1,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
    glEnable(GL_LIGHT0);
    GLfloat lpos[4]={0,0,1,0}, ldiff[4]={1,1,1,1};
    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ldiff);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);

    int bad = 0;
    GLubyte c[3];

    /* baseline: unscaled modelview, unit normal, no rescale/normalize needed - full bright */
    glDisable(GL_NORMALIZE); glDisable(GL_RESCALE_NORMAL);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1);
    glEnd();
    readback(c);
    GLubyte baseline[3] = {c[0],c[1],c[2]};
    printf("baseline (unscaled modelview): %d,%d,%d\n", c[0],c[1],c[2]);

    /* uniformly scale the MODELVIEW UP (1000x), with NEITHER normalize option enabled. Normals are
     * transformed by the INVERSE TRANSPOSE of the modelview's upper 3x3, not by the modelview directly - so
     * scaling the modelview UP actually SHRINKS the transformed normal (by 1/1000 here), dropping N.L
     * toward zero and producing visibly WRONG (dark) lighting. (An earlier version of this test scaled the
     * modelview DOWN expecting the same dimming - backwards: that LENGTHENS the transformed normal via the
     * inverse-transpose relationship, over-driving N.L and saturating to white instead, which is exactly
     * what diag_rescale2.c caught and is why this fixed version scales UP, not down.) */
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glScalef(1000.0f,1000.0f,1000.0f);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex2f(-0.001f,-0.001f); glVertex2f(0.001f,-0.001f); glVertex2f(0.001f,0.001f); glVertex2f(-0.001f,0.001f);
    glEnd();
    readback(c);
    int broken = (c[0] < baseline[0]-30);
    printf("scaled-up modelview, NEITHER normalize option: %d,%d,%d (want visibly darker than baseline, confirming the scale really affects unnormalized lighting) %s\n",
           c[0],c[1],c[2], broken?"OK (confirmed wrong without correction)":"UNEXPECTED (not dimmed - rest of test's premise may not hold)");
    if (!broken) bad++;

    /* same scaled-up modelview, GL_RESCALE_NORMAL enabled - should restore correct (bright) lighting */
    glEnable(GL_RESCALE_NORMAL);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex2f(-0.001f,-0.001f); glVertex2f(0.001f,-0.001f); glVertex2f(0.001f,0.001f); glVertex2f(-0.001f,0.001f);
    glEnd();
    readback(c);
    int ok = (abs((int)c[0]-baseline[0]) <= 15);
    printf("scaled modelview, RESCALE_NORMAL enabled: %d,%d,%d want ~%d (restored) %s\n", c[0],c[1],c[2], baseline[0], ok?"OK":"MISMATCH");
    if (!ok) bad++;

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
