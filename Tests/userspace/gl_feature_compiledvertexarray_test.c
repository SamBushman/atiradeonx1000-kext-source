/* gl_feature_compiledvertexarray_test.c - EXT_compiled_vertex_array: glLockArraysEXT/glUnlockArraysEXT hint
 * that a vertex array range won't change for several draws. Correctness check: locking must not change the
 * rendered result vs. not locking. Never checked before. */
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
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(1,1,1);

    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_QUADS, 0, 4);
    GLubyte unlocked[3]; readback(unlocked);

    glLockArraysEXT(0, 4);
    GLenum e1 = glGetError();
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_QUADS, 0, 4);
    GLubyte locked[3]; readback(locked);
    glUnlockArraysEXT();
    GLenum e2 = glGetError();

    int ok = (unlocked[0]==locked[0]) && (e1==GL_NO_ERROR) && (e2==GL_NO_ERROR);
    printf("LockArrays/UnlockArrays: unlocked=%d,%d,%d locked=%d,%d,%d lockErr=0x%04x unlockErr=0x%04x %s\n",
           unlocked[0],unlocked[1],unlocked[2], locked[0],locked[1],locked[2], (unsigned)e1, (unsigned)e2, ok?"OK":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
