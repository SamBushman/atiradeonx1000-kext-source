/*
 * IOATIR500Surface.h
 *
 * The base display-surface bookkeeping class - window-server-style
 * lock/shape/backing-store management, referenced by every other context
 * class when a surface is bound. RESOLVED (issue #16): this project now
 * has a real base/subclass split for Surface, matching the other three
 * context classes - see `Headers/ATIR500Surface.h` for the concrete
 * subclass (`getTargetAndMethodForIndex`, the real dispatch function
 * itself, and the overlay/`resolve_fsaa_buffer`/
 * `decompress_and_flush_depth_buffer` family all live there, not here -
 * every method still declared below was individually confirmed, via its
 * own real mangled symbol name, to genuinely be a base-class member).
 *
 * Confidence: selector numbers/names/addresses CONFIRMED from raw kext
 * bytes. The lock/shape family was sampled, not exhaustively decompiled
 * (stage10-ga-plugin-full-interface-and-va-driver-confirmed.md) before
 * issue #8 later filled in every real external method's own body.
 */

#ifndef IOATIR500SURFACE_H
#define IOATIR500SURFACE_H

#include <IOKit/IOUserClient.h>
#include <IOKit/IOMemoryDescriptor.h>
#include "ATIRadeonX1000Types.h"

class ATIRadeonX1000;
class IOATIR500GLContext;
class IOATIR500DVDContext; /* real mangled-symbol evidence for set_dvd_context/remove_dvd_context below confirms this is the BASE class (19-char "IOATIR500DVDContext"), not the ATIR500DVDContext subclass */
class IOTextureBuffer; /* real, opaque backing-store handle type - forward declared only, not reconstructed (Apple's own real type, same policy as IOAccelSurfaceData etc. below) */
struct VendorTransferBuffer;
struct VendorSwapBufferHeader; /* real type name (Ghidra's own symbol), own real layout not reconstructed - issue #28 */

/*
 * IOAccelSurfaceReadData / IOAccelSurfaceData / IOAccelSurfaceScaling -
 * real Apple types from the IOAcceleratorFamily framework's own public
 * headers (IOAccelSurfaceConnect.h era), NOT reconstructed by this
 * project - a real build should include Apple's own header for these
 * rather than rely on this forward declaration. Declared here only so
 * this header is self-contained for reading/review purposes.
 */
struct IOAccelSurfaceReadData;
struct IOAccelSurfaceData;
struct IOAccelSurfaceScaling;
struct IOAccelDeviceRegion;

class IOATIR500Surface : public IOUserClient {
    OSDeclareDefaultStructors(IOATIR500Surface)

    /* IOATIR500DVDContext::set_surface (Sources/IOATIR500DVDContext_
     * SetSurface.cpp) needs real access to this class's own protected
     * contextListHeadA/contextListHeadB/boundDVDContext fields exactly as
     * a real member function would - friended here rather than weakening
     * those fields to public, matching this project's already-established
     * pattern for the same situation elsewhere (see e.g. ATIR500DVDContext.h's
     * own friend declarations for its opcode-handler free functions). */
    friend class IOATIR500DVDContext;

public:
    /*
     * start - RESOLVED (issue #58, completing the external-method
     * dispatch chain issue #42 started). Real addr 0x119f0. THE real
     * function that populates `methodTable` (`this+0xd5c`,
     * `getTargetAndMethodForIndex`'s own real dispatch table pointer -
     * see `Headers/ATIR500Surface.h`) - without this, that dispatch
     * mechanism (however correct in isolation) would read an
     * uninitialized/zero pointer at runtime. See
     * Sources/IOATIR500Surface_Start.cpp for the full real transcription.
     */
    virtual bool start(IOService *provider) override;

