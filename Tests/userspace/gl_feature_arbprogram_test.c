/* gl_feature_arbprogram_test.c - issue #128: ARB_vertex_program / ARB_fragment_program (assembly-style shaders, the
 * other half of GL 1.5's programmable pipeline alongside GLSL) RUNTIME correctness - the existing ARB-parser tests in
 * Userspace/libGLProgrammability check that PARSING produces the same instruction stream as stock; this checks that a
 * real ARB program actually EXECUTES correctly through the driver and kext, which is a different, unverified claim. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

static int count_lit(GLubyte *buf, int w, int h) {
    int i, n = 0;
    for (i = 0; i < w * h; i++) if (buf[i * 4] > 10) n++;
    return n;
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
    err = CGLCreatePBuffer(64, 64, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }
    glViewport(0, 0, 64, 64);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    int bad = 0;
    static GLubyte buf[64 * 64 * 4];

    /* ARB fragment program: output a constant local parameter unchanged */
    {
        const char *src = "!!ARBfp1.0\nPARAM c = program.local[0];\nMOV result.color, c;\nEND\n";
        GLuint prog; glGenProgramsARB(1, &prog);
        glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, prog);
        glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)strlen(src), src);
        GLenum e = glGetError();
        GLint pos = -1; glGetIntegerv(GL_PROGRAM_ERROR_POSITION_ARB, &pos);
        if (e != GL_NO_ERROR || pos != -1) {
            printf("ARBfp build failed: glError=0x%04x errorPos=%d log=%s\n", e, pos, (const char *)glGetString(GL_PROGRAM_ERROR_STRING_ARB));
            bad++;
        } else {
            glEnable(GL_FRAGMENT_PROGRAM_ARB);
            glProgramLocalParameter4fARB(GL_FRAGMENT_PROGRAM_ARB, 0, 0.3f, 0.6f, 0.9f, 1.0f);
            float verts[] = {-1,-1, 1,-1, 1,1, -1,1};
            glVertexPointer(2, GL_FLOAT, 0, verts); glEnableClientState(GL_VERTEX_ARRAY);
            glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_QUADS, 0, 4);
            glFinish(); glReadPixels(0, 0, 64, 64, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            GLubyte *p = buf + (32*64+32)*4;
            int w0=(int)(0.3f*255+0.5f), w1=(int)(0.6f*255+0.5f), w2=(int)(0.9f*255+0.5f);
            int ok = abs((int)p[0]-w0)<=2 && abs((int)p[1]-w1)<=2 && abs((int)p[2]-w2)<=2;
            printf("ARBfp local param passthrough: got %d,%d,%d want %d,%d,%d %s\n", p[0],p[1],p[2], w0,w1,w2, ok?"OK":"MISMATCH");
            if (!ok) bad++;
            glDisable(GL_FRAGMENT_PROGRAM_ARB);
        }
    }

    /* ARB vertex program: scale incoming object-space position by a local parameter before the fixed MVP transform
     * would apply (here MVP is identity, so result.position = scale * vertex.position directly); fixed-function
     * fragment stage draws flat white. A real functional check: the rendered quad's area must shrink by the scale. */
    {
        const char *src =
            "!!ARBvp1.0\n"
            "PARAM scale = program.local[0];\n"
            "TEMP p;\n"
            "MUL p, vertex.position, scale;\n"
            "MOV result.position, p;\n"
            "MOV result.color, vertex.color;\n"
            "END\n";
        GLuint prog; glGenProgramsARB(1, &prog);
        glBindProgramARB(GL_VERTEX_PROGRAM_ARB, prog);
        glProgramStringARB(GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)strlen(src), src);
        GLenum e = glGetError();
        GLint pos = -1; glGetIntegerv(GL_PROGRAM_ERROR_POSITION_ARB, &pos);
        if (e != GL_NO_ERROR || pos != -1) {
            printf("ARBvp build failed: glError=0x%04x errorPos=%d log=%s\n", e, pos, (const char *)glGetString(GL_PROGRAM_ERROR_STRING_ARB));
            bad++;
        } else {
            glEnable(GL_VERTEX_PROGRAM_ARB);
            glColor3f(1,1,1);
            float verts[] = {-1,-1,0,1, 1,-1,0,1, 1,1,0,1, -1,1,0,1};   /* homogeneous, since result.position needs w */

            glProgramLocalParameter4fARB(GL_VERTEX_PROGRAM_ARB, 0, 1,1,1,1);
            glVertexPointer(4, GL_FLOAT, 0, verts); glEnableClientState(GL_VERTEX_ARRAY);
            glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_QUADS, 0, 4);
            glFinish(); glReadPixels(0, 0, 64, 64, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            int full = count_lit(buf, 64, 64);

            glProgramLocalParameter4fARB(GL_VERTEX_PROGRAM_ARB, 0, 0.5f,0.5f,0.5f,1);
            glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_QUADS, 0, 4);
            glFinish(); glReadPixels(0, 0, 64, 64, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            int half = count_lit(buf, 64, 64);

            printf("ARBvp scale=1.0 lit=%d, scale=0.5 lit=%d (want ~1/4 area)\n", full, half);
            int ok = full > 1000 && half > 0 && half < full / 2;   /* quartered area is the exact prediction; demand at least a clear, large reduction */
            if (!ok) bad++;
            glDisable(GL_VERTEX_PROGRAM_ARB);
        }
    }

    printf("RESULT: %s (%d mismatches)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
