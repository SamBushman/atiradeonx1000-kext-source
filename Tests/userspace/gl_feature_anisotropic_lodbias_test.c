/* gl_feature_anisotropic_lodbias_test.c - EXT_texture_filter_anisotropic and EXT_texture_lod_bias, never
 * checked before. Anisotropic: just confirm the parameter is settable/readable and clamped to the real
 * implementation max. LOD bias: a positive bias should shift sampling toward a smaller (coarser) mip level,
 * checked the same way the mipmap test identified levels - via distinct per-level colors. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_TEXTURE_MAX_ANISOTROPY_EXT
#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#endif
#ifndef GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
#endif
#ifndef GL_TEXTURE_LOD_BIAS_EXT
#define GL_TEXTURE_LOD_BIAS_EXT 0x8501
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 64
#define H 64

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

    /* anisotropic: query the real max, set it, read back */
    GLfloat maxAniso = -1;
    glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAniso);
    printf("MAX_TEXTURE_MAX_ANISOTROPY = %.1f\n", maxAniso);
    GLuint tex0; glGenTextures(1,&tex0); glBindTexture(GL_TEXTURE_2D,tex0);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAniso);
    GLfloat readback = -1;
    glGetTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, &readback);
    int ok1 = (readback == maxAniso);
    printf("TEXTURE_MAX_ANISOTROPY set to %.1f, readback = %.1f %s\n", maxAniso, readback, ok1?"OK":"MISMATCH");
    if (!ok1) bad++;
    glDeleteTextures(1,&tex0);

    /* LOD bias: build a FULL mip chain down to 1x1 (level0=red 64x64, level1=green 32x32, then solid-color
     * filler levels 2-6) - a mipmapped min filter requires EVERY level present down to 1x1 to be considered
     * "texture complete" per spec; an earlier version of this test only built 2 levels, which the spec
     * defines as making the texture object incomplete, and sampling an incomplete texture is defined to
     * behave as if texturing were disabled entirely (showing the raw fragment color) - that's exactly the
     * unexpected all-white result diag_lodbias.c caught, a test-construction bug, not a driver one. */
    static GLubyte lvl[64*64*4];
    int i;
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    for (i=0;i<64*64;i++) { lvl[i*4]=255; lvl[i*4+1]=0; lvl[i*4+2]=0; lvl[i*4+3]=255; }
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,lvl);
    for (i=0;i<32*32;i++) { lvl[i*4]=0; lvl[i*4+1]=255; lvl[i*4+2]=0; lvl[i*4+3]=255; }
    glTexImage2D(GL_TEXTURE_2D,1,GL_RGBA8,32,32,0,GL_RGBA,GL_UNSIGNED_BYTE,lvl);
    { int lv, sz=16; for (lv=2; lv<=6; lv++, sz/=2) {
        for (i=0;i<sz*sz;i++) { lvl[i*4]=0; lvl[i*4+1]=255; lvl[i*4+2]=0; lvl[i*4+3]=255; }
        glTexImage2D(GL_TEXTURE_2D,lv,GL_RGBA8,sz,sz,0,GL_RGBA,GL_UNSIGNED_BYTE,lvl);
    } }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor3f(1,1,1);

    /* render at a 64px (1:1) footprint - normally selects level 0 (red) */
    glTexEnvf(GL_TEXTURE_FILTER_CONTROL_EXT, GL_TEXTURE_LOD_BIAS_EXT, 0.0f);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(-1,-1); glTexCoord2f(1,0); glVertex2f(1,-1);
    glTexCoord2f(1,1); glVertex2f(1,1); glTexCoord2f(0,1); glVertex2f(-1,1);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte p0[3]; p0[0]=buf[(H/2*W+W/2)*4]; p0[1]=buf[(H/2*W+W/2)*4+1]; p0[2]=buf[(H/2*W+W/2)*4+2];
    printf("no LOD bias, 1:1 footprint: got %d,%d,%d (want red, level 0)\n", p0[0],p0[1],p0[2]);

    glTexEnvf(GL_TEXTURE_FILTER_CONTROL_EXT, GL_TEXTURE_LOD_BIAS_EXT, 4.0f);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(-1,-1); glTexCoord2f(1,0); glVertex2f(1,-1);
    glTexCoord2f(1,1); glVertex2f(1,1); glTexCoord2f(0,1); glVertex2f(-1,1);
    glEnd();
    glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p1 = buf + (H/2*W+W/2)*4;
    printf("LOD_BIAS=4.0, same 1:1 footprint: got %d,%d,%d (want green, level 1 - bias pushed to a coarser level)\n", p1[0],p1[1],p1[2]);
    int ok2 = (p0[0] > 200 && p0[1] < 20) && (p1[1] > 200 && p1[0] < 20);
    if (!ok2) bad++;

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
