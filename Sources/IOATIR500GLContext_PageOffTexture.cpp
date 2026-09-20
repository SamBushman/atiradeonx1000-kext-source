/* NOTE 2026-09-19: 2 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500GLContext_PageOffTexture.cpp
 *
 * RESOLVED: `IOATIR500GLContext::page_off_texture`'s real body, real addr
 * 0x9740. This function had never actually been decompiled/transcribed
 * in this project before - `ATIRadeonX1000Types.h`'s own
 * `formatOrTilingBits` field comment cited it as evidence without a
 * committed transcription ever backing that citation, which is what let
 * a real naming/scope error stand uncaught until this pass (see
 * `hzBlockField`'s own declaration comment for the full account: the
 * "+0x28" this function actually reads belongs to a completely different
 * struct - the per-face mip sub-record already named `loadedBits`
 * elsewhere - not `ATIR500SurfaceBuffer`/`VendorTextureBuffer` at all).
 *
 * Real body: locks `accelerator->commandLock` (the same real
 * lock/unlock stub pair bracketing nearly every external method in this
 * project - RESOLVED via live memory read, real targets `mutex_lock`/
 * `mutex_unlock_rwcmb`), looks up the real texture by ID in the shared
 * allocator's table (the SAME bounds-checked pattern established
 * throughout this project), and - if found - reaches the real per-face
 * mip sub-record (`texture's own +0x14 pointer, offset by `face*2`,
 * where `face = mipAndFace >> 0x10`) and tests whether the requested mip
 * `level` (`mipAndFace & 0x3f`) is dirty-but-not-yet-loaded
 * (`loadedBits & ~dirtyBits`, the SAME real formula
 * `ATIR500GLContext_TextureLoad.cpp`'s `load_texture`/
 * `alloc_and_load_texture` already establish on this identical
 * `faceMip+0x1c`/`faceMip+0x28` field pair). If so, calls the
 * accelerator's own real `+0x52c` vtable method - RESOLVED via the
 * concrete-subclass-vtable technique (base placeholder, subclass real):
 * `ATIRadeonX1000::pageoff_dirty_texture(VendorTextureBuffer*, long,
 * long)`, real addr `0x21c60` - see `Headers/ATIRadeonX1000.h` for that
 * function's own declaration and an honestly-flagged real ambiguity
 * about its exact call arguments here. Returns
 * `kIOReturnBadArgument`-family (`0xe00002c2`) if the texture ID isn't
 * found in the table at all.
 *
 * Confidence: CONFIRMED for control flow and every real offset except
 * the exact arguments passed to `pageoff_dirty_texture` (see below). No
 * C++ compiler was available in the sandboxed environment this was
 * written in (same standing limitation as every other file in this
 * project).
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* FIXED (issue #1, first build attempt): these were all local
 * (function-scope) `extern "C" ...` declarations. gcc-4.0.1's C++03
 * grammar does not allow a linkage-specification as a block-declaration
 * at all (only specific declaration forms are permitted inside a
 * function body, and `extern "C"` isn't one of them) - a real syntax
 * error ("expected unqualified-id before string constant"), not a
 * portability nit. Hoisted to file scope, same real targets. */
extern "C" void GLContext_mutex_lock(void *) asm("_IOLockLock");
extern "C" void GLContext_mutex_unlock(void *) asm("_IOLockUnlock");
extern "C" int kernelTaskRef asm("_kernel_task"); /* kernel_task pointer value; the Ghidra label "_ASICSupportsAGP" hid this real relocation target (issue #58 follow-up) */

/* (re-ported mechanically: see IOATIR500GLContext_page_off_texture_Port.cpp) */


/*
 * ATIRadeonX1000::pageoff_dirty_texture - see this function's own
 * declaration comment in Headers/ATIRadeonX1000.h for the full account,
 * including the honestly-flagged real parameter-mapping ambiguity this
 * transcription is built on (Ghidra's own raw decompile types its first
 * parameter as `VendorTextureBuffer*`, but this project reads it as a
 * mistyped `this` based on the body's own onward `(ATIRadeonX1000*)`
 * casts - NOT independently disassembly-verified).
 *
 * Real body: bails out immediately if the texture's own
 * `transferBufferFlag` (`+0x48`) is zero. Otherwise prepares a real GART
 * mapping on the texture's `memoryDescriptor` (`+0x08`) via the same
 * `+0x14c` vtable chain established elsewhere in this project, then
 * reads a real hardware-info flag word (`+0x20` on the resulting
 * handle). Bit `0x20000000` set means "already paged off, nothing to
 * do." Otherwise: bit `0x40000000` selects `pageoff_linear_buffer`
 * (linear/non-tiled real path); clear, or the GPU-path helper reporting
 * failure, falls through to a real CPU-prepare-then-pageoff pair.
 * Finally, if the texture's own mip array's face-count byte (`+0x34`)
 * is nonzero and a real "not yet processed" flag (`+0x36`) is clear,
 * walks every face's own per-face `dirtyBits`/`loadedBits` pair
 * (`faceMip+0x1c`/`+0x28`, the SAME real fields `page_off_texture`
 * above and `ATIR500GLContext_TextureLoad.cpp` already establish) and
 * ORs `loadedBits` INTO `dirtyBits` (the opposite direction from
 * `load_texture`'s own tail, which ORs `dirtyBits` into `loadedBits`) -
 * a real "anything that was resident is now ALSO flagged dirty" step,
 * consistent with paging a texture off meaning its GPU-resident data is
 * no longer valid and must be reloaded before next use. Releases the
 * GART-mapping handle
 * (vtable `+0x18` - `OSObject::release()`, RESOLVED issue #20) as its
 * final action.
 *
 * The three/four further real functions this branches into
 * (`pageoff_linear_buffer`, `pageoff_dirty_texture_with_gpu`,
 * `prepare_texture_for_pageoff_with_cpu`, `pageoff_dirty_texture_with_cpu`)
 * are real, already-named (via their own real mangled symbols) but their
 * own bodies were NOT decompiled this pass - a genuinely new subsystem
 * this investigation surfaced while chasing an unrelated field-naming
 * question, out of scope for that question and not chased further here.
 *
 * Confidence: CONFIRMED for control flow and every real offset EXCEPT
 * the parameter-mapping question flagged above and in
 * Headers/ATIRadeonX1000.h. No C++ compiler was available in the
 * sandboxed environment this was written in (same standing limitation as
 * every other file in this project).
 */
/* (re-ported mechanically: see ATIRadeonX1000_pageoff_dirty_texture_Port.cpp) */

