/* gl_feature_fogcoord_test.c - EXT_fog_coord: GL_FOG_COORDINATE_SOURCE=GL_FOG_COORD lets each vertex supply
 * its own fog-distance value via glFogCoordfEXT, overriding the default eye-space-depth source. Never
 * checked before. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_FOG_COORDINATE_SOURCE_EXT
#define GL_FOG_COORDINATE_SOURCE_EXT 0x8450
#endif
#ifndef GL_FOG_COORD_EXT
#define GL_FOG_COORD_EXT 0x8451
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
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-10,10,-10,10,-50,50);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    GLfloat fogc[4] = {0,0,1,1};
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogf(GL_FOG_START, 0.0f);
    glFogf(GL_FOG_END, 20.0f);
    glFogfv(GL_FOG_COLOR, fogc);
    glEnable(GL_FOG);
    glFogi(GL_FOG_COORDINATE_SOURCE_EXT, GL_FOG_COORD_EXT);

    /* geometry at object-space z=0 (so the default eye-space-depth source would give fog factor f=(20-0)/20=1.0,
     * i.e. no fog at all - fully object colored), but glFogCoordfEXT supplies a fog coordinate of 10 instead,
     * which per GL_LINEAR should give f=(20-10)/20=0.5 -> a genuine 50% blend toward the fog color */
    glFogCoordfEXT(10.0f);
    glColor3f(1,1,1);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glVertex3f(-1,-1,0); glVertex3f(1,-1,0); glVertex3f(1,1,0); glVertex3f(-1,1,0);
    glEnd();
    GLubyte c[3]; readback(c);

    float f = (20.0f-10.0f)/20.0f;
    float wr = f*1.0f + (1-f)*fogc[0], wb = f*1.0f + (1-f)*fogc[2];
    int wR=(int)(wr*255+0.5f), wB=(int)(wb*255+0.5f);
    int tol = 8;
    int ok = abs((int)c[0]-wR)<=tol && abs((int)c[2]-wB)<=tol;
    printf("FOG_COORD override (vertex z=0, fog coord=10, LINEAR 0..20): got %d,%d,%d want ~%d,0,%d (50%% fog blend, NOT unfogged) %s\n",
           c[0],c[1],c[2], wR, wB, ok?"OK":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
