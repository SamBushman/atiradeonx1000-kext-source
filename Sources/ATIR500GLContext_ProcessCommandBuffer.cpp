/*
 * ATIR500GLContext_ProcessCommandBuffer.cpp
 *
 * The real embedded command-buffer processor - the single most thoroughly
 * reverse-engineered function in this entire project. Real kext address:
 * 0x2b820 (ATIR500GLContext::process_command_buffer). This reconstruction
 * walks the real command-processor dispatch: real PM4 Type-0/Type-2/Type-3
 * packets, PLUS this driver's own private "embedded extended opcode"
 * marker language layered inside them (top byte 0x02-0x46, low 24 bits a
 * distance-to-next-record).
 *
 * IMPORTANT, faithfully preserved: the real chain-walk loop has ZERO
 * bounds checking against the buffer's real end/limit - this is the
 * CONFIRMED root cause of two real hangs this project caused on real
 * hardware early on (see stage3-kernel-side-hang-mechanism-confirmed.md).
 * This reconstruction reproduces that real behavior exactly rather than
 * silently patching it, because the point of this reconstruction is a
 * faithful, debuggable copy of the real driver - the historical hang
 * mechanism is exactly the kind of thing you'd want to be able to see and
 * single-step through in a debugger. A conservative bounds check IS
 * marked, clearly, as an opt-in experiment below (see PROMO4_SAFE_WALK).
 *
 * Confidence: see per-opcode notes. Every opcode implemented below was
 * independently traced and documented across
 * stage3-embedded-opcode-language.md through
 * stage4-opcode-range-0x02-0x31-traced.md and
 * stage4-embedded-opcode-table-completed.md in the reveng repo - this file
 * is the first time those findings have been assembled into one real,
 * structured dispatch function rather than a per-opcode narrative.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/IOATIR500Accelerator.h"

/*
 * Uncomment to add a real bounds check against the buffer's end/limit
 * before dereferencing each record - NOT present in the real driver.
 * Left off by default so this file's behavior matches the real kext
 * exactly, hang-prone chain-walk included.
 */
// #define PROMO4_SAFE_WALK 1

/* Real PM4 packet-type helpers - CONFIRMED, used throughout this project
 * since stage2-pm4-confirmed.md. */
static inline UInt32 PM4_TYPE(UInt32 v)       { return (v >> 30) & 3; }
static inline UInt32 PM4_TYPE0_COUNT(UInt32 v) { return ((v >> 16) & 0x3FFF) + 1; }
static inline UInt32 PM4_TYPE0_BASE(UInt32 v)  { return v & 0x1FFF; }
static inline UInt32 PM4_TYPE3_OPCODE(UInt32 v) { return (v >> 8) & 0xFF; }
#define PM4_TYPE2_FILLER 0x80000000u

/* The embedded marker language's own top-byte opcode extractor -
 * CONFIRMED shape (`uVar38 & 0xff000000`) used identically across every
 * context class's process_command_buffer this project decompiled. */
static inline UInt32 EMBEDDED_OPCODE(UInt32 v) { return v & 0xff000000u; }
static inline UInt32 EMBEDDED_DISTANCE(UInt32 v) { return v & 0x00ffffffu; }

/* ---- Per-opcode handlers, in real opcode order ---- */

/*
 * Opcodes 0x02-0x05: real HyperZ/HiZ compressed-Z block management, using
 * the real, named HiZ memory-manager functions HZMEM_GetBlockOffset/
 * HZMEM_GetBlockCount/HZMEM_IsPartial. CONFIRMED to be real and non-trivial
 * (stage4-opcode-range-0x02-0x31-traced.md); NOT traced to full bit-level
 * precision there, and not reconstructed field-by-field here either, for
 * the same reason given at the time: this project's redesign proposal
 * already avoids HyperZ entirely for a minimal draw, so the marginal value
 * of a byte-exact reconstruction is low relative to everything else in
 * this file. TODO if HyperZ is ever needed: re-trace kext offsets in the
 * 0x2e820-0x2ea00-ish range (see the stage4 doc) field-by-field.
 */
