/*
 * IOATIR500GLContext_ClientMemoryForType.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `IOATIR500GLContext::clientMemoryForType` - real addr 0xa160, the
 * real external-method-family memory-descriptor vendor for this class.
 *
 * type 0/2/3: thin wrappers returning a real, already-allocated shared
 * memory descriptor (accelerator's `+0xac`, this context's own `+0xfc`
 * context-buffer descriptor, accelerator's `+0xb0`), retaining it via
 * the standard `+0x14` vtable slot.
 *
 * type 4: a real growable scratch buffer (double-and-copy on overflow,
 * matching this project's other established growable-buffer patterns)
 * via the already-established `FUN_withOptions`-shaped allocator
 * (declared locally as `ClientMemory_FUN_0000aee8`) and a `memmove`-
 * shaped copy helper (`ClientMemory_FUN_0000aed8`).
 *
 * type 1: the real, large "flush the current command buffer and hand
 * the client a fresh one" path - this class's actual submit/swap
 * logic. Gates on the bound surface's own real state (waiting via
 * `IOLockSleep` for the device to become active, retrying up to 1000
 * times via `alloc_surfaces_pageq` against the surface's own real
 * `+0xbf8`/`+0xc1c` state-bits fields), does real per-texture stream
 * bookkeeping (`add_texture_to_stream`/`remove_texture_from_stream`,
 * both already established), a real command-buffer double-buffer swap
 * against the accelerator's own per-slot ring pool (allocating more
 * via `allocMoreCommandBuffers` on demand), relinks the surface into
 * the accelerator's live-surface circular list when needed, and
 * schedules a real deferred "flush" notification (accelerator `+0xc0`
 * event source, or a simple pending flag) before returning the fresh
 * command-buffer descriptor and re-initializing its header via the
 * newly-established `IOATIR500GLContext::init_command_buffer_header`.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile (the largest single
 * function this project has transcribed). A substantial number of
 * vtable slots (`+0x5b0`/`+0x5b4`/`+0x5b8`/`+0x5bc`/`+0x5c0`/`+0x5d8`/
 * `+0x5dc`/`+0x5e0`/`+0x560`) and raw fields have no established real
 * name/role beyond what's directly inferable from this one function -
 * flagged as such rather than guessed, matching this project's
 * established convention throughout the rest of this pass.
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*RetainFn)(void *);
typedef void (*VoidFn)(void *);
typedef SInt32 (*Fn0x554)(void *, UInt32);
typedef UInt32 (*Fn0x54c)(void *, UInt32);
typedef UInt32 (*Fn0x55c)(void *, UInt32);
} // namespace

extern "C" void ClientMem_mutex_lock(void *lockPtr) asm("_mutex_lock");
extern "C" void ClientMem_mutex_unlock(void *lockPtr) asm("_mutex_unlock_rwcmb");
extern "C" void ClientMem_IOLockSleep(void *lockPtr, void *event, UInt32 zero) asm("_IOLockSleep");
extern "C" void *ClientMem_FUN_0000aee8(UInt32 options, UInt32 capacity, int align);
extern "C" void ClientMem_FUN_0000aed8(void *dest, void *src, UInt32 size);
/* real, address-pinned - own identity NOT independently confirmed;
 * called as a pair immediately after unlocking in a retry loop,
 * plausibly a yield/short-delay pair. */
extern "C" void ClientMem_FUN_0000af98(UInt32 arg);
extern "C" void ClientMem_FUN_0000af88(UInt32 arg);
extern "C" int _ASICSupportsAGP;

void IOATIR500GLContext::init_command_buffer_header(VendorCommandBufferHeader *header, UInt32 size, UInt32 extra) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *h = reinterpret_cast<UInt8 *>(header);
    for (int off = 0; off < 0x20; off += 4) {
        U32At(h, off) = 0;
    }
    U32At(h, 0x14) = extra;
    U32At(h, 0x20) = 0x1000000;
    U32At(h, 0x10) = (size - 0x20) >> 2;
    U32At(h, 0x1c) = 1;
    U32At(h, 0x18) = U32At(self, 0x7c);
}

