/* gl_feature_transposematrix_test.c - ARB_transpose_matrix: glLoadTransposeMatrixf/glMultTransposeMatrixf
 * take a ROW-major matrix (vs. GL's native column-major glLoadMatrixf) and should produce the exact
 * transform as loading the transposed matrix normally. Never checked before. */
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
    /* the quad is translated to NDC (0.3,0.3); with identity projection, window x = (ndc+1)/2*W =
     * (1.3)/2*32 = 20.8 -> sample at window (21,21), which is actually inside the translated quad's
     * footprint (an earlier version sampled (W/4,H/4)=(8,8), nowhere near the translated quad - both
     * readbacks came back 0,0,0 and "matched" without actually testing anything) */
    GLubyte *p = buf + (21*W+21)*4;
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
    glDisable(GL_DEPTH_TEST);
    glColor3f(1,1,1);

    /* a column-major translation-by-(0.3,0.3,0) matrix, GL's native layout (translation in the last COLUMN,
     * i.e. elements [12],[13]) */
    GLfloat colmajor[16] = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0.3f,0.3f,0,1
    };
    glMatrixMode(GL_MODELVIEW); glLoadMatrixf(colmajor);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glVertex2f(-0.1f,-0.1f); glVertex2f(0.1f,-0.1f); glVertex2f(0.1f,0.1f); glVertex2f(-0.1f,0.1f); glEnd();
    GLubyte normal[3]; readback(normal);

    /* the ROW-major transpose of the same matrix (translation now in the last ROW) - loaded via
     * glLoadTransposeMatrixf, which should produce the IDENTICAL transform as the column-major load above */
    GLfloat rowmajor[16] = {
        1,0,0,0.3f,
        0,1,0,0.3f,
        0,0,1,0,
        0,0,0,1
    };
    glLoadTransposeMatrixfARB(rowmajor);
    GLenum e = glGetError();
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glVertex2f(-0.1f,-0.1f); glVertex2f(0.1f,-0.1f); glVertex2f(0.1f,0.1f); glVertex2f(-0.1f,0.1f); glEnd();
    GLubyte transposed[3]; readback(transposed);

    int ok = (normal[0]==transposed[0] && normal[1]==transposed[1] && normal[2]==transposed[2]) && e==GL_NO_ERROR && normal[0] > 200;
    printf("LoadMatrixf(colmajor) vs LoadTransposeMatrixf(rowmajor), same transform: %d,%d,%d vs %d,%d,%d glGetError=0x%04x %s\n",
           normal[0],normal[1],normal[2], transposed[0],transposed[1],transposed[2], (unsigned)e, ok?"OK":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
