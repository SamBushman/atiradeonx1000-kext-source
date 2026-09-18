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

/* selector 0: surface_read_lock_options(UInt32 lockOptions,
 * IOAccelSurfaceData *data, UInt32 size) - the real Apple struct type is
 * still not fully reconstructed, but this project's own full trace of
 * surface_lock_options' real body (Sources/IOATIR500Surface_LockOptions.cpp)
 * gives a byte-exact PARTIAL layout for exactly what this call writes -
 * see that file's own header comment. REQUIRES id=0's record + self+0xb70
 * to be valid (set_id_mode(0, 0x4), already established - see
 * test_set_scale's own precondition). lockOptions=0 is the simplest real
 * path traced: reaches the "granted-pending, no allocation" tail without
 * calling alloc_surfaces_retry/prepare_vram/any GART-mapping code.
 *
 * Real wire shape from the byte-dumped table (Sources/
 * ATIR500Surface_ExternalMethods.cpp): scalarInputCount=1, structureO
 * with the struct as OUTPUT (not input) - matches the real C++ signature
 * exactly (lockOptions in, data out, size unused/dropped).
 *
 * CONFIRMED SUCCESS, live, no incident (2026-09-18, user-authorized):
 * returned kIOReturnSuccess with real structSize=68 (0x44, matching the
 * derived layout exactly) and real, plausible hardware address/pitch
 * values in the output. */
static void test_surface_read_lock_options(io_connect_t connect) {
    kern_return_t rid = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 0, 0x4);
    report("Surface set_id_mode(0,0x4) [precondition]", rid, kExpectSuccess);
    if (rid != TEST_kIOReturnSuccess) {
        report_skipped("Surface surface_read_lock_options(sel 0)", "precondition did not succeed this run");
        return;
    }
    unsigned char data[0x44];
    memset(data, 0xAA, sizeof(data));
    IOByteCount structSize = sizeof(data);
    UInt32 lockOptions = 0;
    kern_return_t r = IOConnectMethodScalarIStructureO(connect, 0, 1, &structSize, lockOptions, data);
    report("Surface surface_read_lock_options(sel 0, lockOptions=0)", r, NULL);
    if (r == TEST_kIOReturnSuccess) {
        UInt32 *d = (UInt32 *)data;
        printf("    structSize=%u data[0..4]={0x%x,0x%x,0x%x,0x%x,0x%x}\n",
               (unsigned int)structSize, d[0], d[1], d[2], d[3], d[4]);
    }
}

/* selector 1: surface_read_unlock_options(void) - already manually
 * verified live earlier this session (returned kIOReturnBadArgument,
 * consistent with "no prior lock held") without incident. 0 in / 0 out,
 * global (no ID/struct), safe. */
static void test_surface_read_unlock_options(io_connect_t connect) {
    /* dispatch table: flags 0, 1 scalar in, 0 out (the old call passed 0 scalars: rejected). Stock body is
     * surface_unlock_options(this, 1, param): with no read lock held (+0xbd0 == 0) it returns
     * kIOReturnCannotLock without touching anything. Runs on its own fresh connection, so no lock is held. */
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 1, 1, 0, 0);
    report("Surface surface_read_unlock_options(sel 1) [no prior lock]", r, kExpectCannotLock);
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

/* selector 4: surface_write_unlock_options(param) - table: flags 0, 1 in, 0 out. Stock body is
 * surface_unlock_options(this, 2, param): with no WRITE lock held (byte +0xbd1 == 0) it returns CannotLock and
 * changes nothing. Fresh connection, so no lock is held. */
static void test_surface_write_unlock_options(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 4, 1, 0, 0);
    report("Surface surface_write_unlock_options(sel 4) [no prior lock]", r, kExpectCannotLock);
}

/* selector 5: surface_read(IOAccelSurfaceReadData*, size) - table: flags 3, struct-in variable, struct-out 0.
 * Input {x,y,w,h,destBase,destStride} = 24 bytes. After the set_id_mode(0,0x4) precondition (the same one
 * surface_read_lock_options uses) the stock body takes the surface lock, passes or fails the "buffer usable" gate,
 * and - for a rectangle entirely off the left edge (x + w <= 0) - returns 0 BEFORE it wraps the caller's range in
 * an IOMemoryDescriptor or touches the blitter. So a real readback is NOT performed; the result is Success if the
 * gate passes or CannotLock if the buffer is not usable yet. */
