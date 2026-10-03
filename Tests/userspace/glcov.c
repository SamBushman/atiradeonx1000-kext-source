/* glcov.c - issue #42: GL workloads that exercise one GL feature area at a time on the stock ATI X1900 / Tiger driver, so Tools/userspace/opcode_recorder.c can attribute the
 * command-stream opcodes each area makes the driver emit. Offscreen only (CGL pbuffer, 512x512: generously sized on purpose, see quirk 15 of the ati-x1900-driver-quirks skill), no window.
 * Correct pixels are NOT the point (several features are documented as unreliable on this driver, e.g. FBO readback); the point is to make the driver emit the commands. Every call is
 * ordinary GL; nothing here fuzzes arguments. Respects the catalog: only `#version 110`-class GLSL, power-of-two sizes for GL_TEXTURE_2D (rectangle textures for NPOT), no extra
 * glBindBuffer tricks before draws.
 *
 * Usage: glcov FEATURE [FEATURE ...]      features: multitex texfmt fbo fbo2 copypix copydepth cglparams msaa query clear state draw shaders pixel vbo bigdraw stress (env GLSTRESS_ITERS, GLSTRESS_SEED)
 * Build on the G5:  gcc -arch ppc -std=gnu99 -w -o glcov glcov.c -framework OpenGL -framework ApplicationServices
 * Each feature ends with glFinish and prints "feature <name>: glGetError sum=<n>"; exit 0 unless the context could not be created.
 */
#define GL_GLEXT_PROTOTYPES 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <signal.h>
#include <unistd.h>

#define W 512
#define H 512
#include "glstress.h"
static CGLContextObj g_ctx; static CGLPBufferObj g_pb; static int g_err;

static int make_ctx(int msaa) {
    CGLPixelFormatAttribute a[24]; int n = 0; CGLPixelFormatObj pf; GLint np = 0; CGLError e;
    a[n++] = kCGLPFAPBuffer; a[n++] = kCGLPFAAccelerated; a[n++] = kCGLPFANoRecovery; a[n++] = kCGLPFAColorSize; a[n++] = 32;
    a[n++] = kCGLPFADepthSize; a[n++] = 24; a[n++] = kCGLPFAStencilSize; a[n++] = 8;
    if (msaa) { a[n++] = kCGLPFAMultisample; a[n++] = kCGLPFASampleBuffers; a[n++] = 1; a[n++] = kCGLPFASamples; a[n++] = msaa; }
    a[n++] = 0;
    e = CGLChoosePixelFormat(a, &pf, &np); if (e || !np) { printf("no pixel format (msaa=%d) err=%d\n", msaa, (int)e); return 0; }
    e = CGLCreateContext(pf, NULL, &g_ctx); CGLDestroyPixelFormat(pf); if (e) { printf("no context err=%d\n", (int)e); return 0; }
    e = CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &g_pb); if (e) { printf("no pbuffer err=%d\n", (int)e); return 0; }
    CGLSetCurrentContext(g_ctx);
    e = CGLSetPBuffer(g_ctx, g_pb, 0, 0, 0); if (e) { printf("SetPBuffer err=%d\n", (int)e); return 0; }
    glViewport(0, 0, W, H);
    return 1;
}
static void errs(const char *what) { GLenum e; while ((e = glGetError()) != GL_NO_ERROR) { g_err++; printf("  GL error 0x%x after %s\n", e, what); } }
static void done(const char *name) { GLubyte px[4]; glFinish(); glReadPixels(W / 2, H / 2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px); errs("finish"); printf("feature %s: glGetError sum=%d\n", name, g_err); }
static void ortho(void) { glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1, 1, -1, 1, -1, 1); glMatrixMode(GL_MODELVIEW); glLoadIdentity(); }
static void quad(float z) { glBegin(GL_QUADS); glTexCoord2f(0, 0); glVertex3f(-0.9f, -0.9f, z); glTexCoord2f(1, 0); glVertex3f(0.9f, -0.9f, z); glTexCoord2f(1, 1); glVertex3f(0.9f, 0.9f, z); glTexCoord2f(0, 1); glVertex3f(-0.9f, 0.9f, z); glEnd(); }
static void tri(float x, float y, float s, float z) { glBegin(GL_TRIANGLES); glColor3f(1, 0, 0); glVertex3f(x - s, y - s, z); glColor3f(0, 1, 0); glVertex3f(x + s, y - s, z); glColor3f(0, 0, 1); glVertex3f(x, y + s, z); glEnd(); }
static GLuint tex2d(int w, int h, GLenum ifmt, GLenum fmt, GLenum type, int mips) {
    GLuint t; unsigned char *d = malloc(w * h * 16); int i, l;
    for (i = 0; i < w * h * 16; i++) d[i] = (unsigned char)(i * 7);
    glGenTextures(1, &t); glBindTexture(GL_TEXTURE_2D, t);
    for (l = 0; l < mips; l++) { glTexImage2D(GL_TEXTURE_2D, l, ifmt, w >> l ? w >> l : 1, h >> l ? h >> l : 1, 0, fmt, type, d); }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mips > 1 ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    free(d); return t;
}
static const char *fp16 = "!!ARBfp1.0\nTEMP c, t;\nMOV c, 0;\n";   /* prefix: the body is built per unit count */