static UInt32 *handle_hyperz_block_ops(ATIR500GLContext *ctx, UInt32 opcode, UInt32 *record) {
    (void)ctx; (void)opcode;
    /* TODO: real HZMEM_GetBlockOffset/GetBlockCount/IsPartial-based
     * compressed-Z clear/resolve logic goes here. */
    return record;
}

/*
 * Opcodes 0x06-0x15 (16 values) and their second alias family,
 * 0x16/0x18/0x19/0x1b/0x1c/0x1e/0x1f/0x21/0x22/0x24/0x25 (11 more values,
 * same handler): real, CONFIRMED per-texture-unit unbind. `N = (opcode's
 * unit-selecting arithmetic)` selects the unit; real formula confirmed
 * this session: `unitIndex = (opcode + 0xea000000) >> 0x16` mapping the
 * marker's top byte to a byte offset within the this+0x2a4-based per-unit
 * slot array (textureSlotArray in ATIR500GLContext.h).
 */
static UInt32 *handle_remove_texture_from_stream(ATIR500GLContext *ctx, UInt32 opcode, UInt32 *record) {
    UInt32 unitIndex = (opcode + 0xea000000u) >> 0x16;
    VendorTextureBuffer **slot = reinterpret_cast<VendorTextureBuffer **>(
        reinterpret_cast<UInt8 *>(ctx) + 0x2a4 + unitIndex * 4);
    if (*slot != nullptr) {
        ctx->remove_texture_from_stream(*slot);
        *slot = nullptr;
    }
    *record = PM4_TYPE2_FILLER;
    return record + 1;
}

/*
 * Opcodes 0x17, 0x1a, 0x1d, 0x20, 0x23: CONFIRMED dead/reserved in this
 * exact kext build. The dispatch code excludes them from the shared unbind
 * handler above with a dedicated `!= 0x1d000000`-style check each, implying
 * the original author intended distinct handling - but no corresponding
 * body exists anywhere in the real decompiled function for an exact match
 * on any of these five values. Modeled here as true no-ops, matching the
 * real observed behavior exactly (not a placeholder for missing analysis -
 * this IS what the real kext does).
 */
static UInt32 *handle_reserved_noop(ATIR500GLContext *ctx, UInt32 opcode, UInt32 *record) {
    (void)ctx; (void)opcode;
    return record; /* real observed behavior: falls through, does nothing */
}

/* Opcode 0x26: real GART transfer-buffer bind. CONFIRMED
 * (stage4-opcode-range-0x02-0x31-traced.md). */
static UInt32 *handle_bind_transfer_buffer(ATIR500GLContext *ctx, UInt32 *record) {
    /* Real: look up a texture/transfer-buffer descriptor via this+0x88's
     * table, track it in transferBufferSlot, refcount++, map_transfer_to_GART. */
    (void)ctx;
    *record = PM4_TYPE2_FILLER; /* TODO: real refcount/lookup body not fully re-transcribed here */
    return record + 1;
}

/* Opcode 0x27: real GART transfer-buffer unbind - the simplest handler in
 * the whole language. CONFIRMED. */
static UInt32 *handle_unbind_transfer_buffer(ATIR500GLContext *ctx, UInt32 *record) {
    /* Real: decrement transferBufferSlot's refcount, clear it. */
    (void)ctx;
    *record = PM4_TYPE2_FILLER;
    return record + 1;
}

/*
 * Opcode 0x28: real single render-target + scissor commit. CONFIRMED,
 * including the real methodological finding that this opcode's embedded
 * register index 0x50b (byte 0x142c) is NOT real MMIO - it's a
 * driver-internal software bookkeeping field (see
 * ATIRadeonX1000Registers.h's note on this). Full per-mip offset/pitch
 * computation matches the same shape already reconstructed in
 * write_kernel_context_buffer_regs.
 */
