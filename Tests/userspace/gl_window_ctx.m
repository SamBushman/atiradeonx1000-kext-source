/* gl_window_ctx.m - #214 probe helper: an on-screen NSWindow + NSOpenGLContext (like SDL on Tiger), so the probe
 * runs with a real window drawable composited by WindowServer instead of a pbuffer / captured display.
 * Must run in the Aqua session (launch via Terminal .command). */
#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>
#import <OpenGL/gl.h>
#include <stdlib.h>

static NSOpenGLContext *g_ctx = nil;

void *gl_window_make_ctx(int w, int h) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    [NSApplication sharedApplication];
    [NSApp finishLaunching];
    NSRect r = NSMakeRect(100, 100, w, h);
    NSWindow *win = [[NSWindow alloc] initWithContentRect:r styleMask:NSTitledWindowMask backing:NSBackingStoreBuffered defer:NO];
    [win setTitle:@"gl_doom_replay_probe"];
    NSOpenGLPixelFormatAttribute a[] = { NSOpenGLPFADoubleBuffer, NSOpenGLPFAAccelerated, NSOpenGLPFAColorSize, 32,
                                         NSOpenGLPFADepthSize, 24, NSOpenGLPFAStencilSize, 8, 0 };
    NSOpenGLPixelFormat *pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:a];
    if (!pf) return NULL;
    g_ctx = [[NSOpenGLContext alloc] initWithFormat:pf shareContext:nil];
    [win makeKeyAndOrderFront:nil];
    [NSApp activateIgnoringOtherApps:YES];
    [g_ctx setView:[win contentView]];
    [g_ctx makeCurrentContext];
    if (getenv("WIN_RESET")) {   /* Doom's kernel trace shows set_surface twice: re-attach the drawable like SDL's [context update]/setView again */
        [g_ctx clearDrawable]; [g_ctx setView:[win contentView]]; [g_ctx update]; [g_ctx makeCurrentContext];
    }
    GLint zero = 0; [g_ctx setValues:&zero forParameter:NSOpenGLCPSwapInterval];
    NSDate *end = [NSDate dateWithTimeIntervalSinceNow:1.5];
    while ([end timeIntervalSinceNow] > 0) {
        NSEvent *e = [NSApp nextEventMatchingMask:NSAnyEventMask untilDate:[NSDate dateWithTimeIntervalSinceNow:0.05] inMode:NSDefaultRunLoopMode dequeue:YES];
        if (e) [NSApp sendEvent:e];
    }
    return [g_ctx CGLContextObj];
}
void gl_window_pump(void) {
    NSEvent *e; while ((e = [NSApp nextEventMatchingMask:NSAnyEventMask untilDate:nil inMode:NSDefaultRunLoopMode dequeue:YES])) [NSApp sendEvent:e];
}
void gl_window_flush(void) { if (g_ctx) [g_ctx flushBuffer]; }
