/*
 * IOATIR5002DContext_ClientMemoryForType.cpp
 *
 * RESOLVED (ledger pass): IOATIR5002DContext::clientMemoryForType (real addr 0xd6f0, vtable +0x580), transcribed
 * from the shipped kext; the retry loops and every alloc_surfaces argument were checked against the disassembly.
 *
 *   type 1: retain and hand out the context-buffer descriptor (this+0xbc), re-initialise its header.
 *   type 2: retain and hand out the accelerator's shared descriptor (accelerator+0xac).
 *   type 0: the 2D "flush the current command buffer and hand the client a fresh one" path. Waits for the display,
 *           re-validates the bound surface (alloc_surfaces retried up to 1000 times with thread_block(0) +
 *           IOSleep(1) between attempts), submits the previous context's buffer if a different context last
 *           submitted, runs process_command_buffer over the client's buffer, submits it through accelerator
 *           vtable +0x560, updates the surface's stamps/refcounts and the accelerator's live-surface ring, swaps
 *           in the next command buffer from the accelerator's 0x1c-byte-entry ring (allocating more on demand)
 *           and schedules the deferred flush notification before returning the fresh command-buffer descriptor.
 *
 * Accelerator vtable slots used here (IOATIR500Accelerator, all pure in the base): +0x54c wait for stamp,
 * +0x554 stamp passed?, +0x558 wait for stamp, +0x560 submit a VendorCommandDescriptor, returning its stamp.
 * Surface vtable slots: +0x5b4 update_ref_stamps, +0x5b8 increment_refcounts, +0x5bc decrement_refcounts,
 * +0x5c0 build_swap, +0x5d4 submit_swap_buffer(index, 0).
 */

#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

extern "C" void Ctx2DM_lock(void *) asm("_IOLockLock");
extern "C" void Ctx2DM_unlock(void *) asm("_IOLockUnlock");
extern "C" void Ctx2DM_sleep(void *lock, void *event, UInt32 interruptible) asm("_IOLockSleep");
extern "C" void Ctx2DM_thread_block(UInt32 continuation) asm("_thread_block");
extern "C" void Ctx2DM_IOSleep(UInt32 ms) asm("_IOSleep");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*StampFn)(void *, UInt32);
typedef UInt32 (*SubmitFn)(void *, VendorCommandDescriptor *);
typedef void (*NotifyFn)(void *, UInt32);
inline void *AccelSlot(void *accel, int off) { return *reinterpret_cast<void **>(*reinterpret_cast<UInt8 **>(accel) + off); }
} // namespace

#define ACCEL() reinterpret_cast<UInt8 *>(accelerator)
#define ACCEL_LOCK() (*reinterpret_cast<void **>(ACCEL() + 0x840))

/* (re-ported mechanically: see IOATIR5002DContext_clientMemoryForType_Port.cpp) */

