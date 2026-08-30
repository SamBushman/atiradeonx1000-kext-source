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

/*
 * ProcessCommandBufferState - CONFIRMED real, function-wide local state
 * this project's earlier per-opcode-handler split (a real, disclosed
 * reconstruction choice - see file header) initially didn't thread
 * through. Real names from the decompile: `local_cc` (the function's own
 * eventual return value, written by opcodes 0x02/0x03), `local_384`/
 * `local_388`/`local_380` (a pending-submission dword count / byte
 * offset / a third counter, read and reset by opcode 0x26's "flush if a
 * transfer buffer needs a real backing" path and, per
 * stage4-opcode-range-0x02-0x31-traced.md, opcode 0x2b's explicit-flush
 * path too - not yet wired there, see that handler's own TODO),
 * `local_378` (a scratch VendorTransferBuffer* used by opcode 0x26 and,
 * per the raw decompile, opcode 0x37's surface-backed branch). Threaded
 * as a reference parameter to every handler that touches it, rather than
 * silently working around the gap - this is the correct fix for the
 * architectural tension the per-opcode split created, not a new
 * shortcut.
 */
struct ProcessCommandBufferState {
    UInt32 local_cc = 0;
    UInt32 local_384 = 0;
    UInt32 local_388 = 0;
    UInt32 local_380 = 0;
    void  *local_378 = nullptr;
};

/* ---- Per-opcode handlers, in real opcode order ---- */

/*
 * Opcodes 0x02/0x03: CONFIRMED, fully transcribed - genuinely trivial,
 * contrary to this project's earlier categorization as "HyperZ block
 * management" (that description belongs to 0x04/0x05 only). These two
 * just set the function's own eventual return value (`local_cc`) to 3
 * or 2 respectively - real, distinct status codes this project never
 * independently named. Real: no dword output, no record mutation - the
 * generic distance-based advance (this function's own dispatch loop)
 * handles cursor movement.
 */
static UInt32 *handle_set_return_code_3(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state) {
    (void)ctx;
    state.local_cc = 3;
    return record;
}
static UInt32 *handle_set_return_code_2(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state) {
    (void)ctx;
    state.local_cc = 2;
    return record;
}

/*
 * Opcode 0x04: CONFIRMED, fully transcribed real HyperZ/HiZ fast-clear
 * setup. Resolves the real bound-surface HiZ record (same two-mode
 * selection as build_scissor/write_kernel_context_buffer_regs), checks
 * a real "surface already fully HiZ-compressed" sentinel
 * (`surfaceRecord+0x28 == 0x3ff00000`-ish bit pattern) to choose between
 * a trivial fast-clear header and a real, dense HZMEM-block-offset-
 * driven partial-clear burst (real float math for the partial case, via
 * the same "magic bias" trick as opcode 0x31). Ends with a real vtable
 * call at offset 0x5a4 - the SAME real, still-unnamed virtual method
 * opcode 0x2f's HyperZ commit handler also calls.
 */
