/*
 * ATIR500GLContext_Start.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `ATIR500GLContext::start` - real addr 0x28540, the 3D subclass's own
 * `start()` override (a DISTINCT real function from the already-
 * transcribed `IOATIR500GLContext::start`, `Sources/
 * IOATIR500GLContext_Start.cpp` - see that file's own header comment
 * for the disambiguation).
 *
 * Real body: locks the accelerator's commandLock, calls the base
 * class's own `IOATIR500GLContext::start(provider)` (a real explicit-
 * base-qualified call in the source, compiled as an indirect call
 * through a lazy pointer in the raw decompile), and on success zeroes
 * a real block of subclass-only state (`+0x3bc`/`+0x34c..+0x358`),
 * initializes a real 6-entry, 0x78-byte-stride per-unit array
 * (`+0x3c0..+0x400`, real per-field defaults including a real masked
 * tiling-config reset at each slot's own `+0xc` sub-field) - the SAME
 * real "alt unit" array `write_r500_3d_blit_state_packet` already
 * reads via `this+0x3c0`/`this+0x3b2` (this function is the real
 * initializer for that array), a real 4-entry `altUnitSelector`
 * mirror array, sets two real fields on the buffer object the base
 * class's own `start()` already allocated at `this+0xe0`, and finally
 * points this class's own `+0x360` extended-external-method-table
 * field at the already-fully-extracted `kGLSpecialMethod20` (real
 * content CONFIRMED via raw memory dump, not a gap - see
 * `IOATIR500GLContext_ExternalMethods.cpp`).
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile. Most individual
 * zeroed/defaulted fields' semantic roles beyond "reset at subclass
 * start" are UNKNOWN, matching this project's own established
 * convention for the base class's own analogous zero-init block.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

extern "C" void Start3D_mutex_lock(void *lockPtr) asm("_IOLockLock");
extern "C" void Start3D_mutex_unlock(void *lockPtr) asm("_IOLockUnlock");
extern const VendorExternalMethod kGLSpecialMethod20;

bool ATIR500GLContext::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

    Start3D_mutex_lock(*reinterpret_cast<void **>(providerBytes + 0x840));

    if (!IOATIR500GLContext::start(provider)) {
        Start3D_mutex_unlock(*reinterpret_cast<void **>(providerBytes + 0x840));
        return false;
    }

    U32At(self, 0x3bc) = 0;
    U32At(self, 0x34c) = 0;
    U32At(self, 0x350) = 0;
    U32At(self, 0x354) = 0;
    U32At(self, 0x358) = 0;

    UInt8 *slot = self;
    UInt8 *slotAlt = self + 0x3f0;
    for (int i = 6; i != 0; i--) {
        U16At(slot, 0x3d4) = 0;
        U16At(slot, 0x3d6) = 0;
        U16At(slot, 0x3d8) = 0;
        U16At(slot, 0x3dc) = 0;
        U16At(slot, 0x3de) = 0;
        U16At(slot, 0x3e0) = 1;
        U16At(slot, 0x3e2) = 1;
        U8At(slot, 0x3f4) = 0;
        U8At(slot, 0x3f5) = 0;
        U8At(slot, 0x3f6) = 0;
        U8At(slot, 0x3f7) = 0xff;
        U8At(slot, 0x3f8) = 0;
        U8At(slot, 0x3f9) = 0;
        U8At(slot, 0x3fb) = 6;
        U8At(slot, 0x3fc) = 0;
        U32At(slot, 0x3c0) = 0;
        U32At(slot, 0x3c4) = 0;
        U32At(slot, 0x3c8) = 0;
        U32At(slot, 0x3cc) = 0;
        U32At(slot, 0x3d0) = 0;
        U32At(slot, 0x3e4) = 0;
        U32At(slot, 1000) = 0xffffffff;
        U32At(slot, 0x3ec) = 0;
        U32At(slot, 0x3f0) = 0;
        U32At(slotAlt, 0xc) = (U32At(slotAlt, 0xc) & 0xff0007ffu) | 0x111000u;
        U32At(slot, 0x400) = 0;
        slotAlt += 0x78;
        U32At(slot, 0x404) = 0;
        slot += 0x78;
    }

    UInt16 unitDefault = U16At(self, 0xac);
    UInt8 *unitSlot = self;
    for (int i = 4; i != 0; i--) {
        U16At(unitSlot, 0x3b2) = 0;
        U16At(unitSlot, 0x3aa) = unitDefault;
        unitSlot += 2;
    }

    U16At(self, 0x3a8) = 1;
    U32At(reinterpret_cast<void *>(U32At(self, 0xe0)), 0x1c) = 9;
    U32At(reinterpret_cast<void *>(U32At(self, 0xe0)), 0x40) = 0x1000000;
    *reinterpret_cast<const VendorExternalMethod **>(self + 0x360) = &kGLSpecialMethod20;

    Start3D_mutex_unlock(*reinterpret_cast<void **>(providerBytes + 0x840));
    return true;
}
