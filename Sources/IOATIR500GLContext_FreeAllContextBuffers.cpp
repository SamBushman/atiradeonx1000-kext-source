/*
 * IOATIR500GLContext_FreeAllContextBuffers.cpp
 *
 * RESOLVED (issue #54): `freeAllContextBuffers`'s real bodies for all
 * three context classes - `IOATIR500GLContext` (real addr 0x7000),
 * `IOATIR5002DContext` (real addr 0xb6c0), `IOATIR500DVDContext` (real
 * addr 0xe270). All three are structurally identical real methods (same
 * real per-class pattern already established for `allocAllContextBuffers`/
 * `init_context_buffer_header`), the real inverse of `allocAllContextBuffers`
 * (issue #33) - found as `stop`'s own real fallback call (issue #49) when
 * a context's primary context-buffer field is set.
 *
 * Real body (identical shape across all three): each of the 16 (GL) or 2
 * (2D/DVD) repeat-array entries `allocAllContextBuffers` allocated turns
 * out to be its own small `VendorCommandBuffer`-shaped record (CONFIRMED
 * by direct field-for-field comparison against the already-resolved
 * standalone `IOATIR500Accelerator::freeCommandBuffer(VendorCommandBuffer*)`,
 * issue #34 - both real bodies check the SAME relative `+4` "has a real
 * GART transfer" flag before calling `removeTransferFromGART`, and both
 * release the SAME relative `+8` field via vtable `+0x18`) - the real
 * struct base is 8 bytes BEFORE this project's own existing "array base"
 * reference point (which pointed at the `+8`/"buf" field, matching
 * `ATIRadeonX1000_AllocAllContextBuffers.cpp`'s own `ReleaseAndZeroEntries`
 * helper exactly: struct base = entry-8). One real, notable difference
 * from `freeCommandBuffer`'s own behavior: this function calls
 * `removeTransferFromGART` WITHOUT a preceding `waitForTimeStamp` on the
 * per-entry record (transcribed exactly as decompiled, not assumed to
 * mirror its sibling).
 *
 * Before that per-entry loop, reads the entry currently pointed at by a
 * real rotating ring-buffer-slot index (`this+0x28c` for GL, matching the
 * SAME field this project's own `ATIR500GLContext::compact_current_textures`/
 * `restore_state_destroyed_by_pageoff` already use identically - CONFIRMED
 * cross-reference, right down to the exact `ringBase+0x11c` field offset
 * matching this function's own `struct_base+0x10`), passes that entry's
 * own `+0x10` field (the same real relative offset `freeCommandBuffer`
 * passes to `waitForTimeStamp`) to the already-established
 * `ATIRadeonX1000::waitForTimeStamp`, and accumulates the real returned
 * delta into a per-class accelerator-owned counter (`accel+0x780` for GL -
 * the SAME field `restore_state_destroyed_by_pageoff`/
 * `compact_current_textures` already accumulate into; `+0x77c`/`+0x784`
 * for 2D/DVD respectively, real per-class siblings never independently
 * named before this pass).
 *
 * Finally releases the primary context buffer (vtable `+0x18`) and zeroes
 * every one of this class's own "primary buffer" fields - the exact same
 * real field group `allocAllContextBuffers`'s own failure-path rollback
 * already zeroes for each class.
 *
 * Real per-class differences (offsets only, identical shape otherwise):
 *   GL:  ring index `this+0x28c`; array struct-base `this+0x10c` (16
 *        entries, stride 0x18); accelerator accumulator `+0x780`; primary
 *        buffer group `this+0xf4/0xf8/0xfc/0x100/0x102/0x104/0x108`.
 *   2D:  ring index `this+0xfc`; array struct-base `this+0xcc` (2
 *        entries); accelerator accumulator `+0x77c`; primary buffer group
 *        `this+0xb4/0xb8/0xbc/0xc0/0xc2/0xc4/200(0xc8)`.
 *   DVD: ring index `this+0xf4`; array struct-base `this+0xc4` (2
 *        entries); accelerator accumulator `+0x784`; primary buffer group
 *        `this+0xac/0xb0/0xb4/0xb8/0xba/0xbc/0xc0`.
 *
 * Confidence: CONFIRMED for control flow and every real offset (all three
 * independently decompiled and cross-checked against each other, against
 * `allocAllContextBuffers`'s own already-committed field names, and
 * against `freeCommandBuffer`'s own already-committed per-record shape).
 * The per-entry "release" call target (`struct_base+8`) is dereferenced
 * unconditionally in the real decompile, with no null check - transcribed
 * as-is, matching the real semantics that this function is only ever
 * reached (via `stop`) after a fully successful `allocAllContextBuffers`,
 * where every entry is guaranteed populated. No C++ compiler was
 * available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project).
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }

inline void ReleaseObj(void *obj) {
    typedef void (*ReleaseFn)(void *);
    void **vtable = *reinterpret_cast<void ***>(obj);
    reinterpret_cast<ReleaseFn>(vtable[0x18 / 4])(obj);
}

/* Shared real per-entry teardown: struct_base is the true 0x18-byte
   record base (entry-8 relative to allocAllContextBuffers' own "buf"
   reference point). Real shape: +0(unnamed), +4("has real GART transfer"
   flag, matches freeCommandBuffer's own +4), +8("buf", released via
   vtable+0x18), +0xc/+0xe (u16 pair, unnamed), +0x10 (real "tag" field,
   same relative offset freeCommandBuffer passes to waitForTimeStamp),
   +0x14 (real header pointer, matches allocAllContextBuffers' own
   "primaryHeader"-shaped field). */
