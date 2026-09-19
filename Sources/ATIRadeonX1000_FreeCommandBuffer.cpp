/*
 * ATIRadeonX1000_FreeCommandBuffer.cpp
 *
 * RESOLVED (issue #34): two DISTINCT real functions this project had
 * been tracking as a single "freeCommandBuffer" gap - decompiling
 * confirmed they are genuinely different methods on different classes,
 * not one function seen from two call sites:
 *
 *   - `IOATIR500Accelerator::freeCommandBuffer(VendorCommandBuffer*)`
 *     (real addr 0x1f10) - the real counterpart to `allocCommandBuffer`/
 *     `allocMoreCommandBuffers` (`Headers/IOATIR500Accelerator.h`),
 *     already declared there.
 *   - `IOATIR500GLContext::freeCommandBuffer()` (real addr 0x7e70, NO
 *     arguments) - a real, previously entirely untracked method, newly
 *     declared below.
 *
 * `IOATIR500Accelerator::freeCommandBuffer` real body: if the buffer's
 * own `+4` field is set, calls the already-RESOLVED `waitForTimeStamp`
 * (`+0x54c`) on its own `+0x10` field, then the already-RESOLVED
 * `removeTransferFromGART` (`+0x5ac`) on the buffer itself (same real
 * `VendorTransferBuffer`/`VendorCommandBuffer` shape-overlap convention
 * this project already relies on elsewhere). Always releases a nested
 * object at the buffer's own `+8` field (vtable `+0x18` -
 * `OSObject::release()`), then resets the buffer's own real fields to
 * their "empty" state (`+0xc`=`1`, `+0xe`=`0`, `+0x18`=`0`, `+0`=`0`,
 * `+4`=`0`, `+8`=`0`, `+0x10`=`0`, `+0x14`=`0` - the same real 0x1c-byte
 * `VendorCommandBuffer` shape `allocMoreCommandBuffers`'s own comment
 * already documents).
 *
 * `IOATIR500GLContext::freeCommandBuffer` real body (a genuinely
 * different, more involved function - NOT a thin wrapper around the
 * accelerator's version): if `this+0xd4` (a real per-context handle -
 * now CONFIRMED, issue #50, to be an `IOMemoryDescriptor*`, given what
 * it's passed to below - real broader role still UNKNOWN beyond this
 * use) is set, walks TWO real singly-linked lists rooted on the
 * accelerator (`accel+0x60` - this project's already-CONFIRMED
 * `liveGLContextListHead`, walked via the already-established
 * `nextLiveContext` field, `+0x80` - `Headers/IOATIR500GLContext.h`; and
 * `accel+0x68`, a real, DIFFERENT, not-previously-documented list head
 * walked the identical way - real role UNKNOWN, a plausible sibling
 * "live DVD/2D context" list given the parallel structure, not
 * confirmed). For each live context node, calls the REAL, previously-
 * unnamed `IOUserClient::removeMappingForDescriptor(IOMemoryDescriptor*)`
 * (`FUN_00007f8c` - RESOLVED, issue #50, live kxld-resolved `/dev/kmem`
 * read on real G5/Tiger hardware, cross-referenced against the running
 * kernel's own symbol table; called non-virtually here even though the
 * real Apple method is declared virtual - each live context node is the
 * real implicit `this` receiver, `this+0xd4` the real `mem` argument)
 * and, if it returns a real non-null `IOMemoryMap*`, releases it (vtable
 * `+0x18`). While walking the FIRST list,
 * also tracks a real accelerator-owned "high water mark" (`accel+0x5c8`,
 * raised to each node's own `+0xb0` field if larger); while walking the
 * SECOND list, the same `accel+0x5c8` field is instead raised to a fixed
 * literal `0x80000` (transcribed exactly as decompiled - not assumed to
 * mirror the first list's per-node value).
 *
 * Confidence: CONFIRMED for control flow and every real offset in the
 * `IOATIR500Accelerator` variant (a simple, already-well-understood
 * field shape). CONFIRMED for control flow/offsets in the
 * `IOATIR500GLContext` variant too; `FUN_00007f8c` is now RESOLVED
 * (issue #50) but `accel+0x68`'s list still has no established broader
 * role beyond what's directly inferable from this one call site -
 * flagged UNKNOWN above rather than guessed. No C++ compiler was
 * available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project).
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }

inline void ReleaseObj(void *obj) {
    typedef void (*ReleaseFn)(void *);
    void **vtable = *reinterpret_cast<void ***>(obj);
    reinterpret_cast<ReleaseFn>(vtable[0x18 / 4])(obj);
}
} // namespace

/* (re-ported mechanically: see IOATIR500Accelerator_freeCommandBuffer_Port.cpp) */


/* RESOLVED, issue #50 (live kxld-resolved /dev/kmem read on real
   G5/Tiger hardware): real target IOUserClient::removeMappingForDescriptor
   (IOMemoryDescriptor*), called non-virtually with liveContextNode as the
   implicit `this` and `handle` (really an IOMemoryDescriptor*) as `mem`. */
extern "C" void *FUN_00007f8c(void *liveContextNode, UInt32 handle) asm("__ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDescriptor");

/* (re-ported mechanically: see IOATIR500GLContext_freeCommandBuffer_Port.cpp) */

