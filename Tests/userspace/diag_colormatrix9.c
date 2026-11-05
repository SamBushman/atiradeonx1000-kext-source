/* diag_colormatrix9.c - #137: is GL_COLOR_MATRIX applied TWICE (result = M*M*c) by glDrawPixels/glCopyPixels? For several matrices prints the observed RGBA next to the
 * single-application prediction (M*c) and the double-application prediction (M*M*c). Matrices are written ROW-major below and loaded transposed (glLoadMatrixf is column-major).
 * glReadPixels itself ignores the color matrix (#137 comment), so reading the framebuffer back is a clean observation. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#define W 8
#define H 8
static int clampb(float v) { int r = (int)floorf(v * 255.0f + 0.5f); return r < 0 ? 0 : r > 255 ? 255 : r; }
static void mulv(const float m[16], const float in[4], float out[4]) { int r, c; for (r = 0; r < 4; r++) { out[r] = 0; for (c = 0; c < 4; c++) out[r] += m[r * 4 + c] * in[c]; } }
static int bad = 0;
static void trial(const char *name, const float rm[16], int r, int g, int b, int a, int useCopy) {
    float cm[16], in[4], one[4], two[4]; GLubyte px[4] = { r, g, b, a }, out[W * H * 4]; int i, j, ok1, ok2;
    for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) cm[j * 4 + i] = rm[i * 4 + j];
    in[0] = r / 255.0f; in[1] = g / 255.0f; in[2] = b / 255.0f; in[3] = a / 255.0f;
    mulv(rm, in, one); mulv(rm, one, two);
    glMatrixMode(GL_COLOR); glLoadMatrixf(cm); glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 0); glClear(GL_COLOR_BUFFER_BIT);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); glRasterPos2i(0, 0);
    if (!useCopy) glDrawPixels(1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px);
    else { /* first draw the source pixel with the identity matrix, then copy it with the matrix active */
        float id[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
        glMatrixMode(GL_COLOR); glLoadIdentity(); glMatrixMode(GL_MODELVIEW);
        glDrawPixels(1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px);
        glMatrixMode(GL_COLOR); glLoadMatrixf(cm); glMatrixMode(GL_MODELVIEW);
        glRasterPos2i(4, 4); glCopyPixels(0, 0, 1, 1, GL_COLOR);
    }
    glFinish();
    glReadPixels(useCopy ? 4 : 0, useCopy ? 4 : 0, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, out);
    ok1 = abs(out[0] - clampb(one[0])) <= 2 && abs(out[1] - clampb(one[1])) <= 2 && abs(out[2] - clampb(one[2])) <= 2 && abs(out[3] - clampb(one[3])) <= 2;
    ok2 = abs(out[0] - clampb(two[0])) <= 2 && abs(out[1] - clampb(two[1])) <= 2 && abs(out[2] - clampb(two[2])) <= 2 && abs(out[3] - clampb(two[3])) <= 2;
    printf("%-34s %s in=(%3d,%3d,%3d,%3d) observed=(%3d,%3d,%3d,%3d)  M*c=(%3d,%3d,%3d,%3d)  M*M*c=(%3d,%3d,%3d,%3d)  => %s\n", name, useCopy ? "copy:" : "draw:", r, g, b, a,
           out[0], out[1], out[2], out[3], clampb(one[0]), clampb(one[1]), clampb(one[2]), clampb(one[3]), clampb(two[0]), clampb(two[1]), clampb(two[2]), clampb(two[3]),
           ok1 && ok2 ? "both (ambiguous)" : ok1 ? "SINGLE" : ok2 ? "DOUBLE" : "NEITHER");
    if (!ok2) bad++;
}
int main(void) {
    CGLPixelFormatObj pf; GLint npix = 0; CGLContextObj ctx; CGLPBufferObj pbuf; int pass;
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    float half[16]   = { 0.5f,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
    float twoB[16]   = { 1,0,0,0, 0,1,0,0, 0,0,2,0, 0,0,0,1 };
    float swap[16]   = { 0,1,0,0, 1,0,0,0, 0,0,0,0, 0,0,0,1 };
    float cycle[16]  = { 0,1,0,0, 0,0,1,0, 1,0,0,0, 0,0,0,1 };
    float general[16]= { 0.5f,0.2f,0,0, 0.1f,0.6f,0.1f,0, 0,0.3f,0.4f,0, 0,0,0,1 };
    float gray[16]   = { 0.3f,0.59f,0.11f,0, 0.3f,0.59f,0.11f,0, 0.3f,0.59f,0.11f,0, 0,0,0,1 };
    float ident[16]  = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
    if (CGLChoosePixelFormat(attrs, &pf, &npix) || !pf) { printf("no pixel format\n"); return 1; }
    CGLCreateContext(pf, NULL, &ctx); CGLDestroyPixelFormat(pf); CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    CGLSetCurrentContext(ctx); CGLSetPBuffer(ctx, pbuf, 0, 0, 0);
    glViewport(0, 0, W, H); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1); glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    for (pass = 0; pass < 2; pass++) {
        trial("identity", ident, 200, 40, 10, 255, pass);
        trial("diag(0.5,1,1,1)", half, 200, 40, 10, 255, pass);
        trial("diag(1,1,2,1) [issue case]", twoB, 200, 40, 10, 255, pass);
        trial("R<->G swap, B=0 [issue case]", swap, 200, 40, 10, 255, pass);
        trial("3-cycle R'=G G'=B B'=R", cycle, 200, 40, 10, 255, pass);
        trial("general (no clamping)", general, 200, 100, 50, 255, pass);
        trial("luminance (rows = .3 .59 .11)", gray, 200, 100, 50, 255, pass);
    }
    printf("RESULT: %s (%d trials not explained by M*M*c)\n", bad == 0 ? "DOUBLE application explains every trial" : "double application does NOT explain all trials", bad);
    return 0;
}
