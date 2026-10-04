/* gl_feature_polymode_linestipple_test.c - glPolygonMode(GL_LINE/GL_POINT, not just GL_FILL) and
 * GL_LINE_STIPPLE, never checked before. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static int count_lit(GLubyte *buf) {
    int i, n=0;
    for (i=0;i<W*H;i++) if (buf[i*4] > 200) n++;
    return n;
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

    static GLubyte buf[W*H*4];
    int bad = 0;

    /* GL_FILL (default): a big quad lights nearly every pixel */
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_QUADS); glVertex2f(-0.9f,-0.9f); glVertex2f(0.9f,-0.9f); glVertex2f(0.9f,0.9f); glVertex2f(-0.9f,0.9f); glEnd();
    glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int fill_lit = count_lit(buf);

    /* GL_LINE: the same quad, outline only - should light far fewer pixels */
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_QUADS); glVertex2f(-0.9f,-0.9f); glVertex2f(0.9f,-0.9f); glVertex2f(0.9f,0.9f); glVertex2f(-0.9f,0.9f); glEnd();
    glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int line_lit = count_lit(buf);
    int ok1 = (line_lit > 0) && (line_lit < fill_lit/2);
    printf("PolygonMode FILL=%d lit, LINE=%d lit (want LINE << FILL and > 0) %s\n", fill_lit, line_lit, ok1?"OK":"MISMATCH");
    if (!ok1) bad++;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /* GL_LINE_STIPPLE: a long horizontal line with a coarse on/off pattern should light noticeably fewer
     * pixels than the same line unstippled */
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1); glLineWidth(1.0f);
    glBegin(GL_LINES); glVertex2f(-0.95f,0); glVertex2f(0.95f,0); glEnd();
    glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int solid_lit = count_lit(buf);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);   /* 8 on, 8 off */
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_LINES); glVertex2f(-0.95f,0); glVertex2f(0.95f,0); glEnd();
    glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int stipple_lit = count_lit(buf);
    int ok2 = (stipple_lit > 0) && (stipple_lit < solid_lit);
    printf("LINE_STIPPLE: solid=%d lit, stippled(8-on-8-off)=%d lit (want stippled < solid, > 0) %s\n", solid_lit, stipple_lit, ok2?"OK":"MISMATCH");
    if (!ok2) bad++;

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
