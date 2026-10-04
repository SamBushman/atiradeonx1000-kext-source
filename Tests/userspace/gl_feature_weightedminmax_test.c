/* gl_feature_weightedminmax_test.c - ATI_blend_weighted_minmax: GL_MIN/GL_MAX blend equations weighted by
 * alpha instead of plain componentwise min/max. Never checked before. */
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

    const char *ext = (const char*)glGetString(GL_EXTENSIONS);
    if (!(ext && strstr(ext, "GL_ATI_blend_weighted_minmax"))) {
        printf("RESULT: SKIPPED - GL_ATI_blend_weighted_minmax not available\n");
        return 0;
    }

    /* No public enum for this extension's actual weighted-min/max token could be confirmed against this
     * machine's installed GL headers (grep of /System/Library/Frameworks/OpenGL.framework/Headers found no
     * ATI_blend_weighted_minmax-specific token, only the extension string advertising it) - without a real
     * token to pass to glBlendEquation, this cannot be exercised safely by guessing a numeric value.
     * Recording the gap rather than guessing. */
    glEnable(GL_BLEND);
    glClearColor(0.8f,0.2f,0.5f,1.0f); glClear(GL_COLOR_BUFFER_BIT);
    glBlendEquation(GL_MAX);
    glColor4f(0.3f,0.9f,0.1f,0.4f);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    GLubyte plainmax[3]; readback(plainmax);
    printf("plain GL_MAX (already proven correct elsewhere in this project): %d,%d,%d\n", plainmax[0],plainmax[1],plainmax[2]);
    printf("RESULT: SKIPPED - GL_ATI_blend_weighted_minmax is advertised but no usable public enum for its actual weighted op was found in this machine's GL headers; not exercised rather than guessed\n");
    return 0;
}