/* ---- features ---- */
static void f_multitex(void) {
    int i; GLuint t[16]; char prog[4096]; GLuint p; glClearColor(0.2f, 0.2f, 0.2f, 1); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ortho();
    for (i = 0; i < 16; i++) { glActiveTexture(GL_TEXTURE0 + i); t[i] = tex2d(8, 8, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, 1); }
    errs("16 texture units");
    strcpy(prog, "!!ARBfp1.0\nTEMP c, t;\nMOV c, 0;\n");
    for (i = 0; i < 16; i++) { char l[96]; snprintf(l, sizeof l, "TEX t, fragment.texcoord[%d], texture[%d], 2D;\nMAD c, t, 0.0625, c;\n", i & 7, i); strcat(prog, l); }
    strcat(prog, "MOV result.color, c;\nEND\n");
    glGenProgramsARB(1, &p); glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, p); glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, strlen(prog), prog); errs("16-unit fragment program");
    glEnable(GL_FRAGMENT_PROGRAM_ARB);
    glBegin(GL_QUADS); for (i = 0; i < 4; i++) { int k; for (k = 0; k < 8; k++) glMultiTexCoord2fARB(GL_TEXTURE0 + k, (i & 1), (i >> 1)); glVertex2f(i & 1 ? 0.8f : -0.8f, i & 2 ? 0.8f : -0.8f); } glEnd();
    glDisable(GL_FRAGMENT_PROGRAM_ARB);
    /* rebind a different texture to every unit: the slots are replaced, which also drives the slot-clear records */
    for (i = 15; i >= 0; i--) { glActiveTexture(GL_TEXTURE0 + i); glBindTexture(GL_TEXTURE_2D, t[(i + 5) & 15]); glEnable(GL_TEXTURE_2D); }
    glActiveTexture(GL_TEXTURE0); quad(0);
    for (i = 0; i < 16; i++) { glActiveTexture(GL_TEXTURE0 + i); glBindTexture(GL_TEXTURE_2D, 0); glDisable(GL_TEXTURE_2D); }
    glActiveTexture(GL_TEXTURE0); glDeleteTextures(16, t); errs("multitex"); done("multitex");
}
static void f_texfmt(void) {
    GLuint t; int i, f; unsigned char buf[64 * 64 * 16]; float fb[16 * 16 * 4];
    memset(buf, 0x55, sizeof buf); for (i = 0; i < 16 * 16 * 4; i++) fb[i] = (float)i / 100.0f; ortho(); glEnable(GL_TEXTURE_2D);
    { GLenum fm[] = { GL_RGBA8, GL_RGB8, GL_LUMINANCE8, GL_ALPHA8, GL_LUMINANCE8_ALPHA8, GL_INTENSITY8, GL_RGBA4, GL_RGB5_A1, GL_RGB5, GL_RGBA16, GL_LUMINANCE16 };
      for (f = 0; f < (int)(sizeof fm / sizeof fm[0]); f++) { t = tex2d(32, 32, fm[f], GL_RGBA, GL_UNSIGNED_BYTE, 6); quad(0); glDeleteTextures(1, &t); } }
    errs("2D formats");
    glDisable(GL_TEXTURE_2D);
    /* rectangle (non power of two) */
    glEnable(GL_TEXTURE_RECTANGLE_EXT); glGenTextures(1, &t); glBindTexture(GL_TEXTURE_RECTANGLE_EXT, t); glTexImage2D(GL_TEXTURE_RECTANGLE_EXT, 0, GL_RGBA8, 100, 60, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    glTexParameteri(GL_TEXTURE_RECTANGLE_EXT, GL_TEXTURE_MIN_FILTER, GL_LINEAR); glBegin(GL_QUADS); glTexCoord2f(0, 0); glVertex2f(-.8f, -.8f); glTexCoord2f(100, 0); glVertex2f(.8f, -.8f); glTexCoord2f(100, 60); glVertex2f(.8f, .8f); glTexCoord2f(0, 60); glVertex2f(-.8f, .8f); glEnd();
    glTexSubImage2D(GL_TEXTURE_RECTANGLE_EXT, 0, 10, 10, 32, 16, GL_RGBA, GL_UNSIGNED_BYTE, buf); glDeleteTextures(1, &t); glDisable(GL_TEXTURE_RECTANGLE_EXT); errs("rectangle");
    /* float textures (ATI_texture_float) */
    glEnable(GL_TEXTURE_2D); glGenTextures(1, &t); glBindTexture(GL_TEXTURE_2D, t);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA_FLOAT16_ATI, 16, 16, 0, GL_RGBA, GL_FLOAT, fb); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); quad(0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA_FLOAT32_ATI, 16, 16, 0, GL_RGBA, GL_FLOAT, fb); quad(0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE_FLOAT32_ATI, 16, 16, 0, GL_LUMINANCE, GL_FLOAT, fb); quad(0); glDeleteTextures(1, &t); errs("float formats");
    /* 3D texture */
    glGenTextures(1, &t); glBindTexture(GL_TEXTURE_3D, t); glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA8, 16, 16, 8, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf); glEnable(GL_TEXTURE_3D);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); glBegin(GL_QUADS); glTexCoord3f(0, 0, .3f); glVertex2f(-.5f, -.5f); glTexCoord3f(1, 0, .3f); glVertex2f(.5f, -.5f); glTexCoord3f(1, 1, .6f); glVertex2f(.5f, .5f); glTexCoord3f(0, 1, .6f); glVertex2f(-.5f, .5f); glEnd();
    glDisable(GL_TEXTURE_3D); glDeleteTextures(1, &t); errs("3D");
    /* cube map */
    glGenTextures(1, &t); glBindTexture(GL_TEXTURE_CUBE_MAP, t);
    for (i = 0; i < 6; i++) glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA8, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR); glEnable(GL_TEXTURE_CUBE_MAP); glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP); glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP); glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
    glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T); glEnable(GL_TEXTURE_GEN_R); glNormal3f(0, 0, 1); quad(0); glDisable(GL_TEXTURE_GEN_S); glDisable(GL_TEXTURE_GEN_T); glDisable(GL_TEXTURE_GEN_R); glDisable(GL_TEXTURE_CUBE_MAP); glDeleteTextures(1, &t); errs("cube");
    /* compressed: DXT1/3/5 blocks, 3dc */
    { GLenum cf[] = { GL_COMPRESSED_RGB_S3TC_DXT1_EXT, GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, GL_COMPRESSED_RGBA_S3TC_DXT3_EXT, GL_COMPRESSED_RGBA_S3TC_DXT5_EXT }; int bs[] = { 8, 8, 16, 16 };
      for (f = 0; f < 4; f++) { glGenTextures(1, &t); glBindTexture(GL_TEXTURE_2D, t); glEnable(GL_TEXTURE_2D);
        glCompressedTexImage2D(GL_TEXTURE_2D, 0, cf[f], 16, 16, 0, bs[f] * 16, buf); glCompressedTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 8, 8, cf[f], bs[f] * 4, buf);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); quad(0); glDeleteTextures(1, &t); } }
    errs("compressed");
    /* texture state: anisotropy, lod bias, border clamp, mirrored repeat, generate mipmap, copy from framebuffer */
    glGenTextures(1, &t); glBindTexture(GL_TEXTURE_2D, t); glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf); glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 8.0f);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS_EXT, 0.5f); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    { GLenum wr[] = { GL_REPEAT, GL_CLAMP, GL_CLAMP_TO_EDGE, GL_MIRRORED_REPEAT, GL_CLAMP_TO_BORDER_ARB, GL_MIRROR_CLAMP_EXT, GL_MIRROR_CLAMP_TO_EDGE_EXT, GL_MIRROR_CLAMP_TO_BORDER_EXT };
      for (f = 0; f < 8; f++) { glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wr[f]); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wr[7 - f]); glBegin(GL_QUADS); glTexCoord2f(-1, -1); glVertex2f(-.9f, -.9f); glTexCoord2f(2, -1); glVertex2f(.9f, -.9f); glTexCoord2f(2, 2); glVertex2f(.9f, .9f); glTexCoord2f(-1, 2); glVertex2f(-.9f, .9f); glEnd(); } }
    glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 0, 0, 64, 64, 0); glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 100, 100, 32, 32); glCopyTexSubImage2D(GL_TEXTURE_2D, 1, 0, 0, 100, 100, 16, 16);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 4, 4, 16, 16, GL_RGBA, GL_UNSIGNED_BYTE, buf); glDeleteTextures(1, &t); glDisable(GL_TEXTURE_2D); errs("texture state"); done("texfmt");
}
static void f_fbo(void) {
    GLuint fb, ct, db, rb, ct2; int i; unsigned char buf[64 * 64 * 4]; memset(buf, 0x40, sizeof buf); ortho();
    glGenFramebuffersEXT(1, &fb); glGenTextures(1, &ct); glBindTexture(GL_TEXTURE_2D, ct);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glGenRenderbuffersEXT(1, &db); glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, db); glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT24, 256, 256);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb); glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, ct, 0); glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, db);
    printf("  fbo status 0x%x\n", glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT)); glViewport(0, 0, 256, 256); glClearColor(0, 0.5f, 0, 1); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glEnable(GL_DEPTH_TEST);
    for (i = 0; i < 4; i++) tri(0, 0, 0.3f + 0.1f * i, -0.5f + 0.25f * i); glDisable(GL_DEPTH_TEST); errs("render to texture");
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); glViewport(0, 0, W, H); glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, ct); glGenerateMipmapEXT(GL_TEXTURE_2D); quad(0);
    /* second color attachment texture, renderbuffer color, switching between FBOs, rectangle target, float target */
    glGenTextures(1, &ct2); glBindTexture(GL_TEXTURE_RECTANGLE_EXT, ct2); glTexImage2D(GL_TEXTURE_RECTANGLE_EXT, 0, GL_RGBA8, 200, 100, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb); glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_RECTANGLE_EXT, ct2, 0); glViewport(0, 0, 200, 100); glClear(GL_COLOR_BUFFER_BIT); tri(0, 0, .5f, 0);
    glGenRenderbuffersEXT(1, &rb); glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, rb); glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_RGBA8, 128, 128); glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_RENDERBUFFER_EXT, rb);
    glViewport(0, 0, 128, 128); glClear(GL_COLOR_BUFFER_BIT); tri(0, 0, .6f, 0); glReadPixels(0, 0, 4, 4, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, ct, 0);
    for (i = 0; i < 6; i++) { glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb); glViewport(0, 0, 256, 256); glClear(GL_COLOR_BUFFER_BIT); tri(0, 0, .2f * (i + 1), 0); }
    { GLuint cm; glGenTextures(1, &cm); glBindTexture(GL_TEXTURE_CUBE_MAP, cm); for (i = 0; i < 6; i++) glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA8, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
      for (i = 0; i < 6; i++) { glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, cm, 0); glViewport(0, 0, 64, 64); glClear(GL_COLOR_BUFFER_BIT); tri(0, 0, .5f, 0); } glDeleteTextures(1, &cm); }
    { GLuint ft; glGenTextures(1, &ft); glBindTexture(GL_TEXTURE_RECTANGLE_EXT, ft); glTexImage2D(GL_TEXTURE_RECTANGLE_EXT, 0, GL_RGBA_FLOAT16_ATI, 64, 64, 0, GL_RGBA, GL_FLOAT, NULL);
      glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_RECTANGLE_EXT, ft, 0); printf("  float fbo status 0x%x\n", glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT)); glViewport(0, 0, 64, 64); glClear(GL_COLOR_BUFFER_BIT); tri(0, 0, .5f, 0); glDeleteTextures(1, &ft); }
    /* depth texture attachment (shadow-map style) */
    { GLuint dt; glGenTextures(1, &dt); glBindTexture(GL_TEXTURE_2D, dt); glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, 128, 128, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, NULL);
      glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb); glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, ct, 0); glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_TEXTURE_2D, dt, 0);
      printf("  depth-texture fbo status 0x%x\n", glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT)); glViewport(0, 0, 128, 128); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glEnable(GL_DEPTH_TEST); tri(0, 0, .5f, 0); glDisable(GL_DEPTH_TEST);
      glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, db); glDeleteTextures(1, &dt); }
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); glViewport(0, 0, W, H); glDeleteFramebuffersEXT(1, &fb); glDeleteRenderbuffersEXT(1, &db); glDeleteRenderbuffersEXT(1, &rb); glDisable(GL_TEXTURE_2D); errs("fbo"); done("fbo");
}

