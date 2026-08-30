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

    /*
     * NOTE on selectors 10-21: real decompiled signatures for all twelve
     * (show_buffer, dvd_setup_overlay, dvd_enable_overlay, read_regs,
     * write_regs, dvd_setup_subpicture, set_macrovision, dvd_enable_deint,
     * doIDCT, wait_for_stamps, check_stamps, setup_buffers) are
     * `ATIR500DVDContext::` (the SUBCLASS), not `IOATIR500DVDContext::`
     * (this base class) - the same base/subclass split pattern already
     * established for the GL and 2D contexts. See ATIR500DVDContext.h.
     */

protected:
    void *accelerator;              /* +0x8c, CONFIRMED offset */
    IOATIR500Surface *boundSurface; /* +0xf8, CONFIRMED: the bound surface every overlay/IDCT/deint method above operates through */
};

#endif /* IOATIR500DVDCONTEXT_H */
