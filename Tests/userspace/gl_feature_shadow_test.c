/* gl_feature_shadow_test.c - ARB_depth_texture + ARB_shadow: a depth texture sampled with
 * GL_TEXTURE_COMPARE_MODE=GL_COMPARE_R_TO_TEXTURE / GL_TEXTURE_COMPARE_FUNC=GL_LEQUAL should return the
 * comparison RESULT (0 or 1, replicated to RGBA or just alpha depending on GL_DEPTH_TEXTURE_MODE), not the
 * raw depth value. Never checked before despite both extensions being advertised. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_TEXTURE_COMPARE_MODE
#define GL_TEXTURE_COMPARE_MODE 0x884C
#endif
#ifndef GL_TEXTURE_COMPARE_FUNC
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#endif
#ifndef GL_COMPARE_R_TO_TEXTURE
#define GL_COMPARE_R_TO_TEXTURE 0x884E
#endif
#ifndef GL_DEPTH_TEXTURE_MODE
#define GL_DEPTH_TEXTURE_MODE 0x884B
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

    /* a 2x1 depth texture: texel0 depth=0.25 (near), texel1 depth=0.75 (far) */
    GLfloat depth[2] = {0.25f, 0.75f};
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_DEPTH_COMPONENT,2,1,0,GL_DEPTH_COMPONENT,GL_FLOAT,depth);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_LUMINANCE);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor3f(1,1,1);

    int bad = 0;

    /* sample texel0 (depth 0.25) with r=0.5: LEQUAL means "result = (r <= texture depth) ? 1 : 0" ->
     * 0.5 <= 0.25 is FALSE -> result 0 (dark). Use glTexCoord4f to set the R component (comparison value). */
    glClearColor(0.3f,0.3f,0.3f,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord4f(0.25f,0,0.5f,1); glVertex2f(-1,-1);
    glTexCoord4f(0.25f,0,0.5f,1); glVertex2f(1,-1);
    glTexCoord4f(0.25f,0,0.5f,1); glVertex2f(1,1);
    glTexCoord4f(0.25f,0,0.5f,1); glVertex2f(-1,1);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p1 = buf + (H/2*W+W/2)*4;
    int ok1 = (p1[0] < 20);
    printf("shadow compare r=0.5 vs depth=0.25 (LEQUAL, want FAIL->dark): got %d,%d,%d %s\n", p1[0],p1[1],p1[2], ok1?"OK":"MISMATCH");
    if (!ok1) bad++;

    /* sample texel1 (depth 0.75) with r=0.5: 0.5 <= 0.75 is TRUE -> result 1 (bright) */
    glClearColor(0.3f,0.3f,0.3f,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord4f(0.75f,0,0.5f,1); glVertex2f(-1,-1);
    glTexCoord4f(0.75f,0,0.5f,1); glVertex2f(1,-1);
    glTexCoord4f(0.75f,0,0.5f,1); glVertex2f(1,1);
    glTexCoord4f(0.75f,0,0.5f,1); glVertex2f(-1,1);
    glEnd();
    glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p2 = buf + (H/2*W+W/2)*4;
    int ok2 = (p2[0] > 230);
    printf("shadow compare r=0.5 vs depth=0.75 (LEQUAL, want PASS->bright): got %d,%d,%d %s\n", p2[0],p2[1],p2[2], ok2?"OK":"MISMATCH");
    if (!ok2) bad++;

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
