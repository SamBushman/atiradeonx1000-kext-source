/*
 * IOATIR500Surface.h
 *
 * The shared display-surface bookkeeping class - window-server-style
 * lock/shape/backing-store management, referenced by every other context
 * class when a surface is bound. Real dispatch shape
 * (ATIR500Surface::getTargetAndMethodForIndex, kext offset 0x3ac80): a
 * single flat 19-entry table (selectors 0-18) at this+0xd5c - the simplest
 * dispatch shape of the four context classes (no special/extra split).
 *
 * Confidence: selector numbers/names/addresses CONFIRMED from raw kext
 * bytes. Bodies for the video-relevant subset (dvd_setup_overlay,
 * enable_overlay/disable_overlay, showbuffer, enable_deint,
 * dvd_setup_subpicture) CONFIRMED via direct decompilation
 * (stage8-dvd-overlay-and-2d-acceleration-decoded.md) - this is where
 * this project found the significant "hardware overlay path is mostly
 * vestigial" result. The remaining lock/shape family was sampled, not
 * exhaustively decompiled (stage10-ga-plugin-full-interface-and-va-driver-confirmed.md).
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

    /*
     * ---- Video/overlay-adjacent real methods, called from
     * IOATIR500DVDContext, NOT external methods of this class themselves ----
     * CONFIRMED bodies, stage8-dvd-overlay-and-2d-acceleration-decoded.md.
     * This is where this project found its most significant unexpected
     * result for the H.264 project: three of these five are REAL, EMPTY
     * NO-OPS in this exact kext build.
     */
    void     disable_overlay(void);   /* CONFIRMED: real empty no-op */
    void     enable_overlay(void);    /* CONFIRMED: real empty no-op */
    void     showbuffer(UInt32 bufferIndex, UInt32 param2); /* CONFIRMED: real empty no-op */
    void     dvd_setup_subpicture(UInt32 param1, UInt32 param2, UInt32 param3); /* CONFIRMED: real empty no-op */
    void     dvd_setup_overlay(UInt32 x, UInt32 y, UInt32 w, UInt32 h); /* CONFIRMED: the one real, non-stub member of this family - stores x/y/w/h into this+0x94/0x96/0x98/0x9a and sets a dirty flag at this+0xd94 */
    void     enable_deint(UInt32 mode); /* CONFIRMED: real, stores mode into this+0xdac; nothing this project decompiled reads it back */

    /*
     * alloc_surfaces / alloc_surfaces_retry - CONFIRMED real names, called
     * throughout the lock/swap/read family above whenever a surface needs
     * on-demand backing allocation. Body UNKNOWN beyond that role.
     */
    IOReturn alloc_surfaces(bool retry);
    IOReturn alloc_surfaces_retry(UInt32 flags, UInt32 param2);

    /* flush_surface / resolve_fsaa_buffer / set_scaling / set_volatile_state /
     * set_surface_blocking - CONFIRMED real names from various call sites
     * across this project (stage4's opcode 0x30 trace for
     * resolve_fsaa_buffer; the GL context's scale_surface for
     * set_scaling/set_volatile_state). Bodies UNKNOWN beyond their roles. */
    void     flush_surface(UInt32 param1, UInt32 param2);
    void    *resolve_fsaa_buffer(UInt32 surfaceIndex, UInt32 formatCode, void *paramBlock,
                                  bool clearFlag, UInt32 param5, UInt32 param6, UInt32 param7,
                                  UInt32 param8);
    /* FIXED this pass: the real opcode 0x30 call site
     * (ATIR500GLContext_ProcessCommandBuffer.cpp's handle_fsaa_resolve_setup)
     * passes FOUR trailing dwords (puVar65[4..7]) after clearFlag, not
     * three - this signature previously dropped one parameter. */
    IOReturn set_scaling(UInt32 flags, IOAccelSurfaceScaling *scaling);
    void     set_volatile_state(UInt32 *state);
    IOReturn set_surface_blocking(UInt32 blockingMode);

    /*
     * decompress_and_flush_depth_buffer - CONFIRMED real name, found this
     * pass (opcode 0x45's real body, kext offset in the 0x2ee.. range).
     * Real call shape: `decompress_and_flush_depth_buffer(surface,
     * surfaceBufferScratch, 0, record)` returning a real UInt32 (used as a
     * record-dword count/index in the caller). Same real subclass-
     * qualification note as `resolve_fsaa_buffer`/`surface_buffer_idx_mask`
     * above (real decompile types the receiver as the `ATIR500Surface`
     * subclass; declared here on the unified `IOATIR500Surface` per this
     * project's current, not-yet-split model - see GAPS.md section 8).
     */
    UInt32 decompress_and_flush_depth_buffer(ATIR500SurfaceBuffer *scratch, UInt32 param2, UInt32 *record);

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

protected:
    ATIRadeonX1000 *accelerator; /* +0xd50, CONFIRMED offset (surface_control/surface_flush/etc. all reach hardware through `*(int*)(this+0xd50)`). CORRECTED to the concrete ATIRadeonX1000 type - see ATIRadeonX1000.h's real-Info.plist correction note. */
};

#endif /* IOATIR500SURFACE_H */
