/* perf_gl_pipeline.c - issue #44 follow-up: feature-level costs that are qualitatively different from a
 * per-draw render cost (perf_gl_features.c covers that) - one-shot/setup-phase costs that #128's
 * correctness tests never measured: GLSL shader compile+link time, FBO render-target switch cost, display
 * list compile vs replay vs immediate-mode cost, and VBO-backed vs client-array draw cost (the correctness
 * of VBO draws was confirmed identical in gl_feature_vbo_correctness_test.c - this measures whether using
 * one actually buys anything on this driver, or costs something, since neither was ever measured here).
 *
 * Same methodology as Tests/perf_methods.c / perf_gl_features.c: mach_absolute_time, warmup() burn, N
 * repeated timed operations, p10 headline, same METRIC line format for Tools/perf_compare.py.
 *
 * Usage: perf_gl_pipeline [iterations per metric, default 500]
 * Build:  gcc -arch ppc -std=gnu99 -w -o perf_gl_pipeline perf_gl_pipeline.c -framework OpenGL
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

    printf("perf_gl_pipeline: %d iterations/metric, %dx%d pbuffer, timer tick %.4f us\n", N, W, H, ticks_to_us);

    /* GLSL shader compile+link time - a one-shot cost never measured anywhere in this project before */
    {
        const char *vsrc = "#version 110\nvoid main() { gl_Position = gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; }\n";
        const char *fsrc = "#version 110\nuniform sampler2D tex; uniform vec3 tint;\n"
                            "void main() { vec4 c = texture2D(tex, gl_TexCoord[0].xy); gl_FragColor = vec4(c.rgb * tint, c.a); }\n";
        int cN = N > 200 ? 200 : N;   /* compiling is much more expensive than a draw - cap the sample count */
        for (i = 0; i < warm && i < cN; i++) {
            GLuint vs = glCreateShader(GL_VERTEX_SHADER); glShaderSource(vs, 1, &vsrc, NULL); glCompileShader(vs);
            GLuint fs = glCreateShader(GL_FRAGMENT_SHADER); glShaderSource(fs, 1, &fsrc, NULL); glCompileShader(fs);
            GLuint prog = glCreateProgram(); glAttachShader(prog, vs); glAttachShader(prog, fs); glLinkProgram(prog);
            glDeleteProgram(prog); glDeleteShader(vs); glDeleteShader(fs);
        }
        for (i = 0; i < cN; i++) {
            double t0 = now_us();
            GLuint vs = glCreateShader(GL_VERTEX_SHADER); glShaderSource(vs, 1, &vsrc, NULL); glCompileShader(vs);
            GLuint fs = glCreateShader(GL_FRAGMENT_SHADER); glShaderSource(fs, 1, &fsrc, NULL); glCompileShader(fs);
            GLuint prog = glCreateProgram(); glAttachShader(prog, vs); glAttachShader(prog, fs); glLinkProgram(prog);
            double t1 = now_us(); samp[i] = t1 - t0;
            glDeleteProgram(prog); glDeleteShader(vs); glDeleteShader(fs);
        }
        report_metric("gl.glsl.compile_link", samp, cN);
    }

    /* ARB fragment program parse time (assembly-style, distinct front end from GLSL above) */
    {
        const char *parbody =
            "!!ARBfp1.0\n"
            "TEMP t;\n"
            "TEX t, fragment.texcoord[0], texture[0], 2D;\n"
            "MUL result.color, t, program.local[0];\n"
            "END\n";
        int cN = N > 500 ? 500 : N;
        for (i = 0; i < warm && i < cN; i++) {
            GLuint p; glGenProgramsARB(1,&p); glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB,p);
            glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)strlen(parbody), parbody);
            glDeleteProgramsARB(1,&p);
        }
        for (i = 0; i < cN; i++) {
            GLuint p; glGenProgramsARB(1,&p); glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB,p);
            double t0 = now_us();
            glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)strlen(parbody), parbody);
            double t1 = now_us(); samp[i] = t1 - t0;
            glDeleteProgramsARB(1,&p);
        }
        report_metric("gl.arbfp.parse", samp, cN);
    }

    /* FBO render-target switch cost: bind an FBO, draw nothing, unbind back to the default framebuffer */
    {
        GLuint tex; glGenTextures(1,&tex); glBindTexture(GL_TEXTURE_RECTANGLE_ARB,tex);
        glTexImage2D(GL_TEXTURE_RECTANGLE_ARB,0,GL_RGBA8,32,32,0,GL_RGBA,GL_UNSIGNED_BYTE,NULL);
        GLuint fbo; glGenFramebuffersEXT(1,&fbo);
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo);
        glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_RECTANGLE_ARB, tex, 0);
        GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
        if (status == GL_FRAMEBUFFER_COMPLETE_EXT) {
            for (i = 0; i < warm; i++) { glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo); glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); glFinish(); }
            for (i = 0; i < N; i++) {
                double t0 = now_us();
                glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo);
                glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
                glFinish();
                double t1 = now_us(); samp[i] = t1 - t0;
            }
            report_metric("gl.fbo.bind_unbind_roundtrip", samp, N);
        } else {
            printf("gl.fbo.bind_unbind_roundtrip: SKIPPED (FBO incomplete, status=0x%04x)\n", (unsigned)status);
        }
        glDeleteFramebuffersEXT(1,&fbo); glDeleteTextures(1,&tex);
    }

    /* display list: compile cost, replay cost, vs immediate-mode cost for the identical 100-triangle draw */
    {
        int dN = N;
        for (i = 0; i < warm; i++) {
            GLuint list = glGenLists(1);
            glNewList(list, GL_COMPILE);
            int q; for (q=0;q<100;q++) { glBegin(GL_TRIANGLES); glVertex2f(-0.8f,-0.8f); glVertex2f(0.8f,-0.8f); glVertex2f(0,0.8f); glEnd(); }
            glEndList();
            glDeleteLists(list, 1);
        }
        for (i = 0; i < dN; i++) {
            double t0 = now_us();
            GLuint list = glGenLists(1);
            glNewList(list, GL_COMPILE);
            int q; for (q=0;q<100;q++) { glBegin(GL_TRIANGLES); glVertex2f(-0.8f,-0.8f); glVertex2f(0.8f,-0.8f); glVertex2f(0,0.8f); glEnd(); }
            glEndList();
            double t1 = now_us(); samp[i] = t1 - t0;
            glDeleteLists(list, 1);
        }
        report_metric("gl.displaylist.compile_100tri", samp, dN);

        GLuint list = glGenLists(1);
        glNewList(list, GL_COMPILE);
        int q; for (q=0;q<100;q++) { glBegin(GL_TRIANGLES); glVertex2f(-0.8f,-0.8f); glVertex2f(0.8f,-0.8f); glVertex2f(0,0.8f); glEnd(); }
        glEndList();
        for (i = 0; i < warm; i++) { glCallList(list); glFinish(); }
        for (i = 0; i < dN; i++) { double t0 = now_us(); glCallList(list); glFinish(); double t1 = now_us(); samp[i] = t1 - t0; }
        report_metric("gl.displaylist.replay_100tri", samp, dN);
        glDeleteLists(list, 1);

        for (i = 0; i < warm; i++) { int q2; for (q2=0;q2<100;q2++) { glBegin(GL_TRIANGLES); glVertex2f(-0.8f,-0.8f); glVertex2f(0.8f,-0.8f); glVertex2f(0,0.8f); glEnd(); } glFinish(); }
        for (i = 0; i < dN; i++) {
            double t0 = now_us();
            int q2; for (q2=0;q2<100;q2++) { glBegin(GL_TRIANGLES); glVertex2f(-0.8f,-0.8f); glVertex2f(0.8f,-0.8f); glVertex2f(0,0.8f); glEnd(); }
            glFinish();
            double t1 = now_us(); samp[i] = t1 - t0;
        }
        report_metric("gl.immediate.draw_100tri", samp, dN);
    }

    /* VBO-backed vs client-array draw of the identical 100-triangle workload */
    {
        GLfloat verts[300]; int v; for (v=0; v<300; v+=6) { verts[v]=-0.8f; verts[v+1]=-0.8f; verts[v+2]=0.8f; verts[v+3]=-0.8f; verts[v+4]=0; verts[v+5]=0.8f; }
        glEnableClientState(GL_VERTEX_ARRAY);

        glVertexPointer(2, GL_FLOAT, 0, verts);
        for (i = 0; i < warm; i++) { glDrawArrays(GL_TRIANGLES, 0, 150); glFinish(); }
        for (i = 0; i < N; i++) { double t0 = now_us(); glDrawArrays(GL_TRIANGLES, 0, 150); glFinish(); double t1 = now_us(); samp[i] = t1 - t0; }
        report_metric("gl.client_array.draw_100tri", samp, N);

        GLuint vbuf; glGenBuffersARB(1,&vbuf); glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbuf);
        glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(verts), verts, GL_STATIC_DRAW_ARB);
        glVertexPointer(2, GL_FLOAT, 0, (void*)0);
        for (i = 0; i < warm; i++) { glDrawArrays(GL_TRIANGLES, 0, 150); glFinish(); }
        for (i = 0; i < N; i++) { double t0 = now_us(); glDrawArrays(GL_TRIANGLES, 0, 150); glFinish(); double t1 = now_us(); samp[i] = t1 - t0; }
        report_metric("gl.vbo.draw_100tri", samp, N);
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
        glDeleteBuffersARB(1,&vbuf);
        glDisableClientState(GL_VERTEX_ARRAY);
    }

    printf("RESULT: PASS\n");
    return 0;
}
