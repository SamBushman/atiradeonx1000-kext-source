/*
 * ATIRadeonX1000.h
 *
 * *** CORRECTED (2026-08-30) - see the real Info.plist find below ***
 *
 * This project always knew `ATIRadeonX1000` was a real class (from real
 * decompiled method signatures like `ATIRadeonX1000::submit_buffer`,
 * `ATIRadeonX1000::submit_idct_buffer_consumed`,
 * `ATIRadeonX1000::waitForRetiredTimeStamp`), but earlier modeled it as a
 * bare, non-IOKit "hardware helper" object every context class merely
 * holds a pointer to - separate from the real class hierarchy entirely.
 *
 * Reading the REAL kext `Info.plist` (already pulled read-only from the
 * Tiger HD earlier this project, just never opened until now) settles
 * this: `<key>IOClass</key><string>ATIRadeonX1000</string>` - **this is
 * the real, concrete, IOKit-registered driver class** IOKit instantiates
 * directly for a matching `IOPCIDevice`. It is therefore this project's
 * `IOATIR500Accelerator` base class's real, concrete SUBCLASS - not a
 * separate, disconnected helper object. Every context class's
 * `accelerator` pointer (this+200 on GL, this+0x94 on 2D, this+0x8c on
 * DVD) is a pointer to the one real, live `ATIRadeonX1000` instance, typed
 * as such (not merely `IOATIR500Accelerator*`) precisely because these
 * contexts need the chip-specific methods declared here, not just the
 * generic accelerator-family ones on the base class.
 *
 * The real Info.plist also settled a related question this project had
 * only guessed at: `OSBundleLibraries` lists `IOGraphicsFamily`/
 * `IONDRVSupport`/`IOPCIFamily` (all `1.0.0b1`) - **not**
 * `IOAcceleratorFamily`. This driver predates/does not use that later,
 * more generic framework; `IOATIR500Accelerator`'s real base is plain
 * `IOService`, and `IOATIR500GLContext`/etc.'s real base is plain
 * `IOUserClient` - both already modeled correctly, just confirmed now
 * rather than assumed by name-analogy.
 *
 * Confidence: CONFIRMED unless marked otherwise. See ../README.md.
 */

#ifndef ATIRADEONX1000_H
#define ATIRADEONX1000_H

#include "IOATIR500Accelerator.h"
#include "ATIRadeonX1000Types.h"
#include "ATIR500Surface.h"
#include "ATIR5002DContext.h"
#include "ATIR500DVDContext.h"
#include "ATIR500GLContext.h"

class IOWorkLoop;
class IOMemoryDescriptor;
struct GLKMemoryElement; /* real mangled type name (16GLKMemoryElement), layout UNKNOWN - only used opaquely as a pointer by tmpAllocVRAM/tmpDeallocVRAM below */

