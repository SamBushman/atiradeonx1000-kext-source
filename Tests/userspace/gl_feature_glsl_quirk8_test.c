/* gl_feature_glsl_quirk8_test.c - issue #128: regression check for a documented GLSL preprocessor bug on this driver
 * (~/.claude/skills/ati-x1900-driver-quirks, quirk 8): a variable declared inside a NESTED #if/#ifdef (one conditional
 * inside another) is wrongly reported "undeclared" later in the same scope, even when the branch that declares it is
 * the one actually taken. Checked against the same code with the nesting flattened to a single #if, which must compile
 * cleanly either way - isolating the bug to the NESTING itself, not the conditional declaration pattern in general. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

static int compiles(const char *src, char *log, int logsz) {
    GLuint sh = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sh, 1, &src, NULL);
    glCompileShader(sh);
    GLint ok = 0; glGetShaderiv(sh, GL_COMPILE_STATUS, &ok);
    GLsizei n = 0; glGetShaderInfoLog(sh, logsz - 1, &n, log); log[n] = 0;
    glDeleteShader(sh);
    return ok;
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
    err = CGLCreatePBuffer(16, 16, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }

    char log[1024];
    int bad = 0;

    /* nested conditional: declares x inside an #ifdef inside another #ifdef, the taken branch declares it */
    const char *nested =
        "#version 110\n"
        "#define OUTER 1\n"
        "#define INNER 1\n"
        "void main() {\n"
        "#if OUTER\n"
        "  #if INNER\n"
        "    float x = 1.0;\n"
        "  #endif\n"
        "#endif\n"
        "  gl_FragColor = vec4(x, 0.0, 0.0, 1.0);\n"
        "}\n";
    int nested_ok = compiles(nested, log, sizeof log);
    printf("quirk8 nested #if declaration:    compiles=%s log=%.150s\n", nested_ok ? "yes" : "no", log);

    /* flattened control: same declaration, single #if - must compile cleanly either way */
    const char *flat =
        "#version 110\n"
        "#define BOTH 1\n"
        "void main() {\n"
        "#if BOTH\n"
        "    float x = 1.0;\n"
        "#endif\n"
        "  gl_FragColor = vec4(x, 0.0, 0.0, 1.0);\n"
        "}\n";
    int flat_ok = compiles(flat, log, sizeof log);
    printf("quirk8 flattened #if (control):   compiles=%s log=%.150s (want yes)\n", flat_ok ? "yes" : "no", log);
    if (!flat_ok) bad++;

    printf("quirk8 nested-vs-flat divergence: %s\n", (flat_ok && !nested_ok) ? "BUG REPRODUCES (nested fails, flat OK, as documented)" :
           (flat_ok && nested_ok) ? "bug does NOT reproduce here (both compile)" : "inconclusive (control itself failed)");
    printf("RESULT: %s (checked the control compiles; nested-case outcome reported above, not treated as pass/fail by itself)\n", bad == 0 ? "PASS" : "FAIL");
    return bad ? 1 : 0;
}
