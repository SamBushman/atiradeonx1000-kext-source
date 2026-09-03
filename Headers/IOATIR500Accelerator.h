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
class IOMemoryDescriptor;
struct VendorTransferBuffer;
struct VendorCommandBuffer; /* real, distinct mangled type name (19VendorCommandBuffer) -
                              * NOT the same as VendorCommandBufferHeader (25 chars) already in
                              * ATIRadeonX1000Types.h; found this pass via allocCommandBuffer's
                              * real signature, layout not yet independently decompiled */

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

    /*
     * addTransferToGART - RESOLVED, issue #19/#23 (real vtable slot
     * +0x5a8, real addr 0x34b0). CORRECTED, issue #23: real signature
     * takes a `VendorTransferBuffer*` parameter (confirmed from this
     * function's own real decompile, which unconditionally dereferences
     * it) - this project's earlier transcription (issue #19) had it
     * taking no parameters. Real body delegates to `addToGART` below with
     * two derived values from the buffer. `ATIRadeonX1000`'s own override
     * (`ATIRadeonX1000.h`) calls this base version explicitly, then adds
     * its own extra bookkeeping.
     */
    virtual void addTransferToGART(VendorTransferBuffer *buffer);

    /*
     * addToGART - RESOLVED, issue #26 (real vtable slot +0x5a0, real addr
     * 0x5220 on this class, real name already present in the kext's own
     * symbol table). Real params: this class's own isolated decompile of
     * this function never references `this` inside its own trivial body,
     * so Ghidra's own signature inference dropped it and named the next
     * two real registers `param_1`/`param_2` as if they were the first -
     * the real call site (`addTransferToGART`'s own body) confirms the
     * true 3-register shape is `(this, IOMemoryDescriptor *descriptor,
     * UInt32 *result)`, matching a real transfer buffer's own `+8`
     * (its IOMemoryDescriptor) and `+4` (an output slot) fields. Real
     * body is a single further delegating call, to a standard Apple
     * `IOMemoryDescriptor` vtable slot (`+0x590` on `descriptor`) - a
     * real, well-known Apple base class this project doesn't
     * reverse-engineer; own real target/role not identified (would
     * require the real IOKit `IOMemoryDescriptor` vtable layout for this
     * OS/architecture, an external fact, not something recoverable from
     * this binary alone).
     *
     * SETTLES issue #26's own real question: this function, and its own
     * one real subclass override (`ATIRadeonX1000::addToGART`,
     * `ATIRadeonX1000.h` - a trivial pass-through with no added logic),
     * are BOTH genuinely `void` - neither ever sets a real return value
     * in its own decompiled control flow. This is strong (not airtight -
     * the deeper `IOMemoryDescriptor+0x590` call's own real behavior is
     * still unknown) confirmation that `addTransferToGART`'s own
     * previously-captured "return value" was a real calling-convention
     * artifact, not a meaningful signal - the conservative unconditional
     * fix already applied to `map_transfer_to_GART`
     * (`IOATIR500GLContext_TextureStream.cpp`) is the correct final
     * answer, not just a placeholder.
     */
    virtual void addToGART(IOMemoryDescriptor *descriptor, UInt32 *result);

    /* allocOneDataBuffer / freeOneDataBuffer / allocDataBufferBacking -
     * CONFIRMED to exist and be real (every context's get_data_buffer
     * calls these), signatures INFERRED from call-site shape. */
    VendorTextureBuffer *allocOneDataBuffer(UInt32 sizeClass, bool forWrite);
    void                 freeOneDataBuffer(VendorTextureBuffer *buffer);
    bool                 allocDataBufferBacking(VendorTextureBuffer *buffer);

    /*
     * pageOffDataBuffer - CONFIRMED real name (real mangled class-qualified
     * decompile, found this pass - issue #23 - as a real call site in
     * `ATIRadeonX1000::deallocate_texture`'s own body,
     * `Sources/ATIRadeonX1000_TextureVRAM.cpp`). Own body not
     * independently decompiled this pass; real signature INFERRED from
     * that one real call site's own shape.
     */
    void pageOffDataBuffer(VendorTextureBuffer *buffer);

    /* find_surface_for_id - CONFIRMED real name (IOATIR500GLContext::
     * get_surface_info calls it), signature INFERRED. */
    void *find_surface_for_id(UInt32 surfaceID);

    /*
     * freeToAllocTextureVRAM - CONFIRMED real name/signature (real
     * mangled symbol __ZN20IOATIR500Accelerator22freeToAllocTextureVRAMEP16IOATIR500SurfacePP19VendorTextureBufferlS3_),
     * found this pass as a real call site in ATIR500GLContext::
     * alloc_and_load_texture / compact_current_textures (issue #5) -
     * see Sources/ATIR500GLContext_TextureLoad.cpp. Own body NOT
     * independently decompiled this pass.
     */
    UInt32 freeToAllocTextureVRAM(IOATIR500Surface *surface, VendorTextureBuffer **excludeList,
                                   SInt32 excludeCount, VendorTextureBuffer *needed);

    /*
     * getVRAMDescriptors / allocCommandBuffer - CONFIRMED real names and
     * to be real methods of this class (both are real, mangled, exported
     * symbols - __ZN20IOATIR500Accelerator18getVRAMDescriptorsEv at kext
     * offset 0x4d20, __ZN20IOATIR500Accelerator18allocCommandBufferEP19VendorCommandBufferm
     * at 0x23e0), found this pass as real call sites in
     * IOATIR500GLContext::start (see IOATIR500GLContext.h). Signatures
     * INFERRED from that one call site
     * (`getVRAMDescriptors(accel)`, `allocCommandBuffer(accel, &this[0xcc], 0x20000)`);
     * neither has been independently decompiled itself.
     */
    bool getVRAMDescriptors(void);
    bool allocCommandBuffer(VendorCommandBuffer *outBuffer, UInt32 size);

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
    IOATIR500GLContext  *liveGLContextListHead;  /* +0x60, CONFIRMED this pass: IOATIR500GLContext::start's
                                                    * real decompile does `piVar4[0x18] = this` on the accelerator
                                                    * pointer (piVar4 = *(int**)(this+200)), i.e. accelerator+0x60
                                                    * word-indexed - an independent, direct confirmation of this
                                                    * offset from the writer side, not just freeWaitToAllocGART's
                                                    * reader side. See IOATIR500GLContext.h's start() note. */
    IOATIR500Surface    *liveSurfaceListHead;    /* +0x5c, INFERRED offset */

    /*
     * newUserClient's four real vtable-dispatched factory slots -
     * RESOLVED, issue #6. Both the names/roles (already solid before this
     * pass - type 0/+0x5d4 = Surface, CONFIRMED via a real
     * IOServiceOpen(...,0,...) call site; type 1/+0x5e0 = GL, CONFIRMED
     * the same way; type 2/+0x5d8 = 2D and type 3/+0x5dc = DVD, INFERRED
     * by elimination) AND the four words' raw numeric CONTENTS (this
     * pass's own find) are now real.
     *
     * The key correction: every earlier attempt at the raw values (see
     * issue #6's own investigation history) read these four words off
     * `IOATIR500Accelerator`'s OWN vtable (`__ZTV20IOATIR500Accelerator`,
     * file-verified at `0x46970`) and confirmed, with hard data, that
     * THAT copy is genuine linker placeholder content (`GENERIC_RELOC_VANILLA`,
     * non-scattered, non-external; raw file bytes are 0; the same values
     * repeat with a ~0x668-byte period across many other slots) - true,
     * but beside the point, because no real object in this driver is ever
     * a bare `IOATIR500Accelerator`. Every real instance is the concrete
     * `ATIRadeonX1000` subclass (this header's own top comment), which
     * has its OWN real vtable - `__ZTV14ATIRadeonX1000`, file-verified at
     * `0x491c8` - and DOES locally override all four slots there. Reading
     * that vtable directly (same zero-shift addressing convention already
     * confirmed for the base) gives real, non-zero, meaningful values:
     *
     *   +0x5d4 -> 0x1a140 -> `ATIRadeonX1000::new_surface(void)`
     *   +0x5d8 -> 0x1a220 -> `ATIRadeonX1000::new_2d_context(void)`
     *   +0x5dc -> 0x1a290 -> `ATIRadeonX1000::new_dvd_context(void)`
     *   +0x5e0 -> 0x1a1b0 -> `ATIRadeonX1000::new_gl_context(void)`
     *
     * These are REAL mangled names already present in the kext's own
     * symbol table (`__ZN14ATIRadeonX100011new_surfaceEv` etc.) - not
     * invented - and their roles match this project's existing
     * INFERRED-by-elimination ordering exactly (Surface/2D/DVD/GL at
     * +0x5d4/+0x5d8/+0x5dc/+0x5e0 respectively), which independently
     * CONFIRMS that ordering was correct all along.
     *
     * RENAMED here (issue #21) from this project's own earlier invented
     * placeholder names (`createSurfaceContext`/`create2DContext`/
     * `createDVDContext`/`createGLContext`) to the real names below - a
     * real C++ override must share its base virtual's exact name (only
     * the return type may covary), so once `ATIRadeonX1000`'s real
     * override names were known (`new_surface` etc., `ATIRadeonX1000.h`),
     * keeping the old invented names here would have made the two
     * declarations two unrelated functions instead of a real override
     * pair. This class's own copy of each slot is genuine placeholder
     * content (raw 0, issue #6) - no local body to decompile here, only
     * the interface declaration.
     */
    virtual IOUserClient *new_surface(void);     /* type 0, +0x5d4 - real override: ATIRadeonX1000::new_surface (covariant return ATIR500Surface*), see ATIRadeonX1000.h */
    virtual IOUserClient *new_2d_context(void);  /* type 2, +0x5d8 - real override: ATIRadeonX1000::new_2d_context (covariant return ATIR5002DContext*), see ATIRadeonX1000.h */
    virtual IOUserClient *new_dvd_context(void); /* type 3, +0x5dc - real override: ATIRadeonX1000::new_dvd_context (covariant return ATIR500DVDContext*), see ATIRadeonX1000.h */
    virtual IOUserClient *new_gl_context(void);  /* type 1, +0x5e0 - real override: ATIRadeonX1000::new_gl_context (covariant return ATIR500GLContext*), see ATIRadeonX1000.h */

    /*
     * setup3D - RESOLVED, issue #19/#23 (real vtable slot +0x530, real
     * addr 0x2610). Declared HERE, not on `ATIRadeonX1000.h` as issue
     * #19 originally had it - CORRECTED, issue #23: this class's own
     * vtable and `ATIRadeonX1000`'s own vtable have the IDENTICAL
     * address at this slot, meaning it is genuinely NOT overridden by
     * the subclass, only declared/implemented here on the base. Real
     * body: a single real call, `allocMoreCommandBuffers(this, 0,
     * 0x20000)` - a new, previously-unknown real function this project
     * hasn't investigated (own body not decompiled this pass).
     */
    virtual UInt32 setup3D(void);
};

#endif /* IOATIR500ACCELERATOR_H */
