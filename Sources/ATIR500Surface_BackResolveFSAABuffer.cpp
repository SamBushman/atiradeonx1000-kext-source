/*
 * ATIR500Surface_BackResolveFSAABuffer.cpp
 *
 * RESOLVED (issue #17): `ATIR500Surface::back_resolve_fsaa_buffer`, a real
 * function found incidentally while locating `resolve_fsaa_buffer`'s own
 * address for issue #13 (kext offset `0x44880`, size 1260 bytes,
 * immediately after `resolve_fsaa_buffer`'s own body) - flagged there but
 * never itself investigated until now. Full decompile obtained fresh this
 * pass and transcribed completely.
 *
 * Real signature: `back_resolve_fsaa_buffer(this, param_1, param_2,
 * param_3)`. `param_1` is real but genuinely UNUSED - never read anywhere
 * in the function body, confirmed by a full read of the raw decompile, not
 * an oversight in this transcription. `param_2` indexes
 * `surfaceBuffersByFormat` (same real per-format-code array
 * `resolve_fsaa_buffer` uses), matching that function's own `formatCode`
 * parameter. `param_3` is the same real "caller's own live command-buffer
 * record pointer, written into directly, explicit next-pointer returned"
 * convention `resolve_fsaa_buffer` and opcode 0x2d's handler both already
 * established.
 *
 * REAL CALLER: none found. A Ghidra reference sweep for every real
 * cross-reference TO this function's address found exactly one hit, typed
 * "Entry Point (EXTERNAL)" with no containing function - i.e. this
 * function is reachable only via an external/vtable-style reference
 * Ghidra's static analysis can't resolve to a real call site, not from any
 * of this project's already-transcribed command-buffer opcode handlers.
 * Consistent with the issue's own "if any exist" hedge on this point.
 *
 * REAL STRUCTURAL RELATIONSHIP TO `resolve_fsaa_buffer` (issue #13) - NOT
 * simply that function run backwards. Real differences, all confirmed
 * directly against the raw decompile:
 *
 *   1. The two real `ATIR500SurfaceBuffer*` sources are the SAME PAIR
 *      `resolve_fsaa_buffer` uses (`fixedSurfaceBuffer`, this+0xb94; and
 *      `surfaceBuffersByFormat[formatCode]`, this+0xb70) but with their
 *      ROLES SWAPPED: here `fixedSurfaceBuffer` feeds the
 *      `[0x9a]`/`[0x9c]`/`[0x8a]`/`[0xb3]` slot group (`resolve_fsaa_buffer`
 *      Block A's `surfA`/indexed-by-format role), and
 *      `surfaceBuffersByFormat[formatCode]` feeds the
 *      `[0xa0]`/`[0xa6]`/`[0xa8]`/`[0xaa]` group (`resolve_fsaa_buffer`
 *      Block A's `surfB`/fixed role) - consistent with this being a real
 *      inverse/companion operation, exactly as the function's own real
 *      name (already present in the kext's symbol table) suggests.
 *   2. `resolve_fsaa_buffer`'s real top-level `this+0xbe8`
 *      HyperZ-vs-float-blit strategy split does NOT exist here. Both
 *      surface-descriptor slot groups are computed UNCONDITIONALLY, every
 *      call, with none of `resolve_fsaa_buffer` Block B's real HyperZ-block
 *      machinery (`HZMEM_GetBlockOffset`/`GetBlockCount`, the `0x1395`/
 *      `0x1399`/`0x13a0`-`0x13a2`/`0x1385`/`0x1380` burst shape) anywhere
 *      in this function. `this+0xbe8`'s flag survives only as a single
 *      extra register write (`paramBlock[0xf] = 0xc0001000`) gating on the
 *      SAME real bit test, nothing more.
 *   3. Only 2 real arguments feed the floating-point tail (`param_2`'s
 *      indexed surface, via `fixedSurfaceBuffer`/`surfaceBuffersByFormat`
 *      already read above) - there is no equivalent of
 *      `resolve_fsaa_buffer`'s real `param5`-`param8` viewport-rectangle
 *      arguments; the float tail here computes a single per-axis
 *      half-extent from `fixedSurfaceBuffer`'s own `heightOrRows`/`extra1e`
 *      fields alone, not a caller-supplied rectangle.
 *   4. That same float tail branches on `fixedSurfaceBuffer->tilingDegreeBits`
 *      (a real PER-SURFACE tiling check, distinct from the top-level
 *      `this+0xbe8` accelerator-mode-style flag) to pick between a plain
 *      unsigned int-to-float conversion (no `^0x80000000` sign-flip, no
 *      tiling-degree divide) and a tiling-degree-divided, sign-flipped
 *      conversion matching `resolve_fsaa_buffer`'s own idiom - two
 *      genuinely different real formulas, not a stylistic variation.
 *
 * REAL BUG FOUND AND FIXED IN `resolve_fsaa_buffer` (issue #13) BY THIS
 * INVESTIGATION - see `ATIR500Surface_ResolveFSAABuffer.cpp`'s own header
 * comment for the full account. Cross-checking this function's real
 * `+0x20` field read and real `this+0xbe8` top-level flag read against
 * that file's already-committed transcription surfaced two real
 * misattributions there (a `bytesPerRow` field aliased onto a distinct
 * real `+0x20` field now named `basePitch`, and an `accelerator+0xbe8`
 * read that should have been `this+0xbe8`) - both now corrected in that
 * file, independently re-verified against the FULL raw decompile this
 * pass turned up no further discrepancies.
 *
 * The real "plain, no sign-flip" magic-bias int-to-float conversion this
 * function uses in one branch of its float tail is the SAME real
 * `DOUBLE_0004c3b0` (2^52, `0x4330000000000000`) constant already
 * CONFIRMED and named in `ATIRadeonX1000Registers.h` (issue #14) - not a
 * new discovery, just the first CALLER this project has found for that
 * specific variant (every other real magic-bias use this project has
 * transcribed so far uses the sign-flipped `DOUBLE_0004c3a8` variant).
 *
 * `FUN_00044d74` (the real `0x2f4`-byte blit-state-packet template copy,
 * called once at the very top, same role as `resolve_fsaa_buffer`'s own
 * `FUN_00044868`) is a SEPARATE real lazy-binding stub instance - CONFIRMED
 * via direct disassembly (`bodySize=16`, `params=0`, the exact same
 * `lis/ori/mtspr/bctr` trampoline shape already documented for
 * `FUN_00044868` and the other ~23 real stubs, `ATIRadeonX1000Registers.h`,
 * issue #15) - almost certainly the same real external target
 * (`bcopy`/`memcpy`-shaped) as `FUN_00044868`, just this call site's own
 * distinct per-reference stub symbol. Does not change issue #15's own
 * open status; noted here as a data point for whoever eventually resolves
 * that issue.
 *
 * TRANSCRIPTION METHOD: same as `ATIR500Surface_ResolveFSAABuffer.cpp`
 * (flat decompile-derived naming kept close to the original rather than
 * renamed into "cleaner" semantic names; `ATIR500SurfaceBuffer*`-typed
 * field access used in place of raw offset arithmetic wherever the struct
 * already names the field, as a safe non-reinterpreting substitution).
 *
 * Confidence: CONFIRMED for every literal constant and the complete
 * control flow - a real, standalone function (not embedded in one of this
 * project's giant multi-opcode dispatch functions), so its own decompile
 * carries none of the brace-nesting-unreliability risk documented
 * elsewhere in this project for `process_command_buffer`. No C++ compiler
 * was available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project) - checked by
 * careful, repeated manual re-reading against the raw decompile instead.
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

const double kBias = 4503601774854144.0;      /* DOUBLE_0004c3a8: sign-flipped variant */
const double kPlainBias = 4503599627370496.0; /* DOUBLE_0004c3b0: plain/unsigned variant */

} // namespace

