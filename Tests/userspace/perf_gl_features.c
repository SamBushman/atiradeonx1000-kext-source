/* perf_gl_features.c - issue #44 follow-up: feature-level GL rendering cost on the STOCK driver.
 *
 * The existing performance baseline (Tests/perf_baseline.c / performance_plan.md) times one GENERIC
 * triangle-draw cycle (CreateContext/SetPBuffer/Clear/Draw100Tri/ReadPixels/Teardown) - it says nothing
 * about whether any SPECIFIC GL feature (the ones issue #128 spent 62 tests correctness-checking: blend
 * modes, texture combine chains, shadow sampling, texture compression, texgen, lighting, ...) costs more
 * than a plain flat-color draw. A feature can be correct and pathologically slow and #128's tests would
 * never have caught it. This file times each feature in isolation, same quad, same size, only the GL state
 * differs, against the same flat-color baseline every other metric is compared to.
 *
 * Same methodology as Tests/perf_methods.c: mach_absolute_time, a warmup() burn to clear the G5's dynamic
 * power-stepping transient, N repeated timed draws (not just one), p10 as the headline (fast-mode floor),
 * same METRIC line format so Tools/perf_compare.py can parse this file's output directly.
 *
 * Usage: perf_gl_features [draws per metric, default 5000]
 * Build:  gcc -arch ppc -std=gnu99 -w -o perf_gl_features perf_gl_features.c -framework OpenGL
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mach/mach_time.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static double ticks_to_us;
static double now_us(void) { return (double)mach_absolute_time() * ticks_to_us; }
static void warmup(void) { double t0 = now_us(); volatile double x = 1.0; while (now_us() - t0 < 700000.0) { int k; for (k = 0; k < 1000; k++) x = x * 1.0000001 + 0.5; } }
static int cmp_d(const void *a, const void *b) { double x = *(const double *)a, y = *(const double *)b; return x < y ? -1 : x > y; }

static void report_metric(const char *name, double *s, int n) {
    qsort(s, n, sizeof(double), cmp_d);
    printf("METRIC %s n=%d min_us=%.2f p10_us=%.2f median_us=%.2f p90_us=%.2f max_us=%.2f\n", name, n, s[0], s[(int)(n * 0.1)], s[n / 2], s[(int)(n * 0.9)], s[n - 1]);
}

#define BENCH(NAME, DRAWEXPR) do { int _i; for (_i = 0; _i < warm; _i++) { DRAWEXPR; glFinish(); } \
    for (_i = 0; _i < N; _i++) { double t0 = now_us(); DRAWEXPR; glFinish(); double t1 = now_us(); samp[_i] = t1 - t0; } \
    report_metric(NAME, samp, N); } while (0)

static void quad(void) { glBegin(GL_QUADS); glVertex2f(-0.9f,-0.9f); glVertex2f(0.9f,-0.9f); glVertex2f(0.9f,0.9f); glVertex2f(-0.9f,0.9f); glEnd(); }
static void texquad(void) { glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(-0.9f,-0.9f); glTexCoord2f(1,0); glVertex2f(0.9f,-0.9f);
    glTexCoord2f(1,1); glVertex2f(0.9f,0.9f); glTexCoord2f(0,1); glVertex2f(-0.9f,0.9f); glEnd(); }
static void multitexquad(void) { glBegin(GL_QUADS);
    glMultiTexCoord2f(GL_TEXTURE0,0,0); glMultiTexCoord2f(GL_TEXTURE1,0,0); glVertex2f(-0.9f,-0.9f);
    glMultiTexCoord2f(GL_TEXTURE0,1,0); glMultiTexCoord2f(GL_TEXTURE1,1,0); glVertex2f(0.9f,-0.9f);
    glMultiTexCoord2f(GL_TEXTURE0,1,1); glMultiTexCoord2f(GL_TEXTURE1,1,1); glVertex2f(0.9f,0.9f);
    glMultiTexCoord2f(GL_TEXTURE0,0,1); glMultiTexCoord2f(GL_TEXTURE1,0,1); glVertex2f(-0.9f,0.9f); glEnd(); }
static void litquad(void) { glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex2f(-0.9f,-0.9f); glVertex2f(0.9f,-0.9f); glVertex2f(0.9f,0.9f); glVertex2f(-0.9f,0.9f); glEnd(); }
static void cube3dquad(void) { glBegin(GL_QUADS);
    glTexCoord3f(0.1f,0.1f,0.1f); glVertex2f(-0.9f,-0.9f); glTexCoord3f(0.9f,0.1f,0.5f); glVertex2f(0.9f,-0.9f);
    glTexCoord3f(0.9f,0.9f,0.9f); glVertex2f(0.9f,0.9f); glTexCoord3f(0.1f,0.9f,0.5f); glVertex2f(-0.9f,0.9f); glEnd(); }

int main(int argc, char **argv) {
    int N = argc > 1 ? atoi(argv[1]) : 5000, warm = 50;
    mach_timebase_info_data_t tb; double *samp;
    mach_timebase_info(&tb); ticks_to_us = (double)tb.numer / tb.denom / 1000.0;
    setvbuf(stdout, NULL, _IONBF, 0);
    samp = malloc(N * sizeof(double));

    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, kCGLPFADepthSize,16, kCGLPFAStencilSize,8, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
    if (err || npix == 0 || !pf) { fprintf(stderr, "ChoosePixelFormat failed\n"); return 1; }
    CGLContextObj ctx = NULL; err = CGLCreateContext(pf, NULL, &ctx);
    if (err) { fprintf(stderr, "CreateContext failed\n"); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf = NULL; err = CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { fprintf(stderr, "CreatePBuffer failed\n"); return 1; }
    err = CGLSetCurrentContext(ctx); if (err) { fprintf(stderr, "SetCurrentContext failed\n"); return 1; }
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, 0); if (err) { fprintf(stderr, "SetPBuffer failed\n"); return 1; }
    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glColor3f(1,1,1);

    printf("perf_gl_features: %d draws/metric, %dx%d pbuffer, timer tick %.4f us\n", N, W, H, ticks_to_us);

    /* baseline: flat-color quad, no extra state - every other metric is read relative to this */
    warmup();
    BENCH("gl.baseline.flatcolor", (quad()));

    /* blend */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    warmup();
    BENCH("gl.blend.srcalpha", (quad()));
    glBlendEquationSeparateEXT(GL_FUNC_ADD, GL_FUNC_REVERSE_SUBTRACT);
    glBlendFuncSeparateEXT(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);
    warmup();
    BENCH("gl.blend.equation_func_separate", (quad()));
    glDisable(GL_BLEND);

    /* fog */
    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogf(GL_FOG_START, 0.0f); glFogf(GL_FOG_END, 20.0f);
    warmup();
    BENCH("gl.fog.linear", (quad()));
    glDisable(GL_FOG);

    /* stencil */
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_ALWAYS, 0, 0xff);
    glStencilOp(GL_KEEP, GL_KEEP, GL_INCR_WRAP);
    warmup();
    BENCH("gl.stencil.funcop", (quad()));
    glDisable(GL_STENCIL_TEST);

    /* alpha test */
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.5f);
    glColor4f(1,1,1,0.8f);
    warmup();
    BENCH("gl.alphatest", (quad()));
    glDisable(GL_ALPHA_TEST);
    glColor3f(1,1,1);

    /* single 2D texture, modulate */
    {
        GLubyte tex[4*4*4]; int i; for (i=0;i<16;i++) { tex[i*4]=200; tex[i*4+1]=100; tex[i*4+2]=50; tex[i*4+3]=255; }
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,4,4,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
        glEnable(GL_TEXTURE_2D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        warmup();
        BENCH("gl.tex2d.modulate", (texquad()));

        /* DOT3 combine on the same bound unit, PREVIOUS x itself */
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
        glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_DOT3_RGB);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE);
        glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE);
        glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_SRC_COLOR);
        warmup();
        BENCH("gl.tex2d.dot3combine", (texquad()));
        glDisable(GL_TEXTURE_2D);
        glDeleteTextures(1,&t);
    }

    /* 2-unit multitexture combine chain */
    {
        GLubyte tex0[4] = {255,0,0,255}, tex1[4] = {0,255,0,255};
        GLuint t0,t1; glGenTextures(1,&t0); glGenTextures(1,&t1);
        glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D,t0);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,tex0);
        glEnable(GL_TEXTURE_2D); glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glActiveTexture(GL_TEXTURE1); glBindTexture(GL_TEXTURE_2D,t1);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,tex1);
        glEnable(GL_TEXTURE_2D); glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);
        warmup();
        BENCH("gl.tex.multiunit2.modulate_add", (multitexquad()));
        glActiveTexture(GL_TEXTURE1); glDisable(GL_TEXTURE_2D); glDeleteTextures(1,&t1);
        glActiveTexture(GL_TEXTURE0); glDisable(GL_TEXTURE_2D); glDeleteTextures(1,&t0);
    }

    /* cube map */
    {
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_CUBE_MAP,t);
        GLenum faces[6] = {GL_TEXTURE_CUBE_MAP_POSITIVE_X,GL_TEXTURE_CUBE_MAP_NEGATIVE_X,GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
                            GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,GL_TEXTURE_CUBE_MAP_POSITIVE_Z,GL_TEXTURE_CUBE_MAP_NEGATIVE_Z};
        GLubyte px[4] = {128,64,200,255};
        int i; for (i=0;i<6;i++) glTexImage2D(faces[i],0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,px);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glEnable(GL_TEXTURE_CUBE_MAP);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        warmup();
        BENCH("gl.tex.cubemap", (cube3dquad()));
        glDisable(GL_TEXTURE_CUBE_MAP); glDeleteTextures(1,&t);
    }

    /* 3D texture */
    {
        GLubyte vol[2*2*2*4]; int i; for (i=0;i<8;i++) { vol[i*4]=i*30; vol[i*4+1]=255-i*30; vol[i*4+2]=128; vol[i*4+3]=255; }
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_3D,t);
        glTexImage3D(GL_TEXTURE_3D,0,GL_RGBA8,2,2,2,0,GL_RGBA,GL_UNSIGNED_BYTE,vol);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glEnable(GL_TEXTURE_3D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        warmup();
        BENCH("gl.tex.3d", (cube3dquad()));
        glDisable(GL_TEXTURE_3D); glDeleteTextures(1,&t);
    }

    /* S3TC compressed texture */
    {
        GLubyte block[8] = {0,0xf8,0,0,0,0,0,0};
        while (glGetError() != GL_NO_ERROR) {}
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGB_S3TC_DXT1_EXT, 4, 4, 0, 8, block);
        if (glGetError() == GL_NO_ERROR) {
            glEnable(GL_TEXTURE_2D);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
            warmup();
            BENCH("gl.tex.s3tc_dxt1", (texquad()));
            glDisable(GL_TEXTURE_2D);
        } else {
            printf("gl.tex.s3tc_dxt1: SKIPPED (compressed upload errored)\n");
        }
        glDeleteTextures(1,&t);
    }

    /* shadow/depth-compare sampling */
    {
        GLfloat depth = 0.5f;
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_DEPTH_COMPONENT,1,1,0,GL_DEPTH_COMPONENT,GL_FLOAT,&depth);
        glTexParameteri(GL_TEXTURE_2D, 0x884C /*COMPARE_MODE*/, 0x884E /*COMPARE_R_TO_TEXTURE*/);
        glTexParameteri(GL_TEXTURE_2D, 0x884D /*COMPARE_FUNC*/, GL_LEQUAL);
        glTexParameteri(GL_TEXTURE_2D, 0x884B /*DEPTH_TEXTURE_MODE*/, GL_LUMINANCE);
        glEnable(GL_TEXTURE_2D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        warmup();
        BENCH("gl.tex.shadow_compare", ( glBegin(GL_QUADS),
            glTexCoord4f(0.5f,0.5f,0.5f,1), glVertex2f(-0.9f,-0.9f),
            glTexCoord4f(0.5f,0.5f,0.5f,1), glVertex2f(0.9f,-0.9f),
            glTexCoord4f(0.5f,0.5f,0.5f,1), glVertex2f(0.9f,0.9f),
            glTexCoord4f(0.5f,0.5f,0.5f,1), glVertex2f(-0.9f,0.9f), glEnd() ));
        glDisable(GL_TEXTURE_2D); glDeleteTextures(1,&t);
    }

    /* texgen */
    {
        GLfloat plane[4] = {0.5f,0,0,0.5f};
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGenfv(GL_S, GL_OBJECT_LINEAR, plane);
        glEnable(GL_TEXTURE_GEN_S);
        warmup();
        BENCH("gl.texgen.objectlinear", (quad()));
        glDisable(GL_TEXTURE_GEN_S);
    }

    /* lighting, one light */
    {
        glEnable(GL_LIGHTING); glEnable(GL_NORMALIZE);
        GLfloat white_mat[4]={1,1,1,1};
        glMaterialfv(GL_FRONT, GL_DIFFUSE, white_mat);
        glEnable(GL_LIGHT0);
        GLfloat lpos[4]={0,0,1,0}, ldiff[4]={1,1,1,1};
        glLightfv(GL_LIGHT0, GL_POSITION, lpos);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, ldiff);
        warmup();
        BENCH("gl.lighting.onelight", (litquad()));
        glDisable(GL_LIGHTING);
    }

    printf("RESULT: PASS\n");
    return 0;
}