    /*
     * RESOLVED this pass (issue #8): surface_read_lock_options,
     * surface_write_lock_options, surface_write_unlock_options,
     * surface_write_lock, surface_write_unlock, set_scale all now fully
     * transcribed from complete real decompiles - see
     * Sources/IOATIR500Surface_LockShape.cpp. Several REAL SIGNATURE
     * CORRECTIONS found in the process (this project's earlier
     * declarations undercounted parameters or assumed the wrong return
     * type for these six):
     *   - surface_read_lock_options / surface_write_lock_options: real
     *     3 params (UInt32, IOAccelSurfaceData*, UInt32), not 2
     *     (void*, UInt32).
     *   - surface_write_unlock_options: real 1 param (UInt32), not 0.
     *   - surface_write_lock / surface_write_unlock /
     *     surface_write_unlock_options: real return type `void`, not
     *     `IOReturn`.
     *   - set_scale: real 2nd param is `IOAccelSurfaceScaling*` (a real
     *     scaling-parameters struct), not raw `UInt32 xScale, UInt32
     *     yScale` - this project had guessed the wrong shape entirely.
     * RESOLVED, issue #8, in a later pass: set_id_mode and
     * set_shape_backing/set_shape_backing_length (plus the shared
     * set_shape_backing_length_ext they both tail-call) are now ALSO
     * fully transcribed - see Sources/IOATIR500Surface_LockShape.cpp
     * for all four. Issue #8 is now fully closed - every one of
     * Surface's 19 real external methods has real decompiled content
     * behind it.
     */
    IOReturn surface_read_lock_options(UInt32 lockOptions, IOAccelSurfaceData *data, UInt32 size); /* 0 */
    IOReturn surface_read_unlock_options(UInt32 param1);                       /* 1, REAL SIGNATURE CORRECTED (issue #42 test-harness pass): real mangled symbol (__ZN16IOATIR500Surface27surface_read_unlock_optionsEm) confirms 1 real param, not 0. Ghidra's own decompile displays this as `void`, but the real raw disassembly is a pure tail branch into surface_unlock_options with no r3 postprocessing at all - real wire behavior DOES propagate surface_unlock_options' own real IOReturn result (a display/type-inference artifact for a discarded-looking tail call, not genuine void - kept IOReturn, matching this selector's own real byte-dumped table output count). CONFIRMED real one-line forward to surface_unlock_options(this, 1, param1). */
    IOReturn get_state(UInt32 *outStateBits);                                  /* 2, CONFIRMED body (stage10): real vtable call at offset 0x520, maps to 0/1 */
    void     surface_write_lock_options(UInt32 lockOptions, IOAccelSurfaceData *data, UInt32 size); /* 3 */
    void     surface_write_unlock_options(UInt32 options);                     /* 4 */
    IOReturn surface_read(IOAccelSurfaceReadData *readData, UInt32 structSize); /* 5, CONFIRMED body (stage10): real clipped-readback pattern, identical shape to the GL context's read_buffer */
    /*
     * set_shape_backing / set_id_mode / set_scale / set_shape /
     * set_shape_backing_length - real signatures CORRECTED to match the
     * real mangled symbols. RESOLVED, issue #8: set_shape_backing and
     * set_shape_backing_length are real, unconditional thin forwards
     * into `set_shape_backing_length_ext` (real kext offset 0x152d0) -
     * "conditional" in this project's earlier note was wrong for
     * set_shape_backing (always forwards) and imprecise for
     * set_shape_backing_length (the "condition" is a real size-vs-region
     * validation gate that can reject BEFORE ever reaching the forward,
     * not a choice between two different forward targets). See
     * Sources/IOATIR500Surface_LockShape.cpp for all bodies, resolved by
     * direct disassembly (Ghidra's own no-analysis decompile mis-numbers
     * these functions' parameters - confirmed and corrected via the raw
     * PPC register trace, not trusted blindly).
     */
    void     set_shape_backing(UInt32 shapeBits, UInt32 param2, UInt32 param3, UInt32 param4,
                                IOAccelDeviceRegion *region, UInt32 param6);    /* 6, RESOLVED (issue #8) */
    IOReturn set_id_mode(UInt32 mode, UInt32 modeBits);                       /* 7, RESOLVED (issue #8) */
    IOReturn set_scale(UInt32 flags, IOAccelSurfaceScaling *scaling, UInt32 param3); /* 8, RESOLVED this pass - see Sources/IOATIR500Surface_LockShape.cpp */
    IOReturn set_shape(UInt32 shapeBits, UInt32 id, IOAccelDeviceRegion *region, UInt32 param4); /* 9, REAL SIGNATURE CORRECTED (issue #42 test-harness pass): real mangled symbol (__ZN16IOATIR500Surface9set_shapeE24eIOAccelSurfaceShapeBitsmP19IOAccelDeviceRegionm) confirms 4 real params, not 0 as previously declared - Ghidra's own decompile hid the real forwarding args entirely (the same "calling-convention-inference artifact" already catalogued elsewhere in this project), resolved via the real raw PPC register moves instead (Sources/IOATIR500Surface_ExternalMethods2.cpp): real forward is set_shape_backing_length_ext(shapeBits, id, 0, 0xffffffff, region, param4, 0) - the SAME real 0xffffffff sentinel set_shape_backing_length's own forward uses. Real disassembly is a pure tail branch with no r3 postprocessing - kept IOReturn (propagating the real ext call's result) rather than trusting Ghidra's own "void" display for what is really an unthreaded passthrough, matching this selector's own real byte-dumped table output count (unlike set_shape_backing, which genuinely discards the result via its own distinct real code path). */
    IOReturn surface_flush(UInt32 param1, UInt32 param2);                      /* 10, CONFIRMED body (stage10): real - alloc_surfaces_retry then flush_surface, plus real completion-counter bookkeeping via a vtable call at offset 0x54c */
    IOReturn surface_query_lock(void);                                        /* 11, CONFIRMED body (stage10): real availability check without acquiring, using the same pending-GPU-flush bits as lock_memory */
    IOReturn surface_read_lock(IOAccelSurfaceData *data, UInt32 size);         /* 12, CONFIRMED body (stage10): thin forward to surface_lock_options(this, 1, 2, data, size) */
    IOReturn surface_read_unlock(void);                                       /* 13, CONFIRMED body (stage10): thin forward to surface_unlock_options(this, 1, 2) */
    void     surface_write_lock(IOAccelSurfaceData *data, UInt32 size);       /* 14, RESOLVED this pass */
    void     surface_write_unlock(void);                                     /* 15, RESOLVED this pass */
    IOReturn surface_control(UInt32 selector, UInt32 *inOut);   /* 16, REAL SIGNATURE CORRECTED (issue #42 test-harness pass): real decompile (Sources/IOATIR500Surface_ExternalMethods2.cpp) shows only 2 real explicit params - what this project had labeled "selector" (the first explicit param, dispatched on ==1/==4) plus "inOut" - Ghidra's own raw dump for this specific function additionally showed NO separate "this" at all in its signature (an `__stdcall`-inferred artifact; the real body clearly uses its own first param exactly where `this` would be used, e.g. passing it on to set_surface_blocking/set_volatile_state), meaning the previously-declared middle "param2" never really existed as a distinct argument - real dispatcher: selector==1 -> set_surface_blocking, selector==4 -> set_volatile_state, else kIOReturnBadArgument. Matches the real byte-dumped external-method table's own count1=2 (Sources/ATIR500Surface_ExternalMethods.cpp). */
    IOReturn set_shape_backing_length(UInt32 shapeBits, UInt32 param2, UInt32 param3, UInt32 param4,
                                       UInt32 param5, IOAccelDeviceRegion *region); /* 17, RESOLVED (issue #8) */
    IOReturn surface_control_alias(UInt32 selector, UInt32 *inOut); /* 18, CONFIRMED to be a real, deliberate alias of selector 16 - same function address, not two implementations. Signature corrected alongside surface_control's own correction (issue #42 test-harness pass) - see that method's own comment. */

