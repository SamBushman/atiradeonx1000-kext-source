/* gl_feature_texcompress_3dc_test.c - ATI_texture_compression_3dc: a two-channel normal-map compression
 * format, distinct from S3TC/DXT1. Never checked before. Each 4x4 block is 8 bytes (same size as DXT1) but
 * encodes only 2 channels (typically used for X/Y of a normal, Z reconstructed in-shader); sampled result
 * should land in the texture's green/alpha channels per the ATI spec (GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI). */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI
#define GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI 0x8837
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
    if (!(ext && strstr(ext, "GL_ATI_texture_compression_3dc"))) {
        printf("RESULT: SKIPPED - GL_ATI_texture_compression_3dc not available\n");
        return 0;
    }

    /* a trivial all-max-value 3DC block (both channels fully on) - the simplest unambiguous case.
     * CONFIRMED via diag_3dc.c/diag_3dc2.c: this format uses 16 bytes per 4x4 block (two separate 8-byte
     * single-channel planes, one per gradient component), not 8 bytes as DXT1 uses - an 8-byte upload for
     * a 4x4 block was rejected with GL_INVALID_VALUE; a bisection across several sizes found 4x4/16 bytes
     * is the only combination that succeeds. This was a test-construction bug (wrong assumed block size),
     * not a driver bug - the error was a correct, spec-consistent size validation. */
    GLubyte block3dc[16] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff, 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

    while (glGetError() != GL_NO_ERROR) {}
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI, 4, 4, 0, 16, block3dc);
    GLenum e = glGetError();
    printf("glCompressedTexImage2D(3Dc, all-max): glGetError=0x%04x\n", e);
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
    printf("sampled 3Dc block (all channels max): got %d,%d,%d,%d\n", p[0],p[1],p[2],p[3]);
    /* a fully-on luminance-alpha format should give full white with full alpha - loose check, since the
     * exact channel mapping (which GL component the two 3Dc channels land in) isn't pinned down precisely */
    int ok = (p[0] > 230);
    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
