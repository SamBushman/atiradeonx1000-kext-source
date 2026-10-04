/* gl_feature_automipmap_test.c - GL_SGIS_generate_mipmap / GL_GENERATE_MIPMAP: upload only the base level
 * with distinct-colored quadrants, enable auto-mipmap-generation, and confirm minified sampling shows an
 * AVERAGED color (not the base level's raw nearest-neighbor color), proving the driver actually built and
 * used a real downsampled chain rather than ignoring the flag. Never checked before. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_GENERATE_MIPMAP
#define GL_GENERATE_MIPMAP 0x8191
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

    /* 64x64 base texture: red up to x=30, blue from x=30 on. A split EXACTLY at a power-of-two boundary
     * (e.g. x=32) downsamples to another perfectly sharp edge at every mip level with no straddling texel
     * at all - that was this test's original bug (diag_automip3.c proved the x=32 version's mip chain was
     * genuinely generated with correct dimensions and a correctly-placed sharp edge at every level, which
     * is exactly what a REAL box filter should produce for a perfectly-aligned split; there was never a
     * reason to expect a blended texel there). x=30 guarantees some 2x2 (and 4x4, etc.) block straddles
     * the boundary at every level, so a real downsample MUST show an averaged color somewhere. */
    static GLubyte base[64*64*4];
    int x,y;
    for (y=0;y<64;y++) for (x=0;x<64;x++) {
        GLubyte *p = base + (y*64+x)*4;
        if (x < 30) { p[0]=255; p[1]=0; p[2]=0; p[3]=255; }
        else { p[0]=0; p[1]=0; p[2]=255; p[3]=255; }
    }
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,base);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    /* directly inspect the generated mip chain's own texel content near the boundary - avoids any ambiguity
     * from on-screen LOD/footprint selection (which mip level a given screen size maps to) that a render-
     * and-sample approach would introduce; this checks what was actually BUILT, not what got SELECTED. */
    GLint w2 = -1;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 2, GL_TEXTURE_WIDTH, &w2);
    printf("mip level 2 reported width = %d (want 16, confirms the chain was allocated)\n", (int)w2);
    int bad = (w2 != 16);

    static GLubyte lvl2[16*16*4];
    glGetTexImage(GL_TEXTURE_2D, 2, GL_RGBA, GL_UNSIGNED_BYTE, lvl2);
    /* base split at x=30 of 64 -> level2 (16x16, each texel = 4x4 base block) boundary falls at x=30/4=7.5,
     * so texel x=7 straddles it (base columns 28-31, half red half blue) and must show a blended color */
    GLubyte *straddle = lvl2 + (8*16+7)*4;
    printf("mip level 2, straddling texel (x=7,y=8): %d,%d,%d\n", straddle[0], straddle[1], straddle[2]);
    int blended = (straddle[0] > 20 && straddle[0] < 235) && (straddle[2] > 20 && straddle[2] < 235);
    printf("  real averaged blend (both R and B present) = %s\n", blended?"YES (auto-mipmap genuinely box-filtered)":"NO (looks like nearest-neighbor subsampling, not a real box filter)");
    if (!blended) bad++;

    printf("RESULT: %s\n", bad==0?"PASS":"FAIL");
    return bad?1:0;
}
