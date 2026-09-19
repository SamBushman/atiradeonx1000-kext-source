/*
 * ATIR500GLContext_RegisterState.cpp
 *
 * The real R580 register-state serialization functions:
 * write_kernel_context_buffer_regs (real kext offset 0x288e0) and
 * build_scissor (real kext offset 0x27ee0), both transcribed CLOSE TO THE
 * REAL DECOMPILE this time (raw offset arithmetic, matching the original
 * control flow line-for-line) rather than abstracted into named struct
 * members - the real per-mip/per-unit pitch and tiling math here is dense
 * enough that a faithful, checkable transcription is more valuable than a
 * "clean" one that might silently introduce a mistake. restore_state_
 * destroyed_by_pageoff and the two HyperZ decision functions remain
 * lower-fidelity stubs - see the TODO markers and GAPS.md.
 *
 * Confidence: write_kernel_context_buffer_regs and build_scissor below
 * are CONFIRMED, transcribed directly from a complete real decompile this
 * project produced and re-read in full for this reconstruction pass
 * (not summarized or reconstructed from notes). Field names use this
 * project's existing named members (ATIR500GLContext.h) where they exist;
 * everything else uses raw offsets with an inline comment, exactly as the
 * original decompile expressed it, to avoid guessing at a name that isn't
 * independently confirmed.
 */

#include "../Headers/ATIR500GLContext.h"

/*
 * write_kernel_context_buffer_regs - CONFIRMED, fully transcribed. Real
 * role: commit render-target/HyperZ/scissor state into a real, dense
 * sequence of PM4-header-shaped (index, value) pairs. Confirmed this
 * session to be called from TWO independent real call sites (opcode
 * 0x41's render-target commit AND opcode 0x29's vertex-format-config
 * commit).
 *
 * param2 is a real dword OFFSET into outputBuffer (not a byte offset) -
 * every `param_1[param_2 + N]` in the original decompile is preserved as
 * `outputBuffer[param2 + N]` below. Returns the real new offset
 * (param2 + 0x39) the caller should continue writing from.
 */
/* (re-ported mechanically: see ATIR500GLContext_write_kernel_context_buffer_regs_Port.cpp) */


/*
 * build_scissor - CONFIRMED, fully transcribed (real kext offset
 * 0x27ee0). Computes the real live scissor rectangle written verbatim
 * into the command stream by opcodes 0x28/0x29/0x2a, using the same
 * per-mip tiling-table lookups as write_kernel_context_buffer_regs.
 */
void ATIR500GLContext::build_scissor(void) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 unitIndex;
    UInt8 *mip;

    if (*reinterpret_cast<UInt32 *>(self + 0x3bc) == 0) {
        unitIndex = mipLevel; /* this+0x29c */
        mip = static_cast<UInt8 *>(boundSurface) +
              (*reinterpret_cast<UInt16 *>(self + 0xac)) * 4 + 0xb70;
        mip = *reinterpret_cast<UInt8 **>(mip);
    } else {
        unitIndex = 0;
        mip = self + (*reinterpret_cast<UInt16 *>(self + 0x3b2)) * 0x78 + 0x3c0;
    }

    UInt32 tilingWord = *reinterpret_cast<UInt32 *>(mip + 0x3c);
    SInt32 dimA;
    if ((tilingWord & 0xf00000) == 0) {
        dimA = 1;
    } else {
        dimA = static_cast<SInt32>(static_cast<UInt32>(*reinterpret_cast<UInt16 *>(mip + 0x1c)) /
                                     ((tilingWord >> 0x14) & 0xf)) >> (unitIndex & 0x3f);
        if (dimA == 0) dimA = 1;
    }
    UInt32 dimB = static_cast<UInt32>(*reinterpret_cast<UInt16 *>(mip + 0x1e)) >> (unitIndex & 0x3f);
    if (dimB == 0) dimB = 1;

    /* Real format-table lookup - same DAT_0004d2dc table
     * write_kernel_context_buffer_regs references, indexed by
     * `formatTableIndex * 0x1c` (ATIR500SurfaceBuffer::formatTableIndex,
     * mip[0x3a]). Table CONTENT (raw binary data, not logic) was never
     * extracted into this reconstruction - see GAPS.md. */
    UInt32 formatEntry = FormatTableLookup_0x0004d2dc(mip[0x3a] * 0x1c);
    UInt32 shiftField = (formatEntry >> 3) & 0x1f;
    SInt32 shiftAdjust;
    if (shiftField < 3) {
        shiftAdjust = 0;
    } else if (shiftField <= 4) {
        shiftAdjust = 1;
    } else if (shiftField == 6) {
        shiftAdjust = 1; /* real decompile's `4 < uVar2 && uVar2 != 6` collapses to iVar3=1 here too - see NOTE */
    } else {
        shiftAdjust = 2;
    }
    UInt32 shiftAmount = ((formatEntry >> 0xc) & 7) - static_cast<UInt32>(shiftAdjust);

    /*
     * CONFIRMED: the real decompile writes ONLY this+0x358 (scissorX in
     * this project's naming) as a single packed dword - low 14 bits one
     * dimension, bits 16-29 the other. It does NOT touch this+0x354
     * (scissorY) anywhere in this function.
     *
     * RESOLVED (issue #11): an exhaustive whole-kext instruction scan for
     * the literal offset 0x354 (every function in the binary, not just
     * this class) turns up exactly three hits, and no others:
     *   - ATIR500GLContext::start (0x285c4): `this[0x354] = 0`, part of
     *     the same zero-init block that also clears this+0x358 - see
     *     Headers/ATIR500GLContext.h's start() note.
     *   - write_kernel_context_buffer_regs (0x29234): relays it verbatim
     *     into the command buffer at slot param2+0x37, immediately
     *     followed by scissorX at +0x38 - already reflected above.
     *   - process_command_buffer's opcode 0x2c handler (0x2ebec): splits
     *     both this+0x354 and this+0x358 into their high/low 16-bit
     *     halves and takes the pairwise MAX against the incoming
     *     record's own bound (`if (contextHalf < recordHalf) contextHalf
     *     = recordHalf;`), i.e. this+0x354/this+0x358 act as an outer
     *     clamp/floor that opcode 0x2c widens against, not a value it
     *     overwrites.
     * So option 1 from the original writeup is ruled out for any
     * directly-offset access: no other function anywhere in this kext
     * writes this+0x354 by that literal offset. Given every write site
     * sets it to a compile-time 0 and no traced function ever changes
     * that, this+0x354 is a real, load-bearing field (opcode 0x2c
     * genuinely uses it as intended, paired with +0x358) whose value is
     * simply always 0 in front of every path this project has traced -
     * functionally a no-op floor for the MAX in opcode 0x2c's clamp,
     * since 0 never wins against a real record bound. Two possibilities
     * remain open, now narrowed considerably: a write exists only via a
     * computed (non-literal-immediate) offset this scan cannot see - or
     * on real X1900 hardware this value never legitimately needs to be
     * nonzero (e.g. because the driver's internal coordinate space
     * always has a Y origin of 0) and this is not a bug at all. See
     * GAPS.md and issue #11 for the full trace.
     */
    scissorX = ((static_cast<UInt32>(dimA) << (shiftAmount & 0x3f)) & 0x3fff) | ((dimB & 0x3fff) << 0x10);
}