static void f_fbo2(void) {
    /* consistent-size framebuffers (the "fbo" feature's float and depth-texture cases were INCOMPLETE_DIMENSIONS and rendered nothing): shadow-map style depth-only FBOs with depth TEXTURES,
     * depth+colour FBOs, float colour targets without a stale depth attachment, and sampling the depth texture afterwards */
    GLuint fb, dt, ct, rb; int i, f; GLenum dfmt[] = { GL_DEPTH_COMPONENT16, GL_DEPTH_COMPONENT24, GL_DEPTH_COMPONENT32 }; static unsigned char buf[256 * 256 * 4]; static float fbuf[256 * 256]; memset(buf, 0x30, sizeof buf); for (i = 0; i < 256 * 256; i++) fbuf[i] = (float)(i % 256) / 255.f; ortho();
    glGenFramebuffersEXT(1, &fb);
    for (f = 0; f < 3; f++) {
        int sz = f == 0 ? 128 : 256; GLenum st;
        glGenTextures(1, &dt); glBindTexture(GL_TEXTURE_2D, dt); glTexImage2D(GL_TEXTURE_2D, 0, dfmt[f], sz, sz, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE_ARB);
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb); glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_TEXTURE_2D, dt, 0); glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, 0, 0);
        glDrawBuffer(GL_NONE); glReadBuffer(GL_NONE); st = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT); printf("  depth-only fbo (%d bits-ish, %d) status 0x%x\n", f, sz, st);
        glViewport(0, 0, sz, sz); glClearDepth(1.0); glClear(GL_DEPTH_BUFFER_BIT); glEnable(GL_DEPTH_TEST); glColorMask(0, 0, 0, 0); for (i = 0; i < 6; i++) { glLoadIdentity(); glRotatef(i * 30.f, 0, 0, 1); tri(0, 0, .6f, -0.8f + i * 0.2f); } glColorMask(1, 1, 1, 1); glDisable(GL_DEPTH_TEST);
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); glDrawBuffer(GL_BACK); glReadBuffer(GL_BACK); glViewport(0, 0, W, H); glLoadIdentity();
        glBindTexture(GL_TEXTURE_2D, dt); glEnable(GL_TEXTURE_2D); glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE_ARB, GL_LUMINANCE); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_NONE); quad(0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE_ARB); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC_ARB, GL_LEQUAL); glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T); glEnable(GL_TEXTURE_GEN_R); glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR); glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR); glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR); quad(0);
        glDisable(GL_TEXTURE_GEN_S); glDisable(GL_TEXTURE_GEN_T); glDisable(GL_TEXTURE_GEN_R); glDisable(GL_TEXTURE_2D); glDeleteTextures(1, &dt); errs("depth-only fbo");
    }
    /* depth texture + colour texture of the same size, rendered, then both sampled */
    glGenTextures(1, &dt); glBindTexture(GL_TEXTURE_2D, dt); glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, 128, 128, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, NULL); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glGenTextures(1, &ct); glBindTexture(GL_TEXTURE_2D, ct); glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 128, 128, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb); glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, ct, 0); glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_TEXTURE_2D, dt, 0);
    printf("  colour+depth-texture fbo status 0x%x\n", glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT)); glViewport(0, 0, 128, 128); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glEnable(GL_DEPTH_TEST); for (i = 0; i < 4; i++) { glLoadIdentity(); glRotatef(i * 45.f, 0, 0, 1); tri(0, 0, .7f, -0.6f + i * 0.3f); } glDisable(GL_DEPTH_TEST);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); glViewport(0, 0, W, H); glLoadIdentity(); glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, ct); quad(0); glBindTexture(GL_TEXTURE_2D, dt); quad(0); glDisable(GL_TEXTURE_2D); errs("colour+depth fbo");
    /* depth textures filled from the CPU and from the framebuffer, then sampled */
    glGenTextures(1, &rb); glBindTexture(GL_TEXTURE_2D, rb); glEnable(GL_TEXTURE_2D); glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, 128, 128, 0, GL_DEPTH_COMPONENT, GL_FLOAT, fbuf); glTexSubImage2D(GL_TEXTURE_2D, 0, 8, 8, 64, 64, GL_DEPTH_COMPONENT, GL_FLOAT, fbuf);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 64, 64, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT, buf); quad(0); glClear(GL_DEPTH_BUFFER_BIT); glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, 0, 0, 128, 128, 0); quad(0); glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 16, 16, 64, 64); quad(0);
    glDisable(GL_TEXTURE_2D); glDeleteTextures(1, &rb); errs("depth texture uploads");
    /* float colour targets, no depth attachment, consistent sizes */
    { GLenum ff[] = { GL_RGBA_FLOAT16_ATI, GL_RGBA_FLOAT32_ATI, GL_RGB_FLOAT16_ATI, GL_LUMINANCE_FLOAT16_ATI, GL_ALPHA_FLOAT16_ATI, GL_INTENSITY_FLOAT16_ATI, GL_LUMINANCE_ALPHA_FLOAT16_ATI };
      GLenum tgt[2] = { GL_TEXTURE_2D, GL_TEXTURE_RECTANGLE_EXT };
      for (f = 0; f < 7; f++) { int t2; for (t2 = 0; t2 < 2; t2++) { GLuint ft; GLenum st; glGenTextures(1, &ft); glBindTexture(tgt[t2], ft); glTexImage2D(tgt[t2], 0, ff[f], 64, 64, 0, GL_RGBA, GL_FLOAT, NULL); glTexParameteri(tgt[t2], GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(tgt[t2], GL_TEXTURE_MAG_FILTER, GL_NEAREST);
          glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb); glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_TEXTURE_2D, 0, 0); glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, tgt[t2], ft, 0); st = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
          printf("  float fbo fmt %d target %d status 0x%x\n", f, t2, st); glViewport(0, 0, 64, 64); glClearColor(0.25f, 0.5f, 0.75f, 1); glClear(GL_COLOR_BUFFER_BIT); glClearColor(0, 0, 0, 0); glClear(GL_COLOR_BUFFER_BIT); glClearColor(1, 1, 1, 1); glClear(GL_COLOR_BUFFER_BIT); tri(0, 0, .6f, 0);
          glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); glViewport(0, 0, W, H); glEnable(tgt[t2]); glBegin(GL_QUADS); glTexCoord2f(0, 0); glVertex2f(-.5f, -.5f); glTexCoord2f(t2 ? 64 : 1, 0); glVertex2f(.5f, -.5f); glTexCoord2f(t2 ? 64 : 1, t2 ? 64 : 1); glVertex2f(.5f, .5f); glTexCoord2f(0, t2 ? 64 : 1); glVertex2f(-.5f, .5f); glEnd(); glDisable(tgt[t2]); glDeleteTextures(1, &ft); } } }
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); glDeleteFramebuffersEXT(1, &fb); glDeleteTextures(1, &dt); glDeleteTextures(1, &ct); errs("fbo2"); done("fbo2");
}

static void f_copypix(void) {
    /* glCopyPixels with the conditions the stock driver's accelerated path (FUN_00018120) tests: NON-overlapping source and destination rectangles, default pixel-transfer state,
     * no fog/blend/texture state bits for colour copies; for GL_DEPTH copies depth test on, glDepthFunc(GL_ALWAYS), depth mask on, stencil off. Window-space raster positions via glWindowPos2iARB. */
    int i, k; int pos[][4] = { { 0, 0, 128, 128 }, { 0, 0, 64, 64 }, { 10, 10, 200, 100 }, { 100, 50, 32, 32 }, { 0, 0, 256, 128 } }; ortho(); glClearColor(.3f, .5f, .7f, 1); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST); tri(0, 0, .8f, -.5f); glDisable(GL_DEPTH_TEST);
    for (i = 0; i < 5; i++) for (k = 0; k < 3; k++) { int dx = 260 + k * 10, dy = 260 + k * 10; glWindowPos2iARB(dx, dy); glCopyPixels(pos[i][0], pos[i][1], pos[i][2] > 240 ? 240 : pos[i][2], pos[i][3] > 240 ? 240 : pos[i][3], GL_COLOR); }
    glEnable(GL_DEPTH_TEST); glDepthFunc(GL_ALWAYS); glDepthMask(GL_TRUE); glDisable(GL_STENCIL_TEST); glColorMask(1, 1, 1, 1);
    for (i = 0; i < 5; i++) { glWindowPos2iARB(260, 260); glCopyPixels(pos[i][0], pos[i][1], pos[i][2] > 240 ? 240 : pos[i][2], pos[i][3] > 240 ? 240 : pos[i][3], GL_DEPTH); }
    glDepthFunc(GL_LESS); glDisable(GL_DEPTH_TEST);
    glEnable(GL_SCISSOR_TEST); glScissor(250, 250, 200, 200); glWindowPos2iARB(260, 260); glCopyPixels(0, 0, 100, 100, GL_COLOR); glDisable(GL_SCISSOR_TEST);
    glWindowPos2iARB(300, 10); glCopyPixels(0, 300, 128, 128, GL_COLOR); glWindowPos2iARB(10, 300); glCopyPixels(300, 10, 100, 100, GL_COLOR); glFinish(); errs("copypix"); done("copypix");
}

