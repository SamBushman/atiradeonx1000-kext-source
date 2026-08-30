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

class ATIRadeonX1000;
class IOATIR500Surface;
class IOATIR500Shared;

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

    /*
     * add_texture_to_stream / remove_texture_from_stream -
     * CONFIRMED real names/signatures (real mangled symbols
     * __ZN19IOATIR500DVDContext21add_texture_to_streamEP19VendorTextureBuffer /
     * __ZN19IOATIR500DVDContext26remove_texture_from_streamEP19VendorTextureBuffer),
     * found this pass (issue #7) as real call sites in
     * ATIR500DVDContext::process_command_buffer's texture bind/unbind
     * opcode families - the same real names as GL's own override of
     * these methods. Own bodies NOT independently decompiled this pass.
     */
    void add_texture_to_stream(VendorTextureBuffer *texture);
    void remove_texture_from_stream(VendorTextureBuffer *texture);

protected:
    ATIRadeonX1000 *accelerator;    /* +0x8c, CONFIRMED offset. CORRECTED to the concrete ATIRadeonX1000 type - see ATIRadeonX1000.h's real-Info.plist correction note. */
    IOATIR500Surface *boundSurface; /* +0xf8, CONFIRMED: the bound surface every overlay/IDCT/deint method above operates through */
    IOATIR500Shared *sharedAllocator; /* +0x84, CONFIRMED (issue #7): owns the real texture-lookup-by-index table (own +0x10/+0x14 fields) the bind/unbind opcode families bounds-check and index into - the same real layout independently confirmed on GL and 2D's own equivalents this session. */

    /* Real fields found this pass (issue #7), via
     * ATIR500DVDContext::process_command_buffer's bind/unbind opcode
     * families: */
    UInt32 commandBufferBase;  /* +0xa4, CONFIRMED: real command-buffer base process_command_buffer reads records from (+0x1c offset to the first record) and submit_buffer's own base-address argument - mirrors GL's this+0xe0/2D's this+0xac role. */
    UInt32 ringSlotZeroCheck;  /* +0x94, CONFIRMED: mirrors GL's this+0xd0/2D's this+0x9c role - zero-checked to decide whether to GART-map the pending transfer buffer. */
    UInt8  pendingTransferBuffer[1]; /* +0x90, CONFIRMED to exist (passed to map_transfer_to_GART as `this+0x90`) - real size/type UNKNOWN, modeled as a byte anchor only. */
    UInt32 lastSubmitResult;   /* +0xa0, CONFIRMED: stores ATIRadeonX1000::submit_buffer's real return value - mirrors GL's this+0xdc/0x7c, 2D's this+0xa8 role. */
};

#endif /* IOATIR500DVDCONTEXT_H */
