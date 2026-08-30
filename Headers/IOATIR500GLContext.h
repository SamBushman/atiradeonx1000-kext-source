/*
 * IOATIR500GLContext.h
 *
 * The base GL user-client class - implements the 20 regular external
 * methods (selectors 0-19). The 3D-specific subclass, ATIR500GLContext,
 * adds the 21st (special) selector plus all real 3D-pipeline behavior.
 *
 * The regular/subclass split, and every method name and selector number
 * below, is CONFIRMED directly from raw kext bytes this project read this
 * session: IOATIR500GLContext::start(IOService*)::methodDescs (kext offset
 * 0x47618), a real static 20-entry table, each entry
 * {target=0(patched live), flags=0xffff, function, count0, count1, count2}.
 * See stage5-iouserclient-external-method-api-complete.md for the full
 * dump this table is transcribed from.
 *
 * Confidence: CONFIRMED for names/selectors/argument counts. Method BODIES
 * for the ones not directly quoted in this project's stage docs are
 * INFERRED from decompiled shape (see Sources/IOATIR500GLContext.cpp).
 */

#ifndef IOATIR500GLCONTEXT_H
#define IOATIR500GLCONTEXT_H

#include <IOKit/IOUserClient.h>
#include "ATIRadeonX1000Types.h"

class ATIRadeonX1000;
struct VendorTextureBuffer;
struct VendorTransferBuffer;

class IOATIR500GLContext : public IOUserClient {
    OSDeclareDefaultStructors(IOATIR500GLContext)

public:
    /* ---- The 20 real external methods, selectors 0-19 ---- */
    IOReturn set_surface(UInt32 surfaceID, UInt32 modeBits, UInt32 param3, UInt32 param4);          /* 0 */
    IOReturn set_swap_rect(SInt32 x, SInt32 y, SInt32 w, SInt32 h);                                    /* 1 */
    IOReturn set_swap_interval(SInt32 numerator, SInt32 denominator);                                  /* 2 */
    IOReturn get_config(UInt32 *out0, UInt32 *out1, UInt32 *out2);                                     /* 3 */
    IOReturn get_status(UInt32 *out0);                                                                 /* 4 */
    IOReturn get_surface_size(SInt32 *outW, SInt32 *outH, SInt32 *outX, SInt32 *outY);                 /* 5 */
    IOReturn get_surface_info(UInt32 surfaceID, SInt32 *outFlags, SInt32 *outW, SInt32 *outH);         /* 6 */
    IOReturn read_buffer(sIOGLContextReadBufferData *readData, UInt32 structSize);                     /* 7, variable struct-in size */
    IOReturn finish(void);                                                                             /* 8 */
    IOReturn wait_for_stamp(UInt32 stamp);                                                              /* 9 - CONFIRMED: the real fence-wait selector this project first found from the client side (stage3-fence-mechanism.md) */
    IOReturn new_texture(sIOGLNewTextureData *newTextureData, sIOGLNewTextureReturnData *returnData,
                         UInt32 structSize, UInt32 *sizeOut);                                          /* 10 */
    IOReturn delete_texture(UInt32 textureID);                                                          /* 11 */
    IOReturn become_global_shared(UInt32 makeShared);                                                   /* 12 */
    IOReturn page_off_texture(UInt32 textureID, UInt32 mipAndFace, UInt32 param3, UInt32 param4);       /* 13 */
    IOReturn scale_surface(UInt32 flags, UInt32 xScale, UInt32 yScale);                                 /* 14 */
    IOReturn purge_texture(UInt32 textureID);                                                            /* 15 */
    IOReturn set_surface_volatile_state(UInt32 state);                                                  /* 16 */
    IOReturn reclaim_resources(void);                                                                    /* 17 */
    IOReturn get_data_buffer(UInt32 *outHandle, UInt32 *outAddress);                                     /* 18 */
    IOReturn set_stereo(UInt32 leftOrRight, UInt32 param2);                                              /* 19 */

    /*
     * connectClient - CONFIRMED real behavior (kext offset 0x86d0). Only
     * succeeds if the caller's task* matches the object's own recorded
     * task*; on success, transfers a reference-counted handle
     * (`this+0x88`) from the connecting IOUserClient to this one under the
     * accelerator's command lock.
     */
    virtual IOReturn connectClient(IOUserClient *client) override;

    /*
     * clientMemoryForType - CONFIRMED real behavior (kext offset 0xa160).
     * type 0 returns the accelerator's shared clientMemoryDescriptorType0
     * (a fixed 0x1000-byte status/register region) and retains it via a
     * real vtable call; any other type is INFERRED to defer to a shared
     * helper (PTR_clientMemoryForType_00047558 in the raw decompile - an
     * indirect function pointer this project never resolved to a name).
     */
    virtual IOReturn clientMemoryForType(UInt32 type, UInt32 *options,
                                          IOMemoryDescriptor **memory) override;

    /*
     * add_texture_to_stream / remove_texture_from_stream / map_transfer_to_GART -
     * CONFIRMED to be real methods of THIS base class (real decompiled
     * signatures are `IOATIR500GLContext::`, not `ATIR500GLContext::` -
     * corrected from an earlier draft that had these on the subclass).
     * Fully reconstructed in Sources/IOATIR500GLContext_TextureStream.cpp.
     */
    void add_texture_to_stream(VendorTextureBuffer *texture);
    void remove_texture_from_stream(VendorTextureBuffer *texture);
    void map_transfer_to_GART(VendorTransferBuffer *buffer);

protected:
    ATIRadeonX1000 *accelerator;   /* +200 (0xc8), CONFIRMED: every method above reaches hardware exclusively through this pointer. CORRECTED to the concrete ATIRadeonX1000 type (was IOATIR500Accelerator*) - see ATIRadeonX1000.h's updated comment: context classes need chip-specific methods (submit_buffer, MMIO access) only declared on the concrete subclass. */
    void                  *clientHandle;  /* +0x88, CONFIRMED: the reference-counted handle connectClient transfers */
    /*
     * The regular external-method table pointer - CONFIRMED to exist at
     * this offset (ATIR500GLContext::getTargetAndMethodForIndex:
     * `return selector*0x18 + *(int*)(this+0x2a0);` for selector < 20).
     * UNKNOWN which function actually populates it (not
     * IOATIR500GLContext::start, which only sets the *subclass's* special
     * selector-20 slot at +0x360 - see ATIR500GLContext.h). Most likely a
     * base-class start()/init() this project never located precisely;
     * the real static table it points at IS fully known (methodDescs,
     * transcribed into Sources/IOATIR500GLContext_ExternalMethods.cpp).
     */
    void *regularMethodTable;             /* +0x2a0 */
};

#endif /* IOATIR500GLCONTEXT_H */
