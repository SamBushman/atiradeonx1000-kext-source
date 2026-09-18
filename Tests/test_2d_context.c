/*
 * Tests/test_2d_context.c
 *
 * Full coverage of the 2D context (type=2, IOATIR5002DContext /
 * ATIR5002DContext) external methods, selectors 0-18 (16 base + 3
 * subclass). Real shapes below come from disassembling the real, live
 * `ATIRadeonX1000GA.plugin` (`otool -tV`) wherever a call site was
 * found; where none was found, the class header's own declared C++
 * signature is used instead and flagged as unverified (this project's
 * "argument-dropped" artifact means such a guess can still be wrong -
 * see Tests/common.h's methodology note).
 *
 * SAFETY: as with GL, only global/side-effect-free queries are actually
 * invoked live. Everything touching surface/swap/lock/image-resource
 * state is recorded with its shape and skipped - see Tests/common.h's
 * safety note and issue #43.
 */

#include "common.h"

/* selector 0: set_surface(UInt32,UInt32,UInt32,UInt32) - no real call
 * site found in this bundle; header's own signature used (4 in / 0 out),
 * UNVERIFIED. Mutates bound surface regardless - skip. */
static void test_set_surface(io_connect_t connect) {
    (void)connect;
    report_skipped("2D set_surface(sel 0)", "mutates bound surface state; shape unverified - see #43");
}

/* selector 1: get_config(UInt32*,UInt32*,UInt32*) - real evidence: GA
 * plugin offset 0x26f0 (_Start), scalarO with output capacity 2
 * observed (scalarInputCount register unresolved in that call, but 0 is
 * the only sane value for a 3-output getter with no ID param, matching
 * GL/DVD's own get_config shape). Global query, safe. */
static void test_get_config(io_connect_t connect) {
    int out0 = -1, out1 = -1, out2 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 1, 0, 3, &out0, &out1, &out2);
    report("2D get_config(sel 1)", r, NULL);
    if (r == TEST_kIOReturnSuccess) printf("    out={%d,%d,%d}\n", out0, out1, out2);
}

/* selector 2: get_surface_info(UInt32,SInt32*,SInt32*,SInt32*) - real
 * evidence: GA plugin offset 0x565c (_radeonCopyRegion), structureO
 * shape (scalarInputCount=2, structureOutputSize capacity=48 bytes) -
 * this CONTRADICTS the header's assumed plain-3-scalar-output shape
 * entirely (48 bytes >> 3 words). Real selector-to-name attribution
 * here needs re-verification, not just the count - flagged, not
 * asserted. NOT run live either way (ID-indexed + shape uncertain). */
static void test_get_surface_info(io_connect_t connect) {
    (void)connect;
    report_skipped("2D get_surface_info(sel 2)", "real evidence conflicts with assumed shape - needs re-verification, see #42");
}

/* selector 3: swap_surface(UInt32,UInt32*) - CONFIRMED: scalarO, in=1/
 * out=1. Evidence: GA plugin offset 0x1924 (_SwapSurface). This IS the
 * real present/flip mechanism - directly in the family that crashed the
 * stock driver in #43 (drives the same submit_swap_buffer path via
 * unlock_memory's negative-lock-type route). Never run live without a
 * real, validly-created and populated surface. */
static void test_swap_surface(io_connect_t connect) {
    (void)connect;
    report_skipped("2D swap_surface(sel 3)", "real present/flip path - see #43, do not run without valid surface setup");
}

/* selector 4: scale_surface(UInt32,UInt32,UInt32) - real evidence: GA
 * plugin offset 0x27e8 (_AllocateSurface), scalarO in=3 (output
 * capacity unresolved). Surface-state mutation - skip. */
static void test_scale_surface(io_connect_t connect) {
    (void)connect;
    report_skipped("2D scale_surface(sel 4)", "surface-state mutation - see #43");
}

/* selector 5: lock_memory(UInt32,UInt32*,UInt32*) - CONFIRMED: scalarO,
 * in=1/out=2 (matches signature exactly). Evidence: GA plugin offset
 * 0x17e4 (_LockSurface). Named explicitly in the safety policy's
 * danger family - skip. */
static void test_lock_memory(io_connect_t connect) {
    (void)connect;
    report_skipped("2D lock_memory(sel 5)", "lock/swap family - see #43");
}

