/* perf_gl_scale.c - issue #44 follow-up: every other perf_gl_*.c file deliberately measures a tiny
 * (64x64 pbuffer, ~100-triangle) workload dominated by fixed per-call overhead, matching this project's
 * existing glcycle.* convention - none of them say anything about whether a feature's cost SCALES
 * differently once the GPU is actually doing real work. This file redraws a few of the same features at
 * increasing geometry/texture/viewport size to find that out.
 *
 * Same methodology as the other perf_gl_*.c files: mach_absolute_time, warmup, N timed repetitions, p10
 * headline, METRIC line format for Tools/perf_compare.py.
 *
 * Usage: perf_gl_scale [iterations per metric, default 200]
 * Build:  gcc -arch ppc -std=gnu99 -w -o perf_gl_scale perf_gl_scale.c -framework OpenGL
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mach/mach_time.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static double ticks_to_us;
static double now_us(void) { return (double)mach_absolute_time() * ticks_to_us; }
static void warmup(void) { double t0 = now_us(); volatile double x = 1.0; while (now_us() - t0 < 700000.0) { int k; for (k = 0; k < 1000; k++) x = x * 1.0000001 + 0.5; } }
static int cmp_d(const void *a, const void *b) { double x = *(const double *)a, y = *(const double *)b; return x < y ? -1 : x > y; }

static void report_metric(const char *name, double *s, int n) {
    qsort(s, n, sizeof(double), cmp_d);
    printf("METRIC %s n=%d min_us=%.2f p10_us=%.2f median_us=%.2f p90_us=%.2f max_us=%.2f\n", name, n, s[0], s[(int)(n * 0.1)], s[n / 2], s[(int)(n * 0.9)], s[n - 1]);
}

static CGLContextObj setup(int w, int h, CGLPBufferObj *pbuf_out) {
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
    if (err || npix == 0 || !pf) { fprintf(stderr, "ChoosePixelFormat failed\n"); exit(1); }
    CGLContextObj ctx = NULL; err = CGLCreateContext(pf, NULL, &ctx);
    if (err) { fprintf(stderr, "CreateContext failed\n"); exit(1); }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf = NULL; err = CGLCreatePBuffer(w, h, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { fprintf(stderr, "CreatePBuffer failed\n"); exit(1); }
    err = CGLSetCurrentContext(ctx); if (err) { fprintf(stderr, "SetCurrentContext failed\n"); exit(1); }
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, 0); if (err) { fprintf(stderr, "SetPBuffer failed\n"); exit(1); }
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glColor3f(1,1,1);
    *pbuf_out = pbuf;
    return ctx;
}

static void teardown(CGLContextObj ctx, CGLPBufferObj pbuf) {
    CGLSetCurrentContext(NULL);
    CGLDestroyContext(ctx);
    CGLDestroyPBuffer(pbuf);
}

int main(int argc, char **argv) {
    int N = argc > 1 ? atoi(argv[1]) : 200, warm = 5, i;
    mach_timebase_info_data_t tb; double *samp;
    mach_timebase_info(&tb); ticks_to_us = (double)tb.numer / tb.denom / 1000.0;
    setvbuf(stdout, NULL, _IONBF, 0);
    samp = malloc(N * sizeof(double));

    printf("perf_gl_scale: %d iterations/metric, timer tick %.4f us\n", N, ticks_to_us);

    /* viewport scale: a fullscreen-covering flat-color quad at increasing pbuffer sizes */
    {
        int sizes[4] = {64, 256, 512, 1024};
        const char *names[4] = {"gl.scale.fullscreenquad.64x64", "gl.scale.fullscreenquad.256x256", "gl.scale.fullscreenquad.512x512", "gl.scale.fullscreenquad.1024x1024"};
        int s;
        for (s = 0; s < 4; s++) {
            CGLPBufferObj pbuf; CGLContextObj ctx = setup(sizes[s], sizes[s], &pbuf);
            warmup();
            for (i = 0; i < warm; i++) { glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd(); glFinish(); }
            for (i = 0; i < N; i++) {
                double t0 = now_us();
                glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
                glFinish();
                double t1 = now_us(); samp[i] = t1 - t0;
            }
            report_metric(names[s], samp, N);
            teardown(ctx, pbuf);
        }
    }

    /* texture size scale: a fullscreen textured quad sampling increasingly large textures, fixed 256x256 viewport */
    {
        int texsizes[4] = {16, 64, 256, 512};
        const char *names[4] = {"gl.scale.texsample.16x16", "gl.scale.texsample.64x64", "gl.scale.texsample.256x256", "gl.scale.texsample.512x512"};
        int s;
        CGLPBufferObj pbuf; CGLContextObj ctx = setup(256, 256, &pbuf);
        for (s = 0; s < 4; s++) {
            int ts = texsizes[s];
            GLubyte *data = malloc(ts*ts*4);
            int px; for (px=0;px<ts*ts;px++) { data[px*4]=px&0xff; data[px*4+1]=0x80; data[px*4+2]=0x40; data[px*4+3]=255; }
            GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,ts,ts,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
            glEnable(GL_TEXTURE_2D);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
            warmup();
            for (i = 0; i < warm; i++) { glBegin(GL_QUADS); glTexCoord2f(0,0); glVertex2f(-1,-1); glTexCoord2f(1,0); glVertex2f(1,-1); glTexCoord2f(1,1); glVertex2f(1,1); glTexCoord2f(0,1); glVertex2f(-1,1); glEnd(); glFinish(); }
            for (i = 0; i < N; i++) {
                double t0 = now_us();
                glBegin(GL_QUADS); glTexCoord2f(0,0); glVertex2f(-1,-1); glTexCoord2f(1,0); glVertex2f(1,-1); glTexCoord2f(1,1); glVertex2f(1,1); glTexCoord2f(0,1); glVertex2f(-1,1); glEnd();
                glFinish();
                double t1 = now_us(); samp[i] = t1 - t0;
            }
            report_metric(names[s], samp, N);
            glDisable(GL_TEXTURE_2D); glDeleteTextures(1,&t); free(data);
        }
        teardown(ctx, pbuf);
    }

    /* triangle count scale: increasing triangle counts in one draw, fixed 256x256 viewport, flat color */
    {
        int counts[4] = {100, 1000, 5000, 20000};
        const char *names[4] = {"gl.scale.tricount.100", "gl.scale.tricount.1000", "gl.scale.tricount.5000", "gl.scale.tricount.20000"};
        int s;
        CGLPBufferObj pbuf; CGLContextObj ctx = setup(256, 256, &pbuf);
        for (s = 0; s < 4; s++) {
            int tc = counts[s];
            warmup();
            for (i = 0; i < warm; i++) { glBegin(GL_TRIANGLES); int q; for (q=0;q<tc;q++) { glVertex2f(-0.1f,-0.1f); glVertex2f(0.1f,-0.1f); glVertex2f(0,0.1f); } glEnd(); glFinish(); }
            for (i = 0; i < N; i++) {
                double t0 = now_us();
                glBegin(GL_TRIANGLES); int q; for (q=0;q<tc;q++) { glVertex2f(-0.1f,-0.1f); glVertex2f(0.1f,-0.1f); glVertex2f(0,0.1f); } glEnd();
                glFinish();
                double t1 = now_us(); samp[i] = t1 - t0;
            }
            report_metric(names[s], samp, N);
        }
        teardown(ctx, pbuf);
    }

    printf("RESULT: PASS\n");
    return 0;
}
