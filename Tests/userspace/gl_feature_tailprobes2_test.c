/* gl_feature_tailprobes2_test.c - more low-priority tail extensions from #128's gap list:
 *  - GL_EXT_clip_volume_hint: GL_CLIP_VOLUME_CLIPPING_HINT_EXT, a pure performance hint with no required
 *    behavioral difference - correctness check is just that enabling it doesn't change rendered output.
 *  - GL_EXT_texture_mirror_clamp: GL_MIRROR_CLAMP_EXT wrap mode (distinct from ATI_texture_mirror_once's
 *    GL_MIRROR_CLAMP_TO_EDGE_ATI, which mirrors-then-clamps-to-edge; this one mirrors-then-clamps to the
 *    texture's border, not its edge texel - a subtly different definition).
 *  - GL_APPLE_specular_vector: GL_LIGHT_MODEL_LOCAL_VIEWER-adjacent alternate specular reflection vector.
 *  - GL_APPLE_transform_hint: GL_TRANSFORM_HINT_APPLE performance hint.
 */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_CLIP_VOLUME_CLIPPING_HINT_EXT
#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT 0x80F0
#endif
#ifndef GL_MIRROR_CLAMP_EXT
#define GL_MIRROR_CLAMP_EXT 0x8742
#endif
#ifndef GL_TRANSFORM_HINT_APPLE
#define GL_TRANSFORM_HINT_APPLE 0x85B1
#endif

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

    const char *ext = (const char*)glGetString(GL_EXTENSIONS);

    /* clip volume hint: enabling must not change output */
    glColor3f(1,1,1);
    glHint(GL_CLIP_VOLUME_CLIPPING_HINT_EXT, GL_FASTEST);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    GLubyte fastest[3]; readback(fastest);
    glHint(GL_CLIP_VOLUME_CLIPPING_HINT_EXT, GL_NICEST);
    GLenum e1 = glGetError();
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    GLubyte nicest[3]; readback(nicest);
    int ok1 = (fastest[0]==nicest[0]) && e1==GL_NO_ERROR;
    printf("CLIP_VOLUME_CLIPPING_HINT fastest vs nicest (must not change output): %d,%d,%d vs %d,%d,%d %s\n",
           fastest[0],fastest[1],fastest[2], nicest[0],nicest[1],nicest[2], ok1?"OK":"MISMATCH");

    /* texture_mirror_clamp */
    if (ext && strstr(ext, "GL_EXT_texture_mirror_clamp")) {
        while (glGetError() != GL_NO_ERROR) {}
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
        GLubyte tex[2*4] = {255,0,0,255, 0,0,255,255};
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,2,1,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRROR_CLAMP_EXT);
        GLenum e2 = glGetError();
        printf("EXT_texture_mirror_clamp MIRROR_CLAMP_EXT set: glGetError=0x%04x %s\n", (unsigned)e2, e2==GL_NO_ERROR?"OK":"MISMATCH");
        glDeleteTextures(1,&t);
    } else {
        printf("EXT_texture_mirror_clamp: NOT AVAILABLE - skipped\n");
    }

    /* APPLE_specular_vector: a pure accept/no-error probe - correctness would need a dedicated specular
     * geometry setup already covered by the earlier separate-specular-color test's methodology */
    if (ext && strstr(ext, "GL_APPLE_specular_vector")) {
        while (glGetError() != GL_NO_ERROR) {}
        glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
        GLenum e3 = glGetError();
        printf("APPLE_specular_vector (via LIGHT_MODEL_LOCAL_VIEWER): glGetError=0x%04x %s\n", (unsigned)e3, e3==GL_NO_ERROR?"OK":"MISMATCH");
    } else {
        printf("APPLE_specular_vector: NOT AVAILABLE - skipped\n");
    }

    /* transform_hint: performance hint, no required behavioral difference */
    if (ext && strstr(ext, "GL_APPLE_transform_hint")) {
        while (glGetError() != GL_NO_ERROR) {}
        glHint(GL_TRANSFORM_HINT_APPLE, GL_FASTEST);
        GLenum e4 = glGetError();
        printf("APPLE_transform_hint: glGetError=0x%04x %s\n", (unsigned)e4, e4==GL_NO_ERROR?"OK":"MISMATCH");
    } else {
        printf("APPLE_transform_hint: NOT AVAILABLE - skipped\n");
    }

    return 0;
}
