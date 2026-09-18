/*
 * IOATIR500Shared_TextureAlloc.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `IOATIR500Shared::delete_texture`, `new_surface_texture`,
 * `new_global_texture`, `new_agp_texture` (a real, previously-
 * undeclared helper `new_texture`/`new_agpref_texture` both call
 * through - added to the header this pass), `new_texture`,
 * `new_agpref_texture`, and three more real, previously-undeclared
 * helpers this pass's decompiling turned up: `alloc_buf_handle`,
 * `free_buf_handle` (a real growable bitmap-based handle table living
 * in the SAME `this+0x10`/`+0x14`/`+0x18` fields `alloc_handles()`
 * already established, see IOATIR500Shared_AllocHandles.cpp), and
 * `alloc_client_shared` (a real growable linked list of 0x2000-byte
 * "shared chunk" nodes at `this+0x20`, each subdivided into 0x80
 * client-visible 0x40-byte `sIOClientShared` slots, mapped once into
 * the client task and once into the kernel task).
 *
 * Real per-texture "kind" tag (`VendorTextureBuffer+0x20`, byte) values
 * established by cross-referencing every allocator below against
 * `delete_texture`'s own real per-kind teardown branches:
 *   0 = surface-owned texture (owner surface at +0x50, linked into the
 *       surface's own +0xbcc list via +0x54) - `new_surface_texture`.
 *   1 = "found existing global surface texture" companion reference
 *       (found texture at +0x50, its refcount bumped via
 *       `_OSIncrementAtomic`, the accelerator's global-shared object
 *       itself retained) - `new_global_texture`.
 *   2 = plain non-AGP-backed texture/data buffer (param2==0 case).
 *   3 = plain non-AGP-backed texture/data buffer (param2!=0 case) -
 *       gets the extra per-format-table-zeroing + `deallocate_texture`
 *       teardown `delete_texture` gates on kind 3/7.
 *   4 = a real, standalone AGP-mapped buffer - `new_agp_texture` itself
 *       (the base allocation kinds 1/6/7 all point a companion at).
 *   6 = "AGP-ref" texture wrapping an existing AGP companion at +0x54 -
 *       `new_agpref_texture`.
 *   7 = texture with a fresh, dedicated AGP companion at +0x58 (the
 *       `new_agp_texture()`-then-`new_texture()` combined path) - same
 *       extra per-format teardown as kind 3.
 *
 * Real global `_ASICSupportsAGP` - used here exactly as this project
 * already uses it in over a dozen other files (see e.g.
 * `IOATIR500Accelerator_DataBufferPool.cpp`, `ATIR500GLContext_
 * TextureLoad.cpp`'s own comment on this same symbol): a real Ghidra
 * global-symbol-table-collision artifact resolving several distinct
 * real globals/constants to one displayed name (a page-size-shaped
 * alignment mask in the rounding-math call sites here, the same
 * established "task" argument in `+0x14c` map() calls, and the
 * established "alignment" argument in `inTaskWithOptions`/`withAddress`
 * calls) - transcribed literally at every site, matching this
 * project's own established convention, rather than guessing a
 * disambiguated replacement.
 *
 * Real external symbols CONFIRMED this pass via Ghidra's own
 * ExternalLocation.getOriginalImportedName() (ground truth from the
 * kext's own Mach-O import table, not guessed):
 *   `IOMemoryDescriptor::withAddress(vm_address_t, IOByteCount,
 *   IODirection, task_t)` -> `__ZN18IOMemoryDescriptor11withAddressE
 *   jm11IODirectionP4task`.
 * `IOBufferMemoryDescriptor::inTaskWithOptions` reuses this project's
 * already-established real mangled name (see DataBufferPool.cpp).
 * `_OSIncrementAtomic`/`_OSDecrementAtomic` INFERRED (not independently
 * confirmed here) by exact calling-convention/field-offset match
 * against this project's own already-CONFIRMED `FUN_0003911c` ->
 * `_OSDecrementAtomic` (see ATIR500DVDContext_ProcessCommandBuffer.cpp)
 * - every call site here uses the identical single-pointer-arg,
 * compare-result-to-1 refcount idiom on the identical `clientShared+
 * 0x10` field shape. `_IOMalloc`/`_IOFree` likewise reused directly
 * (bypassing this binary's own per-object-file lazy-stub indirection
 * entirely - what matters for a correct load is that OUR compiled
 * object references the real named kernel symbol, not that it
 * replicates the original's internal stub chain).
 *
 * `FUN_00017508` (single pointer in, pointer out, gates a "reuse
 * existing AGP companion vs. treat as invalidated" branch in
 * `new_agp_texture`) - RESOLVED (issue #58 follow-up): live kxld read shows
 * it targets `IOMemoryDescriptor::withPersistentMemoryDescriptor(
 * IOMemoryDescriptor*)` (kernel 0x2d6514, exact nm match).
 *
 * One faithfully-preserved real-binary oddity: `new_texture`'s failed-
 * map (`+0x14c` returns null) failure path frees the buf handle and
 * releases the memory descriptor but does NOT release the just-
 * allocated `VendorTextureBuffer` record itself before returning -
 * unlike every other failure path in the same function. Transcribed
 * exactly as the real decompile shows it (not a transcription bug).
 *
 * Confidence: CONFIRMED for control flow and every real struct offset/
 * literal constant in `delete_texture`, `alloc_buf_handle`,
 * `free_buf_handle`, `alloc_client_shared` (each a real, complete,
 * standalone decompile, cross-checked field-by-field against this
 * project's own already-established `alloc_handles()`/struct-layout
 * comments). `new_surface_texture`/`new_global_texture`/`new_texture`/
 * `new_agpref_texture`/`new_agp_texture` CONFIRMED for control flow and
 * struct offsets; the exact real Apple identity of vtable slots
 * `+0x128`/`+0x14` (accelerator "global shared" retain, inferred by
 * exact pairing with `delete_texture`'s own already-transcribed
 * `release()` call on the same object) is INFERRED, not independently
 * verified via live hardware read (unlike issues #15/#20/#27-29's
 * technique) - flagged accordingly at each site.
 */

