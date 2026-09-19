/*
 * IOATIR500Surface_VtableSlotBodies.cpp
 *
 * RESOLVED (issue #22, partial): real bodies for the SMALL/SIMPLE members
 * of the 12 real vtable slots issue #18 named. The larger, denser members
 * of that same set (`dealloc_surface`'s subclass override,
 * `alloc_surface_buffer`, `prepare_vram`'s subclass override,
 * `resetFullScreen`'s subclass override, `shape_surface`) are tracked
 * separately - substantial real functions in their own right, deferred
 * to a dedicated follow-up pass rather than rushed here.
 *
 * update_ref_stamps / increment_refcounts / decrement_refcounts -
 * CONFIRMED real, genuine NO-OPS on the base class (not subclass-
 * overridden - `ATIR500Surface`'s own vtable has the identical addresses).
 * A real, previously-unknown finding: this whole trio - reached from
 * `IOATIR500GLContext::remove_texture_from_stream`/`add_texture_to_stream`
 * (`IOATIR500GLContext_TextureStream.cpp`) - does nothing at all in this
 * exact shipped kext build, the same "real empty no-op" pattern already
 * found for three of the five overlay-family methods
 * (`Sources/ATIR500Surface_Overlay.cpp`). `update_ref_stamps` still
 * returns its own second argument verbatim (dead code from the caller's
 * perspective, since neither real call site uses the return value).
 *
 * invalidate - CONFIRMED, subclass-only (base's own copy of this slot is
 * genuine placeholder content, issue #18). Real body: walks a real
 * fixed-stride array of pointers at `this+0xc34` (stride `0x94`),
 * count from `accelerator+0xcc`, setting bit 0 on each entry's own
 * `+0x1c` field - a real "mark N contexts dirty" sweep, matching the
 * same real per-context dirty-bit role `ATIR500GLContext::invalidate`
 * (issue #12.1) already established for its own class.
 *
 * prepare_vram / complete_vram - base class bodies CONFIRMED real,
 * genuine no-op-style stubs (`return 1;`, no side effects) - the real
 * work happens entirely in `ATIR500Surface`'s own subclass override
 * (tracked separately, see this file's own top comment).
 *
 * is_flip_allowed - CONFIRMED both levels. Base: real gate on three
 * conditions (accelerator's `+0x80` byte nonzero, this surface's own
 * `+0xc14` ID slot not `0xffff`, and a real identity check against the
 * accelerator's own `id*0x20+0xe8`-indexed pointer table - the SAME real
 * ID-slot table `set_id_mode`, issue #8, already established). Subclass:
 * calls the base version first, then ANDs in two more real gates
 * (`accelerator+0x9b0` byte nonzero, and either `accelerator's
 * id*0x18+0xb10` word nonzero or a real fallback pair of checks on
 * `accelerator+0x894`/`+0xb00`/`+0xb18`) - real "is a flip currently
 * possible" composite check. A final real gate common to both levels:
 * `this+0xbe8`'s own sign bit (`-1 < *(int*)(this+0xbe8)`) must be clear
 * for the subclass to report success at all - the SAME real Surface
 * mode-bits field this project's own `ATIR500Surface_ResolveFSAABuffer.cpp`
 * correction (issue #17) already independently confirmed.
 *
 * is_surface_size_supported - CONFIRMED both levels. Base: real check
 * against the accelerator's own max width/height fields
 * (`accelerator+0xa8`/`+0xaa`, real `UInt16`s). Subclass: calls the base
 * version first, then ALSO rejects if BOTH width AND height (not
 * either) exceed `0x1000` (4096) - transcribed exactly as found, not
 * "fixed" to use OR despite that reading like the more obvious real
 * intent. Real mangled parameter types are `short`
 * (`Headers/IOATIR500Surface.h`'s own declaration already corrected to
 * match).
 *
 * Confidence: CONFIRMED for every function in this file - complete real
 * decompiles, not summarized. No C++ compiler was available in the
 * sandboxed environment this was written in (same standing limitation as
 * every other file in this project) - checked by careful, repeated
 * manual re-reading against each raw decompile instead.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see IOATIR500Surface_update_ref_stamps_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_increment_refcounts_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_decrement_refcounts_Port.cpp) */


/* (re-ported mechanically: see ATIR500Surface_invalidate_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_prepare_vram_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_complete_vram_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_is_flip_allowed_Port.cpp) */


/* (re-ported mechanically: see ATIR500Surface_is_flip_allowed_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_is_surface_size_supported_Port.cpp) */



SInt32 ATIR500Surface::is_surface_size_supported(SInt16 width, SInt16 height) {
    SInt32 base = IOATIR500Surface::is_surface_size_supported(width, height);
    if (base == 0 || (width > 0x1000 && height > 0x1000)) {
        return 0;
    }
    return 1;
}

