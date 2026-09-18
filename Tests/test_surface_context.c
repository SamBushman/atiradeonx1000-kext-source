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
 * SAFETY: get_state, surface_query_lock, and surface_read_unlock_options
 * were manually, individually verified live earlier this session - before
 * the #43 incident - and behaved sanely (real, distinct IOReturn codes,
 * no crash). Everything else was originally recorded shape-only and
 * skipped, per Tests/common.h's safety note and issue #43.
 *
 * FOLLOW-UP (2026-09-18, post-#43, user-authorized after full code-path
 * tracing): set_id_mode and set_shape_backing were subsequently exercised
 * for real, using a fully-traced, deliberately-constructed precondition
 * sequence rather than a guess - see each test's own header comment below
 * for the complete reasoning (established via Tests/probe_set_id_mode.c
 * and Tests/probe_shape_backing.c, both run live without incident). This
 * is the model for closing out the rest of this file's skipped selectors:
 * trace the FULL real code path in this project's own reconstructed
 * source first, identify what real state must exist for a given call to
 * be safe (not guess it), establish that state via already-verified
 * calls, THEN test - never guess-and-hope against a struct-taking or
 * state-mutating method. Selectors still requiring a real, unreconstructed
 * Apple struct type (IOAccelSurfaceData/IOAccelSurfaceScaling) remain
 * skipped - their real layout is still unknown, and low-confidence-struct
 * + real-hardware-write is exactly the combination that produced #43.
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

/* selector 6: set_shape_backing(UInt32 shapeBits, UInt32 id, UInt32 param3,
 * UInt32 param4, IOAccelDeviceRegion *region, UInt32 param6) - unlike
 * IOAccelSurfaceData/IOAccelSurfaceScaling, this project's OWN complete
 * reconstructed body for the real forward target
 * (set_shape_backing_length_ext, Sources/IOATIR500Surface_LockShape.cpp)
 * gives a byte-exact account of every field `region` is read at: count
 * (u32 @0), an unused/uninterpreted value (u32 @4), a packed dim pair
 * (SInt16 @8/@10), and one 8-byte rect entry per `count` starting at
 * offset 12 (SInt32 "value_a" @12, packed SInt16 pair "value_b" @16/@18) -
 * real structSize = count*8+0xc. This is a real, derived layout (from
 * this project's own complete trace), not a guess at Apple's naming.
 *
 * REQUIRES real, valid preconditions traced from the same source: `id`
 * must already have a validly-allocated per-ID record (self+id*8+0xd60,
 * from set_id_mode's SLOW path) AND self+0xbe8's bit 0x20 must be set
 * (from set_id_mode's FAST path) - set_id_mode's own record-(re)allocation
 * block is gated on that SAME bit being clear, so calling slow-path once
 * then fast-path again on the SAME id satisfies both without disturbing
 * the record. Empirically verified live (Tests/probe_shape_backing.c,
 * user-authorized, no incident): the 2-call set_id_mode sequence below
 * both succeed exactly as traced; the set_shape_backing call itself
 * returned kIOReturnBadArgument - informative, not a failure of this
 * test's own preconditions (which independently succeeded) - most likely
 * because this selector's real wire shape (scalarInputCount/structureSize
 * for the IOConnectMethodScalarIStructureI call) has no call-site
 * evidence and was constructed from the function's own C++ parameter
 * list rather than confirmed real client usage; the kernel's own
 * argument-count check rejecting a mismatched shape before the function
 * body runs is the same safe-failure behavior already established
 * throughout this project's #42 work. Recorded as the honest real result,
 * not asserted as proof of anything beyond "the precondition sequence
 * itself is real and safe." */
static void test_set_shape_backing(io_connect_t connect) {
    kern_return_t rid1 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 1, 0x0);
    kern_return_t rid2 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 1, 0x20);
    report("Surface set_id_mode(1,0x0) [precondition: allocate record]", rid1, NULL);
    report("Surface set_id_mode(1,0x20) [precondition: set bit 0x20, keep record]", rid2, NULL);
    if (rid1 != TEST_kIOReturnSuccess || rid2 != TEST_kIOReturnSuccess) {
        report_skipped("Surface set_shape_backing(sel 6)", "precondition sequence did not succeed this run - not attempting the shape call itself");
        return;
    }

    unsigned char region[20];
    memset(region, 0, sizeof(region));
    *(UInt32 *)(region + 0) = 1;
    *(SInt16 *)(region + 8) = 4;
    *(SInt16 *)(region + 10) = 4;
    *(SInt16 *)(region + 16) = 4;
    *(SInt16 *)(region + 18) = 4;
    IOByteCount structSize = sizeof(region);
    UInt32 shapeBits = 0, id = 1, param3 = 0, param4 = 0, param6 = 0;
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 6, 5, structSize,
                                                         shapeBits, id, param3, param4, param6, region);
    report("Surface set_shape_backing(sel 6, real preconditions established, wire shape unverified)", r, NULL);
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
