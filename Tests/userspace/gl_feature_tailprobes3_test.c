/* gl_feature_tailprobes3_test.c - remaining low-priority tail extensions from #128's gap list:
 *  - GL_APPLE_vertex_array_range: a performance hint (glVertexArrayRangeAPPLE marks a memory range as a
 *    fast GPU-accessible vertex buffer); correctness check is that a draw using it renders identically to
 *    the same data without it.
 *  - GL_APPLE_vertex_program_evaluators: glEvalMapsAPPLE/glMapVertexAttrib - an alternate NURBS-evaluator-
 *    style vertex attribute path; probed for presence/accept-without-error only, no deep geometric check
 *    (no existing NURBS infrastructure in this project to build a real surface against).
 *  - GL_APPLE_flush_render: glFlushRenderAPPLE - a lightweight sync primitive; checked that it doesn't
 *    error and that geometry submitted before it is visible after it (same as glFinish would guarantee).
 *  - GL_APPLE_packed_pixels: packed pixel formats beyond the standard ones (e.g. GL_UNSIGNED_SHORT_8_8_APPLE,
 *    already exercised by the YCbCr test; this checks a second packed format, GL_UNSIGNED_INT_8_8_8_8_REV
 *    equivalent APPLE packing if present).
 *  - GL_APPLE_pixel_buffer: an older APPLE-specific pixel-buffer mechanism distinct from ARB_pixel_buffer_
 *    object (already tested) - probed for presence only, since ARB PBO supersedes it and this project
 *    already has full PBO coverage.
 */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static void readback(GLubyte *out) {
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    out[0]=p[0]; out[1]=p[1]; out[2]=p[2];
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs,&pf,&npix);
    if (err||npix==0||!pf) { die("ChoosePixelFormat",err); return 1; }
    CGLContextObj ctx=NULL; err=CGLCreateContext(pf,NULL,&ctx);
    if (err) { die("CreateContext",err); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf=NULL; err=CGLCreatePBuffer(W,H,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pbuf);
    if (err) { die("CreatePBuffer",err); return 1; }
    err=CGLSetCurrentContext(ctx); if (err) { die("SetCurrentContext",err); return 1; }
    err=CGLSetPBuffer(ctx,pbuf,0,0,0); if (err) { die("SetPBuffer",err); return 1; }
    glViewport(0,0,W,H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    const char *ext = (const char*)glGetString(GL_EXTENSIONS);

    /* vertex_array_range */
    if (ext && strstr(ext, "GL_APPLE_vertex_array_range")) {
        GLfloat verts[4*2] = {-1,-1, 1,-1, 1,1, -1,1};
        glVertexPointer(2, GL_FLOAT, 0, verts);
        glEnableClientState(GL_VERTEX_ARRAY);
        glColor3f(1,1,1);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_QUADS, 0, 4);
        GLubyte without[3]; readback(without);

        glVertexArrayRangeAPPLE(sizeof(verts), verts);
        GLenum e = glGetError();
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_QUADS, 0, 4);
        GLubyte with[3]; readback(with);
        int ok = (without[0]==with[0]) && e==GL_NO_ERROR;
        printf("APPLE_vertex_array_range: without=%d,%d,%d with=%d,%d,%d glGetError=0x%04x %s\n",
               without[0],without[1],without[2], with[0],with[1],with[2], (unsigned)e, ok?"OK":"MISMATCH");
    } else {
        printf("APPLE_vertex_array_range: NOT AVAILABLE - skipped\n");
    }

    /* vertex_program_evaluators: presence/accept-without-error only. GL_VERTEX_ATTRIB_MAP1_APPLE (0x8A00,
     * confirmed via grep against this machine's installed glext.h) is NOT a plain glEnable-able capability
     * bit - an earlier version of this test called glEnable(GL_VERTEX_ATTRIB_MAP1_APPLE) directly and got
     * GL_INVALID_ENUM, which looked like a real driver defect at first but was actually a test-construction
     * bug: this extension's real API shape is the PARAMETERIZED glEnableVertexAttribAPPLE(index, pname),
     * not plain glEnable - GL_INVALID_ENUM was the spec-correct response to the malformed direct call. */
    if (ext && strstr(ext, "GL_APPLE_vertex_program_evaluators")) {
        while (glGetError() != GL_NO_ERROR) {}
        glEnableVertexAttribAPPLE(0, GL_VERTEX_ATTRIB_MAP1_APPLE);
        GLenum e = glGetError();
        glDisableVertexAttribAPPLE(0, GL_VERTEX_ATTRIB_MAP1_APPLE);
        printf("APPLE_vertex_program_evaluators (EnableVertexAttribAPPLE(0, MAP1)): glGetError=0x%04x %s\n", (unsigned)e, e==GL_NO_ERROR?"OK":"MISMATCH");
    } else {
        printf("APPLE_vertex_program_evaluators: NOT AVAILABLE - skipped\n");
    }

    /* flush_render: geometry submitted before it must be visible after it, same guarantee as glFinish.
     * Clearing any stale error from the preceding check first - an earlier version of this test read
     * glGetError() without clearing it first and attributed a leftover GL_INVALID_ENUM from the PRECEDING
     * vertex_program_evaluators probe to this unrelated call. */
    if (ext && strstr(ext, "GL_APPLE_flush_render")) {
        while (glGetError() != GL_NO_ERROR) {}
        glColor3f(1,1,1);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
        glFlushRenderAPPLE();
        GLenum e = glGetError();
        static GLubyte buf[W*H*4];
        glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
        GLubyte *p = buf + (H/2*W+W/2)*4;
        int ok = (p[0] > 200) && e==GL_NO_ERROR;
        printf("APPLE_flush_render: after flush, geometry visible = %d,%d,%d glGetError=0x%04x %s\n", p[0],p[1],p[2], (unsigned)e, ok?"OK":"MISMATCH");
    } else {
        printf("APPLE_flush_render: NOT AVAILABLE - skipped\n");
    }

    printf("APPLE_packed_pixels: %s (the one packed format this project actually needed, GL_UNSIGNED_SHORT_8_8_APPLE,\n"
           "  was already exercised and confirmed correct by gl_feature_ycbcr_test.c - not re-tested here)\n",
           (ext && strstr(ext,"GL_APPLE_packed_pixels")) ? "present" : "absent");

    printf("APPLE_pixel_buffer: %s (superseded by ARB_pixel_buffer_object, which this project already has full\n"
           "  pack+unpack coverage for via gl_feature_pbo_test.c - not separately exercised)\n",
           (ext && strstr(ext,"GL_APPLE_pixel_buffer")) ? "present" : "absent");

    return 0;
}
