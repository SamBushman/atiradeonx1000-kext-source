/*
 * ATIR500GLContext.h
 *
 * The real 3D-pipeline subclass of IOATIR500GLContext. Owns the embedded
 * command-buffer processor (process_command_buffer), the full R580
 * register-state serializer (write_kernel_context_buffer_regs /
 * restore_state_destroyed_by_pageoff), and every function this project's
 * entire reveng effort has been built around.
 *
 * Confidence: see per-method notes. This is the single most thoroughly
 * decompiled class in the whole project - most of what's below is
 * CONFIRMED, with real gaps called out individually.
 */

#ifndef ATIR500GLCONTEXT_H
#define ATIR500GLCONTEXT_H

#include "IOATIR500GLContext.h"
#include "ATIRadeonX1000Registers.h"

struct r500_3d_blit_state_packet_struct;
struct register_tracking_state;
struct r500_zdecompress_restore_add_on_packet_struct;

class ATIR500GLContext : public IOATIR500GLContext {
    OSDeclareDefaultStructors(ATIR500GLContext)

public:
    /*
     * get_hw_info - CONFIRMED. The special 21st external method
     * (selector 20), reached via a DIFFERENT dispatch path than the
     * regular 0-19 table: getTargetAndMethodForIndex special-cases
     * selector==20 to return `*(int*)(this+0x360)` directly (a single,
     * statically-fixed IOExternalMethod-shaped record, not indexed into
     * an array) - see IOATIR500GLContext.h's regularMethodTable note for
     * the contrast. Real signature: 5 scalar outputs, no inputs.
     * ATIR500GLContext::start() (kext offset 0x28540) sets this pointer:
     *     *(undefined***)(this+0x360) = &start(IOService*)::methodDescs;
     * (a *different*, one-entry methodDescs than the base class's own
     * 20-entry table at +0x2a0 - transcribed in
     * Sources/ATIR500GLContext_ExternalMethods.cpp.)
     */
    IOReturn get_hw_info(UInt32 *out0, UInt32 *out1, UInt32 *out2, UInt32 *out3, UInt32 *out4);

    /*
     * getTargetAndMethodForIndex - CONFIRMED, transcribed directly from
     * the real decompile (kext offset 0x26db0) in
     * Sources/IOATIR500GLContext_ExternalMethods.cpp. Real signature
     * returns `int` (the raw table-entry address); reconstructed here to
     * return a typed pointer into the real static tables that source file
     * defines, which is the same real information expressed more safely.
     */
    virtual const VendorExternalMethod *getTargetAndMethodForIndex(IOService **target, UInt32 selector);

    /*
     * start / stop - CONFIRMED real behavior for start() (kext offset
     * 0x28540): zeroes a large block of per-instance state (this+0x34c..
     * this+0x400ish), initializes the six-entry texture-unit array at
     * this+0x3f0 (stride 0x78) to real defaults (blend/format bits),
     * initializes four swap-chain-related fields, sets the special
     * selector-20 methodDescs pointer described above, and finally calls
     * FUN_000286dc/ec (a lock-pair, real name UNKNOWN) around the base
     * class's own start(). stop() UNKNOWN - not decompiled this project.
     */
    virtual bool start(IOService *provider) override;
    virtual void stop(IOService *provider) override;

    /*
     * process_command_buffer - THE central function of this entire
     * project. CONFIRMED, opcode-by-opcode, for the full real range
     * 0x02-0x46 (see stage3-embedded-opcode-language.md through
     * stage4-opcode-range-0x02-0x31-traced.md for the complete trace
     * history). Implementation broken out into named per-opcode helper
     * functions in Sources/ATIR500GLContext_ProcessCommandBuffer.cpp -
     * NOTE this is a real reconstruction choice, not a reflection of the
     * original binary's structure (the real function is one enormous
     * ~3300-line dispatch chain in the decompile; splitting it into named
     * helpers is this project's own choice, made because the user's goal
     * for this reconstruction is a debuggable/modifiable driver, not a
     * byte-exact decompile).
     */
    IOReturn process_command_buffer(VendorCommandDescriptor *descriptor);

