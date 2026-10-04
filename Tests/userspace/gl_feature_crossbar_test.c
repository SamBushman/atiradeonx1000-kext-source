/* gl_feature_crossbar_test.c - GL_ARB_texture_env_crossbar: a later texture unit's combine can source from
 * an EARLIER unit's raw texture output (GL_TEXTURE0, GL_TEXTURE1, ...), not just GL_PREVIOUS (the unit
 * immediately before it in the chain). Never checked before - the earlier multi-unit combine test only used
 * GL_PREVIOUS as unit1's source. */
#include <stdio.h>
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

    /* unit0: red texture, passed through unmodified (REPLACE).
     * unit1: green texture, but combine ADDs unit0's raw texture (crossbar: GL_TEXTURE0) instead of
     * GL_PREVIOUS (which would be unit0's REPLACE result - same value here, so this alone doesn't prove
     * crossbar; the real proof is unit2 sourcing GL_TEXTURE0 while GL_PREVIOUS at that point is unit1's
     * result, which is DIFFERENT from unit0's - if crossbar works, unit2 adds unit0 (red) not unit1 (green)) */
    GLubyte red[4] = {255,0,0,255}, green[4] = {0,255,0,255}, blue[4] = {0,0,255,255};
    GLuint t0,t1,t2; glGenTextures(1,&t0); glGenTextures(1,&t1); glGenTextures(1,&t2);

    glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D,t0);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,red);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    glActiveTexture(GL_TEXTURE1); glBindTexture(GL_TEXTURE_2D,t1);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,green);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);   /* unit1's own result = green */

    glActiveTexture(GL_TEXTURE2); glBindTexture(GL_TEXTURE_2D,t2);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,blue);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
    glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_ADD);
    glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE0);   /* crossbar: unit2 reads unit0's RAW output (red), not GL_PREVIOUS (green) */
    glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
    glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE);    /* unit2's own blue texture */
    glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_SRC_COLOR);

    glColor3f(1,1,1);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glMultiTexCoord2f(GL_TEXTURE0,0,0); glMultiTexCoord2f(GL_TEXTURE1,0,0); glMultiTexCoord2f(GL_TEXTURE2,0,0); glVertex2f(-1,-1);
    glMultiTexCoord2f(GL_TEXTURE0,1,0); glMultiTexCoord2f(GL_TEXTURE1,1,0); glMultiTexCoord2f(GL_TEXTURE2,1,0); glVertex2f(1,-1);
    glMultiTexCoord2f(GL_TEXTURE0,1,1); glMultiTexCoord2f(GL_TEXTURE1,1,1); glMultiTexCoord2f(GL_TEXTURE2,1,1); glVertex2f(1,1);
    glMultiTexCoord2f(GL_TEXTURE0,0,1); glMultiTexCoord2f(GL_TEXTURE1,0,1); glMultiTexCoord2f(GL_TEXTURE2,0,1); glVertex2f(-1,1);
    glEnd();
    GLubyte c[3]; readback(c);
    /* if crossbar works: result = red(1,0,0) + blue(0,0,1) = magenta (255,0,255), NOT green+blue=cyan(0,255,255) */
    int ok = (c[0] > 200 && c[1] < 20 && c[2] > 200);
    printf("CROSSBAR unit2 = unit0(red, via GL_TEXTURE0) + unit2-own(blue): got %d,%d,%d want ~255,0,255 (NOT cyan 0,255,255) %s\n",
           c[0],c[1],c[2], ok?"OK":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