#include "../Headers/IOATIR500Shared.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"

extern "C" void *FUN_inTaskWithOptions(void *task, UInt32 options, UInt32 capacity, int align) asm("__ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj");
extern "C" void *FUN_withAddress(UInt32 address, UInt32 length, UInt32 direction, void *task) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");
extern "C" UInt32 OSDecrementAtomic_TexAlloc(void *addr) asm("_OSDecrementAtomic");
extern "C" UInt32 OSIncrementAtomic_TexAlloc(void *addr) asm("_OSIncrementAtomic");
extern "C" void *IOMalloc_TexAlloc(UInt32 size) asm("_IOMalloc");
extern "C" void IOFree_TexAlloc(void *ptr, UInt32 size) asm("_IOFree");
extern "C" int kernelPageSize asm("_page_size"); /* kernel page_size (0x1000). Ghidra labels every zero-immediate data relocation in this kext "_ASICSupportsAGP"; the real target of each site comes from the Mach-O relocation table (issue #58 follow-up) */
extern "C" int kernelTaskRef asm("_kernel_task"); /* kernel_task pointer value (alloc_client_shared's map() task argument) */

extern "C" void *FUN_00017508(void *obj) asm("__ZN18IOMemoryDescriptor30withPersistentMemoryDescriptorEPS_");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void *(*AllocVendorBufFn)(void *, UInt32);
typedef void (*ReleaseVendorBufFn)(void *, void *, UInt32);
typedef void (*ReleaseFn)(void *);
typedef void *(*MapFn)(void *, void *, int, UInt32, int, int);
typedef UInt32 (*GetVAFn)(void *);
} // namespace

/* ------------------------------------------------------------------ */
/* alloc_buf_handle / free_buf_handle - real addrs 0x16bb0 / 0x16cf0.  */
/* ------------------------------------------------------------------ */

bool IOATIR500Shared::alloc_buf_handle(void *record, UInt32 *outHandle) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 wordIdx = U32At(self, 0x1c) >> 5;
    UInt32 word = 0;

    while (true) {
        if (wordIdx < (U32At(self, 0x14) >> 5)) {
            UInt8 *bitmapBase = reinterpret_cast<UInt8 *>(U32At(self, 0x18));
            UInt32 byteOff = wordIdx * 4;
            word = *reinterpret_cast<UInt32 *>(bitmapBase + byteOff);
            if (word != 0xffffffffu) {
                goto foundWord;
            }
            UInt32 remaining = (U32At(self, 0x14) >> 5) - wordIdx;
            bool found = false;
            while (true) {
                byteOff += 4;
                wordIdx++;
                remaining--;
                if (remaining == 0) break;
                word = *reinterpret_cast<UInt32 *>(bitmapBase + byteOff);
                if (word != 0xffffffffu) { found = true; break; }
            }
            if (found) goto foundWord;
        }
        if (!alloc_handles()) {
            return false;
        }
    }

foundWord:
    {
        UInt32 bit = 0;
        UInt32 remaining = 0x20;
        UInt32 bestBit = 0x20;
        while (true) {
            bit++;
            remaining--;
            if (remaining == 0) break;
            bestBit = bit;
            if (((word >> (bit & 0x3f)) & 1) == 0) {
                goto foundBit;
            }
        }
        bestBit = 0x20;
    foundBit:
        UInt32 handle = wordIdx * 0x20 + bestBit;
        U32At(self, 0x1c) = handle + 1;
        *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(U32At(self, 0x10)) + handle * 4) = record;
        UInt8 *bitmapBase = reinterpret_cast<UInt8 *>(U32At(self, 0x18));
        UInt32 *w = reinterpret_cast<UInt32 *>(bitmapBase + wordIdx * 4);
        *w |= (1u << (bestBit & 0x3f));
        *outHandle = handle;
        return true;
    }
}

void IOATIR500Shared::free_buf_handle(void *record, UInt32 handle) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (U32At(self, 0x14) <= handle) {
        return;
    }
    UInt8 *primary = reinterpret_cast<UInt8 *>(U32At(self, 0x10));
    if (*reinterpret_cast<void **>(primary + handle * 4) != record) {
        return;
    }
    if (handle < U32At(self, 0x1c)) {
        U32At(self, 0x1c) = handle;
    }
    UInt32 wordByteOff = (handle >> 3) & 0x1ffffffc;
    *reinterpret_cast<void **>(primary + handle * 4) = nullptr;
    UInt8 *bitmapBase = reinterpret_cast<UInt8 *>(U32At(self, 0x18));
    UInt32 *w = reinterpret_cast<UInt32 *>(bitmapBase + wordByteOff);
    *w &= ~(1u << (handle & 0x1f));
}

/* ------------------------------------------------------------------ */
/* alloc_client_shared - real addr 0x16d50.                            */
/* ------------------------------------------------------------------ */

