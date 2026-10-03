/* gl_feature_blend_equation_test.c - issue #128 gap list: glBlendEquation modes (GL_FUNC_ADD default already
 * tested; GL_FUNC_SUBTRACT, GL_FUNC_REVERSE_SUBTRACT, GL_MIN, GL_MAX here) and additional blend func combos
 * (GL_CONSTANT_COLOR via glBlendColor, GL_DST_COLOR). */
#include <stdio.h>
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
    out[0]=p[0]; out[1]=p[1]; out[2]=p[2]; out[3]=p[3];
}

static void draw_dst_then_src(float dst[3], float src[3]) {
    glDisable(GL_BLEND);
    glClearColor(dst[0],dst[1],dst[2],1); glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glColor3fv(src);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
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
    GLubyte c[4];
    float dst[3] = {0.6f, 0.4f, 0.2f};
    float src[3] = {0.3f, 0.3f, 0.3f};

    /* GL_FUNC_SUBTRACT: src*srcFactor - dst*dstFactor, with factors (1,1) -> src - dst */
    glBlendFunc(GL_ONE, GL_ONE);
    glBlendEquation(GL_FUNC_SUBTRACT);
    draw_dst_then_src(dst, src);
    readback(c);
    {
        float wr = src[0]-dst[0], wg = src[1]-dst[1], wb = src[2]-dst[2];
        wr = wr<0?0:wr; wg = wg<0?0:wg; wb = wb<0?0:wb;
        int wR=(int)(wr*255+0.5f), wG=(int)(wg*255+0.5f), wB=(int)(wb*255+0.5f);
        int ok = abs((int)c[0]-wR)<=3 && abs((int)c[1]-wG)<=3 && abs((int)c[2]-wB)<=3;
        printf("FUNC_SUBTRACT src-dst: got %d,%d,%d want %d,%d,%d %s\n", c[0],c[1],c[2],wR,wG,wB, ok?"OK":"MISMATCH");
        if (!ok) bad++;
    }

    /* GL_FUNC_REVERSE_SUBTRACT: dst*dstFactor - src*srcFactor, factors (1,1) -> dst - src */
    glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
    draw_dst_then_src(dst, src);
    readback(c);
    {
        float wr = dst[0]-src[0], wg = dst[1]-src[1], wb = dst[2]-src[2];
        wr = wr<0?0:wr; wg = wg<0?0:wg; wb = wb<0?0:wb;
        int wR=(int)(wr*255+0.5f), wG=(int)(wg*255+0.5f), wB=(int)(wb*255+0.5f);
        int ok = abs((int)c[0]-wR)<=3 && abs((int)c[1]-wG)<=3 && abs((int)c[2]-wB)<=3;
        printf("FUNC_REVERSE_SUBTRACT dst-src: got %d,%d,%d want %d,%d,%d %s\n", c[0],c[1],c[2],wR,wG,wB, ok?"OK":"MISMATCH");
        if (!ok) bad++;
    }

    /* GL_MIN / GL_MAX (componentwise, ignoring blend factors entirely per spec) */
    glBlendEquation(GL_MIN);
    draw_dst_then_src(dst, src);
    readback(c);
    {
        float wr = dst[0]<src[0]?dst[0]:src[0], wg = dst[1]<src[1]?dst[1]:src[1], wb = dst[2]<src[2]?dst[2]:src[2];
        int wR=(int)(wr*255+0.5f), wG=(int)(wg*255+0.5f), wB=(int)(wb*255+0.5f);
        int ok = abs((int)c[0]-wR)<=3 && abs((int)c[1]-wG)<=3 && abs((int)c[2]-wB)<=3;
        printf("GL_MIN: got %d,%d,%d want %d,%d,%d %s\n", c[0],c[1],c[2],wR,wG,wB, ok?"OK":"MISMATCH");
        if (!ok) bad++;
    }

    glBlendEquation(GL_MAX);
    draw_dst_then_src(dst, src);
    readback(c);
    {
        float wr = dst[0]>src[0]?dst[0]:src[0], wg = dst[1]>src[1]?dst[1]:src[1], wb = dst[2]>src[2]?dst[2]:src[2];
        int wR=(int)(wr*255+0.5f), wG=(int)(wg*255+0.5f), wB=(int)(wb*255+0.5f);
        int ok = abs((int)c[0]-wR)<=3 && abs((int)c[1]-wG)<=3 && abs((int)c[2]-wB)<=3;
        printf("GL_MAX: got %d,%d,%d want %d,%d,%d %s\n", c[0],c[1],c[2],wR,wG,wB, ok?"OK":"MISMATCH");
        if (!ok) bad++;
    }

    /* GL_CONSTANT_COLOR blend factor via glBlendColor */
    glBlendEquation(GL_FUNC_ADD);
    glBlendColor(0.25f, 0.5f, 0.75f, 1.0f);
    glBlendFunc(GL_CONSTANT_COLOR, GL_ZERO);
    draw_dst_then_src(dst, src);
    readback(c);
    {
        float wr = src[0]*0.25f, wg = src[1]*0.5f, wb = src[2]*0.75f;
        int wR=(int)(wr*255+0.5f), wG=(int)(wg*255+0.5f), wB=(int)(wb*255+0.5f);
        int ok = abs((int)c[0]-wR)<=3 && abs((int)c[1]-wG)<=3 && abs((int)c[2]-wB)<=3;
        printf("BLEND_COLOR*src (CONSTANT_COLOR,ZERO): got %d,%d,%d want %d,%d,%d %s\n", c[0],c[1],c[2],wR,wG,wB, ok?"OK":"MISMATCH");
        if (!ok) bad++;
    }

    /* GL_DST_COLOR blend factor */
    glBlendFunc(GL_DST_COLOR, GL_ZERO);
    draw_dst_then_src(dst, src);
    readback(c);
    {
        float wr = src[0]*dst[0], wg = src[1]*dst[1], wb = src[2]*dst[2];
        int wR=(int)(wr*255+0.5f), wG=(int)(wg*255+0.5f), wB=(int)(wb*255+0.5f);
        int ok = abs((int)c[0]-wR)<=3 && abs((int)c[1]-wG)<=3 && abs((int)c[2]-wB)<=3;
        printf("src*DST_COLOR: got %d,%d,%d want %d,%d,%d %s\n", c[0],c[1],c[2],wR,wG,wB, ok?"OK":"MISMATCH");
        if (!ok) bad++;
    }

    printf("RESULT: %s (%d mismatches of 6 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
