/*
 * IOATIR500Accelerator_FreeToAllocGART.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): the real global GART-
 * reclamation sweep, a family of eight interdependent real methods:
 *
 *   `IOATIR500Accelerator::freeTransferToAllocGART` (real addr 0x3580) -
 *   the real per-candidate leaf: bails if the candidate has no real
 *   backing descriptor or is still stream-referenced, otherwise (in a
 *   real two-mode gentle/aggressive split) either confirms via the
 *   already-established `+0x554` slot that the candidate is truly free,
 *   or (aggressive) just accumulates a real freed-byte stat, then
 *   unconditionally unmaps the candidate and maps `needed` in its place.
 *
 *   `IOATIR500Accelerator::freeWaitToAllocGART` (real addr 0x37f0) - the
 *   real sweep body: frees an orphan texture and retries `needed`
 *   directly if the accelerator's own orphan list (`+0x664`/`+0x63c`,
 *   real self-pointer-as-empty-sentinel shape) is non-empty, then walks
 *   every live 2D/DVD/GL context's own linked list (`+100`/`+0x68`/
 *   `+0x60`, next via each context's own `+0x80`) trying that context's
 *   IOATIR500Shared allocator's own `freeToAllocGART` then the context's
 *   own `freeToAllocGART`, then every live Surface's own circular list
 *   (`+0x5c`, next via `+0xa0`), then the caller's own excluded shared
 *   allocator, then the accelerator's own two cached power-of-two
 *   ring pools (real capacity/cursor pairs at `+0x5c4`/`+0x5c6` and
 *   `+0x400`/`+0x402`, each entry 0x1c bytes) - walked FORWARD from the
 *   cursor in gentle mode, BACKWARD in aggressive mode (a real, faithful
 *   asymmetry, not a transcription artifact) - then a final linked list
 *   at `+0x5cc`, then finally the caller's own excluded 2D/DVD/GL/
 *   Surface contexts themselves.
 *
 *   `IOATIR500Accelerator::freeToAllocGART` (real addr 0x10c50) - the
 *   real public two-pass entry point: tries `freeWaitToAllocGART` gently
 *   first, then aggressively only if the gentle pass failed.
 *
 *   `IOATIR500Shared::freeToAllocGART` (real addr 0x17060) - walks this
 *   allocator's own texture list (`this+0x24`, the same list
 *   `delete_texture` already establishes in
 *   `IOATIR500Shared_TextureAlloc.cpp`), trying kind-4/3/7 entries via
 *   `freeTransferToAllocGART` (kind 4 additionally marks a real
 *   "pending release" flag at `clientShared+0x14` first).
 *
 *   `IOATIR500Surface::freeToAllocGART` (real addr 0x10c60),
 *   `IOATIR5002DContext::freeToAllocGART` (real addr 0x3c84),
 *   `IOATIR500DVDContext::freeToAllocGART` (real addr 0x3c74/0xe8a0),
 *   `IOATIR500GLContext::freeToAllocGART` (real addr 0x3c64/0x7a50) -
 *   each walks its own small, class-specific set of candidate transfer-
 *   buffer slots (fixed slots plus a small fixed array for 2D/DVD, a
 *   16-element ring array plus a linked list for GL, a nested per-
 *   surface-index array for Surface) via `freeTransferToAllocGART`,
 *   stopping at the first candidate that succeeds - real field roles
 *   beyond "candidate transfer buffer slot" not independently
 *   investigated for any of these four (own struct comments not
 *   otherwise established elsewhere in this project).
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant in all eight - every one a real, complete, standalone
 * decompile, cross-checked field-by-field against this project's own
 * already-established vtable slots (`+0x554`/`+0x54c`/`+0x5a8`/`+0x5ac`)
 * and struct shapes (`VendorTextureBuffer`/`VendorTransferBuffer`'s
 * shared `+4`/`+0xe`/`+0x14`/`+0x3c`/`+0x5c` fields).
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*Fn0x554)(void *, UInt32);
} // namespace

/* (re-ported mechanically: see IOATIR500Accelerator_freeTransferToAllocGART_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Accelerator_freeWaitToAllocGART_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Accelerator_freeWaitToAllocGART_Port.cpp) */


bool IOATIR500Accelerator::freeToAllocGART(IOATIR5002DContext *exclude2D, IOATIR500DVDContext *excludeDVD,
                                             IOATIR500GLContext *excludeGL, IOATIR500Surface *excludeSurface,
                                             IOATIR500Shared *excludeShared, VendorTransferBuffer *needed) {
    if (freeWaitToAllocGART(exclude2D, excludeDVD, excludeGL, excludeSurface, excludeShared, needed, false)) {
        return true;
    }
    return freeWaitToAllocGART(exclude2D, excludeDVD, excludeGL, excludeSurface, excludeShared, needed, true);
}


/* (re-ported mechanically: see IOATIR500Shared_freeToAllocGART_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_freeToAllocGART_Port.cpp) */


/* (re-ported mechanically: see IOATIR5002DContext_freeToAllocGART_Port.cpp) */


/* (re-ported mechanically: see IOATIR500DVDContext_freeToAllocGART_Port.cpp) */


/* (re-ported mechanically: see IOATIR500GLContext_freeToAllocGART_Port.cpp) */