class ATIRadeonX1000 : public IOATIR500Accelerator {
    OSDeclareDefaultStructors(ATIRadeonX1000)

public:
    /*
     * Real, confirmed field offsets (from this base pointer, as reached
     * via each context class's own "this+N" accelerator pointer - e.g.
     * ATIR500GLContext at +200/0xc8, ATIR5002DContext at +0x94,
     * ATIR500DVDContext at +0x8c). Gaps are real (not every byte in
     * between was ever touched by decompiled code this project read).
     *
     * RESOLVED (issue #10): this project's own constructors turned out to
     * be thin trampolines that never touch these fields (real
     * initialization happens in start(), the standard IOKit pattern).
     * ATIRadeonX1000::start itself (kext offset 0x1f750, a large
     * function) has not been fully transcribed into this repo - this
     * finding comes from a targeted decompile used only to answer this
     * specific field-ordering question. Directly found real,
     * repeated, self-consistent accesses to deviceActiveFlag (6
     * independent ATIRadeonX1000:: functions) and commandLock (6 more) -
     * not just via other classes' pointers as before - plus mmioBase's
     * own real set-and-mirror site inside start() itself, confirming
     * both their individual reality and their relative order below - no
     * longer modeled as "unordered".
     */
    UInt8   _pad_before_active[0x80];
    UInt8   deviceActiveFlag;         /* +0x80, CONFIRMED: a real byte gate checked before nearly every hardware operation in every context class, and directly read/written by 6 independent ATIRadeonX1000:: methods (callPlatformFunction, submit_empty_buffer, start_promo4_engine/stop_promo4_engine, GPUSensorFunc, system_will_change_speed) - always as a single byte, never contradicted */
    UInt8   _pad_0x81[0x840 - 0x81];
    void *  commandLock;              /* +0x840, CONFIRMED: passed to lock/unlock helper pairs (FUN_xxxx(this+0x840)) bracketing nearly every external method body across all four context classes, and loaded directly in 6 independent ATIRadeonX1000:: methods (GPUSensorFunc, system_did_change_speed, system_will_change_speed, SWDSFunc, display_mode_did_change, display_mode_will_change) - always as a single word, never contradicted */
    UInt8   _pad_0x844[0x854 - 0x844];
    UInt32  idctSubmitBaseCounter;    /* +0x854, CONFIRMED: read at the top of doIDCT, compared against submit_idct_buffer_consumed's return value */
    UInt8   _pad_0x858[0x860 - 0x858];
    void *  mmioBase;                 /* +0x860, CONFIRMED: the real MMIO base pointer used by read_regs/write_regs (masked with REGISTER_ACCESS_WINDOW_MASK before use); ATIRadeonX1000::start sets it once to a real detected value and mirrors it to +0x864/+0x90c/+0x928 */
    UInt8   _pad_0x864[0x8d8 - 0x864];
    void *  clientMemoryDescriptorType0; /* +0x8d8, CONFIRMED: the real IOMemoryDescriptor returned by every context's clientMemoryForType(0, ...) */
    UInt8   _pad_0x8dc[0x918 - 0x8dc];
    UInt32  mainRingCursor;           /* +0x918, INFERRED offset (this project confirmed the field's existence and role - the real write-cursor submit_ring_data advances - via the same +0x1600-relative-to-userspace reasoning as the client-side cursor fields, not from a from-zero decompile of this exact byte) */
    UInt32  idctRingCursor;           /* +0x930, CONFIRMED distinct from mainRingCursor: submit_idct_buffer_consumed writes IDCT_RING_WPTR using a value derived from this field, not this+0x918 */
    UInt8   _pad_0x934[0x5a4 - 0x934]; /* UNKNOWN: large unverified gap */

    /*
     * GART/data-buffer pool bookkeeping - CONFIRMED from
     * IOATIR500Accelerator's own freeToAllocGART/freeWaitToAllocGART and
     * every context's get_data_buffer/reclaim_resources (they all reach
     * these same fields through their own accelerator pointer).
     */
    UInt32  cachedBufferSizeThreshold;   /* +0x5c8, CONFIRMED: reclaim_resources sets this to 0x20000 on cleanup */
    UInt32  cachedBufferSizeThresholdB;  /* +0x5d8, CONFIRMED: reclaim_resources sets a second threshold to 0x10000; get_data_buffer compares/ratchets this one up */
    void *  freeBufferListHead;          /* +0x5cc, CONFIRMED: real singly-linked free-list head, walked by freeToAllocGART's transfer-buffer ring sweep */
    void *  freeBufferListTail;          /* +0x5d0, CONFIRMED */
    UInt32  freeBufferListCount;         /* +0x5d4, CONFIRMED: compared against a real cap of 16 entries in reclaim_resources */
    UInt8   _pad_0x5dc[0x600 - 0x5dc];
    void *  dirtyTextureListHead;        /* +0x600, CONFIRMED: real doubly-linked list head for "textures with a pending dirty flush" (get_data_buffer/purge_texture insert here) */
    UInt8   _pad_0x604[0x69c - 0x604];
    void *  secondDirtyListHead;         /* +0x69c, CONFIRMED: a second, distinct doubly-linked list head with the identical insert pattern - real purpose (a second dirty class, e.g. read-vs-write) not established */
    UInt8   _pad_0x6a0[0x70c - 0x6a0];
    UInt32  dataBufferByteAccumulator;   /* +0x70c, CONFIRMED: real running total accumulated in get_data_buffer, used to decide when to grow the cache threshold */

    /*
     * The two real, software-only IOInterruptEventSource callbacks this
     * kext registers - CONFIRMED to be pure deferred-work triggers, not
     * hardware interrupt handlers (see stage9-gl-remaining-methods-...md).
     * Declared here as real static method pointers matching their
     * confirmed signature.
     */
    static void garbage_collector(OSObject *owner, class IOInterruptEventSource *source, int count);
    static void gart_collector(OSObject *owner, class IOInterruptEventSource *source, int count);