static UInt32 *handle_hyperz_fast_clear_setup(ATIR500GLContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    void *pAVar77;
    if (*reinterpret_cast<UInt32 *>(self + 0x3bc) == 0) {
        void *surfBase = reinterpret_cast<void *>(*reinterpret_cast<UInt32 *>(self + 0x290));
        UInt16 unit = *reinterpret_cast<UInt16 *>(self + 0xac);
        pAVar77 = reinterpret_cast<void *>(*reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(surfBase) + unit * 0x78 + 0xa8));
    } else {
        pAVar77 = self + (*reinterpret_cast<UInt16 *>(self + 0x3b2)) * 0x78 + 0x3c0;
    }

    UInt32 uVar58 = record[1];
    UInt32 uVar55 = record[2];
    *record = 0xc0011000;
    if ((*reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x28) & 0x3ff00000u) == 0x3ff00000u) {
        *record = 0xc00b1000;
    } else {
        UInt32 uVar61 = HZMEM_GetBlockOffset(reinterpret_cast<_HZDATA *>(reinterpret_cast<UInt8 *>(ctx->accelerator) + 0x870),
                                              *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x28), 2);
        UInt32 uVar38 = HZMEM_GetBlockCount(reinterpret_cast<_HZDATA *>(reinterpret_cast<UInt8 *>(ctx->accelerator) + 0x870),
                                             *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x28), 2);
        UInt8 *boundSurfaceBase = reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(self + 0x290));
        bool volatileGate = (*reinterpret_cast<UInt32 *>(boundSurfaceBase + 0xbe8) & 0x700000) == 0;
        if (volatileGate || *reinterpret_cast<SInt16 *>(self + 0xac) != 9) {
            record[0xc] = 0;
        } else {
            record[0xc] = 0x600;
        }
        record[8] = uVar61;
        UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);
        record[9] = uVar38 / static_cast<UInt32>((*reinterpret_cast<SInt32 *>(accel + 0xb98)) << 4);
        UInt32 isPartial = HZMEM_IsPartial(reinterpret_cast<_HZDATA *>(accel + 0x870),
                                            *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x28), 2);
        if (isPartial == 0) {
            record[0xd] = (uVar58 - 2) * 0x10000 | 0xc0001000;
        } else {
            UInt16 uVar15 = *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x1e);
            UInt32 iVar48 = ((*reinterpret_cast<UInt32 *>(accel + 0xb74) & 0x10000) == 0) ? 0xc : 0x10;
            UInt32 uVar38b = 0;
            if ((*reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x3c) & 0xf00000) != 0) {
                uVar38b = static_cast<UInt32>(*reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x14)) /
                          ((*reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x3c) >> 0x14) & 0xf);
            }
            UInt32 uVar73 = 0x20 / *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x16);
            if (uVar73 <= uVar38b) uVar73 = uVar38b;
            SInt32 iVar33 = 0x20;
            UInt32 uVar38c;
            if (*reinterpret_cast<SInt32 *>(accel + 0xb98) == 4) {
                uVar38c = static_cast<UInt32>(iVar33 * ((iVar33 + static_cast<SInt32>(uVar73) - 1) / iVar33));
            } else {
                iVar33 = (*reinterpret_cast<SInt32 *>(accel + 0xb98)) << 4;
                uVar38c = (iVar33 != 0) ? static_cast<UInt32>(iVar33 * ((iVar33 + static_cast<SInt32>(uVar73) - 1) / iVar33)) : 0;
            }
            UInt32 blockCount2 = HZMEM_GetBlockCount(reinterpret_cast<_HZDATA *>(accel + 0x870),
                                                      *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x28), 2);
            double dVar31 = DOUBLE_0004c3b8; /* real, distinct third bias constant this pass found - see ATIRadeonX1000Registers.h */
            uVar38c = (static_cast<UInt32>(blockCount2 << 4) / uVar38c) & 0xfffffff0u;
            UInt32 iStack_1b4 = uVar15 + uVar38c;
            record[uVar55 + 1] = (static_cast<UInt32>(iVar48 * (uVar15 - uVar38c)) >> 1) | (record[uVar55 + 1] & 0xffff0000u);
            /* real: `(float)((double)CONCAT44(0x43300000,iStack_1b4) - DOUBLE_0004c3b0) * dVar31` -
             * the SAME magic-bias trick as opcode 0x31, unsigned this time (no XOR 0x80000000). */
            union { double d; struct { UInt32 hi, lo; } parts; } u;
            u.parts.hi = 0x43300000; u.parts.lo = iStack_1b4;
            float biased = static_cast<float>(u.d - DOUBLE_0004c3b0);
            record[uVar55 + 7] = static_cast<UInt32>(biased * static_cast<float>(dVar31));
        }
        *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x36) = 1;
    }
    *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(pAVar77) + 0x30) = record[6];
    /* real vtable call at offset 0x5a4 - UNKNOWN real virtual method name,
     * same unresolved slot as opcode 0x2f (Sources/ATIR500GLContext_ProcessCommandBuffer.cpp) */
    // (**(code**)(*(int*)this + 0x5a4))(this);
    return record; /* real: falls to LAB_00031340, this function's own generic distance-based advance */
}

/*
 * Opcode 0x05: CONFIRMED, fully transcribed real HyperZ Z-pass/stencil
 * block setup - the densest of the four HyperZ opcodes. Real, two-part
 * structure: (1) a trivial "not usable" fast-out path when the surface's
 * HiZ field is fully masked; (2) a real dual-block-query path (block
 * kind 0 AND block kind 1 - plausibly depth vs. stencil) computing real
 * tile-scale/pitch adjustments and, when partial, a real float-based
 * scale factor via the same magic-bias trick, writing into a SEPARATE
 * context's own buffer (`this+0x348`) if this context is itself in
 * alternate mode - real, direct evidence of cross-context HiZ state
 * sharing this project had not previously documented.
 */
