/* gl_feature_texcompress_encode_test.c - compressed-texture ENCODE path through the GL API: glTexImage2D with a DXT1/DXT3/DXT5 internal format hands uncompressed RGBA to
 * the GL stack, which compresses it; gl_feature_texcompress_test only uploads hand-built blocks (the decoder). Per format:
 *  1. a 16x16 image, left half solid red / right half solid blue (every 4x4 block has ONE colour, which DXT stores exactly): size queries, drawn with GL_NEAREST,
 *     red left / blue right required, FNV digest + first block of the compressed data read back with glGetCompressedTexImage;
 *  2. a seeded pseudo-random 16x16 image: digest of the drawn pixels and of the compressed data (no expected values - they must equal the stock driver's, which
 *     compare_gl_feature_runs.sh checks).
 * NOT a test of GLDriver's dxtCompressImage (issue #226): the Nov 6 reachability probe (exit(77) patched into dxtCompressImage's entry, positive control on
 * gldTextureMakeResident) showed that no glTexImage2D / glTexSubImage2D / glCopyTexImage2D / GENERATE_MIPMAP variant over the S3TC and ARB-compressed internal formats and the
 * RGBA/RGB/BGRA/BGR/LUMINANCE/ALPHA source formats reaches it - the GL engine compresses in software. That function is covered by Tests/userspace/dxt_test.c and fnfuzz. */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#ifndef GL_COMPRESSED_RGB_S3TC_DXT1_EXT
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3
#endif

#define W 32
#define H 32
#define TW 16
#define TH 16

static unsigned long long fnv(const unsigned char *p, int n) {
    unsigned long long h = 1469598103934665603ULL;
    while (n--) { h ^= *p++; h *= 1099511628211ULL; }
    return h;
}

