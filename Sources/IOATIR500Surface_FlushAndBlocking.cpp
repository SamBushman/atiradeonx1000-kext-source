/*
 * IOATIR500Surface_FlushAndBlocking.cpp
 *
 * RESOLVED (issue #42 test-harness pass): real bodies for
 * `IOATIR500Surface::flush_surface` (real addr 0x10fa0) and
 * `set_surface_blocking` (real addr 0x15ac0) - two more real methods
 * this pass's own new external-method dispatch/implementation work
 * unmasked as never actually implemented (see
 * IOATIR500Surface_ExternalMethods2.cpp's own header comment for the
 * general account).
 *
 * flush_surface real body: bails out entirely unless either this
 * surface's own real "needs flush" byte (`+0xbed`) is set, or the
 * accelerator's own real `+0x554` vtable slot (role INFERRED:
 * "is a flush actually pending for this stamp," called with this
 * surface's own `+0x80` stamp field) says so. If a real "resolve
 * pending" bit (`+0xbf8 & +0xc1c`, masked to `0x10000000`) is set, calls
 * this object's own real `+0x5c0` vtable slot (role UNCONFIRMED) then
 * clears that bit. Copies the pending stamp (`+0x80`) into the
 * "last-flushed" stamp (`+0x84`), then - for every real per-format
 * buffer slot the accelerator's own real `+0xcc` count covers (the SAME
 * real `this + index*0x94` stride array `set_id_mode`/`is_flip_allowed`
 * already establish, each slot's own `+0xcac` flag byte the SAME real
 * field those functions use too) - whose bit is set in the caller's
 * `formatMask` AND whose own `+0xcac` flag is set: calls this object's
 * own real `+0x5d4` vtable slot (role UNCONFIRMED) with the slot index
 * and the caller's `flushArg`, and bumps a real accelerator-owned
 * counter (`accel+0x74c`). Finally clears the accelerator's own real
 * `+0x78` "last-touched" field (the SAME real field
 * `IOATIR500DVDContext::set_surface` also clears on itself).
 *
 * set_surface_blocking real body: acquires the accelerator's real
 * commandLock AND a second, real per-surface lock object at this
 * surface's own `+0xc04` (a real lock/queue handle allocated by the
 * base class's own `start()` via `FUN_00011e38`, since RESOLVED (issue
 * #58) as `IOLockAlloc` - this function only USES the already-allocated
 * handle, it doesn't create it). Stores the real blocking-enabled flag (`+0xbf6`), and - if
 * disabling blocking - calls a real 3-argument primitive on the same
 * lock object matching this project's own already-established
 * `IOLockSleep(lock, event, interruptible)` shape exactly (trusted by
 * pattern-match against that already-proven real primitive, per this
 * project's own established convention for this exact real 3-arg
 * lock/obj/flag call shape - not individually re-verified via a fresh
 * live memory read this pass). Releases both locks in reverse order.
 * Always returns kIOReturnSuccess.
 *
 * Confidence: CONFIRMED for control flow and every real offset/constant
 * in both functions - real, complete, standalone decompiles. The two
 * newly-flagged Surface-vtable slots (+0x5c0/+0x5d4) and the
 * accelerator's own +0x554 slot have no established real name/role
 * beyond what's directly inferable from these call sites.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void SurfFlushBlk_mutex_lock(void *) asm("_IOLockLock");
extern "C" void SurfFlushBlk_mutex_unlock(void *) asm("_IOLockUnlock");
extern "C" void SurfFlushBlk_IOLockSleep(void *lockPtr, void *event, UInt32 interruptible) asm("_IOLockSleep");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

void IOATIR500Surface::flush_surface(UInt32 formatMask, UInt32 flushArg) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(*reinterpret_cast<void **>(self + 0xd50));

    bool needsFlush = (U8At(self, 0xbed) != 0);
    if (!needsFlush) {
        typedef SInt32 (*Fn0x554)(void *, UInt32);
        void **accelVtable = *reinterpret_cast<void ***>(accel);
        SInt32 pending = (*reinterpret_cast<Fn0x554 *>(accelVtable + (0x554 / 4)))(accel, U32At(self, 0x80));
        if (pending == 0) {
            return;
        }
    }

    if ((U32At(self, 0xbf8) & U32At(self, 0xc1c) & 0x10000000u) != 0) {
        typedef void (*Fn0x5c0)(void *);
        void **selfVtable = *reinterpret_cast<void ***>(self);
        (*reinterpret_cast<Fn0x5c0 *>(selfVtable + (0x5c0 / 4)))(this);
        U32At(self, 0xbf8) &= 0xefffffffu;
    }

    accel = reinterpret_cast<UInt8 *>(*reinterpret_cast<void **>(self + 0xd50));
    U32At(self, 0x84) = U32At(self, 0x80);

    if (U32At(accel, 0xcc) != 0) {
        UInt32 index = 0;
        UInt8 *slot = self;
        do {
            if (((1u << (index & 0x3f)) & formatMask) != 0 && U8At(slot, 0xcac) != 0) {
                typedef void (*Fn0x5d4)(void *, UInt32, UInt32);
                void **selfVtable = *reinterpret_cast<void ***>(self);
                (*reinterpret_cast<Fn0x5d4 *>(selfVtable + (0x5d4 / 4)))(this, index, flushArg);
                U32At(accel, 0x74c) += 1;
                accel = reinterpret_cast<UInt8 *>(*reinterpret_cast<void **>(self + 0xd50));
            }
            index++;
            slot += 0x94;
        } while (index < U32At(accel, 0xcc));
    }

    U32At(accel, 0x78) = 0;
}

IOReturn IOATIR500Surface::set_surface_blocking(UInt32 blockingMode) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *accel = *reinterpret_cast<void **>(self + 0xd50);
    void *surfaceLock = *reinterpret_cast<void **>(self + 0xc04);

    SurfFlushBlk_mutex_lock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accel) + 0x840));
    SurfFlushBlk_mutex_lock(surfaceLock);

    U8At(self, 0xbf6) = (blockingMode != 0) ? 1 : 0;
    if (blockingMode == 0) {
        SurfFlushBlk_IOLockSleep(surfaceLock, this, 0);
    }

    SurfFlushBlk_mutex_unlock(surfaceLock);
    SurfFlushBlk_mutex_unlock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(*reinterpret_cast<void **>(self + 0xd50)) + 0x840));
    return 0;
}
