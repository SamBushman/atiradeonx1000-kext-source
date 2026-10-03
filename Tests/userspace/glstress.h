/* !!! HAZARD - read before running (2026-10-03): on the stock Tiger X1900 driver this stress made the GL stack call exit(0) from inside glClear (seed 1: ARB vertex programs enabled with other random
 * state; and a second, different state combination at 200 iterations), produced runs that took minutes, and processes killed mid-run sat in the "E" (exiting) state for 40 s to 3 min. After a sequence of
 * such kills (together with the glwin "fastclear" mode) the whole GL stack stopped serving NEW clients: even the known-safe cgl_probe hung at start-up until the G5 was rebooted. Do NOT run it on a
 * machine you cannot reboot, never kill it with -9 while a GL context is live, and do not include it in unattended runs. It is kept because it documents the exit() paths. */
/* glstress.h - issue #42: deterministic randomized fixed-function GL state stress, shared by glcov.c (pbuffer) and glwin.m (window). Purpose: make the stock GL driver emit as many different
 * command-stream opcodes as possible without having to understand each emitter's guard: every iteration picks seeded-random but API-valid combinations of enables, enums, textures, ARB programs,
 * matrices and draw methods, draws something, and occasionally clears/reads/copies/flushes. The same seed reproduces the same run. Pixels are irrelevant.
 * Kept inside what is known to be safe on this driver (see the ati-x1900-driver-quirks skill): fixed-function + ARB programs, power-of-two 2D textures (rectangle for NPOT), no GLSL, no VBO tricks,
 * no FBO here. Needs <OpenGL/gl.h> + <OpenGL/glext.h> with GL_GLEXT_PROTOTYPES, stdio, stdlib, string, math. */
