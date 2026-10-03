/* diag_pointparam.c - confirming the POINT_SIZE_MAX clamp anomaly from diag_pointsprite.c is real: checks
 * glGetError after every call, and reads the parameter back via glGetFloatv to confirm it was actually stored
 * (not silently rejected), before concluding the rasterizer itself ignores it. */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_POINT_SIZE_MIN
#define GL_POINT_SIZE_MIN 0x8126
#endif
#ifndef GL_POINT_SIZE_MAX
#define GL_POINT_SIZE_MAX 0x8127
#endif
#ifndef GL_POINT_DISTANCE_ATTENUATION
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 64
#define H 64
static void chk(const char *label) { GLenum e = glGetError(); if (e) printf("  glGetError after %s: 0x%04x\n", label, e); }

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

    while (glGetError() != GL_NO_ERROR) {}
    glPointParameterfARB(GL_POINT_SIZE_MIN, 2.0f); chk("PointParameterf(MIN,2.0)");
    glPointParameterfARB(GL_POINT_SIZE_MAX, 8.0f); chk("PointParameterf(MAX,8.0)");
    float atten[3] = {1,0,0};
    glPointParameterfvARB(GL_POINT_DISTANCE_ATTENUATION, atten); chk("PointParameterfv(ATTEN)");

    GLfloat rmin=-1, rmax=-1, ratt[3]={-1,-1,-1};
    glGetFloatv(GL_POINT_SIZE_MIN, &rmin);
    glGetFloatv(GL_POINT_SIZE_MAX, &rmax);
    glGetFloatv(GL_POINT_DISTANCE_ATTENUATION, ratt);
    printf("readback: MIN=%.2f MAX=%.2f ATTEN=(%.2f,%.2f,%.2f)\n", rmin, rmax, ratt[0], ratt[1], ratt[2]);
    printf("(set MIN=2.0 MAX=8.0 ATTEN=(1,0,0) - readback %s\n", (rmin==2.0f && rmax==8.0f && ratt[0]==1.0f) ? "MATCHES what was set" : "DOES NOT MATCH - values were not stored!");

    glPointSize(50.0f);
    glColor3f(1,1,1);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS); glVertex2f(0,0); glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int x, left=-1, right=-1;
    for (x=0;x<W;x++) { GLubyte *p = buf + (H/2*W+x)*4; if (p[0]>200) { if(left<0) left=x; right=x; } }
    printf("rendered width = %d (requested glPointSize=50, PARAMETER MAX stored as %.2f)\n", right-left+1, rmax);
    printf("%s\n", (right-left+1) <= 12 ? "CLAMP APPLIED (within generous band of 8)" : "CLAMP NOT APPLIED - real driver bug if the readback above matched what was set");
    return 0;
}
