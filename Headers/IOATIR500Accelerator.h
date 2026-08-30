/*
 * IOATIR500Accelerator.h
 *
 * The generic accelerator-family base class - real IOService subclass
 * (CONFIRMED: `OSBundleLibraries` in the real kext Info.plist lists only
 * IOGraphicsFamily/IONDRVSupport/IOPCIFamily, not IOAcceleratorFamily, so
 * this is plain `IOService`, not some later framework's base class).
 * `ATIRadeonX1000` (ATIRadeonX1000.h) is its real, concrete, chip-specific
 * subclass and the actual `IOClass` IOKit instantiates - see that header's
 * updated comment for how this project learned that. Implements
 * newUserClient's real type dispatch and the cross-context GART pool
 * arbitration every context class ultimately shares.
 *
 * Confidence: CONFIRMED unless marked otherwise. See ../README.md.
 */

#ifndef IOATIR500ACCELERATOR_H
#define IOATIR500ACCELERATOR_H

#include <IOKit/IOService.h>

class ATIRadeonX1000;
class IOATIR5002DContext;
class IOATIR500DVDContext;
class IOATIR500GLContext;
class IOATIR500Surface;
class IOATIR500Shared;
struct VendorTransferBuffer;

class IOATIR500Accelerator : public IOService {
    OSDeclareDefaultStructors(IOATIR500Accelerator)

public:
    /*
     * newUserClient - CONFIRMED real dispatcher for IOServiceOpen(...,
     * type, ...). Real decoded switch (see
     * stage5-iouserclient-external-method-api-complete.md):
     *
     *   type == 1  -> vtable+0x5e0  -> CONFIRMED: constructs the GL
     *                                  context (ATIR500GLContext),
     *                                  confirmed via a real
     *                                  IOServiceOpen(...,1,...) call site
     *                                  in ATIRadeonX1000GLDriver.bundle's
     *                                  _gldCreateContext.
     *   type == 0  -> vtable+0x5d4  -> CONFIRMED: constructs the Surface
     *                                  context (ATIR500Surface), confirmed
     *                                  via _gldAttachDrawable's real
     *                                  IOServiceOpen(...,0,...) call site.
     *                                  Also does a distinct
     *                                  "IOUserClientCrossEndianCompatible"
     *                                  property dance not seen for the
     *                                  other three types.
     *   type == 2  -> vtable+0x5d8  -> INFERRED (by elimination): the 2D
     *                                  context (ATIR5002DContext). No
     *                                  real IOServiceOpen call site for
     *                                  type 2 was found in any of this
     *                                  project's four downloaded userspace
     *                                  binaries - the real caller is
     *                                  presumably WindowServer, which was
     *                                  never decompiled.
     *   type == 3  -> vtable+0x5dc  -> INFERRED (by elimination): the DVD
     *                                  context (ATIR500DVDContext). Same
     *                                  caveat - the real caller is
     *                                  presumably DVD Player/QuickTime,
     *                                  never decompiled.
     *   anything else -> kIOReturnBadArgument (0xe00002c2)
     *
     * Every successful path tags the new client with the caller's task*,
     * then calls three more real vtable methods on it (`open`, then two
     * initialization steps at vtable+0x150/+0x3a4/+0x348 in the decompile) -
     * exact virtual-method names for those three UNKNOWN (referenced only
     * by vtable slot in the decompile, never independently named).
     */
    virtual IOReturn newUserClient(task *owningTask, void *securityID, UInt32 type,
                                    IOUserClient **handler) override;

    /*
     * freeToAllocGART / freeWaitToAllocGART - CONFIRMED, fully decoded
     * (stage9-gl-remaining-methods-gart-pool-power-interrupts.md). A real,
     * two-pass (gentle then aggressive) global GART reclamation sweep:
     * every live 2D/DVD/GL context and its IOATIR500Shared allocator,
     * every live Surface, the two cached free-transfer-buffer power-of-two
     * ring pools, then finally the caller's own associated
     * contexts/buffer. GART space is a single shared pool across every
     * context in the system, not per-context isolated.
     */
    bool freeToAllocGART(IOATIR5002DContext *exclude2D, IOATIR500DVDContext *excludeDVD,
                          IOATIR500GLContext *excludeGL, IOATIR500Surface *excludeSurface,
                          IOATIR500Shared *excludeShared, VendorTransferBuffer *needed);
    bool freeWaitToAllocGART(IOATIR5002DContext *exclude2D, IOATIR500DVDContext *excludeDVD,
                              IOATIR500GLContext *excludeGL, IOATIR500Surface *excludeSurface,
                              IOATIR500Shared *excludeShared, VendorTransferBuffer *needed,
                              bool aggressive);

