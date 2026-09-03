/*
 * ATIR500Surface_ResetFullScreen.cpp
 *
 * RESOLVED (issue #22): `resetFullScreen`'s real bodies - base
 * (`IOATIR500Surface`, real addr `0x139d0`) and subclass
 * (`ATIR500Surface`, real addr `0x3cf60`) - names/roles/addresses
 * RESOLVED issue #18, bodies transcribed here.
 *
 * Base: if this surface's own `+0xb70` field already points at its own
 * `+0x120` inline record (a real "using the embedded/default record"
 * check), re-derives three more real pointer fields (`+0xb74`/`+0xb80`/
 * `+0xb84`) from it and recomputes `+0xb70` itself from a real
 * accelerator-owned per-ID record array (`accelerator+id*0x78+300`).
 * Then calls the already-resolved `is_flip_allowed` (RESOLVED, issue
 * #22 - this file's own cross-reference, not a new finding); if true
 * AND a real per-ID bit is set in the accelerator's own `+0xd0`
 * bitmask, calls a real, still-uncatalogued vtable slot (`+0x5e0` on
 * this object) with real args `(this, id, 0, 1)` and increments a real
 * accelerator statistics field (`accelerator+0x74c`). `+0x5e0`'s own
 * real target NOT investigated this pass - noted for a future issue,
 * same as issue #22's own earlier finding of this exact slot.
 *
 * Subclass: real per-panel-side (`this+0xc14`, the SAME real ID-slot
 * field `set_id_mode`/`is_flip_allowed` already established) mirroring
 * of a real byte value (`this+0xdbb`) into two accelerator-owned per-ID
 * record fields, gated on real accelerator feature flags
 * (`accelerator+0x9b0`/`+0x894`) via a real, genuinely asymmetric nested
 * if/else (the two branches touch different sides/fields, not a
 * simplifiable mirror of each other). Then calls `is_flip_allowed()`
 * through ordinary virtual dispatch (a real raw vtable-indirect call in
 * the decompile, NOT a base-qualified one - resolves to THIS class's
 * own composite override, not the base's simpler check) and, if that reports
 * false, does a real direct MMIO register write (four real bytes
 * assembled from a fixed table at a real pointer stored at
 * `accelerator+0x860` - dereferenced, not the address itself -
 * `+0x6104..0x6107`) to one of two real register addresses selected by
 * panel side, followed by a real, previously-unreferenced plain C
 * symbol call, `enforceInOrderExecutionIO` (a new find this pass, see
 * below) - repeated a second time, unconditionally
 * gated on the SAME `accelerator+0x894` feature flag the record-mirror
 * step above uses, targeting the OTHER panel side's register address.
 * Finally, unconditionally calls the base class's own `resetFullScreen`.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant - two real, complete decompiles, not summarized. The real
 * MMIO register addresses this function writes to (`0x6104`/`0x6904`
 * region) are transcribed as raw literals - this project has not
 * independently named this register block. No C++ compiler was
 * available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project) - checked by
 * careful, repeated manual re-reading against each raw decompile
 * instead.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void enforceInOrderExecutionIO(void); /* real name, found this pass (issue #22) - a real, already-mangled-free (plain C symbol) call in the raw decompile, almost certainly Apple's standard PPC I/O memory barrier primitive of the same public name; not previously referenced anywhere in this project */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

void IOATIR500Surface::resetFullScreen() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    if (U32At(self, 0xb70) == reinterpret_cast<UInt32>(self + 0x120)) {
        U32At(self, 0xb74) = U32At(self, 0xb70);
        U32At(self, 0xb80) = reinterpret_cast<UInt32>(self + 0x288);
        U32At(self, 0xb84) = reinterpret_cast<UInt32>(self + 0x300);
        U32At(self, 0xb70) = U32At(self, 0xc14) * 0x78 + reinterpret_cast<UInt32>(accel) + 300;
    }

    if (is_flip_allowed() != 0) {
        UInt32 id = U32At(self, 0xc14);
        if ((U32At(accel, 0xd0) & (1u << (id & 0x3f))) != 0) {
            typedef void (*Fn0x5e0)(void *, UInt32, UInt32, UInt32);
            UInt32 *vtable = *reinterpret_cast<UInt32 **>(self);
            (*reinterpret_cast<Fn0x5e0 *>(vtable + (0x5e0 / 4)))(self, id, 0, 1);
            U32At(accel, 0x74c) += 1;
        }
    }
}

