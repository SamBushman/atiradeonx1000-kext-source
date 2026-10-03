/* gl_feature_runtime_quirks_test.c - issue #128: regression checks for two already-documented, real runtime driver bugs
 * on this exact driver (~/.claude/skills/ati-x1900-driver-quirks, quirks 1 and 2) - re-verifying known-bad behaviour so
 * a future change (including a rebuilt driver) is checked against the SAME documented facts.
 *   quirk 1: writing a DISABLED generic vertex attribute (constant-broadcast via glVertexAttrib4f, never enabled via
 *            glEnableVertexAttribArray) into a varying corrupts the whole draw's output - checked against the SAME
 *            attribute properly ENABLED with a real per-vertex array, which must render correctly.
 *   quirk 2: a texture2D() call inside a runtime if/else branch voids the fragment's output even when the branch is
 *            never taken at runtime - checked against an identical shader with the texture2D() call removed, which
 *            must render correctly. */
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
    err = CGLCreatePBuffer(32, 32, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }

    glViewport(0, 0, 32, 32);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    char log[1024];
    static GLubyte buf[32 * 32 * 4];
    int bad = 0;

    /* --- quirk 1: disabled-attribute-into-varying --- */
    {
        const char *vs = "#version 110\nattribute vec4 aColor;\nvarying vec4 vColor;\nvoid main() { vColor = aColor; gl_Position = gl_Vertex; }\n";
        const char *fs = "#version 110\nvarying vec4 vColor;\nvoid main() { gl_FragColor = vColor; }\n";
        GLuint prog = build(vs, fs, log, sizeof log);
        if (!prog) { printf("quirk1: build failed: %.200s\n", log); bad++; }
        else {
            GLint loc = glGetAttribLocation(prog, "aColor");
            glUseProgram(prog);
            float verts[] = {-1,-1, 1,-1, 1,1, -1,1};

            /* enabled case: real per-vertex array, should render correctly (green) */
            glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
            float colarr[4 * 4]; int k; for (k = 0; k < 4; k++) { colarr[k*4]=0; colarr[k*4+1]=1; colarr[k*4+2]=0; colarr[k*4+3]=1; }
            glEnableVertexAttribArray(loc);
            glVertexAttribPointer(loc, 4, GL_FLOAT, GL_FALSE, 0, colarr);
            glVertexPointer(2, GL_FLOAT, 0, verts);
            glEnableClientState(GL_VERTEX_ARRAY);
            glDrawArrays(GL_QUADS, 0, 4);
            glFinish(); glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            GLubyte *pe = buf + (16 * 32 + 16) * 4;
            int enabled_ok = (pe[0] == 0 && pe[1] == 255 && pe[2] == 0);
            printf("quirk1 ENABLED attribute:  got %d,%d,%d want 0,255,0 %s\n", pe[0], pe[1], pe[2], enabled_ok ? "OK" : "MISMATCH");

            /* disabled case: constant broadcast, never enabled - per the known bug, the draw must be corrupted (not green) */
            glDisableVertexAttribArray(loc);
            glVertexAttrib4f(loc, 0, 1, 0, 1);
            glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_QUADS, 0, 4);
            glFinish(); glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            GLubyte *pd = buf + (16 * 32 + 16) * 4;
            int disabled_corrupted = !(pd[0] == 0 && pd[1] == 255 && pd[2] == 0);
            printf("quirk1 DISABLED attribute: got %d,%d,%d (want CORRUPTED, i.e. != 0,255,0) %s\n", pd[0], pd[1], pd[2], disabled_corrupted ? "OK (still bugged, as documented)" : "MISMATCH (bug no longer reproduces!)");
            if (!enabled_ok) bad++;
            if (!disabled_corrupted) bad++;
            glUseProgram(0); glDeleteProgram(prog);
        }
    }

    /* --- quirk 2: texture2D() inside a never-taken runtime if/else voids the fragment --- */
    {
        GLuint tex; glGenTextures(1, &tex); glBindTexture(GL_TEXTURE_2D, tex);
        GLubyte texel[3] = {0, 0, 255};   /* blue: if this ever appears, the if-branch (never meant to run) executed */
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, texel);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        const char *vs = "#version 110\nvoid main() { gl_Position = gl_Vertex; }\n";
        const char *fs_bug = "#version 110\nuniform sampler2D tex;\nuniform bool flag;\nvoid main() { vec4 c; if (flag) { c = texture2D(tex, vec2(0.0)); } else { c = vec4(1.0,0.0,0.0,1.0); } gl_FragColor = c; }\n";
        const char *fs_ctrl = "#version 110\nuniform bool flag;\nvoid main() { vec4 c; if (flag) { c = vec4(0.0,0.0,1.0,1.0); } else { c = vec4(1.0,0.0,0.0,1.0); } gl_FragColor = c; }\n";
        float verts[] = {-1,-1, 1,-1, 1,1, -1,1};
        glVertexPointer(2, GL_FLOAT, 0, verts);
        glEnableClientState(GL_VERTEX_ARRAY);

        GLuint pbug = build(vs, fs_bug, log, sizeof log);
        GLuint pctrl = build(vs, fs_ctrl, log, sizeof log);
        if (!pbug || !pctrl) { printf("quirk2: build failed: %.200s\n", log); bad++; }
        else {
            glUseProgram(pctrl);
            glUniform1i(glGetUniformLocation(pctrl, "flag"), 0);
            glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_QUADS, 0, 4);
            glFinish(); glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            GLubyte *pc = buf + (16*32+16)*4;
            int ctrl_ok = (pc[0] == 255 && pc[1] == 0 && pc[2] == 0);
            printf("quirk2 CONTROL (no texture2D):  got %d,%d,%d want 255,0,0 %s\n", pc[0], pc[1], pc[2], ctrl_ok ? "OK" : "MISMATCH");

            glUseProgram(pbug);
            glUniform1i(glGetUniformLocation(pbug, "flag"), 0);
            glUniform1i(glGetUniformLocation(pbug, "tex"), 0);
            glBindTexture(GL_TEXTURE_2D, tex); glEnable(GL_TEXTURE_2D);
            glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_QUADS, 0, 4);
            glFinish(); glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            GLubyte *pb = buf + (16*32+16)*4;
            int bug_still_voids = !(pb[0] == 255 && pb[1] == 0 && pb[2] == 0);
            printf("quirk2 BUG (texture2D present):  got %d,%d,%d (want VOIDED, i.e. != 255,0,0) %s\n", pb[0], pb[1], pb[2], bug_still_voids ? "OK (still bugged, as documented)" : "MISMATCH (bug no longer reproduces!)");
            if (!ctrl_ok) bad++;
            if (!bug_still_voids) bad++;
            glUseProgram(0); glDeleteProgram(pbug); glDeleteProgram(pctrl);
        }
    }

    printf("RESULT: %s (%d mismatches)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
