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
    IOReturn get_config(UInt32 *out0, UInt32 *out1);                                                    /* 1, REAL SIGNATURE CORRECTED (issue #42 pass): the shipped mangled symbol (get_configEPmS0_) and its dispatch-table entry (0 in / 2 out) have TWO outputs, not three. Body: Sources/IOATIR5002DContext_ExternalMethods.cpp */
    IOReturn get_surface_info(UInt32 surfaceID, SInt32 *outFlags, SInt32 *outW, SInt32 *outH);         /* 2 */
    IOReturn swap_surface(UInt32 lockType, UInt32 *outTag);                                             /* 3, CONFIRMED body (stage9): real retry loop (up to 1000 attempts) calling IOATIR500Surface::alloc_surfaces on demand, flush_surface, real present/flip via unlock_memory's negative-lock-type path */
    IOReturn scale_surface(UInt32 flags, UInt32 xScale, UInt32 yScale);                                 /* 4 */
    IOReturn lock_memory(UInt32 lockType, UInt32 *outAddress, UInt32 *outSize);                          /* 5, CONFIRMED body (stage9): real retry loop with alloc_surfaces fallback, real pending-GPU-flush detection before granting a CPU lock */
    IOReturn unlock_memory(UInt32 lockType, UInt32 *outTag);                                             /* 6, CONFIRMED body (stage9): triggers swap_surface for negative lock-type values - the real present/flip mechanism */
    IOReturn finish(UInt32 mode);                                                                        /* 7, REAL SIGNATURE CORRECTED (issue #42 pass): mangled symbol is finish(unsigned long), table = 1 scalar in. 0 = wait on this context's stamp, 1/2 = wait on the accelerator's pending stamp, else BadArgument. */
    bool     create_shared(void);                                                                        /* helper, real addr 0xbc90: new IOATIR500Shared + init, wired to the accelerator and task */
    IOReturn declare_image(UInt32 param1, UInt32 formatOrSize, UInt32 sizeInBytes, UInt32 *outHandle);   /* 8, CONFIRMED body (stage9): real IOATIR500Shared::new_agp_texture call, same shared allocator as GL */
    IOReturn create_image(UInt32 param1, UInt32 param2, UInt32 *outLow, UInt32 *outHigh);                /* 9, CONFIRMED body (stage9): real IOATIR500Shared::new_texture call */
    IOReturn create_transfer(UInt32 param1, UInt32 sizeInBytes, UInt32 *outHandle, UInt32 *outAddress);  /* 10, CONFIRMED body (stage9): real AGP-backed transfer-buffer alloc + real backing-store swap if a surface is bound */
    IOReturn delete_image(UInt32 textureID);                                                             /* 11, CONFIRMED body (stage9): real bounds-checked lookup + refcounted cleanup */
    IOReturn wait_image(UInt32 textureID);                                                               /* 12, CONFIRMED body (stage9): real fence wait via a vtable call at offset 0x550, shares the fence architecture with GL's wait_for_stamp */
    IOReturn set_surface_paging_options(void *inStruct, void *outStruct, UInt32 structSize, UInt32 *outTag); /* 13, CONFIRMED body (stage9): unconditionally returns 0xe00002c7 (kIOReturnUnsupported) - a deliberate stub in this build */
    IOReturn set_surface_vsync_options(void *inStruct, void *outStruct, UInt32 structSize, UInt32 *outTag);  /* 14, CONFIRMED body (stage9): same deliberate-stub pattern as set_surface_paging_options */
    IOReturn set_macrovision(UInt32 enable);                                                              /* 15, CONFIRMED body (stage9): real and functioning - iterates every active display connection, calls a vtable method (opcode 0x92) on each */

    /*
     * map_transfer_to_GART - RESOLVED, issue #28. Same real structure as
     * every other class's own copy: calls `addTransferToGART` then
     * unconditionally `freeToAllocGART` - see
     * Sources/MapTransferToGART_RemainingContexts.cpp.
     */
    void map_transfer_to_GART(VendorTransferBuffer *buffer);

    /*
     * freeToAllocGART - RESOLVED (issue #1, get-it-linking pass), real
     * addr 0x3c84/0xbbc0. This context's own small set of candidate
     * transfer-buffer slots (`+0xb4`/`+0xc4`, `+0x98`/`+0xa8`, then a
     * fixed 2-element array at `+0xcc`/`+0xdc` stride 0x18) tried in
     * order via `IOATIR500Accelerator::freeTransferToAllocGART`,
     * stopping at the first one that succeeds - called from
     * `IOATIR500Accelerator::freeWaitToAllocGART`'s own global GART
     * reclamation sweep. Real field roles beyond "candidate transfer
     * buffer slot" not independently investigated this pass.
     */
    bool freeToAllocGART(VendorTransferBuffer *needed, bool aggressive);

    /*
     * allocAllContextBuffers - CONFIRMED to exist and be a real member of
     * this class (mangled __ZN18IOATIR5002DContext22allocAllContextBuffersEm,
     * kext offset 0xbee0), a real gap this project's header set had never
     * declared before this pass despite GL/DVD's own equivalents already
     * being documented. Own body RESOLVED, issue #33 - see
     * Sources/ATIRadeonX1000_AllocAllContextBuffers.cpp.
     */
    bool allocAllContextBuffers(UInt32 size);
    void init_context_buffer_header(VendorContextBufferHeader *header, UInt32 size); /* real mangled __ZN18IOATIR5002DContext26init_context_buffer_headerEP25VendorContextBufferHeaderm, real addr 0xbaf0 - RESOLVED, issue #46, see Sources/ATIRadeonX1000_InitContextBufferHeader.cpp */

    /*
     * freeAllContextBuffers - CONFIRMED to exist (real mangled
     * __ZN18IOATIR5002DContext21freeAllContextBuffersEv, real addr
     * 0xb6c0), the real per-class sibling `IOATIR500GLContext::
     * freeAllContextBuffers` (Headers/IOATIR500GLContext.h) already
     * declares. Own body RESOLVED, issue #54 - see
     * Sources/IOATIR500GLContext_FreeAllContextBuffers.cpp (kept with
     * the GL sibling despite the class, matching this project's own
     * per-class-family file convention).
     */
    void freeAllContextBuffers();

    /*
     * NOTE on selectors 16-18: real decompiled signatures for read_regs/
     * write_regs/write_2_regs are `ATIR5002DContext::` (the SUBCLASS),
     * not `IOATIR5002DContext::` (this base class) - matching the exact
     * same base/subclass method split pattern already established for
     * the GL context (IOATIR500GLContext.h/ATIR500GLContext.h). See
     * ATIR5002DContext.h for those three methods.
     */

