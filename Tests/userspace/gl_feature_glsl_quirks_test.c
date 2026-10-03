/* gl_feature_glsl_quirks_test.c - issue #128: regression checks for already-documented GLSL compiler behaviour on this
 * exact driver (~/.claude/skills/ati-x1900-driver-quirks skill, quirks 7, 10, 13) - re-verifying known, real driver
 * limits so a future change (including a rebuilt driver) is checked against the SAME documented facts, not just
 * "did it compile with no error" in general.
 *   quirk 7:  #version 110 compiles; #version 120 is rejected outright (GLSL version ceiling is 1.10 on this driver).
 *   quirk 10: a mat3(mat4_expr) matrix-from-matrix constructor is rejected under #version 110 (spec-correct: GLSL 1.10
 *             reserves this construction) - checked as "fails to compile", not a bug, matching the skill's own framing.
 *   quirk 13: gl_PointCoord is undeclared under #version 110 (added in GLSL 1.20) - also spec-correct for this version,
 *             checked the same way. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

static int compiles(const char *src, GLenum type, char *log, int logsz) {
    GLuint sh = glCreateShader(type);
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

    /* quirk 7: #version 110 compiles */
    {
        const char *src = "#version 110\nvoid main() { gl_Position = ftransform(); }\n";
        int ok = compiles(src, GL_VERTEX_SHADER, log, sizeof log);
        printf("quirk7 #version 110 compiles:   %s (want yes) log=%.80s\n", ok ? "yes" : "no", log);
        if (!ok) bad++;
    }
    /* quirk 7: #version 120 is rejected */
    {
        const char *src = "#version 120\nvoid main() { gl_Position = ftransform(); }\n";
        int ok = compiles(src, GL_VERTEX_SHADER, log, sizeof log);
        printf("quirk7 #version 120 rejected:   %s (want yes, i.e. compile failed) log=%.80s\n", !ok ? "yes" : "no", log);
        if (ok) bad++;
    }
    /* quirk 10: mat3(mat4) is rejected under #version 110 */
    {
        const char *src = "#version 110\nvoid main() { mat4 m = gl_ModelViewMatrix; mat3 n = mat3(m); gl_Position = vec4(n[0], 1.0); }\n";
        int ok = compiles(src, GL_VERTEX_SHADER, log, sizeof log);
        printf("quirk10 mat3(mat4) rejected:    %s (want yes, i.e. compile failed) log=%.80s\n", !ok ? "yes" : "no", log);
        if (ok) bad++;
    }
    /* quirk 13: gl_PointCoord is undeclared under #version 110 */
    {
        const char *src = "#version 110\nvoid main() { gl_FragColor = vec4(gl_PointCoord, 0.0, 1.0); }\n";
        int ok = compiles(src, GL_FRAGMENT_SHADER, log, sizeof log);
        printf("quirk13 gl_PointCoord rejected: %s (want yes, i.e. compile failed) log=%.80s\n", !ok ? "yes" : "no", log);
        if (ok) bad++;
    }
    printf("RESULT: %s (%d mismatches of 4 checks)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
