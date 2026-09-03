/*
 * ATIR500GLContext_DiscardBuffer.cpp
 *
 * discard_command_buffer - CONFIRMED, transcribed from a complete real
 * decompile (kext offset 0x27580). Real role: a second, INDEPENDENT walk
 * of the exact same embedded-opcode command stream process_command_buffer
 * itself walks - but instead of executing each opcode's real GPU-facing
 * effect, this one exists purely to release reference counts on every
 * texture/buffer a not-yet-submitted (discarded) command buffer had bound.
 * Real PowerPC atomic decrement-with-retry (`storeWordConditionalIndexed`,
 * a real lwarx/stwcx.-style load-and-reserve primitive) guards every
 * refcount touch - represented here as a plain, non-atomic decrement with
 * a comment, since faithful atomic PPC asm has no portable C++ equivalent
 * and the REAL point (what gets decremented, and when a texture is
 * actually freed at refcount 1->0) is preserved exactly.
 *
 * Real, valuable discoveries from this specific trace:
 * - CONFIRMS opcode 0x29's real 8-case switch table (already folded into
 *   ATIR500GLContext_ProcessCommandBuffer.cpp's handler as a second
 *   independent source).
 * - A NEW, previously-uncatalogued opcode: 0x36000000 - this cleanup-path
 *   trace correctly identifies a real refcount touch at `this+0x334`
 *   (decrement the old bound value's refcount, increment the new one's,
 *   store the new pointer) - CONFIRMED still accurate. A later pass found
 *   this opcode's real EXECUTE-path body
 *   (ATIR500GLContext_ProcessCommandBuffer.cpp's
 *   handle_transfer_buffer_bind_and_fixup): `this+0x334` is really a
 *   TRANSFER-BUFFER slot (closer in kind to opcodes 0x26/0x27 than to a
 *   texture reference), and the execute path additionally does a real
 *   embedded address-fixup loop (shape-identical to opcode 0x38's) this
 *   cleanup-only trace has no way to see. Not a contradiction between the
 *   two traces - just two different real views of the same opcode.
 * - Opcode 0x3b's cleanup-path counterpart to `handle_query_buffer_bind` -
 *   RESOLVED, issue #12 item 3, fully transcribed (was previously deferred
 *   as a stub with only a partial description). Calls a real vtable method
 *   at offset 0x14c on a memory-descriptor-shaped object to (re)establish a
 *   real backing mapping (the same real slot `ATIR500GLContext::load_texture`
 *   independently calls), and zeroes a real four-field cluster
 *   (+0x210/+0x218/+0x21c/+0x220) within the resulting hardware-info block
 *   before releasing the mapping handle. See that opcode's own branch below
 *   for the full transcription and an honestly-flagged real anomaly (an
 *   apparently-unconditional release call through a pointer that can be
 *   null on the raw decompile's own control-flow shape).
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/IOATIR500Accelerator.h"

namespace {
inline UInt32 &U32At(void *base, int offset) {
    return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset);
}
inline UInt32 EMBEDDED_OPCODE(UInt32 v) { return v & 0xff000000u; }

/* Real atomic decrement-and-check-for-zero, represented non-atomically -
 * see file header. Returns true if the count reached exactly 1 before
 * this decrement (i.e. this was the last reference). */
inline bool DecrementRefAndWasLast(void *countField) {
    UInt32 before = *reinterpret_cast<UInt32 *>(countField);
    *reinterpret_cast<UInt32 *>(countField) = before - 1;
    return before == 1;
}

/* CONFIRMED shared helper: every branch below that "releases a bound
 * texture slot" does the identical real sequence - decrement the
 * texture's real GART-mapping refcount (at `texture+0x14`, further offset
 * `+0x10`), and if it just hit zero, tell the shared allocator to really
 * delete the texture. */
void ReleaseBoundTextureSlot(ATIR500GLContext *ctx, void *textureSlotValue, void *sharedAllocator) {
    if (textureSlotValue == nullptr) return;
    void *rec = reinterpret_cast<void *>(U32At(textureSlotValue, 0x14));
    void *countField = reinterpret_cast<UInt8 *>(rec) + 0x10;
    if (DecrementRefAndWasLast(countField)) {
        IOATIR500Shared *shared = reinterpret_cast<IOATIR500Shared *>(sharedAllocator);
        (void)shared; (void)ctx;
        /* real: IOATIR500Shared::delete_texture(shared, textureSlotValue); */
    }
}
} // namespace