bool IOATIR500Shared::alloc_client_shared(UInt32 index, sIOClientShared **outKernelPtr, UInt32 *outUserAddr) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 *prevNode = nullptr;
    UInt32 *node = *reinterpret_cast<UInt32 **>(self + 0x20);

    for (;;) {
        while (node != nullptr) {
        useNode:
            prevNode = node;
            if (index < node[6]) {
                UInt8 *rec = reinterpret_cast<UInt8 *>(node[4]) + index * 0x40;
                *outKernelPtr = reinterpret_cast<sIOClientShared *>(rec);
                *outUserAddr = node[5] + index * 0x40;
                *reinterpret_cast<UInt32 *>(rec + 0x00) = 0;
                *reinterpret_cast<UInt32 *>(rec + 0x04) = 0;
                *reinterpret_cast<UInt32 *>(rec + 0x08) = 0;
                *reinterpret_cast<UInt32 *>(rec + 0x0c) = 0;
                *reinterpret_cast<UInt32 *>(rec + 0x10) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x1c) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x1e) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x20) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x22) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x24) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x26) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x28) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x2a) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x2c) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x2e) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x30) = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x32) = 0;
                rec[0x14] = 1;
                rec[0x15] = 0;
                rec[0x16] = 0;
                rec[0x34] = 0;
                rec[0x35] = 0;
                rec[0x17] = 0;
                *reinterpret_cast<UInt16 *>(rec + 0x36) = 0;
                return true;
            }
            index -= node[6];
            node = reinterpret_cast<UInt32 *>(node[0]);
        }

        node = reinterpret_cast<UInt32 *>(IOMalloc_TexAlloc(0x1c));
        if (node == nullptr) {
            return false;
        }
        node[1] = reinterpret_cast<UInt32>(
            FUN_inTaskWithOptions(*reinterpret_cast<void **>(self + 8), 0x10022, 0x2000, kernelPageSize));
        if (node[1] == 0) {
            goto releaseNode;
        }
        node[2] = reinterpret_cast<UInt32>(
            (*reinterpret_cast<MapFn *>(*reinterpret_cast<void ***>(node[1]) + (0x14c / 4)))(
                reinterpret_cast<void *>(node[1]), *reinterpret_cast<void **>(self + 8), 0, 1, 0, 0));
        if (node[2] != 0) {
            node[5] = (*reinterpret_cast<GetVAFn *>(*reinterpret_cast<void ***>(node[2]) + (0xd0 / 4)))(
                reinterpret_cast<void *>(node[2]));
            node[3] = reinterpret_cast<UInt32>(
                (*reinterpret_cast<MapFn *>(*reinterpret_cast<void ***>(node[1]) + (0x14c / 4)))(
                    reinterpret_cast<void *>(node[1]), reinterpret_cast<void *>(kernelTaskRef), 0, 1, 0, 0));
            if (node[3] != 0) {
                UInt8 *owner = *reinterpret_cast<UInt8 **>(self + 0xc);
                if (owner != nullptr) {
                    U32At(owner, 0x808) += 0x1c;
                }
                node[4] = (*reinterpret_cast<GetVAFn *>(*reinterpret_cast<void ***>(node[3]) + (0xd0 / 4)))(
                    reinterpret_cast<void *>(node[3]));
                node[0] = 0;
                node[6] = 0x80;
                if (prevNode == nullptr) {
                    *reinterpret_cast<UInt32 **>(self + 0x20) = node;
                } else {
                    *prevNode = reinterpret_cast<UInt32>(node);
                }
                goto useNode;
            }
            (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(node[2]) + (0x18 / 4)))(
                reinterpret_cast<void *>(node[2]));
        }
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(node[1]) + (0x18 / 4)))(
            reinterpret_cast<void *>(node[1]));
    releaseNode:
        IOFree_TexAlloc(node, 0x1c);
        return false;
    }
}

/* ------------------------------------------------------------------ */
/* delete_texture - real addr 0x17950.                                 */
/* ------------------------------------------------------------------ */

