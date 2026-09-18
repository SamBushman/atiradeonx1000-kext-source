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

/* selector 0: set_surface(panel/id, modeBits, *out, *outSize) - table: flags 2, 2 scalars in, struct-out variable.
 * With mode bit 0x800 CLEAR the stock body binds the context to a display PANEL (no surface object): it records
 * the panel index (if in range and enabled) in this context, then calls set_destination -> get_buffer_info, which
 * (for an output size of exactly 0x30) only reads accelerator panel fields into the output. Only this per-connection
 * state changes. Binding a real SURFACE (bit 0x800 set) is NOT tested. Runs LAST in this file so the panel binding
 * cannot affect the other 2D tests. */
static void test_set_surface(io_connect_t connect) {
    unsigned char out[0x30];
    memset(out, 0xAA, sizeof(out));
    IOByteCount outSize = sizeof(out);
    kern_return_t r = IOConnectMethodScalarIStructureO(connect, 0, 2, &outSize, 0, 0, out);
    report("2D set_surface(sel 0, panel 0, no surface)", r, kExpectSuccess);
    if (r == TEST_kIOReturnSuccess) {
        UInt32 *d = (UInt32 *)out;
        printf("    outSize=%u info[0..11]={", (unsigned int)outSize);
        { int i; for (i = 0; i < 12; i++) printf("%s0x%x", i ? "," : "", d[i]); }
        printf("}\n");
    }
}

/* selector 1: get_config(UInt32*,UInt32*,UInt32*) - real evidence: GA
 * plugin offset 0x26f0 (_Start), scalarO with output capacity 2
 * observed (scalarInputCount register unresolved in that call, but 0 is
 * the only sane value for a 3-output getter with no ID param, matching
 * GL/DVD's own get_config shape). Global query, safe. */
static void test_get_config(io_connect_t connect) {
    int out0 = -1, out1 = -1;
    /* dispatch table: flags 0, 0 in, 2 out (the old call asked for 3 outputs: rejected) */
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 1, 0, 2, &out0, &out1);
    report("2D get_config(sel 1)", r, kExpectSuccess);
    if (r == TEST_kIOReturnSuccess) printf("    out={%d,%d}\n", out0, out1);
}

/* selector 2: get_surface_info(id/panel, modeBits, *out, *outSize) - table: flags 2, 2 scalars in, struct-out
 * variable. Stock body (mode bit 0x800 clear): a panel index >= the accelerator's panel count -> BadArgument
 * without any call; with bit 0x800 set it looks the id up in the accelerator's live-surface list and returns
 * NotFound for an unknown id. A valid panel index calls ATIR5002DContext::get_buffer_info, which - if the
 * output size is exactly 0x30 - only READS accelerator panel fields into the output struct. */
static void test_get_surface_info(io_connect_t connect) {
    unsigned char out[0x30];
    memset(out, 0xAA, sizeof(out));
    IOByteCount outSize = sizeof(out);
    kern_return_t r = IOConnectMethodScalarIStructureO(connect, 2, 2, &outSize, 0x7fff, 0, out);
    report("2D get_surface_info(sel 2, panel index out of range)", r, kExpectBadArgument);
    outSize = sizeof(out);
    r = IOConnectMethodScalarIStructureO(connect, 2, 2, &outSize, 0x7fff, 0x800, out);
    report("2D get_surface_info(sel 2, unknown surface id)", r, kExpectNotFound);
    outSize = sizeof(out);
    r = IOConnectMethodScalarIStructureO(connect, 2, 2, &outSize, 0, 0, out);
    report("2D get_surface_info(sel 2, panel 0: read-only buffer info)", r, kExpectSuccess);
    if (r == TEST_kIOReturnSuccess) {
        UInt32 *d = (UInt32 *)out;
        printf("    outSize=%u info[0..11]={", (unsigned int)outSize);
        { int i; for (i = 0; i < 12; i++) printf("%s0x%x", i ? "," : "", d[i]); }
        printf("}\n");
    }
}

/* selector 3: swap_surface(lockType, *outTag) - table: flags 0, 1 in, 1 out. Stock body: with no bound surface
 * (this+0x100 == NULL) it returns NoResources (and zeroes the output kernel-side) BEFORE reading anything else. (Outputs of an error return are NOT copied back to the caller by IOKit, so they are not observable here.) */
