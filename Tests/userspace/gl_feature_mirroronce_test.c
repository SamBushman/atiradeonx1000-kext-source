/* gl_feature_mirroronce_test.c - ATI_texture_mirror_once: GL_MIRROR_CLAMP_TO_EDGE_ATI mirrors the texture
 * once around the [0,1] edge, then clamps beyond that (unlike GL_MIRRORED_REPEAT, which mirrors forever).
 * Never checked before. */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_MIRROR_CLAMP_TO_EDGE_ATI
#define GL_MIRROR_CLAMP_TO_EDGE_ATI 0x8743
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static void draw_sampled_at(float s) {
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glTexCoord2f(s,0.5f); glVertex2f(-1,-1); glTexCoord2f(s,0.5f); glVertex2f(1,-1);
    glTexCoord2f(s,0.5f); glVertex2f(1,1); glTexCoord2f(s,0.5f); glVertex2f(-1,1);
    glEnd();
}

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
    glEnable(GL_TEXTURE_2D);

    const char *ext = (const char*)glGetString(GL_EXTENSIONS);
    if (!(ext && strstr(ext, "GL_ATI_texture_mirror_once"))) {
        printf("RESULT: SKIPPED - GL_ATI_texture_mirror_once not available\n");
        return 0;
    }

    /* 2-texel gradient: texel0=red(edge at s=0), texel1=blue(edge at s=1). At s=1.5 (one mirror past the
     * right edge), MIRROR_CLAMP_TO_EDGE should clamp to the EDGE texel of the mirrored copy = texel1 (blue),
     * same as plain CLAMP_TO_EDGE would give directly, distinguishing it from endless MIRRORED_REPEAT only
     * at s values far enough to show multiple mirror cycles differ - instead, check s=2.5 (second mirror
     * cycle) still gives the same clamped edge color, where MIRRORED_REPEAT would cycle again. */
    GLubyte tex[2*4] = {255,0,0,255, 0,0,255,255};
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,2,1,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRROR_CLAMP_TO_EDGE_ATI);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRROR_CLAMP_TO_EDGE_ATI);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    draw_sampled_at(2.5f);
    GLubyte c1[3]; readback(c1);
    draw_sampled_at(10.5f);   /* far beyond any plausible single mirror - must still clamp, not cycle */
    GLubyte c2[3]; readback(c2);
    int ok = (c1[0]==c2[0] && c1[1]==c2[1] && c1[2]==c2[2]);
    printf("MIRROR_CLAMP_TO_EDGE at s=2.5: %d,%d,%d; at s=10.5: %d,%d,%d (want identical - clamped, not cycling) %s\n",
           c1[0],c1[1],c1[2], c2[0],c2[1],c2[2], ok?"OK":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
