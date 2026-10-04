/* perf_gl_upload.c - issue #44 follow-up: texture upload and pixel-transfer costs, never measured anywhere
 * in this project before (perf_gl_features.c/perf_gl_pipeline.c measured SAMPLING a texture and a handful
 * of setup-phase costs, but never the cost of getting pixel data INTO the GPU in the first place, or OUT
 * of it via ReadPixels/CopyPixels/DrawPixels at more than one size). Also times GL_GENERATE_MIPMAP's real
 * cost at upload time (#128's gl_feature_automipmap_test.c confirmed it's correct; this times it).
 *
 * Same methodology as the other perf_gl_*.c files: mach_absolute_time, warmup, N timed repetitions, p10
 * headline, METRIC line format for Tools/perf_compare.py.
 *
 * Usage: perf_gl_upload [iterations per metric, default 500]
 * Build:  gcc -arch ppc -std=gnu99 -w -o perf_gl_upload perf_gl_upload.c -framework OpenGL
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mach/mach_time.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_GENERATE_MIPMAP
#define GL_GENERATE_MIPMAP 0x8191
#endif
#ifndef GL_PIXEL_UNPACK_BUFFER_ARB
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#endif

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

static GLubyte *mkbuf(int sz) { static GLubyte *b; b = malloc(sz*sz*4); int i; for (i=0;i<sz*sz;i++) { b[i*4]=i&0xff; b[i*4+1]=(i>>8)&0xff; b[i*4+2]=0x80; b[i*4+3]=255; } return b; }

int main(int argc, char **argv) {
    int N = argc > 1 ? atoi(argv[1]) : 500, warm = 10, i;
    mach_timebase_info_data_t tb; double *samp;
    mach_timebase_info(&tb); ticks_to_us = (double)tb.numer / tb.denom / 1000.0;
    setvbuf(stdout, NULL, _IONBF, 0);
    samp = malloc(N * sizeof(double));

    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, (CGLPixelFormatAttribute)0 };
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

    printf("perf_gl_upload: %d iterations/metric, %dx%d pbuffer, timer tick %.4f us\n", N, W, H, ticks_to_us);

    /* glTexImage2D cost at a few sizes - a fresh texture object each call to avoid measuring reuse effects */
    {
        int sizes[3] = {16, 64, 256};
        const char *names[3] = {"gl.teximage2d.16x16", "gl.teximage2d.64x64", "gl.teximage2d.256x256"};
        int s;
        for (s = 0; s < 3; s++) {
            GLubyte *data = mkbuf(sizes[s]);
            warmup();
            warmup();
        for (i = 0; i < warm; i++) { GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t); glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,sizes[s],sizes[s],0,GL_RGBA,GL_UNSIGNED_BYTE,data); glDeleteTextures(1,&t); }
            for (i = 0; i < N; i++) {
                GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
                double t0 = now_us();
                glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,sizes[s],sizes[s],0,GL_RGBA,GL_UNSIGNED_BYTE,data);
                double t1 = now_us(); samp[i] = t1 - t0;
                glDeleteTextures(1,&t);
            }
            report_metric(names[s], samp, N);
            free(data);
        }
    }

    /* PBO-backed upload vs plain client-memory upload, same 64x64 size */
    {
        GLubyte *data = mkbuf(64);
        warmup();
        for (i = 0; i < warm; i++) { GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t); glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,data); glDeleteTextures(1,&t); }
        for (i = 0; i < N; i++) {
            GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
            double t0 = now_us();
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
            double t1 = now_us(); samp[i] = t1 - t0;
            glDeleteTextures(1,&t);
        }
        report_metric("gl.teximage2d.64x64.plain", samp, N);

        GLuint pbo; glGenBuffersARB(1,&pbo); glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
        glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, 64*64*4, data, GL_STREAM_DRAW_ARB);
        warmup();
        for (i = 0; i < warm; i++) { GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t); glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,(void*)0); glDeleteTextures(1,&t); }
        for (i = 0; i < N; i++) {
            GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
            double t0 = now_us();
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,(void*)0);
            double t1 = now_us(); samp[i] = t1 - t0;
            glDeleteTextures(1,&t);
        }
        report_metric("gl.teximage2d.64x64.pbo", samp, N);
        glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);
        glDeleteBuffersARB(1,&pbo);
        free(data);
    }

    /* GL_GENERATE_MIPMAP cost at upload time vs plain upload (same base level, no mipmapping requested) */
    {
        GLubyte *data = mkbuf(64);
        warmup();
        for (i = 0; i < warm; i++) {
            GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
            glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
            glDeleteTextures(1,&t);
        }
        for (i = 0; i < N; i++) {
            GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
            glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
            double t0 = now_us();
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
            double t1 = now_us(); samp[i] = t1 - t0;
            glDeleteTextures(1,&t);
        }
        report_metric("gl.teximage2d.64x64.automipmap", samp, N);
        free(data);
    }

    /* pixel transfer ops at two sizes: glDrawPixels, glCopyPixels, glReadPixels */
    {
        int sizes[2] = {16, 64};
        const char *suffix[2] = {"16x16", "64x64"};
        int s;
        for (s = 0; s < 2; s++) {
            GLubyte *data = mkbuf(sizes[s]);
            char name[64];
            glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1);
            glMatrixMode(GL_MODELVIEW); glLoadIdentity();

            warmup();
            warmup();
        for (i = 0; i < warm; i++) { glRasterPos2i(0,0); glDrawPixels(sizes[s],sizes[s],GL_RGBA,GL_UNSIGNED_BYTE,data); glFinish(); }
            for (i = 0; i < N; i++) { glRasterPos2i(0,0); double t0 = now_us(); glDrawPixels(sizes[s],sizes[s],GL_RGBA,GL_UNSIGNED_BYTE,data); glFinish(); double t1 = now_us(); samp[i] = t1 - t0; }
            snprintf(name, sizeof name, "gl.drawpixels.%s", suffix[s]); report_metric(name, samp, N);

            warmup();
            warmup();
        for (i = 0; i < warm; i++) { glRasterPos2i(0,0); glCopyPixels(0,0,sizes[s],sizes[s],GL_COLOR); glFinish(); }
            for (i = 0; i < N; i++) { glRasterPos2i(0,0); double t0 = now_us(); glCopyPixels(0,0,sizes[s],sizes[s],GL_COLOR); glFinish(); double t1 = now_us(); samp[i] = t1 - t0; }
            snprintf(name, sizeof name, "gl.copypixels.%s", suffix[s]); report_metric(name, samp, N);

            {
                static GLubyte rbuf[256*256*4];
                warmup();
            warmup();
        for (i = 0; i < warm; i++) glReadPixels(0,0,sizes[s],sizes[s],GL_RGBA,GL_UNSIGNED_BYTE,rbuf);
                for (i = 0; i < N; i++) { double t0 = now_us(); glReadPixels(0,0,sizes[s],sizes[s],GL_RGBA,GL_UNSIGNED_BYTE,rbuf); double t1 = now_us(); samp[i] = t1 - t0; }
                snprintf(name, sizeof name, "gl.readpixels.%s", suffix[s]); report_metric(name, samp, N);
            }
            glMatrixMode(GL_PROJECTION); glLoadIdentity();
            glMatrixMode(GL_MODELVIEW); glLoadIdentity();
            free(data);
        }
    }

    printf("RESULT: PASS\n");
    return 0;
}
