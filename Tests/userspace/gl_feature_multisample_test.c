/* gl_feature_multisample_test.c - issue #128 gap list: multisampling/antialiasing correctness, only ever
 * checked for opcode EMISSION before (#42), never for actual visual correctness.
 *
 * ENVIRONMENT LIMITATION (confirmed via diag_msaa.c, not a vendor bug): CGLChoosePixelFormat silently
 * downgrades a Pbuffer-backed request for kCGLPFASampleBuffers=1/kCGLPFASamples=4 to sampleBuffers=0,
 * samples=0 with NO error - this driver/OS combination does not support multisampled Pbuffers at all, only
 * multisampled real windows (consistent with Tests/pm4_opcode_gaps.md's existing note that #42's windowed
 * opcode-coverage program already successfully used 0/2/4/6-sample multisample - that worked because it used
 * a real window, not a Pbuffer, the way every other test in this directory does). This test therefore cannot
 * check multisample correctness in this Pbuffer-only harness; it reports that limitation explicitly rather
 * than asserting a false pass or fail. A real windowed multisample correctness check is a separate, still-open
 * gap (would need glwin.m-style window infrastructure, which has the tiger-ssh skill's usual GUI-over-SSH
 * caveats). */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 64
#define H 64

static int scan_for_blend(GLubyte *buf) {
    int i;
    for (i = 0; i < W*H; i++) {
        GLubyte *p = buf + i*4;
        int isbg = (p[0]==0 && p[1]==0 && p[2]==0);
        int isfg = (p[0]==255 && p[1]==255 && p[2]==255);
        if (!isbg && !isfg) return 1;
    }
    return 0;
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32,
        kCGLPFASampleBuffers, 1, kCGLPFASamples, 4, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs,&pf,&npix);
    if (err||npix==0||!pf) {
        printf("RESULT: SKIPPED - no multisample pixel format available on this hardware (err=%s, npix=%d)\n", CGLErrorString(err), npix);
        return 0;
    }
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

    GLint samples = -1;
    glGetIntegerv(GL_SAMPLES_ARB, &samples);
    printf("GL_SAMPLES (readback) = %d (requested 4)\n", (int)samples);
    if (samples == 0) {
        printf("RESULT: SKIPPED - this Pbuffer context has 0 samples despite requesting 4 (CGL silently\n"
               "  downgraded the pixel format with no error - see diag_msaa.c and this file's header comment;\n"
               "  this is a Pbuffer/CGL limitation on this platform, not something this test can check)\n");
        return 0;
    }

    glDisable(GL_MULTISAMPLE);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES); glVertex2f(-0.8f,-0.7f); glVertex2f(0.85f,-0.55f); glVertex2f(-0.3f,0.9f); glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int blended_off = scan_for_blend(buf);
    printf("MULTISAMPLE disabled: blended pixel present = %s (want NO)\n", blended_off?"YES":"NO");

    glEnable(GL_MULTISAMPLE);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES); glVertex2f(-0.8f,-0.7f); glVertex2f(0.85f,-0.55f); glVertex2f(-0.3f,0.9f); glEnd();
    glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    int blended_on = scan_for_blend(buf);
    printf("MULTISAMPLE enabled (4x pixel format): blended pixel present = %s (want YES, i.e. MSAA resolve smooths the edge)\n", blended_on?"YES":"NO");

    int bad = (blended_off != 0) || (blended_on == 0);
    printf("RESULT: %s (%d mismatches)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