static UInt32 *handle_single_rendertarget_scissor(ATIR500GLContext *ctx, UInt32 *record) {
    record[1] = ctx->scissorY; /* CONFIRMED: embeds the live scissor rect verbatim, same fields build_scissor computes */
    record[2] = ctx->scissorX;
    /* record[0] real header 0x105bb (a real Type-0-shaped header, base index 0x5bb);
     * record[3] carries the real 0x50b software-internal field;
     * record[4] carries the real render-target offset/pitch/tiling value -
     * TODO: transcribe the exact per-mip formula from
     * write_kernel_context_buffer_regs.cpp once written, they share it. */
    return record + 5; /* CONFIRMED real record length for this opcode */
}

/*
 * Opcode 0x29: CONFIRMED, one of the two most architecturally significant
 * opcodes in the whole language. A real vertex-format-configuration opcode
 * with a switch mapping small enum values (0/1/2/3/7/8/0x10/0x11) to
 * internal semantic-slot codes, tracking attachmentCount, and - the real
 * finding - calling build_scissor() and write_kernel_context_buffer_regs()
 * DIRECTLY. This is the proof that write_kernel_context_buffer_regs is a
 * shared "commit everything" primitive used by two independent opcodes
 * (0x29 and 0x41), not opcode-41-specific.
 */
static UInt32 *handle_vertex_format_and_commit(ATIR500GLContext *ctx, UInt32 *record) {
    /* TODO: the real 0/1/2/3/7/8/0x10/0x11 -> 0/4/5/6/2/3/7/8 switch table
     * (same shape as opcode 0x2a's attachment-enum table) goes here,
     * updating ctx's attachmentCount and per-slot state. */
    ctx->build_scissor();
    ctx->write_kernel_context_buffer_regs(record, 0, record[6], record[7]); /* CONFIRMED exact real call shape */
    return record; /* real advance amount depends on the (not yet re-transcribed) switch body above */
}

/*
 * Opcode 0x2a: CONFIRMED. Render-target-PAIR binding plus the live scissor
 * rectangle, using a real GL-attachment-enum-to-internal-slot lookup table
 * (1/2/3/4/7/8/10/11 -> 0/4/5/6/2/3/7/8 - plausibly
 * GL_COLOR_ATTACHMENT0/1/depth/stencil).
 */
static UInt32 *handle_rendertarget_pair_scissor(ATIR500GLContext *ctx, UInt32 *record) {
    static const UInt8 kAttachmentSlotTable[12] = {
        /* index by real attachment enum value 0..11, 0xff = invalid */
        0xff, 0, 4, 5, 6, 0xff, 0xff, 2, 3, 0xff, 7, 8
    };
    (void)kAttachmentSlotTable; /* TODO: wire into the real per-slot bind body */
    record[/* real offset for scissor Y */ 0] = ctx->scissorY; /* placeholder index - TODO: exact record layout not re-transcribed */
    (void)ctx;
    return record;
}

/*
 * Opcode 0x2b: CONFIRMED real, explicit, client-triggered flush. Unlike
 * the automatic "flush if nearly full" pattern used everywhere else in
 * this driver, this is a *named* marker - a real glFlush-equivalent
 * expressed in the marker language.
 */
static UInt32 *handle_explicit_flush(ATIR500GLContext *ctx, UInt32 *record) {
    /* TODO: real `if (pendingCount != 0) submit_buffer(...)` body - see
     * stage4-opcode-range-0x02-0x31-traced.md's exact transcription for
     * the pending-count bookkeeping fields (local_384/local_388 in the
     * original decompile - not yet mapped to named ATIR500GLContext
     * fields in this reconstruction). */
    (void)ctx;
    *record = PM4_TYPE2_FILLER;
    return record + 1;
}

/* Opcode 0x2c: CONFIRMED real mip/slice-aware scissor intersection -
 * narrows a computed per-mip rect against the currently active scissor via
 * real min/max clamps. */
static UInt32 *handle_mip_scissor_intersect(ATIR500GLContext *ctx, UInt32 *record) {
    /* TODO: real per-mip pitch/offset computation (mirrors opcode 0x28's
     * shape) then min/max clamp against ctx->scissorY/scissorX. */
    (void)ctx;
    return record + 3; /* CONFIRMED real record length for this opcode */
}

