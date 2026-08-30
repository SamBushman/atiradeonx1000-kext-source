/*
 * ATIR500GLContext_Surfaces.cpp
 *
 * build_surface_from_texture / process_kATIGLStreamFastClearColor -
 * CONFIRMED, fully transcribed from real decompiles (kext offsets
 * 0x28200/0x292a0). The real backing for opcodes 0x45 and 0x46
 * respectively.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000Registers.h"

namespace {
inline UInt32 &U32At(void *base, int offset) {
    return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset);
}
} // namespace

/*
 * build_surface_from_texture - CONFIRMED, fully transcribed (real kext
 * offset 0x28200, opcode 0x45's real backing function). Populates a
 * caller-owned ATIR500SurfaceBuffer record in place from a
 * VendorTextureBuffer: zeroes/defaults every field, resolves the real
 * GPU base address (via GetTextureOffset for chained/type-6 textures, or
 * directly for plain ones), copies real format/tiling bytes across, and
 * runs the same real format-table-driven tile-alignment check already
 * seen in write_kernel_context_buffer_regs/build_scissor (the
 * DAT_0004d2dc table).
 */
void ATIR500GLContext::build_surface_from_texture(VendorTextureBuffer *texture,
                                                    ATIR500SurfaceBuffer *surfaceBuffer,
                                                    UInt16 param3, UInt16 param4, UInt8 param5,
                                                    UInt32 param6, UInt16 param7) {
    UInt8 *sb = reinterpret_cast<UInt8 *>(surfaceBuffer);

    /* real field-by-field zero/default init */
    sb[0x3c] = 0;
    sb[0x37] = 0xff;
    sb[0x3b] = 6;
    U32At(sb, 0x44) = 0;
    U32At(sb, 0x00) = 0;
    U32At(sb, 0x04) = 0;
    U32At(sb, 0x08) = 0;
    U32At(sb, 0x0c) = 0;
    U32At(sb, 0x10) = 0;
    *reinterpret_cast<UInt16 *>(sb + 0x14) = 0;
    *reinterpret_cast<UInt16 *>(sb + 0x16) = 0;
    U32At(sb, 0x24) = 0;
    U32At(sb, 0x28) = 0xffffffff;
    U32At(sb, 0x2c) = 0;
    U32At(sb, 0x30) = 0;
    *reinterpret_cast<UInt16 *>(sb + 0x1c) = param3;
    *reinterpret_cast<UInt16 *>(sb + 0x1e) = param4;
    *reinterpret_cast<UInt16 *>(sb + 0x18) = 0;
    sb[0x34] = 0; sb[0x35] = 0; sb[0x36] = 0; sb[0x38] = 0; sb[0x39] = 0;
    *reinterpret_cast<UInt16 *>(sb + 0x22) = 1;
    *reinterpret_cast<UInt16 *>(sb + 0x20) = 1;
    U32At(sb, 0x40) = 0;
    U32At(sb, 0x3c) = (U32At(sb, 0x3c) & 0xff0007ffu) | 0x111000u;

    /* real GPU base-address resolution */
    if (U32At(texture, 0x20) == 6) {
        UInt32 base = GetTextureOffset(texture, true);
        U32At(sb, 8) = base + param6;
    } else {
        U32At(sb, 8) = param6 + U32At(texture, 0x48);
    }

    /* real format/dimension copy-through */
    UInt32 f0x4c = U32At(texture, 0x4c);
    UInt32 f0x40 = U32At(texture, 0x40);
    UInt32 f0x44 = U32At(texture, 0x44);
    *reinterpret_cast<UInt16 *>(sb + 0x18) = param7;
    sb[0x3a] = param5;
    U32At(sb, 0x0c) = f0x4c;
    U32At(sb, 0x00) = f0x40;
    U32At(sb, 0x04) = f0x44;

    /* real format-table lookup + tile-alignment check (DAT_0004d2dc,
     * indexed the same way as write_kernel_context_buffer_regs/
     * build_scissor) */
    UInt32 tableOffset = static_cast<UInt32>(param5) * 0x1c;
    UInt8 texRec = *reinterpret_cast<UInt8 *>(U32At(texture, 0x14) + 0x15);
    UInt8 shiftBits = texRec >> 2;
    UInt8 formatClass = shiftBits & 7;
    sb[0x38] = formatClass;

    UInt32 formatEntry = FormatTableLookup_0x0004d2dc(tableOffset);
    UInt32 blockShift, blockSize;
    if (formatClass < 2) {
        blockShift = formatEntry;
        blockSize = 1;
    } else {
        blockShift = formatEntry;
        blockSize = 1u << ((formatEntry >> 8) & 3);
    }

    UInt16 dimW = *reinterpret_cast<UInt16 *>(sb + 0x18);
    UInt16 dimH = *reinterpret_cast<UInt16 *>(sb + 0x1e);
    if (dimW < static_cast<UInt16>((0x20 >> ((blockShift >> 8) & 3)) << 3) ||
        dimH < static_cast<UInt16>(blockSize << 3)) {
        sb[0x38] = shiftBits & 6;
        formatEntry = FormatTableLookup_0x0004d2dc(tableOffset);
    }

    UInt32 alignMask = 1u << ((formatEntry >> 0xc) & 7);
    *reinterpret_cast<UInt16 *>(sb + 0x16) = static_cast<UInt16>(alignMask);
    if ((alignMask & 0xffff) == 0) {
        *reinterpret_cast<UInt16 *>(sb + 0x14) = static_cast<UInt16>(alignMask);
    } else {
        *reinterpret_cast<UInt16 *>(sb + 0x14) =
            static_cast<UInt16>(*reinterpret_cast<UInt16 *>(sb + 0x18) / static_cast<UInt16>(alignMask));
    }

    U32At(sb, 0x28) = U32At(texture, 0x6c);
    sb[0x34] = static_cast<UInt8>(*reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(texture) + 0x7a));
    sb[0x35] = static_cast<UInt8>(*reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(texture) + 0x7a) >> 8);
}

