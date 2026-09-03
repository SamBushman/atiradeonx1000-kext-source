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
 * only managing the ID pool. If set, both reach through a real
 * accelerator-owned pointer at `accelerator+0x238` (word-indexed
 * `piVar4[0x8e]` in the raw decompile - a real "extended command ring"
 * object, own real identity/type not investigated) to build and submit
 * a real PM4 burst there.
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
 * constant - two real, complete decompiles, not summarized. The real
 * "extended command ring" object at `accelerator+0x238` and its own
 * internal field offsets (`+0x120`, `+0x124`, etc.), and the real
 * per-format lookup table indices/constants in `prepare_vram`'s own
 * burst, are transcribed as raw offsets/literals rather than promoted to
 * named fields - neither this pass nor any earlier one has independently
 * corroborated their real roles beyond what's visible in these two
 * functions alone. No C++ compiler was available in the sandboxed
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

UInt32 ATIR500Surface::prepare_vram(ATIR500SurfaceBuffer *buffer) {
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    UInt8 refCount = U8At(buf, 0x3c);
    U8At(buf, 0x3c) = refCount + 1;
    if (refCount + 1 > 1) {
        return 1; /* real: re-entrant prepare, ID pool untouched */
    }

    if (U8At(accel, 0x990) == 0) {
        U8At(buf, 0x37) = 0;
        return 0; /* real: engine not ready */
    }

    UInt32 idMask = U32At(accel, 0x890);
    UInt32 id = 0;
    if ((idMask & 1) != 0) {
        do {
            id = (id + 1) & 0xff;
            if (id == U8At(accel, 0x990)) {
                U8At(buf, 0x37) = 0;
                return 0; /* real: no free ID */
            }
        } while ((idMask & (1u << (id & 0x3f))) != 0);
    }
    U32At(accel, 0x890) = (1u << (id & 0x3f)) | idMask;
    U8At(buf, 0x37) = static_cast<UInt8>(id);

    if (U8At(accel, 0x80) == 0) { /* real: *(char*)((int*)accel + 0x20), int*-scaled - NOT accel+0x20 */
        return 1; /* real: no extended command-ring burst needed */
    }

    UInt8 *ring = reinterpret_cast<UInt8 *>(U32At(accel, 0x238)); /* real: piVar4[0x8e], word-indexed */
    UInt32 idByteOffset = id * 4;
    UInt32 mipOffset = *reinterpret_cast<UInt32 *>(buf + 8);
    UInt32 *record = reinterpret_cast<UInt32 *>(ring + 0x120);

    UInt32 formatWord, sizeWord;
    if (((U32At(buf, 0x3c) >> 0x14) & 0xf) < 2) {
        UInt32 tileMode;
        switch (U8At(buf, 0x38)) {
            case 1: tileMode = 1; break;
            case 2: tileMode = 2; break;
            case 3: tileMode = 3; break;
            case 4: tileMode = 6; break;
            case 5: tileMode = 7; break;
            default: goto noTileMode;
        }
        formatWord = tileMode << 0x10;
        sizeWord = static_cast<UInt32>(U16At(buf, 0x18) >> 3);
    } else {
noTileMode:
        formatWord = 0;
        sizeWord = 0;
    }

    UInt8 stencilBits = U8At(buf, 0x39);
    accelerator->waitForTimeStamp(U32At(accel, 0x234));

    *record = idByteOffset + 0x2c1;
    *reinterpret_cast<UInt32 *>(ring + 0x124) = mipOffset;
    *reinterpret_cast<UInt32 *>(ring + 0x128) = idByteOffset + 0x2c2;
    *reinterpret_cast<UInt32 *>(ring + 300) = mipOffset + *reinterpret_cast<UInt32 *>(buf + 0x10) - 1;
    *reinterpret_cast<UInt32 *>(ring + 0x130) = idByteOffset + 0x2c3;
    *reinterpret_cast<UInt32 *>(ring + 0x134) = formatWord | sizeWord | ((stencilBits & 3u) << 0x14) | ((stencilBits & 3u) << 0x16);

    UInt32 tailIndex, tailByteOffset, tailPlus1, tailPlus2;
    if ((U32At(buf, 0x3c) & 0x800) == 0) {
        *reinterpret_cast<UInt32 *>(ring + 0x138) = 0xd0b;
        *reinterpret_cast<UInt32 *>(ring + 0x13c) = 5;
        *reinterpret_cast<UInt32 *>(ring + 0x140) = 0x1393;
        *reinterpret_cast<UInt32 *>(ring + 0x144) = 10;
        tailIndex = 10;
        tailByteOffset = 0x28;
        tailPlus1 = 0xb;
        tailPlus2 = 0xc;
    } else {
        tailIndex = decompress_and_flush_depth_buffer(buffer, 6, record);
        tailByteOffset = tailIndex << 2;
        tailPlus1 = tailIndex + 1;
        tailPlus2 = tailIndex + 2;
    }

    *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(record) + tailByteOffset) = 0x5c8;
    record[tailPlus1] = 0x70000;
    UInt32 finalCount = tailPlus2;
    if ((tailPlus2 & 7) != 0) {
        finalCount = tailIndex + 3;
        record[tailPlus2] = 0x80000000u;
    }

    IOReturn submitResult = accelerator->submit_buffer(record, U32At(accel, 0x228) + 0x120, finalCount);
    U32At(accel, 0x234) = static_cast<UInt32>(submitResult);

    accelerator->waitForTimeStamp(U32At(accel, 0x234));
    return 1;
}

UInt32 ATIR500Surface::complete_vram(ATIR500SurfaceBuffer *buffer) {
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    if (U8At(buf, 0x3c) == 0) {
        return 0; /* real: already unprepared */
    }
    UInt8 refCount = U8At(buf, 0x3c) - 1;
    U8At(buf, 0x3c) = refCount;
    if (refCount != 0) {
        return 1; /* real: still other real users */
    }

    UInt32 id = U8At(buf, 0x37);
    U8At(buf, 0x37) = 0xff;
    U32At(accel, 0x890) &= ~(1u << (id & 0x1f));

    if (U8At(accel, 0x80) == 0) { /* real: *(char*)((int*)accel + 0x20), int*-scaled - NOT accel+0x20 */
        return 1; /* real: no extended command-ring burst needed */
    }

    UInt8 *ring = reinterpret_cast<UInt8 *>(U32At(accel, 0x238)); /* real: piVar5[0x8e], word-indexed */
    UInt32 idByteOffset = id * 4;
    UInt32 *record = reinterpret_cast<UInt32 *>(ring + 0x120);

    accelerator->waitForTimeStamp(U32At(accel, 0x234));
    *record = idByteOffset + 0x2c1;
    *reinterpret_cast<UInt32 *>(ring + 0x124) = 0;
    *reinterpret_cast<UInt32 *>(ring + 0x128) = idByteOffset + 0x2c2;
    *reinterpret_cast<UInt32 *>(ring + 300) = 0;
    *reinterpret_cast<UInt32 *>(ring + 0x130) = idByteOffset + 0x2c3;
    *reinterpret_cast<UInt32 *>(ring + 0x134) = 0;

    IOReturn submitResult = accelerator->submit_buffer(record, U32At(accel, 0x228) + 0x120, 6);
    U32At(accel, 0x234) = static_cast<UInt32>(submitResult);

    return 1;
}
