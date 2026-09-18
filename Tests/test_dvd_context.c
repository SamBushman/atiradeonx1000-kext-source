/*
 * Tests/test_dvd_context.c
 *
 * Full coverage of the DVD/VA context (type=3, IOATIR500DVDContext /
 * ATIR500DVDContext) external methods, selectors 0-21 (10 base + 12
 * subclass). Real shapes below come from disassembling the real, live
 * `ATIRadeonX1000VADriver.bundle`; where no call site was found, the
 * class header's own declared C++ signature is used and flagged as
 * unverified. See Tests/common.h's methodology note.
 *
 * SAFETY: as with GL/2D, only global/side-effect-free queries (or ones
 * already manually verified earlier this session without incident) are
 * actually invoked live - see Tests/common.h's safety note and #43.
 */

#include "common.h"

/* selector 0: set_surface(UInt32 surfaceID, UInt32 modeBits, SInt32
 * flagCount) - RESOLVED (issue #42 test-harness pass): real signature
 * CORRECTED from a guessed 4-param shape to the real 3-param one, via
 * both the real mangled symbol
 * (__ZN19IOATIR500DVDContext11set_surfaceEm21eIODVDContextModeBitsi) and
 * a full real decompile (Sources/IOATIR500DVDContext_SetSurface.cpp),
 * matching the real wire-shape evidence (3 real scalar inputs, VA bundle
 * offset 0x27f4) exactly - no longer an open discrepancy. Real body
 * rebinds this context to a surface (real requirement-bits/ownership
 * bookkeeping, two unnamed vtable calls) - a genuine surface-binding
 * mutation regardless of the now-resolved signature - skip. */
static void test_set_surface(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD set_surface(sel 0)", "real surface-binding mutation (signature now resolved, see #42)");
}

/* selector 1: get_config(UInt32*,UInt32*,UInt32*) - real evidence: VA
 * bundle offset 0x26bc (_AVAGetRendererInfo), scalarO with output
 * capacity 2 observed (a caller requesting fewer than the max 3 is
 * allowed). Already manually verified live earlier this session without
 * incident. Global query, safe. */
static void test_get_config(io_connect_t connect) {
    int out0 = -1, out1 = -1, out2 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 1, 0, 3, &out0, &out1, &out2);
    report("DVD get_config(sel 1)", r, NULL);
    if (r == TEST_kIOReturnSuccess) printf("    out={%d,%d,%d}\n", out0, out1, out2);
}

/* selector 2: get_status(UInt32*) - already manually verified live
 * earlier this session (returned kIOReturnSuccess, out0=0) without
 * incident. No call site independently found in this bundle pass, but
 * the header's 0-in/1-out shape is already empirically confirmed safe
 * and working. Global query. */
static void test_get_status(io_connect_t connect) {
    int out0 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 2, 0, 1, &out0);
    report("DVD get_status(sel 2)", r, NULL);
    if (r == TEST_kIOReturnSuccess) printf("    out0=%d\n", out0);
}

/* selector 3: get_surface_size(SInt32*,SInt32*,SInt32*,SInt32*) - no
 * real call site found in this bundle; header signature used (0 in / 4
 * out), UNVERIFIED, but structurally identical to GL's own
 * call-site-CONFIRMED get_surface_size shape and equally global/
 * ID-less - safe to try. */
static void test_get_surface_size(io_connect_t connect) {
    int d0 = -1, d1 = -1, d2 = -1, d3 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 3, 0, 4, &d0, &d1, &d2, &d3);
    report("DVD get_surface_size(sel 3, shape unverified but low-risk)", r, NULL);
    if (r == TEST_kIOReturnSuccess) printf("    dims={%d,%d,%d,%d}\n", d0, d1, d2, d3);
}

/* selector 4: lock_all_buffers(UInt32,UInt32*,UInt32*) per header (1 in
 * / 2 out), but real evidence (VA bundle offset 0x3300,
 * _AVAGetRendererInfo) shows a structureO call with scalarInputCount=1
 * and a 256-BYTE output buffer - drastically more than 2 plain UInt32
 * outputs (8 bytes). Real shape clearly does not match the header's
 * assumed simple-scalar-output signature. This is a lock/buffer
 * operation regardless - skip unconditionally. */
static void test_lock_all_buffers(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD lock_all_buffers(sel 4)", "lock family + real shape is a 256-byte structureO, not simple scalars - see #43 and #42");
}

/* selector 5: unlock_memory(UInt32,UInt32*) - no direct call site found
 * in this bundle for the DVD variant specifically, but this is the same
 * named method that (on the 2D side) drives submit_swap_buffer via its
 * negative-lock-type path - never run without valid setup. */
static void test_unlock_memory(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD unlock_memory(sel 5)", "lock/swap family - see #43");
}

