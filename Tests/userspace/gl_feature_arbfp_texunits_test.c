/* gl_feature_arbfp_texunits_test.c - ARB fragment programs that sample N texture units (N = 1..16): glProgramStringARB must accept every one (no GL error, error position -1),
 * and the program must draw (a solid colour texture per unit: the program's sum of the units' samples * 1/16 is a known value). Found by the Nov 6 opcode battery (glcov multitex):
 * the rebuilt libGLProgrammability raised GL_INVALID_OPERATION at glProgramStringARB for the 16-unit program the stock library compiles.
 * Build: gcc -arch ppc -o gl_feature_arbfp_texunits_test gl_feature_arbfp_texunits_test.c -framework OpenGL */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

#define W 16
#define H 16

int main(void) {
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    CGLContextObj ctx = NULL; CGLPBufferObj pbuf = NULL;
    GLuint tex[16]; GLubyte px[4 * 4 * 4], out[W * H * 4];
    int n, i, bad = 0; GLint maxUnits = 0;
    setvbuf(stdout, NULL, _IONBF, 0);
    if (CGLChoosePixelFormat(attrs, &pf, &npix) || !npix || !pf) { printf("FAIL ChoosePixelFormat\n"); return 1; }
    if (CGLCreateContext(pf, NULL, &ctx)) { printf("FAIL CreateContext\n"); return 1; }
    CGLDestroyPixelFormat(pf);
    if (CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf)) { printf("FAIL CreatePBuffer\n"); return 1; }
    if (CGLSetCurrentContext(ctx) || CGLSetPBuffer(ctx, pbuf, 0, 0, 0)) { printf("FAIL SetCurrentContext/SetPBuffer\n"); return 1; }
    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS_ARB, &maxUnits);
    printf("GL_MAX_TEXTURE_IMAGE_UNITS_ARB = %d\n", (int)maxUnits);
    /* unit i holds a solid texture of (i+1)*8 / 255 in red only: the sum over N units of red*1/16 is known */
    for (i = 0; i < 16; i++) {
        int k;
        for (k = 0; k < 16; k++) { px[k * 4] = (GLubyte)((i + 1) * 8); px[k * 4 + 1] = 0; px[k * 4 + 2] = 0; px[k * 4 + 3] = 255; }
        glActiveTexture(GL_TEXTURE0 + i); glGenTextures(1, &tex[i]); glBindTexture(GL_TEXTURE_2D, tex[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 4, 4, 0, GL_RGBA, GL_UNSIGNED_BYTE, px);
    }
    for (n = 1; n <= 16; n++) {
        char prog[4096]; GLuint p; GLenum e; GLint pos = -2; int expect = 0, got;
        strcpy(prog, "!!ARBfp1.0\nTEMP c, t;\nMOV c, 0;\n");
        for (i = 0; i < n; i++) {
            char l[96]; snprintf(l, sizeof l, "TEX t, fragment.texcoord[%d], texture[%d], 2D;\nMAD c, t, 0.0625, c;\n", i & 7, i); strcat(prog, l);
            expect += (i + 1) * 8;
        }
        strcat(prog, "MOV result.color, c;\nEND\n");
        while (glGetError() != GL_NO_ERROR) {}
        glGenProgramsARB(1, &p); glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, p);
        glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)strlen(prog), prog);
        e = glGetError(); glGetIntegerv(GL_PROGRAM_ERROR_POSITION_ARB, &pos);
        if (e != GL_NO_ERROR || pos != -1) {
            printf("%2d units: glProgramStringARB glGetError=0x%04x errorPosition=%d \"%s\" FAIL\n", n, e, (int)pos, (const char *)glGetString(GL_PROGRAM_ERROR_STRING_ARB));
            bad++; glDeleteProgramsARB(1, &p); continue;
        }
        glEnable(GL_FRAGMENT_PROGRAM_ARB);
        glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        for (i = 0; i < 4; i++) { int k; for (k = 0; k < 8; k++) glMultiTexCoord2fARB(GL_TEXTURE0 + k, (GLfloat)(i & 1), (GLfloat)(i >> 1)); glVertex2f(i & 1 ? 1.f : -1.f, i & 2 ? 1.f : -1.f); }
        glEnd();
        glDisable(GL_FRAGMENT_PROGRAM_ARB);
        glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, out);
        got = out[(H / 2 * W + W / 2) * 4];
        { int want = (expect * 1000 / 16 + 500) / 1000; int ok = got >= want - 3 && got <= want + 3; if (!ok) bad++;
          printf("%2d units: compiles, centre red = %3d (want %3d +-3) %s\n", n, got, want, ok ? "OK" : "FAIL"); }
        glDeleteProgramsARB(1, &p);
    }
    printf("RESULT: %s\n", bad == 0 ? "PASS" : "FAIL");
    return bad ? 1 : 0;
}
