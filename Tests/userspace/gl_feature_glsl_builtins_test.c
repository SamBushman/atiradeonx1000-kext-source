/* gl_feature_glsl_builtins_test.c - issue #128: GLSL 1.10 built-in function RUNTIME correctness, distinct from the
 * existing compiler-fidelity tests (which check the COMPILER produces the same ARB stream as stock, not that the
 * resulting program renders correctly). Each case: a fragment shader computes one built-in on constant/uniform inputs
 * and writes it to gl_FragColor; the expected value is computed independently in C (not a hand-derived constant) and
 * compared to the readback with a small float-to-8-bit tolerance. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

static float clamp01(float x) { return x < 0 ? 0 : x > 1 ? 1 : x; }

static int run_case(const char *name, const char *fsrc, float wr, float wg, float wb, float tol) {
    char log[1024];
    wr = clamp01(wr); wg = clamp01(wg); wb = clamp01(wb);   /* the fragment output is clamped to [0,1] by the hardware before becoming a byte - the expected value must be too */
    GLuint prog = build(fsrc, log, sizeof log);
    if (!prog) { printf("%-28s BUILD FAILED: %.300s\n", name, log); return 1; }
    glUseProgram(prog);
    float verts[] = {-1,-1, 1,-1, 1,1, -1,1};
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glEnableClientState(GL_VERTEX_ARRAY);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_QUADS, 0, 4);
    glFinish();
    static GLubyte buf[32 * 32 * 4];
    glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    GLubyte *p = buf + (16 * 32 + 16) * 4;
    int wR = (int)(wr * 255.0f + 0.5f), wG = (int)(wg * 255.0f + 0.5f), wB = (int)(wb * 255.0f + 0.5f);
    int tolb = (int)(tol * 255.0f + 1.0f);
    int ok = abs((int)p[0] - wR) <= tolb && abs((int)p[1] - wG) <= tolb && abs((int)p[2] - wB) <= tolb;
    printf("%-28s got %3d,%3d,%3d want %3d,%3d,%3d %s\n", name, p[0], p[1], p[2], wR, wG, wB, ok ? "OK" : "MISMATCH");
    glUseProgram(0); glDeleteProgram(prog);
    return ok ? 0 : 1;
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

    int bad = 0;
    float a[3] = {3.0f, 4.0f, 0.0f};              /* a 3-4-5 vector, convenient exact length/normalize */
    float la = sqrtf(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);
    float na[3] = {a[0]/la, a[1]/la, a[2]/la};
    float b[3] = {0.0f, 1.0f, 0.0f};
    float dotab = a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
    float crossab[3] = { a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0] };

    char fs[1024];

    snprintf(fs, sizeof fs, "#version 110\nvoid main() { gl_FragColor = vec4(length(vec3(%.6f,%.6f,%.6f))/10.0, 0.0, 0.0, 1.0); }\n", a[0], a[1], a[2]);
    bad += run_case("length(3,4,0)/10", fs, la/10.0f, 0, 0, 0.01f);

    snprintf(fs, sizeof fs, "#version 110\nvoid main() { vec3 n = normalize(vec3(%.6f,%.6f,%.6f)); gl_FragColor = vec4(n.x*0.5+0.5, n.y*0.5+0.5, n.z*0.5+0.5, 1.0); }\n", a[0], a[1], a[2]);
    bad += run_case("normalize(3,4,0)", fs, na[0]*0.5f+0.5f, na[1]*0.5f+0.5f, na[2]*0.5f+0.5f, 0.02f);

    snprintf(fs, sizeof fs, "#version 110\nvoid main() { float d = dot(vec3(%.6f,%.6f,%.6f), vec3(%.6f,%.6f,%.6f)); gl_FragColor = vec4(d*0.5+0.5, 0.0, 0.0, 1.0); }\n",
             a[0], a[1], a[2], b[0], b[1], b[2]);
    bad += run_case("dot((3,4,0),(0,1,0))", fs, dotab*0.5f+0.5f, 0, 0, 0.02f);

    snprintf(fs, sizeof fs, "#version 110\nvoid main() { vec3 c = cross(vec3(%.6f,%.6f,%.6f), vec3(%.6f,%.6f,%.6f)); gl_FragColor = vec4(c.x*0.1+0.5, c.y*0.1+0.5, c.z*0.1+0.5, 1.0); }\n",
             a[0], a[1], a[2], b[0], b[1], b[2]);
    bad += run_case("cross((3,4,0),(0,1,0))", fs, crossab[0]*0.1f+0.5f, crossab[1]*0.1f+0.5f, crossab[2]*0.1f+0.5f, 0.02f);

    bad += run_case("pow(0.5,3.0)", "#version 110\nvoid main() { gl_FragColor = vec4(pow(0.5, 3.0), 0.0, 0.0, 1.0); }\n", powf(0.5f, 3.0f), 0, 0, 0.01f);
    bad += run_case("mix(0.2,0.8,0.25)", "#version 110\nvoid main() { gl_FragColor = vec4(mix(0.2, 0.8, 0.25), 0.0, 0.0, 1.0); }\n", 0.2f + (0.8f-0.2f)*0.25f, 0, 0, 0.01f);
    bad += run_case("clamp(1.5,0,1)", "#version 110\nvoid main() { gl_FragColor = vec4(clamp(1.5, 0.0, 1.0), 0.0, 0.0, 1.0); }\n", 1.0f, 0, 0, 0.01f);
    bad += run_case("floor(3.7)/4", "#version 110\nvoid main() { gl_FragColor = vec4(floor(3.7)/4.0, 0.0, 0.0, 1.0); }\n", floorf(3.7f)/4.0f, 0, 0, 0.01f);
    bad += run_case("mod(5.5,2.0)/4", "#version 110\nvoid main() { gl_FragColor = vec4(mod(5.5, 2.0)/4.0, 0.0, 0.0, 1.0); }\n", fmodf(5.5f, 2.0f)/4.0f, 0, 0, 0.01f);
    bad += run_case("step(0.5,0.3 vs 0.7)", "#version 110\nvoid main() { gl_FragColor = vec4(step(0.5, 0.3), step(0.5, 0.7), 0.0, 1.0); }\n", 0.0f, 1.0f, 0, 0.01f);
    {
        /* reflect(I, N) = I - 2*dot(N,I)*N, with I=(1,-1,0) hitting a flat normal (0,1,0) */
        float I[3] = {1,-1,0}, N[3] = {0,1,0};
        float d = I[0]*N[0]+I[1]*N[1]+I[2]*N[2];
        float R[3] = { I[0]-2*d*N[0], I[1]-2*d*N[1], I[2]-2*d*N[2] };
        bad += run_case("reflect((1,-1,0),(0,1,0))", "#version 110\nvoid main() { vec3 r = reflect(vec3(1.0,-1.0,0.0), vec3(0.0,1.0,0.0)); gl_FragColor = vec4(r.x*0.25+0.5, r.y*0.25+0.5, r.z*0.25+0.5, 1.0); }\n",
                         R[0]*0.25f+0.5f, R[1]*0.25f+0.5f, R[2]*0.25f+0.5f, 0.02f);
    }

    printf("RESULT: %s (%d mismatches)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