int main(void) {
    static const struct { GLenum fmt; const char *name; int block; } F[] = {
        { GL_COMPRESSED_RGB_S3TC_DXT1_EXT, "DXT1", 8 }, { GL_COMPRESSED_RGBA_S3TC_DXT3_EXT, "DXT3", 16 }, { GL_COMPRESSED_RGBA_S3TC_DXT5_EXT, "DXT5", 16 } };
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    CGLContextObj ctx = NULL; CGLPBufferObj pbuf = NULL;
    GLubyte img[TW * TH * 4], out[TW * TH * 4], buf[W * H * 4];
    int i, bad = 0, x, y;
    setvbuf(stdout, NULL, _IONBF, 0);
    if (CGLChoosePixelFormat(attrs, &pf, &npix) || !npix || !pf) { printf("FAIL ChoosePixelFormat\n"); return 1; }
    if (CGLCreateContext(pf, NULL, &ctx)) { printf("FAIL CreateContext\n"); return 1; }
    CGLDestroyPixelFormat(pf);
    if (CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf)) { printf("FAIL CreatePBuffer\n"); return 1; }
    if (CGLSetCurrentContext(ctx) || CGLSetPBuffer(ctx, pbuf, 0, 0, 0)) { printf("FAIL SetCurrentContext/SetPBuffer\n"); return 1; }
    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    {
        const char *ext = (const char *)glGetString(GL_EXTENSIONS);
        if (!(ext && strstr(ext, "GL_EXT_texture_compression_s3tc"))) { printf("RESULT: SKIPPED - GL_EXT_texture_compression_s3tc not available\n"); return 0; }
    }
    for (y = 0; y < TH; y++)
        for (x = 0; x < TW; x++) {
            GLubyte *p = img + (y * TW + x) * 4;
            if (x < TW / 2) { p[0] = 255; p[1] = 0; p[2] = 0; } else { p[0] = 0; p[1] = 0; p[2] = 255; }
            p[3] = 255;
        }
    for (i = 0; i < 3; i++) {
        GLuint t; GLint comp = 0, size = 0; GLenum e;
        unsigned char *L, *R;
        int sizeExpect = (TW / 4) * (TH / 4) * F[i].block;
        while (glGetError() != GL_NO_ERROR) {}
        glGenTextures(1, &t); glBindTexture(GL_TEXTURE_2D, t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, F[i].fmt, TW, TH, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
        e = glGetError();
        if (e != GL_NO_ERROR) { printf("%s: glTexImage2D glGetError=0x%04x FAIL\n", F[i].name, e); bad++; continue; }
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_COMPRESSED, &comp);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_COMPRESSED_IMAGE_SIZE, &size);
        printf("%s: compressed=%d image size=%d (expect %d) %s\n", F[i].name, comp, size, sizeExpect, comp && size == sizeExpect ? "OK" : "MISMATCH");
        if (!comp || size != sizeExpect) { bad++; continue; }
        glEnable(GL_TEXTURE_2D); glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); glColor3f(1, 1, 1);
        glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(-1, -1); glTexCoord2f(1, 0); glVertex2f(1, -1);
        glTexCoord2f(1, 1); glVertex2f(1, 1); glTexCoord2f(0, 1); glVertex2f(-1, 1);
        glEnd();
        glFinish();
        glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        L = buf + (H / 2 * W + W / 4) * 4; R = buf + (H / 2 * W + 3 * W / 4) * 4;
        {
            int okL = L[0] > 230 && L[1] < 25 && L[2] < 25, okR = R[0] < 25 && R[1] < 25 && R[2] > 230;
            printf("%s: left expect red got %d,%d,%d %s; right expect blue got %d,%d,%d %s\n", F[i].name, L[0], L[1], L[2], okL ? "OK" : "MISMATCH", R[0], R[1], R[2], okR ? "OK" : "MISMATCH");
            if (!okL || !okR) bad++;
        }
        memset(out, 0xAA, sizeof out);
        glGetCompressedTexImage(GL_TEXTURE_2D, 0, out);
        e = glGetError();
        if (e != GL_NO_ERROR) printf("%s: glGetCompressedTexImage glGetError=0x%04x (digest skipped)\n", F[i].name, e);
        else {
            printf("%s: compressed data digest %016llx first block:", F[i].name, fnv(out, sizeExpect));
            { int b; for (b = 0; b < F[i].block; b++) printf(" %02x", out[b]); }
            printf("\n");
        }
        glDeleteTextures(1, &t);
        /* Second image: seeded pseudo-random pixels, so the colour/alpha index bits of every block are non-trivial (the solid blocks above all have index 0, which hid #226).
         * No expected pixels - the digest of the compressed data must simply equal the stock driver's (compare_gl_feature_runs.sh). */
        {
            unsigned seed = 12345u + (unsigned)i; GLubyte rnd[TW * TH * 4]; int k;
            for (k = 0; k < TW * TH * 4; k++) { seed = seed * 1103515245u + 12345u; rnd[k] = (GLubyte)(seed >> 16); }
            for (k = 3; k < TW * TH * 4; k += 4) if (F[i].fmt == GL_COMPRESSED_RGB_S3TC_DXT1_EXT) rnd[k] = 255;
            glGenTextures(1, &t); glBindTexture(GL_TEXTURE_2D, t);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);   /* default min filter is mipmapped = incomplete texture */
            while (glGetError() != GL_NO_ERROR) {}
            glTexImage2D(GL_TEXTURE_2D, 0, F[i].fmt, TW, TH, 0, GL_RGBA, GL_UNSIGNED_BYTE, rnd);
            /* the driver compresses when the texture is made resident, i.e. at the first draw that uses it: draw it, and digest the pixels the decoder produced */
            glEnable(GL_TEXTURE_2D); glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); glColor3f(1, 1, 1);
            glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex2f(-1, -1); glTexCoord2f(1, 0); glVertex2f(1, -1);
            glTexCoord2f(1, 1); glVertex2f(1, 1); glTexCoord2f(0, 1); glVertex2f(-1, 1);
            glEnd();
            glFinish();
            glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            printf("%s random: drawn pixels digest %016llx\n", F[i].name, fnv(buf, W * H * 4));
            memset(out, 0xAA, sizeof out);
            glGetCompressedTexImage(GL_TEXTURE_2D, 0, out);
            e = glGetError();
            if (e != GL_NO_ERROR) printf("%s random: glGetError=0x%04x (digest skipped)\n", F[i].name, e);
            else printf("%s random: compressed data digest %016llx\n", F[i].name, fnv(out, sizeExpect));
            glDeleteTextures(1, &t);
        }
    }
    printf("RESULT: %s\n", bad == 0 ? "PASS" : "FAIL");
    return bad ? 1 : 0;
}
