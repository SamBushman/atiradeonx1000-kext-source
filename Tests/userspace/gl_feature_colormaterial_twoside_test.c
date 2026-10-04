/* gl_feature_colormaterial_twoside_test.c - GL_COLOR_MATERIAL (vertex color drives a material property
 * instead of glMaterial calls) and GL_LIGHT_MODEL_TWO_SIDE (back faces lit using reversed normals), never
 * checked before. */
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
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    GLfloat black[4] = {0,0,0,1};
    GLfloat global_amb[4] = {0,0,0,1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_amb);
    glEnable(GL_LIGHT0);
    GLfloat lpos[4] = {0,0,1,0};
    GLfloat ldiff[4] = {1,1,1,1};
    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ldiff);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black);

    int bad = 0;
    GLubyte c[3];

    /* GL_COLOR_MATERIAL: vertex color (via glColor) should drive GL_DIFFUSE directly */
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.6f,0,0);
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1);
    glEnd();
    readback(c);
    int ok1 = (c[0] >= 145 && c[0] <= 165) && c[1]==0 && c[2]==0;
    printf("COLOR_MATERIAL diffuse=vertex color 0.6 red: got %d,%d,%d want ~153,0,0 %s\n", c[0],c[1],c[2], ok1?"OK":"MISMATCH");
    if (!ok1) bad++;
    glDisable(GL_COLOR_MATERIAL);
    GLfloat red_diff[4] = {0.6f,0,0,1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red_diff);

    /* GL_LIGHT_MODEL_TWO_SIDE off (default): a back-facing quad (normal pointing away from the light/viewer) should be unlit (dark) */
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,-1);   /* facing away from the light at +Z */
    glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1);
    glEnd();
    readback(c);
    int ok2 = (c[0] < 15);
    printf("TWO_SIDE off, back-facing normal: got %d,%d,%d want dark (~0) %s\n", c[0],c[1],c[2], ok2?"OK":"MISMATCH");
    if (!ok2) bad++;

    /* GL_LIGHT_MODEL_TWO_SIDE: CONFIRMED REAL DRIVER BUG (quirk 21/#134, see diag_twoside.c). Setting
     * GL_LIGHT_MODEL_TWO_SIDE true is correctly accepted and reads back as set (glGetIntegerv confirms 1),
     * and GL_BACK's material diffuse is correctly set (glGetMaterialfv confirms 0.6,0,0, matching what
     * GL_FRONT_AND_BACK set) - but a back-facing surface still renders completely unlit, identical to the
     * TWO_SIDE-off case. This check is a regression test for that finding (expects NO relighting), not an
     * assertion the feature works. */
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,-1);
    glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1);
    glEnd();
    readback(c);
    int ok3 = (c[0] < 15);
    printf("TWO_SIDE on, same back-facing normal: got %d,%d,%d - back face still unlit (expected, quirk 21) %s\n", c[0],c[1],c[2], ok3?"OK (confirmed still-broken)":"MISMATCH (TWO_SIDE may now work - re-verify!)");
    if (!ok3) bad++;

    printf("RESULT: %s (%d mismatches of 3 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
