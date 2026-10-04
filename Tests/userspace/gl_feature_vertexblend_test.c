/* gl_feature_vertexblend_test.c - ARB_vertex_blend: multi-matrix vertex blending (skinning), never checked
 * before.
 *
 * CONFIRMED REAL DRIVER BUG (quirk 25/#138, see diag_vbaddr.c): GL_ARB_vertex_blend is advertised in
 * GL_EXTENSIONS, and glVertexBlendARB itself resolves to a real function pointer via dlsym - but
 * glActiveMatrixARB (needed to select which per-unit MODELVIEW stack subsequent glLoadMatrix calls target)
 * and glWeightfARB (needed to supply the per-vertex blend weight) both resolve to NULL. Both are absolutely
 * required to use vertex blending at all - there is no way to set up per-unit matrices or weights without
 * them. The extension is advertised but entirely non-functional: at most one of its three core entry
 * points actually exists. This test probes for all three via dlsym and reports the finding rather than
 * attempting calls that would either fail to link or crash through a null function pointer. */
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_VERTEX_BLEND_ARB
#define GL_VERTEX_BLEND_ARB 0x86A7
#endif
#ifndef GL_MAX_VERTEX_UNITS_ARB
#define GL_MAX_VERTEX_UNITS_ARB 0x86A8
#endif
#ifndef GL_MODELVIEW0_ARB
#define GL_MODELVIEW0_ARB 0x1700
#endif
#ifndef GL_MODELVIEW1_ARB
#define GL_MODELVIEW1_ARB 0x850A
#endif

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
    glDisable(GL_DEPTH_TEST);

    const char *ext = (const char*)glGetString(GL_EXTENSIONS);
    if (!(ext && strstr(ext, "GL_ARB_vertex_blend"))) {
        printf("RESULT: SKIPPED - GL_ARB_vertex_blend not available\n");
        return 0;
    }

    GLint maxUnits = -1;
    glGetIntegerv(GL_MAX_VERTEX_UNITS_ARB, &maxUnits);
    printf("MAX_VERTEX_UNITS_ARB = %d\n", (int)maxUnits);

    void *h = dlopen("/System/Library/Frameworks/OpenGL.framework/OpenGL", RTLD_LAZY);
    void *pVertexBlend = dlsym(h, "glVertexBlendARB");
    void *pActiveMatrix = dlsym(h, "glActiveMatrixARB");
    void *pWeight = dlsym(h, "glWeightfARB");
    printf("dlsym glVertexBlendARB=%p glActiveMatrixARB=%p glWeightfARB=%p\n", pVertexBlend, pActiveMatrix, pWeight);

    int usable = pVertexBlend && pActiveMatrix && pWeight;
    if (!usable) {
        printf("RESULT: SKIPPED - GL_ARB_vertex_blend is advertised but %s%s%s is NULL via dlsym; the\n"
               "  extension cannot be exercised without all three entry points (quirk 25/#138)\n",
               pVertexBlend?"":"glVertexBlendARB ", pActiveMatrix?"":"glActiveMatrixARB ", pWeight?"":"glWeightfARB ");
        return 0;
    }
    printf("RESULT: FAIL - all three entry points resolved; this test was never updated to actually use them (re-check quirk 25/#138's status, it may be fixed now)\n");
    return 1;
}