    /* allocOneDataBuffer / freeOneDataBuffer / allocDataBufferBacking -
     * CONFIRMED to exist and be real (every context's get_data_buffer
     * calls these), signatures INFERRED from call-site shape. */
    VendorTextureBuffer *allocOneDataBuffer(UInt32 sizeClass, bool forWrite);
    void                 freeOneDataBuffer(VendorTextureBuffer *buffer);
    bool                 allocDataBufferBacking(VendorTextureBuffer *buffer);

    /* find_surface_for_id - CONFIRMED real name (IOATIR500GLContext::
     * get_surface_info calls it), signature INFERRED. */
    void *find_surface_for_id(UInt32 surfaceID);

    /* setup_stereo - CONFIRMED real name (IOATIR500GLContext::set_stereo
     * calls it), signature INFERRED. */
    IOReturn setup_stereo(UInt32 param1, UInt32 param2);

    /* freeOrphanTexture - CONFIRMED real name, called from both
     * garbage_collector and freeWaitToAllocGART. */
    void freeOrphanTexture(bool aggressive);

private:
    /*
     * Real linked-list heads for each live context type - CONFIRMED to
     * exist (freeWaitToAllocGART walks all three via
     * `*(T**)(this+N)` / `next = *(T**)(ctx+0x80)` chains), exact base
     * offsets INFERRED from the decompile's own literal constants.
     */
    IOATIR5002DContext  *live2DContextListHead;  /* +0x64, INFERRED offset */
    IOATIR500DVDContext *liveDVDContextListHead; /* +0x68, INFERRED offset */
    IOATIR500GLContext  *liveGLContextListHead;  /* +0x60, INFERRED offset */
    IOATIR500Surface    *liveSurfaceListHead;    /* +0x5c, INFERRED offset */

    /*
     * newUserClient's four real vtable-dispatched factory slots. Real
     * offsets confirmed from the decompile (`*(int*)this + 0x5d4/0x5d8/
     * 0x5dc/0x5e0`); this project could not read their actual targets.
     *
     * CONFIRMED this pass (live access to the real kext binary via the
     * G5, cross-checked with nm/otool/Ghidra together): the vtable base
     * itself is real and unambiguous - `IOATIR500Accelerator::vtable` /
     * `__ZTV20IOATIR500Accelerator` sits at file-verified address
     * 0x46970 in `__TEXT,__const`, and the constructor's own decompile
     * (`*(undefined **)this = &vtable;`) confirms this class's vtable
     * pointer has NO Itanium-style offset-to-top/RTTI header skip - the
     * `this->vtable + 0x5d4` addressing this project already used is
     * exactly right, zero shift. So the four target *addresses* (0x46f44/
     * 0x46f48/0x46f4c/0x46f50) are pinned down precisely; only their
     * *contents* remain unknown.
     *
     * Those four words are still genuinely unresolved, and for a more
     * specific reason than originally logged: Ghidra's relocation table
     * marks them SKIPPED and substitutes a placeholder that traces to
     * unrelated `_ModeNNTable` video-mode data, not a real function -
     * i.e. Ghidra's "reads as zero" really means "could not resolve",
     * not that the linked value is zero. `otool -rv` (without full
     * scattered-pair decoding) separately misreads the same words as
     * plain external refs to `__cxa_pure_virtual`, which can't be
     * literally true (this dispatch path returns real working contexts
     * on real hardware) - almost certainly a scattered relocation PAIR
     * being read as a simple entry. Closing this for real needs either
     * a hand decode of the raw `scattered_relocation_info` struct pairs
     * at this address, or a live kxld-relocated memory read on hardware.
     * See issue #6 for the full investigation.
     */
    // UNKNOWN: virtual createSurfaceContext(...)  at vtable+0x5d4
    // UNKNOWN: virtual create2DContext(...)       at vtable+0x5d8
    // UNKNOWN: virtual createDVDContext(...)      at vtable+0x5dc
    // UNKNOWN: virtual createGLContext(...)       at vtable+0x5e0
};

#endif /* IOATIR500ACCELERATOR_H */
