/* glwin.m - issue #42: windowed GL workload for the opcode recorder. The pbuffer contexts of glcov.c silently get NO multisample buffers (GL_SAMPLE_BUFFERS = 0 even when the pixel format asks
 * for them), so everything that needs a real drawable - FSAA resolve, depth resolve, front/back buffer handling, buffer swaps - needs a window. This opens one small NSWindow with an
 * NSOpenGLContext of the requested format, renders N frames (depth-tested, textured, blended triangles; clears; a 1-pixel glReadPixels that forces a resolve) and swaps each one, then exits.
 *
 * Usage: glwin [samples=0] [frames=60] [stencil=1] [depthbits=24] [mode=basic|clears|hz]
 * Build on the G5:  gcc -arch ppc -x objective-c -w -o glwin glwin.m -framework Cocoa -framework OpenGL
 * Launch over SSH like the other GUI workloads (no interaction, window appears on the console, killed or exits by itself): see Tools/userspace/run_gl_features.sh and the tiger-ssh skill.
 */
#import <Cocoa/Cocoa.h>
#import <OpenGL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int samples = argc > 1 ? atoi(argv[1]) : 0, frames = argc > 2 ? atoi(argv[2]) : 60, stencil = argc > 3 ? atoi(argv[3]) : 1, depthbits = argc > 4 ? atoi(argv[4]) : 24;
    const char *mode = argc > 5 ? argv[5] : "basic"; int f, k;
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init]; setvbuf(stdout, NULL, _IONBF, 0);
    [NSApplication sharedApplication];
    NSOpenGLPixelFormatAttribute at[24]; int n = 0;
    at[n++] = NSOpenGLPFAAccelerated; at[n++] = NSOpenGLPFADoubleBuffer; at[n++] = NSOpenGLPFAColorSize; at[n++] = 32; at[n++] = NSOpenGLPFADepthSize; at[n++] = depthbits;
    if (stencil) { at[n++] = NSOpenGLPFAStencilSize; at[n++] = 8; }
    if (samples) { at[n++] = NSOpenGLPFASampleBuffers; at[n++] = 1; at[n++] = NSOpenGLPFASamples; at[n++] = samples; }
    at[n++] = 0;
    NSOpenGLPixelFormat *pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:at];
    if (!pf) { printf("no pixel format (samples=%d stencil=%d depth=%d)\n", samples, stencil, depthbits); return 1; }
    NSWindow *win = [[NSWindow alloc] initWithContentRect:NSMakeRect(40, 40, 320, 240) styleMask:NSTitledWindowMask backing:NSBackingStoreBuffered defer:NO];
    NSOpenGLContext *ctx = [[NSOpenGLContext alloc] initWithFormat:pf shareContext:nil];
    if (!ctx) { printf("no context\n"); return 1; }
    [win orderFront:nil]; [ctx setView:[win contentView]]; [ctx makeCurrentContext];
    { GLint sb = -1, sm = -1, db = -1, sbit = -1; glGetIntegerv(GL_SAMPLE_BUFFERS_ARB, &sb); glGetIntegerv(GL_SAMPLES_ARB, &sm); glGetIntegerv(GL_DEPTH_BITS, &db); glGetIntegerv(GL_STENCIL_BITS, &sbit);
      printf("glwin: sample buffers %d, samples %d, depth bits %d, stencil bits %d, mode %s\n", sb, sm, db, sbit, mode); }
    glViewport(0, 0, 320, 240); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1, 1, -1, 1, -1, 1); glMatrixMode(GL_MODELVIEW);
    for (f = 0; f < frames; f++) {
        unsigned char px[4];
        [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.01]];
        glClearColor(0.1f, 0.1f * (f & 7), 0.3f, 1); glClearDepth(1.0); glClearStencil(0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | (stencil ? GL_STENCIL_BUFFER_BIT : 0));
        glEnable(GL_DEPTH_TEST);
        for (k = 0; k < 6; k++) { glLoadIdentity(); glRotatef(f * 3.0f + k * 40.0f, 0, 0, 1); glBegin(GL_TRIANGLES); glColor3f(1, 0, 0); glVertex3f(-0.7f, -0.6f, -0.8f + 0.25f * k); glColor3f(0, 1, 0); glVertex3f(0.7f, -0.6f, -0.8f + 0.25f * k); glColor3f(0, 0, 1); glVertex3f(0, 0.8f, -0.8f + 0.25f * k); glEnd(); }
        if (stencil) { glEnable(GL_STENCIL_TEST); glStencilFunc(GL_ALWAYS, 1, 0xff); glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE); glLoadIdentity(); glBegin(GL_QUADS); glColor3f(1, 1, 0); glVertex2f(-.3f, -.3f); glVertex2f(.3f, -.3f); glVertex2f(.3f, .3f); glVertex2f(-.3f, .3f); glEnd(); glStencilFunc(GL_EQUAL, 1, 0xff); glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); glBegin(GL_QUADS); glColor3f(0, 1, 1); glVertex2f(-.5f, -.1f); glVertex2f(.5f, -.1f); glVertex2f(.5f, .1f); glVertex2f(-.5f, .1f); glEnd(); glDisable(GL_STENCIL_TEST); }
        glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); glLoadIdentity(); glBegin(GL_QUADS); glColor4f(1, 1, 1, 0.4f); glVertex2f(-.9f, -.2f); glVertex2f(.9f, -.2f); glVertex2f(.9f, .2f); glVertex2f(-.9f, .2f); glEnd(); glDisable(GL_BLEND); glDisable(GL_DEPTH_TEST);
        if (!strcmp(mode, "clears")) { int i; glEnable(GL_SCISSOR_TEST); for (i = 0; i < 4; i++) { glScissor(i * 30, i * 20, 80, 60); glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT); } glDisable(GL_SCISSOR_TEST); glClearDepth(0.0); glClear(GL_DEPTH_BUFFER_BIT); glClearDepth(1.0); glClear(GL_DEPTH_BUFFER_BIT); }
        if (!strcmp(mode, "hz")) { int i; glEnable(GL_DEPTH_TEST); for (i = 0; i < 20; i++) { glClear(GL_DEPTH_BUFFER_BIT); glDepthFunc(i & 1 ? GL_GREATER : GL_LESS); glLoadIdentity(); glBegin(GL_QUADS); glColor3f(i / 20.f, .5f, .5f); glVertex3f(-.8f, -.8f, -.5f + i * 0.04f); glVertex3f(.8f, -.8f, -.5f + i * 0.04f); glVertex3f(.8f, .8f, -.5f + i * 0.04f); glVertex3f(-.8f, .8f, -.5f + i * 0.04f); glEnd(); } glDepthFunc(GL_LESS); glDisable(GL_DEPTH_TEST); }
        glReadPixels(160, 120, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px);             /* forces the multisample buffer to resolve on a multisampled drawable */
        [ctx flushBuffer];
    }
    printf("glwin done: %d frames\n", frames); fflush(stdout);
    [ctx clearDrawable]; [ctx release]; [win close]; [pool release]; return 0;
}