#ifndef GLSTRESS_H
#define GLSTRESS_H
static unsigned gs_rs; static const char *gs_no;
static int gs_verbose = -1;
#define GS_SKIP(c) (gs_no && strchr(gs_no, (c)))
#define GS_LOG(...) do { if (gs_verbose < 0) gs_verbose = getenv("GLSTRESS_VERBOSE") ? 1 : 0; if (gs_verbose) { printf(__VA_ARGS__); fflush(stdout); } } while (0)
static unsigned gs_rnd(void) { gs_rs = gs_rs * 1664525u + 1013904223u; return gs_rs >> 8; }
static int gs_pick(int n) { return (int)(gs_rnd() % (unsigned)n); }
static int gs_chance(int pct) { return gs_pick(100) < pct; }
#define GS_EN(cap) do { if (gs_chance(40)) glEnable(cap); else glDisable(cap); } while (0)
static GLuint gs_tex[10]; static GLenum gs_tgt[10]; static GLuint gs_fp[3], gs_vp[2]; static int gs_ready;
static void gs_setup(void) {
    static unsigned char buf[64 * 64 * 16]; static float fb[16 * 16 * 4]; int i; const char *fps[3] = {
        "!!ARBfp1.0\nTEMP t;\nTEX t, fragment.texcoord[0], texture[0], 2D;\nMUL result.color, t, fragment.color;\nEND\n",
        "!!ARBfp1.0\nTEMP a, b;\nTEX a, fragment.texcoord[0], texture[0], 2D;\nTEX b, fragment.texcoord[1], texture[1], 2D;\nLRP result.color, 0.5, a, b;\nEND\n",
        "!!ARBfp1.0\nTEMP a;\nTEX a, fragment.texcoord[0], texture[0], 2D;\nKIL a.a;\nMOV a.a, fragment.color.a;\nMUL result.color, a, program.env[0];\nEND\n" };
    const char *vps[2] = { "!!ARBvp1.0\nATTRIB p = vertex.position;\nDP4 result.position.x, state.matrix.mvp.row[0], p;\nDP4 result.position.y, state.matrix.mvp.row[1], p;\nDP4 result.position.z, state.matrix.mvp.row[2], p;\nDP4 result.position.w, state.matrix.mvp.row[3], p;\nMOV result.color, vertex.color;\nMOV result.texcoord[0], vertex.texcoord[0];\nMOV result.texcoord[1], vertex.texcoord[0];\nEND\n",
        "!!ARBvp1.0\nATTRIB p = vertex.position;\nPARAM s = { 0.9, 0.9, 1, 1 };\nTEMP r;\nMUL r, p, s;\nDP4 result.position.x, state.matrix.mvp.row[0], r;\nDP4 result.position.y, state.matrix.mvp.row[1], r;\nDP4 result.position.z, state.matrix.mvp.row[2], r;\nDP4 result.position.w, state.matrix.mvp.row[3], r;\nMOV result.color, vertex.color;\nMOV result.texcoord[0], vertex.texcoord[0];\nMOV result.fogcoord.x, p.x;\nEND\n" };
    memset(buf, 0x66, sizeof buf); for (i = 0; i < 16 * 16 * 4; i++) fb[i] = (float)(i % 17) / 16.0f; gs_ready = 1;
    glGenTextures(10, gs_tex);
    for (i = 0; i < 10; i++) {
        GLenum t = i < 4 ? GL_TEXTURE_2D : i == 4 ? GL_TEXTURE_RECTANGLE_EXT : i == 5 ? GL_TEXTURE_CUBE_MAP : i == 6 ? GL_TEXTURE_3D : GL_TEXTURE_2D; gs_tgt[i] = t; glBindTexture(t, gs_tex[i]);
        glTexParameteri(t, GL_TEXTURE_MIN_FILTER, GL_LINEAR); glTexParameteri(t, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        if (i == 0) { glTexImage2D(t, 0, GL_RGBA8, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf); }
        else if (i == 1) { int l; glTexParameteri(t, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); for (l = 0; l < 6; l++) glTexImage2D(t, l, GL_RGB8, 32 >> l, 32 >> l, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf); }
        else if (i == 2) { glTexImage2D(t, 0, GL_LUMINANCE8_ALPHA8, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf); }
        else if (i == 3) { glTexImage2D(t, 0, GL_RGBA_FLOAT16_ATI, 16, 16, 0, GL_RGBA, GL_FLOAT, fb); glTexParameteri(t, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(t, GL_TEXTURE_MAG_FILTER, GL_NEAREST); }
        else if (i == 4) { glTexImage2D(t, 0, GL_RGBA8, 100, 60, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf); }
        else if (i == 5) { int f; for (f = 0; f < 6; f++) glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + f, 0, GL_RGBA8, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf); }
        else if (i == 6) { glTexImage3D(t, 0, GL_RGBA8, 8, 8, 8, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf); }
        else if (i == 7) { glCompressedTexImage2D(t, 0, GL_COMPRESSED_RGBA_S3TC_DXT5_EXT, 16, 16, 0, 16 * 16, buf); }
        else if (i == 8) { glTexImage2D(t, 0, GL_DEPTH_COMPONENT24, 32, 32, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL); glTexParameteri(t, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE_ARB); }
        else { glTexImage2D(t, 0, GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf); glTexParameteri(t, GL_GENERATE_MIPMAP_SGIS, GL_TRUE); glTexParameterf(t, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0f); }
    }
    glGenProgramsARB(3, gs_fp); for (i = 0; i < 3; i++) { glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, gs_fp[i]); glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, strlen(fps[i]), fps[i]); }
    glGenProgramsARB(2, gs_vp); for (i = 0; i < 2; i++) { glBindProgramARB(GL_VERTEX_PROGRAM_ARB, gs_vp[i]); glProgramStringARB(GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, strlen(vps[i]), vps[i]); }
    while (glGetError() != GL_NO_ERROR) {}
}
static void gs_vertex(int k) {
    float x = -0.9f + 1.8f * (gs_rnd() % 1000) / 1000.f, y = -0.9f + 1.8f * (gs_rnd() % 1000) / 1000.f, z = -0.9f + 1.8f * (gs_rnd() % 1000) / 1000.f; (void)k;
    glColor4f((gs_rnd() % 100) / 100.f, (gs_rnd() % 100) / 100.f, (gs_rnd() % 100) / 100.f, (gs_rnd() % 100) / 100.f); glNormal3f(0, 0, 1); glTexCoord2f((gs_rnd() % 100) / 50.f, (gs_rnd() % 100) / 50.f); glVertex3f(x, y, z);
}
static void gs_state(void) {
    int u, i; GLenum bf[] = { GL_ZERO, GL_ONE, GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR, GL_DST_COLOR, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA };
    GLenum be[] = { GL_FUNC_ADD, GL_FUNC_SUBTRACT, GL_FUNC_REVERSE_SUBTRACT, GL_MIN, GL_MAX }, cf[] = { GL_NEVER, GL_LESS, GL_EQUAL, GL_LEQUAL, GL_GREATER, GL_NOTEQUAL, GL_GEQUAL, GL_ALWAYS };
    GLenum so[] = { GL_KEEP, GL_ZERO, GL_REPLACE, GL_INCR, GL_DECR, GL_INVERT, GL_INCR_WRAP_EXT, GL_DECR_WRAP_EXT }, tm[] = { GL_MODULATE, GL_DECAL, GL_BLEND, GL_REPLACE, GL_ADD, GL_COMBINE_ARB };
    GLenum cb[] = { GL_REPLACE, GL_MODULATE, GL_ADD, GL_ADD_SIGNED_ARB, GL_INTERPOLATE_ARB, GL_SUBTRACT_ARB, GL_DOT3_RGB_ARB, GL_DOT3_RGBA_ARB };
    GLenum wr[] = { GL_REPEAT, GL_CLAMP, GL_CLAMP_TO_EDGE, GL_MIRRORED_REPEAT, GL_CLAMP_TO_BORDER_ARB };
    GS_LOG("      s1\n");
    GS_EN(GL_DEPTH_TEST); GS_EN(GL_CULL_FACE); GS_EN(GL_BLEND); GS_EN(GL_ALPHA_TEST); GS_EN(GL_STENCIL_TEST); GS_EN(GL_FOG); GS_EN(GL_LIGHTING); GS_EN(GL_COLOR_MATERIAL); GS_EN(GL_NORMALIZE);
    GS_EN(GL_POLYGON_OFFSET_FILL); GS_EN(GL_LINE_SMOOTH); GS_EN(GL_POINT_SMOOTH); GS_EN(GL_LINE_STIPPLE); GS_EN(GL_POLYGON_STIPPLE); GS_EN(GL_COLOR_LOGIC_OP); GS_EN(GL_DITHER); GS_EN(GL_MULTISAMPLE_ARB);
    GS_EN(GL_SAMPLE_ALPHA_TO_COVERAGE_ARB); GS_EN(GL_SAMPLE_COVERAGE_ARB); GS_EN(GL_SCISSOR_TEST); GS_EN(GL_CLIP_PLANE0); GS_EN(GL_CLIP_PLANE1); GS_EN(GL_CLIP_PLANE2); GS_EN(GL_RESCALE_NORMAL); GS_EN(GL_POINT_SPRITE_ARB);
    GS_EN(GL_LIGHT0); GS_EN(GL_LIGHT1); GS_EN(GL_LIGHT2); if (GS_SKIP('l')) glDisable(GL_LIGHTING); if (GS_SKIP('f')) glDisable(GL_FOG); if (GS_SKIP('b')) { glDisable(GL_BLEND); glDisable(GL_COLOR_LOGIC_OP); } if (GS_SKIP('m')) { glDisable(GL_MULTISAMPLE_ARB); glDisable(GL_SAMPLE_ALPHA_TO_COVERAGE_ARB); glDisable(GL_SAMPLE_COVERAGE_ARB); }
    if (GS_SKIP('o')) { glDisable(GL_POLYGON_OFFSET_FILL); glDisable(GL_LINE_SMOOTH); glDisable(GL_POINT_SMOOTH); glDisable(GL_LINE_STIPPLE); glDisable(GL_POLYGON_STIPPLE); glDisable(GL_POINT_SPRITE_ARB); } if (GS_SKIP('a')) { glDisable(GL_ALPHA_TEST); glDisable(GL_STENCIL_TEST); } if (gs_chance(30)) glEnable(GL_NORMALIZE);
    GS_LOG("      s2\n");
    glBlendFunc(bf[gs_pick(9)], bf[gs_pick(9)]); glBlendEquation(be[gs_pick(5)]); glDepthFunc(cf[gs_pick(8)]); glDepthMask(gs_chance(80)); glAlphaFunc(cf[gs_pick(8)], (gs_rnd() % 100) / 100.f); glColorMask(gs_chance(85), gs_chance(85), gs_chance(85), gs_chance(85));
    GS_LOG("      s3\n");
    glStencilFunc(cf[gs_pick(8)], gs_pick(4), 0xff); glStencilOp(so[gs_pick(8)], so[gs_pick(8)], so[gs_pick(8)]); glStencilMask(gs_chance(80) ? 0xff : 0x0f); glLogicOp(GL_CLEAR + gs_pick(16));
    GS_LOG("      s4\n");
    glFogi(GL_FOG_MODE, gs_chance(33) ? GL_LINEAR : gs_chance(50) ? GL_EXP : GL_EXP2); glFogf(GL_FOG_DENSITY, (gs_rnd() % 100) / 100.f); glFogi(GL_FOG_COORDINATE_SOURCE_EXT, gs_chance(30) ? GL_FOG_COORDINATE_EXT : GL_FRAGMENT_DEPTH_EXT);
    GS_LOG("      s5\n");
    glPolygonMode(GL_FRONT_AND_BACK, gs_chance(70) ? GL_FILL : gs_chance(50) ? GL_LINE : GL_POINT); glFrontFace(gs_chance(80) ? GL_CCW : GL_CW); glCullFace(gs_chance(50) ? GL_BACK : GL_FRONT); glShadeModel(gs_chance(80) ? GL_SMOOTH : GL_FLAT);
    GS_LOG("      s6\n");
    glPolygonOffset((gs_rnd() % 40) / 10.f - 2, (gs_rnd() % 40) / 10.f - 2); glLineWidth(1 + gs_pick(4)); glPointSize(1 + gs_pick(16)); glLineStipple(1 + gs_pick(4), 0x5555 ^ gs_rnd());
    GS_LOG("      s7\n");
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, gs_chance(40)); glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, gs_chance(40) ? GL_SEPARATE_SPECULAR_COLOR : GL_SINGLE_COLOR); glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, gs_chance(40));
    GS_LOG("      s8\n");
    for (i = 0; i < 3; i++) { float p[4] = { gs_pick(3) - 1.f, gs_pick(3) - 1.f, 1, gs_chance(50) }; glLightfv(GL_LIGHT0 + i, GL_POSITION, p); glLightf(GL_LIGHT0 + i, GL_SPOT_CUTOFF, gs_chance(70) ? 180.f : 30.f + gs_pick(40)); }
    GS_LOG("      s9\n");
    if (GS_SKIP('c')) { glDisable(GL_CLIP_PLANE0); glDisable(GL_CLIP_PLANE1); glDisable(GL_CLIP_PLANE2); } else
    glClipPlane(GL_CLIP_PLANE0, (GLdouble[]){ 1, 0, 0, 0.8 }); glClipPlane(GL_CLIP_PLANE1, (GLdouble[]){ 0, 1, 0, 0.8 }); glClipPlane(GL_CLIP_PLANE2, (GLdouble[]){ 0, 0, 1, 0.9 });
    GS_LOG("      s10\n");
    if (gs_chance(30)) glScissor(gs_pick(100), gs_pick(100), 50 + gs_pick(200), 50 + gs_pick(150)); if (GS_SKIP('s')) glDisable(GL_SCISSOR_TEST);
    GS_LOG("      s11\n");
    for (u = 0; u < 4; u++) {
        int ti = gs_pick(10); GS_LOG("      unit %d tex %d\n", u, ti); glActiveTexture(GL_TEXTURE0 + u); glClientActiveTexture(GL_TEXTURE0 + u);
        glDisable(GL_TEXTURE_2D); glDisable(GL_TEXTURE_RECTANGLE_EXT); glDisable(GL_TEXTURE_CUBE_MAP); glDisable(GL_TEXTURE_3D);
        if (gs_chance(60)) { GLenum t = gs_tgt[ti]; glBindTexture(t, gs_tex[ti]); glEnable(t); glTexParameteri(t, GL_TEXTURE_WRAP_S, wr[gs_pick(5)]); glTexParameteri(t, GL_TEXTURE_WRAP_T, wr[gs_pick(5)]);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, tm[gs_pick(6)]); glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, cb[gs_pick(8)]); glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA_ARB, cb[gs_pick(6)]); glTexEnvi(GL_TEXTURE_ENV, GL_RGB_SCALE_ARB, 1 << gs_pick(3));
            glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, gs_chance(50) ? GL_TEXTURE : GL_PREVIOUS_ARB); glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, gs_chance(50) ? GL_PRIMARY_COLOR_ARB : GL_CONSTANT_ARB);
            if (gs_chance(25)) { glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T); glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, gs_chance(50) ? GL_EYE_LINEAR : GL_OBJECT_LINEAR); glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR); } else { glDisable(GL_TEXTURE_GEN_S); glDisable(GL_TEXTURE_GEN_T); } }
        glMatrixMode(GL_TEXTURE); glLoadIdentity(); if (gs_chance(30)) { glRotatef(gs_pick(90), 0, 0, 1); glScalef(1 + gs_pick(2), 1 + gs_pick(2), 1); } glMatrixMode(GL_MODELVIEW);
    }
    GS_LOG("      s12\n");
    glActiveTexture(GL_TEXTURE0); glClientActiveTexture(GL_TEXTURE0);
    GS_LOG("      s13\n");
    if (!GS_SKIP('v') && gs_chance(25)) { glEnable(GL_VERTEX_PROGRAM_ARB); glBindProgramARB(GL_VERTEX_PROGRAM_ARB, gs_vp[gs_pick(2)]); } else glDisable(GL_VERTEX_PROGRAM_ARB);
    GS_LOG("      s14\n");
    if (!GS_SKIP('p') && gs_chance(25)) { glEnable(GL_FRAGMENT_PROGRAM_ARB); glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, gs_fp[gs_pick(3)]); glProgramEnvParameter4fARB(GL_FRAGMENT_PROGRAM_ARB, 0, 1, .5f, .5f, 1); } else glDisable(GL_FRAGMENT_PROGRAM_ARB);
    GS_LOG("      s15\n");
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); if (gs_chance(50)) glOrtho(-1, 1, -1, 1, -1, 1); else glFrustum(-.5, .5, -.5, .5, 1, 5); glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    GS_LOG("      s16\n");
    if (gs_chance(50)) glTranslatef(0, 0, -2); glRotatef(gs_pick(360), gs_pick(2), gs_pick(2), 1); glScalef(0.5f + gs_pick(100) / 100.f, 0.5f + gs_pick(100) / 100.f, 1);
}
static void gs_draw(void) {
    GLenum pr[] = { GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_QUADS, GL_QUAD_STRIP, GL_POLYGON }; int how = gs_pick(8), p = gs_pick(10), n, i;
    static float va[6000 * 3], ca[6000 * 4], ta[6000 * 2]; static unsigned short ia[6000]; static unsigned int uia[6000];
    n = gs_chance(70) ? 3 + gs_pick(60) : 100 + gs_pick(1100); if (p == 7 || p == 8) n &= ~3; if (n < 4) n = 4; if (n > 1200) n = 1200;
    GS_LOG("    draw how=%d prim=%d n=%d\n", how, p, n);
    if (how <= 2) { glBegin(pr[p]); for (i = 0; i < n && i < 300; i++) gs_vertex(i); glEnd(); return; }
    for (i = 0; i < n; i++) { va[i * 3] = -0.9f + 1.8f * (gs_rnd() % 1000) / 1000.f; va[i * 3 + 1] = -0.9f + 1.8f * (gs_rnd() % 1000) / 1000.f; va[i * 3 + 2] = -0.9f + 1.8f * (gs_rnd() % 1000) / 1000.f;
        ca[i * 4] = (gs_rnd() % 100) / 100.f; ca[i * 4 + 1] = (gs_rnd() % 100) / 100.f; ca[i * 4 + 2] = (gs_rnd() % 100) / 100.f; ca[i * 4 + 3] = (gs_rnd() % 100) / 100.f; ta[i * 2] = (gs_rnd() % 100) / 50.f; ta[i * 2 + 1] = (gs_rnd() % 100) / 50.f; ia[i] = (unsigned short)(gs_rnd() % n); uia[i] = gs_rnd() % n; }
    glEnableClientState(GL_VERTEX_ARRAY); glVertexPointer(3, GL_FLOAT, 0, va); if (gs_chance(70)) { glEnableClientState(GL_COLOR_ARRAY); glColorPointer(4, GL_FLOAT, 0, ca); }
    if (gs_chance(60)) { int u; for (u = 0; u < 2; u++) { glClientActiveTexture(GL_TEXTURE0 + u); glEnableClientState(GL_TEXTURE_COORD_ARRAY); glTexCoordPointer(2, GL_FLOAT, 0, ta); } glClientActiveTexture(GL_TEXTURE0); }
    if (how == 3) glDrawArrays(pr[p], 0, n); else if (how == 4) glDrawElements(pr[p], n, GL_UNSIGNED_SHORT, ia); else if (how == 5) glDrawElements(pr[p], n, GL_UNSIGNED_INT, uia);
    else if (how == 6) { glDrawRangeElementsEXT(pr[p], 0, n - 1, n, GL_UNSIGNED_INT, uia); } else { GLuint dl = glGenLists(1); glNewList(dl, GL_COMPILE); glDrawArrays(pr[p], 0, n); glEndList(); glCallList(dl); glCallList(dl); glDeleteLists(dl, 1); }
    glDisableClientState(GL_COLOR_ARRAY); glDisableClientState(GL_VERTEX_ARRAY); { int u; for (u = 0; u < 2; u++) { glClientActiveTexture(GL_TEXTURE0 + u); glDisableClientState(GL_TEXTURE_COORD_ARRAY); } glClientActiveTexture(GL_TEXTURE0); }
}
static void gs_misc(int w, int h) {
    static unsigned char px[128 * 128 * 16]; int k = gs_pick(14); GLuint t; GS_LOG("    misc %d\n", k);
    switch (k) {
    case 0: glClearColor((gs_rnd() % 100) / 100.f, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT); break;
    case 1: glClearDepth((gs_rnd() % 100) / 100.0); glClear(GL_DEPTH_BUFFER_BIT); break;
    case 2: glClearStencil(gs_pick(8)); glClear(GL_STENCIL_BUFFER_BIT); break;
    case 3: glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); break;
    case 4: glReadPixels(0, 0, 32 + gs_pick(96), 32 + gs_pick(96), GL_RGBA, GL_UNSIGNED_BYTE, px); break;
    case 5: glReadPixels(0, 0, 32, 32, GL_DEPTH_COMPONENT, GL_FLOAT, px); break;
    case 6: glGenTextures(1, &t); glBindTexture(GL_TEXTURE_2D, t); glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 0, 0, 64, 64, 0); glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 8, 8, 32, 32); glDeleteTextures(1, &t); break;
    case 7: glFlush(); break;
    case 8: glFinish(); break;
    case 9: glRasterPos2f(-.5f, -.5f); glCopyPixels(0, 0, 32 + gs_pick(64), 32 + gs_pick(64), GL_COLOR); break;
    case 10: glRasterPos2f(-.5f, -.5f); glDrawPixels(32, 32, GL_RGBA, GL_UNSIGNED_BYTE, px); break;
    case 11: glViewport(gs_pick(30), gs_pick(30), w - gs_pick(60), h - gs_pick(60)); break;
    case 12: glViewport(0, 0, w, h); glRectf(-.5f, -.5f, .5f, .5f); break;
    default: break;
    }
}
/* run `iters` iterations on a drawable of size w x h */
static void gs_run(int iters, unsigned seed, int w, int h) {
    int i; gs_rs = seed ? seed : 1; gs_no = getenv("GLSTRESS_NO"); if (!gs_ready) gs_setup();
    for (i = 0; i < iters; i++) {
        GS_LOG("  iteration %d\n", i);
        if (gs_chance(30)) { GS_LOG("    state\n"); gs_state(); }
        GS_LOG("    clear\n"); glClear(gs_chance(70) ? (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT) : GL_DEPTH_BUFFER_BIT);
        gs_draw(); if (gs_chance(35)) gs_draw(); if (gs_chance(25)) gs_misc(w, h);
        while (glGetError() != GL_NO_ERROR) {}
    }
    glDisable(GL_SCISSOR_TEST); glViewport(0, 0, w, h); glFinish();
}
#endif