static void test_swap_surface(io_connect_t connect) {
    int out = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 3, 1, 1, 0, &out);
    report("2D swap_surface(sel 3, no surface bound)", r, kExpectNoResources);
    (void)out;
}

/* selector 4: scale_surface(flags, x, y) - table: flags 0, 3 in, 0 out. No bound surface -> Unsupported. */
static void test_scale_surface(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 4, 3, 0, 0, 0, 0);
    report("2D scale_surface(sel 4, no surface bound)", r, kExpectUnsupported);
}

/* selector 5: lock_memory(lockType, *outAddress, *outSize) - table: flags 0, 1 in, 2 out. Stock body: no bound
 * surface -> CannotLock; kernel-side the first output is set to the sentinel 0xdeadbeef, but (Outputs of an error return are NOT copied back to the caller by IOKit, so they are not observable here.) */
static void test_lock_memory(io_connect_t connect) {
    int out0 = 0, out1 = 0x55555555;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 5, 1, 2, 0, &out0, &out1);
    report("2D lock_memory(sel 5, no surface bound)", r, kExpectCannotLock);
    (void)out0; (void)out1;
}

/* selector 6: unlock_memory(lockType, *outTag) - table: flags 0, 1 in, 1 out. Stock body: no bound surface ->
 * BadArgument (the METHOD's own result; outTag is set to 0 kernel-side, not observable on an error return). It only calls swap_surface for a NEGATIVE lockType when
 * the unlock itself succeeded, which needs a bound surface, so lockType 0 here cannot reach it. The negative-type
 * path is NOT tested. */
static void test_unlock_memory(io_connect_t connect) {
    int out = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 6, 1, 1, 0, &out);
    report("2D unlock_memory(sel 6, lockType 0, no surface bound)", r, kExpectBadArgument);
    (void)out;
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
    /* dispatch table: IOATIR5002DContext::finish(unsigned long), flags 4, 1 scalar, struct size 0.
     * Stock body: 0 = wait on this context's own stamp (same path as GL finish), 1/2 = other waits,
     * else BadArgument. The scalar 0 takes the same path GL finish already runs successfully. */
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 7, 1, 0, 0, NULL);
    report("2D finish(sel 7, mode 0)", r, kExpectSuccess);
}

/* selector 8: declare_image(p1, size/format, bytes, *outHandle) - table: flags 0, 3 in, 1 out. Stock body rejects a
 * zero size or byte count with BadArgument before touching the lock or the allocator. A non-zero call would
 * allocate a real AGP texture and is NOT tested. */
static void test_declare_image(io_connect_t connect) {
    int out = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 8, 3, 1, 0, 0, 0, &out);
    report("2D declare_image(sel 8, zero size)", r, kExpectBadArgument);
}

/* selector 9: create_image(p1, p2, *outLow, *outHigh) - table: flags 0, 2 in, 2 out. p1 == 0 -> BadArgument before
 * any allocation. */
static void test_create_image(io_connect_t connect) {
    int o0 = -1, o1 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 9, 2, 2, 0, 0, &o0, &o1);
    report("2D create_image(sel 9, p1 = 0)", r, kExpectBadArgument);
}

/* selector 10: create_transfer(p1, bytes, *outHandle, *outAddr) - table: flags 0, 2 in, 2 out. bytes == 0 ->
 * BadArgument before any allocation. */
static void test_create_transfer(io_connect_t connect) {
    int o0 = -1, o1 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 10, 2, 2, 0, 0, &o0, &o1);
    report("2D create_transfer(sel 10, bytes = 0)", r, kExpectBadArgument);
}

/* selector 11: delete_image(id) - table: flags 4, 1 scalar. This context's shared allocator is created lazily by
 * the first allocation, so on a fresh connection it is NULL and the stock body returns NoResources. */
static void test_delete_image(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 11, 1, 0, 0x7fff, NULL);
    report("2D delete_image(sel 11, no allocator yet)", r, kExpectNoResources);
}

/* selector 12: wait_image(id) - table: flags 4, 1 scalar. Shared allocator NULL on a fresh connection ->
 * NoResources before any wait. */
static void test_wait_image(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 12, 1, 0, 0x7fff, NULL);
    report("2D wait_image(sel 12, no allocator yet)", r, kExpectNoResources);
}

