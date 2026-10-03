/* diag_fbo.c - isolating the FBO-render-then-sample anomaly from gl_feature_texture_fbo_quirks_test.c (issue #128).
 * The earlier test used a CONSTANT texcoord (16,16) at all 4 quad vertices when sampling - fixed here to vary properly
 * per vertex across the texture's real extent, and run standalone (not sharing a binary/texture-unit state with the
 * NPOT test it was combined with before). Each stage's framebuffer is read back and reported, so if something is
 * still wrong, exactly where it diverges is visible rather than just a final mismatch. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

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
    err = CGLCreatePBuffer(64, 64, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }

    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    GLuint tex; glGenTextures(1, &tex); glBindTexture(GL_TEXTURE_RECTANGLE_ARB, tex);
    glTexImage2D(GL_TEXTURE_RECTANGLE_ARB, 0, GL_RGBA8, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    GLuint fbo; glGenFramebuffersEXT(1, &fbo);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo);
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_RECTANGLE_ARB, tex, 0);
    GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
    printf("FBO status = 0x%04x (want GL_FRAMEBUFFER_COMPLETE_EXT=0x%04x)\n", status, GL_FRAMEBUFFER_COMPLETE_EXT);
    if (status != GL_FRAMEBUFFER_COMPLETE_EXT) return 1;

    glViewport(0, 0, 32, 32);
    glClearColor(0, 1, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();
    printf("rendered green into the FBO's 32x32 texture via glClear\n");

    /* read the FBO directly (quirk 6 says this specific path is unreliable - informational only, not asserted) */
    {
        static GLubyte dbuf[32*32*4];
        glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, dbuf);
        GLubyte *p = dbuf + (16*32+16)*4;
        printf("direct FBO readback after glClear (informational, quirk 6): %d,%d,%d\n", p[0], p[1], p[2]);
    }

    /* isolate: is it glClear-on-an-FBO specifically that's broken, or FBO rendering in general? try a real draw instead */
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1,1,-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_TEXTURE_RECTANGLE_ARB); glDisable(GL_TEXTURE_2D);
    glColor3f(1, 0, 1);   /* magenta, so it's unambiguous against both green-from-clear and black-from-nothing */
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    glFinish();
    printf("rendered magenta into the FBO's 32x32 texture via a real glBegin/glEnd draw\n");
    {
        static GLubyte dbuf[32*32*4];
        glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, dbuf);
        GLubyte *p = dbuf + (16*32+16)*4;
        printf("direct FBO readback after real draw (informational, quirk 6): %d,%d,%d\n", p[0], p[1], p[2]);
    }

    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
    glViewport(0, 0, 64, 64);

    glEnable(GL_TEXTURE_RECTANGLE_ARB);
    glBindTexture(GL_TEXTURE_RECTANGLE_ARB, tex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor3f(1, 1, 1);
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);   glVertex2f(-1, -1);
    glTexCoord2f(32, 0);  glVertex2f(1, -1);
    glTexCoord2f(32, 32); glVertex2f(1, 1);
    glTexCoord2f(0, 32);  glVertex2f(-1, 1);
    glEnd();
    glFinish();
    static GLubyte buf[64*64*4];
    glReadPixels(0, 0, 64, 64, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    GLubyte *p = buf + (32*64+32)*4;
    int ok = (p[0]==255 && p[1]==0 && p[2]==255);   /* magenta, the LAST thing drawn into the FBO's texture */
    printf("sample-via-real-draw (per-vertex texcoords): got %d,%d,%d want 255,0,255 %s\n", p[0], p[1], p[2], ok ? "OK" : "MISMATCH");

    /* also sample at several other points to see if it's uniform or varies */
    int x, y;
    for (y = 8; y < 64; y += 16) for (x = 8; x < 64; x += 16) {
        GLubyte *pp = buf + (y*64+x)*4;
        printf("  (%d,%d): %d,%d,%d\n", x, y, pp[0], pp[1], pp[2]);
    }
    return ok ? 0 : 1;
}
