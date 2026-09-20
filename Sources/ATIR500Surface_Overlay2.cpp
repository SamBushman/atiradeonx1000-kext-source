/* NOTE 2026-09-19: 3 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500Surface_Overlay2.cpp
 *
 * RESOLVED (issue #48): `ATIR500Surface::getFramebufferIndex`/
 * `alloc_overlay`/`setup_overlay`'s real bodies, real addrs 0x3a7a0/
 * 0x39160/0x391e0. All three are real, correctly-declared members
 * (linkage fixed under issue #16); their real call site is
 * `shape_surface`'s own overlay gate (`Sources/
 * ATIR500Surface_ShapeSurface.cpp`), which was itself explicitly
 * flagged there as a real residual left for this issue.
 *
 * `getFramebufferIndex`: walks a real 2-entry array of (pointer, flag)
 * pairs at `this+0xd60`/`this+0xd64` (stride 8 bytes - `this+0xd68`/
 * `this+0xd6c` for entry 1), returning the index of the LAST entry
 * (index 1 wins over index 0 if both qualify - real decompile has no
 * `break`) whose own `+0xd64`-style flag is nonzero AND whose pointed-at
 * record has nonzero real `SInt16`s at its own `+8`/+0xa. Returns 0 if
 * neither entry qualifies (real `iVar3` starts at 0 and is only ever
 * overwritten by a qualifying index). Real per-entry record identity
 * and the real meaning of its `+8`/`+0xa` fields (distinct from the
 * DIFFERENT `+0`/`+0x10`/`+0x12` fields `shape_surface`'s own separate,
 * already-committed gate checks on the SAME kind of record after
 * calling this function - see that file's own header comment) are
 * UNKNOWN.
 *
 * `alloc_overlay`: real body is `if (this+0xda4 == 0) return; this+0xd70
 * |= 2; return;` with NO explicit return statement - but the real call
 * site (`shape_surface`) uses its result as a non-null pointer
 * (`this[0xbf0] = alloc_overlay()`), and this project's own header
 * already declares a `UInt32` return. Since `this` (r3 on entry, per
 * this project's `__thiscall` convention) is never overwritten anywhere
 * in the real body, the real ABI return value is simply `this`
 * unconditionally - transcribed as such (a real "implicit self-return,
 * no explicit return statement" idiom, not this project's invention).
 *
 * `setup_overlay`: real body is a genuine, real EMPTY function (`return;`
 * only, no arguments read or written) - CONFIRMED, not a decompiler
 * artifact hiding a missed argument as this project's own prior filing
 * had speculated. Transcribed as a real no-op.
 *
 * Confidence: CONFIRMED for control flow and every real offset in all
 * three (all short enough for the raw Ghidra decompile to be trusted
 * directly). Real per-field HARDWARE/record semantics beyond what's
 * described above are UNKNOWN. No C++ compiler was available in the
 * sandboxed environment this was written in (same standing limitation
 * as every other file in this project).
 */

#include "../Headers/ATIR500Surface.h"

namespace {
inline UInt32 &W(void *p, int o) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }
} // namespace

/* (re-ported mechanically: see ATIR500Surface_getFramebufferIndex_Port.cpp) */



UInt32 ATIR500Surface::alloc_overlay(void) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (W(self, 0xda4) != 0) {
        W(self, 0xd70) |= 2;
    }
    /* real: no explicit return statement - r3 (this) is never
       overwritten, see file header comment. */
    return reinterpret_cast<UInt32>(self);
}


/* (re-ported mechanically: see ATIR500Surface_setup_overlay_Port.cpp) */


/*
 * free_overlay - RESOLVED (issue #1, get-it-linking pass), real addr
 * 0x391a0, the real inverse of `alloc_overlay` above - found while
 * resolving issue #55 (`stop`'s own real call, already committed).
 * Real body: clears the overlay handle at +0xd94 if set (WITHOUT
 * releasing it through a vtable call - transcribed exactly as
 * decompiled) and clears bit 0x2 of +0xd70, the exact inverse of
 * `alloc_overlay`'s own real `|= 2`.
 */
/* (re-ported mechanically: see ATIR500Surface_free_overlay_Port.cpp) */