    /*
     * set_shape_backing_length_ext - RESOLVED, issue #8, real name/
     * signature (real mangled symbol
     * __ZN16IOATIR500Surface28set_shape_backing_length_extE24eIOAccelSurfaceShapeBitsmjmP19IOAccelDeviceRegionmm,
     * real kext offset 0x152d0) - NOT itself one of Surface's 19 real
     * external methods (no selector number), an internal helper
     * `set_shape_backing`/`set_shape_backing_length`/`set_shape` (selector
     * 9) all tail-call. Real 2nd parameter (`id` here) is CONFIRMED, from
     * this pass's own decompile, to be a real per-surface "shape/ID slot"
     * index - the SAME real accelerator-owned `+0xe8`/`+0xcc`-bounded ID
     * table `set_id_mode` uses, and the SAME `id*8+0xd60/+0xd64` per-ID
     * tracking-record array and `id*0x94+0xcac`/`id*0x78+0x142` per-ID
     * arrays that function also touches - genuinely the same "ID"
     * concept in both functions, not a coincidental same-looking
     * parameter. See Sources/IOATIR500Surface_LockShape.cpp for the full
     * transcription.
     */
    IOReturn set_shape_backing_length_ext(UInt32 shapeBits, UInt32 id, UInt32 param3, UInt32 param4,
                                           IOAccelDeviceRegion *region, UInt32 param6, UInt32 param7);

    /*
     * reset_req_bits / reset_access / prune_buffers / update_contexts /
     * delete_buffer_backing - RESOLVED, issue #8: real names/signatures
     * (real mangled symbols, all already-existing real methods on this
     * class found via real call sites in set_id_mode/
     * set_shape_backing_length_ext) - own bodies NOT independently
     * decompiled this pass (peripheral to those two functions' own real
     * structure, consistent with this project's treatment of similar
     * small opaque helper calls elsewhere).
     */
    void reset_req_bits(void);
    void reset_access(void);
    void prune_buffers(void);
    void update_contexts(void);
    void delete_buffer_backing(IOTextureBuffer *buffer);

    /*
     * set_dvd_context / remove_dvd_context - RESOLVED (issue #42
     * test-harness pass), real names/signatures confirmed via real
     * mangled symbols (__ZN16IOATIR500Surface15set_dvd_contextEP19IOATIR500DVDContext
     * @ 0x10bc0, __ZN16IOATIR500Surface18remove_dvd_contextEP19IOATIR500DVDContext
     * @ 0x13de0), found while decompiling IOATIR500DVDContext::
     * set_surface (Sources/IOATIR500DVDContext_SetSurface.cpp) to resolve
     * a real wire-shape discrepancy. Own bodies NOT independently
     * decompiled this pass (peripheral helpers, same treatment as the
     * other small opaque helpers just above).
     */
    void set_dvd_context(IOATIR500DVDContext *context);
    void remove_dvd_context(IOATIR500DVDContext *context);

    /*
     * surface_lock_options / surface_unlock_options - CONFIRMED real
     * names/signatures (real mangled symbols
     * __ZN16IOATIR500Surface20surface_lock_optionsE9eLockTypemP18IOAccelSurfaceDatam /
     * __ZN16IOATIR500Surface22surface_unlock_optionsE9eLockTypem), the
     * shared internal helpers every real lock/unlock external method
     * above forwards into (lockType 1=read, 2=write). `eLockType`
     * modeled as `UInt32` (a real Apple IOAcceleratorFamily enum, not
     * reconstructed here). STALE COMMENT FIXED (issue #42 test-harness
     * pass): this used to say "bodies NOT independently decompiled this
     * pass" - both real, complete bodies were already decompiled and
     * committed in the original get-it-linking pass (see
     * Sources/IOATIR500Surface_LockOptions.cpp) well before this
     * comment was last touched; the claim was simply never updated
     * afterward. `surface_lock_options`'s own real body also gives a
     * byte-exact PARTIAL layout for Apple's own `IOAccelSurfaceData`
     * (still forward-declared only, not fully reconstructed) - see that
     * source file's own header comment for the real per-offset writes,
     * including real pixel-format FourCC codes ('yuvs'/'2vuy').
     */
    IOReturn surface_lock_options(UInt32 lockType, UInt32 param2, IOAccelSurfaceData *data, UInt32 size);
    IOReturn surface_unlock_options(UInt32 lockType, UInt32 param2); /* RETURN TYPE CORRECTED (issue #1, get-it-linking pass): was void, but the real confirmed body returns a real IOReturn status. */

    /*
     * free_buffer_backing_orphans - CONFIRMED to exist (real call site
     * in surface_unlock_options, issue #1 get-it-linking pass) - the
     * real "drain the single pending-eviction slot at +0xd8c"
     * counterpart `free_buffer_backing_store` defers into. Own body
     * NOT independently decompiled this pass.
     */
    void     free_buffer_backing_orphans(void);

    /*
     * surface_write_lock_int / surface_write_unlock_int - RESOLVED
     * (issue #8), fully transcribed (real kext offsets 0x114a0/0x11540)
     * - see Sources/IOATIR500Surface_LockShape.cpp. Real internal
     * per-buffer lock/unlock helpers indexed by a mip/buffer index, used
     * around GPU-visible surface-buffer access; real vtable calls at
     * +0x5fc/+0x600 (names UNKNOWN) plus real completion-counter
     * bookkeeping via a vtable call at +0x558 on this+0xd50 (the same
     * "accelerator-ish" pointer other IOATIR500Surface methods reach
     * through).
     */
    void surface_write_lock_int(UInt32 bufferIndex, UInt32 *outParam2, UInt32 *outParam3);
    void surface_write_unlock_int(UInt32 bufferIndex);

