/*
 * IOATIR500DVDContext_ClientMemoryForType.cpp
 *
 * RESOLVED (ledger pass): IOATIR500DVDContext::clientMemoryForType (real addr 0xf0c0, vtable +0x580), transcribed
 * from the shipped kext; every alloc_surfaces argument list was checked against the disassembly.
 *
 *   type 0: retain and hand out the accelerator's shared descriptor (accelerator+0xac).
 *   type 2: retain and hand out the context-buffer descriptor (this+0xb4), re-initialise its header.
 *   type 3: retain and hand out the accelerator's shared descriptor (accelerator+0xb0).
 *   type 1: the DVD "flush the current command buffer and hand the client a fresh one" path. Same skeleton as the
 *           2D and GL versions (revalidate the bound surface with alloc_surfaces retried up to 1000 times, submit
 *           the previous context's buffer if a different context last submitted, run process_command_buffer,
 *           submit through accelerator vtable +0x560, update the surface's stamps and the live-surface ring, swap
 *           in the next command buffer from the accelerator's 0x1c-byte-entry ring), plus DVD-specific work:
 *           every bound texture is added to and removed from the command stream around the parse, and the fresh
 *           command buffer is re-allocated at the accelerator's size hint (+0x5c8) when its size differs.
 *
 * Accelerator slots: +0x54c wait for stamp, +0x554 stamp passed?, +0x560 submit a VendorCommandDescriptor.
 * Surface slots: +0x5b4 update_ref_stamps, +0x5c0 build_swap. Own slots: +0x5b0 submit_context_buffer,
 * +0x5b4 process_command_buffer, +0x5b8 discard_command_buffer.
 */

#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

extern "C" void DVDCmft_lock(void *) asm("_IOLockLock");
extern "C" void DVDCmft_unlock(void *) asm("_IOLockUnlock");
extern "C" void DVDCmft_sleep(void *lock, void *event, UInt32 interruptible) asm("_IOLockSleep");
extern "C" void DVDCmft_thread_block(UInt32 continuation) asm("_thread_block");
extern "C" void DVDCmft_IOSleep(UInt32 ms) asm("_IOSleep");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*StampFn)(void *, UInt32);
typedef UInt32 (*SubmitFn)(void *, VendorCommandDescriptor *);
} // namespace

#define ACCEL() reinterpret_cast<UInt8 *>(accelerator)
#define ACCEL_LOCK() (*reinterpret_cast<void **>(ACCEL() + 0x840))

/* (re-ported mechanically: see IOATIR500DVDContext_clientMemoryForType_Port.cpp) */

