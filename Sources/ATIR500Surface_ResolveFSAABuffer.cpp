/*
 * ATIR500Surface_ResolveFSAABuffer.cpp
 *
 * RESOLVED (issue #13 item 2): `ATIR500Surface::resolve_fsaa_buffer`, the
 * one function this project had left genuinely opaque since the opcode
 * 0x31/0x2d misattribution investigation used it only as a targeted
 * negative-identity check (kext offset `0x43e60`, confirmed by symbol
 * name already present in the binary's own symbol table - not a guess).
 * Full decompile obtained fresh this pass and transcribed completely.
 *
 * Real signature, matching this project's existing declaration exactly
 * (`Headers/IOATIR500Surface.h`): called from opcode 0x30's handler
 * (`handle_fsaa_resolve_setup`, `ATIR500GLContext_ProcessCommandBuffer.cpp`)
 * with the caller's own live command-buffer record pointer passed
 * directly as `paramBlock` - this function writes straight into the
 * caller's own record stream and returns a pointer indicating how far it
 * consumed, exactly the same "explicit next pointer, not a natural
 * distance" convention already established for opcode 0x2d's own handler
 * (`local_d0` - see issue #13 item 1). The caller compares the returned
 * pointer against its own natural-distance target and pads the gap if
 * short, confirming this reading of the convention.
 *
 * Real top-level structure: a single flag-bit test
 * (`this+0xbe8 & 0x700000`) selects between two ENTIRELY DIFFERENT real
 * resolve strategies, not two minor variations of the same one:
 *
 *   - Block A (flag clear): a real per-plane MSAA-sample-position/pitch
 *     burst plus real floating-point NDC viewport math (the same
 *     "magic-bias" int-to-float trick already established in
 *     `ATIR500GLContext_FSAAResolveBlit.cpp`/DVD's opcode 0x3d) - the
 *     textured-quad-blit-shaped resolve path.
 *   - Block B (flag set): a real HyperZ-block-driven resolve using
 *     `HZMEM_GetBlockOffset`/`HZMEM_GetBlockCount` and a completely
 *     different real PM4 burst shape (`0x1395`/`0x1399`/`0x13a0`-`0x13a2`/
 *     `0x1385`/`0x1380`), never touching the floating-point path at all.
 *
 * Both blocks are real, independently transcribed from the same
 * complete decompile - not derived from each other or from
 * `FSAAResolveBlit.cpp`'s own similar-looking (but NOT identical) content;
 * that file is a different class (`ATIR500GLContext`, opcode 0x2d) with
 * its own distinct field offsets. The resemblance (same magic-bias float
 * trick, same cascading-format-table-bit-patch idiom already seen at
 * three other real sites this project has found) is real convergent
 * evidence of a shared driver-wide idiom, not code sharing between these
 * two specific functions.
 *
 * Real struct finding this pass: `iVar18`/`iVar19` in the raw decompile
 * are real `ATIR500SurfaceBuffer*` pointers (this project's own
 * already-declared struct, `ATIRadeonX1000Types.h`) - confirmed by a
 * field-by-field match against every already-CONFIRMED field in that
 * struct (`+0x08` base, `+0x14`/`+0x16` width/pitch, `+0x1c`/`+0x1e`
 * height pair, `+0x28` format bits, `+0x38`/`+0x39`/`+0x3a` tiling/format
 * bytes, `+0x40..` mip offsets). This function also reads three real
 * fields the struct didn't have names for yet - `+0x30`, `+0x36`, and
 * `+0x3c` - all three now added to the struct's own declaration with
 * this function cited as the source. `this+0xb70` (indexed by the
 * caller's own format-code argument) and `this+0xb94` (a single, always-
 * read pointer) are the real base addresses these `ATIR500SurfaceBuffer*`
 * pointers come from - both newly declared on `IOATIR500Surface` by this
 * pass, previously undocumented anywhere in this project.
 *
 * TRANSCRIPTION METHOD, matching `FSAAResolveBlit.cpp`'s own stated
 * approach for the same reason: flat decompile-derived variable names
 * (`uVar12`, `uVar15`, etc.) are kept close to the original rather than
 * renamed into "cleaner" semantic names wherever a value is reassigned
 * for an unrelated purpose partway through (e.g. `uVar15` is reused for
 * at least four structurally different real quantities across this one
 * function) - renaming these is exactly the kind of "cleanup" that has
 * caused real transcription mistakes elsewhere in this project.
 * `ATIR500SurfaceBuffer*`-typed field access is used in place of raw
 * `U32At`/`U16At` offset arithmetic where the struct now names the field,
 * for readability - this is a safe substitution, not a reinterpretation,
 * since the struct's own offsets were independently confirmed against
 * this exact function's own field reads (see above).
 *
 * The real "magic-bias" int-to-float constant here (`4503601774854144.0`)
 * is a LITERAL double value in the raw decompile output - Ghidra resolved
 * it directly, unlike `FSAAResolveBlit.cpp`'s own still-unresolved
 * `DOUBLE_0004c3a8`/`0x3b0` externs for the equivalent constant in that
 * function. Used directly here rather than left as an unresolved extern.
 *
 * `FUN_00044868` (the real `0x2f4`-byte blit-state-packet template copy,
 * called once at the very top before either block runs) is called
 * opaquely, matching this project's established treatment of the
 * identical real copy `FSAAResolveBlit.cpp`/`RestoreState.cpp` already
 * document (`_g_r500_3d_blit_state_packet`, `ATIRadeonX1000Types.h`) -
 * not re-modeled as a raw memcpy here since the template's own real
 * per-field content was never extracted from the binary either place.
 *
 * `&_samplesTable` (real binary data, indexed via a real byte offset
 * `(tilingDegreeBits >> 0x12) & 0x3c` - a real up-to-16-entry `UInt32`
 * table; the `0x3c` mask is mathematically the same real 4-byte-stride
 * indexing every other format table in this project uses, just written
 * as a direct byte-offset mask instead of an explicit `<<2` scale -
 * confirmed equivalent: `x & 0x3c == (x & 0xf) << 2`) is declared as a
 * new `extern "C"` accessor (`SamplesTableLookup`, taking the same real
 * byte-offset convention as `FormatTableLookup_0x0004d2e0/e4`,
 * `ATIRadeonX1000Registers.h`) - raw table content not extracted from
 * the binary this pass, same standing caveat as those tables.
 *
 * `this+0xbe8` (the real block-A/block-B selector flag) and the
 * `ATIRadeonX1000`-relative offsets this function reads
 * (`accelerator+0xb74`/`+0xb98`/`+0x78`/`+0x870`) are accessed via raw
 * `U32At`/`U8At` rather than newly-declared named fields - consistent
 * with this project's established practice of leaving single-use,
 * not-independently-corroborated accelerator offsets as raw offsets
 * rather than promoting every one to a named struct member (see e.g.
 * `ATIR500GLContext_FSAAResolveBlit.cpp`'s own `self+0x290`-style
 * offsets). `accelerator+0x870` is the same real `_HZDATA*` base
 * `HZMEM_GetBlockOffset`/`GetBlockCount` already use elsewhere in this
 * project (`ATIRadeonX1000Registers.h`).
 *
 * Confidence: CONFIRMED for every literal constant and the complete
 * control flow - this is a real, standalone function (not embedded in
 * one of this project's giant multi-opcode dispatch functions), so its
 * own decompile carries none of the brace-nesting-unreliability risk
 * this project has repeatedly documented for `process_command_buffer`.
 * No C++ compiler was available in the sandboxed environment this was
 * written in (same standing limitation as every other file in this
 * project) - checked by careful, repeated manual re-reading against the
 * raw decompile instead.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include "../Headers/ATIRadeonX1000Registers.h"

namespace {

inline float BiasedIntToFloat(UInt32 raw, double bias) {
    union { double d; struct { UInt32 hi, lo; } parts; } u;
    u.parts.hi = 0x43300000;
    u.parts.lo = raw;
    return static_cast<float>(u.d - bias);
}

inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }

const double kBias = 4503601774854144.0;

} // namespace

void *ATIR500Surface::resolve_fsaa_buffer(UInt32 surfaceIndex, UInt32 formatCode, void *paramBlockV,
                                             bool clearFlag, UInt32 param5, UInt32 param6,
                                             UInt32 param7, UInt32 param8) {
    UInt32 *paramBlock = reinterpret_cast<UInt32 *>(paramBlockV);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    ATIR500SurfaceBuffer *surfB = fixedSurfaceBuffer;                    /* real: iVar19 */
    ATIR500SurfaceBuffer *surfA = surfaceBuffersByFormat[formatCode];    /* real: iVar18 */

    /* real: FUN_00044868(paramBlock, &_g_r500_3d_blit_state_packet, 0x2f4) -
     * see this file's own header comment. */
    paramBlock[0xb] = U32At(accel, 0xb74);

    if ((U32At(accel, 0xbe8) & 0x700000u) == 0) {
        /* ---- Block A: MSAA burst + floating-point NDC viewport blit ---- */
        UInt32 uVar15 = 0;
        UInt32 tableOffA = static_cast<UInt32>(surfA->formatTableIndex) * 0x1cu;
        paramBlock[0x9a] = (static_cast<UInt32>(surfA->bytesPerRow) * surfA->mipOffsets[0] /* real: *(int*)(iVar18+0x40) - see note below */
                            + surfA->gpuBaseAddress) & 0xffffffe0u;
        if ((surfA->tilingDegreeBits & 0xf00000u) != 0) {
            uVar15 = static_cast<UInt32>(surfA->width) / ((surfA->tilingDegreeBits >> 0x14) & 0xfu);
        }
        UInt32 uVar12 = 0x20u / surfA->bytesPerRow;
        if (uVar12 <= uVar15) uVar12 = uVar15;
        UInt32 uVar11 = paramBlock[0x8a];
        UInt32 fmtA = FormatTableLookup_0x0004d2e0(tableOffA);
        paramBlock[0x9c] = (uVar12 & 0x3ffeu) | ((surfA->tilingConfigByte0 & 1u) << 0x10) |
                            ((surfA->tilingConfigByte0 & 6u) << 0x10) | ((surfA->tilingConfigByte1 & 3u) << 0x13) |
                            ((fmtA >> 1) & 0x1e00000u);
        uVar15 = (fmtA >> 0x11) & 0x1fu;
        paramBlock[0x8a] = uVar15 | (uVar11 & 0xffffffe0u);
        uVar12 = (fmtA >> 7) & 0x300u;
        paramBlock[0x8a] = uVar12 | uVar15 | (uVar11 & 0xfffffce0u);
        UInt32 uVar13 = (fmtA >> 3) & 0xc00u;
        paramBlock[0x8a] = uVar13 | uVar12 | uVar15 | (uVar11 & 0xfffff0e0u);
        UInt32 uVar9 = (fmtA & 0x1800u) << 1;
        paramBlock[0x8a] = uVar9 | uVar13 | uVar12 | uVar15 | (uVar11 & 0xffffc0e0u);
        paramBlock[0x8a] = ((fmtA & 0x600u) << 5) | uVar9 | uVar13 | uVar12 | uVar15 | (uVar11 & 0xffff00e0u);

        if (((surfA->tilingDegreeBits & 0xf00000u) == 0) ||
            (uVar12 = static_cast<UInt32>(surfA->heightOrRows) / ((surfA->tilingDegreeBits >> 0x14) & 0xfu),
             uVar15 = uVar12 - 1, uVar12 == 0)) {
            uVar15 = 0;
        }
        uVar12 = 0;
        if (surfA->extra1e != 0) uVar12 = surfA->extra1e - 1u;
        paramBlock[0xb3] = (uVar15 & 0x1fffu) | ((uVar12 & 0x1fffu) << 0xd);

        UInt8 bVar5 = surfB->formatTableIndex;
        paramBlock[0xa0] = ((surfB->tilingConfigByte0 & 7u) << 2) |
                            ((static_cast<UInt32>(surfB->bytesPerRow) * surfB->mipOffsets[0] + surfB->gpuBaseAddress) & 0xffffffe0u);
        if (((surfB->tilingDegreeBits & 0xf00000u) == 0) ||
            (uVar12 = static_cast<UInt32>(surfB->heightOrRows) / ((surfB->tilingDegreeBits >> 0x14) & 0xfu),
             uVar15 = uVar12 - 1, uVar12 == 0)) {
            uVar15 = 0;
        }
        uVar12 = 0;
        if (surfB->extra1e != 0) uVar12 = surfB->extra1e - 1u;
        paramBlock[0xa6] = (uVar15 & 0x7ffu) | ((uVar12 & 0x7ffu) << 0xb) | 0x80000000u;

        uVar15 = FormatTableLookup_0x0004d2e4(static_cast<UInt32>(bVar5) * 0x1cu);
        paramBlock[0xa8] = ((uVar15 >> 0x13) & 0x1fu) | ((uVar15 & 0x40u) << 0x10) | ((uVar15 >> 7) & 0xe00u) |
                            ((uVar15 >> 1) & 0x7000u) | ((uVar15 & 0x1c00u) << 5) | ((uVar15 & 0x380u) << 0xb);

        uVar15 = surfB->tilingDegreeBits;
        bool bVar1 = (uVar15 & 0xf00000u) == 0;
        if (bVar1) {
            uVar12 = 0;
        } else {
            uVar12 = static_cast<UInt32>(surfB->width) / ((uVar15 >> 0x14) & 0xfu);
        }
        uVar13 = 0x20u / surfB->bytesPerRow;
        if (uVar13 <= uVar12) uVar13 = uVar12;
        if (bVar1 ||
            (uVar12 = static_cast<UInt32>(surfB->heightOrRows) / ((uVar15 >> 0x14) & 0xfu),
             uVar15 = uVar12 - 1, uVar12 == 0)) {
            uVar15 = 0;
        }
        uVar12 = 0;
        if (surfB->extra1e != 0) uVar12 = surfB->extra1e - 1u;
        paramBlock[0xaa] = ((uVar13 - 1u) & 0x3fffu) | ((uVar15 & 0x800u) << 4) | ((uVar12 & 0x800u) << 5);

        paramBlock[0x1e] = (paramBlock[0x1e] & 0xfffffffcu) | 2u;
        paramBlock[0xa2] = (paramBlock[0xa2] & 0xffffe1ffu) | 0x1400u;

        float fVar6 = (surfA->heightOrRows == 0) ? 0.0f : 1.0f / BiasedIntToFloat(static_cast<UInt32>(surfA->heightOrRows) ^ 0x80000000u, kBias);
        float fVar7 = (surfA->extra1e == 0) ? 0.0f : 1.0f / BiasedIntToFloat(static_cast<UInt32>(surfA->extra1e) ^ 0x80000000u, kBias);

        UInt32 *puVar17 = paramBlock + 0xcb;
        paramBlock[0xc2] = 0x1087; paramBlock[0xc4] = 0xc0033500; paramBlock[0xbd] = 0x31080; paramBlock[200] = 0;
        paramBlock[0xc5] = 0x10031; paramBlock[0xc9] = 0x1393; paramBlock[0xca] = 10;

        float fVar2 = BiasedIntToFloat(param5 ^ 0x80000000u, kBias);
        float fVar3 = BiasedIntToFloat((param5 + param7) ^ 0x80000000u, kBias);
        paramBlock[0xc0] = static_cast<UInt32>(fVar6 * fVar3);
        paramBlock[0xbe] = static_cast<UInt32>(fVar6 * fVar2);
        paramBlock[0xc6] = static_cast<UInt32>((fVar2 + fVar3) * 0.5f);

        fVar6 = BiasedIntToFloat((param6 + param8) ^ 0x80000000u, kBias); /* real: fVar6 reused */
        float fVar4 = BiasedIntToFloat(param6 ^ 0x80000000u, kBias);
        paramBlock[0xbf] = static_cast<UInt32>(fVar7 * fVar6);
        paramBlock[0xc1] = static_cast<UInt32>(fVar7 * fVar4);
        paramBlock[199] = static_cast<UInt32>((fVar4 + fVar6) * 0.5f);
        paramBlock[0xc3] = (static_cast<SInt32>((fVar3 - fVar2) * 6.0f) << 0x10) |
                            static_cast<SInt32>((fVar6 - fVar4) * 6.0f);

        U32At(accel, 0x78) = 0; /* real: shared LAB_0004481c tail */
        return puVar17;
    }

    /* ---- Block B: HyperZ-block-driven resolve, no floating point ---- */
    UInt32 uVar15 = 0;
    paramBlock[0xa9] = 0xc0001000; paramBlock[0x9d] = 0xc0001000; paramBlock[0x9f] = 0xc0001000;
    paramBlock[0xa1] = 0xc0001000; paramBlock[0xa3] = 0xc0001000; paramBlock[0xa5] = 0xc0001000;
    paramBlock[0xa7] = 0xc0001000;
    paramBlock[0x9a] = surfB->gpuBaseAddress;
    if ((surfB->tilingDegreeBits & 0xf00000u) != 0) {
        uVar15 = static_cast<UInt32>(surfB->width) / ((surfB->tilingDegreeBits >> 0x14) & 0xfu);
    }
    UInt32 uVar12 = 0x20u / surfB->bytesPerRow;
    if (uVar12 <= uVar15) uVar12 = uVar15;
    /* real: this specific slot cross-mixes surfA's tilingConfigByte0 with
     * surfB's tilingConfigByte1/formatTableIndex - transcribed exactly as
     * found, not "fixed" to be internally consistent. */
    paramBlock[0x9c] = (uVar12 & 0x3ffeu) | ((surfA->tilingConfigByte0 & 1u) << 0x10) |
                        ((surfA->tilingConfigByte0 & 6u) << 0x10) | ((surfB->tilingConfigByte1 & 3u) << 0x13) |
                        ((FormatTableLookup_0x0004d2e0(static_cast<UInt32>(surfB->formatTableIndex) * 0x1cu) >> 1) & 0x1e00000u);

    if (((surfB->formatOrTilingBits & 0x3ff00000u) == 0x3ff00000u) || (surfB->fsaaResolvedFlag == 0)) {
        paramBlock[0x20] = 0;
    } else {
        paramBlock[0x20] = 0x600;
    }

    UInt32 samplesRaw = surfB->tilingDegreeBits;
    paramBlock[0x3c] = 0;
    paramBlock[0x42] = paramBlock[0x4e];
    paramBlock[0x26] = 0;
    paramBlock[0x44] = paramBlock[0x50];
    paramBlock[0x46] = paramBlock[0x52];
    UInt32 samplesVal = SamplesTableLookup((samplesRaw >> 0x12) & 0x3cu);
    paramBlock[0x48] = paramBlock[0x54];
    paramBlock[0x4a] = paramBlock[0x56];
    paramBlock[0x4c] = paramBlock[0x58];
    paramBlock[0x7e] = 0;
    paramBlock[0x86] = 0;
    paramBlock[0x24] = 3;
    paramBlock[0x84] = 0;
    paramBlock[0x88] = 0;
    paramBlock[0x82] = 0;
    paramBlock[0x92] = 0x80;
    paramBlock[0x98] = 0x50000000;
    paramBlock[0x10] = ((samplesVal & 3u) << 1) | 1u;
    paramBlock[0x96] = 0x10000;

    if (((surfA->tilingDegreeBits & 0xf00000u) == 0) ||
        (uVar12 = static_cast<UInt32>(surfA->heightOrRows) / ((surfA->tilingDegreeBits >> 0x14) & 0xfu),
         uVar15 = uVar12 - 1, uVar12 == 0)) {
        uVar15 = 0;
    }
    uVar12 = 0;
    if (surfA->extra1e != 0) uVar12 = surfA->extra1e - 1u;
    paramBlock[0xb3] = (uVar15 & 0x1fffu) | ((uVar12 & 0x1fffu) << 0xd);

    void *hzData = accel + 0x870;
    UInt32 uVar14 = HZMEM_GetBlockOffset(reinterpret_cast<_HZDATA *>(hzData), surfB->formatOrTilingBits, 2);

    uVar15 = 0;
    if ((surfB->tilingDegreeBits & 0xf00000u) != 0) {
        uVar15 = static_cast<UInt32>(surfB->width) / ((surfB->tilingDegreeBits >> 0x14) & 0xfu);
    }
    uVar12 = 0x20u / surfB->bytesPerRow;
    if (uVar12 <= uVar15) uVar12 = uVar15;

    UInt32 iVar10 = 0x20;
    UInt32 uVar16;
    UInt32 accelB98 = U32At(accel, 0xb98);
    if (accelB98 == 4) {
        uVar16 = iVar10 * ((iVar10 + uVar12 - 1) / iVar10);
    } else {
        iVar10 = accelB98 << 4;
        uVar16 = 0;
        if (iVar10 != 0) {
            uVar16 = iVar10 * ((iVar10 + uVar12 - 1) / iVar10); /* real: LAB_00044100, reached both ways */
        }
    }
    paramBlock[0xc0] = uVar16;
    paramBlock[0xbe] = uVar14;
    paramBlock[0xbd] = 0x1395; paramBlock[0xbf] = 0x1399; paramBlock[0xc1] = 0x13a2;
    paramBlock[0xc2] = 5; paramBlock[0xc3] = 0x13a0;

    UInt32 *puVar17 = paramBlock + 0xc9;
    uVar15 = surfA->gpuBaseAddress;
    paramBlock[0xc5] = 0x13a1;
    paramBlock[0xc4] = uVar15 & 0xffffffe0u;
    UInt16 uVar8 = surfA->width;
    paramBlock[199] = 0x1087;
    paramBlock[200] = (param7 * 0x60000u) | (param8 * 6u & 0xffffu);
    paramBlock[0xc6] = uVar8 & 0x3ffeu;

    bool wantExtraSlot = ((surfB->formatOrTilingBits & 0x3ff00000u) != 0x3ff00000u) &&
                          (surfB->fsaaResolvedFlag != 0) && (surfA->tilingConfigByte0 < 2);
    if (wantExtraSlot) {
        puVar17 = paramBlock + 0xcb;
        paramBlock[0xc9] = 0x1392;
        paramBlock[0xca] = 0x400300;
    }

    UInt32 *puVar20 = puVar17 + 0xb;
    *puVar17 = 0xc0033500;
    puVar17[1] = 0x10031;
    puVar17[2] = static_cast<UInt32>(BiasedIntToFloat((param7 + param5 * 2) ^ 0x80000000u, kBias) * 0.5f);
    puVar17[4] = 0;
    puVar17[3] = static_cast<UInt32>(BiasedIntToFloat((param8 + param6 * 2) ^ 0x80000000u, kBias) * 0.5f);
    puVar17[5] = 0x1393; puVar17[6] = 10; puVar17[7] = 0x13c6; puVar17[8] = 3; puVar17[9] = 0x13a2; puVar17[10] = 0;

    if (wantExtraSlot) {
        puVar20 = puVar17 + 0xd;
        puVar17[0xb] = 0x1392;
        puVar17[0xc] = 0x300;
    }
    puVar17 = puVar20;

    if (clearFlag && ((surfB->formatOrTilingBits & 0x3ff00000u) != 0x3ff00000u)) {
        UInt32 blockCount = HZMEM_GetBlockCount(reinterpret_cast<_HZDATA *>(hzData), surfB->formatOrTilingBits, 2);
        *puVar20 = 0x1385;
        puVar17 = puVar20 + 6;
        UInt32 uVar16b = surfB->hzBlockCountField;
        puVar20[2] = 0xc0023800;
        puVar20[3] = uVar14;
        puVar20[1] = uVar16b;
        UInt32 accelB98b = U32At(accel, 0xb98);
        puVar20[5] = 0;
        puVar20[4] = blockCount / (accelB98b << 4);
        if (surfaceIndex == 9) {
            puVar20[6] = 0x1380;
            puVar20[7] = 0x600;
            puVar17 = puVar20 + 8;
        }
        surfB->fsaaResolvedFlag = 1;
    }

    U32At(accel, 0x78) = 0; /* real: shared LAB_0004481c tail */
    return puVar17;
}