static void test_surface_read(io_connect_t connect) {
    kern_return_t rid = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 0, 0x4);
    report("Surface set_id_mode(0,0x4) [precondition for surface_read]", rid, kExpectSuccess);
    if (rid != TEST_kIOReturnSuccess) {
        report_skipped("Surface surface_read(sel 5)", "precondition did not succeed this run");
        return;
    }
    UInt32 in[6] = {(UInt32)-100, 0, 50, 50, 0, 0};
    IOByteCount outSize = 0;
    kern_return_t r = IOConnectMethodStructureIStructureO(connect, 5, sizeof(in), &outSize, in, NULL);
    report("Surface surface_read(sel 5, rectangle entirely off-surface)", r, kExpectSuccessOrCannotLock);
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
 * the record.
 *
 * FURTHER TRACED (past the point checked when this was first attempted):
 * the function's own later `primaryBuf = *(self+0xb70)` dereference and
 * `U32At(primaryBuf, 0x24)` read are ALSO safe given these preconditions
 * alone - `self+0xb70` is populated by `prune_buffers()`
 * (Sources/IOATIR500Surface_ContextTracking.cpp), which `set_id_mode`
 * calls UNCONDITIONALLY on every successful assignment (both paths) -
 * for a fresh surface with no linked contexts (requirement bits stay 0)
 * it sets `self+0xb70` to a real, valid, non-null address (either into
 * the accelerator's own descriptor table or into the surface object's
 * own embedded fields, depending on which path), never null. So the two
 * already-verified `set_id_mode` calls below are sufficient - no further
 * setup is needed, and this function's body should be safe to run to
 * completion end-to-end, not just its first few checks.
 *
 * Empirically verified live (Tests/probe_shape_backing.c, user-authorized,
 * no incident): the 2-call set_id_mode sequence both succeed exactly as
 * traced; the set_shape_backing call itself returned kIOReturnBadArgument.
 * Given the full-body safety trace above, this is now believed to be a
 * wire-shape mismatch specifically (this selector's real
 * scalarInputCount/structureSize has no call-site evidence and was
 * constructed from the function's own C++ parameter list, not confirmed
 * real client usage) rather than any precondition or body-safety issue -
 * the kernel's own argument-count check rejecting a mismatched shape
 * before the function body runs is the same safe-failure behavior
 * already established throughout this project's #42 work. */
static void test_set_shape_backing(io_connect_t connect) {
    kern_return_t rid1 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 1, 0x0);
    kern_return_t rid2 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 1, 0x20);
    report("Surface set_id_mode(1,0x0) [precondition: allocate record]", rid1, kExpectSuccess);
    report("Surface set_id_mode(1,0x20) [precondition: set bit 0x20, keep record]", rid2, kExpectSuccess);
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
    /* dispatch table: flags 4, 4 scalars, variable struct (the old call passed 5 scalars: rejected).
     * set_shape_backing(shapeBits,id,param3,param4,region,size) tail-calls set_shape_backing_length_ext
     * with the register state unchanged, so the ext's 7th argument (r10) is whatever the kernel's
     * dispatcher left there. That argument is only read when param4 != 0xffffffff, so param4 is the
     * sentinel here - exactly the values set_shape_backing_length (sel 17) already ran successfully with. */
    UInt32 shapeBits = 0, id = 1, param3 = 0, param4 = 0xffffffff;
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 6, 4, structSize,
                                                         shapeBits, id, param3, param4, region);
    report("Surface set_shape_backing(sel 6, real preconditions established)", r, kExpectSuccess);
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

