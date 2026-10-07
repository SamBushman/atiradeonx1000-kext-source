/* cgs_probe.c - diagnostic for issue #44: is CGSGetPerformanceData a cumulative counter or an instantaneous rate? Samples N times at true rest
 * (no gesture, no window activity triggered by this program) with a fixed delay between samples, printing each raw sample.
 * Found (2026-10-07, investigating #44's 2D-compositing baseline noise): a/b pin at exactly 0.000 across 20/20 samples at true rest - genuine
 * real-time activity signals, not free-running counters. c/d ramp up from 0 then settle to a small nonzero plateau with their own inherent
 * jitter even at rest - a structural trait of those two metrics, not measurement noise.
 * Build:  gcc -arch ppc -o cgs_probe cgs_probe.c -framework ApplicationServices
 * Usage:  cgs_probe [n_samples=20] [delay_ms=200]
 */
#include <ApplicationServices/ApplicationServices.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int _CGSDefaultConnection(void);
extern int CGSGetPerformanceData(int cid, void *out1, void *out2, void *out3, void *out4);

int main(int argc, char **argv) {
    int n = argc > 1 ? atoi(argv[1]) : 20;
    int delay_ms = argc > 2 ? atoi(argv[2]) : 200;
    int cid = _CGSDefaultConnection();
    int i;
    for (i = 0; i < n; i++) {
        union { unsigned int i; float f; } a, b, c, d;
        CGSGetPerformanceData(cid, &a, &b, &c, &d);
        printf("sample %2d: a=%.3f b=%.3f c=%.3f d=%.3f\n", i, a.f, b.f, c.f, d.f);
        usleep(delay_ms * 1000);
    }
    return 0;
}
