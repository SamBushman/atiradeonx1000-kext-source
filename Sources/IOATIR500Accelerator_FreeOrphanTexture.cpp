/*
 * IOATIR500Accelerator_FreeOrphanTexture.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `IOATIR500Accelerator::freeOrphanTexture` (real addr 0x3680) and
 * `IOATIR500Shared::free_texvert` (real addr 0x18710, a real STATIC
 * method - see its own header comment in `Headers/IOATIR500Shared.h`).
 *
 * `freeOrphanTexture`: walks the accelerator's own orphan-texture list
 * (`+0x664`/`+0x63c`, the same real self-pointer-as-empty-sentinel
 * shape `freeWaitToAllocGART` already establishes), reading each
 * node's own real "release arg" from its `clientShared` (`+0x14`)
 * field - `+0xc` for kind 3/7, `+8` for kind 4/5 (kinds outside
 * [4,5] and not 3/7 stop the walk entirely, matching the real
 * decompile's own early `return`). In gentle mode (`aggressive==
 * false`), confirms via the already-established `+0x554` slot the
 * node is really free before proceeding, and if not, defers the whole
 * orphan sweep to a real one-shot timer (`+0xb8`'s own vtable `+300`
 * slot, real arg `100` - own exact Apple identity unconfirmed) gated
 * by a real "already scheduled" flag at `+0x82`. In aggressive mode,
 * accumulates a freed-byte stat at `+0x790` via the already-established
 * `waitForTimeStamp` `+0x54c` slot (same real argument-dropped
 * situation this project already documents for
 * `freeTransferToAllocGART`). Between iterations after the first, calls
 * a real, address-pinned, unconfirmed single-arg external
 * (`FUN_000037dc`, real arg `0` - plausibly `IODelay`/`IOSleep` by
 * shape, not confirmed) before tearing the node down via
 * `IOATIR500Shared::free_texvert`.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - two real, complete, standalone decompiles.
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Shared.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*Fn0x554)(void *, UInt32);
typedef UInt32 (*Fn0x5ac)(void *, void *);
typedef UInt32 (*Fn0x574)(void *, void *, UInt32);
typedef bool (*ScheduleFn)(void *, UInt32);
typedef UInt32 (*ReleaseFn)(void *);
} // namespace

/* real, address-pinned - own identity NOT independently confirmed;
 * plausibly IODelay/IOSleep by its single-UInt32-arg, no-return shape
 * and its use as a between-iterations yield. */
extern "C" void FUN_000037dc(UInt32 arg);

void IOATIR500Accelerator::freeOrphanTexture(bool aggressive) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void **selfVtable = *reinterpret_cast<void ***>(self);

    UInt8 *node = reinterpret_cast<UInt8 *>(U32At(self, 0x664));
    if (node == self + 0x63c) {
        return;
    }

    bool notFirst = false;
    for (;;) {
        UInt8 kind = U8At(node, 0x20);
        UInt8 *clientShared = reinterpret_cast<UInt8 *>(U32At(node, 0x14));
        UInt32 releaseArg;
        if (kind == 3 || kind == 7) {
            releaseArg = U32At(clientShared, 0xc);
        } else {
            if (static_cast<UInt8>(kind - 4) > 1) {
                return;
            }
            releaseArg = U32At(clientShared, 8);
        }

        if (!aggressive) {
            SInt32 stillLive = (*reinterpret_cast<Fn0x554 *>(selfVtable + (0x554 / 4)))(self, releaseArg);
            if (stillLive == 0) {
                if (U8At(self, 0x82) != 0) {
                    return;
                }
                void *scheduler = *reinterpret_cast<void **>(self + 0xb8);
                (*reinterpret_cast<ScheduleFn *>(*reinterpret_cast<void ***>(scheduler) + (300 / 4)))(scheduler, 100);
                U8At(self, 0x82) = 1;
                return;
            }
        } else {
            UInt32 freed = U32At(self, 0x790);
            freed += waitForTimeStamp(0);
            U32At(self, 0x790) = freed;
        }

        if (notFirst) {
            FUN_000037dc(0);
        }
        IOATIR500Shared::free_texvert(this, reinterpret_cast<IOTextureBuffer *>(node));

        node = reinterpret_cast<UInt8 *>(U32At(self, 0x664));
        if (node == self + 0x63c) {
            break;
        }
        notFirst = true;
    }
}

void IOATIR500Shared::free_texvert(IOATIR500Accelerator *accel, IOTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(accel);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    void **accelVtable = *reinterpret_cast<void ***>(self);

    UInt8 *prev = reinterpret_cast<UInt8 *>(U32At(tex, 0x24));
    UInt32 hasDescriptor = U32At(tex, 4);
    U32At(prev, 0x28) = U32At(tex, 0x28);
    UInt8 *next = reinterpret_cast<UInt8 *>(U32At(tex, 0x28));
    U32At(tex, 0x28) = reinterpret_cast<UInt32>(tex);
    U32At(next, 0x24) = reinterpret_cast<UInt32>(prev);
    U32At(tex, 0x24) = reinterpret_cast<UInt32>(tex);

    if (hasDescriptor != 0) {
        (*reinterpret_cast<Fn0x5ac *>(accelVtable + (0x5ac / 4)))(self, tex);
    }

    UInt8 *owner = reinterpret_cast<UInt8 *>(U32At(tex, 0x1c));
    if (owner != nullptr) {
        reinterpret_cast<IOATIR500Shared *>(owner)->free_buf_handle(tex, U32At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0));
    }

    UInt8 kind = U8At(tex, 0x20);
    if (static_cast<UInt8>(kind - 3) < 5 && U32At(tex, 8) != 0) {
        void *memDesc = reinterpret_cast<void *>(U32At(tex, 8));
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
        kind = U8At(tex, 0x20);
        U32At(tex, 8) = 0;
    }

    UInt32 releaseSize = (kind == 5) ? 0xc0 : 0x80;
    (*reinterpret_cast<Fn0x574 *>(accelVtable + (0x574 / 4)))(self, tex, releaseSize);
}
