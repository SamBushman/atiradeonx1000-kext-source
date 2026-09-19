/*
 * IOATIR500Surface_ExternalMethods2.cpp
 *
 * RESOLVED (issue #42 test-harness pass): real bodies for 9 real
 * IOATIR500Surface methods that had been documented in this project's own
 * comments as "CONFIRMED body" (implying a real transcription existed)
 * but were, in fact, never actually implemented anywhere - a real,
 * previously-invisible gap this pass's own new external-method dispatch
 * table (Sources/ATIR500Surface_ExternalMethods.cpp) unmasked: nothing
 * ever took these methods' addresses or called them internally before
 * now, so the linker never needed to resolve them, and a full clean
 * rebuild reported 0 project-own undefined symbols despite these bodies
 * not existing at all.
 *
 * Several real signature corrections found and fixed alongside these
 * (see each method's own header comment in Headers/IOATIR500Surface.h
 * for the individual real-mangled-symbol/real-register evidence):
 * surface_read_unlock_options (1 real param, not 0), set_shape (4 real
 * params, not 0 - Ghidra hid its own forwarding args entirely, resolved
 * via raw PPC register moves), surface_control/surface_control_alias (2
 * real params, not 3 - the previously-declared middle "param2" never
 * really existed).
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include <string.h>

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

extern "C" void SurfExtM2_mutex_lock(void *) asm("_IOLockLock");
extern "C" void SurfExtM2_mutex_unlock(void *) asm("_IOLockUnlock");

/*
 * surface_read_lock - CONFIRMED, real addr 0x164c0. A real, complete,
 * one-line thin forward - already documented correctly in the header.
 * Ghidra's own decompile shows this as `void` (discarding the inner
 * call's result), but that's a real PPC tail-call-passthrough display
 * artifact, not real behavior: a bare `bl` immediately followed by
 * return leaves r3 holding the inner call's own result, which the real
 * caller (expecting a real IOReturn) does receive - the header's own
 * already-declared IOReturn return type is correct; propagated
 * explicitly here rather than matching Ghidra's own display choice.
 */
IOReturn IOATIR500Surface::surface_read_lock(IOAccelSurfaceData *data, UInt32 size) {
    return surface_lock_options(static_cast<eLockType>(1), 2, data, size);
}

/*
 * surface_read_unlock - CONFIRMED, real addr 0x15120. A real, complete,
 * one-line thin forward - same real tail-call-passthrough note as
 * surface_read_lock above applies here too.
 */
IOReturn IOATIR500Surface::surface_read_unlock() {
    return surface_unlock_options(static_cast<eLockType>(1), 2);
}

/*
 * surface_read_unlock_options - RESOLVED, real addr 0x15160. Real
 * signature CORRECTED (1 real param, not 0 - see header). A real,
 * complete, one-line thin forward; real return value propagated per the
 * same tail-call-passthrough reasoning as surface_read_lock/unlock above.
 */
IOReturn IOATIR500Surface::surface_read_unlock_options(UInt32 param1) {
    return surface_unlock_options(static_cast<eLockType>(1), param1);
}

/*
 * get_state - CONFIRMED, real addr 0x10f30. Real body: a real vtable
 * call at this-object's own +0x520 (role INFERRED: "is currently
 * displayed/active," given the 0/1 boolean-style translation into the
 * real output param) with no further arguments, translated into a real
 * 0/1 output. Always returns kIOReturnSuccess.
 */
IOReturn IOATIR500Surface::get_state(eIOAccelSurfaceStateBits *outStateBitsE) {
    UInt32 *outStateBits = reinterpret_cast<UInt32 *>(outStateBitsE);
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    typedef SInt32 (*Fn0x520)(void *);
    void *accel = *reinterpret_cast<void **>(self + 0xd50);
    SInt32 active = (*reinterpret_cast<Fn0x520 *>(*reinterpret_cast<void ***>(accel) + (0x520 / 4)))(accel);
    *outStateBits = (active == 0) ? 0u : 1u;
    return 0;
}

/*
 * set_shape - RESOLVED, real addr 0x159a0. Real signature CORRECTED (4
 * real params, not 0 - Ghidra's own decompile hid the real forwarding
 * args entirely; resolved via the real raw PPC register moves - see
 * header comment). Real body: a thin forward into
 * set_shape_backing_length_ext with the SAME real 0xffffffff sentinel
 * set_shape_backing_length's own forward uses, and a real literal 0 for
 * both param3 and param7. Real return value propagated (real
 * disassembly is a pure tail branch with no r3 postprocessing) - see
 * header comment for why this differs from set_shape_backing's own
 * genuinely-void real behavior.
 */
IOReturn IOATIR500Surface::set_shape(eIOAccelSurfaceShapeBits shapeBits, UInt32 id, IOAccelDeviceRegion *region, UInt32 param4) {
    return set_shape_backing_length_ext(shapeBits, id, 0, 0xffffffffu, region, param4, 0);
}

