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
UInt32 convertIOGLBufferToBufIdx(UInt32 bufferKind, UInt32 *outIndex);   /* real addr 0x26ce0 (free function, C++ linkage) */
struct r500_zdecompress_restore_add_on_packet_struct;

class ATIR500GLContext : public IOATIR500GLContext {
    OSDeclareDefaultStructors(ATIR500GLContext)

    /*
     * FIXED (issue #1, first build attempt): same friendship need as
     * IOATIR500GLContext.h's own copy of this block - see that header's
     * comment. These handlers need this subclass's own protected fields
     * too (scissorX/scissorY confirmed so far).
     */
    friend UInt32 *handle_set_return_code_3(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_set_return_code_2(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_hyperz_fast_clear_setup(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_hyperz_zpass_setup(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_remove_texture_from_stream(ATIR500GLContext *ctx, UInt32 opcode, UInt32 *record);
    friend UInt32 *handle_texture_bind(ATIR500GLContext *ctx, UInt32 opcode, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_bind_transfer_buffer(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_unbind_transfer_buffer(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_single_rendertarget_scissor(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_vertex_format_and_commit(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_rendertarget_pair_scissor(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_rt0_generation_stamp(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_transfer_buffer_bind_and_fixup(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_explicit_flush(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_mip_scissor_intersect(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_hyperz_commit(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_fsaa_resolve_setup(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_depth_buffer_resolve(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_deferred_offset_patch(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_address_fixup(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_bind_vertex_attributes(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_clear_vertex_attribute_slots(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_forward_volatile_state(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_query_fence_alloc(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_query_buffer_bind(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_rt0_texture_commit(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_rendertarget_tiling_commit(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_index_buffer_commit(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_texture_commit_with_generation(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_depth_flush_and_tile_patch(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_color_and_z_register_burst(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_rendertarget_commit(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_transfer_gart_completion(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *handle_build_surface_from_texture(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state);
    friend UInt32 *handle_fast_clear(ATIR500GLContext *ctx, UInt32 *record);
    friend UInt32 *ATIR500GLContext_handle_fsaa_resolve_blit(ATIR500GLContext *ctx, UInt32 *record);

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
     * returns `int` (the raw table-entry address). RETURN TYPE
     * CORRECTED (build fixup, issue #1): declared here as the real base
     * class's own exact return type (`IOExternalMethod *`, non-const) -
     * this project's own richer `VendorExternalMethod` struct is not
     * covariant with it (different real field order/size), so real gcc
     * rejected the original `const VendorExternalMethod *` declaration
     * as an invalid override. See the .cpp file's own header comment.
     */
    virtual IOExternalMethod *getTargetAndMethodForIndex(IOService **target, UInt32 selector);

    /*
     * start / stop - CONFIRMED real behavior for start() (kext offset
     * 0x28540): zeroes a large block of per-instance state (this+0x34c..
     * this+0x400ish), initializes the six-entry texture-unit array at
     * this+0x3f0 (stride 0x78) to real defaults (blend/format bits),
     * initializes four swap-chain-related fields, sets the special
     * selector-20 methodDescs pointer described above, and finally calls
     * FUN_000286dc/ec (a lock-pair) around the base class's own start() -
     * RESOLVED, issue #15 (live kxld-resolved memory read on real
     * G5/Tiger hardware, cross-referenced against the running kernel's
     * own symbol table): the real pair is `mutex_unlock_rwcmb`/
     * `mutex_lock`, the same real pair used throughout this project - see
     * `Headers/ATIRadeonX1000Registers.h`. stop() RESOLVED, issue #49 -
     * see Sources/IOATIR500GLContext_Stop.cpp: real addr 0x28700, a tiny
     * real body - locks the accelerator's own mutex (`accel+0x840`, the
     * same real `_mutex_lock`/`_mutex_unlock` pair
     * `ATIR500DVDContext::set_macrovision` already established) around a
     * single call to the BASE class's `IOATIR500GLContext::stop`, where
     * essentially all the real teardown work actually lives.
     */
    virtual bool start(IOService *provider) override;
    virtual void stop(IOService *provider) override;

    /*
     * invalidate - RESOLVED (issue #12.1): this is the real name of the
     * previously-unnamed vtable+0x5a4 virtual method called from opcodes
     * 0x02/0x03/0x04/0x05/0x29/0x2f/0x41 and from restore_state_destroyed_by_pageoff
     * (real mangled symbol __ZN16ATIR500GLContext10invalidateEv, kext
     * offset 0x26fb0; every sibling context class - 2D/DVD/Surface - has
     * its own identically-named, identically-shaped override, a real
     * shared pattern). Resolved via the vtable slot's real raw bytes
     * (Ghidra marks the relocation SKIPPED, same as issue #6, but this
     * one is a plain local VANILLA relocation into __TEXT,__text, not a
     * SECTDIFF pair - confirmed via otool -rv and cross-checked against
     * a second, already-known-correct vtable slot at the same class's
     * +0x348 before trusting it). Real body: fully transcribed, one
     * line - `*(uint*)(*(int*)(this+0x108) + 0x1c) |= 1;` - sets a dirty/
     * invalidate bit on the object start() allocates and zeroes at
     * this+0x108 (see start()'s note above; that object's own type and
     * the meaning of its +0x1c field are UNKNOWN).
     */
    virtual void invalidate();

    /* Overrides of the base class's other virtual slots (stock vtable +0x580/+0x5a8/+0x5ac/+0x5c0). Bodies:
     * Sources/ATIR500GLContext_SmallMethods.cpp. */
    virtual IOReturn clientMemoryForType(UInt32 type, UInt32 *options, IOMemoryDescriptor **memory) override; /* +0x580, addr 0x27000 */
    virtual void update_surface();                                                    /* +0x5a8, addr 0x27fd0 */
    virtual bool setCompatibleSurfaceMode(SInt32 *modeBits, eIOGLContextModeBits mode, SInt32 flags); /* +0x5ac, addr 0x270a0 */
    virtual void set_texture_flags(VendorTextureBuffer *texture);                    /* +0x5c0, addr 0x26fd0 */

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
    virtual IOReturn process_command_buffer(VendorCommandDescriptor *descriptor);

    /*
     * write_kernel_context_buffer_regs - CONFIRMED, fully decoded
     * (stage3-write-kernel-context-buffer-regs-fully-decoded.md). The
     * real "commit full render-target/framebuffer/HyperZ state" primitive,
     * confirmed this session to be shared by TWO independent call sites
     * (opcode 0x41's handler, and opcode 0x29's vertex-format-config
     * handler) - not opcode-41-specific as first assumed.
     */
    UInt32 write_kernel_context_buffer_regs(UInt32 *outputBuffer, UInt32 param2, UInt32 param3, UInt32 param4); /* return type FIXED this pass (issue #5) - real definition in ATIR500GLContext_RegisterState.cpp already returns UInt32; this declaration had drifted out of sync */

    /*
     * restore_state_destroyed_by_pageoff - CONFIRMED, the capstone
     * function. Rebuilds the ENTIRE real 3D render state after a VRAM
     * eviction by serializing a register_tracking_state snapshot back out
     * as ~120 real PM4-header-shaped writes. FULLY transcribed in
     * Sources/ATIR500GLContext_RestoreState.cpp from a complete real
     * decompile (real kext offset 0x2af10) - see that file for an honest
     * caveat about transposition risk in a transcription this dense.
     */
    void restore_state_destroyed_by_pageoff(register_tracking_state *savedState);

    /*
     * write_r500_3d_blit_state_packet - RESOLVED (issue #1, get-it-
     * linking pass), real addr 0x2ac10. Real body: picks a source
     * `ATIR500SurfaceBuffer` record two different ways depending on a
     * real mode flag at `this+0x3bc` - zero selects the currently-bound
     * surface's own per-format buffer-pointer table
     * (`boundSurface+0xb70`, indexed by `this+0xac`) combined with the
     * inline per-slot array at `boundSurface+0xa8` (stride 0x78,
     * indexed the same way - the SAME array shape
     * `alloc_surfaces_pageq` already establishes on `IOATIR500Surface`);
     * nonzero selects a second, previously-uncatalogued INLINE
     * `ATIR500SurfaceBuffer` array on THIS class itself
     * (`this+0x3c0`, stride 0x78, indexed by `this+0x3b2` - the
     * already-named `altUnitSelector`, confirming that field's role
     * extends to indexing this array too). Computes a real GPU base-
     * address dword from the selected buffer's own `mipOffsets`/
     * `basePitch`/`gpuBaseAddress` fields, five real `FormatTableLookup_
     * 0x0004d2e0`-derived bitfields packed into the packet's own
     * `+0x228` dword, a real HyperZ-eligibility gated dword at `+0x80`,
     * and a real texture-offset dword at `+0x280` via the already-
     * established `GetTextureOffset` - see
     * `Sources/ATIR500GLContext_WriteR500BlitStatePacket.cpp` for the
     * full transcription.
     */
    void write_r500_3d_blit_state_packet(r500_3d_blit_state_packet_struct *packet);

    /*
     * write_r500_zdecompress_restore_add_on_packet - RESOLVED (issue
     * #1, get-it-linking pass), real addr 0x28780. Real body: picks a
     * source `ATIR500SurfaceBuffer` record the same two-way `this+0x3bc`
     * mode switch as `write_r500_3d_blit_state_packet` uses, except the
     * nonzero-mode source here is a single fixed record at `this+0x5a0`
     * (NOT the `altUnitSelector`-indexed array that function uses) and
     * the zero-mode index comes from `this+0xae` (a distinct field from
     * that function's own `this+0xac`). Writes five real dwords
     * (`+4`/`+0xc`/`+0x10`/`+0x18`/`+0x20`/`+0x28`) - RESOLVED the real
     * struct's own minimum size from this (see `ATIRadeonX1000Types.h`'s
     * own header comment, a real struct-size bug fix). `+4`'s own
     * bizarre real bit-trick (`-(formatTableIndex^0x10) >> 30 & 2`)
     * simplified to its verified-equivalent direct form,
     * `formatTableIndex != 0x10 ? 2 : 0`.
     */
    void write_r500_zdecompress_restore_add_on_packet(r500_zdecompress_restore_add_on_packet_struct *packet);

    /*
     * compute_sc_hyperz_en / compute_zb_bw_cntl - CONFIRMED, FULLY
     * transcribed (real kext offsets 0x26df0/0x26e40) in
     * Sources/ATIR500GLContext_RegisterState.cpp. Both resolve the real
     * bound surface record and gate their real bit contributions on two
     * real per-surface flags this pass discovered and named
     * (ATIR500SurfaceBuffer::hyperZEligible/zbBandwidthEligible, +0x35/
     * +0x34) - confirmed to be directly invoked by TWO real call sites
     * each (write_kernel_context_buffer_regs's HyperZ burst, AND opcode
     * 0x2f's dedicated "HyperZ configuration commit" handler).
     */
    UInt32 compute_sc_hyperz_en(UInt32 requested);
    UInt32 compute_zb_bw_cntl(UInt32 requested);

    /*
     * build_scissor - CONFIRMED, FULLY transcribed (real kext offset
     * 0x27ee0) in Sources/ATIR500GLContext_RegisterState.cpp. Real,
     * surprising finding from that transcription: it only ever writes
     * `this+0x358`, never `this+0x354` - see that file's note (this
     * project's earlier assumption the two form a simple Y/X pair is now
     * an open question, tracked in GAPS.md).
     */
    void build_scissor(void);

    /* GetTextureOffset / WriteTextureOffset - CONFIRMED, FULLY
     * transcribed (real kext offsets 0x280c0/0x28420) in
     * Sources/ATIR500GLContext_TextureOffsets.cpp: resolve a
     * VendorTextureBuffer's real GPU-visible base address via a real
     * 6-value type-discriminant byte at +0x20, distinguishing VRAM-
     * direct/chained/surface-backed storage. */
    UInt32 GetTextureOffset(VendorTextureBuffer *texture, bool forWrite);
    /* Real return value is the real dword-count written (3 or 4), not
     * void as an earlier draft guessed - fixed after full transcription
     * in Sources/ATIR500GLContext_TextureOffsets.cpp. */
    UInt32 WriteTextureOffset(UInt32 param1, UInt32 *outputBuffer, UInt32 index, VendorTextureBuffer *texture);

    /* GetVertexArrayOffset / WriteVertexArrayOffset - CONFIRMED real names
     * (opcode 0x39's full trace, stage4-embedded-opcode-table-completed.md).
     * The vertex-attribute-buffer analog of GetTextureOffset/
     * WriteTextureOffset, confirmed to route through the identical
     * texture-fetch-unit hardware (a genuine, confirmed R5xx architectural
     * fact: vertex attributes and fragment textures share fetch hardware). */
    UInt32 GetVertexArrayOffset(VendorTextureBuffer *buffer, UInt32 param2);
    /* Real return value is a fixed dword-count constant (0x18), not void -
     * fixed after full transcription. */
    UInt32 WriteVertexArrayOffset(UInt32 *outputBuffer, UInt32 startIndex);

    /* GetQueryOffset - CONFIRMED real name (GL_ARB_occlusion_query support,
     * stage3-query-api-and-flush-safety-check.md), body UNKNOWN beyond role. */
    UInt32 GetQueryOffset(VendorTextureBuffer *buffer, UInt32 param2, UInt32 param3);

    /*
     * NOTE: add_texture_to_stream/remove_texture_from_stream/
     * map_transfer_to_GART are real methods of the BASE class
     * (IOATIR500GLContext) - see IOATIR500GLContext.h, corrected from an
     * earlier draft that had them here.
     */

    /*
     * load_texture / alloc_and_load_texture / compact_current_textures -
     * FULLY RESOLVED (issue #5): all three now fully transcribed (real
     * kext offsets 0x29480/0x2a3d0/0x29dd0) - see
     * Sources/ATIR500GLContext_TextureLoad.cpp for all three, including
     * load_texture's own detailed header comment (deferred across an
     * earlier pass for being large/dense - ~380 lines, dozens of locals,
     * per-mip/tiling math matching write_kernel_context_buffer_regs's
     * shape - now done). This machinery backs every texture-load opcode
     * (0x06-0x15 BIND family - not plain unbind - plus 0x37/0x39/0x3b/
     * 0x3e/0x3f/0x40/0x43).
     *
     * RETURN TYPES CORRECTED this pass - the real decompile shows these
     * were swapped from what this project had assumed:
     * alloc_and_load_texture is real `void` (was declared `IOReturn`),
     * compact_current_textures really returns a value (was declared
     * `void`) - both confirmed directly from their real decompiled
     * bodies' `return` statements.
     */
    void     load_texture(VendorTextureBuffer *texture);
    void     alloc_and_load_texture(VendorTextureBuffer *texture);
    IOReturn compact_current_textures(VendorTextureBuffer *texture);

    /*
     * get_texture - RESOLVED (issue #5): real body fully decompiled and
     * transcribed this pass (kext offset 0x2b5f0) - see
     * Sources/ATIR500GLContext_TextureLoad.cpp. Confirms the guess this
     * project had flagged as plausible-but-unconfirmed: it IS close to
     * the "pending-flush + alloc_and_load_texture + restore_state +
     * map_transfer_to_GART" bundle manually inlined at other bind call
     * sites, plus a real atomic counter update this project hadn't
     * anticipated.
     */
    void get_texture(UInt32 *record, VendorTextureBuffer *texture, UInt32 *pLocal388, UInt32 *pLocal384,
                      UInt32 *pLocal380, register_tracking_state *scratch);

    /*
     * convertIOGLBufferToBufIdx - RESOLVED (issue #5): real body fully
     * decompiled this pass. CORRECTED signature - this is NOT a member
     * of this class at all: it's a real free (non-member, non-static-
     * member) C++ function (mangled `_Z25convertIOGLBufferToBufIdxmPm`,
     * global namespace), and it returns `bool`-like success/failure
     * (`undefined4`, 1/0), not `void`. Declared and defined in
     * Sources/ATIR500GLContext_ProcessCommandBuffer.cpp next to its one
     * real call site (opcode 0x32). Real body: a plain 7-case switch
     * mapping client-facing "IOGL buffer" enum values (0/1/2/3/4/7/8) to
     * internal buffer/mip-table indices (1/0/4/5/6/2/3) - default case
     * returns failure (0) and writes 1 as a fallback index.
     */

    /* freeToAllocGART (this context's own override) - CONFIRMED real
     * name/role (used identically across GL/2D/DVD contexts and the IDCT
     * engine). */
    bool freeToAllocGART(VendorTransferBuffer *needed, bool aggressive);

    /*
     * process_kATIGLStreamFastClearColor - CONFIRMED, fully decoded (real
     * kext offset 0x292a0, opcode 0x46 "fast clear"). Real per-mip
     * render-target offset/tiling computation for TWO surfaces (color +
     * an associated Z/stencil-adjacent surface at `this+0xae`'s unit
     * index), writing a real Type-0-header-shaped burst. Full
     * reconstruction in Sources/ATIR500GLContext_Surfaces.cpp.
     */
    void process_kATIGLStreamFastClearColor(UInt32 *record);

    /*
     * build_surface_from_texture - CONFIRMED, fully decoded (real kext
     * offset 0x28200, opcode 0x45). Real signature returns void, not a
     * pointer (corrected from an earlier draft's guess) - it populates
     * the caller-owned `surfaceBuffer` in place. Full reconstruction in
     * Sources/ATIR500GLContext_Surfaces.cpp.
     */
    void build_surface_from_texture(VendorTextureBuffer *texture, ATIR500SurfaceBuffer *surfaceBuffer,
                                     UInt16 param3, UInt16 param4, UInt8 param5, UInt32 param6, UInt16 param7);

    /* submit_context_buffer / discard_command_buffer - CONFIRMED real
     * names for the two real buffer-lifecycle bookends around
     * process_command_buffer's own "submit if nearly full" internal
     * calls. submit_context_buffer RESOLVED (issue #5) - fully
     * transcribed, see Sources/ATIR500GLContext_TextureLoad.cpp. Return
     * type CORRECTED to real `void` (was declared `IOReturn`). */
    virtual void submit_context_buffer(void);
    virtual void discard_command_buffer(void);

protected:
    /*
     * FIXED (issue #56): these thirteen fields were declared in
     * roughly-discovery order, not ascending real-offset order, with no
     * padding scaffolding between them - reordered into true ascending
     * real-offset order with a leading pad from this class's own start
     * and a pad array in every real gap. None of these fields are ever
     * accessed by their C++ name anywhere in this project's own `.cpp`
     * files (every real access goes through raw pointer arithmetic at
     * the literal offset, e.g. `U16At(self, 0x35c)`), so there was no
     * live functional bug from this today - but `sizeof(ATIR500GLContext)`
     * was far smaller than the real object, which matters for this
     * class's own real `OSTypeAlloc` allocation size.
     *
     * Real, confirmed per-instance field offsets used throughout
     * process_command_buffer and the register-write functions. Every
     * offset here was read directly off real decompiled code this
     * project produced (not guessed) - see the individual stage docs
     * cross-referenced in comments for the exact function each was
     * confirmed in.
     */
    UInt8   _pad_0x00[0x290];
    void   *boundSurface;          /* +0x290, CONFIRMED: the currently-bound render surface, read throughout get_config/get_status/get_surface_size/scale_surface/read_buffer */
    UInt8   _pad_0x294[0x29c - 0x294];
    SInt32  mipLevel;              /* +0x29c, CONFIRMED: current mip level index, used in per-mip offset computations throughout */
    UInt8   _pad_0x2a0[0x2a4 - 0x2a0];
    void   *textureSlotArray;      /* +0x2a4, base of a 20-entry (16 fragment-texture + 4 vertex-attribute) per-unit slot array, stride 4 bytes - CONFIRMED (0x06-0x15/0x16-0x25 unbind families, opcode 0x39's vertex-attribute binding at index>=16) */
    UInt8   _pad_0x2a8[0x328 - 0x2a8];
    void   *transferBufferSlot;    /* +0x328, a single distinct texture-tracking slot separate from textureSlotArray - CONFIRMED (opcodes 0x26/0x27's bind/unbind pair) */
    UInt8   _pad_0x32c[0x338 - 0x32c];
    void   *secondaryTextureSlotA; /* +0x338, CONFIRMED to exist as a distinct per-unit slot field (opcode 0x3b family), role beyond that UNKNOWN */
    UInt8   _pad_0x33c[0x348 - 0x33c];
    void   *secondaryTextureSlotB; /* +0x348, CONFIRMED to exist (opcode 0x3f family), same caveat as above */
    UInt8   _pad_0x34c[0x354 - 0x34c];
    UInt32  scissorY;              /* +0x354, CONFIRMED: live scissor rectangle Y (build_scissor's output, embedded verbatim by opcodes 0x28/0x29/0x2a) */
    UInt32  scissorX;              /* +0x358, CONFIRMED: live scissor rectangle X, same family as scissorY */
    UInt16  someUnitIndex;         /* +0x35c, CONFIRMED referenced in opcode 0x2d's two-surface (main + FSAA-resolve) mip computation (CORRECTED, issue #12 item 4 - previously misattributed to opcode 0x31) */
    UInt8   _pad_0x35e[0x3a8 - 0x35e];
    UInt16  attachmentCount;       /* +0x3a8, CONFIRMED: real count tracked by opcode 0x29's render-target/vertex-format attachment enumeration */
    UInt16  altUnitFormat;         /* +0x3aa, CONFIRMED, same init call as altUnitSelector */
    UInt8   _pad_0x3ac[0x3b2 - 0x3ac];
    UInt16  altUnitSelector;       /* +0x3b2, CONFIRMED referenced alongside +0x3aa in the per-context texture-unit array init in start() */
    UInt8   _pad_0x3b4[0x3f0 - 0x3b4];
    void   *perUnitTextureArray;   /* +0x3f0, stride 0x78, 6 real entries, CONFIRMED initialized in start() with real default blend/format bits */
};

#endif /* ATIR500GLCONTEXT_H */
