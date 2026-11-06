/* gl_state_dump.h - #214: dump a large slice of fixed-function + client-array GL state as sorted "name value" text lines so the state
 * dhewm3 has at the draw that wedges the CP can be diffed against a standalone probe's state at the equivalent draw.
 * Used from two places with different function-pointer naming: define GSD_ISEN(cap), GSD_GETI(pname, int4*), GSD_GETF(pname, float4*),
 * GSD_GETIV_ATTRIB(idx, pname, int*), GSD_CLIENTACTIVE(unit), GSD_ACTIVETEX(unit), GSD_TEXLEVEL(target, level, pname, int*), GSD_TEXPARAM(target, pname, int*), GSD_TEXENV(pname, int*) before including.  Output goes to FILE *fp. */
#ifndef GL_STATE_DUMP_H
#define GL_STATE_DUMP_H
#include <stdio.h>
#ifndef GL_TEXTURE_BINDING_RECTANGLE_EXT
#define GL_TEXTURE_BINDING_RECTANGLE_EXT 0x84F6
#endif
#ifndef GL_TEXTURE_BINDING_CUBE_MAP_ARB
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB 0x8514
#endif
#ifndef GL_TEXTURE_BINDING_3D
#define GL_TEXTURE_BINDING_3D 0x806A
#endif
#ifndef GL_TEXTURE_COMPRESSED_ARB
#define GL_TEXTURE_COMPRESSED_ARB 0x86A1
#endif

struct gsd_cap { const char *name; unsigned cap; };
#define GSD_CAP(x) { #x, x }

