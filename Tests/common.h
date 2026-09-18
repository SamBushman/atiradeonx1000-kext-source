/*
 * Tests/common.h
 *
 * Shared helpers for the issue #42 feature-parity test harness. This
 * harness is a plain userspace program (NOT a kext) that opens the real
 * ATIRadeonX1000 accelerator service via IOKit and drives its external
 * methods exactly the way a real client (the GL/2D/VA userspace bundles)
 * would, so results can be compared against this project's own decompiled
 * understanding of each method's real behavior.
 *
 * Built and run on the G5 (Tiger 10.4.11) against whichever driver is
 * currently loaded - initially the stock Apple driver, to validate the
 * harness itself, then later this project's own rebuilt kext once #41's
 * install/rollback procedure is exercised.
 *
 * METHODOLOGY, CORRECTED (2026-09-18, see issue #43's comment thread for
 * the full incident writeup): a real per-selector call SHAPE (scalar/
 * struct in/out counts) can NOT be reliably read off this project's own
 * `VendorExternalMethod` kernel-table dump alone - that table's trailing
 * three count fields are real, correctly-read raw bytes, but their
 * semantic role (which one is "input count" vs "output count" vs
 * something else) is NOT reliably input/output/other in a fixed order,
 * contrary to what this project's headers previously claimed with
 * unwarranted confidence (see the corrected comment on
 * `VendorExternalMethod` in Headers/ATIRadeonX1000Types.h). The reliable
 * source of truth is CALL-SITE CROSS-REFERENCING: disassembling the real
 * vendor userspace bundles (ATIRadeonX1000GLDriver.bundle,
 * ATIRadeonX1000GA.plugin, ATIRadeonX1000VADriver.bundle) and reading the
 * literal register values passed to the raw `io_connect_method_*` MIG
 * stubs they call directly (PPC calling convention: r3=connection,
 * r4=selector, r5/r6=first data pointer/count, r7/r8=second data
 * pointer/count - which of "count" fields is a scalar count vs a
 * structure BYTE size depends on which of the four stub variants is
 * used: scalarI_scalarO, scalarI_structureI, scalarI_structureO,
 * structureI_structureO). Each test below cites the real binary+address
 * evidence it's built from, or is explicitly marked as falling back to
 * the class header's own declared C++ signature when no real call site
 * was found (this project's own established "argument-dropped"/hidden-
 * argument decompiler artifact means a signature-based guess can still
 * be wrong - such tests are flagged as lower confidence, not asserted as
 * fact).
 *
 * SAFETY, NON-NEGOTIABLE: a broad, automated sweep of many call shapes
 * against the live driver (this project's own earlier
 * `Tests/diag_shape_scan.c`, deliberately not committed/kept) triggered
 * a REAL KERNEL PANIC in Apple's stock driver (root-caused via static
 * Ghidra analysis to `ATIR500Surface::submit_swap_buffer` - see issue
 * #43's comment thread for the full panic log and analysis). The G5
 * hard-hung and needed a physical restart. It recovered cleanly (issue
 * #41's recovery plan, now validated for real), but this must not be
 * repeated. Every test in this harness that is actually EXECUTED live
 * (via `report()`, not `report_skipped()`) has been individually
 * reasoned about as safe: either a global, ID-less, side-effect-free
 * query, or a call already exercised in an earlier, narrower, manual
 * pass this session without incident. Any method whose real behavior
 * could plausibly touch surface/swap/lock/buffer-submission machinery
 * with synthetic/unvalidated state is recorded here with its real shape
 * (for documentation and for a future, deliberately-staged test with
 * real setup) but marked `report_skipped()` and NEVER actually invoked.
 * Do not "upgrade" a skipped test to a live one without first
 * establishing a real, valid setup sequence (a genuinely created/bound
 * surface, etc.) - see #43 for what happens otherwise.
 */

#ifndef ATIRADEONX1000_TESTS_COMMON_H
#define ATIRADEONX1000_TESTS_COMMON_H

#include <IOKit/IOKitLib.h>
#include <mach/mach.h>
#include <stdio.h>
#include <string.h>

/* Real IOReturn values, confirmed by direct inspection of this system's
 * own /System/Library/Frameworks/IOKit.framework/.../IOReturn.h. */
#define TEST_kIOReturnSuccess        0x00000000
#define TEST_kIOReturnError          0xe00002bc
#define TEST_kIOReturnNoMemory       0xe00002bd
#define TEST_kIOReturnNoResources    0xe00002be
#define TEST_kIOReturnBadArgument    0xe00002c2
#define TEST_kIOReturnUnsupported    0xe00002c7
#define TEST_kIOReturnCannotLock     0xe00002cc
#define TEST_kIOReturnNotAttached    0xe00002d9
#define TEST_kIOReturnUnsupportedMode 0xe00002e6
#define TEST_kIOReturnNotFound       0xe00002f0

