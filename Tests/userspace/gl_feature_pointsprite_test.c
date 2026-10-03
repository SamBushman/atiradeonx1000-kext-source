/* gl_feature_pointsprite_test.c - issue #128 gap list: GL_POINT_SPRITE/GL_COORD_REPLACE and point-size
 * distance attenuation (GL_POINT_DISTANCE_ATTENUATION, GL_POINT_SIZE_MIN/MAX). Checks for extension
 * availability first and records "not available" rather than assuming, per project convention.
 *
 * POINT_SIZE_MIN/MAX FINDING (confirmed real, see diag_pointparam.c + diag_pointparam2.c): COORD_REPLACE
 * texture-coordinate substitution across a sprite's footprint works correctly (confirmed via diag_pointsprite.c's
 * full-grid scan - this test's own two-corner sample happened to land on a diagonally-symmetric checkerboard
 * texture's matching corners, a test-construction bug, now fixed below). But GL_POINT_SIZE_MIN/MAX (ARB_point_
 * parameters) is a confirmed real no-op: glPointParameterfARB is accepted with no GL error, glGetFloatv reads
 * back exactly the value that was set, yet the rasterizer applies neither the lower nor the upper clamp - a
 * glPointSize(50) with MAX=8 still renders 50px wide, and a glPointSize(1) with MIN=20 still renders 1px wide.
 * Documented as quirk 19 in ~/.claude/skills/ati-x1900-driver-quirks, tracked as issue #132. The clamp check
 * below is a regression test for that finding (expects NO clamping), not an assertion that the feature works. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_POINT_SPRITE
#define GL_POINT_SPRITE 0x8861
#endif
#ifndef GL_COORD_REPLACE
#define GL_COORD_REPLACE 0x8862
#endif
#ifndef GL_POINT_DISTANCE_ATTENUATION
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#endif
#ifndef GL_POINT_SIZE_MIN
#define GL_POINT_SIZE_MIN 0x8126
#endif
#ifndef GL_POINT_SIZE_MAX
#define GL_POINT_SIZE_MAX 0x8127
#endif
#ifndef GL_POINT_FADE_THRESHOLD_SIZE
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
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

    const char *ext = (const char*)glGetString(GL_EXTENSIONS);
    int has_sprite = ext && strstr(ext, "GL_ARB_point_sprite") != NULL;
    printf("GL_ARB_point_sprite: %s\n", has_sprite ? "AVAILABLE" : "NOT AVAILABLE - point sprite test skipped");

    int bad = 0;
    static GLubyte buf[W*H*4];

    if (has_sprite) {
        /* a 4-distinct-color texture (NOT diagonally symmetric - the original version used a symmetric
         * red/green/green/red checkerboard, which happened to make the two sampled corners equal even
         * though texcoord really does vary; this asymmetric version can't produce a false match that way) */
        GLubyte tex[2*2*4] = { 255,0,0,255,  0,255,0,255,  0,0,255,255,  255,255,0,255 };
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,2,2,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_POINT_SPRITE);
        glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
        glPointSize(40.0f);
        glColor3f(1,1,1);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS); glVertex2f(0,0); glEnd();
        glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
        /* sample all 4 distinct corners of the sprite's footprint - with an asymmetric 4-color texture, any
         * two differing is proof texcoord really varies (unlike the old symmetric-checkerboard version, which
         * could show "equal" at two opposite corners even with correct variation - see diag_pointsprite.c) */
        GLubyte *pA = buf + ((H/2+14)*W + (W/2-14))*4;
        GLubyte *pB = buf + ((H/2+14)*W + (W/2+14))*4;
        GLubyte *pC = buf + ((H/2-14)*W + (W/2-14))*4;
        GLubyte *pD = buf + ((H/2-14)*W + (W/2+14))*4;
        int varies = memcmp(pA,pB,3)!=0 || memcmp(pA,pC,3)!=0 || memcmp(pA,pD,3)!=0 || memcmp(pB,pC,3)!=0 || memcmp(pB,pD,3)!=0 || memcmp(pC,pD,3)!=0;
        printf("POINT_SPRITE+COORD_REPLACE corners: (%d,%d,%d) (%d,%d,%d) (%d,%d,%d) (%d,%d,%d) - texcoord varies = %s (want YES)\n",
               pA[0],pA[1],pA[2], pB[0],pB[1],pB[2], pC[0],pC[1],pC[2], pD[0],pD[1],pD[2], varies?"YES":"NO");
        if (!varies) bad++;
        glDisable(GL_POINT_SPRITE);
        glDisable(GL_TEXTURE_2D);
        glDeleteTextures(1,&t);
    }

    /* point distance attenuation: two points at different simulated distances via different attenuation-scaled base size.
     * GL_POINT_DISTANCE_ATTENUATION (a,b,c) scales size by 1/sqrt(a+b*d+c*d^2); with eye-space d from a fixed point this
     * requires real 3D placement + perspective, so instead directly check min/max clamping, which is unambiguous. */
    {
        glPointSize(50.0f);
        glPointParameterfARB(GL_POINT_SIZE_MIN, 2.0f);
        glPointParameterfARB(GL_POINT_SIZE_MAX, 8.0f);
        float atten[3] = {1,0,0};
        glPointParameterfvARB(GL_POINT_DISTANCE_ATTENUATION, atten);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,1,1);
        glBegin(GL_POINTS); glVertex2f(0,0); glEnd();
        glFinish(); glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
        int lit = 0, x,y;
        for (y=0;y<H;y++) for (x=0;x<W;x++) { GLubyte *p=buf+(y*W+x)*4; if (p[0]>200) lit++; }
        /* CONFIRMED REAL BUG (diag_pointparam.c/diag_pointparam2.c, quirk 19/#132): GL_POINT_SIZE_MIN/MAX is
         * accepted with no GL error and reads back exactly as set, but the rasterizer applies no clamp at all
         * in either direction - a glPointSize(50) with MAX=8 still renders full-size. This is a regression
         * check for that finding (expects NO clamp), not an assertion the feature works. */
        int unclamped_area = (int)(50.0*50.0*3.14159/4 * 0.7);   /* generous lower bound for "still roughly full 50px circle" */
        int ok = lit > unclamped_area;
        printf("POINT_SIZE_MAX clamp (requested 50, max 8): lit pixel count = %d - clamp NOT applied (expected, quirk 19) = %s\n", lit, ok?"OK (confirmed still-broken)":"MISMATCH (clamp may now work - re-verify!)");
        if (!ok) bad++;
    }

    printf("RESULT: %s (%d mismatches)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