/* selector 6: write_buffer(UInt32*,UInt32 byteCount) - no call site
 * found in this bundle; header signature used, UNVERIFIED. Writes real
 * buffer contents - skip. */
static void test_write_buffer(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD write_buffer(sel 6)", "writes real buffer contents; shape unverified");
}

/* selector 7: finish(void) - already manually verified live earlier
 * this session (returned kIOReturnBadArgument, consistent with a
 * global 0-in/0-out call made before any real DVD context setup)
 * without incident. Global call, safe. */
static void test_finish(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 7, 0, 0);
    report("DVD finish(sel 7)", r, NULL);
}

/* selector 8: declare_image(UInt32,UInt32,UInt32,UInt32*) - CONFIRMED:
 * scalarO, in=3/out=1 (matches signature exactly). Evidence: VA bundle
 * offset 0x35c0 (_AVAGetRendererInfo). Allocates a real resource - skip. */
static void test_declare_image(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD declare_image(sel 8)", "real resource allocation - see #43");
}

/* selector 9: delete_image(UInt32) - CONFIRMED: structureI, in=1,
 * struct=0 (matches signature exactly). Evidence: VA bundle offset
 * 0x2978 (_AVAGetRendererInfo). Deletes a real resource by ID - skip. */
static void test_delete_image(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD delete_image(sel 9)", "real resource deletion, bogus ID - see #43");
}

/* selector 10 (subclass show_buffer) - body is CONFIRMED (prior
 * decompile) to be a thin lock wrapper delegating to a REAL EMPTY NO-OP
 * (ATIR500Surface::showbuffer). No call site found for its wire shape
 * in this bundle; header signature used (2 params), UNVERIFIED. Still a
 * lock-wrapper regardless of the no-op body - skip for shape/lock
 * reasons rather than relying on the no-op body being unconditional. */
static void test_show_buffer(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD show_buffer(sel 10)", "lock wrapper; shape unverified");
}

/* selector 11 (dvd_setup_overlay) - body is CONFIRMED real (stores
 * geometry into shared surface fields, not a no-op). No call site found
 * for its wire shape; header signature used (5 params), UNVERIFIED.
 * Mutates real shared surface state - skip. */
static void test_dvd_setup_overlay(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD dvd_setup_overlay(sel 11)", "mutates real shared surface geometry; shape unverified");
}

/* selector 12 (dvd_enable_overlay) - body is CONFIRMED to be a REAL
 * EMPTY NO-OP in this exact kext build (both enable_overlay/
 * disable_overlay). Shape (1 param per header) UNVERIFIED via call
 * site, but the confirmed no-op body makes this safe to try regardless
 * of input - a wrong scalar count is safely rejected by the kernel's
 * own argument-count check before the (no-op) body would run anyway. */
static void test_dvd_enable_overlay(io_connect_t connect) {
    UInt32 enable = 0;
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 12, 0, sizeof(enable), &enable);
    report("DVD dvd_enable_overlay(sel 12, confirmed no-op body)", r, NULL);
}

/* selector 13 (read_regs) - real hardware register read (same shape
 * family as 2D's own read_regs). No call site found in this bundle;
 * header signature used, UNVERIFIED encoding - skip (real register
 * reads with an unconfirmed input encoding are exactly the kind of call
 * this policy exists to avoid). */
static void test_read_regs(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD read_regs(sel 13)", "real hardware register read, input encoding unconfirmed");
}

/* selector 14 (write_regs, DVD's own 2-scalar-param variant per the
 * header's own note that it differs from 2D's array-based version) -
 * writes a real hardware register - skip unconditionally regardless of
 * shape confidence. */
static void test_write_regs(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD write_regs(sel 14)", "writes a real hardware register - never fuzz this");
}

/* selector 15 (dvd_setup_subpicture) - body is CONFIRMED to be a REAL
 * EMPTY NO-OP in this exact kext build. Shape (3 params per header)
 * UNVERIFIED via call site, but same reasoning as selector 12 applies -
 * safe to try regardless of input since the body is a confirmed no-op. */
static void test_dvd_setup_subpicture(io_connect_t connect) {
    UInt32 args[3] = {0, 0, 0};
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 15, 0, sizeof(args), args);
    report("DVD dvd_setup_subpicture(sel 15, confirmed no-op body)", r, NULL);
}

/* selector 16 (set_macrovision) - RESOLVED (issue #42 test-harness
 * pass): the header's own 1-param signature is CORRECT for what the real
 * body actually uses (Sources/ATIR500DVDContext_SetMacrovision.cpp) - the
 * apparent mismatch against real wire evidence (VA bundle offset 0x52b8,
 * 2 real scalar inputs) is this project's own well-established
 * "argument-dropped" decompiler artifact (the wire sends 2, the compiled
 * body only ever reads the first), not a signature error. Real
 * hardware-facing side effect either way - skip. */
