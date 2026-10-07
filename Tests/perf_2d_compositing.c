/* perf_2d_compositing.c - issue #44's last open item: an automated replacement for the single-session, human-driven
 * desktop-compositing baseline in Tests/performance_plan.md section 8.
 *
 * Why automate rather than repeat the manual method: that method needed a human physically at the console reading
 * Quartz Debug's Frame Meter live during each gesture (tiger-ssh's own documented limits on SSH-driven GUI
 * interaction). This file drives the same five gestures via Quartz Event Services' real, Tiger-native synthetic-
 * input API (CGPostMouseEvent/CGPostScrollWheelEvent, CGRemoteOperation.h - posts at the HID level, indistinguishable
 * to WindowServer from real hardware input) against the ALREADY-RUNNING login session - this never launches a new
 * GUI process of its own, so it does not touch the CoreDrag/bootstrap deadlock the tiger-ssh skill documents for
 * SSH-launched GUI apps.
 *
 * Caveat accepted deliberately, per the user's own call (2026-10-06): synthetic input may drive a genuinely
 * different (likely lower) redraw cadence than a real human hand on a real mouse - WindowServer could coalesce a
 * paced synthetic event stream differently than real HID interrupts. This is NOT claimed to numerically match the
 * original manual session's reported "~5-35 fps" range, and should not be compared against those numbers directly.
 * What this buys instead: a fully automated, precisely repeatable procedure - the same inputs, byte-for-byte, every
 * run - which is what a real regression gate actually needs, more than matching an old human-eyeballed number.
 *
 * Readout (revised 2026-10-06 - no screenshots at all): Quartz Debug's own Frame Meter is an analog needle gauge
 * fed by the private CGSGetPerformanceData() call - found by disassembling Quartz Debug's own binary (otool -tV),
 * not guessed: `bl __CGSDefaultConnection` then `bl _CGSGetPerformanceData` with 4 output pointers at stack offsets
 * 0x44,0x3c,0x40,0x38 (in that argument order). Calling it directly gives live values with zero screenshot/file-I/O
 * cost, sampleable every tick of the input loop - confirmed empirically (not just by the disassembly) to respond
 * clearly to real redraw load: idle readings of roughly a=25-26, b=2.0-2.9M, c=146-153, d=77-86 versus roughly
 * a=52-58, b=8.3-10M, c=321-352, d=329-377 during an active window drag on this machine. Which exact one (or what
 * derived rate of them) matches the Frame Meter's own displayed 0-90 number is NOT established - Quartz Debug's own
 * binary runs a block of floating-point math on values derived from this call before displaying anything, which
 * was not fully traced - so this reports all four raw values per scenario rather than overclaiming a single "fps".
 *
 * Precondition (checked, not set up by this program): a disposable Finder window open (this program finds it by
 * querying the front window's bounds via AppleScript, not fixed coordinates).
 *
 * Usage: perf_2d_compositing [ticks per scenario, default 200] [tick interval us, default 16000]
 * Output (same stable METRIC-line format as perf_methods.c/perf_baseline.c, parsed by Tools/perf_compare.py):
 *   METRIC <scenario>.<a|b|c|d> n=<n> min=<> p10=<> median=<> p90=<> max=<>
 * Build on the G5: gcc -arch ppc -o perf_2d_compositing perf_2d_compositing.c -framework ApplicationServices
 */
#include <ApplicationServices/ApplicationServices.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern int _CGSDefaultConnection(void);
extern int CGSGetPerformanceData(int cid, void *out1, void *out2, void *out3, void *out4);

static int g_cid;
static int g_ticks;
static int g_tick_us;

static int cmp_f(const void *a, const void *b) {
    float x = *(const float *)a, y = *(const float *)b;
    return x < y ? -1 : x > y;
}