protected:
    /*
     * FIXED (issue #56): these ten fields were declared in discovery
     * order with no padding scaffolding at all - reordered here into
     * true ascending real-offset order with a leading pad from this
     * class's own start (IOUserClient is the real base) and a pad
     * array in every real gap. None of these fields are accessed by
     * their C++ name anywhere in this project's own `.cpp` files (real
     * access is always raw pointer arithmetic at the literal offset),
     * so there was no live functional bug from this today - but
     * `sizeof(IOATIR5002DContext)` was far smaller than the real
     * object, which matters for this class's own real `OSTypeAlloc`
     * allocation size.
     */
    UInt8 _pad_0x00[0x88];
    IOATIR500Shared *sharedAllocator; /* +0x88, CONFIRMED: the IOATIR500Shared* lazily created via create_shared() on first texture/transfer allocation. Concrete type CONFIRMED this pass (issue #7) - real bounds-checked texture-by-index lookups go through its own +0x10 (array)/+0x14 (count) fields, the same real layout independently confirmed via DVD's this+0x84 and GL's own texture lists. */
    UInt8 _pad_0x8c[0x94 - 0x8c];
    ATIRadeonX1000 *accelerator;   /* +0x94, CONFIRMED offset (every method above reaches hardware through `*(int*)(this+0x94)`). CORRECTED to the concrete ATIRadeonX1000 type - see ATIRadeonX1000.h's real-Info.plist correction note. */
    UInt8 pendingTransferBuffer[1]; /* +0x98, CONFIRMED to exist (passed to map_transfer_to_GART as `this+0x98`) - real size/type UNKNOWN, modeled as a byte anchor only. */
    UInt8 _pad_0x99[0x9c - 0x99];
    UInt32 ringSlotBufferOffset; /* +0x9c, CONFIRMED: mirrors GL's own this+0xd0 role - zero-checked to decide whether to GART-map the pending transfer buffer. */
    UInt8 _pad_0xa0[0xa8 - 0xa0];
    UInt32 lastSubmitResult; /* +0xa8, CONFIRMED: stores ATIRadeonX1000::submit_buffer's real return value, mirroring GL's this+0xdc/this+0x7c role. */
    UInt32 commandBufferBase; /* +0xac, CONFIRMED: the real command-buffer base this class's process_command_buffer reads records from (+0x1c offset to the first record), and submit_buffer's own base-address argument. */
    UInt8 _pad_0xb0[0xc8 - 0xb0];
    void *pendingWriteQueue; /* +200 (0xc8), CONFIRMED: the SAME real "pending write batch" object GL's invalidate()/submit_context_buffer use at this+0x108 (own +0x1c bit 0 = dirty flag) - same idiom, different per-class offset. */
    UInt8 _pad_0xcc[0x100 - 0xcc];
    IOATIR500Surface *boundSurface; /* +0x100, CONFIRMED: the currently-bound surface, read throughout lock_memory/swap_surface/create_transfer */
    UInt8 _pad_0x104[0x110 - 0x104];
    UInt32 defaultMipIndex; /* +0x110, CONFIRMED: real fallback per-mip index used when boundSurface (this+0x100) is null. */
    VendorTextureBuffer *lastBoundTexture; /* +0x114, CONFIRMED: the currently-bound texture for the raw command-buffer bind opcodes (0x3/0x4/0x7/0x8/0xd/0x13) - flushed and re-set every time a bind opcode runs, mirroring the same single-slot "last bound" pattern GL's own context classes don't need (GL tracks a 42-entry array instead - this class only ever has one). */
};

#endif /* IOATIR5002DCONTEXT_H */
