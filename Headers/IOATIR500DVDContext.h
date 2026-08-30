/*
 * IOATIR500DVDContext.h
 *
 * The DVD/video user-client class - the richest external-method table of
 * the four (22 real selectors), and the one most directly relevant to the
 * project's overarching H.264 GPU-decode goal (owns doIDCT, the real
 * independent hardware IDCT engine's external entry point).
 *
 * Real dispatch shape (ATIR500DVDContext::getTargetAndMethodForIndex, kext
 * offset 0x33bf0): selectors 0-9 index a 10-entry base table at this+0x100;
 * selectors 10-21 index a separate 12-entry table at this+0x1dc
 * (offset-adjusted by -0xf0 = 10 entries * 0x18 bytes).
 *
 * Confidence: selector numbers/names/addresses CONFIRMED from raw kext
 * bytes. Per-method behavior CONFIRMED for everything decompiled this
 * project (stage5, stage8, stage9); argument counts INFERRED from
 * decompiled C signatures, not re-dumped from the raw table.
 */

#ifndef IOATIR500DVDCONTEXT_H
#define IOATIR500DVDCONTEXT_H

#include <IOKit/IOUserClient.h>
#include "ATIRadeonX1000Types.h"

class IOATIR500Surface;

class IOATIR500DVDContext : public IOUserClient {
    OSDeclareDefaultStructors(IOATIR500DVDContext)

public:
    /* ---- Base table, selectors 0-9 ---- */
    IOReturn set_surface(UInt32 surfaceID, UInt32 modeBits, UInt32 param3, UInt32 param4); /* 0 */
    IOReturn get_config(UInt32 *out0, UInt32 *out1, UInt32 *out2);                            /* 1 */
    IOReturn get_status(UInt32 *out0);                                                         /* 2 */
    IOReturn get_surface_size(SInt32 *outW, SInt32 *outH, SInt32 *outX, SInt32 *outY);         /* 3 */
    IOReturn lock_all_buffers(UInt32 param1, UInt32 *outAddress, UInt32 *outSize);              /* 4 */
    IOReturn unlock_memory(UInt32 lockType, UInt32 *outTag);                                    /* 5 */
    IOReturn write_buffer(UInt32 *data, UInt32 byteCount);                                       /* 6 */
    IOReturn finish(void);                                                                       /* 7 */
    IOReturn declare_image(UInt32 param1, UInt32 formatOrSize, UInt32 sizeInBytes, UInt32 *outHandle); /* 8 */
    IOReturn delete_image(UInt32 textureID);                                                     /* 9 */

    /* ---- Extra table, selectors 10-21 ---- */
    IOReturn show_buffer(UInt32 bufferIndex, UInt32 param2); /* 10, CONFIRMED body (stage8): thin lock wrapper delegating to ATIR500Surface::showbuffer, which is a REAL EMPTY NO-OP in this exact kext build */
    IOReturn dvd_setup_overlay(UInt32 x, UInt32 y, UInt32 w, UInt32 h, UInt32 param5); /* 11, CONFIRMED body (stage8): delegates to ATIR500Surface::dvd_setup_overlay - real, stores geometry into the surface's shared this+0x94/0x96/0x98/0x9a fields plus a dirty flag at +0xd94 */
    IOReturn dvd_enable_overlay(UInt32 enable); /* 12, CONFIRMED body (stage8): delegates to ATIR500Surface::enable_overlay/disable_overlay, BOTH real empty no-ops in this exact kext build */
    IOReturn read_regs(UInt32 *offsets, UInt32 *outValues, UInt32 byteCount, UInt32 *inOutCount); /* 13, CONFIRMED body: identical masking/validation shape to the 2D context's read_regs */
    IOReturn write_regs(UInt32 offset, UInt32 value); /* 14, CONFIRMED body: identical masking/validation shape to the 2D context's write_regs (this DVD variant takes a single scalar offset+value pair, not an array, per its real decompiled signature) */
    IOReturn dvd_setup_subpicture(UInt32 param1, UInt32 param2, UInt32 param3); /* 15, CONFIRMED body (stage8): delegates to ATIR500Surface::dvd_setup_subpicture, a REAL EMPTY NO-OP in this exact kext build */
    IOReturn set_macrovision(UInt32 enable); /* 16, INFERRED to be the DVD-context-local equivalent of the 2D context's real, functioning set_macrovision - not independently re-decompiled for the DVD variant this pass */
    IOReturn dvd_enable_deint(UInt32 mode); /* 17, CONFIRMED body (stage8): delegates to ATIR500Surface::enable_deint - real, stores the mode into the surface's +0xdac field; nothing observed reading it back anywhere this project decompiled */
    IOReturn doIDCT(sATIDVDIDCTInfo *info, UInt32 *ioctlParams); /* 18, CONFIRMED body (stage5): real, complex - per-field(top/bottom)/per-plane(luma/chroma) buffer geometry, real ping-pong double-buffering, map_transfer_to_GART, then ATIRadeonX1000::submit_idct_buffer_consumed. THE real external entry point for hardware-accelerated IDCT, directly relevant to the project's H.264 goal. */
    IOReturn wait_for_stamps(UInt32 waitMain, UInt32 waitIDCT); /* 19, CONFIRMED body (stage5): calls two distinct vtable methods (0x5fc/0x558) depending on which flags are set - mirrors the GL side's fence pair, confirming the IDCT path uses the same stamp architecture */
    IOReturn check_stamps(UInt32 checkMain, UInt32 checkIDCT, UInt32 *outBothDone); /* 20, CONFIRMED body (stage5): non-blocking poll counterpart to wait_for_stamps */
    IOReturn setup_buffers(UInt32 topHeight, UInt32 leftWidth, UInt32 bottomHeight, UInt32 rightWidth, UInt32 controlFlags); /* 21, CONFIRMED body (stage5): real per-plane geometry setup for the IDCT working surface, writes a control dword combining caller flags with a fixed 0x20000002 base */

protected:
    void *accelerator;              /* +0x8c, CONFIRMED offset */
    IOATIR500Surface *boundSurface; /* +0xf8, CONFIRMED: the bound surface every overlay/IDCT/deint method above operates through */
};

#endif /* IOATIR500DVDCONTEXT_H */