/* type dispatch confirmed from IOATIR500Accelerator::newUserClient
 * (Sources/IOATIR500Accelerator_NewUserClient.cpp): 0=Surface, 1=GL,
 * 2=2D, 3=DVD. */
#define CLIENT_TYPE_SURFACE 0
#define CLIENT_TYPE_GL      1
#define CLIENT_TYPE_2D      2
#define CLIENT_TYPE_DVD     3

/* extern, not static: this header is included by every test_*.c file,
 * and each needs to increment the SAME counters (a `static` file-scope
 * variable in a header gives every translation unit its own private
 * copy, silently making main.c's own final summary always read 0 -
 * found via this exact symptom while running the full 78-method
 * harness live). Defined once in main.c. */
extern int g_testsRun;
extern int g_testsUnexpected;
extern int g_testsSkipped;

static const char *ioreturn_name(kern_return_t r) {
    switch ((unsigned int)r) {
        case TEST_kIOReturnSuccess: return "kIOReturnSuccess";
        case TEST_kIOReturnError: return "kIOReturnError";
        case TEST_kIOReturnNoMemory: return "kIOReturnNoMemory";
        case TEST_kIOReturnNoResources: return "kIOReturnNoResources";
        case TEST_kIOReturnBadArgument: return "kIOReturnBadArgument";
        case TEST_kIOReturnUnsupported: return "kIOReturnUnsupported";
        case TEST_kIOReturnCannotLock: return "kIOReturnCannotLock";
        case TEST_kIOReturnNotAttached: return "kIOReturnNotAttached";
        case TEST_kIOReturnUnsupportedMode: return "kIOReturnUnsupportedMode";
        case TEST_kIOReturnNotFound: return "kIOReturnNotFound";
        default: return "???";
    }
}

/* Finds the live ATIRadeonX1000 IOService. Real registered IOClass name
 * confirmed via `ioreg -c ATIRadeonX1000` on this machine - matching on
 * this exact class name (rather than the base IOATIR500Accelerator) is
 * safest since it's the one actually observed live in the registry. */
static io_service_t find_accelerator_service(void) {
    CFMutableDictionaryRef matching = IOServiceMatching("ATIRadeonX1000");
    if (matching == NULL) {
        return IO_OBJECT_NULL;
    }
    return IOServiceGetMatchingService(kIOMasterPortDefault, matching);
}

static kern_return_t open_user_client(io_service_t service, UInt32 type, io_connect_t *outConnect) {
    return IOServiceOpen(service, mach_task_self(), type, outConnect);
}

/* Records a call's outcome. At this "prove out the structure" stage we
 * are not yet asserting a specific expected IOReturn per method (that
 * needs the fuller correctness pass #42 also calls for) - we ARE
 * asserting the round trip itself behaves sanely: a real IOReturn code
 * comes back (not a hang, not a kernel panic, not a wildly out-of-range
 * value), which is exactly what proves the harness's own call shape
 * (selector index, scalar in/out counts, struct sizes) matches what the
 * live kernel object expects. `expectedOneOf` is a NULL-terminated list
 * of IOReturn values considered sane for this specific call, given real
 * driver/hardware state (e.g. a texture ID we made up should sanely
 * come back kIOReturnBadArgument or kIOReturnNotFound, not Success).
 */
static void report(const char *testName, kern_return_t result, const kern_return_t *expectedOneOf) {
    int ok = 0;
    int i;
    g_testsRun++;
    if (expectedOneOf == NULL) {
        ok = 1; /* no specific expectation recorded yet for this call */
    } else {
        for (i = 0; expectedOneOf[i] != (kern_return_t)-1; i++) {
            if (result == expectedOneOf[i]) {
                ok = 1;
                break;
            }
        }
    }
    printf("[%s] %s -> 0x%08x (%s)\n", ok ? "OK" : "UNEXPECTED", testName,
           (unsigned int)result, ioreturn_name(result));
    if (!ok) {
        g_testsUnexpected++;
    }
}

/* Records a method's real (or best-available) shape WITHOUT calling it -
 * see the safety note at the top of this file for why. `reason` should
 * name the real risk (e.g. "touches surface/swap state - see #43") so a
 * future, deliberate staged-setup test knows what it needs to establish
 * first before this can be safely upgraded to a live `report()` call. */
static void report_skipped(const char *testName, const char *reason) {
    g_testsSkipped++;
    printf("[SKIP] %s -- not run live: %s\n", testName, reason);
}

/* Per-context-class test entry points, one per test_*.c file. */
void run_gl_context_tests(io_service_t service);
void run_2d_context_tests(io_service_t service);
void run_dvd_context_tests(io_service_t service);
void run_surface_context_tests(io_service_t service);

#endif /* ATIRADEONX1000_TESTS_COMMON_H */
