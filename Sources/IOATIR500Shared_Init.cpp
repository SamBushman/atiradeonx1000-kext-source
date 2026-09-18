/*
 * IOATIR500Shared_Init.cpp
 *
 * RESOLVED (issue #24, partial): `IOATIR500Shared::init`'s real body.
 * Real kext offset 0x16aa0. Calls `OSObject::init()` first - RESOLVED (issue
 * #58 follow-up): the call is an indirect one through the OSObject vtable
 * symbol (the Mach-O relocation at 0x16aa4 targets `__ZTV8OSObject`; slot
 * +0x48 of the real kernel's OSObject vtable, read statically from
 * /mach_kernel, is `OSObject::init()`), the conventional IOKit base-class call
 * every real `init()` override makes first. If
 * that succeeds, zeroes five real, previously-undocumented fields
 * (`this+0x10`/`+0x14`/`+0x18`/`+0x1c`/`+0x24`), calls the already-known
 * real `alloc_handles` (real addr `0x16910`, own body RESOLVED, issue
 * #28 - see `Sources/IOATIR500Shared_AllocHandles.cpp`), then zeroes a
 * sixth field (`this+0x20`). Real return value
 * is the same success/failure boolean the external base-class call
 * produced.
 *
 * The paired real `+0x18` (release-like) vtable call is RESOLVED, issue
 * #20 (live kxld-resolved memory read on real hardware): real target
 * `OSObject::release() const` - see `Headers/IOATIR500Shared.h`. This
 * function's own body doesn't touch it.
 *
 * Confidence: CONFIRMED for control flow and every field offset - a
 * real, standalone, complete decompile. No C++ compiler was available in
 * the sandboxed environment this was written in (same standing
 * limitation as every other file in this project) - checked by careful,
 * repeated manual re-reading against the raw decompile instead.
 */

#include "../Headers/IOATIR500Shared.h"

/* real object size, from its allocation site (issue #24); catches any drift in the OSObject base + pad layout */
static_assert(sizeof(IOATIR500Shared) == 0x28, "IOATIR500Shared must be 0x28 bytes");

bool IOATIR500Shared::init() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    bool ok = OSObject::init(); /* real: qualified base call (relocation at 0x16aa4 -> __ZTV8OSObject, slot +0x48 = OSObject::init()) */
    if (ok) {
        *reinterpret_cast<UInt32 *>(self + 0x24) = 0;
        *reinterpret_cast<UInt32 *>(self + 0x10) = 0;
        *reinterpret_cast<UInt32 *>(self + 0x18) = 0;
        *reinterpret_cast<UInt32 *>(self + 0x14) = 0;
        *reinterpret_cast<UInt32 *>(self + 0x1c) = 0;
        alloc_handles();
        *reinterpret_cast<UInt32 *>(self + 0x20) = 0;
    }
    return ok;
}
