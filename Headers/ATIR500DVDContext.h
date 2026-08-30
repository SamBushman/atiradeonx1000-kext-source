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
     * process_command_buffer - PARTIALLY RESOLVED (issue #7): the real
     * dispatch skeleton and two real opcode families (texture bind,
     * covering opcodes 0x19/0x1a/0x1b/0x1c/0x1e-0x25/0x26-0x2a/0x2d, and
     * texture unbind, covering 0x2b/0x2c/0x2e-0x30/0x32-0x34/0x36-0x3c -
     * 33 of the real ~55 opcodes) are transcribed - see
     * Sources/ATIR500DVDContext_ProcessCommandBuffer.cpp for the two
     * handler functions and GAPS.md for the full opcode-by-opcode
     * status. The remaining opcodes (dense per-mip YUV/tiling math,
     * comparable in density to GL's own richest opcodes) are NOT yet
     * transcribed, so this method itself is not yet declared/wired -
     * the two handlers exist as free functions a future completed
     * dispatcher will call.
     */

protected:
    sATIDVDIDCTInfo *idctInfo; /* +0xf8-adjacent per-context IDCT state - CONFIRMED to be reached through boundSurface's slot in the real decompile (`*(int*)(this+0xf8)`); modeled as its own field here since sATIDVDIDCTInfo (Headers/ATIRadeonX1000Types.h) IS the real struct doIDCT receives as its first argument, and this project confirmed the two are the same object (doIDCT's param_1 gets passed around identically to what setup_buffers/dvd_setup_overlay's `this+0xf8` chases). */
};

#endif /* ATIR500DVDCONTEXT_H */
