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

/* selector 0: set_surface(id, modeBits, flagCount) - table: flags 4, 3 scalars, struct 0. Surface id 0 = "detach":
 * no surface is found or bound, this context's surface pointer stays NULL, and ATIR500DVDContext::update_surface
 * (guarded by a bound-surface check) does nothing. Binding a real surface is NOT tested. */
static void test_set_surface(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 0, 3, 0, 0, 0, 0, NULL);
    report("DVD set_surface(sel 0, id 0 = detach)", r, kExpectSuccess);
}

/* selector 1: get_config(UInt32*,UInt32*,UInt32*) - real evidence: VA
 * bundle offset 0x26bc (_AVAGetRendererInfo), scalarO with output
 * capacity 2 observed (a caller requesting fewer than the max 3 is
 * allowed). Already manually verified live earlier this session without
 * incident. Global query, safe. */
static void test_get_config(io_connect_t connect) {
    int out0 = -1, out1 = -1;
    /* dispatch table: flags 0, 0 in, 2 out (stock body reads two accelerator fields only) */
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 1, 0, 2, &out0, &out1);
    report("DVD get_config(sel 1)", r, kExpectSuccess);
    if (r == TEST_kIOReturnSuccess) printf("    out={%d,%d}\n", out0, out1);
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
    int d0 = -1, d1 = -1;
    /* dispatch table: flags 0, 0 in, 2 out. Stock body checks this+0xf8 (the bound surface) for NULL
     * first and returns kIOReturnError, so on a fresh connection it is safe (unlike set_macrovision). */
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 3, 0, 2, &d0, &d1);
    report("DVD get_surface_size(sel 3, unbound surface)", r, kExpectUnboundGuard);
    if (r == TEST_kIOReturnSuccess) printf("    dims={%d,%d}\n", d0, d1);
}

/* selector 4: lock_all_buffers(param, *out) - table: flags 2, 1 scalar in, struct-out 256 bytes. Stock body with no
 * bound surface: takes the lock, zero-fills the first 0x68 bytes of the output (kernel-side; not observable on an
 * error return), returns CannotLock. (With a bound
 * surface it allocates VRAM and retries up to 1000 times: NOT tested.) */
static void test_lock_all_buffers(io_connect_t connect) {
    unsigned char out[256];
    memset(out, 0xAA, sizeof(out));
    IOByteCount outSize = sizeof(out);
    kern_return_t r = IOConnectMethodScalarIStructureO(connect, 4, 1, &outSize, 0, out);
    report("DVD lock_all_buffers(sel 4, no surface bound)", r, kExpectCannotLock);
}

/* selector 5: unlock_memory(lockType, *outTag) - table: flags 0, 1 in, 1 out. No bound surface -> BadArgument (the
 * METHOD's own result; outTag = 0 kernel-side, not observable on an error return). */
static void test_unlock_memory(io_connect_t connect) {
    int out = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 5, 1, 1, 0, &out);
    report("DVD unlock_memory(sel 5, no surface bound)", r, kExpectBadArgument);
    (void)out;
}

/* selector 6: write_buffer(sIODVDContextWriteBufferData*, size) - table: flags 3, struct-in variable. NEVER RUN on a
 * connection with no bound surface: the stock body loads boundSurface+0xb70+off BEFORE it checks boundSurface for
 * NULL, so on a fresh connection it is a kernel NULL dereference - it panics the stock driver exactly like DVD
 * set_macrovision does (#43). Found by reading the stock decompile; reproduced faithfully in
 * Sources/IOATIR500DVDContext_ExternalMethods.cpp. Testable only after a real set_surface bound a surface. */
static void test_write_buffer(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD write_buffer(sel 6)", "PANICS the stock driver when no surface is bound (derefs boundSurface+0xb70 before its NULL check) - second instance of the #43 bug");
}

/* selector 7: finish(void) - already manually verified live earlier
 * this session (returned kIOReturnBadArgument, consistent with a
 * global 0-in/0-out call made before any real DVD context setup)
 * without incident. Global call, safe. */
static void test_finish(io_connect_t connect) {
    /* dispatch table: IOATIR500DVDContext::finish(), flags 4 (scalarI/structI), 0 scalars, size 0 */
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 7, 0, 0, NULL);
    report("DVD finish(sel 7)", r, kExpectSuccess);
}

/* selector 8: declare_image(p1, size/format, bytes, *outHandle) - table: flags 0, 3 in, 1 out. Zero size or bytes ->
 * BadArgument before the lock or any allocation. */
static void test_declare_image(io_connect_t connect) {
    int out = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 8, 3, 1, 0, 0, 0, &out);
    report("DVD declare_image(sel 8, zero size)", r, kExpectBadArgument);
}

/* selector 9: delete_image(id) - table: flags 4, 1 scalar. Shared allocator not yet created on a fresh connection
 * -> NoResources. */
static void test_delete_image(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 9, 1, 0, 0x7fff, NULL);
    report("DVD delete_image(sel 9, no allocator yet)", r, kExpectNoResources);
}

/* selector 10: show_buffer(index, p2) - table: flags 0, 2 in, 0 out. Guarded wrapper: hardware not up -> NotReady,
 * no bound surface -> Error, before reaching the (no-op) surface method. */
static void test_show_buffer(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 10, 2, 0, 0, 0);
    report("DVD show_buffer(sel 10, no surface bound)", r, kExpectUnboundGuard);
}

/* selector 11: dvd_setup_overlay(x,y,w,h,p5) - table: flags 0, 5 in, 0 out. Same guard as selector 10 (the write to
 * the surface's overlay geometry happens only after the guard passes). */
