/*
 * ATIR500Surface_AllocSurfaceBuffer.cpp
 *
 * RESOLVED (issue #22): `ATIR500Surface::alloc_surface_buffer`'s real
 * body - subclass-only (base's own copy of this vtable slot is genuine
 * placeholder content, issue #18), real addr `0x3e230`.
 *
 * Real structure: picks between two real size-limit checks depending on
 * whether this surface's own mode-bits flag (`this+0xbe8`, the same real
 * field `is_flip_allowed`/`ATIR500Surface_ResolveFSAABuffer.cpp` already
 * established) is set AND the buffer being allocated is NOT this
 * surface's own fixed buffer (`this+0x4e0`) - CONFIRMED to be the same
 * real "fixed buffer" role `resolve_fsaa_buffer` already established for
 * a different but related field. In that combined case, checks the
 * buffer's own width/height against a real per-tiling-degree-divided
 * limit (`0x1000`); otherwise checks against the accelerator's own real
 * max width/height fields (`accelerator+0xa8`/`+0xaa`, the SAME fields
 * `is_surface_size_supported` already established).
 *
 * Delegates the real allocation to `ATIR500Memory::alloc` (the same
 * class this project found in issue #23) via the accelerator's "main"
 * GART pool (`accelerator+0x7c`) - real strategy selection (which of
 * three real range-argument shapes to use) mirrors
 * `ATIRadeonX1000::allocate_texture`'s own real "prefer overflow region,
 * fall back if the accelerator's own VRAM budget/cap fields disagree, or
 * if a real per-surface flag at `this+0x90` says so" pattern (RESOLVED,
 * issue #23) - a real, previously-unnoticed structural echo between two
 * functions this project transcribed independently, on two different
 * classes.
 *
 * On success, real HyperZ-block bookkeeping via the already-known
 * `HZMEM_Alloc` - real block-size computation (a shared real formula,
 * used up to three times) reuses the same real per-tiling-degree/pitch
 * arithmetic this project has already independently transcribed in
 * `resolve_fsaa_buffer`/`back_resolve_fsaa_buffer`. This function reads/
 * writes `ATIR500SurfaceBuffer+0x28` as an `HZMEM_Alloc` block-handle
 * slot - RESOLVED via a targeted follow-up cross-check: this IS that
 * field's real, sole role (now named `hzBlockField`,
 * `ATIRadeonX1000Types.h`). The earlier `formatOrTilingBits` naming was a
 * real scope error in this project's own prior documentation - decompiling
 * `page_off_texture` directly (it had never actually been transcribed)
 * showed its own "+0x28" read is on an entirely different struct (a
 * per-face mip sub-record's already-known `loadedBits` field), not this
 * one at all. `ATIR500Surface_ResolveFSAABuffer.cpp`'s own already-
 * committed usage of the same field independently confirms the real
 * bit-layout matches `HZMEM_Free`'s (issue #28) exactly.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant - a real, complete decompile, not summarized. `this+0x10`
 * (the real size/count passed to `ATIR500Memory::alloc`) and `this+0x90`
 * (the real strategy-selection flag) are transcribed as raw offsets
 * rather than promoted to named struct fields - neither this pass nor
 * any earlier one has independently corroborated their real roles beyond
 * what's visible in this function alone. No C++ compiler was available
 * in the sandboxed
 * environment this was written in (same standing limitation as every
 * other file in this project) - checked by careful, repeated manual
 * re-reading against the raw decompile instead.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/ATIR500Memory.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see ATIR500Surface_alloc_surface_buffer_Port.cpp) */