/* selector 13: set_surface_paging_options - table: flags 3, struct-in 12 bytes, struct-out 12 bytes. The stock
 * body ignores its arguments and returns kIOReturnUnsupported (a deliberate stub). */
static void test_set_surface_paging_options(io_connect_t connect) {
    UInt32 in[3] = {0, 0, 0}, out[3] = {0, 0, 0};
    IOByteCount outSize = sizeof(out);
    kern_return_t r = IOConnectMethodStructureIStructureO(connect, 13, sizeof(in), &outSize, in, out);
    report("2D set_surface_paging_options(sel 13)", r, kExpectUnsupported);
}

/* selector 14: set_surface_vsync_options - same shape and same deliberate Unsupported stub as selector 13. */
static void test_set_surface_vsync_options(io_connect_t connect) {
    UInt32 in[3] = {0, 0, 0}, out[3] = {0, 0, 0};
    IOByteCount outSize = sizeof(out);
    kern_return_t r = IOConnectMethodStructureIStructureO(connect, 14, sizeof(in), &outSize, in, out);
    report("2D set_surface_vsync_options(sel 14)", r, kExpectUnsupported);
}

/* selector 15: set_macrovision(enable) - table: flags 4, 1 scalar. NOT run: the stock body walks every active
 * framebuffer, casts it to IONDRVFramebuffer and calls a display-driver method (code 0x92) on it - a real TV-out
 * / display side effect. */
static void test_set_macrovision(io_connect_t connect) {
    (void)connect;
    report_skipped("2D set_macrovision(sel 15)", "calls the display driver on every active framebuffer (macrovision / TV-out)");
}

/* selector 16: ATIR5002DContext::read_regs(offsets, outValues, inSize, *outSize) - table: flags 3, struct-in and
 * struct-out variable. Stock body: (*outSize != inSize) or a size not a multiple of 4 -> BadArgument BEFORE the
 * lock; otherwise it reads outSize/4 hardware registers through the MMIO window. Both tests here read ZERO
 * registers (size 0) or are rejected (sizes differ), so no register is touched. */
static void test_read_regs(io_connect_t connect) {
    IOByteCount outSize = 0;
    kern_return_t r = IOConnectMethodStructureIStructureO(connect, 16, 0, &outSize, NULL, NULL);
    report("2D read_regs(sel 16, zero registers)", r, kExpectSuccess);
    UInt32 in = 0;
    outSize = 0;
    r = IOConnectMethodStructureIStructureO(connect, 16, sizeof(in), &outSize, &in, NULL);
    report("2D read_regs(sel 16, in/out sizes differ)", r, kExpectBadArgument);
}

/* selector 17: ATIR5002DContext::write_regs(pairs, byteCount) - table: flags 4, 0 scalars, struct variable. A byte
 * count that is not a multiple of 8 -> BadArgument before the lock; a count of 0 -> takes the lock, writes nothing,
 * returns Success. NO register is written by either test. (A real write is never tested.) */
static void test_write_regs(io_connect_t connect) {
    UInt32 in = 0;
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 17, 0, sizeof(in), &in);
    report("2D write_regs(sel 17, 4 bytes: not a multiple of 8)", r, kExpectBadArgument);
    r = IOConnectMethodScalarIStructureI(connect, 17, 0, 0, NULL);
    report("2D write_regs(sel 17, zero pairs)", r, kExpectSuccess);
}

/* selector 18: write_2_regs(off1, off2, pairs, byteCount) - table: flags 4, 2 scalars, struct variable. Same
 * validation as write_regs: byte count not a multiple of 8 -> BadArgument; 0 -> Success with no register written. */
static void test_write_2_regs(io_connect_t connect) {
    UInt32 in = 0;
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 18, 2, sizeof(in), 0, 0, &in);
    report("2D write_2_regs(sel 18, 4 bytes: not a multiple of 8)", r, kExpectBadArgument);
    r = IOConnectMethodScalarIStructureI(connect, 18, 2, 0, 0, 0, NULL);
    report("2D write_2_regs(sel 18, zero pairs)", r, kExpectSuccess);
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
    test_set_surface(connect); /* last: binds a display panel on this connection */
    IOServiceClose(connect);
}
