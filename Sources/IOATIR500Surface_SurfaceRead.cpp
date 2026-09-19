/*
 * IOATIR500Surface_SurfaceRead.cpp
 *
 * RESOLVED (issue #58): real body for `IOATIR500Surface::surface_read` -
 * external method selector 5, real addr 0x14a30. The Surface-side twin of
 * `IOATIR500GLContext::read_buffer` (real addr 0x8d10): a clipped readback
 * of this surface's own current buffer into a caller-supplied userspace
 * range, wrapped in a real `IOMemoryDescriptor` and handed to the real
 * per-tile blit vtable slot (+0x5e8).
 *
 * WHAT WAS BLOCKING IT, and how it was resolved: the body was fully
 * decompiled long ago; the only holdout was one call, `FUN_00014e28`, a
 * kxld-patched lazy-binding stub (`lis r12,0 / ori r12,r12,0 / mtspr CTR /
 * bctr` - zero immediates on disk). Resolved by a live, single-address
 * read of the loaded kext on the G5 (read-only /dev/kmem, no scan): the
 * live immediates decode to kernel 0x2d617c, an exact offset-0 match in
 * `nm /mach_kernel` for `IOMemoryDescriptor::withAddress(unsigned long,
 * unsigned long, IODirection, task*)` - the same symbol
 * `IOATIR500GLContext::read_buffer` and `IOATIR500Shared`'s texture
 * allocator already call. The two lock stubs used here were re-verified the
 * same way (0x14e58 -> `mutex_lock`, 0x14e38 -> `mutex_unlock_rwcmb`); they are
 * imported BY NAME as `IOLockLock`/`IOLockUnlock` (like the shipped kext), since
 * `mutex_unlock_rwcmb` is not an exported symbol and kld rejects it.
 * Slide used: this kext is a single unnamed LC_SEGMENT at vmaddr 0; the
 * live Mach-O header (read at kextstat's address 0x588000) reports
 * vmaddr 0x589000, i.e. live = 0x589000 + Ghidra address. Validated first
 * against `get_state` (0x10f30): live prologue bytes identical to static.
 * (The issue's earlier "formula doesn't hold" observation was a slide of
 * kextstat's address, one page short of the real segment base - not a
 * flaw in the technique.)
 *
 * Real body: identical in shape to read_buffer, minus the buffer-kind
 * translation (this surface always reads its own `+0xb70` primary buffer
 * record) and with the real "transfer buffer" bookkeeping live rather
 * than dead: the tile-blit call is handed a real 16-byte on-stack record
 * {word0=0, word1(needs-release flag)=0, memDesc, u16 kind=3, u16 0}
 * (stack slots 0x5c..0x6b in the raw disassembly, confirmed contiguous),
 * and afterwards, if the blit set word1, the record is released back to
 * the accelerator via its `+0x5ac` vtable slot.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile, stack layout of the
 * on-stack record checked against raw disassembly.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void SurfRead_mutex_lock(void *lockPtr) asm("_IOLockLock");
extern "C" void SurfRead_mutex_unlock(void *lockPtr) asm("_IOLockUnlock");
extern "C" void *SurfRead_withAddress(UInt32 address, UInt32 length, UInt32 direction, void *task) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");
extern "C" int kernelPageSize asm("_page_size"); /* kernel page_size (0x1000). Ghidra labels every zero-immediate data relocation in this kext "_ASICSupportsAGP"; the real target of each site comes from the Mach-O relocation table (issue #58 follow-up) */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*BlitTileFn)(void *, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, void *, UInt32, UInt32, UInt32, UInt32, UInt32);
typedef SInt32 (*QueryFn)(void *, UInt32, UInt32 *);
typedef SInt32 (*Fn0x55c)(void *, UInt32);
typedef void (*ReleaseFn)(void *);

/* the real on-stack record handed to the tile-blit slot and (if flagged)
 * released via accelerator vtable +0x5ac - see header comment */
struct SurfReadXferRecord {
    UInt32 word0;
    UInt32 needsRelease;
    void *memDesc;
    UInt16 kind;
    UInt16 pad;
};
} // namespace

/* (re-ported mechanically: see IOATIR500Surface_surface_read_Port.cpp) */

