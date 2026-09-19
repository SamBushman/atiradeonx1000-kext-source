/*
 * ATIRadeonX1000_TexturePageoff.cpp
 *
 * RESOLVED (issue #30): the four real functions `ATIRadeonX1000::
 * pageoff_dirty_texture` (already resolved, `IOATIR500GLContext_
 * PageOffTexture.cpp`) branches into - `pageoff_linear_buffer` (real
 * addr 0x217a0), `pageoff_dirty_texture_with_gpu` (0x210f0),
 * `prepare_texture_for_pageoff_with_cpu` (0x20d30), and
 * `pageoff_dirty_texture_with_cpu` (0x1e500) - grouped in one file given
 * how tightly this real subsystem's four members share structure.
 *
 * Two real, disassembly-CONFIRMED shared building blocks factor out
 * cleanly (see the static helpers below):
 *
 * - `EnsureGARTMapped`/`ResolveKindAndEnsureMapped`: `pageoff_linear_
 *   buffer` and `pageoff_dirty_texture_with_gpu` open with an IDENTICAL
 *   real prologue - the texture's own `+0x20` "kind" byte is `3` (plain)
 *   or `7` (has a real companion `VendorTransferBuffer` at `+0x58`,
 *   itself refcounted at `+0xe` around this call), and either way calls
 *   the real vtable `+0x5a8` slot (`addTransferToGART`, already RESOLVED
 *   elsewhere) followed by a real check of `freeToAllocGART`'s own
 *   return, retrying once (with a `waitForTimeStamp`) on failure. The
 *   raw decompile shows `addTransferToGART`'s OWN "return value" being
 *   checked here too - this project has ALREADY established, from a
 *   full decompile of `addTransferToGART` and everything it calls
 *   (`Headers/IOATIR500Accelerator.h`'s own `addToGART` note), that this
 *   is a real calling-convention artifact with no meaningful signal (the
 *   function and everything beneath it are genuinely `void`) - the
 *   "conservative unconditional fix" already applied to `map_transfer_
 *   to_GART` is reapplied here: `addTransferToGART` is called
 *   unconditionally, and only `freeToAllocGART`'s own real `bool` return
 *   gates the retry.
 * - `ResolveTileShiftFactors`: `pageoff_dirty_texture_with_gpu` and
 *   `prepare_texture_for_pageoff_with_cpu` (and, in a slightly
 *   restructured but numerically identical form, `pageoff_dirty_
 *   texture_with_cpu`) all derive the same real pair of log2-scaled
 *   "tile shift" factors from the texture's own mip array's `+0x15`
 *   byte and a real per-`ATITextureBufferHeader` format-selector byte
 *   (`+0x1a`) via an identical real branch structure - real HARDWARE
 *   MEANING (almost certainly a compressed/tiled-texture block-size
 *   selection) not independently confirmed against R5xx register
 *   documentation, transcribed for its exact real bit-level behavior
 *   only.
 *
 * `ATITextureBufferHeader` remains an intentionally OPAQUE type in this
 * project (`Headers/ATIRadeonX1000.h`) - these four functions are, by a
 * wide margin, the densest real consumers of its own internal layout
 * this project has decompiled, but formalizing a full struct for it was
 * judged not worth the real risk of a transcription error given how
 * many of its fields' real roles remain genuinely unclear beyond their
 * bit position (tile/mip geometry tables, format selectors, PM4 scratch
 * buffer regions) - every access below is a raw, disassembly-consistent
 * byte offset instead, same as every other opaque type in this project.
 *
 * Confidence: CONFIRMED for control flow and every real offset in
 * `pageoff_linear_buffer` (independently cross-checked against raw PPC
 * disassembly in full, given it's the simplest of the four and a good
 * proxy for validating the shared prologue helpers above).
 * `pageoff_dirty_texture_with_gpu`/`prepare_texture_for_pageoff_with_cpu`/
 * `pageoff_dirty_texture_with_cpu` are CONFIRMED for control flow and
 * every real offset AS GIVEN BY Ghidra's own C decompile (trustworthy
 * per the same opaque-type byte-scaling precedent independently
 * verified for their simpler sibling above) but were NOT independently
 * re-traced against raw disassembly instruction-by-instruction given
 * their sheer size - real per-field HARDWARE semantics beyond "this bit
 * pattern feeds this PM4 register field" are UNKNOWN rather than
 * guessed. `pageoff_dirty_texture_with_cpu` additionally does real raw
 * MMIO register access with explicit PowerPC cache/memory-barrier
 * intrinsics (`dataCacheBlockStore`/`dataCacheBlockFlush`/`sync`/
 * `instructionSynchronize`/`enforceInOrderExecutionIO`) - real, standard
 * Apple/PPC kernel primitives, not previously used anywhere else in this
 * project. No C++ compiler was available in the sandboxed environment
 * this was written in (same standing limitation as every other file in
 * this project).
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h" /* dcbf/dcbst/eieio/isync, see that header */