static void test_set_macrovision(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD set_macrovision(sel 16)", "real display side effect (signature discrepancy now resolved as argument-dropped, see #42)");
}

/* selector 17 (dvd_enable_deint) - CONFIRMED: scalarO, in=1/out=0.
 * Evidence: VA bundle offset 0x31ec (_AVAGetRendererInfo). Body is
 * CONFIRMED real (stores a mode into a real surface field, not a
 * no-op) - a real side effect, though a narrow one (nothing reads the
 * field back per this project's own decompile). Skipped out of caution
 * since it's a real, non-no-op state mutation. */
static void test_dvd_enable_deint(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD dvd_enable_deint(sel 17)", "real (non-no-op) surface-field mutation");
}

/* selector 18: doIDCT(sATIDVDIDCTInfo*,sATIDVDIDCTParams*) - CONFIRMED:
 * structureIO, structureInputSize=56 bytes (matches this project's
 * earlier-established finding). Evidence: VA bundle offset 0x60f4
 * (_AVAGetRendererInfo). Drives the real, independent IDCT hardware
 * engine from a synthetic all-zero 56-byte struct - exactly the kind of
 * call this safety policy exists to prevent (unknown real field
 * layout, real hardware engine, same risk class as #43). Never run
 * live without a decoded field layout and valid state. */
static void test_do_idct(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD doIDCT(sel 18)", "drives real IDCT hardware from an unknown 56-byte struct layout - see #43");
}

/* selector 19: wait_for_stamps(UInt32,UInt32) - CONFIRMED: structureI,
 * in=2, struct=0 (matches signature exactly). Evidence: VA bundle
 * offset 0x2d48 (_AVAGetRendererInfo). Same fence-wait architecture as
 * GL's confirmed-safe wait_for_stamp - waiting on stamp/tag 0 is always
 * already-reached, safe to run. */
static void test_wait_for_stamps(io_connect_t connect) {
    UInt32 args[2] = {0, 0};
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 19, 0, sizeof(args), args);
    report("DVD wait_for_stamps(sel 19, 0,0)", r, NULL);
}

/* selector 20: check_stamps(UInt32,UInt32,UInt32*) - CONFIRMED: scalarO,
 * in=2/out=1 (matches signature exactly). Evidence: VA bundle offset
 * 0x2cc0/0x44f8/0x5158 (_AVAGetRendererInfo). A non-blocking poll, same
 * safe reasoning as wait_for_stamps. */
static void test_check_stamps(io_connect_t connect) {
    int outBothDone = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 20, 2, 1, 0, 0, &outBothDone);
    report("DVD check_stamps(sel 20, 0,0)", r, NULL);
    if (r == TEST_kIOReturnSuccess) printf("    outBothDone=%d\n", outBothDone);
}

/* selector 21: setup_buffers(UInt32,UInt32,UInt32,UInt32,UInt32) -
 * CONFIRMED: scalarO, in=5/out=0 (matches signature exactly). Evidence:
 * VA bundle offset 0x328c/0x44f8(dup)/0x5158(dup) (_AVAGetRendererInfo).
 * Real per-plane IDCT-surface geometry setup - a real mutation of IDCT
 * working-buffer state from synthetic zero geometry - skip. */
static void test_setup_buffers(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD setup_buffers(sel 21)", "real IDCT working-buffer geometry setup - see #43");
}

void run_dvd_context_tests(io_service_t service) {
    io_connect_t connect = IO_OBJECT_NULL;
    kern_return_t kr = open_user_client(service, CLIENT_TYPE_DVD, &connect);
    if (kr != TEST_kIOReturnSuccess) {
        printf("[FAIL] could not open DVD user client: 0x%08x (%s)\n", (unsigned int)kr, ioreturn_name(kr));
        g_testsUnexpected++;
        return;
    }
    printf("-- DVD context (type=3), all 22 selectors --\n");
    test_set_surface(connect);
    test_get_config(connect);
    test_get_status(connect);
    test_get_surface_size(connect);
    test_lock_all_buffers(connect);
    test_unlock_memory(connect);
    test_write_buffer(connect);
    test_finish(connect);
    test_declare_image(connect);
    test_delete_image(connect);
    test_show_buffer(connect);
    test_dvd_setup_overlay(connect);
    test_dvd_enable_overlay(connect);
    test_read_regs(connect);
    test_write_regs(connect);
    test_dvd_setup_subpicture(connect);
    test_set_macrovision(connect);
    test_dvd_enable_deint(connect);
    test_do_idct(connect);
    test_wait_for_stamps(connect);
    test_check_stamps(connect);
    test_setup_buffers(connect);
    IOServiceClose(connect);
}
