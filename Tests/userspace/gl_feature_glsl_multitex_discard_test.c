/* gl_feature_glsl_multitex_discard_test.c - issue #128: GLSL multi-sampler RUNTIME correctness (two texture units read
 * in ONE fragment shader, combined by a known formula) and the `discard` keyword's exact effect (a discarded fragment
 * must not write colour OR depth - checked by discarding half a quad and confirming the background shows through
 * there, unmodified, while the other half is overwritten). */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

static GLuint build(const char *vsrc, const char *fsrc, char *log, int logsz) {
    GLuint vs = glCreateShader(GL_VERTEX_SHADER); glShaderSource(vs, 1, &vsrc, NULL); glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER); glShaderSource(fs, 1, &fsrc, NULL); glCompileShader(fs);
    GLint ok;
    glGetShaderiv(vs, GL_COMPILE_STATUS, &ok); if (!ok) { glGetShaderInfoLog(vs, logsz, NULL, log); return 0; }
    glGetShaderiv(fs, GL_COMPILE_STATUS, &ok); if (!ok) { glGetShaderInfoLog(fs, logsz, NULL, log); return 0; }
    GLuint prog = glCreateProgram();
    glAttachShader(prog, vs); glAttachShader(prog, fs);
    glLinkProgram(prog);
    glGetProgramiv(prog, GL_LINK_STATUS, &ok);
    if (!ok) { glGetProgramInfoLog(prog, logsz, NULL, log); return 0; }
    return prog;
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
    if (err || npix == 0 || !pf) { die("ChoosePixelFormat", err); return 1; }
    CGLContextObj ctx = NULL;
    err = CGLCreateContext(pf, NULL, &ctx);
    if (err) { die("CreateContext", err); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf = NULL;
    err = CGLCreatePBuffer(64, 64, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }
    glViewport(0, 0, 64, 64);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    char log[1024];
    int bad = 0;

    /* multi-sampler: tex0 = red 0.8, tex1 = green 0.3; shader outputs tex0.r + tex1.g */
    {
        GLuint t0, t1; glGenTextures(1, &t0); glGenTextures(1, &t1);
        GLubyte c0[3] = {204, 0, 0}, c1[3] = {0, 76, 0};   /* 0.8*255, 0.3*255 */
        glBindTexture(GL_TEXTURE_2D, t0); glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, c0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glBindTexture(GL_TEXTURE_2D, t1); glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, c1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        const char *vs = "#version 110\nvoid main() { gl_Position = gl_Vertex; }\n";
        const char *fs = "#version 110\nuniform sampler2D s0;\nuniform sampler2D s1;\nvoid main() { vec4 a = texture2D(s0, vec2(0.5)); vec4 b = texture2D(s1, vec2(0.5)); gl_FragColor = vec4(a.r + b.g, 0.0, 0.0, 1.0); }\n";
        GLuint prog = build(vs, fs, log, sizeof log);
        if (!prog) { printf("multitex: build failed %.200s\n", log); bad++; }
        else {
            glUseProgram(prog);
            glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D, t0); glEnable(GL_TEXTURE_2D);
            glActiveTexture(GL_TEXTURE1); glBindTexture(GL_TEXTURE_2D, t1); glEnable(GL_TEXTURE_2D);
            glUniform1i(glGetUniformLocation(prog, "s0"), 0);
            glUniform1i(glGetUniformLocation(prog, "s1"), 1);
            float verts[] = {-1,-1, 1,-1, 1,1, -1,1};
            glVertexPointer(2, GL_FLOAT, 0, verts); glEnableClientState(GL_VERTEX_ARRAY);
            glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_QUADS, 0, 4);
            glFinish();
            static GLubyte buf[64*64*4]; glReadPixels(0, 0, 64, 64, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            GLubyte *p = buf + (32*64+32)*4;
            int w0 = (int)((0.8f+0.3f)*255.0f+0.5f); if (w0>255) w0=255;
            int ok = abs((int)p[0]-w0) <= 2;
            printf("multi-sampler (0.8r+0.3g)  got %d want %d %s\n", p[0], w0, ok?"OK":"MISMATCH");
            if (!ok) bad++;
            glUseProgram(0); glDeleteProgram(prog);
        }
    }

    /* discard: left half discards, right half writes white; background cleared to a known non-white, non-black colour */
    {
        const char *vs = "#version 110\nvoid main() { gl_Position = gl_Vertex; }\n";
        const char *fs = "#version 110\nvoid main() { if (gl_FragCoord.x < 32.0) discard; gl_FragColor = vec4(1.0,1.0,1.0,1.0); }\n";
        GLuint prog = build(vs, fs, log, sizeof log);
        if (!prog) { printf("discard: build failed %.200s\n", log); bad++; }
        else {
            glUseProgram(prog);
            glDisable(GL_TEXTURE_2D);
            float verts[] = {-1,-1, 1,-1, 1,1, -1,1};
            glVertexPointer(2, GL_FLOAT, 0, verts); glEnableClientState(GL_VERTEX_ARRAY);
            glClearColor(0.2f, 0.4f, 0.6f, 1); glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_QUADS, 0, 4);
            glFinish();
            static GLubyte buf[64*64*4]; glReadPixels(0, 0, 64, 64, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            GLubyte *pl = buf + (32*64+10)*4;   /* left: discarded, background must show through unmodified */
            GLubyte *pr = buf + (32*64+54)*4;   /* right: not discarded, must be white */
            int bgr=51, bgg=102, bgb=153;   /* 0.2,0.4,0.6 * 255 */
            int left_ok = abs((int)pl[0]-bgr)<=2 && abs((int)pl[1]-bgg)<=2 && abs((int)pl[2]-bgb)<=2;
            int right_ok = pr[0]==255 && pr[1]==255 && pr[2]==255;
            printf("discard left (want background %d,%d,%d): got %d,%d,%d %s\n", bgr,bgg,bgb, pl[0],pl[1],pl[2], left_ok?"OK":"MISMATCH");
            printf("discard right (want white):              got %d,%d,%d %s\n", pr[0],pr[1],pr[2], right_ok?"OK":"MISMATCH");
            if (!left_ok) bad++;
            if (!right_ok) bad++;
            glUseProgram(0); glDeleteProgram(prog);
        }
    }

    printf("RESULT: %s (%d mismatches)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
