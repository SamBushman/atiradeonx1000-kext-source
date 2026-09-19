/*
 * ATIR500Surface_Stop.cpp
 *
 * RESOLVED (issue #55): `ATIR500Surface::stop(IOService*)`'s real body,
 * real addr 0x3b0c0 - found while resolving issue #52 (a partial read of
 * this function is what originally confirmed `ATIRadeonX1000::
 * scratchHeader`/`pendingTimeStamp`). No separate `IOATIR500Surface::stop`
 * symbol exists in this kext - unlike the GL context pair (issue #49),
 * this class's own base apparently doesn't override `IOUserClient::stop`
 * itself; the real tail call at the end of this function (a lazy Mach-O
 * symbol pointer in the raw decompile) is presumed to be `IOUserClient::
 * stop` directly, matching this project's own established convention for
 * this exact idiom - not independently re-verified via live memory this
 * pass.
 *
 * `provider` here is really this surface's own accelerator (the real
 * decompile never reads `this+0xd50` - the already-established
 * `accelerator` field - at all, using the `IOService*` parameter directly
 * for every accelerator-relative access instead; same real convention
 * already established for `ATIR500GLContext::stop`, issue #49).
 *
 * Real body, in order:
 * 1. Locks `provider`'s own `commandLock` (`+0x840`) - real stub
 *    addresses `0x3b2fc`/`0x3b2cc` for lock/unlock, presumed
 *    `_mutex_lock`/`_mutex_unlock_rwcmb` (verified, issue #58 follow-up; see
 *    the declarations below) like every other real `commandLock` bracket
 *    in this project (e.g. `ATIR500DVDContext::set_macrovision`).
 * 2. Walks the real 23-entry `ATIR500SurfaceBuffer` array at `this+0xa8`
 *    (stride `0x78` - the SAME array `shape_surface` reshapes), calling
 *    the already-resolved `complete_vram` (vtable `+0x600`) on every slot
 *    whose own VRAM-lock-ID byte (`slot+0x37`, the SAME field `prepare_
 *    vram`/`complete_vram` already manage, issue #22) is not `0xff`
 *    (i.e. still holds an outstanding VRAM prepare lock) - releasing
 *    every real outstanding lock before teardown.
 * 3. If this surface is the real currently-registered "active" surface
 *    for its own real panel/display ID slot (`this+0xc14`, already
 *    established as `idSlot` elsewhere - `Sources/
 *    IOATIR500Surface_VtableSlotBodies.cpp`/`Sources/
 *    IOATIR500Surface_LockShape.cpp` - checked against the accelerator's
 *    own real per-panel registration array, `provider+idSlot*0x20+0xe8`,
 *    same array `set_id_mode`/`is_flip_allowed` already use) AND the
 *    device is active (`provider+0x80`, `deviceActiveFlag`): writes the
 *    real per-panel overlay-format selector (`provider+idSlot*0x78+0x164`
 *    - the SAME field `shape_surface` already writes, via a different
 *    real base-pointer expression reaching the same accelerator) from
 *    this surface's own `+0xdb8` field's low byte (a real, previously
 *    untracked field - own broader role UNKNOWN beyond feeding this one
 *    write). Then, if `is_flip_allowed()` (already-resolved virtual, real
 *    addr varies base/subclass) says no, OR this surface's own cached
 *    "last flipped-away-from" pointer (`this+0xb74`, already established
 *    by `resetFullScreen`, issue #18 - compared here against `this+0x120`,
 *    a real embedded sub-object within the surface itself) already equals
 *    `this+0x120`, submits an EMPTY (0-dword) buffer; otherwise builds a
 *    real 2-dword PM4 burst into the accelerator's own scratch command
 *    buffer (`scratchHeader+0x120`/`+0x124`, issue #52) - a real "flip
 *    away from this surface" register write (literal header `0x1844` for
 *    panel 0, `0x1a44` otherwise, second dword copied from
 *    `provider+idSlot*0x78+0x134`, another real per-panel accelerator
 *    field not independently corroborated elsewhere) - and updates
 *    `this+0xb74 = this+0x120` to record that this surface's own flip-away
 *    state is now current. Either way, wraps the burst in the already-
 *    established `waitForTimeStamp`/`submit_buffer`/`pendingTimeStamp`
 *    pattern (issue #52).
 * 4. Frees this surface's own overlay handle if allocated (`this+0xbf0`,
 *    already established - issue #48) via the real, previously-untracked
 *    `free_overlay()` (RESOLVED, issue #55 - see `Headers/
 *    ATIR500Surface.h`), the exact real inverse of `alloc_overlay`.
 * 5. If a real, previously-untracked accelerator-owned GART-transfer-
 *    buffer-shaped record at `provider+0x8a8` is flagged live
 *    (`provider+0x8b8` nonzero - real relative offsets do not match this
 *    project's usual `VendorCommandBuffer`-shaped `+4`/`+8` convention
 *    exactly, transcribed literally rather than forced into that shape):
 *    calls `removeTransferFromGART` on it and releases a nested handle at
 *    `provider+0x8b0` (vtable `+0x18`), then clears the flag. Own real
 *    identity/role UNKNOWN beyond this one call site.
 * 6. Tail-calls the presumed `IOUserClient::stop` and unlocks
 *    `commandLock`.
 *
 * Confidence: CONFIRMED for control flow and every real offset against
 * the raw Ghidra decompile (one complete, standalone decompile - not
 * independently re-traced via raw disassembly given its moderate size
 * and the number of already-established cross-references corroborating
 * it). Several real fields (`this+0xdb8`, `provider+0x8a8`/`+0x8b0`/
 * `+0x8b8`, `provider+idSlot*0x78+0x134`, `this+0x120`'s own broader
 * role) remain UNKNOWN beyond their one confirmed usage here. No C++
 * compiler was available in the sandboxed environment this was written
 * in (same standing limitation as every other file in this project).
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }

inline void ReleaseObj(void *obj) {
    typedef void (*ReleaseFn)(void *);
    void **vtable = *reinterpret_cast<void ***>(obj);
    reinterpret_cast<ReleaseFn>(vtable[0x18 / 4])(obj);
}
} // namespace

/* real addrs 0x3b2fc/0x3b2cc - VERIFIED (issue #58 follow-up), both by live kxld read and by the
   Mach-O relocation table (`IOLockLock`/`IOLockUnlock`, which kxld resolves to
   `mutex_lock`/`mutex_unlock_rwcmb`, and imported by those KPI names - `mutex_unlock_rwcmb` itself is
   not exported). CORRECTED: this file (and two others) previously aliased the unlock to `_mutex_unlock`, a
   different kernel function (0xa49c0) than the real target (0xa4b20). */
extern "C" void FUN_0003b2fc(void *lockPtr) asm("_IOLockLock");
extern "C" void FUN_0003b2cc(void *lockPtr) asm("_IOLockUnlock");

/* (re-ported mechanically: see ATIR500Surface_stop_Port.cpp) */

