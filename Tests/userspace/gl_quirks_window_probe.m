/* gl_quirks_window_probe.m - issue #193: the documented runtime driver quirks 1 and 2 (ati-x1900-driver-quirks skill) checked in a WINDOW-backed NSOpenGLContext, the context type they
 * were first observed in (gl_feature_runtime_quirks_test.c runs the same checks, shared through runtime_quirks_checks.h, in a CGL pbuffer where neither reproduces).
 * Output (stdout): the same "quirk1 ..." / "quirk2 ..." lines; each defect line ends in "REPRODUCES (documented defect present)" or "does not reproduce in this context type".
 * Exit code: number of CONTROL failures (0 = pass); reproduction itself is informational.
 *
 * Needs a real Aqua session (an ssh-launched Cocoa app has a different Mach bootstrap: blank window / CoreDrag deadlock, see the tiger-ssh skill). Run it from the console session:
 *   gcc -arch ppc -x objective-c -w -I. -o gl_quirks_window_probe gl_quirks_window_probe.m -framework Cocoa -framework OpenGL
 *   write a launcher  run.command  that exports GLD_REDIRECT_FROM, GLD_REDIRECT_TO and DYLD_INSERT_LIBRARIES if you want the rebuilt driver, runs ./gl_quirks_window_probe > out.txt 2>&1 and then `echo DONE > done.txt`;
 *   chmod +x run.command; ssh G5 'open -a Terminal run.command'; poll done.txt. (Tools/userspace/godot_gui.command is a worked launcher example.) */
#import <Cocoa/Cocoa.h>
#import <OpenGL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "runtime_quirks_checks.h"

int main(int argc, char **argv) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    int bad, i;
    setvbuf(stdout, NULL, _IONBF, 0);
    [NSApplication sharedApplication];
    NSOpenGLPixelFormatAttribute at[] = { NSOpenGLPFAAccelerated, NSOpenGLPFADoubleBuffer, NSOpenGLPFAColorSize, 32, 0 };
    NSOpenGLPixelFormat *pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:at];
    if (!pf) { printf("no pixel format\n"); return 1; }
    NSWindow *win = [[NSWindow alloc] initWithContentRect:NSMakeRect(40, 40, 64, 64) styleMask:NSTitledWindowMask backing:NSBackingStoreBuffered defer:NO];
    NSOpenGLContext *ctx = [[NSOpenGLContext alloc] initWithFormat:pf shareContext:nil];
    if (!ctx) { printf("no context\n"); return 1; }
    [win orderFront:nil];
    [ctx setView:[win contentView]];
    [ctx makeCurrentContext];
    /* let the window server show the window before reading back (quirk 5 of the skill) */
    for (i = 0; i < 10; i++) [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.05]];
    glViewport(0, 0, 32, 32);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    printf("gl_quirks_window_probe: GL_RENDERER %s, GL_VERSION %s\n", glGetString(GL_RENDERER), glGetString(GL_VERSION));
    bad = rq_run("window");
    printf("RESULT: %s (%d control mismatches; defect reproduction is informational, context = window)\n", bad == 0 ? "PASS" : "FAIL", bad);
    [pool release];
    return bad ? 1 : 0;
}
