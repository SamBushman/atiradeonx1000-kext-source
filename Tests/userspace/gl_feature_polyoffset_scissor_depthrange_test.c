/* gl_feature_polyoffset_scissor_depthrange_test.c - issue #128 gap list: scissor test, glDepthRange,
 * glPolygonOffset/GL_POLYGON_OFFSET_FILL - none checked before. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, kCGLPFADepthSize,24, (CGLPixelFormatAttribute)0 };
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

    int bad = 0;
    static GLubyte buf[W*H*4];

    /* scissor test: clear whole buffer to red, set a sub-rect scissor, clear to blue - only the scissor rect should be blue */
    glDisable(GL_SCISSOR_TEST);
    glClearColor(1,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_SCISSOR_TEST);
    glScissor(4,4,8,8);
    glClearColor(0,0,1,1); glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
    glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *inside = buf + (8*W+8)*4;    /* inside the scissor rect (4..12, 4..12) */
    GLubyte *outside = buf + (20*W+20)*4; /* outside it */
    int ok1 = (inside[2]==255 && inside[0]==0) && (outside[0]==255 && outside[2]==0);
    printf("SCISSOR_TEST: inside=%d,%d,%d (want blue) outside=%d,%d,%d (want red) %s\n",
           inside[0],inside[1],inside[2], outside[0],outside[1],outside[2], ok1?"OK":"MISMATCH");
    if (!ok1) bad++;

    /* glDepthRange(0.0, 0.5): map NDC z=-1..1 to depth-buffer values 0.0..0.5. Draw a quad at NDC z=1 (far),
     * which with the compressed range should write depth ~0.5 (not ~1.0). Checked indirectly: draw it, then
     * draw a second quad with depth test LESS and a glDepthRange back to default-equivalent comparison depth
     * by instead reading GL_DEPTH_COMPONENT directly. */
    glEnable(GL_DEPTH_TEST); glDepthFunc(GL_ALWAYS);
    glClearDepth(1.0); glClear(GL_DEPTH_BUFFER_BIT);
    glDepthRange(0.0, 0.5);
    glColor3f(1,1,1);
    glBegin(GL_QUADS); glVertex3f(-1,-1,1.0f); glVertex3f(1,-1,1.0f); glVertex3f(1,1,1.0f); glVertex3f(-1,1,1.0f); glEnd();
    glFinish();
    static GLfloat dbuf[W*H];
    glReadPixels(0,0,W,H,GL_DEPTH_COMPONENT,GL_FLOAT,dbuf);
    float d = dbuf[H/2*W+W/2];
    int ok2 = (d > 0.45f && d < 0.55f);
    printf("DEPTH_RANGE(0,0.5) at NDC z=1: depth buffer value = %.4f (want ~0.5) %s\n", d, ok2?"OK":"MISMATCH");
    if (!ok2) bad++;
    glDepthRange(0.0, 1.0);

    /* GL_POLYGON_OFFSET_FILL: two coplanar quads at the same depth, one offset away from the camera -
     * with depth test LESS, the non-offset (nearer) one should win regardless of draw order */
    glDepthFunc(GL_LESS);
    glClearDepth(1.0); glClear(GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1,1,-1,1,0.1,10);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(0, 50);   /* push this one back */
    glColor3f(0,1,0);   /* green, offset, drawn FIRST */
    glBegin(GL_QUADS); glVertex3f(-1,-1,-5); glVertex3f(1,-1,-5); glVertex3f(1,1,-5); glVertex3f(-1,1,-5); glEnd();
    glPolygonOffset(0, 0);
    glColor3f(1,0,0);   /* red, no offset, drawn SECOND at the same nominal depth -> should win */
    glBegin(GL_QUADS); glVertex3f(-1,-1,-5); glVertex3f(1,-1,-5); glVertex3f(1,1,-5); glVertex3f(-1,1,-5); glEnd();
    glDisable(GL_POLYGON_OFFSET_FILL);
    glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    int ok3 = (p[0]==255 && p[1]==0);
    printf("POLYGON_OFFSET_FILL (offset pushed back, flat wins): got %d,%d,%d want 255,0,0 %s\n", p[0],p[1],p[2], ok3?"OK":"MISMATCH");
    if (!ok3) bad++;

    printf("RESULT: %s (%d mismatches of 3 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
