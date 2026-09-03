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
class IOTextureBuffer; /* real, opaque backing-store handle type - forward declared only, not reconstructed (Apple's own real type, same policy as IOAccelSurfaceData etc. below) */

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

public:
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
    IOReturn surface_read_unlock_options(void);                                /* 1 */
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
    IOReturn set_shape(void);                                                  /* 9, CONFIRMED body (stage10): a real one-line forward to set_shape_backing_length_ext (not itself a distinct external method - an internal helper name this project happened to see via the decompile) */
    IOReturn surface_flush(UInt32 param1, UInt32 param2);                      /* 10, CONFIRMED body (stage10): real - alloc_surfaces_retry then flush_surface, plus real completion-counter bookkeeping via a vtable call at offset 0x54c */
    IOReturn surface_query_lock(void);                                        /* 11, CONFIRMED body (stage10): real availability check without acquiring, using the same pending-GPU-flush bits as lock_memory */
    IOReturn surface_read_lock(IOAccelSurfaceData *data, UInt32 size);         /* 12, CONFIRMED body (stage10): thin forward to surface_lock_options(this, 1, 2, data, size) */
    IOReturn surface_read_unlock(void);                                       /* 13, CONFIRMED body (stage10): thin forward to surface_unlock_options(this, 1, 2) */
    void     surface_write_lock(IOAccelSurfaceData *data, UInt32 size);       /* 14, RESOLVED this pass */
    void     surface_write_unlock(void);                                     /* 15, RESOLVED this pass */
    IOReturn surface_control(UInt32 selector, UInt32 param2, UInt32 *inOut);   /* 16, CONFIRMED body (stage10): real dispatcher - param2==1 -> set_surface_blocking, param2==4 -> set_volatile_state, else kIOReturnBadArgument */
    IOReturn set_shape_backing_length(UInt32 shapeBits, UInt32 param2, UInt32 param3, UInt32 param4,
                                       UInt32 param5, IOAccelDeviceRegion *region); /* 17, RESOLVED (issue #8) */
    IOReturn surface_control_alias(UInt32 selector, UInt32 param2, UInt32 *inOut); /* 18, CONFIRMED to be a real, deliberate alias of selector 16 - same function address, not two implementations */

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
     * surface_lock_options / surface_unlock_options - CONFIRMED real
     * names/signatures (real mangled symbols
     * __ZN16IOATIR500Surface20surface_lock_optionsE9eLockTypemP18IOAccelSurfaceDatam /
     * __ZN16IOATIR500Surface22surface_unlock_optionsE9eLockTypem), the
     * shared internal helpers every real lock/unlock external method
     * above forwards into (lockType 1=read, 2=write). `eLockType`
     * modeled as `UInt32` (a real Apple IOAcceleratorFamily enum, not
     * reconstructed here). Bodies NOT independently decompiled this
     * pass - referenced by name in this project's comments for a while,
     * only now formally declared.
     */
    IOReturn surface_lock_options(UInt32 lockType, UInt32 param2, IOAccelSurfaceData *data, UInt32 size);
    void     surface_unlock_options(UInt32 lockType, UInt32 param2);

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
    void     set_volatile_state(UInt32 *state);
    IOReturn set_surface_blocking(UInt32 blockingMode);

    /* RE-HOMED (issue #16): decompress_and_flush_depth_buffer moved to
     * the real subclass, Headers/ATIR500Surface.h - real mangled symbol
     * confirms it's an ATIR500Surface:: receiver, not this base class. */

    /* add_gl_context_to_list / remove_gl_context_from_list - CONFIRMED
     * real names (a surface tracks which GL contexts currently reference
     * it). Bodies UNKNOWN beyond that role. */
    void add_gl_context_to_list(IOATIR500GLContext *context);
    void remove_gl_context_from_list(IOATIR500GLContext *context);

    /* connect_buffer_backing_store / free_buffer_backing_store /
     * attach_buffer_backing_store / surface_buffer_idx_mask - CONFIRMED
     * real names, the real per-surface-buffer backing-store lifecycle used
     * throughout the 2D/GL texture-transfer paths (create_transfer,
     * delete_image, opcode 0x37's surface-backed branch). Bodies UNKNOWN
     * beyond their roles. */
    IOReturn connect_buffer_backing_store(ATIR500SurfaceBuffer *buffer, UInt32 param2, UInt32 param3);
    void     free_buffer_backing_store(ATIR500SurfaceBuffer *buffer);
    void     attach_buffer_backing_store(ATIR500SurfaceBuffer *buffer, IOMemoryDescriptor *memory,
                                          UInt32 param3, UInt32 alignedPitch);
    UInt32   surface_buffer_idx_mask(UInt32 param1, UInt32 *outParam);

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
    void   move_buffer_to_backing_store(ATIR500SurfaceBuffer *buffer);
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

    virtual void   invalidate();                                   /* +0x5c4, real addr 0x3acb0 on ATIR500Surface (subclass-only) */
    virtual void   dealloc_surface(UInt32 surfaceIndex);            /* +0x5cc, real addr 0x12580 (base) / 0x3df70 (subclass override) - real mangled param type confirmed `unsigned long` */
    virtual UInt32 alloc_surface_buffer(ATIR500SurfaceBuffer *buffer); /* +0x5d0, real addr 0x3e230 on ATIR500Surface (subclass-only) - real mangled param type confirmed */
    virtual void   prepare_vram(ATIR500SurfaceBuffer *buffer);      /* +0x5fc, real addr 0x110e0 (base) / 0x3dc50 (subclass override) - real mangled param type confirmed ATIR500SurfaceBuffer*, not the generic void* this project's call sites had inferred */
    virtual void   complete_vram(ATIR500SurfaceBuffer *buffer);     /* +0x600, real addr 0x110f0 (base) / 0x3c000 (subclass override) - real mangled param type confirmed ATIR500SurfaceBuffer*, not the generic void* this project's call sites had inferred */

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
    virtual void   shape_surface();                                          /* +0x5c8, real addr 0x3c130 on ATIR500Surface (subclass-only) */
    virtual SInt32 is_surface_size_supported(SInt16 width, SInt16 height);   /* +0x5b0, real addr 0x13fb0 (base) / 0x3aef0 (subclass override) - real mangled param types confirmed `short` */

protected:
    ATIRadeonX1000 *accelerator; /* +0xd50, CONFIRMED offset (surface_control/surface_flush/etc. all reach hardware through `*(int*)(this+0xd50)`). CORRECTED to the concrete ATIRadeonX1000 type - see ATIRadeonX1000.h's real-Info.plist correction note. */

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
    ATIR500SurfaceBuffer *fixedSurfaceBuffer;       /* +0xb94, CONFIRMED: a single real `ATIR500SurfaceBuffer*`, always read regardless of the caller's own format-code argument - the "primary"/depth-or-stencil-style attachment resolve_fsaa_buffer treats as fixed rather than per-format-code. */
};

#endif /* IOATIR500SURFACE_H */
