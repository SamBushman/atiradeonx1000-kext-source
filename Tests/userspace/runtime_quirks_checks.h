/* runtime_quirks_checks.h - the two documented runtime driver quirks (ati-x1900-driver-quirks skill, quirks 1 and 2) as a context-agnostic check,
 * shared by gl_feature_runtime_quirks_test.c (CGL pbuffer) and gl_quirks_window_probe.m (NSOpenGLContext in a real window, the way the quirks were first seen).
 * The caller makes a 32x32-or-larger drawable current with GL_VIEWPORT 0,0,32,32 and an identity-ish ortho projection, then calls rq_run(label).
 * Return value = number of CONTROL failures (a case that must render correctly but did not). Whether the defect itself reproduces is reported as information:
 *   "REPRODUCES" = the documented defect is present in this context type; "does not reproduce" = renders correctly here. Neither is a test failure (#193). */
#ifndef RUNTIME_QUIRKS_CHECKS_H
#define RUNTIME_QUIRKS_CHECKS_H
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



/* --- extra variants closer to how the quirks were first hit (Godot's GLES2 shaders): reported only, never a failure --- */
static GLuint rq_build_bound(const char *vsrc, const char *fsrc, const char **names, const int *locs, int n, char *log, int logsz) {
    GLuint vs = glCreateShader(GL_VERTEX_SHADER), fs = glCreateShader(GL_FRAGMENT_SHADER), prog; GLint ok; int i;
    glShaderSource(vs, 1, &vsrc, NULL); glCompileShader(vs); glShaderSource(fs, 1, &fsrc, NULL); glCompileShader(fs);
    glGetShaderiv(vs, GL_COMPILE_STATUS, &ok); if (!ok) { glGetShaderInfoLog(vs, logsz, NULL, log); return 0; }
    glGetShaderiv(fs, GL_COMPILE_STATUS, &ok); if (!ok) { glGetShaderInfoLog(fs, logsz, NULL, log); return 0; }
    prog = glCreateProgram(); glAttachShader(prog, vs); glAttachShader(prog, fs);
    for (i = 0; i < n; i++) glBindAttribLocation(prog, locs[i], names[i]);
    glLinkProgram(prog); glGetProgramiv(prog, GL_LINK_STATUS, &ok);
    if (!ok) { glGetProgramInfoLog(prog, logsz, NULL, log); return 0; }
    return prog;
}
static void rq_variants(void) {
    char log[1024]; static GLubyte buf[32 * 32 * 4]; GLubyte *p; GLuint prog, vbo; int v;
    float pos[] = {-1,-1, 1,-1, 1,1, -1,1}, uv[] = {0,0, 1,0, 1,1, 0,1}, col[16]; int k;
    for (k = 0; k < 4; k++) { col[k*4]=0; col[k*4+1]=1; col[k*4+2]=0; col[k*4+3]=1; }
    /* quirk 1, Godot shape: position as GENERIC attribute 0 (enabled, client array), second attribute at location 4 either enabled or disabled (constant), written into a varying */
    {
        const char *vs = "#version 110\nattribute vec3 vertex;\nattribute vec4 uv_attrib;\nvarying vec4 uv_interp;\nvoid main() { uv_interp = uv_attrib; gl_Position = vec4(vertex, 1.0); }\n";
        const char *fs = "#version 110\nvarying vec4 uv_interp;\nvoid main() { gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0) * (uv_interp.w > 0.5 ? 1.0 : 0.25); }\n";
        const char *names[2] = { "vertex", "uv_attrib" }; int locs[2] = { 0, 4 };
        float pos3[12] = {-1,-1,0, 1,-1,0, 1,1,0, -1,1,0};
        prog = rq_build_bound(vs, fs, names, locs, 2, log, sizeof log);
        if (!prog) printf("quirk1 godot-shape: build failed: %.200s\n", log);
        else for (v = 0; v < 4; v++) {   /* 0: client arrays, uv enabled; 1: client arrays, uv DISABLED; 2: VBO position, uv enabled; 3: VBO position, uv DISABLED */
            int dis = v & 1, usevbo = v >> 1;
            glUseProgram(prog); glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
            if (usevbo) { glGenBuffers(1, &vbo); glBindBuffer(GL_ARRAY_BUFFER, vbo); glBufferData(GL_ARRAY_BUFFER, sizeof pos3, pos3, GL_STATIC_DRAW); glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); glBindBuffer(GL_ARRAY_BUFFER, 0); }
            else glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, pos3);
            glEnableVertexAttribArray(0);
            if (dis) { glDisableVertexAttribArray(4); glVertexAttrib4f(4, 0, 1, 0, 1); }
            else { glEnableVertexAttribArray(4); glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 0, col); }
            glDrawArrays(GL_QUADS, 0, 4); glFinish(); glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            p = buf + (16*32+16)*4;
            printf("quirk1 godot-shape %s pos, uv_attrib %s: got %d,%d,%d  -> %s\n", usevbo ? "VBO" : "client", dis ? "DISABLED" : "enabled", p[0], p[1], p[2],
                   (p[0] == 0 && p[1] == 255 && p[2] == 0) ? (dis ? "does not reproduce" : "OK") : (dis ? "REPRODUCES (documented defect present)" : "MISMATCH on the enabled control (informational)"));
            glDisableVertexAttribArray(0); glDisableVertexAttribArray(4);
            if (usevbo) glDeleteBuffers(1, &vbo);
        }
        glUseProgram(0);
    }
    (void)pos; (void)uv;
    /* quirk 2 variants: texture2D inside a runtime if/else whose condition is a uniform float / a varying / an expression, with an unused helper function and a second texture */
    {
        static const char *fsv[3] = {
          "#version 110\nuniform sampler2D tex;\nuniform float k;\nvarying vec4 vc;\nvoid main() { vec4 c = vec4(1.0,0.0,0.0,1.0); if (k > 0.5) { c = texture2D(tex, vec2(0.5)); } gl_FragColor = c; }\n",
          "#version 110\nuniform sampler2D tex;\nvarying vec4 vc;\nvoid main() { vec4 c; if (vc.x > 2.0) { c = texture2D(tex, vc.xy); } else { c = vec4(1.0,0.0,0.0,1.0); } gl_FragColor = c; }\n",
          "#version 110\nuniform sampler2D tex;\nuniform bool flag;\nvarying vec4 vc;\nvec4 helper(vec2 p) { return texture2D(tex, p) * 0.5; }\nvoid main() { vec4 c = vec4(1.0,0.0,0.0,1.0); if (flag) { c = helper(vc.xy); } else { c.a = 1.0; } gl_FragColor = c; }\n" };
        const char *vs = "#version 110\nvarying vec4 vc;\nvoid main() { vc = gl_Color; gl_Position = gl_Vertex; }\n";
        GLuint tex; GLubyte texel[3] = {0,0,255};
        glGenTextures(1, &tex); glBindTexture(GL_TEXTURE_2D, tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, texel);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glVertexPointer(2, GL_FLOAT, 0, pos); glEnableClientState(GL_VERTEX_ARRAY); glColor4f(0.2f, 0.2f, 0.2f, 1.0f);
        for (v = 0; v < 3; v++) {
            prog = build(vs, fsv[v], log, sizeof log);
            if (!prog) { printf("quirk2 variant %d: build failed: %.200s\n", v, log); continue; }
            glUseProgram(prog); glUniform1i(glGetUniformLocation(prog, "tex"), 0);
            if (v == 0) glUniform1f(glGetUniformLocation(prog, "k"), 0.0f);
            if (v == 2) glUniform1i(glGetUniformLocation(prog, "flag"), 0);
            glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT); glDrawArrays(GL_QUADS, 0, 4); glFinish(); glReadPixels(0, 0, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            p = buf + (16*32+16)*4;
            printf("quirk2 variant %d (%s): got %d,%d,%d  -> %s\n", v, v == 0 ? "uniform float cond" : v == 1 ? "varying cond" : "helper fn + bool", p[0], p[1], p[2],
                   (p[0] == 255 && p[1] == 0 && p[2] == 0) ? "does not reproduce" : "REPRODUCES (documented defect present)");
            glUseProgram(0); glDeleteProgram(prog);
        }
        glDisableClientState(GL_VERTEX_ARRAY);
    }
}

static int rq_run(const char *label) {
    char log[1024];
    static GLubyte buf[32 * 32 * 4];
    int bad = 0;
    (void)label;
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
            printf("quirk1 DISABLED attribute: got %d,%d,%d  -> %s\n", pd[0], pd[1], pd[2], disabled_corrupted ? "REPRODUCES (documented defect present)" : "does not reproduce in this context type");
            if (!enabled_ok) bad++;
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
            printf("quirk2 texture2D-in-if:  got %d,%d,%d  -> %s\n", pb[0], pb[1], pb[2], bug_still_voids ? "REPRODUCES (documented defect present)" : "does not reproduce in this context type");
            if (!ctrl_ok) bad++;
            glUseProgram(0); glDeleteProgram(pbug); glDeleteProgram(pctrl);
        }
    }


    rq_variants();
    return bad;
}
#endif
