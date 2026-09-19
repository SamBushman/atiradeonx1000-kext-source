/*
 * IOATIR500GLContext_Stop.cpp
 *
 * RESOLVED (issue #49): `IOATIR500GLContext::stop(IOService*)`'s real
 * body (real addr 0x7fa0, the BASE class - a real gap this project
 * hadn't even declared before this pass) and
 * `ATIR500GLContext::stop(IOService*)`'s real body (real addr 0x28700,
 * the SUBCLASS override, previously flagged UNKNOWN in
 * `Headers/ATIR500GLContext.h`).
 *
 * `ATIR500GLContext::stop` is tiny: locks the accelerator's own mutex
 * (`*(void**)(provider+0x840)`, the SAME real field/lock pair
 * `ATIR500DVDContext::set_macrovision` already established via
 * `_mutex_lock`/`_mutex_unlock` - `provider` here really is this
 * context's accelerator, matching `ATIRadeonX1000`'s own IOService
 * ancestry), calls the BASE class's `stop` (a real indirect call through
 * a fixed Mach-O lazy-symbol pointer in the raw decompile - written here
 * as a direct call, matching this project's own established treatment
 * of the analogous `IOUserClient::start` tail-call in `start()`), then
 * unlocks. All the real teardown work lives in the base.
 *
 * `IOATIR500GLContext::stop`'s real body, in order:
 * 1. Clears the "started successfully" flag (`this+0x294`, set to `1` on
 *    `start()`'s success path).
 * 2. Unlinks this context from the accelerator's live-context singly-
 *    linked list (`nextLiveContext`/`liveGLContextListHead`, both
 *    CONFIRMED from `start()`'s own push) - head-of-list and mid-list
 *    removal are both handled. If this was the LAST live GL-or-DVD
 *    context (`liveGLContextListHead == 0 && liveDVDContextListHead ==
 *    0`), calls a real, still-undeclared accelerator vtable slot
 *    (`+0x538`, immediately past the already-resolved `setup3D` at
 *    `+0x530` with one still-unknown slot, `+0x534`, in between) - a
 *    plausible real "last context closes, tear down the shared 3D setup"
 *    counterpart to `setup3D` itself, INFERRED, not independently
 *    confirmed. Left as a raw vtable-offset call rather than a new
 *    declared virtual method, since the `+0x534` gap between it and
 *    `setup3D` is a genuinely separate, still-completely-uncharacterized
 *    slot this pass didn't investigate.
 * 3. Decrements a counter at `accelerator+0x738` directly. NOTE: this is
 *    NOT obviously the same counter `start()` increments
 *    (`start()` increments `+0x738` on the ACCELERATOR'S OWN provider,
 *    one further level of indirection - `*(UInt8**)(accelerator+200)` -
 *    not the accelerator itself). Transcribed literally rather than
 *    "corrected" to match start()'s object, since this project has no
 *    independent confirmation either counter is really the same one.
 * 4. Sets `accelerator->cachedBufferSizeThreshold = 0x20000`, calls this
 *    context's own `freeCommandBuffer()` (issue #34), then sets
 *    `accelerator->cachedBufferSizeThresholdB = 0x10000`.
 * 5. Walks the accelerator's shared `freeBufferListHead` chain looking
 *    for any pooled buffer whose own `gartMapping` (`+0x10`, already-
 *    established `VendorTextureBuffer` field) identifies (via a real
 *    vtable `+0xdc` accessor call) as belonging to `this+0x78` (role
 *    UNKNOWN, same field `start()` already left unresolved) - releases
 *    that mapping (vtable `+0x18`) and nulls it in place.
 * 6. Walks THIS CONTEXT's OWN pending-data-buffer list (`this+0xe8`,
 *    linked via the already-established `VendorTextureBuffer::
 *    streamListNext`, `+0x3c`), returning each buffer to the
 *    accelerator's shared free-list (head/tail/count all already-
 *    established `ATIRadeonX1000` fields) when there's room (< 16,
 *    matching `freeOneDataBuffer`'s own established cap), clearing its
 *    the real byte flag at `+0x54` (already anticipated in
 *    `VendorTextureBuffer`'s own header comment as a real "resident/in-
 *    flight" flag seen elsewhere - NOT the same field as the 4-byte
 *    `linkedBuffer` pointer that ALSO starts at `+0x54`; Ghidra's own
 *    decompile here treats it as a plain byte, matching that comment
 *    exactly) and releasing its own `gartMapping` if
 *    present - or calling `IOATIR500Accelerator::freeOneDataBuffer`
 *    directly when the free-list is already full. Then zeroes this
 *    context's own list head/tail/count (`+0xe8`/`+0xe8`.."+0xf0"
 *    triple, in the real decompile's own write order) and evicts any
 *    free-list overflow past 16 via `freeOneDataBuffer` in a trailing
 *    loop - the exact same overflow-eviction shape `reclaim_resources`
 *    already established elsewhere in this project.
 * 7. If this context ever got a primary context-buffer (`this+0xfc`,
 *    the SAME field `allocAllContextBuffers` sets - issue #33), calls
 *    the real, previously-undeclared sibling `freeAllContextBuffers()`
 *    (own body NOT decompiled this pass - filed as its own issue, same
 *    3-class-family shape as `init_context_buffer_header`/
 *    `allocAllContextBuffers`, issue #46). If this context has its own
 *    separate command buffer (`this+0xd4` flag set), releases it via
 *    `IOATIR500Accelerator::freeCommandBuffer(VendorCommandBuffer*)`.
 * 8. Releases a handle at `this+0xb8` if present (role UNKNOWN, vtable
 *    `+0x18` release), clears the accelerator's own "current GL context"
 *    field (`accelerator+0x78`) if it still points at `this`, and
 *    unregisters from the owning `ATIR500Surface` (`+0x290`) via
 *    `remove_gl_context_from_list`/`prune_buffers`.
 * 9. Releases every live entry of `textureSlotArray` (`+0x2a4`, the
 *    already-established 42-entry - NOT the subclass's own smaller
 *    20-entry array of the same name; this is the BASE class's own,
 *    numerically larger block `start()` already zero-initializes as an
 *    "UNKNOWN 0x2a-word block") via a real atomic
 *    decrement-and-check-for-zero helper (`FUN_00008340`, since resolved as
 *    `OSDecrementAtomic`; body not decompiled this pass - same real shape as this project's own
 *    already-named `DecrementRefAndWasLast`/`ReleaseBoundTextureSlot`,
 *    `Sources/ATIR500GLContext_DiscardBuffer.cpp`, but a genuinely
 *    separate compiled subroutine, not that same one), calling
 *    `IOATIR500Shared::delete_texture` when a slot's refcount just hit
 *    zero.
 * 10. Releases `clientHandle` (`+0x88`) if present and tail-calls
 *     `IOUserClient::stop`.
 *
 * Confidence: CONFIRMED for control flow and every real offset against
 * the raw Ghidra decompile for both functions (both short enough, and
 * the base's own size made a full independent raw-disassembly re-check
 * impractical this pass - treat individual literal offsets as CONFIRMED-
 * from-decompile). the accelerator's `+0x538`
 * vtable slot's own real body is UNKNOWN. No C++ compiler was
 * available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project).
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &W(void *p, int o) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline void ReleaseObj(void *obj) {
    typedef void (*ReleaseFn)(void *);
    void **vtable = *reinterpret_cast<void ***>(obj);
    reinterpret_cast<ReleaseFn>(vtable[0x18 / 4])(obj);
}
} // namespace

/* real, still-undecompiled atomic-decrement-and-check-for-zero helper -
   see file header comment for how this differs from this project's own
   ReleaseBoundTextureSlot/DecrementRefAndWasLast. */
/* FUN_00008340: RESOLVED (issue #58 follow-up) - live kxld target 0x30a840 = OSDecrementAtomic,
 * which returns the PREVIOUS value (so "was last" is old == 1, as the call site tests). */
extern "C" SInt32 FUN_00008340(void *countField) asm("_OSDecrementAtomic");

extern "C" void GLStop_mutex_lock(void *) asm("_IOLockLock");
extern "C" void GLStop_mutex_unlock(void *) asm("_IOLockUnlock");

void ATIR500GLContext::stop(IOService *provider) {
    void *mtx = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(provider) + 0x840);
    GLStop_mutex_lock(mtx);
    IOATIR500GLContext::stop(provider);
    GLStop_mutex_unlock(mtx);
}

/* (re-ported mechanically: see IOATIR500GLContext_stop_Port.cpp) */

