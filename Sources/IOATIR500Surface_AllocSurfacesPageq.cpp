/*
 * IOATIR500Surface_AllocSurfacesPageq.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `IOATIR500Surface::invalidate_contexts` (real addr 0x12050) and
 * `IOATIR500Surface::alloc_surfaces_pageq` (real addr 0x12110) - see
 * each method's own header comment in `Headers/IOATIR500Surface.h` for
 * full detail on real offsets/return-value meanings.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - two real, complete, standalone decompiles.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*InvalidateFn)(void *);
typedef UInt32 (*Fn0x5f4)(void *, UInt32, UInt32);
} // namespace

void IOATIR500Surface::invalidate_contexts(void) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    U32At(accelerator, 0x78) = 0;

    for (UInt8 *node = reinterpret_cast<UInt8 *>(U32At(self, 0x8c)); node != nullptr;
         node = reinterpret_cast<UInt8 *>(U32At(node, 0x84))) {
        (*reinterpret_cast<InvalidateFn *>(*reinterpret_cast<void ***>(node) + (0x5a4 / 4)))(node);
    }
    for (UInt8 *node = reinterpret_cast<UInt8 *>(U32At(self, 0x88)); node != nullptr;
         node = reinterpret_cast<UInt8 *>(U32At(node, 0x84))) {
        (*reinterpret_cast<InvalidateFn *>(*reinterpret_cast<void ***>(node) + (0x5a4 / 4)))(node);
    }
    UInt8 *single = reinterpret_cast<UInt8 *>(U32At(self, 0x90));
    if (single != nullptr) {
        (*reinterpret_cast<InvalidateFn *>(*reinterpret_cast<void ***>(single) + (0x5a4 / 4)))(single);
    }
}

UInt32 IOATIR500Surface::alloc_surfaces_pageq(UInt32 mask, UInt32 flag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void **selfVtable = *reinterpret_cast<void ***>(self);

    invalidate_contexts();

    UInt32 bits = mask & U32At(self, 0xbf8);
    if (bits == 0) {
        return 0;
    }

    bool allOk;
    {
        UInt32 bitIndex = 0;
        allOk = true;
        do {
            UInt32 bitVal = 1u << (bitIndex & 0x3f);
            if ((bits & bitVal) != 0) {
                UInt32 ok = (*reinterpret_cast<Fn0x5f4 *>(selfVtable + (0x5f4 / 4)))(self, bitIndex, (flag & bitVal) == 0);
                allOk = allOk && (ok != 0);
            }
            bitIndex++;
            if ((bits >> (bitIndex & 0x3f)) == 0 || bitIndex == 0x17) {
                break;
            }
        } while (allOk);
    }
    if (allOk) {
        return 0;
    }

    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);
    UInt8 *surfHead = reinterpret_cast<UInt8 *>(U32At(accel, 0x5c));
    if (surfHead != nullptr) {
        UInt8 *node = surfHead;
        do {
            if (U32At(node, 0xbd0) != 0) {
                return 1;
            }
            node = reinterpret_cast<UInt8 *>(U32At(node, 0x9c));
        } while (node != surfHead);
    }

    bool movedAny = false;
    for (UInt32 i = 0; i <= 0x16; i++) {
        UInt8 *elem = self + 0xa8 + i * 0x78;
        if (U32At(elem, 8) != 0) {
            move_buffer_to_backing_store(reinterpret_cast<ATIR500SurfaceBuffer *>(elem));
            movedAny = true;
        }
    }

    if (movedAny) {
        bits = mask & U32At(self, 0xbf8);
        if (bits == 0) {
            return 0;
        }
        UInt32 bitIndex = 0;
        bool retryOk = true;
        do {
            UInt32 bitVal = 1u << (bitIndex & 0x3f);
            if ((bits & bitVal) != 0) {
                UInt32 ok = (*reinterpret_cast<Fn0x5f4 *>(selfVtable + (0x5f4 / 4)))(self, bitIndex, (flag & bitVal) == 0);
                retryOk = retryOk && (ok != 0);
            }
            bitIndex++;
            if ((bits >> (bitIndex & 0x3f)) == 0 || bitIndex == 0x17) {
                break;
            }
        } while (retryOk);
        if (retryOk) {
            return 0;
        }
    }

    return 2;
}