static UInt32 *handle_hyperz_zpass_setup(ATIR500GLContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);
    void *pAVar77 = self + 0x5a0;
    if (*reinterpret_cast<UInt32 *>(self + 0x3bc) == 0) {
        void *surfBase = reinterpret_cast<void *>(*reinterpret_cast<UInt32 *>(self + 0x290));
        UInt16 unit = *reinterpret_cast<UInt16 *>(self + 0xae);
        pAVar77 = reinterpret_cast<void *>(*reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(surfBase) + unit * 0x78 + 0xa8));
    }
    UInt8 *p77 = reinterpret_cast<UInt8 *>(pAVar77);

    UInt32 uVar55 = *reinterpret_cast<UInt32 *>(p77 + 0x28);
    UInt32 uVar58 = record[1], uVar64 = record[2], uVar61 = record[3], uVar62 = record[5];

    if ((uVar55 & 0x3ff) == 0x3ff || (uVar55 & 0xffc00) == 0xffc00) {
        *record = (record[4] - 2) * 0x10000 | 0xc0001000;
        p77[0x35] = 0; p77[0x34] = 0;
        return record; /* real: falls to LAB_00031340 */
    }

    *record = 0xc0041000;
    UInt32 blockOffset0 = HZMEM_GetBlockOffset(reinterpret_cast<_HZDATA *>(accel + 0x870), uVar55, 0);
    UInt32 blockCount0 = HZMEM_GetBlockCount(reinterpret_cast<_HZDATA *>(accel + 0x870), *reinterpret_cast<UInt32 *>(p77 + 0x28), 0);
    UInt32 isPartial0 = HZMEM_IsPartial(reinterpret_cast<_HZDATA *>(accel + 0x870), *reinterpret_cast<UInt32 *>(p77 + 0x28), 0);
    UInt32 blockOffset1 = HZMEM_GetBlockOffset(reinterpret_cast<_HZDATA *>(accel + 0x870), *reinterpret_cast<UInt32 *>(p77 + 0x28), 1);
    UInt32 blockCount1 = HZMEM_GetBlockCount(reinterpret_cast<_HZDATA *>(accel + 0x870), *reinterpret_cast<UInt32 *>(p77 + 0x28), 1);
    UInt32 isPartial1 = HZMEM_IsPartial(reinterpret_cast<_HZDATA *>(accel + 0x870), *reinterpret_cast<UInt32 *>(p77 + 0x28), 1);
    SInt32 iVar33 = (*reinterpret_cast<SInt32 *>(accel + 0xb98)) * (*reinterpret_cast<SInt32 *>(accel + 0xb9c));

    record[9] = blockOffset0;
    record[10] = blockCount0 / static_cast<UInt32>(iVar33 * 0x10);
    p77[0x34] = 1;

    if (uVar58 == 0) {
        p77[0x35] = 0;
    } else if ((*reinterpret_cast<UInt32 *>(p77 + 0x28) & 0xffc00u) == 0xffc00u) {
        *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(record) + uVar64) = 0xc0021000;
        p77[0x35] = 0;
    } else {
        record[uVar64 / 4 + 1] = blockOffset1;
        record[uVar64 / 4 + 2] = blockCount1 / static_cast<UInt32>(iVar33 * 4);
        p77[0x35] = 1;
    }

    if (isPartial0 == 0 && isPartial1 == 0) {
        record[uVar62 + 1] &= 0xffff0000u;
    } else {
        UInt32 uVar75 = 0;
        SInt32 iVar48 = *reinterpret_cast<SInt32 *>(accel + 0xb98);
        UInt8 *unitRecAe = self + (*reinterpret_cast<UInt16 *>(self + 0xae)) * 0x78 + *reinterpret_cast<UInt32 *>(self + 0x290);
        if ((*reinterpret_cast<UInt32 *>(unitRecAe + 0xe4) & 0xf00000) != 0) {
            uVar75 = static_cast<UInt32>(*reinterpret_cast<UInt16 *>(unitRecAe + 0xbc)) /
                     ((*reinterpret_cast<UInt32 *>(unitRecAe + 0xe4) >> 0x14) & 0xf);
        }
        UInt32 uVar37 = 0x20 / *reinterpret_cast<UInt16 *>(unitRecAe + 0xbe);
        if (uVar37 <= uVar75) uVar37 = uVar75;
        SInt32 tileBase;
        UInt32 uVar75b;
        if (iVar48 == 4) {
            tileBase = 0x20;
            uVar75b = static_cast<UInt32>(tileBase * ((tileBase + static_cast<SInt32>(uVar37) - 1) / tileBase));
        } else {
            tileBase = iVar48 << 4;
            uVar75b = (tileBase != 0) ? static_cast<UInt32>(tileBase * ((tileBase + static_cast<SInt32>(uVar37) - 1) / tileBase)) : 0;
        }
        UInt16 uVar53 = *reinterpret_cast<UInt16 *>(p77 + 0x1e);
        UInt32 uVar37b = (*reinterpret_cast<UInt32 *>(accel + 0xb74) >> 4) & 3;
        SInt32 iVar59 = uVar37b * 0x10;
        SInt32 iVar33b = (iVar48 == 4) ? static_cast<SInt32>(uVar37b << 5) : iVar59;
        UInt32 uVar38 = (blockCount1 < blockCount0) ? blockCount1 : blockCount0;
        UInt32 uVar73 = (uVar75b != 0) ? ((uVar38 * static_cast<UInt32>(iVar59)) / uVar75b) & static_cast<UInt32>(-iVar33b) : 0;
        UInt32 uVar38b = (uVar53 != 0) ? ((record[uVar62 + 1] & 0xffffu) / uVar53) * (uVar53 - uVar73) : 0;

        void *local_378 = nullptr;
        if ((*reinterpret_cast<UInt32 *>(p77 + 0x3c) & 0xf000) != 0) {
            UInt32 iStack_1ac = uVar73 + uVar53;
            UInt32 uStack_1a4 = ((*reinterpret_cast<UInt32 *>(p77 + 0x3c) >> 0xc) & 0xf) ^ 0x80000000u;
            union { double d; struct { UInt32 hi, lo; } p; } uA; uA.p.hi = 0x43300000; uA.p.lo = uStack_1a4;
            float fVar4 = static_cast<float>(uA.d - DOUBLE_0004c3a8);
            union { double d; struct { UInt32 hi, lo; } p; } uB; uB.p.hi = 0x43300000; uB.p.lo = iStack_1ac;
            float ratio = static_cast<float>(uB.d - DOUBLE_0004c3b0) / (fVar4 + fVar4);
            local_378 = reinterpret_cast<void *>(static_cast<UInt32>(ratio));
        }
        record[uVar62 + 1] = uVar38b | (record[uVar62 + 1] & 0xffff0000u);
        record[uVar62 + 7] = reinterpret_cast<UInt32>(local_378);
    }

    *reinterpret_cast<UInt32 *>(p77 + 0x2c) = record[uVar61];
    if (*reinterpret_cast<UInt32 *>(self + 0x3bc) != 0 && *reinterpret_cast<UInt32 *>(self + 0x348) != 0) {
        /* real, direct cross-context HiZ state sharing - see file header note */
        UInt8 *otherCtx = reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(self + 0x348));
        *reinterpret_cast<UInt32 *>(otherCtx + 0x7c) = record[uVar61];
        *reinterpret_cast<UInt16 *>(otherCtx + 0x7a) = static_cast<UInt16>(p77[0x34]) | (static_cast<UInt16>(p77[0x35]) << 8);
    }
    /* real vtable call at offset 0x5a4 - see handle_hyperz_fast_clear_setup's identical note */
    return record; /* real: falls to LAB_00031340 */
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
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt32 unitIndex = (opcode + 0xea000000u) >> 0x16;
    VendorTextureBuffer **slot = reinterpret_cast<VendorTextureBuffer **>(self + unitIndex + 0x2a4);
    if (*slot != nullptr) {
        ctx->remove_texture_from_stream(*slot);
        /*
         * CONFIRMED, previously missing from this handler: a SECOND real
         * step after remove_texture_from_stream - a real atomic
         * (PowerPC lwarx/stwcx.-style) decrement of the texture's GART-
         * mapping refcount at `texture+0x14`, further offset `+0x10`
         * (the identical pattern this project's discard_command_buffer
         * transcription already named `ReleaseBoundTextureSlot`), and if
         * it just hit zero, a real call to IOATIR500Shared::delete_texture.
         * Represented non-atomically per the same rationale given in
         * Sources/ATIR500GLContext_DiscardBuffer.cpp.
         */
        VendorTextureBuffer *tex = *slot;
        void *rec = reinterpret_cast<void *>(*reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(tex) + 0x14));
        UInt32 *countField = reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(rec) + 0x10);
        UInt32 before = *countField;
        *countField = before - 1;
        if (before == 1) {
            IOATIR500Shared *shared = *reinterpret_cast<IOATIR500Shared **>(self + 0x88);
            (void)shared; /* real: IOATIR500Shared::delete_texture(shared, tex); */
        }
        *slot = nullptr;
    }
    *record = PM4_TYPE2_FILLER; /* real: LAB_0002eae8 */
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

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }

