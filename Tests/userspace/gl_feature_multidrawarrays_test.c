/* gl_feature_multidrawarrays_test.c - EXT_multi_draw_arrays: glMultiDrawArraysEXT issues several
 * first/count sub-ranges of the SAME bound vertex array in one call, equivalent to calling glDrawArrays
 * that many times. Never checked before. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static void readback_at(int x, int y, GLubyte *out) {
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (y*W+x)*4;
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

    /* two separate, non-adjacent triangles in one array: one on the left half, one on the right half */
    GLfloat verts[12] = {
        -0.9f,-0.5f, -0.5f,-0.5f, -0.7f,0.5f,    /* left triangle */
         0.5f,-0.5f,  0.9f,-0.5f,  0.7f,0.5f      /* right triangle */
    };
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(1,1,1);

    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    GLint first[2] = {0,3};
    GLsizei count[2] = {3,3};
    glMultiDrawArraysEXT(GL_TRIANGLES, first, count, 2);
    GLenum e = glGetError();

    GLubyte left[3]; readback_at(4,16,left);     /* inside the left triangle's footprint */
    GLubyte right[3]; readback_at(27,16,right);  /* inside the right triangle's footprint */
    int ok = (left[0]>200) && (right[0]>200) && e==GL_NO_ERROR;
    printf("MultiDrawArrays (2 separate sub-ranges): left=%d,%d,%d right=%d,%d,%d glGetError=0x%04x %s\n",
           left[0],left[1],left[2], right[0],right[1],right[2], (unsigned)e, ok?"OK (both triangles drawn)":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
