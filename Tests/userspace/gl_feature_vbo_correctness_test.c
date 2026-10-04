/* gl_feature_vbo_correctness_test.c - a direct A/B correctness check: a draw using vertex/color data
 * uploaded into a real GL_ARRAY_BUFFER VBO must render IDENTICALLY to the same data drawn straight from
 * client memory. VBOs were used incidentally elsewhere in this project (opcode-coverage workloads) but
 * never checked at the feature level for a correctness difference vs. client arrays. */
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
    GLfloat colors[4*3] = {1,0,0, 0,1,0, 0,0,1, 1,1,0};   /* varying per-vertex color, interpolated */
    GLubyte idx[6] = {0,1,2, 0,2,3};

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    /* client-memory draw */
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, idx);
    GLubyte clientres[3]; readback(clientres);

    /* VBO-backed draw: upload the identical vertex/color/index data into real buffer objects */
    GLuint vbuf, cbuf, ibuf;
    glGenBuffersARB(1,&vbuf); glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbuf);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(verts), verts, GL_STATIC_DRAW_ARB);
    glGenBuffersARB(1,&cbuf); glBindBufferARB(GL_ARRAY_BUFFER_ARB, cbuf);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(colors), colors, GL_STATIC_DRAW_ARB);
    glGenBuffersARB(1,&ibuf); glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, ibuf);
    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(idx), idx, GL_STATIC_DRAW_ARB);

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbuf);
    glVertexPointer(2, GL_FLOAT, 0, (void*)0);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, cbuf);
    glColorPointer(3, GL_FLOAT, 0, (void*)0);
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, ibuf);

    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, (void*)0);   /* offset into the bound element buffer */
    GLenum e = glGetError();
    GLubyte vborres[3]; readback(vborres);

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

    int ok = (clientres[0]==vborres[0] && clientres[1]==vborres[1] && clientres[2]==vborres[2]) && e==GL_NO_ERROR;
    printf("client-array vs VBO-backed draw (same vertex/color/index data): client=%d,%d,%d vbo=%d,%d,%d glGetError=0x%04x %s\n",
           clientres[0],clientres[1],clientres[2], vborres[0],vborres[1],vborres[2], (unsigned)e, ok?"OK":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
