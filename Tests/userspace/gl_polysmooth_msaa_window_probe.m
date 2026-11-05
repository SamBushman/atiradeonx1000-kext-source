/* gl_polysmooth_msaa_window_probe.m - issue #131: antialiased polygon edges on the X1900. GL_POLYGON_SMOOTH is never consulted by the GLDriver (no polygon coverage hardware),
 * so the supported route is a multisampled pixel format. CGL pbuffers cannot be multisampled on this stack (diag_msaa.c), so this checks a WINDOW-backed NSOpenGLContext:
 *   case A: 1x (no multisample), POLYGON_SMOOTH + blend       -> expected: hard 0/255 edge (the #131 symptom)
 *   case B: 4x multisample, POLYGON_SMOOTH off                -> expected: intermediate edge values (real antialiasing)
 *   case C: 4x multisample, POLYGON_SMOOTH on + blend         -> expected: intermediate edge values (smooth must not break it)
 * Output (stdout): one line per case "caseX samples=N distinct=D intermediate=I" and a RESULT line. Exit code 0 when B and C show intermediate coverage values.
 * Needs a real Aqua session (see gl_quirks_window_probe.m for the launcher recipe).
 *   gcc -arch ppc -x objective-c -w -o gl_polysmooth_msaa_window_probe gl_polysmooth_msaa_window_probe.m -framework Cocoa -framework OpenGL */
#import <Cocoa/Cocoa.h>
#import <OpenGL/gl.h>
#include <stdio.h>
#include <stdlib.h>

#define N 64
static int run_case(const char *name, int samples, int smooth) {
    NSOpenGLPixelFormatAttribute at[16]; int k = 0, i, y, x, inter = 0, distinct = 0; GLint gotSamples = 0; unsigned char seen[256]; static unsigned char buf[N * N * 4];
    at[k++] = NSOpenGLPFAAccelerated; at[k++] = NSOpenGLPFADoubleBuffer; at[k++] = NSOpenGLPFAColorSize; at[k++] = 32;
    if (samples) { at[k++] = NSOpenGLPFASampleBuffers; at[k++] = 1; at[k++] = NSOpenGLPFASamples; at[k++] = samples; }
    at[k] = 0;
    NSOpenGLPixelFormat *pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:at];
    if (!pf) { printf("%s samples=%d no pixel format\n", name, samples); return 0; }
    NSWindow *win = [[NSWindow alloc] initWithContentRect:NSMakeRect(60, 60, N, N) styleMask:NSTitledWindowMask backing:NSBackingStoreBuffered defer:NO];
    NSOpenGLContext *ctx = [[NSOpenGLContext alloc] initWithFormat:pf shareContext:nil];
    [win orderFront:nil]; [ctx setView:[win contentView]]; [ctx makeCurrentContext];
    for (i = 0; i < 10; i++) [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.05]];
    [pf getValues:&gotSamples forAttribute:NSOpenGLPFASamples forVirtualScreen:0];
    glViewport(0, 0, N, N); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, N, 0, N, -1, 1); glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST); glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    if (samples) glEnable(0x809D /* GL_MULTISAMPLE_ARB */);
    if (smooth) { glEnable(GL_POLYGON_SMOOTH); glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST); glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); }
    glColor4f(1, 1, 1, 1);
    glBegin(GL_TRIANGLES); glVertex2f(4.3f, 5.7f); glVertex2f(58.2f, 13.1f); glVertex2f(21.6f, 57.9f); glEnd();
    glFinish();
    glReadBuffer(GL_BACK); glReadPixels(0, 0, N, N, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    for (i = 0; i < 256; i++) seen[i] = 0;
    for (y = 0; y < N; y++) for (x = 0; x < N; x++) { unsigned char v = buf[(y * N + x) * 4]; if (!seen[v]) { seen[v] = 1; distinct++; } if (v > 8 && v < 247) inter++; }
    printf("%s samples=%d (pixel format reports %d) smooth=%d distinct=%d intermediate=%d\n", name, samples, (int)gotSamples, smooth, distinct, inter);
    [NSOpenGLContext clearCurrentContext]; [win close];
    return inter;
}
int main(int argc, char **argv) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init]; int a, b, c, ok;
    setvbuf(stdout, NULL, _IONBF, 0);
    [NSApplication sharedApplication];
    a = run_case("caseA", 0, 1); b = run_case("caseB", 4, 0); c = run_case("caseC", 4, 1);
    ok = (b > 0 && c > 0);
    printf("RESULT: %s (1x smooth intermediate=%d [0 = #131 symptom], 4x msaa intermediate=%d, 4x msaa + smooth intermediate=%d)\n", ok ? "PASS" : "FAIL", a, b, c);
    [pool release];
    return ok ? 0 : 1;
}
