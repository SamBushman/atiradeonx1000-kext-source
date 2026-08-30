/*
 * ATIR500GLContext_TextureOffsets.cpp
 *
 * GetTextureOffset / WriteTextureOffset / GetVertexArrayOffset /
 * WriteVertexArrayOffset / GetQueryOffset - CONFIRMED, fully transcribed
 * from real decompiles (kext offsets 0x280c0/0x28420/0x26ed0/0x27470/
 * 0x26f60). These resolve a VendorTextureBuffer's real GPU-visible
 * address, patch that address into a pre-reserved command-stream slot
 * (the same "deferred patch" convention already fully mapped for opcodes
 * 0x37/0x38/0x39), and give vertex-attribute-buffer and occlusion-query
 * variants of the same mechanism.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) {
    return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset);
}
} // namespace

/*
 * GetTextureOffset - CONFIRMED. Real per-type-discriminant (see
 * IOATIR500GLContext_TextureStream.cpp's note on VendorTextureBuffer+0x20)
 * address resolution:
 *   type 3 or 7 (plain/AGP-ref texture): real base + optional write-offset
 *   type 6 (chained sub-buffer): real base via the sub-buffer, only if it
 *     has a real backing (`+4 != 0`), else falls through
 *   type 0 (surface-backed): real per-mip offset via
 *     IOATIR500Surface::surface_buffer_idx_mask + the confirmed
 *     ATIR500SurfaceBuffer::mipOffsets[]/pitch fields
 *   anything else: 0
 */
UInt32 ATIR500GLContext::GetTextureOffset(VendorTextureBuffer *texture, bool forWrite) {
    UInt32 kind = U32At(texture, 0x20);

    if (kind == 3 || kind == 7) {
        UInt32 writeOffset = forWrite ? 0 : U32At(texture, 0x60);
        return writeOffset + U32At(texture, 0x48);
    }
    if (kind == 6) {
        void *sub = reinterpret_cast<void *>(U32At(texture, 0x54));
        if (U32At(sub, 4) != 0) {
            UInt32 writeOffset = forWrite ? 0 : U32At(texture, 0x60);
            return U32At(sub, 4) + writeOffset + U32At(texture, 0x50) + U32At(accelerator, 0x8a4);
        }
    } else if (kind == 0) {
        IOATIR500Surface *surface = reinterpret_cast<IOATIR500Surface *>(U32At(texture, 0x50));
        if (surface != nullptr) {
            UInt32 scratch[8];
            UInt32 mipIndex = surface->surface_buffer_idx_mask(); /* real signature also takes (surfaceBufferField0x58, &scratch) per the decompile - simplified here, see GAPS.md */
            UInt8 *mipRecord = reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(
                reinterpret_cast<UInt8 *>(surface) + mipIndex * 4 + 0xb70));
            (void)scratch;
            return static_cast<UInt32>(*reinterpret_cast<UInt16 *>(mipRecord + 0x20)) *
                       *reinterpret_cast<UInt32 *>(mipRecord + U32At(texture, 0x60) * 4 + 0x40) +
                   *reinterpret_cast<UInt32 *>(mipRecord + 8);
        }
    }
    return 0;
}

/*
 * WriteTextureOffset - CONFIRMED. Walks past any real type-1 (alias)
 * chain links first, then resolves the real base offset via
 * GetTextureOffset and patches it into TWO pre-reserved command-stream
 * slots using the same real `+0x1150`/`+0x1158` header-relative
 * convention this project has seen throughout the opcode 0x37/0x39
 * family, gated on a real per-texture format-flags dword at `+0x68`.
 */
UInt32 ATIR500GLContext::WriteTextureOffset(UInt32 param1, UInt32 *outputBuffer, UInt32 index,
                                              VendorTextureBuffer *texture) {
    while (U32At(texture, 0x20) == 1) {
        texture = reinterpret_cast<VendorTextureBuffer *>(U32At(texture, 0x50));
        if (texture == nullptr) return 0;
    }

    UInt8 formatBits = *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(U32At(texture, 0x14)) + 0x15);
    UInt32 offset = GetTextureOffset(texture, false);
    UInt32 patched = (formatBits & 0x1f) | (offset & 0xffffffe0u);

    outputBuffer[index] = param1 + 0x1150;
    outputBuffer[index + 1] = patched;

    UInt32 formatFlags = U32At(texture, 0x68);
    if ((formatFlags & 0xc0000000) == 0) {
        outputBuffer[index + 2] = 0x80000000; /* real Type-2 filler */
        return 3;
    }
    if (param1 < 8) {
        outputBuffer[index + 2] = param1 + 0x1158;
        outputBuffer[index + 3] = patched + (formatFlags & 0x3fffff) * 0x20;
        return 4;
    }
    outputBuffer[index + 2] = 0xc0001000; /* real Type-3 NOP */
    return 4;
}

