/*
 * Tests/main.c
 *
 * Entry point for the issue #42 feature-parity test harness. Covers all
 * 81 real external methods across the 4 context classes with real,
 * call-site-verified (or honestly-flagged-unverified) shapes; only a
 * deliberately-selected safe subset is actually invoked live - see
 * Tests/common.h's top-of-file safety note and Tests/README.md for the
 * full methodology and the #43 incident this policy is built from.
 */

#include "common.h"

int g_testsRun = 0;
int g_testsUnexpected = 0;
int g_testsSkipped = 0;
int g_testsRecorded = 0;

int main(void) {
    io_service_t service = find_accelerator_service();
    if (service == IO_OBJECT_NULL) {
        printf("[FAIL] ATIRadeonX1000 service not found in the IORegistry\n");
        return 1;
    }

    run_gl_context_tests(service);
    run_2d_context_tests(service);
    run_dvd_context_tests(service);
    run_surface_context_tests(service);

    IOObjectRelease(service);

    printf("\n%d calls made (%d asserted, %d recorded-only), %d unexpected result(s), %d skipped (shape-known, not live-tested)\n",
           g_testsRun, g_testsRun - g_testsRecorded, g_testsRecorded, g_testsUnexpected, g_testsSkipped);
    return g_testsUnexpected == 0 ? 0 : 1;
}
