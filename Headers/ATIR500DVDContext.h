/*
 * ATIR500DVDContext.h
 *
 * The DVD/video subclass adding selectors 10-21 on top of
 * IOATIR500DVDContext's base 0-9 - the richest extra-selector block of
 * any context class, and the one most directly relevant to this
 * project's H.264 GPU-decode goal (owns doIDCT).
 */

#ifndef ATIR500DVDCONTEXT_H
#define ATIR500DVDCONTEXT_H

#include "IOATIR500DVDContext.h"
#include "ATIRadeonX1000Registers.h"

class ATIR500DVDContext : public IOATIR500DVDContext {
    OSDeclareDefaultStructors(ATIR500DVDContext)

public:
    IOReturn show_buffer(UInt32 bufferIndex, UInt32 param2); /* 10, CONFIRMED body (stage8): thin lock wrapper delegating to ATIR500Surface::showbuffer, which is a REAL EMPTY NO-OP in this exact kext build */
    IOReturn dvd_setup_overlay(UInt32 x, UInt32 y, UInt32 w, UInt32 h, UInt32 param5); /* 11, CONFIRMED body (stage8): delegates to ATIR500Surface::dvd_setup_overlay - real, stores geometry into the surface's shared this+0x94/0x96/0x98/0x9a fields plus a dirty flag at +0xd94 */
    IOReturn dvd_enable_overlay(UInt32 enable); /* 12, CONFIRMED body (stage8): delegates to ATIR500Surface::enable_overlay/disable_overlay, BOTH real empty no-ops in this exact kext build */
    IOReturn read_regs(UInt32 *offsets, UInt32 *outValues, UInt32 byteCount, UInt32 *inOutCount); /* 13, CONFIRMED body: identical masking/validation shape to the 2D context's read_regs - see Sources/ATIR500DVDContext_RawRegs.cpp */
    IOReturn write_regs(UInt32 offset, UInt32 value); /* 14, CONFIRMED body: this DVD variant's real decompiled signature takes a single scalar (offset, value) pair, not an array like the 2D context's write_regs */
    IOReturn dvd_setup_subpicture(UInt32 param1, UInt32 param2, UInt32 param3); /* 15, CONFIRMED body (stage8): delegates to ATIR500Surface::dvd_setup_subpicture, a REAL EMPTY NO-OP in this exact kext build */
    IOReturn set_macrovision(UInt32 enable); /* 16, INFERRED to be the DVD-context-local equivalent of the 2D context's real, functioning set_macrovision - not independently re-decompiled for the DVD variant this pass */
    IOReturn dvd_enable_deint(UInt32 mode); /* 17, CONFIRMED body (stage8): delegates to ATIR500Surface::enable_deint - real, stores the mode into the surface's +0xdac field; nothing observed reading it back anywhere this project decompiled */

    /*
     * doIDCT - CONFIRMED, fully decoded (real kext offset 0x35540). THE
     * real external entry point for hardware-accelerated IDCT - directly
     * relevant to this project's H.264 goal. Full reconstruction in
     * Sources/ATIR500DVDContext_IDCT.cpp.
     */
    IOReturn doIDCT(sATIDVDIDCTInfo *info, sATIDVDIDCTParams *ioctlParams);   /* 18 */
    IOReturn wait_for_stamps(UInt32 waitMain, UInt32 waitIDCT);                /* 19, CONFIRMED body (stage5): calls two distinct vtable methods (0x5fc/0x558) depending on which flags are set - mirrors the GL side's fence pair, confirming the IDCT path uses the same stamp architecture */
    IOReturn check_stamps(UInt32 checkMain, UInt32 checkIDCT, UInt32 *outBothDone); /* 20, CONFIRMED body (stage5): non-blocking poll counterpart to wait_for_stamps */
    IOReturn setup_buffers(UInt32 topHeight, UInt32 leftWidth, UInt32 bottomHeight, UInt32 rightWidth, UInt32 controlFlags); /* 21, CONFIRMED body (stage5): real per-plane geometry setup for the IDCT working surface, writes a control dword combining caller flags with a fixed 0x20000002 base */

    /* map_transfer_to_GART - CONFIRMED real name (called directly by
     * doIDCT), shared architecture with every other context's own
     * override of the same real name. Body UNKNOWN beyond role. */
    void map_transfer_to_GART(VendorTransferBuffer *buffer);

    /*
     * submit_context_buffer / allocAllContextBuffers - CONFIRMED real
     * names/signatures (real mangled symbols
     * __ZN17ATIR500DVDContext21submit_context_bufferEv /
     * __ZN19IOATIR500DVDContext22allocAllContextBuffersEm), the same
     * real per-context-type pattern GL has its own versions of (issue
     * #5). Neither independently decompiled this pass.
     */
    void submit_context_buffer(void);
    bool allocAllContextBuffers(UInt32 size);