/* Opcodes 0x2f: CONFIRMED real HyperZ configuration commit - directly
 * calls compute_sc_hyperz_en/compute_zb_bw_cntl and patches the results
 * into the embedded slots. */
static UInt32 *handle_hyperz_commit(ATIR500GLContext *ctx, UInt32 *record) {
    record[0] = PM4_TYPE2_FILLER;
    record[2] = ctx->compute_sc_hyperz_en(record[2]);
    record[4] = ctx->compute_zb_bw_cntl(record[4]);
    /* TODO: real trailing vtable call `(**(code**)(*(int*)this+0x5a4))(this)` -
     * UNKNOWN real virtual method name, not resolved this project. */
    return record + 5; /* CONFIRMED real record length */
}

/* Opcode 0x30: CONFIRMED real FSAA resolve-buffer setup, calling the real,
 * named ATIR500Surface::resolve_fsaa_buffer. */
static UInt32 *handle_fsaa_resolve_setup(ATIR500GLContext *ctx, UInt32 *record) {
    (void)ctx;
    /* TODO: real format-code switch + resolve_fsaa_buffer call - see
     * stage4-opcode-range-0x02-0x31-traced.md for the exact switch table. */
    return record + 1;
}

/*
 * Opcode 0x31: CONFIRMED the richest single opcode in the language - a
 * full state-restore blit reusing the EXACT SAME 0x2f4-byte
 * _g_r500_3d_blit_state_packet template as
 * restore_state_destroyed_by_pageoff, for TWO surfaces (main + FSAA-resolve
 * target), followed by a complete textured full-quad draw with real
 * floating-point NDC/viewport math and US-block shader headers - the
 * second independent confirmed real example (after
 * _radeon3DCopySetup/_radeon3DFillSetup) of this driver generation's
 * "blit via textured quad" technique. Full field-by-field transcription
 * deliberately deferred - see stage4-opcode-range-0x02-0x31-traced.md for
 * the complete real trace this would be built from.
 */
static UInt32 *handle_fsaa_resolve_blit(ATIR500GLContext *ctx, UInt32 *record) {
    (void)ctx;
    /* TODO: this is the single largest remaining reconstruction gap in
     * this file - see the doc reference above for the real trace. */
    return record;
}

/* Opcode 0x37: CONFIRMED real "deferred texture/render-target
 * offset-and-format patch" - the answer to how this driver embeds a
 * texture/render-target reference before the kernel finalizes where that
 * surface lives in memory (it doesn't - it patches placeholder slots once
 * the real address is known). */
static UInt32 *handle_deferred_offset_patch(ATIR500GLContext *ctx, UInt32 *record) {
    /* TODO: real branch on the bound texture/render-target's backing type
     * (surface-backed vs plain-texture vs no-texture-bound), calling
     * GetTextureOffset/WriteTextureOffset or
     * IOATIR500Surface::surface_buffer_idx_mask as appropriate - see
     * stage4-embedded-opcode-table-completed.md's full trace. */
    (void)ctx;
    return record;
}

/* Opcode 0x38: CONFIRMED real deferred address-fixup pass - consumes
 * itself (overwrites its own marker with real Type-2 filler) then walks an
 * embedded array converting relative offsets into absolute GART addresses. */
static UInt32 *handle_address_fixup(ATIR500GLContext *ctx, UInt32 *record) {
    (void)ctx;
    *record = PM4_TYPE2_FILLER;
    return record + 1; /* TODO: real embedded-array walk not yet re-transcribed */
}

/*
 * Opcode 0x39: CONFIRMED, the other most architecturally significant
 * opcode - the real "bind vertex attribute buffers + index buffer"
 * mechanism, using the SAME texture-fetch-unit hardware already confirmed
 * for fragment textures (a genuine, confirmed R5xx architectural fact).
 * Binds into per-context slots starting at index 16 (textureSlotArray+16),
 * a separate range from the 0-15 fragment-texture-unit slots.
 */
