/* perf_methods.c - issue #44: per-selector latency of the kext's own external methods, so a regression in the rebuilt kext can be localised to a context and selector
 * (criterion 4) and the stock driver has a baseline for the 2D, DVD and Surface domains as well as GL (criterion 1/2).
 *
 * Every call here is already proven safe on stock (Tests/test_deep_t1.c asserts each one): global, side-effect-free queries and two real register READS (no writes, no allocation).
 * Nothing here binds a surface, locks, flips or submits.  What it measures is the round trip user -> IOConnectMethod* -> kernel -> the kext's method body -> back, i.e. the cost of the
 * method plus a constant per-call IOKit overhead that is the same for the stock and the rebuilt kext, so differences between the two are the method bodies.
 *
 * Usage: perf_methods [calls per metric, default 50000] [connection open/close cycles, default 200]
 * Output (one line per metric, stable format, parsed by Tools/perf_compare.py):
 *   METRIC <name> n=<n> min_us=<> p10_us=<> median_us=<> p90_us=<> max_us=<>
 * The p10 is the headline number: on this G5 the IOKit round trip is bimodal (about 3.5 us or about 7.3 us per call, flipping on scheduler timescales of ~10 ms), so a median over a short
 * sample can land in either mode; p10 over a long sample (50 000+ calls, >= 0.2 s per metric) is the fast-mode floor, i.e. the cost of the code without the placement penalty.
 * Build on the G5:  gcc -arch ppc -std=gnu99 -w -o perf_methods perf_methods.c -framework IOKit -framework CoreFoundation
 */
#include "common.h"
#include <stdlib.h>
#include <mach/mach_time.h>

int g_testsRun = 0, g_testsUnexpected = 0, g_testsSkipped = 0, g_testsRecorded = 0;

static double ticks_to_us;
static double now_us(void) { return (double)mach_absolute_time() * ticks_to_us; }
/* burn CPU for ~0.7 s so the G5's dynamic power stepping has ramped to full speed before anything is timed (an idle machine starts a process at about half speed for its first tens of ms: that is
 * the 3.5 us vs 7.3 us bimodality seen in the first stock baseline with 2000-call samples). Measured on stock: after this and with 50 000-call samples all metrics sit in the fast mode within 1-2 %. */
static void warmup(void) { double t0 = now_us(); volatile double x = 1.0; while (now_us() - t0 < 700000.0) { int k; for (k = 0; k < 1000; k++) x = x * 1.0000001 + 0.5; } }
static int cmp_d(const void *a, const void *b) { double x = *(const double *)a, y = *(const double *)b; return x < y ? -1 : x > y; }

static void report_metric(const char *name, double *s, int n) {
    qsort(s, n, sizeof(double), cmp_d);
    printf("METRIC %s n=%d min_us=%.2f p10_us=%.2f median_us=%.2f p90_us=%.2f max_us=%.2f\n", name, n, s[0], s[(int)(n * 0.1)], s[n / 2], s[(int)(n * 0.9)], s[n - 1]);
}

#define BENCH(NAME, EXPR) do { int _i; for (_i = 0; _i < warm; _i++) { (EXPR); } \
    for (_i = 0; _i < N; _i++) { double t0 = now_us(); kern_return_t _r = (EXPR); double t1 = now_us(); samp[_i] = t1 - t0; if (_r != want) bad++; } \
    report_metric(NAME, samp, N); } while (0)

