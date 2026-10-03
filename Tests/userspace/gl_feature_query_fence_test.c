/* gl_feature_query_fence_test.c - issue #128 gap list: occlusion queries (ARB_occlusion_query,
 * GL_SAMPLES_PASSED) and APPLE_fence - only ever checked for opcode EMISSION before (#42), never for
 * actual correctness (does the sample count reported differ meaningfully between occluded/unoccluded). */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_SAMPLES_PASSED_ARB
#define GL_SAMPLES_PASSED_ARB 0x8914
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, kCGLPFADepthSize,16, (CGLPixelFormatAttribute)0 };
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

    int bad = 0;
    const char *ext = (const char*)glGetString(GL_EXTENSIONS);

    if (ext && strstr(ext, "GL_ARB_occlusion_query")) {
        glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LESS);
        GLuint qid; glGenQueriesARB(1, &qid);

        /* unoccluded: query a quad drawn with nothing in front of it */
        glClearDepth(1.0); glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        glBeginQueryARB(GL_SAMPLES_PASSED_ARB, qid);
        glColor3f(1,1,1);
        glBegin(GL_QUADS); glVertex3f(-0.5f,-0.5f,0); glVertex3f(0.5f,-0.5f,0); glVertex3f(0.5f,0.5f,0); glVertex3f(-0.5f,0.5f,0); glEnd();
        glEndQueryARB(GL_SAMPLES_PASSED_ARB);
        GLuint unoccluded = 0;
        glGetQueryObjectuivARB(qid, GL_QUERY_RESULT_ARB, &unoccluded);
        printf("occlusion query, unoccluded quad: samples passed = %u (want > 0)\n", unoccluded);
        if (unoccluded == 0) bad++;

        /* occluded: draw a full-screen quad closer to the camera first, then query the same quad behind it */
        glClearDepth(1.0); glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        glColor3f(0,0,0);
        glBegin(GL_QUADS); glVertex3f(-1,-1,-0.5f); glVertex3f(1,-1,-0.5f); glVertex3f(1,1,-0.5f); glVertex3f(-1,1,-0.5f); glEnd();
        glBeginQueryARB(GL_SAMPLES_PASSED_ARB, qid);
        glColor3f(1,1,1);
        glBegin(GL_QUADS); glVertex3f(-0.5f,-0.5f,0); glVertex3f(0.5f,-0.5f,0); glVertex3f(0.5f,0.5f,0); glVertex3f(-0.5f,0.5f,0); glEnd();
        glEndQueryARB(GL_SAMPLES_PASSED_ARB);
        GLuint occluded = 0;
        glGetQueryObjectuivARB(qid, GL_QUERY_RESULT_ARB, &occluded);
        printf("occlusion query, occluded quad (behind a nearer full-screen quad): samples passed = %u (want 0)\n", occluded);
        if (occluded != 0) bad++;

        glDeleteQueriesARB(1, &qid);
    } else {
        printf("GL_ARB_occlusion_query: NOT AVAILABLE - occlusion query test skipped\n");
    }

    if (ext && strstr(ext, "GL_APPLE_fence")) {
        GLuint fid; glGenFencesAPPLE(1, &fid);
        glSetFenceAPPLE(fid);
        GLboolean done = glTestFenceAPPLE(fid);
        glFinishFenceAPPLE(fid);
        GLboolean done_after_finish = glTestFenceAPPLE(fid);
        printf("APPLE_fence: TestFence before Finish = %d, after Finish = %d (want 1 after)\n", done, done_after_finish);
        if (!done_after_finish) bad++;
        glDeleteFencesAPPLE(1, &fid);
    } else {
        printf("GL_APPLE_fence: NOT AVAILABLE - fence test skipped\n");
    }

    printf("RESULT: %s (%d mismatches)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