/* Real render-target offset/tiling burst - the SAME shape used by
 * opcodes 0x28/0x2a and write_kernel_context_buffer_regs. Factored out
 * once here since 0x2a computes it twice (main + secondary target). */
UInt32 RTOffsetTilingBurst(void *pAVar77, UInt32 unitIndex, UInt32 nextIndex, UInt32 mipFraction) {
    UInt32 hz = 0;
    if ((U32At(pAVar77, 0x3c) & 0xf00000) != 0) {
        hz = static_cast<UInt32>(U16At(pAVar77, 0x14)) / ((U32At(pAVar77, 0x3c) >> 0x14) & 0xf);
    }
    UInt32 tileDim = 0x20 / U16At(pAVar77, 0x16);
    if (tileDim <= hz) tileDim = hz;
    UInt32 msb = (U8At(pAVar77, 0x38) < 2) ? 0u : 0x80000000u;
    return msb | ((U32At(pAVar77, unitIndex * 4 + 0x40) * static_cast<UInt32>(U16At(pAVar77, 0x20)) +
                   mipFraction * (U32At(pAVar77, nextIndex * 4 + 0x40) - U32At(pAVar77, unitIndex * 4 + 0x40)) +
                   U32At(pAVar77, 8)) >> 10) |
           ((tileDim * U16At(pAVar77, 0x16) * 0x10000u) & 0x3fc00000u) |
           ((U8At(pAVar77, 0x38) & 1u) << 0x1e);
}
} // namespace