    /* ---- Real, confirmed methods ---- */

    /*
     * submit_ring_data - CONFIRMED. Advances CP_RB_WPTR using the real
     * bit-packing formula this project found and re-confirmed identically
     * in submit_idct_buffer_consumed:
     *     mmio[CP_RB_WPTR] = (wptr << 24) | ((wptr & 0x700) << 8);
     * Exact parameter list not re-derived for this reconstruction (the
     * original decompile was read for its MMIO-write shape, not transcribed
     * argument-by-argument) - modeled with a plausible signature.
     */
    void submit_ring_data(UInt32 wptr);

    /*
     * submit_buffer / submit_buffer_retired - CONFIRMED to exist and to be
     * the real indirect-buffer submission path every context's deferred/
     * "flush if nearly full" logic calls (distinct from submit_ring_data's
     * direct-ring path). Exact signature INFERRED from the many real call
     * sites this project read (e.g. ATIR5002DContext::process_command_buffer's
     * `ATIRadeonX1000::submit_buffer(accel, ptr1, ptr2, count)` shape).
     */
    IOReturn submit_buffer(UInt32 *bufferStart, UInt32 bufferOffsetOrEnd, UInt32 dwordCount);

    /*
     * submit_idct_buffer_consumed - CONFIRMED real name and behavior
     * (stage5-iouserclient-external-method-api-complete.md's doIDCT trace).
     * Writes the 8 real (register,value) coefficient-address pairs plus
     * six IDCT_TRIGGER_PULSE strobes directly into the main ring, then
     * advances IDCT_RING_WPTR via idctRingCursor. Returns the new
     * completion tag.
     */
    UInt32 submit_idct_buffer_consumed(UInt32 *ringPtr, UInt32 ringOffset, sATIDVDIDCTInfo *info);

    /*
     * waitForRetiredTimeStamp / waitForTimeStampNoLock - CONFIRMED to be
     * the real kernel-side fence-wait pair every context's wait_for_stamp/
     * wait_image/wait_for_stamps external method ultimately calls.
     * waitForConsumedIDCTTimeStamp - CONFIRMED distinct IDCT-specific
     * counterpart (stage4-real-hardware-idct-engine-found.md).
     */
    IOReturn waitForRetiredTimeStamp(UInt32 tag);
    IOReturn waitForTimeStampNoLock(UInt32 tag);
    IOReturn waitForConsumedIDCTTimeStamp(UInt32 tag); /* real vtable slot +0x5ec on this class's own vtable, real addr 0x254e0 - CONFIRMED (issue #19), see ATIR500DVDContext_ProcessCommandBuffer.cpp's own EngineKickFn call sites */

    /*
     * External-method selector 9 on the GL context, CONFIRMED to be
     * exactly wait_for_stamp - see ATIR500GLContext.h.
     */

    /*
     * The four real `IOATIR500Accelerator` factory virtuals' real
     * overrides - names/addresses RESOLVED issue #6, bodies RESOLVED
     * issue #21. Each real body is trivially uniform: allocate a fixed
     * real byte size via a real lazy-binding stub (almost certainly
     * `operator new(unsigned long)` - same 4-instruction trampoline
     * shape as issue #15's 24-stub catalog, a distinct per-call-site
     * instance each), placement-construct the real concrete class if the
     * allocation succeeded, return it (or null). Real covariant return
     * types below (the base class's own declaration,
     * `IOATIR500Accelerator.h`, keeps the generic `IOUserClient*`
     * interface type, which remains valid C++ for the base) - the real
     * compiled return type on THIS class is the concrete subclass,
     * confirmed directly from each real decompile. Real per-class
     * allocation sizes, also a new real finding this pass:
     * `ATIR500Surface` `0xdbc` bytes, `ATIR5002DContext` `300` (`0x12c`)
     * bytes, `ATIR500DVDContext` `0x1e0` bytes, `ATIR500GLContext`
     * `0x690` bytes.
     */
    virtual ATIR500Surface    *new_surface(void);     /* +0x5d4 on this class's own vtable, real addr 0x1a140 - allocates 0xdbc bytes via FUN_0001a194 (real lazy-binding stub) */
    virtual ATIR5002DContext  *new_2d_context(void);  /* +0x5d8, real addr 0x1a220 - allocates 300 (0x12c) bytes via FUN_0001a274 (real lazy-binding stub) */
    virtual ATIR500DVDContext *new_dvd_context(void); /* +0x5dc, real addr 0x1a290 - allocates 0x1e0 bytes via FUN_0001a2e4 (real lazy-binding stub) */
    virtual ATIR500GLContext  *new_gl_context(void);  /* +0x5e0, real addr 0x1a1b0 - allocates 0x690 bytes via FUN_0001a204 (real lazy-binding stub) */