    /* RE-HOMED (issue #16): the overlay/subpicture/deinterlace family
     * (disable_overlay/enable_overlay/showbuffer/dvd_setup_subpicture/
     * dvd_setup_overlay/enable_deint) moved to the real subclass,
     * Headers/ATIR500Surface.h - real mangled symbols confirm they're
     * ATIR500Surface:: receivers, not this base class. */

    /*
     * alloc_surfaces / alloc_surfaces_retry - CONFIRMED real names, called
     * throughout the lock/swap/read family above whenever a surface needs
     * on-demand backing allocation. Body UNKNOWN beyond that role.
     */
    IOReturn alloc_surfaces(bool retry);
    IOReturn alloc_surfaces_retry(UInt32 flags, UInt32 param2);

    /* flush_surface / set_scaling / set_volatile_state / set_surface_blocking -
     * CONFIRMED real names from various call sites across this project (the
     * GL context's scale_surface for set_scaling/set_volatile_state). Bodies
     * UNKNOWN beyond their roles. */
    void     flush_surface(UInt32 param1, UInt32 param2);
    /* FIXED this pass: the real opcode 0x30 call site
     * (ATIR500GLContext_ProcessCommandBuffer.cpp's handle_fsaa_resolve_setup)
     * passes FOUR trailing dwords (puVar65[4..7]) after clearFlag, not
     * three - this signature previously dropped one parameter. RE-HOMED
     * (issue #16): resolve_fsaa_buffer itself moved to the real subclass,
     * Headers/ATIR500Surface.h. */
    IOReturn set_scaling(UInt32 flags, IOAccelSurfaceScaling *scaling);
    void     set_volatile_state(UInt32 state); /* SIGNATURE CORRECTED (issue #1, get-it-linking pass): was `UInt32 *state` (a pointer) - the real confirmed body takes the state value directly (real mangled type `eSurfaceVolatileState`, a plain enum/int), never dereferences a pointer. */
    IOReturn set_surface_blocking(UInt32 blockingMode);

    /* RE-HOMED (issue #16): decompress_and_flush_depth_buffer moved to
     * the real subclass, Headers/ATIR500Surface.h - real mangled symbol
     * confirms it's an ATIR500Surface:: receiver, not this base class. */

    /* add_gl_context_to_list / remove_gl_context_from_list - CONFIRMED
     * real names (a surface tracks which GL contexts currently reference
     * it). Bodies UNKNOWN beyond that role. */
    void add_gl_context_to_list(IOATIR500GLContext *context);
    void remove_gl_context_from_list(IOATIR500GLContext *context);

    /*
     * invalidate_contexts - RESOLVED (issue #1, get-it-linking pass),
     * real addr 0x12050. Zeroes the accelerator's own `+0x78` field
     * (real role unconfirmed), then walks two singly-linked context
     * lists (`this+0x8c`, `this+0x88` - next pointer at each node's own
     * `+0x84`) calling each node's own vtable `+0x5a4` (the already-
     * established `invalidate()` slot on `ATIR500GLContext`; other real
     * node types at this same raw offset/slot not independently
     * confirmed), then the same call on a single node at `this+0x90` if
     * non-null.
     */
    void invalidate_contexts(void);

    /*
     * alloc_surfaces_pageq - RESOLVED (issue #1, get-it-linking pass),
     * real addr 0x12110. SECOND PARAMETER TYPE CORRECTED from `bool` to
     * `UInt32`: the real decompile ANDs it directly against a per-bit
     * `1 << bitIndex` mask (a real `CONCAT31` register-reconstruction
     * artifact around it - Ghidra's own hint that the real caller
     * passes a full 32-bit value, not a true 0/1 boolean) when deciding
     * each page-queue bit's own "force" sub-flag - a real bitmask
     * intersected bit-by-bit against `mask`'s own selected bits, not a
     * single global boolean. Existing call sites (`alloc_surfaces_
     * retry`) already only ever pass literal `false`/0, so this
     * correction doesn't change their behavior.
     *
     * Real body: invalidates every bound context via
     * `invalidate_contexts()`, then tries an unnamed real vtable
     * `+0x5f4` slot for every bit `mask` shares with this surface's own
     * `+0xbf8` state-bits field (own identity NOT independently
     * confirmed - referenced only by raw offset in the real decompile).
     * If every tried bit succeeds, returns 0 (nothing more to do). If
     * any bit fails, first bails with 1 if any live surface in the
     * accelerator's own surface list (`accelerator+0x5c`) has its own
     * `+0xbd0` field set; otherwise walks this surface's own 23-entry
     * buffer array (`this+0xa8`, stride 0x78) moving every buffer whose
     * own `+8` flag is set to backing store via
     * `move_buffer_to_backing_store`, then retries the same `+0x5f4`
     * bit sweep once more if anything was actually moved. Returns 2 if
     * the retry (or the original attempt, when nothing needed moving)
     * still didn't fully succeed.
     */
    UInt32 alloc_surfaces_pageq(UInt32 mask, UInt32 flag);

    /*
     * convert_surface_bits - RESOLVED (issue #1, get-it-linking pass),
     * real addr 0x12320. RETURN TYPE CORRECTED from `bool` to `UInt32`:
     * the real decompile returns a real accumulated bitmask, not a
     * true/false value - this project's own prior inference (from call
     * sites alone, before this pass independently decompiled the real
     * body) was wrong. Its real result feeds directly into
     * `alloc_surfaces_pageq`'s own `flag` parameter (itself already
     * corrected from `bool` to `UInt32` this same pass, for the
     * identical reason) - see `Sources/
     * IOATIR500Surface_ConvertSurfaceBits.cpp` for the full real body.
     */
    UInt32 convert_surface_bits(UInt32 selectorBits);
    void   sleep_blocked(void);

