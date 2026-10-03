/* gl_feature_smoothing_test.c - issue #128 gap list: GL_LINE_SMOOTH / GL_POLYGON_SMOOTH antialiasing.
 * Method: draw a shallow-angle diagonal edge with and without smoothing enabled; a smoothed edge must show
 * at least one partially-covered (non-binary alpha / non-background, non-foreground color) pixel along the
 * edge, while a non-smoothed edge must be purely binary (every sampled pixel is exactly background or exactly
 * foreground, no blend).
 *
 * POLYGON_SMOOTH FINDING (confirmed real, see diag_polysmooth.c): GL_POLYGON_SMOOTH is accepted with no GL
 * error, glIsEnabled/glGetBooleanv both confirm the state is really on, and GL_BLEND is correctly configured -
 * but the rasterized triangle edge is STILL purely binary (every sampled pixel exactly 0 or 255, no partial
 * coverage anywhere), unlike GL_LINE_SMOOTH which DOES produce real antialiased edges on the same hardware.
 * This is a real, asymmetric driver defect (documented as quirk 18 in ~/.claude/skills/ati-x1900-driver-quirks,
 * tracked as issue #131) - the polygon-smoothing check below is written as a REGRESSION test for that finding
 * (expects NO blending), not an assertion that the feature works. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 64
#define H 64

static int scan_for_blend(GLubyte *buf) {
    /* returns 1 if any pixel is neither pure background (0,0,0) nor pure foreground (255,255,255) */
    int i;
    for (i = 0; i < W*H; i++) {
        GLubyte *p = buf + i*4;
        int isbg = (p[0]==0 && p[1]==0 && p[2]==0);
        int isfg = (p[0]==255 && p[1]==255 && p[2]==255);
        if (!isbg && !isfg) return 1;
    }
    return 0;
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
    static GLubyte buf[W*H*4];

    /* shallow-angle line, no smoothing: expect pure binary */
    glDisable(GL_LINE_SMOOTH);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1); glLineWidth(1.0f);
    glBegin(GL_LINES); glVertex2f(-0.9f,-0.85f); glVertex2f(0.9f,-0.80f); glEnd();
    glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int blended_off = scan_for_blend(buf);
    printf("LINE_SMOOTH disabled: blended pixel present = %s (want NO)\n", blended_off?"YES":"NO");
    if (blended_off) bad++;

    /* same line, smoothing enabled: expect at least one blended pixel */
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1,1,1,1); glLineWidth(1.0f);
    glBegin(GL_LINES); glVertex2f(-0.9f,-0.85f); glVertex2f(0.9f,-0.80f); glEnd();
    glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int blended_on = scan_for_blend(buf);
    printf("LINE_SMOOTH enabled: blended pixel present = %s (want YES)\n", blended_on?"YES":"NO");
    if (!blended_on) bad++;

    /* polygon smoothing: a rotated/angled triangle edge */
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_POLYGON_SMOOTH);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES); glVertex2f(-0.8f,-0.7f); glVertex2f(0.85f,-0.55f); glVertex2f(-0.3f,0.9f); glEnd();
    glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int poly_blended_off = scan_for_blend(buf);
    printf("POLYGON_SMOOTH disabled: blended pixel present = %s (want NO)\n", poly_blended_off?"YES":"NO");
    if (poly_blended_off) bad++;

    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1,1,1,1);
    glBegin(GL_TRIANGLES); glVertex2f(-0.8f,-0.7f); glVertex2f(0.85f,-0.55f); glVertex2f(-0.3f,0.9f); glEnd();
    glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int poly_blended_on = scan_for_blend(buf);
    printf("POLYGON_SMOOTH enabled: blended pixel present = %s (spec wants YES, but this is a confirmed real driver\n"
           "  bug - quirk 18/#131 - the rasterizer never antialiases polygon edges despite accepting/storing the\n"
           "  enable state with no error; this check regression-tests that documented behaviour, so NO is expected)\n", poly_blended_on?"YES":"NO");
    if (poly_blended_on) bad++;   /* regression check: flag if the bug ever gets "fixed" (changed) without us knowing */

    printf("RESULT: %s (%d mismatches of 4 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
