/* gl_feature_glsl_uniform_test.c - issue #128: GLSL uniform RUNTIME correctness across several types (float, vec3,
 * mat4, int/bool, float array) - each uploaded via its real glUniform* entry point and read back through rendering,
 * compared against the exact value this program itself sent, not a hand-derived constant. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

static GLuint build(const char *fsrc, char *log, int logsz) {
    const char *vsrc = "#version 110\nvoid main() { gl_Position = gl_Vertex; }\n";
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
static void draw_and_read(GLubyte *out) {
    float verts[] = {-1,-1, 1,-1, 1,1, -1,1};
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glEnableClientState(GL_VERTEX_ARRAY);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_QUADS, 0, 4);
    glFinish();
    static GLubyte buf[32*32*4];
    glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    GLubyte *p = buf + (16*32+16)*4;
    out[0]=p[0]; out[1]=p[1]; out[2]=p[2]; out[3]=p[3];
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
    err = CGLCreatePBuffer(32, 32, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }
    glViewport(0, 0, 32, 32);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    char log[1024];
    GLubyte out[4];
    int bad = 0;

    /* float + vec3 uniform */
    {
        GLuint prog = build("#version 110\nuniform float fu;\nuniform vec3 vu;\nvoid main() { gl_FragColor = vec4(fu, vu.g, vu.b, 1.0); }\n", log, sizeof log);
        if (!prog) { printf("float/vec3: build failed %.200s\n", log); bad++; }
        else {
            glUseProgram(prog);
            glUniform1f(glGetUniformLocation(prog, "fu"), 0.6f);
            glUniform3f(glGetUniformLocation(prog, "vu"), 0.1f, 0.4f, 0.8f);
            draw_and_read(out);
            int w0=(int)(0.6f*255+0.5f), w1=(int)(0.4f*255+0.5f), w2=(int)(0.8f*255+0.5f);
            int ok = abs(out[0]-w0)<=2 && abs(out[1]-w1)<=2 && abs(out[2]-w2)<=2;
            printf("uniform1f+uniform3f    got %d,%d,%d want %d,%d,%d %s\n", out[0],out[1],out[2], w0,w1,w2, ok?"OK":"MISMATCH");
            if (!ok) bad++;
            glUseProgram(0); glDeleteProgram(prog);
        }
    }
    /* mat4 uniform: build a pure-scale matrix, multiply a known vector, encode result */
    {
        GLuint prog = build("#version 110\nuniform mat4 mu;\nvoid main() { vec4 v = mu * vec4(0.5,0.25,0.0,1.0); gl_FragColor = vec4(v.x, v.y, 0.0, 1.0); }\n", log, sizeof log);
        if (!prog) { printf("mat4: build failed %.200s\n", log); bad++; }
        else {
            glUseProgram(prog);
            /* column-major scale(2,3,1) */
            float m[16] = {2,0,0,0,  0,3,0,0,  0,0,1,0,  0,0,0,1};
            glUniformMatrix4fv(glGetUniformLocation(prog, "mu"), 1, GL_FALSE, m);
            draw_and_read(out);
            float ex = 0.5f*2.0f, ey = 0.25f*3.0f;   /* 1.0, 0.75 */
            int w0=(int)(ex*255+0.5f), w1=(int)(ey*255+0.5f); if (w0>255) w0=255;
            int ok = abs(out[0]-w0)<=2 && abs(out[1]-w1)<=2;
            printf("uniformMatrix4fv       got %d,%d want %d,%d %s\n", out[0],out[1], w0,w1, ok?"OK":"MISMATCH");
            if (!ok) bad++;
            glUseProgram(0); glDeleteProgram(prog);
        }
    }
    /* bool + int uniform */
    {
        GLuint prog = build("#version 110\nuniform bool bu;\nuniform int iu;\nvoid main() { float r = bu ? 1.0 : 0.0; float g = float(iu)/10.0; gl_FragColor = vec4(r, g, 0.0, 1.0); }\n", log, sizeof log);
        if (!prog) { printf("bool/int: build failed %.200s\n", log); bad++; }
        else {
            glUseProgram(prog);
            glUniform1i(glGetUniformLocation(prog, "bu"), 1);
            glUniform1i(glGetUniformLocation(prog, "iu"), 7);
            draw_and_read(out);
            int w0=255, w1=(int)(0.7f*255+0.5f);
            int ok = abs(out[0]-w0)<=2 && abs(out[1]-w1)<=2;
            printf("uniform1i (bool+int)   got %d,%d want %d,%d %s\n", out[0],out[1], w0,w1, ok?"OK":"MISMATCH");
            if (!ok) bad++;
            glUseProgram(0); glDeleteProgram(prog);
        }
    }
    /* float array uniform */
    {
        GLuint prog = build("#version 110\nuniform float arr[4];\nvoid main() { gl_FragColor = vec4(arr[0], arr[2], 0.0, 1.0); }\n", log, sizeof log);
        if (!prog) { printf("array: build failed %.200s\n", log); bad++; }
        else {
            glUseProgram(prog);
            float a[4] = {0.3f, 0.5f, 0.7f, 0.9f};
            glUniform1fv(glGetUniformLocation(prog, "arr"), 4, a);
            draw_and_read(out);
            int w0=(int)(a[0]*255+0.5f), w1=(int)(a[2]*255+0.5f);
            int ok = abs(out[0]-w0)<=2 && abs(out[1]-w1)<=2;
            printf("uniform1fv (array[4])  got %d,%d want %d,%d %s\n", out[0],out[1], w0,w1, ok?"OK":"MISMATCH");
            if (!ok) bad++;
            glUseProgram(0); glDeleteProgram(prog);
        }
    }

    printf("RESULT: %s (%d mismatches)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