    /*
     * process_command_buffer - PARTIALLY RESOLVED (issue #7), NOW
     * ASSEMBLED AND WIRED (was previously just free functions awaiting a
     * dispatcher - the dispatcher itself is now real, see
     * Sources/ATIR500DVDContext_ProcessCommandBuffer.cpp). Real dispatch
     * skeleton plus real opcode groups: texture bind (0x19-0x1d,
     * 0x1e-0x25, 0x26-0x2a - 0x2d moved OUT, see correction below);
     * texture unbind (0x2b/0x2c, 0x2d, 0x2e-0x30, 0x31, 0x32-0x34, 0x35,
     * 0x36-0x3c); the opcode 0x2 return-code setter; the opcode 0x4
     * explicit-flush; the opcode 0x5/0x6 texture-sampler-state pair;
     * opcodes 0xa/0xb/0xd's own per-mip YUV/tiling setup; opcode 0x13's
     * texture-fetch setup; opcodes 0x3e/0x3f/0x42/0x43/0x44/0x46/0x47; and,
     * in later continuations of this same pass, opcodes 0x14/0x16 (dense
     * multi-plane YUV/tiling bursts), 0x18 (a two-transfer-buffer fetch),
     * 0x15 (a real FIXED `boundSurface+0x7b0` sub-record, unlike every
     * other opcode in this cluster), and 0x3d (the densest opcode
     * transcribed this whole pass - a real self-consuming record
     * producing TWO 5-plane PM4 bursts, with a real 32-bit-overflow
     * pointer-arithmetic subtlety this project caught and worked around
     * rather than reproducing via undefined behavior - see that
     * function's own header comment), and 0x17 (a 3-output analog of
     * 0x14's own 6-way branch, transcribed in a still-later continuation
     * after an earlier attempt at it was deliberately abandoned
     * mid-branch on a register whose value looked unexplained -
     * resolved by re-reading from the real function entry rather than
     * mid-function; see handle_opcode_17's own header comment), and
     * FINALLY 0x12 (the single largest item in this whole issue, closing
     * it out - two independent real transfer buffers each GART-mapped
     * via the exact same real sequence `handle_opcode_18` already
     * transcribes, feeding an 8-entry stride table split across two
     * near-mirror 30-slot PM4 bursts, each ending in a real caller-data-
     * driven variable-length trailing loop using the exact same real
     * 32-bit-address-arithmetic-overflow idiom `handle_opcode_3d`
     * documents, independently re-confirmed here via direct disassembly
     * tracing; see handle_opcode_12's own header comment for a real
     * false lead this project chased and ruled out while locating this
     * opcode's true body) (50 real opcodes with genuine handlers now),
     * plus four more (0x07/0x08/0x09/0x0c) confirmed to be real
     * HARD-ABORT paths (not a plain skip - see the dispatcher's own
     * comment) with no other real handler.
     *
     * THREE REAL CORRECTIONS to this project's own earlier opcode
     * accounting, found via direct PPC branch-instruction tracing (not
     * decompiled-C brace nesting, which had already produced two
     * mistakes on this exact function in an earlier pass): opcode 0x2d
     * is really part of the UNBIND family, not bind as earlier prose
     * here wrongly listed; opcode 0x35 is ALSO an unbind opcode,
     * previously not catalogued at all; opcode 0x31 was already known to
     * be a real unbind opcode but had never actually been wired to a
     * handler in any dispatcher (none existed yet) - now fixed, reusing
     * the already-transcribed handler with no new decompile work. Also
     * corrected:
     * `handle_texture_bind`'s own bounds-check-failure path is a real
     * HARD ABORT (not a plain skip) - see that function's own header
     * note - and `local_64`/`local_58`/`local_60`/`local_5c` (used by
     * opcodes 0xa/0xb/0x46) are real shared, cross-opcode-call
     * `process_command_buffer`-scope state, not fresh per-call locals as
     * an earlier pass modeled them - see handle_opcode_0a's header note
     * for the full explanation of both corrections.
     *
     * See Sources/ATIR500DVDContext_ProcessCommandBuffer.cpp for every
     * handler function and GAPS.md for the full opcode-by-opcode status,
     * including a real correction (DVD has no opcode 0x11 at all).
     *
     * FULLY RESOLVED: issue #7 is closed. Every real DVD opcode this
     * project found now has a genuine handler wired into the dispatcher.
     */
    IOReturn process_command_buffer(VendorCommandDescriptor *descriptor);

protected:
    sATIDVDIDCTInfo *idctInfo; /* +0xf8-adjacent per-context IDCT state - CONFIRMED to be reached through boundSurface's slot in the real decompile (`*(int*)(this+0xf8)`); modeled as its own field here since sATIDVDIDCTInfo (Headers/ATIRadeonX1000Types.h) IS the real struct doIDCT receives as its first argument, and this project confirmed the two are the same object (doIDCT's param_1 gets passed around identically to what setup_buffers/dvd_setup_overlay's `this+0xf8` chases). */
};

#endif /* ATIR500DVDCONTEXT_H */
