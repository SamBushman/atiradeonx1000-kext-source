/* gl_feature_texture_fbo_quirks_test.c - issue #128: regression checks for two already-documented driver facts on this
 * exact driver (~/.claude/skills/ati-x1900-driver-quirks, quirks 3 and 4's "important refinement"):
 *   quirk 3: glTexImage2D(GL_TEXTURE_2D, ...) rejects any non-power-of-two size outright with GL_INVALID_VALUE.
 *   quirk 4 (refinement): render-to-texture via an FBO DOES work correctly when later SAMPLED by a real draw (checked
 *            via glReadPixels against the DEFAULT framebuffer after that sampling draw), for GL_TEXTURE_RECTANGLE_ARB +
 *            GL_RGBA8 - this is the specific combination the skill documents as confirmed working, not a general FBO
 *            claim. (Direct glReadPixels against the FBO itself is documented as separately unreliable - quirk 6 - and
 *            is deliberately NOT asserted here as a hard failure condition, since "unreliable" is not a fixed
 *            prediction; this test only checks the one well-defined, confirmed-working path.) */
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

    int bad = 0;

    /* quirk 3: NPOT glTexImage2D rejected */
    {
        while (glGetError() != GL_NO_ERROR) {}   /* clear any pending error */
        GLuint tex; glGenTextures(1, &tex); glBindTexture(GL_TEXTURE_2D, tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 100, 60, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        GLenum e = glGetError();
        printf("quirk3 NPOT glTexImage2D: error=0x%04x (want GL_INVALID_VALUE=0x%04x) %s\n", e, GL_INVALID_VALUE,
               e == GL_INVALID_VALUE ? "OK (still rejected, as documented)" : "MISMATCH (no longer rejected!)");
        if (e != GL_INVALID_VALUE) bad++;
        glDeleteTextures(1, &tex);
    }

    /* quirk 4 refinement: FBO render-to-RECTANGLE-RGBA8-texture, then SAMPLE it via a real draw, read back the DEFAULT framebuffer */
    {
        glViewport(0, 0, 64, 64);
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
        if (status != GL_FRAMEBUFFER_COMPLETE_EXT) {
            printf("quirk4refinement: FBO incomplete (status=0x%04x), cannot test\n", status);
            bad++;
        } else {
            glViewport(0, 0, 32, 32);
            glClearColor(0, 1, 0, 1);   /* render pure green into the FBO's texture */
            glClear(GL_COLOR_BUFFER_BIT);
            glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
            glViewport(0, 0, 64, 64);

            /* second draw: sample the FBO's texture via texture2DRect through a fixed-function rectangle-texture unit */
            glEnable(GL_TEXTURE_RECTANGLE_ARB);
            glBindTexture(GL_TEXTURE_RECTANGLE_ARB, tex);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
            glColor3f(1, 1, 1);
            glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_QUADS);
            glTexCoord2f(16, 16); glVertex2f(-1, -1);
            glTexCoord2f(16, 16); glVertex2f(1, -1);
            glTexCoord2f(16, 16); glVertex2f(1, 1);
            glTexCoord2f(16, 16); glVertex2f(-1, 1);
            glEnd();
            glFinish();
            static GLubyte buf[64 * 64 * 4];
            glReadPixels(0, 0, 64, 64, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            GLubyte *p = buf + (32 * 64 + 32) * 4;
            int ok = (p[0] == 0 && p[1] == 255 && p[2] == 0);
            printf("quirk4refinement FBO render-then-sample: got %d,%d,%d want 0,255,0 %s\n", p[0], p[1], p[2], ok ? "OK" : "MISMATCH");
            if (!ok) bad++;
        }
        glDeleteFramebuffersEXT(1, &fbo);
        glDeleteTextures(1, &tex);
    }

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
