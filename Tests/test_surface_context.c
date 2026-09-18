/*
 * Tests/test_surface_context.c
 *
 * Full coverage of the Surface context (type=0, IOATIR500Surface /
 * ATIR500Surface) external methods, selectors 0-18. Unlike GL/2D/DVD,
 * NO vendor userspace bundle in this project's possession calls Surface
 * directly except one real cross-connection call found INSIDE the GL
 * bundle (selector 7/set_id_mode, statically traced via its own r3
 * origin - see test_gl_context.c's header note and issue #42's comment
 * thread for how the GL-vs-Surface connection ambiguity was resolved).
 * Every other selector below falls back to the class header's own
 * declared C++ signature and is flagged UNVERIFIED by call-site
 * evidence. Several real methods also take Apple's own
 * IOAccelSurfaceData/IOAccelSurfaceScaling/IOAccelDeviceRegion struct
 * types this project deliberately did not reconstruct (real Apple
 * types, not ours to guess the layout of) - those are left
 * shape-unknown entirely, not just unverified.
 *
 * SAFETY: four of these selectors (get_state, surface_query_lock,
 * surface_read_unlock_options, set_id_mode) were manually, individually
 * verified live earlier this session - before the #43 incident - and
 * behaved sanely (real, distinct IOReturn codes, no crash). They remain
 * the only ones actually invoked here. Everything else is recorded with
 * whatever shape is available and skipped - see Tests/common.h's safety
 * note and issue #43. Surface is exactly this project's own bookkeeping
 * class for the buffer/lock/swap machinery that #43's crash lives in -
 * treat every other selector here with at least as much caution as the
 * equivalent GL/2D/DVD methods, more where a real Apple struct type is
 * involved and its layout is unknown.
 */

#include "common.h"

/* selector 0: surface_read_lock_options(UInt32,IOAccelSurfaceData*,UInt32)
 * - real Apple struct type, layout not reconstructed. Lock-family call
 * regardless - skip. */
static void test_surface_read_lock_options(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_read_lock_options(sel 0)", "lock family + real Apple struct type unreconstructed");
}

/* selector 1: surface_read_unlock_options(void) - already manually
 * verified live earlier this session (returned kIOReturnBadArgument,
 * consistent with "no prior lock held") without incident. 0 in / 0 out,
 * global (no ID/struct), safe. */
static void test_surface_read_unlock_options(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 1, 0, 0);
    report("Surface surface_read_unlock_options(sel 1) [no prior lock]", r, NULL);
}

/* selector 2: get_state(UInt32*) - already manually verified live
 * earlier this session (returned kIOReturnSuccess, outState=0x1)
 * without incident. 0 in / 1 out, global, safe. */
static void test_get_state(io_connect_t connect) {
    int outState = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 2, 0, 1, &outState);
    report("Surface get_state(sel 2)", r, NULL);
    if (r == TEST_kIOReturnSuccess) printf("    outState=0x%x\n", outState);
}

/* selector 3: surface_write_lock_options(UInt32,IOAccelSurfaceData*,UInt32)
 * - same struct-type/lock-family reasoning as selector 0 - skip. */
static void test_surface_write_lock_options(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_write_lock_options(sel 3)", "lock family + real Apple struct type unreconstructed");
}

/* selector 4: surface_write_unlock_options(UInt32) - lock family - skip
 * (shape is plain scalar per signature, 1 in / 0 out, but the DANGER
 * here is semantic - an unlock call with a real side effect on surface
 * state - not shape uncertainty). */
static void test_surface_write_unlock_options(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_write_unlock_options(sel 4)", "lock/unlock family - see #43");
}

/* selector 5: surface_read(IOAccelSurfaceReadData*,UInt32) - real Apple
 * struct type, layout not reconstructed, and reads real surface
 * contents - skip. */
static void test_surface_read(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_read(sel 5)", "reads real surface contents + real Apple struct type unreconstructed");
}

/* selector 6: set_shape_backing(UInt32,UInt32,UInt32,UInt32,
 * IOAccelDeviceRegion*,UInt32) - real Apple struct type, layout not
 * reconstructed, mutates real surface shape - skip. */
static void test_set_shape_backing(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface set_shape_backing(sel 6)", "mutates real surface shape + real Apple struct type unreconstructed");
}

/* selector 7: set_id_mode(UInt32 mode, UInt32 modeBits) - CONFIRMED via
 * real cross-connection call-site evidence found INSIDE the GL bundle
 * (offset 0x7444, function _gldAttachDrawable, calling this Surface
 * connection's own selector 7 - see test_gl_context.c's header note):
 * scalarO, in=2/out=0, matching the header's own 2-param signature
 * exactly. Already manually verified live earlier this session
 * (returned kIOReturnError with mode=0,modeBits=0) without incident. A
 * plain mode setter, no struct/ID indexing - safe. */
static void test_set_id_mode(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 0, 0);
    report("Surface set_id_mode(sel 7, 0,0)", r, NULL);
}

