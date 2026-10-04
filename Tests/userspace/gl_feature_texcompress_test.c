/* gl_feature_texcompress_test.c - EXT_texture_compression_s3tc / EXT_texture_compression_dxt1: upload a
 * hand-built DXT1 block (a single 4x4 block, 8 bytes) and confirm it actually decodes and samples as the
 * two endpoint colors it encodes - not just that glCompressedTexImage2D returns no error. Never checked
 * before (only the extension's presence was noted, never exercised). */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_COMPRESSED_RGB_S3TC_DXT1_EXT
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

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

    const char *ext = (const char*)glGetString(GL_EXTENSIONS);
    if (!(ext && strstr(ext, "GL_EXT_texture_compression_s3tc"))) {
        printf("RESULT: SKIPPED - GL_EXT_texture_compression_s3tc not available\n");
        return 0;
    }

    /* a DXT1 block with color0 = pure red (RGB565 0xF800), color1 = pure blue (0x001F), and all 16 pixel
     * indices = 0 (every pixel picks color0 = red exactly, the simplest unambiguous case) */
    GLubyte dxt1[8];
    GLushort c0 = 0xF800, c1 = 0x001F;
    dxt1[0] = c0 & 0xff; dxt1[1] = (c0>>8)&0xff;
    dxt1[2] = c1 & 0xff; dxt1[3] = (c1>>8)&0xff;
    dxt1[4] = dxt1[5] = dxt1[6] = dxt1[7] = 0x00;   /* all indices 0 -> color0 for every texel */

    while (glGetError() != GL_NO_ERROR) {}
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGB_S3TC_DXT1_EXT, 4, 4, 0, 8, dxt1);
    GLenum e = glGetError();
    printf("glCompressedTexImage2D(DXT1, all-index-0-red): glGetError=0x%04x\n", e);
    int bad = 0;
    if (e != GL_NO_ERROR) { printf("RESULT: FAIL (upload itself errored)\n"); return 1; }

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor3f(1,1,1);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(-1,-1); glTexCoord2f(1,0); glVertex2f(1,-1);
    glTexCoord2f(1,1); glVertex2f(1,1); glTexCoord2f(0,1); glVertex2f(-1,1);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    int ok = (p[0] > 230 && p[1] < 20 && p[2] < 20);
    printf("sampled DXT1 block (expect decoded pure red ~255,0,0): got %d,%d,%d %s\n", p[0],p[1],p[2], ok?"OK":"MISMATCH");
    if (!ok) bad++;

    printf("RESULT: %s\n", bad==0?"PASS":"FAIL");
    return bad?1:0;
}