void *ATIR500Surface::back_resolve_fsaa_buffer(UInt32 /* real: unused */, UInt32 formatCode, void *paramBlockV) {
    UInt32 *paramBlock = reinterpret_cast<UInt32 *>(paramBlockV);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    /* real: same two sources resolve_fsaa_buffer uses, roles SWAPPED - see
     * this file's own header comment. */
    ATIR500SurfaceBuffer *fixedBuf  = fixedSurfaceBuffer;                 /* real: iVar14 */
    ATIR500SurfaceBuffer *formatBuf = surfaceBuffersByFormat[formatCode]; /* real: iVar13 */

    /* real: FUN_00044d74(paramBlock, &_g_r500_3d_blit_state_packet, 0x2f4) -
     * see this file's own header comment. */
    paramBlock[0xb] = U32At(accel, 0xb74);

    UInt32 tableOffFixed = static_cast<UInt32>(fixedBuf->formatTableIndex) * 0x1cu;
    UInt32 uVar12 = 0;
    paramBlock[0x9a] = (static_cast<UInt32>(fixedBuf->basePitch) * fixedBuf->mipOffsets[0]
                        + fixedBuf->gpuBaseAddress) & 0xffffffe0u;
    if ((fixedBuf->tilingDegreeBits & 0xf00000u) != 0) {
        uVar12 = static_cast<UInt32>(fixedBuf->width) / ((fixedBuf->tilingDegreeBits >> 0x14) & 0xfu);
    }
    UInt32 uVar10 = 0x20u / fixedBuf->bytesPerRow;
    if (uVar10 <= uVar12) uVar10 = uVar12;
    UInt32 uVar8 = paramBlock[0x8a];
    UInt32 fmtFixed = FormatTableLookup_0x0004d2e0(tableOffFixed);
    paramBlock[0x9c] = (uVar10 & 0x3ffeu) | ((fixedBuf->tilingConfigByte0 & 1u) << 0x10) |
                        ((fixedBuf->tilingConfigByte0 & 6u) << 0x10) | ((fixedBuf->tilingConfigByte1 & 3u) << 0x13) |
                        ((fmtFixed >> 1) & 0x1e00000u);
    uVar12 = (fmtFixed >> 0x11) & 0x1fu;
    paramBlock[0x8a] = uVar12 | (uVar8 & 0xffffffe0u);
    uVar10 = (fmtFixed >> 7) & 0x300u;
    paramBlock[0x8a] = uVar10 | uVar12 | (uVar8 & 0xfffffce0u);
    UInt32 uVar11 = (fmtFixed >> 3) & 0xc00u;
    paramBlock[0x8a] = uVar11 | uVar10 | uVar12 | (uVar8 & 0xfffff0e0u);
    UInt32 uVar7 = (fmtFixed & 0x1800u) << 1;
    paramBlock[0x8a] = uVar7 | uVar11 | uVar10 | uVar12 | (uVar8 & 0xffffc0e0u);
    paramBlock[0x8a] = ((fmtFixed & 0x600u) << 5) | uVar7 | uVar11 | uVar10 | uVar12 | (uVar8 & 0xffff00e0u);

    if (((fixedBuf->tilingDegreeBits & 0xf00000u) == 0) ||
        (uVar10 = static_cast<UInt32>(fixedBuf->heightOrRows) / ((fixedBuf->tilingDegreeBits >> 0x14) & 0xfu),
         uVar12 = uVar10 - 1, uVar10 == 0)) {
        uVar12 = 0;
    }
    uVar10 = 0;
    if (fixedBuf->extra1e != 0) uVar10 = fixedBuf->extra1e - 1u;
    paramBlock[0xb3] = (uVar12 & 0x1fffu) | ((uVar10 & 0x1fffu) << 0xd);

    UInt8 formatIdxFmt = formatBuf->formatTableIndex;
    paramBlock[0xa0] = ((formatBuf->tilingConfigByte0 & 7u) << 2) |
                        ((static_cast<UInt32>(formatBuf->basePitch) * formatBuf->mipOffsets[0] + formatBuf->gpuBaseAddress) & 0xffffffe0u);
    if (((formatBuf->tilingDegreeBits & 0xf00000u) == 0) ||
        (uVar10 = static_cast<UInt32>(formatBuf->heightOrRows) / ((formatBuf->tilingDegreeBits >> 0x14) & 0xfu),
         uVar12 = uVar10 - 1, uVar10 == 0)) {
        uVar12 = 0;
    }
    uVar10 = 0;
    if (formatBuf->extra1e != 0) uVar10 = formatBuf->extra1e - 1u;
    paramBlock[0xa6] = (uVar12 & 0x7ffu) | ((uVar10 & 0x7ffu) << 0xb) | 0x80000000u;

    uVar12 = FormatTableLookup_0x0004d2e4(static_cast<UInt32>(formatIdxFmt) * 0x1cu);
    paramBlock[0xa8] = ((uVar12 >> 0x13) & 0x1fu) | ((uVar12 & 0x40u) << 0x10) | ((uVar12 >> 7) & 0xe00u) |
                        ((uVar12 >> 1) & 0x7000u) | ((uVar12 & 0x1c00u) << 5) | ((uVar12 & 0x380u) << 0xb);

    uVar12 = formatBuf->tilingDegreeBits;
    bool tilingClearFmt = (uVar12 & 0xf00000u) == 0;
    if (tilingClearFmt) {
        uVar10 = 0;
    } else {
        uVar10 = static_cast<UInt32>(formatBuf->width) / ((uVar12 >> 0x14) & 0xfu);
    }
    uVar11 = 0x20u / formatBuf->bytesPerRow;
    if (uVar11 <= uVar10) uVar11 = uVar10;
    if (tilingClearFmt ||
        (uVar10 = static_cast<UInt32>(formatBuf->heightOrRows) / ((uVar12 >> 0x14) & 0xfu),
         uVar12 = uVar10 - 1, uVar10 == 0)) {
        uVar12 = 0;
    }
    uVar10 = 0;
    if (formatBuf->extra1e != 0) uVar10 = formatBuf->extra1e - 1u;
    paramBlock[0xaa] = ((uVar11 - 1u) & 0x3fffu) | ((uVar12 & 0x800u) << 4) | ((uVar10 & 0x800u) << 5);

    /* real: this+0xbe8's flag (the SAME top-level flag resolve_fsaa_buffer
     * branches its entire Block-A/Block-B strategy on) gates only this one
     * extra register write here, nothing more - see this file's own header
     * comment, point 2. */
    if ((U32At(this, 0xbe8) & 0x700000u) != 0) {
        paramBlock[0xf] = 0xc0001000;
    }

    /* ---- Float tail: a real per-surface tiling check on fixedBuf (NOT
     * the this+0xbe8 flag above) picks between two real conversion
     * formulas - see this file's own header comment, points 3-4. ---- */
    UInt32 tilingFixed = fixedBuf->tilingDegreeBits;
    float fVar2, fVar3;
    if ((tilingFixed & 0xf00000u) == 0) {
        UInt16 uVar5 = fixedBuf->extra1e;
        paramBlock[0xc5] = 0x10031;
        paramBlock[0xc0] = 0x3f800000; /* real: FLOAT constant, 1.0f */
        paramBlock[0xbd] = 0x31080;
        paramBlock[200] = 0;
        paramBlock[0xbf] = 0x3f800000;
        paramBlock[0xc2] = 0x1087;
        paramBlock[0xc4] = 0xc0033500;
        paramBlock[0xbe] = 0;
        paramBlock[0xc1] = 0;
        paramBlock[0xc6] = 0;
        fVar2 = BiasedIntToFloat(static_cast<UInt32>(uVar5), kPlainBias); /* real: plain, no ^0x80000000 */
        paramBlock[199] = static_cast<UInt32>(fVar2 * 0.5f);
        paramBlock[0xc3] = static_cast<SInt32>(fVar2 * 6.0f);
    } else {
        UInt16 uVar5 = fixedBuf->heightOrRows;
        UInt16 uVar6 = fixedBuf->extra1e;
        paramBlock[0xbd] = 0x31080;
        paramBlock[0xc0] = 0x3f800000;
        paramBlock[0xc2] = 0x1087;
        paramBlock[0xc4] = 0xc0033500;
        paramBlock[0xc5] = 0x10031;
        paramBlock[200] = 0;
        paramBlock[0xbe] = 0;
        paramBlock[0xbf] = 0x3f800000;
        paramBlock[0xc1] = 0;
        fVar2 = BiasedIntToFloat((static_cast<UInt32>(uVar5) / ((tilingFixed >> 0x14) & 0xfu)) ^ 0x80000000u, kBias);
        fVar3 = BiasedIntToFloat(static_cast<UInt32>(uVar6), kPlainBias); /* real: plain, no ^0x80000000 */
        paramBlock[0xc6] = static_cast<UInt32>(fVar2 * 0.5f);
        paramBlock[199] = static_cast<UInt32>(fVar3 * 0.5f);
        paramBlock[0xc3] = (static_cast<SInt32>(fVar2 * 6.0f) << 0x10) | static_cast<SInt32>(fVar3 * 6.0f);
    }

    paramBlock[0xc9] = 0x1393;
    paramBlock[0xca] = 10;

    U32At(accel, 0x78) = 0; /* real: same shared LAB_0004481c-style tail resolve_fsaa_buffer ends with */
    return paramBlock + 0xcb;
}
