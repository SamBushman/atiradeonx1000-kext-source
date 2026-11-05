/* diag_pointparam4.c - #132 follow-up (new issue): distance-attenuated point size (vertex-program path) sweep over eye distance and a/b/c; every width should follow size*1/sqrt(a+b*d+c*d*d) but the stock and rebuilt driver both saturate at POINT_SIZE_MAX. */
#include <stdio.h>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#define W 128
#define H 64
static void P(GLenum n, GLfloat v) { glPointParameterfARB(n, v); }
static int width(float size, int smooth) {
    static GLubyte buf[W*H*4]; int x, l = -1, r = -1;
    glPointSize(size); if (smooth) glEnable(GL_POINT_SMOOTH); else glDisable(GL_POINT_SMOOTH);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS); glVertex3f(0, 0, 0); glEnd(); glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    for (x = 0; x < W; x++) { GLubyte *p = buf + (H/2*W+x)*4; if (p[0] > 128) { if (l < 0) l = x; r = x; } }
    return l < 0 ? 0 : r - l + 1;
}
static void run(const char *label, float mn, float mx, float a, float b, float c, int smooth, float size) {
    float att[3]; att[0] = a; att[1] = b; att[2] = c;
    P(0x8126, mn); P(0x8127, mx); glPointParameterfvARB(0x8129, att);
    printf("%-52s min=%-4g max=%-4g atten=(%g,%g,%g) smooth=%d size=%-4g -> width %d\n", label, mn, mx, a, b, c, smooth, size, width(size, smooth));
}
int main(void) {
    CGLPixelFormatObj pf; GLint npix = 0; CGLContextObj ctx; CGLPBufferObj pbuf; GLfloat rng[2];
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    if (CGLChoosePixelFormat(attrs, &pf, &npix) || !pf) return 1;
    CGLCreateContext(pf, NULL, &ctx); CGLDestroyPixelFormat(pf); CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    CGLSetCurrentContext(ctx); CGLSetPBuffer(ctx, pbuf, 0, 0, 0);
    glViewport(0,0,W,H); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(0, 0, -0.5f);
    glDisable(GL_DEPTH_TEST); glColor3f(1,1,1);
    glGetFloatv(GL_POINT_SIZE_RANGE, rng); printf("GL_POINT_SIZE_RANGE = %g .. %g\n", rng[0], rng[1]);
    { float bs[] = {0.0001f, 0.5f, 1.0f, 2.0f, 4.0f}; float zs[] = {-0.5f, -0.25f, -1.0f}; int i, j;
      for (j = 0; j < 3; j++) { glLoadIdentity(); glTranslatef(0, 0, zs[j]);
        for (i = 0; i < 5; i++) { char lab[64]; sprintf(lab, "atten sweep eyez=%g (d=%g) expect %.1f", zs[j], -zs[j], 10.0f / sqrtf(1.0f + bs[i] * -zs[j])); run(lab, 0, 64, 1, bs[i], 0, 0, 10); } }
      glLoadIdentity(); glTranslatef(0, 0, -0.5f);
      run("c term: a=1,b=0,c=4 d=0.5 expect 5.0", 0, 64, 1, 0, 4, 0, 10);
      run("a term: a=4,b=0.0001,c=0 expect 5.0", 0, 64, 4, 0.0001f, 0, 0, 10);
      run("MIN only, atten (1,1,0) size 1 min 6 max 64 expect 6", 6, 64, 1, 1, 0, 0, 1);
      run("MIN only, atten (1,1,0) size 10 min 6 max 64 expect 8", 6, 64, 1, 1, 0, 0, 10); }
    return 0;
}
