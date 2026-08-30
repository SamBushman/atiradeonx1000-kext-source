/*
 * IOATIR5002DContext.h
 *
 * The 2D (QuickDraw) acceleration user-client class. Real selector
 * numbers/names/addresses CONFIRMED from raw kext bytes
 * (stage5-iouserclient-external-method-api-complete.md); real per-method
 * behavior for most of these CONFIRMED from direct decompilation
 * (stage8-dvd-overlay-and-2d-acceleration-decoded.md). Argument scalar/
 * struct counts below are INFERRED from each method's own decompiled C
 * signature, not re-dumped from the raw static table the way GL's was -
 * see Headers/IOATIR500GLContext.h for the difference in confidence tier.
 *
 * Real dispatch shape (ATIR5002DContext::getTargetAndMethodForIndex,
 * kext offset 0x31990): selectors 0-15 index a 16-entry base table at
 * this+0x10c; selectors 16-18 index a SEPARATE 3-entry table at
 * this+0x120 (offset-adjusted by -0x180 = 16 entries * 0x18 bytes).
 */

#ifndef IOATIR5002DCONTEXT_H
#define IOATIR5002DCONTEXT_H

#include <IOKit/IOUserClient.h>
#include "ATIRadeonX1000Types.h"

class ATIRadeonX1000;
class IOATIR500Shared;
class IOATIR500Surface;

class IOATIR5002DContext : public IOUserClient {
    OSDeclareDefaultStructors(IOATIR5002DContext)

public:
    /* ---- Base table, selectors 0-15 ---- */
    IOReturn set_surface(UInt32 surfaceID, UInt32 modeBits, UInt32 param3, UInt32 param4);          /* 0, INFERRED shape by analogy with the GL context's own set_surface */
    IOReturn get_config(UInt32 *out0, UInt32 *out1, UInt32 *out2);                                     /* 1 */
    IOReturn get_surface_info(UInt32 surfaceID, SInt32 *outFlags, SInt32 *outW, SInt32 *outH);         /* 2 */
    IOReturn swap_surface(UInt32 lockType, UInt32 *outTag);                                             /* 3, CONFIRMED body (stage9): real retry loop (up to 1000 attempts) calling IOATIR500Surface::alloc_surfaces on demand, flush_surface, real present/flip via unlock_memory's negative-lock-type path */
    IOReturn scale_surface(UInt32 flags, UInt32 xScale, UInt32 yScale);                                 /* 4 */
    IOReturn lock_memory(UInt32 lockType, UInt32 *outAddress, UInt32 *outSize);                          /* 5, CONFIRMED body (stage9): real retry loop with alloc_surfaces fallback, real pending-GPU-flush detection before granting a CPU lock */
    IOReturn unlock_memory(UInt32 lockType, UInt32 *outTag);                                             /* 6, CONFIRMED body (stage9): triggers swap_surface for negative lock-type values - the real present/flip mechanism */
    IOReturn finish(void);                                                                               /* 7 */
    IOReturn declare_image(UInt32 param1, UInt32 formatOrSize, UInt32 sizeInBytes, UInt32 *outHandle);   /* 8, CONFIRMED body (stage9): real IOATIR500Shared::new_agp_texture call, same shared allocator as GL */
    IOReturn create_image(UInt32 param1, UInt32 param2, UInt32 *outLow, UInt32 *outHigh);                /* 9, CONFIRMED body (stage9): real IOATIR500Shared::new_texture call */
    IOReturn create_transfer(UInt32 param1, UInt32 sizeInBytes, UInt32 *outHandle, UInt32 *outAddress);  /* 10, CONFIRMED body (stage9): real AGP-backed transfer-buffer alloc + real backing-store swap if a surface is bound */
    IOReturn delete_image(UInt32 textureID);                                                             /* 11, CONFIRMED body (stage9): real bounds-checked lookup + refcounted cleanup */
    IOReturn wait_image(UInt32 textureID);                                                               /* 12, CONFIRMED body (stage9): real fence wait via a vtable call at offset 0x550, shares the fence architecture with GL's wait_for_stamp */
    IOReturn set_surface_paging_options(void *inStruct, void *outStruct, UInt32 structSize, UInt32 *outTag); /* 13, CONFIRMED body (stage9): unconditionally returns 0xe00002c7 (kIOReturnUnsupported) - a deliberate stub in this build */
    IOReturn set_surface_vsync_options(void *inStruct, void *outStruct, UInt32 structSize, UInt32 *outTag);  /* 14, CONFIRMED body (stage9): same deliberate-stub pattern as set_surface_paging_options */
    IOReturn set_macrovision(UInt32 enable);                                                              /* 15, CONFIRMED body (stage9): real and functioning - iterates every active display connection, calls a vtable method (opcode 0x92) on each */

