/* perf_gl_statechange.c - issue #44 follow-up: state-change cost, batching benefit, context-switch cost,
 * and occlusion-query/fence round-trip overhead - none measured anywhere in this project before.
 *
 * Same methodology as the other perf_gl_*.c files: mach_absolute_time, warmup, N timed repetitions, p10
 * headline, METRIC line format for Tools/perf_compare.py.
 *
 * Usage: perf_gl_statechange [iterations per metric, default 500]
 * Build:  gcc -arch ppc -std=gnu99 -w -o perf_gl_statechange perf_gl_statechange.c -framework OpenGL
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mach/mach_time.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_SAMPLES_PASSED_ARB
#define GL_SAMPLES_PASSED_ARB 0x8914
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

static void drawquad(void) { glBegin(GL_QUADS); glVertex2f(-0.9f,-0.9f); glVertex2f(0.9f,-0.9f); glVertex2f(0.9f,0.9f); glVertex2f(-0.9f,0.9f); glEnd(); }

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

    printf("perf_gl_statechange: %d iterations/metric, %dx%d pbuffer, timer tick %.4f us\n", N, W, H, ticks_to_us);

    /* texture bind switch cost: 10 draws with the SAME texture bound once, vs 10 draws each re-binding
     * between two different textures - both do 10 real draws, only the bind pattern differs */
    {
        GLuint t0t,t1t; glGenTextures(1,&t0t); glGenTextures(1,&t1t);
        GLubyte px[4] = {255,0,0,255};
        glBindTexture(GL_TEXTURE_2D,t0t); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,px);
        glBindTexture(GL_TEXTURE_2D,t1t); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,px);
        glEnable(GL_TEXTURE_2D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

        glBindTexture(GL_TEXTURE_2D,t0t);
        for (i = 0; i < warm; i++) { int q; for (q=0;q<10;q++) drawquad(); glFinish(); }
        for (i = 0; i < N; i++) { double a0=now_us(); int q; for (q=0;q<10;q++) drawquad(); glFinish(); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.statechange.tex_bind.same_x10", samp, N);

        for (i = 0; i < warm; i++) { int q; for (q=0;q<10;q++) { glBindTexture(GL_TEXTURE_2D, q&1?t1t:t0t); drawquad(); } glFinish(); }
        for (i = 0; i < N; i++) { double a0=now_us(); int q; for (q=0;q<10;q++) { glBindTexture(GL_TEXTURE_2D, q&1?t1t:t0t); drawquad(); } glFinish(); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.statechange.tex_bind.alternate_x10", samp, N);

        glDisable(GL_TEXTURE_2D); glDeleteTextures(1,&t0t); glDeleteTextures(1,&t1t);
    }

    /* GLSL program switch cost: same pattern, same program bound vs alternating between two programs */
    {
        const char *vsrc = "#version 110\nvoid main() { gl_Position = gl_Vertex; }\n";
        const char *fsrc0 = "#version 110\nvoid main() { gl_FragColor = vec4(1.0,0.0,0.0,1.0); }\n";
        const char *fsrc1 = "#version 110\nvoid main() { gl_FragColor = vec4(0.0,1.0,0.0,1.0); }\n";
        GLuint vs = glCreateShader(GL_VERTEX_SHADER); glShaderSource(vs,1,&vsrc,NULL); glCompileShader(vs);
        GLuint fs0 = glCreateShader(GL_FRAGMENT_SHADER); glShaderSource(fs0,1,&fsrc0,NULL); glCompileShader(fs0);
        GLuint fs1 = glCreateShader(GL_FRAGMENT_SHADER); glShaderSource(fs1,1,&fsrc1,NULL); glCompileShader(fs1);
        GLuint p0 = glCreateProgram(); glAttachShader(p0,vs); glAttachShader(p0,fs0); glLinkProgram(p0);
        GLuint p1 = glCreateProgram(); glAttachShader(p1,vs); glAttachShader(p1,fs1); glLinkProgram(p1);

        glUseProgram(p0);
        for (i = 0; i < warm; i++) { int q; for (q=0;q<10;q++) drawquad(); glFinish(); }
        for (i = 0; i < N; i++) { double a0=now_us(); int q; for (q=0;q<10;q++) drawquad(); glFinish(); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.statechange.program.same_x10", samp, N);

        for (i = 0; i < warm; i++) { int q; for (q=0;q<10;q++) { glUseProgram(q&1?p1:p0); drawquad(); } glFinish(); }
        for (i = 0; i < N; i++) { double a0=now_us(); int q; for (q=0;q<10;q++) { glUseProgram(q&1?p1:p0); drawquad(); } glFinish(); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.statechange.program.alternate_x10", samp, N);

        glUseProgram(0);
        glDeleteProgram(p0); glDeleteProgram(p1); glDeleteShader(vs); glDeleteShader(fs0); glDeleteShader(fs1);
    }

    /* blend-state switch cost: same pattern, blend func held constant vs toggled every draw */
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        for (i = 0; i < warm; i++) { int q; for (q=0;q<10;q++) drawquad(); glFinish(); }
        for (i = 0; i < N; i++) { double a0=now_us(); int q; for (q=0;q<10;q++) drawquad(); glFinish(); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.statechange.blendfunc.same_x10", samp, N);

        for (i = 0; i < warm; i++) { int q; for (q=0;q<10;q++) { glBlendFunc(q&1?GL_ONE:GL_SRC_ALPHA, q&1?GL_ZERO:GL_ONE_MINUS_SRC_ALPHA); drawquad(); } glFinish(); }
        for (i = 0; i < N; i++) { double a0=now_us(); int q; for (q=0;q<10;q++) { glBlendFunc(q&1?GL_ONE:GL_SRC_ALPHA, q&1?GL_ZERO:GL_ONE_MINUS_SRC_ALPHA); drawquad(); } glFinish(); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.statechange.blendfunc.alternate_x10", samp, N);
        glDisable(GL_BLEND);
    }

    /* multi-draw-arrays batching: one glMultiDrawArraysEXT covering 10 sub-ranges vs 10 separate glDrawArrays calls, identical total geometry */
    {
        GLfloat verts[10*8];   /* 10 quads of 4 verts x 2 floats, all at the same small spot (content doesn't matter for timing) */
        int q,v; for (q=0;q<10;q++) { float *p = verts + q*8; float ox = 0; p[0]=-0.1f+ox; p[1]=-0.1f; p[2]=0.1f+ox; p[3]=-0.1f; p[4]=0.1f+ox; p[5]=0.1f; p[6]=-0.1f+ox; p[7]=0.1f; }
        glVertexPointer(2, GL_FLOAT, 0, verts);
        glEnableClientState(GL_VERTEX_ARRAY);
        GLint first[10]; GLsizei count[10];
        for (q=0;q<10;q++) { first[q]=q*4; count[q]=4; }

        for (i = 0; i < warm; i++) { for (q=0;q<10;q++) glDrawArrays(GL_QUADS, q*4, 4); glFinish(); }
        for (i = 0; i < N; i++) { double a0=now_us(); for (q=0;q<10;q++) glDrawArrays(GL_QUADS, q*4, 4); glFinish(); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.batching.loop_drawarrays_x10", samp, N);

        for (i = 0; i < warm; i++) { glMultiDrawArraysEXT(GL_QUADS, first, count, 10); glFinish(); }
        for (i = 0; i < N; i++) { double a0=now_us(); glMultiDrawArraysEXT(GL_QUADS, first, count, 10); glFinish(); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.batching.multidrawarrays_x10", samp, N);
        glDisableClientState(GL_VERTEX_ARRAY);
    }

    /* context-switch cost: CGLSetCurrentContext between two live contexts sharing the same pbuffer setup */
    {
        CGLContextObj ctx2 = NULL;
        CGLPixelFormatObj pf2; GLint npix2=0;
        CGLChoosePixelFormat(attrs, &pf2, &npix2);
        CGLCreateContext(pf2, NULL, &ctx2);
        CGLDestroyPixelFormat(pf2);
        CGLPBufferObj pbuf2 = NULL; CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf2);
        CGLSetCurrentContext(ctx2); CGLSetPBuffer(ctx2, pbuf2, 0, 0, 0);
        glViewport(0,0,W,H);

        for (i = 0; i < warm; i++) { CGLSetCurrentContext(ctx); CGLSetCurrentContext(ctx2); }
        for (i = 0; i < N; i++) { double a0=now_us(); CGLSetCurrentContext(ctx); CGLSetCurrentContext(ctx2); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.context_switch.roundtrip", samp, N);

        CGLSetCurrentContext(ctx);
        CGLDestroyContext(ctx2); CGLDestroyPBuffer(pbuf2);
    }

    /* occlusion query round trip: begin/end + fetch result, on a trivially small draw */
    {
        glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LESS); glClearDepth(1.0); glClear(GL_DEPTH_BUFFER_BIT);
        GLuint qid; glGenQueriesARB(1,&qid);
        for (i = 0; i < warm; i++) { GLuint r; glBeginQueryARB(GL_SAMPLES_PASSED_ARB, qid); drawquad(); glEndQueryARB(GL_SAMPLES_PASSED_ARB); glGetQueryObjectuivARB(qid, GL_QUERY_RESULT_ARB, &r); }
        for (i = 0; i < N; i++) { double a0=now_us(); GLuint r; glBeginQueryARB(GL_SAMPLES_PASSED_ARB, qid); drawquad(); glEndQueryARB(GL_SAMPLES_PASSED_ARB); glGetQueryObjectuivARB(qid, GL_QUERY_RESULT_ARB, &r); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.occlusionquery.roundtrip", samp, N);
        glDeleteQueriesARB(1,&qid);
        glDisable(GL_DEPTH_TEST);
    }

    /* APPLE_fence round trip: set + finish, on a trivially small draw */
    {
        GLuint fid; glGenFencesAPPLE(1,&fid);
        for (i = 0; i < warm; i++) { drawquad(); glSetFenceAPPLE(fid); glFinishFenceAPPLE(fid); }
        for (i = 0; i < N; i++) { drawquad(); double a0=now_us(); glSetFenceAPPLE(fid); glFinishFenceAPPLE(fid); double a1=now_us(); samp[i]=a1-a0; }
        report_metric("gl.fence.set_finish_roundtrip", samp, N);
        glDeleteFencesAPPLE(1,&fid);
    }

    printf("RESULT: PASS\n");
    return 0;
}