/*
 * surface_flush - CONFIRMED, real addr 0x14e70. Real body matches this
 * project's own already-existing header comment exactly: real
 * alloc_surfaces_retry (using this surface's own +0xc1c mode bits masked
 * to 2 bits) gates a real flush_surface call, then unconditionally does
 * real completion-counter bookkeeping via the accelerator's own +0x54c
 * vtable slot (role INFERRED: "record flush completion timestamp,"
 * matching the same real accumulator-field pattern this project already
 * established for the sibling +0x558/+0x55c slots) using this surface's
 * own +0x84 field as the real argument.
 */
IOReturn IOATIR500Surface::surface_flush(UInt32 param1, UInt32 param2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *accel = *reinterpret_cast<void **>(self + 0xd50);
    SurfExtM2_mutex_lock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accel) + 0x840));

    IOReturn result = alloc_surfaces_retry(U32At(self, 0xc1c) & 3, static_cast<eLockType>(0));
    if (result == 0) {
        flush_surface(param1, param2);
    }
    UInt32 arg = U32At(self, 0x84);

    SurfExtM2_mutex_unlock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accel) + 0x840));

    accel = *reinterpret_cast<void **>(self + 0xd50);
    typedef SInt32 (*Fn0x54c)(void *, UInt32);
    UInt32 before = U32At(accel, 0x798); /* real: piVar3[0x1e6], dword-indexed = byte offset 0x1e6*4 */
    SInt32 delta = (*reinterpret_cast<Fn0x54c *>(*reinterpret_cast<void ***>(accel) + (0x54c / 4)))(accel, arg);
    U32At(accel, 0x798) = before + delta;
    return result;
}

/*
 * surface_control / surface_control_alias - CONFIRMED, real addr
 * 0x15cb0 (a real, deliberate alias - same function address for both
 * selectors). Real signature CORRECTED (2 real params, not 3 - the
 * function's own real first parameter fills the role of `this` itself,
 * used directly as the receiver for set_surface_blocking/
 * set_volatile_state - Ghidra's own raw dump showed no separate `this`
 * for this specific function at all, an `__stdcall`-inferred artifact -
 * see header comment).
 */
IOReturn IOATIR500Surface::surface_control(UInt32 selector, UInt32 value, UInt32 *out) {
    (void)out; /* the third (output) pointer is never used */
    IOReturn result;
    if (selector == 1) {
        result = set_surface_blocking(value);
    } else if (selector == 4) {
        set_volatile_state(static_cast<eSurfaceVolatileState>(value));
        result = 0;
    } else {
        result = 0xe00002c2;
    }
    return result;
}

/* NB: there is no separate surface_control_alias in the shipped kext: external-method table entry 18 is the
 * SAME function as entry 16 (surface_control). The wrapper this project used to define had no stock counterpart
 * and was removed (ledger pass). */

/*
 * surface_query_lock - CONFIRMED, real addr 0x151a0. Real body: a
 * genuine availability CHECK - rejects immediately (kIOReturnCannotLock)
 * if already locked (this+0xbd0's own upper 16 bits) or if the primary
 * buffer has no real dimensions (this+0xb70's own +0x10). Otherwise, if
 * a real pending-flush condition holds (this+0xbf8 & this+0xc1c, masked
 * to the low 2 bits) for the OTHER of the two alternating buffer slots
 * (this+((bits&1)^1)*0x78+0xb8/+0xb0 - the same real per-slot fields
 * `alloc_surfaces`-family functions already establish elsewhere), calls
 * this object's own real vtable +0x5d0 (role INFERRED: "attempt
 * something like a non-blocking flip/resolve," given its boolean-style
 * result gates a real +0x5cc call - CONFIRMED as `dealloc_surface` - on
 * that same slot index when it fails). Always returns kIOReturnSuccess
 * or kIOReturnCannotLock, never actually acquiring anything - matching
 * this project's own already-established header comment exactly.
 */
IOReturn IOATIR500Surface::surface_query_lock() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *accel = *reinterpret_cast<void **>(self + 0xd50);
    SurfExtM2_mutex_lock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accel) + 0x840));

    IOReturn result;
    UInt8 *primaryBuf = *reinterpret_cast<UInt8 **>(self + 0xb70);
    if ((U32At(self, 0xbd0) & 0xffff0000u) == 0 && U32At(primaryBuf, 0x10) != 0) {
        if ((U32At(self, 0xbf8) & 0x20000000u) == 0) {
            UInt32 bits = U32At(self, 0xbf8) & U32At(self, 0xc1c);
            if ((bits & 3) != 0) {
                UInt32 otherSlot = (bits & 1) ^ 1;
                UInt8 *slotBase = self + otherSlot * 0x78;
                if (U32At(slotBase, 0xb8) != 0 && U32At(slotBase, 0xb0) == 0) {
                    typedef SInt32 (*Fn0x5d0)(void *);
                    void **selfVtable = *reinterpret_cast<void ***>(self);
                    SInt32 attempted = (*reinterpret_cast<Fn0x5d0 *>(selfVtable + (0x5d0 / 4)))(this);
                    if (attempted != 0) {
                        result = 0;
                        dealloc_surface(otherSlot);
                        goto tail;
                    }
                    result = 0xe00002cc;
                    goto tail;
                }
            }
            result = 0;
            goto tail;
        }
    }
    result = 0xe00002cc;

tail:
    SurfExtM2_mutex_unlock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(*reinterpret_cast<void **>(self + 0xd50)) + 0x840));
    return result;
}