    /*
     * write_kernel_context_buffer_regs - CONFIRMED, fully decoded
     * (stage3-write-kernel-context-buffer-regs-fully-decoded.md). The
     * real "commit full render-target/framebuffer/HyperZ state" primitive,
     * confirmed this session to be shared by TWO independent call sites
     * (opcode 0x41's handler, and opcode 0x29's vertex-format-config
     * handler) - not opcode-41-specific as first assumed.
     */
    void write_kernel_context_buffer_regs(UInt32 *outputBuffer, UInt32 param2, UInt32 param3, UInt32 param4);

    /*
     * restore_state_destroyed_by_pageoff - CONFIRMED, the capstone
     * function (stage4-complete-register-tracking-state-map.md). Rebuilds
     * the ENTIRE real 3D render state after a VRAM eviction by serializing
     * a register_tracking_state snapshot back out as ~45 confirmed real
     * PM4 register writes via write_r500_3d_blit_state_packet.
     */
    void restore_state_destroyed_by_pageoff(register_tracking_state *savedState);

    /*
     * write_r500_3d_blit_state_packet - CONFIRMED to exist and be called
     * by restore_state_destroyed_by_pageoff; further internal processing
     * beyond the register-write shape already captured by the capstone
     * doc was never independently re-derived for this reconstruction.
     */
    void write_r500_3d_blit_state_packet(r500_3d_blit_state_packet_struct *packet);

    /* write_r500_zdecompress_restore_add_on_packet - UNKNOWN body, real
     * name/signature only. */
    void write_r500_zdecompress_restore_add_on_packet(r500_zdecompress_restore_add_on_packet_struct *packet);

    /*
     * compute_sc_hyperz_en / compute_zb_bw_cntl - CONFIRMED real HyperZ
     * decision logic (stage4-render-target-and-full-draw-reference.md).
     * Both take the requested value and return the real, hardware-safe
     * value to actually write to SC_HYPERZ_EN / ZB_BW_CNTL - confirmed
     * this session to be directly invoked by TWO real call sites each
     * (write_kernel_context_buffer_regs's HyperZ burst, AND opcode 0x2f's
     * dedicated "HyperZ configuration commit" handler).
     */
    UInt32 compute_sc_hyperz_en(UInt32 requested);
    UInt32 compute_zb_bw_cntl(UInt32 requested);

    /*
     * build_scissor - CONFIRMED real name and role: computes the fields
     * this project tracks as `this+0x354`/`this+0x358` (the live scissor
     * rectangle), written directly into the command stream by opcodes
     * 0x28/0x29/0x2a. Internal computation UNKNOWN beyond "produces the
     * two scissor dwords" - never independently decompiled this project.
     */
    void build_scissor(void);

    /* GetTextureOffset / WriteTextureOffset - CONFIRMED real names and
     * role (stage3, referenced throughout the opcode-0x37 trace): resolve
     * a VendorTextureBuffer's real GPU-visible base address, distinguishing
     * VRAM-direct/GART/surface-backed storage via a real type byte. Full
     * internal body UNKNOWN beyond this role. */
    UInt32 GetTextureOffset(VendorTextureBuffer *texture, bool forWrite);
    void   WriteTextureOffset(UInt32 relativeOffset, UInt32 *patchLocation, UInt32 size, VendorTextureBuffer *texture);

    /* GetVertexArrayOffset / WriteVertexArrayOffset - CONFIRMED real names
     * (opcode 0x39's full trace, stage4-embedded-opcode-table-completed.md).
     * The vertex-attribute-buffer analog of GetTextureOffset/
     * WriteTextureOffset, confirmed to route through the identical
     * texture-fetch-unit hardware (a genuine, confirmed R5xx architectural
     * fact: vertex attributes and fragment textures share fetch hardware). */
    UInt32 GetVertexArrayOffset(VendorTextureBuffer *buffer, UInt32 param2);
    void   WriteVertexArrayOffset(UInt32 *patchLocation, UInt32 relativeOffset);

    /* GetQueryOffset - CONFIRMED real name (GL_ARB_occlusion_query support,
     * stage3-query-api-and-flush-safety-check.md), body UNKNOWN beyond role. */
    UInt32 GetQueryOffset(VendorTextureBuffer *buffer, UInt32 param2, UInt32 param3);