IOReturn IOATIR500Shared::delete_texture(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);

    UInt8 *head = reinterpret_cast<UInt8 *>(U32At(self, 0x24));
    if (head == tex) {
        U32At(self, 0x24) = U32At(tex, 0x3c);
    } else {
        if (head == nullptr) {
            return 0xe00002bc;
        }
        UInt8 *prevInList = head;
        UInt8 *cur = reinterpret_cast<UInt8 *>(U32At(head, 0x3c));
        while (cur != tex) {
            if (cur == nullptr) {
                return 0xe00002bc;
            }
            prevInList = cur;
            cur = reinterpret_cast<UInt8 *>(U32At(cur, 0x3c));
        }
        U32At(prevInList, 0x3c) = U32At(tex, 0x3c);
    }

    UInt8 *prev = reinterpret_cast<UInt8 *>(U32At(tex, 0x24));
    UInt8 kind = U8At(tex, 0x20);
    U32At(prev, 0x28) = U32At(tex, 0x28);
    UInt8 *next = reinterpret_cast<UInt8 *>(U32At(tex, 0x28));
    U32At(tex, 0x28) = reinterpret_cast<UInt32>(tex);
    U32At(next, 0x24) = reinterpret_cast<UInt32>(prev);
    U32At(tex, 0x24) = reinterpret_cast<UInt32>(tex);

    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
    void **accelVtable = *reinterpret_cast<void ***>(accel);
    typedef SInt32 (*Fn0x554)(void *, UInt32);
    typedef void (*DeallocTextureFn)(void *, void *);
    typedef void (*RemoveTransferFn)(void *, void *);

    if ((static_cast<UInt8>(kind - 2) < 2) || kind == 6 || kind == 7) {
        if (kind == 3 || kind == 7) {
            UInt8 *clientShared = reinterpret_cast<UInt8 *>(U32At(tex, 0x14));
            UInt32 i = 0;
            if (*reinterpret_cast<char *>(clientShared + 0x34) != 0) {
                do {
                    *reinterpret_cast<UInt16 *>(clientShared + 0x28 + i * 2) = 0;
                    i++;
                    clientShared = reinterpret_cast<UInt8 *>(U32At(tex, 0x14));
                } while (i < *reinterpret_cast<UInt8 *>(clientShared + 0x34));
            }
            if (U32At(tex, 0x48) != 0) {
                (*reinterpret_cast<DeallocTextureFn *>(accelVtable + (0x524 / 4)))(accel, tex);
            }
        }
        if (U32At(tex, 0x10) != 0) {
            void *gart = reinterpret_cast<void *>(U32At(tex, 0x10));
            (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(gart) + (0x18 / 4)))(gart);
            U32At(tex, 0x10) = 0;
        }

        UInt8 *companion = nullptr;
        bool haveCompanion = false;
        if (kind == 7) {
            companion = reinterpret_cast<UInt8 *>(U32At(tex, 0x58));
            U32At(tex, 0x58) = 0;
            haveCompanion = true;
        } else if (kind == 6) {
            companion = reinterpret_cast<UInt8 *>(U32At(tex, 0x54));
            U32At(tex, 0x54) = 0;
            haveCompanion = true;
        }
        if (haveCompanion) {
            UInt32 wasOne = OSDecrementAtomic_TexAlloc(reinterpret_cast<UInt8 *>(U32At(companion, 0x14)) + 0x10);
            if (wasOne == 1) {
                delete_texture(reinterpret_cast<VendorTextureBuffer *>(companion));
            }
        }

        if (U32At(tex, 4) != 0) {
            UInt8 *clientShared = reinterpret_cast<UInt8 *>(U32At(tex, 0x14));
            UInt32 arg = U32At(clientShared, 0xc);
            SInt32 stillLive = (*reinterpret_cast<Fn0x554 *>(accelVtable + (0x554 / 4)))(accel, arg);
            if (stillLive == 0) {
                reinterpret_cast<IOATIR500Accelerator *>(accel)->addOrphanTexture(reinterpret_cast<IOTextureBuffer *>(tex));
                U32At(accel, 0x72c) -= 1;
                return 0;
            }
            if (U32At(tex, 4) != 0) {
                (*reinterpret_cast<RemoveTransferFn *>(accelVtable + (0x5ac / 4)))(accel, tex);
            }
        }

        free_buf_handle(tex, U32At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0));
        if (U32At(tex, 8) != 0) {
            void *memDesc = reinterpret_cast<void *>(U32At(tex, 8));
            (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
            U32At(tex, 8) = 0;
        }
    } else {
        if (kind == 4) {
            if (U32At(tex, 0x10) != 0) {
                void *gart = reinterpret_cast<void *>(U32At(tex, 0x10));
                (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(gart) + (0x18 / 4)))(gart);
                U32At(tex, 0x10) = 0;
            }
            if (U32At(tex, 4) != 0) {
                UInt8 *clientShared = reinterpret_cast<UInt8 *>(U32At(tex, 0x14));
                UInt32 arg = U32At(clientShared, 8);
                SInt32 stillLive = (*reinterpret_cast<Fn0x554 *>(accelVtable + (0x554 / 4)))(accel, arg);
                if (stillLive == 0) {
                    reinterpret_cast<IOATIR500Accelerator *>(accel)->addOrphanTexture(reinterpret_cast<IOTextureBuffer *>(tex));
                    U32At(accel, 0x72c) -= 1;
                    return 0;
                }
                if (U32At(tex, 4) != 0) {
                    (*reinterpret_cast<RemoveTransferFn *>(accelVtable + (0x5ac / 4)))(accel, tex);
                }
            }
            free_buf_handle(tex, U32At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0));
            if (U32At(tex, 8) != 0) {
                void *memDesc = reinterpret_cast<void *>(U32At(tex, 8));
                (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
                U32At(tex, 8) = 0;
            }
        } else if (kind == 0) {
            UInt8 *surface = reinterpret_cast<UInt8 *>(U32At(tex, 0x50));
            if (surface != nullptr) {
                UInt8 *listHead = reinterpret_cast<UInt8 *>(U32At(surface, 0xbcc));
                if (tex == listHead) {
                    U32At(surface, 0xbcc) = U32At(tex, 0x54);
                } else {
                    UInt8 *cur = listHead;
                    UInt8 *found = nullptr;
                    while (cur != nullptr) {
                        found = cur;
                        cur = reinterpret_cast<UInt8 *>(U32At(cur, 0x54));
                        if (tex == cur) break;
                    }
                    if (found != nullptr) {
                        U32At(found, 0x54) = U32At(tex, 0x54);
                    }
                }
                reinterpret_cast<IOATIR500Surface *>(surface)->reset_req_bits();
                reinterpret_cast<IOATIR500Surface *>(surface)->prune_buffers();
            }
            free_buf_handle(tex, U32At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0));
        } else if (kind == 1) {
            UInt8 *companion = reinterpret_cast<UInt8 *>(U32At(tex, 0x50));
            if (companion != nullptr) {
                UInt32 wasOne = OSDecrementAtomic_TexAlloc(reinterpret_cast<UInt8 *>(U32At(companion, 0x14)) + 0x10);
                UInt8 *globalShared = reinterpret_cast<UInt8 *>(U32At(accel, 0x6c));
                if (wasOne == 1) {
                    reinterpret_cast<IOATIR500Shared *>(globalShared)->delete_texture(reinterpret_cast<VendorTextureBuffer *>(companion));
                }
                (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(globalShared) + (0x18 / 4)))(globalShared);
                U32At(tex, 0x50) = 0;
            }
            free_buf_handle(tex, U32At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0));
        } else {
            U32At(accel, 0x72c) -= 1;
            return 0;
        }
        (*reinterpret_cast<ReleaseVendorBufFn *>(accelVtable + (0x574 / 4)))(accel, tex, 0x80);
        U32At(accel, 0x72c) -= 1;
        return 0;
    }

    (*reinterpret_cast<ReleaseVendorBufFn *>(accelVtable + (0x574 / 4)))(accel, tex, 0x80);
    U32At(accel, 0x72c) -= 1;
    return 0;
}

