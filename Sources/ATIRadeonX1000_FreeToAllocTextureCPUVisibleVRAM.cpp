/*
 * ATIRadeonX1000_FreeToAllocTextureCPUVisibleVRAM.cpp
 *
 * RESOLVED (issue #47): `ATIRadeonX1000::freeToAllocTextureCPUVisibleVRAM`'s
 * real body, real addr 0x1e320. Only real caller is `prepare_texture_
 * for_pageoff_with_cpu` (issue #30, `Sources/ATIRadeonX1000_
 * TexturePageoff.cpp`), as its own real fallback when a direct
 * `ATIR500Memory::alloc` for the texture's own CPU-visible VRAM element
 * fails - walks this accelerator's own real "live CPU-visible-eligible
 * texture" list looking for a victim to evict, then retries the alloc.
 *
 * Real body: first calls the already-RESOLVED `sleepForTimeStamp`
 * (vtable +0x558, `Headers/ATIRadeonX1000.h`) with `poolSizeClass - 1`
 * (`this+0x50`, matching `prepare_texture_for_pageoff_with_cpu`'s own
 * `poolSizeClass` local exactly - same real field, same name reused
 * here). Then walks a real circular intrusive doubly-linked list of
 * `VendorTextureBuffer` nodes, embedded directly in this accelerator
 * object: sentinel/list-end address `this+0x5dc`, initial link
 * `this+0x604` (both currently unnamed padding in
 * `Headers/ATIRadeonX1000.h` - a real, newly-identified "live CPU-
 * visible texture list" this project hadn't previously named; left as
 * raw offsets here rather than restructuring that header, matching this
 * project's own established practice of not renaming a base struct's
 * padding just because one more consumer read into it - see
 * `ATIRadeonX1000_TexturePageoff.cpp`'s own raw-offset style for the
 * same accelerator object).
 *
 * For each node, skips forward (via `VendorTextureBuffer::listNext`,
 * `+0x28`, already-CONFIRMED real field) while its own
 * `transferBufferFlag` (`+0x48`, already-CONFIRMED) is below this
 * accelerator's own `+0x84c` threshold field (same real field
 * `prepare_texture_for_pageoff_with_cpu` already reads). A candidate's
 * `+0x14` field points at a real, still-opaque per-candidate object (own
 * real identity/type not established this pass); when null, the
 * candidate is unconditionally eligible; otherwise up to
 * `*(byte*)(entry+0x34)` 2-byte-stride entries starting at `entry` are
 * each checked via `(entry[+0x28] & ~entry[+0x1c]) == 0` (real "no flag
 * set outside what this entry allows" shape - exact real hardware
 * meaning UNKNOWN, transcribed for its bit-level behavior only) - ALL
 * must pass (zero entries counts as automatically eligible) for the
 * candidate to be evicted.
 *
 * An eligible candidate is evicted via the already-RESOLVED
 * `deallocate_texture` (vtable +0x524) FIRST, before anything else -
 * then the SAME `+0x14` companion object (re-read fresh from the node,
 * not cached - see HONEST FLAG below) has its own `+0x14` byte set to 1
 * and SIX consecutive UInt16 fields (`+0x28` through `+0x32` - the exact
 * same 6-slot span the eligibility check above walks) zeroed, i.e. a
 * real "mark this companion object free, clear every one of its up-to-6
 * real flag slots" reset. Only THEN is the node unlinked from the
 * accelerator's list (real doubly-linked unlink via the already-
 * CONFIRMED `surfaceOrFormatInfo`/`listNext` prev/next fields, each end
 * of the unlinked node then self-looped - CONFIRMED this is the exact
 * real inverse of `VendorTextureBuffer`'s own already-established
 * list-node shape) and this accelerator's own `+0x7e0` counter
 * incremented (real role INFERRED - a real "textures evicted this way"
 * count, not independently confirmed by any reader). Finally the
 * REQUESTED texture's own CPU-visible element is allocated via
 * `ATIR500Memory::alloc` with the exact same real (alignment, rangeStart,
 * rangeSize) argument shape `prepare_texture_for_pageoff_with_cpu`
 * itself already uses - success returns `true` immediately. Reaching the
 * sentinel with no eligible candidate found returns `false`.
 *
 * HONEST FLAG #1, not resolved this pass: the companion-object reset
 * (`entry->+0x14 = 1`, six `entry->+0x28.._0x32 = 0` writes) re-reads
 * `node->+0x14` FRESH for the null-entry case too (the real decompile
 * reaches this exact code both when `entry` was already known non-null
 * from the eligibility walk, AND via direct fallthrough when
 * `node->+0x14` is null) - read completely literally, the null-entry
 * case dereferences address `0x14` (and `0x28`..`0x32`). Transcribed
 * exactly as decompiled rather than adding a null check the real code
 * doesn't have, matching this project's confidence-tier discipline;
 * either this path is never actually reached with a null `+0x14` in
 * practice, or it's a real latent bug in Apple's own driver - not
 * independently confirmed either way this pass.
 *
 * HONEST FLAG #2, not resolved this pass: on alloc FAILURE after a real
 * eviction, the real decompile advances via the JUST-UNLINKED node's own
 * `listNext` (`goto LAB_0001e480` jumps into the same fallthrough the
 * normal "skip below threshold" path uses, which reads `node->+0x28`) -
 * but the unlink above already self-looped that exact field
 * (`node->+0x28 = node`, matching `VendorTextureBuffer`'s own established
 * "unlinked node points at itself" convention). Read literally, the next
 * outer-loop iteration re-examines the SAME already-evicted,
 * already-`deallocate_texture`'d node rather than advancing past it -
 * transcribed exactly as decompiled rather than "corrected" to reset to
 * the list head, matching this project's own confidence-tier discipline
 * for a genuinely uncertain real control-flow point (same category as
 * `allocAllSlaveSwapBuffers`'s already-flagged real failure-path anomaly,
 * issue #32) - not independently confirmed as a real vendor bug this
 * pass, but real enough to flag rather than silently paper over.
 *
 * Confidence: CONFIRMED for control flow, the list unlink shape, and
 * every field this project had already independently named
 * (`transferBufferFlag`/`listNext`/`surfaceOrFormatInfo`/`poolSizeClass`/
 * the accelerator's own `+0x7c`/`+0x84c` fields, `sleepForTimeStamp`/
 * `deallocate_texture`). The per-candidate `+0x14` companion object's
 * own real identity and the `+0x7e0` counter's real role are INFERRED,
 * not confirmed by any other reader in this project. No C++ compiler
 * was available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project).
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include "../Headers/ATIR500Memory.h"

namespace {
inline UInt8  &B(void *p, int o) { return *(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt16 &H(void *p, int o) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt32 &W(void *p, int o) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }
} // namespace

UInt32 ATIRadeonX1000::freeToAllocTextureCPUVisibleVRAM(VendorTextureBuffer *texture, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    sleepForTimeStamp(W(self, 0x50) - 1);

    UInt8 *listEnd = self + 0x5dc;      /* real sentinel address - newly-identified "live CPU-visible texture list" head, see file header comment */
    UInt8 *node = reinterpret_cast<UInt8 *>(W(self, 0x604));

    for (;;) {
        while (true) {
            if (node == listEnd) {
                return 0;
            }
            if (W(node, 0x48) >= W(self, 0x84c)) {
                break;
            }
            node = reinterpret_cast<UInt8 *>(W(node, 0x28)); /* VendorTextureBuffer::listNext */
        }

        UInt8 *entry = reinterpret_cast<UInt8 *>(W(node, 0x14));
        bool eligible;
        if (entry == nullptr) {
            eligible = true;
        } else {
            UInt32 entryCount = B(entry, 0x34);
            eligible = true;
            UInt8 *e = entry;
            for (UInt32 i = 0; i < entryCount; i++) {
                if ((H(e, 0x28) & static_cast<UInt16>(~H(e, 0x1c))) != 0) {
                    eligible = false;
                    break;
                }
                e += 2;
            }
        }

        if (!eligible) {
            node = reinterpret_cast<UInt8 *>(W(node, 0x28));
            continue;
        }

        deallocate_texture(reinterpret_cast<VendorTextureBuffer *>(node));

        /* Real companion-object reset - re-reads node->+0x14 fresh, exactly
           as decompiled (see HONEST FLAG #1 above for the null-entry case). */
        UInt8 *companion = reinterpret_cast<UInt8 *>(W(node, 0x14));
        B(companion, 0x14) = 1;
        H(companion, 0x28) = 0;
        H(companion, 0x2a) = 0;
        H(companion, 0x2c) = 0;
        H(companion, 0x2e) = 0;
        H(companion, 0x30) = 0;
        H(companion, 0x32) = 0;

        /* Real doubly-linked unlink: prev->next = next; next->prev = prev;
           node self-loops both ends (matches VendorTextureBuffer's own
           already-established prev/next field shape). */
        UInt8 *prev = reinterpret_cast<UInt8 *>(W(node, 0x24)); /* VendorTextureBuffer::surfaceOrFormatInfo */
        UInt8 *next = reinterpret_cast<UInt8 *>(W(node, 0x28));
        W(prev, 0x28) = reinterpret_cast<UInt32>(next);
        W(node, 0x28) = reinterpret_cast<UInt32>(node);
        W(next, 0x24) = reinterpret_cast<UInt32>(prev);
        W(node, 0x24) = reinterpret_cast<UInt32>(node);

        W(self, 0x7e0) = W(self, 0x7e0) + 1;

        ATIR500Memory *mem = reinterpret_cast<ATIR500Memory *>(W(self, 0x7c));
        if (mem->alloc(reinterpret_cast<GLKMemoryElement *>(reinterpret_cast<UInt8 *>(texture) + 0x40), size, 0x1000, 0, W(self, 0x84c)) != 0) {
            return 1;
        }
        /* real: advances via the just-unlinked node's own (now self-looped)
           listNext - see HONEST FLAG #2 in the file header comment. */
        node = reinterpret_cast<UInt8 *>(W(node, 0x28));
    }
}