    /*
     * Five more real vtable slots this project had called through raw
     * offset casts with no name attached - RESOLVED, issue #19. Same
     * "read the concrete ATIRadeonX1000 vtable, not the base class's own
     * copy" technique that resolved issue #6 above. `waitForTimeStamp`/
     * `sleepForTimeStamp` extend the already-declared
     * waitFor.../sleepFor... fence-wait family above (this binary has a
     * real 8-member family total: Retired/NoLock/Consumed-IDCT already
     * known, these two are the plain, non-"NoLock"/non-IDCT-specific
     * pair).
     *
     * CORRECTED, issue #23 (decompiling the real bodies): `setup3D`'s
     * real vtable slot has the IDENTICAL address on both this class's
     * own vtable and the base's - i.e. it is NOT actually overridden
     * here, only declared on the base (`IOATIR500Accelerator.h`); moved
     * there. `addTransferToGART` real signature takes a
     * `VendorTransferBuffer*` parameter (this project's issue #19 filing
     * had it taking none) - the base class declares the virtual
     * (`IOATIR500Accelerator.h`); THIS class provides a real, genuinely
     * different override (explicitly calls the base version, then adds
     * its own bookkeeping) - both declared as their own class's owner.
     */
    IOReturn allocate_texture(VendorTextureBuffer *texture);      /* +0x528 on this class's own vtable, real addr 0x1a800 - CONFIRMED signature (ATIR500GLContext_TextureLoad.cpp's own callAcceleratorVtable0x528) */
    void     deallocate_texture(void);                            /* +0x524, real addr 0x1a620 - CONFIRMED signature, no texture parameter (ATIR500GLContext_TextureLoad.cpp's own callAcceleratorVtable0x524) */
    UInt32   waitForTimeStamp(UInt32 tag);                        /* +0x54c, real addr 0x251e0 - CONFIRMED signature (ATIR500GLContext_TextureLoad.cpp/ATIR500GLContext_RestoreState.cpp's own StampFn/VTableCall0x54c typedefs) */
    UInt32   sleepForTimeStamp(UInt32 tag);                       /* +0x558, real addr 0x25960 - CONFIRMED signature (IOATIR500Surface_LockShape.cpp's own StampFn/Fn0x558 typedefs) */
    virtual void addTransferToGART(VendorTransferBuffer *buffer); /* +0x5a8 on this class's own vtable, real addr 0x1a4d0 - real override of IOATIR500Accelerator::addTransferToGART, see that header */
    virtual void addToGART(IOMemoryDescriptor *descriptor, UInt32 *result); /* +0x5a0 on this class's own vtable, real addr 0x1a480 - RESOLVED, issue #26: a trivial pass-through override, calls IOATIR500Accelerator::addToGART with no added logic, see that header */

    /*
     * tmpAllocVRAM / tmpDeallocVRAM - RESOLVED, issue #19 (found while
     * wiring in the rest of that issue - two more real vtable slots
     * `IOATIR500Surface::set_shape_backing_length_ext`
     * (`Sources/IOATIR500Surface_LockShape.cpp`) calls through raw
     * `Fn0x540`/`Fn0x544` casts, same real gap regardless of not being in
     * that issue's original enumeration). Own bodies not independently
     * decompiled this pass.
     */
    bool tmpAllocVRAM(GLKMemoryElement *elem, UInt32 size, UInt32 alignment); /* +0x540, real addr 0x1aad0 - RETURN TYPE CORRECTED, issue #21/#23: real body is a thin wrapper around ATIR500Memory::alloc's own real bool success/failure return, not a pointer as this project's call sites had inferred (Ghidra's own isolated decompile of this trivial wrapper mislabeled it void; the real callee's own decompiled body proves the real value in r3 is a real, meaningful boolean) */
    void tmpDeallocVRAM(GLKMemoryElement *elem);                              /* +0x544, real addr 0x1ab20 - real return value (ATIR500Memory::dealloc's own bool) is never used at either real call site, so void is a safe, correct declaration despite the callee itself returning a value */
};

#endif /* ATIRADEONX1000_H */