/* selector 6: unlock_memory(UInt32,UInt32*) - CONFIRMED: scalarO, in=1/
 * out=1 (matches signature exactly). Evidence: GA plugin offset 0x1894
 * (_UnlockSurface). This is the call whose negative-lock-type variant
 * triggers swap_surface -> submit_swap_buffer, the exact function that
 * crashed the stock driver in #43 - skip unconditionally. */
static void test_unlock_memory(io_connect_t connect) {
    (void)connect;
    report_skipped("2D unlock_memory(sel 6)", "drives submit_swap_buffer on negative lock type - THE #43 crash path, never run without valid setup");
}

/* selector 7: header declares finish(void) (0 params), but the one real
 * call site found (GA plugin offset 0x3f14, function named
 * _WaitComplete) shows structureI with scalarInputCount=1 - a shape
 * that doesn't match "finish(void)" at all, and the calling function's
 * own name ("WaitComplete") reads much more like a fence-wait
 * (analogous to GL's wait_for_stamp) than an unconditional finish. Real
 * selector-to-name attribution here is uncertain - flagged, not
 * asserted. Tried live with the fence-wait interpretation (1 scalar
 * input = 0, i.e. "wait for stamp/tag 0") since that's the same
 * always-safe shape GL's own confirmed wait_for_stamp uses; a shape
 * mismatch is safely rejected by the kernel's own argument-count check
 * before any real method body runs, so this carries the same low risk
 * as trying any other candidate shape - it does NOT touch surface/swap
 * state either way. */
static void test_finish_or_wait(io_connect_t connect) {
    UInt32 stampOrTag = 0;
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 7, 0, sizeof(stampOrTag), &stampOrTag);
    report("2D finish-or-wait(sel 7, real name uncertain, tried as wait(0))", r, NULL);
}

/* selector 8: declare_image(UInt32,UInt32,UInt32,UInt32*) - CONFIRMED:
 * scalarO, in=3/out=1 (matches signature exactly). Evidence: GA plugin
 * offset 0x2984 (_AllocateSurface). Allocates a real resource - skip. */
static void test_declare_image(io_connect_t connect) {
    (void)connect;
    report_skipped("2D declare_image(sel 8)", "real resource allocation - see #43");
}

/* selector 9: create_image(UInt32,UInt32,UInt32*,UInt32*) - CONFIRMED:
 * scalarO, in=2/out=2 (matches signature exactly). Evidence: GA plugin
 * offset 0x2a78 (_AllocateSurface). Allocates a real resource - skip. */
static void test_create_image(io_connect_t connect) {
    (void)connect;
    report_skipped("2D create_image(sel 9)", "real resource allocation - see #43");
}

/* selector 10: create_transfer(UInt32,UInt32,UInt32*,UInt32*) -
 * CONFIRMED: scalarO, in=2/out=2 (matches signature exactly). Evidence:
 * GA plugin offset 0x2884 (_AllocateSurface). Allocates a real
 * AGP-backed buffer - skip. */
static void test_create_transfer(io_connect_t connect) {
    (void)connect;
    report_skipped("2D create_transfer(sel 10)", "real GART-backed allocation - see #43");
}

/* selector 11: delete_image(UInt32) - CONFIRMED: structureI, in=1,
 * struct=0. Evidence: GA plugin offset 0x3fe4 (_FreeSurface). Deletes a
 * real resource by ID - skip. */
static void test_delete_image(io_connect_t connect) {
    (void)connect;
    report_skipped("2D delete_image(sel 11)", "real resource deletion, bogus ID - see #43");
}

/* selector 12: wait_image(UInt32) - CONFIRMED: structureI, in=1,
 * struct=0. Evidence: GA plugin offset 0x410c/0x4364
 * (_createTextureBuffer/_createOffscreenBuffer). Unlike GL's
 * wait_for_stamp (a raw monotonic counter value), this takes a real
 * textureID that indexes per-texture bookkeeping - same ID-indexed-
 * lookup risk as #43, skip. */
static void test_wait_image(io_connect_t connect) {
    (void)connect;
    report_skipped("2D wait_image(sel 12)", "ID-indexed fence wait on a bogus texture ID - see #43");
}

