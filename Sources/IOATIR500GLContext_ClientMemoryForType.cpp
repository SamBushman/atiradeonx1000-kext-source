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

extern "C" void ClientMem_mutex_lock(void *lockPtr) asm("_IOLockLock");
extern "C" void ClientMem_mutex_unlock(void *lockPtr) asm("_IOLockUnlock");
extern "C" void ClientMem_IOLockSleep(void *lockPtr, void *event, UInt32 zero) asm("_IOLockSleep");
/* RESOLVED (issue #58 follow-up): the four former FUN_0000aee8/aed8/af98/af88
 * lazy-binding stubs, resolved via live kxld read (slide 0x589000; exact
 * offset-0 matches in nm /mach_kernel). aed8 targets 0xacbe0, where _memcpy
 * and _memmove are aliases of the same code - memmove chosen (overlap-safe). */
extern "C" void *ClientMem_IOBufferMemoryDescriptor_withOptions(UInt32 options, UInt32 capacity, UInt32 alignment) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");
extern "C" void ClientMem_memmove(void *dest, const void *src, UInt32 size) asm("_memmove");
/* called as a pair immediately after unlocking in a retry loop: a
 * thread_block(0) yield followed by a 1 ms IOSleep. */
extern "C" void ClientMem_thread_block(UInt32 continuation) asm("_thread_block");
extern "C" void ClientMem_IOSleep(UInt32 milliseconds) asm("_IOSleep");
extern "C" int kernelPageSize asm("_page_size"); /* kernel page_size (0x1000). Ghidra labels every zero-immediate data relocation in this kext "_ASICSupportsAGP"; the real target of each site comes from the Mach-O relocation table (issue #58 follow-up) */

/* (re-ported mechanically: see IOATIR500GLContext_init_command_buffer_header_Port.cpp) */


/* (re-ported mechanically: see IOATIR500GLContext_clientMemoryForType_Port.cpp) */