/*
 * Opcode 0x26: CONFIRMED, fully transcribed real GART transfer-buffer
 * bind (real kext offset within the ~0x2e900-0x2ea00 dispatch region).
 * Real, substantially more involved than this project's earlier
 * simplified version: looks up a real texture-table entry via `this+0x88`,
 * swaps it into `transferBufferSlot` (`this+0x328`) with real refcount
 * inc/dec on the old/new entries, and - if the new entry has no real
 * backing yet (`+4 == 0`) - a real "flush pending buffer if non-empty"
 * step (referencing this function's own shared `ProcessCommandBufferState`)
 * followed by TWO real map_transfer_to_GART calls (the new entry, and,
 * if `this+0xd0` is still zero, a second fixed buffer at `this+0xcc`).
 * Self-consumes into a real two-dword `0x80000000` pair plus a real
 * "attach cookie" write at `record[5]`.
 */
static UInt32 *handle_bind_transfer_buffer(ATIR500GLContext *ctx, UInt32 *record, ProcessCommandBufferState &state) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    void *sharedAllocator = reinterpret_cast<void *>(U32At(self, 0x88));

    if (U32At(sharedAllocator, 0x14) <= record[1]) return record; /* real: goto LAB_00030d40 - falls to the generic advance, see the dispatch loop's own note */
    VendorTextureBuffer *tex = reinterpret_cast<VendorTextureBuffer *>(U32At(reinterpret_cast<void *>(U32At(sharedAllocator, 0x10)), record[1] * 4));
    if (tex == nullptr) return record; /* same real fallthrough */

    VendorTextureBuffer *old = reinterpret_cast<VendorTextureBuffer *>(U32At(self, 0x328));
    void *local_378 = tex;
    if (old != tex) {
        if (old != nullptr) {
            U32At(reinterpret_cast<void *>(U32At(old, 0x14)), 8) = U32At(ctx->accelerator, 0x50);
            *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(U32At(self, 0x328)) + 0xe) -= 1;
        }
        *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(tex) + 0xe) += 1;
        U32At(self, 0x328) = reinterpret_cast<UInt32>(tex);
    }

    if (U32At(tex, 4) == 0) {
        if (state.local_384 != 0) {
            UInt32 uVar38 = static_cast<UInt32>(record[-1]) >> 2;
            if (4 < uVar38) {
                UInt32 uVar73 = (uVar38 != 5) ? (((uVar38 - 6) * 0x10000) | 0xc0001000u) : 0x80000000u;
                record[-static_cast<SInt32>(uVar38)] = uVar73;
            }
            record[-4] = 0x1393; record[-3] = 0; record[-2] = 0x5c8; record[-1] = 0x20000;
            U32At(ctx->accelerator, 0x704) += state.local_384 * 4;
            U32At(ctx->accelerator, 0xb94) = 1;
            UInt32 newTag = ctx->accelerator->submit_buffer(
                reinterpret_cast<UInt32 *>(((state.local_388 & 0xfffffffcu) + U32At(self, 0xe0) + 0x20)),
                state.local_388 + U32At(self, 0xd0) + 0x20, state.local_384);
            U32At(self, 0xdc) = newTag;
            UInt32 uVar55 = state.local_384;
            state.local_380 = 0;
            state.local_384 = 0;
            state.local_388 = uVar55 * 4 + state.local_388;
        }
        ctx->map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(local_378));
        if (U32At(self, 0xd0) == 0) {
            ctx->map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(self + 0xcc));
        }
    }
    *record = 0x80000000u;
    record[1] = 0x80000000u;
    record[5] = U32At(local_378, 4) + U32At(ctx->accelerator, 0x8a4) + record[5] + 0x80;
    return record; /* real: falls to LAB_00031340 */
}

/*
 * Opcode 0x27: CONFIRMED, fully transcribed. The real transfer-buffer
 * unbind - decrements the currently-bound transfer buffer's refcount
 * (if any), clears `transferBufferSlot`, then jumps into the SAME
 * simple `record[0] = 0x80000000` self-erasure the plain texture-unbind
 * family uses (`LAB_0002eae8` in the raw decompile).
 */