    /* connect_buffer_backing_store / free_buffer_backing_store /
     * attach_buffer_backing_store / surface_buffer_idx_mask - CONFIRMED
     * real names, the real per-surface-buffer backing-store lifecycle used
     * throughout the 2D/GL texture-transfer paths (create_transfer,
     * delete_image, opcode 0x37's surface-backed branch). Bodies UNKNOWN
     * beyond their roles. */
    bool     connect_buffer_backing_store(ATIR500SurfaceBuffer *buffer, UInt32 param2, UInt32 param3); /* RETURN TYPE CORRECTED (issue #1, get-it-linking pass): was IOReturn, but the real confirmed body is a plain bool __thiscall function. */
    UInt32   free_buffer_backing_store(ATIR500SurfaceBuffer *buffer); /* RETURN TYPE CORRECTED (issue #1, get-it-linking pass): was void, but the real confirmed body ends with `return 1;` from a real UInt32-returning function. */
    UInt32   attach_buffer_backing_store(ATIR500SurfaceBuffer *buffer, IOMemoryDescriptor *memory,
                                          UInt32 param3, UInt32 alignedPitch); /* RETURN TYPE CORRECTED (issue #1, get-it-linking pass): was void, but the real confirmed body returns a real UInt32 (0 or 1). */
    UInt32   surface_buffer_idx_mask(UInt32 param1, UInt32 *outParam);

    /*
     * copy_buffer_to_backing_store - CONFIRMED real name (found issue
     * #22, ATIR500Surface::shape_surface's own deinterlace-plane reshape
     * path). Own body RESOLVED, issue #36 - see
     * Sources/IOATIR500Surface_CopyBufferToBackingStore.cpp. REAL RETURN
     * TYPE CORRECTED there: the real decompile returns a genuine `1`/`0`
     * result (not `void` as this project had previously assumed by
     * analogy with `free_buffer_backing_store`).
     */
    bool copy_buffer_to_backing_store(ATIR500SurfaceBuffer *buffer);

    /*
     * alloc_surfaces_keep - CONFIRMED real name/signature, found this
     * pass as a real call site in ATIR500GLContext::alloc_and_load_texture
     * (issue #5) - see Sources/ATIR500GLContext_TextureLoad.cpp. Real
     * call shape: `alloc_surfaces_keep(surface, ctx-owned surface ptr,
     * ctx's 42-entry texture-slot array, 0x2a, a real bitmask)` - the
     * same "exclude list + count" shape freeToAllocTextureVRAM uses. Own
     * body NOT independently decompiled this pass.
     */
    UInt32 alloc_surfaces_keep(IOATIR500Surface *excludeSurface, VendorTextureBuffer **excludeList,
                                SInt32 excludeCount, UInt32 mask);

    /*
     * move_buffer_to_backing_store / copy_buffer_from_backing_store -
     * CONFIRMED real names/signatures, found this pass as real call
     * sites in ATIR500GLContext::compact_current_textures (issue #5) -
     * see Sources/ATIR500GLContext_TextureLoad.cpp. move_buffer's
     * return value (if any) is discarded at every real call site seen
     * this pass; copy_buffer's real return IS checked at one real call
     * site (a success/failure indicator). Neither body independently
     * decompiled this pass.
     */
    bool   move_buffer_to_backing_store(ATIR500SurfaceBuffer *buffer); /* RETURN TYPE CORRECTED (issue #1, get-it-linking pass): was void, but the real confirmed body returns copy_buffer_to_backing_store's own real bool result. */
    UInt32 copy_buffer_from_backing_store(ATIR500SurfaceBuffer *buffer);
    /* FIXED this pass: real call site (opcodes 0x06-0x15's texture-bind
     * handler, ATIR500GLContext_ProcessCommandBuffer.cpp) passes TWO
     * explicit arguments (both real 32-bit `ulong` values on this PPC32
     * target, not 64-bit) - this declaration previously dropped both. */