static void f_copydepth(void) {
    /* every on/off combination of 8 GL states, each followed by a non-overlapping glCopyPixels(GL_DEPTH): finds which state mix the driver's accelerated depth copy (record 0x31) accepts */
    int m; GLuint t = tex2d(16, 16, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, 1); ortho(); glClearColor(.3f, .5f, .7f, 1); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST); tri(0, 0, .8f, -.5f); glDisable(GL_DEPTH_TEST);
    for (m = 0; m < 256; m++) {
        if (m & 1) glEnable(GL_DEPTH_TEST); else glDisable(GL_DEPTH_TEST);
        glDepthFunc(m & 2 ? GL_ALWAYS : GL_LESS); glDepthMask(m & 4 ? GL_TRUE : GL_FALSE); glColorMask(m & 8, m & 8, m & 8, m & 8);
        if (m & 16) glEnable(GL_STENCIL_TEST); else glDisable(GL_STENCIL_TEST); if (m & 32) glEnable(GL_BLEND); else glDisable(GL_BLEND);
        if (m & 64) { glEnable(GL_SCISSOR_TEST); glScissor(200, 200, 300, 300); } else glDisable(GL_SCISSOR_TEST); if (m & 128) glEnable(GL_TEXTURE_2D); else glDisable(GL_TEXTURE_2D);
        glWindowPos2iARB(260, 260); glCopyPixels(0, 0, 120, 120, GL_DEPTH);
    }
    glColorMask(1, 1, 1, 1); glDepthMask(GL_TRUE); glDisable(GL_STENCIL_TEST); glDisable(GL_BLEND); glDisable(GL_SCISSOR_TEST); glDisable(GL_TEXTURE_2D); glDepthFunc(GL_LESS); glDisable(GL_DEPTH_TEST); glDeleteTextures(1, &t); glFinish(); errs("copydepth"); done("copydepth");
}

