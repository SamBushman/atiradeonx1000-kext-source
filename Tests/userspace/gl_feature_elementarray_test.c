/* gl_feature_elementarray_test.c - GL_APPLE_element_array: glElementPointerAPPLE + glDrawElementArrayAPPLE
 * (an index-array-only draw path, distinct from glDrawElements which takes the index pointer per-call).
 * Correctness checked against the equivalent glDrawElements result. Never checked before. */
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

    GLfloat verts[4*2] = {-1,-1, 1,-1, 1,1, -1,1};
    GLubyte idx[6] = {0,1,2, 0,2,3};
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(1,1,1);

    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, idx);
    GLubyte de[3]; readback(de);

    glElementPointerAPPLE(GL_UNSIGNED_BYTE, idx);
    GLenum e1 = glGetError();
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawElementArrayAPPLE(GL_TRIANGLES, 0, 6);
    GLenum e2 = glGetError();
    GLubyte dea[3]; readback(dea);

    int ok = (de[0]==dea[0] && de[1]==dea[1] && de[2]==dea[2]) && e1==GL_NO_ERROR && e2==GL_NO_ERROR;
    printf("DrawElements vs DrawElementArrayAPPLE: %d,%d,%d vs %d,%d,%d err1=0x%04x err2=0x%04x %s\n",
           de[0],de[1],de[2], dea[0],dea[1],dea[2], (unsigned)e1, (unsigned)e2, ok?"OK":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