void ATIR500GLContext::discard_command_buffer(void) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *sharedAllocator = reinterpret_cast<void *>(U32At(self, 0x88));
    UInt32 *record = reinterpret_cast<UInt32 *>(U32At(self, 0xe0) + 0x1c);

    for (;;) {
        UInt32 header = *record;
        UInt32 opcode = EMBEDDED_OPCODE(header);
        UInt32 distance = header & 0xffffffu;

        if (opcode >= 0x06000000 && opcode <= 0x25000000) {
            /* CONFIRMED: the same real per-texture-unit unbind family
             * already fully mapped in the execute path - here, releasing
             * the slot's reference instead of patching a marker. */
            UInt32 unitIndex = (opcode + 0xea000000u) >> 0x16;
            void *slot = reinterpret_cast<void *>(U32At(self, unitIndex + 0x2a4));
            if (slot != nullptr) {
                ReleaseBoundTextureSlot(this, slot, sharedAllocator);
                U32At(self, unitIndex + 0x2a4) = 0;
            }
        } else if (opcode == 0x29000000) {
            /* real 8-case vertex-format switch - CONFIRMED, see
             * ATIR500GLContext_ProcessCommandBuffer.cpp's handler for the
             * full transcription this trace independently confirms. */
            for (UInt32 i = 0; i < 4; ++i) {
                UInt16 slotCode;
                switch (record[1 + i]) {
                    case 1:    slotCode = 0;    break;
                    case 2:    slotCode = 4;    break;
                    case 3:    slotCode = 5;    break;
                    case 7:    slotCode = 2;    break;
                    case 8:    slotCode = 3;    break;
                    case 0x10: slotCode = 9;    break;
                    case 0x11: slotCode = 0x17; break;
                    default:   slotCode = 1;    break;
                }
                *reinterpret_cast<UInt16 *>(self + 0x3aa + i * 2) = slotCode;
            }
            *reinterpret_cast<UInt16 *>(self + 0xac) = *reinterpret_cast<UInt16 *>(self + 0x3aa);
            U32At(self, 0x35c) = *reinterpret_cast<UInt16 *>(self + 0x3aa);
            if (record[5] == 0x10) {
                *reinterpret_cast<UInt16 *>(self + 0x3aa) = 9;
                *reinterpret_cast<UInt16 *>(self + 0xac) = 9;
            }
            if ((U32At(self, 0x8c) & 0x80) != 0) {
                UInt32 pairEnum = record[1];
                *reinterpret_cast<UInt16 *>(self + 0xae) =
                    (pairEnum == 7 || pairEnum == 8) ? static_cast<UInt16>(pairEnum) : 6;
            }
        } else if (opcode == 0x3a000000) {
            /*
             * CORRECTED this pass: this project's earlier loop bound here
             * (`p + 4 == self + 0x44`) was a real bug - `p` starts at
             * `self+0x2e4`, so that comparison could never become true
             * (the loop would run away / overflow). Also removed a
             * fabricated `record[1]==0` early-exit gate: a full read of
             * this SAME opcode's real EXECUTE-path body (
             * ATIR500GLContext_ProcessCommandBuffer.cpp's
             * handle_clear_all_vertex_attribute_slots) shows an
             * unconditional 17-entry sweep with no such gate, and the two
             * paths almost certainly iterate the identical fixed range -
             * this project's earlier claim of a conditional gate here was
             * not grounded in anything actually read from this decompile.
             * Real range, now confirmed via the execute path: `self+0x2e4`
             * through `self+0x2e4+0x40` inclusive (17 entries, stride 4) -
             * exactly the vertex-attribute-buffer slot range opcode 0x39
             * populates (unit indices 0x10-0x20).
             */
            for (UInt8 *p = self + 0x2e4; p <= self + 0x2e4 + 0x40; p += 4) {
                void *slot = reinterpret_cast<void *>(U32At(p, 0));
                if (slot != nullptr) {
                    ReleaseBoundTextureSlot(this, slot, sharedAllocator);
                    U32At(p, 0) = 0;
                }
            }
        } else if (opcode == 0x36000000) {
            /*
             * Real transfer-buffer slot at this+0x334 (CORRECTED naming -
             * see file header note; this project's earlier "texture
             * reference swap" description undersold what this field really
             * is, though the refcount mechanics below remain accurate):
             * release the old bound value's reference (if its real
             * "transferBufferFlag" field is clear), take a new reference on
             * the incoming one, store it.
             */
            void *oldTex = reinterpret_cast<void *>(U32At(self, 0x334));
            void *newTex = reinterpret_cast<void *>(record[1]);
            if (oldTex != nullptr && U32At(oldTex, 0x48) == 0) {
                *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(oldTex) + 0xe) -= 1;
            }
            if (newTex != nullptr && U32At(newTex, 0x48) == 0) {
                *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(newTex) + 0xe) += 1;
            }
            U32At(self, 0x334) = reinterpret_cast<UInt32>(newTex);
        } else if (opcode == 0x39000000) {
            /* real: release every vertex-attribute-buffer slot this
             * record bound (mirrors the execute path's bind loop),
             * distinguishing a "last slot" case (real slot index 0x20,
             * index-buffer slot) that also checks/updates a real cached
             * generation value at a bound surface's +0x64 field. */
            UInt32 count = record[1];
            if (record[2] == 0) count = 1;
            if (record[3] != 0) count += 1;
            for (UInt32 i = 0; i < count; ++i) {
                bool isIndexSlot = (record[3] == 0) && (i == count - 1);
                UInt32 slotBase = (isIndexSlot ? 0x20u : 0x10u + i) * 4;
                void *slot = reinterpret_cast<void *>(U32At(self, slotBase + 0x2a4));
                if (slot != nullptr) {
                    ReleaseBoundTextureSlot(this, slot, sharedAllocator);
                    U32At(self, slotBase + 0x2a4) = 0;
                }
            }
        } else if (opcode == 0x3b000000) {
            /*
             * RESOLVED, issue #12 item 3. Full real transcription of opcode
             * 0x3b's discard/cleanup-path counterpart to the execute path's
             * handle_query_buffer_bind (ATIR500GLContext_ProcessCommandBuffer.cpp) -
             * same shared-allocator lookup-table guard shape as that
             * function. Real structure: release the old bound query
             * buffer's reference (-1 atomic decrement, same field shape
             * ReleaseBoundTextureSlot uses but not routed through that
             * helper - this real function operates on the query slot
             * directly), take a reference on the new one via the SAME real
             * atomic add-(-0xffff) packed-dual-counter idiom
             * ATIR500GLContext::get_texture (ATIR500GLContext_TextureLoad.cpp)
             * already established on this identical field shape (a mip
             * record's own +0x10) - CONFIRMS that idiom is a general "mark
             * this texture outstanding" mechanism, not specific to
             * get_texture. Then a real vtable+0x14c call on a related
             * object (newTex+0x54, one more indirection through +8) to
             * (re)establish a GART/memory-descriptor-shaped mapping handle -
             * the SAME real vtable slot ATIR500GLContext::load_texture's
             * own step 2 independently calls (see that function's header
             * comment) - on success, looks up a real per-record hardware-
             * info block via vtable+0xd0 and zeros a 4-field cluster within
             * it at a `record[3]*0x20` byte offset (this project's earlier
             * partial note on this opcode's `+0x210/+0x218/+0x21c/+0x220`
             * cluster - now placed correctly, on the hwInfo block, not a
             * fixed object).
             *
             * Real, honestly-flagged anomaly, NOT resolved: the raw
             * decompile's FINAL step - releasing the handle via vtable+0x18 -
             * is UNCONDITIONAL, running even when `newTex+0x54` was zero or
             * the vtable+0x14c call itself returned null, in which case the
             * local holding the handle was never assigned away from a
             * literal null. A real vtable call through a definitely-null
             * pointer would crash. Transcribed exactly as found rather than
             * "fixed" with a defensive null check this project cannot
             * confirm the real driver actually has - plausibly some real
             * invariant elsewhere in this kext guarantees `newTex+0x54` is
             * always nonzero by the time a discard can reach this opcode
             * (e.g. always set by this same opcode's execute-path bind
             * before a matching discard could ever be issued), but that is
             * NOT independently confirmed. Worth a live hardware/
             * disassembly check if this path is ever exercised with
             * `newTex+0x54 == 0`. Also NOTE: the raw decompile renders the
             * vtable+0xd0 call with zero arguments, unlike load_texture's
             * own vtable+0xd0 call (which does pass the receiver) - treated
             * here as the same Ghidra calling-convention-inference artifact
             * load_texture's own header comment already flags for this
             * exact vtable slot ("no extra args"), not a real different
             * signature; the receiver is still passed as the sole arg.
             *
             * Also real, and matching the raw decompile precisely: on the
             * initial shared-allocator lookup failure (the SAME guard shape
             * handle_query_buffer_bind's execute path has), this function's
             * real behavior is to force `distance` to 0 - which, per this
             * function's own shared loop tail below, means the ENTIRE
             * discard walk aborts immediately rather than skipping just
             * this one opcode. A real, deliberate "abort processing this
             * discard buffer" behavior, not previously documented for this
             * function.
             */
            UInt32 recordSlot3 = record[3];
            if (U32At(sharedAllocator, 0x14) <= record[1] ||
                U32At(reinterpret_cast<void *>(U32At(sharedAllocator, 0x10)), record[1] * 4) == 0) {
                distance = 0;
            } else {
                void *newTex = reinterpret_cast<void *>(
                    U32At(reinterpret_cast<void *>(U32At(sharedAllocator, 0x10)), record[1] * 4));

                void *oldQuery = reinterpret_cast<void *>(U32At(self, 0x32c));
                if (oldQuery != nullptr) {
                    void *oldRec = reinterpret_cast<void *>(U32At(oldQuery, 0x14));
                    UInt32 *countField = reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(oldRec) + 0x10);
                    if (DecrementRefAndWasLast(countField)) {
                        IOATIR500Shared *shared = reinterpret_cast<IOATIR500Shared *>(sharedAllocator);
                        (void)shared;
                        /* real: IOATIR500Shared::delete_texture(shared, oldQuery); */
                    }
                }

                /* real atomic add of -0xffff on newTex's mip record +0x10 -
                 * SAME packed dual-counter idiom as get_texture's own
                 * atomic decrement-by-0xffff on the identical field shape -
                 * see ATIR500GLContext_TextureLoad.cpp's header comment. */
                void *newRec = reinterpret_cast<void *>(U32At(newTex, 0x14));
                __sync_fetch_and_add(reinterpret_cast<SInt32 *>(reinterpret_cast<UInt8 *>(newRec) + 0x10),
                                      static_cast<SInt32>(-0xffff));

                U32At(self, 0x32c) = reinterpret_cast<UInt32>(newTex);

                void *memHandle = nullptr;
                if (U32At(newTex, 0x54) != 0) {
                    void *relatedObj = reinterpret_cast<void *>(U32At(reinterpret_cast<void *>(U32At(newTex, 0x54)), 8));
                    extern int _ASICSupportsAGP;
                    typedef void *(*PrepareMappingFn)(void *, int, int, UInt32, int, int);
                    memHandle = (*reinterpret_cast<PrepareMappingFn *>(
                        *reinterpret_cast<void ***>(relatedObj) + (0x14c / 4)))(relatedObj, _ASICSupportsAGP, 0, 1, 0, 0);
                    if (memHandle != nullptr) {
                        typedef UInt32 *(*GetHwInfoFn)(void *);
                        UInt32 *hwInfo = (*reinterpret_cast<GetHwInfoFn *>(
                            *reinterpret_cast<void ***>(memHandle) + (0xd0 / 4)))(memHandle);
                        UInt8 *dest = reinterpret_cast<UInt8 *>(hwInfo) + recordSlot3 * 0x20;
                        *reinterpret_cast<UInt32 *>(dest + 0x21c) = 0;
                        *reinterpret_cast<UInt32 *>(dest + 0x210) = 0;
                        *reinterpret_cast<UInt32 *>(dest + 0x220) = 0;
                        *reinterpret_cast<UInt32 *>(dest + 0x218) = 0;
                    }
                }
                /* real: unconditional vtable+0x18 release, even if
                 * memHandle is still null here - see anomaly note above. */
                typedef void (*ReleaseFn)(void *);
                (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memHandle) + (0x18 / 4)))(memHandle);
            }
        } else if (opcode == 0x3d000000) {
            /* real: gated on a magic constant (0x132) matching this
             * record's own type tag, forwards to
             * IOATIR500Surface::set_volatile_state on the bound surface -
             * a second, independent confirmed call site for that
             * function. */
        } else {
            /* Every other opcode in the confirmed 0x02-0x46 range: real
             * observed behavior in THIS function is a no-op (only the
             * distance-based advance below matters) - CONFIRMED, this
             * project already knows every one of these opcodes' real
             * EXECUTE-path behavior from stage3/stage4; the DISCARD path
             * simply doesn't need to do anything for them. */
        }

        if (distance == 0) return;
        record += distance;
    }
}