    /*
     * add_texture_to_stream / remove_texture_from_stream / load_texture /
     * alloc_and_load_texture / compact_current_textures - CONFIRMED real
     * names, the texture-binding machinery every texture-load opcode
     * (0x06-0x15 unbind family, 0x37/0x39/0x3b/0x3e/0x3f/0x40/0x43 bind
     * family) ultimately calls. Bodies UNKNOWN beyond the role already
     * documented in stage3-kernel-side-hang-mechanism-confirmed.md and
     * stage4-embedded-opcode-table-completed.md.
     */
    void     add_texture_to_stream(VendorTextureBuffer *texture);
    void     remove_texture_from_stream(VendorTextureBuffer *texture);
    void     load_texture(VendorTextureBuffer *texture);
    IOReturn alloc_and_load_texture(VendorTextureBuffer *texture);
    void     compact_current_textures(VendorTextureBuffer *texture);

    /* map_transfer_to_GART / freeToAllocGART (this context's own override) -
     * CONFIRMED real names/roles (used identically across GL/2D/DVD
     * contexts and the IDCT engine). */
    void map_transfer_to_GART(VendorTransferBuffer *buffer);
    bool freeToAllocGART(VendorTransferBuffer *needed, bool aggressive);

    /* process_kATIGLStreamFastClearColor - CONFIRMED real name (opcode
     * 0x46, "fast clear"). Body UNKNOWN beyond that role. */
    void process_kATIGLStreamFastClearColor(UInt32 *record);

    /* build_surface_from_texture - CONFIRMED real name (opcode 0x45,
     * depth/stencil-gated at its one known real call site). */
    void *build_surface_from_texture(VendorTextureBuffer *texture, ATIR500SurfaceBuffer *surfaceBuffer,
                                      UInt16 param3, UInt16 param4, UInt32 param5, UInt32 param6);

    /* submit_context_buffer / discard_command_buffer - CONFIRMED real
     * names for the two real buffer-lifecycle bookends around
     * process_command_buffer's own "submit if nearly full" internal calls. */
    IOReturn submit_context_buffer(void);
    void     discard_command_buffer(void);

protected:
    /*
     * Real, confirmed per-instance field offsets used throughout
     * process_command_buffer and the register-write functions. Every
     * offset here was read directly off real decompiled code this
     * project produced (not guessed) - see the individual stage docs
     * cross-referenced in comments for the exact function each was
     * confirmed in.
     */
    void   *textureSlotArray;      /* +0x2a4, base of a 20-entry (16 fragment-texture + 4 vertex-attribute) per-unit slot array, stride 4 bytes - CONFIRMED (0x06-0x15/0x16-0x25 unbind families, opcode 0x39's vertex-attribute binding at index>=16) */
    void   *transferBufferSlot;    /* +0x328, a single distinct texture-tracking slot separate from textureSlotArray - CONFIRMED (opcodes 0x26/0x27's bind/unbind pair) */
    void   *boundSurface;          /* +0x290, CONFIRMED: the currently-bound render surface, read throughout get_config/get_status/get_surface_size/scale_surface/read_buffer */
    SInt32  mipLevel;              /* +0x29c, CONFIRMED: current mip level index, used in per-mip offset computations throughout */
    UInt32  scissorY;              /* +0x354, CONFIRMED: live scissor rectangle Y (build_scissor's output, embedded verbatim by opcodes 0x28/0x29/0x2a) */
    UInt32  scissorX;              /* +0x358, CONFIRMED: live scissor rectangle X, same family as scissorY */
    void   *secondaryTextureSlotA; /* +0x338, CONFIRMED to exist as a distinct per-unit slot field (opcode 0x3b family), role beyond that UNKNOWN */
    void   *secondaryTextureSlotB; /* +0x348, CONFIRMED to exist (opcode 0x3f family), same caveat as above */
    UInt16  attachmentCount;       /* +0x3a8, CONFIRMED: real count tracked by opcode 0x29's render-target/vertex-format attachment enumeration */
    UInt16  someUnitIndex;         /* +0x35c, CONFIRMED referenced in opcode 0x31's two-surface (main + FSAA-resolve) mip computation */
    UInt16  altUnitSelector;       /* +0x3b2, CONFIRMED referenced alongside +0x3aa in the per-context texture-unit array init in start() */
    UInt16  altUnitFormat;         /* +0x3aa, CONFIRMED, same init call as altUnitSelector */
    void   *perUnitTextureArray;   /* +0x3f0, stride 0x78, 6 real entries, CONFIRMED initialized in start() with real default blend/format bits */
};

#endif /* ATIR500GLCONTEXT_H */
