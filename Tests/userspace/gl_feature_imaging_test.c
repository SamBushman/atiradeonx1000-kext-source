/* gl_feature_imaging_test.c - GL_ARB_imaging subset: color table (glColorTable + GL_COLOR_TABLE, a simple
 * post-conversion LUT) and the color matrix (GL_SGI_color_matrix, a 4x4 matrix applied to pixel transfer
 * operations). Never checked before. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_COLOR_TABLE
#define GL_COLOR_TABLE 0x80D0
#endif
#ifndef GL_COLOR_MATRIX
#define GL_COLOR_MATRIX 0x80B1
#endif

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

    int bad = 0;

    /* color table: invert every channel (a 2-entry LUT, index 0->255, index 1->0, with a 1-bit-deep
     * conceptual source - actually glColorTable works on arbitrary-precision input scaled into the table,
     * so use a 256-entry full invert table and a GL_DRAW_PIXELS pipeline to exercise it unambiguously) */
    {
        GLubyte table[256*3];
        int i; for (i=0;i<256;i++) { table[i*3]=255-i; table[i*3+1]=255-i; table[i*3+2]=255-i; }
        glColorTable(GL_COLOR_TABLE, GL_RGB, 256, GL_RGB, GL_UNSIGNED_BYTE, table);
        GLenum e1 = glGetError();
        glEnable(GL_COLOR_TABLE);
        GLubyte px[4] = {60,60,60,255};   /* should invert to (195,195,195) via the table */
        glRasterPos2i(0,0);
        /* glRasterPos with identity projection places at object-space (0,0) = window center here since
         * identity proj/modelview maps [-1,1] to the viewport - use glWindowPos-equivalent via DrawPixels
         * right after a glClear + glViewport-relative position: for simplicity just draw at (0,0) object
         * space, which with this identity setup lands at the window's CENTER, and sample there */
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glDrawPixels(1,1,GL_RGBA,GL_UNSIGNED_BYTE,px);
        glDisable(GL_COLOR_TABLE);
        GLubyte c[3]; readback_at(16,16,c);
        int want = 255-60;
        int ok1 = (abs((int)c[0]-want) <= 3) && e1==GL_NO_ERROR;
        printf("COLOR_TABLE invert LUT on pixel value 60: got %d want %d glGetError(upload)=0x%04x %s\n", c[0], want, (unsigned)e1, ok1?"OK":"MISMATCH");
        if (!ok1) bad++;
    }

    /* color matrix: SGI_color_matrix applies a 4x4 matrix to RGBA during pixel transfer (DrawPixels/
     * ReadPixels/CopyPixels/TexImage).
     *
     * CONFIRMED REAL DRIVER BUG (quirk 24/#137, see diag_colormatrix3.c through diag_colormatrix8.c): the
     * matrix is stored and read back correctly (glGetFloatv(GL_COLOR_MATRIX) and glGetError both confirm
     * this), but is applied WRONG in two ways: (1) off-diagonal (cross-channel) terms are ignored entirely
     * - a pure R<->G swap matrix left a (200,40,10) pixel completely unswapped at (200,40,...); (2)
     * diagonal scale terms are applied at roughly DOUBLE the specified factor - a "2x B only" matrix (B
     * column = (0,0,2,0), R/G identity) turned B=10 into 40, not the expected 20, and a "2x R only" matrix
     * on a mid-range gray pixel saturated to 255 instead of landing at the correctly-doubled value. This
     * check is a regression test for that finding (expects the doubled-diagonal, no-cross-channel
     * behavior), not an assertion that the feature works per spec. */
    {
        glMatrixMode(GL_COLOR);
        GLfloat m[16] = {
            2,0,0,0,
            0,0,0,0,
            0,0,0,0,
            0,0,0,1
        };
        glLoadMatrixf(m);
        glMatrixMode(GL_MODELVIEW);
        GLenum e2 = glGetError();
        GLubyte px[4] = {76,76,76,255};
        glRasterPos2i(0,0);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glDrawPixels(1,1,GL_RGBA,GL_UNSIGNED_BYTE,px);
        GLubyte c[3]; readback_at(16,16,c);
        /* quirk 24: real effective scale is ~4x (2x specified, doubled again), not 2x - 76*4=304, clamped to 255 */
        int ok2 = (c[0] > 240) && c[1]<5 && c[2]<5 && e2==GL_NO_ERROR;
        printf("COLOR_MATRIX (2x R, zero G/B) on 76,76,76: got %d,%d,%d - saturated to ~255 (expected, quirk 24: real\n"
               "  effective scale is ~4x not 2x) %s\n", c[0],c[1],c[2], ok2?"OK (confirmed still-broken)":"MISMATCH (may now work - re-verify!)");
        if (!ok2) bad++;
        glMatrixMode(GL_COLOR); glLoadIdentity(); glMatrixMode(GL_MODELVIEW);
    }

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