extern "C" UInt32 global_dummy_read_back_a_register; /* real: a genuine global this function reads INTO after a register write - a real "force the write to actually land before continuing" pattern, distinct from the explicit barrier intrinsics also present */

extern "C" void FUN_000210d8(void *dest, void *src, UInt32 size) asm("_memmove"); /* RESOLVED, issue #50 (live kxld-resolved /dev/kmem read) */
extern "C" void FUN_0001eb18(void *dest, SInt32 byteOffset, UInt32 byteCount) asm("_memmove"); /* RESOLVED, issue #50 - same real target as FUN_000210d8; the real second argument (`byteOffset`, an SInt32 here rather than a pointer type) is passed through unchanged - this project's own prior "running byte offset" reading of this parameter is presumably really a raw VRAM-mapped address the caller already computed, not a plain relative offset, though that caller-side semantic question is unchanged by this linkage fix. */
extern "C" int kernelTaskRef asm("_kernel_task"); /* kernel_task pointer value; the Ghidra label "_ASICSupportsAGP" hid this real relocation target (issue #58 follow-up) */

namespace {
inline UInt8  &B(void *p, int o)  { return *(reinterpret_cast<UInt8 *>(p) + o); }
inline SInt16 &SH(void *p, int o) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt16 &H(void *p, int o)  { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline SInt32 &SW(void *p, int o) { return *reinterpret_cast<SInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt32 &W(void *p, int o)  { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }

bool EnsureGARTMapped(ATIRadeonX1000 *accel, VendorTransferBuffer *buf) {
    accel->addTransferToGART(buf);
    if (accel->freeToAllocGART(nullptr, nullptr, nullptr, nullptr, nullptr, buf)) {
        return true;
    }
    accel->waitForTimeStamp(W(accel, 0x50) - 1);
    accel->addTransferToGART(buf);
    return accel->freeToAllocGART(nullptr, nullptr, nullptr, nullptr, nullptr, buf);
}

bool ResolveKindAndEnsureMapped(ATIRadeonX1000 *accel, VendorTextureBuffer *texture, UInt8 *outKind) {
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 kind = B(tex, 0x20);

    if (kind == 3) {
        if (W(tex, 4) == 0) {
            if (!EnsureGARTMapped(accel, reinterpret_cast<VendorTransferBuffer *>(texture))) {
                return false;
            }
            kind = B(tex, 0x20);
        }
    } else if (kind == 7) {
        VendorTransferBuffer *aux = *reinterpret_cast<VendorTransferBuffer **>(tex + 0x58);
        UInt8 *auxBytes = reinterpret_cast<UInt8 *>(aux);
        if (W(auxBytes, 4) == 0) {
            if (!EnsureGARTMapped(accel, aux)) {
                return false;
            }
        }
        UInt32 hasBacking = W(tex, 4);
        SInt16 refcount = SH(auxBytes, 0xe) + 1;
        SH(auxBytes, 0xe) = refcount;
        if (hasBacking == 0) {
            if (!EnsureGARTMapped(accel, reinterpret_cast<VendorTransferBuffer *>(texture))) {
                SH(auxBytes, 0xe) -= 1;
                return false;
            }
            refcount = SH(auxBytes, 0xe);
        }
        kind = B(tex, 0x20);
        SH(auxBytes, 0xe) = refcount - 1;
    } else {
        return false;
    }

    *outKind = kind;
    return true;
}

/* real: derives the same two log2-scaled "tile shift" factors
   (`shiftA`/`shiftB`) and format-selector byte (`fmtSel`) that
   `pageoff_dirty_texture_with_gpu`/`prepare_texture_for_pageoff_with_cpu`
   each independently (but identically) compute - see this file's own
   header comment. */
void ResolveTileShiftFactors(UInt8 *mip, UInt8 *hw, int &shiftA, int &shiftB, UInt32 &fmtSel) {
    UInt8 shiftedFmt = B(mip, 0x15) >> 3;
    shiftA = -(shiftedFmt & 3);
    fmtSel = B(hw, 0x1a);
    bool zeroSel;
    if (shiftedFmt & 2) {
        zeroSel = true;
    } else if (shiftA < 0) {
        zeroSel = (fmtSel == 0);
    } else {
        zeroSel = false;
    }
    if (fmtSel < 4) {
        if (zeroSel) { shiftB = 2; shiftA = 3; }
        else         { shiftB = 1; shiftA = 4; }
    } else {
        shiftB = 0;
        shiftA = 5;
    }
}
} // namespace

/* (re-ported mechanically: see ATIRadeonX1000_pageoff_linear_buffer_Port.cpp) */


/* (re-ported mechanically: see ATIRadeonX1000_pageoff_dirty_texture_with_gpu_Port.cpp) */


/* (re-ported mechanically: see ATIRadeonX1000_prepare_texture_for_pageoff_with_cpu_Port.cpp) */


/* (re-ported mechanically: see ATIRadeonX1000_pageoff_dirty_texture_with_cpu_Port.cpp) */