    /*
     * map_transfer_to_GART - CONFIRMED real name/signature (real mangled
     * symbol __ZN18IOATIR5002DContext20map_transfer_to_GARTEP20VendorTransferBuffer),
     * found this pass as a real call site in ATIR5002DContext::
     * process_command_buffer (issue #7) - see
     * Sources/ATIR5002DContext_ProcessCommandBuffer.cpp. Same real role
     * as the identically-named methods on IOATIR500GLContext/
     * IOATIR500DVDContext. Own body NOT independently decompiled this
     * pass.
     */
    void map_transfer_to_GART(VendorTransferBuffer *buffer);

    /*
     * NOTE on selectors 16-18: real decompiled signatures for read_regs/
     * write_regs/write_2_regs are `ATIR5002DContext::` (the SUBCLASS),
     * not `IOATIR5002DContext::` (this base class) - matching the exact
     * same base/subclass method split pattern already established for
     * the GL context (IOATIR500GLContext.h/ATIR500GLContext.h). See
     * ATIR5002DContext.h for those three methods.
     */

protected:
    ATIRadeonX1000 *accelerator;   /* +0x94, CONFIRMED offset (every method above reaches hardware through `*(int*)(this+0x94)`). CORRECTED to the concrete ATIRadeonX1000 type - see ATIRadeonX1000.h's real-Info.plist correction note. */
    IOATIR500Shared *sharedAllocator; /* +0x88, CONFIRMED: the IOATIR500Shared* lazily created via create_shared() on first texture/transfer allocation. Concrete type CONFIRMED this pass (issue #7) - real bounds-checked texture-by-index lookups go through its own +0x10 (array)/+0x14 (count) fields, the same real layout independently confirmed via DVD's this+0x84 and GL's own texture lists. */
    IOATIR500Surface *boundSurface; /* +0x100, CONFIRMED: the currently-bound surface, read throughout lock_memory/swap_surface/create_transfer */

    /*
     * Real fields found this pass (issue #7), via
     * ATIR5002DContext::process_command_buffer:
     */
    VendorTextureBuffer *lastBoundTexture; /* +0x114, CONFIRMED: the currently-bound texture for the raw command-buffer bind opcodes (0x3/0x4/0x7/0x8/0xd/0x13) - flushed and re-set every time a bind opcode runs, mirroring the same single-slot "last bound" pattern GL's own context classes don't need (GL tracks a 42-entry array instead - this class only ever has one). */
    void *pendingWriteQueue; /* +200 (0xc8), CONFIRMED: the SAME real "pending write batch" object GL's invalidate()/submit_context_buffer use at this+0x108 (own +0x1c bit 0 = dirty flag) - same idiom, different per-class offset. */
    UInt32 commandBufferBase; /* +0xac, CONFIRMED: the real command-buffer base this class's process_command_buffer reads records from (+0x1c offset to the first record), and submit_buffer's own base-address argument. */
    UInt32 ringSlotBufferOffset; /* +0x9c, CONFIRMED: mirrors GL's own this+0xd0 role - zero-checked to decide whether to GART-map the pending transfer buffer. */
    UInt8 pendingTransferBuffer[1]; /* +0x98, CONFIRMED to exist (passed to map_transfer_to_GART as `this+0x98`) - real size/type UNKNOWN, modeled as a byte anchor only. */
    UInt32 lastSubmitResult; /* +0xa8, CONFIRMED: stores ATIRadeonX1000::submit_buffer's real return value, mirroring GL's this+0xdc/this+0x7c role. */
    UInt32 defaultMipIndex; /* +0x110, CONFIRMED: real fallback per-mip index used when boundSurface (this+0x100) is null. */
};

#endif /* IOATIR5002DCONTEXT_H */
