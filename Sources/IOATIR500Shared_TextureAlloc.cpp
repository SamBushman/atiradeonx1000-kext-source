/* NOTE 2026-09-19: 9 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
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

/* (re-ported mechanically: see IOATIR500Shared_alloc_buf_handle_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Shared_free_buf_handle_Port.cpp) */


/* ------------------------------------------------------------------ */
/* alloc_client_shared - real addr 0x16d50.                            */
/* ------------------------------------------------------------------ */

/* (re-ported mechanically: see IOATIR500Shared_alloc_client_shared_Port.cpp) */


/* ------------------------------------------------------------------ */
/* delete_texture - real addr 0x17950.                                 */
/* ------------------------------------------------------------------ */

/* (re-ported mechanically: see IOATIR500Shared_delete_texture_Port.cpp) */


/* ------------------------------------------------------------------ */
/* new_surface_texture - real addr 0x17520.                            */
/* ------------------------------------------------------------------ */

/* (re-ported mechanically: see IOATIR500Shared_new_surface_texture_Port.cpp) */


/* ------------------------------------------------------------------ */
/* new_global_texture - real addr 0x17740.                             */
/* ------------------------------------------------------------------ */

/* (re-ported mechanically: see IOATIR500Shared_new_global_texture_Port.cpp) */


/* ------------------------------------------------------------------ */
/* new_agp_texture - real addr 0x17150.                                */
/* ------------------------------------------------------------------ */

/* (re-ported mechanically: see IOATIR500Shared_new_agp_texture_Port.cpp) */


/* ------------------------------------------------------------------ */
/* new_texture - real addr 0x18060.                                    */
/* ------------------------------------------------------------------ */

/* (re-ported mechanically: see IOATIR500Shared_new_texture_Port.cpp) */


/* ------------------------------------------------------------------ */
/* new_agpref_texture - real addr 0x17df0.                             */
/* ------------------------------------------------------------------ */

/* (re-ported mechanically: see IOATIR500Shared_new_agpref_texture_Port.cpp) */

