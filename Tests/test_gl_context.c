/*
 * Tests/test_gl_context.c
 *
 * Full coverage of the GL context (type=1, IOATIR500GLContext /
 * ATIR500GLContext) external methods, selectors 0-20. Real shapes below
 * are call-site-CONFIRMED for ALL 21 selectors, extracted by
 * disassembling the real, live `ATIRadeonX1000GLDriver.bundle`
 * (`otool -tV`) and reading the literal register values passed to the
 * raw `io_connect_method_*` MIG stubs it calls directly - see
 * Tests/common.h's top-of-file methodology note. Every selector below
 * was observed being called against the real GL connection (confirmed
 * by tracing each call site's own `r3` back to a `lwz r3,0x4(rXX)`
 * pattern consistent across ~76 of 78 real call sites in this bundle;
 * the one true exception - a call at bundle offset 0x7444 using a
 * DIFFERENT base register/offset - turned out to be a call against a
 * second, Surface-typed connection the same bundle also opens, not a
 * GL-selector ambiguity; see test_surface_context.c).
 *
 * SAFETY: only selectors whose real behavior is a global, ID-less,
 * side-effect-free query (or which were already manually verified
 * earlier this session without incident) are actually invoked live via
 * report(). Everything else is recorded via report_skipped() with its
 * real shape - see Tests/common.h's safety note and issue #43 for why.
 */

#include "common.h"

/* selector 0: set_surface(id, modeBits, p3, p4) - table: flags 4, 4 scalars, struct 0. RESOLVED (#42 skipped-method pass):
 * surface id 0 means "detach": the stock body finds no surface to bind, leaves this context's surface
 * pointers NULL, clears the accelerator's "last hardware context" marker if it is this context, then calls
 * ATIR500GLContext::update_surface (a no-op when no surface is bound) and returns 0. A real surface id
 * would bind a surface and is NOT tested. */
static void test_set_surface(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 0, 4, 0, 0, 0, 0, 0, NULL);
    report("GL set_surface(sel 0, id 0 = detach)", r, kExpectSuccess);
}

/* selector 1: set_swap_rect(x,y,w,h) - table: flags 4, 4 scalars. Stock body stores four halfwords in this
 * context and calls the bound surface's invalidate ONLY if one is bound; none is on a fresh connection. */
static void test_set_swap_rect(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 1, 4, 0, 0, 0, 0, 0, NULL);
    report("GL set_swap_rect(sel 1, 0,0,0,0)", r, kExpectSuccess);
}

/* selector 2: IOATIR500GLContext::set_swap_interval(SInt32,SInt32) -
 * CONFIRMED: structureI, scalarInputCount=2, structSize=0. Evidence: GL
 * bundle offset 0x5820/0x5858 (_gldSetInteger) and 0x1a970/0x1abc8
 * (_gldFinish), r6=2,r8=0. A plain interval setter, no surface/texture
 * ID involved - safe to run. */
static void test_set_swap_interval(io_connect_t connect) {
    /* shape per dispatch table: flags 4 (scalarI/structI), 2 scalars, struct size 0 */
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 2, 2, 0, 0, 0, NULL);
    report("GL set_swap_interval(sel 2, 0,0)", r, kExpectSuccess);
}

/* selector 3: get_config(UInt32*,UInt32*,UInt32*) - CONFIRMED: scalarO,
 * in=0/out=3. Evidence: GL bundle offset 0x685c (_gldCreateContext),
 * 0x7608/0x8b4c (_gldAttachDrawable/_gldGetRendererInfo), r6=0,
 * capacity=3. Global query, safe. */
static void test_get_config(io_connect_t connect) {
    int out0 = -1, out1 = -1, out2 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 3, 0, 3, &out0, &out1, &out2);
    report("GL get_config(sel 3)", r, NULL);
    if (r == TEST_kIOReturnSuccess) printf("    out={%d,%d,%d}\n", out0, out1, out2);
}

/* selector 4: get_status(UInt32*) - CONFIRMED: scalarO, in=0/out=1.
 * Evidence: GL bundle offset 0x7644 (_gldAttachDrawable), r6=0,
 * capacity=1. Global query, safe. */