void FreeContextBufferEntry(ATIRadeonX1000 *accel, UInt8 *structBase) {
    if (U32At(structBase, 4) != 0) {
        accel->removeTransferFromGART(reinterpret_cast<VendorTransferBuffer *>(structBase));
    }
    ReleaseObj(reinterpret_cast<void *>(U32At(structBase, 8)));
    U32At(structBase, 0) = 0;
    U32At(structBase, 4) = 0;
    U32At(structBase, 8) = 0;
    U16At(structBase, 0xc) = 0;
    U16At(structBase, 0xe) = 0;
    U32At(structBase, 0x10) = 0;
    U32At(structBase, 0x14) = 0;
}
} // namespace

void IOATIR500GLContext::freeAllContextBuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    UInt32 ringIndex = U32At(self, 0x28c);
    UInt32 stampDelta = accelerator->waitForTimeStamp(U32At(self, ringIndex * 0x18 + 0x11c));
    U32At(accelerator, 0x780) += stampDelta;

    for (UInt32 i = 0; i < 0x10; i++) {
        FreeContextBufferEntry(accelerator, self + 0x10c + i * 0x18);
    }

    ReleaseObj(reinterpret_cast<void *>(U32At(self, 0xfc)));
    U16At(self, 0x102) = 0;
    U16At(self, 0x100) = 0;
    U32At(self, 0x108) = 0;
    U32At(self, 0xf4) = 0;
    U32At(self, 0xf8) = 0;
    U32At(self, 0xfc) = 0;
    U32At(self, 0x104) = 0;
}

void IOATIR5002DContext::freeAllContextBuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    UInt32 ringIndex = U32At(self, 0xfc);
    UInt32 stampDelta = accelerator->waitForTimeStamp(U32At(self, ringIndex * 0x18 + 0xdc));
    U32At(accelerator, 0x77c) += stampDelta;

    for (UInt32 i = 0; i < 2; i++) {
        FreeContextBufferEntry(accelerator, self + 0xcc + i * 0x18);
    }

    ReleaseObj(reinterpret_cast<void *>(U32At(self, 0xbc)));
    U16At(self, 0xc2) = 0;
    U16At(self, 0xc0) = 0;
    U32At(self, 200) = 0;
    U32At(self, 0xb4) = 0;
    U32At(self, 0xb8) = 0;
    U32At(self, 0xbc) = 0;
    U32At(self, 0xc4) = 0;
}

void IOATIR500DVDContext::freeAllContextBuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    UInt32 ringIndex = U32At(self, 0xf4);
    UInt32 stampDelta = accelerator->waitForTimeStamp(U32At(self, ringIndex * 0x18 + 0xd4));
    U32At(accelerator, 0x784) += stampDelta;

    for (UInt32 i = 0; i < 2; i++) {
        FreeContextBufferEntry(accelerator, self + 0xc4 + i * 0x18);
    }

    ReleaseObj(reinterpret_cast<void *>(U32At(self, 0xb4)));
    U16At(self, 0xba) = 0;
    U16At(self, 0xb8) = 0;
    U32At(self, 0xc0) = 0;
    U32At(self, 0xac) = 0;
    U32At(self, 0xb0) = 0;
    U32At(self, 0xb4) = 0;
    U32At(self, 0xbc) = 0;
}
