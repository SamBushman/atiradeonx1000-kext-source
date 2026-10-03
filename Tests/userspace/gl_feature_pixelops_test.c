/* gl_feature_pixelops_test.c - issue #128 gap list: glDrawPixels/glCopyPixels/glBitmap pixel-op CORRECTNESS,
 * only ever checked for opcode EMISSION before (#42), never for actual output correctness. */
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
    /* glRasterPos is transformed by the current MODELVIEW/PROJECTION like any vertex - a window-pixel-space
     * ortho (0,W)x(0,H) is needed so glRasterPos2i(x,y) lands at window pixel (x,y); with the plain identity
     * projection used elsewhere in this test suite, glRasterPos2i(4,4) is object-space (4,4), miles outside
     * the [-1,1] clip volume, silently invalidating the raster position and making every subsequent
     * DrawPixels/CopyPixels/Bitmap call a no-op - this was the root cause of this test's original 3 failures. */
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glPixelZoom(1.0f, 1.0f);

    int bad = 0;
    GLubyte c[3];

    /* glDrawPixels: upload a known 8x8 solid-orange block at raster pos (4,4) */
    GLubyte block[8*8*4];
    { int i; for (i=0;i<8*8;i++) { block[i*4]=255; block[i*4+1]=128; block[i*4+2]=0; block[i*4+3]=255; } }
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glRasterPos2i(4,4);
    glDrawPixels(8,8,GL_RGBA,GL_UNSIGNED_BYTE,block);
    readback_at(8,8,c);
    int ok1 = (c[0]==255 && c[1]==128 && c[2]==0);
    printf("glDrawPixels 8x8 orange at (4,4): got %d,%d,%d want 255,128,0 %s\n", c[0],c[1],c[2], ok1?"OK":"MISMATCH");
    if (!ok1) bad++;
    readback_at(0,0,c);   /* outside the block, should remain background */
    int ok1b = (c[0]==0 && c[1]==0 && c[2]==0);
    printf("  outside block (0,0): got %d,%d,%d want 0,0,0 %s\n", c[0],c[1],c[2], ok1b?"OK":"MISMATCH");
    if (!ok1b) bad++;

    /* glCopyPixels: copy that orange block from (4,4) to (16,16) in the color buffer */
    glRasterPos2i(16,16);
    glCopyPixels(4,4,8,8,GL_COLOR);
    readback_at(20,20,c);
    int ok2 = (c[0]==255 && c[1]==128 && c[2]==0);
    printf("glCopyPixels orange block (4,4)->(16,16): got %d,%d,%d want 255,128,0 %s\n", c[0],c[1],c[2], ok2?"OK":"MISMATCH");
    if (!ok2) bad++;

    /* glBitmap: a 1-bit 8x8 pattern (checkerboard), drawn in green; set bits -> green, clear bits -> unchanged background */
    GLubyte bitmap[8] = { 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55 };  /* alternating bit rows */
    glClearColor(0,0,1,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glRasterPos2i(4,4);
    glBitmap(8,8,0,0,0,0,bitmap);
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    /* row 0 (bottom of the bitmap, at y=4) = 0xAA = 10101010 -> bit7 (leftmost, x=4) is SET -> green at x=4,y=4 */
    GLubyte *pset = buf + (4*W+4)*4;
    GLubyte *pclear = buf + (4*W+5)*4;   /* bit6 = 0 -> background blue */
    int ok3 = (pset[1]==255 && pset[2]==0) && (pclear[2]==255 && pclear[1]==0);
    printf("glBitmap checkerboard: set-bit pixel=%d,%d,%d (want green) clear-bit pixel=%d,%d,%d (want blue) %s\n",
           pset[0],pset[1],pset[2], pclear[0],pclear[1],pclear[2], ok3?"OK":"MISMATCH");
    if (!ok3) bad++;

    printf("RESULT: %s (%d mismatches of 4 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