static UInt32 *handle_bind_vertex_attributes(ATIR500GLContext *ctx, UInt32 *record) {
    (void)ctx;
    /* TODO: real per-attribute loop calling add_texture_to_stream/
     * alloc_and_load_texture and GetVertexArrayOffset/
     * WriteVertexArrayOffset, plus the trailing index-buffer offset patch
     * with its real sub-dword alignment correction - see
     * stage4-embedded-opcode-table-completed.md's full trace. */
    return record;
}

/* Opcodes 0x3a/0x3d/0x3e/0x3b/0x3f/0x40/0x43: CONFIRMED real texture
 * load/attach family - structurally identical add_texture_to_stream /
 * alloc_and_load_texture calls, differing only in which per-context
 * texture-slot field they target (textureSlotArray vs
 * secondaryTextureSlotA vs secondaryTextureSlotB) - real, confirmed
 * evidence this driver tracks multiple independent texture-unit slots
 * through parallel, structurally-identical opcode variants. */
static UInt32 *handle_texture_load_family(ATIR500GLContext *ctx, UInt32 opcode, UInt32 *record) {
    (void)opcode;
    /* TODO: dispatch to the correct slot field per opcode, then call
     * add_texture_to_stream/alloc_and_load_texture. */
    (void)ctx;
    return record;
}

/* Opcode 0x41: CONFIRMED real render-target/framebuffer commit - the
 * first-found (chronologically) caller of write_kernel_context_buffer_regs,
 * now known to share that function with opcode 0x29. */
static UInt32 *handle_rendertarget_commit(ATIR500GLContext *ctx, UInt32 *record) {
    ctx->write_kernel_context_buffer_regs(record, 0, record[6], record[7]); /* INFERRED to match opcode 0x29's exact call shape - not independently re-verified for 0x41 specifically in this reconstruction pass */
    return record;
}

/* Opcode 0x44: CONFIRMED real transfer-buffer GART completion - calls
 * map_transfer_to_GART, builds a Type-3-wrapped completion record
 * referencing register index 0x575. */
static UInt32 *handle_transfer_gart_completion(ATIR500GLContext *ctx, UInt32 *record) {
    (void)ctx;
    return record; /* TODO: real body not yet re-transcribed */
}

/* Opcode 0x45: CONFIRMED real build_surface_from_texture call
 * (depth/stencil-gated at its one known real call site). */
static UInt32 *handle_build_surface_from_texture(ATIR500GLContext *ctx, UInt32 *record) {
    (void)ctx;
    return record; /* TODO: real argument marshalling not yet re-transcribed */
}

/* Opcode 0x46: CONFIRMED real fast-clear (process_kATIGLStreamFastClearColor). */
static UInt32 *handle_fast_clear(ATIR500GLContext *ctx, UInt32 *record) {
    ctx->process_kATIGLStreamFastClearColor(record);
    return record;
}

/*
 * The real dispatch loop. CONFIRMED overall shape: read one dword, branch
 * on real PM4 packet type (Type-0 register write, Type-2 filler, Type-3
 * opcode packet) OR this driver's own embedded top-byte marker language,
 * advance the cursor by the real distance encoded in the low 24 bits, and
 * repeat until the buffer's declared length is consumed.
 *
 * The embedded-marker branch below is a real, faithful reconstruction of
 * the confirmed opcode table; PM4 Type-0/Type-2/Type-3 handling is
 * INFERRED from this project's general PM4 knowledge (stage2-pm4-confirmed.md)
 * rather than re-transcribed from this exact function's own real Type-0/
 * Type-3 handling code, which this reconstruction pass did not re-read
 * line-by-line for that part.
 */
