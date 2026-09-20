/* NOTE 2026-09-19: 4 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
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
/* (re-ported mechanically: see ATIR500GLContext_build_scissor_Port.cpp) */


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
/* (re-ported mechanically: see ATIR500GLContext_compute_sc_hyperz_en_Port.cpp) */


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
/* (re-ported mechanically: see ATIR500GLContext_compute_zb_bw_cntl_Port.cpp) */

