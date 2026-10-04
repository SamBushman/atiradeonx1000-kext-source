/* gl_feature_vao_test.c - GL_APPLE_vertex_array_object: glGenVertexArraysAPPLE/glBindVertexArrayAPPLE
 * should save/restore vertex-array client state (enabled arrays, pointers) exactly like a real draw with
 * that state set directly. Never checked before. */
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

    GLfloat vertsA[4*2] = {-1,-1, 1,-1, 1,1, -1,1};
    GLfloat vertsB[4*2] = {-0.5f,-0.5f, 0.5f,-0.5f, 0.5f,0.5f, -0.5f,0.5f};

    GLuint vao; glGenVertexArraysAPPLE(1, &vao);
    glBindVertexArrayAPPLE(vao);
    glVertexPointer(2, GL_FLOAT, 0, vertsA);
    glEnableClientState(GL_VERTEX_ARRAY);
    glBindVertexArrayAPPLE(0);

    /* set up DIFFERENT state directly (not through the VAO) */
    glVertexPointer(2, GL_FLOAT, 0, vertsB);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(1,1,1);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_QUADS, 0, 4);
    GLubyte direct[3]; readback(direct);   /* full-screen-ish quad from vertsB */

    /* now bind the VAO back - should restore vertsA's pointer/enable state */
    glBindVertexArrayAPPLE(vao);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_QUADS, 0, 4);
    GLubyte viaVAO[3]; readback(viaVAO);

    /* vertsA is a LARGER quad (-1..1) than vertsB (-0.5..0.5); sample a point only vertsA's footprint covers (e.g. near the edge) */
    GLfloat edgeNDCx = 0.8f;   /* inside vertsA's quad, outside vertsB's */
    int edgeWinX = (int)((edgeNDCx+1.0f)/2.0f*W);
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *edge = buf + (H/2*W+edgeWinX)*4;
    int ok = (edge[0] > 200);   /* lit only if vertsA's (larger) quad is what actually rendered via the VAO */
    printf("VAO restores vertsA's pointer: edge-of-vertsA-only sample = %d,%d,%d (want lit, confirming VAO's quad is the large one) %s\n",
           edge[0],edge[1],edge[2], ok?"OK":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