static void f_cglparams(void) {
    /* CGL-level context parameters/enables: the stock driver's gldSetInteger (and the 0x3d records) are probably behind these; each call is the documented CGL API with in-range values */
    GLint v[4]; int i; CGLError e; ortho();
    { CGLContextParameter ps[] = { kCGLCPSwapInterval, kCGLCPSurfaceOrder, kCGLCPSurfaceOpacity, kCGLCPSurfaceBackingSize, kCGLCPSwapRectangle, kCGLCPClientStorage, kCGLCPDispatchTableSize, kCGLCPGPUVertexProcessing, kCGLCPGPUFragmentProcessing };
      for (i = 0; i < 9; i++) { GLint o = 0; e = CGLGetParameter(g_ctx, ps[i], &o); v[0] = o; v[1] = v[2] = v[3] = 0; if (ps[i] == kCGLCPSurfaceBackingSize) { v[0] = 640; v[1] = 480; } if (ps[i] == kCGLCPSwapRectangle) { v[0] = 0; v[1] = 0; v[2] = 256; v[3] = 256; }
        e = CGLSetParameter(g_ctx, ps[i], v); printf("  CGLSetParameter %d -> %d (get %d)\n", (int)ps[i], (int)e, o); quad(0); } }
    { CGLContextEnable es[] = { kCGLCESwapRectangle, kCGLCESwapLimit, kCGLCERasterization, kCGLCEStateValidation, kCGLCESurfaceBackingSize, kCGLCEDisplayListOptimization, kCGLCEMPEngine };
      for (i = 0; i < 7; i++) { e = CGLEnable(g_ctx, es[i]); printf("  CGLEnable %d -> %d\n", (int)es[i], (int)e); quad(0); glFlush(); e = CGLDisable(g_ctx, es[i]); quad(0); glFlush(); } }
    { int ids[] = { 300, 306, 0x1fe, 0x29b }; int j; for (j = 0; j < 4; j++) { int val; for (val = 0; val < 2; val++) { GLint pv[4]; pv[0] = val; pv[1] = pv[2] = pv[3] = 0; e = CGLSetParameter(g_ctx, (CGLContextParameter)ids[j], pv); printf("  CGLSetParameter id %d value %d -> %d\n", ids[j], val, (int)e); quad(0); glFlush();
          e = (j < 4) ? CGLEnable(g_ctx, (CGLContextEnable)ids[j]) : 0; printf("  CGLEnable id %d -> %d\n", ids[j], (int)e); quad(0); glFlush(); CGLDisable(g_ctx, (CGLContextEnable)ids[j]); } } }
    { GLint o; CGLGetParameter(g_ctx, kCGLCPCurrentRendererID, &o); CGLGetParameter(g_ctx, kCGLCPSwapInterval, &o); }
    { CGLGlobalOption go[] = { kCGLGOFormatCacheSize, kCGLGOClearFormatCache, kCGLGORetainRenderers, kCGLGOResetLibrary }; GLint o = 0; for (i = 0; i < 3; i++) { e = CGLGetOption(go[i], &o); } }
    glFinish(); errs("cglparams"); done("cglparams");
}
static void f_msaa(void) {
    int i; unsigned char px[16 * 16 * 4]; { GLint sb = -1, sm = -1, db = -1, sbit = -1; glGetIntegerv(GL_SAMPLE_BUFFERS_ARB, &sb); glGetIntegerv(GL_SAMPLES_ARB, &sm); glGetIntegerv(GL_DEPTH_BITS, &db); glGetIntegerv(GL_STENCIL_BITS, &sbit); printf("  context: sample buffers %d, samples %d, depth bits %d, stencil bits %d\n", sb, sm, db, sbit); } glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); ortho();
    glEnable(GL_MULTISAMPLE_ARB); glEnable(GL_DEPTH_TEST);
    for (i = 0; i < 8; i++) { glPushMatrix(); glRotatef(i * 20.0f, 0, 0, 1); tri(0, 0, 0.8f, -0.9f + i * 0.2f); glPopMatrix(); }
    glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE_ARB); glSampleCoverageARB(0.5f, GL_FALSE); glEnable(GL_SAMPLE_COVERAGE_ARB); tri(0.1f, 0.1f, 0.5f, 0); glDisable(GL_SAMPLE_COVERAGE_ARB); glDisable(GL_SAMPLE_ALPHA_TO_COVERAGE_ARB);
    glReadPixels(0, 0, 16, 16, GL_RGBA, GL_UNSIGNED_BYTE, px);   /* resolves the multisample buffer */
    glReadPixels(0, 0, 16, 16, GL_DEPTH_COMPONENT, GL_FLOAT, (float *)px); tri(0, 0, .3f, 0.5f); glFlush(); glDisable(GL_DEPTH_TEST); errs("msaa"); done("msaa");
}
static void f_query(void) {
    GLuint q[8], fence[4], res = 0; int i; glGenQueriesARB(8, q); ortho(); glEnable(GL_DEPTH_TEST); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (i = 0; i < 8; i++) { glBeginQueryARB(GL_SAMPLES_PASSED_ARB, q[i]); tri(0, 0, 0.2f + 0.1f * i, -0.8f + i * 0.2f); glEndQueryARB(GL_SAMPLES_PASSED_ARB); }
    for (i = 0; i < 8; i++) { glGetQueryObjectuivARB(q[i], GL_QUERY_RESULT_AVAILABLE_ARB, &res); glGetQueryObjectuivARB(q[i], GL_QUERY_RESULT_ARB, &res); printf("  query %d samples %u\n", i, res); }
    glDeleteQueriesARB(8, q); glDisable(GL_DEPTH_TEST);
    glGenFencesAPPLE(4, fence); for (i = 0; i < 4; i++) { tri(0, 0, .3f, 0); glSetFenceAPPLE(fence[i]); } for (i = 0; i < 4; i++) { glTestFenceAPPLE(fence[i]); glFinishFenceAPPLE(fence[i]); } glFinishObjectAPPLE(GL_FENCE_APPLE, fence[0]); glDeleteFencesAPPLE(4, fence);
    glFlushRenderAPPLE(); errs("query"); done("query");
}
static void f_clear(void) {
    int i; GLfloat d[] = { 0, 0.5f, 1.0f }; ortho();
    for (i = 0; i < 3; i++) { glClearColor(i * 0.5f, 0, 1 - i * 0.5f, 1); glClearDepth(d[i]); glClearStencil(i * 7); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); }
    glClearColor(0, 0, 0, 0); glClearDepth(1.0); glClearStencil(0); glClear(GL_COLOR_BUFFER_BIT); glClear(GL_DEPTH_BUFFER_BIT); glClear(GL_STENCIL_BUFFER_BIT); glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glEnable(GL_SCISSOR_TEST); for (i = 0; i < 6; i++) { glScissor(i * 40, i * 30, 100 + i * 20, 80); glClearColor(1, i * 0.2f, 0, 1); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); } glDisable(GL_SCISSOR_TEST);
    glColorMask(GL_TRUE, GL_FALSE, GL_TRUE, GL_FALSE); glClear(GL_COLOR_BUFFER_BIT); glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); glDepthMask(GL_FALSE); glClear(GL_DEPTH_BUFFER_BIT); glDepthMask(GL_TRUE); glStencilMask(0x0f); glClear(GL_STENCIL_BUFFER_BIT); glStencilMask(0xff);
    for (i = 0; i < 4; i++) { glViewport(i * 10, i * 10, W - i * 20, H - i * 20); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); } glViewport(0, 0, W, H);
    glEnable(GL_DEPTH_TEST); for (i = 0; i < 10; i++) { glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT); tri(0, 0, .5f, -0.5f + 0.1f * i); } glDisable(GL_DEPTH_TEST); errs("clear"); done("clear");
}
static void f_state(void) {
    int i; GLfloat fogc[] = { .5f, .5f, .5f, 1 }, pos[] = { 1, 1, 1, 0 }, amb[] = { .2f, .2f, .2f, 1 }, plane[] = { 1, 0, 0, 0.5f }, pa[] = { 1, 0, 0 }; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); ortho();
    { GLenum sf[] = { GL_ZERO, GL_ONE, GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR, GL_DST_COLOR, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_DST_ALPHA, GL_CONSTANT_COLOR, GL_SRC_ALPHA_SATURATE };
      GLenum eq[] = { GL_FUNC_ADD, GL_FUNC_SUBTRACT, GL_FUNC_REVERSE_SUBTRACT, GL_MIN, GL_MAX }; glEnable(GL_BLEND); glBlendColor(.2f, .4f, .6f, .8f);
      for (i = 0; i < 10; i++) { glBlendFunc(sf[i], sf[(i + 3) % 10 == 9 ? 1 : (i + 3) % 9]); glBlendEquation(eq[i % 5]); tri(0, 0, .5f, 0); }
      glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE, GL_ONE, GL_ZERO); glBlendEquationSeparateATI(GL_FUNC_ADD, GL_FUNC_SUBTRACT); tri(0, 0, .5f, 0); glBlendEquation(GL_FUNC_ADD); glDisable(GL_BLEND); }
    glEnable(GL_ALPHA_TEST); for (i = 0; i < 8; i++) { glAlphaFunc(GL_NEVER + i, 0.5f); tri(0, 0, .4f, 0); } glDisable(GL_ALPHA_TEST);
    glEnable(GL_DEPTH_TEST); for (i = 0; i < 8; i++) { glDepthFunc(GL_NEVER + i); tri(0, 0, .4f, 0.1f * i); } glDepthFunc(GL_LESS); glDepthRange(0.2, 0.8); tri(0, 0, .3f, 0); glDepthRange(0, 1);
    glEnable(GL_STENCIL_TEST); for (i = 0; i < 8; i++) { glStencilFunc(GL_NEVER + i, 1, 0xff); glStencilOp(GL_KEEP + (i % 2), GL_INCR, GL_DECR_WRAP_EXT); tri(0, 0, .4f, 0); }
    glStencilOpSeparateATI(GL_FRONT, GL_KEEP, GL_INCR, GL_REPLACE); glStencilOpSeparateATI(GL_BACK, GL_KEEP, GL_DECR, GL_INVERT); glStencilFuncSeparateATI(GL_ALWAYS, GL_ALWAYS, 1, 0xff); tri(0, 0, .4f, 0); glDisable(GL_STENCIL_TEST); glDisable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE); glCullFace(GL_FRONT); tri(0, 0, .4f, 0); glCullFace(GL_BACK); glFrontFace(GL_CW); tri(0, 0, .4f, 0); glFrontFace(GL_CCW); glDisable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); tri(0, 0, .6f, 0); glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); glPointSize(4); tri(0, 0, .6f, 0); glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_POLYGON_OFFSET_FILL); glPolygonOffset(1.0f, 2.0f); tri(0, 0, .4f, 0); glDisable(GL_POLYGON_OFFSET_FILL);
    glFogi(GL_FOG_MODE, GL_LINEAR); glFogfv(GL_FOG_COLOR, fogc); glFogf(GL_FOG_START, 0); glFogf(GL_FOG_END, 2); glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_EXP); glFogf(GL_FOG_DENSITY, 0.5f); tri(0, 0, .4f, 0); glFogi(GL_FOG_MODE, GL_EXP2); tri(0, 0, .4f, 0); glFogi(GL_FOG_COORDINATE_SOURCE_EXT, GL_FOG_COORDINATE_EXT); glFogCoordfEXT(1.0f); tri(0, 0, .4f, 0); glDisable(GL_FOG);
    glEnable(GL_LIGHTING); glEnable(GL_LIGHT0); glEnable(GL_LIGHT1); glLightfv(GL_LIGHT0, GL_POSITION, pos); glLightfv(GL_LIGHT1, GL_AMBIENT, amb); glEnable(GL_COLOR_MATERIAL); glEnable(GL_NORMALIZE); glNormal3f(0, 0, 1);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 30); glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1); glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR); tri(0, 0, .5f, 0); glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1); tri(0, 0, .5f, 0); glDisable(GL_LIGHTING);
    glClipPlane(GL_CLIP_PLANE0, (GLdouble[]){ 1, 0, 0, 0.5 }); glEnable(GL_CLIP_PLANE0); glClipPlane(GL_CLIP_PLANE1, (GLdouble[]){ 0, 1, 0, 0.5 }); glEnable(GL_CLIP_PLANE1); tri(0, 0, .8f, 0); glDisable(GL_CLIP_PLANE0); glDisable(GL_CLIP_PLANE1);
    glEnable(GL_LINE_SMOOTH); glLineWidth(3); glBegin(GL_LINES); glVertex2f(-.5f, -.5f); glVertex2f(.5f, .5f); glEnd(); glEnable(GL_LINE_STIPPLE); glLineStipple(2, 0x5555); glBegin(GL_LINE_STRIP); glVertex2f(-.5f, .5f); glVertex2f(0, 0); glVertex2f(.5f, .5f); glEnd(); glDisable(GL_LINE_STIPPLE); glDisable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_STIPPLE); { GLubyte st[128]; memset(st, 0xaa, sizeof st); glPolygonStipple(st); } tri(0, 0, .5f, 0); glDisable(GL_POLYGON_STIPPLE);
    glEnable(GL_POINT_SMOOTH); glPointParameterfvARB(GL_POINT_DISTANCE_ATTENUATION_ARB, pa); glPointParameterfARB(GL_POINT_SIZE_MIN_ARB, 1); glPointParameterfARB(GL_POINT_SIZE_MAX_ARB, 32); glPointSize(8);
    glEnable(GL_POINT_SPRITE_ARB); glTexEnvi(GL_POINT_SPRITE_ARB, GL_COORD_REPLACE_ARB, GL_TRUE); glBegin(GL_POINTS); glVertex2f(0, 0); glVertex2f(.5f, .5f); glEnd(); glDisable(GL_POINT_SPRITE_ARB); glDisable(GL_POINT_SMOOTH);
    glEnable(GL_COLOR_LOGIC_OP); for (i = 0; i < 4; i++) { glLogicOp(GL_CLEAR + i * 3); tri(0, 0, .5f, 0); } glDisable(GL_COLOR_LOGIC_OP); glShadeModel(GL_FLAT); tri(0, 0, .5f, 0); glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D); { GLuint t = tex2d(16, 16, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, 1); GLenum m[] = { GL_MODULATE, GL_DECAL, GL_BLEND, GL_REPLACE, GL_ADD }; for (i = 0; i < 5; i++) { glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, m[i]); quad(0); }
      glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB); { GLenum c[] = { GL_REPLACE, GL_MODULATE, GL_ADD, GL_ADD_SIGNED_ARB, GL_INTERPOLATE_ARB, GL_SUBTRACT_ARB, GL_DOT3_RGB_ARB, GL_DOT3_RGBA_ARB };
      for (i = 0; i < 8; i++) { glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, c[i]); glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA_ARB, c[i] == GL_DOT3_RGB_ARB || c[i] == GL_DOT3_RGBA_ARB ? GL_REPLACE : c[i]); glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, GL_TEXTURE); glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, GL_PRIMARY_COLOR_ARB); glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE2_RGB_ARB, GL_CONSTANT_ARB); quad(0); } }
      glTexEnvi(GL_TEXTURE_ENV, GL_RGB_SCALE_ARB, 2); quad(0); glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
      glMatrixMode(GL_TEXTURE); glRotatef(30, 0, 0, 1); glScalef(2, 2, 1); quad(0); glLoadIdentity(); glMatrixMode(GL_MODELVIEW);
      { GLenum g[] = { GL_OBJECT_LINEAR, GL_EYE_LINEAR, GL_SPHERE_MAP }; glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T); for (i = 0; i < 3; i++) { glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, g[i]); glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, g[i]); quad(0); } glDisable(GL_TEXTURE_GEN_S); glDisable(GL_TEXTURE_GEN_T); }
      glDeleteTextures(1, &t); } glDisable(GL_TEXTURE_2D);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); glEnable(GL_RESCALE_NORMAL); glDisable(GL_RESCALE_NORMAL); glEnable(GL_DITHER); glDisable(GL_DITHER); glEnable(GL_AUTO_NORMAL); glDisable(GL_AUTO_NORMAL);
    glEnable(GL_SCISSOR_TEST); glScissor(50, 50, 300, 300); tri(0, 0, .9f, 0); glDisable(GL_SCISSOR_TEST); glSecondaryColor3fEXT(1, 0, 0); errs("state"); done("state");
}
static void f_draw(void) {
    float v[12 * 3], c[12 * 4], tc[12 * 2]; unsigned short ix[18]; unsigned int uix[18]; int i; GLuint dl; GLint first[3] = { 0, 3, 6 }; GLsizei cnt[3] = { 3, 3, 3 }; ortho();
    for (i = 0; i < 12; i++) { v[i * 3] = -0.8f + 0.14f * i; v[i * 3 + 1] = (i & 1) ? 0.5f : -0.5f; v[i * 3 + 2] = 0; c[i * 4] = i / 12.f; c[i * 4 + 1] = 1 - i / 12.f; c[i * 4 + 2] = .5f; c[i * 4 + 3] = 1; tc[i * 2] = i / 12.f; tc[i * 2 + 1] = (i & 1); }
    for (i = 0; i < 18; i++) { ix[i] = i % 12; uix[i] = i % 12; }
    glEnableClientState(GL_VERTEX_ARRAY); glVertexPointer(3, GL_FLOAT, 0, v); glEnableClientState(GL_COLOR_ARRAY); glColorPointer(4, GL_FLOAT, 0, c); glEnableClientState(GL_TEXTURE_COORD_ARRAY); glTexCoordPointer(2, GL_FLOAT, 0, tc);
    { GLenum pr[] = { GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_QUADS, GL_QUAD_STRIP, GL_POLYGON };
      for (i = 0; i < 10; i++) { glDrawArrays(pr[i], 0, i == 7 || i == 8 ? 8 : (i == 4 ? 12 : 9)); glDrawElements(pr[i], 8, GL_UNSIGNED_SHORT, ix); glDrawElements(pr[i], 8, GL_UNSIGNED_INT, uix); glDrawElements(pr[i], 8, GL_UNSIGNED_BYTE, (unsigned char[]){ 0, 1, 2, 3, 4, 5, 6, 7 }); } }
    glDrawRangeElementsEXT(GL_TRIANGLES, 0, 11, 18, GL_UNSIGNED_SHORT, ix); glMultiDrawArraysEXT(GL_TRIANGLES, first, cnt, 3); glLockArraysEXT(0, 12); glDrawArrays(GL_TRIANGLES, 0, 12); glUnlockArraysEXT();
    glArrayElement(3); glBegin(GL_TRIANGLES); glArrayElement(0); glArrayElement(1); glArrayElement(2); glEnd();
    glDisableClientState(GL_COLOR_ARRAY); glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glInterleavedArrays(GL_C4F_N3F_V3F, 0, (float[]){ 1, 0, 0, 1, 0, 0, 1, -.5f, -.5f, 0, 0, 1, 0, 1, 0, 0, 1, .5f, -.5f, 0, 0, 0, 1, 1, 0, 0, 1, 0, .5f, 0 }); glDrawArrays(GL_TRIANGLES, 0, 3);
    glEnableClientState(GL_SECONDARY_COLOR_ARRAY_EXT); glSecondaryColorPointerEXT(3, GL_FLOAT, 0, c); glEnableClientState(GL_FOG_COORDINATE_ARRAY_EXT); glFogCoordPointerEXT(GL_FLOAT, 0, tc); glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableClientState(GL_SECONDARY_COLOR_ARRAY_EXT); glDisableClientState(GL_FOG_COORDINATE_ARRAY_EXT);
    glActiveTexture(GL_TEXTURE1); glClientActiveTexture(GL_TEXTURE1); glEnableClientState(GL_TEXTURE_COORD_ARRAY); glTexCoordPointer(2, GL_FLOAT, 0, tc); glDrawArrays(GL_TRIANGLES, 0, 6); glDisableClientState(GL_TEXTURE_COORD_ARRAY); glActiveTexture(GL_TEXTURE0); glClientActiveTexture(GL_TEXTURE0);
    glDisableClientState(GL_VERTEX_ARRAY);
    dl = glGenLists(2); glNewList(dl, GL_COMPILE); tri(0, 0, .5f, 0); glTranslatef(.1f, 0, 0); glEndList(); glNewList(dl + 1, GL_COMPILE_AND_EXECUTE); tri(0, 0, .3f, 0); glEndList(); for (i = 0; i < 6; i++) glCallList(dl); glCallLists(2, GL_UNSIGNED_INT, (GLuint[]){ dl, dl + 1 }); glDeleteLists(dl, 2);
    glRectf(-.5f, -.5f, .5f, .5f); glRecti(-1, -1, 0, 0); glBegin(GL_TRIANGLES); for (i = 0; i < 900; i++) { glColor3f(i / 900.f, .5f, .5f); glVertex2f(-.9f + (i % 30) * .06f, -.9f + (i / 30) * .06f); } glEnd();
    errs("draw"); done("draw");
}
static GLuint glsl(const char *vs, const char *fs) {
    GLuint v = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB), f = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB), p = glCreateProgramObjectARB(); GLint ok = 0; char log[512];
    glShaderSourceARB(v, 1, &vs, NULL); glCompileShaderARB(v); glGetObjectParameterivARB(v, GL_OBJECT_COMPILE_STATUS_ARB, &ok); if (!ok) { glGetInfoLogARB(v, 512, NULL, log); printf("  vs: %s\n", log); }
    glShaderSourceARB(f, 1, &fs, NULL); glCompileShaderARB(f); glGetObjectParameterivARB(f, GL_OBJECT_COMPILE_STATUS_ARB, &ok); if (!ok) { glGetInfoLogARB(f, 512, NULL, log); printf("  fs: %s\n", log); }
    glAttachObjectARB(p, v); glAttachObjectARB(p, f); glLinkProgramARB(p); glGetObjectParameterivARB(p, GL_OBJECT_LINK_STATUS_ARB, &ok); if (!ok) { glGetInfoLogARB(p, 512, NULL, log); printf("  link: %s\n", log); } return p;
}
static void f_shaders(void) {
    GLuint p, t[4], vp, fp, i; unsigned char buf[16 * 16 * 4]; memset(buf, 0x77, sizeof buf); ortho();
    for (i = 0; i < 4; i++) { glActiveTexture(GL_TEXTURE0 + i); t[i] = tex2d(16, 16, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, 1); } glActiveTexture(GL_TEXTURE0);
    p = glsl("varying vec4 col; varying vec2 uv; void main() { col = gl_Color; uv = gl_MultiTexCoord0.xy; gl_Position = ftransform(); }",
             "uniform sampler2D s0, s1, s2, s3; uniform vec4 k; varying vec4 col; varying vec2 uv; void main() { vec4 a = texture2D(s0, uv) + texture2D(s1, uv * 2.0) * 0.5 + texture2D(s2, uv) * k.x + texture2D(s3, uv) * k.y; gl_FragColor = col * a * 0.25; }");
    glUseProgramObjectARB(p); for (i = 0; i < 4; i++) { char n[8]; snprintf(n, sizeof n, "s%d", i); glUniform1iARB(glGetUniformLocationARB(p, n), i); glActiveTexture(GL_TEXTURE0 + i); glBindTexture(GL_TEXTURE_2D, t[i]); }
    glUniform4fARB(glGetUniformLocationARB(p, "k"), .5f, .25f, 0, 0); glActiveTexture(GL_TEXTURE0); quad(0); errs("glsl multi-sampler");
    { GLuint p2 = glsl("attribute vec4 pos; uniform mat4 m; varying float d; void main() { d = pos.x * 0.5 + 0.5; gl_Position = m * pos; gl_PointSize = 4.0; }",
                       "varying float d; void main() { float s = d; if (s > 0.5) discard; gl_FragColor = vec4(fract(d * 4.0), s, 1.0 - s, 1.0); gl_FragDepth = d; }");
      glUseProgramObjectARB(p2); glUniformMatrix4fvARB(glGetUniformLocationARB(p2, "m"), 1, GL_FALSE, (float[]){ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }); glBindAttribLocationARB(p2, 3, "pos");
      { float v[] = { -.8f, -.8f, 0, 1, .8f, -.8f, 0, 1, 0, .8f, 0, 1 }; glEnable(GL_DEPTH_TEST); glEnableVertexAttribArrayARB(3); glVertexAttribPointerARB(3, 4, GL_FLOAT, GL_FALSE, 0, v); glDrawArrays(GL_TRIANGLES, 0, 3); glDisableVertexAttribArrayARB(3); glDisable(GL_DEPTH_TEST); } errs("glsl attrib/discard/depth"); }
    glUseProgramObjectARB(0);
    { const char *vps = "!!ARBvp1.0\nPARAM mvp[4] = { state.matrix.mvp };\nTEMP r;\nDP4 r.x, mvp[0], vertex.position;\nDP4 r.y, mvp[1], vertex.position;\nDP4 r.z, mvp[2], vertex.position;\nDP4 r.w, mvp[3], vertex.position;\nMOV result.position, r;\nMOV result.color, vertex.color;\nMOV result.texcoord[0], vertex.texcoord[0];\nEND\n";
      const char *fps = "!!ARBfp1.0\nTEMP t;\nTEX t, fragment.texcoord[0], texture[0], 2D;\nMUL t, t, fragment.color;\nPOW t.x, t.x, t.y;\nLRP result.color, 0.5, t, fragment.color;\nMOV result.depth, t.z;\nEND\n";
      glGenProgramsARB(1, &vp); glBindProgramARB(GL_VERTEX_PROGRAM_ARB, vp); glProgramStringARB(GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, strlen(vps), vps);
      glGenProgramsARB(1, &fp); glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, fp); glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, strlen(fps), fps);
      glEnable(GL_VERTEX_PROGRAM_ARB); glEnable(GL_FRAGMENT_PROGRAM_ARB); glEnable(GL_TEXTURE_2D); glProgramLocalParameter4fARB(GL_FRAGMENT_PROGRAM_ARB, 0, 1, 2, 3, 4); glProgramEnvParameter4fARB(GL_FRAGMENT_PROGRAM_ARB, 1, 1, 2, 3, 4); quad(0); quad(0.1f); glDisable(GL_VERTEX_PROGRAM_ARB); glDisable(GL_FRAGMENT_PROGRAM_ARB); errs("arb programs"); }
    /* shadow compare on a depth texture */
    { GLuint dt; glGenTextures(1, &dt); glBindTexture(GL_TEXTURE_2D, dt); glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, 64, 64, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE_ARB); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC_ARB, GL_LEQUAL); glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE_ARB, GL_INTENSITY);
      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, 0, 0, 64, 64, 0);
      glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T); glEnable(GL_TEXTURE_GEN_R); glEnable(GL_TEXTURE_GEN_Q); glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR); glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR); glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR); glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
      quad(0); glDisable(GL_TEXTURE_GEN_S); glDisable(GL_TEXTURE_GEN_T); glDisable(GL_TEXTURE_GEN_R); glDisable(GL_TEXTURE_GEN_Q); glDeleteTextures(1, &dt); errs("shadow"); }
    glDisable(GL_TEXTURE_2D); done("shaders");
}
static void f_pixel(void) {
    int i; static unsigned char buf[128 * 128 * 4]; GLuint pbo; memset(buf, 0x30, sizeof buf); ortho(); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRasterPos2f(-.8f, -.8f); glDrawPixels(128, 128, GL_RGBA, GL_UNSIGNED_BYTE, buf); glDrawPixels(64, 64, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, buf); glDrawPixels(32, 32, GL_LUMINANCE, GL_UNSIGNED_BYTE, buf); glDrawPixels(32, 32, GL_ABGR_EXT, GL_UNSIGNED_BYTE, buf);
    glDrawPixels(32, 32, GL_RGBA, GL_FLOAT, (float[32 * 32 * 4]){ 0 }); glPixelZoom(2, 2); glDrawPixels(32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf); glPixelZoom(1, 1);
    glPixelTransferf(GL_RED_SCALE, 0.5f); glPixelTransferf(GL_GREEN_BIAS, 0.1f); glDrawPixels(32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf); glPixelTransferf(GL_RED_SCALE, 1); glPixelTransferf(GL_GREEN_BIAS, 0);
    glPixelTransferi(GL_MAP_COLOR, 1); { GLfloat m[2] = { 1, 0 }; glPixelMapfv(GL_PIXEL_MAP_R_TO_R, 2, m); } glDrawPixels(16, 16, GL_RGBA, GL_UNSIGNED_BYTE, buf); glPixelTransferi(GL_MAP_COLOR, 0);
    glMatrixMode(GL_COLOR); glScalef(.5f, .5f, .5f); glMatrixMode(GL_MODELVIEW); glDrawPixels(16, 16, GL_RGBA, GL_UNSIGNED_BYTE, buf); glMatrixMode(GL_COLOR); glLoadIdentity(); glMatrixMode(GL_MODELVIEW);
    glDrawPixels(32, 32, GL_DEPTH_COMPONENT, GL_FLOAT, (float[32 * 32]){ 0.5f }); glDrawPixels(32, 32, GL_STENCIL_INDEX, GL_UNSIGNED_BYTE, buf);
    glBitmap(8, 8, 0, 0, 10, 0, (GLubyte[]){ 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff }); errs("drawpixels");
    glReadPixels(0, 0, 128, 128, GL_RGBA, GL_UNSIGNED_BYTE, buf); glReadPixels(0, 0, 64, 64, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, buf); glReadPixels(0, 0, 64, 64, GL_RGB, GL_UNSIGNED_BYTE, buf); glReadPixels(0, 0, 32, 32, GL_DEPTH_COMPONENT, GL_FLOAT, buf); glReadPixels(0, 0, 32, 32, GL_STENCIL_INDEX, GL_UNSIGNED_BYTE, buf); glReadPixels(0, 0, 32, 32, GL_RGBA, GL_FLOAT, buf);
    glReadBuffer(GL_FRONT); glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf); glReadBuffer(GL_BACK); glCopyPixels(0, 0, 64, 64, GL_COLOR); glCopyPixels(0, 0, 32, 32, GL_DEPTH); glCopyPixels(0, 0, 32, 32, GL_STENCIL); errs("readpixels/copypixels");
    glGenBuffersARB(1, &pbo); glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB, pbo); glBufferDataARB(GL_PIXEL_PACK_BUFFER_ARB, 128 * 128 * 4, NULL, GL_STREAM_READ_ARB); glReadPixels(0, 0, 128, 128, GL_RGBA, GL_UNSIGNED_BYTE, NULL); { void *m = glMapBufferARB(GL_PIXEL_PACK_BUFFER_ARB, GL_READ_ONLY_ARB); if (m) glUnmapBufferARB(GL_PIXEL_PACK_BUFFER_ARB); }
    glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB, 0); glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo); glDrawPixels(64, 64, GL_RGBA, GL_UNSIGNED_BYTE, NULL); glEnable(GL_TEXTURE_2D); { GLuint t; glGenTextures(1, &t); glBindTexture(GL_TEXTURE_2D, t); glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL); glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, NULL); quad(0); glDeleteTextures(1, &t); } glDisable(GL_TEXTURE_2D);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0); glDeleteBuffersARB(1, &pbo); errs("pbo");
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); glPixelStorei(GL_UNPACK_ROW_LENGTH, 128); glPixelStorei(GL_UNPACK_SKIP_PIXELS, 3); glDrawPixels(30, 30, GL_RGBA, GL_UNSIGNED_BYTE, buf); glPixelStorei(GL_UNPACK_ROW_LENGTH, 0); glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0); glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glPixelStorei(GL_UNPACK_CLIENT_STORAGE_APPLE, 1); glEnable(GL_TEXTURE_2D); { GLuint t; glGenTextures(1, &t); glBindTexture(GL_TEXTURE_2D, t); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_STORAGE_HINT_APPLE, GL_STORAGE_SHARED_APPLE); glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); quad(0); glDeleteTextures(1, &t); }
    glPixelStorei(GL_UNPACK_CLIENT_STORAGE_APPLE, 0); glDisable(GL_TEXTURE_2D); errs("pixel store"); done("pixel");
}