static void test_dvd_setup_overlay(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 11, 5, 0, 0, 0, 0, 0, 0);
    report("DVD dvd_setup_overlay(sel 11, no surface bound)", r, kExpectUnboundGuard);
}

/* selector 12 (dvd_enable_overlay) - body is CONFIRMED to be a REAL
 * EMPTY NO-OP in this exact kext build (both enable_overlay/
 * disable_overlay). Shape (1 param per header) UNVERIFIED via call
 * site, but the confirmed no-op body makes this safe to try regardless
 * of input - a wrong scalar count is safely rejected by the kernel's
 * own argument-count check before the (no-op) body would run anyway. */
static void test_dvd_enable_overlay(io_connect_t connect) {
    /* dispatch table: flags 0 (scalarI/scalarO), 1 in, 0 out. Stock wrapper takes the command lock, then
     * returns NotReady if the accelerator is not up, or Error if no surface is bound (this+0xf8 == NULL)
     * BEFORE it reaches the (no-op) overlay code, so it is safe on a fresh connection. */
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 12, 1, 0, 0);
    report("DVD dvd_enable_overlay(sel 12, unbound surface)", r, kExpectUnboundGuard);
}

/* selector 13: ATIR500DVDContext::read_regs - table: flags 3, struct-in and struct-out variable. Same validation as
 * 2D read_regs: sizes differ -> BadArgument; size 0 -> zero registers read. */
static void test_read_regs(io_connect_t connect) {
    IOByteCount outSize = 0;
    kern_return_t r = IOConnectMethodStructureIStructureO(connect, 13, 0, &outSize, NULL, NULL);
    report("DVD read_regs(sel 13, zero registers)", r, kExpectSuccess);
    UInt32 in = 0;
    outSize = 0;
    r = IOConnectMethodStructureIStructureO(connect, 13, sizeof(in), &outSize, &in, NULL);
    report("DVD read_regs(sel 13, in/out sizes differ)", r, kExpectBadArgument);
}

/* selector 14: write_regs(offset, value) - table: flags 0, 2 in, 0 out. NOT run: the stock body writes ONE hardware
 * register unconditionally (once the accelerator is up) with no argument validation at all, so there is no
 * zero-length or rejected form to test. */
static void test_write_regs(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD write_regs(sel 14)", "writes one real hardware register with no validation; no side-effect-free form exists");
}

/* selector 15 (dvd_setup_subpicture) - body is CONFIRMED to be a REAL
 * EMPTY NO-OP in this exact kext build. Shape (3 params per header)
 * UNVERIFIED via call site, but same reasoning as selector 12 applies -
 * safe to try regardless of input since the body is a confirmed no-op. */
static void test_dvd_setup_subpicture(io_connect_t connect) {
    /* dispatch table: flags 0, 4 in, 0 out. Same unbound-surface guard as selector 12. */
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 15, 4, 0, 0, 0, 0, 0);
    report("DVD dvd_setup_subpicture(sel 15, unbound surface)", r, kExpectUnboundGuard);
}

/* selector 16: set_macrovision(enable, p2) - table: flags 0, 2 in, 0 out. NEVER RUN on a connection with no bound
 * surface: it calls getFramebufferIndex() on the NULL bound surface and panics the stock driver (#43). The
 * reproduction lives in Sources/ATIR500DVDContext_SetMacrovision.cpp. */
static void test_set_macrovision(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD set_macrovision(sel 16)", "PANICS the stock driver when no surface is bound: getFramebufferIndex(NULL) (#43); also a real display side effect");
}

/* selector 17: dvd_enable_deint(mode) - table: flags 0, 1 in, 0 out. Same guard as selectors 10/11. */
static void test_dvd_enable_deint(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 17, 1, 0, 0);
    report("DVD dvd_enable_deint(sel 17, no surface bound)", r, kExpectUnboundGuard);
}

/* selector 18: doIDCT(sATIDVDIDCTInfo*, sATIDVDIDCTParams*) - table: flags 3, struct-in variable, struct-out 0.
 * NOT run: drives the real IDCT hardware from a 56-byte info struct and needs a bound surface plus IDCT working
 * buffers set up by setup_buffers/set_surface. The 1000-line body has not been traced for a safe minimal input. */
static void test_do_idct(io_connect_t connect) {
    (void)connect;
    report_skipped("DVD doIDCT(sel 18)", "drives real IDCT hardware; body not traced for a safe minimal input");
}

/* selector 19: wait_for_stamps(UInt32,UInt32) - CONFIRMED: structureI,
 * in=2, struct=0 (matches signature exactly). Evidence: VA bundle
 * offset 0x2d48 (_AVAGetRendererInfo). Same fence-wait architecture as
 * GL's confirmed-safe wait_for_stamp - waiting on stamp/tag 0 is always
 * already-reached, safe to run. */
static void test_wait_for_stamps(io_connect_t connect) {
    /* dispatch table: flags 4, 2 scalars, struct size 0. Stock body only waits for a non-zero argument,
     * so (0,0) makes no call at all. */
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 19, 2, 0, 0, 0, NULL);
    report("DVD wait_for_stamps(sel 19, 0,0)", r, kExpectSuccess);
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

/* selector 21: setup_buffers(top,left,bottom,right,flags) - table: flags 0, 5 in, 0 out. Stock body writes the
 * bound surface's geometry only if a surface is bound AND the hardware is up, otherwise returns NotReady
 * (0xe00002d8). Not under the lock. */
static void test_setup_buffers(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 21, 5, 0, 0, 0, 0, 0, 0);
    report("DVD setup_buffers(sel 21, no surface bound)", r, kExpectUnboundGuard);
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