    /*
     * Five real vtable slots - RESOLVED, issue #18. Declared HERE on the
     * base rather than on `ATIR500Surface` (the concrete subclass)
     * because every real call site reaches them through a base-typed
     * `IOATIR500Surface *`/`this` pointer via ordinary virtual dispatch
     * (`Sources/ATIR500GLContext_TextureLoad.cpp`'s `evictSurfaceBuffers`,
     * `Sources/IOATIR500Surface_LockShape.cpp`'s
     * `surface_write_lock_int`/`unlock_int`) - C++ requires the
     * declaration live wherever the call is actually written, and virtual
     * dispatch then reaches whichever class's real override actually
     * exists at runtime. Real names/addresses found by reading
     * `ATIR500Surface`'s own vtable (`__ZTV14ATIR500Surface`, `0x4bbe0`)
     * directly - the same technique that resolved issue #6/#19's
     * accelerator slots.
     *
     * `invalidate` exists ONLY as a subclass override (this base class's
     * own copy of that vtable slot is genuine placeholder content, raw
     * 0) - the same real per-context dirty-bit override pattern
     * `ATIR500GLContext::invalidate` already established (issue #12.1).
     * The other four ALSO have their own, different, real bodies on this
     * base class (`dealloc_surface` at real addr `0x12580`,
     * `alloc_surface_buffer` unresolved on the base - raw 0,
     * `prepare_vram`/`complete_vram` at `0x110e0`/`0x110f0`) - but since
     * every real Surface object in this driver is the concrete
     * `ATIR500Surface` subclass (issue #16), the subclass's own override
     * bodies (`0x3df70`/`0x3e230`/`0x3dc50`/`0x3c000` respectively) are
     * the ones real callers actually reach. None of the seven real
     * bodies (base or subclass) independently decompiled this pass -
     * only the vtable slot values/real names were in scope for issue
     * #18.
     */
    /*
     * update_ref_stamps / increment_refcounts / decrement_refcounts -
     * RESOLVED, issue #18/#22. Three more real vtable slots, called from
     * `IOATIR500GLContext::remove_texture_from_stream`/
     * `add_texture_to_stream` (`Sources/IOATIR500GLContext_TextureStream.cpp`)
     * against a texture's own `+0x50`-field Surface pointer. Unlike the
     * five below, these are NOT subclass overrides - `ATIR500Surface`'s
     * own vtable has the identical addresses at these three slots as the
     * base, confirming this base class's own bodies are what every real
     * caller reaches either way. Real bodies (issue #22) CONFIRMED to be
     * genuine NO-OPS - real, previously-unknown finding, matching the
     * same "real empty stub" pattern already found for the overlay
     * family (`Sources/ATIR500Surface_Overlay.cpp`). `update_ref_stamps`
     * still has a real, non-void return type (returns its own second
     * argument verbatim) even though neither real caller uses it.
     */
    virtual UInt32 update_ref_stamps(UInt32 generation, UInt32 tag); /* +0x5b4, real addr 0x13fe0 - CONFIRMED real no-op, returns tag verbatim */
    virtual void   increment_refcounts(UInt32 tag);                  /* +0x5b8, real addr 0x13ff0 - CONFIRMED real no-op */
    virtual void   decrement_refcounts(UInt32 tag);                  /* +0x5bc, real addr 0x14000 - CONFIRMED real no-op */

    virtual void   invalidate() = 0;                                /* +0x5c4, real addr 0x3acb0 on ATIR500Surface (subclass-only). FIXED (issue #1, get-it-linking pass): pure virtual - confirmed subclass-only real address, no real base body to decompile. */
    virtual UInt32 dealloc_surface(UInt32 surfaceIndex);            /* +0x5cc, real addr 0x12580 (base) / 0x3df70 (subclass override) - real mangled param type confirmed `unsigned long`. RETURN TYPE CORRECTED (issue #1, first build attempt): the subclass override's own real decompiled body (Sources/ATIR500Surface_VRAM.cpp) ends with `return 1;` from a real `UInt32`-returning function - was declared `void` here, missing the same issue #22 "RETURN TYPE CORRECTED" treatment already applied to prepare_vram/complete_vram just below. */
    virtual UInt32 alloc_surface_buffer(ATIR500SurfaceBuffer *buffer) = 0; /* +0x5d0, real addr 0x3e230 on ATIR500Surface (subclass-only) - real mangled param type confirmed. FIXED (issue #1, get-it-linking pass): pure virtual - confirmed subclass-only real address, no real base body to decompile. */
    virtual UInt32 prepare_vram(ATIR500SurfaceBuffer *buffer);      /* +0x5fc, real addr 0x110e0 (base) / 0x3dc50 (subclass override) - real mangled param type confirmed ATIR500SurfaceBuffer*, not the generic void* this project's call sites had inferred. RETURN TYPE CORRECTED, issue #22: real return type is a real, checked UInt32 (0/1), not void - both real bodies' own decompiles show explicit `return` statements with real values. */
    virtual UInt32 complete_vram(ATIR500SurfaceBuffer *buffer);     /* +0x600, real addr 0x110f0 (base) / 0x3c000 (subclass override) - real mangled param type confirmed ATIR500SurfaceBuffer*, not the generic void* this project's call sites had inferred. RETURN TYPE CORRECTED, issue #22: same real non-void finding as prepare_vram above. */

    /*
     * resetFullScreen / is_flip_allowed - RESOLVED, issue #18 (found
     * while wiring in the rest of that issue - `set_id_mode`
     * (`Sources/IOATIR500Surface_LockShape.cpp`) calls both through raw
     * `Fn0x5a8`/`Fn0x5dc` vtable-offset casts this project had never
     * flagged with an explicit "names UNKNOWN" note, so they weren't in
     * that issue's original enumeration - same real gap regardless, same
     * resolution technique). Both real names ALREADY declared-sounding
     * enough that they were presumably assumed resolved somewhere -
     * confirmed here they were not actually declared anywhere in this
     * project before now. Both exist as real, different bodies on base
     * and subclass; every real Surface object is the concrete
     * `ATIR500Surface` subclass (issue #16), so the subclass bodies
     * (`0x3cf60`/`0x3ae30`) are what real callers reach.
     */
    virtual void   resetFullScreen();                               /* +0x5a8, real addr 0x139d0 (base) / 0x3cf60 (subclass override) */
    virtual SInt32 is_flip_allowed();                                /* +0x5dc, real addr 0x13f60 (base) / 0x3ae30 (subclass override) */