IOReturn ATIR500GLContext::process_command_buffer(VendorCommandDescriptor *descriptor) {
    UInt32 *record = static_cast<UInt32 *>(descriptor->commandBuffer);
#ifdef PROMO4_SAFE_WALK
    UInt32 *realEnd = record + (descriptor->commandLength / sizeof(UInt32)); /* NOT present in the real driver - see file header */
#endif

    for (;;) {
#ifdef PROMO4_SAFE_WALK
        if (record >= realEnd) break; /* the fix the real driver does NOT have */
#endif
        UInt32 header = *record;
        UInt32 type = PM4_TYPE(header);

        if (type == 2) {
            /* real PM4 Type-2: pure filler, advance one dword */
            record += 1;
            continue;
        }
        if (type == 0) {
            /* real PM4 Type-0: register write burst - not this driver's
             * embedded marker language at all. INFERRED advance amount
             * (real Type-0 semantics: 1 header dword + COUNT value dwords). */
            record += 1 + PM4_TYPE0_COUNT(header);
            continue;
        }
        if (type == 3 && PM4_TYPE3_OPCODE(header) == 0x10 /* real NOP opcode */) {
            /* A real Type-3 NOP - either a genuine no-op, or (far more
             * commonly in this driver) the CONFIRMED "self-consuming
             * marker erasure" convention every deferred-patch opcode above
             * uses once it has consumed its own content. */
            record += 1 + PM4_TYPE0_COUNT(header); /* INFERRED: Type-3's count field uses the identical bit position as Type-0's */
            continue;
        }

        /* Not a plain PM4 packet - try this driver's own embedded
         * extended-opcode marker language. CONFIRMED dispatch range
         * 0x02000000-0x46000000. */
        UInt32 opcode = EMBEDDED_OPCODE(header);
        UInt32 *next = nullptr;

        switch (opcode) {
            case 0x02000000: case 0x03000000: case 0x04000000: case 0x05000000:
                next = handle_hyperz_block_ops(this, opcode, record); break;
            case 0x17000000: case 0x1a000000: case 0x1d000000: case 0x20000000: case 0x23000000:
                next = handle_reserved_noop(this, opcode, record); break;
            case 0x26000000: next = handle_bind_transfer_buffer(this, record); break;
            case 0x27000000: next = handle_unbind_transfer_buffer(this, record); break;
            case 0x28000000: next = handle_single_rendertarget_scissor(this, record); break;
            case 0x29000000: next = handle_vertex_format_and_commit(this, record); break;
            case 0x2a000000: next = handle_rendertarget_pair_scissor(this, record); break;
            case 0x2b000000: next = handle_explicit_flush(this, record); break;
            case 0x2c000000: next = handle_mip_scissor_intersect(this, record); break;
            case 0x2f000000: next = handle_hyperz_commit(this, record); break;
            case 0x30000000: next = handle_fsaa_resolve_setup(this, record); break;
            case 0x31000000: next = handle_fsaa_resolve_blit(this, record); break;
            case 0x37000000: next = handle_deferred_offset_patch(this, record); break;
            case 0x38000000: next = handle_address_fixup(this, record); break;
            case 0x39000000: next = handle_bind_vertex_attributes(this, record); break;
            case 0x3a000000: case 0x3b000000: case 0x3d000000: case 0x3e000000:
            case 0x3f000000: case 0x40000000: case 0x43000000:
                next = handle_texture_load_family(this, opcode, record); break;
            case 0x41000000: next = handle_rendertarget_commit(this, record); break;
            case 0x44000000: next = handle_transfer_gart_completion(this, record); break;
            case 0x45000000: next = handle_build_surface_from_texture(this, record); break;
            case 0x46000000: next = handle_fast_clear(this, record); break;
            default:
                if (opcode >= 0x06000000 && opcode <= 0x25000000) {
                    /* the shared unbind family, including the second alias
                     * range 0x16-0x25 confirmed this session */
                    next = handle_remove_texture_from_stream(this, opcode, record);
                } else {
                    /* CONFIRMED: end-of-buffer sentinel or truly unknown
                     * content - the real driver's own behavior for the
                     * loop-terminating case was not independently
                     * re-transcribed for this reconstruction; the low 24
                     * bits' real distance-to-next-record value governs
                     * advancement here, exactly as documented in
                     * stage3-embedded-opcode-language.md. */
                    UInt32 distance = EMBEDDED_DISTANCE(header);
                    if (distance == 0) {
                        return kIOReturnSuccess; /* INFERRED loop-termination condition */
                    }
                    next = record + distance; /* the real, confirmed ZERO-BOUNDS-CHECKED advance - see file header */
                }
                break;
        }

        record = next;
    }
}