void ATIR500Surface::resetFullScreen() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    UInt8 sideValue = U8At(self, 0xdbb);
    UInt32 id = U32At(self, 0xc14);
    U8At(accel + id * 0x78, 0x164) = sideValue;
    U8At(self, id + 0xdb6) = 0;

    /* real: transcribed to precisely match the raw decompile's own nested if/else - the two
     * branches are NOT symmetric (real "which side" and "which fields" differ), not simplified. */
    if (U8At(accel, 0x9b0) != 0) {
        if (U32At(accel + id * 0x18, 0xb10) == 0) {
            UInt32 otherId = (id == 0) ? 1u : 0u;
            if (U32At(accel, 0x894) != 0 && U32At(accel + otherId * 0x18, 0xb10) != 0) {
                UInt8 *otherRec = accel + otherId * 0x78;
                U8At(otherRec, 0x9f4) = sideValue;
                U8At(otherRec, 0x164) = sideValue;
            }
        } else {
            U8At(accel + id * 0x78, 0x9f4) = sideValue;
            if (U32At(accel, 0x894) != 0) {
                UInt32 otherId = (id == 0) ? 1u : 0u;
                if (U32At(accel + otherId * 0x18, 0xb10) == 0) {
                    U8At(accel + otherId * 0x78, 0x164) = sideValue;
                } else {
                    U8At(accel + otherId * 0x78, 0x164) = sideValue;
                    U8At(accel + otherId * 0x78, 0x9f4) = sideValue;
                }
            }
        }
    }

    /* real: a genuine raw vtable-indirect call (not a base-qualified call) - ordinary virtual
     * dispatch, which for this real object type resolves to THIS class's own composite
     * is_flip_allowed() override, not the base's simpler check. CORRECTED before commit - an
     * earlier draft of this file wrongly base-qualified this call. */
    if (is_flip_allowed() == 0) {
        UInt8 *mmio = reinterpret_cast<UInt8 *>(U32At(accel, 0x860)); /* real: *(int*)(accel+0x860) is a pointer VALUE, not accel+0x860 itself */
        UInt8 b7 = U8At(mmio, 0x6107);
        UInt8 b5 = U8At(mmio, 0x6105);
        UInt8 b4 = U8At(mmio, 0x6104);
        UInt32 field6 = (U8At(mmio, 0x6106) & 0xffcfu) << 0x10;
        UInt8 sideAtId = U8At(accel + id * 0x78, 0x164);
        UInt32 bit1 = (sideAtId & 1u) << 0x15;
        UInt32 bit2 = (sideAtId > 1) ? 0x100000u : 0u;
        UInt32 regOffset = (id == 0) ? 0x6104u : 0x6904u;
        U32At(mmio, regOffset) = (static_cast<UInt32>(b4) << 0x18) | (static_cast<UInt32>(b5) << 0x10) |
                                  (((bit2 | field6 | bit1) >> 8)) | static_cast<UInt32>(b7);
        enforceInOrderExecutionIO();

        if (U32At(accel, 0x894) != 0) {
            UInt32 otherRegOffset = (id == 0) ? 0x6904u : 0x6104u;
            U32At(mmio, otherRegOffset) = (static_cast<UInt32>(b4) << 0x18) | (static_cast<UInt32>(b5) << 0x10) |
                                           (((bit2 | field6 | bit1) >> 8)) | static_cast<UInt32>(b7);
            enforceInOrderExecutionIO();
        }
    }

    IOATIR500Surface::resetFullScreen();
}