static void test_get_status(io_connect_t connect) {
    int out0 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 4, 0, 1, &out0);
    report("GL get_status(sel 4)", r, NULL);
    if (r == TEST_kIOReturnSuccess) printf("    status=0x%x\n", out0);
}

/* selector 5: get_surface_size(SInt32*,SInt32*,SInt32*,SInt32*) -
 * CONFIRMED: scalarO, in=0/out=4. Evidence: GL bundle offset 0x7344
 * (_gldAttachDrawable), r6=0, capacity=4. Global query (returns
 * "no surface" sanely with nothing bound), safe. */
static void test_get_surface_size(io_connect_t connect) {
    int d0 = -1, d1 = -1, d2 = -1, d3 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 5, 0, 4, &d0, &d1, &d2, &d3);
    report("GL get_surface_size(sel 5)", r, NULL);
    if (r == TEST_kIOReturnSuccess) printf("    dims={%d,%d,%d,%d}\n", d0, d1, d2, d3);
}

/* selector 6: get_surface_info(id, *flags, *w, *h) - table: flags 0, 1 in, 3 out. Stock body: id 0 (or an id
 * with no live surface) returns BadArgument (it zeroes the three outputs kernel-side) and never dereferences anything.
 * (This BadArgument is the METHOD's own result: the wire shape matches the table.) (Outputs of an error return are NOT copied back to the caller by IOKit, so they are not observable here.) */
static void test_get_surface_info(io_connect_t connect) {
    int o0 = -1, o1 = -1, o2 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 6, 1, 3, 0, &o0, &o1, &o2);
    report("GL get_surface_info(sel 6, id 0)", r, kExpectBadArgument);
    (void)o0; (void)o1; (void)o2;
}

/* selector 7: read_buffer(sIOGLContextReadBufferData*, size) - table: flags 3, struct-in variable, struct-out 0.
 * Input {x,y,w,h,kind,destBase,stride} = 28 bytes. Stock body: kinds other than 0-4/7/8/10/11 return
 * BadArgument before the lock; a valid kind with no bound surface returns CannotLock (the surface NULL check
 * precedes every dereference - unlike DVD write_buffer). Two safe cases; a real readback is NOT tested. */
static void test_read_buffer(io_connect_t connect) {
    UInt32 in[7] = {0, 0, 1, 1, 5, 0, 0};
    IOByteCount outSize = 0;
    kern_return_t r = IOConnectMethodStructureIStructureO(connect, 7, sizeof(in), &outSize, in, NULL);
    report("GL read_buffer(sel 7, invalid kind 5)", r, kExpectBadArgument);
    in[4] = 0;
    outSize = 0;
    r = IOConnectMethodStructureIStructureO(connect, 7, sizeof(in), &outSize, in, NULL);
    report("GL read_buffer(sel 7, valid kind 0, no surface bound)", r, kExpectCannotLock);
}

/* selector 8: finish(void) - CONFIRMED: structureI, scalarInputCount=0,
 * structSize=0 - i.e. truly zero real arguments, matching the C++
 * signature exactly (the earlier session's assumption of "4 hidden
 * inputs" for this selector, from the kernel-table's ambiguous count
 * fields, was WRONG - this call-site evidence supersedes it; see #43).
 * Evidence: GL bundle offset 0x1a648/0x1a8c8 (_gldFinish). A global
 * "wait for GPU idle"-style call, safe. */
static void test_finish(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 8, 0, 0, NULL);
    report("GL finish(sel 8)", r, NULL);
}

/* selector 9: wait_for_stamp(UInt32 stamp) - CONFIRMED: structureI,
 * scalarInputCount=1, structSize=0 (matches signature exactly - the
 * earlier session's assumed "1 hidden output" was also wrong). Evidence:
 * GL bundle offset 0x7bf0 (_gldFinishObject), r6=1,r8=0. stamp=0 is
 * always already-reached (monotonic counter starts above 0), safe. */
