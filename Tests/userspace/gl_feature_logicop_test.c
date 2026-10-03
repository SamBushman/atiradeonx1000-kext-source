/* gl_feature_logicop_test.c - issue #128: GL 1.5 feature-completeness check for glLogicOp (GL_COLOR_LOGIC_OP), against the exact
 * spec-defined bitwise result, not opcode emission.
 *
 * Spec (GL 1.5 sec 4.1.9, table 4.1): with GL_COLOR_LOGIC_OP enabled, the fragment colour and the framebuffer colour (both as their
 * raw integer bit patterns) are combined per-channel by the selected op instead of blending. Tested here with exact 8-bit integer
 * colours (via glColor3ub) so the expected result is a plain bitwise computation with no floating-point rounding at all. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

typedef struct { GLenum op; const char *name; } OpCase;

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
    if (err || npix == 0 || !pf) { die("ChoosePixelFormat", err); return 1; }
    CGLContextObj ctx = NULL;
    err = CGLCreateContext(pf, NULL, &ctx);
    if (err) { die("CreateContext", err); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf = NULL;
    err = CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }

    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_LOGIC_OP);

    GLubyte dstR = 0xB4, dstG = 0x3C, dstB = 0x5A;   /* arbitrary non-trivial background bit pattern */
    GLubyte srcR = 0x6D, srcG = 0xC3, srcB = 0x81;

    OpCase cases[] = {
        {GL_CLEAR, "CLEAR"}, {GL_SET, "SET"}, {GL_COPY, "COPY"}, {GL_NOOP, "NOOP"},
        {GL_AND, "AND"}, {GL_OR, "OR"}, {GL_XOR, "XOR"}, {GL_NAND, "NAND"}, {GL_NOR, "NOR"},
        {GL_EQUIV, "EQUIV"}, {GL_INVERT, "INVERT"}, {GL_AND_REVERSE, "AND_REVERSE"},
        {GL_OR_REVERSE, "OR_REVERSE"}, {GL_COPY_INVERTED, "COPY_INVERTED"}, {GL_AND_INVERTED, "AND_INVERTED"}, {GL_OR_INVERTED, "OR_INVERTED"},
    };
    int n = sizeof cases / sizeof cases[0], i;
    static GLubyte buf[W * H * 4];
    int bad = 0;

    for (i = 0; i < n; i++) {
        glDisable(GL_COLOR_LOGIC_OP);
        glClearColor(dstR / 255.0f, dstG / 255.0f, dstB / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_COLOR_LOGIC_OP);
        glLogicOp(cases[i].op);
        glColor3ub(srcR, srcG, srcB);
        glBegin(GL_QUADS);
        glVertex2f(0, 0); glVertex2f(W, 0); glVertex2f(W, H); glVertex2f(0, H);
        glEnd();
        glFinish();
        glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);

        GLubyte wr, wg, wb;
        switch (cases[i].op) {
            case GL_CLEAR: wr = 0; wg = 0; wb = 0; break;
            case GL_SET: wr = 0xff; wg = 0xff; wb = 0xff; break;
            case GL_COPY: wr = srcR; wg = srcG; wb = srcB; break;
            case GL_NOOP: wr = dstR; wg = dstG; wb = dstB; break;
            case GL_AND: wr = srcR & dstR; wg = srcG & dstG; wb = srcB & dstB; break;
            case GL_OR: wr = srcR | dstR; wg = srcG | dstG; wb = srcB | dstB; break;
            case GL_XOR: wr = srcR ^ dstR; wg = srcG ^ dstG; wb = srcB ^ dstB; break;
            case GL_NAND: wr = ~(srcR & dstR); wg = ~(srcG & dstG); wb = ~(srcB & dstB); break;
            case GL_NOR: wr = ~(srcR | dstR); wg = ~(srcG | dstG); wb = ~(srcB | dstB); break;
            case GL_EQUIV: wr = ~(srcR ^ dstR); wg = ~(srcG ^ dstG); wb = ~(srcB ^ dstB); break;
            case GL_INVERT: wr = ~dstR; wg = ~dstG; wb = ~dstB; break;
            case GL_AND_REVERSE: wr = srcR & ~dstR; wg = srcG & ~dstG; wb = srcB & ~dstB; break;
            case GL_OR_REVERSE: wr = srcR | ~dstR; wg = srcG | ~dstG; wb = srcB | ~dstB; break;
            case GL_COPY_INVERTED: wr = ~srcR; wg = ~srcG; wb = ~srcB; break;
            case GL_AND_INVERTED: wr = ~srcR & dstR; wg = ~srcG & dstG; wb = ~srcB & dstB; break;
            case GL_OR_INVERTED: wr = ~srcR | dstR; wg = ~srcG | dstG; wb = ~srcB | dstB; break;
            default: wr = wg = wb = 0;
        }
        int x = W / 2, y = H / 2;
        GLubyte *p = buf + (y * W + x) * 4;
        int ok = (p[0] == wr && p[1] == wg && p[2] == wb);
        printf("%-14s got %02x,%02x,%02x want %02x,%02x,%02x %s\n", cases[i].name, p[0], p[1], p[2], wr, wg, wb, ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
    }
    printf("RESULT: %s (%d mismatches of %d ops)\n", bad == 0 ? "PASS" : "FAIL", bad, n);
    return bad ? 1 : 0;
}
