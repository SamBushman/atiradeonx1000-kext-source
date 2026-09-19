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

struct IOSurfacePagingControlInfoStruct;   /* real struct names (they appear in the mangled symbols); layouts never recovered */
struct IOSurfaceVsyncControlInfoStruct;

class IOATIR5002DContext : public IOUserClient {
    OSDeclareAbstractStructors(IOATIR5002DContext)

public:
    /*
     * Virtual slots, in the stock vtable's own order (Ledger/kext_ppc_vtables.txt: start +0x348, stop +0x34c,
     * clientClose +0x568, clientMemoryForType +0x580, then the five pure slots +0x5a4..+0x5b4 that
     * ATIR5002DContext overrides).
     */
    virtual bool     start(IOService *provider) override;                                              /* +0x348, real addr 0xc0a0 */
    virtual void     stop(IOService *provider) override;                                               /* +0x34c, real addr 0xb7f0 */
    virtual IOReturn clientClose() override;                                                           /* +0x568, real addr 0xba30 */
    virtual IOReturn clientMemoryForType(UInt32 type, UInt32 *options, IOMemoryDescriptor **memory) override; /* +0x580, real addr 0xd6f0 */
    virtual void     invalidate() = 0;                                                                 /* +0x5a4 */
    virtual void     submit_context_buffer() = 0;                                                      /* +0x5a8 */
    virtual IOReturn process_command_buffer(VendorCommandDescriptor *descriptor) = 0;                  /* +0x5ac */
    virtual IOReturn set_destination(void *info, UInt32 *infoSize) = 0;                               /* +0x5b0 */
    virtual IOReturn get_buffer_info(IOATIR500Surface *surface, UInt32 index, void *info, UInt32 *infoSize) = 0; /* +0x5b4 */

    /* ---- Base table, selectors 0-15 (Sources/IOATIR5002DContext_MethodTables.cpp). Every signature below is the
     * exact stock mangling (the eIOContextModeBits enum, `unsigned int*` vs `unsigned long*` outputs, and the two
     * option-struct pointers all appear in the symbols). ---- */
    IOReturn set_surface(UInt32 surfaceID, eIOContextModeBits modeBits, void *info, UInt32 *infoSize);      /* 0, real addr 0xc570 */
    IOReturn get_config(UInt32 *out0, UInt32 *out1);                                                        /* 1, real addr 0xbd90 */
    IOReturn get_surface_info(UInt32 surfaceID, eIOContextModeBits modeBits, void *info, UInt32 *infoSize); /* 2, real addr 0xc850 */
    IOReturn swap_surface(UInt32 lockType, UInt32 *outTag);                                                 /* 3, real addr 0xc960 */
    IOReturn scale_surface(UInt32 flags, UInt32 xScale, UInt32 yScale);                                     /* 4, real addr 0xcb90 */
    IOReturn lock_memory(UInt32 lockType, unsigned int *outAddress, UInt32 *outSize);                        /* 5, real addr 0xcc80 */
    IOReturn unlock_memory(UInt32 lockType, UInt32 *outTag);                                                 /* 6, real addr 0xcf30 */
    IOReturn finish(UInt32 mode);                                                                            /* 7, real addr 0xbdc0 */
    IOReturn declare_image(UInt32 param1, unsigned int formatOrSize, UInt32 sizeInBytes, unsigned int *outHandle); /* 8, real addr 0xd020 */
    IOReturn create_image(UInt32 param1, UInt32 param2, unsigned int *outLow, unsigned int *outHigh);       /* 9, real addr 0xd130 */
    IOReturn create_transfer(UInt32 param1, UInt32 sizeInBytes, unsigned int *outHandle, unsigned int *outAddress); /* 10, real addr 0xd260 */
    IOReturn delete_image(UInt32 textureID);                                                                 /* 11, real addr 0xd450 */
    IOReturn wait_image(UInt32 textureID);                                                                   /* 12, real addr 0xd5c0 */
    IOReturn set_surface_paging_options(IOSurfacePagingControlInfoStruct *in, IOSurfacePagingControlInfoStruct *out,
                                        UInt32 structSize, UInt32 *outTag);                                  /* 13, real addr 0xc2c0: returns kIOReturnUnsupported */
    IOReturn set_surface_vsync_options(IOSurfaceVsyncControlInfoStruct *in, IOSurfaceVsyncControlInfoStruct *out,
                                       UInt32 structSize, UInt32 *outTag);                                   /* 14, real addr 0xc2d0: returns kIOReturnUnsupported */
    IOReturn set_macrovision(UInt32 enable);                                                                 /* 15, real addr 0xc2e0 */

    void     remove_surface(void);  /* real addr 0xbb30: clears the bound-surface pointer (+0x100) */
    bool     create_shared(void);                                                                        /* helper, real addr 0xbc90: new IOATIR500Shared + init, wired to the accelerator and task */
    void     init_command_buffer_header(VendorCommandBufferHeader *header, UInt32 size, UInt32 flags);   /* real addr 0xbab0 */

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