    /*
     * submit_flip_buffer - RESOLVED, issue #29. `resetFullScreen`'s own
     * `+0x5e0` call (flagged "still-uncatalogued" when found during the
     * `shape_surface` pass, issue #22) - resolved via the same
     * concrete-subclass-vtable technique that closed issues #6/#18/#19:
     * the BASE class's own `+0x5e0` slot is genuine placeholder content
     * (raw 0), but the concrete `ATIR500Surface` subclass's own vtable
     * has a real override at the same offset, real addr `0x3e5c0`, real
     * mangled symbol `__ZN14ATIR500Surface18submit_flip_bufferEmP18IOATIR500GLContextm`.
     * Declared on the base since the real call site (`resetFullScreen`,
     * below) uses a base-typed pointer with ordinary virtual dispatch,
     * matching this project's established convention for this exact
     * situation. Own body not independently decompiled - own real
     * behavior UNKNOWN beyond the real signature confirmed here.
     *
     * INDEPENDENTLY RE-CONFIRMED, issue #51: the "genuine placeholder
     * content (raw 0)" claim above had never actually been verified by a
     * direct read of the base vtable - re-checked this pass by reading
     * the compiled `__ZTV16IOATIR500Surface` vtable directly (real kext
     * address `0x486d8`; real function-pointer array starts 8 bytes past
     * the mangled symbol per the standard Itanium ABI layout, matching
     * this project's own `vtable[N/4]` convention). CONFIRMED: the real
     * byte content at `+0x5e0` is exactly `0` - cross-validated in the
     * same read by also fetching the immediately-neighboring, already-
     * known-correct slots `resetFullScreen` (`+0x5a8`, read back exactly
     * `0x139d0`) and `is_flip_allowed` (`+0x5dc`, read back exactly
     * `0x13f60`), both exact matches, confirming the offset arithmetic
     * before trusting the previously-unverified `+0x5e0` read. Since
     * every real object in this driver is the concrete `ATIR500Surface`
     * subclass (issue #16), this base-only null is never actually
     * reachable in practice - no placeholder body is needed, and no live
     * hardware read was required to settle this.
     */
    virtual void   submit_flip_buffer(UInt32 id, IOATIR500GLContext *context, UInt32 flag) = 0; /* +0x5e0, real addr CONFIRMED null/0 (base, genuine placeholder - issue #51) / 0x3e5c0 (subclass override). FIXED (issue #1, get-it-linking pass): declared pure virtual - confirmed no real base body exists; the concrete ATIR500Surface subclass provides the real override. Previously left non-pure with no redeclaration on the subclass, which would have compiled `resetFullScreen`'s own unqualified `submit_flip_buffer(...)` call against THIS placeholder slot instead of the real subclass override - see ATIR500Surface.h's own new redeclaration. */

    /*
     * shape_surface / is_surface_size_supported - RESOLVED, issue #18
     * (found while wiring in the rest of that issue -
     * `set_shape_backing_length_ext` calls both through raw
     * `Fn0x5c8`/`Fn0x5b0` casts, same real gap regardless of not being in
     * that issue's original enumeration). `shape_surface` is
     * subclass-only (base's own copy of this vtable slot is genuine
     * placeholder content, raw 0), matching `invalidate`'s pattern above.
     * `is_surface_size_supported`'s real mangled parameter types are
     * `short` (not the `SInt32` this project's call site had inferred).
     */
    virtual void   shape_surface() = 0;                                       /* +0x5c8, real addr 0x3c130 on ATIR500Surface (subclass-only) - RESOLVED (own body, issue #22): see Sources/ATIR500Surface_ShapeSurface.cpp. FIXED (issue #1, get-it-linking pass): pure virtual - confirmed subclass-only real address, no real base body to decompile. */
    virtual SInt32 is_surface_size_supported(SInt16 width, SInt16 height);   /* +0x5b0, real addr 0x13fb0 (base) / 0x3aef0 (subclass override) - real mangled param types confirmed `short` */

    /*
     * map_transfer_to_GART - RESOLVED, issue #28. A DIFFERENT real
     * function from `IOATIR500GLContext::map_transfer_to_GART` (same
     * real name, different real receiver class - confirmed via Ghidra's
     * own class-qualified decompile naming, not assumed), but
     * structurally identical: calls `addTransferToGART` then
     * unconditionally `freeToAllocGART` - see
     * `Sources/MapTransferToGART_RemainingContexts.cpp`.
     */
    void map_transfer_to_GART(VendorTransferBuffer *buffer);

    /*
     * freeToAllocGART - RESOLVED (issue #1, get-it-linking pass), real
     * addr 0x10c60. Iterates every accelerator-wide "surface swap
     * buffer" slot (`accelerator+0xcc` count, `accelerator+0x114+idx*4`
     * per-surface-index gating, this surface's own `+idx*0x94+0xc30`/
     * `+idx*0x94+0xc20`/`+idx*0x94+0xc3c`/`+idx*0x94+0xc4c` nested
     * arrays - own exact field semantics beyond "candidate transfer
     * buffer slot" not independently investigated this pass), then a
     * final flat array walk at `this+0xcc` (stride 0x78, arg via the
     * node's own `clientShared+8`, matching the established
     * `VendorTextureBuffer+0x14` clientShared-pointer convention), all
     * via `IOATIR500Accelerator::freeTransferToAllocGART`.
     */
    bool freeToAllocGART(VendorTransferBuffer *needed, bool aggressive);

    /*
     * init_swap_buffer_header - RESOLVED, issue #28 (real mangled symbol
     * __ZN16IOATIR500Surface23init_swap_buffer_headerEP22VendorSwapBufferHeaderm,
     * real addr 0x10b40), found decompiling `allocAllSlaveSwapBuffers`
     * below. Own body RESOLVED, issue #37 - see
     * Sources/IOATIR500Surface_InitSwapBufferHeader.cpp.
     */
    void init_swap_buffer_header(VendorSwapBufferHeader *header, UInt32 size);

    /*
     * allocAllSlaveSwapBuffers - RESOLVED, issue #28, real addr 0x11e50 -
     * see `Sources/IOATIR500Surface_AllocAllSlaveSwapBuffers.cpp` for the
     * full transcription. Follow-up investigation CONFIRMED (not just
     * suspected) a real infinite loop in Apple's own driver on this
     * function's allocation-failure path - a genuine, latent vendor bug,
     * not a transcription gap.
     */
    UInt32 allocAllSlaveSwapBuffers(UInt32 param1, UInt32 param2);