static void report_metric(const char *name, float *s, int n) {
    qsort(s, n, sizeof(float), cmp_f);
    printf("METRIC %s n=%d min=%.3f p10=%.3f median=%.3f p90=%.3f max=%.3f\n",
           name, n, s[0], s[(int)(n * 0.1)], s[n / 2], s[(int)(n * 0.9)], s[n - 1]);
}

typedef void (*gesture_step_fn)(int tick);

/* Samples CGSGetPerformanceData once per tick, interleaved with the gesture's own input event for that tick -
 * both are now cheap (a function call, not a blocking screenshot), so this is true per-tick interleaving, not the
 * capture-blocks-for-a-second approximation the screenshot-based first draft of this file needed. */
static void run_scenario(const char *name, gesture_step_fn step) {
    float *sa = malloc(g_ticks * sizeof(float)), *sb = malloc(g_ticks * sizeof(float));
    float *sc = malloc(g_ticks * sizeof(float)), *sd = malloc(g_ticks * sizeof(float));
    char nbuf[64];
    int i;
    printf("scenario %s: %d ticks at %d us\n", name, g_ticks, g_tick_us);
    for (i = 0; i < g_ticks; i++) {
        union { unsigned int i; float f; } a, b, c, d;
        if (step) step(i);
        CGSGetPerformanceData(g_cid, &a, &b, &c, &d);
        sa[i] = a.f; sb[i] = b.f; sc[i] = c.f; sd[i] = d.f;
        usleep(g_tick_us);
    }
    snprintf(nbuf, sizeof nbuf, "%s.a", name); report_metric(nbuf, sa, g_ticks);
    snprintf(nbuf, sizeof nbuf, "%s.b", name); report_metric(nbuf, sb, g_ticks);
    snprintf(nbuf, sizeof nbuf, "%s.c", name); report_metric(nbuf, sc, g_ticks);
    snprintf(nbuf, sizeof nbuf, "%s.d", name); report_metric(nbuf, sd, g_ticks);
    free(sa); free(sb); free(sc); free(sd);
}

/* --- per-scenario gesture step functions --- */
static double g_dragFX, g_dragFY, g_dragTX, g_dragTY;
static void step_drag(int tick) {
    int lap = tick / 40, sub = tick % 40;
    double fx = (lap % 2 == 0) ? g_dragFX : g_dragTX, fy = (lap % 2 == 0) ? g_dragFY : g_dragTY;
    double tx = (lap % 2 == 0) ? g_dragTX : g_dragFX, ty = (lap % 2 == 0) ? g_dragTY : g_dragFY;
    double x = fx + (tx - fx) * (sub + 1) / 40.0, y = fy + (ty - fy) * (sub + 1) / 40.0;
    CGPostMouseEvent(CGPointMake(x, y), TRUE, 1, TRUE);
}

static void step_scroll(int tick) {
    int dir = ((tick / 30) % 2 == 0) ? -3 : 3; /* alternate scroll direction every 30 ticks */
    CGPostScrollWheelEvent(1, dir);
}

static double g_dockY;
static void step_dock(int tick) {
    double x = 40 + (tick % 60) * 30.0; /* sweep left-to-right across the Dock, wrapping */
    CGPostMouseEvent(CGPointMake(x, g_dockY), TRUE, 1, FALSE);
}

static void step_idle(int tick) { (void)tick; }

static void step_window_open(int tick) {
    if (tick % 40 == 0) {
        system("osascript -e 'tell application \"Finder\" to make new Finder window' "
               "-e 'tell application \"Finder\" to set bounds of front window to {700,100,1000,350}' "
               "-e 'tell application \"Finder\" to close front window' > /dev/null 2>&1 &");
    }
}