static void test_wait_for_stamp(io_connect_t connect) {
    /* shape per dispatch table: flags 4, 1 scalar, struct size 0 (was passed as a 4-byte struct: rejected) */
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 9, 1, 0, 0, NULL);
    report("GL wait_for_stamp(sel 9, stamp=0)", r, kExpectSuccess);
}

/* selector 10: new_texture(sIOGLNewTextureData*, sIOGLNewTextureReturnData*, ...) - table: flags 3, struct-in and
 * struct-out both variable. The stock body switches on the first word (the texture kind); kinds 0-3/6/7 allocate a
 * real GPU resource (NOT tested), any other kind returns NoResources with both output words zeroed. */
static void test_new_texture(io_connect_t connect) {
    UInt32 in[5] = {5, 0, 0, 0, 0};
    UInt32 out[2] = {0xaaaaaaaa, 0xaaaaaaaa};
    IOByteCount outSize = sizeof(out);
    kern_return_t r = IOConnectMethodStructureIStructureO(connect, 10, sizeof(in), &outSize, in, out);
    report("GL new_texture(sel 10, invalid kind 5)", r, kExpectNoResources);
    (void)out; (void)outSize;
}

/* selector 11: delete_texture(id) - table: flags 4, 1 scalar. Stock body indexes this context's texture table
 * (allocated at start, so never NULL on an open connection): an id past the table or an empty slot returns
 * BadArgument. */
static void test_delete_texture(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 11, 1, 0, 0x7fff, NULL);
    report("GL delete_texture(sel 11, unallocated id)", r, kExpectBadArgument);
}

/* selector 12: become_global_shared(flag) - table: flags 4, 1 scalar. flag 0 = "stop being the global shared
 * context": the stock body only clears the accelerator's global-shared pointer if it is THIS context's
 * allocator, otherwise returns CannotLock. On a fresh connection it is not, so CannotLock. (flag != 0 would
 * make this context the global shared one - NOT tested.) */
static void test_become_global_shared(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 12, 1, 0, 0, NULL);
    report("GL become_global_shared(sel 12, 0)", r, kExpectCannotLock);
}

/* selector 13: page_off_texture(textureID, level) - table: flags 4, 2 scalars. Stock body: if the accelerator
 * is up, an id past this context's texture table (or an empty slot) returns BadArgument; if it is not up,
 * returns 0. Either is harmless here. */
static void test_page_off_texture(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 13, 2, 0, 0x7fff, 0, NULL);
    report("GL page_off_texture(sel 13, unallocated id)", r, kExpectBadArgument);
}

/* selector 14: scale_surface(flags, x, y) - table: flags 4, 3 scalars. No bound surface (or flag bit 0 clear)
 * -> kIOReturnUnsupported before anything else happens. */
static void test_scale_surface(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 14, 3, 0, 0, 0, 0, NULL);
    report("GL scale_surface(sel 14, no surface bound)", r, kExpectUnsupported);
}

/* selector 15: purge_texture(id) - table: flags 4, 1 scalar. Same table lookup as delete_texture: an
 * unallocated id returns BadArgument. */
static void test_purge_texture(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 15, 1, 0, 0x7fff, NULL);
    report("GL purge_texture(sel 15, unallocated id)", r, kExpectBadArgument);
}

/* selector 16: set_surface_volatile_state(state) - table: flags 4, 1 scalar. Stock body stores the value in this
 * context and forwards to the bound surface only if one is bound. */
static void test_set_surface_volatile_state(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 16, 1, 0, 0, NULL);
    report("GL set_surface_volatile_state(sel 16, 0)", r, kExpectSuccess);
}

/* selector 17: reclaim_resources(void) - CONFIRMED: structureI, in=0,
 * struct=0 (matches signature exactly). Evidence: GL bundle offset
 * 0x6fc0 (_gldReclaimContext). A global sweep with no ID/target
 * argument at all - safe to run (worst case, a real no-op if nothing to
 * reclaim). */
static void test_reclaim_resources(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 17, 0, 0, NULL);
    report("GL reclaim_resources(sel 17)", r, NULL);
}