/* selector 13: set_surface_paging_options(void*,void*,UInt32,UInt32*) -
 * body is CONFIRMED (this project's own prior decompile) to
 * unconditionally return kIOReturnUnsupported with no real logic at
 * all, so it's genuinely safe regardless of input - but no real
 * call-site evidence exists for its wire shape (struct-based per the
 * signature, exact structureI/O layout unconfirmed), so it can't be
 * called correctly. Skipped for shape-uncertainty, not safety. */
static void test_set_surface_paging_options(io_connect_t connect) {
    (void)connect;
    report_skipped("2D set_surface_paging_options(sel 13)", "known-safe stub body, but real wire shape unverified");
}

/* selector 14: set_surface_vsync_options(...) - same deliberate-stub
 * pattern and same shape-uncertainty as selector 13. */
static void test_set_surface_vsync_options(io_connect_t connect) {
    (void)connect;
    report_skipped("2D set_surface_vsync_options(sel 14)", "known-safe stub body, but real wire shape unverified");
}

/* selector 15: set_macrovision(UInt32) - body is CONFIRMED (prior
 * decompile) to iterate real display connections and toggle a real
 * copy-protection signal - not memory-unsafe, but a real side effect on
 * physical display output, and no call-site evidence exists in this
 * bundle for its exact shape. Skipped for shape-uncertainty and to
 * avoid an unwanted real-hardware side effect. */
static void test_set_macrovision(io_connect_t connect) {
    (void)connect;
    report_skipped("2D set_macrovision(sel 15)", "real display-output side effect + unverified shape");
}

/* selector 16 (subclass ATIR5002DContext::read_regs) -
 * (UInt32*,UInt32*,UInt32,UInt32*) - real evidence: GA plugin offset
 * 0x2244, function named _GetBeamPosition - a real hardware-register
 * read (beam position, used for vsync timing), structureIO shape with
 * structureInputSize=4 bytes / structureOutputSize capacity=4 bytes.
 * Plausible name match (reading a register) but not touching surface/
 * swap/buffer bookkeeping the way the crash family does - however the
 * exact 4-byte input encoding (which register) is unconfirmed, so a
 * synthetic all-zero payload's effect on real register-read code is
 * unverified. Skipped out of the same "don't call what you can't reason
 * about" caution as the ID-indexed methods above. */
static void test_read_regs(io_connect_t connect) {
    (void)connect;
    report_skipped("2D read_regs(sel 16)", "real hardware register read, input encoding unconfirmed");
}

/* selector 17 (subclass write_regs) - no real call site found in this
 * bundle; header signature used (2 params), UNVERIFIED. Writes hardware
 * registers - skip unconditionally regardless of shape confidence. */
static void test_write_regs(io_connect_t connect) {
    (void)connect;
    report_skipped("2D write_regs(sel 17)", "writes real hardware registers - never fuzz this");
}

/* selector 18 (subclass write_2_regs) - same as write_regs: no call
 * site found, header signature UNVERIFIED, writes hardware registers -
 * skip unconditionally. */
static void test_write_2_regs(io_connect_t connect) {
    (void)connect;
    report_skipped("2D write_2_regs(sel 18)", "writes real hardware registers - never fuzz this");
}

void run_2d_context_tests(io_service_t service) {
    io_connect_t connect = IO_OBJECT_NULL;
    kern_return_t kr = open_user_client(service, CLIENT_TYPE_2D, &connect);
    if (kr != TEST_kIOReturnSuccess) {
        printf("[FAIL] could not open 2D user client: 0x%08x (%s)\n", (unsigned int)kr, ioreturn_name(kr));
        g_testsUnexpected++;
        return;
    }
    printf("-- 2D context (type=2), all 19 selectors --\n");
    test_set_surface(connect);
    test_get_config(connect);
    test_get_surface_info(connect);
    test_swap_surface(connect);
    test_scale_surface(connect);
    test_lock_memory(connect);
    test_unlock_memory(connect);
    test_finish_or_wait(connect);
    test_declare_image(connect);
    test_create_image(connect);
    test_create_transfer(connect);
    test_delete_image(connect);
    test_wait_image(connect);
    test_set_surface_paging_options(connect);
    test_set_surface_vsync_options(connect);
    test_set_macrovision(connect);
    test_read_regs(connect);
    test_write_regs(connect);
    test_write_2_regs(connect);
    IOServiceClose(connect);
}