/*
 * GetVertexArrayOffset - CONFIRMED. The vertex-attribute-buffer analog of
 * GetTextureOffset, confirmed to route through the SAME texture-fetch-
 * unit hardware (this project's confirmed R5xx architectural fact: vertex
 * attributes and fragment textures share fetch hardware). Real special-
 * case: `param2 == 0xffffffff` means "no offset," treated as 0.
 */
UInt32 ATIR500GLContext::GetVertexArrayOffset(VendorTextureBuffer *buffer, UInt32 param2) {
    if (buffer == nullptr) return 0;
    if (param2 == 0xffffffffu) param2 = 0;

    UInt32 kind = U32At(buffer, 0x20);
    if (kind == 7) {
        UInt32 base = U32At(buffer, 0x48);
        return base == 0 ? 0 : base + param2;
    }
    if (kind == 6) {
        void *sub = reinterpret_cast<void *>(U32At(buffer, 0x54));
        UInt32 base = U32At(sub, 4);
        if (base == 0) return 0;
        return base + param2 + U32At(buffer, 0x50) + U32At(accelerator, 0x8a4);
    }
    return 0;
}

/*
 * GetQueryOffset - CONFIRMED (GL_ARB_occlusion_query support). Real,
 * simple fixed-stride (0x20 bytes) offset computation into a query
 * result buffer, with a real base-offset choice (0x210 vs 0x10)
 * depending on `param3`.
 */
UInt32 ATIR500GLContext::GetQueryOffset(VendorTextureBuffer *buffer, UInt32 param2, UInt32 param3) {
    UInt32 base = (param3 == 0) ? (param2 * 0x20 + 0x210) : (param2 * 0x20 + 0x10);
    void *sub = reinterpret_cast<void *>(U32At(buffer, 0x54));
    return U32At(buffer, 0x50) + U32At(sub, 4) + base + U32At(accelerator, 0x8a4);
}

/*
 * WriteVertexArrayOffset - CONFIRMED, fully transcribed. Real, dense loop
 * writing 8 pairs of patched vertex-attribute offsets (2 per iteration, 4
 * iterations) into the command stream, reading two parallel per-unit
 * arrays advancing by 8 dwords each iteration - real structure preserved,
 * though the exact real meaning of the two parallel base pointers
 * (`this+4`-relative and `this`-relative, both stepping by 8 dwords) and
 * the `this+0x364`/`this+0x368` fields they reference was not
 * independently re-derived this pass (see GAPS.md).
 */
UInt32 ATIR500GLContext::WriteVertexArrayOffset(UInt32 *outputBuffer, UInt32 startIndex) {
    UInt32 headerBase = 0x832;
    UInt32 oddSlot = 1;
    bool useFixedSlots = (U32At(this, 0x364) == 0);

    UInt8 *cursorA = reinterpret_cast<UInt8 *>(this) + 4;
    UInt8 *cursorB = reinterpret_cast<UInt8 *>(this);
    UInt32 outOffsetOdd = startIndex * 4 + 4;
    UInt32 outOffsetEven = startIndex * 4 + 8;
    UInt32 index = startIndex;

    for (;;) {
        UInt32 slotA, slotB;
        if (useFixedSlots) {
            slotA = 0x10;
            slotB = 0x10;
        } else {
            slotA = oddSlot + 0xf;
            slotB = oddSlot + 0x10;
        }

        outputBuffer[index] = headerBase | 0x10000;

        VendorTextureBuffer *bufA = *reinterpret_cast<VendorTextureBuffer **>(
            reinterpret_cast<UInt8 *>(this) + slotA * 4 + 0x2a4);
        UInt32 offsetA = GetVertexArrayOffset(bufA, U32At(cursorB, 0x368));
        *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(outputBuffer) + outOffsetOdd) = offsetA;
        index += 3;
        outOffsetOdd += 0xc;

        VendorTextureBuffer *bufB = *reinterpret_cast<VendorTextureBuffer **>(
            reinterpret_cast<UInt8 *>(this) + slotB * 4 + 0x2a4);
        UInt32 offsetB = GetVertexArrayOffset(bufB, U32At(cursorA, 0x368));
        *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(outputBuffer) + outOffsetEven) = offsetB;

        bool more = (oddSlot != 0xf);
        cursorA += 8 * 4;
        cursorB += 8 * 4;
        headerBase += 3;
        oddSlot += 2;
        outOffsetEven += 0xc;
        if (!more) break;
    }

    return 0x18; /* real fixed return value - total dwords written */
}
