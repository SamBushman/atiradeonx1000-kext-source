/* perf_baseline.c - issue #44: a first real timing baseline of the STOCK driver's basic operations,
 * captured on the actual test hardware (G5, ATI Radeon X1900) before any rebuilt kext ever runs. Purely
 * additive to Tests/userspace/cgl_probe.c's sequence - no new risk, just timing what already runs safely.
 * Repeats each phase N times and reports min/median/max (not just one sample) per the issue's own
 * criterion 5 (distinguish noise from a real regression via repeated runs, not a single measurement).
 *
 * Usage: perf_baseline [iterations, default 20]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 256
#define H 256

static double now_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
}

static void stats(const char *label, double *samples, int n) {
    /* simple insertion sort - n is small */
    int i, j;
    for (i = 1; i < n; i++) {
        double key = samples[i];
        j = i - 1;
        while (j >= 0 && samples[j] > key) { samples[j + 1] = samples[j]; j--; }
        samples[j + 1] = key;
    }
    double sum = 0;
    for (i = 0; i < n; i++) sum += samples[i];
    printf("%-24s min=%.3fms median=%.3fms max=%.3fms mean=%.3fms (n=%d)\n",
           label, samples[0], samples[n / 2], samples[n - 1], sum / n, n);
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    int N = argc > 1 ? atoi(argv[1]) : 20;
    double *t_choose = malloc(N * sizeof(double));
    double *t_create = malloc(N * sizeof(double));
    double *t_pbuffer = malloc(N * sizeof(double));
    double *t_clear = malloc(N * sizeof(double));
    double *t_draw = malloc(N * sizeof(double));
    double *t_readback = malloc(N * sizeof(double));
    double *t_teardown = malloc(N * sizeof(double));
    static GLubyte buf[W * H * 4];

    CGLPixelFormatAttribute attrs[] = {
        kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0
    };

    for (int i = 0; i < N; i++) {
        double t0, t1;
        CGLPixelFormatObj pf; GLint npix = 0;
        t0 = now_ms();
        CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
        t1 = now_ms(); t_choose[i] = t1 - t0;
        if (err || npix == 0) { fprintf(stderr, "ChoosePixelFormat failed at iter %d\n", i); return 1; }

        CGLContextObj ctx = NULL;
        t0 = now_ms();
        err = CGLCreateContext(pf, NULL, &ctx);
        t1 = now_ms(); t_create[i] = t1 - t0;
        CGLDestroyPixelFormat(pf);
        if (err) { fprintf(stderr, "CreateContext failed at iter %d\n", i); return 1; }

        CGLPBufferObj pbuf = NULL;
        err = CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
        if (err) { fprintf(stderr, "CreatePBuffer failed at iter %d\n", i); return 1; }
        CGLSetCurrentContext(ctx);
        t0 = now_ms();
        err = CGLSetPBuffer(ctx, pbuf, 0, 0, 0);
        t1 = now_ms(); t_pbuffer[i] = t1 - t0;
        if (err) { fprintf(stderr, "SetPBuffer failed at iter %d\n", i); return 1; }

        glViewport(0, 0, W, H);
        t0 = now_ms();
        glClearColor(0.25f, 0.5f, 0.75f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glFlush();
        t1 = now_ms(); t_clear[i] = t1 - t0;

        glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1, 1, -1, 1, -1, 1);
        glMatrixMode(GL_MODELVIEW); glLoadIdentity();
        t0 = now_ms();
        for (int q = 0; q < 100; q++) {
            glBegin(GL_TRIANGLES);
            glColor3f(1, 0, 0); glVertex2f(-0.8f, -0.8f);
            glColor3f(0, 1, 0); glVertex2f(0.8f, -0.8f);
            glColor3f(0, 0, 1); glVertex2f(0.0f, 0.8f);
            glEnd();
        }
        glFlush();
        t1 = now_ms(); t_draw[i] = t1 - t0;

        t0 = now_ms();
        glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        t1 = now_ms(); t_readback[i] = t1 - t0;

        t0 = now_ms();
        CGLSetCurrentContext(NULL);
        CGLDestroyContext(ctx);
        CGLDestroyPBuffer(pbuf);
        t1 = now_ms(); t_teardown[i] = t1 - t0;
    }

    printf("perf_baseline: %d iterations, %dx%d pbuffer, 100 triangles/draw phase\n", N, W, H);
    stats("ChoosePixelFormat", t_choose, N);
    stats("CreateContext", t_create, N);
    stats("SetPBuffer", t_pbuffer, N);
    stats("Clear+Flush", t_clear, N);
    stats("Draw100Tri+Flush", t_draw, N);
    stats("ReadPixels", t_readback, N);
    stats("Teardown", t_teardown, N);
    printf("RESULT: PASS\n");
    return 0;
}