/* selector 8: set_scale(UInt32,IOAccelSurfaceScaling*,UInt32) - real
 * Apple struct type, layout not reconstructed, mutates real surface
 * scale state - skip. */
static void test_set_scale(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface set_scale(sel 8)", "mutates real surface scale + real Apple struct type unreconstructed");
}

/* selector 9: set_shape(void) - CONFIRMED body (prior decompile) to be
 * a real one-line forward into set_shape_backing_length_ext, i.e. a
 * real mutation of surface shape state, not a no-op. Shape (0 params
 * per header) UNVERIFIED via call site - skip regardless, since the
 * body is a real mutation. */
static void test_set_shape(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface set_shape(sel 9)", "real forward into shape-mutation code, not a no-op");
}

/* selector 10: surface_flush(UInt32,UInt32) - CONFIRMED body (prior
 * decompile) to call alloc_surfaces_retry + flush_surface - a real,
 * non-trivial mutation directly adjacent to the #43 crash family - skip. */
static void test_surface_flush(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_flush(sel 10)", "real alloc/flush path adjacent to #43's crash family");
}

/* selector 11: surface_query_lock(void) - already manually verified
 * live earlier this session (returned kIOReturnCannotLock) without
 * incident. CONFIRMED body (prior decompile) to be a pure availability
 * CHECK that does not acquire anything - 0 in / 0 out, global, safe. */
static void test_surface_query_lock(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 11, 0, 0);
    report("Surface surface_query_lock(sel 11)", r, NULL);
}

/* selector 12: surface_read_lock(IOAccelSurfaceData*,UInt32) - CONFIRMED
 * body to be a thin forward into the same lock_options path as selector
 * 0 - same struct-type/lock-family reasoning - skip. */
static void test_surface_read_lock(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_read_lock(sel 12)", "forwards into lock_options - see selector 0");
}

/* selector 13: surface_read_unlock(void) - CONFIRMED body to be a thin
 * forward into surface_unlock_options(this,1,2) - a real unlock
 * mutation, not a no-op - skip even though the shape itself (0 in / 0
 * out) is simple and known. */
static void test_surface_read_unlock(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_read_unlock(sel 13)", "real unlock mutation - see #43");
}

/* selector 14: surface_write_lock(IOAccelSurfaceData*,UInt32) - same
 * struct-type/lock-family reasoning as selector 0/3 - skip. */
static void test_surface_write_lock(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_write_lock(sel 14)", "lock family + real Apple struct type unreconstructed");
}

/* selector 15: surface_write_unlock(void) - real unlock mutation, same
 * reasoning as selector 13 - skip. */
static void test_surface_write_unlock(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_write_unlock(sel 15)", "real unlock mutation - see #43");
}

/* selector 16: surface_control(UInt32,UInt32,UInt32*) - CONFIRMED body
 * to be a real dispatcher onto set_surface_blocking/set_volatile_state
 * - real surface-state mutations behind a selector param, not a
 * read-only control query - skip. */
static void test_surface_control(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_control(sel 16)", "real dispatcher onto surface-state mutations");
}

/* selector 17: set_shape_backing_length(UInt32,UInt32,UInt32,UInt32,
 * UInt32,IOAccelDeviceRegion*) - real Apple struct type, layout not
 * reconstructed, mutates real surface shape - skip. */
static void test_set_shape_backing_length(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface set_shape_backing_length(sel 17)", "mutates real surface shape + real Apple struct type unreconstructed");
}

/* selector 18: surface_control_alias(UInt32,UInt32,UInt32*) - CONFIRMED
 * to be a real, deliberate alias of selector 16 (same function
 * address) - same reasoning, skip. */
static void test_surface_control_alias(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_control_alias(sel 18)", "deliberate alias of selector 16 - same real dispatcher");
}

void run_surface_context_tests(io_service_t service) {
    io_connect_t connect = IO_OBJECT_NULL;
    kern_return_t kr = open_user_client(service, CLIENT_TYPE_SURFACE, &connect);
    if (kr != TEST_kIOReturnSuccess) {
        printf("[FAIL] could not open Surface user client: 0x%08x (%s)\n", (unsigned int)kr, ioreturn_name(kr));
        g_testsUnexpected++;
        return;
    }
    printf("-- Surface context (type=0), all 19 selectors --\n");
    test_surface_read_lock_options(connect);
    test_surface_read_unlock_options(connect);
    test_get_state(connect);
    test_surface_write_lock_options(connect);
    test_surface_write_unlock_options(connect);
    test_surface_read(connect);
    test_set_shape_backing(connect);
    test_set_id_mode(connect);
    test_set_scale(connect);
    test_set_shape(connect);
    test_surface_flush(connect);
    test_surface_query_lock(connect);
    test_surface_read_lock(connect);
    test_surface_read_unlock(connect);
    test_surface_write_lock(connect);
    test_surface_write_unlock(connect);
    test_surface_control(connect);
    test_set_shape_backing_length(connect);
    test_surface_control_alias(connect);
    IOServiceClose(connect);
}