/* ------------------------------------------------------------------ */
/* new_surface_texture - real addr 0x17520.                            */
/* ------------------------------------------------------------------ */

VendorTextureBuffer *IOATIR500Shared::new_surface_texture(UInt32 surfaceID, UInt32 param2, UInt32 param3, UInt32 *outParam) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
    void **accelVtable = *reinterpret_cast<void ***>(accel);

    void *surfaceRaw = reinterpret_cast<IOATIR500Accelerator *>(accel)->find_surface_for_id(surfaceID);
    if (surfaceRaw == nullptr) {
        return nullptr;
    }
    UInt8 *surf = reinterpret_cast<UInt8 *>(surfaceRaw);

    UInt8 *tex = reinterpret_cast<UInt8 *>((*reinterpret_cast<AllocVendorBufFn *>(accelVtable + (0x570 / 4)))(accel, 0x80));
    if (tex == nullptr) {
        return nullptr;
    }
    U32At(tex, 8) = 0;

    UInt32 handle;
    if (!alloc_buf_handle(tex, &handle)) {
        (*reinterpret_cast<ReleaseVendorBufFn *>(accelVtable + (0x574 / 4)))(accel, tex, 0x80);
        return nullptr;
    }
    sIOClientShared *clientShared;
    UInt32 userAddr;
    if (!alloc_client_shared(handle, &clientShared, &userAddr)) {
        free_buf_handle(tex, handle);
        (*reinterpret_cast<ReleaseVendorBufFn *>(accelVtable + (0x574 / 4)))(accel, tex, 0x80);
        return nullptr;
    }

    UInt8 *cs = reinterpret_cast<UInt8 *>(clientShared);
    U32At(tex, 0x14) = reinterpret_cast<UInt32>(cs);
    U32At(cs, 0) = handle;
    U32At(cs, 8) = U32At(accel, 0x54);
    U32At(cs, 0xc) = U32At(accel, 0x54);
    U8At(cs, 0x16) = 0;
    U8At(cs, 0x34) = static_cast<UInt8>(param3);
    U8At(tex, 0x20) = 0;
    U32At(tex, 0x10) = 0;
    U32At(tex, 0x58) = param2;
    U32At(tex, 0x5c) = surfaceID;
    U32At(tex, 0x1c) = reinterpret_cast<UInt32>(self);
    U32At(tex, 0x50) = reinterpret_cast<UInt32>(surf);
    U32At(tex, 0x3c) = U32At(self, 0x24);
    U32At(self, 0x24) = reinterpret_cast<UInt32>(tex);
    *outParam = userAddr;
    U32At(tex, 0x54) = U32At(surf, 0xbcc);
    U32At(surf, 0xbcc) = reinterpret_cast<UInt32>(tex);
    reinterpret_cast<IOATIR500Surface *>(surf)->reset_req_bits();
    reinterpret_cast<IOATIR500Surface *>(surf)->prune_buffers();
    U32At(accel, 0x72c) += 1;

    UInt8 *globalShared = reinterpret_cast<UInt8 *>(U32At(accel, 0x6c));
    if (self != globalShared) {
        return reinterpret_cast<VendorTextureBuffer *>(tex);
    }
    UInt32 seq = U32At(accel, 0x70);
    U32At(cs, 4) = seq;
    U32At(accel, 0x70) = seq + 1;
    return reinterpret_cast<VendorTextureBuffer *>(tex);
}

/* ------------------------------------------------------------------ */
/* new_global_texture - real addr 0x17740.                             */
/* ------------------------------------------------------------------ */

