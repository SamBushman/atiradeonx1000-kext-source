/*
 * ATIR500Surface_DecompressAndFlushDepthBuffer.cpp
 *
 * RESOLVED (issue #38): `ATIR500Surface::decompress_and_flush_depth_buffer`'s
 * real body, real addr 0x3db40.
 *
 * Real body: clears the accelerator's real `+0xb94` flag (the same
 * "swap chain active" flag `shape_surface` sets to `1` -
 * `Sources/ATIR500Surface_ShapeSurface.cpp` - CONFIRMED cross-reference,
 * this function clears it back to `0`). Checks the real scratch
 * buffer's own `+0x34` byte (`scratch->field_0x34`, an
 * `ATIR500SurfaceBuffer`-relative byte offset per this project's
 * established "class-typed pointer already byte-scaled" convention):
 *
 * - If zero (no real depth data to decompress): writes a fixed real
 *   6-dword PM4 "no-op flush" packet directly into the caller's record
 *   buffer at `record[param2]` (`0x1393`/`10`/`0x13c6`/`3`/`0x5c8`/
 *   `0x20000` - the first two dwords, `0x1393`/count `10`, are the same
 *   real burst-header literal pair this project has now independently
 *   confirmed at least 4 other places, per
 *   `ATIR500GLContext_RestoreState.cpp`'s own note), and returns
 *   `param2 + 6` (the new record-dword index/count).
 * - Otherwise: calls `load_3d_blit` (own body RESOLVED, issue #47 - see
 *   Sources/ATIR500Surface_Load3DBlit.cpp) to emit the real
 *   depth-decompress PM4 sequence directly into `record + param2`,
 *   returns the resulting dword index
 *   as `(endPointer - record) / 4` (real: `>> 2`, a byte-to-dword
 *   conversion, not this project's `int*`-scaling trap - `load_3d_blit`
 *   real returns a byte pointer per the raw decompile's own explicit
 *   `(int)` cast before the shift), and sets two more real accelerator
 *   flags: `+0xb90 = 1` and `+0x78 = 0` (real roles UNKNOWN beyond
 *   "something about the just-emitted depth-decompress packet the
 *   accelerator needs to know about" - not independently investigated
 *   this pass).
 *
 * Confidence: CONFIRMED for control flow and every real offset -
 * `this+0xd50` is this project's already-established `accelerator`
 * field (ATIR500Surface.h), `scratch[0x34]` uses the same real
 * byte-scaled convention already established for `this`/class-typed
 * pointers throughout this project. `load_3d_blit`'s own body is now
 * RESOLVED too (issue #47). No C++ compiler was available in the
 * sandboxed environment this was written in (same standing limitation
 * as every other file in this project).
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

UInt32 ATIR500Surface::decompress_and_flush_depth_buffer(ATIR500SurfaceBuffer *scratch, UInt32 param2, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *scratchBytes = reinterpret_cast<UInt8 *>(scratch);
    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);

    U32At(accel, 0xb94) = 0;

    if (U8At(scratchBytes, 0x34) == 0) {
        record[param2 + 0] = 0x1393;
        record[param2 + 1] = 10;
        record[param2 + 2] = 0x13c6;
        record[param2 + 3] = 3;
        record[param2 + 4] = 0x5c8;
        record[param2 + 5] = 0x20000;
        return param2 + 6;
    }

    UInt32 *end = load_3d_blit(record + param2, scratch);
    UInt32 result = static_cast<UInt32>(reinterpret_cast<UInt8 *>(end) - reinterpret_cast<UInt8 *>(record)) >> 2;
    U32At(accel, 0xb90) = 1;
    U32At(accel, 0x78) = 0;
    return result;
}