static UInt32 *handle_unbind_transfer_buffer(ATIR500GLContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    void *bound = reinterpret_cast<void *>(U32At(self, 0x328));
    if (bound != nullptr) {
        U32At(reinterpret_cast<void *>(U32At(bound, 0x14)), 8) = U32At(ctx->accelerator, 0x50);
        *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(bound) + 0xe) -= 1;
        U32At(self, 0x328) = 0;
    }
    *record = PM4_TYPE2_FILLER;
    return record + 1;
}

/*
 * Opcode 0x28: CONFIRMED, fully transcribed real single render-target +
 * scissor commit, including the real methodological finding that this
 * opcode's embedded register index 0x50b (byte 0x142c) is NOT real MMIO
 * - a driver-internal software field (ATIRadeonX1000Registers.h). Real
 * header `0x105bb` OVERWRITES `record[0]` itself (the marker's own
 * dword) - the reason the dispatch loop's shared "record unchanged means
 * apply the generic advance" rule reads `header` captured BEFORE this
 * handler runs, not `*record` afterward.
 */
static UInt32 *handle_single_rendertarget_scissor(ATIR500GLContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    void *pAVar77;
    UInt32 unitIndex, nextIndex, mipFraction;
    if (U32At(self, 0x3bc) == 0) {
        mipFraction = U32At(self, 0x29c);
        unitIndex = U32At(self, 0x298);
        nextIndex = mipFraction + 1;
        void *surfBase = reinterpret_cast<void *>(U32At(self, 0x290));
        pAVar77 = reinterpret_cast<void *>(U32At(surfBase, U16At(self, 0xac) * 4 + 0xb70));
    } else {
        unitIndex = 0; mipFraction = 0; nextIndex = 1;
        pAVar77 = self + U16At(self, 0x3b2) * 0x78 + 0x3c0;
    }

    *record = 0x105bb;
    record[1] = ctx->scissorY; /* this+0x354, CONFIRMED verbatim embed */
    record[2] = ctx->scissorX; /* this+0x358, CONFIRMED verbatim embed */
    record[3] = 0x50bu; /* CONFIRMED software-internal field index, NOT real MMIO - see ATIRadeonX1000Registers.h */
    record[4] = RTOffsetTilingBurst(pAVar77, unitIndex, nextIndex, mipFraction);
    return record; /* real: falls to LAB_00031340 */
}

/*
 * Opcode 0x29: CONFIRMED, fully transcribed - one of the two most
 * architecturally significant opcodes in the whole language. Now
 * cross-checked against BOTH this opcode's own real execute-path body
 * (found this pass) AND discard_command_buffer's independent trace - the
 * two agree exactly on the 8-case switch table. New real details this
 * pass added: a real "reset alternate-mode flag" step at entry, a real
 * PER-SLOT count (`this+0x3a8`) that only increments for cases that
 * actually match (0/1/2/3/7/8/0x10 - NOT case 0x11, which writes a fixed
 * slot without incrementing the count) rather than this project's
 * earlier fixed-4-slots assumption, and confirmation this opcode really
 * does call build_scissor()/write_kernel_context_buffer_regs() directly.
 */
