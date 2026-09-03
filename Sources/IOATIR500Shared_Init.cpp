/*
 * IOATIR500Shared_Init.cpp
 *
 * RESOLVED (issue #24, partial): `IOATIR500Shared::init`'s real body.
 * Real kext offset 0x16aa0. Calls a real, unidentified external symbol
 * first (a real kxld-patched call site, same real-address-only-at-
 * load-time category this project already established for the
 * accelerator's own factory slots, issue #6, before those were resolved
 * via the concrete-subclass-vtable technique - no subclass exists for
 * this class to try that technique on, so this one really does look
 * external) - almost certainly `OSObject::init()`, the conventional
 * IOKit base-class call every real `init()` override makes first. If
 * that succeeds, zeroes five real, previously-undocumented fields
 * (`this+0x10`/`+0x14`/`+0x18`/`+0x1c`/`+0x24`), calls the already-known
 * real `alloc_handles` (real addr `0x16910`, own body not decompiled
 * this pass), then zeroes a sixth field (`this+0x20`). Real return value
 * is the same success/failure boolean the external base-class call
 * produced.
 *
 * The paired real `+0x18` (release-like) vtable call issue #20 already
 * confirmed as genuinely unresolvable statically stays that way - this
 * function's own body doesn't touch it.
 *
 * Confidence: CONFIRMED for control flow and every field offset - a
 * real, standalone, complete decompile. No C++ compiler was available in
 * the sandboxed environment this was written in (same standing
 * limitation as every other file in this project) - checked by careful,
 * repeated manual re-reading against the raw decompile instead.
 */

#include "../Headers/IOATIR500Shared.h"

extern "C" bool IOATIR500Shared_super_init(void *self); /* real external call, almost certainly OSObject::init() - own real target unresolved, matches issue #6's pre-resolution category (kxld-patched, no local body) */

bool IOATIR500Shared::init() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    bool ok = IOATIR500Shared_super_init(this);
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
