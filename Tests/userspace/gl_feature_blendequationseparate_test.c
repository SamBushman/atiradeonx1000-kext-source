/* gl_feature_blendequationseparate_test.c - glBlendEquationSeparate (EXT/ATI): independent RGB and ALPHA
 * blend EQUATIONS (distinct from glBlendFuncSeparate's independent FACTORS, already tested). Never checked. */
#include <stdio.h>
#include <stdlib.h>
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

    /* RGB uses FUNC_ADD (src+dst), alpha uses FUNC_REVERSE_SUBTRACT (dst-src), both with factors (1,1) */
    glClearColor(0.5f,0.3f,0.1f,0.8f); glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glBlendEquationSeparateEXT(GL_FUNC_ADD, GL_FUNC_REVERSE_SUBTRACT);
    glColor4f(0.2f,0.2f,0.2f,0.3f);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    GLubyte c[4]; readback(c);

    float wr = 0.5f+0.2f, wg = 0.3f+0.2f, wb = 0.1f+0.2f;   /* RGB: ADD */
    float wa = 0.8f-0.3f;                                    /* alpha: REVERSE_SUBTRACT (dst-src) */
    int wR=(int)(wr*255+0.5f), wG=(int)(wg*255+0.5f), wB=(int)(wb*255+0.5f), wA=(int)(wa*255+0.5f);
    int ok = abs((int)c[0]-wR)<=3 && abs((int)c[1]-wG)<=3 && abs((int)c[2]-wB)<=3 && abs((int)c[3]-wA)<=3;
    printf("BlendEquationSeparate(ADD,REVERSE_SUBTRACT): got %d,%d,%d,%d want %d,%d,%d,%d %s\n",
           c[0],c[1],c[2],c[3], wR,wG,wB,wA, ok?"OK":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