int main(int argc, char **argv) {
    int N = argc > 1 ? atoi(argv[1]) : 50000, M = argc > 2 ? atoi(argv[2]) : 200, warm = 50, bad = 0, i;
    mach_timebase_info_data_t tb; double *samp; io_service_t svc; kern_return_t want = 0;
    mach_timebase_info(&tb); ticks_to_us = (double)tb.numer / tb.denom / 1000.0;
    setvbuf(stdout, NULL, _IONBF, 0);
    samp = malloc((N > M ? N : M) * sizeof(double));
    svc = find_accelerator_service();
    if (svc == IO_OBJECT_NULL) { printf("no accelerator service\n"); return 1; }
    printf("perf_methods: %d calls/metric, %d open/close cycles, timer tick %.4f us\n", N, M, ticks_to_us);
    {   /* GL */
        warmup();
        io_connect_t c; int a0, a1, a2, st, hw[5];
        if (open_user_client(svc, CLIENT_TYPE_GL, &c) == 0) {
            BENCH("gl.get_config.sel3", IOConnectMethodScalarIScalarO(c, 3, 0, 3, &a0, &a1, &a2));
            BENCH("gl.get_status.sel4", IOConnectMethodScalarIScalarO(c, 4, 0, 1, &st));
            BENCH("gl.get_hw_info.sel20", IOConnectMethodScalarIScalarO(c, 20, 0, 5, &hw[0], &hw[1], &hw[2], &hw[3], &hw[4]));
            IOServiceClose(c);
        }
    }
    {   /* 2D */
        warmup();
        io_connect_t c; int o0, o1; unsigned char info[0x30]; IOByteCount sz; UInt32 offs[2] = { 0x00f8, 0x0e40 }, v[2]; IOByteCount osz;
        if (open_user_client(svc, CLIENT_TYPE_2D, &c) == 0) {
            BENCH("2d.get_config.sel1", IOConnectMethodScalarIScalarO(c, 1, 0, 2, &o0, &o1));
            BENCH("2d.get_surface_info.sel2", (sz = sizeof info, IOConnectMethodScalarIStructureO(c, 2, 2, &sz, 0, 0, info)));
            BENCH("2d.read_regs_1.sel16", (osz = 4, IOConnectMethodStructureIStructureO(c, 16, 4, &osz, offs, v)));
            BENCH("2d.read_regs_2.sel16", (osz = 8, IOConnectMethodStructureIStructureO(c, 16, 8, &osz, offs, v)));
            IOServiceClose(c);
        }
    }
    {   /* DVD */
        warmup();
        io_connect_t c; int o0, o1, s0, both; UInt32 offs[1] = { 0x00f8 }, v[1]; IOByteCount osz;
        if (open_user_client(svc, CLIENT_TYPE_DVD, &c) == 0) {
            BENCH("dvd.get_config.sel1", IOConnectMethodScalarIScalarO(c, 1, 0, 2, &o0, &o1));
            BENCH("dvd.get_status.sel2", IOConnectMethodScalarIScalarO(c, 2, 0, 1, &s0));
            BENCH("dvd.read_regs.sel13", (osz = 4, IOConnectMethodStructureIStructureO(c, 13, 4, &osz, offs, v)));
            BENCH("dvd.check_stamps.sel20", IOConnectMethodScalarIScalarO(c, 20, 2, 1, 0, 0, &both));
            IOServiceClose(c);
        }
    }
    {   /* Surface: get_state succeeds; query_lock returns CannotLock by design (the method's own answer with no lock held) */
        warmup();
        io_connect_t c; int st;
        if (open_user_client(svc, CLIENT_TYPE_SURFACE, &c) == 0) {
            BENCH("surface.get_state.sel2", IOConnectMethodScalarIScalarO(c, 2, 0, 1, &st));
            want = TEST_kIOReturnCannotLock;
            BENCH("surface.query_lock.sel11", IOConnectMethodScalarIScalarO(c, 11, 0, 0));
            want = 0;
            IOServiceClose(c);
        }
    }
    {   /* connection open/close per context type: allocates and frees the user-client object, its memory maps and the context's state */
        warmup();
        static const char *nm[4] = { "surface", "gl", "2d", "dvd" };
        int t;
        for (t = 0; t < 4; t++) {
            int ok = 0;
            for (i = 0; i < M; i++) {
                io_connect_t c; double t0 = now_us(); kern_return_t r = open_user_client(svc, t, &c); double t1;
                if (r == 0) { IOServiceClose(c); ok++; }
                t1 = now_us(); samp[i] = t1 - t0;
            }
            { char name[64]; snprintf(name, sizeof name, "open_close.%s", nm[t]); report_metric(name, samp, M); }
            if (ok != M) { printf("open_close.%s: only %d of %d cycles opened\n", nm[t], ok, M); bad++; }
        }
    }
    printf("%s (%d call(s) returned an unexpected code)\n", bad ? "RESULT: FAIL" : "RESULT: PASS", bad);
    return bad ? 1 : 0;
}