VendorTextureBuffer *IOATIR500Shared::new_global_texture(UInt32 param2, UInt32 *outParam) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (param2 == 0) {
        return nullptr;
    }
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
    UInt8 *globalShared = reinterpret_cast<UInt8 *>(U32At(accel, 0x6c));
    if (globalShared == nullptr || self == globalShared) {
        return nullptr;
    }

    for (UInt8 *cand = reinterpret_cast<UInt8 *>(U32At(globalShared, 0x24)); cand != nullptr;
         cand = reinterpret_cast<UInt8 *>(U32At(cand, 0x3c))) {
        UInt8 *candShared = reinterpret_cast<UInt8 *>(U32At(cand, 0x14));
        if (param2 != U32At(candShared, 4)) {
            continue;
        }

        void **accelVtable = *reinterpret_cast<void ***>(accel);
        UInt8 *tex = reinterpret_cast<UInt8 *>((*reinterpret_cast<AllocVendorBufFn *>(accelVtable + (0x570 / 4)))(accel, 0x80));
        if (tex == nullptr) {
            return nullptr;
        }
        UInt32 handle;
        if (!alloc_buf_handle(tex, &handle)) {
            (*reinterpret_cast<ReleaseVendorBufFn *>(accelVtable + (0x574 / 4)))(accel, tex, 0x80);
            return nullptr;
        }
        sIOClientShared *clientShared;
        UInt32 userAddr;
        if (!alloc_client_shared(handle, &clientShared, &userAddr)) {
            (*reinterpret_cast<ReleaseVendorBufFn *>(accelVtable + (0x574 / 4)))(accel, tex, 0x80);
            return nullptr;
        }

        UInt8 *cs = reinterpret_cast<UInt8 *>(clientShared);
        U32At(tex, 8) = 0;
        U32At(tex, 0x14) = reinterpret_cast<UInt32>(cs);
        U32At(cs, 0) = handle;
        U32At(cs, 8) = U32At(accel, 0x54);
        U32At(cs, 0xc) = U32At(accel, 0x54);
        U8At(cs, 0x16) = 1;
        U8At(tex, 0x20) = 1;
        U32At(tex, 0x10) = 0;
        U32At(tex, 0x1c) = reinterpret_cast<UInt32>(self);
        U32At(tex, 0x50) = reinterpret_cast<UInt32>(cand);

        /* real +0x10 refcount bump on the found companion (established
         * `_OSIncrementAtomic`, see file header), then a real +0x14
         * vtable call on the accelerator's own global-shared object
         * itself - INFERRED as `OSObject::retain()` by exact pairing
         * with `delete_texture`'s kind==1 teardown, which calls the
         * already-CONFIRMED `+0x18` `release()` on this SAME object
         * every time it tears down one of these companion references. */
        OSIncrementAtomic_TexAlloc(candShared + 0x10);
        typedef void (*RetainFn)(void *);
        (*reinterpret_cast<RetainFn *>(*reinterpret_cast<void ***>(globalShared) + (0x14 / 4)))(globalShared);

        U32At(tex, 0x3c) = U32At(self, 0x24);
        U32At(self, 0x24) = reinterpret_cast<UInt32>(tex);
        *outParam = userAddr;
        U32At(accel, 0x72c) += 1;
        return reinterpret_cast<VendorTextureBuffer *>(tex);
    }
    return nullptr;
}

/* ------------------------------------------------------------------ */
/* new_agp_texture - real addr 0x17150.                                */
/* ------------------------------------------------------------------ */

VendorTextureBuffer *IOATIR500Shared::new_agp_texture(UInt32 param1, UInt32 param2, UInt32 *outParam) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
    void **accelVtable = *reinterpret_cast<void ***>(accel);

    UInt32 pageOffset = (static_cast<UInt32>(kernelPageSize) - 1) & param1;
    UInt32 pageBase = param1 & static_cast<UInt32>(-kernelPageSize);
    UInt32 roundedSize = static_cast<UInt32>(-kernelPageSize) &
                          ((static_cast<UInt32>(kernelPageSize) + pageOffset + param2) - 1);

    if (roundedSize > (U32At(accel, 0x830) * 0xc00) >> 2) {
        return nullptr;
    }

    void *memDesc = nullptr;
    if (pageBase == 0) {
        memDesc = FUN_inTaskWithOptions(reinterpret_cast<void *>(U32At(self, 8)),
                                         U32At(accel, 0x82c) | 0x10022, roundedSize, kernelPageSize);
        if (memDesc == nullptr) {
            return nullptr;
        }
        typedef UInt32 (*GetBytesFn)(void *);
        pageBase = (*reinterpret_cast<GetBytesFn *>(*reinterpret_cast<void ***>(memDesc) + (0x1cc / 4)))(memDesc);
    } else {
        UInt8 *prevNode = nullptr;
        UInt8 *cur = reinterpret_cast<UInt8 *>(U32At(self, 0x24));
        UInt8 *node = nullptr;
        bool reused = false;

        while (cur != nullptr) {
            node = cur;
            if (U8At(node, 0x20) == 4 && U32At(node, 0x54) == 0 &&
                pageOffset == U32At(node, 0x50) && pageBase == U32At(node, 0x58) &&
                roundedSize == U32At(node, 0x5c)) {
                UInt8 *oldDesc = reinterpret_cast<UInt8 *>(U32At(node, 8));
                void *retained = FUN_00017508(oldDesc);
                if (retained == oldDesc) {
                    (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(retained) + (0x18 / 4)))(retained);
                    *outParam = U32At(node, 0x18);
                    if (node == reinterpret_cast<UInt8 *>(U32At(self, 0x24))) {
                        return reinterpret_cast<VendorTextureBuffer *>(node);
                    }
                    U32At(prevNode, 0x3c) = U32At(node, 0x3c);
                    U32At(node, 0x3c) = U32At(self, 0x24);
                    U32At(self, 0x24) = reinterpret_cast<UInt32>(node);
                    return reinterpret_cast<VendorTextureBuffer *>(node);
                }
                U32At(node, 0x54) = 1;
                if (retained != nullptr) {
                    memDesc = retained;
                    reused = true;
                }
                break;
            }
            prevNode = node;
            cur = reinterpret_cast<UInt8 *>(U32At(node, 0x3c));
        }

        if (!reused) {
            memDesc = FUN_withAddress(pageBase, roundedSize, 0x10002, reinterpret_cast<void *>(U32At(self, 8)));
            if (memDesc == nullptr) {
                return nullptr;
            }
        }
    }

    UInt8 *tex = reinterpret_cast<UInt8 *>((*reinterpret_cast<AllocVendorBufFn *>(accelVtable + (0x570 / 4)))(accel, 0x80));
    if (tex == nullptr) {
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
        return nullptr;
    }
    U32At(tex, 8) = reinterpret_cast<UInt32>(memDesc);

    UInt32 handle;
    if (!alloc_buf_handle(tex, &handle)) {
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
        (*reinterpret_cast<ReleaseVendorBufFn *>(accelVtable + (0x574 / 4)))(accel, tex, 0x80);
        return nullptr;
    }
    sIOClientShared *clientShared;
    UInt32 userAddr;
    if (!alloc_client_shared(handle, &clientShared, &userAddr)) {
        free_buf_handle(tex, handle);
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
        (*reinterpret_cast<ReleaseVendorBufFn *>(accelVtable + (0x574 / 4)))(accel, tex, 0x80);
        return nullptr;
    }

    UInt8 *cs = reinterpret_cast<UInt8 *>(clientShared);
    U32At(tex, 0x14) = reinterpret_cast<UInt32>(cs);
    U32At(tex, 0x18) = userAddr;
    U32At(cs, 0) = handle;
    U32At(cs, 8) = U32At(accel, 0x54);
    U32At(cs, 0xc) = U32At(accel, 0x54);
    U8At(cs, 0x16) = 4;
    U8At(tex, 0x20) = 4;
    U32At(tex, 0x50) = pageOffset;
    U32At(tex, 0x58) = pageBase;
    U32At(tex, 0x1c) = reinterpret_cast<UInt32>(self);

    typedef UInt32 (*Fn0x128)(void *);
    UInt32 extra = (*reinterpret_cast<Fn0x128 *>(*reinterpret_cast<void ***>(memDesc) + (0x128 / 4)))(memDesc);
    U32At(tex, 0x5c) = extra;
    U32At(tex, 0x54) = 0;

    U32At(tex, 0x3c) = U32At(self, 0x24);
    U32At(self, 0x24) = reinterpret_cast<UInt32>(tex);
    *outParam = userAddr;
    U32At(accel, 0x72c) += 1;

    UInt8 *globalShared = reinterpret_cast<UInt8 *>(U32At(accel, 0x6c));
    if (self == globalShared) {
        UInt32 seq = U32At(accel, 0x70);
        U32At(cs, 4) = seq;
        U32At(accel, 0x70) = seq + 1;
    }
    return reinterpret_cast<VendorTextureBuffer *>(tex);
}