/*
 * compute_sc_hyperz_en - CONFIRMED, fully transcribed (real kext offset
 * 0x26df0; this project's earlier draft of this function was a stub -
 * this replaces it after a fresh decompile). Real logic: resolve the
 * real surface record (either the bound surface's `this+0xae`-indexed
 * mip record, or the alternate-mode fixed record at `this+0x5a0` - the
 * exact same two-mode selection write_kernel_context_buffer_regs and
 * build_scissor already use). If that surface's real `hyperZEligible`
 * flag (+0x35) is clear, OR the caller's requested value has bit 0
 * clear, the result's bit 0 is forced to 0; otherwise it's forced to 1.
 * Every other bit of `requested` passes through unchanged.
 */
UInt32 ATIR500GLContext::compute_sc_hyperz_en(UInt32 requested) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    ATIR500SurfaceBuffer *rec;
    if (*reinterpret_cast<UInt32 *>(self + 0x3bc) == 0) {
        UInt8 *surfaceBase = static_cast<UInt8 *>(boundSurface);
        UInt16 unit = *reinterpret_cast<UInt16 *>(self + 0xae);
        rec = *reinterpret_cast<ATIR500SurfaceBuffer **>(surfaceBase + unit * 4 + 0xb70);
    } else {
        rec = reinterpret_cast<ATIR500SurfaceBuffer *>(self + 0x5a0);
    }

    UInt32 bit0 = (rec->hyperZEligible != 0 && (requested & 1) != 0) ? 1u : 0u;
    return (requested & 0xfffffffeu) | bit0;
}

/*
 * compute_zb_bw_cntl - CONFIRMED, fully transcribed (real kext offset
 * 0x26e40; replaces this project's earlier stub the same way as
 * compute_sc_hyperz_en above). Same real surface-record selection. Real
 * bit 0x1c (HZ_MIN-area, per ATIRadeonX1000Registers.h's ZB_BW_CNTL
 * note) is set when the surface's `zbBandwidthEligible` flag is set AND
 * either its block width (+0x16) exceeds 2 texels or its tiling-degree
 * bits (`tilingDegreeBits`, +0x3c, bits 20-23 - CORRECTED: this comment
 * previously misattributed the real read to `formatOrTilingBits`/+0x28,
 * a field that never actually existed here; the real code has always
 * correctly read +0x3c) exceed 2. Real bit 0x1 is set when
 * `hyperZEligible` is set AND the
 * caller requested bit 0 - the same condition compute_sc_hyperz_en uses.
 */
UInt32 ATIR500GLContext::compute_zb_bw_cntl(UInt32 requested) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    ATIR500SurfaceBuffer *rec;
    if (*reinterpret_cast<UInt32 *>(self + 0x3bc) == 0) {
        UInt8 *surfaceBase = static_cast<UInt8 *>(boundSurface);
        UInt16 unit = *reinterpret_cast<UInt16 *>(self + 0xae);
        rec = *reinterpret_cast<ATIR500SurfaceBuffer **>(surfaceBase + unit * 4 + 0xb70);
    } else {
        rec = reinterpret_cast<ATIR500SurfaceBuffer *>(self + 0x5a0);
    }

    UInt32 bits = 0;
    UInt8 *recBytes = reinterpret_cast<UInt8 *>(rec);
    UInt16 blockWidth = *reinterpret_cast<UInt16 *>(recBytes + 0x16);
    UInt32 tilingDegree = (*reinterpret_cast<UInt32 *>(recBytes + 0x3c) >> 0x14) & 0xf;
    if (rec->zbBandwidthEligible != 0 && (blockWidth > 2 || tilingDegree > 2)) {
        bits = 0x1c;
    }
    if (rec->hyperZEligible != 0 && (requested & 1) != 0) {
        bits |= 1;
    }
    return (requested & 0xffffffe2u) | bits;
}