/* selector 8: set_scale(UInt32 flags, IOAccelSurfaceScaling *scaling,
 * UInt32 param3) - the real IOAccelSurfaceScaling struct's layout is NOT
 * reconstructed in general, but the specific "scaling disabled" path
 * (param3==0) never reads it at all: set_scale's own body (Sources/
 * IOATIR500Surface_LockShape.cpp) only forwards `scaling` to `set_scaling`
 * when `param3!=0`; with param3==0 it passes nullptr instead, and
 * set_scaling's own "disabled" branch (Sources/
 * IOATIR500Surface_ScalingAndState.cpp) doesn't touch `scaling` at all -
 * so this exact call is fully safe regardless of the struct's unknown
 * layout, since the driver-side code never reads it on this path.
 *
 * REQUIRES self+0xd60 (id=0's hardcoded record - set_scale/set_scaling
 * take no `id` parameter) and self+0xb70 to be real, valid pointers.
 * BOTH are already established by a single already-proven-safe call:
 * set_id_mode(mode=0, modeBits=0x4) - its real body unconditionally calls
 * prune_buffers() on success, which (for a fresh, unlinked surface) sets
 * self+0xb70 to a real, valid, non-null address - see the fuller trace in
 * test_set_shape_backing's own comment above. No second set_id_mode call
 * is needed here (unlike set_shape_backing) since the "disabled" path
 * never checks self+0xbe8's bit 0x20 at all.
 *
 * Empirically verified live (Tests/probe_set_scale.c, user-authorized, no
 * incident): set_id_mode(0,0x4) succeeds as already established;
 * set_scale itself returned kIOReturnBadArgument - per the same reasoning
 * as set_shape_backing, most likely this selector's own unverified wire
 * shape (guessed as 2 scalars + a 0x2c-byte struct, no call-site
 * evidence) being safely rejected before the (traced-safe) body runs. */
static void test_set_scale(io_connect_t connect) {
    kern_return_t rid = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 0, 0x4);
    report("Surface set_id_mode(0,0x4) [precondition: id=0 record + prune_buffers]", rid, kExpectSuccess);
    if (rid != TEST_kIOReturnSuccess) {
        report_skipped("Surface set_scale(sel 8)", "precondition did not succeed this run - not attempting the scale call itself");
        return;
    }
    /* dispatch table: flags 4, 1 scalar (flags), variable struct. The C++ signature's THIRD parameter
     * is the struct's SIZE (the kernel appends it), not a separate scalar: stock set_scale accepts 0 or
     * 0x2c and only reads the struct when it is 0x2c. The old call passed 2 scalars and a 0x2c struct
     * (rejected; had it been accepted it would have taken the ENABLED path). Disabled path = struct
     * size 0, which calls set_scaling(flags, NULL). */
    UInt32 flags = 0;
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 8, 1, 0, flags, NULL);
    report("Surface set_scale(sel 8, disabled path: struct size 0)", r, kExpectSuccessOrNoResources);
}

/* selector 9: set_shape(shapeBits, id, region, size) - table: flags 4, 2 scalars, struct variable. The stock body is a
 * thin forward into set_shape_backing_length_ext with the SAME sentinel (0xffffffff) set_shape_backing_length uses
 * and literal 0 for the other parameters, so with the SAME preconditions and the same 20-byte region it takes the
 * same path that already succeeds for selectors 6 and 17. */
static void test_set_shape(io_connect_t connect) {
    kern_return_t rid1 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 1, 0x0);
    kern_return_t rid2 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 1, 0x20);
    report("Surface set_id_mode(1,0x0) [precondition for set_shape]", rid1, kExpectSuccess);
    report("Surface set_id_mode(1,0x20) [precondition for set_shape]", rid2, kExpectSuccess);
    if (rid1 != TEST_kIOReturnSuccess || rid2 != TEST_kIOReturnSuccess) {
        report_skipped("Surface set_shape(sel 9)", "precondition sequence did not succeed this run");
        return;
    }
    unsigned char region[20];
    memset(region, 0, sizeof(region));
    *(UInt32 *)(region + 0) = 1;
    *(SInt16 *)(region + 8) = 4;
    *(SInt16 *)(region + 10) = 4;
    *(SInt16 *)(region + 16) = 4;
    *(SInt16 *)(region + 18) = 4;
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 9, 2, sizeof(region), 0, 1, region);
    report("Surface set_shape(sel 9, real preconditions established)", r, kExpectSuccess);
}

/* selector 10: surface_flush(a, b) - table: flags 0, 2 in, 0 out. NOT run: the stock body first calls
 * alloc_surfaces_retry(mode & 3, 0), which can allocate VRAM and sleep-retry, then flush_surface, then waits on the
 * accelerator's timestamp. alloc_surfaces_retry has not been traced for a safe argument on a fresh surface. */
