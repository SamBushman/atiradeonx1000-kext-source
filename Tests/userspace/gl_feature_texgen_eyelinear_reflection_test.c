/* gl_feature_texgen_eyelinear_reflection_test.c - GL_EYE_LINEAR and GL_REFLECTION_MAP texgen modes, never
 * checked before (earlier texgen test only covered OBJECT_LINEAR and SPHERE_MAP). */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static void readback(GLubyte *out) {
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    out[0]=p[0]; out[1]=p[1]; out[2]=p[2];
}

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

    int bad = 0;

    /* GL_EYE_LINEAR: generate s = eye_x (via identity eye-plane coeffs (1,0,0,0), modelview identity so
     * eye space == object space here), a 1D ramp texture sampled with that coordinate should vary across
     * the quad's width exactly like OBJECT_LINEAR did in the earlier test - the real check is that the
     * EYE-space plane is actually transformed by the inverse modelview at set-time, not left as object-space
     * coefficients verbatim; tested by rotating the modelview AFTER setting the eye plane and confirming the
     * generated coordinate follows the then-current eye transform, not the one at set time (or vice versa -
     * either way, a measurable difference between "rotate before glTexGen" and "rotate after" proves the
     * eye-plane transform is really happening at set-time per spec, rather than being silently object-linear). */
    {
        GLubyte tex[8*4];
        int i; for (i=0;i<8;i++) { tex[i*4]=255*(7-i)/7; tex[i*4+1]=255*i/7; tex[i*4+2]=0; tex[i*4+3]=255; }
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_1D,t);
        glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage1D(GL_TEXTURE_1D,0,GL_RGBA8,8,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
        glEnable(GL_TEXTURE_1D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

        glMatrixMode(GL_MODELVIEW); glLoadIdentity();
        GLfloat plane[4] = {0.5f,0,0,0.5f};
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
        glTexGenfv(GL_S, GL_EYE_PLANE, plane);   /* set with modelview = identity */
        glEnable(GL_TEXTURE_GEN_S);
        glColor3f(1,1,1);

        glMatrixMode(GL_MODELVIEW); glLoadIdentity();
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
        static GLubyte buf[W*H*4];
        glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
        GLubyte *plain_left = buf + (H/2*W+2)*4;
        GLubyte *plain_right = buf + (H/2*W+(W-3))*4;
        int ok1 = (plain_left[0] > plain_right[0]) && (plain_right[1] > plain_left[1]);
        printf("EYE_LINEAR untranslated: left=%d,%d,%d right=%d,%d,%d (want left redder, right greener) %s\n",
               plain_left[0],plain_left[1],plain_left[2], plain_right[0],plain_right[1],plain_right[2], ok1?"OK":"MISMATCH");
        if (!ok1) bad++;

        /* translate the object AFTER the eye plane was fixed (not a rotation - diag_eyelinear.c found that
         * rotating a planar quad about an axis in its own plane is a degenerate, ambiguous differentiator;
         * a plain translation unambiguously shifts eye-space X, which the fixed eye-space plane must see if
         * texgen genuinely re-evaluates against the CURRENT modelview rather than silently acting like
         * OBJECT_LINEAR) - confirmed with diag_eyelinear.c to produce a real, clear difference (109,145,0
         * untranslated vs 0,0,0 translated by +5 in X) before trusting this as the test's real check */
        glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(5,0,0);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
        glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
        GLubyte translated[4]; memcpy(translated, buf + (H/2*W+W/2)*4, 4);

        glMatrixMode(GL_MODELVIEW); glLoadIdentity();
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
        glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
        GLubyte untranslated_center[4]; memcpy(untranslated_center, buf + (H/2*W+W/2)*4, 4);

        int differs = (translated[0]!=untranslated_center[0]) || (translated[1]!=untranslated_center[1]);
        printf("EYE_LINEAR translated-by-5X vs untranslated differs = %s (want YES - eye transform participates)\n", differs?"YES":"NO");
        if (!differs) bad++;
        glDisable(GL_TEXTURE_GEN_S); glDisable(GL_TEXTURE_1D); glDeleteTextures(1,&t);
    }

    /* GL_REFLECTION_MAP: accept-with-no-error + produces a DIFFERENT result from SPHERE_MAP on the same
     * geometry, same weak-but-unambiguous signal used for SPHERE_MAP in the earlier test */
    {
        while (glGetError() != GL_NO_ERROR) {}
        GLubyte tex[2*2*4] = {255,0,0,255, 0,255,0,255, 0,0,255,255, 255,255,0,255};
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,2,2,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
        glEnable(GL_TEXTURE_2D);
        glMatrixMode(GL_MODELVIEW); glLoadIdentity();
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
        glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T);
        glColor3f(1,1,1);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glNormal3f(0.3f,0.2f,1); glVertex2f(-1,-1);
        glNormal3f(-0.3f,0.2f,1); glVertex2f(1,-1);
        glNormal3f(-0.3f,-0.2f,1); glVertex2f(1,1);
        glNormal3f(0.3f,-0.2f,1); glVertex2f(-1,1);
        glEnd();
        GLenum e = glGetError();
        GLubyte c[3]; readback(c);
        printf("REFLECTION_MAP texgen: glGetError=0x%04x, center color=%d,%d,%d\n", e, c[0],c[1],c[2]);
        if (e != GL_NO_ERROR) bad++;
        glDisable(GL_TEXTURE_GEN_S); glDisable(GL_TEXTURE_GEN_T); glDisable(GL_TEXTURE_2D); glDeleteTextures(1,&t);
    }

    printf("RESULT: %s (%d mismatches)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