static void f_bigdraw(void) {
    int sizes[] = { 600, 3000, 20000, 100000 }, si, i, k; float *v, *c; unsigned short *ix; unsigned int *uix; GLuint b[4], dl; ortho();
    for (si = 0; si < 4; si++) {
        int n = sizes[si]; v = malloc(n * 3 * sizeof(float)); c = malloc(n * 4 * sizeof(float)); ix = malloc(n * sizeof(unsigned short)); uix = malloc(n * sizeof(unsigned int));
        for (i = 0; i < n; i++) { v[i * 3] = -0.9f + 1.8f * ((i * 7) % 1000) / 1000.f; v[i * 3 + 1] = -0.9f + 1.8f * ((i * 13) % 1000) / 1000.f; v[i * 3 + 2] = 0; c[i * 4] = (i % 100) / 100.f; c[i * 4 + 1] = .5f; c[i * 4 + 2] = 1 - (i % 100) / 100.f; c[i * 4 + 3] = 1; ix[i] = (unsigned short)(n > 65535 ? i % 65535 : i); uix[i] = i; }
        glEnableClientState(GL_VERTEX_ARRAY); glVertexPointer(3, GL_FLOAT, 0, v); glEnableClientState(GL_COLOR_ARRAY); glColorPointer(4, GL_FLOAT, 0, c);
        glDrawArrays(GL_TRIANGLES, 0, n - n % 3); glDrawArrays(GL_TRIANGLE_STRIP, 0, n); glDrawArrays(GL_POINTS, 0, n); glDrawArrays(GL_LINES, 0, n & ~1); glDrawArrays(GL_QUADS, 0, n & ~3);
        glDrawElements(GL_TRIANGLES, n - n % 3, GL_UNSIGNED_SHORT, ix); glDrawElements(GL_TRIANGLES, n - n % 3, GL_UNSIGNED_INT, uix); glDrawElements(GL_TRIANGLE_STRIP, n, GL_UNSIGNED_INT, uix);
        glDrawRangeElementsEXT(GL_TRIANGLES, 0, n - 1, n - n % 3, GL_UNSIGNED_INT, uix); glLockArraysEXT(0, n); glDrawArrays(GL_TRIANGLES, 0, n - n % 3); glDrawArrays(GL_TRIANGLES, 0, n - n % 3); glUnlockArraysEXT();
        { GLint first[2] = { 0, n / 2 - (n / 2) % 3 }; GLsizei cnt[2] = { n / 2 - (n / 2) % 3, n / 2 - (n / 2) % 3 }; glMultiDrawArraysEXT(GL_TRIANGLES, first, cnt, 2); }
        glDisableClientState(GL_COLOR_ARRAY); errs("big client arrays");
        /* buffer objects of every usage, array + element, plus buffer updates between draws */
        glGenBuffersARB(3, b); { GLenum us[] = { GL_STATIC_DRAW_ARB, GL_DYNAMIC_DRAW_ARB, GL_STREAM_DRAW_ARB };
          for (k = 0; k < 3; k++) { glBindBufferARB(GL_ARRAY_BUFFER_ARB, b[0]); glBufferDataARB(GL_ARRAY_BUFFER_ARB, n * 3 * sizeof(float), v, us[k]); glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, b[1]); glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, n * sizeof(unsigned int), uix, us[k]);
            glVertexPointer(3, GL_FLOAT, 0, 0); glDrawArrays(GL_TRIANGLES, 0, n - n % 3); glDrawElements(GL_TRIANGLES, n - n % 3, GL_UNSIGNED_INT, 0); glDrawArrays(GL_POINTS, 0, n);
            glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, n * 3 * sizeof(float) / 2, v); glDrawArrays(GL_TRIANGLES, 0, n - n % 3); { void *m = glMapBufferARB(GL_ARRAY_BUFFER_ARB, GL_READ_WRITE_ARB); if (m) glUnmapBufferARB(GL_ARRAY_BUFFER_ARB); } glDrawArrays(GL_TRIANGLE_STRIP, 0, n); }
          glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0); glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0); }
        glDeleteBuffersARB(3, b); errs("big VBOs");
        /* APPLE_vertex_array_range / element_array: draws straight from "AGP" client memory */
        glVertexPointer(3, GL_FLOAT, 0, v); glVertexArrayRangeAPPLE(n * 3 * sizeof(float), v); glVertexArrayParameteriAPPLE(GL_VERTEX_ARRAY_STORAGE_HINT_APPLE, GL_STORAGE_SHARED_APPLE); glEnableClientState(GL_VERTEX_ARRAY_RANGE_APPLE);
        glDrawArrays(GL_TRIANGLES, 0, n - n % 3); glFlushVertexArrayRangeAPPLE(n * 3 * sizeof(float), v); glElementPointerAPPLE(GL_UNSIGNED_INT, uix); glEnableClientState(GL_ELEMENT_ARRAY_APPLE); glDrawElementArrayAPPLE(GL_TRIANGLES, 0, n - n % 3); glDisableClientState(GL_ELEMENT_ARRAY_APPLE);
        glDisableClientState(GL_VERTEX_ARRAY_RANGE_APPLE); glDisableClientState(GL_VERTEX_ARRAY); errs("vertex array range");
        free(v); free(c); free(ix); free(uix); glFinish();
    }
    /* a big compiled display list, called repeatedly */
    dl = glGenLists(1); glNewList(dl, GL_COMPILE); glBegin(GL_TRIANGLES); for (i = 0; i < 30000; i++) { glColor3f((i % 50) / 50.f, .5f, .5f); glVertex2f(-.9f + (i % 300) * .006f, -.9f + (i / 300) * .018f); } glEnd(); glEndList(); for (i = 0; i < 8; i++) glCallList(dl); glDeleteLists(dl, 1);
    errs("bigdraw"); done("bigdraw");
}
static void f_stress(void) {
    int it = getenv("GLSTRESS_ITERS") ? atoi(getenv("GLSTRESS_ITERS")) : 120; unsigned seed = getenv("GLSTRESS_SEED") ? (unsigned)atoi(getenv("GLSTRESS_SEED")) : 1;
    printf("  stress: %d iterations, seed %u\n", it, seed); gs_run(it, seed, W, H); errs("stress"); done("stress");
}
static void f_vbo(void) {
    GLuint b[3], vao; float v[] = { -.8f, -.8f, 0, .8f, -.8f, 0, 0, .8f, 0, -.5f, .5f, 0 }; unsigned short ix[] = { 0, 1, 2, 0, 2, 3 }; ortho();
    glGenBuffersARB(2, b); glBindBufferARB(GL_ARRAY_BUFFER_ARB, b[0]); glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof v, v, GL_STATIC_DRAW_ARB); glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, b[1]); glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof ix, ix, GL_STATIC_DRAW_ARB);
    glEnableClientState(GL_VERTEX_ARRAY); glVertexPointer(3, GL_FLOAT, 0, 0); glDrawArrays(GL_TRIANGLES, 0, 3); glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0); glDrawRangeElementsEXT(GL_TRIANGLES, 0, 3, 6, GL_UNSIGNED_SHORT, 0);
    glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, sizeof v, v); { void *m = glMapBufferARB(GL_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB); if (m) { memcpy(m, v, sizeof v); glUnmapBufferARB(GL_ARRAY_BUFFER_ARB); } } glDrawArrays(GL_TRIANGLES, 0, 3);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof v, v, GL_DYNAMIC_DRAW_ARB); glDrawArrays(GL_TRIANGLES, 0, 3); glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof v, v, GL_STREAM_DRAW_ARB); glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0); glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0); glDisableClientState(GL_VERTEX_ARRAY);
    glGenVertexArraysAPPLE(1, &vao); glBindVertexArrayAPPLE(vao); glEnableClientState(GL_VERTEX_ARRAY); glVertexPointer(3, GL_FLOAT, 0, v); glDrawArrays(GL_TRIANGLES, 0, 3); glBindVertexArrayAPPLE(0); glDeleteVertexArraysAPPLE(1, &vao); glDisableClientState(GL_VERTEX_ARRAY);
    glDeleteBuffersARB(2, b); errs("vbo"); done("vbo");
}

