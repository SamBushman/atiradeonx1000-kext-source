/* gl_feature_glsl_varying_test.c - issue #128: GLSL varying interpolation RUNTIME correctness (GL 1.5/GLSL 1.10
 * sec 7.3): a varying written per-vertex in the vertex shader must be linearly interpolated (perspective-correct, but
 * here with an orthographic projection so perspective-correct and screen-space linear coincide) across the primitive
 * for the fragment shader to read. Three triangle vertices carry three very different scalar values; sampled at the
 * triangle's centroid, where the expected interpolated value is exactly the arithmetic mean of the three (equal
 * barycentric weights at the centroid). */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

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
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    const char *vsrc =
        "#version 110\nattribute float aVal;\nvarying float vVal;\n"
        "void main() { vVal = aVal; gl_Position = gl_Vertex; }\n";
    const char *fsrc = "#version 110\nvarying float vVal;\nvoid main() { gl_FragColor = vec4(vVal, 0.0, 0.0, 1.0); }\n";
    GLuint vs = glCreateShader(GL_VERTEX_SHADER); glShaderSource(vs, 1, &vsrc, NULL); glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER); glShaderSource(fs, 1, &fsrc, NULL); glCompileShader(fs);
    GLint ok; char log[1024];
    glGetShaderiv(vs, GL_COMPILE_STATUS, &ok); if (!ok) { glGetShaderInfoLog(vs, sizeof log, NULL, log); printf("vs build failed: %s\n", log); return 1; }
    glGetShaderiv(fs, GL_COMPILE_STATUS, &ok); if (!ok) { glGetShaderInfoLog(fs, sizeof log, NULL, log); printf("fs build failed: %s\n", log); return 1; }
    GLuint prog = glCreateProgram(); glAttachShader(prog, vs); glAttachShader(prog, fs);
    glLinkProgram(prog);
    glGetProgramiv(prog, GL_LINK_STATUS, &ok); if (!ok) { glGetProgramInfoLog(prog, sizeof log, NULL, log); printf("link failed: %s\n", log); return 1; }
    glUseProgram(prog);
    GLint loc = glGetAttribLocation(prog, "aVal");

    /* a triangle covering most of the viewport, vertices carrying 0.1, 0.5, 0.9; sample near the centroid where the
     * expected interpolated value is the mean (0.1+0.5+0.9)/3 = 0.5 */
    float verts[] = {-0.9f,-0.9f, 0.9f,-0.9f, 0.0f,0.9f};
    float vals[] = {0.1f, 0.5f, 0.9f};
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 1, GL_FLOAT, GL_FALSE, 0, vals);

    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glFinish();
    static GLubyte buf[64 * 64 * 4];
    glReadPixels(0, 0, 64, 64, GL_RGBA, GL_UNSIGNED_BYTE, buf);

    /* centroid of (-0.9,-0.9),(0.9,-0.9),(0,0.9) in object space = (0, -0.3); map to window coords with this ortho+viewport */
    int cx = (int)((0.0f + 1.0f) * 0.5f * 64.0f);
    int cy = (int)((-0.3f + 1.0f) * 0.5f * 64.0f);
    GLubyte *p = buf + (cy * 64 + cx) * 4;
    float want = (vals[0] + vals[1] + vals[2]) / 3.0f;
    int wantb = (int)(want * 255.0f + 0.5f);
    int ok2 = abs((int)p[0] - wantb) <= 10;   /* generous tolerance: "near the centroid" is not pixel-exact for the sample point */
    printf("centroid (%d,%d): got %d want ~%d (mean of 0.1,0.5,0.9) %s\n", cx, cy, p[0], wantb, ok2 ? "OK" : "MISMATCH");

    /* also confirm the three CORNERS individually carry close to their own vertex value, not some constant/averaged value everywhere */
    int corner_ok = 1;
    struct { float ox, oy, want; } corners[] = {
        {-0.85f,-0.85f, 0.1f}, {0.85f,-0.85f, 0.5f}, {0.0f, 0.85f, 0.9f}
    };
    int i;
    for (i = 0; i < 3; i++) {
        int x = (int)((corners[i].ox + 1.0f) * 0.5f * 64.0f);
        int y = (int)((corners[i].oy + 1.0f) * 0.5f * 64.0f);
        GLubyte *pc = buf + (y * 64 + x) * 4;
        int wb = (int)(corners[i].want * 255.0f + 0.5f);
        int cok = abs((int)pc[0] - wb) <= 25;
        printf("near corner %d (%d,%d): got %d want ~%d %s\n", i, x, y, pc[0], wb, cok ? "OK" : "MISMATCH");
        if (!cok) corner_ok = 0;
    }

    int bad = (!ok2) + (!corner_ok);
    printf("RESULT: %s (%d mismatches)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
