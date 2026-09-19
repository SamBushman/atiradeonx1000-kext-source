/*
 * IOATIR500GLContext_TextureStream.cpp
 *
 * add_texture_to_stream / remove_texture_from_stream / map_transfer_to_GART -
 * CONFIRMED, fully transcribed from real decompiles (kext offsets
 * 0x72c0/0x71b0/0x79d0). Real, previously-unknown finding this pass:
 * `VendorTextureBuffer+0x20` is a real TYPE DISCRIMINANT byte with at
 * least six distinct real values (0, 1, 6, 7, 8, and 3 - seen across this
 * file and GetTextureOffset), each routing to different real handling -
 * this is the real "kind of texture reference" tag this project had only
 * partially inferred before (VendorTextureBuffer serves plain textures,
 * chained/aliased references (type 1, recursive), surface-backed
 * references (type 0), and at least two more real kinds this
 * reconstruction pass didn't fully name).
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) {
    return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset);
}
inline SInt16 &S16At(void *base, int offset) {
    return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset);
}
inline UInt8 &U8At(void *base, int offset) {
    return *(reinterpret_cast<UInt8 *>(base) + offset);
}
} // namespace

/*
 * remove_texture_from_stream - CONFIRMED, fully transcribed (real kext
 * offset 0x71b0). Real per-type-discriminant cleanup: type 6 (chained
 * sub-buffer) decrements a nested refcount and returns; type 0
 * (surface-backed) calls `update_ref_stamps`/`decrement_refcounts`
 * (RESOLVED, issue #18) with a generation tag and returns; type 1 (alias) walks to the next real
 * texture in the chain and loops; type 8 decrements a refcount and
 * stores the current generation tag.
 */
/* (re-ported mechanically: see IOATIR500GLContext_remove_texture_from_stream_Port.cpp) */


/*
 * add_texture_to_stream - CONFIRMED, fully transcribed (real kext offset
 * 0x72c0). The real bind-side counterpart to remove_texture_from_stream -
 * same discriminant values, opposite direction (increment refcounts, real
 * dirty-bit propagation for type 6/1, and for type 6 a real unlink-then-
 * reinsert-at-head into the accelerator's dirty-texture doubly-linked
 * list at +0x6d0/+0x69c - the same list get_data_buffer/purge_texture
 * already use).
 */
/* (re-ported mechanically: see IOATIR500GLContext_add_texture_to_stream_Port.cpp) */


/*
 * map_transfer_to_GART - real kext offset 0x79d0. CORRECTED, issue #23:
 * decompiling `ATIRadeonX1000::addTransferToGART`'s own real body turned
 * up two real problems with this function's earlier transcription, both
 * fixed here:
 *
 * 1. Real signature mismatch: `addTransferToGART` (both the
 *    `ATIRadeonX1000` override and the `IOATIR500Accelerator` base it
 *    calls) is CONFIRMED, from each real decompile, to take a real
 *    `VendorTransferBuffer*` parameter - the previous transcription
 *    called it with NO arguments at all. Since the real callee
 *    unconditionally dereferences that parameter (`param_1+8`/`param_1+4`
 *    at the base level), calling it without `buffer` would be a real
 *    crash risk - fixed by passing `buffer`.
 * 2. Real return-value uncertainty: BOTH `addTransferToGART` levels
 *    (`ATIRadeonX1000`'s own override and the `IOATIR500Accelerator`
 *    base it calls) decompile as genuinely `void` - neither ever sets a
 *    real return value in its own control flow. The earlier
 *    transcription's `if (result == 0) { ... }` gate around the
 *    `freeToAllocGART` call was capturing whatever the real compiled
 *    call site's indirect-call-with-unknown-prototype artifact happened
 *    to leave in the return register - NOT a confirmed real signal, per
 *    this project's own established caveat about this exact category of
 *    artifact elsewhere (e.g. `ATIR500GLContext_TextureLoad.cpp`'s
 *    `load_texture` note). SETTLED (issue #26): decompiling the further
 *    slot `addTransferToGART` itself calls (`IOATIR500Accelerator`'s own
 *    `+0x5a0`, real name `addToGART`, `Headers/IOATIR500Accelerator.h`)
 *    shows it is ALSO genuinely void at both class levels - strong (not
 *    airtight; the deepest call, on Apple's own standard
 *    `IOMemoryDescriptor`, is out of this project's scope) confirmation
 *    that no real signal exists anywhere in this chain. The
 *    unconditional call below is the correct final transcription, not a
 *    placeholder.
 */
/* (re-ported mechanically: see IOATIR500GLContext_map_transfer_to_GART_Port.cpp) */