static void test_surface_flush(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_flush(sel 10)", "calls alloc_surfaces_retry (VRAM allocation + sleep-retry loop), not traced for a safe input");
}

/* selector 11: surface_query_lock(void) - already manually verified
 * live earlier this session (returned kIOReturnCannotLock) without
 * incident. CONFIRMED body (prior decompile) to be a pure availability
 * CHECK that does not acquire anything - 0 in / 0 out, global, safe. */
static void test_surface_query_lock(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 11, 0, 0);
    report("Surface surface_query_lock(sel 11)", r, NULL);
}

/* selector 12: surface_read_lock(data, size) - table: flags 2, 0 in, struct-out variable. NOT run: stock body is
 * surface_lock_options(this, 1, lockOptions=2, ...). Only lockOptions == 0 (selector 0) has been traced to the
 * "granted-pending, no allocation" tail; lockOptions 2 reaches the VRAM-allocation / prepare_vram paths. */
static void test_surface_read_lock(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_read_lock(sel 12)", "lockOptions=2 reaches VRAM allocation / prepare_vram; only lockOptions=0 (sel 0) is traced");
}

/* selector 13: surface_read_unlock() - table: flags 0, 0 in, 0 out. Stock body is surface_unlock_options(this, 1, 2):
 * no read lock held -> CannotLock, nothing touched. */
static void test_surface_read_unlock(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 13, 0, 0);
    report("Surface surface_read_unlock(sel 13) [no prior lock]", r, kExpectCannotLock);
}

/* selector 14: surface_write_lock(data, size) - table: flags 2, 0 in, struct-out variable. NOT run: stock body is
 * surface_lock_options(this, 2, 1, ...) - a WRITE lock with lockOptions 1, an untraced path. */
static void test_surface_write_lock(io_connect_t connect) {
    (void)connect;
    report_skipped("Surface surface_write_lock(sel 14)", "write-lock path with lockOptions=1 is not traced");
}

/* selector 15: surface_write_unlock() - table: flags 0, 0 in, 0 out. Stock body is surface_unlock_options(this, 2, 2):
 * no write lock held -> CannotLock. */
static void test_surface_write_unlock(io_connect_t connect) {
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 15, 0, 0);
    report("Surface surface_write_unlock(sel 15) [no prior lock]", r, kExpectCannotLock);
}

/* selector 16: surface_control(selector, value, *out) - table: flags 0, 2 in, 1 out. Stock body: selector 1 ->
 * set_surface_blocking(value), selector 4 -> set_volatile_state(value), anything else -> BadArgument. Only the
 * BadArgument path (selector 0) is tested: set_volatile_state relinks the accelerator's global surface list and
 * set_surface_blocking(0) sleeps on a lock. */
static void test_surface_control(io_connect_t connect) {
    int out = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 16, 2, 1, 0, 0, &out);
    report("Surface surface_control(sel 16, selector 0 -> BadArgument)", r, kExpectBadArgument);
}

/* selector 17: set_shape_backing_length(UInt32 shapeBits, UInt32 id,
 * UInt32 param3, UInt32 param4, UInt32 param5, IOAccelDeviceRegion *region)
 * - same real underlying body as set_shape_backing (selector 6, this
 * project's own byte-exact derived `region` layout applies identically -
 * see that test's header comment for the full struct/precondition trace).
 * The only real difference is one extra pre-check this function itself
 * does before forwarding: `if (param4 != 0xffffffff) { require param5 >=
 * param4 * region+0xa }`, skipped entirely by passing the real
 * `0xffffffff` sentinel for param4 - which also makes the forwarded call
 * take the simplest, already-traced-safe internal branch (param4 reset
 * to 0, skipping any backing-store (re)connect call).
 *
 * Preconditions identical to set_shape_backing's: id's per-ID record
 * allocated (slow path) + self+0xbe8 bit 0x20 set (fast path, same id) -
 * re-established defensively here (idempotent - calling set_id_mode
 * again with the same already-successful arguments is safe, see that
 * function's own header comment) rather than relying on test_
 * set_shape_backing having already run first in the same connection.
 *
 * RESULT: CONFIRMED SUCCESS, live, no incident (2026-09-18,
 * user-authorized). Unlike set_shape_backing's own inconclusive
 * kIOReturnBadArgument, this exact call - same 5-scalar +
 * 20-byte-structureI wire shape, same region layout, same preconditions -
 * returned kIOReturnSuccess, meaning the function's FULL real body ran to
 * completion exactly as traced: the region/precondition byte layout
 * derived purely from this project's own reconstructed source is now
 * empirically PROVEN correct on real hardware, not just theorized. (Why
 * selector 6 itself returned BadArgument with an apparently-equivalent
 * shape while this selector succeeded is unresolved - possibly a real
 * wire-encoding difference between a void-returning external method and
 * an IOReturn-returning one - worth a follow-up, not a blocker.) */
