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
 * `resolve_fsaa_buffer`/`back_resolve_fsaa_buffer`. A real, previously
 * undocumented WRINKLE: this function reads/writes
 * `ATIR500SurfaceBuffer+0x28` as an `HZMEM_Alloc` block-handle slot -
 * the SAME offset this project's own struct (`ATIRadeonX1000Types.h`)
 * already names `formatOrTilingBits` from an unrelated real function
 * (`page_off_texture`). NOT resolved this pass whether that's a real
 * dual-purpose field or a naming/offset error in one of the two
 * findings - accessed here via raw offset rather than the named field,
 * to avoid asserting either reading without more evidence; worth a
 * dedicated cross-check in a future pass.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant - a real, complete decompile, not summarized. `this+0x10`
 * (the real size/count passed to `ATIR500Memory::alloc`), `this+0x90`
 * (the real strategy-selection flag), and the `+0x28` wrinkle noted
 * above are transcribed as raw offsets rather than promoted to named
 * struct fields - neither this pass nor any earlier one has
 * independently corroborated their real roles beyond what's visible in
 * this function alone. No C++ compiler was available in the sandboxed
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

UInt32 ATIR500Surface::alloc_surface_buffer(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);
    UInt8 *accel;

    UInt32 tilingBits = U32At(buf, 0x3c);
    UInt32 isFsaaTarget = (tilingBits >> 0xb) & 1;

    if ((U32At(self, 0xbe8) & 0x700000u) == 0 ||
        (isFsaaTarget == 0 && buffer != reinterpret_cast<ATIR500SurfaceBuffer *>(self + 0x4e0))) {
        accel = reinterpret_cast<UInt8 *>(accelerator);
        if (U16At(accel, 0xa8) < U16At(buf, 0x1c)) return 0;
        if (U16At(accel, 0xaa) < U16At(buf, 0x1e)) return 0;
    } else {
        if ((tilingBits & 0xf00000u) != 0 &&
            static_cast<UInt32>(U16At(buf, 0x1c)) / ((tilingBits >> 0x14) & 0xfu) > 0x1000u) {
            return 0;
        }
        if (U16At(buf, 0x1e) > 0x1000) return 0;
        accel = reinterpret_cast<UInt8 *>(accelerator);
    }

    ATIR500Memory *pool;
    UInt32 requestedSize = U32At(buf, 0x10);

    if (U32At(self, 0x90) == 0) {
allocFallback:
        pool = *reinterpret_cast<ATIR500Memory **>(accel + 0x7c);
        UInt32 allocResult;
        if (U32At(accel, 0xd0) == 0) {
            allocResult = pool->alloc(reinterpret_cast<GLKMemoryElement *>(buffer), requestedSize, 0x1000, 0x10000, U32At(accel, 0x84c) - 0x10000);
        } else {
            allocResult = pool->alloc(reinterpret_cast<GLKMemoryElement *>(buffer), requestedSize, 0x1000, 0, U32At(accel, 0x84c));
        }
        if (allocResult == 0) return 0;
    } else {
        pool = *reinterpret_cast<ATIR500Memory **>(accel + 0x7c);
        UInt32 used = U32At(accel, 0x84c);
        UInt8 fmtIdx = U8At(buf, 0x3a); /* real: formatTableIndex, checked here against a raw range, not looked up */
        bool notEligible = (static_cast<UInt8>(fmtIdx - 0x2d) > 1) && (fmtIdx != 0xb);
        if (U32At(accel, 0x9c) <= used || notEligible) {
            goto allocFallback;
        }
        UInt32 allocResult = pool->alloc(reinterpret_cast<GLKMemoryElement *>(buffer), requestedSize, 0x1000, used, U32At(accel, 0x9c) - used);
        if (allocResult == 0) {
            accel = reinterpret_cast<UInt8 *>(accelerator);
            goto allocFallback;
        }
    }

    if (isFsaaTarget == 0) {
        if (buffer != reinterpret_cast<ATIR500SurfaceBuffer *>(self + 0x4e0)) {
            return 1;
        }

        UInt32 rowsPerBlock = 0;
        UInt32 tb = U32At(buf, 0x3c);
        if ((tb & 0xf00000u) != 0) {
            rowsPerBlock = static_cast<UInt32>(U16At(buf, 0x14)) / ((tb >> 0x14) & 0xfu);
        }
        UInt32 minRows = 0x20u / U16At(buf, 0x16);
        if (minRows <= rowsPerBlock) minRows = rowsPerBlock;
        UInt32 divisor = U32At(accel, 0xb98);
        UInt32 blockSize;
        if (divisor != 4) {
            blockSize = 0;
            UInt32 scaled = divisor << 4;
            if (scaled != 0) blockSize = scaled * ((scaled + minRows - 1) / scaled);
        } else {
            blockSize = 0x20u * ((0x20u + minRows - 1) / 0x20u);
        }

        UInt16 extra1e = U16At(buf, 0x1e);
        UInt32 alignedHeight = extra1e;
        if ((extra1e & 0x1f) != 0) alignedHeight = (extra1e & 0xffffffe0u) + 0x20;

        UInt32 hzResult = HZMEM_Alloc(reinterpret_cast<_HZDATA *>(accel + 0x870), U32At(buf, 0x28), 2, blockSize, alignedHeight);
        U32At(buf, 0x28) = hzResult;
        return 1;
    }

    /* real: unconditional fallthrough for real FSAA-target buffers - first HZMEM_Alloc, blockKind 0 */
    UInt32 rowsPerBlock1 = 0;
    UInt32 tb1 = U32At(buf, 0x3c);
    if ((tb1 & 0xf00000u) != 0) {
        rowsPerBlock1 = static_cast<UInt32>(U16At(buf, 0x14)) / ((tb1 >> 0x14) & 0xfu);
    }
    UInt32 minRows1 = 0x20u / U16At(buf, 0x16);
    if (minRows1 <= rowsPerBlock1) minRows1 = rowsPerBlock1;
    UInt32 divisor1 = U32At(accel, 0xb98);
    UInt32 blockSize1;
    if (divisor1 == 4) {
        blockSize1 = 0x20u * ((0x20u + minRows1 - 1) / 0x20u);
    } else {
        UInt32 scaled1 = divisor1 << 4;
        blockSize1 = 0;
        if (scaled1 != 0) blockSize1 = scaled1 * ((scaled1 + minRows1 - 1) / scaled1);
    }
    UInt16 extra1e1 = U16At(buf, 0x1e);
    UInt32 alignedHeight1 = extra1e1;
    if ((extra1e1 & 0x1f) != 0) alignedHeight1 = (extra1e1 & 0xffffffe0u) + 0x20;

    UInt32 hzResult1 = HZMEM_Alloc(reinterpret_cast<_HZDATA *>(accel + 0x870), U32At(buf, 0x28), 0, blockSize1, alignedHeight1);
    U32At(buf, 0x28) = hzResult1;

    UInt32 tb2;
    if (U16At(buf, 0x16) == 2) {
        tb2 = U32At(buf, 0x3c);
        if (((tb2 >> 0x14) & 0xf) > 1) return 1;
    } else {
        tb2 = U32At(buf, 0x3c);
    }

    /* real: second HZMEM_Alloc, blockKind 1, using the FIRST call's own result as its
     * "existing block" argument (not re-reading buf+0x28) */
    UInt32 rowsPerBlock2 = 0;
    if ((tb2 & 0xf00000u) != 0) {
        rowsPerBlock2 = static_cast<UInt32>(U16At(buf, 0x14)) / ((tb2 >> 0x14) & 0xfu);
    }
    UInt32 minRows2 = 0x20u / U16At(buf, 0x16);
    if (minRows2 <= rowsPerBlock2) minRows2 = rowsPerBlock2;
    UInt32 divisor2 = U32At(accel, 0xb98);
    UInt32 blockSize2;
    if (divisor2 != 4) {
        blockSize2 = 0;
        UInt32 scaled2 = divisor2 << 4;
        if (scaled2 != 0) blockSize2 = scaled2 * ((scaled2 + minRows2 - 1) / scaled2);
    } else {
        blockSize2 = 0x20u * ((0x20u + minRows2 - 1) / 0x20u);
    }
    UInt16 extra1e2 = U16At(buf, 0x1e);
    UInt32 alignedHeight2 = extra1e2;
    if ((extra1e2 & 0x1f) != 0) alignedHeight2 = (extra1e2 & 0xffffffe0u) + 0x20;

    UInt32 hzResult2 = HZMEM_Alloc(reinterpret_cast<_HZDATA *>(accel + 0x870), hzResult1, 1, blockSize2, alignedHeight2);
    U32At(buf, 0x28) = hzResult2;
    return 1;
}
