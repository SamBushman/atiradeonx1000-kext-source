/* NOTE 2026-09-19: 14 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Surface_Methods.cpp
 *
 * RESOLVED (ledger pass): IOATIR500Surface members that had no body in the rebuild, transcribed from the shipped
 * kext (real addrs in parentheses):
 *   free (0x10a50)  clientClose (0x10ac0)  add_2d_context_to_list (0x10ba0)  set_access (0x11100)
 *   sleep_blocked (0x11840)  alloc_surfaces (0x12470)  alloc_buffer_backing_store (0x12900)
 *   move_buffer_from_backing_store (0x131b0)  alloc_surface_keep (0x13210)  alloc_surface (0x13360)
 *   stop (0x134b0)  setupFullScreen (0x13900)  remove_2d_context_from_list (0x13e30)  surface_req_bits (0x13f50)
 *   buffer_map_offset (0x14010)  clientMemoryForType (0x141b0)
 *
 * Field offsets: this+0x7c stamp, +0x88/+0x8c/+0x90 GL / 2D / DVD context list heads (each context links to the
 * next through its own +0x84), +0x9c/+0xa0 accelerator surface-list links, +0xa8 first of 23 buffer records
 * (stride 0x78), +0xb70 per-format record pointers, +0xbd0/+0xbd1 read/write lock state bytes, +0xbf6 blocking
 * flag, +0xbf7 "has backing store" flag, +0xbf8 pending-allocation mask, +0xc00 access handle, +0xc04 per-surface
 * lock, +0xc14 full-screen panel (0xffff = none), +0xc18 combined context mode bits, +0xc28.. per-panel swap
 * buffers (stride 0x94), +0xd50 accelerator, +0xd58 "started" flag, +0xd60/+0xd64 per-id region records.
 *
 * `alloc_surfaces(mask, retry)` is `alloc_surfaces_pageq(mask, 0, retry)`: the raw decompile shows the wrong
 * argument shuffle (Ghidra thought the first parameter was `this`); the disassembly (`or r6,r5,r5; li r5,0; bl`)
 * is unambiguous.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void SurfM_IOLockFree(void *lock) asm("_IOLockFree");
extern "C" void SurfM_IOFree(void *ptr, UInt32 size) asm("_IOFreeAligned"); /* stub 0x13884 resolves to IOFreeAligned, not IOFree */
extern "C" void SurfM_IOLockLock(void *lock) asm("_IOLockLock");
extern "C" void SurfM_IOLockUnlock(void *lock) asm("_IOLockUnlock");
extern "C" void SurfM_IOLockSleep(void *lock, void *event, UInt32 interruptible) asm("_IOLockSleep");
extern "C" void *SurfM_inTaskWithOptions(void *task, UInt32 options, UInt32 capacity, unsigned int alignment) asm("__ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj");
extern "C" int kernelPageSize asm("_page_size");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*ReleaseFn)(void *);
typedef void (*RetainFn)(void *);
inline void ReleaseObj(void *obj) {
    void **vtable = *reinterpret_cast<void ***>(obj);
    reinterpret_cast<ReleaseFn>(vtable[0x18 / 4])(obj);
}
} // namespace


void IOATIR500Surface::free() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (U32At(self, 0xc04) != 0) {
        SurfM_IOLockFree(reinterpret_cast<void *>(U32At(self, 0xc04)));
    }
    OSObject::free();
}


/* (re-ported mechanically: see IOATIR500Surface_clientClose_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_add_2d_context_to_list_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_remove_2d_context_from_list_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_set_access_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_sleep_blocked_Port.cpp) */



UInt32 IOATIR500Surface::alloc_surfaces(UInt32 mask, bool retry) {
    return alloc_surfaces_pageq(mask, 0, retry);
}


/* (re-ported mechanically: see IOATIR500Surface_surface_req_bits_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_buffer_map_offset_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_alloc_buffer_backing_store_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_move_buffer_from_backing_store_Port.cpp) */


/* Shared tail of alloc_surface / alloc_surface_keep: clear bit `index` of the pending-allocation mask. */
static inline void ClearPendingBit(UInt8 *self, UInt32 index) {
    U32At(self, 0xbf8) &= ~(1u << (index & 0x1f));
}

/* (re-ported mechanically: see IOATIR500Surface_alloc_surface_keep_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_alloc_surface_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_setupFullScreen_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_clientMemoryForType_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_stop_Port.cpp) */

