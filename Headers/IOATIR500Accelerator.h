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

    /* allocOneDataBuffer / freeOneDataBuffer / allocDataBufferBacking -
     * CONFIRMED to exist and be real (every context's get_data_buffer
     * calls these), signatures INFERRED from call-site shape. */
    VendorTextureBuffer *allocOneDataBuffer(UInt32 sizeClass, bool forWrite);
    void                 freeOneDataBuffer(VendorTextureBuffer *buffer);
    bool                 allocDataBufferBacking(VendorTextureBuffer *buffer);

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
     * newUserClient's four real vtable-dispatched factory slots. Real
     * offsets confirmed from the decompile (`*(int*)this + 0x5d4/0x5d8/
     * 0x5dc/0x5e0`), and NAMES/PURPOSE are effectively resolved (see
     * newUserClient's own comment above: type 0/+0x5d4 = Surface context,
     * CONFIRMED via a real IOServiceOpen(...,0,...) call site; type 1/
     * +0x5e0 = GL context, CONFIRMED the same way; type 2/+0x5d8 = 2D and
     * type 3/+0x5dc = DVD, both INFERRED by elimination). This is real,
     * independent, high-confidence evidence that does NOT depend on
     * decoding the vtable's own raw relocations at all - it comes from
     * matching real userspace client call sites (`_gldCreateContext`,
     * `_gldAttachDrawable`) against the real `type` values they pass.
     *
     * The vtable *addresses* are also pinned down precisely: `IOATIR500Accelerator::vtable`/
     * `__ZTV20IOATIR500Accelerator` sits at file-verified address 0x46970
     * in `__TEXT,__const`, and the constructor's own decompile
     * (`*(undefined **)this = &vtable;`) confirms zero Itanium-style
     * offset-to-top/RTTI shift - `this->vtable + 0x5d4` etc. is exactly
     * right as-is.
     *
     * What's STILL genuinely unresolved is only the four words' raw
     * numeric CONTENTS (the actual compiled function pointer values) -
     * lower-value information at this point, since the real names/roles
     * above are already solid and a numeric value can't be verified
     * without a real compile+link anyway (issue #1's standing gap).
     * Investigated exhaustively this pass with a real Ghidra headless
     * script parsing the raw Mach-O structures directly (not just the
     * higher-level analyzed Program) - ruling out every hypothesis tried
     * so far, each confirmed with hard data, not assumption:
     *   - NOT `PPC_RELOC_LOCAL_SECTDIFF` (type 15, scattered) as
     *     originally logged - the real raw relocation_info entries at
     *     these four addresses are type 0 (`GENERIC_RELOC_VANILLA`),
     *     `r_scattered=0`, `r_extern=0`.
     *   - NOT a plain absolute address - the raw `r_symbolnum` values
     *     (0x4ae50 for +0x5d4/+0x5d8, 0x140 for +0x5dc) don't point to
     *     real functions when read as VM addresses (0x4ae50 lands mid-way
     *     through `_Mode1112Table`, an unrelated video-mode data table;
     *     0x140 lands inside this class's own `~IOATIR500Accelerator`
     *     destructor, at +0x20 into it).
     *   - NOT a section ordinal (the spec-mandated meaning of
     *     `r_symbolnum` when `r_extern=0`) - this binary has only 10
     *     real sections total, ruling out values in the hundreds of
     *     thousands.
     *   - NOT a symbol-table index either, despite `r_extern=0` reading
     *     as a false negative being considered - most values (0x4ae50,
     *     0x37e50, etc.) exceed the real symbol count (1215) outright;
     *     the one that happened to be in-bounds (0x140 -> index 320)
     *     resolved to an unrelated symbol, almost certainly coincidental
     *     rather than a real pattern (spot-checked against several other
     *     values from the same relocation run, all out of bounds).
     *   - There is no separate `LC_DYSYMTAB` local/external relocation
     *     table to fall back to (confirmed absent) - the per-section
     *     `reloff`/`nreloc` table already used is genuinely the only one
     *     in this file, for both `RelocationInfo` reads and this
     *     project's own manual raw-byte reads (which agree byte-for-byte
     *     with Ghidra's parse, ruling out a parsing bug too).
     *   - The raw FILE BYTES at all four addresses are genuinely 0 (not
     *     just Ghidra's in-memory zeroing after a skipped relocation) -
     *     confirmed by reading the file directly, bypassing the analyzed
     *     Program entirely. Contrast with e.g. `ATIR500GLContext::start`'s
     *     own vtable slot, which has a real, correct, unrelocated literal
     *     value stored directly in the file (no relocation entry at all
     *     needed) - proving some slots ARE resolvable this way and these
     *     four specifically are not, for a real reason still unknown.
     *   - The four raw values also repeat with a ~0x668-byte period
     *     across a much wider span of the vtable than just these four
     *     slots (many OTHER inherited-but-unoverridden slots show the
     *     same handful of recurring values) - consistent with these
     *     being genuine placeholder/scratch content the static linker
     *     left behind for slots requiring load-time patching, rather
     *     than a value this project is failing to decode correctly.
     * Leading hypothesis, NOT confirmed: these four slots (along with
     * the many others sharing the same recurring placeholder values) are
     * inherited from `IOAccelerator`/`IOService`/`OSObject` and were
     * never locally overridden in the object file the compiler saw for
     * THIS particular build unit - meaning their real addresses may only
     * ever have existed via Apple's kext-load-time "vtable patching"
     * mechanism (`kxld`/`kld` matching against the actual running
     * kernel's own symbol table), not anywhere in this static file at
     * all. If true, no amount of further static analysis of this file
     * alone can recover the real numeric values - only a live
     * kxld-relocated memory read on real Tiger/Leopard hardware could.
     * See issue #6 for the full investigation, including the raw
     * relocation-table evidence for each ruled-out hypothesis.
     */
    virtual IOUserClient *createSurfaceContext(void); /* type 0, +0x5d4 - CONFIRMED real purpose (real IOServiceOpen(...,0,...) call site), real name/signature INFERRED */
    virtual IOUserClient *create2DContext(void);      /* type 2, +0x5d8 - INFERRED by elimination */
    virtual IOUserClient *createDVDContext(void);     /* type 3, +0x5dc - INFERRED by elimination */
    virtual IOUserClient *createGLContext(void);      /* type 1, +0x5e0 - CONFIRMED real purpose (real IOServiceOpen(...,1,...) call site), real name/signature INFERRED */
};

#endif /* IOATIR500ACCELERATOR_H */
