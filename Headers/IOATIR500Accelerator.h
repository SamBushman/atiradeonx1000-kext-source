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
struct VendorCommandBufferHeader; /* real struct, defined in ATIRadeonX1000Types.h - forward-declared
                                     * here (build fixup, issue #1: this header uses it, and several
                                     * others below, pointer-only, without ever including that file) */
struct VendorTextureBuffer;       /* real struct, defined in ATIRadeonX1000Types.h - see above */
struct ATIR500SurfaceBuffer;      /* real struct, defined in ATIRadeonX1000Types.h - see above */
class IOTextureBuffer;            /* real, opaque Apple type - see IOATIR500Surface.h's own note */

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
     * freeTransferToAllocGART - RESOLVED (issue #1, get-it-linking
     * pass), real addr 0x3580. The real per-candidate leaf of the whole
     * GART-reclaim sweep: bails (returns 0) if `candidate` has no real
     * backing descriptor (`+4`==0) or is still referenced by a live
     * stream (`+0xe`!=0); otherwise, in the non-aggressive pass, first
     * confirms via the already-established `+0x554` slot that the
     * candidate is really free before touching it (aggressive pass
     * skips this check and instead accumulates a real freed-byte-count
     * stat at `this+0x790` via the already-named `waitForTimeStamp`
     * `+0x54c` slot - HONEST FLAG: that slot's real argument is dropped
     * entirely in this specific real decompile, transcribed as `0`),
     * then unconditionally unmaps `candidate` (`removeTransferFromGART`,
     * already established) and maps `needed` in its place
     * (`addTransferToGART`, already established). RETURN TYPE CORRECTED
     * to `bool`: the real decompile propagates `addTransferToGART`'s own
     * "return value" as this function's result, but `addTransferToGART`
     * is already CONFIRMED real `void` - the same real Ghidra return-
     * value-dropped artifact this project already documents elsewhere
     * (e.g. `allocVendorTextureBuffer`). Since every step up to that
     * final call already succeeded by the time it runs, `true` is the
     * correct, honest transcription of the intended value.
     */
    bool freeTransferToAllocGART(VendorTransferBuffer *candidate, VendorTransferBuffer *needed,
                                  UInt32 arg, bool aggressive);

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

    /*
     * allocOneDataBuffer / freeOneDataBuffer - RESOLVED, including the
     * real identity of every vtable call each makes. An earlier pass
     * this same session reported a real anomaly here (subclass vtable
     * read for `+0x570` appearing to give a non-matching signature) -
     * that was CORRECTED on a careful re-verification: it was a real
     * arithmetic slip in that pass's own by-hand row reading (misread a
     * table row 8 bytes/2 words off in two separate places), not a real
     * codebase issue. Freshly re-verified via direct `nm` cross-check on
     * every value (not by-hand hex row arithmetic) - all four slots are
     * real, clean, exactly-matching-signature overrides on both the base
     * and the concrete `ATIRadeonX1000` subclass:
     *   `+0x56c` -> `alloc_surface_buffer(ATIR500SurfaceBuffer*)` (a
     *     real, DIFFERENT function from the already-resolved
     *     `ATIR500Surface::alloc_surface_buffer`, issue #22 - same name,
     *     different real class; NOT overridden by the subclass - base
     *     and subclass vtables hold the identical address)
     *   `+0x570` -> `allocVendorTextureBuffer(unsigned long)` (real
     *     subclass override, different real address, identical
     *     signature)
     *   `+0x574` -> `releaseVendorTextureBuffer(VendorTextureBuffer*,
     *     unsigned long)` (real subclass override, identical signature)
     *   `+0x5ac` -> `removeTransferFromGART(VendorTransferBuffer*)`
     *     (real subclass override, identical signature - this project's
     *     own PRIOR draft of this comment mislabeled this slot
     *     `makeGARTEntry`, the SAME kind of by-hand row-reading slip -
     *     also corrected)
     * See Sources/IOATIR500Accelerator_DataBufferPool.cpp for the now
     * cleanly-named call sites.
     */
    VendorTextureBuffer *allocOneDataBuffer(UInt32 sizeClass, bool forWrite);
    void                 freeOneDataBuffer(VendorTextureBuffer *buffer);
    virtual SInt32 alloc_surface_buffer(ATIR500SurfaceBuffer *buffer); /* +0x56c - real, DIFFERENT function from ATIR500Surface::alloc_surface_buffer (issue #22); real return type confirmed SInt32 status from its own call site in setup_stereo; NOT overridden by ATIRadeonX1000 (identical address on both vtables) */
    virtual VendorTextureBuffer *allocVendorTextureBuffer(UInt32 size); /* +0x570 - real subclass override, different address */
    virtual void                 releaseVendorTextureBuffer(VendorTextureBuffer *buffer, UInt32 size); /* +0x574 - real subclass override, different address */
    virtual void                 removeTransferFromGART(VendorTransferBuffer *buffer); /* +0x5ac - real subclass override, different address */
    /*
     * allocate_texture / waitForTimeStamp - REAL MISSING-DECLARATION BUG
     * FIXED, issue #34 sweep: the SAME "pre-existing inconsistency" class
     * as `deallocate_texture` below - `Sources/
     * IOATIR500Accelerator_OneDataBuffer.cpp`'s own `allocOneDataBuffer`/
     * `freeOneDataBuffer` bodies (an `IOATIR500Accelerator::` method)
     * already called both of these completely unqualified, which only
     * compiles as real virtual dispatch if THIS base class declares them
     * - it never did (only `ATIRadeonX1000.h`'s subclass declaration
     * existed). Added here to match; signatures/addresses per that
     * subclass declaration (`+0x528`/`+0x54c`).
     */
    virtual IOReturn allocate_texture(VendorTextureBuffer *texture) = 0; /* +0x528 FIXED (issue #1, get-it-linking pass): declared pure virtual - this base class's own vtable slot is confirmed genuine placeholder content (no real base body exists to decompile; every real object is the concrete ATIRadeonX1000 subclass, which already has a real, committed override) - `= 0` is the correct C++ representation of that already-established fact, not a guess. */
    virtual UInt32   waitForTimeStamp(UInt32 tag) = 0;                  /* +0x54c FIXED (issue #1, get-it-linking pass): declared pure virtual - this base class's own vtable slot is confirmed genuine placeholder content (no real base body exists to decompile; every real object is the concrete ATIRadeonX1000 subclass, which already has a real, committed override) - `= 0` is the correct C++ representation of that already-established fact, not a guess. */

    /*
     * allocDataBufferBacking - RESOLVED. Real body: allocates via
     * `IOBufferMemoryDescriptor::inTaskWithOptions` (RESOLVED, this pass,
     * via live kxld-resolved memory read), stores the result at the
     * buffer's own `memoryDescriptor` field. See
     * Sources/IOATIR500Accelerator_DataBufferPool.cpp.
     */
    bool                 allocDataBufferBacking(VendorTextureBuffer *buffer);

    /*
     * deallocate_texture - RESOLVED, issue #28 addendum: a real,
     * pre-existing inconsistency caught while wiring in
     * `pageOffDataBuffer` below. `ATIRadeonX1000.h`'s own declaration
     * comment already claimed "the base class declares the virtual", but
     * this declaration never actually existed here - `pageOffDataBuffer`
     * calls it through a base-typed `this` (raw vtable-offset cast on
     * `IOATIR500Accelerator*`), which only works as real virtual dispatch
     * if the base actually declares it. Added here to match
     * `ATIRadeonX1000::deallocate_texture`'s own real override signature.
     */
    virtual void deallocate_texture(VendorTextureBuffer *texture) = 0; /* +0x524 FIXED (issue #1, get-it-linking pass): declared pure virtual - this base class's own vtable slot is confirmed genuine placeholder content (no real base body exists to decompile; every real object is the concrete ATIRadeonX1000 subclass, which already has a real, committed override) - `= 0` is the correct C++ representation of that already-established fact, not a guess. */

    /*
     * pageOffDataBuffer - RESOLVED, issue #28. Real mangled symbol
     * __ZN20IOATIR500Accelerator17pageOffDataBufferEP19VendorTextureBuffer,
     * real addr 0x3140. Real body: tries `allocDataBufferBacking`; on
     * failure, falls back to `deallocate_texture` (virtual dispatch,
     * base-typed - see above) instead. On success: calls this object's
     * own already-known `+0x524`... texture unbind via
     * `freeOneDataBuffer`-adjacent list splice (uses the SAME real
     * `+0x10` doubly-linked-list field pattern as other texture lists in
     * this project), then real GART-mapping prepare/get-info/release
     * sequence on the texture's own memoryDescriptor (`+0x08`) - the SAME
     * real `+0x14c`/`+0xd0`/`+0x18` vtable chain `load_texture` already
     * establishes - copying real per-word data from `this+0xe4`
     * (accelerator-owned) into the mapped hardware buffer, then splicing
     * the texture back into a real per-buffer list a second time with a
     * different real argument. See
     * `Sources/IOATIR500Accelerator_PageOffDataBuffer.cpp` for the full
     * transcription.
     */
    void pageOffDataBuffer(VendorTextureBuffer *buffer);

    /* find_surface_for_id - RESOLVED. Real body: a linear walk of the
     * live-surface circular list (`liveSurfaceListHead`, `+0x5c`),
     * matching each surface's own real `+0xa4` ID field (the same real
     * "ID slot" field `set_id_mode` establishes) - see
     * Sources/IOATIR500Accelerator_DataBufferPool.cpp. */
    void *find_surface_for_id(UInt32 surfaceID);

    /*
     * freeToAllocTextureVRAM - CONFIRMED real name/signature (real
     * mangled symbol __ZN20IOATIR500Accelerator22freeToAllocTextureVRAMEP16IOATIR500SurfacePP19VendorTextureBufferlS3_),
     * found this pass as a real call site in ATIR500GLContext::
     * alloc_and_load_texture / compact_current_textures (issue #5) -
     * see Sources/ATIR500GLContext_TextureLoad.cpp. Own body RESOLVED,
     * issue #31 - see Sources/IOATIR500Accelerator_VRAMReclaim.cpp.
     */
    UInt32 freeToAllocTextureVRAM(IOATIR500Surface *surface, VendorTextureBuffer **excludeList,
                                   SInt32 excludeCount, VendorTextureBuffer *needed);

    /*
     * freeToAllocSurfaceVRAM / tossSurfacesForVRAM - CONFIRMED real
     * names/signatures via `nm` (real mangled symbols
     * __ZN20IOATIR500Accelerator22freeToAllocSurfaceVRAMEP16IOATIR500SurfaceS1_PP19VendorTextureBufferlP20ATIR500SurfaceBuffer /
     * __ZN20IOATIR500Accelerator19tossSurfacesForVRAMEP16IOATIR500SurfacePP19VendorTextureBufferlS3_b),
     * found this pass as `setup_stereo`'s own real fallback calls
     * (`Sources/IOATIR500Accelerator_SetupStereo.cpp` - that file's own
     * earlier placeholder declared `freeToAllocSurfaceVRAM` as a free
     * function taking an explicit accelerator pointer; fixed to call
     * through as a real member here). Own bodies RESOLVED, issue #31 -
     * see Sources/IOATIR500Accelerator_VRAMReclaim.cpp.
     */
    UInt32 freeToAllocSurfaceVRAM(IOATIR500Surface *excludeA, IOATIR500Surface *excludeB,
                                   VendorTextureBuffer **excludeList, SInt32 excludeCount, ATIR500SurfaceBuffer *needed);
    UInt32 tossSurfacesForVRAM(IOATIR500Surface *excludeSurface, VendorTextureBuffer **excludeList,
                                SInt32 excludeCount, VendorTextureBuffer *needed, bool skipExcludeCheck);

    /*
     * getVRAMDescriptors - RESOLVED. Real body: loops calling a real,
     * previously-unknown per-index local method, `getVRAMDescriptor`
     * (singular, real addr 0x290 - own body not decompiled this pass),
     * once per index up to `this+0xcc`'s own count; real success gate
     * checks that count and `this+0xe4` are both still nonzero
     * afterward. See Sources/IOATIR500Accelerator_DataBufferPool.cpp.
     */
    bool getVRAMDescriptors(void);
    UInt32 getVRAMDescriptor(UInt32 index); /* real addr 0x290, own body RESOLVED issue #31 - see Sources/IOATIR500Accelerator_DataBufferPool.cpp */

    /*
     * allocCommandBuffer - RESOLVED. Real body: allocates via
     * `IOBufferMemoryDescriptor::withOptions`, stores the requested size,
     * gets a real hardware-mappable header via vtable+0x1cc, then calls
     * a real, previously-unknown method, `init_command_buffer_header`
     * (own body not decompiled this pass). See
     * Sources/IOATIR500Accelerator_DataBufferPool.cpp.
     */
    bool allocCommandBuffer(VendorCommandBuffer *outBuffer, UInt32 size);
    void init_command_buffer_header(VendorCommandBufferHeader *header, UInt32 size); /* real name, own body RESOLVED issue #31 - see Sources/IOATIR500Accelerator_DataBufferPool.cpp */

    /*
     * freeCommandBuffer - RESOLVED, issue #28 (found decompiling
     * `allocMoreCommandBuffers`'s own rollback-on-failure path below).
     * Own body RESOLVED, issue #34 - see
     * Sources/ATIRadeonX1000_FreeCommandBuffer.cpp. NOTE: a real,
     * completely DIFFERENT, previously-untracked `IOATIR500GLContext::
     * freeCommandBuffer()` (no arguments) also exists - see
     * Headers/IOATIR500GLContext.h - do not confuse the two.
     */
    void freeCommandBuffer(VendorCommandBuffer *buffer);

    /*
     * allocMoreCommandBuffers - RESOLVED, issue #28 (real mangled symbol
     * __ZN20IOATIR500Accelerator23allocMoreCommandBuffersEmm, real addr
     * 0x24a0). REAL SIGNATURE CORRECTED: this project had previously
     * declared it as a free function taking an explicit accelerator
     * parameter (`allocMoreCommandBuffers(IOATIR500Accelerator*, UInt32,
     * UInt32)`) - the real mangled symbol is a genuine MEMBER function
     * taking two `unsigned long` parameters, `this` implicit. `setup3D`'s
     * own call site (`Sources/ATIRadeonX1000_VtableSlotBodies.cpp`)
     * updated to match.
     *
     * Real body: doubles a per-record-block command-buffer array
     * (`this+recordIndex*0x1c4+0x402`, a real `UInt16` current-capacity
     * field, capped at `0x10`) via `allocCommandBuffer`, one real
     * `VendorCommandBuffer`-sized (`0x1c` bytes) slot at a time
     * (`this+recordIndex*0x1c4+0x240`, stride `0x1c`); on any single
     * allocation failure, rolls back every newly-allocated slot from
     * this call via `freeCommandBuffer` (in reverse order) and returns
     * `false`, leaving the array at its original capacity. On success,
     * stores the new capacity and - into a real, previously-unnamed
     * field `this+recordIndex*0x1c4+0x400` - the OLD capacity (role
     * beyond "backup of the previous count" UNKNOWN).
     */
    bool allocMoreCommandBuffers(UInt32 recordIndex, UInt32 size);

    /* setup_stereo - CONFIRMED real name (IOATIR500GLContext::set_stereo
     * calls it), signature INFERRED. */
    IOReturn setup_stereo(UInt32 param1, UInt32 param2);

    /* freeOrphanTexture - CONFIRMED real name, called from both
     * garbage_collector and freeWaitToAllocGART. */
    void freeOrphanTexture(bool aggressive);

    /*
     * addOrphanTexture - CONFIRMED to exist (real call site in
     * IOATIR500Surface::delete_buffer_backing, issue #1 get-it-linking
     * pass - the real inverse of freeOrphanTexture above). Real
     * signature INFERRED from that call site; own body NOT
     * independently decompiled this pass.
     */
    void addOrphanTexture(IOTextureBuffer *buffer);

