/* gl_feature_blendfuncsep_drawrange_test.c - EXT_blend_func_separate (independent RGB/alpha blend factors)
 * and EXT_draw_range_elements (glDrawRangeElements vs plain glDrawElements), never checked before. */
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

    int bad = 0;
    GLubyte c[4];

    /* blendFuncSeparate: RGB uses (SRC_ALPHA, ONE_MINUS_SRC_ALPHA) [normal blend], alpha uses (ONE, ZERO)
     * [alpha just passes through src alpha unmodified by dst]. dst=(0.6,0.4,0.2,0.9), src=(0.3,0.3,0.3,0.5) */
    glClearColor(0.6f,0.4f,0.2f,0.9f); glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFuncSeparateEXT(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);
    glColor4f(0.3f,0.3f,0.3f,0.5f);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    readback(c);
    float wr = 0.3f*0.5f + 0.6f*0.5f, wg = 0.3f*0.5f + 0.4f*0.5f, wb = 0.3f*0.5f + 0.2f*0.5f, wa = 0.5f;
    int wR=(int)(wr*255+0.5f), wG=(int)(wg*255+0.5f), wB=(int)(wb*255+0.5f), wA=(int)(wa*255+0.5f);
    int ok1 = abs((int)c[0]-wR)<=3 && abs((int)c[1]-wG)<=3 && abs((int)c[2]-wB)<=3 && abs((int)c[3]-wA)<=3;
    printf("BlendFuncSeparate: got %d,%d,%d,%d want %d,%d,%d,%d %s\n", c[0],c[1],c[2],c[3], wR,wG,wB,wA, ok1?"OK":"MISMATCH");
    if (!ok1) bad++;
    glDisable(GL_BLEND);

    /* draw-range-elements: draw a quad via glDrawRangeElements and confirm it renders identically to
     * glDrawElements with the same indices */
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    GLfloat verts[4*2] = {-1,-1, 1,-1, 1,1, -1,1};
    GLubyte idx[6] = {0,1,2, 0,2,3};
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(1,1,1);

    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, idx);
    GLubyte de[4]; readback(de);

    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawRangeElements(GL_TRIANGLES, 0, 3, 6, GL_UNSIGNED_BYTE, idx);
    GLubyte dre[4]; readback(dre);
    glDisableClientState(GL_VERTEX_ARRAY);

    int ok2 = (de[0]==dre[0] && de[1]==dre[1] && de[2]==dre[2]);
    printf("DrawRangeElements vs DrawElements: %d,%d,%d vs %d,%d,%d (want identical) %s\n", de[0],de[1],de[2], dre[0],dre[1],dre[2], ok2?"OK":"MISMATCH");
    if (!ok2) bad++;

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
