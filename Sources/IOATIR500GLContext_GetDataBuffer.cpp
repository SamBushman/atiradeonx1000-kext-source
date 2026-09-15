/*
 * IOATIR500GLContext_GetDataBuffer.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `IOATIR500GLContext::get_data_buffer` - real addr 0x9a30, the real
 * "hand the client a fresh/recycled scratch data buffer" external
 * method (external method 18).
 *
 * Real body: grows this context's own requested-size hint
 * (`this+0xb4`, capped at 0x80000) if the previous buffer turned out
 * too small for the current command-buffer's own needs, ratchets the
 * accelerator's own shared `cachedBufferSizeThresholdB` (`+0x5d8`) up
 * to match, then either reuses the accelerator's single cached free
 * data buffer (`+0x5cc`) if it's confirmed idle (via the already-
 * established `+0x554` slot) or allocates a fresh one via
 * `allocOneDataBuffer` - falling back to accumulating a real freed-
 * byte stat (`+0x1de`-th field, via `waitForTimeStamp`) when reuse
 * fails and a fresh allocation also fails. If the fetched buffer no
 * longer matches the accelerator's own cache slot, unlinks it from a
 * real secondary list (`+0x3c` singly-linked) and does real per-kind
 * teardown (GART unmap, `deallocate_texture`, GART-mapping release) to
 * reset it to a plain, unmapped, correctly-sized buffer. Then - gated
 * on whether the device is active - either backs it with plain memory
 * via `allocDataBufferBacking` (freeing and failing on error) or tries
 * the accelerator's own `allocate_texture` first, falling back to
 * `allocDataBufferBacking` if that vtable call reports no support.
 * Every path funnels into a shared tail that marks the buffer resident
 * (`+0x54`=1), appends it to this context's own pending-buffer list
 * (`+0xec`/`+0xe8`/`+0xf0`), stamps it with this context's own
 * generation counter (`+0x5c`), records it as the current command-
 * buffer target (`this+0x108`'s own `+8`), lazily creates its real
 * userspace mapping via the already-established `+0x14c` map call if
 * missing, and returns its virtual address (`+0xd0`) plus its own
 * `+0x50` field to the caller.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile. Several vtable
 * slots (`+0xdc`/`+0xf0`) have no established real name/role beyond
 * what's directly inferable from this one call site - flagged
 * accordingly rather than guessed.
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*Fn0x554)(void *, UInt32);
typedef UInt32 (*Fn0x54c)(void *, UInt32);
typedef void (*Fn0x5ac)(void *, void *);
typedef void (*Fn0x524)(void *, void *);
typedef IOReturn (*Fn0x528)(void *, void *);
typedef void (*ReleaseFn)(void *);
typedef UInt32 (*Fn0xdc)(void *);
typedef void (*Fn0xf0)(void *, UInt32, UInt32, UInt32);
typedef void *(*MapFn)(void *, void *, int, UInt32, UInt32, UInt32);
typedef UInt32 (*Fn0xd0)(void *);
} // namespace

extern "C" void GetDataBuffer_mutex_lock(void *lockPtr) asm("_mutex_lock");
extern "C" void GetDataBuffer_mutex_unlock(void *lockPtr) asm("_mutex_unlock_rwcmb");
extern "C" int _ASICSupportsAGP;

IOReturn IOATIR500GLContext::get_data_buffer(UInt32 *outHandle, UInt32 *outAddress) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
    GetDataBuffer_mutex_lock(*reinterpret_cast<void **>(accel + 0x840));

    UInt8 *pendingTail = reinterpret_cast<UInt8 *>(U32At(self, 0xec));
    if (pendingTail != nullptr) {
        UInt32 neededBytes = U32At(reinterpret_cast<void *>(U32At(self, 0x108)), 0xc) * 4;
        if (static_cast<UInt32>(static_cast<SInt32>(U32At(pendingTail, 0x50)) - _ASICSupportsAGP) < neededBytes &&
            U32At(self, 0xb4) < 0x80000) {
            U32At(self, 0xb4) <<= 1;
        }
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
        U32At(accel, 0x70c) += neededBytes;
    }

    accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
    if (U32At(accel, 0x5d8) < U32At(self, 0xb4)) {
        U32At(accel, 0x5d8) = U32At(self, 0xb4);
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
    }

    void **accelVtable = *reinterpret_cast<void ***>(accel);
    UInt8 *buf = reinterpret_cast<UInt8 *>(U32At(accel, 0x5cc));
    if (buf == nullptr) {
        buf = reinterpret_cast<UInt8 *>(
            reinterpret_cast<IOATIR500Accelerator *>(accel)->allocOneDataBuffer(U32At(accel, 0x5d8), true));
        if (buf == nullptr) {
            GetDataBuffer_mutex_unlock(*reinterpret_cast<void **>(accel + 0x840));
            *outHandle = 0;
            *outAddress = 0;
            return 0xe00002be;
        }
    } else {
        SInt32 stillLive = (*reinterpret_cast<Fn0x554 *>(accelVtable + (0x554 / 4)))(accel, U32At(buf, 0x5c));
        if (stillLive == 0) {
            buf = reinterpret_cast<UInt8 *>(
                reinterpret_cast<IOATIR500Accelerator *>(reinterpret_cast<UInt8 *>(U32At(self, 0xc8)))
                    ->allocOneDataBuffer(U32At(reinterpret_cast<void *>(U32At(self, 0xc8)), 0x5d8), true));
            if (buf == nullptr) {
                UInt8 *accel2 = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
                buf = reinterpret_cast<UInt8 *>(U32At(accel2, 0x5cc));
                UInt32 prevStat = U32At(accel2, 0x778);
                void **accel2Vtable = *reinterpret_cast<void ***>(accel2);
                UInt32 delta = (*reinterpret_cast<Fn0x54c *>(accel2Vtable + (0x54c / 4)))(accel2, U32At(buf, 0x5c));
                U32At(accel2, 0x778) = prevStat + delta;
            }
        }
    }

    accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
    accelVtable = *reinterpret_cast<void ***>(accel);

    if (buf == reinterpret_cast<UInt8 *>(U32At(accel, 0x5cc))) {
        U32At(accel, 0x5cc) = U32At(buf, 0x3c);
        if (U32At(buf, 0x3c) == 0) {
            U32At(accel, 0x5d0) = 0;
        } else {
            U32At(buf, 0x3c) = 0;
        }
        U32At(accel, 0x5d4) -= 1;
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));

        if (U32At(buf, 0x50) != U32At(accel, 0x5d8)) {
            UInt8 *gart = reinterpret_cast<UInt8 *>(U32At(buf, 8));
            if (gart != nullptr) {
                if (U32At(buf, 4) != 0) {
                    (*reinterpret_cast<Fn0x5ac *>(*reinterpret_cast<void ***>(accel) + (0x5ac / 4)))(accel, buf);
                    gart = reinterpret_cast<UInt8 *>(U32At(buf, 8));
                }
                (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(gart) + (0x18 / 4)))(gart);
                U32At(buf, 8) = 0;
            }
            if (U32At(buf, 0x48) != 0) {
                (*reinterpret_cast<Fn0x524 *>(*reinterpret_cast<void ***>(accel) + (0x524 / 4)))(accel, buf);
                UInt8 *prev = reinterpret_cast<UInt8 *>(U32At(buf, 0x24));
                U32At(prev, 0x28) = U32At(buf, 0x28);
                UInt8 *next = reinterpret_cast<UInt8 *>(U32At(buf, 0x28));
                U32At(buf, 0x28) = reinterpret_cast<UInt32>(buf);
                U32At(next, 0x24) = reinterpret_cast<UInt32>(prev);
                U32At(buf, 0x24) = reinterpret_cast<UInt32>(buf);
            }
            UInt8 *mapping = reinterpret_cast<UInt8 *>(U32At(buf, 0x10));
            if (mapping != nullptr) {
                (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(mapping) + (0x18 / 4)))(mapping);
                U32At(buf, 0x10) = 0;
            }
            U32At(buf, 0x50) = U32At(reinterpret_cast<void *>(U32At(self, 0xc8)), 0x5d8);
            accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
        }

        if (U8At(accel, 0x80) == 0) {
            if (U32At(buf, 8) == 0) {
                bool ok = reinterpret_cast<IOATIR500Accelerator *>(accel)->allocDataBufferBacking(
                    reinterpret_cast<VendorTextureBuffer *>(buf));
                if (!ok) {
                    reinterpret_cast<IOATIR500Accelerator *>(reinterpret_cast<UInt8 *>(U32At(self, 0xc8)))
                        ->freeOneDataBuffer(reinterpret_cast<VendorTextureBuffer *>(buf));
                    GetDataBuffer_mutex_unlock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(U32At(self, 0xc8)) + 0x840));
                    *outHandle = 0;
                    *outAddress = 0;
                    return 0xe00002be;
                }
                if (U32At(buf, 0x48) != 0) {
                    UInt8 *mapping = reinterpret_cast<UInt8 *>(U32At(buf, 0x10));
                    if (mapping != nullptr) {
                        UInt32 taskCheck = (*reinterpret_cast<Fn0xdc *>(*reinterpret_cast<void ***>(mapping) + (0xdc / 4)))(mapping);
                        if (taskCheck == U32At(self, 0x78)) {
                            (*reinterpret_cast<Fn0xf0 *>(*reinterpret_cast<void ***>(mapping) + (0xf0 / 4)))(
                                mapping, U32At(buf, 8), 0x400, 0);
                        } else {
                            (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(mapping) + (0x18 / 4)))(mapping);
                            U32At(buf, 0x10) = 0;
                        }
                    }
                    UInt8 *accel3 = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
                    (*reinterpret_cast<Fn0x524 *>(*reinterpret_cast<void ***>(accel3) + (0x524 / 4)))(accel3, buf);
                    UInt8 *prev = reinterpret_cast<UInt8 *>(U32At(buf, 0x24));
                    U32At(prev, 0x28) = U32At(buf, 0x28);
                    UInt8 *next = reinterpret_cast<UInt8 *>(U32At(buf, 0x28));
                    U32At(buf, 0x28) = reinterpret_cast<UInt32>(buf);
                    U32At(next, 0x24) = reinterpret_cast<UInt32>(prev);
                    U32At(buf, 0x24) = reinterpret_cast<UInt32>(buf);
                }
                goto haveBuffer;
            }
        } else if (U32At(buf, 0x48) == 0) {
            accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
            accelVtable = *reinterpret_cast<void ***>(accel);
            IOReturn allocated = (*reinterpret_cast<Fn0x528 *>(accelVtable + (0x528 / 4)))(accel, buf);
            if (allocated != 0) {
                if (U32At(buf, 0x48) != 0) {
                    UInt8 *prev = reinterpret_cast<UInt8 *>(U32At(buf, 0x24));
                    U32At(prev, 0x28) = U32At(buf, 0x28);
                    U32At(reinterpret_cast<void *>(U32At(buf, 0x28)), 0x24) = reinterpret_cast<UInt32>(prev);
                    U32At(buf, 0x24) = U32At(accel, 0x600);
                    U32At(buf, 0x28) = reinterpret_cast<UInt32>(accel + 0x5dc);
                    U32At(accel, 0x600) = reinterpret_cast<UInt32>(buf);
                    U32At(reinterpret_cast<void *>(U32At(buf, 0x24)), 0x28) = reinterpret_cast<UInt32>(buf);
                }
                UInt8 *accel4 = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
                void **accel4Vtable = *reinterpret_cast<void ***>(accel4);
                (*reinterpret_cast<Fn0x54c *>(accel4Vtable + (0x54c / 4)))(accel4, U32At(accel4, 0x50) - 1);
                if (U32At(buf, 8) != 0) {
                    UInt8 *mapping = reinterpret_cast<UInt8 *>(U32At(buf, 0x10));
                    if (mapping != nullptr) {
                        UInt32 taskCheck = (*reinterpret_cast<Fn0xdc *>(*reinterpret_cast<void ***>(mapping) + (0xdc / 4)))(mapping);
                        if (taskCheck == U32At(self, 0x78)) {
                            (*reinterpret_cast<Fn0xf0 *>(*reinterpret_cast<void ***>(mapping) + (0xf0 / 4)))(
                                mapping, U32At(reinterpret_cast<void *>(U32At(self, 0xc8)), 0xdc), 0x400, U32At(buf, 0x48));
                        } else {
                            (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(mapping) + (0x18 / 4)))(mapping);
                            U32At(buf, 0x10) = 0;
                        }
                    }
                    if (U32At(buf, 4) != 0) {
                        UInt8 *accel5 = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
                        (*reinterpret_cast<Fn0x5ac *>(*reinterpret_cast<void ***>(accel5) + (0x5ac / 4)))(accel5, buf);
                    }
                    UInt8 *gart = reinterpret_cast<UInt8 *>(U32At(buf, 8));
                    (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(gart) + (0x18 / 4)))(gart);
                    U32At(buf, 8) = 0;
                }
                goto haveBuffer;
            }
            if (U32At(buf, 8) == 0) {
                bool ok = reinterpret_cast<IOATIR500Accelerator *>(reinterpret_cast<UInt8 *>(U32At(self, 0xc8)))
                              ->allocDataBufferBacking(reinterpret_cast<VendorTextureBuffer *>(buf));
                if (!ok) {
                    reinterpret_cast<IOATIR500Accelerator *>(reinterpret_cast<UInt8 *>(U32At(self, 0xc8)))
                        ->freeOneDataBuffer(reinterpret_cast<VendorTextureBuffer *>(buf));
                    GetDataBuffer_mutex_unlock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(U32At(self, 0xc8)) + 0x840));
                    *outHandle = 0;
                    *outAddress = 0;
                    return 0xe00002be;
                }
                goto haveBuffer;
            }
        }
    }

    {
        UInt8 *mapping = reinterpret_cast<UInt8 *>(U32At(buf, 0x10));
        if (mapping != nullptr) {
            UInt32 taskCheck = (*reinterpret_cast<Fn0xdc *>(*reinterpret_cast<void ***>(mapping) + (0xdc / 4)))(mapping);
            if (taskCheck != U32At(self, 0x78)) {
                (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(mapping) + (0x18 / 4)))(mapping);
                U32At(buf, 0x10) = 0;
            }
        }
    }

haveBuffer:
    U8At(buf, 0x54) = 1;
    if (U32At(self, 0xec) == 0) {
        U32At(self, 0xe8) = reinterpret_cast<UInt32>(buf);
        U32At(self, 0xec) = reinterpret_cast<UInt32>(buf);
    } else {
        U32At(reinterpret_cast<void *>(U32At(self, 0xec)), 0x3c) = reinterpret_cast<UInt32>(buf);
        U32At(self, 0xec) = reinterpret_cast<UInt32>(buf);
    }
    U32At(self, 0xf0) += 1;
    U32At(buf, 0x5c) = U32At(self, 0x7c);
    U32At(reinterpret_cast<void *>(U32At(self, 0x108)), 8) = reinterpret_cast<UInt32>(buf);

    UInt8 *mapping = reinterpret_cast<UInt8 *>(U32At(buf, 0x10));
    if (mapping == nullptr) {
        if (U32At(buf, 0x48) == 0) {
            UInt8 *memDesc = reinterpret_cast<UInt8 *>(U32At(buf, 8));
            mapping = reinterpret_cast<UInt8 *>((*reinterpret_cast<MapFn *>(*reinterpret_cast<void ***>(memDesc) + (0x14c / 4)))(
                memDesc, reinterpret_cast<void *>(U32At(self, 0x78)), 0, 0x4000401, 0, U32At(buf, 0x50)));
        } else {
            UInt8 *provider = reinterpret_cast<UInt8 *>(U32At(reinterpret_cast<void *>(U32At(self, 0xc8)), 0xdc));
            mapping = reinterpret_cast<UInt8 *>((*reinterpret_cast<MapFn *>(*reinterpret_cast<void ***>(provider) + (0x14c / 4)))(
                provider, reinterpret_cast<void *>(U32At(self, 0x78)), 0, 0x4000401, U32At(buf, 0x48), U32At(buf, 0x50)));
        }
        if (mapping == nullptr) {
            *outHandle = 0;
            *outAddress = 0;
            return 0xe00002be;
        }
        U32At(buf, 0x10) = reinterpret_cast<UInt32>(mapping);
    }

    UInt32 va = (*reinterpret_cast<Fn0xd0 *>(*reinterpret_cast<void ***>(mapping) + (0xd0 / 4)))(mapping);
    *outHandle = va;
    *outAddress = U32At(buf, 0x50);
    GetDataBuffer_mutex_unlock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(U32At(self, 0xc8)) + 0x840));
    return 0;
}