    /*
     * freeAllSwapBuffers / allocMasterSwapBuffer - CONFIRMED real names
     * (found alongside `allocAllSlaveSwapBuffers` in `setup_stereo`'s own
     * real live-surface notification loop,
     * `Sources/IOATIR500Accelerator_SetupStereo.cpp`). Own bodies
     * RESOLVED, issue #31 - see Sources/IOATIR500Surface_SwapBuffers.cpp
     * (real addrs 0x10860/0x118e0).
     */
    void freeAllSwapBuffers(UInt32 param1);
    bool allocMasterSwapBuffer(UInt32 param1, UInt32 param2);

protected:
    /*
     * FIXED (issue #56): these three fields were declared in discovery
     * order with no padding scaffolding - reordered into true ascending
     * real-offset order with a leading pad from this class's own start
     * (IOUserClient is the real base) and a pad array in every real gap.
     */
    UInt8 _pad_0x00[0x88];

    /* contextListHeadA/B - FIXED (issue #42 test-harness pass, "fix real
     * layout bugs found" policy): these two offsets were previously
     * buried in the opaque `_pad_0x00` blob, but `reset_req_bits`/
     * `update_contexts` (Sources/IOATIR500Surface_ContextTracking.cpp)
     * already walk both as real singly-linked lists (next-link at each
     * node's own +0x84, a real "requirement bits" field at +0x8c) -
     * almost certainly one per-GL-context and one per-2D-context
     * reference list (a surface can be bound to multiple GL/2D contexts
     * simultaneously, unlike DVD's single-owner binding below), but which
     * is which is NOT independently confirmed - named generically rather
     * than guessed. Real node type also not reconstructed (declared as
     * `void*`, matching this project's established treatment of other
     * not-fully-typed opaque linked-list nodes). */
    void *contextListHeadA; /* +0x88 */
    void *contextListHeadB; /* +0x8c */

    /* boundDVDContext - FIXED (issue #42 test-harness pass): CONFIRMED
     * via real decompile of IOATIR500DVDContext::set_surface (Sources/
     * IOATIR500DVDContext_SetSurface.cpp), which reads/writes this
     * surface's own `this+0x90` as a plain `IOATIR500DVDContext*` - the
     * single currently-bound DVD context (DVD binding is real 1:1, unlike
     * the GL/2D linked lists just above), set via `set_dvd_context`/
     * cleared via `remove_dvd_context`. */
    IOATIR500DVDContext *boundDVDContext; /* +0x90 */

    UInt8 _pad_0x94[0xb70 - 0x94];

    /* Both found this pass (issue #13, ATIR500Surface::resolve_fsaa_buffer)
     * - real per-attachment `ATIR500SurfaceBuffer*` pointers, the same
     * struct restore_state_destroyed_by_pageoff's own per-mip array
     * already established (ATIRadeonX1000Types.h). Neither offset was
     * previously documented anywhere in this class. `surfaceBuffersByFormat`
     * is real base address `this+0xb70`, indexed `[formatCode]` (real
     * element count not independently confirmed - declared as a pointer
     * to the base rather than a fixed-size array for that reason; real
     * access is `surfaceBuffersByFormat[formatCode]`, matching the real
     * `*(int*)(this + formatCode*4 + 0xb70)` decompile expression). */
    ATIR500SurfaceBuffer **surfaceBuffersByFormat; /* +0xb70, CONFIRMED base address */
    UInt8 _pad_0xb74[0xb94 - 0xb74];
    ATIR500SurfaceBuffer *fixedSurfaceBuffer;       /* +0xb94, CONFIRMED: a single real `ATIR500SurfaceBuffer*`, always read regardless of the caller's own format-code argument - the "primary"/depth-or-stencil-style attachment resolve_fsaa_buffer treats as fixed rather than per-format-code. */
    UInt8 _pad_0xb98[0xd50 - 0xb98];
    ATIRadeonX1000 *accelerator; /* +0xd50, CONFIRMED offset (surface_control/surface_flush/etc. all reach hardware through `*(int*)(this+0xd50)`). CORRECTED to the concrete ATIRadeonX1000 type - see ATIRadeonX1000.h's real-Info.plist correction note. */

    /*
     * lastFlipFlag/vramInitSucceeded/methodTable - FIXED (issue #42
     * test-harness pass): three real fields found via `IOATIR500Surface::
     * start`'s own real decompile (real addr 0x119f0 - the base class's
     * OWN start, distinct from the subclass ATIR500Surface::start which
     * calls it via vtable; this base start() is itself a large,
     * substantial real function - real VRAM-descriptor/master-swap-buffer
     * setup plus ~80 other field initializations - NOT fully transcribed
     * this pass, tracked as its own real gap, see issue filed for it).
     * `lastFlipFlag` (+0xd54) is ALSO independently referenced in
     * Sources/ATIR500Surface_SubmitFlipBuffer.cpp (a real "compare
     * against caller's flag, update if different" pattern) - real
     * semantic role beyond that UNKNOWN. `vramInitSucceeded` (+0xd58) is
     * set to 1 only on start()'s own real VRAM-descriptor-setup success
     * path. `methodTable` (+0xd5c) is THE real external-method dispatch
     * table pointer `ATIR500Surface::getTargetAndMethodForIndex`
     * (Headers/ATIR500Surface.h) reads - CONFIRMED via the real
     * instruction `stw r2,0xd5c(r31)` in start() setting it to the real
     * static table's own absolute address (0x48d60) - see
     * Sources/ATIR500Surface_ExternalMethods.cpp.
     */
    UInt32 lastFlipFlag;      /* +0xd54 */
    UInt32 vramInitSucceeded; /* +0xd58 */
    void   *methodTable;      /* +0xd5c */
};

#endif /* IOATIR500SURFACE_H */
