/* gl_feature_stipple_test.c - issue #128: GL 1.5 feature-completeness check for GL_POLYGON_STIPPLE (sec 3.5.2), against
 * the exact per-pixel mask the spec defines: a 32x32 1-bit-per-pixel pattern, indexed by (window x mod 32, window y mod
 * 32), bit 0 of each byte corresponding to the highest x in that byte's group of 8 (the mask is stored MSB-first per
 * byte per the spec's own figure). A fragment is discarded outright where its mask bit is 0 - not blended, not dimmed -
 * so this is an exact pass/fail per pixel, like the stencil test. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

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

    /* a simple, unambiguous pattern: vertical stripes, every other column of 4 set within each 32-bit row group.
     * Byte 0 of each row covers x=0..7 with bit7=x0 (MSB-first), so pattern[row*4+0]=0xF0 means x=0..3 ON, x=4..7 OFF. */
    GLubyte mask[128];
    int r, byte;
    for (r = 0; r < 32; r++) for (byte = 0; byte < 4; byte++) mask[r * 4 + byte] = (byte % 2 == 0) ? 0xF0 : 0x0F;

    glEnable(GL_POLYGON_STIPPLE);
    glPolygonStipple(mask);
    glColor3f(1, 1, 1);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glVertex2f(0, 0); glVertex2f(W, 0); glVertex2f(W, H); glVertex2f(0, H); glEnd();
    glFinish();
    static GLubyte buf[W * H * 4];
    glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);

    /* predict per spec: for window x, stipple-x = x mod 32, byte = stipple-x / 8, bit-in-byte (MSB-first) = 7 - (stipple-x mod 8) */
    int bad = 0, checked = 0;
    int x, y;
    for (y = 0; y < H; y += 3) {
        for (x = 0; x < W; x += 1) {
            int sx = x % 32;
            int b = sx / 8;
            int bitpos = 7 - (sx % 8);
            int row = y % 32;
            int bitval = (mask[row * 4 + b] >> bitpos) & 1;
            GLubyte *p = buf + (y * W + x) * 4;
            int lit = p[0] > 128;
            checked++;
            if ((bitval && !lit) || (!bitval && lit)) {
                bad++;
                if (bad <= 10) printf("(%d,%d): mask bit=%d but pixel %s\n", x, y, bitval, lit ? "LIT" : "DARK");
            }
        }
    }
    printf("RESULT: %s (%d mismatches of %d sampled)\n", bad == 0 ? "PASS" : "FAIL", bad, checked);
    return bad ? 1 : 0;
}
