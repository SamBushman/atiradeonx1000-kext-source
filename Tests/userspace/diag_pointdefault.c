/* diag_pointdefault.c - #132: with NO glPointParameter calls at all, do default point sizes still render at their requested size? */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#define W 128
#define H 64
static int width(float size) {
    static GLubyte buf[W*H*4]; int x, l = -1, r = -1;
    glPointSize(size); glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS); glVertex3f(0, 0, 0); glEnd(); glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    for (x = 0; x < W; x++) { GLubyte *p = buf + (H/2*W+x)*4; if (p[0] > 128) { if (l < 0) l = x; r = x; } }
    return l < 0 ? 0 : r - l + 1;
}
int main(void) {
    CGLPixelFormatObj pf; GLint npix = 0; CGLContextObj ctx; CGLPBufferObj pbuf; float s[] = {1, 8, 50, 3};
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    int i; GLfloat mn = -1, mx = -1;
    if (CGLChoosePixelFormat(attrs, &pf, &npix) || !pf) return 1;
    CGLCreateContext(pf, NULL, &ctx); CGLDestroyPixelFormat(pf); CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    CGLSetCurrentContext(ctx); CGLSetPBuffer(ctx, pbuf, 0, 0, 0);
    glViewport(0,0,W,H); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST); glColor3f(1,1,1);
    glGetFloatv(0x8126, &mn); glGetFloatv(0x8127, &mx); printf("default GL_POINT_SIZE_MIN=%g MAX=%g\n", mn, mx);
    for (i = 0; i < 4; i++) printf("default state glPointSize(%g) -> width %d\n", s[i], width(s[i]));
    return 0;
}
