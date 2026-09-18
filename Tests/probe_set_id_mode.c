/*
 * Tests/probe_set_id_mode.c -- deliberate, fully-reasoned parameter scan
 * over IOATIR500Surface::set_id_mode (selector 7), NOT a blind fuzz sweep.
 * User-authorized 2026-09-18 after a full code-path trace and an explicit
 * safety review, following the #43 kernel-panic incident earlier today.
 *
 * This project's own reconstructed source (Sources/IOATIR500Surface_
 * LockShape.cpp) gives a COMPLETE trace of every code path set_id_mode can
 * take. On a freshly-opened Surface user client (self+0x88/0x8c/0x90 all
 * zero - a fresh IOKit object), the function always enters its `proceed`
 * branch. With the "slow" path (modeBits without bit 0x20 set), it:
 *   1. requires mode < accelerator's own real ID-table bound (accel+0xcc)
 *      - a plain bounds check, safe to fail (returns kIOReturnError, the
 *      already-observed default) or pass (proceeds to step 2, still safe).
 *   2. compares a real per-ID hardware "kind" field against a small table
 *      driven by modeBits&0xf (0->0, 3->2, 4->4, 0xb/0xc->8, 0xd->0x10).
 *      A mismatch cleanly returns kIOReturnError, touching nothing else
 *      (already confirmed live: mode=0,modeBits=0 -> kIOReturnError,
 *      matching this exact path). A match proceeds into fully-traced,
 *      already-CONFIRMED bookkeeping (ID assignment, a small
 *      IOMallocAligned'd per-ID record, reset_req_bits/reset_access - both
 *      safe no-ops on a list-head-null fresh object, see that file's own
 *      header comments for the full trace).
 * No path here touches the swap-buffer machinery that actually crashed
 * (issue #43) - that requires a SEPARATE, later call (submit_swap_buffer,
 * reached via unlock_memory's negative-lock-type path), not anything in
 * set_id_mode itself. This scan is bounded to mode 0-3 and the 6 real
 * kind-bit patterns the switch statement above recognizes (24 calls
 * total) - not an open-ended fuzz, a closed enumeration of a fully-traced
 * function's only meaningfully-different inputs. Each call is followed by
 * a fresh IOServiceOpen/Close pair, and every line is fflush'd, so a
 * problem would pin down exactly which of the 24 combinations caused it.
 */
#include "common.h"

/* common.h declares these `extern` (defined once in main.c for the full
 * harness); this standalone probe doesn't link against main.c, so it
 * provides its own definitions to satisfy the link. Unused here. */
int g_testsRun = 0;
int g_testsUnexpected = 0;
int g_testsSkipped = 0;

static UInt32 kinds[] = {0x0, 0x3, 0x4, 0xb, 0xc, 0xd};

int main(void) {
    UInt32 mode;
    size_t i;
    io_service_t service = find_accelerator_service();
    if (service == IO_OBJECT_NULL) { printf("no service\n"); fflush(stdout); return 1; }

    for (mode = 0; mode < 4; mode++) {
        for (i = 0; i < sizeof(kinds)/sizeof(kinds[0]); i++) {
            UInt32 modeBits = kinds[i];
            io_connect_t connect = IO_OBJECT_NULL;
            kern_return_t kr = open_user_client(service, CLIENT_TYPE_SURFACE, &connect);
            if (kr != TEST_kIOReturnSuccess) {
                printf("mode=%u modeBits=0x%x: open failed 0x%08x\n", mode, modeBits, (unsigned int)kr);
                fflush(stdout);
                continue;
            }
            kern_return_t r = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, mode, modeBits);
            printf("mode=%u modeBits=0x%x -> 0x%08x (%s)%s\n", mode, modeBits, (unsigned int)r,
                   ioreturn_name(r), r == TEST_kIOReturnSuccess ? "  <-- SUCCESS, real ID assigned" : "");
            fflush(stdout);
            IOServiceClose(connect);
        }
    }

    IOObjectRelease(service);
    printf("scan complete, clean exit.\n"); fflush(stdout);
    return 0;
}