/* ------------------------------------------------------------------ */
/* new_texture - real addr 0x18060.                                    */
/* ------------------------------------------------------------------ */

VendorTextureBuffer *IOATIR500Shared::new_texture(UInt32 param1, UInt32 param2, UInt32 param3, UInt32 param4, UInt32 *out1, UInt32 *out2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
    void **accelVtable = *reinterpret_cast<void ***>(accel);

    UInt8 *companion = nullptr;
    UInt8 kind;
    UInt32 baseSize;
    if (param3 == 0 || param4 == 0) {
        if (param2 == 0) { kind = 2; baseSize = 0x80; }
        else { kind = 3; baseSize = 0xa00; }
    } else {
        UInt32 companionOut;
        companion = reinterpret_cast<UInt8 *>(new_agp_texture(param3, param4, &companionOut));
        if (companion == nullptr) {
            return nullptr;
        }
        kind = 7; baseSize = 0xa00;
    }

    UInt32 roundedSize = (baseSize + param1 + static_cast<UInt32>(kernelPageSize) + 7) &
                          static_cast<UInt32>(-kernelPageSize);
    UInt8 *tex = nullptr;
    void *memDesc = nullptr;

    if (roundedSize <= (U32At(accel, 0x20c) * 0xc00) >> 2) {
        tex = reinterpret_cast<UInt8 *>((*reinterpret_cast<AllocVendorBufFn *>(accelVtable + (0x570 / 4)))(accel, 0x80));
        if (tex == nullptr) {
            if (companion != nullptr && U32At(reinterpret_cast<void *>(U32At(companion, 0x14)), 0x10) == 0) {
                delete_texture(reinterpret_cast<VendorTextureBuffer *>(companion));
            }
            return nullptr;
        }
        memDesc = FUN_inTaskWithOptions(reinterpret_cast<void *>(U32At(self, 8)),
                                         U32At(accel, 0x82c) | 0x10022, roundedSize, kernelPageSize);
        if (memDesc != nullptr) {
            U32At(tex, 8) = reinterpret_cast<UInt32>(memDesc);
            UInt32 handle;
            if (alloc_buf_handle(tex, &handle)) {
                sIOClientShared *clientShared;
                UInt32 userAddr;
                if (alloc_client_shared(handle, &clientShared, &userAddr)) {
                    UInt8 *cs = reinterpret_cast<UInt8 *>(clientShared);
                    U32At(tex, 0x14) = reinterpret_cast<UInt32>(cs);
                    U32At(tex, 0x18) = userAddr;
                    U32At(cs, 0) = handle;
                    U32At(cs, 8) = U32At(accel, 0x54);
                    U32At(cs, 0xc) = U32At(accel, 0x54);
                    U8At(cs, 0x16) = kind;
                    U8At(tex, 0x20) = kind;
                    U32At(tex, 0x1c) = reinterpret_cast<UInt32>(self);

                    void *userMap = (*reinterpret_cast<MapFn *>(*reinterpret_cast<void ***>(memDesc) + (0x14c / 4)))(
                        memDesc, reinterpret_cast<void *>(U32At(self, 8)), 0, U32At(accel, 0x82c) | 1, 0, 0);
                    if (userMap != nullptr) {
                        U32At(tex, 0x10) = reinterpret_cast<UInt32>(userMap);
                        if (kind == 3) {
                            U32At(tex, 0x50) = param2;
                        } else if (kind != 2) {
                            U32At(tex, 0x50) = param2;
                            U32At(tex, 0x58) = reinterpret_cast<UInt32>(companion);
                            OSIncrementAtomic_TexAlloc(reinterpret_cast<UInt8 *>(U32At(companion, 0x14)) + 0x10);
                        }
                        U32At(tex, 0x3c) = U32At(self, 0x24);
                        U32At(self, 0x24) = reinterpret_cast<UInt32>(tex);

                        UInt32 va = (*reinterpret_cast<GetVAFn *>(*reinterpret_cast<void ***>(userMap) + (0xd0 / 4)))(userMap);
                        *out1 = va;
                        *out2 = userAddr;
                        U32At(accel, 0x72c) += 1;

                        UInt8 *globalShared = reinterpret_cast<UInt8 *>(U32At(accel, 0x6c));
                        if (self == globalShared) {
                            UInt32 seq = U32At(accel, 0x70);
                            U32At(cs, 4) = seq;
                            U32At(accel, 0x70) = seq + 1;
                        }
                        return reinterpret_cast<VendorTextureBuffer *>(tex);
                    }

                    /* real: literal transcription - the failed-map path does
                     * NOT release `tex` itself via releaseVendorTextureBuffer
                     * before returning, unlike every other failure path in
                     * this function. Matches the real binary exactly (see
                     * this file's own header comment). */
                    free_buf_handle(tex, U32At(cs, 0));
                    (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
                    U32At(tex, 8) = 0;
                    goto companionCleanupOnly;
                }
                free_buf_handle(tex, handle);
            }
            (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
            U32At(tex, 8) = 0;
        }
        if (companion != nullptr && U32At(reinterpret_cast<void *>(U32At(companion, 0x14)), 0x10) == 0) {
            delete_texture(reinterpret_cast<VendorTextureBuffer *>(companion));
        }
        (*reinterpret_cast<ReleaseVendorBufFn *>(accelVtable + (0x574 / 4)))(accel, tex, 0x80);
        return nullptr;
    }

companionCleanupOnly:
    if (companion != nullptr && U32At(reinterpret_cast<void *>(U32At(companion, 0x14)), 0x10) == 0) {
        delete_texture(reinterpret_cast<VendorTextureBuffer *>(companion));
        return nullptr;
    }
    return nullptr;
}

/* ------------------------------------------------------------------ */
/* new_agpref_texture - real addr 0x17df0.                             */
/* ------------------------------------------------------------------ */

VendorTextureBuffer *IOATIR500Shared::new_agpref_texture(UInt32 param1, UInt32 param2, UInt32 param3, UInt32 *outParam) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
    void **accelVtable = *reinterpret_cast<void ***>(accel);

    UInt32 companionOut;
    UInt8 *companion = reinterpret_cast<UInt8 *>(new_agp_texture(param2, param3, &companionOut));
    if (companion == nullptr) {
        return nullptr;
    }

    UInt8 *tex = reinterpret_cast<UInt8 *>((*reinterpret_cast<AllocVendorBufFn *>(accelVtable + (0x570 / 4)))(accel, 0x80));
    if (tex == nullptr) {
        if (U32At(reinterpret_cast<void *>(U32At(companion, 0x14)), 0x10) == 0) {
            delete_texture(reinterpret_cast<VendorTextureBuffer *>(companion));
        }
        return nullptr;
    }

    UInt32 handle;
    if (alloc_buf_handle(tex, &handle)) {
        sIOClientShared *clientShared;
        UInt32 userAddr;
        if (alloc_client_shared(handle, &clientShared, &userAddr)) {
            UInt8 *cs = reinterpret_cast<UInt8 *>(clientShared);
            U32At(tex, 0x14) = reinterpret_cast<UInt32>(cs);
            U32At(tex, 0x18) = userAddr;
            U32At(cs, 0) = handle;
            U32At(cs, 8) = U32At(accel, 0x54);
            U32At(cs, 0xc) = U32At(accel, 0x54);
            U8At(cs, 0x16) = 6;
            U8At(tex, 0x20) = 6;
            U32At(tex, 0x1c) = reinterpret_cast<UInt32>(self);

            UInt32 offset = 0;
            if (param1 != 0) {
                offset = param1 - U32At(companion, 0x58);
            }
            U32At(tex, 0x50) = offset;
            U32At(tex, 0x54) = reinterpret_cast<UInt32>(companion);
            OSIncrementAtomic_TexAlloc(reinterpret_cast<UInt8 *>(U32At(companion, 0x14)) + 0x10);

            U32At(tex, 0x3c) = U32At(self, 0x24);
            U32At(self, 0x24) = reinterpret_cast<UInt32>(tex);
            *outParam = userAddr;
            U32At(accel, 0x72c) += 1;

            UInt8 *globalShared = reinterpret_cast<UInt8 *>(U32At(accel, 0x6c));
            if (self != globalShared) {
                return reinterpret_cast<VendorTextureBuffer *>(tex);
            }
            UInt32 seq = U32At(accel, 0x70);
            U32At(cs, 4) = seq;
            U32At(accel, 0x70) = seq + 1;
            return reinterpret_cast<VendorTextureBuffer *>(tex);
        }
        free_buf_handle(tex, handle);
    }

    if (U32At(reinterpret_cast<void *>(U32At(companion, 0x14)), 0x10) == 0) {
        delete_texture(reinterpret_cast<VendorTextureBuffer *>(companion));
    }
    (*reinterpret_cast<ReleaseVendorBufFn *>(accelVtable + (0x574 / 4)))(accel, tex, 0x80);
    return nullptr;
}