static void on_sig(int sg) { char m[48]; int n = snprintf(m, sizeof m, "glcov: caught signal %d\n", sg); write(1, m, n); _exit(100 + sg); }
static void on_exit_marker(void) { printf("glcov: exit() called\n"); }
int main(int argc, char **argv) {
    int i, msaa = 0; setvbuf(stdout, NULL, _IONBF, 0);
    signal(SIGSEGV, on_sig); signal(SIGBUS, on_sig); signal(SIGILL, on_sig); signal(SIGABRT, on_sig); signal(SIGFPE, on_sig); signal(SIGTERM, on_sig); signal(SIGHUP, on_sig); signal(SIGPIPE, on_sig); atexit(on_exit_marker);
    if (argc < 2) { printf("usage: glcov FEATURE...\n"); return 2; }
    for (i = 1; i < argc; i++) if (!strncmp(argv[i], "msaa", 4)) msaa = argv[i][4] ? atoi(argv[i] + 4) : 4;
    if (!make_ctx(msaa)) return 1;
    for (i = 1; i < argc; i++) {
        const char *f = argv[i];
        if (!strcmp(f, "multitex")) f_multitex(); else if (!strcmp(f, "fbo2")) f_fbo2(); else if (!strcmp(f, "copypix")) f_copypix(); else if (!strcmp(f, "copydepth")) f_copydepth(); else if (!strcmp(f, "cglparams")) f_cglparams(); else if (!strcmp(f, "texfmt")) f_texfmt(); else if (!strcmp(f, "fbo")) f_fbo();
        else if (!strncmp(f, "msaa", 4)) f_msaa(); else if (!strcmp(f, "query")) f_query(); else if (!strcmp(f, "clear")) f_clear();
        else if (!strcmp(f, "state")) f_state(); else if (!strcmp(f, "draw")) f_draw(); else if (!strcmp(f, "shaders")) f_shaders();
        else if (!strcmp(f, "pixel")) f_pixel(); else if (!strcmp(f, "vbo")) f_vbo(); else if (!strcmp(f, "bigdraw")) f_bigdraw(); else if (!strcmp(f, "stress")) f_stress(); else printf("unknown feature %s\n", f);
    }
    CGLSetCurrentContext(NULL); CGLDestroyContext(g_ctx); CGLDestroyPBuffer(g_pb); printf("glcov done errors=%d\n", g_err); return 0;
}