static UInt32 *handle_vertex_format_and_commit(ATIR500GLContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);

    if (U32At(self, 0x3bc) != 0) U32At(self, 0x3bc) = 0;

    UInt32 uVar38 = 0;
    UInt32 *puVar69 = record;
    UInt8 *pAVar77 = self;
    for (SInt32 i = 4; i != 0; --i) {
        switch (puVar69[1]) {
            case 0:    U16At(self, static_cast<int>((uVar38 & 0xffffu) * 2) + 0x3aa) = 1; uVar38 = (uVar38 & 0xffffu) + 1; U16At(self, 0x3a8) = static_cast<UInt16>(uVar38); break;
            case 1:    U16At(self, static_cast<int>((uVar38 & 0xffffu) * 2) + 0x3aa) = 0; uVar38 = (uVar38 & 0xffffu) + 1; U16At(self, 0x3a8) = static_cast<UInt16>(uVar38); break;
            case 2:    U16At(self, static_cast<int>((uVar38 & 0xffffu) * 2) + 0x3aa) = 4; uVar38 = (uVar38 & 0xffffu) + 1; U16At(self, 0x3a8) = static_cast<UInt16>(uVar38); break;
            case 3:    U16At(self, static_cast<int>((uVar38 & 0xffffu) * 2) + 0x3aa) = 5; uVar38 = (uVar38 & 0xffffu) + 1; U16At(self, 0x3a8) = static_cast<UInt16>(uVar38); break;
            case 7:    U16At(self, static_cast<int>((uVar38 & 0xffffu) * 2) + 0x3aa) = 2; uVar38 = (uVar38 & 0xffffu) + 1; U16At(self, 0x3a8) = static_cast<UInt16>(uVar38); break;
            case 8:    U16At(self, static_cast<int>((uVar38 & 0xffffu) * 2) + 0x3aa) = 3; uVar38 = (uVar38 & 0xffffu) + 1; U16At(self, 0x3a8) = static_cast<UInt16>(uVar38); break;
            case 0x10: U16At(self, static_cast<int>((uVar38 & 0xffffu) * 2) + 0x3aa) = 9; uVar38 = (uVar38 & 0xffffu) + 1; U16At(self, 0x3a8) = static_cast<UInt16>(uVar38); break;
            case 0x11: U16At(pAVar77, 0x3aa) = 0x17; break; /* real: writes pAVar77 (the WALKING pointer, not `self`!) - see NOTE below */
            default: break;
        }
        puVar69 += 1;
        pAVar77 += 2;
    }

    if ((uVar38 & 0xffff) == 0) {
        U16At(self, 0x3a8) = 1;
        U16At(self, 0x3aa) = 1;
    }
    U16At(self, 0xac) = U16At(self, 0x3aa);
    U32At(self, 0x35c) = U16At(self, 0x3aa);
    if (record[5] == 0x10) {
        U16At(self, 0x3aa) = 9;
        U16At(self, 0xac) = 9;
    }

    if ((U32At(self, 0x8c) & 0x80) != 0) {
        UInt32 uVar55 = record[1];
        U16At(self, 0xae) = (uVar55 == 7 || uVar55 == 8) ? static_cast<UInt16>(uVar55) : 6;
    }

    /* real vtable call at offset 0x5a4 - same unresolved slot as opcodes 0x04/0x05/0x2f */
    // (**(code**)(*(int*)this + 0x5a4))(this);
    ctx->build_scissor();
    ctx->write_kernel_context_buffer_regs(record, 0, record[6], record[7]);
    return record; /* real: falls to LAB_00031340 */
}

/*
 * Opcode 0x2a: CONFIRMED, fully transcribed. Render-target-PAIR binding
 * plus the live scissor rectangle. Real structure: TWO independent
 * RTOffsetTilingBurst computations (one for the attachment-enum-selected
 * target, one for a SEPARATE, already-bound secondary target at
 * `this+0xac`'s unit) written into `record[0]`/`record[1]` respectively,
 * followed by the live scissor rect duplicated into BOTH `record[2]`/
 * `record[4]` (real - not a copy-paste artifact, the raw decompile writes
 * the same value twice).
 */
static UInt32 *handle_rendertarget_pair_scissor(ATIR500GLContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);

    UInt32 attachEnum = record[1];
    UInt32 slot;
    switch (attachEnum) {
        case 1: slot = 0; break;
        case 2: slot = 4; break;
        case 3: slot = 5; break;
        case 4: slot = 6; break;
        case 7: slot = 2; break;
        case 8: slot = 3; break;
        case 10: slot = 7; break;
        case 0xb: slot = 8; break;
        default: slot = 1; break;
    }

    bool altMode = U32At(self, 0x3bc) != 0;
    UInt32 unitIndex, nextIndex, mipFraction;
    void *pAVar77;
    if (!altMode) {
        unitIndex = U32At(self, 0x29c);
        mipFraction = U32At(self, 0x298);
        nextIndex = unitIndex + 1;
        void *surfBase = reinterpret_cast<void *>(U32At(self, 0x290));
        pAVar77 = reinterpret_cast<void *>(U32At(surfBase, slot * 4 + 0xb70));
    } else {
        unitIndex = 0; mipFraction = 0; nextIndex = 1;
        pAVar77 = self + U16At(self, 0x3b2) * 0x78 + 0x3c0;
    }
    *record = RTOffsetTilingBurst(pAVar77, unitIndex, nextIndex, mipFraction);

    void *pAVar77b;
    if (!altMode) {
        void *surfBase = reinterpret_cast<void *>(U32At(self, 0x290));
        pAVar77b = reinterpret_cast<void *>(U32At(surfBase, U16At(self, 0xac) * 4 + 0xb70));
    } else {
        pAVar77b = self + U16At(self, 0x3b2) * 0x78 + 0x3c0;
    }
    record[1] = RTOffsetTilingBurst(pAVar77b, unitIndex, nextIndex, mipFraction);

    UInt32 scissorY = ctx->scissorY;
    record[2] = scissorY;
    record[3] = ctx->scissorX;
    record[4] = scissorY; /* real: duplicated, not a transcription error - see doc comment */
    return record; /* real: falls to LAB_00031340 */
}

