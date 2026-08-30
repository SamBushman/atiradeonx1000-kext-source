/*
 * IOATIR500Surface_LockShape.cpp
 *
 * RESOLVED (issue #8): the lock/unlock family's real internal shape.
 * All six real external methods below are thin, fully-transcribed
 * forwards into two shared internal helpers, `surface_lock_options` /
 * `surface_unlock_options` (declared in IOATIR500Surface.h, bodies NOT
 * independently decompiled this pass), plus the two genuinely internal
 * (non-external-method) helpers `surface_write_lock_int` /
 * `surface_write_unlock_int`.
 *
 * Confidence: CONFIRMED for every function transcribed here - real,
 * complete decompiles, not summarized. `set_id_mode` and
 * `set_shape_backing`/`set_shape_backing_length` (and the shared
 * `set_shape_backing_length_ext` they both tail-call) remain deferred -
 * see GAPS.md.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"

void IOATIR500Surface::surface_write_unlock() {
    surface_unlock_options(2, 2);
}

void IOATIR500Surface::surface_write_unlock_options(UInt32 options) {
    surface_unlock_options(2, options);
}

void IOATIR500Surface::surface_write_lock(IOAccelSurfaceData *data, UInt32 size) {
    surface_lock_options(2, 1, data, size);
}

void IOATIR500Surface::surface_write_lock_options(UInt32 lockOptions, IOAccelSurfaceData *data, UInt32 size) {
    surface_lock_options(2, lockOptions, data, size);
}

IOReturn IOATIR500Surface::surface_read_lock_options(UInt32 lockOptions, IOAccelSurfaceData *data, UInt32 size) {
    return surface_lock_options(1, lockOptions, data, size);
}

/*
 * set_scale - CONFIRMED, fully transcribed (real kext offset 0x159f0).
 * REAL SIGNATURE CORRECTION: takes a real `IOAccelSurfaceScaling*`
 * (this project had guessed raw `UInt32 xScale, UInt32 yScale` instead
 * - a real structural error, not just a naming gap). Real body: only
 * accepts `param3 == 0 || param3 == 0x2c` (an INFERRED "real struct
 * size" gate - 0x2c matches a plausible real IOAccelSurfaceScaling
 * size on this 32-bit target, not independently confirmed against
 * Apple's own header this pass); on a gate pass, takes the accelerator
 * lock (this+0xd50's own +0x840, the same real lock field
 * ATIRadeonX1000.h documents as `commandLock`), calls the already-
 * declared `set_scaling`, and releases the lock.
 */
/*
 * Real, locally-generated lock/unlock helper pair set_scale calls
 * around set_scaling (real addresses 0x15aa4/0x15a84, immediately
 * after set_scale's own body) - the same "FUN_xxxx(lockPtr)" pattern
 * this project already documents for ATIR500GLContext::start's
 * FUN_000286dc/ec and discard_command_buffer's own lock pair: each
 * real caller gets its own small lock/unlock function taking the real
 * commandLock pointer (this+0xd50's own +0x840 here) as sole argument,
 * rather than one shared helper. Not independently decompiled - real
 * names UNKNOWN.
 */
extern void FUN_00015aa4(void *lockPtr);
extern void FUN_00015a84(void *lockPtr);

IOReturn IOATIR500Surface::set_scale(UInt32 flags, IOAccelSurfaceScaling *scaling, UInt32 param3) {
    if (param3 != 0 && param3 != 0x2c) {
        return 0xe00002c2; /* real: kIOReturnBadArgument-family literal, same constant used elsewhere in this project */
    }

    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
    bool passedScaling = (param3 != 0); /* real: `bVar2` gate, INFERRED role from the real decompile's own inverted-bit encoding */

    FUN_00015aa4(*reinterpret_cast<void **>(accel + 0x840));
    IOReturn result = set_scaling(flags, passedScaling ? scaling : nullptr);
    FUN_00015a84(*reinterpret_cast<void **>(accel + 0x840));
    return result;
}

/*
 * surface_write_lock_int / surface_write_unlock_int - CONFIRMED, fully
 * transcribed (real kext offsets 0x114a0/0x11540). Real per-buffer
 * lock/unlock around a mip/buffer record at this+bufferIndex*4+0xb70
 * (the SAME real per-mip array shape ATIR500GLContext::build_scissor
 * and friends index via a texture's own +0xb70 field - here indexed
 * directly off the surface object itself). Real vtable calls at
 * +0x5fc (lock) / +0x600 (unlock), names UNKNOWN. surface_write_lock_int
 * additionally does real completion-counter bookkeeping via a vtable
 * call at +0x558 on this+0xd50 (mirrors the same real "stamp delta"
 * pattern ATIR500GLContext::compact_current_textures/
 * submit_context_buffer use on their own accelerator pointer, at the
 * same +0x54c-family offset region - see
 * Sources/ATIR500GLContext_TextureLoad.cpp).
 */
static inline void callSurfaceVtable0x5fc(void *surfaceObj, void *mip) {
    typedef void (*Fn)(void *, void *);
    (*reinterpret_cast<Fn *>(*reinterpret_cast<void ***>(surfaceObj) + (0x5fc / 4)))(surfaceObj, mip);
}
static inline void callSurfaceVtable0x600(void *surfaceObj, void *mip) {
    typedef void (*Fn)(void *, void *);
    (*reinterpret_cast<Fn *>(*reinterpret_cast<void ***>(surfaceObj) + (0x600 / 4)))(surfaceObj, mip);
}

void IOATIR500Surface::surface_write_lock_int(UInt32 bufferIndex, UInt32 *outParam2, UInt32 *outParam3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *mip = *reinterpret_cast<UInt8 **>(self + bufferIndex * 4 + 0xb70);

    callSurfaceVtable0x5fc(self, mip);
    *outParam2 = *reinterpret_cast<UInt32 *>(mip + 8);
    *outParam3 = *reinterpret_cast<UInt16 *>(mip + 0x18);

    UInt8 *accelIsh = *reinterpret_cast<UInt8 **>(self + 0xd50);
    typedef UInt32 (*StampFn)(void *, UInt32);
    UInt32 stampDelta = (*reinterpret_cast<StampFn *>(*reinterpret_cast<void ***>(accelIsh) + (0x558 / 4)))(
        accelIsh, *reinterpret_cast<UInt32 *>(accelIsh + 0x50) - 1); /* real: piVar1[0x14], word-indexed = +0x50 */
    *reinterpret_cast<UInt32 *>(accelIsh + 0x7bc) += stampDelta; /* real: piVar1[0x1ef] = accelIsh+0x7bc word-indexed */
}

void IOATIR500Surface::surface_write_unlock_int(UInt32 bufferIndex) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *mip = *reinterpret_cast<UInt8 **>(self + bufferIndex * 4 + 0xb70);
    callSurfaceVtable0x600(self, mip);
}
