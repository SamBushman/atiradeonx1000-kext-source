/* gl_feature_texturelod_range_test.c - GL_SGIS_texture_lod / core GL_TEXTURE_MIN_LOD/GL_TEXTURE_MAX_LOD:
 * clamps which mip levels the sampler is allowed to select, independent of GL_TEXTURE_BASE_LEVEL/MAX_LEVEL
 * (which restrict the levels that EXIST). Never checked before.
 *
 * CONFIRMED REAL DRIVER BUG (quirk 26/#139, see diag_lodrange.c): GL_TEXTURE_MAX_LOD is accepted with no
 * GL error and reads back exactly as set (0.0), but the sampler still selects a smaller mip level for a
 * tiny on-screen footprint, completely ignoring the clamp - the same class of bug as quirks 18/19/24 (state
 * correctly stored, but never actually consulted by the relevant pipeline stage). A full 7-level chain with
 * MAX_LOD=0 should force level 0 regardless of footprint size; it does not. */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

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

    static GLubyte lvl[64*64*4];
    int i;
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    for (i=0;i<64*64;i++) { lvl[i*4]=255; lvl[i*4+1]=0; lvl[i*4+2]=0; lvl[i*4+3]=255; }   /* level0 = red */
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,lvl);
    { int lv, sz=32; for (lv=1; lv<=6; lv++, sz/=2) {
        for (i=0;i<sz*sz;i++) { lvl[i*4]=0; lvl[i*4+1]=255; lvl[i*4+2]=0; lvl[i*4+3]=255; }   /* all other levels = green */
        glTexImage2D(GL_TEXTURE_2D,lv,GL_RGBA8,sz,sz,0,GL_RGBA,GL_UNSIGNED_BYTE,lvl);
    } }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor3f(1,1,1);

    /* tiny 4px footprint - without any LOD clamp, this would normally select a small (green) level */
    float half = 4.0f/W;
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(-half,-half); glTexCoord2f(1,0); glVertex2f(half,-half);
    glTexCoord2f(1,1); glVertex2f(half,half); glTexCoord2f(0,1); glVertex2f(-half,half);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte unclamped[3]; memcpy(unclamped, buf+(H/2*W+W/2)*4, 3);
    printf("tiny footprint, no LOD clamp: got %d,%d,%d (expected green, confirming a small level would normally be picked)\n", unclamped[0],unclamped[1],unclamped[2]);

    /* now clamp TEXTURE_MAX_LOD to 0 - the sampler must never go past level 0 (red), regardless of footprint */
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_LOD, 0.0f);
    GLenum e = glGetError();
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(-half,-half); glTexCoord2f(1,0); glVertex2f(half,-half);
    glTexCoord2f(1,1); glVertex2f(half,half); glTexCoord2f(0,1); glVertex2f(-half,half);
    glEnd();
    glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *clamped = buf + (H/2*W+W/2)*4;
    /* regression check for the confirmed bug: clamp NOT applied (green, not red) is the expected result */
    int ok = (clamped[1] > 200 && clamped[0] < 20) && e==GL_NO_ERROR;
    printf("TEXTURE_MAX_LOD=0, same tiny footprint: got %d,%d,%d - clamp NOT applied (expected, quirk 26) %s\n",
           clamped[0],clamped[1],clamped[2], ok?"OK (confirmed still-broken)":"MISMATCH (clamp may now work - re-verify!)");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