private:
    /*
     * Real linked-list heads for each live context type - CONFIRMED to
     * exist (freeWaitToAllocGART walks all three via
     * `*(T**)(this+N)` / `next = *(T**)(ctx+0x80)` chains), exact base
     * offsets INFERRED from the decompile's own literal constants.
     *
     * FIXED (issue #56): these four fields were declared in discovery
     * order with no padding scaffolding, not ascending real-offset
     * order - reordered to true ascending order with a leading pad from
     * this class's own start (following the same convention already
     * used and hardware-validated for ATIRadeonX1000's own
     * `_pad_before_active`) and a pad between liveGLContextListHead and
     * live2DContextListHead.
     */
    UInt8   _pad_0x00[0x5c];
    IOATIR500Surface    *liveSurfaceListHead;    /* +0x5c, INFERRED offset */
    IOATIR500GLContext  *liveGLContextListHead;  /* +0x60, CONFIRMED this pass: IOATIR500GLContext::start's
                                                    * real decompile does `piVar4[0x18] = this` on the accelerator
                                                    * pointer (piVar4 = *(int**)(this+200)), i.e. accelerator+0x60
                                                    * word-indexed - an independent, direct confirmation of this
                                                    * offset from the writer side, not just freeWaitToAllocGART's
                                                    * reader side. See IOATIR500GLContext.h's start() note. */
    IOATIR5002DContext  *live2DContextListHead;  /* +0x64, INFERRED offset */
    IOATIR500DVDContext *liveDVDContextListHead; /* +0x68, INFERRED offset */

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
    virtual IOUserClient *new_surface(void) = 0;     /* type 0, +0x5d4 - real override: ATIRadeonX1000::new_surface (covariant return ATIR500Surface*), see ATIRadeonX1000.h */
    virtual IOUserClient *new_2d_context(void) = 0;  /* type 2, +0x5d8 - real override: ATIRadeonX1000::new_2d_context (covariant return ATIR5002DContext*), see ATIRadeonX1000.h */
    virtual IOUserClient *new_dvd_context(void) = 0; /* type 3, +0x5dc - real override: ATIRadeonX1000::new_dvd_context (covariant return ATIR500DVDContext*), see ATIRadeonX1000.h */
    virtual IOUserClient *new_gl_context(void) = 0;  /* type 1, +0x5e0 - real override: ATIRadeonX1000::new_gl_context (covariant return ATIR500GLContext*), see ATIRadeonX1000.h */

public:
    /*
     * setup3D - RESOLVED, issue #19/#23 (real vtable slot +0x530, real
     * addr 0x2610). Declared HERE, not on `ATIRadeonX1000.h` as issue
     * #19 originally had it - CORRECTED, issue #23: this class's own
     * vtable and `ATIRadeonX1000`'s own vtable have the IDENTICAL
     * address at this slot, meaning it is genuinely NOT overridden by
     * the subclass, only declared/implemented here on the base. Real
     * body: a single real call, `allocMoreCommandBuffers(0, 0x20000)` -
     * RESOLVED, issue #28 (also required a real signature correction -
     * see that method's own declaration below).
     *
     * FIXED (issue #1, first build attempt): moved from `private:` to
     * `public:` - real call site `IOATIR500GLContext::start()` invokes
     * this through its own `accelerator` pointer, an unrelated class,
     * so `private` couldn't have compiled against that real, confirmed
     * call. `new_surface`/`new_2d_context`/`new_dvd_context`/
     * `new_gl_context` just above stay `private` - their only real
     * caller is this class's own `newUserClient`.
     */
    virtual UInt32 setup3D(void);
};

#endif /* IOATIR500ACCELERATOR_H */