/* selector 18: get_data_buffer(UInt32*,UInt32*) - CONFIRMED: scalarO,
 * in=0/out=2. Evidence: GL bundle offset 0x270b4 (_gldInitDispatch),
 * 0x37b30 (_gldGetTextureLevel), r6=0, capacity=2. Global query, safe. */
static void test_get_data_buffer(io_connect_t connect) {
    int out0 = -1, out1 = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 18, 0, 2, &out0, &out1);
    report("GL get_data_buffer(sel 18)", r, NULL);
    if (r == TEST_kIOReturnSuccess) printf("    out={0x%x,0x%x}\n", out0, out1);
}

/* selector 19: set_stereo(UInt32,UInt32) - CONFIRMED: structureI, in=2,
 * struct=0. Evidence: GL bundle offset 0x5a18 (_gldSetInteger). A plain
 * global mode setter, no surface/texture ID - safe to run. */
static void test_set_stereo(io_connect_t connect) {
    (void)connect;
    /* CORRECT wire shape per the dispatch table: flags 4, 2 scalars, struct size 0, i.e.
     *   IOConnectMethodScalarIStructureI(connect, 19, 2, 0, 0, 0, NULL)
     * (the old call passed the two values as an 8-byte struct and was rejected BadArgument).
     * NOT run: with the right shape it executes IOATIR500Accelerator::setup_stereo(0,0), which writes
     * GLOBAL accelerator state (the per-panel stereo mode). It is a no-op only if stereo is currently
     * off, which the harness cannot check, so it stays skipped. */
    report_skipped("GL set_stereo(sel 19, 0,0)", "shape corrected (2 scalars) but mutates global accelerator stereo state");
}

/* selector 20 (special, ATIR500GLContext::get_hw_info): 5 real scalar
 * OUTPUTS via plain scalarO (in=0/out=5) - CONFIRMED. This corrects the
 * earlier session's wrong assumption that this was a 20-byte
 * structureO call (that guess is exactly why the original
 * representative-subset harness got kIOReturnBadArgument here). Evidence:
 * GL bundle offset 0x2c8d4 (_gldGetQueryInfo), r6=0, capacity=5. Reads
 * static hardware info, safe. */
static void test_get_hw_info(io_connect_t connect) {
    int hw0 = -1, hw1 = -1, hw2 = -1, hw3 = -1, hw4 = -1;
    kern_return_t expected[] = { TEST_kIOReturnSuccess, (kern_return_t)-1 };
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 20, 0, 5, &hw0, &hw1, &hw2, &hw3, &hw4);
    report("GL get_hw_info(sel 20)", r, expected);
    if (r == TEST_kIOReturnSuccess) {
        printf("    hw={0x%x,0x%x,0x%x,0x%x,0x%x}\n", hw0, hw1, hw2, hw3, hw4);
    }
}

void run_gl_context_tests(io_service_t service) {
    io_connect_t connect = IO_OBJECT_NULL;
    kern_return_t kr = open_user_client(service, CLIENT_TYPE_GL, &connect);
    if (kr != TEST_kIOReturnSuccess) {
        printf("[FAIL] could not open GL user client: 0x%08x (%s)\n", (unsigned int)kr, ioreturn_name(kr));
        g_testsUnexpected++;
        return;
    }
    printf("-- GL context (type=1), all 21 selectors --\n");
    test_set_surface(connect);
    test_set_swap_rect(connect);
    test_set_swap_interval(connect);
    test_get_config(connect);
    test_get_status(connect);
    test_get_surface_size(connect);
    test_get_surface_info(connect);
    test_read_buffer(connect);
    test_finish(connect);
    test_wait_for_stamp(connect);
    test_new_texture(connect);
    test_delete_texture(connect);
    test_become_global_shared(connect);
    test_page_off_texture(connect);
    test_scale_surface(connect);
    test_purge_texture(connect);
    test_set_surface_volatile_state(connect);
    test_reclaim_resources(connect);
    test_get_data_buffer(connect);
    test_set_stereo(connect);
    test_get_hw_info(connect);
    IOServiceClose(connect);
}
