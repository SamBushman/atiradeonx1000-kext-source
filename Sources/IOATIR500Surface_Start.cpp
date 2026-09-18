/*
 * IOATIR500Surface_Start.cpp
 *
 * RESOLVED (issue #58, completing the external-method dispatch chain
 * issue #42 started): real body for `IOATIR500Surface::start`, real addr
 * 0x119f0. THE real function that populates `methodTable` (`this+0xd5c`,
 * `ATIR500Surface::getTargetAndMethodForIndex`'s own dispatch pointer) -
 * without this, the dispatch mechanism this project already implemented
 * (Sources/ATIR500Surface_ExternalMethods.cpp) would read an
 * uninitialized/zero pointer at runtime.
 *
 * Real structure: calls the real superclass `IOUserClient::start(provider)`
 * first (Ghidra's own decompile shows this call with zero visible
 * arguments - the same "argument-dropped" artifact already catalogued
 * throughout this project; the real provider argument is passed, matching
 * the identical already-established pattern in every other context
 * class's own start() override, e.g. Sources/ATIR500GLContext_Start.cpp).
 * `provider` here really is the accelerator itself (real client of the
 * accelerator's own device-tree node) - this function's very next line
 * stores it as `this+0xd50`, the SAME real `accelerator` field every
 * other Surface method already reads.
 *
 * Real per-slot array initialization (CONFIRMED, cross-validated against
 * already-established fields elsewhere in this project): a 23-iteration
 * loop (real count `0x17`, matching `prune_buffers`' own already-
 * documented "23 real per-format records" and `dealloc_surface`'s own
 * `0..0x16` range) zeroes/defaults a stride-`0x78` array starting at
 * `this+0` - its own `+0xa8..+0xd8` sub-range is the FIRST 0x30 bytes of
 * the SEPARATE, already-named `this+0xa8`-based `surfaceBuffersByFormat`
 * array (Headers/IOATIR500Surface.h) for the SAME slot index (confirmed:
 * this loop also writes `surfaceBuffersByFormat[i] = this+0xa8+i*0x78`
 * directly), and its own `+0x28+0x14` (`this+i*0x78+0x3c`) sub-field
 * masks in a real `0x111000` bit pattern - real per-field roles beyond
 * their raw offsets are UNKNOWN, transcribed literally.
 *
 * A second, 2-iteration loop (real count fixed at 2, matching the
 * already-established "two alternating buffer slots" pattern this
 * project has seen throughout `submit_swap_buffer`/`set_id_mode`/
 * `is_flip_allowed` - `this+id*8+0xd60/+0xd64` and `this+id*0x94+0xcac`
 * range) zeroes both slots' own small per-ID tracking records and a
 * nested 4-entry sub-array at `this+id*0x94+0xc3c` (stride `0x1c`).
 *
 * Real VRAM/swap-buffer bring-up: if the accelerator has zero real VRAM
 * heads (`accelerator+0xcc == 0`), just calls the accelerator's own
 * already-established real `getVRAMDescriptors()`. Otherwise, for each
 * real accelerator VRAM head (`0..accelerator->0xcc-1`), allocates a
 * real 12-byte per-ID tracking record (`IOMallocAligned(0xc, 0x20)`,
 * the SAME real allocator/size this project's own `set_id_mode` already
 * establishes) and calls the already-established real
 * `allocMasterSwapBuffer(id, 0x9000)` - a real, fixed 0x9000-byte size.
 * Either path's failure still falls through to real table/list setup
 * below (not an early return) - only the final `bVar1`/success flag
 * differs, gating whether `this+0xd58` gets set and whether a real
 * `stop(provider)` call happens at the very end (real cleanup-on-failure,
 * not a a bail-out).
 *
 * Real table/list setup (runs on EVERY path, success or failure): sets
 * `methodTable` to the real static table's own absolute address (see
 * Sources/ATIR500Surface_ExternalMethods.cpp), then splices this surface
 * into the accelerator's own real doubly-linked surface list
 * (`accelerator+0x5c` head, this surface's own `+0x9c`/`+0xa0`
 * next/prev links - a real, standard intrusive doubly-linked-list
 * insertion, self-linked if the list was empty), and increments a real
 * accelerator-owned surface-count field (`accelerator+0x730`).
 *
 * Confidence: CONFIRMED for control flow and every real offset/constant -
 * a real, complete, standalone decompile, cross-validated against this
 * project's own already-established fields wherever they overlap (see
 * above). Many per-slot sub-fields (`+0xbc`/`+0xbe`/`+0xc0`/`+0xc4`/
 * `+0xc6`/`+0xc8`/`+0xca`/`+0xdc`..`+0xe4` per 0x78-stride slot) have no
 * established real name/role beyond their raw offsets - transcribed
 * literally, not guessed at.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

extern "C" void *SurfStart_IOMallocAligned(UInt32 size, UInt32 align) asm("_IOMallocAligned");

/* real table, Sources/ATIR500Surface_ExternalMethods.cpp */
extern const VendorExternalMethod kSurfaceMethods[19];

