/* diag_pointsprite.c - isolating the point-sprite anomalies from gl_feature_pointsprite_test.c (issue #128):
 * (1) does COORD_REPLACE texcoord vary ANYWHERE across the sprite's footprint (not just the two corners
 * the main test sampled)? (2) what is the real point size actually used once PARAMETER min/max are set? */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_POINT_SPRITE
#define GL_POINT_SPRITE 0x8861
#endif
#ifndef GL_COORD_REPLACE
#define GL_COORD_REPLACE 0x8862
#endif
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

    printf("GL_POINT_SIZE_MAX implementation limit: ");
    { GLfloat r[2]; glGetFloatv(GL_POINT_SIZE_RANGE, r); printf("range=[%.1f,%.1f]\n", r[0], r[1]); }

    /* (1) coord_replace variation scan */
    GLubyte tex[2*2*4] = { 255,0,0,255,  0,255,0,255,  0,0,255,255,  255,255,0,255 };
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,2,2,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_POINT_SPRITE);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
    glPointSize(40.0f);
    glColor3f(1,1,1);
    glClearColor(0.1f,0.1f,0.1f,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS); glVertex2f(0,0); glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int x,y;
    int distinct = 0;
    GLubyte first[3] = {255,255,255};
    int have_first = 0;
    for (y=H/2-18; y<=H/2+18; y+=4) {
        for (x=W/2-18; x<=W/2+18; x+=4) {
            GLubyte *p = buf + (y*W+x)*4;
            if (p[0]==25 && p[1]==25 && p[2]==25) continue; /* background */
            if (!have_first) { first[0]=p[0]; first[1]=p[1]; first[2]=p[2]; have_first=1; }
            else if (p[0]!=first[0] || p[1]!=first[1] || p[2]!=first[2]) distinct++;
            printf("  (%d,%d) rel(%d,%d): %d,%d,%d\n", x, y, x-W/2, y-H/2, p[0],p[1],p[2]);
        }
    }
    printf("distinct-from-first count = %d (want > 0 if texcoord truly varies)\n", distinct);

    /* (2) point size min/max clamp behavior - directly measure the rendered sprite's width in pixels */
    glDisable(GL_POINT_SPRITE); glDisable(GL_TEXTURE_2D);
    glPointParameterfARB(GL_POINT_SIZE_MIN, 2.0f);
    glPointParameterfARB(GL_POINT_SIZE_MAX, 8.0f);
    float atten[3] = {1,0,0};
    glPointParameterfvARB(GL_POINT_DISTANCE_ATTENUATION, atten);
    glPointSize(50.0f);
    glColor3f(1,1,1);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS); glVertex2f(0,0); glEnd();
    glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    /* measure horizontal extent of lit pixels on the center row */
    int left=-1, right=-1;
    for (x=0;x<W;x++) { GLubyte *p = buf + (H/2*W+x)*4; if (p[0]>200) { if(left<0) left=x; right=x; } }
    printf("center-row lit extent: left=%d right=%d width=%d (requested size 50, PARAMETER MAX=8)\n", left, right, right-left+1);

    return 0;
}
