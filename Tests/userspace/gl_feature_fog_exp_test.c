/* gl_feature_fog_exp_test.c - issue #128 gap list: GL_EXP and GL_EXP2 fog modes (linear already tested
 * in gl_feature_fog_test.c). GL_EXP: f = exp(-density*z). GL_EXP2: f = exp(-(density*z)^2). Fragment color
 * = f*objectColor + (1-f)*fogColor. */
#include <stdio.h>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static int run_fog(GLenum mode, float density, float z, float obj[3], float fogc[4], const char *label) {
    glFogi(GL_FOG_MODE, mode);
    glFogf(GL_FOG_DENSITY, density);
    glFogfv(GL_FOG_COLOR, fogc);
    glEnable(GL_FOG);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3fv(obj);
    glBegin(GL_QUADS);
    glVertex3f(-1,-1,z); glVertex3f(1,-1,z); glVertex3f(1,1,z); glVertex3f(-1,1,z);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;

    float f = (mode == GL_EXP) ? expf(-density*fabsf(z)) : expf(-(density*fabsf(z))*(density*fabsf(z)));
    float wr = f*obj[0] + (1-f)*fogc[0];
    float wg = f*obj[1] + (1-f)*fogc[1];
    float wb = f*obj[2] + (1-f)*fogc[2];
    int wR = (int)(wr*255+0.5f), wG=(int)(wg*255+0.5f), wB=(int)(wb*255+0.5f);
    int tol = 6;
    int ok = abs((int)p[0]-wR)<=tol && abs((int)p[1]-wG)<=tol && abs((int)p[2]-wB)<=tol;
    printf("%-28s got %3d,%3d,%3d want %3d,%3d,%3d %s\n", label, p[0],p[1],p[2], wR,wG,wB, ok?"OK":"MISMATCH");
    return ok?0:1;
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, kCGLPFADepthSize,16, (CGLPixelFormatAttribute)0 };
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
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-10, 10, -10, 10, 0.1, 100);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    float obj[3] = {1,1,1};
    float fogc[4] = {0,0,1,1};
    int bad = 0;
    bad += run_fog(GL_EXP, 0.15f, -5.0f, obj, fogc, "EXP density=0.15 z=-5");
    bad += run_fog(GL_EXP, 0.15f, -15.0f, obj, fogc, "EXP density=0.15 z=-15");
    bad += run_fog(GL_EXP2, 0.1f, -5.0f, obj, fogc, "EXP2 density=0.1 z=-5");
    bad += run_fog(GL_EXP2, 0.1f, -10.0f, obj, fogc, "EXP2 density=0.1 z=-10");

    printf("RESULT: %s (%d mismatches)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