static void gsd_dump(FILE *fp) {
    static const struct gsd_cap caps[] = {
        GSD_CAP(GL_ALPHA_TEST), GSD_CAP(GL_BLEND), GSD_CAP(GL_COLOR_LOGIC_OP), GSD_CAP(GL_COLOR_MATERIAL), GSD_CAP(GL_CULL_FACE),
        GSD_CAP(GL_DEPTH_TEST), GSD_CAP(GL_DITHER), GSD_CAP(GL_FOG), GSD_CAP(GL_LIGHTING), GSD_CAP(GL_LINE_SMOOTH), GSD_CAP(GL_LINE_STIPPLE),
        GSD_CAP(GL_NORMALIZE), GSD_CAP(GL_POINT_SMOOTH), GSD_CAP(GL_POLYGON_OFFSET_FILL), GSD_CAP(GL_POLYGON_OFFSET_LINE),
        GSD_CAP(GL_POLYGON_OFFSET_POINT), GSD_CAP(GL_POLYGON_SMOOTH), GSD_CAP(GL_POLYGON_STIPPLE), GSD_CAP(GL_SCISSOR_TEST),
        GSD_CAP(GL_STENCIL_TEST), GSD_CAP(GL_CLIP_PLANE0), GSD_CAP(GL_CLIP_PLANE1), GSD_CAP(GL_CLIP_PLANE2), GSD_CAP(GL_CLIP_PLANE3),
        GSD_CAP(GL_CLIP_PLANE4), GSD_CAP(GL_CLIP_PLANE5), GSD_CAP(GL_VERTEX_PROGRAM_ARB), GSD_CAP(GL_FRAGMENT_PROGRAM_ARB),
        GSD_CAP(GL_MULTISAMPLE_ARB), GSD_CAP(GL_RESCALE_NORMAL), GSD_CAP(GL_TEXTURE_GEN_S), GSD_CAP(GL_TEXTURE_GEN_T),
        GSD_CAP(GL_TEXTURE_GEN_R), GSD_CAP(GL_TEXTURE_GEN_Q), GSD_CAP(GL_VERTEX_ARRAY), GSD_CAP(GL_NORMAL_ARRAY), GSD_CAP(GL_COLOR_ARRAY),
        GSD_CAP(GL_TEXTURE_COORD_ARRAY), GSD_CAP(GL_INDEX_ARRAY), GSD_CAP(GL_EDGE_FLAG_ARRAY), GSD_CAP(GL_SECONDARY_COLOR_ARRAY),
        GSD_CAP(GL_FOG_COORDINATE_ARRAY), { 0, 0 } };
    static const struct gsd_cap texcaps[] = { GSD_CAP(GL_TEXTURE_1D), GSD_CAP(GL_TEXTURE_2D), GSD_CAP(GL_TEXTURE_3D),
        GSD_CAP(GL_TEXTURE_CUBE_MAP_ARB), GSD_CAP(GL_TEXTURE_RECTANGLE_EXT), { 0, 0 } };
    static const struct gsd_cap ints[] = {
        GSD_CAP(GL_DEPTH_FUNC), GSD_CAP(GL_DEPTH_WRITEMASK), GSD_CAP(GL_BLEND_SRC), GSD_CAP(GL_BLEND_DST), GSD_CAP(GL_CULL_FACE_MODE),
        GSD_CAP(GL_FRONT_FACE), GSD_CAP(GL_ALPHA_TEST_FUNC), GSD_CAP(GL_STENCIL_FUNC), GSD_CAP(GL_STENCIL_REF), GSD_CAP(GL_STENCIL_VALUE_MASK),
        GSD_CAP(GL_STENCIL_WRITEMASK), GSD_CAP(GL_STENCIL_FAIL), GSD_CAP(GL_STENCIL_PASS_DEPTH_FAIL), GSD_CAP(GL_STENCIL_PASS_DEPTH_PASS),
        GSD_CAP(GL_MATRIX_MODE), GSD_CAP(GL_SHADE_MODEL), GSD_CAP(GL_ACTIVE_TEXTURE_ARB), GSD_CAP(GL_CLIENT_ACTIVE_TEXTURE_ARB),
        GSD_CAP(GL_ARRAY_BUFFER_BINDING_ARB), GSD_CAP(GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB), GSD_CAP(GL_LOGIC_OP_MODE),
        GSD_CAP(GL_VERTEX_ARRAY_SIZE), GSD_CAP(GL_VERTEX_ARRAY_TYPE), GSD_CAP(GL_VERTEX_ARRAY_STRIDE),
        GSD_CAP(GL_COLOR_ARRAY_SIZE), GSD_CAP(GL_COLOR_ARRAY_TYPE), GSD_CAP(GL_COLOR_ARRAY_STRIDE),
        GSD_CAP(GL_TEXTURE_COORD_ARRAY_SIZE), GSD_CAP(GL_TEXTURE_COORD_ARRAY_TYPE), GSD_CAP(GL_TEXTURE_COORD_ARRAY_STRIDE),
        GSD_CAP(GL_NORMAL_ARRAY_TYPE), GSD_CAP(GL_NORMAL_ARRAY_STRIDE),
        GSD_CAP(GL_VERTEX_ARRAY_BUFFER_BINDING_ARB), GSD_CAP(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB), GSD_CAP(GL_COLOR_ARRAY_BUFFER_BINDING_ARB),
        GSD_CAP(GL_POLYGON_MODE), GSD_CAP(GL_VIEWPORT), GSD_CAP(GL_SCISSOR_BOX), GSD_CAP(GL_COLOR_WRITEMASK), { 0, 0 } };
    static const struct gsd_cap floats[] = {
        GSD_CAP(GL_CURRENT_COLOR), GSD_CAP(GL_CURRENT_NORMAL), GSD_CAP(GL_DEPTH_RANGE), GSD_CAP(GL_COLOR_CLEAR_VALUE),
        GSD_CAP(GL_POLYGON_OFFSET_FACTOR), GSD_CAP(GL_POLYGON_OFFSET_UNITS), GSD_CAP(GL_ALPHA_TEST_REF), { 0, 0 } };
    int i, u, k;
    GLint saveTex[4] = { 0, 0, 0, 0 }, saveClient[4] = { 0, 0, 0, 0 };
    GSD_GETI(GL_ACTIVE_TEXTURE_ARB, saveTex); GSD_GETI(GL_CLIENT_ACTIVE_TEXTURE_ARB, saveClient);
    for (i = 0; caps[i].name; i++) fprintf(fp, "%s %d\n", caps[i].name, (int)GSD_ISEN(caps[i].cap));
    for (u = 0; u < 8; u++) {
        GSD_ACTIVETEX(u); GSD_CLIENTACTIVE(u);
        for (i = 0; texcaps[i].name; i++) fprintf(fp, "unit%d.%s %d\n", u, texcaps[i].name, (int)GSD_ISEN(texcaps[i].cap));
        fprintf(fp, "unit%d.client.GL_TEXTURE_COORD_ARRAY %d\n", u, (int)GSD_ISEN(GL_TEXTURE_COORD_ARRAY));
    }
    /* per-unit texture objects: binding, level-0 size/format, sampler params, env (the draw references every bound texture the driver must make resident) */
    for (u = 0; u < 8; u++) {
        static const struct gsd_cap binds[] = { { "1D", GL_TEXTURE_BINDING_1D }, { "2D", GL_TEXTURE_BINDING_2D }, { "3D", GL_TEXTURE_BINDING_3D },
                                                { "CUBE", GL_TEXTURE_BINDING_CUBE_MAP_ARB }, { "RECT", GL_TEXTURE_BINDING_RECTANGLE_EXT }, { 0, 0 } };
        static const unsigned tgt[] = { GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D, GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_RECTANGLE_EXT };
        GSD_ACTIVETEX(u);
        for (i = 0; binds[i].name; i++) {
            GLint b[4] = { 0, 0, 0, 0 }; GSD_GETI(binds[i].cap, b);
            if (!b[0]) continue;
            { GLint w = 0, h = 0, ifm = 0, comp = 0, mn = 0, mg = 0, ws = 0, wt = 0, nl = 0; unsigned tg = (i == 3) ? GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB : tgt[i];
              GSD_TEXLEVEL(tg, 0, GL_TEXTURE_WIDTH, &w); GSD_TEXLEVEL(tg, 0, GL_TEXTURE_HEIGHT, &h); GSD_TEXLEVEL(tg, 0, GL_TEXTURE_INTERNAL_FORMAT, &ifm);
              GSD_TEXLEVEL(tg, 0, GL_TEXTURE_COMPRESSED_ARB, &comp);
              GSD_TEXPARAM(tgt[i], GL_TEXTURE_MIN_FILTER, &mn); GSD_TEXPARAM(tgt[i], GL_TEXTURE_MAG_FILTER, &mg);
              GSD_TEXPARAM(tgt[i], GL_TEXTURE_WRAP_S, &ws); GSD_TEXPARAM(tgt[i], GL_TEXTURE_WRAP_T, &wt);
              fprintf(fp, "unit%d.bound%s tex=%d %dx%d ifmt=0x%x compressed=%d min=0x%x mag=0x%x wrap=0x%x/0x%x\n", u, binds[i].name, (int)b[0], (int)w, (int)h, (unsigned)ifm, (int)comp, (unsigned)mn, (unsigned)mg, (unsigned)ws, (unsigned)wt); }
        }
        { GLint em = 0; GSD_TEXENV(GL_TEXTURE_ENV_MODE, &em); fprintf(fp, "unit%d.texenv_mode 0x%x\n", u, (unsigned)em); }
    }
    GSD_ACTIVETEX((int)saveTex[0] - GL_TEXTURE0_ARB); GSD_CLIENTACTIVE((int)saveClient[0] - GL_TEXTURE0_ARB);   /* restore */
    for (k = 0; k < 16; k++) { GLint en = 0; GSD_GETIV_ATTRIB(k, GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB, &en); fprintf(fp, "attrib%d.enabled %d\n", k, en); }
    for (i = 0; ints[i].name; i++) { GLint v[4] = { 0, 0, 0, 0 }; GSD_GETI(ints[i].cap, v); fprintf(fp, "%s %d %d %d %d\n", ints[i].name, (int)v[0], (int)v[1], (int)v[2], (int)v[3]); }
    for (i = 0; floats[i].name; i++) { GLfloat v[4] = { 0, 0, 0, 0 }; GSD_GETF(floats[i].cap, v); fprintf(fp, "%s %g %g %g %g\n", floats[i].name, v[0], v[1], v[2], v[3]); }
}
#endif