/* FUN_00011e38 - RESOLVED (issue #58): a kxld-patched lazy-binding stub
 * whose live target is `IOLockAlloc` (kernel 0x2b2704, exact offset-0 match
 * in `nm /mach_kernel`). Creates this surface's own per-object lock at
 * +0xc04, later used by set_surface_blocking. Resolved via the live
 * per-segment-slide read of the loaded kext (slide validated first against
 * `get_state`, whose live bytes match the static file exactly). */
extern "C" void *SurfStart_IOLockAlloc(void) asm("_IOLockAlloc");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

bool IOATIR500Surface::start(IOService *provider) {
    if (!IOUserClient::start(provider)) {
        return false;
    }

    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    U32At(self, 0xd50) = reinterpret_cast<UInt32>(provider);
    U32At(self, 0xd58) = 0;
    UInt32 providerField50 = U32At(provider, 0x50);
    U32At(self, 0xa4) = 0xffffffe0u;
    U32At(self, 0x80) = 0;
    U32At(self, 0x84) = 0;
    *reinterpret_cast<SInt32 *>(self + 0x7c) = static_cast<SInt32>(providerField50) - 0x3fffffff;
    void *lockHandle = SurfStart_IOLockAlloc(); /* FUN_00011e38 = IOLockAlloc */
    U32At(self, 0xd4c) = 0;
    U32At(self, 0x88) = 0;
    U32At(self, 0xc04) = reinterpret_cast<UInt32>(lockHandle);
    U32At(self, 0x8c) = 0;
    U32At(self, 0x90) = 0;
    U32At(self, 0xd54) = 0;
    U32At(self, 0xbe8) = 0;
    U32At(self, 0xbfc) = 0;
    U16At(self, 0xbd4) = 0;
    U16At(self, 0xbd6) = 0;
    U16At(self, 0xbd8) = 0;
    U16At(self, 0xbda) = 0;
    U32At(self, 0xc18) = 0x20000000u;
    U32At(self, 0xc1c) = 0x20000000u;
    U8At(self, 0xc09) = 0;
    U8At(self, 0xbf7) = 0;

    for (UInt32 i = 0; i < 0x17; i++) {
        UInt8 *slot = self + i * 0x78;
        UInt8 *formatRec = self + 0xa8 + i * 0x78;

        U16At(slot, 0xbc) = 0;
        U16At(slot, 0xbe) = 0;
        U16At(slot, 0xc0) = 0;
        U16At(slot, 0xc4) = 0;
        U16At(slot, 0xc6) = 0;
        U16At(slot, 0xc8) = 1;
        U16At(slot, 0xca) = 1;
        U8At(slot, 0xdc) = 0;
        U8At(slot, 0xdd) = 0;
        U8At(slot, 0xde) = 0;
        U8At(slot, 0xdf) = 0xff;
        U8At(slot, 0xe0) = 0;
        U8At(slot, 0xe1) = 0;
        U8At(slot, 0xe3) = 6;
        U8At(slot, 0xe4) = 0;
        U32At(slot, 0xa8) = 0;
        U32At(slot, 0xac) = 0;
        U32At(slot, 0xb0) = 0;
        U32At(slot, 0xb4) = 0;
        U32At(slot, 0xb8) = 0;
        U32At(slot, 0xcc) = 0;
        U32At(slot, 0xd0) = 0xffffffffu;
        U32At(slot, 0xd4) = 0;
        U32At(slot, 0xd8) = 0;
        U32At(slot, 0x3c) = (U32At(slot, 0x3c) & 0xff0007ffu) | 0x111000u;
        U32At(slot, 0xe8) = 0;
        U32At(slot, 0xec) = 0;
        U32At(self, i * 4 + 0xb70) = reinterpret_cast<UInt32>(formatRec);
    }

    for (UInt32 id = 0; id < 2; id++) {
        UInt8 *idSlot8 = self + id * 8;
        UInt8 *idSlot94 = self + id * 0x94;
        UInt8 *nested = self + id * 0x94 + 0xc3c;

        U32At(idSlot8, 0xd60) = 0;
        U32At(idSlot8, 0xd64) = 0;
        U8At(idSlot94, 0xcac) = 0;
        U8At(idSlot94, 0xcad) = 0;
        U16At(idSlot94, 0xcae) = 0;
        U32At(idSlot94, 0xcb0) = 0;
        U32At(idSlot94, 0xc20) = 0;
        U32At(idSlot94, 0xc24) = 0;
        U32At(idSlot94, 0xc28) = 0;
        U16At(idSlot94, 0xc2e) = 0;
        U16At(idSlot94, 0xc2c) = 2;
        U32At(idSlot94, 0xc30) = 0;
        U32At(idSlot94, 0xc34) = 0;
        U32At(idSlot94, 0xc38) = 0;

        for (UInt32 j = 0; j < 4; j++) {
            UInt8 *entry = nested + j * 0x1c;
            U32At(entry, 0) = 0;
            U32At(entry, 4) = 0;
            U32At(entry, 8) = 0;
            U16At(entry, 0xe) = 0;
            U16At(entry, 0xc) = 2;
            U32At(entry, 0x10) = 0;
            U32At(entry, 0x14) = 0;
            U32At(entry, 0x18) = 0;
        }
    }

    U8At(self, 0xbd1) = 0;
    U16At(self, 0xbd2) = 0;
    U8At(self, 0xc08) = 0;
    U8At(self, 0xbec) = 0;
    U8At(self, 0xbd0) = 0;
    U8At(self, 0xbf4) = 1;
    U8At(self, 0xbed) = 0;
    U8At(self, 0xbf0) = 0;
    U8At(self, 0xbf1) = 0;
    U8At(self, 0xbf2) = 0;
    U8At(self, 0xbf3) = 0;
    U8At(self, 0xbef) = 0;
    U32At(self, 0xd48) = 0;
    U32At(self, 0xbcc) = 0;
    U32At(self, 0xc00) = 0;
    U32At(self, 0xd84) = 0;
    U32At(self, 0xc0c) = 0;
    U32At(self, 0xd88) = 0;
    U32At(self, 0xc10) = 0;
    U32At(self, 0xd8c) = 0;
    U32At(self, 0xd70) = 0;

    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
    U32At(self, 0xbf8) = 0x307fffffu;
    U32At(self, 0xc14) = 0xffffu;

    bool success;
    if (U32At(accel, 0xcc) == 0) {
    vramDescriptorsPath:
        success = reinterpret_cast<ATIRadeonX1000 *>(accel)->getVRAMDescriptors();
    } else {
        UInt32 id = 0;
        UInt8 *idSlot8 = self;
        success = false;
        bool allocatedAll = false;
        do {
            void *rec = SurfStart_IOMallocAligned(0xc, 0x20);
            U32At(idSlot8, 0xd60) = reinterpret_cast<UInt32>(rec);
            if (rec == nullptr) {
                break;
            }
            UInt8 *accel2 = *reinterpret_cast<UInt8 **>(self + 0xd50);
            if (accel2 != nullptr) {
                U32At(accel2, 0x804) += 0xc;
            }
            U32At(idSlot8, 0xd64) = 0xc;
            U32At(rec, 0) = 0;
            U16At(rec, 4) = 0;
            U16At(rec, 6) = 0;
            U16At(rec, 8) = 0;
            U16At(rec, 10) = 0;
            bool allocOk = allocMasterSwapBuffer(id, 0x9000);
            if (!allocOk) {
                break;
            }
            accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
            id++;
            idSlot8 += 8;
        } while (id < U32At(accel, 0xcc));
        if (id == U32At(accel, 0xcc)) {
            allocatedAll = true;
        }
        if (allocatedAll) {
            goto vramDescriptorsPath;
        }
        accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
    }

    U32At(self, 0xd5c) = reinterpret_cast<UInt32>(&kSurfaceMethods[0]);
    UInt8 *listHead = reinterpret_cast<UInt8 *>(U32At(accel, 0x5c));
    if (listHead == nullptr) {
        U32At(self, 0x9c) = reinterpret_cast<UInt32>(self);
        U32At(self, 0xa0) = reinterpret_cast<UInt32>(self);
    } else {
        UInt8 *prevOfHead = reinterpret_cast<UInt8 *>(U32At(listHead, 0xa0));
        U32At(self, 0x9c) = reinterpret_cast<UInt32>(listHead);
        U32At(self, 0xa0) = reinterpret_cast<UInt32>(prevOfHead);
        U32At(prevOfHead, 0x9c) = reinterpret_cast<UInt32>(self);
        U32At(listHead, 0xa0) = reinterpret_cast<UInt32>(self);
    }
    U32At(accel, 0x5c) = reinterpret_cast<UInt32>(self);
    U32At(*reinterpret_cast<void **>(self + 0xd50), 0x730) += 1;

    if (success) {
        U32At(self, 0xd58) = 1;
    } else {
        stop(reinterpret_cast<IOService *>(provider));
    }
    return success;
}
