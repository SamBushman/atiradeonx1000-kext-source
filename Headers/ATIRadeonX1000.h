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
struct ATITextureBufferHeader; /* real mangled type name (22ATITextureBufferHeader), found via pageoff_dirty_texture's own real callees - layout UNKNOWN, used opaquely as a pointer */

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
    UInt8   _pad_0x81[0x224 - 0x81];

    /*
     * The accelerator's own default/scratch command buffer - RESOLVED,
     * issue #52, via pure static analysis (no live hardware needed): a
     * real 0x18-byte `VendorCommandBuffer`-shaped record (the SAME real
     * shape this project already established for the GL/2D/DVD contexts'
     * own per-buffer records - `Sources/ATIRadeonX1000_
     * AllocAllContextBuffers.cpp`/`Sources/IOATIR500GLContext_
     * FreeAllContextBuffers.cpp`), allocated via `allocCommandBuffer(this,
     * (VendorCommandBuffer*)(this+0x224), 0x1000)` in `ATIRadeonX1000::
     * start` (kext offset 0x2650 - a separate, large, still-not-fully-
     * transcribed function; only this specific field-init/allocation
     * region was decompiled to answer this question). CONFIRMED via THREE
     * independent real usage sites: this same zero-init/allocation region
     * in `start`; both already-committed `ATIR500Surface::prepare_vram`/
     * `complete_vram` real reads of `scratchHeader`
     * (`Sources/ATIR500Surface_PrepareCompleteVRAM.cpp`, previously
     * described only as an unidentified "extended command ring" object);
     * and a fresh decompile of `ATIR500Surface::stop` (kext offset
     * 0x3b0c0, own body not otherwise transcribed this pass), which reads
     * this exact same field, passes `scratchHeader+0x120`/`+0x124` to
     * `ATIRadeonX1000::submit_buffer`, and calls `waitForTimeStamp` on
     * `pendingTimeStamp` (below) - all three sites agree exactly on both
     * fields' real roles and relative offsets.
     */
    UInt32  _unknown_0x224;           /* +0x224, real field, own role UNKNOWN beyond being this record's own first dword (matches this project's own established per-buffer-record shape, e.g. `VendorCommandBuffer`'s own +0 field) */
    UInt32  _unknown_0x228;           /* +0x228, real field - used in `ATIR500Surface::stop` as a base value added to `0x120` for `submit_buffer`'s own destination-offset argument; plausibly a real GPU-mapped base address for this buffer, not independently confirmed as such */
    void *  _unknown_0x22c;           /* +0x22c, real pointer field - dereferenced for its OWN vtable `+0x144` slot in `ATIRadeonX1000::start` (called with argument `3`); real object identity UNKNOWN, own vtable slot number distinct from this project's usual `+0x18` "release" convention, so likely not a simple releasable handle */
    UInt8   _pad_0x230[0x234 - 0x230]; /* +0x230 (UInt16, set to 1 in `start`) / +0x232 (UInt16) - real fields, own roles UNKNOWN, matching this project's own established per-buffer-record "u16 pair" shape */
    UInt32  pendingTimeStamp;         /* +0x234, CONFIRMED: real "tag" value passed to `ATIRadeonX1000::waitForTimeStamp` by both `ATIR500Surface::prepare_vram`/`complete_vram` and `ATIR500Surface::stop` - matches this project's own established per-buffer-record "+0x10 tag" shape exactly */
    VendorContextBufferHeader *scratchHeader; /* +0x238, CONFIRMED (issue #52): the real hardware-mappable header pointer for this same scratch command buffer - matches this project's own already-resolved `VendorContextBufferHeader` type (issue #46) and the identical "+0x14 header" shape already established for the GL/2D/DVD contexts' own primary buffers. Used as a small ad-hoc PM4 "ring" by `prepare_vram`/`complete_vram`/`stop` (real fields at `scratchHeader+0x120`/`+0x124`, well within the buffer's own 0x1000-byte allocation, past the 0x20-byte `VendorContextBufferHeader` proper) - explains this project's prior "extended command ring" naming, which was a reasonable guess given only the usage site, not the allocation site. */

    UInt8   _pad_0x23c[0x5c8 - 0x23c];

    /*
     * GART/data-buffer pool bookkeeping - CONFIRMED from
     * IOATIR500Accelerator's own freeToAllocGART/freeWaitToAllocGART and
     * every context's get_data_buffer/reclaim_resources (they all reach
     * these same fields through their own accelerator pointer).
     *
     * REORDERED (build fixup, issue #1): this whole block was previously
     * placed textually AFTER `mmioBase`/`mainRingCursor`/`idctRingCursor`
     * (real offsets 0x860-0x930), even though its own real offsets
     * (0x5c8-0x710) are smaller - real gcc (correctly) lays out non-
     * virtual data members in strict declaration order, so the old
     * ordering silently produced a WRONG struct layout (every field from
     * `cachedBufferSizeThreshold` onward would have compiled at some
     * offset near 0x934+, not its own real confirmed offset) even though
     * it happened to build without an error via the `_pad_0x934[0x5c8 -
     * 0x934]` typo-fix that preceded this discovery. Moved to its real
     * position between `scratchHeader` (+0x238) and `commandLock`
     * (+0x840), where all of its own real offsets actually fit.
     */
    UInt32  cachedBufferSizeThreshold;   /* +0x5c8, CONFIRMED: reclaim_resources sets this to 0x20000 on cleanup */
    void *  freeBufferListHead;          /* +0x5cc, CONFIRMED: real singly-linked free-list head, walked by freeToAllocGART's transfer-buffer ring sweep */
    void *  freeBufferListTail;          /* +0x5d0, CONFIRMED */
    UInt32  freeBufferListCount;         /* +0x5d4, CONFIRMED: compared against a real cap of 16 entries in reclaim_resources */
    UInt32  cachedBufferSizeThresholdB;  /* +0x5d8, CONFIRMED: reclaim_resources sets a second threshold to 0x10000; get_data_buffer compares/ratchets this one up */
    UInt8   _pad_0x5dc[0x600 - 0x5dc];
    void *  dirtyTextureListHead;        /* +0x600, CONFIRMED: real doubly-linked list head for "textures with a pending dirty flush" (get_data_buffer/purge_texture insert here) */
    UInt8   _pad_0x604[0x69c - 0x604];
    void *  secondDirtyListHead;         /* +0x69c, CONFIRMED: a second, distinct doubly-linked list head with the identical insert pattern - real purpose (a second dirty class, e.g. read-vs-write) not established */
    UInt8   _pad_0x6a0[0x70c - 0x6a0];
    UInt32  dataBufferByteAccumulator;   /* +0x70c, CONFIRMED: real running total accumulated in get_data_buffer, used to decide when to grow the cache threshold */
    UInt8   _pad_0x710[0x840 - 0x710];

    void *  commandLock;              /* +0x840, CONFIRMED: passed to lock/unlock helper pairs (FUN_xxxx(this+0x840)) bracketing nearly every external method body across all four context classes, and loaded directly in 6 independent ATIRadeonX1000:: methods (GPUSensorFunc, system_did_change_speed, system_will_change_speed, SWDSFunc, display_mode_did_change, display_mode_will_change) - always as a single word, never contradicted */
    UInt8   _pad_0x844[0x854 - 0x844];
    UInt32  idctSubmitBaseCounter;    /* +0x854, CONFIRMED: read at the top of doIDCT, compared against submit_idct_buffer_consumed's return value */
    UInt8   _pad_0x858[0x860 - 0x858];
    void *  mmioBase;                 /* +0x860, CONFIRMED: the real MMIO base pointer used by read_regs/write_regs (masked with REGISTER_ACCESS_WINDOW_MASK before use); ATIRadeonX1000::start sets it once to a real detected value and mirrors it to +0x864/+0x90c/+0x928 */
    UInt8   _pad_0x864[0x8d8 - 0x864];
    void *  clientMemoryDescriptorType0; /* +0x8d8, CONFIRMED: the real IOMemoryDescriptor returned by every context's clientMemoryForType(0, ...) */
    UInt8   _pad_0x8dc[0x918 - 0x8dc];
    UInt32  mainRingCursor;           /* +0x918, INFERRED offset (this project confirmed the field's existence and role - the real write-cursor submit_ring_data advances - via the same +0x1600-relative-to-userspace reasoning as the client-side cursor fields, not from a from-zero decompile of this exact byte) */
    UInt8   _pad_0x91c[0x930 - 0x91c]; /* FIXED (issue #57): a real 0x14-byte gap between mainRingCursor and idctRingCursor had no padding array at all, so idctRingCursor was compiling at +0x91c instead of its own documented +0x930. */
    UInt32  idctRingCursor;           /* +0x930, CONFIRMED distinct from mainRingCursor: submit_idct_buffer_consumed writes IDCT_RING_WPTR using a value derived from this field, not this+0x918 */
    UInt8   _pad_0x934[0xc00 - 0x934]; /* UNKNOWN: large unverified gap - real upper bound NOT confirmed; sized to comfortably cover the largest real accelerator-relative offset referenced anywhere else in this project's own code (0xbe8, in IOATIR500Surface_LockShape.cpp) plus margin, NOT a confirmed real boundary - a genuine placeholder, flagged honestly rather than guessed precisely. Revisit once more of this class's own tail fields are independently decompiled. */

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
     * submit_ring_data - RESOLVED (issue #1, get-it-linking pass), real
     * addr 0x1f030. SIGNATURE CORRECTED: real body takes NO explicit
     * parameter (confirmed from `submit_buffer`'s own real call site,
     * `submit_ring_data(this)` with nothing else) - it reads the real
     * pending ring-write cursor itself from `this+0x914` (own name not
     * established - a distinct field from the already-named
     * `mainRingCursor`/`+0x918`, which this function treats as the
     * "last committed" cursor and updates at the very end). Real body:
     * pads the ring to the next 8-dword boundary with NOP tokens
     * (0x80000000) if needed, performs real PowerPC cache-maintenance
     * (`dataCacheBlockStore`/`dataCacheBlockFlush`/`sync`/
     * `instructionSynchronize`) over exactly the newly-written ring
     * range UNLESS a real "write-combined, no maintenance needed" flag
     * (`this+0x98` bit `0x400000`... structurally same bit-test shape as
     * `this+0x98` bit `0x80` elsewhere - own exact bit CONFIRMED from
     * this function's own decompile) is set, handling the real ring-
     * wraparound case as two separate flush passes, then writes the
     * already-established `CP_RB_WPTR` bit-packing formula, calls
     * `enforceInOrderExecutionIO`, and commits the new cursor to
     * `mainRingCursor`. A real no-op early-return when the pending and
     * committed cursors already match.
     */
    void submit_ring_data();

    /*
     * submit_buffer / submit_buffer_retired - RESOLVED (issue #1, get-
     * it-linking pass), real addr 0x20980. RETURN TYPE CORRECTED to
     * `UInt32`: the real decompile returns a real monotonic submission
     * stamp (`this+0x50`, the SAME already-heavily-used real "current
     * stamp" counter this project references throughout as a raw
     * offset, e.g. `waitForTimeStamp(U32At(accel,0x50)-1)`), not an
     * IOReturn error code - post-incrementing it exactly like every
     * other real stamp-issuing call site in this project. Real body:
     * NOP-pads the caller's own buffer to an 8-dword boundary, waits
     * (spinning up to 1000 times, `FUN_00020cc4`-shaped short delay
     * between attempts - real identity unconfirmed) for real ring FIFO
     * space via the same bit-packed RBBM read-pointer shape
     * `wait_for_rb_space`'s own log message names, performs real cache
     * maintenance over the caller's buffer if needed (same `this+0x98`
     * bit-0x80 gate as `submit_ring_data`), optionally flushes a
     * pending `submit_empty_buffer` first, then waits again for space
     * to write six real ring dwords (an `INDIRECT_BUFFER` PM4 packet:
     * opcode `0x101ce`, the caller's own buffer address/dword-count,
     * framed by two `NOP`-shaped `0x57f`/`0x578` tokens) via
     * `submit_ring_data`. On a real, total FIFO-wait timeout, logs a
     * real diagnostic (`FUN_00020c94`, real shape matches `IOLog`) and
     * calls `DumpASICHangState` before returning the stamp counter
     * unincremented (`this+0x50 - 1`).
     */
    UInt32 submit_buffer(UInt32 *bufferStart, UInt32 bufferOffsetOrEnd, UInt32 dwordCount);

    /*
     * submit_empty_buffer - RESOLVED (issue #1, get-it-linking pass),
     * real addr 0x1bca0. Real body: no-ops if `deviceActiveFlag`
     * (`+0x80`) is clear. Otherwise performs a real indexed-register
     * round-trip handshake through `mmioBase+0x30`(index)/`+0x34`(data)
     * - writes a real byte-swapped config value (`this+0xbbc`, own
     * identity unconfirmed) twice with different byte-swap patterns,
     * then polls (up to 0x2711 times) a real 4-byte MMIO field at
     * `mmioBase+0x34..0x37` for an all-zero result, each iteration
     * re-issuing the same indexed writes. Real purpose beyond "a real
     * indirect-register write/verify handshake" not independently
     * confirmed.
     */
    void submit_empty_buffer();

    /*
     * DumpASICHangState - RESOLVED (issue #1, get-it-linking pass),
     * real addr 0x1d480. A real, purely-diagnostic register dump only
     * ever reached from `submit_buffer`'s own fatal ring-space-timeout
     * path (the GPU has already failed to free FIFO space after 1000+
     * retries by the time this runs) - disables the GPU sensor, waits
     * (via the real Mach `assert_wait_timeout`/`thread_block` pair) for
     * a real MMIO scratch-register value to change (confirming the ASIC
     * is genuinely wedged, not just slow) for up to 0x186a1 iterations,
     * then logs ~10 real 4-register-wide hex dumps plus a full 0x400-
     * byte ring-buffer-adjacent memory region (`mmioBase+0x7f0..`,
     * 4 bytes at a time) via a real varargs logger (`FUN_0001d7dc`,
     * shape matches `IOLog`) with a real small delay
     * (`FUN_0001d7ec`, shape matches `IODelay`) after every line.
     */
    void DumpASICHangState();

    /*
     * enable_GPUSensor / disable_GPUSensor - RESOLVED (issue #1, get-
     * it-linking pass), real addrs 0x19f30/0x19fd0. A real timer/event-
     * source object at `this+0x9a8` (own exact Apple type unconfirmed -
     * plausibly an `IOTimerEventSource`) gets armed (`enable`: zeroes
     * two real fields at `+0x9a0`/`+0x99c`, then calls a real vtable
     * `+300`(0x12c)-slot "arm" method with a real interval argument at
     * `+0x998`, then a real `+0xec` "enable"-shaped call) or disarmed
     * (`disable`: real `+0x158`/`+0xf0` vtable calls) - both no-op if
     * the event source is null. Exact Apple virtual-method identities
     * for all four vtable slots UNKNOWN, referenced only by raw offset
     * in the real decompile.
     */
    void enable_GPUSensor();
    void disable_GPUSensor();

    /*
     * submit_idct_buffer_consumed - RESOLVED (issue #1, get-it-linking
     * pass), real addr 0x1eb30. CORRECTED from the prior "8 pairs"
     * count: real body writes exactly 10 real (register-or-address,
     * value) pairs (20 dwords: `sATIDVDIDCTParams`'s own destBaseAddress/
     * destEndAddress/computedStride/computedChromaStride/dmaByteCount/
     * idctCoeffAddr24/strideBroadcast/idctCoeffAddr14/idctCoeffAddr18,
     * a real computed DMA address derived from the caller's own buffer
     * pointer/count, and this class's own separate IDCT completion
     * stamp at `this+0x854`) into a SEPARATE, previously-uncatalogued
     * IDCT-only ring at `this+0x91c` (own name not established - a
     * distinct ring base from the main ring's `this+0x900`), followed
     * by six real (0x80001fb4, 0) "trigger pulse" pairs (12 more
     * dwords) - 32 dwords total, matching the real FIFO-space
     * requirement (`< 0x20` free slots) the real decompile itself waits
     * for. Real body also performs real cache maintenance over the
     * caller's own buffer (same `this+0x98` bit-0x80 gate as
     * `submit_buffer`), optionally flushes a pending
     * `submit_empty_buffer` first, and busy-waits (a real static-local
     * spin counter, NOT a delay call - CONFIRMED distinct from
     * `submit_buffer`'s own `FUN_00020cc4`-based wait) for a real
     * separate IDCT FIFO status register pair (`this+0x928`/`+0x92c`)
     * before writing. On success, advances the already-established
     * `IDCT_RING_WPTR` via the same bit-packing formula as
     * `submit_ring_data`'s `CP_RB_WPTR`, and returns the OLD value of
     * the real `this+0x854` completion-stamp counter (post-
     * incrementing it) - NOT the `this+0x50` stamp `submit_buffer`
     * uses, a genuinely separate counter. On a real total FIFO-wait
     * timeout, calls `DumpASICHangState` and returns `this+0x854 - 1`
     * unincremented, mirroring `submit_buffer`'s own timeout-return
     * shape.
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
    UInt32 SWDSWriteBlitToCmdBuf(UInt32 *buffer, UInt32 wordCount, bool flag, UInt32 panel); /* real addr 0x23320: appends the software-dual-screen blit packets to a swap command buffer, returns the new word count */
    void start_xdct_engine(void);                       /* real addr 0x25c60: powers up the IDCT engine when the first DVD context starts */
    void stop_xdct_engine(void);                        /* real addr in ledger: the matching shut-down from ATIR500DVDContext::stop */

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
    virtual IOReturn allocate_texture(VendorTextureBuffer *texture);      /* +0x528 on this class's own vtable, real addr 0x1a800 - CONFIRMED signature (ATIR500GLContext_TextureLoad.cpp's own callAcceleratorVtable0x528). `virtual` ADDED, issue #34 sweep - base declaration was missing (see IOATIR500Accelerator.h). */
    void     deallocate_texture(VendorTextureBuffer *texture);    /* +0x524, real addr 0x1a620 - CORRECTED, issue #23: real body takes a real VendorTextureBuffer* parameter, confirmed from its own real decompile which unconditionally reads texture+0x20 etc. - this project's issue #19 filing had it taking none, matching a real call-site bug in ATIR500GLContext_TextureLoad.cpp (fixed there too) */
    virtual UInt32   waitForTimeStamp(UInt32 tag);                        /* +0x54c, real addr 0x251e0 - CONFIRMED signature (ATIR500GLContext_TextureLoad.cpp/ATIR500GLContext_RestoreState.cpp's own StampFn/VTableCall0x54c typedefs). `virtual` ADDED, issue #34 sweep - base declaration was missing (see IOATIR500Accelerator.h). */
    UInt32   sleepForTimeStamp(UInt32 tag);                       /* +0x558, real addr 0x25960 - CONFIRMED signature (IOATIR500Surface_LockShape.cpp's own StampFn/Fn0x558 typedefs) */
    virtual void addTransferToGART(VendorTransferBuffer *buffer); /* +0x5a8 on this class's own vtable, real addr 0x1a4d0 - real override of IOATIR500Accelerator::addTransferToGART, see that header */
    virtual void addToGART(IOMemoryDescriptor *descriptor, UInt32 *result); /* +0x5a0 on this class's own vtable, real addr 0x1a480 - RESOLVED, issue #26: a trivial pass-through override, calls IOATIR500Accelerator::addToGART with no added logic, see that header */

    /*
     * allocVendorTextureBuffer / releaseVendorTextureBuffer /
     * removeTransferFromGART - real overrides confirmed via `nm`
     * cross-check (own bodies not decompiled) - see
     * `IOATIR500Accelerator.h`'s own declaration comments for the full
     * account (including a real by-hand arithmetic slip in an earlier
     * pass this session, now corrected).
     */
    virtual VendorTextureBuffer *allocVendorTextureBuffer(UInt32 size); /* +0x570, real addr 0x1a560 */
    virtual void                 releaseVendorTextureBuffer(VendorTextureBuffer *buffer, UInt32 size); /* +0x574, real addr 0x1a590 */
    virtual void                 removeTransferFromGART(VendorTransferBuffer *buffer); /* +0x5ac, real addr 0x1a530 */

    /*
     * pageoff_dirty_texture - RESOLVED via the concrete-subclass-vtable
     * technique (this class's own `+0x52c` slot is a real override; the
     * base `IOATIR500Accelerator`'s own copy is genuine placeholder
     * content) - real addr `0x21c60`, found while decompiling
     * `IOATIR500GLContext::page_off_texture`
     * (`Sources/IOATIR500GLContext_PageOffTexture.cpp`). Real body:
     * prepares a real GART mapping on the texture's `memoryDescriptor`
     * (the same `+0x14c`/`+0xd0` chain established elsewhere), then reads
     * a real hardware-info flag word (`+0x20` on the resulting handle,
     * bits `0x20000000`/`0x40000000`) to choose between three further
     * real, previously-unknown functions this pass did NOT chase down
     * (found via their own already-demangled real names, but their own
     * bodies not decompiled): `pageoff_linear_buffer`,
     * `pageoff_dirty_texture_with_gpu`,
     * `prepare_texture_for_pageoff_with_cpu` +
     * `pageoff_dirty_texture_with_cpu` (real addrs `0x217a0`, `0x210f0`,
     * `0x20d30`, `0x1e500` respectively - all real methods on THIS class,
     * all taking `(VendorTextureBuffer*, ATITextureBufferHeader*)` - a
     * new, previously-undocumented real type this pass found but did not
     * reconstruct). Real HONEST FLAG: Ghidra's own `-noanalysis` decompile
     * of THIS function renders its own parameter list ambiguously
     * (`VendorTextureBuffer*, long, long` per its raw signature line, but
     * the body's own field accesses and its own onward `(ATIRadeonX1000*)`
     * casts strongly suggest the REAL first param is `this`, mistyped by
     * Ghidra, with the real explicit `VendorTextureBuffer*` in the SECOND
     * slot) - own body transcribed as a real 3-real-parameter method here
     * on that reading, but NOT independently disassembly-verified; the
     * call site in `page_off_texture` passes `0` for both trailing `long`
     * arguments since this function's own body never references either
     * one (so the real values, whatever they are, do not affect real
     * behavior even if this parameter-mapping reading is wrong).
     */
    void pageoff_dirty_texture(VendorTextureBuffer *texture, long param2, long param3);

    /*
     * Four real, already-named (via their own real mangled symbols)
     * methods `pageoff_dirty_texture` calls into. Own bodies RESOLVED,
     * issue #30 - see Sources/ATIRadeonX1000_TexturePageoff.cpp. Real
     * addrs: pageoff_linear_buffer 0x217a0, pageoff_dirty_texture_with_gpu
     * 0x210f0, prepare_texture_for_pageoff_with_cpu 0x20d30,
     * pageoff_dirty_texture_with_cpu 0x1e500. REAL RETURN TYPE CORRECTED:
     * `pageoff_dirty_texture_with_cpu` is genuinely `void` (this
     * project's earlier placeholder declaration had it returning
     * `UInt32` by analogy with its siblings - its own real decompile
     * never returns a value).
     */
    UInt32 pageoff_linear_buffer(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo);
    UInt32 pageoff_dirty_texture_with_gpu(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo);
    UInt32 prepare_texture_for_pageoff_with_cpu(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo);
    void   pageoff_dirty_texture_with_cpu(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo);

    /*
     * freeToAllocTextureCPUVisibleVRAM - CONFIRMED real name/addr
     * (0x1e320, via `nm`), found as `prepare_texture_for_
     * pageoff_with_cpu`'s own real fallback call when a direct
     * `ATIR500Memory::alloc` fails. Own body RESOLVED, issue #47 - see
     * Sources/ATIRadeonX1000_FreeToAllocTextureCPUVisibleVRAM.cpp.
     */
    UInt32 freeToAllocTextureCPUVisibleVRAM(VendorTextureBuffer *texture, UInt32 size);

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

    /*
     * getNumPipes / getChipID / getChipRev / getNumZPipes - RESOLVED
     * (issue #1 gap-fill pass), real addrs 0x1aba0/0x1abb0/0x1abc0/
     * 0x1abd0. Four genuinely trivial real accessors, each a single raw
     * field read (own field names not otherwise established elsewhere
     * in this project) - found as `ATIR500GLContext::get_hw_info`'s own
     * real call targets, see Sources/ATIR500GLContext_GetHwInfo.cpp.
     */
    UInt32 getNumPipes();
    UInt32 getChipID();
    UInt32 getChipRev();
    UInt32 getNumZPipes();
};

#endif /* ATIRADEONX1000_H */
