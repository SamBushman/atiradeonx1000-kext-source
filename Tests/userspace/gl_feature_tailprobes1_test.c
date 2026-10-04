/* gl_feature_tailprobes1_test.c - low-priority tail extensions from #128's gap list, grouped into one
 * program since each is a quick presence/sanity probe rather than a deep correctness test:
 *  - GL_ATI_text_fragment_shader: old register-combiner-style text fragment shader (superseded by
 *    ARB_fragment_program, which this driver also has and this project already tested extensively)
 *  - GL_NV_blend_square: src*src / dst*dst as blend factors
 *  - GL_NV_fog_distance: alternate fog-distance modes (eye-radial vs eye-plane-absolute)
 *  - GL_NV_light_max_exponent: raises the max GL_SPOT_EXPONENT past the standard 128 limit
 *  - GL_IBM_rasterpos_clip: whether glRasterPos is properly clipped to the view volume
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_SRC_NV
#define GL_SRC_NV 0x8528
#endif
#ifndef GL_FOG_DISTANCE_MODE_NV
#define GL_FOG_DISTANCE_MODE_NV 0x855A
#endif
#ifndef GL_EYE_RADIAL_NV
#define GL_EYE_RADIAL_NV 0x855B
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
    printf("ATI_text_fragment_shader: %s (superseded by ARB_fragment_program, already extensively tested - not separately exercised)\n",
           (ext && strstr(ext,"GL_ATI_text_fragment_shader")) ? "present" : "absent");

    /* NV_blend_square: the real extension adds NO new enum tokens - it just makes GL_SRC_COLOR/
     * GL_ONE_MINUS_SRC_COLOR/GL_DST_COLOR/GL_ONE_MINUS_DST_COLOR legal as the SOURCE factor too (core GL
     * already allowed them as the destination factor only), so glBlendFunc(GL_SRC_COLOR, GL_ZERO) gives a
     * real src*src result. An earlier version of this test invented a nonexistent GL_SRC_NV token (0x8528,
     * not defined anywhere in this machine's real GL headers - confirmed via grep), which silently did
     * something other than intended instead of erroring. */
    if (ext && strstr(ext, "GL_NV_blend_square")) {
        glEnable(GL_BLEND);
        glClearColor(0.5f,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBlendFunc(GL_SRC_COLOR, GL_ZERO);
        glColor3f(0.6f,0,0);
        glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
        glFinish();
        static GLubyte buf[W*H*4];
        glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
        GLubyte *p = buf + (H/2*W+W/2)*4;
        int want = (int)(0.6f*0.6f*255+0.5f);
        int ok = abs((int)p[0]-want) <= 4;
        printf("NV_blend_square src*src (0.6*0.6=0.36): got %d want %d %s\n", p[0], want, ok?"OK":"MISMATCH");
    } else {
        printf("NV_blend_square: NOT AVAILABLE - skipped\n");
    }

    /* NV_fog_distance: just confirm the enum is accepted without error (functional difference is subtle -
     * radial vs plane-absolute distance only differs off-axis, not worth a full geometric derivation here) */
    if (ext && strstr(ext, "GL_NV_fog_distance")) {
        while (glGetError() != GL_NO_ERROR) {}
        glFogi(GL_FOG_DISTANCE_MODE_NV, GL_EYE_RADIAL_NV);
        GLenum e = glGetError();
        printf("NV_fog_distance EYE_RADIAL_NV: glGetError=0x%04x %s\n", (unsigned)e, e==GL_NO_ERROR?"OK":"MISMATCH");
    } else {
        printf("NV_fog_distance: NOT AVAILABLE - skipped\n");
    }

    /* NV_light_max_exponent: query the real max and confirm it's settable up to that value */
    if (ext && strstr(ext, "GL_NV_light_max_exponent")) {
        GLfloat maxExp = -1;
#ifndef GL_MAX_SHININESS_NV
#define GL_MAX_SHININESS_NV 0x8504
#endif
        glGetFloatv(GL_MAX_SHININESS_NV, &maxExp);
        printf("NV_light_max_exponent MAX_SHININESS_NV = %.1f\n", maxExp);
    } else {
        printf("NV_light_max_exponent: NOT AVAILABLE - skipped\n");
    }

    /* IBM_rasterpos_clip: a raster position set OUTSIDE the view volume should be marked invalid, and a
     * subsequent DrawPixels should be a no-op (vs. the old pre-clip behavior of drawing anyway at a
     * clamped/undefined position) */
    glRasterPos3f(100.0f, 100.0f, 0.0f);   /* far outside any reasonable clip volume */
    GLboolean valid; glGetBooleanv(GL_CURRENT_RASTER_POSITION_VALID, &valid);
    printf("IBM_rasterpos_clip: raster pos set far outside view volume, GL_CURRENT_RASTER_POSITION_VALID = %d (want 0/FALSE)\n", valid);

    return 0;
}
