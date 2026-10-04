/* gl_feature_pbo_test.c - ARB_pixel_buffer_object: upload texture data FROM a PBO (GL_PIXEL_UNPACK_BUFFER)
 * instead of client memory, and read pixels INTO a PBO (GL_PIXEL_PACK_BUFFER), checked against the
 * equivalent client-memory path. Never checked before. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_PIXEL_UNPACK_BUFFER_ARB
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#endif
#ifndef GL_PIXEL_PACK_BUFFER_ARB
#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

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

    /* unpack: upload a 1x1 orange texel from a PBO instead of client memory */
    GLubyte texel[4] = {255,128,0,255};
    GLuint pbo; glGenBuffersARB(1, &pbo);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
    glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, 4, texel, GL_STATIC_DRAW);
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,(void*)0);   /* offset 0 into the bound PBO */
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor3f(1,1,1);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(-1,-1); glTexCoord2f(1,0); glVertex2f(1,-1);
    glTexCoord2f(1,1); glVertex2f(1,1); glTexCoord2f(0,1); glVertex2f(-1,1);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    int ok1 = (p[0]==255 && p[1]==128 && p[2]==0);
    printf("PBO unpack (upload from GL_PIXEL_UNPACK_BUFFER): got %d,%d,%d want 255,128,0 %s\n", p[0],p[1],p[2], ok1?"OK":"MISMATCH");
    if (!ok1) bad++;
    glDeleteBuffersARB(1,&pbo);

    /* pack: read pixels INTO a PBO instead of client memory, then map it back and check */
    GLuint pbo2; glGenBuffersARB(1, &pbo2);
    glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB, pbo2);
    glBufferDataARB(GL_PIXEL_PACK_BUFFER_ARB, W*H*4, NULL, GL_STREAM_READ);
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,(void*)0);   /* offset 0 into the bound pack PBO */
    GLubyte *mapped = (GLubyte*)glMapBufferARB(GL_PIXEL_PACK_BUFFER_ARB, GL_READ_ONLY_ARB);
    int ok2 = mapped && (mapped[(H/2*W+W/2)*4]==255) && (mapped[(H/2*W+W/2)*4+1]==128);
    printf("PBO pack (ReadPixels into GL_PIXEL_PACK_BUFFER): mapped=%p center=%d,%d,%d %s\n",
           (void*)mapped, mapped?mapped[(H/2*W+W/2)*4]:-1, mapped?mapped[(H/2*W+W/2)*4+1]:-1, mapped?mapped[(H/2*W+W/2)*4+2]:-1, ok2?"OK":"MISMATCH");
    if (!ok2) bad++;
    glUnmapBufferARB(GL_PIXEL_PACK_BUFFER_ARB);
    glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB, 0);
    glDeleteBuffersARB(1,&pbo2);

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
