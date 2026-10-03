/* gl_feature_combine_dot3_test.c - issue #128 gap list: GL_DOT3_RGB/GL_DOT3_RGBA texture env combine modes
 * (bump-mapping dot product), and a 2-unit combine chain (unit0 modulate, unit1 add result). */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_DOT3_RGB
#define GL_DOT3_RGB 0x86AE
#endif
#ifndef GL_DOT3_RGBA
#define GL_DOT3_RGBA 0x86AF
#endif
#ifndef GL_COMBINE
#define GL_COMBINE 0x8570
#endif
#ifndef GL_COMBINE_RGB
#define GL_COMBINE_RGB 0x8571
#endif
#ifndef GL_SOURCE0_RGB
#define GL_SOURCE0_RGB 0x8580
#endif
#ifndef GL_SOURCE1_RGB
#define GL_SOURCE1_RGB 0x8581
#endif
#ifndef GL_OPERAND0_RGB
#define GL_OPERAND0_RGB 0x8590
#endif
#ifndef GL_OPERAND1_RGB
#define GL_OPERAND1_RGB 0x8591
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static void readback(GLubyte *out) {
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    out[0]=p[0]; out[1]=p[1]; out[2]=p[2]; out[3]=p[3];
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

    int bad = 0;
    GLubyte c[4];

    /* DOT3_RGB: two "normal" textures encoded as 0.5+0.5*n. tex0 encodes n0=(0,0,1) -> (128,128,255).
     * tex1 encodes n1=(0,0,1) -> (128,128,255) too (same normal => dot=1 => result white). */
    {
        GLubyte t0[4] = {128,128,255,255};
        GLubyte t1[4] = {128,128,255,255};
        GLuint tex0,tex1; glGenTextures(1,&tex0); glGenTextures(1,&tex1);
        glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D,tex0);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,t0);
        glEnable(GL_TEXTURE_2D);
        glActiveTexture(GL_TEXTURE1); glBindTexture(GL_TEXTURE_2D,tex1);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,t1);
        glEnable(GL_TEXTURE_2D);

        glActiveTexture(GL_TEXTURE1);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
        glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_DOT3_RGB);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_PREVIOUS);
        glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE1);
        glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_SRC_COLOR);
        glActiveTexture(GL_TEXTURE0);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

        glColor3f(1,1,1);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glMultiTexCoord2f(GL_TEXTURE0,0,0); glMultiTexCoord2f(GL_TEXTURE1,0,0); glVertex2f(-1,-1);
        glMultiTexCoord2f(GL_TEXTURE0,1,0); glMultiTexCoord2f(GL_TEXTURE1,1,0); glVertex2f(1,-1);
        glMultiTexCoord2f(GL_TEXTURE0,1,1); glMultiTexCoord2f(GL_TEXTURE1,1,1); glVertex2f(1,1);
        glMultiTexCoord2f(GL_TEXTURE0,0,1); glMultiTexCoord2f(GL_TEXTURE1,0,1); glVertex2f(-1,1);
        glEnd();
        readback(c);
        /* dot((0,0,1),(0,0,1)) = 1.0 -> result should be white (255,255,255) */
        int ok = c[0]>240 && c[1]>240 && c[2]>240;
        printf("DOT3_RGB same-normal (n.n=1): got %d,%d,%d want ~255,255,255 %s\n", c[0],c[1],c[2], ok?"OK":"MISMATCH");
        if (!ok) bad++;

        glActiveTexture(GL_TEXTURE1); glDisable(GL_TEXTURE_2D);
        glActiveTexture(GL_TEXTURE0); glDisable(GL_TEXTURE_2D);
        glDeleteTextures(1,&tex0); glDeleteTextures(1,&tex1);
    }

    /* 2-unit combine chain: unit0 modulate vertex color (0.5 gray) by a red texture (1,0,0); unit1 adds a
     * constant blue texture (0,0,1) to the result -> expect (0.5,0,1) clamped -> (128,0,255) */
    {
        GLubyte tred[4] = {255,0,0,255};
        GLubyte tblue[4] = {0,0,255,255};
        GLuint tex0,tex1; glGenTextures(1,&tex0); glGenTextures(1,&tex1);
        glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D,tex0);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,tred);
        glEnable(GL_TEXTURE_2D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

        glActiveTexture(GL_TEXTURE1); glBindTexture(GL_TEXTURE_2D,tex1);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,tblue);
        glEnable(GL_TEXTURE_2D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);

        glColor3f(0.5f,0.5f,0.5f);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glMultiTexCoord2f(GL_TEXTURE0,0,0); glMultiTexCoord2f(GL_TEXTURE1,0,0); glVertex2f(-1,-1);
        glMultiTexCoord2f(GL_TEXTURE0,1,0); glMultiTexCoord2f(GL_TEXTURE1,1,0); glVertex2f(1,-1);
        glMultiTexCoord2f(GL_TEXTURE0,1,1); glMultiTexCoord2f(GL_TEXTURE1,1,1); glVertex2f(1,1);
        glMultiTexCoord2f(GL_TEXTURE0,0,1); glMultiTexCoord2f(GL_TEXTURE1,0,1); glVertex2f(-1,1);
        glEnd();
        readback(c);
        int ok = (c[0]>=118 && c[0]<=138) && c[1]==0 && c[2]==255;
        printf("2-unit chain MODULATE(0.5gray,red)+ADD(blue): got %d,%d,%d want ~128,0,255 %s\n", c[0],c[1],c[2], ok?"OK":"MISMATCH");
        if (!ok) bad++;

        glActiveTexture(GL_TEXTURE1); glDisable(GL_TEXTURE_2D);
        glActiveTexture(GL_TEXTURE0); glDisable(GL_TEXTURE_2D);
        glDeleteTextures(1,&tex0); glDeleteTextures(1,&tex1);
    }

    printf("RESULT: %s (%d mismatches)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
