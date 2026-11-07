/* gl_copypixels_exact_test.c - glCopyPixels (colour, overlapping source/destination: the GLDriver's software path gld_drawPixelsAsPoints turns every source pixel into a point whose colour is
 * byte/255.0f, issue #232) must reproduce every byte value of every channel. 4 passes x 4096 pixels visit all 256 values of R, G, B and A several times; a pass is written with glDrawPixels, read back,
 * copied onto itself (overlapping rectangle) and read back again; a second copy moves the lower-left 32x32 to (32,32). Prints one line per check; the output is byte-identical between two drivers that behave alike,
 * and the self-check ("exact") counts the bytes that came back different from what was drawn.
 * Build on the G5:  gcc -arch ppc -std=gnu99 -w -o gl_copypixels_exact_test gl_copypixels_exact_test.c -framework OpenGL
 * Run: ./gl_copypixels_exact_test [> out]   (CGL pbuffer context, no window) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#define W 64
#define H 64
static unsigned fnv(const unsigned char *p, int n) { unsigned h = 2166136261u; int i; for (i = 0; i < n; i++) h = (h ^ p[i]) * 16777619u; return h; }
int main(void) {
    CGLPixelFormatObj pf; GLint npix = 0; CGLContextObj ctx = NULL; CGLPBufferObj pbuf = NULL;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    static unsigned char src[W * H * 4], rb[W * H * 4];
    int pass, i, total_bad = 0;
    if (CGLChoosePixelFormat(attrs, &pf, &npix) || !pf) { printf("FAIL pixel format\n"); return 1; }
    if (CGLCreateContext(pf, NULL, &ctx)) { printf("FAIL context\n"); return 1; }
    CGLDestroyPixelFormat(pf);
    if (CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf)) { printf("FAIL pbuffer\n"); return 1; }
    if (CGLSetCurrentContext(ctx) || CGLSetPBuffer(ctx, pbuf, 0, 0, 0)) { printf("FAIL attach\n"); return 1; }
    glViewport(0, 0, W, H); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1); glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST); glDisable(GL_BLEND); glDisable(GL_DITHER); glPixelStorei(GL_PACK_ALIGNMENT, 1); glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    for (pass = 0; pass < 4; pass++) {
        for (i = 0; i < W * H; i++) { src[i * 4] = (i + pass * 64) & 255; src[i * 4 + 1] = (i * 3 + pass * 17 + (i >> 8)) & 255; src[i * 4 + 2] = (255 - (i + pass * 91)) & 255; src[i * 4 + 3] = (i * 7 + pass * 5) & 255; }
        glClearColor(0, 0, 0, 0); glClear(GL_COLOR_BUFFER_BIT);
        glRasterPos2i(0, 0); glDrawPixels(W, H, GL_RGBA, GL_UNSIGNED_BYTE, src); glFinish();
        glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, rb);
        { int bad = 0; for (i = 0; i < W * H * 4; i++) bad += rb[i] != src[i]; printf("pass %d draw   hash %08x exact-bad %d\n", pass, fnv(rb, sizeof rb), bad); total_bad += bad; }
        glRasterPos2i(0, 0); glCopyPixels(0, 0, W, H, GL_COLOR); glFinish();
        glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, rb);
        { int bad = 0; for (i = 0; i < W * H * 4; i++) bad += rb[i] != src[i]; printf("pass %d copy   hash %08x exact-bad %d\n", pass, fnv(rb, sizeof rb), bad); total_bad += bad; }
        glRasterPos2i(32, 32); glCopyPixels(0, 0, 32, 32, GL_COLOR); glFinish();
        glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, rb);
        { int bad = 0, x, y; for (y = 0; y < 32; y++) for (x = 0; x < 32; x++) { int k; for (k = 0; k < 4; k++) bad += rb[((y + 32) * W + x + 32) * 4 + k] != src[(y * W + x) * 4 + k]; }
          printf("pass %d shift  hash %08x exact-bad %d\n", pass, fnv(rb, sizeof rb), bad); total_bad += bad; }
    }
    printf("RESULT: %s (%d bytes differ from what was drawn)\n", total_bad ? "REPORT" : "PASS", total_bad);
    return 0;
}
