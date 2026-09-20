/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500GLContext_ReadBuffer.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `IOATIR500GLContext::read_buffer` - real addr 0x8d10, the real
 * glReadPixels-style "copy hardware framebuffer to a userspace-mapped
 * buffer" external method.
 *
 * HONEST NOTE on the real decompile's own parameter list: Ghidra
 * mis-detected the calling convention as `__stdcall` and renders only
 * two visible parameters (`sIOGLContextReadBufferData *param_1, ulong
 * param_2`) - but every real field access inside the body reads
 * `param_1+200`/`+0x290`/etc. as this class's own already-established
 * `self+0xc8`(accelerator)/`self+0x290`(boundSurface) fields, proving
 * `param_1` is really the implicit `this`, not a real data parameter.
 * The real `readData` struct pointer is Ghidra's own `param_2`
 * (rendered as `ulong` - the same real pointer-degraded-to-integer
 * artifact this project already documents for `sATIDVDIDCTParams`).
 * This function's own real body never reads a third value, so the
 * class's own already-declared `structSize` parameter (required by the
 * real external linkage signature, confirmed via `nm`) is accepted for
 * ABI correctness but genuinely unused here - another instance of this
 * project's established "argument accepted but not read" pattern.
 *
 * Real body: translates the caller's requested buffer-type tag (a
 * 10-way switch) to an internal buffer-family index, locks the
 * accelerator's commandLock, waits (via the already-established
 * `IOLockSleep`) for a real surface to become bound if the bound
 * surface's own ID (`+0xa4`) hasn't been assigned yet, resolves a real
 * per-format buffer-pointer-table entry (the SAME `boundSurf+idx*4+
 * 0xb70` table `write_r500_3d_blit_state_packet` already establishes,
 * with a real alternate lookup through the accelerator's own
 * `+idx*0x20+0xe8` array when the surface's own `+0xc14` cross-
 * reference applies), gates on the surface's own `+0xbf8` state-bits
 * field (allocating on demand via `alloc_surfaces_retry` when needed),
 * clips the caller's requested rectangle to the surface's own real
 * bounds (`+0xbd4`/`+0xbd6`), allocates a real userspace-mapped
 * `IOMemoryDescriptor` via the already-confirmed
 * `IOMemoryDescriptor::withAddress` for the clipped region, calls the
 * real per-tile blit vtable slot (`+0x5e8`, already established in
 * `IOATIR500Surface_CopyBufferToBackingStore.cpp`) once for the whole
 * clipped rectangle, propagates a real "generation stamp" bump to any
 * other cached slot referencing the same buffer (the SAME fixed
 * 23-entry `+0xa0/+0x78`-stride array shape `alloc_surfaces_pageq`
 * already establishes, here read from the bound surface directly), and
 * - if a real flag was set - releases a real transfer buffer back to
 * GART before releasing the memory descriptor and unlocking.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile.
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*BlitTileFn)(void *, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, void *, UInt32, UInt32, UInt32, UInt32, UInt32);
typedef void (*ReleaseFn)(void *);

/* the real 16-byte on-stack record handed to the tile-blit slot (+0x5e8) and,
 * if the blit flags it, released via accelerator vtable +0x5ac. Real layout
 * per raw decompile (local_48/local_44/local_40/local_3c/local_3a, contiguous):
 * {word0=0, needsRelease=0, memDesc, u16 kind=3, u16 0}. Corrected in issue
 * #58's cross-check against surface_read (same record). */
struct ReadBufferXferRecord {
    UInt32 word0;
    UInt32 needsRelease;
    void *memDesc;
    UInt16 kind;
    UInt16 pad;
};
} // namespace

extern "C" void ReadBuffer_mutex_lock(void *lockPtr) asm("_IOLockLock");
extern "C" void ReadBuffer_mutex_unlock(void *lockPtr) asm("_IOLockUnlock");
extern "C" void ReadBuffer_IOLockSleep(void *lockPtr, void *event, UInt32 zero) asm("_IOLockSleep");
extern "C" void *ReadBuffer_withAddress(UInt32 address, UInt32 length, UInt32 direction, void *task) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");
extern "C" int kernelPageSize asm("_page_size"); /* kernel page_size (0x1000). Ghidra labels every zero-immediate data relocation in this kext "_ASICSupportsAGP"; the real target of each site comes from the Mach-O relocation table (issue #58 follow-up) */

/* (re-ported mechanically: see IOATIR500GLContext_read_buffer_Port.cpp) */

