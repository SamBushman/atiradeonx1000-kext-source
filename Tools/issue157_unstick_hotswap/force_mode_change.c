/*
 * force_mode_change.c - issue #157: userspace tool to force a REAL display mode-set on the main
 * display, using the classic CoreGraphics display-mode API (CGDisplaySwitchToMode), to unstick a
 * hot-swapped ATIRadeonX1000's VRAM pool (accel+0x9c/+0x84c, used by tmpAllocVRAM and therefore by
 * Surface::set_shape and almost every T3 destructive test via t3_surface()).
 *
 * CONFIRMED WORKING RECIPE (2026-10-11, see issue #157's comment thread for the full derivation and
 * every intermediate finding - this header only states the final, confirmed sequence):
 *   1. Hot-swap the kext as usual (kextunload/kextload).
 *   2. Kill WindowServer so it restarts fresh against the NEW instance: find its pid (`ps auxww |
 *      grep WindowServer`), `sudo kill -9 <pid>` (it respawns automatically via the login session).
 *      Required because a WindowServer that was already running before the hot-swap keeps stale
 *      connection state tied to the OLD instance; attempting a mode-set through it hangs WindowServer
 *      itself (confirmed twice) until it's killed - restarting it FIRST avoids that entirely.
 *   3. Run Tools/request_probe (IOServiceRequestProbe) - framebuffer discovery (accel+0xcc/+0xe4).
 *      Confirmed REQUIRED: without this step, step 4 still completes without hanging, but the VRAM
 *      pool stays at zero anyway (display_mode_did_change() still doesn't reach the driver).
 *   4. Run this tool. It switches to a different valid mode and back to the original.
 * After all four steps, accel+0x9c/+0x84c are populated with the real VRAM size (confirmed:
 * 0x10000000/0x8000000, exactly matching this hardware's real 128MB) and Surface::set_shape (and by
 * extension every T3 test that depends on it via t3_surface()) passes identically to a genuine
 * boot-time load - confirmed by re-running t3_2d_lock_unlock end to end afterward: PASS, matching the
 * original 2026-10-02 boot-time Phase S baseline exactly (lock_memory addr=0x3810000 size=0x100).
 *
 * Any ONE of steps 2-4 done alone, or steps out of order, does not work (see the issue thread for the
 * specific partial results of each). This is the first known way to make hot-swap T3 Phase R testing
 * produce real data for the ~18 of 27 tests that depend on Surface allocation.
 *
 * Usage: ./force_mode_change   (switches to a different available mode, waits, switches back)
 * Exit 0 on success (a genuinely different mode was found and both switches succeeded), nonzero on
 * any failure (printed). Read-only from the kext's perspective - this never touches kernel memory or
 * kext code, only standard CoreGraphics APIs any ordinary app could call. Has its own internal 15s
 * safety alarm (exits 99) in case a future regression reintroduces the hang this recipe avoids.
 */
#include <ApplicationServices/ApplicationServices.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void on_alarm(int sig) {
    fprintf(stderr, "force_mode_change: internal 15s safety timeout hit, aborting\n");
    fflush(stderr);
    _exit(99);
}

static void printMode(const char *label, CFDictionaryRef mode) {
    CFNumberRef w = CFDictionaryGetValue(mode, kCGDisplayWidth);
    CFNumberRef h = CFDictionaryGetValue(mode, kCGDisplayHeight);
    CFNumberRef bpp = CFDictionaryGetValue(mode, kCGDisplayBitsPerPixel);
    CFNumberRef hz = CFDictionaryGetValue(mode, kCGDisplayRefreshRate);
    int wi = 0, hi = 0, bppi = 0; double hzd = 0;
    if (w) CFNumberGetValue(w, kCFNumberIntType, &wi);
    if (h) CFNumberGetValue(h, kCFNumberIntType, &hi);
    if (bpp) CFNumberGetValue(bpp, kCFNumberIntType, &bppi);
    if (hz) CFNumberGetValue(hz, kCFNumberDoubleType, &hzd);
    printf("%s: %dx%d %d-bit %.0fHz\n", label, wi, hi, bppi, hzd);
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    signal(SIGALRM, on_alarm);
    alarm(15);

    printf("force_mode_change: calling CGMainDisplayID...\n");
    CGDirectDisplayID display = CGMainDisplayID();
    printf("force_mode_change: CGMainDisplayID returned %u\n", (unsigned)display);

    printf("force_mode_change: calling CGDisplayCurrentMode...\n");
    CFDictionaryRef original = CGDisplayCurrentMode(display);
    if (!original) { fprintf(stderr, "force_mode_change: CGDisplayCurrentMode failed\n"); return 1; }
    printMode("current", original);

    CFNumberRef origW = CFDictionaryGetValue(original, kCGDisplayWidth);
    CFNumberRef origH = CFDictionaryGetValue(original, kCGDisplayHeight);
    int origWi = 0, origHi = 0;
    CFNumberGetValue(origW, kCFNumberIntType, &origWi);
    CFNumberGetValue(origH, kCFNumberIntType, &origHi);

    CFArrayRef modes = CGDisplayAvailableModes(display);
    if (!modes) { fprintf(stderr, "force_mode_change: CGDisplayAvailableModes failed\n"); return 1; }
    CFIndex count = CFArrayGetCount(modes);
    printf("force_mode_change: %ld available modes\n", (long)count);

    CFDictionaryRef target = NULL;
    for (CFIndex i = 0; i < count; i++) {
        CFDictionaryRef m = CFArrayGetValueAtIndex(modes, i);
        int wi = 0, hi = 0;
        CFNumberGetValue(CFDictionaryGetValue(m, kCGDisplayWidth), kCFNumberIntType, &wi);
        CFNumberGetValue(CFDictionaryGetValue(m, kCGDisplayHeight), kCFNumberIntType, &hi);
        if (wi != origWi || hi != origHi) { target = m; break; }
    }
    if (!target) { fprintf(stderr, "force_mode_change: no genuinely different mode found\n"); return 2; }
    printMode("switching to", target);

    CGDisplayErr err = CGDisplaySwitchToMode(display, target);
    if (err != kCGErrorSuccess) { fprintf(stderr, "force_mode_change: switch to target failed, err=%d\n", (int)err); return 3; }
    printf("force_mode_change: switched to target mode, settling...\n");
    sleep(2);

    err = CGDisplaySwitchToMode(display, original);
    if (err != kCGErrorSuccess) { fprintf(stderr, "force_mode_change: switch BACK to original failed, err=%d\n", (int)err); return 4; }
    printf("force_mode_change: switched back to original mode, settling...\n");
    sleep(2);

    printf("force_mode_change: done, exit 0\n");
    return 0;
}
