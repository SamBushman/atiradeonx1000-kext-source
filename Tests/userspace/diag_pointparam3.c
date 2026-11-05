/* diag_pointparam3.c - #132: which point-size path honours GL_POINT_SIZE_MIN/MAX? Non-attenuated (a=1,b=c=0) vs attenuated (vertex-program) vs smooth-point, each at a size above MAX and below MIN. */
#include <stdio.h>
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
    run("default path, MAX below size", 1, 8, 1, 0, 0, 0, 50);
    run("default path, MIN above size", 20, 64, 1, 0, 0, 0, 1);
    run("default path, no clamp requested (reference)", 0, 64, 1, 0, 0, 0, 50);
    run("attenuated (b=1, d=0.5 -> factor .816), MAX", 1, 8, 1, 1, 0, 0, 50);
    run("attenuated, MIN", 20, 64, 1, 1, 0, 0, 1);
    run("attenuated, no clamp (reference, expect ~41)", 0, 64, 1, 1, 0, 0, 50);
    run("smooth points, MAX", 1, 8, 1, 0, 0, 1, 50);
    run("smooth points, MIN", 20, 64, 1, 0, 0, 1, 1);
    return 0;
}
