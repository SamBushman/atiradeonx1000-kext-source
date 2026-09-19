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

bool IOATIR500Shared::alloc_client_shared(UInt32 index, sIOClientShared **outKernelPtr, unsigned int *outUserAddr) {
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

/* (re-ported mechanically: see IOATIR500Shared_delete_texture_Port.cpp) */


/* ------------------------------------------------------------------ */
/* new_surface_texture - real addr 0x17520.                            */
/* ------------------------------------------------------------------ */

VendorTextureBuffer *IOATIR500Shared::new_surface_texture(UInt32 surfaceID, UInt32 param2, UInt32 param3, unsigned int *outParam) {
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
    unsigned int userAddr;
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

/* (re-ported mechanically: see IOATIR500Shared_new_global_texture_Port.cpp) */


/* ------------------------------------------------------------------ */
/* new_agp_texture - real addr 0x17150.                                */
/* ------------------------------------------------------------------ */

VendorTextureBuffer *IOATIR500Shared::new_agp_texture(unsigned int param1, UInt32 param2, unsigned int *outParam) {
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
    unsigned int userAddr;
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

/* (re-ported mechanically: see IOATIR500Shared_new_texture_Port.cpp) */


/* ------------------------------------------------------------------ */
/* new_agpref_texture - real addr 0x17df0.                             */
/* ------------------------------------------------------------------ */

VendorTextureBuffer *IOATIR500Shared::new_agpref_texture(unsigned int param1, unsigned int param2, UInt32 param3, unsigned int *outParam) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
    void **accelVtable = *reinterpret_cast<void ***>(accel);

    unsigned int companionOut;
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
        unsigned int userAddr;
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