/*
 * Opcode 0x36: NEW, previously-uncatalogued opcode - found via
 * discard_command_buffer's cleanup-path trace (Sources/
 * ATIR500GLContext_DiscardBuffer.cpp), not via this function's own
 * execute-path decompile (this project has never located a 0x36 handler
 * in process_command_buffer's own real body - a real, open gap, see
 * GAPS.md). Modeled here by direct analogy with the discard-path's own
 * confirmed refcount semantics: a real texture REFERENCE SWAP at
 * `this+0x334`. Whether the execute path does anything beyond this
 * bookkeeping (e.g. an actual register write) is UNKNOWN.
 */
static UInt32 *handle_texture_reference_swap(ATIR500GLContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    void *oldTex = reinterpret_cast<void *>(*reinterpret_cast<UInt32 *>(self + 0x334));
    void *newTex = reinterpret_cast<void *>(record[1]);
    if (oldTex != nullptr && *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(oldTex) + 0x48) == 0) {
        *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(oldTex) + 0xe) -= 1;
    }
    if (newTex != nullptr && *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(newTex) + 0x48) == 0) {
        *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(newTex) + 0xe) += 1;
    }
    *reinterpret_cast<UInt32 *>(self + 0x334) = reinterpret_cast<UInt32>(newTex);
    *record = PM4_TYPE2_FILLER; /* INFERRED self-consuming marker erasure, matching every other confirmed opcode in this family - not independently confirmed for 0x36 specifically */
    return record + 1;
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
 * "blit via textured quad" technique. FULLY transcribed, literally,
 * in Sources/ATIR500GLContext_FSAAResolveBlit.cpp (see that file for the
 * transcription method and an honest caveat about the two real, open
 * integration/precision gaps it documents).
 */
extern UInt32 *ATIR500GLContext_handle_fsaa_resolve_blit(ATIR500GLContext *ctx, UInt32 *record);

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
    ProcessCommandBufferState state; /* real local_cc/local_384/local_388/local_380/local_378 - see the struct's own doc comment */
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
            case 0x02000000: next = handle_set_return_code_3(this, record, state); break;
            case 0x03000000: next = handle_set_return_code_2(this, record, state); break;
            case 0x04000000: next = handle_hyperz_fast_clear_setup(this, record); break;
            case 0x05000000: next = handle_hyperz_zpass_setup(this, record); break;
            case 0x17000000: case 0x1a000000: case 0x1d000000: case 0x20000000: case 0x23000000:
                next = handle_reserved_noop(this, opcode, record); break;
            case 0x26000000: next = handle_bind_transfer_buffer(this, record, state); break;
            case 0x27000000: next = handle_unbind_transfer_buffer(this, record); break;
            case 0x28000000: next = handle_single_rendertarget_scissor(this, record); break;
            case 0x29000000: next = handle_vertex_format_and_commit(this, record); break;
            case 0x2a000000: next = handle_rendertarget_pair_scissor(this, record); break;
            case 0x2b000000: next = handle_explicit_flush(this, record); break;
            case 0x2c000000: next = handle_mip_scissor_intersect(this, record); break;
            case 0x2f000000: next = handle_hyperz_commit(this, record); break;
            case 0x30000000: next = handle_fsaa_resolve_setup(this, record); break;
            case 0x31000000: next = ATIR500GLContext_handle_fsaa_resolve_blit(this, record); break;
            case 0x36000000: next = handle_texture_reference_swap(this, record); break;
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

        /*
         * CONFIRMED real structural fact this reconstruction pass found:
         * many real opcode bodies (0x02-0x05, the reserved no-ops,
         * 0x26-0x2a/0x2c/0x30/0x37-0x45) do NOT self-compute their own
         * "next record" pointer - they write real values into `record`'s
         * OWN fields (sometimes including `record[0]` itself, as opcode
         * 0x28 does) and then real-fall-through to the same generic
         * distance-based advance every other unrecognized opcode uses
         * (`LAB_00031340` in the raw decompile). A handler returning
         * `record` completely unchanged is the real, unambiguous signal
         * for this case (no opcode that genuinely advances zero dwords
         * makes sense - it would be a real infinite loop in the ORIGINAL
         * driver too), so it's used here as a real, safe sentinel rather
         * than threading a distance value through every handler
         * signature. IMPORTANT: this reads `header`, the dword captured
         * BEFORE any handler ran (some handlers, like opcode 0x28,
         * overwrite `record[0]` itself as part of their real logic) -
         * exactly matching the real function's own read-before-write
         * ordering.
         */
        if (next == record) {
            UInt32 distance = EMBEDDED_DISTANCE(header);
            if (distance == 0) return kIOReturnSuccess; /* INFERRED loop-termination condition, matching the default case above */
            next = record + distance;
        }

        record = next;
    }
}