int main(int argc, char **argv) {
    double winL, winT, winR, winB;
    FILE *fp;

    g_ticks = argc > 1 ? atoi(argv[1]) : 200;
    g_tick_us = argc > 2 ? atoi(argv[2]) : 16000;
    g_cid = _CGSDefaultConnection();

    /* Find the disposable test window's bounds via AppleScript rather than assume fixed coordinates. */
    fp = popen("osascript -e 'tell application \"Finder\" to get bounds of front window'", "r");
    if (!fp || fscanf(fp, "%lf, %lf, %lf, %lf", &winL, &winT, &winR, &winB) != 4) {
        fprintf(stderr, "could not read front Finder window bounds - open one first\n");
        if (fp) pclose(fp);
        return 1;
    }
    pclose(fp);
    printf("using Finder window bounds: %.0f,%.0f - %.0f,%.0f\n", winL, winT, winR, winB);

    run_scenario("idle", step_idle);
    run_scenario("window_open", step_window_open);

    /* window drag: titlebar is ~11px above winT, centered horizontally */
    g_dragFX = (winL + winR) / 2.0; g_dragFY = winT - 11;
    g_dragTX = g_dragFX + 150; g_dragTY = g_dragFY + 100;
    CGPostMouseEvent(CGPointMake(g_dragFX, g_dragFY), TRUE, 1, FALSE);
    usleep(150000);
    CGPostMouseEvent(CGPointMake(g_dragFX, g_dragFY), TRUE, 1, TRUE);
    usleep(100000);
    run_scenario("window_drag", step_drag);
    CGPostMouseEvent(CGPointMake(g_dragTX, g_dragTY), TRUE, 1, FALSE);
    {
        char restoreCmd[400];
        snprintf(restoreCmd, sizeof restoreCmd,
                 "osascript -e 'tell application \"Finder\" to set bounds of front window to {%.0f,%.0f,%.0f,%.0f}'"
                 " > /dev/null 2>&1", winL, winT, winR, winB);
        system(restoreCmd);
        usleep(200000);
    }

    /* window resize: drag the bottom-right corner */
    g_dragFX = winR - 8; g_dragFY = winB - 8;
    g_dragTX = g_dragFX + 150; g_dragTY = g_dragFY + 100;
    CGPostMouseEvent(CGPointMake(g_dragFX, g_dragFY), TRUE, 1, FALSE);
    usleep(150000);
    CGPostMouseEvent(CGPointMake(g_dragFX, g_dragFY), TRUE, 1, TRUE);
    usleep(100000);
    run_scenario("window_resize", step_drag);
    CGPostMouseEvent(CGPointMake(g_dragTX, g_dragTY), TRUE, 1, FALSE);
    /* BUG FIX (2026-10-07): unlike window_drag above, this scenario never restored the window's original SIZE - each
     * invocation permanently grew it by the same (150,100) delta with nothing resetting it, so repeated back-to-back
     * runs measured a progressively larger window (confirmed: a 10-run pool showed a clean monotonic drift in both
     * window_resize's own metrics and window_drag's, the latter because each run's drag step then dragged whatever
     * size the window had grown to by the previous run's unrestored resize). Restore it the same way window_drag does. */
    {
        char restoreCmd[400];
        snprintf(restoreCmd, sizeof restoreCmd,
                 "osascript -e 'tell application \"Finder\" to set bounds of front window to {%.0f,%.0f,%.0f,%.0f}'"
                 " > /dev/null 2>&1", winL, winT, winR, winB);
        system(restoreCmd);
        usleep(200000);
    }

    /* scrolling: cursor needs to be over the Finder window's content area */
    CGPostMouseEvent(CGPointMake((winL + winR) / 2.0, (winT + winB) / 2.0), TRUE, 1, FALSE);
    usleep(100000);
    run_scenario("scroll", step_scroll);

    /* Dock hover: Dock sits at the very bottom of the screen */
    g_dockY = (double)(int)CGDisplayPixelsHigh(CGMainDisplayID()) - 20;
    run_scenario("dock_hover", step_dock);
    CGPostMouseEvent(CGPointMake(960, 540), TRUE, 1, FALSE); /* park the cursor away from the Dock when done */

    printf("RESULT: PASS\n");
    return 0;
}