IOReturn IOATIR500GLContext::clientMemoryForType(UInt32 type, UInt32 *options, IOMemoryDescriptor **memory) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));

    switch (type) {
    case 0: {
        UInt8 *desc = reinterpret_cast<UInt8 *>(U32At(accel, 0xac));
        if (desc != nullptr) {
            (*reinterpret_cast<RetainFn *>(*reinterpret_cast<void ***>(desc) + (0x14 / 4)))(desc);
            *options = 0;
            *memory = reinterpret_cast<IOMemoryDescriptor *>(desc);
            return 0;
        }
        break;
    }
    case 2: {
        ClientMem_mutex_lock(*reinterpret_cast<void **>(accel + 0x840));
        UInt8 *desc = reinterpret_cast<UInt8 *>(U32At(self, 0xfc));
        (*reinterpret_cast<RetainFn *>(*reinterpret_cast<void ***>(desc) + (0x14 / 4)))(desc);
        *options = 0;
        *memory = reinterpret_cast<IOMemoryDescriptor *>(desc);
        init_context_buffer_header(reinterpret_cast<VendorContextBufferHeader *>(U32At(self, 0x108)), 0x8000);
        ClientMem_mutex_unlock(*reinterpret_cast<void **>(accel + 0x840));
        return 0;
    }
    case 3: {
        UInt8 *desc = reinterpret_cast<UInt8 *>(U32At(accel, 0xb0));
        if (desc != nullptr) {
            (*reinterpret_cast<RetainFn *>(*reinterpret_cast<void ***>(desc) + (0x14 / 4)))(desc);
            *options = 0;
            *memory = reinterpret_cast<IOMemoryDescriptor *>(desc);
            return 0;
        }
        break;
    }
    case 4: {
        if (U32At(self, 0xb8) == 0) {
            U32At(self, 0xbc) = _ASICSupportsAGP;
            UInt8 *desc = reinterpret_cast<UInt8 *>(ClientMem_FUN_0000aee8(0x10023, _ASICSupportsAGP, _ASICSupportsAGP));
            U32At(self, 0xb8) = reinterpret_cast<UInt32>(desc);
            if (desc != nullptr) {
                typedef UInt32 (*Fn0x1cc)(void *);
                UInt32 va = (*reinterpret_cast<Fn0x1cc *>(*reinterpret_cast<void ***>(desc) + (0x1cc / 4)))(desc);
                U32At(self, 0xc0) = va;
                UInt8 *d2 = reinterpret_cast<UInt8 *>(U32At(self, 0xb8));
                (*reinterpret_cast<RetainFn *>(*reinterpret_cast<void ***>(d2) + (0x14 / 4)))(d2);
                *options = 0;
                *memory = reinterpret_cast<IOMemoryDescriptor *>(d2);
                return 0;
            }
        } else {
            UInt32 oldSize = U32At(self, 0xbc);
            UInt8 *desc = reinterpret_cast<UInt8 *>(ClientMem_FUN_0000aee8(0x10023, oldSize << 1, _ASICSupportsAGP));
            if (desc != nullptr) {
                typedef UInt32 (*Fn0x1cc)(void *);
                UInt32 va = (*reinterpret_cast<Fn0x1cc *>(*reinterpret_cast<void ***>(desc) + (0x1cc / 4)))(desc);
                ClientMem_FUN_0000aed8(reinterpret_cast<void *>(va), reinterpret_cast<void *>(U32At(self, 0xc0)), oldSize);
                UInt8 *oldDesc = reinterpret_cast<UInt8 *>(U32At(self, 0xb8));
                (*reinterpret_cast<VoidFn *>(*reinterpret_cast<void ***>(oldDesc) + (0x18 / 4)))(oldDesc);
                U32At(self, 0xb8) = reinterpret_cast<UInt32>(desc);
                U32At(self, 0xbc) = oldSize << 1;
                U32At(self, 0xc0) = va;
                UInt8 *d2 = reinterpret_cast<UInt8 *>(U32At(self, 0xb8));
                (*reinterpret_cast<RetainFn *>(*reinterpret_cast<void ***>(d2) + (0x14 / 4)))(d2);
                *options = 0;
                *memory = reinterpret_cast<IOMemoryDescriptor *>(d2);
                return 0;
            }
        }
        break;
    }
    case 1: {
        UInt32 wantBits = 0;
        UInt32 retries = 0;
        UInt32 convertBit = 0;
        UInt32 syncFlags;
        bool needsFlushNotify;

    retryFromTop:
        for (;;) {
            ClientMem_mutex_lock(*reinterpret_cast<void **>(accel + 0x840));
            UInt8 *surface = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
            if (surface == nullptr) {
                syncFlags = 0;
                needsFlushNotify = false;
                goto notActive;
            }

            UInt8 *accelForSurf;
            if (U32At(surface, 0xa4) < 0x100) {
            haveAccel:
                accelForSurf = accel;
            } else {
                accelForSurf = accel;
                if (U8At(accel, 0x80) == 0) {
                    do {
                        ClientMem_IOLockSleep(*reinterpret_cast<void **>(accel + 0x840), accel, 0);
                    } while (U8At(accel, 0x80) == 0);
                    surface = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                    if (surface != nullptr) goto haveAccel;
                    syncFlags = 0;
                    needsFlushNotify = false;
                    goto notActive;
                }
            }
            (void)accelForSurf;

            if (U8At(accel, 0x80) == 0) {
                syncFlags = 0;
                needsFlushNotify = false;
                goto notActive;
            }

            if (U8At(surface, 0xbf6) == 0) {
                syncFlags = U32At(surface, 0xbfc);
                if (U16At(self, 0x98) != 0 && (U32At(surface, 0xbe8) & 0x20) != 0) {
                    syncFlags |= 2;
                }

                if (U8At(surface, 0xbd0) == 0 || retries == 999) {
                    UInt32 stateBits = U32At(surface, 0xbf8);
                    if (((U32At(self, 0x8c) | U32At(surface, 0xc1c)) & stateBits) != 0) {
                        if ((stateBits & 0x20000000u) != 0) {
                            goto bailInactive;
                        }
                        UInt32 mask = (U32At(self, 0x8c) | U32At(surface, 0xc1c)) & 0x7fffffu;
                        UInt32 hitMask = stateBits & mask;
                        SInt32 pageqResult;
                        if (hitMask == 0) {
                            pageqResult = 0; /* real: iVar3 = *(int*)surface (vtable ptr) - value never used except for the fallthrough vtable call below */
                        } else {
                            if ((hitMask & 1) != 0 && U32At(surface, 0xcc) == 0 &&
                                ((stateBits & 2) == 0 || U32At(surface, 0x144) != 0)) {
                                wantBits |= 1;
                            }
                            if ((U32At(surface, 0xbe8) & 0x20u) == 0 && (hitMask & 0x20u) != 0) {
                                wantBits |= 2;
                            }
                            convertBit = reinterpret_cast<IOATIR500Surface *>(surface)->convert_surface_bits(
                                U32At(reinterpret_cast<void *>(U32At(self, 0xe0)), 0xc));
                            pageqResult = reinterpret_cast<IOATIR500Surface *>(surface)->alloc_surfaces_pageq(mask, convertBit);
                            if (pageqResult != 0) {
                                if (pageqResult != 2) goto retryWait;
                                goto bailInactive;
                            }
                            surface = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                            if ((U32At(surface, 0xbf8) & U32At(surface, 0xc1c) & 0x10000000u) == 0) {
                                goto afterVtable5c0;
                            }
                        }
                        typedef void (*Fn0x5c0)(void *);
                        (*reinterpret_cast<Fn0x5c0 *>(*reinterpret_cast<void ***>(surface) + (0x5c0 / 4)))(surface);
                        U32At(reinterpret_cast<void *>(U32At(self, 0x290)), 0xbf8) &= 0xefffffffu;
                    }
                afterVtable5c0:
                    if (retries > 999) {
                        if (retries < 0x3e9) goto forceRetry;
                        goto bailInactive;
                    }
                } else {
                retryWait:
                    if (retries != 1000) {
                        retries++;
                        ClientMem_mutex_unlock(*reinterpret_cast<void **>(accel + 0x840));
                        ClientMem_FUN_0000af98(0);
                        ClientMem_FUN_0000af88(1);
                        goto retryFromTop;
                    }
                forceRetry:
                    {
                        UInt8 *surf2 = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                        SInt32 pageqResult2 = reinterpret_cast<IOATIR500Surface *>(surf2)->alloc_surfaces_pageq(
                            (U32At(self, 0x8c) | U32At(surf2, 0xc1c)) & 0x7fffffu, convertBit);
                        if (pageqResult2 != 0) goto bailInactive;
                        UInt8 *surf3 = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                        if ((U32At(surf3, 0xbf8) & U32At(surf3, 0xc1c) & 0x10000000u) != 0) {
                            typedef void (*Fn0x5c0)(void *);
                            (*reinterpret_cast<Fn0x5c0 *>(*reinterpret_cast<void ***>(surf3) + (0x5c0 / 4)))(surf3);
                            U32At(reinterpret_cast<void *>(U32At(self, 0x290)), 0xbf8) &= 0xefffffffu;
                        }
                    }
                }

                if (wantBits != 0) {
                    UInt8 *surf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                    if ((wantBits & 1) != 0) {
                        typedef void (*Fn0x5d8)(void *, UInt32, UInt32, void *);
                        (*reinterpret_cast<Fn0x5d8 *>(*reinterpret_cast<void ***>(surf) + (0x5d8 / 4)))(surf, 0, 1, self);
                        U32At(accel, 0x74c) += 1;
                    }
                    if ((wantBits & 2) != 0) {
                        surf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                        UInt32 bitIdx = U32At(surf, 0x305 * 4);
                        if (((1u << (bitIdx & 0x3f)) & U32At(accel, 0xd0)) != 0) {
                            typedef void (*Fn0x5e0)(void *, UInt32, void *, UInt32);
                            (*reinterpret_cast<Fn0x5e0 *>(*reinterpret_cast<void ***>(surf) + (0x5e0 / 4)))(surf, bitIdx, self, 0);
                            U32At(accel, 0x74c) += 1;
                        }
                    }
                }

                for (UInt8 *slot = self; slot != self + 0xa8; slot += 4) {
                    UInt32 tex = U32At(slot, 0x2a4);
                    if (tex != 0) {
                        add_texture_to_stream(reinterpret_cast<VendorTextureBuffer *>(tex));
                    }
                }

                if (self != reinterpret_cast<UInt8 *>(U32At(accel, 0x78))) {
                    typedef void (*Fn0x5b0)(void *);
                    (*reinterpret_cast<Fn0x5b0 *>(*reinterpret_cast<void ***>(self) + (0x5b0 / 4)))(self);
                    U32At(accel, 0x740) += 1;
                    U32At(accel, 0x78) = reinterpret_cast<UInt32>(self);
                }

                {
                    UInt8 *surf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                    typedef void (*Fn0x5b8)(void *, UInt32);
                    (*reinterpret_cast<Fn0x5b8 *>(*reinterpret_cast<void ***>(surf) + (0x5b8 / 4)))(surf, U32At(self, 0x8c));
                }
                if (U32At(self, 0xd0) == 0) {
                    map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(self + 0xcc));
                }

                UInt8 stackBuf[8];
                UInt32 local60;
                UInt32 local5c;
                {
                    typedef UInt32 (*Fn0x5b4)(void *, void *);
                    wantBits = (*reinterpret_cast<Fn0x5b4 *>(*reinterpret_cast<void ***>(self) + (0x5b4 / 4)))(self, stackBuf);
                    local60 = *reinterpret_cast<UInt32 *>(stackBuf);
                    local5c = *reinterpret_cast<UInt32 *>(stackBuf + 4);
                }

                for (UInt8 *slot = self; slot != self + 0xa8; slot += 4) {
                    UInt32 tex = U32At(slot, 0x2a4);
                    if (tex != 0) {
                        remove_texture_from_stream(reinterpret_cast<VendorTextureBuffer *>(tex));
                    }
                }

                UInt8 *ctxHeader = reinterpret_cast<UInt8 *>(U32At(self, 0xe0));
                if (static_cast<UInt32>(U32At(ctxHeader, 0x10) * 4 - _ASICSupportsAGP) <
                    static_cast<UInt32>(local5c - reinterpret_cast<UInt32>(ctxHeader + 0x20)) &&
                    U32At(self, 0xb0) < 0x80000) {
                    U32At(self, 0xb0) <<= 1;
                }

                SInt32 stamp;
                if (local60 == 0) {
                    stamp = static_cast<SInt32>(U32At(accel, 0x50)) - 1;
                } else {
                    U32At(accel, 0x704) += local60 * 4;
                    typedef SInt32 (*Fn0x560)(void *, void *);
                    stamp = (*reinterpret_cast<Fn0x560 *>(*reinterpret_cast<void ***>(accel) + (0x560 / 4)))(accel, stackBuf);
                }

                UInt8 *surf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                typedef SInt32 (*Fn0x5b4b)(void *, SInt32, UInt32);
                stamp = (*reinterpret_cast<Fn0x5b4b *>(*reinterpret_cast<void ***>(surf) + (0x5b4 / 4)))(surf, stamp, U32At(self, 0x8c));
                U32At(surf, 0x7c) = static_cast<UInt32>(stamp);
                U32At(self, 0x7c) = static_cast<UInt32>(stamp);
                U32At(self, 0xdc) = static_cast<UInt32>(stamp);

                surf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                if (surf != reinterpret_cast<UInt8 *>(U32At(accel, 0x5c))) {
                    UInt8 *prev = reinterpret_cast<UInt8 *>(U32At(surf, 0x9c));
                    U32At(prev, 0xa0) = U32At(surf, 0xa0);
                    UInt8 *next = reinterpret_cast<UInt8 *>(U32At(surf, 0xa0));
                    U32At(next, 0x9c) = U32At(surf, 0x9c);
                    UInt8 *oldHead = reinterpret_cast<UInt8 *>(U32At(accel, 0x5c));
                    U32At(surf, 0x9c) = reinterpret_cast<UInt32>(oldHead);
                    UInt8 *oldHeadPrev = reinterpret_cast<UInt8 *>(U32At(oldHead, 0xa0));
                    U32At(surf, 0xa0) = reinterpret_cast<UInt32>(oldHeadPrev);
                    U32At(oldHead, 0xa0) = reinterpret_cast<UInt32>(surf);
                    U32At(oldHeadPrev, 0x9c) = reinterpret_cast<UInt32>(surf);
                    U32At(accel, 0x5c) = reinterpret_cast<UInt32>(surf);
                    surf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                }

                {
                    typedef void (*Fn0x5bc)(void *, UInt32);
                    (*reinterpret_cast<Fn0x5bc *>(*reinterpret_cast<void ***>(surf) + (0x5bc / 4)))(surf, U32At(self, 0x8c));
                }

                if ((syncFlags & 2) != 0) {
                    wantBits &= 1;
                }

                needsFlushNotify = (wantBits != 0);
                if (needsFlushNotify) {
                    surf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                    U32At(surf, 0x84) = U32At(surf, 0x80);
                    surf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                    if ((U32At(surf, 0x2fa * 1) & 0x20u) == 0) {
                        typedef SInt32 (*Fn0x5dc)(void *);
                        SInt32 rc = (*reinterpret_cast<Fn0x5dc *>(*reinterpret_cast<void ***>(surf) + (0x5dc / 4)))(surf);
                        if (rc == 0) {
                            goto perTileNotify;
                        }
                        surf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                        UInt32 tmp1 = U32At(surf, 0xb74);
                        UInt32 slot307 = U32At(surf, 0xc14);
                        U32At(surf, 0xb74) = U32At(surf, 0xb70);
                        U32At(reinterpret_cast<void *>(U32At(self, 0x290)), 0xb70) = tmp1;
                        surf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                        UInt32 tmp2 = U32At(surf, 0xb80);
                        U32At(surf, 0xb80) = U32At(surf, 0xb84);
                        U32At(reinterpret_cast<void *>(U32At(self, 0x290)), 0xb84) = tmp2;
                        if (((1u << (slot307 & 0x3f)) & U32At(accel, 0x34 * 4)) != 0) {
                            UInt8 *surf4 = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                            typedef void (*Fn0x5e0)(void *, UInt32, void *, UInt32);
                            (*reinterpret_cast<Fn0x5e0 *>(*reinterpret_cast<void ***>(surf4) + (0x5e0 / 4)))(surf4, slot307, self, 0);
                            U32At(accel, 0x74c) += 1;
                        }
                    } else {
                    perTileNotify:
                        UInt32 tileIdx = 0;
                        SInt32 byteOff = 0;
                        for (;;) {
                            UInt8 *surf5 = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                            UInt32 dispatchBits = wantBits;
                            if (U8At(surf5, byteOff + 0xcac) != 0 || (dispatchBits = wantBits & 1) != 0) {
                                typedef void (*Fn0x5d8)(void *, UInt32, UInt32, void *);
                                (*reinterpret_cast<Fn0x5d8 *>(*reinterpret_cast<void ***>(surf5) + (0x5d8 / 4)))(surf5, tileIdx, dispatchBits, self);
                                U32At(accel, 0x74c) += 1;
                            }
                            tileIdx++;
                            byteOff += 0x94;
                            UInt8 *surf6 = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                            if (tileIdx >= U32At(surf6, 0x33 * 4)) break;
                            wantBits &= 0xfffffffeu;
                            if (wantBits == 0) break;
                        }
                    }
                    if (U16At(self, 0x9a) == 0) {
                        goto skipRing;
                    }
                    {
                        UInt32 idx = U32At(self, 0xa8);
                        UInt8 *surf7 = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
                        U32At(self, idx * 4 + 0x9c) = U32At(surf7, 0x84);
                        U32At(self, 0xa8) = (idx + 1) % 3;
                    }
                } else {
                skipRing:;
                }

                if (U32At(accel, 0x172 * 4) < U32At(self, 0xb0)) {
                    U32At(accel, 0x172 * 4) = U32At(self, 0xb0);
                }

                UInt8 *ringRec = accel + static_cast<UInt32>(U16At(accel, 0x100 * 2)) * 0x1c + 0x240;
                {
                    typedef SInt32 (*Fn0x554b)(void *, UInt32);
                    SInt32 stillFree = (*reinterpret_cast<Fn0x554b *>(*reinterpret_cast<void ***>(accel) + (0x554 / 4)))(accel, U32At(ringRec, 0x10));
                    if (stillFree == 0) {
                        if (U16At(accel, 0x402 * 2) < 0x10) {
                            bool grew = reinterpret_cast<IOATIR500Accelerator *>(accel)->allocMoreCommandBuffers(0, U32At(accel, 0x5c8));
                            if (grew) {
                                ringRec = accel + static_cast<UInt32>(U16At(accel, 0x400 * 2)) * 0x1c + 0x240;
                                goto haveRingRec;
                            }
                        }
                        UInt32 prevStat = U32At(accel, 0x770);
                        typedef UInt32 (*Fn0x54cb)(void *, UInt32);
                        UInt32 delta = (*reinterpret_cast<Fn0x54cb *>(*reinterpret_cast<void ***>(accel) + (0x54c / 4)))(accel, U32At(ringRec, 0x10));
                        U32At(accel, 0x770) = prevStat + delta;
                    }
                }
            haveRingRec:
                U16At(accel, 0x400 * 2) = (U16At(accel, 0x400 * 2) + 1) & (U16At(accel, 0x402 * 2) - 1);

                {
                    UInt32 saveCC = U32At(self, 0xcc), saveD0 = U32At(self, 0xd0), saveD4 = U32At(self, 0xd4);
                    UInt32 saveD8 = U32At(self, 0xd8), saveDC = U32At(self, 0xdc), saveE0 = U32At(self, 0xe0), saveE4 = U32At(self, 0xe4);

                    U32At(self, 0xcc) = *reinterpret_cast<UInt32 *>(ringRec);
                    U32At(self, 0xd0) = *reinterpret_cast<UInt32 *>(ringRec + 4);
                    U32At(self, 0xd4) = *reinterpret_cast<UInt32 *>(ringRec + 8);
                    U32At(self, 0xd8) = *reinterpret_cast<UInt32 *>(ringRec + 0xc);
                    U32At(self, 0xdc) = *reinterpret_cast<UInt32 *>(ringRec + 0x10);
                    U32At(self, 0xe0) = *reinterpret_cast<UInt32 *>(ringRec + 0x14);
                    U32At(self, 0xe4) = *reinterpret_cast<UInt32 *>(ringRec + 0x18);

                    *reinterpret_cast<UInt32 *>(ringRec) = saveCC;
                    *reinterpret_cast<UInt32 *>(ringRec + 4) = saveD0;
                    *reinterpret_cast<UInt32 *>(ringRec + 8) = saveD4;
                    *reinterpret_cast<UInt32 *>(ringRec + 0xc) = saveD8;
                    *reinterpret_cast<UInt32 *>(ringRec + 0x10) = saveDC;
                    *reinterpret_cast<UInt32 *>(ringRec + 0x14) = saveE0;
                    *reinterpret_cast<UInt32 *>(ringRec + 0x18) = saveE4;
                }

                UInt8 *accel2 = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
                if (U32At(self, 0xe4) != U32At(accel2, 0x5c8)) {
                    UInt8 tmpBuf[0x1c] = {0};
                    *reinterpret_cast<UInt32 *>(tmpBuf) = 0x10000;
                    bool allocOk = reinterpret_cast<IOATIR500Accelerator *>(accel2)->allocCommandBuffer(
                        reinterpret_cast<VendorCommandBuffer *>(tmpBuf), U32At(accel2, 0x5c8));
                    if (!allocOk) {
                        freeCommandBuffer();
                        reinterpret_cast<IOATIR500Accelerator *>(reinterpret_cast<UInt8 *>(U32At(self, 0xc8)))
                            ->freeCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0xcc));
                        U32At(self, 0xd0) = *reinterpret_cast<UInt32 *>(tmpBuf + 4);
                        U32At(self, 0xd4) = *reinterpret_cast<UInt32 *>(tmpBuf + 8);
                        U32At(self, 0xd8) = *reinterpret_cast<UInt32 *>(tmpBuf);
                        U32At(self, 0xdc) = *reinterpret_cast<UInt32 *>(tmpBuf + 0xc);
                        U32At(self, 0xe0) = *reinterpret_cast<UInt32 *>(tmpBuf + 0x10);
                        U32At(self, 0xe4) = *reinterpret_cast<UInt32 *>(tmpBuf + 0x14);
                        U32At(self, 0xcc) = *reinterpret_cast<UInt32 *>(tmpBuf);
                    }
                }

                U32At(self, 0xdc) = U32At(self, 0x7c);
                UInt8 *accel3 = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
                if (U8At(accel3, 0x88 * 1) == 0) {
                    UInt8 *scheduler = reinterpret_cast<UInt8 *>(U32At(accel3, 0xc0));
                    typedef void (*ScheduleFn)(void *, UInt32);
                    (*reinterpret_cast<ScheduleFn *>(*reinterpret_cast<void ***>(scheduler) + (300 / 4)))(scheduler, U32At(accel3, 0x8c));
                    U8At(reinterpret_cast<void *>(U32At(self, 0xc8)), 0x88) = 1;
                } else {
                    U8At(accel3, 0x89) = 1;
                }
                goto haveFreshBuffer;
            } else {
            bailInactive:
                /* real: reached directly (goto LAB_0000a484 in the raw
                 * decompile) from several mid-computation bail-outs below,
                 * WITHOUT resetting syncFlags - only the three "not active
                 * yet" sites above (which fall through to this same shared
                 * tail via `notActive`) zero it first. Do not add a
                 * `syncFlags = 0` here - that would silently clobber an
                 * already-computed value from those other paths. */
                needsFlushNotify = false;
            notActive:
                typedef void (*Fn0x5b8Self)(void *);
                (*reinterpret_cast<Fn0x5b8Self *>(*reinterpret_cast<void ***>(self) + (0x5b8 / 4)))(self);
                U32At(accel, 0x78) = 0;
                goto haveFreshBuffer;
            }

        haveFreshBuffer:
            UInt8 *pendingHead = reinterpret_cast<UInt8 *>(U32At(self, 0xe8));
            if (pendingHead != reinterpret_cast<UInt8 *>(U32At(self, 0xec))) {
                UInt8 *node = pendingHead;
                do {
                    UInt8 *next = reinterpret_cast<UInt8 *>(U32At(node, 0x3c));
                    UInt8 *freeTail = reinterpret_cast<UInt8 *>(U32At(accel, 0x5d0));
                    if (freeTail == nullptr) {
                        U32At(accel, 0x5cc) = reinterpret_cast<UInt32>(node);
                        U32At(accel, 0x5d0) = reinterpret_cast<UInt32>(node);
                        U32At(node, 0x3c) = 0;
                    } else {
                        U32At(freeTail, 0x3c) = reinterpret_cast<UInt32>(node);
                        U32At(accel, 0x5d0) = reinterpret_cast<UInt32>(node);
                        U32At(node, 0x3c) = 0;
                    }
                    U32At(accel, 0x5d4) += 1;
                    U8At(node, 0x54) = 0;
                    node = next;
                } while (reinterpret_cast<UInt8 *>(U32At(self, 0xec)) != node);
                U32At(self, 0xe8) = reinterpret_cast<UInt32>(node);
                U32At(node, 0x3c) = 0;
                U32At(self, 0xf0) = 1;
            }

            UInt8 *cmdDesc = reinterpret_cast<UInt8 *>(U32At(self, 0xd4));
            (*reinterpret_cast<RetainFn *>(*reinterpret_cast<void ***>(cmdDesc) + (0x14 / 4)))(cmdDesc);
            *options = 0;
            *memory = reinterpret_cast<IOMemoryDescriptor *>(cmdDesc);
            init_command_buffer_header(reinterpret_cast<VendorCommandBufferHeader *>(U32At(self, 0xe0)),
                                        U32At(self, 0xe4), syncFlags);
            ClientMem_mutex_unlock(*reinterpret_cast<void **>(accel + 0x840));

            if (!needsFlushNotify) {
                return 0;
            }
            {
                UInt8 *accel4 = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
                UInt32 idx = U32At(self, 0xa8);
                UInt32 prevStat = U32At(accel4, 0x798);
                typedef SInt32 (*Fn0x55cb)(void *, UInt32);
                SInt32 delta = (*reinterpret_cast<Fn0x55cb *>(*reinterpret_cast<void ***>(accel4) + (0x55c / 4)))(
                    accel4, U32At(self, idx * 4 + 0x9c));
                U32At(accel4, 0x798) = prevStat + delta;
            }
            return 0;
        }
    }
    default:
        return 0xe00002c2;
    }
    return 0xe00002be;
}
