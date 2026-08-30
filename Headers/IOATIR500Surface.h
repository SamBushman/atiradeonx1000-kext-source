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

class IOATIR500GLContext;

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

class IOATIR500Surface : public IOUserClient {
    OSDeclareDefaultStructors(IOATIR500Surface)

public:
    IOReturn surface_read_lock_options(void *inStruct, UInt32 size);          /* 0 */
    IOReturn surface_read_unlock_options(void);                                /* 1 */
    IOReturn get_state(UInt32 *outStateBits);                                  /* 2, CONFIRMED body (stage10): real vtable call at offset 0x520, maps to 0/1 */
    IOReturn surface_write_lock_options(void *inStruct, UInt32 size);          /* 3 */
    IOReturn surface_write_unlock_options(void);                               /* 4 */
    IOReturn surface_read(IOAccelSurfaceReadData *readData, UInt32 structSize); /* 5, CONFIRMED body (stage10): real clipped-readback pattern, identical shape to the GL context's read_buffer */
    IOReturn set_shape_backing(void *inStruct, UInt32 size);                   /* 6 */
    IOReturn set_id_mode(UInt32 mode);                                         /* 7 */
    IOReturn set_scale(UInt32 flags, UInt32 xScale, UInt32 yScale);            /* 8 */
    IOReturn set_shape(void);                                                  /* 9, CONFIRMED body (stage10): a real one-line forward to set_shape_backing_length_ext (not itself a distinct external method - an internal helper name this project happened to see via the decompile) */
    IOReturn surface_flush(UInt32 param1, UInt32 param2);                      /* 10, CONFIRMED body (stage10): real - alloc_surfaces_retry then flush_surface, plus real completion-counter bookkeeping via a vtable call at offset 0x54c */
    IOReturn surface_query_lock(void);                                        /* 11, CONFIRMED body (stage10): real availability check without acquiring, using the same pending-GPU-flush bits as lock_memory */
    IOReturn surface_read_lock(IOAccelSurfaceData *data, UInt32 size);         /* 12, CONFIRMED body (stage10): thin forward to surface_lock_options(this, 1, 2, data, size) */
    IOReturn surface_read_unlock(void);                                       /* 13, CONFIRMED body (stage10): thin forward to surface_unlock_options(this, 1, 2) */
    IOReturn surface_write_lock(IOAccelSurfaceData *data, UInt32 size);        /* 14 */
    IOReturn surface_write_unlock(void);                                      /* 15 */
    IOReturn surface_control(UInt32 selector, UInt32 param2, UInt32 *inOut);   /* 16, CONFIRMED body (stage10): real dispatcher - param2==1 -> set_surface_blocking, param2==4 -> set_volatile_state, else kIOReturnBadArgument */
    IOReturn set_shape_backing_length(UInt32 length);                         /* 17 */
    IOReturn surface_control_alias(UInt32 selector, UInt32 param2, UInt32 *inOut); /* 18, CONFIRMED to be a real, deliberate alias of selector 16 - same function address, not two implementations */

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
                                  bool clearFlag, UInt32 param6, UInt32 param7, UInt32 param8);
    IOReturn set_scaling(UInt32 flags, IOAccelSurfaceScaling *scaling);
    void     set_volatile_state(UInt32 *state);
    IOReturn set_surface_blocking(UInt32 blockingMode);

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
    UInt32   surface_buffer_idx_mask(void);

protected:
    void *accelerator; /* +0xd50, CONFIRMED offset (surface_control/surface_flush/etc. all reach hardware through `*(int*)(this+0xd50)`) */
};

#endif /* IOATIR500SURFACE_H */
