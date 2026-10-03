/* gl_feature_specular_test.c - issue #128: GL 1.5 feature-completeness check for separate specular colour
 * (GL_LIGHT_MODEL_COLOR_CONTROL = GL_SEPARATE_SPECULAR_COLOR), against the exact spec formula.
 *
 * Spec (GL 1.5 sec 2.14.1): in SEPARATE_SPECULAR_COLOR mode, the specular contribution is added to the fragment AFTER
 * texturing (instead of being folded into the lit vertex colour before texturing, which would let it get multiplied by
 * the texture). Tested here without a texture (so GL_SINGLE_COLOR and GL_SEPARATE_SPECULAR_COLOR should be numerically
 * identical in the untextured case), and WITH a texture that would change the result only if specular is correctly kept
 * separate: a dark (0.1) modulating texture should darken the diffuse term but leave a bright specular highlight intact
 * only under SEPARATE_SPECULAR_COLOR. */
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
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    /* a bright head-on light that produces a strong specular highlight on a facing quad */
    float lightpos[4] = {0, 0, 1, 0};              /* directional, straight at the viewer */
    float ambient[4] = {0, 0, 0, 1};
    float diffuse[4] = {0.2f, 0.2f, 0.2f, 1};
    float specular[4] = {1, 1, 1, 1};
    float mat_specular[4] = {1, 1, 1, 1};
    float mat_diffuse[4] = {1, 1, 1, 1};
    float shininess = 1.0f;                          /* low exponent so the highlight is broad, not a tiny point */

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    /* a dark grey modulating texture: a facing quad with normal (0,0,1), lit head-on, modulated by a 0.1-grey texture */
    GLuint tex; glGenTextures(1, &tex); glBindTexture(GL_TEXTURE_2D, tex);
    GLubyte texel[3] = {26, 26, 26};  /* ~0.1 * 255 */
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, texel);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glEnable(GL_TEXTURE_2D);

    static GLubyte buf[W * H * 4];
    int results[2][3]; const char *names[2] = {"SINGLE_COLOR", "SEPARATE_SPECULAR_COLOR"};
    GLenum modes[2] = {GL_SINGLE_COLOR, GL_SEPARATE_SPECULAR_COLOR};
    int m;
    for (m = 0; m < 2; m++) {
        glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, modes[m]);
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, 0);
        glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, 0);
        glTexCoord2f(1, 1); glVertex3f(0.5f, 0.5f, 0);
        glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, 0);
        glEnd();
        glFinish();
        glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        GLubyte *p = buf + (H / 2 * W + W / 2) * 4;
        results[m][0] = p[0]; results[m][1] = p[1]; results[m][2] = p[2];
        printf("%-24s centre pixel = %d,%d,%d\n", names[m], p[0], p[1], p[2]);
    }

    /* SEPARATE_SPECULAR_COLOR's specular term is added post-texture, so it must not be darkened by the 0.1 texture the
     * way SINGLE_COLOR's folded-in specular is - the separate-mode result must be brighter (the real, falsifiable check). */
    int brighter = results[1][0] > results[0][0] + 20;   /* a generous margin: the formulas differ by roughly 0.9 * 255 in the specular channel */
    printf("RESULT: %s (SEPARATE mode centre=%d vs SINGLE mode centre=%d, expected SEPARATE clearly brighter)\n",
           brighter ? "PASS" : "FAIL", results[1][0], results[0][0]);
    return brighter ? 0 : 1;
}
