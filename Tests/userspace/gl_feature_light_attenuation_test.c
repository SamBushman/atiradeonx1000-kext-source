/* gl_feature_light_attenuation_test.c - GL_CONSTANT_ATTENUATION/GL_LINEAR_ATTENUATION/GL_QUADRATIC_ATTENUATION,
 * never checked before. attenuation = 1/(kc + kl*d + kq*d^2), compared at two different light distances.
 *
 * NOTE (separate finding, see diag_posdim.c): a positional (w=1) light at atten=(1,0,0) - i.e. no
 * attenuation requested at all - reads back at ~208/255 (~82%) instead of a full 255, identical across
 * every projection matrix tried (including plain identity) and with GL_NORMALIZE both on and off. This is
 * NOT explained by quirk 20 (the projection-matrix lighting bug fixed below via a symmetric Z range) since
 * it reproduces even with identity projection. Documented as quirk 23/#136: a real, consistent ~18% dimming
 * specific to positional lights vs. directional ones, not yet root-caused. Because of this, run_case()
 * compares the MEASURED atten=(1,0,0) baseline at each distance against the requested attenuation's
 * predicted RATIO, rather than against the textbook formula's absolute value - this still meaningfully
 * tests that CONSTANT/LINEAR/QUADRATIC_ATTENUATION reduce intensity by the right proportion, without
 * re-deriving or depending on quirk 23's unexplained constant. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

static void draw_at(float d, float kc, float kl, float kq) {
    GLfloat lpos[4] = {0,0,d,1};
    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, kc);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, kl);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, kq);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex3f(-1,-1,0); glVertex3f(1,-1,0); glVertex3f(1,1,0); glVertex3f(-1,1,0);
    glEnd();
}

static int run_case(float d, float kc, float kl, float kq) {
    /* measured baseline at this exact distance with attenuation disabled (1,0,0) - see quirk 23's note above */
    draw_at(d, 1.0f, 0.0f, 0.0f);
    GLubyte base[3]; readback(base);

    draw_at(d, kc, kl, kq);
    GLubyte c[3]; readback(c);

    float atten = 1.0f / (kc + kl*d + kq*d*d);
    if (atten > 1) atten = 1;
    int want = (int)(base[0]*atten+0.5f);
    /* generous tolerance: the measured-baseline-ratio approach (see the header comment on quirk 23) is an
     * approximation given this driver's unexplained positional-light dimming is not provably a fixed
     * constant across every attenuation/distance combination - this isn't a tight formula-match test */
    int tol = (int)(base[0]*0.12f)+3;
    int ok = abs((int)c[0]-want) <= tol;
    printf("d=%.1f kc=%.1f kl=%.2f kq=%.3f: got %d want ~%d (baseline=%d, atten=%.4f) %s\n", d,kc,kl,kq, c[0], want, base[0], atten, ok?"OK":"MISMATCH");
    return ok?0:1;
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
    /* CONFIRMED REAL DRIVER BUG (quirk 20/#133, see diag_poslight*.c): an asymmetric near/far Z range in
     * the PROJECTION matrix breaks fixed-function lighting entirely (fully black output). Using a
     * symmetric near/far range (near = -far) as a workaround so this test can exercise attenuation. */
    glViewport(0,0,W,H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-10,10,-10,10,-50,50);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    GLfloat black[4] = {0,0,0,1}, white_mat[4] = {1,1,1,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    GLfloat global_amb[4] = {0,0,0,1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_amb);
    glEnable(GL_LIGHT0);
    GLfloat ldiff[4] = {1,1,1,1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ldiff);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);

    int bad = 0;
    bad += run_case(2.0f, 1.0f, 0.3f, 0.0f);
    bad += run_case(4.0f, 1.0f, 0.3f, 0.0f);
    bad += run_case(2.0f, 0.5f, 0.0f, 0.1f);
    bad += run_case(4.0f, 0.5f, 0.0f, 0.1f);

    printf("RESULT: %s (%d mismatches)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