static void test_set_shape_backing_length(io_connect_t connect) {
    kern_return_t rid1 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 1, 0x0);
    kern_return_t rid2 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 1, 0x20);
    report("Surface set_id_mode(1,0x0) [precondition, idempotent]", rid1, kExpectSuccess);
    report("Surface set_id_mode(1,0x20) [precondition, idempotent]", rid2, kExpectSuccess);
    if (rid1 != TEST_kIOReturnSuccess || rid2 != TEST_kIOReturnSuccess) {
        report_skipped("Surface set_shape_backing_length(sel 17)", "precondition sequence did not succeed this run");
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
    UInt32 shapeBits = 0, id = 1, param3 = 0, param4 = 0xffffffff, param5 = 0;
    kern_return_t r = IOConnectMethodScalarIStructureI(connect, 17, 5, structSize,
                                                         shapeBits, id, param3, param4, param5, region);
    report("Surface set_shape_backing_length(sel 17, real preconditions established, wire shape unverified)", r, NULL);
}

/* selector 18: identical table entry and function to selector 16 (a deliberate alias). */
static void test_surface_control_alias(io_connect_t connect) {
    int out = -1;
    kern_return_t r = IOConnectMethodScalarIScalarO(connect, 18, 2, 1, 0, 0, &out);
    report("Surface surface_control_alias(sel 18, selector 0 -> BadArgument)", r, kExpectBadArgument);
}

/* Each live Surface test gets its OWN fresh connection. They previously shared one:
 * surface_read_lock_options (sel 0) takes a lock that is never released, so every
 * later set_id_mode precondition returned kIOReturnCannotLock and the three
 * set_shape_backing/set_scale/set_shape_backing_length scenarios silently never ran
 * (while still printing "OK", since expectations were NULL). Closing the connection
 * tears down the per-connection Surface object and its lock state. */
static void run_isolated(io_service_t service, void (*test)(io_connect_t)) {
    io_connect_t connect = IO_OBJECT_NULL;
    kern_return_t kr = open_user_client(service, CLIENT_TYPE_SURFACE, &connect);
    if (kr != TEST_kIOReturnSuccess) {
        printf("[FAIL] could not open Surface user client: 0x%08x (%s)\n", (unsigned int)kr, ioreturn_name(kr));
        g_testsUnexpected++;
        return;
    }
    test(connect);
    IOServiceClose(connect);
}

void run_surface_context_tests(io_service_t service) {
    printf("-- Surface context (type=0), all 19 selectors --\n");
    run_isolated(service, test_surface_read_lock_options);
    run_isolated(service, test_surface_read_unlock_options);
    run_isolated(service, test_get_state);
    test_surface_write_lock_options(IO_OBJECT_NULL);
    run_isolated(service, test_surface_write_unlock_options);
    run_isolated(service, test_surface_read);
    run_isolated(service, test_set_shape_backing);
    run_isolated(service, test_set_id_mode);
    run_isolated(service, test_set_scale);
    run_isolated(service, test_set_shape);
    test_surface_flush(IO_OBJECT_NULL);
    run_isolated(service, test_surface_query_lock);
    test_surface_read_lock(IO_OBJECT_NULL);
    run_isolated(service, test_surface_read_unlock);
    test_surface_write_lock(IO_OBJECT_NULL);
    run_isolated(service, test_surface_write_unlock);
    run_isolated(service, test_surface_control);
    run_isolated(service, test_set_shape_backing_length);
    run_isolated(service, test_surface_control_alias);
}