/*
 * process_kATIGLStreamFastClearColor - CONFIRMED, fully transcribed (real
 * kext offset 0x292a0, opcode 0x46 "fast clear"). Computes real per-mip
 * render-target offset/tiling values for TWO surfaces simultaneously (the
 * bound color surface at `this+0xac`'s unit index, and a second surface
 * at `this+0xae`'s unit index - plausibly a paired depth/stencil or MRT
 * target) and writes a real Type-0-header-shaped burst starting at a
 * caller-supplied dword offset (`record[1]`, confirmed to be read BEFORE
 * being overwritten - the real function uses it purely as an output
 * index, not as data).
 */
void ATIR500GLContext::process_kATIGLStreamFastClearColor(UInt32 *record) {
    UInt32 outIndex = record[1];
    UInt8 *surfaceBase = static_cast<UInt8 *>(boundSurface); /* this+0x290 */
    UInt32 unit = mipLevel; /* this+0x29c */
    SInt32 mipIdx = *reinterpret_cast<SInt32 *>(reinterpret_cast<UInt8 *>(this) + 0x298);

    UInt8 *mip = reinterpret_cast<UInt8 *>(U32At(surfaceBase,
        (*reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(this) + 0xac)) * 4 + 0xb70));
    UInt8 *pairUnitRecordBase = surfaceBase + (*reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(this) + 0xae)) * 0x78;
    UInt8 *pairMip = reinterpret_cast<UInt8 *>(U32At(surfaceBase,
        (*reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(this) + 0xae)) * 4 + 0xb70));

    UInt16 pitchWords = *reinterpret_cast<UInt16 *>(mip + 0x20);
    UInt32 offsetCur  = U32At(mip, unit * 4 + 0x40);
    UInt32 offsetNext = U32At(mip, unit * 4 + 0x44);
    UInt32 gpuBase    = U32At(mip, 8);

    UInt32 tileDim = 0x10;
    SInt32 hExtra = static_cast<SInt32>(static_cast<UInt32>(*reinterpret_cast<UInt16 *>(mip + 0x1e)) >> (unit & 0x3f));
    if (hExtra != 0) tileDim = hExtra + 0xf;

    UInt32 hz = 0;
    UInt32 formatIdx = (*reinterpret_cast<UInt8 *>(mip + 0x3a)) * 0x1cu;
    if ((U32At(mip, 0x3c) & 0xf00000) != 0) {
        hz = static_cast<UInt32>(*reinterpret_cast<UInt16 *>(mip + 0x14)) /
             ((U32At(mip, 0x3c) >> 0x14) & 0xf) >> (unit & 0x3f);
    }
    UInt32 tileWidth = 0x20 / *reinterpret_cast<UInt16 *>(mip + 0x16);
    if (tileWidth <= hz) tileWidth = hz;

    UInt8 tilingByte0 = *reinterpret_cast<UInt8 *>(mip + 0x38);
    UInt32 fmtA = FormatTableLookup_0x0004d2dc(formatIdx);
    UInt32 fmtB = FormatTableLookup_0x0004d2e0(formatIdx);

    record[0] = 0x13c8;
    UInt32 fmtAPacked = (fmtA & 0xc00) << 9;
    UInt32 fmtBPacked = (fmtB >> 1) & 0x1e00000;
    UInt32 halfTile = (tileWidth & 0x3ffe) >> 1;
    UInt32 tilingWord = fmtBPacked | fmtAPacked | (tileWidth & 0x3ffe);

    record[1] = offsetCur * pitchWords + (offsetNext - offsetCur) * static_cast<UInt32>(mipIdx) +
                gpuBase + (tileDim & 0xfffffff0u) * halfTile * 4;
    record[7] = tilingWord;
    record[3] = tilingWord;
    record[5] = (((tileDim & 0xfffffff0u) >> 1) - 1) * 0x2000 & 0x3ffe000;
    record[5] |= (halfTile * 2 - 1) & 0x1fff;
    record[outIndex] = U32At(pairUnitRecordBase, 0xb0);

    UInt32 hz2 = 0;
    if ((U32At(pairMip, 0x3c) & 0xf00000) != 0) {
        hz2 = static_cast<UInt32>(*reinterpret_cast<UInt16 *>(pairMip + 0x14)) /
              ((U32At(pairMip, 0x3c) >> 0x14) & 0xf);
    }
    UInt32 tileWidth2 = 0x20 / *reinterpret_cast<UInt16 *>(pairMip + 0x16);
    if (tileWidth2 <= hz2) tileWidth2 = hz2;

    record[outIndex + 2] =
        ((*reinterpret_cast<UInt8 *>(pairMip + 0x38) & 6) << 0x10) |
        ((*reinterpret_cast<UInt8 *>(pairMip + 0x38) & 1) << 0x10) |
        ((*reinterpret_cast<UInt8 *>(pairMip + 0x39) & 3) << 0x13) |
        (tileWidth2 & 0x3ffc);
    record[outIndex + 4] = fmtBPacked | fmtAPacked | ((tilingByte0 & 6) << 0x10) |
                            ((tilingByte0 & 1) << 0x10) | (tileWidth & 0x3ffe);
    record[outIndex + 6] = static_cast<UInt32>(-static_cast<SInt32>(
        *reinterpret_cast<UInt8 *>(pairUnitRecordBase + 0xe2) ^ 0x10)) >> 0x1e & 2;
}
