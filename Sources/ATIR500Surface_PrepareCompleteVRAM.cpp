/*
 * ATIR500Surface_PrepareCompleteVRAM.cpp
 *
 * RESOLVED (issue #22): `ATIR500Surface::prepare_vram`/`complete_vram`'s
 * real bodies - the subclass overrides, real addrs `0x3dc50`/`0x3c000`
 * (the base class's own trivial `return 1;` copies, `0x110e0`/`0x110f0`,
 * were already transcribed - `Headers/IOATIR500Surface.h`).
 *
 * REAL RETURN TYPE BUG CAUGHT AND FIXED: both were originally declared
 * `void` (issue #18/#22's first pass) - both real bodies (base AND
 * subclass, all four) return a real, checked `UInt32` (0/1). Fixed in
 * `Headers/IOATIR500Surface.h`; the two real call sites
 * (`Sources/IOATIR500Surface_LockShape.cpp`'s `surface_write_lock_int`/
 * `unlock_int`) already discard the result as a bare statement, which
 * remains valid C++ with the corrected non-void return type - no call
 * site fix needed.
 *
 * Both real functions manage a real per-accelerator "VRAM lock ID" pool
 * (`accelerator+0x890`, a real 32-bit bitmask of in-use IDs, capped at a
 * real per-accelerator limit `accelerator+0x990`) - `prepare_vram`
 * allocates one real ID and stamps it into the buffer's own `+0x37`
 * byte, `complete_vram` releases it. Both also touch a real reference-
 * count BYTE that shares a 32-bit word with the already-named
 * `tilingDegreeBits` field (`ATIR500SurfaceBuffer+0x3c`,
 * `ATIRadeonX1000Types.h`) - CONFIRMED not to conflict: on this
 * big-endian target, `tilingDegreeBits`'s own established bit ranges
 * (`&0xf00000`, `(>>0x14)&0xf` - bits 20-23, the word's SECOND byte)
 * never overlap the raw BYTE this function reads/writes at the exact
 * same base address (the word's FIRST/most-significant byte on this
 * big-endian target) - two real, independent sub-fields of one 32-bit
 * word, accessed here via raw offset rather than through the named
 * field to avoid conflating them.
 *
 * Real gate on whether either function does any hardware work at all:
 * a real byte at `accelerator+0x80` (`*(char*)((int*)accel + 0x20)` in
 * the raw decompile - an `int*`-scaled pointer addition, NOT a byte
 * offset of `0x20`, a real trap this project's own transcription caught
 * and corrected before commit). If clear, both functions return after
 * only managing the ID pool. If set, both reach through
 * `accelerator->scratchHeader` (word-indexed `piVar4[0x8e]` in the raw
 * decompile - RESOLVED, issue #52, via pure static analysis: the
 * accelerator's own default/scratch `VendorCommandBuffer`'s real
 * hardware-mappable header, `Headers/ATIRadeonX1000.h`) to build and
 * submit a real PM4 burst there.
 *
 * `prepare_vram`'s burst: a real per-format lookup picks a real
 * "swizzle/tile mode" constant from the buffer's own tiling-config byte
 * (`+0x38`), computes a real per-mip byte offset, and - depending on a
 * real "has stencil" bit in the buffer's own tiling bits (`&0x800`) -
 * either writes 4 real fixed register-burst dwords directly, or calls
 * the already-known `decompress_and_flush_depth_buffer` to build the
 * burst instead. Wrapped in two real completion-stamp accumulation
 * calls (`ATIRadeonX1000::waitForTimeStamp`, RESOLVED issue #23 - one
 * before building the burst, one after submitting it) and a real
 * `ATIRadeonX1000::submit_buffer` call, storing the result into a real
 * per-accelerator field (`accelerator+0x234`) - the SAME field read as
 * `waitForTimeStamp`'s own tag argument on both calls, consistent with
 * a real "last submission's own completion tag" role.
 *
 * `complete_vram`'s burst is the simpler inverse: a single real fixed
 * 6-dword clear/reset burst (no per-format lookup, no depth-buffer
 * path), same real `waitForTimeStamp`/`submit_buffer`/`accelerator+0x234`
 * pattern, called once.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant - two real, complete decompiles, not summarized.
 * `scratchHeader`'s own real identity is now RESOLVED (issue #52) and
 * independently cross-validated against a THIRD real usage site
 * (`ATIR500Surface::stop`, kext offset 0x3b0c0) that agrees exactly on
 * both this field and `pendingTimeStamp` - see `Headers/ATIRadeonX1000.h`'s
 * own comment for the full account. Its own internal field offsets
 * (`+0x120`, `+0x124`, etc. - past the 0x20-byte `VendorContextBufferHeader`
 * proper, within the buffer's own larger 0x1000-byte allocation) and the
 * real per-format lookup table indices/constants in `prepare_vram`'s own
 * burst remain transcribed as raw offsets/literals rather than promoted
 * to named fields - not independently corroborated beyond what's visible
 * in these two functions alone. No C++ compiler was available in the sandboxed
 * environment this was written in (same standing limitation as every
 * other file in this project) - checked by careful, repeated manual
 * re-reading against each raw decompile instead.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Registers.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see ATIR500Surface_prepare_vram_Port.cpp) */


/* (re-ported mechanically: see ATIR500Surface_complete_vram_Port.cpp) */

